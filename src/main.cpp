// #include<Arduino.h>
// #include<WiFi.h>

// void setup(){
//   Serial.begin(115200);
//   WiFi.mode(WIFI_STA);
//   WiFi.disconnect();
//   Serial.println("setup done");
//   delay(2000);

// }
// void loop(){
//     Serial.println("start scan");
//   int n = WiFi.scanNetworks();
//   if(n == 0){
//     Serial.println("No Wifi Found");
//   }
//   else
//   {
//     Serial.println("Scan "+String(n)+" Wifi:");
//     for (int i = 0; i < n; i++)
//     {
//       Serial.println(String(i+1)+":"+WiFi.SSID(i)+"("+WiFi.RSSI(i)+" dbm)");
//     }
//   }
// }







// #include<Arduino.h>
// #include<WiFi.h>

// const char *ssid = "Chicky2";
// const char *password = "abc123123";

// void initWifi(){
//   WiFi.mode(WIFI_STA);
//   WiFi.begin(ssid, password);
//   Serial.print("Connecting to Wifi..");
//   while (WiFi.status() != WL_CONNECTED)
//   {
//     Serial.print(".");
//     delay(1000);
//   }
//   Serial.println("");
//   Serial.print("IP:");
//   Serial.println(WiFi.localIP());
// }
// void setup(){
//   Serial.begin(115200);
//   initWifi();
//   Serial.print("RSSI:");
//   Serial.println(WiFi.RSSI());
// }
// void loop(){

// }







// #include<Arduino.h>
// #include<WiFi.h>
// const char *ssid = "Chicky2";
// const char *password = "acb123123";
// IPAddress local_IP(192,168,1,50);
// IPAddress gateway(192,168,1,1);
// IPAddress subnet(255,255,255,0);
// IPAddress thefirstDNS(203,113,131,2);
// IPAddress thesecondDNS(203,113,188,6);
// void setup(){
//     Serial.begin((9600));
//     if (!WiFi.config(local_IP,gateway,subnet,thefirstDNS,thesecondDNS)){
//         Serial.println("Configuration Failed");
//     }
//     WiFi.mode(WIFI_STA);
//     WiFi.begin(ssid,password);
//     Serial.println("Connecting to");
//     while (WiFi.status() != WL_CONNECTED)
//     {
//         Serial.print(".");
//         delay(1000);
//     }
//     Serial.println("");
//     Serial.println("Wifi connected");
//     Serial.println("IP address:");
//     Serial.print(WiFi.localIP());
//     Serial.println("signal strength:");
//     Serial.print(WiFi.RSSI());
// }
// void loop(){

// }







// #include<Arduino.h>
// #include<WiFi.h>
// const char *ssid = "Chicky2";
// const char *password = "abc123123";
// unsigned long previousMillis = 0;
// unsigned long interval = 5000;
// void initWifi(){
//     WiFi.mode(WIFI_STA);
//     WiFi.begin(ssid,password);
//     Serial.print("Connecting to WiFi");
//     while (WiFi.status() != WL_CONNECTED)
//     {
//         Serial.print(".");
//         delay(1000);
//     }
//     Serial.println("");
//     Serial.print("IP address:");
//     Serial.println(WiFi.localIP());
// }
// void setup(){
//     Serial.begin(115200);
//     initWifi();
//     Serial.print("RSSI:");
//     Serial.println(WiFi.RSSI());
// }
// void loop(){
//     unsigned long currentMillis = millis();
//     if ((WiFi.status() != WL_CONNECTED) && (currentMillis - previousMillis >= interval)){
//         Serial.println(millis());
//         Serial.println("Reconnecting to WiFi ...");
//         WiFi.disconnect();
//         WiFi.reconnect();
//         previousMillis = currentMillis;
//     }
//     if (WiFi.status() == WL_CONNECTED){
//         Serial.print("RSSI:");
//         Serial.print(WiFi.RSSI());
//         Serial.println("dbm");
//     }
//     delay(5000);
// }







// #include<Arduino.h>
// #include<WiFi.h>

// String ssid;
// String password;

// void setup(){

//   //Setup wifi station mode
//   WiFi.mode(WIFI_STA);
//   WiFi.disconnect(true);
//   Serial.begin(115200);
//   Serial.println("Setup done");
//   delay(1000);

//   //List of Wifi networks
//   int a = WiFi.scanNetworks();
//   if (a == 0)
//   {
//     Serial.println("No Wifi found");
//   }else
//   {
//     Serial.println("List of wifi networks:");
//     for (int i = 0; i < a; i++)
//     {
//       Serial.println(String(i+1)+"."+WiFi.SSID(i)+"("+WiFi.RSSI(i)+" dBm)");
//       delay(500);
//     } 
//   }

//   // enter the name wifi
//   bool invalidSSId = true;
//   while (invalidSSId)
//   {
//     Serial.print("Emter the Wifi name: ");
//     while (!Serial.available())
//     {
//       // wait for user to enter wifi name
//     }
//     ssid = Serial.readString();
//     ssid.trim();
//     Serial.println(ssid);
//     for (int i = 0; i < a; i++)
//     {
//       if (ssid == WiFi.SSID(i))
//       {
//         invalidSSId = false;
//         break;
//       }
//     }
//     if (invalidSSId)
//     {
//       Serial.print(ssid);
//       Serial.println(" isn't in list of wifi network.Please try again.");
//     }
//   }
  
//   // enter password wifi
//   bool invalidpassword = true;
//   while (invalidpassword)
//   {
//     Serial.print("Enter password: ");
//     while (!Serial.available())
//     {
//       //wait for user to enter password
//     }
//     password = Serial.readString();
//     password.trim();
//     Serial.println(password);

//     //connect to wifi
//     WiFi.begin(ssid.c_str(),password.c_str());
//     Serial.print("Connecting to ");
//     Serial.print(ssid);

//     unsigned long c = millis();

//     //try to connect for 10s
//     while (WiFi.status() != WL_CONNECTED && millis() - c < 10000)
//     {
//       Serial.print(".");
//       delay(1000);
//     }
//     Serial.println("");
//     if (WiFi.status() == WL_CONNECTED)
//     {
//       invalidpassword = false;
//       Serial.print("Successfully connected to ");
//       Serial.println(ssid);
//       delay(500);
      
//       //Show IP address
//       Serial.print("IP address: ");
//       Serial.println(WiFi.localIP());
//     }
//     else
//     {
//       Serial.println("wifi conncetion failed.Please try again.");
//     }
//   }
// }

// void loop(){

// }






#include<Arduino.h>
#include<WiFi.h>

String ssid;
String password;

void scanwifi(){
  int a = WiFi.scanNetworks();
  if (a == 0)
  {
    Serial.println("No Wifi found");
  }
  else
  {
    Serial.println("List of wifi networks:");
    for (int i = 0; i < a; i++)
    {
      Serial.println(String(i+1)+"."+WiFi.SSID(i)+"("+WiFi.RSSI(i)+" dBm)");
      delay(500);
    }    
  }  
}

void conncettowifi()
{
  //enter the wifi name
  bool invalidSSID = true;
  while (invalidSSID)
  {
    Serial.print("Enter the wifi name: ");
    while (!Serial.available())
    {
      //wait for user to enter the wifi name
    }
    ssid = Serial.readString();
    ssid.trim();
    Serial.println(ssid);
    int a = WiFi.scanNetworks();
    for (int i = 0; i < a; i++)
    {
      if (ssid == WiFi.SSID(i))
      {
        invalidSSID = false;
        break;
      }
    }
    if (invalidSSID)
    {
      Serial.print(ssid);
      Serial.println(" isn't in list of wifi.Please try again.");
    }
  }

  //enter the password
  bool invalidpassword = true;
  while (invalidpassword)
  {
    Serial.print("Enter password: ");
    while (!Serial.available())
    {
      //wait for user to enter password
    }
    password = Serial.readString();
    password.trim();
    Serial.println(password);

    Serial.print("connecting to ");
    Serial.print(ssid);
    WiFi.begin(ssid.c_str(),password.c_str());
    unsigned long b = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - b <10000)
    {
      Serial.print(".");
      delay(1000);
    }
    Serial.println("");
    if (WiFi.status() == WL_CONNECTED)
    {
      invalidpassword = false;
      Serial.print("Successfully conncetion to ");
      Serial.println(ssid);
      Serial.print("IP address: ");
      Serial.println(WiFi.localIP());
    }
    else
    {
      Serial.println("Wifi connection failed.Please try again.");
    }
  }
}

void disconnectowifi()
{
  WiFi.disconnect(true);
  Serial.print("Disconnect to wifi");
}

void setup()
{
  WiFi.mode(WIFI_STA);
  WiFi.disconnect(true);
  Serial.begin(115200);
  Serial.println("Setup done");
  scanwifi();
  delay(1000);
  conncettowifi();
}

void loop()
{
  if (Serial.available())
  {
    String command = Serial.readString();
    Serial.print(command);
    command.trim();
    if (command == "disconnect" || command == "Disconnect")
    {
      disconnectowifi();
      unsigned long c = millis();
      while (millis() - c < 3000)
      {
        Serial.print(".");
        delay(1000);
      }
      Serial.println("");
      conncettowifi();
    }
  }
}