#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 创建场景对象
    auto scene = Scene::create();
    // 创建层对象
    auto layer = HelloWorld::create();
    // 把层放到场景里
    scene->addChild(layer);
    // 返回这个场景
    return scene;
}

// on "init" you need to initialize your instance
// 初始化当前这个层
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();//得到屏幕的大小(可见区域大小)
    Vec2 origin = Director::getInstance()->getVisibleOrigin();//得到可见区域大小的左下角坐标
	cocos2d::log("visibleSize:%f,%f", visibleSize.width, visibleSize.height);//visibleSize:480.000000,320.000000
	cocos2d::log("origin:%f,%f", origin.x, origin.y);//origin:0.000000,0.000000

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
	// 得到图片菜单 以及设置回调函数
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    //关闭的按钮 
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
	//把菜单项放到菜单里
    auto menu = Menu::create(closeItem, NULL);
	//指定菜单的位置 设置显示的坐标位置
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);//把菜单放到当前层

    /////////////////////////////
    // 3. add your codes below...

    //标签 也就是中间显示的那个文字  以及加载字体
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
	//指定标签的位置
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

	//把标签加入到层中
    this->addChild(label, 1,123);//设置tag，方便后面获取

	//指定一个图片的精灵
    auto sprite = Sprite::create("HelloWorld.png");

    // 设置图片精灵的位置
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	//把图片精灵加入到层中
    this->addChild(sprite, 0);
    
	//更新函数
	//this->scheduleUpdate();//停止更新 -unscheduleUpdate();
	this->schedule(schedule_selector(HelloWorld::update), 1.0f / 60);//可以指定函数和时间间隔  停止更新 - unschedule(schedule_selector(HelloWorld::update));

    return true;
}

void HelloWorld::update(float dt){
	auto label = this->getChildByTag(123);//通过tag获取标签
	//label->setPosition(label->getPosition() + Vec2(2, -2));//移动标签 移动的距离就是 Vec2(2, -2)
	label->setPosition(label->getPosition() + Point(2, -2));//原来的3.0版本是Point,3.01就变成Vec2了
	//Vec-矢量，作用就是我们定义一个二维或者三维的矢量做一些事情，在这里是x轴和y轴的矢量，正负代表方向
}

//点击close菜单项来回调的
void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
   // Director::getInstance()->end();

	//停止更新
	//unscheduleUpdate();
	unschedule(schedule_selector(HelloWorld::update));

	//条件编译 ，也就是满足条件就编译过去，如果不满足，就相当于注释了
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS) 
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    

    
}
