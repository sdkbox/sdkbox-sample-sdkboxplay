/****************************************************************************

 Copyright (c) 2014-2016 SDKBOX Inc

 ****************************************************************************/

#ifndef _PLUGIN_SDKBOXPLAY_WRAPPER_H_
#define _PLUGIN_SDKBOXPLAY_WRAPPER_H_

#include "PluginSdkboxPlay.h"
#include "json98.h"
#include "CocosMacros.h"
#include <map>

#define GPS_CATEGORY "sdkboxplay"


namespace sdkbox {

    class SdkboxPlayWrapper {

    public:

        static SdkboxPlayWrapper *getInstance();
        virtual bool init(const char* jsonConfig = nullptr) = 0;
        virtual void setListener(SdkboxPlayListener *listener) = 0;
        virtual SdkboxPlayListener *getListener() = 0;
        virtual void removeListener() = 0;
        virtual std::string getVersion() const = 0;

        virtual bool isConnectionError() const = 0;
        virtual bool isConnected() const = 0;
        virtual bool isDisconnected() const = 0;
        virtual bool isSignedIn() const = 0;

        virtual void signin() const = 0;
        virtual void signout() const = 0;
        virtual void submitScore( const std::string& leaderboard_name, int score ) const = 0;
        virtual void getMyScore(const std::string &leaderboard_name, int time_span, int collection_type) const = 0;
        virtual void getPlayerCenteredScores( const std::string& leaderboard_name, int time_span, int collection_type, int number_of_entries ) const = 0;
        virtual void showLeaderboard( const std::string& leaderboard_name ) const = 0;
        virtual void showAllLeaderboards( ) const = 0;
        virtual void unlockAchievement( const std::string& achievement_name ) const = 0;
        virtual void incrementAchievement( const std::string& achievement_name, int increment ) const = 0;
        virtual void showAchievements( ) const = 0;
        virtual void loadAchievements( bool force_reload ) const = 0;
        virtual void reveal( const std::string& achievement_name ) const = 0;
        virtual void setSteps( const std::string& achievement_name, int steps ) const = 0;

        virtual std::string getPlayerId() const = 0;
        virtual std::string getPlayerAccountField(  const std::string& field ) const = 0;

    };

    class SdkboxPlayWrapperEnabled : public SdkboxPlayWrapper {

    public:
        SdkboxPlayWrapperEnabled();

        virtual bool init(const char* jsonConfig = nullptr);
        virtual void setListener(SdkboxPlayListener *listener);
        virtual SdkboxPlayListener *getListener();
        virtual void removeListener();
        virtual std::string getVersion() const;

        virtual bool isConnectionError() const;
        virtual bool isConnected() const;
        virtual bool isSignedIn() const;
        virtual bool isDisconnected() const;

        virtual void signin() const;
        virtual void signout() const;

        virtual void submitScore( const std::string& leaderboard_name, int score ) const;
        virtual void getMyScore(const std::string &leaderboard_name, int time_span, int collection_type) const;
        virtual void getPlayerCenteredScores( const std::string& leaderboard_name, int time_span, int collection_type, int number_of_entries ) const;
        virtual void showLeaderboard( const std::string& leaderboard_name ) const;
        virtual void showAllLeaderboards( ) const;
        virtual void unlockAchievement( const std::string& achievement_name ) const;
        virtual void incrementAchievement( const std::string& achievement_name, int increment ) const;
        virtual void showAchievements( ) const;
        virtual void loadAchievements( bool force_reload ) const;
        virtual void reveal( const std::string& achievement_name ) const;
        virtual void setSteps( const std::string& achievement_name, int steps ) const;

        virtual std::string getPlayerId() const;
        virtual std::string getPlayerAccountField( const std::string& field ) const;

        
    protected:

        bool _connectOnStart;
        int _connectionStatus = 0;
        
        bool nativeInit(const Json &config);
        std::string nativeSDKVersion() const;
        
        SdkboxPlayListener *_listener;
    };

    class SdkboxPlayWrapperDisabled : public SdkboxPlayWrapper {

    public:
        SdkboxPlayWrapperDisabled() { }

        virtual bool init(const char* jsonConfig = nullptr) { return false; }
        virtual void setListener(SdkboxPlayListener *listener) { }
        virtual SdkboxPlayListener *getListener() { return NULL; }
        virtual void removeListener() { }
        virtual std::string getVersion() const { return ""; }

        virtual bool isConnectionError() const { return true; }
        virtual bool isConnected() const { return false; }
        virtual bool isSignedIn() const { return false; }
        virtual bool isDisconnected() const { return true; }

        virtual void signin() const {}
        virtual void signout() const {}

        virtual void submitScore( const std::string& leaderboard_name, int score ) const { }
        virtual void getMyScore(const std::string &leaderboard_name, int time_span, int collection_type) const { }
        virtual void getPlayerCenteredScores( const std::string& leaderboard_name, int time_span, int collection_type, int number_of_entries ) const { }
        virtual void showLeaderboard( const std::string& leaderboard_name ) const { }
        virtual void showAllLeaderboards( ) const { }
        virtual void unlockAchievement( const std::string& achievement_name ) const {}
        virtual void incrementAchievement( const std::string& achievement_name, int increment ) const {}
        virtual void showAchievements( ) const {}
        virtual void loadAchievements( bool force_reload ) const {}
        virtual void reveal( const std::string& achievement_name ) const {}
        virtual void setSteps( const std::string& achievement_name, int steps ) const {}

        virtual std::string getPlayerId() const { return ""; }
        virtual std::string getPlayerAccountField(  const std::string& field ) const { return ""; }

    };


}

#endif
