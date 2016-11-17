
local MainScene = class("MainScene", function()
    return display.newScene("MainScene")
end)

function MainScene:ctor()
        
    local bg = cc.Sprite:create("bg.png")
    	:align(display.CENTER, display.cx, display.cy)
        :addTo(self,-1)


    local label = cc.ui.UILabel.new({
            UILabelType = 2, text = "Hello, World", size = 64})
        :align(display.CENTER, display.cx, display.cy)
        :addTo(self)


    local anim = zcAnimNode:create( "ironman.swf.sam" , 1 , "ironman.plist" );
    print(tostring(anim), "anim ======= ")

	local function animEnd(node ,theId ,theLabelName)
		anim:playSection(theLabelName);
	end
	local function animEnd1(node ,theId ,theLabelName)
		anim:playSection(theLabelName);
	end
	anim:registerScriptTapHandler(animEnd);
	anim:registerScriptTapHandler(animEnd1);
	anim:playSection("Ddaiji")



    local node = tolua.cast(anim, "cc.Sprite")
    node:setPosition(200, 200)
    local size = node:getContentSize()
    print("(width, height)", size.width, size.height)
    self:addChild(node, 1, 1)

    -- local sprite = cc.Sprite:createWithSpriteFrameName("hero_1.swf1.png")
    -- 		:addTo(self)
    -- 		:align(display.CENTER, display.cx, display.cy)

    cc.LayerColor:create(cc.c4f(1, 0.5, 0.1, 1), 100, 100)
        :size(size.width, size.height)
        :pos(200, 200)
        :addTo(self)
        :setTouchEnabled(false)


    local animFunc = function (name)
		anim:playSection(name)
    end
    self:addButton("Ddaiji", animFunc)
    self:addButton("Dqianjin", animFunc)
    self:addButton("RDdaiji", animFunc)
    self:addButton("RDshifa", animFunc)
    self:addButton("RUgongji2", animFunc)
    self:addButton("RUqianjin", animFunc)
    self:addButton("Uqianjin", animFunc)
end

local index = 1
function MainScene:addButton(name, func)
    cc.ui.UIPushButton.new()
        :setButtonLabel(cc.ui.UILabel.new({text = name, size = 32, color = display.COLOR_BLUE}))
        :onButtonClicked(function(event)
        	func(name)
        end)
        :align(display.LEFT_BOTTOM, display.right - 80, display.bottom + 40 * index)
        :addTo(self)
	index = index + 1
end




function MainScene:onEnter()
end

function MainScene:onExit()
end

return MainScene
