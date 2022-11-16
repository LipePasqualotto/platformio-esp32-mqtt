#include "WiFiManager.h"

WiFiManager::WiFiManager(string ssid, string password, string hostName)
{
  Serial.println("===== Conexão WiFi =====");
  Serial.print("Conectando ao WiFi: ");
  Serial.println(ssid.c_str());

  this->ssid = ssid;
  this->password = password;
  this->hostName = hostName;
  this->checkConnection();
}

void WiFiManager::checkConnection()
{
  if (WiFi.status() == WL_CONNECTED)
    return;

  WiFi.setHostname(this->hostName.c_str());
  WiFi.begin(this->ssid.c_str(), this->password.c_str());

  Serial.println();
  Serial.print("Conectando ao WiFi: ");
  Serial.println(this->ssid.c_str());
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}