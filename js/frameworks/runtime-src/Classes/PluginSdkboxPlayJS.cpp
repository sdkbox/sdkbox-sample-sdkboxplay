#include "PluginSdkboxPlayJS.hpp"
#include "PluginSdkboxPlay/PluginSdkboxPlay.h"
#include "SDKBoxJSHelper.h"
#include "sdkbox/Sdkbox.h"


#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
template<class T>
static bool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedValue initializing(cx);
    bool isNewValid = true;
    if (isNewValid)
    {
        TypeTest<T> t;
        js_type_class_t *typeClass = nullptr;
        std::string typeName = t.s_name();
        auto typeMapIter = _js_global_type_map.find(typeName);
        CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
        typeClass = typeMapIter->second;
        CCASSERT(typeClass, "The value is null.");

#if (SDKBOX_COCOS_JSB_VERSION >= 2)
        JS::RootedObject proto(cx, typeClass->proto.ref());
        JS::RootedObject parent(cx, typeClass->parentProto.ref());
#else
        JS::RootedObject proto(cx, typeClass->proto.get());
        JS::RootedObject parent(cx, typeClass->parentProto.get());
#endif
        JS::RootedObject _tmp(cx, JS_NewObject(cx, typeClass->jsclass, proto, parent));

        T* cobj = new T();
        js_proxy_t *pp = jsb_new_proxy(cobj, _tmp);
        AddObjectRoot(cx, &pp->obj);
        args.rval().set(OBJECT_TO_JSVAL(_tmp));
        return true;
    }

    return false;
}

static bool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    return false;
}

static bool js_is_native_obj(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    args.rval().setBoolean(true);
    return true;
}
#else
template<class T>
static bool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    JS::RootedValue initializing(cx);
    bool isNewValid = true;
    if (isNewValid)
    {
        TypeTest<T> t;
        js_type_class_t *typeClass = nullptr;
        std::string typeName = t.s_name();
        auto typeMapIter = _js_global_type_map.find(typeName);
        CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
        typeClass = typeMapIter->second;
        CCASSERT(typeClass, "The value is null.");

        JSObject *_tmp = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
        T* cobj = new T();
        js_proxy_t *pp = jsb_new_proxy(cobj, _tmp);
        JS_AddObjectRoot(cx, &pp->obj);
        JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(_tmp));
        return true;
    }

    return false;
}

static bool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    return false;
}

static bool js_is_native_obj(JSContext *cx, JS::HandleObject obj, JS::HandleId id, JS::MutableHandleValue vp)
{
    vp.set(BOOLEAN_TO_JSVAL(true));
    return true;
}
#endif
#elif defined(JS_VERSION)
template<class T>
static JSBool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    TypeTest<T> t;
    T* cobj = new T();
    js_type_class_t *p;
    uint32_t typeId = t.s_id();
    HASH_FIND_INT(_js_global_type_ht, &typeId, p);
    assert(p);
    JSObject *_tmp = JS_NewObject(cx, p->jsclass, p->proto, p->parentProto);
    js_proxy_t *pp = jsb_new_proxy(cobj, _tmp);
    JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(_tmp));

    return JS_TRUE;
}

static JSBool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    return JS_FALSE;
}
#endif
JSClass  *jsb_sdkbox_PluginSdkboxPlay_class;
JSObject *jsb_sdkbox_PluginSdkboxPlay_prototype;

#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_incrementAchievement(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 2) {
        std::string arg0;
        int arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_incrementAchievement : Error processing arguments");
        sdkbox::PluginSdkboxPlay::incrementAchievement(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_incrementAchievement : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginSdkboxPlayJS_PluginSdkboxPlay_incrementAchievement(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 2) {
        std::string arg0;
        int arg1;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginSdkboxPlay::incrementAchievement(arg0, arg1);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_getPlayerId(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        std::string ret = sdkbox::PluginSdkboxPlay::getPlayerId();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_getPlayerId : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginSdkboxPlayJS_PluginSdkboxPlay_getPlayerId(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        std::string ret = sdkbox::PluginSdkboxPlay::getPlayerId();
        jsval jsret;
        jsret = std_string_to_jsval(cx, ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_getMyScore(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 3) {
        std::string arg0;
        int arg1;
        int arg2;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
        ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_getMyScore : Error processing arguments");
        sdkbox::PluginSdkboxPlay::getMyScore(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_getMyScore : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginSdkboxPlayJS_PluginSdkboxPlay_getMyScore(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 3) {
        std::string arg0;
        int arg1;
        int arg2;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
        ok &= jsval_to_int32(cx, argv[2], (int32_t *)&arg2);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginSdkboxPlay::getMyScore(arg0, arg1, arg2);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_showAllLeaderboards(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginSdkboxPlay::showAllLeaderboards();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_showAllLeaderboards : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginSdkboxPlayJS_PluginSdkboxPlay_showAllLeaderboards(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginSdkboxPlay::showAllLeaderboards();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_getPlayerAccountField(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_getPlayerAccountField : Error processing arguments");
        std::string ret = sdkbox::PluginSdkboxPlay::getPlayerAccountField(arg0);
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_getPlayerAccountField : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginSdkboxPlayJS_PluginSdkboxPlay_getPlayerAccountField(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        std::string ret = sdkbox::PluginSdkboxPlay::getPlayerAccountField(arg0);
        jsval jsret;
        jsret = std_string_to_jsval(cx, ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_getPlayerCenteredScores(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 4) {
        std::string arg0;
        int arg1;
        int arg2;
        int arg3;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
        ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
        ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_getPlayerCenteredScores : Error processing arguments");
        sdkbox::PluginSdkboxPlay::getPlayerCenteredScores(arg0, arg1, arg2, arg3);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_getPlayerCenteredScores : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginSdkboxPlayJS_PluginSdkboxPlay_getPlayerCenteredScores(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 4) {
        std::string arg0;
        int arg1;
        int arg2;
        int arg3;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
        ok &= jsval_to_int32(cx, argv[2], (int32_t *)&arg2);
        ok &= jsval_to_int32(cx, argv[3], (int32_t *)&arg3);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginSdkboxPlay::getPlayerCenteredScores(arg0, arg1, arg2, arg3);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_showLeaderboard(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 0) {
        sdkbox::PluginSdkboxPlay::showLeaderboard();
        args.rval().setUndefined();
        return true;
    }
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_showLeaderboard : Error processing arguments");
        sdkbox::PluginSdkboxPlay::showLeaderboard(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_showLeaderboard : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginSdkboxPlayJS_PluginSdkboxPlay_showLeaderboard(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 0) {
        sdkbox::PluginSdkboxPlay::showLeaderboard();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginSdkboxPlay::showLeaderboard(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_signout(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginSdkboxPlay::signout();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_signout : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginSdkboxPlayJS_PluginSdkboxPlay_signout(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginSdkboxPlay::signout();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_isSignedIn(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        bool ret = sdkbox::PluginSdkboxPlay::isSignedIn();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_isSignedIn : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginSdkboxPlayJS_PluginSdkboxPlay_isSignedIn(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        bool ret = sdkbox::PluginSdkboxPlay::isSignedIn();
        jsval jsret;
        jsret = BOOLEAN_TO_JSVAL(ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_init(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        bool ret = sdkbox::PluginSdkboxPlay::init();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_init : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginSdkboxPlayJS_PluginSdkboxPlay_init(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        bool ret = sdkbox::PluginSdkboxPlay::init();
        jsval jsret;
        jsret = BOOLEAN_TO_JSVAL(ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_unlockAchievement(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_unlockAchievement : Error processing arguments");
        sdkbox::PluginSdkboxPlay::unlockAchievement(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_unlockAchievement : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginSdkboxPlayJS_PluginSdkboxPlay_unlockAchievement(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginSdkboxPlay::unlockAchievement(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_loadAchievements(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_loadAchievements : Error processing arguments");
        sdkbox::PluginSdkboxPlay::loadAchievements(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_loadAchievements : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginSdkboxPlayJS_PluginSdkboxPlay_loadAchievements(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(argv[0]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginSdkboxPlay::loadAchievements(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_showAchievements(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginSdkboxPlay::showAchievements();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_showAchievements : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginSdkboxPlayJS_PluginSdkboxPlay_showAchievements(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginSdkboxPlay::showAchievements();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_isConnected(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        bool ret = sdkbox::PluginSdkboxPlay::isConnected();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_isConnected : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginSdkboxPlayJS_PluginSdkboxPlay_isConnected(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        bool ret = sdkbox::PluginSdkboxPlay::isConnected();
        jsval jsret;
        jsret = BOOLEAN_TO_JSVAL(ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_submitScore(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 2) {
        std::string arg0;
        int arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_submitScore : Error processing arguments");
        sdkbox::PluginSdkboxPlay::submitScore(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_submitScore : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginSdkboxPlayJS_PluginSdkboxPlay_submitScore(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 2) {
        std::string arg0;
        int arg1;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginSdkboxPlay::submitScore(arg0, arg1);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_setSteps(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 2) {
        std::string arg0;
        int arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_setSteps : Error processing arguments");
        sdkbox::PluginSdkboxPlay::setSteps(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_setSteps : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginSdkboxPlayJS_PluginSdkboxPlay_setSteps(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 2) {
        std::string arg0;
        int arg1;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginSdkboxPlay::setSteps(arg0, arg1);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_getVersion(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        std::string ret = sdkbox::PluginSdkboxPlay::getVersion();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_getVersion : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginSdkboxPlayJS_PluginSdkboxPlay_getVersion(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        std::string ret = sdkbox::PluginSdkboxPlay::getVersion();
        jsval jsret;
        jsret = std_string_to_jsval(cx, ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_removeListener(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginSdkboxPlay::removeListener();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_removeListener : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginSdkboxPlayJS_PluginSdkboxPlay_removeListener(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginSdkboxPlay::removeListener();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_reveal(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_reveal : Error processing arguments");
        sdkbox::PluginSdkboxPlay::reveal(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_reveal : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginSdkboxPlayJS_PluginSdkboxPlay_reveal(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginSdkboxPlay::reveal(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_signin(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginSdkboxPlay::signin();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_signin : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginSdkboxPlayJS_PluginSdkboxPlay_signin(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginSdkboxPlay::signin();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif


void js_PluginSdkboxPlayJS_PluginSdkboxPlay_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (PluginSdkboxPlay)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;

#if (SDKBOX_COCOS_JSB_VERSION >= 2)
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
#else
    jsproxy = jsb_get_js_proxy(obj);
#endif

    if (jsproxy) {
        nproxy = jsb_get_native_proxy(jsproxy->ptr);

        sdkbox::PluginSdkboxPlay *nobj = static_cast<sdkbox::PluginSdkboxPlay *>(nproxy->ptr);
        if (nobj)
            delete nobj;

        jsb_remove_proxy(nproxy, jsproxy);
    }
}

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginSdkboxPlayJS_PluginSdkboxPlay(JSContext *cx, JS::HandleObject global) {
    jsb_sdkbox_PluginSdkboxPlay_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginSdkboxPlay_class->name = "PluginSdkboxPlay";
    jsb_sdkbox_PluginSdkboxPlay_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginSdkboxPlay_class->delProperty = JS_DeletePropertyStub;
    jsb_sdkbox_PluginSdkboxPlay_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginSdkboxPlay_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginSdkboxPlay_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginSdkboxPlay_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginSdkboxPlay_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginSdkboxPlay_class->finalize = js_PluginSdkboxPlayJS_PluginSdkboxPlay_finalize;
    jsb_sdkbox_PluginSdkboxPlay_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSG("__nativeObj", js_is_native_obj, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("incrementAchievement", js_PluginSdkboxPlayJS_PluginSdkboxPlay_incrementAchievement, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getPlayerId", js_PluginSdkboxPlayJS_PluginSdkboxPlay_getPlayerId, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getMyScore", js_PluginSdkboxPlayJS_PluginSdkboxPlay_getMyScore, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("showAllLeaderboards", js_PluginSdkboxPlayJS_PluginSdkboxPlay_showAllLeaderboards, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getPlayerAccountField", js_PluginSdkboxPlayJS_PluginSdkboxPlay_getPlayerAccountField, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getPlayerCenteredScores", js_PluginSdkboxPlayJS_PluginSdkboxPlay_getPlayerCenteredScores, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("showLeaderboard", js_PluginSdkboxPlayJS_PluginSdkboxPlay_showLeaderboard, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("signout", js_PluginSdkboxPlayJS_PluginSdkboxPlay_signout, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isSignedIn", js_PluginSdkboxPlayJS_PluginSdkboxPlay_isSignedIn, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginSdkboxPlayJS_PluginSdkboxPlay_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("unlockAchievement", js_PluginSdkboxPlayJS_PluginSdkboxPlay_unlockAchievement, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("loadAchievements", js_PluginSdkboxPlayJS_PluginSdkboxPlay_loadAchievements, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("showAchievements", js_PluginSdkboxPlayJS_PluginSdkboxPlay_showAchievements, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isConnected", js_PluginSdkboxPlayJS_PluginSdkboxPlay_isConnected, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("submitScore", js_PluginSdkboxPlayJS_PluginSdkboxPlay_submitScore, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setSteps", js_PluginSdkboxPlayJS_PluginSdkboxPlay_setSteps, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getVersion", js_PluginSdkboxPlayJS_PluginSdkboxPlay_getVersion, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("removeListener", js_PluginSdkboxPlayJS_PluginSdkboxPlay_removeListener, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("reveal", js_PluginSdkboxPlayJS_PluginSdkboxPlay_reveal, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("signin", js_PluginSdkboxPlayJS_PluginSdkboxPlay_signin, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginSdkboxPlay_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(), // parent proto
        jsb_sdkbox_PluginSdkboxPlay_class,
        dummy_constructor<sdkbox::PluginSdkboxPlay>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27
//  JS_SetPropertyAttributes(cx, global, "PluginSdkboxPlay", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
#if (SDKBOX_COCOS_JSB_VERSION >= 2)
    JS::RootedObject proto(cx, jsb_sdkbox_PluginSdkboxPlay_prototype);
    jsb_register_class<sdkbox::PluginSdkboxPlay>(cx, jsb_sdkbox_PluginSdkboxPlay_class, proto, JS::NullPtr());
#else
    TypeTest<sdkbox::PluginSdkboxPlay> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_sdkbox_PluginSdkboxPlay_class;
        p->proto = jsb_sdkbox_PluginSdkboxPlay_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
#endif
}
#else
void js_register_PluginSdkboxPlayJS_PluginSdkboxPlay(JSContext *cx, JSObject *global) {
    jsb_sdkbox_PluginSdkboxPlay_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginSdkboxPlay_class->name = "PluginSdkboxPlay";
    jsb_sdkbox_PluginSdkboxPlay_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginSdkboxPlay_class->delProperty = JS_DeletePropertyStub;
    jsb_sdkbox_PluginSdkboxPlay_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginSdkboxPlay_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginSdkboxPlay_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginSdkboxPlay_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginSdkboxPlay_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginSdkboxPlay_class->finalize = js_PluginSdkboxPlayJS_PluginSdkboxPlay_finalize;
    jsb_sdkbox_PluginSdkboxPlay_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        {"__nativeObj", 0, JSPROP_ENUMERATE | JSPROP_PERMANENT, JSOP_WRAPPER(js_is_native_obj), JSOP_NULLWRAPPER},
        {0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("incrementAchievement", js_PluginSdkboxPlayJS_PluginSdkboxPlay_incrementAchievement, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getPlayerId", js_PluginSdkboxPlayJS_PluginSdkboxPlay_getPlayerId, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getMyScore", js_PluginSdkboxPlayJS_PluginSdkboxPlay_getMyScore, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("showAllLeaderboards", js_PluginSdkboxPlayJS_PluginSdkboxPlay_showAllLeaderboards, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getPlayerAccountField", js_PluginSdkboxPlayJS_PluginSdkboxPlay_getPlayerAccountField, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getPlayerCenteredScores", js_PluginSdkboxPlayJS_PluginSdkboxPlay_getPlayerCenteredScores, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("showLeaderboard", js_PluginSdkboxPlayJS_PluginSdkboxPlay_showLeaderboard, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("signout", js_PluginSdkboxPlayJS_PluginSdkboxPlay_signout, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isSignedIn", js_PluginSdkboxPlayJS_PluginSdkboxPlay_isSignedIn, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginSdkboxPlayJS_PluginSdkboxPlay_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("unlockAchievement", js_PluginSdkboxPlayJS_PluginSdkboxPlay_unlockAchievement, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("loadAchievements", js_PluginSdkboxPlayJS_PluginSdkboxPlay_loadAchievements, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("showAchievements", js_PluginSdkboxPlayJS_PluginSdkboxPlay_showAchievements, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isConnected", js_PluginSdkboxPlayJS_PluginSdkboxPlay_isConnected, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("submitScore", js_PluginSdkboxPlayJS_PluginSdkboxPlay_submitScore, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setSteps", js_PluginSdkboxPlayJS_PluginSdkboxPlay_setSteps, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getVersion", js_PluginSdkboxPlayJS_PluginSdkboxPlay_getVersion, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("removeListener", js_PluginSdkboxPlayJS_PluginSdkboxPlay_removeListener, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("reveal", js_PluginSdkboxPlayJS_PluginSdkboxPlay_reveal, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("signin", js_PluginSdkboxPlayJS_PluginSdkboxPlay_signin, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginSdkboxPlay_prototype = JS_InitClass(
        cx, global,
        NULL, // parent proto
        jsb_sdkbox_PluginSdkboxPlay_class,
        dummy_constructor<sdkbox::PluginSdkboxPlay>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27
//  JS_SetPropertyAttributes(cx, global, "PluginSdkboxPlay", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginSdkboxPlay> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_sdkbox_PluginSdkboxPlay_class;
        p->proto = jsb_sdkbox_PluginSdkboxPlay_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}
#endif
#elif defined(JS_VERSION)
void js_register_PluginSdkboxPlayJS_PluginSdkboxPlay(JSContext *cx, JSObject *global) {
    jsb_sdkbox_PluginSdkboxPlay_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginSdkboxPlay_class->name = "PluginSdkboxPlay";
    jsb_sdkbox_PluginSdkboxPlay_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginSdkboxPlay_class->delProperty = JS_PropertyStub;
    jsb_sdkbox_PluginSdkboxPlay_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginSdkboxPlay_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginSdkboxPlay_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginSdkboxPlay_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginSdkboxPlay_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginSdkboxPlay_class->finalize = js_PluginSdkboxPlayJS_PluginSdkboxPlay_finalize;
    jsb_sdkbox_PluginSdkboxPlay_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    JSPropertySpec *properties = NULL;

    JSFunctionSpec *funcs = NULL;

    static JSFunctionSpec st_funcs[] = {
        JS_FN("incrementAchievement", js_PluginSdkboxPlayJS_PluginSdkboxPlay_incrementAchievement, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getPlayerId", js_PluginSdkboxPlayJS_PluginSdkboxPlay_getPlayerId, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getMyScore", js_PluginSdkboxPlayJS_PluginSdkboxPlay_getMyScore, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("showAllLeaderboards", js_PluginSdkboxPlayJS_PluginSdkboxPlay_showAllLeaderboards, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getPlayerAccountField", js_PluginSdkboxPlayJS_PluginSdkboxPlay_getPlayerAccountField, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getPlayerCenteredScores", js_PluginSdkboxPlayJS_PluginSdkboxPlay_getPlayerCenteredScores, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("showLeaderboard", js_PluginSdkboxPlayJS_PluginSdkboxPlay_showLeaderboard, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("signout", js_PluginSdkboxPlayJS_PluginSdkboxPlay_signout, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isSignedIn", js_PluginSdkboxPlayJS_PluginSdkboxPlay_isSignedIn, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginSdkboxPlayJS_PluginSdkboxPlay_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("unlockAchievement", js_PluginSdkboxPlayJS_PluginSdkboxPlay_unlockAchievement, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("loadAchievements", js_PluginSdkboxPlayJS_PluginSdkboxPlay_loadAchievements, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("showAchievements", js_PluginSdkboxPlayJS_PluginSdkboxPlay_showAchievements, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isConnected", js_PluginSdkboxPlayJS_PluginSdkboxPlay_isConnected, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("submitScore", js_PluginSdkboxPlayJS_PluginSdkboxPlay_submitScore, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setSteps", js_PluginSdkboxPlayJS_PluginSdkboxPlay_setSteps, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getVersion", js_PluginSdkboxPlayJS_PluginSdkboxPlay_getVersion, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("removeListener", js_PluginSdkboxPlayJS_PluginSdkboxPlay_removeListener, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("reveal", js_PluginSdkboxPlayJS_PluginSdkboxPlay_reveal, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("signin", js_PluginSdkboxPlayJS_PluginSdkboxPlay_signin, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginSdkboxPlay_prototype = JS_InitClass(
        cx, global,
        NULL, // parent proto
        jsb_sdkbox_PluginSdkboxPlay_class,
        dummy_constructor<sdkbox::PluginSdkboxPlay>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
    JSBool found;
    JS_SetPropertyAttributes(cx, global, "PluginSdkboxPlay", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginSdkboxPlay> t;
    js_type_class_t *p;
    uint32_t typeId = t.s_id();
    HASH_FIND_INT(_js_global_type_ht, &typeId, p);
    if (!p) {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->type = typeId;
        p->jsclass = jsb_sdkbox_PluginSdkboxPlay_class;
        p->proto = jsb_sdkbox_PluginSdkboxPlay_prototype;
        p->parentProto = NULL;
        HASH_ADD_INT(_js_global_type_ht, type, p);
    }
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void register_all_PluginSdkboxPlayJS(JSContext* cx, JS::HandleObject obj) {
    // Get the ns
    JS::RootedObject ns(cx);
    get_or_create_js_obj(cx, obj, "sdkbox", &ns);

    js_register_PluginSdkboxPlayJS_PluginSdkboxPlay(cx, ns);

    sdkbox::setProjectType("js");
}
#else
void register_all_PluginSdkboxPlayJS(JSContext* cx, JSObject* obj) {
    // first, try to get the ns
    JS::RootedValue nsval(cx);
    JS::RootedObject ns(cx);
    JS_GetProperty(cx, obj, "sdkbox", &nsval);
    if (nsval == JSVAL_VOID) {
        ns = JS_NewObject(cx, NULL, NULL, NULL);
        nsval = OBJECT_TO_JSVAL(ns);
        JS_SetProperty(cx, obj, "sdkbox", nsval);
    } else {
        JS_ValueToObject(cx, nsval, &ns);
    }
    obj = ns;

    js_register_PluginSdkboxPlayJS_PluginSdkboxPlay(cx, obj);

    sdkbox::setProjectType("js");
}
#endif
#elif defined(JS_VERSION)
void register_all_PluginSdkboxPlayJS(JSContext* cx, JSObject* obj) {
    // first, try to get the ns
    jsval nsval;
    JSObject *ns;
    JS_GetProperty(cx, obj, "sdkbox", &nsval);
    if (nsval == JSVAL_VOID) {
        ns = JS_NewObject(cx, NULL, NULL, NULL);
        nsval = OBJECT_TO_JSVAL(ns);
        JS_SetProperty(cx, obj, "sdkbox", &nsval);
    } else {
        JS_ValueToObject(cx, nsval, &ns);
    }
    obj = ns;

    js_register_PluginSdkboxPlayJS_PluginSdkboxPlay(cx, obj);

    sdkbox::setProjectType("js");
}
#endif