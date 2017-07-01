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

	auto node1 = Sprite::create("Node1.png");//Sprite�Ǿ���
	node1->setPosition(Vec2(400, 500));//����λ��
	node1->setAnchorPoint(Vec2(0.5, 0.5));//����ê��

	this->addChild(node1, 0);//����Ӿ���

	auto node2 = Sprite::create("Node2.png");//Sprite�Ǿ���
	//node2->setPosition(Vec2(0.0, 0.0));//����λ��
	//node2->setAnchorPoint(Vec2(0.0, 0.0));//����ê��
	//node1->addChild(node2, 0);//��Node2�ŵ�Node1

	node2->setPosition(Vec2(250, 450));
	node2->setAnchorPoint(Vec2(0.0, 0.0));
	this->addChild(node2, 0);

	//��Node2��λ��ת��Ϊ�����Node1��ģ�����꣬����AR�ģ���ʾ�����Node1������ԭ��
	Vec2 point1 = node1->convertToWorldSpace(node2->getPosition());
	Vec2 point2 = node1->convertToWorldSpaceAR(node2->getPosition());

	log("Node2 WorldSpace = (%f,%f)", point1.x, point1.y);//Node2 WorldSpace = (250.000000,450.000000)
	log("Node2 WorldSpaceAR = (%f,%f)", point2.x, point2.y);//Node2 WorldSpaceAR = (400.000000,500.000000)

	return true;
}
