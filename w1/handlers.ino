/* handlers.ino, w1 Mark I - Watch Winder, Arduino handlers sketch file
 * 
 * Author: Márcio Pessoa <marcio.pessoa@gmail.com>
 * Contributors: none
 */

bool AxesHandler() {
}

void DemonstrationHandler() {
}

void HealthCheckHandler() {
}

void NotificationHandler() {
  analogWrite(led_status_pin, wave.sine() * 255);
}

void PowerHandler() {
}

void SensorsHandler() {
}
