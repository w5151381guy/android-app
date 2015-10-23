package com.example.kirito_fan.bmi;

import android.app.AlertDialog;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import java.text.DecimalFormat;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        /*add tone when button is clicked*/
        Button count;
        count = (Button) findViewById(R.id.button);
        count.setOnClickListener(calcBMI);
    }
       public OnClickListener calcBMI = new OnClickListener(){
           public void onClick(View v){
               DecimalFormat nf = new DecimalFormat("0.00");
               /*輸入框*/
               EditText fieldheight = (EditText)findViewById(R.id.editText);
               EditText fieldweight = (EditText)findViewById(R.id.editText2);
               /*string轉double*/
               double height = Double.parseDouble(fieldheight.getText().toString())/100;
               double weight = Double.parseDouble(fieldweight.getText().toString());
               double BMI = weight/height/height;
               /*顯示框*/
               TextView answer = (TextView)findViewById(R.id.textView3);
               /*double轉string*/
               answer.setText("Your BMI is:"+nf.format(BMI));
               /*give suggestion*/
               TextView suggest = (TextView)findViewById(R.id.textView4);
               /*先到strings.xml設定參數*/
               if(BMI > 24)
               {
                   suggest.setText(R.string.advice_heavy);
               }
               if(BMI > 18.5 && BMI <=24)
               {
                   suggest.setText(R.string.advice_average);
               }
               if(BMI < 18.5)
               {
                   suggest.setText(R.string.advice_light);
               }
       }
       };
    /*設定選單*/
    /*先到menu_main.xml裡面打上icon的相關設定*/
    @Override
    public boolean onOptionsItemSelected(MenuItem item){
        //TODO Auto-generated method stub
        switch (item.getItemId()){
            case R.id.action_about:
                openOptionsDialog();
                break;
            case R.id.action_close:
                finish();
                break;
        }
        return super.onOptionsItemSelected(item);
    }
    /*實作對話框*/
    public void openOptionsDialog(){
        AlertDialog.Builder dialog = new AlertDialog.Builder(MainActivity.this);
            dialog.setTitle("關於 Android BMI");
            dialog.setMessage("Android BMI Calc");
            dialog.show();
    };
}


