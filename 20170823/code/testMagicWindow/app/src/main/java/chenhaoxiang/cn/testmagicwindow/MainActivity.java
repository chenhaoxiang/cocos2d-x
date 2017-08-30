package chenhaoxiang.cn.testmagicwindow;

import android.app.AlertDialog;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;

import cn.magicwindow.MLinkAPIFactory;
import cn.magicwindow.MWConfiguration;
import cn.magicwindow.MagicWindowSDK;
import cn.magicwindow.Session;
import cn.magicwindow.mlink.annotation.MLinkDefaultRouter;

/**
 * 首页
 */
@MLinkDefaultRouter
public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        ////实现效果：App未安装时，通过短链跳转到下载页面，安装后，第一次打开实现场景还原。
        //// 在首页的onCreate()内调用MLinkAPIFactory.createAPI(this).deferredRouter(); 来实现场景还原。
        MLinkAPIFactory.createAPI(this).deferredRouter();
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

    public void onClick(View view)
    {
        Intent intent = new Intent();
        intent.setClass(MainActivity.this, ParaSetActivity.class);
        startActivity(intent);
    }

}
