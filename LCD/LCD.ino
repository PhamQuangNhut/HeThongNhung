#include <LiquidCrystal_I2C.h>
#include <DHT.h>
//SCL -> A5
//SDA -> A4 
//DHT -> 2
//Button -> 3
#define DHTPIN 2
#define DHTTYPE DHT11
#define BUTTON_PIN 3  // Chân nối nút nhấn với Arduino

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

bool isFahrenheit = false;           // Biến lưu đơn vị nhiệt độ, false là °C, true là °F
unsigned long lastDebounceTime = 0;  // Thời gian lần cuối chống dội (debounce)
unsigned long debounceDelay = 50;    // Độ trễ chống dội (miliseconds)

void setup() {
  lcd.init();
  lcd.backlight();
  dht.begin();
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // Cài đặt pin nút nhấn là INPUT_PULLUP
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);
  if (buttonState == 1) {          // Kiểm tra xem nút có được nhấn không
                                   // Kiểm tra xem sự kiện nhấn có phải là do nhiễu (noise) hay không
    isFahrenheit = !isFahrenheit;  // Đảo đơn vị nhiệt độ
    while (digitalRead(BUTTON_PIN)) delay(50);
    int time = millis();
    int dbClick = 0;
    while (!(dbClick = digitalRead(BUTTON_PIN))) {
      delay(50);
      if (millis() - time > 200) break;
    }
    if (dbClick) {
      lcd.noBacklight();  // Tắt đèn nền LCD
      isFahrenheit = !isFahrenheit;
    }
  }

  float t = dht.readTemperature(isFahrenheit);  // Đọc nhiệt độ theo đơn vị hiện tại
  if (isnan(t)) {
    lcd.print("Error");  // Nếu không đọc được nhiệt độ, hiển thị lỗi
    return;
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print((char)223);
  lcd.print(isFahrenheit ? "F" : "C");  // Hiển thị đơn vị tùy thuộc vào giá trị của isFahrenheit

  delay(50);  // Cập nhật mỗi giây
}
