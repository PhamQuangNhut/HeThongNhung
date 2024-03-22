// Định nghĩa chân LED
const int ledPinRed = 9;     // Chân PWM cho LED Đỏ
const int ledPinGreen = 10;  // Chân PWM cho LED Xanh lá
const int ledPinBlue = 11;   // Chân PWM cho LED Xanh dương

void setup() {
  // Khởi tạo cổng Serial
  Serial.begin(9600);
  // Đặt chế độ chân LED
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinBlue, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) { // Kiểm tra xem có dữ liệu từ cổng Serial không
    String data = Serial.readStringUntil('\n'); // Đọc dữ liệu đến khi gặp ký tự xuống dòng
    int rIndex = data.indexOf('R'); // Tìm vị trí của 'R'
    int gIndex = data.indexOf('G'); // Tìm vị trí của 'G'
    int bIndex = data.indexOf('B'); // Tìm vị trí của 'B'

    // Phân tích chuỗi và lấy giá trị RGB
    int redValue = data.substring(rIndex + 1, gIndex).toInt();
    int greenValue = data.substring(gIndex + 1, bIndex).toInt();
    int blueValue = data.substring(bIndex + 1).toInt();

    // Điều chỉnh giá trị nếu lớn hơn 255
    redValue = min(redValue, 255);
    greenValue = min(greenValue, 255);
    blueValue = min(blueValue, 255);

    // Cài đặt độ sáng cho mỗi LED
    analogWrite(ledPinRed, redValue);
    analogWrite(ledPinGreen, greenValue);
    analogWrite(ledPinBlue, blueValue);
  }
}