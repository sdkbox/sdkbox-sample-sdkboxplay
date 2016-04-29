#include "PluginSdkboxPlayJSHelper.h"
#include "cocos2d_specifics.hpp"
#include "PluginSdkboxPlay/PluginSdkboxPlay.h"
#include "SDKBoxJSHelper.h"

#include "js_manual_conversions.h"

extern JSObject* jsb_sdkbox_PluginSdkboxPlay_prototype;
static JSContext* s_cx = nullptr;

class SdkboxPlayCallbackJS: public cocos2d::CCObject {
public:
    SdkboxPlayCallbackJS();
    void schedule();
    void notityJs(float dt);

    std::string _name;

    jsval _paramVal[2];
    int _paramLen;
};

class SdkboxPlayListenerJS : public sdkbox::SdkboxPlayListener {
private:
    JSObject* _JSDelegate;
public:
    void setJSDelegate(JSObject* delegate) {
        _JSDelegate = delegate;
    }

    JSObject* getJSDelegate() {
        return _JSDelegate;
    }

    void onConnectionStatusChanged(int connection_status) {
        JSContext* cx = s_cx;
        SdkboxPlayCallbackJS* cb = new SdkboxPlayCallbackJS();
        cb->_name = "onConnectionStatusChanged";
        cb->_paramVal[0] = INT_TO_JSVAL(connection_status);
        cb->_paramLen = 1;
        cb->schedule();
    }
    void onScoreSubmitted(const std::string &leaderboard_name, int score, bool alltime, bool week, bool day) {
        JSContext* cx = s_cx;
        SdkboxPlayCallbackJS* cb = new SdkboxPlayCallbackJS();
        cb->_name = "onScoreSubmitted";
        cb->_paramVal[0] = std_string_to_jsval(cx, leaderboard_name);
        cb->_paramVal[1] = INT_TO_JSVAL(score);
        cb->_paramVal[2] = BOOLEAN_TO_JSVAL(alltime);
        cb->_paramVal[3] = BOOLEAN_TO_JSVAL(week);
        cb->_paramVal[4] = BOOLEAN_TO_JSVAL(day);
        cb->_paramLen = 5;
        cb->schedule();
    }
    void onIncrementalAchievementUnlocked(const std::string &achievement_name) {
        JSContext* cx = s_cx;
        SdkboxPlayCallbackJS* cb = new SdkboxPlayCallbackJS();
        cb->_name = "onIncrementalAchievementUnlocked";
        cb->_paramVal[0] = std_string_to_jsval(cx, achievement_name);
        cb->_paramLen = 1;
        cb->schedule();
    }
    void onIncrementalAchievementStep(const std::string &achievement_name, int step) {
        JSContext* cx = s_cx;
        SdkboxPlayCallbackJS* cb = new SdkboxPlayCallbackJS();
        cb->_name = "onIncrementalAchievementStep";
        cb->_paramVal[0] = std_string_to_jsval(cx, achievement_name);
        cb->_paramVal[1] = INT_TO_JSVAL(step);
        cb->_paramLen = 2;
        cb->schedule();
    }
    void onAchievementUnlocked(const std::string &achievement_name, bool newly) {
        JSContext* cx = s_cx;
        SdkboxPlayCallbackJS* cb = new SdkboxPlayCallbackJS();
        cb->_name = "onAchievementUnlocked";
        cb->_paramVal[0] = std_string_to_jsval(cx, achievement_name);
        cb->_paramVal[1] = BOOLEAN_TO_JSVAL(newly);
        cb->_paramLen = 2;
        cb->schedule();
    }

    void invokeJS(const char* func, jsval* pVals, int valueSize) {
        if (!s_cx) {
            return;
        }
        JSContext* cx = s_cx;
        const char* func_name = func;
        JS::RootedObject obj(cx, _JSDelegate);
        JSAutoCompartment ac(cx, obj);

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
        bool hasAction;
        JS::RootedValue retval(cx);
        JS::RootedValue func_handle(cx);
#else
        bool hasAction;
        jsval retval;
        JS::RootedValue func_handle(cx);
#endif
#elif defined(JS_VERSION)
        JSBool hasAction;
        jsval retval;
        jsval func_handle;
#endif

        if (JS_HasProperty(cx, obj, func_name, &hasAction) && hasAction) {
            if(!JS_GetProperty(cx, obj, func_name, &func_handle)) {
                return;
            }
            if(func_handle == JSVAL_VOID) {
                return;
            }

#if MOZJS_MAJOR_VERSION >= 31
            if (0 == valueSize) {
                JS_CallFunctionName(cx, obj, func_name, JS::HandleValueArray::empty(), &retval);
            } else {
                JS_CallFunctionName(cx, obj, func_name, JS::HandleValueArray::fromMarkedLocation(valueSize, pVals), &retval);
            }
#else
            if (0 == valueSize) {
                JS_CallFunctionName(cx, obj, func_name, 0, nullptr, &retval);
            } else {
                JS_CallFunctionName(cx, obj, func_name, valueSize, pVals, &retval);
            }
#endif
        }
    }

};


SdkboxPlayCallbackJS::SdkboxPlayCallbackJS():
_paramLen(0) {
}

void SdkboxPlayCallbackJS::schedule() {
    retain();
    cocos2d::CCDirector::sharedDirector()->getScheduler()->scheduleSelector(schedule_selector(SdkboxPlayCallbackJS::notityJs), this, 0, false);
    autorelease();
}

void SdkboxPlayCallbackJS::notityJs(float dt) {
    sdkbox::SdkboxPlayListener* lis = sdkbox::PluginSdkboxPlay::getListener();
    SdkboxPlayListenerJS* l = dynamic_cast<SdkboxPlayListenerJS*>(lis);
    if (l) {
        l->invokeJS(_name.c_str(), _paramVal, _paramLen);
    }
    cocos2d::CCDirector::sharedDirector()->getScheduler()->unscheduleAllForTarget(this);
    release();
}


#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_setListener(JSContext *cx, uint32_t argc, jsval *vp)
#else
bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_setListener(JSContext *cx, uint32_t argc, jsval *vp)
#endif
#elif defined(JS_VERSION)
JSBool js_PluginSdkboxPlayJS_PluginSdkboxPlay_setListener(JSContext *cx, uint32_t argc, jsval *vp)
#endif
{
    s_cx = cx;
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;

    if (argc == 1) {

        if (!args.get(0).isObject())
        {
            ok = false;
        }
        JSObject *tmpObj = args.get(0).toObjectOrNull();

        JSB_PRECONDITION2(ok, cx, false, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_setIAPListener : Error processing arguments");
        SdkboxPlayListenerJS* wrapper = new SdkboxPlayListenerJS();
        wrapper->setJSDelegate(tmpObj);
        sdkbox::PluginSdkboxPlay::setListener(wrapper);

        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_setListener : wrong number of arguments");
    return false;
}


#if defined(MOZJS_MAJOR_VERSION) and MOZJS_MAJOR_VERSION >= 26
void SdkboxPlay_set_constants(JSContext* cx, const JS::RootedObject& obj, const std::string& name, const std::map<std::string, int>& params)
#else
void SdkboxPlay_set_constants(JSContext* cx, JSObject* obj, const std::string& name, const std::map<std::string, int>& params)
#endif
{
    jsval val = sdkbox::std_map_string_int_to_jsval(cx, params);

    JS::RootedValue rv(cx);
    rv = val;
#if defined(MOZJS_MAJOR_VERSION) and MOZJS_MAJOR_VERSION >= 26
    JS_SetProperty(cx, obj, name.c_str(), rv);
#else
    JS_SetProperty(cx, obj, name.c_str(), rv.address());
#endif
}

#if defined(MOZJS_MAJOR_VERSION) and MOZJS_MAJOR_VERSION >= 26
void SdkboxPlay_register_constants(JSContext* cx, const JS::RootedObject& obj)
#else
void SdkboxPlay_register_constants(JSContext* cx, JSObject* obj)
#endif
{
    // std::map<std::string, int> enums;
    // enums.clear();
    // enums.insert(std::make_pair("kIMSDKGenderMale", 1));
    // enums.insert(std::make_pair("kIMSDKGenderFemale", 2));
    // admob_set_constants(cx, obj, "SBIMSDKGender", enums);
}

#define REGISTE_SdkboxPlay_FUNCTIONS \
JS_DefineFunction(cx, pluginObj, "setListener", js_PluginSdkboxPlayJS_PluginSdkboxPlay_setListener, 1, JSPROP_READONLY | JSPROP_PERMANENT); \
SdkboxPlay_register_constants(cx, pluginObj);

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void register_all_PluginSdkboxPlayJS_helper(JSContext* cx, JS::HandleObject global) {
    JS::RootedObject pluginObj(cx);
    sdkbox::getJsObjOrCreat(cx, global, "sdkbox.PluginSdkboxPlay", &pluginObj);

    REGISTE_SdkboxPlay_FUNCTIONS
}
#else
void register_all_PluginSdkboxPlayJS_helper(JSContext* cx, JSObject* global) {
    JS::RootedObject pluginObj(cx);
    sdkbox::getJsObjOrCreat(cx, JS::RootedObject(cx, global), "sdkbox.PluginAdMob", &pluginObj);

    REGISTE_SdkboxPlay_FUNCTIONS
}
#endif
#elif defined(JS_VERSION)
void register_all_PluginSdkboxPlayJS_helper(JSContext* cx, JSObject* global) {
    jsval pluginVal;
    JSObject* pluginObj;
    pluginVal = sdkbox::getJsObjOrCreat(cx, global, "sdkbox.PluginSdkboxPlay", &pluginObj);

    REGISTE_SdkboxPlay_FUNCTIONS
}
#endif
