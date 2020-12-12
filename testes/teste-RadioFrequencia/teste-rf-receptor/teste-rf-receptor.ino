#include <VirtualWire.h>

 
const int PINO_LED = 7; 
const int PINO_RECEPTOR = 6;

int potenciaLED = HIGH ;

struct PACOTE_EXEMPLO
{
   bool  ligado ;  
};


PACOTE_EXEMPLO pacoteRecebimento;


uint8_t buf[sizeof(pacoteRecebimento)];
uint8_t buflen = sizeof(pacoteRecebimento);



// the setup function runs once when you press reset or power the board
void setup() {
  
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.  
  pinMode(PINO_LED, OUTPUT);

  //configuração do receptor  
  vw_set_rx_pin(PINO_RECEPTOR);
  vw_setup(2000);   
  vw_rx_start();
  
  Serial.println("Iniciando receptor");
  
  digitalWrite(PINO_LED, LOW);
}

// the loop function runs over and over again forever
void loop() { 


  Serial.println("Verificando se tem pacote");
  
  if ( vw_have_message() ) {
    Serial.println("Tem pacote, pegando pacote para memória");
    vw_get_message(buf, &buflen);
    Serial.println("Copiando para estrutura pacote ");
    memcpy(&pacoteRecebimento,&buf,buflen);


      if(pacoteRecebimento.ligado)
      {
        Serial.println("Recebido ligado");
        digitalWrite( PINO_LED , HIGH);
      }
      else
      {
        Serial.println("Recebido desligado");
        digitalWrite( PINO_LED , LOW);
      }
  }  


  delay(1000);                       // wait for a second
}



 
