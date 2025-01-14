#include <stdint.h>
#include <stdbool.h>

#include "efm32gg.h"

void setupDAC() {
    *CMU_HFPERCLKEN0 |= (1 << 17);
    *DAC0_CTRL = 0x50014; // prescaling by a factor of 1/2⁵ and enable output to pin
    *DAC0_CH0CTRL = 1;
    *DAC0_CH1CTRL = 1;
}

void disableDAC() {
    *DAC0_CTRL = 0;
    *DAC0_CH0CTRL = 0;
    *DAC0_CH1CTRL = 0;
    *CMU_HFPERCLKEN0 &= ~(1 << 17);
}
