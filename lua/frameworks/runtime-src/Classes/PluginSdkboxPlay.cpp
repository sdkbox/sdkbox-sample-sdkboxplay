#include "PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay.hpp"
#include "PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay/PluginSdkboxPlay.h"
#include "tolua_fix.h"
#include "SDKBoxLuaHelper.h"
#include "sdkbox/sdkbox.h"



int lua_PluginSdkboxPlay_PluginSdkboxPlay_signout(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginSdkboxPlay",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSdkboxPlay_PluginSdkboxPlay_signout'", nullptr);
            return 0;
        }
        sdkbox::PluginSdkboxPlay::signout();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginSdkboxPlay:signout",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxPlay_PluginSdkboxPlay_signout'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginSdkboxPlay_PluginSdkboxPlay_incrementAchievement(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginSdkboxPlay",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        int arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginSdkboxPlay:incrementAchievement");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "sdkbox.PluginSdkboxPlay:incrementAchievement");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSdkboxPlay_PluginSdkboxPlay_incrementAchievement'", nullptr);
            return 0;
        }
        sdkbox::PluginSdkboxPlay::incrementAchievement(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginSdkboxPlay:incrementAchievement",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxPlay_PluginSdkboxPlay_incrementAchievement'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginSdkboxPlay_PluginSdkboxPlay_showLeaderboard(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginSdkboxPlay",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginSdkboxPlay:showLeaderboard");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSdkboxPlay_PluginSdkboxPlay_showLeaderboard'", nullptr);
            return 0;
        }
        sdkbox::PluginSdkboxPlay::showLeaderboard(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginSdkboxPlay:showLeaderboard",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxPlay_PluginSdkboxPlay_showLeaderboard'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginSdkboxPlay_PluginSdkboxPlay_isConnected(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginSdkboxPlay",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSdkboxPlay_PluginSdkboxPlay_isConnected'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginSdkboxPlay::isConnected();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginSdkboxPlay:isConnected",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxPlay_PluginSdkboxPlay_isConnected'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginSdkboxPlay_PluginSdkboxPlay_showAchievements(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginSdkboxPlay",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSdkboxPlay_PluginSdkboxPlay_showAchievements'", nullptr);
            return 0;
        }
        sdkbox::PluginSdkboxPlay::showAchievements();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginSdkboxPlay:showAchievements",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxPlay_PluginSdkboxPlay_showAchievements'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginSdkboxPlay_PluginSdkboxPlay_signin(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginSdkboxPlay",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSdkboxPlay_PluginSdkboxPlay_signin'", nullptr);
            return 0;
        }
        sdkbox::PluginSdkboxPlay::signin();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginSdkboxPlay:signin",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxPlay_PluginSdkboxPlay_signin'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginSdkboxPlay_PluginSdkboxPlay_init(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginSdkboxPlay",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSdkboxPlay_PluginSdkboxPlay_init'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginSdkboxPlay::init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginSdkboxPlay:init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxPlay_PluginSdkboxPlay_init'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginSdkboxPlay_PluginSdkboxPlay_submitScore(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginSdkboxPlay",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        int arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginSdkboxPlay:submitScore");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "sdkbox.PluginSdkboxPlay:submitScore");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSdkboxPlay_PluginSdkboxPlay_submitScore'", nullptr);
            return 0;
        }
        sdkbox::PluginSdkboxPlay::submitScore(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginSdkboxPlay:submitScore",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxPlay_PluginSdkboxPlay_submitScore'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginSdkboxPlay_PluginSdkboxPlay_unlockAchievement(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginSdkboxPlay",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginSdkboxPlay:unlockAchievement");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSdkboxPlay_PluginSdkboxPlay_unlockAchievement'", nullptr);
            return 0;
        }
        sdkbox::PluginSdkboxPlay::unlockAchievement(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginSdkboxPlay:unlockAchievement",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxPlay_PluginSdkboxPlay_unlockAchievement'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginSdkboxPlay_PluginSdkboxPlay_getVersion(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginSdkboxPlay",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSdkboxPlay_PluginSdkboxPlay_getVersion'", nullptr);
            return 0;
        }
        std::string ret = sdkbox::PluginSdkboxPlay::getVersion();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginSdkboxPlay:getVersion",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxPlay_PluginSdkboxPlay_getVersion'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginSdkboxPlay_PluginSdkboxPlay_removeListener(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginSdkboxPlay",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSdkboxPlay_PluginSdkboxPlay_removeListener'", nullptr);
            return 0;
        }
        sdkbox::PluginSdkboxPlay::removeListener();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginSdkboxPlay:removeListener",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxPlay_PluginSdkboxPlay_removeListener'.",&tolua_err);
#endif
    return 0;
}
static int lua_PluginSdkboxPlay_PluginSdkboxPlay_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PluginSdkboxPlay)");
    return 0;
}

int lua_register_PluginSdkboxPlay_PluginSdkboxPlay(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"sdkbox.PluginSdkboxPlay");
    tolua_cclass(tolua_S,"PluginSdkboxPlay","sdkbox.PluginSdkboxPlay","",nullptr);

    tolua_beginmodule(tolua_S,"PluginSdkboxPlay");
        tolua_function(tolua_S,"signout", lua_PluginSdkboxPlay_PluginSdkboxPlay_signout);
        tolua_function(tolua_S,"incrementAchievement", lua_PluginSdkboxPlay_PluginSdkboxPlay_incrementAchievement);
        tolua_function(tolua_S,"showLeaderboard", lua_PluginSdkboxPlay_PluginSdkboxPlay_showLeaderboard);
        tolua_function(tolua_S,"isConnected", lua_PluginSdkboxPlay_PluginSdkboxPlay_isConnected);
        tolua_function(tolua_S,"showAchievements", lua_PluginSdkboxPlay_PluginSdkboxPlay_showAchievements);
        tolua_function(tolua_S,"signin", lua_PluginSdkboxPlay_PluginSdkboxPlay_signin);
        tolua_function(tolua_S,"init", lua_PluginSdkboxPlay_PluginSdkboxPlay_init);
        tolua_function(tolua_S,"submitScore", lua_PluginSdkboxPlay_PluginSdkboxPlay_submitScore);
        tolua_function(tolua_S,"unlockAchievement", lua_PluginSdkboxPlay_PluginSdkboxPlay_unlockAchievement);
        tolua_function(tolua_S,"getVersion", lua_PluginSdkboxPlay_PluginSdkboxPlay_getVersion);
        tolua_function(tolua_S,"removeListener", lua_PluginSdkboxPlay_PluginSdkboxPlay_removeListener);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(sdkbox::PluginSdkboxPlay).name();
    g_luaType[typeName] = "sdkbox.PluginSdkboxPlay";
    g_typeCast["PluginSdkboxPlay"] = "sdkbox.PluginSdkboxPlay";
    return 1;
}
TOLUA_API int register_all_PluginSdkboxPlay(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"sdkbox",0);
	tolua_beginmodule(tolua_S,"sdkbox");

	lua_register_PluginSdkboxPlay_PluginSdkboxPlay(tolua_S);

	tolua_endmodule(tolua_S);

	sdkbox::setProjectType("lua");
	return 1;
}

