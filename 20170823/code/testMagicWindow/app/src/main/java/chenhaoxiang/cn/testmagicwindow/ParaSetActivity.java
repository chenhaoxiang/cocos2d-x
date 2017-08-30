package chenhaoxiang.cn.testmagicwindow;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.Intent;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;
import android.text.TextUtils;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

import cn.magicwindow.MLinkAPIFactory;
import cn.magicwindow.Session;
import cn.magicwindow.mlink.annotation.MLinkRouter;

/**
 * 跳转页
 * Created by Administrator on 2017/8/10 0010.
 */
//其中 mLinkKey即后台mLink服务对应的mLink Key。
@MLinkRouter(keys={"mLinkHello"})
public class ParaSetActivity extends AppCompatActivity {
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.layout);
//        String param = "";
        //通过intent方式获取动态参数值
//        Intent intent = getIntent();
//        if (intent != null && intent.hasExtra("chx_id")) {
//            param = intent.getStringExtra("chx_id");
//            Log.i("tag","param2:"+param);
//            new AlertDialog.Builder(this) .setTitle("标题1:"+param).setMessage(param) .setPositiveButton("确定", null) .show();
//        }

        TextView textView=(TextView) findViewById(R.id.textView);
//        textView.setText("["+param+"]");
        showDynamicParam(textView);

    }

    public static void show(String param,Activity sh){
        new AlertDialog.Builder(sh) .setTitle("标题").setMessage(param) .setPositiveButton("确定", null) .show();
    }

    private void showDynamicParam(TextView textView) {
        Intent intent = getIntent();
        if (intent != null) {
            String str="";
            if(!TextUtils.isEmpty(intent.getStringExtra("id"))){
                str = "id="+intent.getStringExtra("id")+",";
            }
            if(!TextUtils.isEmpty(intent.getStringExtra("name"))){
                textView.setText(str+"name="+intent.getStringExtra("name"));
            }
        }
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
        intent.setClass(ParaSetActivity.this, MainActivity.class);
        startActivity(intent);
    }
}
