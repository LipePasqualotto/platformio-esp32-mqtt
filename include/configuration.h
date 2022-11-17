#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#define MONITOR_BAUDRATE 115200

// WiFi Connection information
#define WIFI_SSID "trabprogdistribuida"
#define WIFI_PASSWORD "unoesc123"
#define WIFI_HOSTNAME "ESP32-MQTT"

// MQTT Connection information
#define BROKER_DNS "192.168.88.248"
#define BROKER_PORT 1883
#define MQTT_TOPIC_CONTROLE_SENSOR "ControleSensor"
#define MQTT_TOPIC_COMANDOS_SENSOR "ComandosSensor"

#endif