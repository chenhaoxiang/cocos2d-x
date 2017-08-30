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

    auto mountain1 = Sprite::create("SpriteSheet.png",Rect(2,391, 934, 388));//��ȡͼƬ
	mountain1->setAnchorPoint(Vec2::ZERO);//����ê��
    mountain1->setPosition(Vec2(-200,80));//��������
    this->addChild(mountain1,0);

    Texture2D* cache = Director::getInstance()->getTextureCache()->addImage("SpriteSheet.png");//��������ͼƬ��������
    auto hero1 = Sprite::create();
    hero1->setTexture(cache);
    hero1->setTextureRect(Rect(2,1706,391,327));//���������н�ȡͼƬ  ���Ͻ����� �Լ���ȡͼƬ�Ŀ��
    hero1->setPosition(Vec2(800,200));
    this->addChild(hero1,0);
	
	return true;
}
