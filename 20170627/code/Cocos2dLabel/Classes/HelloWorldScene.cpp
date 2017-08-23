#include "HelloWorldScene.h"
#include "MyUtility.h"

USING_NS_CC;

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
bool HelloWorld::init()
{
	if ( !Layer::init() )
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
		origin.y + closeItem->getContentSize().height/2));


	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);


	auto label1 = Label::createWithSystemFont(MyUtility::gbk_2_utf8("中国"), "Arial", 36);
	label1->setPosition(Vec2(origin.x + visibleSize.width/2,
		origin.y + visibleSize.height - 100));
	this->addChild(label1, 1);//Win32的字体库可以在控制面板中找到

	/*
	auto label2 = Label::createWithTTF("Hello World2", "fonts/Marker Felt.ttf", 36);
	label2->setPosition(Vec2(origin.x + visibleSize.width/2,
		origin.y + visibleSize.height - 200));
	this->addChild(label2, 1);

	auto label3 = Label::createWithBMFont("fonts/BMFont.fnt", "Hello World3");
	label3->setPosition(Vec2(origin.x + visibleSize.width/2,
		origin.y + visibleSize.height - 300));
	this->addChild(label3, 1);


	TTFConfig ttfConfig("fonts/Marker Felt.ttf",
		36,
		GlyphCollection::DYNAMIC);
	auto label4 = Label::createWithTTF(ttfConfig, "Hello World4");
	label4->setPosition(Vec2(origin.x + visibleSize.width/2,
		origin.y + visibleSize.height - 400));
	this->addChild(label4 , 1);

	ttfConfig.outlineSize = 4;
	auto label5 = Label::createWithTTF(ttfConfig, "Hello World5");
	//ttfConfig-结构体配置，能配置更多的特效，比如描边，阴影，闪烁的文字等
	//只能是TTF文件的，才能使用这些特效
	label5->setPosition(Vec2(origin.x + visibleSize.width/2,
		origin.y + visibleSize.height - 500));
	label5->enableShadow(Color4B(255,255,255,128), Size(4, -4));//设置阴影，阴影的颜色，阴影的大小 
	label5->setColor(Color3B::RED);//设置颜色
	
	this->addChild(label5, 1);
	*/

	auto label3 = Label::createWithBMFont("fonts/bitmapFontChinese.fnt", MyUtility::gbk_2_utf8("中国2"));
	label3->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - 350));
	this->addChild(label3, 1);

	TTFConfig ttfConfig("fonts/STLITI.ttf", 36, GlyphCollection::DYNAMIC);//中文字体库，华文隶书
	auto labe4 = Label::createWithTTF(ttfConfig, MyUtility::gbk_2_utf8("美好的一天啊"),
		TextHAlignment::CENTER,
		visibleSize.width);
	labe4->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - 500));
	this->addChild(labe4, 1);

	return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
	return;
#endif

	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
