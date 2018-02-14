/* auxiliar.ino, w1 Mark I - Watch Winder, Arduino auxiliar sketch file
 * 
 * Author: Márcio Pessoa <marcio.pessoa@sciemon.com>
 * Contributors: none
 */

int rpm = 0;  // RPM (Rotations Per Minute)
int rph = 0;  // RPH (Rotations Per Hour)
int rpd = 0;  // RPD (Rotations Per Day)
int delta_t = 0;
int resolution = 10;
byte counter_turn = 0;
unsigned long timer = millis();

/* spinCounter
 * 
 * Description
 *   Motor spin counter.
 * 
 *   spinCounter()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   void
 */
void spinCounter() {
  counter_turn++;
  if (counter_turn >= resolution) {
    // Calculate speed
    delta_t = millis() - timer;
    rpm = (float)counter_turn / delta_t * 1000 * 60;
    rph = rpm * 60;
    rpd = rph * 24;
    timer = millis();
    counter_turn = 0;
  }
  // Store turns in EEPROM
  recordData();
}

/* parkRotor
 * 
 * Description
 *   Park rotor.
 * 
 *   parkRotor()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   void
 */
void parkRotor() {
  CommandG28();  // Gracefully stop
}

/* recordData
 * 
 * Description
 *   Record rotor turns in EEPROM.
 * 
 *   recordData()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   void
 */
void recordData() {
  byte new_turn_count = counter_turn;
  byte new_turn_count_1 = 0;
  byte new_turn_count_2 = 0;
  byte new_turn_count_3 = 0;
  byte new_turn_count_4 = 0;
  // Increment counter
  if (new_turn_count == 255) {
    new_turn_count = 0;
    new_turn_count_1++;
  }
  if (new_turn_count_1 == 255) {
    new_turn_count_1 = 0;
    new_turn_count_2++;
  }
  if (new_turn_count_2 == 255) {
    new_turn_count_2 = 0;
    new_turn_count_3++;
  }
  if (new_turn_count_3 == 255) {
    new_turn_count_3 = 0;
    new_turn_count_4++;
  }
  // Write data in EEPROM
  if (turn_count != new_turn_count) {
    turn_count = new_turn_count;
    EEPROM.write(addr_turn_count, turn_count);
  }
  if (turn_count_1 != new_turn_count_1) {
    turn_count_1 = new_turn_count_1;
    EEPROM.write(addr_turn_count_1, turn_count_1);
  }
  if (turn_count_2 != new_turn_count_2) {
    turn_count_2 = new_turn_count_2;
    EEPROM.write(addr_turn_count_2, turn_count_2);
  }
  if (turn_count_3 != new_turn_count_3) {
    turn_count_3 = new_turn_count_3;
    EEPROM.write(addr_turn_count_3, turn_count_3);
  }
  if (turn_count_4 != new_turn_count_4) {
    turn_count_4 = new_turn_count_4;
    EEPROM.write(addr_turn_count_4, turn_count_4);
  }
}

/* totalTurnCount
 * 
 * Description
 *   Return total rotor turns.
 * 
 *   totalTurnCount()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   float
 */
float totalTurnCount() {
  return turn_count + 255 *
         turn_count_1 * turn_count_2 * turn_count_3 * turn_count_4;
}
