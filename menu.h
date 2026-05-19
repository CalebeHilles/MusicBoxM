#ifndef MENU_H
#define MENU_H

#include <Arduino.h>
#include <U8g2lib.h>
#include "songs.h"

void menuInit();
void menuUpdate();         // Deve ser chamado no loop()
void menuScrollUp();       // Chamado pelo encoder girando pra cima
void menuScrollDown();     // Chamado pelo encoder girando pra baixo
void menuSelect();         // Chamado pelo clique do encoder
int  menuGetSelected();    // Retorna índice da música selecionada
bool menuShouldPlay();     // Retorna true quando usuário confirmou seleção
void menuClearPlay();      // Reseta o flag após iniciar a música

#endif