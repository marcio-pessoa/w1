/* config.h, w1 Mark I - Watch Winder, Arduino project config file
 * 
 * Author: Márcio Pessoa <marcio.pessoa@gmail.com>
 * Contributors: none
 */

// LED
const byte led_status_pin = 13;

// Motor
const byte in1_pin = 5;
const byte in2_pin = 6;
byte motor_speed = 75;  // percent

// Timers
const byte health_check_timer = 2;  // seconds
const byte sensors_timer = 0.5;  // seconds

// Spin sensor
const byte spin_sensor_pin = 1;  // pin: Digital 3
const byte spin_sensor_vcc_pin = 2;
const byte spin_sensor_gnd_pin = 4;

// Debug mode
bool debug_mode = false;

// Serial speed: 4800, 9600, 14400, 19200, 28800, 38400, 57600, 115200
const unsigned long serial_speed = 9600;

// 
const int FLIMIT = 32767;
