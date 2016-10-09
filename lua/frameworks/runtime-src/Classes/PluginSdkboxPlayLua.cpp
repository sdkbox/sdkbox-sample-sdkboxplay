#include "PluginSdkboxPlayLua.hpp"
#include "PluginSdkboxPlay/PluginSdkboxPlay.h"
#include "SDKBoxLuaHelper.h"
#include "sdkbox/Sdkbox.h"



int lua_PluginSdkboxPlayLua_PluginSdkboxPlay_incrementAchievement(lua_State* tolua_S)
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_incrementAchievement'", nullptr);
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
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_incrementAchievement'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginSdkboxPlayLua_PluginSdkboxPlay_getPlayerId(lua_State* tolua_S)
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_getPlayerId'", nullptr);
            return 0;
        }
        std::string ret = sdkbox::PluginSdkboxPlay::getPlayerId();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginSdkboxPlay:getPlayerId",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_getPlayerId'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginSdkboxPlayLua_PluginSdkboxPlay_getMyScore(lua_State* tolua_S)
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

    if (argc == 3)
    {
        std::string arg0;
        int arg1;
        int arg2;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginSdkboxPlay:getMyScore");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "sdkbox.PluginSdkboxPlay:getMyScore");
        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "sdkbox.PluginSdkboxPlay:getMyScore");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_getMyScore'", nullptr);
            return 0;
        }
        sdkbox::PluginSdkboxPlay::getMyScore(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginSdkboxPlay:getMyScore",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_getMyScore'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginSdkboxPlayLua_PluginSdkboxPlay_showAllLeaderboards(lua_State* tolua_S)
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_showAllLeaderboards'", nullptr);
            return 0;
        }
        sdkbox::PluginSdkboxPlay::showAllLeaderboards();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginSdkboxPlay:showAllLeaderboards",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_showAllLeaderboards'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginSdkboxPlayLua_PluginSdkboxPlay_getPlayerAccountField(lua_State* tolua_S)
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
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginSdkboxPlay:getPlayerAccountField");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_getPlayerAccountField'", nullptr);
            return 0;
        }
        std::string ret = sdkbox::PluginSdkboxPlay::getPlayerAccountField(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginSdkboxPlay:getPlayerAccountField",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_getPlayerAccountField'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginSdkboxPlayLua_PluginSdkboxPlay_getPlayerCenteredScores(lua_State* tolua_S)
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

    if (argc == 4)
    {
        std::string arg0;
        int arg1;
        int arg2;
        int arg3;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginSdkboxPlay:getPlayerCenteredScores");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "sdkbox.PluginSdkboxPlay:getPlayerCenteredScores");
        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "sdkbox.PluginSdkboxPlay:getPlayerCenteredScores");
        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "sdkbox.PluginSdkboxPlay:getPlayerCenteredScores");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_getPlayerCenteredScores'", nullptr);
            return 0;
        }
        sdkbox::PluginSdkboxPlay::getPlayerCenteredScores(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginSdkboxPlay:getPlayerCenteredScores",argc, 4);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_getPlayerCenteredScores'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginSdkboxPlayLua_PluginSdkboxPlay_showLeaderboard(lua_State* tolua_S)
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_showLeaderboard'", nullptr);
            return 0;
        }
        sdkbox::PluginSdkboxPlay::showLeaderboard();
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginSdkboxPlay:showLeaderboard");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_showLeaderboard'", nullptr);
            return 0;
        }
        sdkbox::PluginSdkboxPlay::showLeaderboard(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginSdkboxPlay:showLeaderboard",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_showLeaderboard'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginSdkboxPlayLua_PluginSdkboxPlay_signout(lua_State* tolua_S)
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_signout'", nullptr);
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
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_signout'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginSdkboxPlayLua_PluginSdkboxPlay_isSignedIn(lua_State* tolua_S)
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_isSignedIn'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginSdkboxPlay::isSignedIn();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginSdkboxPlay:isSignedIn",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_isSignedIn'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginSdkboxPlayLua_PluginSdkboxPlay_init(lua_State* tolua_S)
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_init'", nullptr);
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
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_init'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginSdkboxPlayLua_PluginSdkboxPlay_unlockAchievement(lua_State* tolua_S)
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_unlockAchievement'", nullptr);
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
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_unlockAchievement'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginSdkboxPlayLua_PluginSdkboxPlay_loadAchievements(lua_State* tolua_S)
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
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginSdkboxPlay:loadAchievements");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_loadAchievements'", nullptr);
            return 0;
        }
        sdkbox::PluginSdkboxPlay::loadAchievements(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginSdkboxPlay:loadAchievements",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_loadAchievements'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginSdkboxPlayLua_PluginSdkboxPlay_showAchievements(lua_State* tolua_S)
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_showAchievements'", nullptr);
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
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_showAchievements'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginSdkboxPlayLua_PluginSdkboxPlay_isConnected(lua_State* tolua_S)
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_isConnected'", nullptr);
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
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_isConnected'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginSdkboxPlayLua_PluginSdkboxPlay_submitScore(lua_State* tolua_S)
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_submitScore'", nullptr);
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
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_submitScore'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginSdkboxPlayLua_PluginSdkboxPlay_setSteps(lua_State* tolua_S)
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
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginSdkboxPlay:setSteps");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "sdkbox.PluginSdkboxPlay:setSteps");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_setSteps'", nullptr);
            return 0;
        }
        sdkbox::PluginSdkboxPlay::setSteps(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginSdkboxPlay:setSteps",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_setSteps'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginSdkboxPlayLua_PluginSdkboxPlay_getVersion(lua_State* tolua_S)
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_getVersion'", nullptr);
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
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_getVersion'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginSdkboxPlayLua_PluginSdkboxPlay_removeListener(lua_State* tolua_S)
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_removeListener'", nullptr);
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
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_removeListener'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginSdkboxPlayLua_PluginSdkboxPlay_reveal(lua_State* tolua_S)
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
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginSdkboxPlay:reveal");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_reveal'", nullptr);
            return 0;
        }
        sdkbox::PluginSdkboxPlay::reveal(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginSdkboxPlay:reveal",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_reveal'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginSdkboxPlayLua_PluginSdkboxPlay_signin(lua_State* tolua_S)
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_signin'", nullptr);
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
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxPlayLua_PluginSdkboxPlay_signin'.",&tolua_err);
#endif
    return 0;
}
static int lua_PluginSdkboxPlayLua_PluginSdkboxPlay_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PluginSdkboxPlay)");
    return 0;
}

int lua_register_PluginSdkboxPlayLua_PluginSdkboxPlay(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"sdkbox.PluginSdkboxPlay");
    tolua_cclass(tolua_S,"PluginSdkboxPlay","sdkbox.PluginSdkboxPlay","",nullptr);

    tolua_beginmodule(tolua_S,"PluginSdkboxPlay");
        tolua_function(tolua_S,"incrementAchievement", lua_PluginSdkboxPlayLua_PluginSdkboxPlay_incrementAchievement);
        tolua_function(tolua_S,"getPlayerId", lua_PluginSdkboxPlayLua_PluginSdkboxPlay_getPlayerId);
        tolua_function(tolua_S,"getMyScore", lua_PluginSdkboxPlayLua_PluginSdkboxPlay_getMyScore);
        tolua_function(tolua_S,"showAllLeaderboards", lua_PluginSdkboxPlayLua_PluginSdkboxPlay_showAllLeaderboards);
        tolua_function(tolua_S,"getPlayerAccountField", lua_PluginSdkboxPlayLua_PluginSdkboxPlay_getPlayerAccountField);
        tolua_function(tolua_S,"getPlayerCenteredScores", lua_PluginSdkboxPlayLua_PluginSdkboxPlay_getPlayerCenteredScores);
        tolua_function(tolua_S,"showLeaderboard", lua_PluginSdkboxPlayLua_PluginSdkboxPlay_showLeaderboard);
        tolua_function(tolua_S,"signout", lua_PluginSdkboxPlayLua_PluginSdkboxPlay_signout);
        tolua_function(tolua_S,"isSignedIn", lua_PluginSdkboxPlayLua_PluginSdkboxPlay_isSignedIn);
        tolua_function(tolua_S,"init", lua_PluginSdkboxPlayLua_PluginSdkboxPlay_init);
        tolua_function(tolua_S,"unlockAchievement", lua_PluginSdkboxPlayLua_PluginSdkboxPlay_unlockAchievement);
        tolua_function(tolua_S,"loadAchievements", lua_PluginSdkboxPlayLua_PluginSdkboxPlay_loadAchievements);
        tolua_function(tolua_S,"showAchievements", lua_PluginSdkboxPlayLua_PluginSdkboxPlay_showAchievements);
        tolua_function(tolua_S,"isConnected", lua_PluginSdkboxPlayLua_PluginSdkboxPlay_isConnected);
        tolua_function(tolua_S,"submitScore", lua_PluginSdkboxPlayLua_PluginSdkboxPlay_submitScore);
        tolua_function(tolua_S,"setSteps", lua_PluginSdkboxPlayLua_PluginSdkboxPlay_setSteps);
        tolua_function(tolua_S,"getVersion", lua_PluginSdkboxPlayLua_PluginSdkboxPlay_getVersion);
        tolua_function(tolua_S,"removeListener", lua_PluginSdkboxPlayLua_PluginSdkboxPlay_removeListener);
        tolua_function(tolua_S,"reveal", lua_PluginSdkboxPlayLua_PluginSdkboxPlay_reveal);
        tolua_function(tolua_S,"signin", lua_PluginSdkboxPlayLua_PluginSdkboxPlay_signin);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(sdkbox::PluginSdkboxPlay).name();
    g_luaType[typeName] = "sdkbox.PluginSdkboxPlay";
    g_typeCast["PluginSdkboxPlay"] = "sdkbox.PluginSdkboxPlay";
    return 1;
}
TOLUA_API int register_all_PluginSdkboxPlayLua(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"sdkbox",0);
	tolua_beginmodule(tolua_S,"sdkbox");

	lua_register_PluginSdkboxPlayLua_PluginSdkboxPlay(tolua_S);

	tolua_endmodule(tolua_S);

	sdkbox::setProjectType("lua");
	return 1;
}

