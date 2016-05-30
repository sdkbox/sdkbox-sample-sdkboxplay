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
                console.log("sdkbox is not exist")
                return
            }

            if ("undefined" != typeof(sdkbox.PluginSdkboxPlay)) {
                var plugin = sdkbox.PluginSdkboxPlay
                plugin.setListener({
                    onScoreSubmitted : function (leaderboard_name, score, maxScoreAllTime, maxScoreWeek, maxScoreToday) {
                        cc.log("on score " + score + " submitted to leaderboard: " + leaderboard_name);
                        cc.log("all time hi " + maxScoreAllTime ? 1 : 0 );
                        cc.log("weekly hi " + maxScoreWeek ? 1 : 0 );
                        cc.log("daily hi " + maxScoreToday ? 1 : 0 );
                    },
                    onIncrementalAchievementUnlocked : function (achievement_name) {
                        cc.log("incremental achievement " + achievement_name + " unlocked.");
                    },
                    onIncrementalAchievementStep : function (achievement_name, step) {
                        cc.log("incremental achievent " + achievement_name + " step: " + step);
                    },
                    onAchievementUnlocked : function (achievement_name, newlyUnlocked) {
                        cc.log("achievement " + achievement_name + " unlocked (new " + newlyUnlocked ? 1 : 0 + ")");
                    },
                    onConnectionStatusChanged : function (connection_status) {
                        cc.log("connection status change: " + connection_status + " connection_status");      
                        if ( connection_status==1000 ) {
                            cc.log( 'Player id: '+plugin.getPlayerId() );
                            cc.log( 'Player name: '+plugin.getPlayerAccountField("name") );
                            me.info.setString( "connection status: " + connection_status + " " + plugin.getPlayerId() + " " + plugin.getPlayerAccountField("name") + "("+ plugin.getPlayerAccountField("display_name") +")");
                       } else {
                           me.info.setString( "Not connected. Status: " + connection_status );
                       }
                                   
                                   
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

