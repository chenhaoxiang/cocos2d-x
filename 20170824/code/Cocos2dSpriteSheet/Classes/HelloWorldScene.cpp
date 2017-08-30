#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	// 'scene' is an autorelease Ref
	auto scene = Scene::create();

	// 'layer' is an autorelease Ref
	auto layer = HelloWorld::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool HelloWorld::init()
{
	if ( !Layer::init() )
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto background = Sprite::create("background.png");
	background->setAnchorPoint(Vec2::ZERO);
    this->addChild(background,0);   

    auto mountain1 = Sprite::create("SpriteSheet.png",Rect(2,391, 934, 388));//截取图片
	mountain1->setAnchorPoint(Vec2::ZERO);//设置锚点
    mountain1->setPosition(Vec2(-200,80));//设置坐标
    this->addChild(mountain1,0);

    Texture2D* cache = Director::getInstance()->getTextureCache()->addImage("SpriteSheet.png");//加载整个图片到纹理缓存
    auto hero1 = Sprite::create();
    hero1->setTexture(cache);
    hero1->setTextureRect(Rect(2,1706,391,327));//在纹理缓存中截取图片  左上角坐标 以及截取图片的宽高
    hero1->setPosition(Vec2(800,200));
    this->addChild(hero1,0);
	
	return true;
}
