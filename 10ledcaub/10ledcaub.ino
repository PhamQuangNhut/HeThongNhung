const int numberOfLeds = 10;  // Số lượng đèn LED
int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};  // Chân điều khiển của từng đèn LED

void setup() {
  for (int i = 0; i < numberOfLeds; i++) {
    pinMode(ledPins[i], OUTPUT);  // Thiết lập chân điều khiển của đèn LED là OUTPUT
  }
}

void loop() {
  // Sáng dần từ hai bên vào trong
  for (int i = 0; i < numberOfLeds / 2; i++) {
    digitalWrite(ledPins[i], HIGH);  // Bật đèn LED bên phải
    digitalWrite(ledPins[numberOfLeds - 1 - i], HIGH);  // Bật đèn LED bên trái
    delay(100);  // Chờ 100 milliseconds
  }

  // Tắt dần từ trong ra hai bên
  for (int i = numberOfLeds / 2 -1; i >= 0; i--) {
    digitalWrite(ledPins[i], LOW);  // Tắt đèn LED bên phải
    digitalWrite(ledPins[numberOfLeds - 1 - i], LOW);  // Tắt đèn LED bên trái
    delay(100);  // Chờ 100 milliseconds
  }
}
