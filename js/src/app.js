var HelloWorldLayer = cc.Layer.extend({
    sprite:null,
                                      info:null,
    ctor:function () {
        //////////////////////////////
        // 1. super init first
        this._super();

        cc.log("Sample Startup")

        this.createTestMenu();

        var winsize = cc.winSize;

        var logo = new cc.Sprite("res/Logo.png");
        var logoSize = logo.getContentSize();
        logo.x = logoSize.width / 2;
        logo.y = winsize.height - logoSize.height / 2;
        this.addChild(logo);

        var quit = new cc.MenuItemLabel(new cc.LabelTTF("QUIT", "sans", 32), function() {
            cc.log("QUIT");
        });
        var menu = new cc.Menu(quit);
        var size = quit.getContentSize();
        menu.x = winsize.width - size.width / 2 - 16;
        menu.y = size.height / 2 + 16;
        this.addChild(menu);

                                        this.info =new cc.LabelTTF("unknown status", "sans", 24);
                                         this.info.x = cc.Director.getInstance().getWinSize().width/2;
                                         this.info.y = 90;
                                         this.addChild(this.info);

        return true;
    },

    createTestMenu:function() {
        cc.MenuItemFont.setFontName("sans");
        var size = cc.Director.getInstance().getWinSize();

        // var coin = 0;
        // var coinLabel = new cc.LabelTTF("0", "sans", 32);
        // coinLabel.x = size.width / 2;
        // coinLabel.y = size.height - 80;
        // this.addChild(coinLabel);

        var score = 1000;

        var menu = new cc.Menu(
            new cc.MenuItemFont("Connect/Disconnect", function() {
                                if (sdkbox.PluginSdkboxPlay.isSignedIn() ) {
              sdkbox.PluginSdkboxPlay.signout();
                                } else {
                sdkbox.PluginSdkboxPlay.signin();
                                }
            }),
            new cc.MenuItemFont("Show Leaderboard ldb1", function() {
                sdkbox.PluginSdkboxPlay.showLeaderboard("ldb1");
            }),
            new cc.MenuItemFont("Achievements", function() {
                sdkbox.PluginSdkboxPlay.showAchievements();
            }),
            new cc.MenuItemFont("Unlock Craftsmen", function() {
                sdkbox.PluginSdkboxPlay.unlockAchievement("craftsman");
            }),
            new cc.MenuItemFont("Unlock Hunter", function() {
                sdkbox.PluginSdkboxPlay.unlockAchievement("hunter");
            }),
            new cc.MenuItemFont("Unlock Ten Games", function() {
                sdkbox.PluginSdkboxPlay.unlockAchievement("ten-games");
            }),
            new cc.MenuItemFont("Unlock incremental", function() {
                sdkbox.PluginSdkboxPlay.incrementAchievement("incremental",1);
            }),
            new cc.MenuItemFont("Submit Score 1000", function() {
                sdkbox.PluginSdkboxPlay.submitScore("ldb1", score);
            })
        );

        menu.alignItemsVerticallyWithPadding(5);
        menu.x = size.width/2;
        menu.y = size.height/2;
        this.addChild(menu);

                                      var me= this;

        var initSDK = function() {
            if ("undefined" == typeof(sdkbox)) {
                cc.log("sdkbox is not exist")
                return
            }

            if ("undefined" != typeof(sdkbox.PluginSdkboxPlay)) {
                var plugin = sdkbox.PluginSdkboxPlay
                plugin.setListener({
                    onConnectionStatusChanged : function (connection_status) {
                        cc.log("connection status change: " + connection_status + " connection_status");
                        if ( connection_status==1000 ) {
                            cc.log( 'Player id: '+plugin.getPlayerId() );
                            cc.log( 'Player name: '+plugin.getPlayerAccountField("name") );
                            me.info.setString( "connection status: " + connection_status + " " + plugin.getPlayerId() + " " + plugin.getPlayerAccountField("name") + "("+ plugin.getPlayerAccountField("display_name") +")");
                       } else {
                           me.info.setString( "Not connected. Status: " + connection_status );
                       }
                    },
                    onScoreSubmitted : function (leaderboard_name, score, maxScoreAllTime, maxScoreWeek, maxScoreToday) {
                        cc.log('onScoreSubmitted trigger leaderboard_name:' + leaderboard_name
                            + ' score:' + score + ' maxScoreAllTime:' + maxScoreAllTime
                            + ' maxScoreWeek:' + maxScoreWeek + ' maxScoreToday:' + maxScoreToday);
                    },
                    onMyScore : function (leaderboard_name, time_span, collection_type, score ) {
                        cc.log('onMyScore trigger leaderboard_name:' + leaderboard_name
                            + ' time_span:' + time_span + ' collection_type:' + collection_type + ' score:' + score);
                    },
                    onMyScoreError : function (leaderboard_name, time_span, collection_type, error_code, error_description) {
                        cc.log('onMyScoreError trigger leaderboard_name:' + leaderboard_name
                            + ' time_span:' + time_span + ' collection_type:' + collection_type
                            + ' error_code:' + error_code + ' error_description:' + error_description);
                    },
                    onPlayerCenteredScores : function (leaderboard_name, time_span, collection_type, json_with_score_entries ) {
                        cc.log('onPlayerCenteredScores trigger leaderboard_name:' + leaderboard_name
                            + ' time_span:' + time_span + ' collection_type:' + collection_type
                            + ' json_with_score_entries:' + json_with_score_entries);
                    },
                    onPlayerCenteredScoresError : function (leaderboard_name, time_span, collection_type, error_code, error_description) {
                        cc.log('onPlayerCenteredScoresError trigger leaderboard_name:' + leaderboard_name
                            + ' time_span:' + time_span + ' collection_type:' + collection_type
                            + ' error_code:' + error_code + ' error_description:' + error_description);
                    },
                    onIncrementalAchievementUnlocked : function (achievement_name) {
                        cc.log("incremental achievement " + achievement_name + " unlocked.");
                    },
                    onIncrementalAchievementStep : function (achievement_name, step) {
                        cc.log("incremental achievent " + achievement_name + " step: " + step);
                    },
                    onIncrementalAchievementStepError : function (name, steps, error_code, error_description) {
                        cc.log('onIncrementalAchievementStepError trigger leaderboard_name:' + name
                            + ' steps:' + steps
                            + ' error_code:' + error_code + ' error_description:' + error_description);
                    },
                    onAchievementUnlocked : function (achievement_name, newlyUnlocked) {
                        cc.log('onAchievementUnlocked trigger achievement_name:' + achievement_name + ' newlyUnlocked:' + newlyUnlocked);
                    },
                    onAchievementUnlockError : function (achievement_name, error_code, error_description ) {
                        cc.log('onAchievementUnlockError trigger achievement_name:' + achievement_name
                            + ' error_code:' + error_code + ' error_description:' + error_description);
                    },
                    onAchievementsLoaded : function ( reload_forced, json_achievements_info ) {
                        cc.log('onAchievementsLoaded trigger reload_forced:' + reload_forced
                            + ' json_achievements_info:' + json_achievements_info);
                    },
                    onSetSteps : function (name, steps ) {
                        cc.log('onSetSteps trigger name:' + name + ' steps:' + steps);
                    },
                    onSetStepsError : function (name, steps, error_code, error_description ) {
                        cc.log('onSetStepsError trigger name:' + name + ' steps:' + steps
                            + ' error_code:' + error_code + ' error_description:' + error_description);
                    },
                    onReveal : function (name) {
                        cc.log('onReveal trigger name:' + name);
                    },
                    onRevealError : function (name, error_code, error_description ) {
                        cc.log('onRevealError trigger name:' + name
                            + ' error_code:' + error_code + ' error_description:' + error_description);
                    }
                });
                plugin.init();

            } else {
                printf("no plugin init")
            }
        }

        initSDK();
    }
});

var HelloWorldScene = cc.Scene.extend({
    onEnter:function () {
        this._super();
        var layer = new HelloWorldLayer();
        this.addChild(layer);
    }
});

