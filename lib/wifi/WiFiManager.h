#pragma once
#include <WiFi.h>

using namespace std;

class WiFiManager
{
private:
  string ssid;
  string password;
  string hostName;

public:
  WiFiManager(string ssid, string password, string hostName);
  void checkConnection();
};