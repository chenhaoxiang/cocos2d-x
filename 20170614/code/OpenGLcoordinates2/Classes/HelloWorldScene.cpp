#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = HelloWorld::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	auto node1 = Sprite::create("Node1.png");//Sprite是精灵
	node1->setPosition(Vec2(400, 500));//设置位置
	node1->setAnchorPoint(Vec2(0.5, 0.5));//设置锚点

	this->addChild(node1, 0);//层添加精灵

	auto node2 = Sprite::create("Node2.png");//Sprite是精灵
	//node2->setPosition(Vec2(0.0, 0.0));//设置位置
	//node2->setAnchorPoint(Vec2(0.0, 0.0));//设置锚点
	//node1->addChild(node2, 0);//把Node2放到Node1

	node2->setPosition(Vec2(250, 450));
	node2->setAnchorPoint(Vec2(0.0, 0.0));
	this->addChild(node2, 0);

	//将Node2的位置转换为相对于Node1的模型坐标，不带AR的，表示相对于Node1的坐标原点
	Vec2 point1 = node1->convertToWorldSpace(node2->getPosition());
	Vec2 point2 = node1->convertToWorldSpaceAR(node2->getPosition());

	log("Node2 WorldSpace = (%f,%f)", point1.x, point1.y);//Node2 WorldSpace = (250.000000,450.000000)
	log("Node2 WorldSpaceAR = (%f,%f)", point2.x, point2.y);//Node2 WorldSpaceAR = (400.000000,500.000000)

	return true;
}
