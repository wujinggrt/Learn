package com.wujing.myapplication;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        // using java8's feature lambda
        MyInterface obj = (x) -> x * 2;
        int result = obj.process(100);

        TextView infoTextView = (TextView) findViewById(R.id.textInfo);
        Button calculateButton = (Button) findViewById(R.id.btnCalculate);

        // use lambda to response the clicking button event
        calculateButton.setOnClickListener((View) -> {
            infoTextView.setText(String.valueOf(result));
        });
    }
}
