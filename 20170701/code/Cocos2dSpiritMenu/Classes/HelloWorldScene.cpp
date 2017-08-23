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

    Sprite *bg = Sprite::create("menu/background.png");

    bg->setPosition(Vec2(origin.x + visibleSize.width/2,

                             origin.y + visibleSize.height /2));

    this->addChild(bg);

	//开始精灵
    Sprite *startSpriteNormal = Sprite::create("menu/start-up.png");
    Sprite *startSpriteSelected = Sprite::create("menu/start-down.png");
	//创建精灵菜单  添加精灵以及回调函数
	MenuItemSprite *startMenuItem = MenuItemSprite::create(startSpriteNormal, 
													startSpriteSelected,
												   CC_CALLBACK_1(HelloWorld::menuItemStartCallback, this));
	startMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(700, 170)));
	//指定坐标    convertToGL转换-将左上角为原点的UI坐标转换为OpenGL坐标，cocos2d默认坐标为OpenGL坐标
	//700, 170为UI坐标

	// 设置 图片菜单 图片菜单的好处就是直接使用图片就好了
    MenuItemImage *settingMenuItem = MenuItemImage::create(
                             "menu/setting-up.png",
                             "menu/setting-down.png",
							 CC_CALLBACK_1(HelloWorld::menuItemSettingCallback, this)); 

	settingMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(480, 400)));	

	// 帮助 图片菜单
    MenuItemImage *helpMenuItem = MenuItemImage::create(
                             "menu/help-up.png",
                             "menu/help-down.png",
							 CC_CALLBACK_1(HelloWorld::menuItemHelpCallback, this));	

	helpMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(860, 480)));
	//在这里，精灵菜单和图片菜单没什么区别，视觉效果一样，也一样有回调函数
	
	Menu* mu = Menu::create(startMenuItem, settingMenuItem, helpMenuItem, NULL);//指定菜单  NULL指定菜单列表的结束
	mu->setPosition(Vec2::ZERO);//菜单处于坐标原点 - 因为菜单项已经都指定位置了
	this->addChild(mu);


    return true;
}

//回调函数
void HelloWorld::menuItemHelpCallback(Ref* pSender)
{
    MenuItem* item = (MenuItem*)pSender;
	log("Touch Help %p", item);
}

void HelloWorld::menuItemStartCallback(Ref* pSender)
{
    MenuItem* item = (MenuItem*)pSender;
	log("Touch Start %p", item);
}

void HelloWorld::menuItemSettingCallback(Ref* pSender)
{
    MenuItem* item = (MenuItem*)pSender;
	log("Touch Setting %p", item);
}
