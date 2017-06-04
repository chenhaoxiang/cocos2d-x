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
    /**  you can create scene with following comment code instead of using csb file.
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    **/
    
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
	//创建Request对象
	auto request = new HttpRequest();
	//设置请求网址
	request->setUrl("http://httpbin.org/");
	//设置请求类型
	request->setRequestType(HttpRequest::Type::GET);
	//设置请求的数据
	//char data[50] = "data";
	//request->setRequestData(data,strlen(data));
	//完整的Request对象已经创建成功了

	request->setResponseCallback(CC_CALLBACK_2(HelloWorld::complete,this));
	//CC_CALLBACK_n  n这个数字，表示回调函数里面包含几个形参
	//HelloWorld::complete不加括号，表示传进来的是这个函数的地址！加了括号就表示运行了！  this表示接受该函数的类

	//创建HttpClient对象
	auto client = HttpClient::getInstance();//getInstance静态成员函数-单例模式模型
	client->setTimeoutForConnect(60);//当客户端向服务端发送请求超过这个时间，就会返回一个错误信息
	client->setTimeoutForRead(100);//接收数据的读取时间
	client->send(request);
	request->release();//释放请求
	/* 
    auto rootNode = CSLoader::createNode("MainScene.csb");
    addChild(rootNode);*/

    return true;

}
//实现回调函数
void HelloWorld::complete(HttpClient *client, HttpResponse *response){
	//使用HttpResponse类的相关函数，获取状态和数据
	log("response code is:%d",response->getResponseCode());//获取请求返回的状态码
	if (response->isSucceed()){//判断返回是否成功  成功就返回true
		把数据输出到字符串 1
		std::vector<char> * data = response->getResponseData();
		std::string str1 ;

		log("response data is:");
		
		for (int i = 0; i < data->size(); i++){
			str1 = str1 + (*data)[i];
			//log("%c",(*data)[i]);
		//	//因为data是一个指针，所以需要取内容操作符，(*data)这样获取的就是数组的首地址，然后再加上角标
		}
		log(str1.c_str());
	}
	else{
		log("error msg is:%s", response->getErrorBuffer()); // getErrorBuffer-会返回请求数据错误的信息
	}

}
