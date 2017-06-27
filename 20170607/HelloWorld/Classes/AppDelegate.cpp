#include "AppDelegate.h"
#include "HelloWorldScene.h"

USING_NS_CC;

static cocos2d::Size designResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate() 
{
}

// if you want a different context, modify the value of glContextAttrs
// it will affect all platforms
void AppDelegate::initGLContextAttrs()
{
    // set OpenGL context attributes: red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

// if you want to use the package manager to install more packages,  
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

//����������ڳ���������ʱ����������Ҳ��������Ϸ������ʱ����ã�һ�������Ϸ�ĳ�ʼ����������Ϸ�ĵ��ݰ�������������������г�ʼ���� 
bool AppDelegate::applicationDidFinishLaunching() {
    // ��ʼ������
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();//��һ����ͼ(ʹ��OpenGL��Ⱦ��һ������)
	//�������д����ţ��Ŷ��ʵ���ϣ����ڲ�ͬ��ƽ̨���ܽ��г�ʼ����ͼ����win32�³�ʼ��win32�Ĵ��ڣ��ڰ�׿�Ͼ��ǰ�׿��view�ȣ����Ǻ�Ӳ���򽻵����ˣ�

	
    if(!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)//ƽ̨�ж�
        //���ó������������  //��һ��Ĭ�ϴ��ڴ�С
		glview = GLViewImpl::createWithRect("Hello Cocos2d", cocos2d::Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
#else
        glview = GLViewImpl::create("Hello Cocos2d");
#endif
        director->setOpenGLView(glview);
    }

    // �����Ƿ���ʾ֡��  �ڵ��Ե�ʱ��һ������Ϊtrue  ��ʽ����������Ϊfalse
    director->setDisplayStats(true);

	//����֡��  ÿ�벥��ͼƬ,����ˢ�³����Ĵ��� 1/60���Ǵ�����1sˢ��60��
	//���ô�СҪ�����ʵ��Ӧ�������
    director->setAnimationInterval(1.0f / 60);

	//���ò�ͬ��ߵĽ������ 
    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
    auto frameSize = glview->getFrameSize();
    // if the frame's height is larger than the height of medium size.
    if (frameSize.height > mediumResolutionSize.height)
    {        
        director->setContentScaleFactor(MIN(largeResolutionSize.height/designResolutionSize.height, largeResolutionSize.width/designResolutionSize.width));
    }
    // if the frame's height is larger than the height of small size.
    else if (frameSize.height > smallResolutionSize.height)
    {        
        director->setContentScaleFactor(MIN(mediumResolutionSize.height/designResolutionSize.height, mediumResolutionSize.width/designResolutionSize.width));
    }
    // if the frame's height is smaller than the height of medium size.
    else
    {        
        director->setContentScaleFactor(MIN(smallResolutionSize.height/designResolutionSize.height, smallResolutionSize.width/designResolutionSize.width));
    }


    register_all_packages();

    // ��������
    auto scene = HelloWorld::createScene();

    // ������ת
    director->runWithScene(scene);

    return true;
}

//�˵���̨�����ǵ��home�����ص����档�ӵ绰����������һ��Ӧ�ó���ȥ������������������
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be paused
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

//�Ӻ�̨���»ص�ǰ̨��Ҳ���Ǵ��ֻ����������»ص���Ϸ��������������   
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
