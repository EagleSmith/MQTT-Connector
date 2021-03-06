#include <DHT.h>
#include <MqttConnector.h>
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#include <PubSubClient.h>

MqttConnector *mqtt;

#define DHTPIN 12
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
DHT dht(DHTPIN, DHTTYPE);


#define MQTT_PORT        1883
#define PUBLISH_EVERY    (3*1000) // every 15 seconds

/* comment ทิ้งถ้าไม่ส่ username/password */

#define MQTT_HOST         "gb.netpie.io"
#define MQTT_USERNAME     "VKUbwn8T5FsNKpp"
#define MQTT_PASSWORD     "dDfoyjzgNox3ExWvmXaRb4tw3ik="
#define MQTT_CLIENT_ID    "S1E6h0qKLTmjC1Vh"
#define MQTT_PREFIX       "/NatWeerawan2/gearname"

/* SENSOR INFO */
#define DEVICE_NAME       "DEEPSLEEP-001"
#define AUTHOR            "Nat Weerawan"
#define BOARD             "NODEMCU V1.0"
#define SENSOR            "DHT22"

/* WIFI INFO */
#ifndef WIFI_SSID
  #define WIFI_SSID        ""
  #define WIFI_PASSWORD    ""
#endif

#include "_publish.h"
#include "_receive.h"
#include "init_mqtt.h"


#define DHTPIN 12 // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)

void init_hardware()
{

  Serial.begin(115200);
  delay(10);
  Serial.println();
  Serial.println("BEGIN");

  init_dht();

}

void init_dht() {
  pinMode(DHTPIN, INPUT_PULLUP);
}

void init_wifi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while(WiFi.status() != WL_CONNECTED) {
    Serial.println("CONNECTING...");
    delay(300);
  }
}

void setup()
{
  init_hardware();
  init_wifi();
  init_mqtt();
}

void loop()
{
  mqtt->loop();
}
