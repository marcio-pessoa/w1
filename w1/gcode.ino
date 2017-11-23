/* gcode.ino, w1 Mark I - Watch Winder, G-code parser sketch file
 * 
 * Author: Márcio Pessoa <marcio.pessoa@sciemon.com>
 * Contributors: none
 */

#define BUFFER_SIZE 48

char buffer[BUFFER_SIZE];
int buffer_pointer = 0;

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
bool echo(String message) {
  Serial.print(String(message));
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
bool echoln(String message) {
  echo(message + "\n");
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
void debug(String message) {
  if (debug_mode) {
    echo(message);
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
void debugln(String message) {
  if (debug_mode) {
    echoln(message);
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
void status(bool i) {
  echoln(i == false ? F("ok") : F("nok"));
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
void GcodeReady() {
  buffer_pointer = 0;
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
void GcodeCheck() {
  while (Serial.available() > 0) {
    char c = Serial.read();
    if (buffer_pointer < BUFFER_SIZE-1) {
      buffer[buffer_pointer++] = c;
    }
    if (c == '\n') {
      buffer[buffer_pointer] = 0;
      GCodeParse();
      GcodeReady();
    }
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
float GCodeNumber(char code, float val) {
  char *ptr = buffer;
  while(ptr && *ptr && ptr < buffer + buffer_pointer) {
    if(*ptr == code) {
      return atof(ptr + 1);
    }
    ptr = strchr(ptr, ' ') + 1;
  }
  return val;
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
void GCodeParse() {
  bool retval = false;
  bool skip_status = false;
  char letter = buffer[0];
  byte number = GCodeNumber(letter, -1);
  switch (letter) {
    case 'M':
      switch(number) {
        case 0:
          retval = CommandM0();
          break;
        case 1:
          retval = CommandM1(GCodeNumber('S', FLIMIT));
          break;
        case 2:
          retval = CommandM2(GCodeNumber('S', FLIMIT));
          break;
        case 3:
          CommandM3();
          break;
        case 15:
          CommandM15();
          break;
        case 92:
          CommandM92();
          break;
        case 99:
          CommandM99();
          break;
        case 100:
          CommandM100();
          break;
        case 111:
          CommandM111();
          break;
        default:
          Command0();
          break;
      }
      break;
    default:
      if (buffer_pointer > 2) {
        Command0();
      }
      break;
  }
  if (buffer_pointer > 2 and skip_status == false) {
    status(retval);
  }
}
