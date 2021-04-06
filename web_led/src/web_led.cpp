/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/duvaldi/Desktop/web_led/web_led/src/web_led.ino"
/*
 * Project web_led
 * Description:
 * Author:
 * Date:
 */
int ledToggle(String command);
void setup();
void loop();
#line 7 "/Users/duvaldi/Desktop/web_led/web_led/src/web_led.ino"
const pin_t GREEN_LED = D4;
const pin_t BLUE_LED = D3;
const pin_t RED_LED = D2;

SYSTEM_THREAD(ENABLED);

// This function is called when the Particle.function is called
int ledToggle(String command)
{
    if (command.equals("green"))
    {
        digitalWrite(GREEN_LED, HIGH);
        digitalWrite(RED_LED, LOW);
        digitalWrite(BLUE_LED, LOW);
        return 1;
    }
    else if (command.equals("blue"))
    {
        digitalWrite(BLUE_LED, HIGH);
        digitalWrite(RED_LED, LOW);
        digitalWrite(GREEN_LED, LOW);
        return 1;
    }
    else if (command.equals("red"))
    {
        digitalWrite(RED_LED, HIGH);
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(BLUE_LED, LOW);
        return 1;
    }
    else if (command.equals("off"))
    {
        digitalWrite(RED_LED, LOW);
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(BLUE_LED, LOW);
        return 0;
    }
    else
    {
        // Unknown option
        return -1;
    }
}

// The setup() method is called once when the device boots.
void setup()
{
    // 3 leds as output pins
    pinMode(RED_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);

    // This registers a function call. When the function "led"
    // is called from the cloud, the ledToggle() function above
    // will be called.
    Particle.function("led", ledToggle);
}

void loop()
{
}