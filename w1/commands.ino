/* commands.ino, w1 Mark I - Watch Winder, Arduino commands sketch file
 * 
 * Author: Márcio Pessoa <marcio.pessoa@sciemon.com>
 * Contributors: none
 */

/* CommandM100
 * 
 * Description
 *   Shows help messages.
 * 
 *   CommandM100()
 * 
 * Parameters
 *   letter: The command initial letter. It's used to display a specific help
 *           about a letter.
 *           If letter equals to zero, all help messages will be shown.
 * 
 * Returns
 *   void
 */
void CommandM100(char letter = 0) {
  if (letter == 'M' or letter == 0) {
    echoln(F("M0\tCompulsory stop"));
    echoln(F("M1\tForward and speed"));
    echoln(F("M2\tBackward and speed"));
    echoln(F("M3\tShow motor speed"));
    echoln(F("M15\tSystem info"));
    echoln(F("M89\tMemory information"));
    echoln(F("M92\tSystem information"));
    echoln(F("M99\tReset system"));
    echoln(F("M100\tThis help message"));
    echoln(F("M111\tDebug mode"));
  }
}

/* CommandM0
 * 
 * Description
 *   Compulsory stop.
 * 
 *   CommandM0()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   bool
 */
bool CommandM0() {
  motor.stop();
  return false;
}

/* CommandM1
 * 
 * Description
 *   Forward and speed.
 * 
 *   CommandM1(100)
 * 
 * Parameters
 *   speed: axis speed.
 * 
 * Returns
 *   false: OK
 *   true: Position limit has exceeded
 */
bool CommandM1(float speed) {
  if ((speed != FLIMIT) and (speed >= 0 and speed <= 100)) {
    motor_speed = speed;
  }
  motor.direct(motor_speed);
  return false;
}

/* CommandM2
 * 
 * Description
 *   Backward and speed.
 * 
 *   CommandM2(100)
 * 
 * Parameters
 *   speed: axis speed.
 * 
 * Returns
 *   false: OK
 *   true: Position limit has exceeded
 */
bool CommandM2(float speed) {
  if ((speed != FLIMIT) and (speed >= 0 and speed <= 100)) {
    motor_speed = speed;
  }
  motor.reverse(motor_speed);
  return false;
}

/* CommandM3
 * 
 * Description
 *   Backward and speed.
 * 
 *   CommandM2(100)
 * 
 * Parameters
 *   speed: axis speed.
 * 
 * Returns
 *   false: OK
 *   true: Position limit has exceeded
 */
bool CommandM3() {
  echo("Motor speed: " + String(motor_speed));
  if (debug_mode) {
    echo(" %");
  }
  echoln("");
  return motor_speed;
}

/* 
 * 
 * Description
 *   .
 * 
 *   ()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   void
 */
void CommandM99() {
  echoln("Reseting...\n");
  CommandM0();
  w1.reset();
}

/* CommandM89
 * 
 * Description
 *   Memory information.
 * 
 *   ()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   void
 */
bool CommandM89() {
  int total = 2 * 1024;
  int free = freeMemory();
  int used = total - free;
  int percent = (float)used * 100 / total;
  // 
  Alarm memory(75, 85);
  memory.nameWrite("Memory");
  memory.unitWrite("%");
  memory.check(percent);
  // 
  echoln(memory.nameRead() + " (" + memory.status_name() + "): " + 
         percent + memory.unitRead() + " used");
  if (debug_mode) {
    echoln("  SRAM:\t" + String(total) + " B\n" +
           "  Used:\t" + used + " B\n" +
           "  Free:\t" + free + " B\n" +
           "  Warning: " + memory.max_warningRead() + memory.unitRead() + "\n" +
           "  Critical: " + memory.max_criticalRead() + memory.unitRead());
  }
}

/* 
 * 
 * Description
 *   .
 * 
 *   ()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   void
 */
void CommandM15() {
  CommandM92();  // System information
  CommandM89();  // Memory information
  CommandM3();  // Motor speed
}

/* 
 * 
 * Description
 *   System information.
 * 
 *   ()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   void
 */
void CommandM92() {
  echoln(w1.version());
  if (debug or (millis() < 100)) {
    echoln(w1.owner());
    echoln(w1.compiled());
    echoln(w1.license());
    echoln(w1.website());
    echoln(w1.contact());
  }
}

/* CommandM111
 * 
 * Description
 *   Changes debug mode on or off.
 * 
 *   CommandM111()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   void
 */
void CommandM111() {
  debug_mode = !debug_mode;
  echoln("DEBUG: " + String(debug_mode ? F("on") : F("off")));
}

/* 
 * 
 * Description
 *   .
 * 
 *   ()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   void
 */
void Command0() {
  echoln(F("Unknown command")); 
}
