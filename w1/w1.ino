/* w1.ino, w1 Mark I - Watch Winder, Arduino main sketch file
 *
 * This sketch was developed and tested on: Arduino Leonardo
 * To work on other Arduino models, some adaptations may be necessary.
 *
 * Author: Márcio Pessoa <marcio.pessoa@gmail.com>
 * Contributors: none
 */

#include <Arduino.h>         // Arduino - Main library
#include <Project.h>         // Marcio Pessoa - Basic project definitions
#include <Timer.h>           // Marcio Pessoa - Timer with nice features
#include <SigGen.h>          // Marcio Pessoa - Signal Generator
#include <Alarm.h>           // Marcio Pessoa - Manage alarms
#include <L298.h>            // Marcio Pessoa - L298 DC motor control
#include "config.h"          // Marcio Pessoa - Configuration
#include <MemoryFree.h>      //

// Project definitions
Project w1("w1",  // Platform
           "I",  // Mark
           "Watch Winder",  // Name
           "0.4",  // Version
           "2019-02-12",  // Version date
           "7",  // Serial number
           "Copyright (c) 2017-2019 Marcio Pessoa",  // Owner
           "undefined. There is NO WARRANTY.",  // License
           "https://github.com/marcio-pessoa/w1",  // Website
           "Marcio Pessoa <marcio.pessoa@gmail.com>");  // Contact

// LEDs
SigGen wave;

// Check timer
Timer health_check(health_check_timer * 1000);

// Sensors timer
Timer sensors_status(sensors_timer * 1000);

// Axis
L298 motor;

void setup() {
  // Serial interface
  Serial.begin(serial_speed);
  // Start up message
  CommandM92();  // System information
  // Status LED
  pinMode(led_status_pin, OUTPUT);
  analogWrite(led_status_pin, LOW);
  // Motor
  motor.attach(in1_pin, in2_pin);
  CommandM2(motor_speed);  // Run rotor counterclockwise at default speed
  // Spin sensor
  pinMode(spin_sensor_vcc_pin, OUTPUT);
  pinMode(spin_sensor_gnd_pin, OUTPUT);
  digitalWrite(spin_sensor_vcc_pin, HIGH);
  digitalWrite(spin_sensor_gnd_pin, LOW);
  pinMode(spin_sensor_pin, INPUT_PULLUP);
  attachInterrupt(spin_sensor_pin, spinCounter, RISING);
  // G-code ready to receive commands
  GcodeReady();
}

void loop() {
  SensorsHandler();
  HealthCheckHandler();
  NotificationHandler();
  AxesHandler();
  DemonstrationHandler();
  PowerHandler();
  GcodeCheck();
}
