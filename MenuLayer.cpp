#include "MenuLayer.h"
#include "GameScene.h"
#include "GameData.h"
#include "Audio.h"
bool MenuLayer::init(){
	if(!Layer::init()){
		return false;
	}

	Size winSize = Director::getInstance()->getWinSize();
	/*初始化背景*/
	Sprite* background = Sprite::create("bg_menuscene.jpg");
	background->setPosition(winSize.width/2,winSize.height/2);
	background->setScale(winSize.height/background->getContentSize().height);
	this->addChild(background,-1);
	
	/*初始化菜单*/
	MenuItemImage* startBtn = MenuItemImage::create(
		"menu_start.png","menu_star.png",CC_CALLBACK_0(MenuLayer::startGame,this)
		);
	Menu* menu = Menu::create(startBtn,NULL);
	menu->alignItemsVertically();
	menu->setPosition(winSize.width/2,winSize.height/2);
	this->addChild(menu);
	return true;
}

void MenuLayer::startGame(){
	CCLOG("START!");
	GAMEDATA::getInstance()->init();
	Director::getInstance()->replaceScene(GameScene::create());

}
