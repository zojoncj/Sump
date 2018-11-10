int i = 0;
int flag = 0;
int saftey = 1;
int delayTime = 5;
int pumpTime = 15;
const int sumpFloat = 2;
const int bucketFloat = 4;
const int relayPin = 8;
const int ledPin = 13;



void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(sumpFloat, INPUT_PULLUP);
  pinMode(bucketFloat, INPUT_PULLUP);
  pinMode(relayPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
}

// the loop routine runs over and over again forever:
void loop() {
  delay(1000);
  if(saftey == 0){
    digitalWrite(ledPin,HIGH);
  }

    
  int sumpVal = digitalRead(sumpFloat); //low means full (doesn't need water)
  int bucketVal = readBucket(); //high means full (ok to pump)
  
  if(sumpVal== LOW && bucketVal == HIGH && flag == 0){
    flag = 1;
      
    }
  
  if(flag == 1 && saftey ==1){
    i++;
    //Serial.println(i);
  }
  
  if(saftey == 1 && i > delayTime){
    saftey = pumpIt(pumpTime);
    flag = 0;
    i = 0;
  }
  
}

int pumpIt(int leng){
  Serial.println("PUMPING");
  int retVal=1;
  for(int j=0;j < leng;j++){ 
    digitalWrite(relayPin,HIGH);
    if(readBucket() ==LOW){
      retVal = 0;
      digitalWrite(relayPin,LOW);
      break;
    }
    Serial.println(j);  
    delay(1000);
   
  }
  digitalWrite(relayPin,LOW);
  return retVal;  
}

int readBucket() {
  return  digitalRead(bucketFloat);
}
 
