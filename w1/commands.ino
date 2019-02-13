/* commands.ino, w1 Mark I - Watch Winder, Arduino commands sketch file
 *
 * Author: Márcio Pessoa <marcio.pessoa@gmail.com>
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
bool CommandM100(char letter = 0) {
  if (letter == 'M' or letter == 0) {
    echoln(F("G28\t"));
    echoln(F("M0\tCompulsory stop"));
    echoln(F("M1\tClockwise and speed"));
    echoln(F("M2\tCounterclockwise and speed"));
    echoln(F("M3\tShow rotor direction and speed"));
    //echoln(F("M4\tShow total rotor turns"));
    echoln(F("M15\tSystem information"));
    echoln(F("M89\tMemory information"));
    echoln(F("M92\tSystem version"));
    echoln(F("M99\tReset system"));
    echoln(F("M100\tThis help message"));
    echoln(F("M111\tDebug mode"));
    echoln(F("S\tSet speed"));
  }
  return false;
}

/* CommandG28
 *
 * Description
 *   Gracefully stop.
 *
 *   CommandG28()
 *
 * Parameters
 *   none
 *
 * Returns
 *   bool
 */
bool CommandG28() {
  CommandM0();
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
  motor.stopA();
  return false;
}

/* CommandM1
 *
 * Description
 *   Clockwise and speed.
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
  // When speed is omitted, only set direction
  if (speed == FLIMIT) {
    speed = round(100 * motor.getDeltaA() / 255);
  }
  // Check user defined speed
  if (speed < 0 or speed > 100) {
    return true;
  }
  motor.directA((float)255 * speed / 100);
  return false;
}

/* CommandM2
 *
 * Description
 *   Counterclockwise and speed.
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
  // When speed is omitted, only set direction
  if (speed == FLIMIT) {
    speed = round(100 * motor.getDeltaA() / 255);
  }
  // Check user defined speed
  if (speed < 0 or speed > 100) {
    return true;
  }
  motor.reverseA((float)255 * speed / 100);
  return false;
}

/* CommandM3
 *
 * Description
 *   Show motor direction and speed.
 *
 *   CommandM3()
 *
 * Parameters
 *   none
 *
 * Returns
 *   false: OK
 *   true: Position limit has exceeded
 */
bool CommandM3() {
  echoln("Rotor direction: " +
    String(motor.getDirectionA() ? "Clockwise" : "Counterclockwise"));
  echo("Rotor speed: " + String(round(100 * motor.getDeltaA() / 255)) + "%");
  if (debug_mode) {
    echo(" %");
  }
  echoln("");
  return false;
}

/* CommandM4
 *
 * Description
 *   Show total rotor turns.
 *
 *   CommandM4()
 *
 * Parameters
 *   none
 *
 * Returns
 *   void
 */
bool CommandM4() {
  //echo("Total rotor turns: " + String(totalTurnCount()));
  return false;
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
bool CommandM99() {
  echoln("Reseting...\n");
  CommandM0();
  w1.reset();
  return false;
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
  int total = 2.5 * 1024;
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
bool CommandM15() {
  CommandM92();  // System information
  CommandM89();  // Memory information
  CommandM4();  // Total rotor turns
  CommandM3();  // Rotor speed
  return false;
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
bool CommandM92() {
  echoln(w1.version());
  if (debug or (millis() < 100)) {
    echoln(w1.owner());
    echoln(w1.compiled());
    echoln(w1.license());
    echoln(w1.website());
    echoln(w1.contact());
  }
  return false;
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
bool CommandM111() {
  debug_mode = !debug_mode;
  echoln("DEBUG: " + String(debug_mode ? F("on") : F("off")));
  return false;
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
bool Command0() {
  echoln(F("Unknown command"));
  return true;
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
bool CommandS(float speed) {
  if (speed < 0 or speed > 100) {
    return true;
  }
  motor.setDeltaA((float)255 * speed / 100);
  return false;
}
