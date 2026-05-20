# MusicBoxM

A fully functional Arduino-based music box with OLED display, rotary encoder control, and integrated power management. Play your favorite melodies through a mini-speaker while navigating an interactive menu on a small OLED screen. Features battery power with charging capability, volume control, and an on/off switch.

## Features

- 🎵 **5 Pre-programmed Melodies**:
  - Gravity Falls Theme
  - Star Wars - Imperial March
  - Super Mario Bros - Main Theme
  - Do-Re-Mi Scale
  - And more!

- 📺 **OLED Display**: Beautiful menu interface for song selection
- 🎛️ **Rotary Encoder Control**: Intuitive navigation
  - Rotate to scroll through songs
  - Press to select and play
- 🔊 **Mini-Speaker Output**: Crystal clear audio playback
- 🔋 **Battery Powered**: Rechargeable battery with integrated charging module
- 🎚️ **Volume Control**: Potentiometer for adjustable playback volume
- ⚡ **On/Off Switch**: Slide switch for convenient power management
- ⚡ **Non-blocking Playback**: System remains responsive while music plays
- 💾 **Flash Memory Optimized**: Songs stored in PROGMEM for efficient memory usage

## Hardware Requirements

### Microcontroller

- Arduino board (tested with Arduino Uno/Nano)

### Components

**Control & Display:**
- **1x KY-040 Rotary Encoder** (with integrated push button)
- **1x OLED Display** (I2C, 128x64 or similar)

**Audio & Power:**
- **1x Mini-Speaker** (8Ω - 16Ω, 1-2W)
- **1x Rechargeable Battery** (Li-Po or Li-Ion recommended)
- **1x Battery Charging Module** (TP4056 or similar)
- **1x Slide Switch Button** (On/Off power control)

**User Interface:**
- **1x Potentiometer** (10kΩ - for volume control)

**Wiring:**
- Jumper wires, breadboard, and solder (for permanent connections)

### Pin Connections

| Component           | Pin       |
| ------------------- | --------- |
| Encoder CLK         | 2         |
| Encoder DT          | 3         |
| Encoder Button (SW) | 4         |
| Speaker/Buzzer      | 8 (PWM)   |
| Volume Potentiometer| A0        |
| OLED SDA            | A4        |
| OLED SCL            | A5        |
| Power On/Off Switch | GND + VCC |
| Battery +           | VCC       |
| Battery -           | GND       |

## Software Requirements

- Arduino IDE
- **U8g2lib**: OLED display library (install via Arduino Library Manager)

## Project Structure

```
MusicBoxM/
├── MusicBoxM.ino      # Main sketch - encoder and button handling
├── menu.h/.cpp        # Menu system and OLED display management
├── player.h/.cpp      # Music playback engine (non-blocking)
├── songs.h/.cpp       # Song definitions and melody data
├── pitches.h          # Musical note frequency definitions
└── README.md          # This file
```

## Code Overview

### Main Components

**MusicBoxM.ino**

- Initializes all systems (Serial, GPIO, encoder, display, player)
- Main loop handles encoder input, button presses, and playback updates

**player.h/player.cpp**

- Manages non-blocking music playback using `tone()` function
- Plays notes at precise timings without blocking the main loop
- Single melody playback at a time

**menu.h/menu.cpp**

- Renders menu on OLED display
- Handles scroll up/down and selection logic
- Communicates with player to trigger playback

**songs.h/songs.cpp**

- Stores melody data in program memory (PROGMEM)
- Each song contains note frequencies and durations
- Easy to add new songs following the existing pattern

**pitches.h**

- Frequency lookup table for musical notes
- Supports notes from B0 to beyond octave 5

## How to Use

1. **Upload** the sketch to your Arduino board
2. **Connect the battery** to the charging module (or use USB charging if available)
3. **Toggle the on/off switch** to power on the device
4. **Use the potentiometer** to adjust volume as needed
5. **Rotate** the encoder to browse songs
6. **Press** the encoder button to play a song
7. **While playing**, you can rotate to select the next song, adjust volume with the potentiometer, or wait for the current one to finish
8. **Toggle the switch** to power off when not in use

## Adding New Songs

To add a new song, follow this pattern in `songs.cpp`:

```cpp
static const int melodyNewSong[] PROGMEM = {
    NOTE_C4, NOTE_D4, NOTE_E4, // ... your notes
};

static const int durationsNewSong[] PROGMEM = {
    8, 8, 4, // ... note durations (1=whole, 2=half, 4=quarter, 8=eighth, etc.)
};
```

Then update the `songs` array:

```cpp
const Song songs[NUM_SONGS] = {
    // ... existing songs
    { "Your Song Name", melodyNewSong, durationsNewSong, sizeof(melodyNewSong)/sizeof(melodyNewSong[0]) }
};
```

Don't forget to increment `NUM_SONGS` in `songs.h`.

## Serial Monitor

The project outputs debug information to the Serial Monitor at 9600 baud:

- Encoder rotation directions
- Button clicks
- Song playback status

## Notes

- Songs are stored in flash memory to conserve SRAM
- Playback is non-blocking, allowing the UI to remain responsive
- Add debouncing (50ms) prevents false encoder triggers
- Empty encoder input handling prevents missed rotations

## Development Status

**Current Stage:** Prototype with full functionality
- Rotative encoder KY-40 to select musics
- Buzzer for playing songs
- OLED screen to navigate between songs
**Final Product Features:** 
- Mini-speaker audio output
- Rechargeable battery with charging module
- Potentiometer-based volume control
- On/off slide switch
- Fully working music box

## Future Enhancements

- [ ] All improvements which embraces working towards the final product
- [ ] Add more songs to the library
- [ ] Implement volume level display on OLED
- [ ] Store custom songs via EEPROM

## License

Feel free to use and modify this project as you wish.

---
