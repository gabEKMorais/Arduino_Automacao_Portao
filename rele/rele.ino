int relay = 4; // configurta pino do relay
volatile byte relayState = LOW; // pode ser usada para verificar o status do realy

void setup () {
  pinMode(relay, OUTPUT); // ativa saida para o relay
  digitalWrite(relay, LOW); // inicia o relay como desativo
  Serial.begin(9600);
}
 
void loop () {
  if(relayState == LOW){
    digitalWrite(relay, HIGH);
    relayState = HIGH;
  }
}