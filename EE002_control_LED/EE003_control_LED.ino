/* 可變電阻
線路:
LED: D6->LED->R->GND
可變電阻: 5V->可變電阻->GND
                  L>A0
原理: A0可讀取類比訊號
透過他讀取電阻造成的電壓變化
並進行類比to PWM映射 1023 to 255
之後演算轉換變成符合日常習慣(順時針開電)

 */

int pot_pin = A0; //A0針腳讀取可變電阻
int led_pin = 6; //led pin

void setup(){
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT); //給定腳位輸出格式
  
}

void loop(){
  //讀取可變電阻類比數據
  int value = analogRead(pot_pin); //1023格式 A0為類比針腳
  int volta = value / 4; // 類比 to PWM
  Serial.println("轉換前資料: ");
  Serial.println(volta); 
  volta = 255-volta; // 做一個資料反轉 符合順時針開逆時針觀的邏輯
  Serial.println(volta); 
  // 燈泡亮暗輸出
  analogWrite(led_pin, volta);
  }


