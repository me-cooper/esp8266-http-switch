# esp8266-http-switch
A simple esp8266 with three links for: ON / OFF and STATE

YouTube-Video: https://studio.youtube.com/video/t9-ywg3ClT8/edit

Diese Zeilen müssen vor dem Upload bearbeitet werden:

```c++

const char* ssid = "WLAN_SSID";
const char* password = "WLAN_PASSWORD";

```

Der ESP ist erreichbar unter folgenden links
* http://esp8266.local/relay_on - Schaltet das Relais an
* http://esp8266.local/relay_off -  Schlatet das Relais aus
* http://esp8266.local/state - Zeigt den Schaltzustand des Relais 0 / 1


Die Signalleitung des Relaismoduls kommt an D1.

```c++
int relay_pin = 5; //D1
```

Hier nochmal alle Pins mit den dazugehörigen Nummern.
https://github.com/makesmartnet/esp8266-pin-definitions



Diesen Schalter in Homekit einbinden:
https://github.com/makesmartnet/homebridge-http-switch-example
https://www.youtube.com/watch?v=MWYLtgmZU5k
