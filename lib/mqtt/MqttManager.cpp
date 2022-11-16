#include "MqttManager.h"

MqttManager::MqttManager()
{
  this->initializeClients();
}

MqttManager::MqttManager(string wifiSSID, string wifiPassword, string brokerAddress, int brokerPort, string mqttId, string MqttToken, MQTT_CALLBACK_SIGNATURE)
{
  this->initializeClients();

  this->wifiSSID = wifiSSID;
  this->wifiPassword = wifiPassword;
  this->brokerAddress = brokerAddress;
  this->brokerPort = brokerPort;
  this->mqttId = mqttId;
  this->mqttToken = MqttToken;

  this->mqttClient->setServer(this->brokerAddress.c_str(), this->brokerPort);
  this->mqttClient->setCallback(callback);

  this->checkConnection();
}

void MqttManager::initializeClients()
{
  this->wiFiClient = new WiFiClient();
  this->mqttClient = new PubSubClient(*this->wiFiClient);
}

boolean MqttManager::checkConnection()
{
  while (!this->mqttClient->connected())
  {
    Serial.println("Connecting to MQTT...");
    Serial.print("ID: ");
    Serial.println(this->mqttId.c_str());
    Serial.print("Token: ");
    Serial.println(this->mqttToken.c_str());

    if (this->mqttClient->connect(this->mqttId.c_str(), this->mqttToken.c_str(), ""))
    {
      Serial.println("Conectado ao broker MQTT!");
      this->subscribeToTopics();
      return true;
    }
    else
    {
      Serial.println("Falha ao conectar ao broker MQTT!");
      Serial.println("Tentando novamente em 2 segundos...");
      delay(2000);

      return false;
    }
  }

  this->mqttClient->loop();
  return true;
}

boolean MqttManager::publishToTopic(string topic, string payload)
{
  if (!this->mqttClient->connected())
  {
    this->checkConnection();
  }

  return this->mqttClient->publish(topic.c_str(), payload.c_str());
}

void MqttManager::subscribeToTopics()
{
  for (auto topic : this->topicsToSubscribe)
  {
    Serial.print("Subscrevendo ao tópico: ");
    Serial.println(topic.c_str());

    this->mqttClient->subscribe(topic.c_str());
  }
}

void MqttManager::addSubscriptionTopic(string topicToSubscribe)
{
  this->topicsToSubscribe.push_back(topicToSubscribe);
}
