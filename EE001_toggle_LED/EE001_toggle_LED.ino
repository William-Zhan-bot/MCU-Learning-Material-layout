/*
LED: 12->LED->R->GND
BTN: 2->btn->GND
以晶片讀取按鈕訊號，非按鈕為直接通路
*/

int led_pin = 12;
int bt_pin = 2;

int led_state = LOW;
int last_bt_state = HIGH;
  
void setup(){
  pinMode(led_pin, OUTPUT);
  pinMode(bt_pin, INPUT_PULLUP);
}

void loop(){
  // 讀取當前bt狀態
  int current_state = digitalRead(bt_pin);
  // 當前與上一個狀態不同，改變LED輸出模式
  if (last_bt_state == HIGH && current_state == LOW){
    led_state = !led_state;    
  }

  // 輸出LED
  digitalWrite(led_pin, led_state);

  // 當前按鈕狀態記錄到之前的狀態
  last_bt_state = current_state;
}