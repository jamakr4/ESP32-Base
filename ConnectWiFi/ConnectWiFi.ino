#include <Wifi.h>;

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
  }
  else
  {
    Serial.println("WiFi Connection lost");
  }

  delay(10000);
}