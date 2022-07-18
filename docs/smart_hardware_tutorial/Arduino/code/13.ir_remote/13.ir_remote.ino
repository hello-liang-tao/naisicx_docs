// #define ADD 0x00
// int IR_S =  8;     //接arduino 8号引脚
// void setup() 
// { 
//   pinMode(IR_S, OUTPUT);
//   Serial.begin(9600); // 9600 波特率
// }
// void loop() 
// {
//   uint8_t dat,temp;
//   if ( Serial.available()) {
//     temp = Serial.read();//?
     
//     IR_Send38KHZ(280,1);//发送9ms的起始码
//     IR_Send38KHZ(140,0);//发送4.5ms的结果码
     
//     IR_Sendcode(ADD);//用户识别码
//     dat=~ADD;
//     IR_Sendcode(dat);//用户识别码反吗
     
//     IR_Sendcode(temp);//操作码
//     dat=~temp;
//     IR_Sendcode(dat);//操作码反码
     
//     IR_Send38KHZ(21,1);//发送结束码
//   }
//   delay(200);
// }
// void IR_Send38KHZ(int x,int y) //产生38KHZ红外脉冲
// { 
// for(int i=0;i<x;i++)//15=386US
// { 
//            if(y==1)
//            {
//      digitalWrite(IR_S,1);
//             delayMicroseconds(9);
//      digitalWrite(IR_S,0);
//             delayMicroseconds(9);
//            }
//            else
//            {
//      digitalWrite(IR_S,0);
//             delayMicroseconds(20);
//            }            
// }
// }
// void IR_Sendcode(uint8_t x) //
// {
//     for(int i=0;i<8;i++)
//      {
//        if((x&0x01)==0x01)
//         {
//            IR_Send38KHZ(23,1);
//            IR_Send38KHZ(64,0);             
//         }
//         else
//          {
//             IR_Send38KHZ(23,1);
//             IR_Send38KHZ(21,0);  
//          }
//        x=x>>1;
//      }  
// }


#include <IRremote.h>
 
int RECV_PIN = 11;
 
IRrecv irrecv(RECV_PIN);
 
decode_results results;
 
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); //初始化红外遥控
  pinMode(12,1);
}
 
void loop() {
  if (irrecv.decode(&results)) {
    //if(results.value==16753245)      //确认接收到的第一排按键1的编码，此码是预先读出来的按键编码。
    //{
    //  digitalWrite(12,1);                //点亮LED
    //  Serial.println("turn on LED"); //串口显示开灯
    //}
    //else if(results.value==16736925)   //确认接收到的第一排按键2的编码
    //{
    //  digitalWrite(12,0);            //熄灭LED
    //  Serial.println("turn off LED");    //串口显示关灯
    //}
    Serial.println(results.value); //串口显示开灯
    irrecv.resume(); // 接收下一个值
  }
}
