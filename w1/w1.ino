/* w1.ino, w1 Mark I - Watch Winder, Arduino main sketch file
 * 
 * This sketch was developed and tested on: Arduino Leonardo
 * To work on other Arduino models, some adaptations may be necessary.
 * 
 * Author: Márcio Pessoa <marcio.pessoa@sciemon.com>
 * Contributors: none
 */

#include <Arduino.h>         // Arduino - Main library
#include <EEPROM.h>          // Arduino - EEPROM library
#include <Project.h>         // Sciemon - Basic project definitions
#include <Blinker.h>         // Sciemon - Blink leds nicely
#include <Timer.h>           // Sciemon - Timer with nice features
#include <RGB.h>             // Sciemon - RGB LED controller
#include <SigGen.h>          // Sciemon - Signal Generator
#include <Alarm.h>           // Sciemon - Manage alarms
#include <L298.h>            // Sciemon - L298 DC motor control
#include <IDMS.h>            // Sciemon - Infrared distance measuring
#include "config.h"          // Sciemon - Configuration
#include <MemoryFree.h>      // 

// Project definitions
Project w1("w1",  // Platform
           "I",  // Mark
           "Watch Winder",  // Name
           "0.0b",  // Version
           "2017-11-13",  // Version date
           "7",  // Serial number
           "Copyright (c) 2017-2017 Marcio Pessoa",  // Owner
           "undefined. There is NO WARRANTY.",  // License
           "http://pessoa.eti.br/",  // Website
           "Marcio Pessoa <marcio.pessoa@sciemon.com>");  // Contact

// OK LED (Status LED)
Blinker status_led(led_status_pin);

// Check timer
Timer health_check(health_check_timer * 1000);

// Sensors timer
Timer sensors_status(sensors_timer * 1000);

// Infrared distance measuring sensor
IDMS ir_sensor;

// Axis
L298 motor;

void setup() {
  // Serial interface
  Serial.begin(serial_speed);
  // Start up message
  CommandM92();  // System information
  pinMode(speed_sensor_pin, INPUT_PULLUP);
  attachInterrupt(speed_sensor_pin, spinCounter, RISING);
  // Motor
  motor.attach(in1_pin, in2_pin);
  CommandM1(motor_speed);  // Run motor clockwise at default speed
  // Infrared distance measuring sensor
  ir_sensor.attach(idms_pin);
  // Random number generator seed
  pinMode(random_Seed_pin, INPUT);
  randomSeed(analogRead(random_Seed_pin));
  // G-code ready to receive commands
  GcodeReady();
}

void loop() {
  SensorsHandler();
  HealthCheckHandler();
  // NotificationHandler();
  AxesHandler();
  DemonstrationHandler();
  PowerHandler();
  GcodeCheck();
}
