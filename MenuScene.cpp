#include "MenuScene.h"
#include "MenuLayer.h"
#include "Audio.h"
USING_NS_CC;
bool MenuScene::init(){
	if(!Scene::init()){
		return false;
	}
	Audio::getInstance()->playBGM();
	this->addChild(MenuLayer::create());
	return true;
}