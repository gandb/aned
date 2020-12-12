#include <TM1637Display.h> //INCLUSÃO DE BIBLIOTECA

const int CLK  = 2 ;//PINO DIGITAL UTILIZADO PELO CLK
const int DIO = 3; //PINO DIGITAL UTILIZADO PELO DIO
const int TEST_DELAY = 30000 ;//A QUANTIDADE DE TEMPO (EM MILISSEGUNDOS) ENTRE OS TESTES

const uint8_t C = 0b00111001;
const uint8_t H = 0b01110110;
const uint8_t EMPTY = 0b00000000;
const uint8_t MINUS = 0b01000000;


bool humity = true;

TM1637Display display(CLK, DIO); //PPASSA OS PARÂMETROS PARA UMA FUNÇÃO DA BIBLIOTECA TM1637Display
 
 
int contador = -99; //VARIÁVEL DO TIPO INTEIRA

 
void setup(){  
 Serial.begin(9600);
  display.setBrightness(0x0f); //DEFINE A INTESIDADE LUMINOSA DOS SEGMENTOS DO DISPLAY
}

void print(bool humity, int value)
{
  Serial.println("print:100");
  uint8_t  clear[] = {EMPTY, EMPTY,EMPTY,  EMPTY};
  display.setSegments(clear);

  Serial.println("print:150");
      
  if(humity)
  {
    if(value<0)
    {
      value=value*-1;
    }
      Serial.println("print:200");
      uint8_t  data[] = {EMPTY, EMPTY,EMPTY,  H};
      display.setSegments(data);
      
  }
  else
  {
    Serial.println("print:300");
    if(value<0)
    {
      Serial.println("print:400");
       uint8_t  data[] = {MINUS, EMPTY,EMPTY,  C};
       display.setSegments(data);
       value = value * -1;
    }
    else
    {
      Serial.println("print:500");
      uint8_t  data[] = {EMPTY, EMPTY,EMPTY,  C};
       display.setSegments(data);
    }
  }
  Serial.println("print:600");

       
  display.showNumberDec(value,false,2,1); //IMPRIME NO DISPLAY A CONTAGEM ATUAL         

  
}
 
void loop(){
  
  // display.showNumberDec(contador,false); //IMPRIME NO DISPLAY A CONTAGEM ATUAL   


  humity = !humity;

  contador++;
  
  print(humity,contador);
  
   delay(TEST_DELAY);
      
}
