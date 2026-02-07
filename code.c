#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define PH_PIN A0
#define TDS_PIN A1
#define V_REF 5.0
#define ADC_RES 1024.0

float phValue = 0;
float tdsValue = 0;

void setup() {
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    for(;;);
  }

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(25, 20);
  display.println("SYSTEM READY");
  display.display();
  delay(2000);
}

void loop() {
  float phSum = 0;
  for(int i = 0; i < 10; i++) {
    phSum += analogRead(PH_PIN);
    delay(10);
  }
  float phVoltage = (phSum / 10.0) * V_REF / ADC_RES;
  phValue = 3.5 * phVoltage; 

  float tdsSum = 0;
  for(int i = 0; i < 10; i++) {
    tdsSum += analogRead(TDS_PIN);
    delay(10);
  }
  float tdsVoltage = (tdsSum / 10.0) * V_REF / ADC_RES;
  tdsValue = (133.42 * pow(tdsVoltage, 3) - 255.86 * pow(tdsVoltage, 2) + 857.39 * tdsVoltage) * 0.5;

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(15, 0);
  display.println("WATER QUALITY");
  display.drawFastHLine(0, 10, 128, WHITE);

  display.setTextSize(2);
  display.setCursor(0, 20);
  display.print("pH : ");
  display.print(phValue, 1);

  display.setCursor(0, 45);
  display.print("TDS: ");
  display.print((int)tdsValue);
  display.setTextSize(1);
  display.print(" ppm");

  display.display();

  Serial.print("pH:"); Serial.print(phValue);
  Serial.print("|TDS:"); Serial.println(tdsValue);

  delay(1000);
}