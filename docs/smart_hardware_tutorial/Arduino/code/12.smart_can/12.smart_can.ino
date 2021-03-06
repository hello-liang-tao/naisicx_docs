 /***************************************************************************
 * @brief      超声波测距，VCC - 5V、TRIG - D2、ECHO - D3、GND - GND
 * @author     奈斯编程
 ***************************************************************************/
#include <Servo.h>

#define TRIG_PIN (2)                      //触发产生超声波
#define ECHO_PIN (3)                      //输出产生超声波到接收反射超声波持续时间
#define OPEN_ACTION (130)                 //触发产生超声波
#define CLOSE_ACTION (80)                 //输出产生超声波到接收反射超声波持续时间

float distance;                           //转换为厘米长度
Servo myservo;                            // 定义Servo对象来控制
int current_angle=0;                      // 定义Servo对象来控制


float ping() {
  digitalWrite(TRIG_PIN,HIGH);            //触发产生超声波
  delayMicroseconds(10);                  //持续10us,10us为了产生超声波信号，不参于计算        
  digitalWrite(TRIG_PIN,LOW);             //停止超声波
  return float(pulseIn(ECHO_PIN,HIGH)*17) / 1000; 
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);              //初始化对于引脚
  pinMode(ECHO_PIN, INPUT);               //初始化对于引脚
  myservo.attach(9);                      // 控制线连接数字9
}

void loop() {
  distance = ping();                      //调用函数测量距离
  if(distance < 10) {
    open_active();
  } else {
    close_active();
  }
  delay(200);                             //间隔1s打印一次
}

void close_active() {
  if(CLOSE_ACTION < temp) {
    for(int i=OPEN_ACTION;i>CLOSE_ACTION;i--) {
      myservo.write(i);                   //合盖动作
      delay(5);
    }
    temp = CLOSE_ACTION;
  }
}

void open_active() {
  if(OPEN_ACTION > temp) {
    for(int i= CLOSE_ACTION;i<OPEN_ACTION;i++) {
      myservo.write(i);                   //开盖动作
      delay(5);
    }
    temp = OPEN_ACTION;
  }
}
