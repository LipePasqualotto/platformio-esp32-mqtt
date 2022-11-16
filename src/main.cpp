#include "configuration.h"

#include <WiFi.h>
#include <PubSubClient.h>

#include <MqttManager.h>
#include <WiFiManager.h>

MqttManager *mqttManager;
WiFiManager *wiFiManager;

// Declarando funções
void mqttCallback(char *topic, byte *payload, unsigned int length);
void publishToMqttTopic();

void setup()
{
  Serial.begin(MONITOR_BAUDRATE);

  wiFiManager = new WiFiManager(WIFI_SSID, WIFI_PASSWORD, WIFI_HOSTNAME);

  mqttManager = new MqttManager(WIFI_SSID, WIFI_PASSWORD, BROKER_DNS, BROKER_PORT, MQTT_ID, MQTT_TOKEN, mqttCallback);

  mqttManager->addSubscriptionTopic(MQTT_TOPIC);

  if (mqttManager->checkConnection())
  {
    publishToMqttTopic();
  }
}

void loop()
{
}

void publishToMqttTopic()
{
  char payload[250];
  sprintf(payload, "{\"%s\": %d}", "alarme", 1);

  Serial.println("Publishing...");
  Serial.println(payload);

  mqttManager->publishToTopic(MQTT_TOPIC, payload);
}

void mqttCallback(char *topic, byte *payload, unsigned int length)
{
  Serial.print("Mensagem recebida: ");
  Serial.println(topic);

  char message;

  for (int i = 0; i < length; i++)
  {
    char c = (char)payload[i];
    message += c;
  }
  Serial.print("[MQTT] Mensagem recebida: ");
  Serial.print(message);
}