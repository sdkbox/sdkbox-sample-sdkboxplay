#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "PluginSdkboxPlay/PluginSdkboxPlay.h"

class HelloWorld : public cocos2d::Layer, public sdkbox::SdkboxPlayListener
{
protected:
    cocos2d::Label * _txtStat;
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    void runtests(int fd, const std::string& args);
    
    void connect(cocos2d::Ref *sender);
    void disconnect(cocos2d::Ref *sender);
    
    void showLeaderboard(cocos2d::Ref *sender);
    void showAchievements(cocos2d::Ref *sender);
    
    void achievement_hunter(cocos2d::Ref* sender);
    void achievement_craftsman(cocos2d::Ref* sender);
    void achievement_ten_games(cocos2d::Ref* sender);
    void achievement_incremental(cocos2d::Ref* sender);
    
    void send_score(cocos2d::Ref* sender);
    
    virtual void onConnectionStatusChanged(int connection_status);
    virtual void onScoreSubmitted( const std::string& leaderboard_name, int score, bool maxScoreAllTime, bool maxScoreWeek, bool maxScoreToday );
    virtual void onIncrementalAchievementUnlocked( const std::string& achievement_name );
    virtual void onIncrementalAchievementStep( const std::string& achievement_name, int step );
    virtual void onAchievementUnlocked( const std::string& achievement_name, bool newlyUnlocked );
};

#endif // __HELLOWORLD_SCENE_H__
