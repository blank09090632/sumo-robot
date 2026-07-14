# Sumo Robot

Robot sử dụng:

* **Arduino UNO R3** làm bộ điều khiển trung tâm.
* **Driver động cơ L298N** để điều khiển 2 động cơ DC.
* **Cảm biến siêu âm HC-SR04** để phát hiện vị trí đối thủ.
* **Hai cảm biến hồng ngoại TCRT5000** để nhận biết vạch biên sân.
* **Hai động cơ DC** để di chuyển.

Robot hoạt động theo chiến thuật:

1. Quét tìm đối thủ.
2. Khi phát hiện đối thủ trong phạm vi cho phép → tăng tốc lao tới.
3. Khi phát hiện mép sân → lùi lại và đổi hướng.
4. Tiếp tục tìm kiếm cho đến khi kết thúc trận đấu.

---

# Phần cứng sử dụng

| Linh kiện           | Số lượng |
| ------------------- | -------- |
| Arduino UNO R3      | 1        |
| Module L298N        | 1        |
| Động cơ DC giảm tốc | 2        |
| Bánh xe robot       | 2        |
| HC-SR04             | 1        |
| TCRT5000            | 2        |
| Pin cấp nguồn       | 1        |
| Khung xe robot sumo | 1        |

---

# Sơ đồ kết nối

## L298N → Arduino UNO R3

| L298N | Arduino |
| ----- | ------- |
| ENA   | D5      |
| IN1   | D8      |
| IN2   | D9      |
| IN3   | D10     |
| IN4   | D11     |
| ENB   | D6      |

---

## HC-SR04 → Arduino UNO R3

| HC-SR04 | Arduino |
| ------- | ------- |
| VCC     | 5V      |
| GND     | GND     |
| TRIG    | D12     |
| ECHO    | D13     |

---

## TCRT5000 → Arduino UNO R3

| Cảm biến      | Arduino |
| ------------- | ------- |
| Cảm biến trái | A0      |
| Cảm biến phải | A1      |
| VCC           | 5V      |
| GND           | GND     |

# 💻 Cài đặt chương trình

## Yêu cầu

* Arduino IDE
* Board Arduino UNO R3
* Cáp USB
* Driver USB Arduino

---
