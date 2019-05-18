#include "pin_mux.h"
#include "clock_config.h"
#include "MKE18F16.h"

#include "canlight.h"
#include "spi.h"
#include "fsl_lpspi.h"
using namespace BSP;

uint8_t flag;
uint32_t data[20];

#define ADDRESS 0x300

#define PERIOD 50 // ms between cycles

void sendcan(uint8_t offset, uint32_t value){
    can::CANlight::frame f;
    f.ext = 1;
    f.id = ADDRESS+offset;
    f.data[0] = value & 0xff;
    f.data[1] = (value>>8) & 0xff;
    f.data[2] = (value>>16) & 0xff;
    can::CANlight::StaticClass().tx(0, f);    
}


int main(void) {
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    SysTick_Config(60000);
    // Construct SPI driver with default driver settings
    spi::spi_config conf;
    spi::SPI::ConstructStatic(&conf);
    spi::SPI& spi = spi::SPI::StaticClass();

    can::canlight_config c;
    can::CANlight::ConstructStatic(&c);
    can::CANlight& can = can::CANlight::StaticClass();
    can::CANlight::canx_config c0;
    can.init(0, &c0);
    // Set up master configuration, including CS pin
    spi::SPI::masterConfig mconf;
    mconf.baudRate = 100000;
    mconf.cphase = kLPSPI_ClockPhaseSecondEdge;
    mconf.cpol = kLPSPI_ClockPolarityActiveHigh;


    //Sensor 12 config
    mconf.csport = gpio::PortE;
    mconf.cspin = 9;


    // Initialize SPI module 1 as master
    //SPI module 1 controls sensors 11-20
    spi.initMaster(1, &mconf);



    uint8_t tx[8] = {0x06, 0x44, 0x44, 0x08, 0xff, 0xff, 0xff, 0xff};
    uint8_t rx[8];

    spi.mastertx(1, tx, rx, 8);

    while(spi.xcvrs[1].transmitting);


    //Configure PortB and pin 6, followed by Create tx/rx arrays:
    //Anticipated command is 4 MOSI command bytes, followed by
    //4 MISO data bytes. Total message length is 8
    //Sensor 11

    spi.xcvrs[1].csport = gpio::PortD;
    spi.xcvrs[1].cspin = 16;

    spi.mastertx(1, tx, rx, 8);

    while(spi.xcvrs[1].transmitting);



    //Configure PortB and pin 6, followed by Create tx/rx arrays:
    //Anticipated command is 4 MOSI command bytes, followed by
    //4 MISO data bytes. Total message length is 8
    //Sensor 13

    spi.xcvrs[1].csport = gpio::PortB;
    spi.xcvrs[1].cspin = 6;

    spi.mastertx(1, tx, rx, 8);

    while(spi.xcvrs[1].transmitting);




    //Configure PortB and pin 6, followed by Create tx/rx arrays:
    //Anticipated command is 4 MOSI command bytes, followed by
    //4 MISO data bytes. Total message length is 8
    //Sensor 14

    spi.xcvrs[1].csport = gpio::PortE;
    spi.xcvrs[1].cspin = 10;

    spi.mastertx(1, tx, rx, 8);

    while(spi.xcvrs[1].transmitting);

    //Configure PortB and pin 6, followed by Create tx/rx arrays:
    //Anticipated command is 4 MOSI command bytes, followed by
    //4 MISO data bytes. Total message length is 8
    //Sensor 15

    spi.xcvrs[1].csport = gpio::PortE;
    spi.xcvrs[1].cspin = 2;

    spi.mastertx(1, tx, rx, 8);

    while(spi.xcvrs[1].transmitting);



    //Configure PortB and pin 6, followed by Create tx/rx arrays:
    //Anticipated command is 4 MOSI command bytes, followed by
    //4 MISO data bytes. Total message length is 8
    //Sensor 16

    spi.xcvrs[1].csport = gpio::PortA;
    spi.xcvrs[1].cspin = 13;

    spi.mastertx(1, tx, rx, 8);

    while(spi.xcvrs[1].transmitting);



    //Configure PortB and pin 6, followed by Create tx/rx arrays:
    //Anticipated command is 4 MOSI command bytes, followed by
    //4 MISO data bytes. Total message length is 8
    //Sensor 17

    spi.xcvrs[1].csport = gpio::PortE;
    spi.xcvrs[1].cspin = 6;

    spi.mastertx(1, tx, rx, 8);

    while(spi.xcvrs[1].transmitting);


    //Configure PortB and pin 6, followed by Create tx/rx arrays:
    //Anticipated command is 4 MOSI command bytes, followed by
    //4 MISO data bytes. Total message length is 8
    //Sensor 18

    spi.xcvrs[1].csport = gpio::PortC;
    spi.xcvrs[1].cspin = 7;

    spi.mastertx(1, tx, rx, 8);

    while(spi.xcvrs[1].transmitting);

    //Configure PortB and pin 6, followed by Create tx/rx arrays:
    //Anticipated command is 4 MOSI command bytes, followed by
    //4 MISO data bytes. Total message length is 8
    //Sensor 19	

    spi.xcvrs[1].csport = gpio::PortA;
    spi.xcvrs[1].cspin = 1;

    spi.mastertx(1, tx, rx, 8);

    while(spi.xcvrs[1].transmitting);


    //Configure PortB and pin 6, followed by Create tx/rx arrays:
    //Anticipated command is 4 MOSI command bytes, followed by
    //4 MISO data bytes. Total message length is 8
    //Sensor 20

    spi.xcvrs[1].csport = gpio::PortD;
    spi.xcvrs[1].cspin = 3;

    spi.mastertx(1, tx, rx, 8);

    while(spi.xcvrs[1].transmitting);


    // Initialize SPI module 1 as master
    //SPI module 1 controls sensors 11-20
    spi.initMaster(0, &mconf);



    //Configure PortB and pin 6, followed by Create tx/rx arrays:
    //Anticipated command is 4 MOSI command bytes, followed by
    //4 MISO data bytes. Total message length is 8
    //Sensor 1

    spi.xcvrs[0].csport = gpio::PortB;
    spi.xcvrs[0].cspin = 5;

    spi.mastertx(0, tx, rx, 8);

    while(spi.xcvrs[0].transmitting);



    //Configure PortB and pin 6, followed by Create tx/rx arrays:
    //Anticipated command is 4 MOSI command bytes, followed by
    //4 MISO data bytes. Total message length is 8
    //Sensor 2

    spi.xcvrs[0].csport = gpio::PortC;
    spi.xcvrs[0].cspin = 3;

    spi.mastertx(0, tx, rx, 8);

    while(spi.xcvrs[0].transmitting);



    //Configure PortB and pin 6, followed by Create tx/rx arrays:
    //Anticipated command is 4 MOSI command bytes, followed by
    //4 MISO data bytes. Total message length is 8
    //Sensor 3

    spi.xcvrs[0].csport = gpio::PortD;
    spi.xcvrs[0].cspin = 7;

    spi.mastertx(0, tx, rx, 8);

    while(spi.xcvrs[0].transmitting);

    //Configure PortB and pin 6, followed by Create tx/rx arrays:
    //Anticipated command is 4 MOSI command bytes, followed by
    //4 MISO data bytes. Total message length is 8
    //Sensor 4

    spi.xcvrs[0].csport = gpio::PortD;
    spi.xcvrs[0].cspin = 5;

    spi.mastertx(0, tx, rx, 8);

    while(spi.xcvrs[0].transmitting);



    //Configure PortB and pin 6, followed by Create tx/rx arrays:
    //Anticipated command is 4 MOSI command bytes, followed by
    //4 MISO data bytes. Total message length is 8
    //Sensor 5

    spi.xcvrs[0].csport = gpio::PortC;
    spi.xcvrs[0].cspin = 0;

    spi.mastertx(0, tx, rx, 8);

    while(spi.xcvrs[0].transmitting);



    //Configure PortB and pin 6, followed by Create tx/rx arrays:
    //Anticipated command is 4 MOSI command bytes, followed by
    //4 MISO data bytes. Total message length is 8
    //Sensor 6

    spi.xcvrs[0].csport = gpio::PortC;
    spi.xcvrs[0].cspin = 16;

    spi.mastertx(0, tx, rx, 8);

    while(spi.xcvrs[0].transmitting);


    //Configure PortB and pin 6, followed by Create tx/rx arrays:
    //Anticipated command is 4 MOSI command bytes, followed by
    //4 MISO data bytes. Total message length is 8
    //Sensor 7

    spi.xcvrs[0].csport = gpio::PortC;
    spi.xcvrs[0].cspin = 14;

    spi.mastertx(0, tx, rx, 8);

    while(spi.xcvrs[0].transmitting);

    //Configure PortB and pin 6, followed by Create tx/rx arrays:
    //Anticipated command is 4 MOSI command bytes, followed by
    //4 MISO data bytes. Total message length is 8
    //Sensor 8  

    spi.xcvrs[0].csport = gpio::PortC;
    spi.xcvrs[0].cspin = 9;

    spi.mastertx(0, tx, rx, 8);

    while(spi.xcvrs[0].transmitting);


    //Configure PortB and pin 6, followed by Create tx/rx arrays:
    //Anticipated command is 4 MOSI command bytes, followed by
    //4 MISO data bytes. Total message length is 8
    //Sensor 9

    spi.xcvrs[0].csport = gpio::PortA;
    spi.xcvrs[0].cspin = 7;

    spi.mastertx(0, tx, rx, 8);

    while(spi.xcvrs[0].transmitting);



    //Configure PortB and pin 6, followed by Create tx/rx arrays:
    //Anticipated command is 4 MOSI command bytes, followed by
    //4 MISO data bytes. Total message length is 8
    //Sensor 10

    spi.xcvrs[0].csport = gpio::PortE;
    spi.xcvrs[0].cspin = 7;

    spi.mastertx(0, tx, rx, 8);

    while(spi.xcvrs[0].transmitting);

    flag = 1;


    while(1) {

        if(flag){
            // do a thing


            //transmit ones and log rx buffer into data array 
            //sensor 12
            spi.xcvrs[1].csport = gpio::PortE;
            spi.xcvrs[1].cspin = 9;

            spi.mastertx(1, tx+5, rx, 3);
            while(spi.xcvrs[1].transmitting);
            data[11] = rx[2] + (rx[1] << 8) + (rx[0] <<16);

            sendcan(11, data[11]);

            //transmit ones and log rx buffer into data array 
            //sensor 11
            spi.xcvrs[1].csport = gpio::PortD;
            spi.xcvrs[1].cspin = 16;

            spi.mastertx(1, tx+5, rx, 3);
            while(spi.xcvrs[1].transmitting);
            data[10] = rx[2] + (rx[1] << 8) + (rx[0] <<16);

            sendcan(10, data[10]);


            //transmit ones and log rx buffer into data array 
            //sensor 13
            spi.xcvrs[1].csport = gpio::PortB;
            spi.xcvrs[1].cspin = 6;

            spi.mastertx(1, tx+5, rx, 3);
            while(spi.xcvrs[1].transmitting);
            data[12] = rx[2] + (rx[1] << 8) + (rx[0] <<16);

            sendcan(12, data[12]);

            //transmit ones and log rx buffer into data array 
            //sensor 14
            spi.xcvrs[1].csport = gpio::PortE;
            spi.xcvrs[1].cspin = 10;

            spi.mastertx(1, tx+5, rx, 3);
            while(spi.xcvrs[1].transmitting);
            data[13] = rx[2] + (rx[1] << 8) + (rx[0] <<16);

            sendcan(13, data[13]);

            //transmit ones and log rx buffer into data array 
            //sensor 15
            spi.xcvrs[1].csport = gpio::PortE;
            spi.xcvrs[1].cspin = 1;

            spi.mastertx(1, tx+5, rx, 3);
            while(spi.xcvrs[1].transmitting);
            data[14] = rx[2] + (rx[1] << 8) + (rx[0] <<16);

            sendcan(14, data[14]);

            //transmit ones and log rx buffer into data array 
            //sensor 16
            spi.xcvrs[1].csport = gpio::PortE;
            spi.xcvrs[1].cspin = 2;

            spi.mastertx(1, tx+5, rx, 3);
            while(spi.xcvrs[1].transmitting);
            data[15] = rx[2] + (rx[1] << 8) + (rx[0] <<16);

            sendcan(15, data[15]);

            //transmit ones and log rx buffer into data array 
            //sensor 17
            spi.xcvrs[1].csport = gpio::PortE;
            spi.xcvrs[1].cspin = 6;

            spi.mastertx(1, tx+5, rx, 3);
            while(spi.xcvrs[1].transmitting);
            data[16] = rx[2] + (rx[1] << 8) + (rx[0] <<16);

            sendcan(16, data[16]);


            //transmit ones and log rx buffer into data array 
            //sensor 18
            spi.xcvrs[1].csport = gpio::PortC;
            spi.xcvrs[1].cspin = 7;

            spi.mastertx(1, tx+5, rx, 3);
            while(spi.xcvrs[1].transmitting);
            data[17] = rx[2] + (rx[1] << 8) + (rx[0] <<16);

            sendcan(17, data[17]);

            //transmit ones and log rx buffer into data array 
            //sensor 19
            spi.xcvrs[1].csport = gpio::PortA;
            spi.xcvrs[1].cspin = 1;

            spi.mastertx(1, tx+5, rx, 3);
            while(spi.xcvrs[1].transmitting);
            data[18] = rx[2] + (rx[1] << 8) + (rx[0] <<16);

            sendcan(18, data[18]);

            //transmit ones and log rx buffer into data array 
            //sensor 20
            spi.xcvrs[1].csport = gpio::PortD;
            spi.xcvrs[1].cspin = 3;

            spi.mastertx(1, tx+5, rx, 3);
            while(spi.xcvrs[1].transmitting);
            data[19] = rx[2] + (rx[1] << 8) + (rx[0] <<16);

            sendcan(19, data[19]);

            //transmit ones and log rx buffer into data array 
            //sensor 1
            spi.xcvrs[0].csport = gpio::PortB;
            spi.xcvrs[0].cspin = 5;

            spi.mastertx(0, tx+5, rx, 3);
            while(spi.xcvrs[0].transmitting);
            data[0] = rx[2] + (rx[1] << 8) + (rx[0] <<16);

            sendcan(0, data[0]);

            //transmit ones and log rx buffer into data array 
            //sensor 2
            spi.xcvrs[0].csport = gpio::PortC;
            spi.xcvrs[0].cspin = 3;

            spi.mastertx(0, tx+5, rx, 3);
            while(spi.xcvrs[0].transmitting);
            data[1] = rx[2] + (rx[1] << 8) + (rx[0] <<16);

            sendcan(1, data[1]);


            //transmit ones and log rx buffer into data array 
            //sensor 3
            spi.xcvrs[0].csport = gpio::PortD;
            spi.xcvrs[0].cspin = 7;

            spi.mastertx(0, tx+5, rx, 3);
            while(spi.xcvrs[0].transmitting);
            data[2] = rx[2] + (rx[1] << 8) + (rx[0] <<16);

            sendcan(2, data[2]);

            //transmit ones and log rx buffer into data array 
            //sensor 4
            spi.xcvrs[0].csport = gpio::PortD;
            spi.xcvrs[0].cspin = 5;

            spi.mastertx(0, tx+5, rx, 3);
            while(spi.xcvrs[0].transmitting);
            data[3] = rx[2] + (rx[1] << 8) + (rx[0] <<16);

            sendcan(3, data[3]);

            //transmit ones and log rx buffer into data array 
            //sensor 5
            spi.xcvrs[0].csport = gpio::PortC;
            spi.xcvrs[0].cspin = 0;

            spi.mastertx(0, tx+5, rx, 3);
            while(spi.xcvrs[0].transmitting);
            data[4] = rx[2] + (rx[1] << 8) + (rx[0] <<16);

            sendcan(4, data[4]);

            //transmit ones and log rx buffer into data array 
            //sensor 6
            spi.xcvrs[0].csport = gpio::PortC;
            spi.xcvrs[0].cspin = 16;

            spi.mastertx(0, tx+5, rx, 3);
            while(spi.xcvrs[0].transmitting);
            data[5] = rx[2] + (rx[1] << 8) + (rx[0] <<16);

            sendcan(5, data[5]);

            //transmit ones and log rx buffer into data array 
            //sensor 7
            spi.xcvrs[0].csport = gpio::PortC;
            spi.xcvrs[0].cspin = 14;

            spi.mastertx(0, tx+5, rx, 3);
            while(spi.xcvrs[0].transmitting);
            data[6] = rx[2] + (rx[1] << 8) + (rx[0] <<16);

            sendcan(6, data[6]);
            //transmit ones and log rx buffer into data array 
            //sensor 8
            spi.xcvrs[0].csport = gpio::PortC;
            spi.xcvrs[0].cspin = 9;

            spi.mastertx(0, tx+5, rx, 3);
            while(spi.xcvrs[0].transmitting);
            data[7] = rx[2] + (rx[1] << 8) + (rx[0] <<16);

            sendcan(7, data[7]);

            //transmit ones and log rx buffer into data array 
            //sensor 9
            spi.xcvrs[0].csport = gpio::PortA;
            spi.xcvrs[0].cspin = 7;

            spi.mastertx(0, tx+5, rx, 3);
            while(spi.xcvrs[0].transmitting);
            data[8] = rx[2] + (rx[1] << 8) + (rx[0] <<16);

            sendcan(8, data[8]);
            //transmit ones and log rx buffer into data array 
            //sensor 10
            spi.xcvrs[0].csport = gpio::PortE;
            spi.xcvrs[0].cspin = 7;

            spi.mastertx(0, tx+5, rx, 3);
            while(spi.xcvrs[0].transmitting);
            data[9] = rx[2] + (rx[1] << 8) + (rx[0] <<16);

            sendcan(9, data[9]);

            flag = 0;
        }
    }
    return 0;
}

extern "C" {
    void SysTick_Handler(void){
        static uint16_t timer = 0;
        timer++;
        if(timer == PERIOD){
            flag = 1;
            timer = 0;
        }
    }
}
