// LTC Sistemas LTDA. Gabriel Krummenauer de Morais - 2024
// Sistema de gerenciamento de fechamento e abertura automatico - projeto desenvolvido para secretaria de obras de Três Coroas / RS
//
// Iniciando modulo RTC
#include <ThreeWire.h>
#include <RtcDS1302.h>
ThreeWire myWire(7, 6, 8);
RtcDS1302<ThreeWire> Rtc(myWire);
//
const int pinoMicro = 10; //PINO DIGITAL UTILIZADO PELA CHAVE FIM DE CURSO
const int rele01 = 4; // configurta pino do relay
//
// Funções
void AtivarBotoeira () {
    digitalWrite(rele01, LOW);
    delay(1000);
    digitalWrite(rele01, HIGH);
    delay(1000);
}
//
void setup() {
  Rtc.Begin();
  pinMode(pinoMicro, INPUT_PULLUP); //DEFINE O PINO COMO ENTRADA / "_PULLUP" É PARA ATIVAR O RESISTOR INTERNO
  //DO ARDUINO PARA GARANTIR QUE NÃO EXISTA FLUTUAÇÃO ENTRE 0 (LOW) E 1 (HIGH)
  pinMode(rele01, OUTPUT); // ativa saida para o rele
  digitalWrite(rele01, HIGH); // inicia o relay como desativo
}
//
void loop() {
  // Função padrão de fechamento automatico durante qualquer dia e horario
  if(digitalRead(pinoMicro) == LOW){
    delay(60000);
    if(digitalRead(pinoMicro) == LOW) {
      AtivarBotoeira();
      }
    }
    // Iniciando programação especifica por dia e horario
    RtcDateTime agora = Rtc.GetDateTime(); // Pega informação da data atual
    int dia = agora.DayOfWeek(); // Pega informação do dia da semana atual
    int hora = agora.Hour(); // Informação da hora
    int minuto = agora.Minute(); // Informação dos minutos
    while ( // Aqui teremos uma função exclusiva para determinado dia e horario
            (dia==1||dia==2||dia==3||dia==4||dia==5) // dias da semana seg-sex
         && ( (
                  hora >= 6 && hora <= 7 && minuto >= 28 // Entre 6:28-7:00
               ) || (
                  hora >= 12 && hora <= 13 && minuto >= 43 // Entre 12:43-13:00
               ) || (
                  hora == 17 && minuto <= 30 // Entre 17:00-17:30
            ) )
          ) {
            
        if(digitalRead(pinoMicro) == HIGH){
          delay(90000);
          if(digitalRead(pinoMicro) == HIGH) {
            AtivarBotoeira();
          }
        }
        RtcDateTime agora = Rtc.GetDateTime();  // atualiza as informações de horas na variavel agora
        int dia = agora.DayOfWeek();
        int hora = agora.Hour(); // Informação da hora
        int minuto = agora.Minute(); // Informação dos minutos
        delay(2000);
      }
    delay(2000);    
}
