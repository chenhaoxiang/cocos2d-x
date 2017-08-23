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

	Sprite *bg = Sprite::create("menu/background.png"); //����ͼƬ����
	bg->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2));
	this->addChild(bg);

	MenuItemFont::setFontName("Times New Roman");//ʹ��ϵͳ���壬����ϵͳ���������
	MenuItemFont::setFontSize(86);//����ϵͳ����Ĵ�С
	MenuItemFont *item1 = MenuItemFont::create("Start",
		CC_CALLBACK_1(HelloWorld::menuItem1Callback, this)); //��������ϵͳ�����MenuItemFont


	MenuItemAtlasFont *item2 = MenuItemAtlasFont::create("Help",
		"menu/tuffy_bold_italic-charmap.png", 48, 65, ' ',
		CC_CALLBACK_1(HelloWorld::menuItem2Callback, this));

	Menu* mn = Menu::create(item1, item2, NULL);//��MenuItem�ŵ�Menu�����ֱ�Ӱ�MenuItem�ŵ�����
	mn->alignItemsVertically();//���ò˵�λ�ã���ֱ����
	this->addChild(mn);//�Ѳ˵��ŵ�����

	return true;
}


void HelloWorld::menuItem1Callback(Ref* pSender)
{
	//ʵ�������ﴫ�����Ĳ�����MenuItem���ͣ��������������ǿת��Ҳ����ֱ�Ӱ��β�����д��MenuItem����д��Ref
	MenuItem* item = (MenuItem*)pSender;
	//һ������£����ǲ���Ҫ���������ֻ������ҪһЩ�ض�����Ϣ������£����ǲ���Ҫ����ת����ֵ
	log("Touch Start Menu Item %p", item); //�����������ָ��ĵ�ַ��û������,������ֻ�����λص������������ˣ��Ҷ��󴫹�����
}

void HelloWorld::menuItem2Callback(Ref* pSender)
{
	MenuItem* item = (MenuItem*)pSender;
	log("Touch Help Menu Item %p", item);
}

