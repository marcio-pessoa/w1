/* config.h, w1 Mark I - Watch Winder, Arduino project config file
 * 
 * Author: Márcio Pessoa <marcio.pessoa@sciemon.com>
 * Contributors: none
 */

// LED
const byte led_ok_pin = 13;
const byte led_warning_pin = 17;
const byte led_critical_pin = 16;

// Motor
#define FORWARD 1
#define BACKWARD 2
#define BRAKE 3
#define RELEASE 4
const byte speed_sensor_pin = 0;
byte motor_speed = 240;  // Ideal é entre 600 e 800 rotações por dia
byte motor_direction = FORWARD;

// Infrared distance measuring sensor
const byte idms_pin = 0;

// Random number generator Seed pin
const byte random_Seed_pin = 1;

// Timers
const byte health_check_timer = 2;  // seconds
const byte sensors_timer = 2;  // seconds
const byte standby_timer = 1;  // minute

// System status (initial state)
byte general_status = UNKNOWN;

// Debug mode
bool debug_mode = false;

// Serial speed: 4800, 9600, 14400, 19200, 28800, 38400, 57600, 115200
const unsigned long serial_speed = 115200;

// 
const float FLIMIT = 340282350000000000000000000000000000000;
