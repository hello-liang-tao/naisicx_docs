 /***************************************************************************
 * @简介:  红外接收头接收红外信号，控制LED灯开和灭
 * @接线:  LED灯（D13）、红外接收（-接GND，中间-5V，S-接D11）
 * @材料:  红外接收头、红外遥控器、LED灯、Arduino开发板、杜邦线
 * @其他:  引入IRremote库
 * @作者:  奈斯编程
 ***************************************************************************/
#include <IRremote.h>       

#define RECV_PIN (11)                       //红外接收头IO
#define LED_PIN (13)                        //LED IO

IRrecv irrecv(RECV_PIN);                
decode_results results;
 
void setup() {
  Serial.begin(9600);                       //串口波特率
  irrecv.enableIRIn();                      //初始化红外遥控

  pinMode(2, OUTPUT);                 //LED 外设初始化      
  pinMode(3, OUTPUT);                 //LED 外设初始化      
  pinMode(4, OUTPUT);                 //LED 外设初始化  
  pinMode(5, OUTPUT);                 //LED 外设初始化
  
  pinMode(6, OUTPUT);                 //LED 外设初始化
  pinMode(7, OUTPUT);                 //LED 外设初始化
  pinMode(8, OUTPUT);                 //LED 外设初始化
  pinMode(9, OUTPUT);                 //LED 外设初始化
}
 
void loop() {
  if (irrecv.decode(&results)) {
    if(results.value==16718055)             //前
    {
      digitalWrite(2, LOW);  
      digitalWrite(3, HIGH);  
      digitalWrite(4, LOW);  
      digitalWrite(5, HIGH);  

      digitalWrite(6, LOW);  
      digitalWrite(7, HIGH);  
      digitalWrite(8, LOW);  
      digitalWrite(9, HIGH);  
    }
    else if(results.value==16730805)        //后
    {
      digitalWrite(2, HIGH);  
      digitalWrite(3, LOW);  
      digitalWrite(4, HIGH);  
      digitalWrite(5, LOW);  

      digitalWrite(6, HIGH);  
      digitalWrite(7, LOW);  
      digitalWrite(8, HIGH);  
      digitalWrite(9, LOW);  
    }
    else if(results.value==16716015)        //左
    {
      digitalWrite(2, HIGH);  
      digitalWrite(3, LOW);    //左前
      
      digitalWrite(4, HIGH);  
      digitalWrite(5, LOW);  //左后

      digitalWrite(6, LOW);  
      digitalWrite(7, HIGH);  //右后
      digitalWrite(8, LOW);  
      digitalWrite(9, HIGH);  //右前
    }
    else if(results.value==16734885)        //右
    {
      digitalWrite(2, LOW);  
      digitalWrite(3, HIGH);  
      digitalWrite(4, LOW);  
      digitalWrite(5, HIGH);  

      digitalWrite(6, HIGH);  
      digitalWrite(7, LOW);  
      digitalWrite(8, HIGH);  
      digitalWrite(9, LOW);  
    }
    else if(results.value==16726215) {
      digitalWrite(2, LOW);  
      digitalWrite(3, LOW);  
      digitalWrite(4, LOW);  
      digitalWrite(5, LOW);  

      digitalWrite(6, LOW);  
      digitalWrite(7, LOW);  
      digitalWrite(8, LOW);  
      digitalWrite(9, LOW);  
    }
    irrecv.resume();                        // 接收下一个值
  }
}
