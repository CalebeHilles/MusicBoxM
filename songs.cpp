#include "songs.h"
#include "pitches.h"

// ─────────────────────────────────────────
// Harry Potter - Hedwig's Theme
// ─────────────────────────────────────────
static const int melodyGravityFalls[] PROGMEM = {
    NOTE_F4, NOTE_C4, NOTE_A3, NOTE_C4, NOTE_A3, NOTE_F4,
    NOTE_F4, NOTE_C4, NOTE_A3, NOTE_C4, NOTE_A3, NOTE_F4,
    NOTE_E4, NOTE_C4, NOTE_G3, NOTE_C4, NOTE_G3, NOTE_E4,
    NOTE_E4, NOTE_C4, NOTE_G3, NOTE_C4, NOTE_G3, NOTE_E4,
    NOTE_E4, NOTE_CS4, NOTE_A3, NOTE_CS4, NOTE_A3, NOTE_E4,
    NOTE_E4, NOTE_CS4, NOTE_A3, NOTE_CS4, NOTE_A3, NOTE_E4,
    NOTE_D4, NOTE_E4, NOTE_F4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_C4,
    NOTE_D4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4,
    NOTE_F4, NOTE_F4, NOTE_F4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_F4,
    NOTE_A4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4,
    NOTE_F4, NOTE_F4, NOTE_F4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_F4,
    NOTE_A4, NOTE_A4, NOTE_A4, NOTE_CS5, NOTE_CS5, NOTE_CS5,
    NOTE_F4, NOTE_F4, NOTE_F4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_F4,
    NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_G4, NOTE_C5, NOTE_A4, NOTE_CS5, NOTE_D5};

static const int durationsGravityFalls[] PROGMEM = {
    8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8,
    2, 3, 3, 4, 4, 2, 2,
    2, 3, 3, 4, 4, 2, 2, 2,
    8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8,
    3, 3, 3, 3, 3, 2,
    3, 3, 3, 3, 3, 3, 3,
    4, 4, 4, 4, 4, 4, 4, 1};

// ─────────────────────────────────────────
// Star Wars - Imperial March
// ─────────────────────────────────────────
static const int melodyStarWars[] PROGMEM = {
    NOTE_A4, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_C5,
    NOTE_A4, NOTE_F4, NOTE_C5, NOTE_A4,
    NOTE_E5, NOTE_E5, NOTE_E5, NOTE_F5, NOTE_C5,
    NOTE_GS4, NOTE_F4, NOTE_C5, NOTE_A4,
    NOTE_A5, NOTE_A4, NOTE_A4, NOTE_A5, NOTE_GS5, NOTE_G5,
    NOTE_FS5, NOTE_F5, NOTE_FS5, REST, NOTE_AS4, NOTE_DS5, NOTE_D5, NOTE_CS5,
    NOTE_C5, NOTE_B4, NOTE_C5, REST, NOTE_F4, NOTE_GS4, NOTE_F4, NOTE_A4,
    NOTE_C5, NOTE_A4, NOTE_C5, NOTE_E5};

static const int durationsStarWars[] PROGMEM = {
    4, 4, 4, 8, 2,
    4, 8, 2, 1,
    4, 4, 4, 8, 2,
    4, 8, 2, 1,
    4, 8, 4, 4, 8, 8,
    8, 8, 8, 8, 8, 4, 8, 8,
    8, 8, 8, 8, 8, 4, 8, 8,
    4, 8, 2, 1};

// ─────────────────────────────────────────
// Super Mario Bros - Main Theme
// ─────────────────────────────────────────
static const int melodyMario[] PROGMEM = {
    NOTE_E5, NOTE_E5, NOTE_E5, NOTE_C5, NOTE_E5, NOTE_G5, REST, NOTE_G4,
    NOTE_C5, NOTE_G4, NOTE_E4, NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4,
    NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5,
    NOTE_E5, NOTE_C5, NOTE_D5, NOTE_B4};

static const int durationsMario[] PROGMEM = {
    8, 8, 8, 8, 8, 4, 10,
    4, 4, 4, 4, 4, 8, 4,
    8, 8, 8, 4, 8, 4,
    4, 8, 8, 4};

// ─────────────────────────────────────────
// Dó Ré Mi Fá Sol (escala simples)
// ─────────────────────────────────────────
static const int melodyDoReMi[] PROGMEM = {
    NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5,
    NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4};

static const int durationsDoReMi[] PROGMEM = {
    4, 4, 4, 4, 4, 4, 2,
    4, 4, 4, 4, 4, 4, 2};

// ─────────────────────────────────────────
// Gravity Falls - Theme
// ─────────────────────────────────────────
static const int melodyHarryPotter[] PROGMEM = {
    REST, NOTE_D4,
    NOTE_G4, NOTE_AS4, NOTE_A4,
    NOTE_G4, NOTE_D5,
    NOTE_C5, NOTE_C5,
    NOTE_A4, NOTE_A4,
    NOTE_G4, NOTE_AS4, NOTE_A4,
    NOTE_F4, NOTE_GS4,
    NOTE_D4};

static const int durationsHarryPotter[] PROGMEM = {
    2, 4,
    3, 6, 4,
    2, 4,
    2, 4, 4,
    2, 4, 4,
    3, 6, 4,
    2, 4,
    2};

// ─────────────────────────────────────────
// Array principal com todas as músicas
// ─────────────────────────────────────────
const Song songs[NUM_SONGS] = {
    {"Harry Potter",
     melodyHarryPotter,
     durationsHarryPotter,
     sizeof(melodyHarryPotter) / sizeof(melodyHarryPotter[0])},
    {"Star Wars",
     melodyStarWars,
     durationsStarWars,
     sizeof(melodyStarWars) / sizeof(melodyStarWars[0])},
    {"Super Mario",
     melodyMario,
     durationsMario,
     sizeof(melodyMario) / sizeof(melodyMario[0])},
    {"Do Re Mi",
     melodyDoReMi,
     durationsDoReMi,
     sizeof(melodyDoReMi) / sizeof(melodyDoReMi[0])},
    {"Gravity Falls",
     melodyGravityFalls,
     durationsGravityFalls,
     sizeof(melodyGravityFalls) / sizeof(melodyGravityFalls[0])}};