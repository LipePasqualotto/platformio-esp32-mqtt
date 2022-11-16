#pragma once
#include <WiFi.h>
#include <PubSubClient.h>
#include <vector>

using namespace std;

class MqttManager
{
private:
  int brokerPort;
  string wifiSSID;
  string wifiPassword;
  string brokerAddress;
  vector<string> topicsToSubscribe;
  WiFiClient *wiFiClient;
  PubSubClient *mqttClient;

  string mqttId;
  string mqttToken;

  void initializeClients();

public:
  MqttManager();
  MqttManager(string wifiSSID, string wifiPassword, string brokerAddress, int brokerPort, string mqttId, string MqttToken, MQTT_CALLBACK_SIGNATURE);

  boolean checkConnection();

  void subscribeToTopics();
  boolean publishToTopic(string topic, string payload);
  void addSubscriptionTopic(string topicToSubscribe);
};