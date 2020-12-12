const int pinoSensor = 5; //PINO DIGITAL UTILIZADO PELO SENSOR
 
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(pinoSensor, INPUT_PULLUP); //DEFINE O PINO COMO ENTRADA / "_PULLUP" É PARA ATIVAR O RESISTOR INTERNO
  //DO ARDUINO PARA GARANTIR QUE NÃO EXISTA FLUTUAÇÃO ENTRE 0 (LOW) E 1 (HIGH)
}

void loop() {
  // put your main code here, to run repeatedly:
 if(digitalRead(pinoSensor) == LOW){ //SE A LEITURA DO PINO FOR IGUAL A LOW, FAZ
      Serial.println("Perto");
  }else{ //SENÃO, FAZ
      Serial.println("longe");
  }
}
