 /***************************************************************************
 * @brief      超声波测距，VCC - 5V、TRIG - D2、ECHO - D3、GND - GND
 * @author     奈斯编程
 ***************************************************************************/

#define TRIG_PIN 2                  //触发产生超声波
#define ECHO_PIN 3                  //输出产生超声波到接收反射超声波持续时间
float distance;                     //转换为厘米长度

/*
 * TRIG引脚输出高电平产生超声波，持续10us即可
 * ECHO引脚输入高电平时间t即为产生超声波到接收反射超声波持续时间
 * 由光速s为340m/s,换算为34cm/1000us
 * distance = (t*s)/2=(t*17)/1000;
 */
float ping() {
  digitalWrite(TRIG_PIN,  HIGH);    //触发产生超声波
  delayMicroseconds(10);            //持续10us,10us为了产生超声波信号，不参于计算        
  digitalWrite(TRIG_PIN, LOW);      //停止超声波
  return float( pulseIn(ECHO_PIN, HIGH) * 17 ) / 1000; 
}

void setup()  {
  pinMode(TRIG_PIN, OUTPUT);        //初始化对于引脚
  pinMode(ECHO_PIN, INPUT);         //初始化对于引脚
  Serial.begin(9600);               //设置串口打印波特率为9600
}

void loop() {
  distance = ping();               //调用函数测量距离
  Serial.print("distance=");       //打印数据
  Serial.print(distance);
  Serial.println("cm");
  delay(1000);                     //间隔1s打印一次
}
