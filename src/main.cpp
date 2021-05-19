// ArduCAM demo with Wio Terminal

#include <Arduino.h>
#include "SD/Seeed_SD.h"
#include <Seeed_FS.h>
#include <SPI.h>
#include <Wire.h>

#include "arducam_ov2640_wio.h"

Camera camera = Camera(JPEG, OV2640_800x600);
bool capture = true;

void setup()
{
	Serial.begin(9600);

	while (!Serial)
		; // Wait for Serial to be ready

	delay(1000);

    Wire.begin();

    Serial.println("ArduCAM Start!");
    
    // set the SPI_CS as an output:
    pinMode(PIN_SPI_SS, OUTPUT);
    digitalWrite(PIN_SPI_SS, HIGH);
    
    // initialize SPI:
    SPI.begin();

    // Initialize the camera
    if (!camera.init())
    {
        Serial.println("ArduCAM Error!");
        capture = false;
    }

    // Initialize SD Card
    while (!SD.begin(SDCARD_SS_PIN, SDCARD_SPI))
    {
        Serial.println(F("SD Card Error"));
        capture = false;
    }

    Serial.println(F("SD Card detected!"));
}

void loop()
{
    if (capture)
    {
        Serial.println("Starting image capture...");

        camera.start_capture();
        
        Serial.println("Image capture started!");

        while (!camera.capture_ready())
            delay(100);

        Serial.println("Capture ready");

        byte *buffer;
        uint32_t length;

        Serial.println("Reading image to buffer...");
        if (camera.read_image_to_buffer(&buffer, length))
        {
            Serial.println("Image read to buffer!");
            Serial.println("Writing image to file...");

            File outFile = SD.open("1.jpg", FILE_WRITE );
            outFile.write(buffer, length);
            outFile.close();

            Serial.println("Image written to file!");
        }

        capture = false;
    }

    delay(100);
}
