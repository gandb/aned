
const int PINO_LED = 12; 
const int PINO_BUTTON = 2; 
int potenciaLED = LOW ;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(PINO_LED, OUTPUT);
  pinMode(PINO_BUTTON, INPUT_PULLUP);
  
  //attachInterrupt(digitalPinToInterrupt( PINO_BUTTON), onClick, RISING);// chama a funçao zerocross quando mudar de estado high-low
  attachInterrupt(digitalPinToInterrupt( PINO_BUTTON), onClick, FALLING  );// chama a funçao zerocross quando mudar de estado high-low
 
}

void loop() {
  // put your main code here, to run repeatedly:
  //int reading = digitalRead(PINO_BUTTON);   
  digitalWrite(PINO_LED, potenciaLED);  
  delay(10);
}


void onClick()  {
  
  Serial.println("Clicado");
  potenciaLED = (potenciaLED==HIGH)?LOW:HIGH;
  delay(1000);
}
