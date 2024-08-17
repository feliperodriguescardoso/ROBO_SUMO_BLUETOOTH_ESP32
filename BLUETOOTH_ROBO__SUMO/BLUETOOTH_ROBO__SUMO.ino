/*
   OLÁ,ESTE CÓDIGO "BASE" DE CONTROLE BLUETOOTH FOI RETIRADO DESTE LINK: "https://www.youtube.com/watch?v=S1AcaPEq4r0&t=5s", DO YOUTUBE, 
   NO CANAL "Brincando com Ideias".
   A IMPLEMENTAÇÃO DO LED SERVE APENAS COMO TESTE FUNCIONAL DO BLUETOOTH DO ESP32, E TAMBÉM, UMA EXEMPLIFICAÇÃO DE COMO PROSEGUIR COM O
   ACIONAMENTO DE COMPONENTES/MODULOS.

   ONDE HOUVER " //! " E " /*°/ ", JAMAIS ALTERAR! :)
   NAO ESQUECER DE COLOCAR 115200 Baud, SE NÃO, A COMUNICAÇÃO BLUETOOTH NÃO IRÁ FUNCIONAR!

   TENHA UM BOM DESENVOLVIMENTO!

   == Felipe Rodrigues Cardoso ==  06/07/2024 ;)
*/

#include <BluetoothSerial.h> //!

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED) /**/
#error Bluetooth is not enabled! Please run 'make menuconfig to and anable it //!
#endif //!

 BluetoothSerial bluth; //!
 char letra; //!
 
 int in1 = 27;
 int in2 = 14;
 int in3 = 12;
 int in4 = 13;

 int ledtras = 26;
 int buzzer = 25;
 int buzzer2 = 33;


void setup() { //!
 Serial.begin(115200); //!
 bluth.begin("RedeESP32"); //! NOME DO BLUETOOTH DO ESP32, PODE NOMEAR COMO DESEJAR!
 Serial.println("The device started, now you can pair it with bluetooth!"); //!

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(ledtras, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(buzzer2, OUTPUT);
}

void loop() {                      //!         
  if (Serial.available()){         //! 
    bluth.write(Serial.read());    //! 
   }                               //!
    if (bluth.available()){        //! 
     letra = bluth.read();         //!
     Serial.write(letra);          //!


      if (letra == 'F'){ // PARA FRENTE
       digitalWrite(in1, HIGH);
       digitalWrite(in2, LOW);
       digitalWrite(in3, HIGH);
       digitalWrite(in4, LOW);

       digitalWrite(ledtras, LOW); // LED DE TRÁS DESLIGADO
      }
      if (letra == 'B'){ // PARA TRÁS
       digitalWrite(in1, LOW);
       digitalWrite(in2, HIGH);
       digitalWrite(in3, LOW);
       digitalWrite(in4, HIGH);

       digitalWrite(ledtras, HIGH); // LED DE TRÁS ACIONADO

       digitalWrite(buzzer, HIGH); // BUZZER É ACIONADO
      
      }

      if (letra == 'S'){ // S É ACIONADO QUANDO NENHUM BOTÃO ESTIVER ACIONADO
       digitalWrite(in1, LOW);
       digitalWrite(in2, LOW);
       digitalWrite(in3, LOW);
       digitalWrite(in4, LOW);

       digitalWrite(ledtras, LOW);
       digitalWrite(buzzer, LOW);
      } 

      if(letra == 'R'){ // PARA DIREITA
       digitalWrite(in1, HIGH);
       digitalWrite(in2, LOW);
       digitalWrite(in3, LOW);
       digitalWrite(in4, HIGH);
      }
       
      if(letra == 'L'){ // PARA ESQUERDA
       digitalWrite(in1, LOW);
       digitalWrite(in2, HIGH);
       digitalWrite(in3, HIGH);
       digitalWrite(in4, LOW);
      } 

      if(letra == 'I'){ // PARA FRENTE À DIREITA
       digitalWrite(in1, HIGH);
       digitalWrite(in2, LOW);
       digitalWrite(in3, HIGH);
       digitalWrite(in4, HIGH);
      } 

      if(letra == 'G'){ // PARA FRENTE À ESQUERDA
       digitalWrite(in1, HIGH);
       digitalWrite(in2, HIGH);
       digitalWrite(in3, HIGH);
       digitalWrite(in4, LOW);
      }

      if(letra == 'J'){ // PARA TRÁS À DIREITA
       digitalWrite(in1, LOW);
       digitalWrite(in2, HIGH);
       digitalWrite(in3, HIGH);
       digitalWrite(in4, HIGH);
      }

      if(letra == 'H'){ // PARA TRÁS À ESQUERDA
       digitalWrite(in1, HIGH);
       digitalWrite(in2, HIGH);
       digitalWrite(in3, LOW);
       digitalWrite(in4, HIGH);
      }

      if (letra == 'U'){ // LIGAR LUZ DE TRÁS
       digitalWrite(ledtras, HIGH);
      }

      if (letra == 'u'){ // DESLIGAR LUZ DE TRÁS
       digitalWrite(ledtras, LOW);
      }

      if (letra == 'V'){ // LIGA O BUZZER2
       digitalWrite(buzzer2, HIGH);
      }

      if (letra == 'v'){ // DESLIGA O BUZZER2
       digitalWrite(buzzer2, LOW);
      }


    }
  }
