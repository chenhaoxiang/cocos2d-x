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

	//背景精灵
	auto background = Sprite::create("background.png");//背景图
	//background->setAnchorPoint(Vec2::ZERO);//指定锚点(默认坐标为0，0)或者:
	background->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));//指定位置(默认锚点为0.5，0.5)
	this->addChild(background,0);

	auto tree1 = Sprite::create("tree1.png", Rect(608, 36, 300, 298));//左上角的坐标，宽，高
	//指定大图，指定Rect获取树的截图
	tree1->setPosition(Vec2(200,230));
	this->addChild(tree1,0);
	
	Texture2D* cache = Director::getInstance()->getTextureCache()->addImage("tree1.png");
	auto tree2 = Sprite::create();
	tree2->setTexture(cache);
	tree2->setTextureRect(Rect(70, 72, 187, 267));
	tree2->setPosition(Vec2(500, 200));//设置精灵位置
	this->addChild(tree2, 0);
	//通过纹理缓存截取树
	
	return true;
}

 