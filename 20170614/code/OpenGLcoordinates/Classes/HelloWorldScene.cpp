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
    if ( !Layer::init() )
    {
        return false;
    }
    
	auto node1 = Sprite::create("Node1.png");//Sprite�Ǿ���
	node1->setPosition(Vec2(400,500));//����λ��
	node1->setAnchorPoint(Vec2(1.0, 1.0));//����ê��

	this->addChild(node1,0);//����Ӿ���

	auto node2 = Sprite::create("Node2.png");//Sprite�Ǿ���
	node2->setPosition(Vec2(200, 300));//����λ��
	node2->setAnchorPoint(Vec2(0.5, 0.5));//����ê��
	this->addChild(node2, 0);

	Vec2 point1 = node1->convertToNodeSpace(node2->getPosition());//��Node2��λ��ת��Ϊ�����Node1��ģ�����꣬����AR�ģ���ʾ�����Node1������ԭ��
	
	Vec2 point2 = node1->convertToNodeSpaceAR(node2->getPosition());

	log("Node2 NodeSpace = (%f,%f)",point1.x,point1.y);//Node2 NodeSpace = (100.000000,-100.000000)
	log("Node2 NodeSpaceAR = (%f,%f)", point2.x, point2.y);//Node2 NodeSpaceAR = (-200.000000,-200.000000)

    return true;
}
