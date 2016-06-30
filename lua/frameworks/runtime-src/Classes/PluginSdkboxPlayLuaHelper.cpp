
#include "PluginSdkboxPlayLuaHelper.h"
#include "PluginSdkboxPlay/PluginSdkboxPlay.h"
#include "SDKBoxLuaHelper.h"

class SdkboxPlayListenerLua : public sdkbox::SdkboxPlayListener {
public:
    SdkboxPlayListenerLua(): mLuaHandler(0) {

    }
    ~SdkboxPlayListenerLua() {
        resetHandler();
    }

    void setHandler(int luaHandler) {
        if (mLuaHandler == luaHandler) {
            return;
        }
        resetHandler();
        mLuaHandler = luaHandler;
    }

    void resetHandler() {
        if (0 == mLuaHandler) {
            return;
        }

        LUAENGINE->removeScriptHandler(mLuaHandler);
        mLuaHandler = 0;
    }

    virtual void onConnectionStatusChanged( int status ) {
        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onConnectionStatusChanged")));
        dict.insert(std::make_pair("status", LuaValue::intValue((int)status)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    virtual void onScoreSubmitted(
        const std::string& leaderboard_name,
        int score,
        bool alltime,
        bool week,
        bool day) {

        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onScoreSubmitted")));
        dict.insert(std::make_pair("leaderboard_name", LuaValue::stringValue(leaderboard_name)));
        dict.insert(std::make_pair("score", LuaValue::intValue(score)));
        dict.insert(std::make_pair("alltime_best", LuaValue::booleanValue(alltime)));
        dict.insert(std::make_pair("weekly_best", LuaValue::booleanValue(week)));
        dict.insert(std::make_pair("daily_best", LuaValue::booleanValue(day)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);

    }

    virtual void onMyScore( const std::string& leaderboard_name, int time_span, int collection_type, long score ) {
        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onMyScore")));
        dict.insert(std::make_pair("leaderboard_name", LuaValue::stringValue(leaderboard_name)));
        dict.insert(std::make_pair("time_span", LuaValue::intValue(time_span)));
        dict.insert(std::make_pair("collection_type", LuaValue::intValue(collection_type)));
        dict.insert(std::make_pair("score", LuaValue::intValue(score)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    virtual void onMyScoreError( const std::string& leaderboard_name, int time_span, int collection_type, int error_code, const std::string& error_description) {
        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onMyScoreError")));
        dict.insert(std::make_pair("leaderboard_name", LuaValue::stringValue(leaderboard_name)));
        dict.insert(std::make_pair("time_span", LuaValue::intValue(time_span)));
        dict.insert(std::make_pair("collection_type", LuaValue::intValue(collection_type)));
        dict.insert(std::make_pair("error_code", LuaValue::intValue(error_code)));
        dict.insert(std::make_pair("error_description", LuaValue::stringValue(error_description)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    virtual void onPlayerCenteredScores( const std::string& leaderboard_name,
                                        int time_span,
                                        int collection_type,
                                        const std::string& json_with_score_entries ) {
        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onPlayerCenteredScores")));
        dict.insert(std::make_pair("leaderboard_name", LuaValue::stringValue(leaderboard_name)));
        dict.insert(std::make_pair("time_span", LuaValue::intValue(time_span)));
        dict.insert(std::make_pair("collection_type", LuaValue::intValue(collection_type)));
        dict.insert(std::make_pair("json_with_score_entries", LuaValue::stringValue(json_with_score_entries)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    virtual void onPlayerCenteredScoresError( const std::string& leaderboard_name,
                                             int time_span,
                                             int collection_type,
                                             int error_code,
                                             const std::string& error_description) {
        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onPlayerCenteredScoresError")));
        dict.insert(std::make_pair("leaderboard_name", LuaValue::stringValue(leaderboard_name)));
        dict.insert(std::make_pair("time_span", LuaValue::intValue(time_span)));
        dict.insert(std::make_pair("collection_type", LuaValue::intValue(collection_type)));
        dict.insert(std::make_pair("error_code", LuaValue::intValue(error_code)));
        dict.insert(std::make_pair("error_description", LuaValue::stringValue(error_description)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    virtual void onIncrementalAchievementUnlocked( const std::string& achievement_name ) {

        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onIncrementalAchievementUnlocked")));
        dict.insert(std::make_pair("achievement_name", LuaValue::stringValue(achievement_name)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    virtual void onIncrementalAchievementStep( const std::string& achievement_name, int step ) {

        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onIncrementalAchievementStep")));
        dict.insert(std::make_pair("achievement_name", LuaValue::stringValue(achievement_name)));
        dict.insert(std::make_pair("step", LuaValue::intValue(step)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    virtual void onIncrementalAchievementStepError( const std::string& achievement_name, int steps, int error_code, const std::string& error_description ) {
        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onIncrementalAchievementStepError")));
        dict.insert(std::make_pair("achievement_name", LuaValue::stringValue(achievement_name)));
        dict.insert(std::make_pair("steps", LuaValue::intValue(steps)));
        dict.insert(std::make_pair("error_code", LuaValue::intValue(error_code)));
        dict.insert(std::make_pair("error_description", LuaValue::stringValue(error_description)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    virtual void onAchievementUnlocked( const std::string& achievement_name, bool newlyUnlocked ) {

        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onAchievementUnlocked")));
        dict.insert(std::make_pair("achievement_name", LuaValue::stringValue(achievement_name)));
        dict.insert(std::make_pair("newlyUnlocked", LuaValue::booleanValue(newlyUnlocked)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    virtual void onAchievementUnlockError( const std::string& achievement_name, int error_code, const std::string& error_description ) {
        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onIncrementalAchievementStepError")));
        dict.insert(std::make_pair("achievement_name", LuaValue::stringValue(achievement_name)));
        dict.insert(std::make_pair("error_code", LuaValue::intValue(error_code)));
        dict.insert(std::make_pair("error_description", LuaValue::stringValue(error_description)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    virtual void onAchievementsLoaded( bool reload_forced, const std::string& json_achievements_info ) {
        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onAchievementsLoaded")));
        dict.insert(std::make_pair("reload_forced", LuaValue::booleanValue(reload_forced)));
        dict.insert(std::make_pair("json_achievements_info", LuaValue::stringValue(json_achievements_info)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    virtual void onSetSteps( const std::string& step_name, int steps ) {
        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onSetSteps")));
        dict.insert(std::make_pair("step_name", LuaValue::stringValue(step_name)));
        dict.insert(std::make_pair("steps", LuaValue::intValue(steps)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    virtual void onSetStepsError( const std::string& step_name, int steps, int error_code, const std::string& error_description ) {
        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onSetStepsError")));
        dict.insert(std::make_pair("step_name", LuaValue::stringValue(step_name)));
        dict.insert(std::make_pair("steps", LuaValue::intValue(steps)));
        dict.insert(std::make_pair("error_code", LuaValue::intValue(error_code)));
        dict.insert(std::make_pair("error_description", LuaValue::stringValue(error_description)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    virtual void onReveal( const std::string& reveal_name) {
        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onReveal")));
        dict.insert(std::make_pair("reveal_name", LuaValue::stringValue(reveal_name)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    virtual void onRevealError( const std::string& reveal_name, int error_code, const std::string& error_description ) {
        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onRevealError")));
        dict.insert(std::make_pair("reveal_name", LuaValue::stringValue(reveal_name)));
        dict.insert(std::make_pair("error_code", LuaValue::intValue(error_code)));
        dict.insert(std::make_pair("error_description", LuaValue::stringValue(error_description)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }


private:
    int mLuaHandler;
};

int lua_PluginSdkboxPlayLua_PluginSdkboxPlay_setListener(lua_State* tolua_S) {
    int argc = 0;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginSdkboxPlay",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
#if COCOS2D_DEBUG >= 1
        if (!toluafix_isfunction(tolua_S, 2 , "LUA_FUNCTION",0,&tolua_err))
        {
            goto tolua_lerror;
        }
#endif
        LUA_FUNCTION handler = (  toluafix_ref_function(tolua_S,2,0));
        SdkboxPlayListenerLua* lis = static_cast<SdkboxPlayListenerLua*> (sdkbox::PluginSdkboxPlay::getListener());
        if (nullptr == lis) {
            lis = new SdkboxPlayListenerLua();
        }
        lis->setHandler(handler);
        sdkbox::PluginSdkboxPlay::setListener(lis);

        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginSdkboxPlay::setListener",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_setListener'.",&tolua_err);
#endif
    return 0;
}

int extern_PluginSdkboxPlay(lua_State* L) {
    if (nullptr == L) {
        return 0;
    }

    lua_pushstring(L, "sdkbox.PluginSdkboxPlay");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1))
    {
        tolua_function(L,"setListener", lua_PluginSdkboxPlayLua_PluginSdkboxPlay_setListener);
    }
     lua_pop(L, 1);

    return 1;
}

TOLUA_API int register_all_PluginSdkboxPlayLua_helper(lua_State* L) {
    tolua_module(L,"sdkbox",0);
    tolua_beginmodule(L,"sdkbox");

    extern_PluginSdkboxPlay(L);

    tolua_endmodule(L);
    return 1;
}


