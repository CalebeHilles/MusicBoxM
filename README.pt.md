# MusicBoxM

Um teclado musical Arduino totalmente funcional com display OLED, controle por encoder rotativo e gerenciamento de energia integrado. Toque suas melodias favoritas através de um mini-alto-falante enquanto navega um menu interativo em uma pequena tela OLED. Apresenta alimentação por bateria recarregável com módulo de carregamento, controle de volume e um botão chave liga/desliga.

## Características

- 🎵 **5 Melodias Pré-programadas**: 
  - Tema de Gravity Falls
  - Star Wars - Marcha Imperial
  - Super Mario Bros - Tema Principal
  - Escala Do-Ré-Mi
  - E mais!

- 📺 **Display OLED**: Interface de menu bonita para seleção de músicas
- 🎛️ **Controle por Encoder Rotativo**: Navegação intuitiva
  - Girar para rolar entre as músicas
  - Pressionar para selecionar e tocar
- 🔊 **Saída por Mini-Alto-falante**: Reprodução de áudio cristalina
- 🔋 **Alimentação por Bateria**: Bateria recarregável com módulo de carregamento integrado
- 🎚️ **Controle de Volume**: Potenciômetro para ajustar o volume de reprodução
- ⚡ **Botão Chave Liga/Desliga**: Chave deslizante para gerenciamento conveniente de energia
- ⚡ **Reprodução Sem Bloqueio**: Sistema permanece responsivo durante a reprodução
- 💾 **Otimizado para Memória Flash**: Músicas armazenadas em PROGMEM para uso eficiente de memória

## Componentes Necessários

### Microcontrolador
- Placa Arduino (testado com Arduino Uno/Nano)

### Componentes Eletrônicos

**Controle e Display:**
- **1x Encoder Rotativo KY-040** (com botão integrado)
- **1x Display OLED** (I2C, 128x64 ou similar)

**Áudio e Energia:**
- **1x Mini-Alto-falante** (8Ω - 16Ω, 1-2W)
- **1x Bateria Recarregável** (Li-Po ou Li-Ion recomendado)
- **1x Módulo de Carregamento de Bateria** (TP4056 ou similar)
- **1x Botão Chave Deslizante** (Controle de energia liga/desliga)

**Interface de Usuário:**
- **1x Potenciômetro** (10kΩ - para controle de volume)

**Cabeamento:**
- Fios jumper, protoboard e solda (para conexões permanentes)

### Conexões dos Pinos

| Componente         | Pino      |
|------------------|----------|
| Encoder CLK       | 2        |
| Encoder DT        | 3        |
| Botão do Encoder  | 4        |
| Alto-falante      | 8 (PWM)  |
| Potenciômetro Vol.| A0       |
| OLED SDA          | A4       |
| OLED SCL          | A5       |
| Chave Liga/Desliga| GND + VCC|
| Bateria +         | VCC      |
| Bateria -         | GND      |

## Requisitos de Software

- Arduino IDE
- **U8g2lib**: Biblioteca para display OLED (instale via Arduino Library Manager)

## Estrutura do Projeto

```
MusicBoxM/
├── MusicBoxM.ino      # Sketch principal - controle do encoder e botão
├── menu.h/.cpp        # Sistema de menu e gerenciamento do display OLED
├── player.h/.cpp      # Motor de reprodução de música (sem bloqueio)
├── songs.h/.cpp       # Definições de músicas e dados de melodias
├── pitches.h          # Tabela de frequências de notas musicais
└── README.pt.md       # Este arquivo
```

## Visão Geral do Código

### Componentes Principais

**MusicBoxM.ino**
- Inicializa todos os sistemas (Serial, GPIO, encoder, display, player)
- Loop principal que trata entrada do encoder, pressionamentos de botão e atualizações de reprodução

**player.h/player.cpp**
- Gerencia reprodução de música sem bloqueio usando a função `tone()`
- Toca notas em tempos precisos sem bloquear o loop principal
- Reprodução de uma única melodia por vez

**menu.h/menu.cpp**
- Renderiza menu no display OLED
- Trata lógica de rolar para cima/baixo e seleção
- Comunica com o player para iniciar reprodução

**songs.h/songs.cpp**
- Armazena dados de melodia na memória de programa (PROGMEM)
- Cada música contém frequências de notas e durações
- Fácil adicionar novas músicas seguindo o padrão existente

**pitches.h**
- Tabela de lookup de frequências para notas musicais
- Suporta notas de B0 até além da oitava 5

## Como Usar

1. **Carregue** o sketch na placa Arduino
2. **Conecte a bateria** ao módulo de carregamento (ou use carregamento USB se disponível)
3. **Alterne a chave liga/desliga** para ligar o dispositivo
4. **Use o potenciômetro** para ajustar o volume conforme necessário
5. **Gire** o encoder para navegar entre as músicas
6. **Pressione** o botão do encoder para tocar uma música
7. **Durante a reprodução**, você pode girar para selecionar a próxima música, ajustar o volume com o potenciômetro ou esperar a atual terminar
8. **Alterne a chave** para desligar quando não estiver em uso

## Adicionando Novas Músicas

Para adicionar uma nova música, siga este padrão em `songs.cpp`:

```cpp
static const int melodyMusikaNova[] PROGMEM = {
    NOTE_C4, NOTE_D4, NOTE_E4, // ... suas notas
};

static const int durationsMusikaNova[] PROGMEM = {
    8, 8, 4, // ... durações das notas (1=semibreve, 2=mínima, 4=semínima, 8=colcheia, etc.)
};
```

Depois atualize o array `songs`:

```cpp
const Song songs[NUM_SONGS] = {
    // ... músicas existentes
    { "Nome da Sua Música", melodyMusikaNova, durationsMusikaNova, sizeof(melodyMusikaNova)/sizeof(melodyMusikaNova[0]) }
};
```

Não esqueça de incrementar `NUM_SONGS` em `songs.h`.

## Monitor Serial

O projeto envia informações de debug para o Monitor Serial a 9600 baud:
- Direções de rotação do encoder
- Cliques de botão
- Status de reprodução de música

## Observações

- As músicas são armazenadas na memória flash para conservar SRAM
- A reprodução é sem bloqueio, permitindo que a interface permaneça responsiva
- Debouncing (50ms) adicional previne gatilhos falsos do encoder
- Tratamento de entrada vazia do encoder previne rotações perdidas

## Status do Desenvolvimento

**Estágio Atual:** Protótipo com funcionalidade completa
- Encoder rotativo KY-40 para selecionar as músicas
- Buzzer para tocar as melodias
- Tela OLED para navegação
**Características do Produto Final:** 
- Saída de áudio por mini-alto-falante
- Bateria recarregável com módulo de carregamento
- Controle de volume baseado em potenciômetro
- Botão chave liga/desliga

## Melhorias Futuras

- [ ] Todas as melhorias que envolvam avançar até o produto final
- [ ] Adicionar mais músicas à biblioteca
- [ ] Implementar exibição de nível de volume no OLED
- [ ] Armazenar músicas personalizadas via EEPROM


## Licença

Sinta-se livre para usar e modificar este projeto como desejar.

---
