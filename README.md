# Wio Terminal ArduCAM

This repo shows how to use an ArduCAM OV2640 Camera Shield Rev 2.1 with an Wio Terminal from Seeed Studios.

## Hardware:

* [Wio Terminal](https://www.seeedstudio.com/Wio-Terminal-p-4509.html)
* [ArduCAM OV2640 2MP Plus](https://amzn.to/3fIVhjl)

The ArduCam comes with the cables you need to connect to the Wio Terminal.

Connect the following pins. Use the GPIO pins on the back of the Wio Terminal. The Wio Terminal should come with a sticker making pin identification easier.

| ArduCAM pin | Wio Terminal pin |
| ----------- | ---------------- |
| CS          | 24 (SPI_CS)      |
| MOSI        | 19 (SPI_MOSI)    |
| MISO        | 21 (SPI_MISO)    |
| SCK         | 23 (SPI_SCLK)    |
| GND         | 6 (GND)          |
| VCC         | 4 (5V)           |
| SDA         | 3 (I2C1_SDA)     |
| SCL         | 5 (I2C1_SCL)     |

This sample takes a single photo and saves it to an SD Card, in the root and called `1.jpg`. You will need to insert a FAT-32 formatted SD Card into the Wio Terminal, then once the image is taken, power it off and view the image by accessing the SD Card from another device.

## Software

The code here is designed to run using [PlatformIO](https://platformio.org) in [VS Code](https://code.visualstudio.com/?WT.mc_id=17441). You will also need to add the ArduCAM library as it is only available as source code.

* Clone the [ArduCAM GitHub repo](https://github.com/ArduCAM/Arduino), or download the latest source
* Copy the ArduCAM folder from that repo into the `lib` folder of this repo
* Open this repo in VS Code, build and deploy to your Wio Terminal
