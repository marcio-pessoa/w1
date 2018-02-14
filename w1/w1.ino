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
#include <Timer.h>           // Sciemon - Timer with nice features
#include <RGB.h>             // Sciemon - RGB LED controller
#include <SigGen.h>          // Sciemon - Signal Generator
#include <Alarm.h>           // Sciemon - Manage alarms
#include <L298.h>            // Sciemon - L298 DC motor control
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

// LEDs
SigGen wave;

// Check timer
Timer health_check(health_check_timer * 1000);

// Sensors timer
Timer sensors_status(sensors_timer * 1000);

// Axis
L298 motor;

// Turn counters
byte turn_count = 0;
byte turn_count_1 = 0;
byte turn_count_2 = 0;
byte turn_count_3 = 0;
byte turn_count_4 = 0;

void setup() {
  // Serial interface
  Serial.begin(serial_speed);
  // Start up message
  CommandM92();  // System information
  // Status LED
  pinMode(led_status_pin, OUTPUT);
  analogWrite(led_status_pin, LOW);
  // Rotor speed sensor
  pinMode(speed_sensor_pin, INPUT_PULLUP);
  attachInterrupt(speed_sensor_pin, spinCounter, RISING);
  // Door magnetic sensor
  pinMode(door_sensor_pin, INPUT_PULLUP);
  attachInterrupt(door_sensor_pin, parkRotor, RISING);
  // Motor
  motor.attach(in1_pin, in2_pin);
  CommandM1(motor_speed);  // Run motor clockwise at default speed
  // Random number generator seed
  pinMode(random_Seed_pin, INPUT);
  randomSeed(analogRead(random_Seed_pin));
  // Get data from EEPROM addresses
  turn_count = EEPROM.read(addr_turn_count);
  turn_count_1 = EEPROM.read(addr_turn_count_1);
  turn_count_2 = EEPROM.read(addr_turn_count_2);
  turn_count_3 = EEPROM.read(addr_turn_count_3);
  turn_count_4 = EEPROM.read(addr_turn_count_4);
  // Calculate total number of turns
  float total_turn_count = totalTurnCount();
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
