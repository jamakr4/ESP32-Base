#include <Wifi.h>;
#include <HTTPClient.h>;
#include <ArduinoJson.h>;

void setup() 
{
  Serial.beginn(115200);
  const char* ssid = "ssid";
  const char* password = "Wifi Password";

  Wifi.begin(ssid, password);
  Serial.println("Connecting to Wifi");

  while(WiFi.status() != WL_CONNECTED)
   {
    Serial.print(".");
    delay(500);
   }

  Serial.println("\nConnected to WiFi");
  Serial.println("IP address: ");
  Serial.println(Wifi.localIP());

}

void loop() 
{
  if((Wifi.status() == WL_CONNECTED))
  {
    Serial.println("Connected");

    long rnd = random(1, 10);
    HTTPClient client;

    client.begin("Request Adress");
    int httpCode = client.GET(); //status Code

    if(httpCode > 0)
   {
    String payload = client.getString();
    Serial.println("\nStatuscode: " + String(httpCode));
    Serial.println(payload);

    char json[500];
    payload.replace(" ", "");
    payload.replace("\n", "");
    payload.trim();
    payload.remove(0,1);
    payload.toCharArray(json, 500);

    StaticJsonDocument<200> doc;
    deserializeJson(doc, json);

    int id = doc["id"]; //Example to acces json 

   }
   else
   {
    Serial.println("HTTP Request Failed");
   }
  }
  else
  {
    Serial.println("WiFi Connection lost");
  }

  delay(10000);
}