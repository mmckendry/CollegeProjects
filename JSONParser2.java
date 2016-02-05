protected void getJsonFeed2()
	{
		String url = "json.php";	
		//String url = "http://ergast.com/api/f1/drivers/alonso/constructors/renault/seasons.json";
		RequestBuilder builder = new RequestBuilder(RequestBuilder.GET, url);
		
		try{
			
			Request response = builder.sendRequest("", new RequestCallback()
			{

				@Override
				public void onResponseReceived(Request request,
						Response response)
				{
					String html = "<table>";
					JSONObject j = (JSONObject) JSONParser.parse(response.getText());
					
					JSONString disneyLand = (JSONString) j.get("name");
					
					JSONArray lands = (JSONArray) j.get("lands");
					
					html += "<tr><th>" + disneyLand +"</th></tr>";
					
					for(int i = 0; i<lands.size(); i++)
					{
						JSONObject obj = (JSONObject)lands.get(i); 
					
						String landname = ((JSONString)obj.get("land_name")).toString().replace("\""," ");
						
						JSONArray rides = (JSONArray)obj.get("rides");
						
						for(int rI = 0; rI < rides.size(); rI++ ){
							JSONObject objR = (JSONObject)rides.get(rI);
							String rideName = ((JSONString)objR.get("name")).toString().replace("\""," ");
							html += "<tr><td>Ride Name: "+ rideName +"</td></tr>";
							JSONArray descr = (JSONArray)objR.get("description");
							
							for(int dI = 0; dI < descr.size() ; dI++){
								JSONValue objD = (JSONValue)descr.get(dI);
								String description = objD.toString();
								html += "<tr><td>Description : "+ description +"</td></tr>";
							} 
							
							
						
						}
						
						html += "<tr><th>"+ landname  + "</th></tr>" ;
					}
					
					
					
					
					
					html+="</table>";
					f1Stats.setHTML(html);	
					
				}