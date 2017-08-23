#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

#include "MyUtility.h"

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


	std::string name = "jack";//直接赋值

	log("name = %s",name);//直接这样会出现乱码问题，因为log用的不对
	//我们可以去看log函数:void CC_DLL log(const char * format, ...) CC_FORMAT_PRINTF(1, 2);类型是const char*

	log("name = %s", name.c_str());

	std::string *name1 = new std::string("jack");//直接赋值    
	log("name1 = %s", name1->c_str());

    auto visibleSize = Director::getInstance()->getVisibleSize();//得到屏幕的大小(可见区域大小)
    Vec2 origin = Director::getInstance()->getVisibleOrigin();//得到可见区域大小的左下角坐标

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
	//把菜单项放到菜单里
    auto menu = Menu::create(closeItem, NULL);
	//指定菜单的位置 设置显示的坐标位置
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);//把菜单放到当前层


	__String *name2 = __String::create("Hi,Tony");//得到对象指针，因为是通过静态create函数获取的，不需要我们delete
	log("name = %s", name2->getCString());

	const char* cstring = "Hi,Tonny";
	__String *name3 = __String::createWithFormat("%s", cstring);//将char转换为__String

	std::string string = "Hi,Tonny";
	__String *name4 = __String::createWithFormat("%s", string.c_str());//将std::string转换为__String


	int num = 123;
	__String *ns = __String::createWithFormat("%d", num);//这种方式可以转换很多其他类型
	log("%d",ns->intValue());

	//解决中文乱码
	__String *ns2 = __String::create("大家好");
	const char* cns;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	std::string sns = MyUtility::gbk_2_utf8(ns2->getCString());
	cns = sns.c_str();
#else
	cns = ns2->getCString();
#endif
	log("%s", cns);
	auto label = LabelTTF::create(cns, "Arial", 24);//在cocos2d 3.01时，认为已经过时了，但是这种用法还是能用

	// 3. add your codes below...
	//标签 也就是中间显示的那个文字  以及加载字体
    //auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    



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
    

	auto label1 = LabelAtlas::create("HelloWorld", "fonts/tuffy_bold_italic-charmap.png", 48, 66, ' ');
	label1->setPosition(Vec2(visibleSize.width / 2 - label1->getContentSize().width / 2, visibleSize.height - label1->getContentSize().height));
	this->addChild(label1, 1);

	auto label2 = LabelBMFont::create("HelloWord","fonts/BMFont.fnt");
	label2->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - label2->getContentSize().height));
	this->addChild(label2,1);

    return true;
}


//点击close菜单项来回调的
void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
   Director::getInstance()->end();


	//条件编译 ，也就是满足条件就编译过去，如果不满足，就相当于注释了
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS) 
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    

    
}
