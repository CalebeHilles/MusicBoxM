#include "pitches.h"
#include "songs.h"
#include "player.h"
#include "menu.h"

// ─────────────────────────────────────────
// Pinos do Encoder KY-040
// ─────────────────────────────────────────
#define PIN_CLK 2
#define PIN_DT  3
#define PIN_SW  4

// Estado do encoder
static int lastCLK;
static bool lastButtonState = HIGH;
static unsigned long lastDebounceTime = 0;
#define DEBOUNCE_DELAY 50

void setup() {
  Serial.begin(9600);
  Serial.println("MusicBox iniciando...");

  pinMode(PIN_CLK, INPUT);
  pinMode(PIN_DT,  INPUT);
  pinMode(PIN_SW,  INPUT_PULLUP);

  lastCLK = digitalRead(PIN_CLK);

  playerInit();
  menuInit();

  Serial.println("Pronto!");
}

void loop() {
  handleEncoder();
  handleButton();
  playerUpdate();  // Toca nota a nota sem bloquear
  menuUpdate();    // Atualiza o display
}

// ─────────────────────────────────────────
// Leitura do encoder (rotação)
// ─────────────────────────────────────────
void handleEncoder() {
  int currentCLK = digitalRead(PIN_CLK);

  if (currentCLK != lastCLK && currentCLK == LOW) {
    if (digitalRead(PIN_DT) != currentCLK) {
      menuScrollDown();
      Serial.println("Encoder: baixo");
    } else {
      menuScrollUp();
      Serial.println("Encoder: cima");
    }
  }

  lastCLK = currentCLK;
}

// ─────────────────────────────────────────
// Leitura do botão do encoder (clique)
// ─────────────────────────────────────────
void handleButton() {
  bool buttonState = digitalRead(PIN_SW);

  if (buttonState != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY) {
    if (buttonState == LOW && lastButtonState == HIGH) {
      menuSelect();
      Serial.println("Botao: clicado");
    }
  }

  lastButtonState = buttonState;

  // Se o menu sinalizou que quer tocar, inicia a música
  if (menuShouldPlay()) {
    menuClearPlay();
    int idx = menuGetSelected();
    Serial.print("Tocando: ");
    Serial.println(songs[idx].name);
    playerPlay(songs[idx]);
  }
}
