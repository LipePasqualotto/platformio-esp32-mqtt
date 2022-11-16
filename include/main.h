#include <Arduino.h>
#include <AsyncMqttClient.h>
#include <Ticker.h>
#include <Wifi.h>

using namespace std;

#include <configuration.h>

void connectToWiFi();
void connectToMQTT();

AsyncMqttClient mqttClient;
Ticker mqttReconnectTimer;
Ticker wifiReconnectTimer;

// Event handlers
void onWiFiEvent(WiFiEvent_t event);
void onMQTTConnect(bool sessionPresent);
void onMQTTDisconnect(AsyncMqttClientDisconnectReason reason);
void onMQTTMessage(
    char *topic,
    char *payload,
    AsyncMqttClientMessageProperties properties,
    size_t len,
    size_t index,
    size_t total);