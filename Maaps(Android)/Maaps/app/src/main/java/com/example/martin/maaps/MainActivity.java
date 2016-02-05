package com.example.martin.maaps;

import android.app.ListActivity;
import android.location.Criteria;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.net.http.AndroidHttpClient;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.v7.app.ActionBarActivity;
import android.util.Log;
import android.widget.ArrayAdapter;
import android.widget.TextView;

import com.google.android.gms.common.ConnectionResult;
import com.google.android.gms.common.GooglePlayServicesUtil;
import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.SupportMapFragment;
import com.google.android.gms.maps.model.BitmapDescriptor;
import com.google.android.gms.maps.model.BitmapDescriptorFactory;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.Marker;
import com.google.android.gms.maps.model.MarkerOptions;
import com.google.android.gms.maps.model.Polygon;
import com.google.android.gms.maps.model.PolygonOptions;
import com.google.android.gms.maps.model.Polyline;
import com.google.android.gms.maps.model.PolylineOptions;
import com.example.martin.maaps.BarsJSON;

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


public class MainActivity extends ActionBarActivity implements LocationListener {

    static final LatLng NAVAN = new LatLng(53.655429000000000000, -6.686700200000018000);
    static final LatLng HOME = new LatLng(53.67943990000001, -6.587459399999943);
   // static List<String> result = new ArrayList<String>();

    GoogleMap tMap;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);



        if (!isGooglePlayServicesAvailable()) {
            finish();
        }
        setContentView(R.layout.activity_main);
        SupportMapFragment supportMapFragment =
                (SupportMapFragment) getSupportFragmentManager().findFragmentById(R.id.tMap);


        tMap = supportMapFragment.getMap();
        tMap.setMyLocationEnabled(true);

        tMap.setMapType(GoogleMap.MAP_TYPE_HYBRID);


        Marker home = tMap.addMarker(new MarkerOptions().position(NAVAN)
                .title("Navan"));
        Marker dest = tMap.addMarker(new MarkerOptions()
                .position(HOME)
                .title("Home")
                .snippet("home is where the heart is"));
                //.icon(BitmapDescriptorFactory
               // .fromResource(R.drawable.ic_launcher)));


        LocationManager locationManager = (LocationManager) getSystemService(LOCATION_SERVICE);
        Criteria criteria = new Criteria();
        String bestProvider = locationManager.getBestProvider(criteria, true);
        Location location = locationManager.getLastKnownLocation(bestProvider);
        if (location != null) {
            onLocationChanged(location);
        }
        locationManager.requestLocationUpdates(bestProvider, 20000, 0, this);


        PolylineOptions pLine = new PolylineOptions().add(NAVAN);
        pLine.add(HOME);
        pLine.add();

        Polyline addedLine = tMap.addPolyline(pLine);
        //new Bars().execute();




    }



    public void drawingLines() {

    }

    @Override
    public void onLocationChanged(Location location) {
        TextView locationTv = (TextView) findViewById(R.id.latlongLocation);
        double latitude = location.getLatitude();
        double longitude = location.getLongitude();
        LatLng latLng = new LatLng(latitude, longitude);
        tMap.addMarker(new MarkerOptions().position(latLng));
        tMap.moveCamera(CameraUpdateFactory.newLatLng(latLng));
        tMap.animateCamera(CameraUpdateFactory.zoomTo(15), 5000, null);
        locationTv.setText("Latitude:" + latitude + ", Longitude:" + longitude);

        PolygonOptions rectOptions = new PolygonOptions()
                .add(new LatLng(latitude, longitude),
                        new LatLng(latitude + 0.05, longitude),
                        new LatLng(latitude + 0.05, longitude + -0.05),
                        new LatLng(latitude, longitude + -0.05),
                        new LatLng(latitude, longitude));

/*
        .add(new LatLng(37.35, -122.0),
                new LatLng(37.45, -122.0),
                new LatLng(37.45, -122.2),
                new LatLng(37.35, -122.2),
                new LatLng(37.35, -122.0));
*/

// Get back the mutable Polygon
        Polygon polygon = tMap.addPolygon(rectOptions);

    }

    @Override
    public void onProviderDisabled(String provider) {
        // TODO Auto-generated method stub
    }

    @Override
    public void onProviderEnabled(String provider) {
        // TODO Auto-generated method stub
    }

    @Override
    public void onStatusChanged(String provider, int status, Bundle extras) {
        // TODO Auto-generated method stub
    }

    private boolean isGooglePlayServicesAvailable() {
        int status = GooglePlayServicesUtil.isGooglePlayServicesAvailable(this);
        if (ConnectionResult.SUCCESS == status) {
            return true;
        } else {
            GooglePlayServicesUtil.getErrorDialog(status, this, 0).show();
            return false;
        }
    }

/*
    static List<String> result = new ArrayList<String>();




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
*/

}
