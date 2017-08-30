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

	auto background = Sprite::create("background.png");//加载背景精灵
	background->setAnchorPoint(Vec2::ZERO);
    this->addChild(background,0);
	
	SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();//单例对象
	frameCache->addSpriteFramesWithFile("SpriteSheet.plist");//加载精灵图集

    auto mountain1 = Sprite::createWithSpriteFrameName("mountain1.png");//通过精灵帧名创建精灵
	mountain1->setAnchorPoint(Vec2::ZERO);//设置锚点
    mountain1->setPosition(Vec2(-200,80));
    this->addChild(mountain1,0);

	SpriteFrame *heroSpriteFrame = frameCache->getSpriteFrameByName("hero1.png");//通过精灵帧名字获取精灵帧
	Sprite *hero1 = Sprite::createWithSpriteFrame(heroSpriteFrame);//通过精灵帧创建精灵
	//上面的两条语句相当于前面一条语句的效果auto mountain1 = Sprite::createWithSpriteFrameName("mountain1.png");
    hero1->setPosition(Vec2(800,200));
    this->addChild(hero1,0);

	return true;
}
