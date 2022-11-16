// #include "main.h"

// using namespace std;

// void connectToWiFi()
// {
//   if (WiFi.status() == WL_CONNECTED)
//     return;

//   Serial.println("Connecting to WiFi...");
//   Serial.println(WIFI_SSID);
//   Serial.println(WIFI_PASSWORD);
//   try
//   {
//     WiFi.setHostname(WIFI_HOSTNAME);
//     WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
//   }
//   catch (const std::exception &e)
//   {
//     Serial.println("Erro ao conectar WiFi");
//   }
// }

// void onWiFiEvent(WiFiEvent_t event)
// {
//   switch (event)
//   {
//   case SYSTEM_EVENT_STA_START:
//     Serial.println("WIFI: Connecting...");
//     break;
//   case SYSTEM_EVENT_STA_CONNECTED:
//     Serial.println("WIFI: Connected! Waiting for IP...");
//     break;
//   case SYSTEM_EVENT_STA_LOST_IP:
//     Serial.println("WIFI: Lost IP address...");
//     break;
//   case SYSTEM_EVENT_STA_GOT_IP:
//     Serial.println("WIFI: Got IP!");
//     Serial.print("WIFI: IP Address: ");
//     Serial.println(WiFi.localIP());
//     connectToMQTT();
//     break;
//   case SYSTEM_EVENT_STA_DISCONNECTED:
//     Serial.println("WIFI: Disconnected.");
//     mqttReconnectTimer.detach();
//     wifiReconnectTimer.once(2, connectToWiFi);
//     break;
//   default:
//     break;
//   }
// }

// void onMQTTConnect(bool sessionPresent)
// {
//   Serial.println("MQTT Connected!");

//   char payload[250];
//   sprintf(payload, "{\"%s\": %d}", "alarme", 1);

//   Serial.println("Publishing...");
//   Serial.println(payload);

//   mqttClient.publish(MQTT_TOPIC, 2, true, payload);
// }

// void onMQTTDisconnect(AsyncMqttClientDisconnectReason reason)
// {
//   Serial.println("MQTT Disconnected...");
//   if (WiFi.isConnected())
//   {
//     mqttReconnectTimer.once(10, connectToMQTT);
//   }
// }

// void onMQTTMessage(
//     char *topic, char *payload,
//     AsyncMqttClientMessageProperties properties,
//     size_t len, size_t index, size_t total)
// {
//   Serial.println("MQTT Message Received!");
//   Serial.print("Topic: ");
//   Serial.println(topic);
//   Serial.print("Payload: ");
//   Serial.println(payload);
// }

// void connectToMQTT()
// {
//   Serial.println("Connecting to MQTT...");
//   Serial.println("MQTT_HOST");
//   Serial.println(BROKER_DNS);

//   try
//   {
//     mqttClient.setClientId(WIFI_HOSTNAME);
//     mqttClient.setServer(BROKER_DNS, BROKER_PORT);
//     mqttClient.setCredentials(MQTT_TOKEN, "");
//     mqttClient.setWill(MQTT_TOPIC, 0, true, "offline");
//     mqttClient.connect();
//   }
//   catch (const std::exception &e)
//   {
//     Serial.println("Erro ao conectar MQTT");
//     Serial.println(e.what());
//   }
// }

// void setup()
// {
//   Serial.begin(MONITOR_BAUDRATE);
//   Serial.println();
//   Serial.println();

//   delay(2000);

//   Serial.println("MQTT\n\n");

//   WiFi.onEvent(onWiFiEvent);
//   mqttClient.onConnect(onMQTTConnect);
//   mqttClient.onDisconnect(onMQTTDisconnect);
//   mqttClient.onMessage(onMQTTMessage);

//   connectToWiFi();
// }

// void loop()
// {
//   // put your main code here, to run repeatedly:
// }