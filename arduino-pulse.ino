void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2,OUTPUT);  // uv
  pinMode(3,OUTPUT); // b
  pinMode(4,OUTPUT); // g
  pinMode(5,OUTPUT); // r
  pinMode(6,OUTPUT); // bf
  pinMode(11,INPUT); // input
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
}
void ledon(int data){
      digitalWrite(data,HIGH);
            }
void ledoff(int data){
      digitalWrite(data,LOW);
}
void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()>0){
    delay(20);
    byte data_size = Serial.available();
//    Serial.println(data_size);
    char data[data_size];
    for (byte i = 0 ; i < data_size ; i++){
      data[i] = Serial.read();
//      Serial.print(data[i]);
//      byte data_size = Serial.available();
      // char data[data_size];
    }
    char switchtrigger = data[0];
//    Serial.println(data[0]);
//    Serial.println(switchtrigger);
    switch (switchtrigger) {   
      case 'm':
        // ELP aquirement
        while (true) {
          for (int i=1;i<data_size;i++){
            if (data[i]== '1'){
                int ch=i+1;
              while (digitalRead(11)==HIGH){
                ledon(ch);
                }
              while (digitalRead(11)==LOW){
                ledoff(ch);
                if (Serial.available()>0){
                  if (Serial.read()== '0'){goto bailout;}
                }
                }  
            }          
          }
        }
        bailout:
        break;
      

    }
  //Serial.println(char('break'));
  }
}
