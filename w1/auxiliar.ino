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
int counter_turn = 0;
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
  // Store turn in EEPROM
  int turns = EEPROM.read(addr_turns);
  EEPROM.write(addr_turns, turns++);
}
