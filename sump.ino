int i = 0;
int flag = 0;
const int TopFloat = 2;
const int BottomFloat = 4;
const int relayPin = 8;
const int ledPin = 13;



void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(TopFloat, INPUT_PULLUP);
  pinMode(BottomFloat, INPUT_PULLUP);
  pinMode(relayPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
}

// the loop routine runs over and over again forever:
void loop() {
  delay(1000);

  
  int TopVal = digitalRead(TopFloat); //low means full (doesn't need water)
  int BottomVal = digitalRead(BottomFloat);

  if(TopVal== LOW && BottomVal == LOW && flag == 0){
       Serial.println("On");
       flag = turnItOn(TopVal); 
       Serial.println("OFF");

  }
  if(flag ==1){
    for(int i=0;i < 1000;i++){
      digitalWrite(ledPin,LOW);
      delay(100);
      digitalWrite(ledPin,HIGH);
      delay(100);
      
    }

    
  }

}

int turnItOn(int TopVal){
  digitalWrite(ledPin,HIGH);
  while(TopVal == LOW){
    TopVal = digitalRead(TopFloat);
    delay(1000);
    Serial.println("Still On");
    
    
    
  }
  digitalWrite(ledPin,LOW);
  return 1;

}


