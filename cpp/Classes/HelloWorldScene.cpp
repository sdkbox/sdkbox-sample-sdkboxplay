#include "HelloWorldScene.h"

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#else
#include <io.h>
#include <WS2tcpip.h>
#endif

USING_NS_CC;

using namespace sdkbox;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

static int score;

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    Size size = CCDirector::getInstance()->getWinSize();
    std::string defaultFont("arial.ttf");
    int defaultFontSize = 32;

    char buffer[128];
    
    time_t tt;
    time(&tt);
    score =  tt%10000;
    sprintf( buffer, "Send score of %d", score);
    std::string str = buffer;
    
    Menu* menu = Menu::create(
                      MenuItemFont::create("Connect/Disconnect",    CC_CALLBACK_1(HelloWorld::connectOrDisconnect, this)),
                      MenuItemFont::create("Show Leaderboard ldb1", CC_CALLBACK_1(HelloWorld::showLeaderboard, this)),
                      MenuItemFont::create("Achievements", CC_CALLBACK_1(HelloWorld::showAchievements, this)),
                      MenuItemFont::create("Unlock Craftsman", CC_CALLBACK_1(HelloWorld::achievement_craftsman, this)),
                      MenuItemFont::create("Unlock Hunter", CC_CALLBACK_1(HelloWorld::achievement_hunter, this)),
                      MenuItemFont::create("Unlock Ten Games", CC_CALLBACK_1(HelloWorld::achievement_ten_games, this)),
                      MenuItemFont::create("Unlock incremental ", CC_CALLBACK_1(HelloWorld::achievement_incremental, this)),
                      MenuItemFont::create(str, CC_CALLBACK_1(HelloWorld::send_score, this)),
                      NULL
    );

    menu->alignItemsVerticallyWithPadding(5);
    menu->setPosition(size.width/2, size.height/2);
    addChild(menu);
        
    _txtStat = Label::create("No action yet.", "fonts/Marker Felt.ttf",24);
    _txtStat->setAnchorPoint(cocos2d::Point(0, 0));
    _txtStat->setPosition(cocos2d::Point(10, 65));
    addChild(_txtStat);
    
    _txtC = Label::create("Disconnected", "fonts/Marker Felt.ttf",24);
    _txtC->setAnchorPoint(cocos2d::Point(0, 0));
    _txtC->setPosition(cocos2d::Point(10, 85));
    addChild(_txtC);

    sdkbox::PluginSdkboxPlay::setListener(this);
    sdkbox::PluginSdkboxPlay::init();

    return true;
}

void HelloWorld::connectOrDisconnect(cocos2d::CCObject *sender) {
    if ( sdkbox::PluginSdkboxPlay::isSignedIn()) {
        sdkbox::PluginSdkboxPlay::signout();
    } else {
        sdkbox::PluginSdkboxPlay::signin();
    }
}

void HelloWorld::showLeaderboard(cocos2d::CCObject *sender) {
    sdkbox::PluginSdkboxPlay::showLeaderboard("ldb1");
}

void HelloWorld::showAchievements(cocos2d::CCObject *sender) {
    sdkbox::PluginSdkboxPlay::showAchievements();
}

void HelloWorld::achievement_craftsman(cocos2d::CCObject *sender) {
    sdkbox::PluginSdkboxPlay::unlockAchievement("craftsman");
}

void HelloWorld::achievement_hunter(cocos2d::CCObject *sender) {
    sdkbox::PluginSdkboxPlay::unlockAchievement("hunter");
}

void HelloWorld::achievement_ten_games(cocos2d::CCObject *sender) {
    sdkbox::PluginSdkboxPlay::unlockAchievement("ten-games");
}

void HelloWorld::achievement_incremental(cocos2d::CCObject *sender) {
    sdkbox::PluginSdkboxPlay::incrementAchievement("incremental",1);
}

void HelloWorld::send_score(cocos2d::CCObject *sender) {
    sdkbox::PluginSdkboxPlay::submitScore("ldb1", score);
}

void HelloWorld::onScoreSubmitted( const std::string& leaderboard_name, int score, bool maxScoreAllTime, bool maxScoreWeek, bool maxScoreToday ) {
    CCLOG("on score %d submitted to leaderboard:%s", score, leaderboard_name.c_str() );
    CCLOG("all time hi %d", maxScoreAllTime ? 1 : 0 );
    CCLOG("weekly hi %d", maxScoreWeek ? 1 : 0 );
    CCLOG("daily hi %d", maxScoreToday ? 1 : 0 );
}

void HelloWorld::onIncrementalAchievementUnlocked( const std::string& achievement_name ) {
    CCLOG("incremental achievement %s unlocked.", achievement_name.c_str());
}

void HelloWorld::onIncrementalAchievementStep( const std::string& achievement_name, int step ) {
    CCLOG("incremental achievent %s step: %d", achievement_name.c_str(), step);
}

void HelloWorld::onAchievementUnlocked( const std::string& achievement_name, bool newlyUnlocked ) {
    CCLOG("achievement %s unlocked (new %d)", achievement_name.c_str(), newlyUnlocked ? 1 : 0);
}

void HelloWorld::onConnectionStatusChanged(int connection_status) {
    CCLOG("connection status change: %d", connection_status);
    
    char str[256];
    sprintf(str, "Connection status: %d. Is Connected: %d", connection_status, sdkbox::PluginSdkboxPlay::isConnected() ? 1 : 0 );
    
    _txtStat->setString( str );
    
    if ( connection_status==1000 ) {
        std::string sstr = PluginSdkboxPlay::getPlayerId() +
            ":'" +
            PluginSdkboxPlay::getPlayerAccountField("name")+
            "(" +
            PluginSdkboxPlay::getPlayerAccountField("display_name")+
            ")'";
        
        _txtC->setString( sstr );
    } else {
        _txtC->setString( "" );
    }
}