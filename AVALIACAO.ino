//declarar todas as variáveis que serão utilizadas:

//portas digitais:
//portas do LED da esquerda (dezenas)
int a1 = 7;
int b1 = 8;
int c1 = 9;
int d1 = 10;
int e1 = 11;
int f1 = 13;
int g1 = 12;

//portas do LED da direita (unidades)
int a2 = 0;
int b2 = 1;
int c2 = 2;
int d2 = 3;
int e2 = 4;
int f2 = 6;
int g2 = 5;

//valores de entrada para serem multiplicados:
int x = 0;
int y = 0;

//estados das portas de entrada:
int buttonStateA0 = 0; //referente ao botão da esquerda.
int buttonStateA1 = 0; //referente ao botão da direita.

//variáveis para o visor:
int produto = 0; //<- protudo de x e y que será separada em dezenas e unidades.
int unidade = 0; //<- será mostrada no display da direita.
int dezena = 0; //<- será mostrada no display da esquerda.


void setup() {
  // configurar todas as portas digitais como saída:
  pinMode(a1,OUTPUT);
  pinMode(b1,OUTPUT);
  pinMode(c1,OUTPUT);
  pinMode(d1,OUTPUT);
  pinMode(e1,OUTPUT);
  pinMode(f1,OUTPUT);
  pinMode(g1,OUTPUT);
  pinMode(a2,OUTPUT);
  pinMode(b2,OUTPUT);
  pinMode(c2,OUTPUT);
  pinMode(d2,OUTPUT);
  pinMode(e2,OUTPUT);
  pinMode(f2,OUTPUT);
  pinMode(g2,OUTPUT);
  
  //configurar duas portas analógicas como entrada dos botões:
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
}

void loop() {
  //configuração de leitura dos botões de leitura:
  buttonStateA0 = digitalRead(A0);
  buttonStateA1 = digitalRead(A1);

  //verificar entradas de dados e executar ações:
  while (buttonStateA0 == HIGH || buttonStateA1 == HIGH){

    //aumenta o valor de x em 1 cada vez que o botão da esquerda é pressionado:
    if (buttonStateA0 == HIGH){
      x++;
      
      //quando x chegar a 10, reset para 0:
      if (x == 10){
        x = 0;
      }
    }

    //aumenta o valor de y em 1 cada vez que o botão da direita é pressionado:
    if (buttonStateA1 == HIGH){
      y++;

      //quando y chegar a 10, reset para 0:
      if (y == 10){
        y = 0;
      }
    }
    produto = x*y; //<- produto entre as duas entradas.
    unidade = produto;
    dezena = produto;

    //subtrai todas as dezenas do produto até permanecer apenas as unidades:
    while (unidade>=10){
      unidade -= 10;
    }

    //subtrai todas as unidades do produto até permanecer apenas as dezenas:
    while (dezena%10) ! (0);{
      dezena -= 1;
    }

    //compara o valor da dezena para comandar quais LEDs serão acesos e quias serão apagados no display da esquerda:
    switch(dezena){
      //como o maior produto entre as entradas terá 8 dezenas, não é necessário especificar o caso de 9 dezenas.
      case 0: {
        digitalWrite(a1,HIGH);
        digitalWrite(b1,HIGH);
        digitalWrite(c1,HIGH);
        digitalWrite(d1,HIGH);
        digitalWrite(e1,HIGH);
        digitalWrite(f1,HIGH);
        digitalWrite(g1,LOW);
        break;
      }
      case 10: {
        digitalWrite(a1,LOW);
        digitalWrite(b1,HIGH);
        digitalWrite(c1,HIGH);
        digitalWrite(d1,LOW);
        digitalWrite(e1,LOW);
        digitalWrite(f1,LOW);
        digitalWrite(g1,LOW);
        break;
      }
      case 20: {
        digitalWrite(a1,HIGH);
        digitalWrite(b1,HIGH);
        digitalWrite(c1,LOW);
        digitalWrite(d1,HIGH);
        digitalWrite(e1,HIGH);
        digitalWrite(f1,LOW);
        digitalWrite(g1,HIGH);
        break;
      }
      case 30: {
        digitalWrite(a1,HIGH);
        digitalWrite(b1,HIGH);
        digitalWrite(c1,HIGH);
        digitalWrite(d1,HIGH);
        digitalWrite(e1,LOW);
        digitalWrite(f1,LOW);
        digitalWrite(g1,HIGH);
        break;
      }
      case 40: {
        digitalWrite(a1,LOW);
        digitalWrite(b1,HIGH);
        digitalWrite(c1,HIGH);
        digitalWrite(d1,LOW);
        digitalWrite(e1,LOW);
        digitalWrite(f1,HIGH);
        digitalWrite(g1,HIGH);
        break;
      }
      case 50: {
        digitalWrite(a1,HIGH);
        digitalWrite(b1,LOW);
        digitalWrite(c1,HIGH);
        digitalWrite(d1,HIGH);
        digitalWrite(e1,LOW);
        digitalWrite(f1,HIGH);
        digitalWrite(g1,HIGH);
        break;
      }
      case 60: {
        digitalWrite(a1,HIGH);
        digitalWrite(b1,LOW);
        digitalWrite(c1,HIGH);
        digitalWrite(d1,HIGH);
        digitalWrite(e1,HIGH);
        digitalWrite(f1,HIGH);
        digitalWrite(g1,HIGH);
        break;
      }
      case 70: {
        digitalWrite(a1,HIGH);
        digitalWrite(b1,HIGH);
        digitalWrite(c1,HIGH);
        digitalWrite(d1,LOW);
        digitalWrite(e1,LOW);
        digitalWrite(f1,LOW);
        digitalWrite(g1,LOW);
        break;
      }
      case 80: {
        digitalWrite(a1,HIGH);
        digitalWrite(b1,HIGH);
        digitalWrite(c1,HIGH);
        digitalWrite(d1,HIGH);
        digitalWrite(e1,HIGH);
        digitalWrite(f1,HIGH);
        digitalWrite(g1,HIGH);
        break;
      }
    }

    //compara o valor da unidade para comandar quais LEDs serão acesos e quias serão apagados no display da direita:
    switch(unidade){
      case 0: {
        digitalWrite(a2,HIGH);
        digitalWrite(b2,HIGH);
        digitalWrite(c2,HIGH);
        digitalWrite(d2,HIGH);
        digitalWrite(e2,HIGH);
        digitalWrite(f2,HIGH);
        digitalWrite(g2,LOW);
        break;
      }
      case 1: {
        digitalWrite(a2,LOW);
        digitalWrite(b2,HIGH);
        digitalWrite(c2,HIGH);
        digitalWrite(d2,LOW);
        digitalWrite(e2,LOW);
        digitalWrite(f2,LOW);
        digitalWrite(g2,LOW);
        break;
      }
      case 2: {
        digitalWrite(a2,HIGH);
        digitalWrite(b2,HIGH);
        digitalWrite(c2,LOW);
        digitalWrite(d2,HIGH);
        digitalWrite(e2,HIGH);
        digitalWrite(f2,LOW);
        digitalWrite(g2,HIGH);
        break;
      }
      case 3: {
        digitalWrite(a2,HIGH);
        digitalWrite(b2,HIGH);
        digitalWrite(c2,HIGH);
        digitalWrite(d2,HIGH);
        digitalWrite(e2,LOW);
        digitalWrite(f2,LOW);
        digitalWrite(g2,HIGH);
        break;
      }
      case 4: {
        digitalWrite(a2,LOW);
        digitalWrite(b2,HIGH);
        digitalWrite(c2,HIGH);
        digitalWrite(d2,LOW);
        digitalWrite(e2,LOW);
        digitalWrite(f2,HIGH);
        digitalWrite(g2,HIGH);
        break;
      }
      case 5: {
        digitalWrite(a2,HIGH);
        digitalWrite(b2,LOW);
        digitalWrite(c2,HIGH);
        digitalWrite(d2,HIGH);
        digitalWrite(e2,LOW);
        digitalWrite(f2,HIGH);
        digitalWrite(g2,HIGH);
        break;
      }
      case 6: {
        digitalWrite(a2,HIGH);
        digitalWrite(b2,LOW);
        digitalWrite(c2,HIGH);
        digitalWrite(d2,HIGH);
        digitalWrite(e2,HIGH);
        digitalWrite(f2,HIGH);
        digitalWrite(g2,HIGH);
        break;
      }
      case 7: {
        digitalWrite(a2,HIGH);
        digitalWrite(b2,HIGH);
        digitalWrite(c2,HIGH);
        digitalWrite(d2,LOW);
        digitalWrite(e2,LOW);
        digitalWrite(f2,LOW);
        digitalWrite(g2,LOW);
        break;
      }
      case 8: {
        digitalWrite(a2,HIGH);
        digitalWrite(b2,HIGH);
        digitalWrite(c2,HIGH);
        digitalWrite(d2,HIGH);
        digitalWrite(e2,HIGH);
        digitalWrite(f2,HIGH);
        digitalWrite(g2,HIGH);
        break;
      }
      case 9: {
        digitalWrite(a2,HIGH);
        digitalWrite(b2,HIGH);
        digitalWrite(c2,HIGH);
        digitalWrite(d2,HIGH);
        digitalWrite(e2,LOW);
        digitalWrite(f2,HIGH);
        digitalWrite(g2,HIGH);
        break;
      }
    }
    //tempo de 0,1s de espera para reconhecer uma nova entrada :
    delay(100);
  }
}
