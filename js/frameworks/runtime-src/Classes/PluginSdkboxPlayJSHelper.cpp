#include "PluginSdkboxPlayJSHelper.h"
#include "PluginSdkboxPlay/PluginSdkboxPlay.h"
#include "SDKBoxJSHelper.h"

extern JSObject* jsb_sdkbox_PluginSdkboxPlay_prototype;
static JSContext* s_cx = nullptr;

#if (COCOS2D_VERSION < 0x00030000)
#define Ref CCObject
#define Director CCDirector
#define getInstance sharedDirector
#define schedule scheduleSelector
#endif

class SdkboxPlayCallbackJS: public cocos2d::Ref {
public:
    SdkboxPlayCallbackJS();
    void schedule();
    void notityJs(float dt);

    std::string _name;

    JS::Value _paramVal[5];
    int _paramLen;
};

class SdkboxPlayListenerJS : public sdkbox::SdkboxPlayListener, public sdkbox::JSListenerBase
{
public:
    SdkboxPlayListenerJS():sdkbox::JSListenerBase() {
    }

    virtual void onConnectionStatusChanged(int connection_status) {
        //JSContext* cx = s_cx;
        SdkboxPlayCallbackJS* cb = new SdkboxPlayCallbackJS();

#if MOZJS_MAJOR_VERSION < 52
        JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
#endif

        cb->_name = "onConnectionStatusChanged";
        cb->_paramVal[0] = JS::Int32Value(connection_status);
        cb->_paramLen = 1;
        cb->schedule();
    }
    virtual void onScoreSubmitted(const std::string &leaderboard_name, long score, bool alltime, bool week, bool day) {
        JSContext* cx = s_cx;
        SdkboxPlayCallbackJS* cb = new SdkboxPlayCallbackJS();

#if MOZJS_MAJOR_VERSION < 52
        JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
#endif

        cb->_name = "onScoreSubmitted";
        cb->_paramVal[0] = SB_STR_TO_JSVAL(cx, leaderboard_name);
        cb->_paramVal[1] = JS::Int32Value(score);
        cb->_paramVal[2] = JS::BooleanValue(alltime);
        cb->_paramVal[3] = JS::BooleanValue(week);
        cb->_paramVal[4] = JS::BooleanValue(day);
        cb->_paramLen = 5;
        cb->schedule();
    }
    virtual void onMyScore( const std::string& leaderboard_name, int time_span, int collection_type, long score ) {
        JSContext* cx = s_cx;
        SdkboxPlayCallbackJS* cb = new SdkboxPlayCallbackJS();

#if MOZJS_MAJOR_VERSION < 52
        JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
#endif

        cb->_name = "onMyScore";
        cb->_paramVal[0] = SB_STR_TO_JSVAL(cx, leaderboard_name);
        cb->_paramVal[1] = JS::Int32Value(time_span);
        cb->_paramVal[2] = JS::Int32Value(collection_type);
        cb->_paramVal[3] = JS::Int32Value(score);
        cb->_paramLen = 4;
        cb->schedule();
    }
    virtual void onMyScoreError( const std::string& leaderboard_name, int time_span, int collection_type, int error_code, const std::string& error_description) {
        JSContext* cx = s_cx;
        SdkboxPlayCallbackJS* cb = new SdkboxPlayCallbackJS();

#if MOZJS_MAJOR_VERSION < 52
        JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
#endif

        cb->_name = "onMyScoreError";
        cb->_paramVal[0] = SB_STR_TO_JSVAL(cx, leaderboard_name);
        cb->_paramVal[1] = JS::Int32Value(time_span);
        cb->_paramVal[2] = JS::Int32Value(collection_type);
        cb->_paramVal[3] = JS::Int32Value(error_code);
        cb->_paramVal[4] = SB_STR_TO_JSVAL(cx, error_description);
        cb->_paramLen = 5;
        cb->schedule();
    }
    virtual void onPlayerCenteredScores( const std::string& leaderboard_name,
                                         int time_span,
                                         int collection_type,
                                         const std::string& json_with_score_entries ) {
        JSContext* cx = s_cx;
        SdkboxPlayCallbackJS* cb = new SdkboxPlayCallbackJS();

#if MOZJS_MAJOR_VERSION < 52
        JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
#endif

        cb->_name = "onPlayerCenteredScores";
        cb->_paramVal[0] = SB_STR_TO_JSVAL(cx, leaderboard_name);
        cb->_paramVal[1] = JS::Int32Value(time_span);
        cb->_paramVal[2] = JS::Int32Value(collection_type);
        cb->_paramVal[3] = SB_STR_TO_JSVAL(cx, json_with_score_entries);
        cb->_paramLen = 4;
        cb->schedule();
    }
    virtual void onPlayerCenteredScoresError( const std::string& leaderboard_name,
                                              int time_span,
                                              int collection_type,
                                              int error_code,
                                              const std::string& error_description) {
        JSContext* cx = s_cx;
        SdkboxPlayCallbackJS* cb = new SdkboxPlayCallbackJS();

#if MOZJS_MAJOR_VERSION < 52
        JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
#endif

        cb->_name = "onPlayerCenteredScoresError";
        cb->_paramVal[0] = SB_STR_TO_JSVAL(cx, leaderboard_name);
        cb->_paramVal[1] = JS::Int32Value(time_span);
        cb->_paramVal[2] = JS::Int32Value(collection_type);
        cb->_paramVal[3] = JS::Int32Value(error_code);
        cb->_paramVal[4] = SB_STR_TO_JSVAL(cx, error_description);
        cb->_paramLen = 5;
        cb->schedule();
    }
    virtual void onIncrementalAchievementUnlocked(const std::string &achievement_name) {
        JSContext* cx = s_cx;
        SdkboxPlayCallbackJS* cb = new SdkboxPlayCallbackJS();

#if MOZJS_MAJOR_VERSION < 52
        JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
#endif

        cb->_name = "onIncrementalAchievementUnlocked";
        cb->_paramVal[0] = SB_STR_TO_JSVAL(cx, achievement_name);
        cb->_paramLen = 1;
        cb->schedule();
    }
    virtual void onIncrementalAchievementStep(const std::string &achievement_name, double step) {
        JSContext* cx = s_cx;
        SdkboxPlayCallbackJS* cb = new SdkboxPlayCallbackJS();
        cb->_name = "onIncrementalAchievementStep";
        cb->_paramVal[0] = SB_STR_TO_JSVAL(cx, achievement_name);
        cb->_paramVal[1] = JS::DoubleValue(step);
        cb->_paramLen = 2;
        cb->schedule();
    }
    virtual void onIncrementalAchievementStepError( const std::string& name, double steps, int error_code, const std::string& error_description ) {
        JSContext* cx = s_cx;
        SdkboxPlayCallbackJS* cb = new SdkboxPlayCallbackJS();

#if MOZJS_MAJOR_VERSION < 52
        JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
#endif

        cb->_name = "onIncrementalAchievementStepError";
        cb->_paramVal[0] = SB_STR_TO_JSVAL(cx, name);
        cb->_paramVal[1] = JS::DoubleValue(steps);
        cb->_paramVal[2] = JS::Int32Value(error_code);
        cb->_paramVal[3] = SB_STR_TO_JSVAL(cx, error_description);
        cb->_paramLen = 4;
        cb->schedule();
    }
    virtual void onAchievementUnlocked(const std::string &achievement_name, bool newly) {
        JSContext* cx = s_cx;
        SdkboxPlayCallbackJS* cb = new SdkboxPlayCallbackJS();

#if MOZJS_MAJOR_VERSION < 52
        JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
#endif

        cb->_name = "onAchievementUnlocked";
        cb->_paramVal[0] = SB_STR_TO_JSVAL(cx, achievement_name);
        cb->_paramVal[1] = JS::BooleanValue(newly);
        cb->_paramLen = 2;
        cb->schedule();
    }
    virtual void onAchievementUnlockError( const std::string& achievement_name, int error_code, const std::string& error_description ) {
        JSContext* cx = s_cx;
        SdkboxPlayCallbackJS* cb = new SdkboxPlayCallbackJS();

#if MOZJS_MAJOR_VERSION < 52
        JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
#endif

        cb->_name = "onAchievementUnlockError";
        cb->_paramVal[0] = SB_STR_TO_JSVAL(cx, achievement_name);
        cb->_paramVal[1] = JS::Int32Value(error_code);
        cb->_paramVal[2] = SB_STR_TO_JSVAL(cx, error_description);
        cb->_paramLen = 3;
        cb->schedule();
    }
    virtual void onAchievementsLoaded( bool reload_forced, const std::string& json_achievements_info ) {
        JSContext* cx = s_cx;
        SdkboxPlayCallbackJS* cb = new SdkboxPlayCallbackJS();

#if MOZJS_MAJOR_VERSION < 52
        JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
#endif

        cb->_name = "onAchievementsLoaded";
        cb->_paramVal[0] = JS::BooleanValue(reload_forced);
        cb->_paramVal[1] = SB_STR_TO_JSVAL(cx, json_achievements_info);
        cb->_paramLen = 2;
        cb->schedule();
    }
    virtual void onSetSteps( const std::string& name, double steps ) {
        JSContext* cx = s_cx;
        SdkboxPlayCallbackJS* cb = new SdkboxPlayCallbackJS();

#if MOZJS_MAJOR_VERSION < 52
        JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
#endif

        cb->_name = "onSetSteps";
        cb->_paramVal[0] = SB_STR_TO_JSVAL(cx, name);
        cb->_paramVal[1] = JS::DoubleValue(steps);
        cb->_paramLen = 2;
        cb->schedule();
    }
    virtual void onSetStepsError( const std::string& name, double steps, int error_code, const std::string& error_description ) {
        JSContext* cx = s_cx;
        SdkboxPlayCallbackJS* cb = new SdkboxPlayCallbackJS();

#if MOZJS_MAJOR_VERSION < 52
        JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
#endif

        cb->_name = "onSetStepsError";
        cb->_paramVal[0] = SB_STR_TO_JSVAL(cx, name);
        cb->_paramVal[1] = JS::DoubleValue(steps);
        cb->_paramVal[2] = JS::Int32Value(error_code);
        cb->_paramVal[3] = SB_STR_TO_JSVAL(cx, error_description);
        cb->_paramLen = 4;
        cb->schedule();
    }
    virtual void onReveal( const std::string& name) {
        JSContext* cx = s_cx;
        SdkboxPlayCallbackJS* cb = new SdkboxPlayCallbackJS();

#if MOZJS_MAJOR_VERSION < 52
        JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
#endif

        cb->_name = "onReveal";
        cb->_paramVal[0] = SB_STR_TO_JSVAL(cx, name);
        cb->_paramLen = 1;
        cb->schedule();
    }
    virtual void onRevealError( const std::string& name, int error_code, const std::string& error_description ) {
        JSContext* cx = s_cx;
        SdkboxPlayCallbackJS* cb = new SdkboxPlayCallbackJS();

#if MOZJS_MAJOR_VERSION < 52
        JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
#endif

        cb->_name = "onRevealError";
        cb->_paramVal[0] = SB_STR_TO_JSVAL(cx, name);
        cb->_paramVal[1] = JS::Int32Value(error_code);
        cb->_paramVal[2] = SB_STR_TO_JSVAL(cx, error_description);
        cb->_paramLen = 3;
        cb->schedule();
    }

    virtual void onGameData(const std::string& action, const std::string& name, const std::string& data, const std::string& error) {
        JSContext* cx = s_cx;
        SdkboxPlayCallbackJS* cb = new SdkboxPlayCallbackJS();

#if MOZJS_MAJOR_VERSION < 52
        JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
#endif

        cb->_name = "onGameData";
        cb->_paramVal[0] = SB_STR_TO_JSVAL(cx, action);
        cb->_paramVal[1] = SB_STR_TO_JSVAL(cx, name);
        cb->_paramVal[2] = SB_STR_TO_JSVAL(cx, data);
        cb->_paramVal[3] = SB_STR_TO_JSVAL(cx, error);
        cb->_paramLen = 4;
        cb->schedule();
    }

    void invokeJS(const char* func, JS::Value* pVals, int valueSize) {
        if (!s_cx) {
            return;
        }
        JSContext* cx = s_cx;
        const char* func_name = func;
        JS::RootedObject obj(cx, getJSDelegate());
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
            if(func_handle == JS::NullValue()) {
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
    cocos2d::Director::getInstance()->getScheduler()->schedule(schedule_selector(SdkboxPlayCallbackJS::notityJs), this, 0, 0, 0.0f, false);
    autorelease();
}

void SdkboxPlayCallbackJS::notityJs(float dt) {
    sdkbox::SdkboxPlayListener* lis = sdkbox::PluginSdkboxPlay::getListener();
    SdkboxPlayListenerJS* l = dynamic_cast<SdkboxPlayListenerJS*>(lis);
    if (l) {
        l->invokeJS(_name.c_str(), _paramVal, _paramLen);
    }
    release();
}


#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_setListener(JSContext *cx, uint32_t argc, JS::Value *vp)
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

        JSB_PRECONDITION2(ok, cx, false, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_setIAPListener : Error processing arguments");
        SdkboxPlayListenerJS* wrapper = new SdkboxPlayListenerJS();
        wrapper->setJSDelegate(cx, args.get(0));
        sdkbox::PluginSdkboxPlay::setListener(wrapper);

        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_setListener : wrong number of arguments");
    return false;
}


#if defined(MOZJS_MAJOR_VERSION) and MOZJS_MAJOR_VERSION >= 26
void SdkboxPlay_set_constants(JSContext* cx, const JS::RootedObject& obj, const std::string& name, const std::map<std::string, int>& params)
#else
void SdkboxPlay_set_constants(JSContext* cx, JSObject* obj, const std::string& name, const std::map<std::string, int>& params)
#endif
{
    JS::RootedValue val(cx);
    sdkbox::std_map_string_int_to_jsval(cx, params, &val);

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
    sdkbox::getJsObjOrCreat(cx, JS::RootedObject(cx, global), "sdkbox.PluginSdkboxPlay", &pluginObj);

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
