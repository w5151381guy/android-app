package com.example.kirito_fan.listview;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        ListView list = (ListView)findViewById(R.id.listView);

        final String[] str_list = {"牛肉麵","肉臊飯","陽春麵"};

        ArrayAdapter<String> adapter;

        adapter = new ArrayAdapter(this,android.R.layout.simple_list_item_1,str_list);

        list.setAdapter(adapter);
        list.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                String meal = str_list[position];
                Toast.makeText(MainActivity.this,meal,Toast.LENGTH_LONG).show();
            }
        });
    }
}
