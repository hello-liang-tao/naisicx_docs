    #include "Arduino_SensorKit.h"       //Arduino传感器包用到头文件

    void setup()  
    {
      Oled.begin();                      //OLED初始化
      Oled.setFlipMode(true);            //OLED显示模式
    }  
      
    void loop() {
      int random_value = analogRead(A0);   //read value from A0

      Oled.setFont(u8x8_font_chroma48medium8_r); 
      Oled.setCursor(0, 33);    // Set the Coordinates 
      Oled.print("Analog Value:");   
      Oled.print(random_value); // Print the Values  
      Oled.refreshDisplay();    // Update the Display 
      delay(1000);
    }
