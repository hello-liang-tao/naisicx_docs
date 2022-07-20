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
  pinMode(LED_PIN, OUTPUT);                 //LED 外设初始化                     
}
 
void loop() {
  if (irrecv.decode(&results)) {
    if(results.value==16753245)             //根据实际码值修改
    {
      digitalWrite(LED_PIN, HIGH);  
    }
    else if(results.value==16736925)        //根据实际码值修改
    {
      digitalWrite(LED_PIN, LOW); 
    }
    Serial.println(results.value);          //串口显示接收的码值
    irrecv.resume();                        // 接收下一个值
  }
}
