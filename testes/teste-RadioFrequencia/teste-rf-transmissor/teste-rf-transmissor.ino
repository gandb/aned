#include <VirtualWire.h>

 
const int PINO_BUTTON = 2; 
const int PINO_TRANSMISSOR = 5; 

long lastclicked = 0;
bool clicado = false;

struct PACOTE_EXEMPLO
{
   bool  ligado ;  
};


PACOTE_EXEMPLO pacoteTransferencia;


// the setup function runs once when you press reset or power the board
void setup() {
  
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(PINO_BUTTON, INPUT_PULLUP);

  Serial.print("Iniciando transmissor");

  //configuração do transmissor
  vw_set_tx_pin(PINO_TRANSMISSOR);
  vw_set_ptt_inverted(true);
  vw_setup(2000);

  
  
 //attachInterrupt(digitalPinToInterrupt( PINO_BUTTON), onClick, RISING);// chama a funçao zerocross quando mudar de estado high-low
  attachInterrupt(digitalPinToInterrupt( PINO_BUTTON), onClick, FALLING  );// chama a funçao zerocross quando mudar de estado high-low

}

// the loop function runs over and over again forever
void loop() { 

  pacoteTransferencia.ligado = clicado;

  Serial.print("Pressionado ");
  if(pacoteTransferencia.ligado)
  {
    Serial.println(" sim ");
  }
  else
  {
    Serial.println(" não ");
  }

  Serial.print("Iniciando transmissão:");

  //transmissor
  vw_send((uint8_t *)&pacoteTransferencia, sizeof(pacoteTransferencia));
  Serial.print("Aguardando transmitir:");
  vw_wait_tx(); 
  Serial.print("Aguardando próximo pacote");
  delay(10000);                       // wait for a second
}




void onClick()  {

  long now = millis();

  if((lastclicked+500)>now)
  {
    return;
  }

  lastclicked = now;
  
  clicado = !clicado;
  
  delay(100);                       // wait for a second
    
}
