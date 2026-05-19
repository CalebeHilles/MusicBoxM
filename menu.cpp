#include "menu.h"
#include "player.h"

// Instância do display OLED (I2C, endereço padrão 0x3C)
static U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

static int selectedIndex = 0;
static bool shouldPlay = false;

// Quantas músicas cabem na tela de uma vez
#define VISIBLE_ITEMS 4

void menuInit() {
  u8g2.begin();
  u8g2.setFont(u8g2_font_6x10_tf);
}

void menuScrollUp() {
  selectedIndex--;
  if (selectedIndex < 0) selectedIndex = NUM_SONGS - 1;
}

void menuScrollDown() {
  selectedIndex++;
  if (selectedIndex >= NUM_SONGS) selectedIndex = 0;
}

void menuSelect() {
  if (playerIsPlaying()) {
    playerStop();
  } else {
    shouldPlay = true;
  }
}

int menuGetSelected() {
  return selectedIndex;
}

bool menuShouldPlay() {
  return shouldPlay;
}

void menuClearPlay() {
  shouldPlay = false;
}

void menuUpdate() {
  // Calcula o offset de scroll para manter o item selecionado visível
  int scrollOffset = 0;
  if (selectedIndex >= VISIBLE_ITEMS) {
    scrollOffset = selectedIndex - VISIBLE_ITEMS + 1;
  }

  u8g2.firstPage();
  do {
    // Título
    u8g2.setFont(u8g2_font_6x10_tf);
    u8g2.drawStr(0, 10, "** Music Box **");
    u8g2.drawHLine(0, 12, 128);

    // Desenha os itens do menu
    for (int i = 0; i < VISIBLE_ITEMS && (i + scrollOffset) < NUM_SONGS; i++) {
      int itemIndex = i + scrollOffset;
      int y = 26 + (i * 12);

      if (itemIndex == selectedIndex) {
        u8g2.drawBox(0, y - 9, 128, 11);
        u8g2.setDrawColor(0);
        u8g2.drawStr(4, y, songs[itemIndex].name);
        u8g2.setDrawColor(1);
      } else {
        u8g2.drawStr(4, y, songs[itemIndex].name);
      }
    }

    // Rodapé
    if (playerIsPlaying()) {
      u8g2.drawStr(0, 63, ">> Tocando...");
    } else {
      u8g2.drawStr(0, 63, "Clique p/ tocar");
    }
  } while (u8g2.nextPage());
}