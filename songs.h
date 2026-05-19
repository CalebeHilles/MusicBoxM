#ifndef SONGS_H
#define SONGS_H

#include <Arduino.h>
#include <avr/pgmspace.h>

// Estrutura que representa uma música
// Os ponteiros apontam para dados na Flash (PROGMEM)
struct Song {
  const char* name;
  const int*  melody;
  const int*  durations;
  int         length;
};

#define NUM_SONGS 5

extern const Song songs[NUM_SONGS];

// Helpers para ler dados da Flash com segurança
inline int songGetNote(const Song& s, int i) {
  return (int) pgm_read_word(&s.melody[i]);
}

inline int songGetDuration(const Song& s, int i) {
  return (int) pgm_read_word(&s.durations[i]);
}

#endif