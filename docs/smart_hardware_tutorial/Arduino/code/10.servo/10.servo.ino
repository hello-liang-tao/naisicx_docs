 /***************************************************************************
 * @brief      舵机控制，棕色- GND、红色-5V、橙色- PWM（D9）
 * @author     奈斯编程
 ***************************************************************************/

#include <Servo.h>                              // 引用舵机控制头文件

 Servo myservo;                                 // 定义Servo对象
 int pos = 0;                                   // 角度变量

 void setup() {
    myservo.attach(9);                          // 控制线连接数字D9
 }

 void loop() {
    for (pos = 0; pos <= 180; pos ++) {         // 0°到180°
        myservo.write(pos);                     // 舵机角度写入
        delay(100);                             // 等待舵机机械响应时间，同样也可以控制旋转1°的快慢
    }

    for (pos = 180; pos >= 0; pos --) {         // 从180°到0°
        myservo.write(pos);                     // 舵机角度写入
        delay(10);                              // 10ms延时，旋转1°速度大于100ms
    }
 }
