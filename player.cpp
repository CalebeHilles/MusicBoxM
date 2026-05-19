#include "player.h"

static const Song* currentSong = nullptr;
static int currentNote = 0;
static bool playing = false;
static unsigned long nextNoteTime = 0;

void playerInit() {
  pinMode(PIN_BUZZER, OUTPUT);
}

void playerPlay(const Song& song) {
  playerStop();
  currentSong = &song;
  currentNote = 0;
  playing = true;
  nextNoteTime = millis();
}

void playerStop() {
  noTone(PIN_BUZZER);
  playing = false;
  currentSong = nullptr;
  currentNote = 0;
}

bool playerIsPlaying() {
  return playing;
}

// Chamado no loop() — toca nota a nota sem bloquear o programa
// Isso é importante para o OLED e encoder continuarem respondendo
void playerUpdate() {
  if (!playing || currentSong == nullptr) return;
  if (millis() < nextNoteTime) return;

  if (currentNote >= currentSong->length) {
    playerStop();
    return;
  }

  int duration = 1000 / songGetDuration(*currentSong, currentNote);
  int note = songGetNote(*currentSong, currentNote);

  if (note == 0) {
    noTone(PIN_BUZZER);
  } else {
    tone(PIN_BUZZER, note, duration);
  }

  nextNoteTime = millis() + (duration * 1.30);
  currentNote++;
}