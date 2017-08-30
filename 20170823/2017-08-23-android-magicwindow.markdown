---
layout: post
title: "【安卓】安卓集成魔窗-完整实例"
date: 2017-08-23 13:38:54 +0800
comments: true
categories: Android
tags: [Android, Java]
keyword: 陈浩翔, 谙忆, Java, 安卓,魔窗
description: 前些日子，公司安卓应用的魔窗出现问题，需要重新写过。于是，就有了此篇魔窗HelloWord。没有包含微信分享，如果有微信分享，无非就是再集成微信分享，将分享链接改为魔窗的mLink深度链接即可  
---

前些日子，公司安卓应用的魔窗出现问题，需要重新写过。于是，就有了此篇魔窗HelloWord。   
没有包含微信分享，如果有微信分享，无非就是再集成微信分享，将分享链接改为魔窗的mLink深度链接即可  

<!-- more -->
----------

魔窗官网:http://www.magicwindow.cn/

魔窗介绍就不重复了，想去了解的可以去官网看看、  
```
企业级的深度链接（Deeplink）解决方案mLink
场景式连接/服务连接
内容分发
跨App Store/应用市场的渠道分析
```

可以这么理解，通过浏览器访问某一链接(可以带参数)，直接在本机上打开安装的应用(通过scheme)，通过配置或者参数跳转到不同的场景  

首先当然是去注册账号咯。   
然后进入到管理后台，也就是http://mgnt.magicwindow.cn  

![](http://i.imgur.com/9d9Zn1E.png)  

填写产品信息：  
![](http://i.imgur.com/O0xpipe.png)  
这里的微信分享AppID，是你集成微信分享(微信会分配给你一个appid)后需要填写的。  

填写APP信息:
![](http://i.imgur.com/4OK2wSh.png)  
iOS应用的填写先不管，这里讲的是安卓。  
包名就是你的项目AndroidManifest.xml里面的包名：  
![](http://i.imgur.com/LwT2SXa.png)  
URL Scheme其实填写的是你的应用的唯一标识，你可以自定义，记住后面需要加```://```
下载地址是你没有安装应用时，访问链接后跳转的链接，一般填写应用下载地址  

魔窗位信息:  
![](http://i.imgur.com/wHpDWIO.png)  
不需要填写，直接点完成即可。  

下面就是选择添加mLink服务，选择好产品之后，点击添加mLink服务  
![](http://i.imgur.com/N2B1kxL.png)  

接下来就是填写信息了：  
![](http://i.imgur.com/Ml1sLgh.png)  

mLink服务名称自定义。可以有中文。  
mLink服务key： 页面key只能包含英文字母,数字和下划线，且只能以英文字母或者下划线开头,且长度不得大于50  
也就是mLink的唯一标识  
iOS URL我现在不管。  
Android URL： 第一个参数mLinkHello我是随便写的(可以自定义为其他的)，我到现在都不明白配置这个有什么用。  
官方文档解释为:  
![](http://i.imgur.com/zpUfGIi.png)  
貌似这是一个动态参数，我没用到这个，不管，我随便填写的。  
?问号后面的也是动态参数，这是我比较熟悉的传参。id和name为参数名。记得中间需要填写的是```=:```这两个符号不能分开写。  
点击保存即可。  
不出意外的话，会这样:  
![](http://i.imgur.com/nDlsJxM.png)  

现在配置完了，直接看代码吧。  

首先你需要创建一个启动页(Cocos2d-x开发的游戏也可以)，记得是启动页而不是首页。  
在AndroidManifest.xml中配置启动页:  
```xml
        <activity android:name=".HomeMWActivity">
            <intent-filter>
                <action android:name="android.intent.action.MAIN" />
                <category android:name="android.intent.category.LAUNCHER" />
            </intent-filter>
            <intent-filter>
                <data android:scheme="chenhaoxiang"/>
                <action android:name="android.intent.action.VIEW" />
                <category android:name="android.intent.category.DEFAULT" />
                <category android:name="android.intent.category.BROWSABLE" />
            </intent-filter>
        </activity>
```
首页:  
```xml
        <activity android:name=".MainActivity">
            <intent-filter>
                <category android:name="android.intent.category.DEFAULT"/>
            </intent-filter>
        </activity>
```
需要跳转的页面:
```xml
        <activity
            android:name=".ParaSetActivity"
            android:label="ParaSetActivity">
            <intent-filter>
                <category android:name="android.intent.category.DEFAULT"/>
            </intent-filter>
        </activity>
```
ParaSetActivity类上的注解的值为mLink的key  

实例说明，没有集成微信分享，想测试的，可以直接用mLink短链接带上参数，例如：https://aevcir.mlinks.cc/A0dY?id=1&name=chx  
在浏览器中直接访问，即可跳转到ParaSetActivity页面,参数值也可在app中读出  
实例中的MW_APPID请替换为自己的魔窗App Key，可以在产品管理中看到：  
![](http://i.imgur.com/i6h5nAB.png)  

更多的理解，可以通过下面的实例(使用android studio开发)去看看。也可以直接下载官方的DEMO  

#源代码下载地址：
<blockquote cite='陈浩翔'>
GITHUB源码下载地址:<strong>【<a href='http://chenhaoxiang.cn' target='_blank'>点我进行下载</a>】</strong></p>
</blockquote>


本文章由<a href="http://chenhaoxiang.cn/">[谙忆]</a>编写， 所有权利保留。 
欢迎转载，分享是进步的源泉。
<blockquote cite='陈浩翔'>
<p background-color='#D3D3D3'>转载请注明出处：<a href='http://chenhaoxiang.cn'><font color="green">http://chenhaoxiang.cn</font></a><br><br>
本文源自<strong>【<a href='http://chenhaoxiang.cn' target='_blank'>人生之旅_谙忆的博客</a>】</strong></p>
</blockquote>
