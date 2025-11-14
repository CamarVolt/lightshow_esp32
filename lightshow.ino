#define LED 2

void flash(int t) {
  digitalWrite(LED, HIGH);
  delay(t);
  digitalWrite(LED, LOW);
  delay(t);
}

void pulse(int up, int hold, int down) {
  digitalWrite(LED, HIGH);
  delay(up);
  digitalWrite(LED, HIGH);
  delay(hold);
  digitalWrite(LED, LOW);
  delay(down);
}

void burst(int times, int speed) {
  for (int i = 0; i < times; i++) {
    digitalWrite(LED, HIGH);
    delay(speed);
    digitalWrite(LED, LOW);
    delay(speed / 2);
  }
}

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {

  // 1) INTRO – BATIMENTO LENTO ESTILO CORAÇÃO
  for (int i = 0; i < 4; i++) {
    flash(200);
    delay(300);
  }

  // 2) PULSO CRESCENTE – COMO SE ESTIVESSE CARREGANDO ENERGIA
  for (int i = 50; i <= 300; i += 50) {
    flash(i);
  }

  // 3) EXPLOSÃO – RAJADONA MUITO RÁPIDA
  burst(20, 40);

  delay(400);

  // 4) SEQUÊNCIA RITMADA – ESTILO MÚSICA ELETRÔNICA
  for (int i = 0; i < 8; i++) {
    flash(100);
    delay(150);
  }

  // 5) STROBE CAÓTICO – PISCANDO IRREGULARMENTE
  flash(30);
  delay(120);
  flash(60);
  delay(40);
  flash(20);
  delay(200);
  flash(35);
  delay(50);

  // 6) MOMENTO DRAMÁTICO – LED APAGA TOTAL E VOLTA COM UM SUSTO
  delay(800);
  burst(10, 25);

  // 7) GRANDE FINAL – PULSOS GRANDES VARIANDO VELOCIDADE
  for (int i = 0; i < 5; i++) {
    flash(150 - i * 20);
    flash(150 - i * 20);
  }

  // LOOP REPETE O SHOW
  delay(500);
}
