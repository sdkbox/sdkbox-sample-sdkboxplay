/****************************************************************************

 Copyright (c) 2014-2016 SDKBOX Inc

 ****************************************************************************/

#ifndef _PLUGIN_SDKBOXPLAY_H_
#define _PLUGIN_SDKBOXPLAY_H_

#include <string>

namespace sdkbox {
    
    const int GPS_CONNECTED = 1000;
    const int GPS_DISCONNECTED = 1001;
    const int GPS_CONNECTION_ERROR = 1002;
    
    class SdkboxPlayListener;
    class PluginSdkboxPlay {
    public:
        /**
         * Initialize the plugin instance.
         * The plugin initializes from the sdkbox_config.json file, and reads a configuration of the form:
         * {
         *     "leaderboards"     : LeaderboardObject[],
         *     "achievements"     : AchievementObject[],
         *     "connect_on_start" : boolean,
         *     "debug"            : boolean,
         *     "enabled"          : boolean
         * }
         *
         * debug: 
         *    is a common value to all plugins which enables debug info to be sent to the console. Useful when developing.
         * enabled: 
         *    is a common value to all plugins, which enables or disables the plugin. If enabled is false, the plugin methods will do nothing.
         * connect_on_start: 
         *    tells the plugin to make an automatic connection to Google Play Services on application startup.
         * leaderboards:
         *    a collection of objects of the form:
         *    {
         *        "id"   : // google play's assigned leaderboard id
         *        "name" : // human readable leaderboard name. You'll request leaderboard actions with this name.
         *    }
         * achievements:
         *    a collection of objects of the form:
         *    {
         *        "id"          : // google play's assigned achievement id.
         *        "name"        : // human readable achievement name. You'll request achievement actions with this name.
         *        "incremental" : // boolean
         *    }
         */
        static bool init();

        /**
         * Set SdkboxPlay plugin listener.
         */
        static void setListener(SdkboxPlayListener* listener);

        /**
         * Get the plugin's listener.
         */
        static SdkboxPlayListener* getListener();

        /**
         * Remove the listener.
         * This plugin allows only for one listener which will be disabled after calling this method.
         */
        static void removeListener();

        /**
         * Use this to get the version of the SDK.
         * @return The version of the SDK.
         */
        static std::string getVersion();

        /**
         * Request submission of an score value to a leaderboard name defined in sdkbox_config.json file.
         * If the leaderboard name does not exists, or the id associated is not defined in the Developer Console for the application,
         * the call will silently fail.
         * If everything's right, it will notify the method <code>onScoreSubmitted</code>.
         */
        static void submitScore( const std::string& leaderboard_name, int score );
        
        /**
         * Request to show the default Leaderboard view.
         * In this view you'll be able to interactively select between daily, weekly or all-time leaderboard time frames and the scope
         * to global or you google play's friends results.
         */
        static void showLeaderboard( const std::string& leaderboard_name );
        
        /**
         * Request to unlock an achievement defined by its name.
         * This method assumes the achievement is non incremental.
         * If the achievement type is incorrectly defined in the configuration file, or the play services determines it is of the wrong type,
         * this method will fail silently.
         * Otherwise, if everything is right, the method <code>onAchievementUnlocked</code> will be invoked on the plugin listener.
         */
        static void unlockAchievement( const std::string& achievement_name );
        
        /**
         * Request to increment the step count of an incremental achievement by the specified number of steps.
         * This method assumes the achievement is incremental.
         * If the achievement type is incorrectly defined in the configuration file, or the play services determines it is of the wrong type,
         * this method will fail silently.
         * If the call is successful, this method may invoke two different methods:
         *   + <code>onIncrementalAchievementStep</code> if the achievement is not unlocked.
         *   + <code>onIncrementalAchievementUnlocked</code> the first time it's been newly unlocked.
         */
        static void incrementAchievement( const std::string& achievement_name, int increment );
        
        /**
         * Request to show the default Achievements view.
         * In this view, you'll only see public achievements.
         * It will show wether or not achievements are unlocked, and the steps towards unlocking it for incremental achievements.
         * Total experience count is measured as well.
         */
        static void showAchievements( );
        
        /**
         * Fast method to know plugin's connection status.
         */
        static bool isConnected();

        /**
         * Request connection to the platform-specific services backend.
         * This method will invoke plugin's listener <code>onConnectionStatusChanged</code> method.
         */
        static void signin();
        
        /**
         * Request disconnection from the GooglePlay/Game Center backend.
         * This method will invoke plugin's listener <code>onConnectionStatusChanged</code> method.
         */
        static void signout();
    };
    
    class SdkboxPlayListener {
    public:
        /**
         * Call method invoked when the Plugin connection changes its status.
         * Values are as follows:
         *   + GPS_CONNECTED:       successfully connected.
         *   + GPS_DISCONNECTED:    successfully disconnected.
         *   + GPS_CONNECTION_ERROR:error with google play services connection.
         */
        virtual void onConnectionStatusChanged( int status ) =0;
        
        /**
         * Callback method invoked when an score has been successfully submitted to a leaderboard.
         * It notifies back with the leaderboard_name (not id, see the sdkbox_config.json file) and the
         * subbmited score, as well as whether the score is the daily, weekly, or all time best score.
         * Since Game center can't determine if submitted score is maximum, it will send the max score flags as false.
         */
        virtual void onScoreSubmitted( const std::string& leaderboard_name, int score, bool maxScoreAllTime, bool maxScoreWeek, bool maxScoreToday )=0;
        
        /**
         * Callback method invoked when the request call to increment an achievement is succeessful and
         * that achievement gets unlocked. This happens when the incremental step count reaches its maximum value. 
         * Maximum step count for an incremental achievement is defined in the google play developer console.
         */
        virtual void onIncrementalAchievementUnlocked( const std::string& achievement_name )=0;
        
        /**
         * Callback method invoked when the request call to increment an achievement is successful.
         * If possible (Google play only) it notifies back with the current achievement step count.
         */
        virtual void onIncrementalAchievementStep( const std::string& achievement_name, int step )=0;
        
        /**
         * Call method invoked when the request call to unlock a non-incremental achievement is successful.
         * If this is the first time the achievement is unlocked, newUnlocked will be true.
         */
        virtual void onAchievementUnlocked( const std::string& achievement_name, bool newlyUnlocked )=0;
    };
}

#endif
