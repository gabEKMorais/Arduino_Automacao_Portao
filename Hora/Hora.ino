#include <ThreeWire.h>
#include <RtcDS1302.h>
 
ThreeWire myWire(7, 6, 8);
RtcDS1302<ThreeWire> Rtc(myWire);
 
void setup () {
  Rtc.Begin();
  //RtcDateTime currentTime = RtcDateTime(__DATE__, __TIME__);
  //Rtc.SetDateTime(currentTime);
  Serial.begin(9600);
}
 
void loop () {
  
  RtcDateTime now = Rtc.GetDateTime();
  int dia = now.DayOfWeek();

  Serial.print("Data: ");
  Serial.print(now.Day());
  Serial.print("/");
  Serial.print(now.Month());
  Serial.print("/");
  Serial.print(now.Year());
  Serial.println();
  
  Serial.print("Hora: ");
  Serial.print(now.Hour());
  Serial.print(":");
  Serial.print(now.Minute());
  Serial.print(":");
  Serial.print(now.Second());
  Serial.println();

  Serial.print("Hoje é: ");
  Serial.print(dia);
  Serial.println();

  delay(500);
}
