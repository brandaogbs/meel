/**
  ******************************************************************************
  * @file    lab1.ino
  * @brief   Experimento de acionamento de rele, transistor como 
  *          chave e display 7 segmentos.
  * @authors 
  ******************************************************************************
  */

/******************************************************************************
 *                              INCLUDES
 ******************************************************************************/
 #include <Arduino.h>

/******************************************************************************
 *                              DEFINES
 ******************************************************************************/

#define PIN_LIGHT  2
#define PIN_BUTTON 3
#define PIN_LED   13

#define PIN_A 5
#define PIN_B 6
#define PIN_C 7
#define PIN_D 8
#define PIN_E 9
#define PIN_F 10
#define PIN_G 11

/******************************************************************************
 *                              PRIVATE VARIABLES
 ******************************************************************************/
const int delay_ms = 1000;

/******************************************************************************
 *                         PRIVATE FUNCTIONS PROTOTYPE
 ******************************************************************************/
// Debug
void debugLD(int);


// Botao
int isButtonPressed();

// Rele
void setLightOn();
void setLightOff();


// Display
void setDisplayOff();
void setDisplayCount();
void setDisplayDigit(int digit);


/******************************************************************************
 *                              PRIVATE USER CODE
 ******************************************************************************/

/**
  * @brief  Inicializacao dos perifericos e das entradas e saidas utilizadas.
  * @param  None
  * @retval None
  */
void setup() 
{  
  Serial.begin(9600);

  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_LIGHT, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);

  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_C, OUTPUT);
  pinMode(PIN_D, OUTPUT);
  pinMode(PIN_E, OUTPUT);
  pinMode(PIN_F, OUTPUT);
  pinMode(PIN_G, OUTPUT);

}

/**
  * @brief Loop embarcado.
  * @param  None
  * @retval None
  */
void loop() 
{
  if(isButtonPressed())
  {
    setLightOn();
    setDisplayCount();
  }
  else
  {
    setLightOff();
  }

}


/******************************************************************************
 *                                   DEBUG
 ******************************************************************************/

/**
  * @brief  Faz o LED piscar de acordo com delay_ms
  * @param  delay_ms: inteiro em milisegundos
  * @retval None
  */
void debugLD(int delay_ms)
{
  digitalWrite(PIN_LED, HIGH);
  delay(delay_ms);
  digitalWrite(PIN_LED, LOW);
  delay(delay_ms);
}


/******************************************************************************
 *                                   BOTAO
 ******************************************************************************/
/**
  * @brief  Verifica se o botao esta pressionado
  * @param  None
  * @retval int: estado do botao: 1-pressionado e 0-caso contrario
  */
int isButtonPressed()
{
    bool pressed = false;
    if(digitalRead(PIN_BUTTON) == HIGH)
    {
      Serial.println("Pressionado!");
      pressed = true;
    }      
    return pressed;
}


/******************************************************************************
 *                                   RELE
 ******************************************************************************/

/**
  * @brief  Aciona a lampada atraves do acionamento digital do rele
  * @param  None
  * @retval None 
  */
void setLightOn()
{
  digitalWrite(PIN_LIGHT, HIGH);
}

/**
  * @brief  Desliga a lampada atraves do acionamento digital do rele
  * @param  None
  * @retval None 
  */
void setLightOff()
{
  digitalWrite(PIN_LIGHT, LOW);
}


/******************************************************************************
 *                                   DISPLAY
 ******************************************************************************/

/**
  * @brief  Desliga individualmente todos os LEDs do display 7seg
  * @param  None
  * @retval None
  */
void setDisplayOff()
{
  digitalWrite(PIN_A, LOW);
  digitalWrite(PIN_B, LOW);
  digitalWrite(PIN_C, LOW);
  digitalWrite(PIN_D, LOW);
  digitalWrite(PIN_E, LOW);
  digitalWrite(PIN_F, LOW);
  digitalWrite(PIN_G, LOW);
}


/**
  * @brief  Realiza o acionamento do display 7seg conforme a entrada.
  * @param  digit: um inteiro de 0-9.
  * @retval None
  */
void setDisplayDigit(int digit)
{
    if(digit != 1 && digit != 4)
    {
      digitalWrite(PIN_A,HIGH);
    }

    if(digit != 5 && digit != 6)
    {
      digitalWrite(PIN_B,HIGH);
    }

    if(digit != 2)
    {
      digitalWrite(PIN_C,HIGH);
    }

    if(digit != 1 && digit != 4 && digit != 7)
    {
      digitalWrite(PIN_D,HIGH);
    }

    if(digit == 2 || digit == 6 || digit == 8 || digit == 0)
    {
      digitalWrite(PIN_E,HIGH);
    }

    if(digit != 1 && digit != 2 && digit != 3 && digit != 7)
    {
      digitalWrite(PIN_F,HIGH);
    }

    if (digit != 0 && digit != 1 && digit != 7)
    {
      digitalWrite(PIN_G,HIGH);
    }
}

/**
  * @brief  Realiza o acionamento do display de forma a exibir uma
  *         contagem crescente de 0-9
  * @param  None
  * @retval None
  */
void setDisplayCount()
{
    int i;
    for(i=0; i<=9; i++)
    {
        setDisplayDigit(i);
        delay(delay_ms);
        setDisplayOff();
    }
}
