#include "Star.h"

Star* Star::create(int color){
	Star* ret = new Star();
	if(ret && ret->initWithFile(ret->getImage(color))){
		ret->color = color;
		ret->selected = false;
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

char* Star::getImage(int color){
	switch(color){
	case color::BLUE:
		return "blue.png";
	case color::GREEN:
		return "green.png";
	case color::YELLOW:
		return "orange.png";
	case color::RED:
		return "red.png";
	case color::PURPLE:
		return "purple.png";
	}
}

char* Star::getImageHeart(int color){
	switch(color){
	case color::BLUE:
		return "blue_heart.png";
	case color::GREEN:
		return "green_heart.png";
	case color::YELLOW:
		return "orange_heart.png";
	case color::RED:
		return "red_heart.png";
	case color::PURPLE:
		return "purple_heart.png";
	}
}

bool Star::isSelected(){
	return selected;
}

int Star::getColor(){
	return color;
}

void Star::setDesPosition(const Point& p){
	desPosition = p;
}

void Star::updatePosition(){
	if(desPosition.y != getPositionY()){
		setPositionY(getPositionY() - MOVE_SPEED);
		if(getPositionY() < desPosition.y){
			setPositionY(desPosition.y);
		}
	}
	if(desPosition.x != getPositionX()){
		setPositionX(getPositionX() - MOVE_SPEED);
		if(getPositionX() < desPosition.x){
			setPositionX(desPosition.x);
		}
	}
}
