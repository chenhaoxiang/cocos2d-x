package chenhaoxiang.cn.testmagicwindow;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;

import java.util.Map;

import cn.magicwindow.MLinkAPIFactory;
import cn.magicwindow.MWConfiguration;
import cn.magicwindow.MagicWindowSDK;
import cn.magicwindow.Session;
import cn.magicwindow.mlink.MLinkCallback;
import cn.magicwindow.mlink.MLinkIntentBuilder;
import cn.magicwindow.mlink.annotation.MLinkDefaultRouter;

/**  启动页
 * Created by Administrator on 2017/8/11 0011.
 */

public class HomeMWActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.homemw);
        initMW();

        /* //这种方法会跳转到指定页面后，点击返回就退出程序了
        if (getIntent().getData() != null) {
            MLinkAPIFactory.createAPI(this).router(this, getIntent().getData());
            //跳转后结束当前activity
            finish();
        } else {
            //todo: 应用宝跳转有两个方式,方式①
            MLinkAPIFactory.createAPI(this).checkYYB();
            gotoHome();
        }
        */

        //解决通过mLink跳转直达的页面，如何做到“返回时进入首页，而不是退出程序”
        //跳转到首页
        gotoHome();
        //跳转router调用
        if (getIntent().getData()!=null) {
            MLinkAPIFactory.createAPI(this).router(getIntent().getData());
        } else {
            //如果需要应用宝跳转，则调用。否则不需要
            MLinkAPIFactory.createAPI(this).checkYYB();
        }
        //跳转后结束当前activity
        finish();

    }

    private static void register(Context context) {
        MLinkAPIFactory.createAPI(context).registerDefault(new MLinkCallback() {
            @Override
            public void execute(Map<String, String> map, Uri uri, Context context) {
                MLinkIntentBuilder.buildIntent(context, MainActivity.class);

            }
        });
        // mLinkKey:  mLink 的 key, mLink的唯一标识
        MLinkAPIFactory.createAPI(context).register("mLinkHello", new MLinkCallback() {
            @Override
            public void execute(Map<String, String> map, Uri uri, Context context) {
                Intent intent = new Intent(context, ParaSetActivity.class);
                intent.putExtra("id",map.get("id"));
                intent.putExtra("name",map.get("name"));
                intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK | Intent.FLAG_ACTIVITY_CLEAR_TOP);
                context.startActivity(intent);
            }
        });
    }

    private void gotoHome() {
        startActivity(new Intent(this, MainActivity.class));
        finish();
    }

    private void initMW(){
        MWConfiguration config = new MWConfiguration(this);
        config.setLogEnable(true)//打开魔窗Log信息
//  .setPageTrackWithFragment(true)//是否统计Fragment页面
//  .setCustomWebViewTitleBarOn()//代码内定义webview标题
                .setSharePlatform(MWConfiguration.ORIGINAL);
        MagicWindowSDK.initSDK(config);
        MLinkAPIFactory.createAPI(this).registerWithAnnotation(this);
        register(this);
    }

    @Override
    protected void onPause() {
        Session.onPause(this);
        super.onPause();
    }

    @Override
    protected void onResume() {
        Session.onResume(this);
        super.onResume();
    }


}
