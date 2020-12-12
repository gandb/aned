 
const int pinSentido1MotorA = 6;
const int pinSentido2MotorA = 7;

const int pinSentido1MotorB = 5;
const int pinSentido2MotorB = 4;

const int PINO_BUTTON = 2; 

long lastclicked = 0;
long startSystem = 0;

byte motor = 0 ; //0==OFF, 1==ESQ+, 2==ESQ-, 3==DIR+, 4==DIR-

void setup() { 
  long now = millis();
  startSystem = now;
 
  Serial.begin(9600);
  
  pinMode(pinSentido1MotorA, OUTPUT);
  pinMode(pinSentido2MotorA, OUTPUT);
  pinMode(pinSentido1MotorB, OUTPUT);
  pinMode(pinSentido2MotorB, OUTPUT);

  
  pinMode(PINO_BUTTON, INPUT_PULLUP);
  
  //attachInterrupt(digitalPinToInterrupt( PINO_BUTTON), onClick, RISING);// chama a funçao zerocross quando mudar de estado high-low
  attachInterrupt(digitalPinToInterrupt( PINO_BUTTON), onClick, FALLING  );// chama a funçao zerocross quando mudar de estado high-low

 
}



void onClick()  {
  
  long now = millis();

 if((lastclicked + 1000)>now)
  {
    return;
  }

  lastclicked = now;

  motor = motor + 1;
  
  if(motor == 5 )
  {
     motor = 0;
  } 

  Serial.print("Clicado ");

  Serial.println(motor);
  
}

void loop() {

    long now = millis();
  
   if((startSystem +5000)>now)
    {
      motor = 0;
      return;
    }

    
    

      if(motor==0)
      {
         Serial.println("Desligando motores");
         digitalWrite(pinSentido1MotorA, LOW);
         digitalWrite(pinSentido2MotorA, LOW);    
         
         digitalWrite(pinSentido1MotorB, LOW);
         digitalWrite(pinSentido2MotorB, LOW);    
      }
      else if(motor==1)
      {
         Serial.println("Ligando motor ESQ FRENTE");
         digitalWrite(pinSentido1MotorA, HIGH);
         digitalWrite(pinSentido2MotorA, LOW);    
         
         digitalWrite(pinSentido1MotorB, LOW);
         digitalWrite(pinSentido2MotorB, LOW);    
            
      }
      else if(motor==2)
      {
        Serial.println("Ligando motor ESQ TRAS");
         digitalWrite(pinSentido1MotorA, LOW);
         digitalWrite(pinSentido2MotorA, HIGH);    
         
         digitalWrite(pinSentido1MotorB, LOW);
         digitalWrite(pinSentido2MotorB, LOW);    
            
      }      
      else if(motor==3)
      {
        Serial.println("Ligando motor DIR FRENTE");
         digitalWrite(pinSentido1MotorA, LOW);
         digitalWrite(pinSentido2MotorA, LOW);    
         
         digitalWrite(pinSentido1MotorB, HIGH);
         digitalWrite(pinSentido2MotorB, LOW);                
      }
      else if(motor==4)
      {
        Serial.println("Ligando motor DIR TRAS");
         digitalWrite(pinSentido1MotorA, LOW);
         digitalWrite(pinSentido2MotorA, LOW);    
         
         digitalWrite(pinSentido1MotorB, LOW);
         digitalWrite(pinSentido2MotorB, HIGH);    
            
      } 

      
  delay(500);
}
