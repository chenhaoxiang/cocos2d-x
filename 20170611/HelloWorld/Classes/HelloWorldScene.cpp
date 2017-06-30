#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // ������������
    auto scene = Scene::create();
    // ���������
    auto layer = HelloWorld::create();
    // �Ѳ�ŵ�������
    scene->addChild(layer);
    // �����������
    return scene;
}

// on "init" you need to initialize your instance
// ��ʼ����ǰ�����
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();//�õ���Ļ�Ĵ�С(�ɼ������С)
    Vec2 origin = Director::getInstance()->getVisibleOrigin();//�õ��ɼ������С�����½�����
	cocos2d::log("visibleSize:%f,%f", visibleSize.width, visibleSize.height);//visibleSize:480.000000,320.000000
	cocos2d::log("origin:%f,%f", origin.x, origin.y);//origin:0.000000,0.000000

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
	// �õ�ͼƬ�˵� �Լ����ûص�����
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    //�رյİ�ť 
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
	//�Ѳ˵���ŵ��˵���
    auto menu = Menu::create(closeItem, NULL);
	//ָ���˵���λ�� ������ʾ������λ��
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);//�Ѳ˵��ŵ���ǰ��

    /////////////////////////////
    // 3. add your codes below...

    //��ǩ Ҳ�����м���ʾ���Ǹ�����  �Լ���������
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
	//ָ����ǩ��λ��
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

	//�ѱ�ǩ���뵽����
    this->addChild(label, 1,123);//����tag����������ȡ

	//ָ��һ��ͼƬ�ľ���
    auto sprite = Sprite::create("HelloWorld.png");

    // ����ͼƬ�����λ��
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	//��ͼƬ������뵽����
    this->addChild(sprite, 0);
    
	//���º���
	//this->scheduleUpdate();//ֹͣ���� -unscheduleUpdate();
	this->schedule(schedule_selector(HelloWorld::update), 1.0f / 60);//����ָ��������ʱ����  ֹͣ���� - unschedule(schedule_selector(HelloWorld::update));

    return true;
}

void HelloWorld::update(float dt){
	auto label = this->getChildByTag(123);//ͨ��tag��ȡ��ǩ
	//label->setPosition(label->getPosition() + Vec2(2, -2));//�ƶ���ǩ �ƶ��ľ������ Vec2(2, -2)
	label->setPosition(label->getPosition() + Point(2, -2));//ԭ����3.0�汾��Point,3.01�ͱ��Vec2��
	//Vec-ʸ�������þ������Ƕ���һ����ά������ά��ʸ����һЩ���飬��������x���y���ʸ��������������
}

//���close�˵������ص���
void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
   // Director::getInstance()->end();

	//ֹͣ����
	//unscheduleUpdate();
	unschedule(schedule_selector(HelloWorld::update));

	//�������� ��Ҳ�������������ͱ����ȥ����������㣬���൱��ע����
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS) 
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    

    
}
