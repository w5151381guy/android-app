package com.example.user.listview;

import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Adapter;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.SimpleAdapter;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.TwoLineListItem;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.SimpleTimeZone;


public class MainActivity extends ActionBarActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final String ID_TITLE = "TITLE",ID_SUBTITLE = "SUBTITLE";

        String[] title =new String[]{"消夜","夜衝","運動","讀書","夜唱","吃飯","聯誼"};
        String[] subtitle = new String[]{"發起人A","發起人B","發起人C","發起人D","發起人E","發起人F","發起人G"};

        ArrayList<HashMap<String,String>> myListData = new ArrayList<HashMap<String,String>>();
        for(int i=0;i<title.length;++i)
        {
            HashMap<String,String> item = new HashMap<String,String>();
            item.put(ID_TITLE,title[i]);
            item.put(ID_SUBTITLE,subtitle[i]);
            myListData.add(item);
        }
        ListView listview = (ListView)findViewById(R.id.listView);

        SimpleAdapter adapter = new SimpleAdapter(this,myListData,android.R.layout.simple_list_item_2,
                new String[] {ID_TITLE,ID_SUBTITLE},
                new int[] {android.R.id.text1,android.R.id.text2});
        listview.setAdapter(adapter);

        listview.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {

                if(view instanceof TwoLineListItem){
                    System.out.println("test1");
                }else {
                    System.out.println("test2");
                    String value = ((TextView) view).getText().toString();
                }
            }
        });
    }



}
