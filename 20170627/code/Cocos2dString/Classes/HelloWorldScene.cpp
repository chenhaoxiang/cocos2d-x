#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

#include "MyUtility.h"

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


	std::string name = "jack";//ֱ�Ӹ�ֵ

	log("name = %s",name);//ֱ������������������⣬��Ϊlog�õĲ���
	//���ǿ���ȥ��log����:void CC_DLL log(const char * format, ...) CC_FORMAT_PRINTF(1, 2);������const char*

	log("name = %s", name.c_str());

	std::string *name1 = new std::string("jack");//ֱ�Ӹ�ֵ    
	log("name1 = %s", name1->c_str());

    auto visibleSize = Director::getInstance()->getVisibleSize();//�õ���Ļ�Ĵ�С(�ɼ������С)
    Vec2 origin = Director::getInstance()->getVisibleOrigin();//�õ��ɼ������С�����½�����

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
	//�Ѳ˵���ŵ��˵���
    auto menu = Menu::create(closeItem, NULL);
	//ָ���˵���λ�� ������ʾ������λ��
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);//�Ѳ˵��ŵ���ǰ��


	__String *name2 = __String::create("Hi,Tony");//�õ�����ָ�룬��Ϊ��ͨ����̬create������ȡ�ģ�����Ҫ����delete
	log("name = %s", name2->getCString());

	const char* cstring = "Hi,Tonny";
	__String *name3 = __String::createWithFormat("%s", cstring);//��charת��Ϊ__String

	std::string string = "Hi,Tonny";
	__String *name4 = __String::createWithFormat("%s", string.c_str());//��std::stringת��Ϊ__String


	int num = 123;
	__String *ns = __String::createWithFormat("%d", num);//���ַ�ʽ����ת���ܶ���������
	log("%d",ns->intValue());

	//�����������
	__String *ns2 = __String::create("��Һ�");
	const char* cns;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	std::string sns = MyUtility::gbk_2_utf8(ns2->getCString());
	cns = sns.c_str();
#else
	cns = ns2->getCString();
#endif
	log("%s", cns);
	auto label = LabelTTF::create(cns, "Arial", 24);//��cocos2d 3.01ʱ����Ϊ�Ѿ���ʱ�ˣ����������÷���������

	// 3. add your codes below...
	//��ǩ Ҳ�����м���ʾ���Ǹ�����  �Լ���������
    //auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    



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
    

	auto label1 = LabelAtlas::create("HelloWorld", "fonts/tuffy_bold_italic-charmap.png", 48, 66, ' ');
	label1->setPosition(Vec2(visibleSize.width / 2 - label1->getContentSize().width / 2, visibleSize.height - label1->getContentSize().height));
	this->addChild(label1, 1);

	auto label2 = LabelBMFont::create("HelloWord","fonts/BMFont.fnt");
	label2->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - label2->getContentSize().height));
	this->addChild(label2,1);

    return true;
}


//���close�˵������ص���
void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
   Director::getInstance()->end();


	//�������� ��Ҳ�������������ͱ����ȥ����������㣬���൱��ע����
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS) 
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    

    
}
