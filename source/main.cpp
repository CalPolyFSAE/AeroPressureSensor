#include "pin_mux.h"
#include "clock_config.h"
#include "MKE18F16.h"

#include "canlight.h"
#include "spi.h"

using namespace BSP;

int main(void) {
    BOARD_InitBootPins();
    BOARD_InitBootClocks();


    while(1) {
    }
    return 0;
}
