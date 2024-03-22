// Định nghĩa chân LED
const int ledPinRed = 9;     // Chân PWM cho LED Đỏ
const int ledPinGreen = 10;  // Chân PWM cho LED Xanh lá
const int ledPinBlue = 11;   // Chân PWM cho LED Xanh dương

// Khởi tạo giá trị ban đầu cho mỗi màu
int redValue = 0;
int greenValue = 0;
int blueValue = 0;

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

    // Xử lý thông tin của mỗi đèn
    processLedData(data, 'R', redValue);
    processLedData(data, 'G', greenValue);
    processLedData(data, 'B', blueValue);

    // Cài đặt độ sáng cho mỗi LED
    analogWrite(ledPinRed, redValue);
    analogWrite(ledPinGreen, greenValue);
    analogWrite(ledPinBlue, blueValue);
  }
}

void processLedData(String data, char color, int &value) {
  int startIndex = data.indexOf(color);
  if (startIndex != -1) { // Nếu tìm thấy ký tự chỉ màu
    String valueStr = ""; // Chuỗi để lưu trữ giá trị
    startIndex++; // Bỏ qua ký tự chỉ màu
    while (startIndex < data.length() && isDigit(data[startIndex])) {
      valueStr += data[startIndex++];
    }
    if (valueStr.length() > 0) {
      int newValue = valueStr.toInt(); // Chuyển đổi chuỗi thành số
      value = min(newValue, 255); // Điều chỉnh giá trị nếu lớn hơn 255
    }
  }
}