
local MainScene = class("MainScene", cc.load("mvc").ViewBase)

function MainScene:onCreate()
    print("Sample Startup")

    local logo = cc.Sprite:create("Logo.png")
    local logoSize = logo:getContentSize()
    logo:setPosition(cc.p(logoSize.width / 2, display.top - logoSize.height / 2))
    self:addChild(logo)

    local label = cc.Label:createWithSystemFont("QUIT", "sans", 32)
    local quit = cc.MenuItemLabel:create(label)
    quit:onClicked(function()
        os.exit(0)
    end)
    local size = label:getContentSize()
    local menu = cc.Menu:create(quit)
    menu:setPosition(display.right - size.width / 2 - 16, display.bottom + size.height / 2 + 16)
    self:addChild(menu)

    self:setupTestMenu()
end

function MainScene:setupTestMenu()

    sdkbox.PluginSdkboxPlay:init()
    sdkbox.PluginSdkboxPlay:setListener(function(args)

        dump(args)

        if "onScoreSubmitted" == args.name then
            -- local isLogin = args.isLoggedIn
            -- if isLogin then
            --     showText("login successful")
            -- else
            --     showText("login failed")
            end
        elseif "onIncrementalAchievementUnlocked" ==  args.name then
            -- local isLogin = args.ok
            -- local msg = args.msg;
            -- if isLogin then
            --     showText("request permission successful")
            -- else
            --     showText("request permission failed")
            end
        elseif "onIncrementalAchievementStep" ==  args.name then
            -- local tag = args.tag;
            -- local jsonData = args.jsonData;
            -- cc.log("============")
            -- cc.log(tag)
            -- cc.log(jsonData)
            end
        elseif "onAchievementUnlocked" ==  args.name then
            -- local msg = args.message
            -- showText("share successful")
            -- cc.log(msg)
            end
        elseif "onConnectionStatusChanged" ==  args.name then
            -- local msg = args.message
            -- showText("share failed")
            -- cc.log(msg)
            end
    end)

    cc.MenuItemFont:setFontName("Arial")
    cc.Menu:create(
                   cc.MenuItemFont:create("Connect"):onClicked(function()
                        -- sdkbox.PluginAdMob:cache(self.kHomeBanner)
                    end),
                   cc.MenuItemFont:create("Disconnect"):onClicked(function()
                        -- sdkbox.PluginAdMob:show(self.kHomeBanner)
                    end),
                   cc.MenuItemFont:create("Show Leaderboard ldb1"):onClicked(function()
                        -- sdkbox.PluginAdMob:hide(self.kHomeBanner)
                    end),
                   cc.MenuItemFont:create("Achievements"):onClicked(function()
                        -- local yes = sdkbox.PluginAdMob:isAvailable(self.kHomeBanner) and "yes" or "no"
                        -- showText("is " .. self.kHomeBanner .. " available " .. yes)
                    end),

                   cc.MenuItemFont:create("Unlock Craftsmen"):onClicked(function()
                        -- sdkbox.PluginAdMob:cache(self.kGameOverAd)
                    end),
                   cc.MenuItemFont:create("Unlock Hunter"):onClicked(function()
                        -- sdkbox.PluginAdMob:show(self.kGameOverAd)
                    end),
                   cc.MenuItemFont:create("Unlock Ten Games"):onClicked(function()
                        -- local yes = sdkbox.PluginAdMob:isAvailable(self.kGameOverAd) and "yes" or "no"
                        -- showText("is " .. self.kGameOverAd .. " available " .. yes)
                    end),
                   cc.MenuItemFont:create("Unlock Incremental"):onClicked(function()
                        -- sdkbox.PluginAdMob:show(self.kGameOverAd)
                    end),
                   cc.MenuItemFont:create("Send Score 1000"):onClicked(function()
                        -- sdkbox.PluginAdMob:show(self.kGameOverAd)
                    end)
                   )
        :move(display.cx, display.cy)
        :addTo(self)
        :alignItemsVerticallyWithPadding(20)


    require('cocos.cocos2d.json')
end

return MainScene
