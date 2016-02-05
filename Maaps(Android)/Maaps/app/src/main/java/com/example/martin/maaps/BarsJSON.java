package com.example.martin.maaps;

import android.app.ListActivity;
import android.net.http.AndroidHttpClient;
import android.os.AsyncTask;
import android.os.Bundle;
import android.widget.ArrayAdapter;

import org.apache.http.HttpResponse;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.ResponseHandler;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.BasicResponseHandler;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;
import org.json.JSONTokener;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;


public class BarsJSON extends ListActivity {


    static List<String> result = new ArrayList<String>();

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        new Bars().execute();


    }


    private class Bars extends AsyncTask<Void, Void, List<String>> {

        //private static final String CONSUMER_KEY = "X-Mashape-Key, rgF7OCus6Ymshr2nNyMcaEzGZWNCp1C3HOzjsn7vIbyQDsUlmO";
        //  private static final String URL = "https://george-vustrey-weather.p.mashape.com/api.php?location=Dublin" + "Header{"+CONSUMER_KEY+"};";
        private static final String URL = "https://github.com/mmckendry/BarJSONFeed/blob/master/barJson.xml";

        AndroidHttpClient mClient = AndroidHttpClient.newInstance("");


        @Override
        protected List<String> doInBackground(Void... params) {
            HttpGet request = new HttpGet(URL);

            JSONResponseHandler responseHandler = new JSONResponseHandler();
            try {
                return mClient.execute(request, responseHandler);
            } catch (ClientProtocolException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return null;
        }

        @Override
        protected void onPostExecute(List<String> result) {
            if (null != mClient)
                mClient.close();
            //setListAdapter(new ArrayAdapter<String>(
            // MainActivity.this,
            // R.layout.list_item, result));
        }


        private class JSONResponseHandler implements ResponseHandler<List<String>> {

            private static final String NAME = "name";
            private static final String LATITUDE = "lat";
            private static final String LONGITUDE = "lng";
            private static final String AREA = "city/town";


            @Override
            public List<String> handleResponse(HttpResponse response)
                    throws ClientProtocolException, IOException {

                String JSONResponse = new BasicResponseHandler()
                        .handleResponse(response);
                try {

                    JSONObject responseObject = (JSONObject) new JSONTokener(
                            JSONResponse).nextValue();

                    JSONArray values = responseObject.names();
                    JSONArray weather = responseObject.toJSONArray(values);

                    for (int idx = 0; idx < weather.length(); idx++) {


                        JSONObject weatherObj = weather.getJSONObject(idx);


                        // result
                        result.add(NAME + ": "
                                + weatherObj.get(NAME) + "\n"
                                + "\n" + LATITUDE + ": "
                                + weatherObj.getString(LATITUDE) + "\n"
                                + "\n" + LONGITUDE + ": "
                                + weatherObj.get(LONGITUDE) + " F'" + "\n"
                                + "\n" + AREA + ": "
                                + weatherObj.get(AREA));


                    }


                } catch (JSONException e) {
                    e.printStackTrace();
                }

                return result;

            }

        }
    }
}



