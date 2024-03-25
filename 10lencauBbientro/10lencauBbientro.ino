const int numberOfLeds = 10;  // Số lượng đèn LED
int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};  // Chân điều khiển của từng đèn LED
const int potPin = A0;  // Chân kết nối với biến trở
void setup() {
  for (int i = 0; i < numberOfLeds; i++) {
    pinMode(ledPins[i], OUTPUT);  // Thiết lập chân điều khiển của đèn LED là OUTPUT
  }
}

void loop() {
  int potValue = analogRead(potPin);  // Đọc giá trị từ biến trở

  Serial.print("Potentiometer Value: ");
  Serial.println(potValue);  // In giá trị của biến trở lên Serial Monitor

  int delayTime = map(potValue, 0, 1023, 10, 1000);  // Chuyển giá trị từ biến trở thành khoảng giá trị delay (10-1000ms)
  // Sáng dần từ hai bên vào trong
  for (int i = 0; i < numberOfLeds / 2; i++) {
    digitalWrite(ledPins[i], HIGH);  // Bật đèn LED bên phải
    digitalWrite(ledPins[numberOfLeds - 1 - i], HIGH);  // Bật đèn LED bên trái
    delay(analogRead(potPin));  // Chờ analogRead(potPin) milliseconds
  }

  // Tắt dần từ trong ra hai bên
  for (int i = numberOfLeds / 2 -1; i >= 0; i--) {
    digitalWrite(ledPins[i], LOW);  // Tắt đèn LED bên phải
    digitalWrite(ledPins[numberOfLeds - 1 - i], LOW);  // Tắt đèn LED bên trái
    delay(analogRead(potPin));  // Chờ analogRead(potPin) milliseconds
  }
}
