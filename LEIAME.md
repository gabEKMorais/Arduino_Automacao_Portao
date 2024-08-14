# Arduino_Automacao_Portao
Automação de portão com o auxílio de Arduíno

O objetivo do projeto é de incluir em um sistema já utilizado de automatizador de portão uma função de mantê-lo aberto em horários específicos, mantendo também o fechamento automático fora desses horários.
Dentro das soluções existentes não encontramos nada com bom custo-benefício e que pudesse ser implementada como um módulo à parte sem comprometer nada no funcionamento normal do automatizador.

Para realizar o fechamento automático sem ocorrer conflitos o fechamento automático da central do automatizador foi desativado e ficou a cargo do arduino, assim o portão em si tem as funções básicas de abertura e fechamento, com sensor de barreira, completamente independentes do módulo arduino.

Para o projeto foi utilizado um arduino uno, um módulo de relé com 2 canais (poderia ser de apenas 1 canal também) e um módulo RTC para identificar dias e horários.

O funcionamento basicamente seria:
- Arduino verifica se a micro está acionada, indicando que o portão está aberto;
- Aguardar 60 segundos;
- Verifica novamente;
- Envia o comando para o relé, acionando a botoeira da central presente no automatizador;
- Aqui temos duas opções, já por parte da central:
   No primeiro caso ela fecharia o portão e a micro não estaria mais acionada.
   No segundo caso com o sensor de barreira acusando algo no meio do caminho a central não fecha o portão e a micro continua acionada, nesse caso o arduino vai emitir um novo comando após 60 segundos devido a micro ainda estar ativa.
- No caso de estar dentro dos dias e horários estipulados, o arduino passa a ter um comportamento diferente onde a micro precisa estar acionada. Caso ela não esteja acionada o arduino aguarda 90 segundo e verifica uma segunda vez para aí enviar o comando para o relé e a central abrir o portão.
  Nesse segundo caso o funcionamento dele é baseado na premissa que se a micro não está acionada o portão não está aberto, o objetivo é manter o portão aberto dentro desses horários.

