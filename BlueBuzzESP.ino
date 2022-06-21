#define BLYNK_TEMPLATE_ID "TMPLUiQ1nCdh"
#define BLYNK_DEVICE_NAME "WaterAlert"
#define BLYNK_AUTH_TOKEN "MTI-fNzB18sGSI0H2rKT9jhz7EvsM8zA"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial

#define APP_DEBUG

#include "BlynkEdgent.h"

#define SensorPin A0

int notificationFlag = 0;

void setup()
{
  Serial.begin(115200);
  delay(100);
  pinMode(SensorPin, INPUT);
  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
  int WaterState = analogRead(SensorPin);
  Blynk.virtualWrite(V0, WaterState);
  Serial.println(WaterState);
  if(WaterState >= 700 && notificationFlag ==0){
    Blynk.logEvent("wateralert");
    notificationFlag = 1;
  }
}
