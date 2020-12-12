 
const int PINO_BUTTON = 2; 
const int PINO_ENGINE_LEFT = 8; 
const int PINO_ENGINE_RIGHT = 7;  
int potenciaLED = HIGH ;
long lastclicked = 0;
bool clicado = false;



// the setup function runs once when you press reset or power the board
void setup() {
  
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);  
  pinMode(PINO_BUTTON, INPUT_PULLUP);
  pinMode(PINO_ENGINE_LEFT, OUTPUT);  
  pinMode(PINO_ENGINE_RIGHT, OUTPUT);  

 //attachInterrupt(digitalPinToInterrupt( PINO_BUTTON), onClick, RISING);// chama a funçao zerocross quando mudar de estado high-low
  attachInterrupt(digitalPinToInterrupt( PINO_BUTTON), onClick, FALLING  );// chama a funçao zerocross quando mudar de estado high-low

  digitalWrite(LED_BUILTIN, LOW);   // turn the LED on (HIGH is the voltage level)
 
}

// the loop function runs over and over again forever
void loop() { 
 
  if(clicado)
  {
    Serial.println("clicado");
    teste();
  }
  else
  {
    Serial.println("desclicado");
   }
    
 
   delay(1000);                       // wait for a second
}

void goFoward()
{
   digitalWrite(PINO_ENGINE_LEFT, HIGH);   
   digitalWrite(PINO_ENGINE_RIGHT, HIGH);   
 
}

void stopEngine()
{
   digitalWrite(PINO_ENGINE_LEFT, LOW);
   digitalWrite(PINO_ENGINE_RIGHT,LOW);   
 
}

void teste()
{
  goFoward();
//  delay(500);
 // stopEngine();
 // delay(500);
}

void onClick()  {

  long now = millis();

  if((lastclicked+500)>now)
  {
    return;
  }

  lastclicked = now;
  

  if(potenciaLED == LOW)
  {
   potenciaLED = HIGH;   
   clicado = true;   
  }
  else
  {
    clicado = false;
    potenciaLED = LOW;
  }

  digitalWrite(LED_BUILTIN, potenciaLED);   // turn the LED on (HIGH is the voltage level)
  
  delay(100);                       // wait for a second
  
    
}
