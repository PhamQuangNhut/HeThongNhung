const int numberOfLeds = 10;  // Số lượng đèn LED
// int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};  // Chân điều khiển của từng đèn LED
int ledPins[] = {2, 4, 6, 8, 10, 11, 9, 7, 5, 3};  // Chân điều khiển của từng đèn LED

void setup() {
  for (int i = 0; i < numberOfLeds; i++) {
    pinMode(ledPins[i], OUTPUT);  // Thiết lập chân điều khiển của đèn LED là OUTPUT
  }
}

void loop() {
 
 for (int i = 0; i < numberOfLeds; i++) {
    digitalWrite(ledPins[i], HIGH);  // Bật đèn LED thứ i
    delay(300);  // Chờ 100 milliseconds
    digitalWrite(ledPins[i], LOW);   // Tắt đèn LED thứ i
  }

  // Tắt từ trái sang phải
  // for (int i = numberOfLeds - 1; i >= 0; i--) {
  //   digitalWrite(ledPins[i], HIGH);  // Bật đèn LED thứ i
  //   digitalWrite(ledPins[i], LOW);   // Tắt đèn LED thứ i
  //   delay(100);
  // }
}
