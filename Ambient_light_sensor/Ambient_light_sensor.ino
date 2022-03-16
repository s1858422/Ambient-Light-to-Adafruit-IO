#include <WiFiNINA.h>
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>
const char* ssid = "MIWIFI_Qnn7";
const char* password = "4HMUePat";
#define ioServer "io.adafruit.com"
#define ioPort 1883
#define ioUsername "s1858422"
#define ioKey "aio_Ysjr65IHQMnFJ2Oq62ibYYuV2YyB"
WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, ioServer, ioPort, ioUsername, ioKey);
Adafruit_MQTT_Publish dataFeed  = Adafruit_MQTT_Publish(&mqtt, ioUsername "/feeds/tilt-control");

void setup() {

  Serial.begin(9600);
  while (!Serial) {}
  connectToWiFi(ssid, password);

  pinMode(13, OUTPUT);
}

void loop() {
  // reads the input on analog pin A0 (value between 0 and 1023)

  connectToMQTT();
  //
  if (millis() > pTime = timer) {
    pTime = millis();

    uint32_t analogValue = analogRead(A0);
    Serial.print("sending ambient light reading: ");
    Serial.println(analogValue);

    if (! dataFeed.publish(analogValue)) {
      Serial.println("Failed!");
    } else {
      Serial.println("OK!");
    }
    //
    //  int analogValue = analogRead(A0);
    //
    //  Serial.print("Analog reading: ");
    //  Serial.print(analogValue);   // the raw analog reading
    //
    //  // We'll have a few threshholds, qualitatively determined
    //  if (analogValue < 1) {
    //    Serial.println(" - Dark");
    //    digitalWrite(13, HIGH);
    //  } else if (analogValue < 10) {
    //    Serial.println(" - Dim");
    //    digitalWrite(13, LOW);
    //  }
    //
    //  delay(500);
