#include "Arduino.h"

const int sensorPin = 5;    // Pin number the PIR sensor is on
const int ledpin = 2;       // Pin Number the LED is on
int sensorValue = LOW;


void setup() {
  Serial.begin(115200);
  
  pinMode(ledpin, OUTPUT);
  pinMode(sensorPin, INPUT);

  constexpr auto DEFAULT_WAKEUP_PIN = 5;  //set the wake up trigger to be pin 5 which is the PIR sensor
	constexpr auto DEFAULT_WAKEUP_LEVEL = ESP_GPIO_WAKEUP_GPIO_HIGH;  //set the wakeup to happen when pin 5 is HIGH (ie, the PIR sensor detects motion)

	const gpio_config_t config = {
		.pin_bit_mask = BIT(DEFAULT_WAKEUP_PIN),
		.mode = GPIO_MODE_INPUT,
	};
 ESP_ERROR_CHECK(gpio_config(&config));
 ESP_ERROR_CHECK(esp_deep_sleep_enable_gpio_wakeup(BIT(DEFAULT_WAKEUP_PIN), DEFAULT_WAKEUP_LEVEL));  //setting the ESP to wake up from deep sleep when motion is detected.


digitalWrite(ledpin, HIGH);   //turn on onboard LED
  delay(2500);                //the PIR sensor has a hardware trigger of 2 seconds, setting a delay of 2.5 seconds helps eliminate debounce.
  digitalWrite(ledpin, LOW);    //turn off onboard LED
  digitalWrite(sensorPin, LOW); //set the PIR senor to low
  esp_deep_sleep_start();  //go to sleep
}


void loop() {
  
}