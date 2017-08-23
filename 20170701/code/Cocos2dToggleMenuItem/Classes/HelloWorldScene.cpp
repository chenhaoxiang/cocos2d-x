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

	Size visibleSize = Director::getInstance()->getVisibleSize();//大小
	Vec2 origin = Director::getInstance()->getVisibleOrigin();//锚点 默认为0.5  0.5

	//Sprite* bg = Sprite::create("menu/setting-back.png");
	auto bg = Sprite::create("menu/setting-back.png");// auto-自动推断类型
	bg->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));
	this->addChild(bg);

	//音效菜单项
	auto soundOnMenuItem = MenuItemImage::create("menu/on.png", "menu/on.png");//正常和按下是同一张图片 - 开
	auto soundOffMenuItem = MenuItemImage::create("menu/off.png", "menu/off.png");//关
	//音效开关菜单项
	auto soundToggleMenuItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(HelloWorld::menuSoundToggleCallback,this),//函数指针
		soundOnMenuItem,soundOffMenuItem,//菜单项集合
		NULL//集合结束
		);
	//设置坐标 - UI坐标(原点为左上角)转换为OpenGL坐标(原点为左下角)
	soundToggleMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(818, 220)));

	//音乐菜单项 
	auto musicOnMenuItem = MenuItemImage::create(
		"menu/on.png",
		"menu/on.png");
	auto musicOffMenuItem = MenuItemImage::create(
		"menu/off.png",
		"menu/off.png");
	//音乐开关菜单项
	auto musicToggleMenuItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(HelloWorld::menuMusicToggleCallback, this),
		musicOnMenuItem,
		musicOffMenuItem,
		NULL);
	musicToggleMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(818, 362)));

	//OK按钮
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