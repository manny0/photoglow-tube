void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(7, OUTPUT); //STCP
  pinMode(4, OUTPUT); //SHCP
  pinMode(2, OUTPUT); //DS
  settube(0x00);
}

void loop() {
  while(Serial.available()){
    char inChar = (char)Serial.read();
    settube(inChar);
    Serial.write(inChar);
  }
  // put your main code here, to run repeatedly:
  
  
//  delay(2000);
}

char settube(char num){
  if(num > 8)
    return 1;
  digitalWrite(7, LOW);
  delay(2);
  for(char i = 0;i<8;i++){
    digitalWrite(4, LOW);
    delay(2);
    if(i == num){
      digitalWrite(2, HIGH);
    } else {
      digitalWrite(2, LOW);
    }
    delay(2);
    digitalWrite(4, HIGH);
    delay(2);
  }
  digitalWrite(4, LOW);  
  digitalWrite(2, LOW);
  delay(2);
  digitalWrite(7, HIGH);
  delay(2);
  digitalWrite(7, LOW);
}

