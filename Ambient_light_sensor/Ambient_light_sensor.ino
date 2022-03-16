#include <WiFiNINA.h>
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>
const char* ssid = "PLUSNET-FMGC";
const char* password = "746987bc73";
#define ioServer "io.adafruit.com"
#define ioPort 1883
#define ioUsername "s1858422"
#define ioKey "aio_PbEO90QR7M7kL7IfYrIBPdBkX5ph"
WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, ioServer, ioPort, ioUsername, ioKey);
Adafruit_MQTT_Publish dataFeed  = Adafruit_MQTT_Publish(&mqtt, ioUsername "/feeds/pantilt-control");


//WiFiClient client;
//Adafruit_MQTT_Client mqtt(&client, ioServer, ioPort, ioUsername, ioKey);
//
//Adafruit_MQTT_Publish lightFeed = Adafruit_MQTT_Publish(&mqtt, ioUsername "/feeds/tilt-control");
//
//long timer = 5000;
//long pTime = 0;

void setup() {

  Serial.begin(9600);
  while (!Serial) {}
  connectToWiFi(ssid, password);

  //pinMode(13, OUTPUT);
}

void loop() {
  // reads the input on analog pin A0 (value between 0 and 1023)

  connectToMQTT();

// The file runs smoothly when all of the below is commented out, but as soon as I uncomment it, it throws up the error 
//'connectToWifi is not declared in the scope' and am not sure where I am going wrong
  
//
//  if (millis() > pTime = timer) {
//    pTime = millis();
//
//    uint32_t analogValue = analogRead(A0);
//    Serial.print("sending ambient light reading: ");
//    Serial.println(analogValue);

    //    if (! potFeed.publish(analogValue)) [
    //    Serial.println("Failed!");
    //    } else {
    //    Serial.println("OK!");
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
