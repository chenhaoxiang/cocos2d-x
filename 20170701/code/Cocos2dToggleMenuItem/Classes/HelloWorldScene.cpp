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

	if (!Layer::init()){
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();//��С
	Vec2 origin = Director::getInstance()->getVisibleOrigin();//ê�� Ĭ��Ϊ0.5  0.5

	//Sprite* bg = Sprite::create("menu/setting-back.png");
	auto bg = Sprite::create("menu/setting-back.png");// auto-�Զ��ƶ�����
	bg->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));
	this->addChild(bg);

	//��Ч�˵���
	auto soundOnMenuItem = MenuItemImage::create("menu/on.png", "menu/on.png");//�����Ͱ�����ͬһ��ͼƬ - ��
	auto soundOffMenuItem = MenuItemImage::create("menu/off.png", "menu/off.png");//��
	//��Ч���ز˵���
	auto soundToggleMenuItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(HelloWorld::menuSoundToggleCallback,this),//����ָ��
		soundOnMenuItem,soundOffMenuItem,//�˵����
		NULL//���Ͻ���
		);
	//�������� - UI����(ԭ��Ϊ���Ͻ�)ת��ΪOpenGL����(ԭ��Ϊ���½�)
	soundToggleMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(818, 220)));

	//���ֲ˵��� 
	auto musicOnMenuItem = MenuItemImage::create(
		"menu/on.png",
		"menu/on.png");
	auto musicOffMenuItem = MenuItemImage::create(
		"menu/off.png",
		"menu/off.png");
	//���ֿ��ز˵���
	auto musicToggleMenuItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(HelloWorld::menuMusicToggleCallback, this),
		musicOnMenuItem,
		musicOffMenuItem,
		NULL);
	musicToggleMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(818, 362)));

	//OK��ť
	auto okMenuItem = MenuItemImage::create("menu/ok-up.png", "menu/ok-down.png");
	okMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(600, 510)));

	Menu* mn = Menu::create(soundToggleMenuItem, musicToggleMenuItem, okMenuItem, NULL);
	mn->setPosition(Vec2::ZERO);
	this->addChild(mn);

    return true;
}


void HelloWorld::menuSoundToggleCallback(Ref* pSender)
{
	log("menuSoundToggleCallback");
}


void HelloWorld::menuMusicToggleCallback(Ref* pSender)
{
	log("menuMusicToggleCallback");
}