#ifndef PLAYER_H
#define PLAYER_H

#include <Arduino.h>
#include "songs.h"

#define PIN_BUZZER 8

void playerInit();
void playerPlay(const Song& song);
void playerStop();
bool playerIsPlaying();
void playerUpdate(); // Deve ser chamado no loop()

#endif