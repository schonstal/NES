#include <stdint.h>

#define TV_NTSC 1
#include "nes.h"

#pragma bss-name(push, "ZEROPAGE")
uint8_t i;
#pragma bss-name(pop)

const char TEXT[] = "Bingo the Kitty";

const uint8_t PALETTE[] = {
    COLOR_BLACK,
    COLOR_WHITE,
    COLOR_WHITE,
    COLOR_WHITE,
};

void main(void) {
    // load palette
    PPU_ADDRESS = 0x3f;
    PPU_ADDRESS = 0x00;
    for (i = 0; i < sizeof(PALETTE); ++i) {
        PPU_DATA = PALETTE[i];
    }

    // load text
    PPU_ADDRESS = 0x21;
    PPU_ADDRESS = 0xca;
    for (i = 0; i < sizeof(TEXT); ++i) {
        PPU_DATA = (uint8_t) TEXT[i];
    }

    // reset scroll location
    PPU_SCROLL = 0x00;
    PPU_SCROLL = 0x00;

    // enable NMI and rendering
    PPU_CTRL = 0x80;
    PPU_MASK = 0x1e;

    while (1) {};
};

