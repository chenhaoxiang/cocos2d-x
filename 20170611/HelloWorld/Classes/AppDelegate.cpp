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

//这个函数是在程序启动的时候会调用它，也就是在游戏启动的时候调用，一般进行游戏的初始化，比如游戏的导演啊，场景啊等在这里进行初始化。 
bool AppDelegate::applicationDidFinishLaunching() {
    // 初始化导演
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();//打开一个视图(使用OpenGL渲染的一个画布)
	//上面这行代码很牛逼哦，实际上，它在不同的平台都能进行初始化视图！在win32下初始化win32的窗口，在安卓上就是安卓的view等，它是和硬件打交道的了！

	
    if(!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)//平台判断
        //设置程序标题栏文字  //有一个默认窗口大小
		glview = GLViewImpl::createWithRect("Hello Cocos2d", cocos2d::Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
#else
        glview = GLViewImpl::create("Hello Cocos2d");
#endif
        director->setOpenGLView(glview);
    }

    // 设置是否显示帧率  在调试的时候一般设置为true  正式发布了设置为false
    director->setDisplayStats(true);

	//设置帧率  每秒播放图片,或者刷新场景的次数 1/60就是代表着1s刷新60次
	//设置大小要看你的实际应用情况了
    director->setAnimationInterval(1.0f / 60);

	//设置不同宽高的解决方案 
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

    // 创建场景
    auto scene = HelloWorld::createScene();

    // 场景跳转
    director->runWithScene(scene);

    return true;
}

//退到后台，就是点击home键，回到桌面。接电话或者跳到另一个应用程序去，都会调用这个函数。
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be paused
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

//从后台重新回到前台，也就是从手机任务栏重新回到游戏，会调用这个函数   
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
