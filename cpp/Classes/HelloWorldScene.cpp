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

#include <vector>
#include <string>

//#define ENABLE_CLOUD_SAVE

USING_NS_CC;
using namespace sdkbox;
using namespace std;

std::vector<std::string> msgbuf;
static void showMsg(const std::string& msg) {
    static int msgIndex = 0;
    //
    Label *label = dynamic_cast<Label*>(Director::getInstance()->getNotificationNode());
    if (label == nullptr) {
        auto size = Director::getInstance()->getWinSize();
        label = Label::createWithSystemFont("test", "arial", 16);
        label->setAnchorPoint(ccp(0,0));
        label->setTextColor(Color4B(0, 255, 0, 255));
        label->setPosition(10, size.height*0.1);
        Director::getInstance()->setNotificationNode(label);
    }

    stringstream buf;
    buf << msgIndex++ << " " << msg << "\n";
    msgbuf.push_back(buf.str());
    if (msgbuf.size() > 10) {
        msgbuf.erase(msgbuf.cbegin());
    }


    std::string text = "";
    for (int i = 0; i < msgbuf.size(); i++) {
        text = text + msgbuf[i];
    }

    label->setString(text);
}

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

    Size size = Director::getInstance()->getWinSize();
    std::string defaultFont("arial.ttf");

    char buffer[128];

    score = genRandomScore();
    sprintf( buffer, "submit score: %d", score);
    std::string str = buffer;

    _btn_signin = MenuItemFont::create("Sign In", CC_CALLBACK_1(HelloWorld::connect, this));

    updateSignInBtn();

    Menu* menu = Menu::create(
        _btn_signin,
        MenuItemFont::create("Show Leaderboard", CC_CALLBACK_1(HelloWorld::showLeaderboard, this)),
        MenuItemFont::create("Show All Leaderboards", CC_CALLBACK_1(HelloWorld::showAllLeaderboards, this)),
        MenuItemFont::create(str, CC_CALLBACK_1(HelloWorld::send_score, this)),
        MenuItemFont::create("Get my score", CC_CALLBACK_1(HelloWorld::getMyScore, this)),
        MenuItemFont::create("Get score around me", CC_CALLBACK_1(HelloWorld::getUserCenteredScore, this)),
        MenuItemFont::create("Show Achievements", CC_CALLBACK_1(HelloWorld::showAchievements, this)),
        MenuItemFont::create("achievement unlock", CC_CALLBACK_1(HelloWorld::achievement_craftsman, this)),
        MenuItemFont::create("achievement reveal", CC_CALLBACK_1(HelloWorld::revealHidden, this)),
        MenuItemFont::create("achievement increase progress", CC_CALLBACK_1(HelloWorld::achievement_incremental, this)),
        MenuItemFont::create("achievement set progress", CC_CALLBACK_1(HelloWorld::setSteps, this)),
        MenuItemFont::create("Load Achievements data ", CC_CALLBACK_1(HelloWorld::loadAchievements, this)),
        MenuItemFont::create("Load all game data", [] (cocos2d::Ref* sender) {
            // comment this to compile with old version sdkboxplay
#ifdef ENABLE_CLOUD_SAVE
             sdkbox::PluginSdkboxPlay::loadAllData();
#else
            CCLOG("cloud save is not enable");
#endif
        }),
        MenuItemFont::create("Load one game data", [](cocos2d::Ref* sender) {
            // comment this to compile with old version sdkboxplay
#ifdef ENABLE_CLOUD_SAVE
        sdkbox::PluginSdkboxPlay::loadGameData("key1");
#else
        CCLOG("cloud save is not enable");
#endif
        }),
        MenuItemFont::create("Save game data", [](cocos2d::Ref* sender) {
            // comment this to compile with old version sdkboxplay
#ifdef ENABLE_CLOUD_SAVE
             sdkbox::PluginSdkboxPlay::saveGameData("key1", "{\"game_name\": \"sdkbox go\", \"stage\": 3}");
#else
        CCLOG("cloud save is not enable");
#endif
    }),
        NULL
    );

    menu->alignItemsVerticallyWithPadding(5);
    menu->setPosition(size.width/2, size.height/2);
    addChild(menu);

    _txtStat = Label::create("No action yet.", "fonts/Marker Felt.ttf",32);
    _txtStat->setAnchorPoint(cocos2d::Point(0, 0));
    _txtStat->setPosition(cocos2d::Point(10, 10));
    addChild(_txtStat);

    _txtC = Label::create("Disconnected", "fonts/Marker Felt.ttf",32);
    _txtC->setAnchorPoint(cocos2d::Point(0, 0));
    _txtC->setPosition(cocos2d::Point(10, 45));
    addChild(_txtC);

    sdkbox::PluginSdkboxPlay::setListener(this);
    sdkbox::PluginSdkboxPlay::init();

    return true;
}

int HelloWorld::genRandomScore()
{
    int s;
    time_t tt;
    time(&tt);
    s =  tt%10000;

    return s;
}

void HelloWorld::updateSignInBtn()
{
    if (_btn_signin)
    {
        if (sdkbox::PluginSdkboxPlay::isSignedIn())
        {
            _btn_signin->setString("SignOut");
        }
        else
        {
            _btn_signin->setString("SignIn");
        }
    }

}

void HelloWorld::connect(cocos2d::Ref *sender)
{

    if( sdkbox::PluginSdkboxPlay::isSignedIn())
    {
        sdkbox::PluginSdkboxPlay::signout();
    }
    else
    {
        sdkbox::PluginSdkboxPlay::signin();
    }
}

void HelloWorld::showLeaderboard(cocos2d::Ref *sender) {
    sdkbox::PluginSdkboxPlay::showLeaderboard("ldb1");
}

void HelloWorld::showAllLeaderboards(cocos2d::Ref *sender) {
    sdkbox::PluginSdkboxPlay::showAllLeaderboards();
}

void HelloWorld::showAchievements(cocos2d::Ref *sender) {
    sdkbox::PluginSdkboxPlay::showAchievements();
}

void HelloWorld::achievement_craftsman(cocos2d::Ref *sender) {
    sdkbox::PluginSdkboxPlay::unlockAchievement("craftsman");
}

void HelloWorld::achievement_incremental(cocos2d::Ref *sender) {
    sdkbox::PluginSdkboxPlay::incrementAchievement("incremental",10);
    sdkbox::PluginSdkboxPlay::incrementAchievement("hidden_incremental",20);
}

void HelloWorld::getMyScore(cocos2d::Ref *sender) {
    sdkbox::PluginSdkboxPlay::getMyScore("ldb1",ALL_TIME,GLOBAL);
}

void HelloWorld::getUserCenteredScore(cocos2d::Ref *sender)
{
    sdkbox::PluginSdkboxPlay::getPlayerCenteredScores("ldb1", 2, 2, 3);
}

void HelloWorld::loadAchievements(cocos2d::Ref *sender) {
  sdkbox::PluginSdkboxPlay::loadAchievements(true);
}

void HelloWorld::send_score(cocos2d::Ref *sender) {
    sdkbox::PluginSdkboxPlay::submitScore("ldb1", score);
}

void HelloWorld::setSteps(cocos2d::Ref* sender) {
    sdkbox::PluginSdkboxPlay::setSteps("incremental", 50);
}

void HelloWorld::revealHidden(cocos2d::Ref* sender) {
    sdkbox::PluginSdkboxPlay::reveal("hidden");
}


void HelloWorld::onScoreSubmitted( const std::string& leaderboard_name, long score, bool maxScoreAllTime, bool maxScoreWeek, bool maxScoreToday ) {
    CCLOG("on score %ld submitted to leaderboard:%s", score, leaderboard_name.c_str() );
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
    sprintf(str, "Connection status: %d. Is Connected: %d", connection_status, sdkbox::PluginSdkboxPlay::isSignedIn() ? 1 : 0 );

    _txtStat->setString( str );

    if ( connection_status==1000 ) {
        std::string sstr = PluginSdkboxPlay::getPlayerId() +
            ":'" +
            PluginSdkboxPlay::getPlayerAccountField("name")+
            "(" +
            PluginSdkboxPlay::getPlayerAccountField("display_name")+
            ")'";

        _txtC->setString( sstr );
    }

    updateSignInBtn();
}

void HelloWorld::onAchievementsLoaded( bool reload_forced, const std::string& json_achievements_info ) {
    CCLOG("load achievements fr: %d, metadata: %s", reload_forced ? 1 : 0, json_achievements_info.c_str());
}

void HelloWorld::onSetSteps( const std::string& name, int steps ) {
    CCLOG("achievement set steps: %s, steps: %d", name.c_str(), steps);
}

void HelloWorld::onSetStepsError( const std::string& name, int steps, int error_code, const std::string& error_description ) {
    CCLOG("achievement set steps error: %s, steps: %d. %d:%s", name.c_str(), steps, error_code, error_description.c_str());
}

void HelloWorld::onReveal( const std::string& name) {
    CCLOG("achievement revealed: %s", name.c_str());
}

void HelloWorld::onRevealError( const std::string& name, int error_code, const std::string& error_description ) {
    CCLOG("achievement reveal error: %s. %d:%s", name.c_str(), error_code, error_description.c_str());
}

void HelloWorld::onAchievementUnlockError( const std::string& achievement_name, int error_code, const std::string& error_description ) {
    CCLOG("achievement %s unlock error. %d:%s", achievement_name.c_str(), error_code, error_description.c_str());
}

void HelloWorld::onMyScore( const std::string& leaderboard_name, int time_span, int collection_type, long score ) {
    CCLOG("get my score in leaderboard %s time scope %d collection scope %d = %ld", leaderboard_name.c_str(), time_span, collection_type, score);
}

void HelloWorld::onMyScoreError( const std::string& leaderboard_name, int time_span, int collection_type, int error_code, const std::string& error_description) {

    CCLOG("get my score error %d:%s", error_code, error_description.c_str());
}

void HelloWorld::onPlayerCenteredScores( const std::string& leaderboard_name,
                                    int time_span,
                                    int collection_type,
                                    const std::string& json_with_score_entries )  {
    CCLOG("%s", json_with_score_entries.c_str());
}

void HelloWorld::onPlayerCenteredScoresError( const std::string& leaderboard_name,
                                         int time_span,
                                         int collection_type,
                                         int error_code,
                                         const std::string& error_description) {

    CCLOG("error retriving user centered score");
}

void HelloWorld::onIncrementalAchievementStepError( const std::string& name, int steps, int error_code, const std::string& error_description ) {
    CCLOG("incremental achievent step error: %s step: %d. %d:%s", name.c_str(), steps, error_code, error_description.c_str());
}

// new callback style
void HelloWorld::onIncrementalAchievementStep( const std::string& achievement_name, double step ) {
    CCLOG("incremental achievent %s step: %.1lf", achievement_name.c_str(), step);
}
void HelloWorld::onIncrementalAchievementStepError( const std::string& name, double steps,
                                                    int error_code, const std::string& error_description ) {
    CCLOG("incremental achievent step error: %s step: %.1lf. %d:%s", name.c_str(),
          steps, error_code, error_description.c_str());
}
void HelloWorld::onSetSteps( const std::string& name, double steps ) {
    CCLOG("achievement set steps: %s, steps: %.1lf", name.c_str(), steps);
}
void HelloWorld::onSetStepsError( const std::string& name,
                                  double steps,
                                  int error_code,
                                  const std::string& error_description ) {
    CCLOG("achievement set steps error: %s, steps: %.1lf. %d:%s", name.c_str(),
          steps, error_code, error_description.c_str());
}
void HelloWorld::onScoreSubmitted( const std::string& leaderboard_name, int score, bool maxScoreAllTime, bool maxScoreWeek, bool maxScoreToday ) {
    CCLOG("on score %d submitted to leaderboard:%s", score, leaderboard_name.c_str() );
    CCLOG("all time hi %d", maxScoreAllTime ? 1 : 0 );
    CCLOG("weekly hi %d", maxScoreWeek ? 1 : 0 );
    CCLOG("daily hi %d", maxScoreToday ? 1 : 0 );
}

void HelloWorld::onGameData(const std::string& action, const std::string& name, const std::string& data, const std::string& error) {
    char str[256];
    if (error.length() > 0) {
        // failed
        CCLOG("game data failed:%s", error.c_str());
        snprintf(str, 256, "GameData failed:%s", error.c_str());
    } else {
        //success
        if (0 == action.compare("load")) {
            CCLOG("load game data, %s : %s", name.c_str(), data.c_str());
            sprintf(str, "GameData load %s:%s", name.c_str(), data.c_str());
        } else if (0 == action.compare("save")) {
            CCLOG("save game data, %s : %s", name.c_str(), data.c_str());
            sprintf(str, "GameData save %s:%s", name.c_str(), data.c_str());
        } else {
            CCLOG("unknow game data action: %s", action.c_str());
            sprintf(str, "GameData unknow action:%s", action.c_str());
        }
    }

    _txtStat->setString( str );
}

