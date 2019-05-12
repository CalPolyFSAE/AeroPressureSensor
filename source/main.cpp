#include "pin_mux.h"
#include "clock_config.h"
#include "MKE18F16.h"

#include "canlight.h"
#include "spi.h"
#include "fsl_lpspi.h"
using namespace BSP;

uint8_t flag;

int main(void) {
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
//SysTick_Config(1000000);
// Construct SPI driver with default driver settings
spi::spi_config conf;
spi::SPI::ConstructStatic(&conf);
spi::SPI& spi = spi::SPI::StaticClass();

// Set up master configuration, including CS pin
spi::SPI::masterConfig mconf;
mconf.csport = gpio::PortE;
mconf.cspin = 9;

mconf.cphase = kLPSPI_ClockPhaseSecondEdge;
mconf.cpol = kLPSPI_ClockPolarityActiveHigh;


// Initialize SPI module 0 as master
spi.initMaster(1, &mconf);




// Create tx/rx arrays:
// Anticipated command is 4 MOSI command bytes, followed by 
// 4 MISO data bytes. Total message length is 8
uint8_t tx[8] = {0x06, 0x44, 0x44, 0x08, 0xff, 0xff, 0xff, 0xff};
uint8_t rx[8];

uint8_t tx2[4] = {0xff, 0xff, 0xff, 0xff};

//memset(rx, 0, 8);

// Do SPI command using SPI module 0
//spi.mastertx(1, tx, rx, 4);

//spi.xcvrs[1].csport = gpio::PortA;
//spi.xcvrs[1].cspin = 2;

spi.mastertx(1, tx, rx, 4);


while(spi.xcvrs[1].transmitting);




    while(1) {
			//if(flag){
				// do a thing
				spi.mastertx(1, tx2, rx, 4);


				while(spi.xcvrs[1].transmitting);

			//	flag = 0;
			//	}
    }
    return 0;
}

extern "C" {
void SysTick_Handler(void){
		flag = 1;
}
}