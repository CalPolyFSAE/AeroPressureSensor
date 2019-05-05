#include "pin_mux.h"
#include "clock_config.h"
#include "MKE18F16.h"

#include "canlight.h"
#include "spi.h"

using namespace BSP;

int main(void) {
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
// Construct SPI driver with default driver settings
spi::spi_config conf;
spi::SPI::ConstructStatic(&conf);
spi::SPI& spi = spi::SPI::StaticClass();

// Set up master configuration, including CS pin
spi::SPI::masterConfig mconf;
mconf.csport = gpio::PortE;
mconf.cspin = 9;

// Initialize SPI module 0 as master
spi.initMaster(1, &mconf);

// Create tx/rx arrays:
// Anticipated command is 4 MOSI command bytes, followed by 
// 4 MISO data bytes. Total message length is 8
uint8_t tx[8] = {0x44, 0x06, 0xFF, 0xff, 0xff, 0xff, 0xff, 0xff};
uint8_t rx[8];

// Do SPI command using SPI module 0
spi.mastertx(1, tx, rx, 3);

    while(1) {
    }
    return 0;
}
