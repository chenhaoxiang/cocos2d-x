#include "HelloWorldScene.h"

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
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Sprite *bg = Sprite::create("menu/background.png"); //背景图片精灵
	bg->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2));
	this->addChild(bg);

	MenuItemFont::setFontName("Times New Roman");//使用系统字体，设置系统字体的名字
	MenuItemFont::setFontSize(86);//设置系统字体的大小
	MenuItemFont *item1 = MenuItemFont::create("Start",
		CC_CALLBACK_1(HelloWorld::menuItem1Callback, this)); //创建基于系统字体的MenuItemFont


	MenuItemAtlasFont *item2 = MenuItemAtlasFont::create("Help",
		"menu/tuffy_bold_italic-charmap.png", 48, 65, ' ',
		CC_CALLBACK_1(HelloWorld::menuItem2Callback, this));

	Menu* mn = Menu::create(item1, item2, NULL);//把MenuItem放到Menu里，不能直接把MenuItem放到层里
	mn->alignItemsVertically();//设置菜单位置，垂直对齐
	this->addChild(mn);//把菜单放到层里

	return true;
}


void HelloWorld::menuItem1Callback(Ref* pSender)
{
	//实际上这里传进来的参数是MenuItem类型，所以在这里可以强转，也可以直接把形参类型写成MenuItem，不写成Ref
	MenuItem* item = (MenuItem*)pSender;
	//一般情况下，我们不需要这个参数，只有在需要一些特定的信息的情况下，我们才需要进行转换拿值
	log("Touch Start Menu Item %p", item); //这个输出是输出指针的地址，没有意义,在这里只是掩饰回调函数起作用了！且对象传过来了
}

void HelloWorld::menuItem2Callback(Ref* pSender)
{
	MenuItem* item = (MenuItem*)pSender;
	log("Touch Help Menu Item %p", item);
}

