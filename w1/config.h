/* config.h, w1 Mark I - Watch Winder, Arduino project config file
 * 
 * Author: Márcio Pessoa <marcio.pessoa@sciemon.com>
 * Contributors: none
 */

// LED
const byte led_status_pin = 13;
const byte led_R_pin = 9;
const byte led_G_pin = 10;
const byte led_B_pin = 11;

// Motor
const byte in1_pin = 5;
const byte in2_pin = 6;
float motor_speed = 53;  // percent
const byte speed_sensor_pin = 0;  // pin: Digital 2
const byte addr_turns = 0;  // EEPROM Address to store turns

// Door
const byte door_sensor_pin = 1  // pin: Digital 3

// Infrared distance measuring sensor
const byte idms_pin = 0;

// Random number generator Seed pin
const byte random_Seed_pin = 5;

// Timers
const byte health_check_timer = 2;  // seconds
const byte sensors_timer = 0.5;  // seconds

// Debug mode
bool debug_mode = false;

// Serial speed: 4800, 9600, 14400, 19200, 28800, 38400, 57600, 115200
const unsigned long serial_speed = 115200;

// 
const float FLIMIT = 340282350000000000000000000000000000000;
