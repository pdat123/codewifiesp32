#include<Arduino.h>
#include<WiFi.h>

String ssid;
String password;

#define Ledwifi 2

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
      Serial.print("Default Gateway: ");
      Serial.println(WiFi.gatewayIP());
      Serial.print("SubnetMask: ");
      Serial.println(WiFi.subnetMask());
      Serial.print("DNS server: ");
      Serial.println(WiFi.dnsIP());

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
  pinMode(Ledwifi , OUTPUT);

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
  
  if (WiFi.status() == WL_CONNECTED)
  {
    digitalWrite(Ledwifi , HIGH);
  }

  if (Serial.available())
  {
    String command = Serial.readString();
    // Serial.print(command);
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

      digitalWrite(Ledwifi , LOW);

      Serial.println("");
      scanwifi();
      delay(1000);
      conncettowifi();
    }
  }
}