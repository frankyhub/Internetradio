<a name="oben"></a>

<div align="center">

  |[:skull:ISSUE](https://github.com/frankyhub/Internetradio/issues?q=is%3Aissue)|[:speech_balloon: Forum /Discussion](https://github.com/frankyhub/Internetradio/discussions)|[:grey_question:WiKi](https://github.com/frankyhub/Internetradio/wiki)|
|--|--|--|
| | | |
|![GitHub issues](https://img.shields.io/github/issues/frankyhub/Internetradio)![GitHub closed issues](https://img.shields.io/github/issues-closed/frankyhub/Internetradio)|![GitHub Discussions](https://img.shields.io/github/discussions/frankyhub/Internetradio)|![GitHub release (with filter)](https://img.shields.io/github/v/release/frankyhub/Internetradio)|
|![GitHub closed pull requests](https://img.shields.io/github/issues-pr-closed/finaldie/skull.svg)[](https://github.com/frankyhub/Internetradio/pulls)|[<img src="https://img.shields.io/github/license/finaldie/skull.svg">](https://github.com/frankyhub/Internetradio/blob/main/LICENSE.md)| ![GitHub User's stars](https://img.shields.io/github/stars/frankyhub)|
</div>



# Internetradio
Internetradio mit WEB-Server, OTA-Funktion, TFT 1,88 oder LCD 4 Zeilen Display, digitales Amplifier Board MAX98357A

## Story
Das Internetradio steht mit einem  TFT 1,88" Display oder einem LCD 4x20 Display mit I2C Schnittstelle zur Verfügung.
Neben dem gerade gespielten Sender werden Datum und Uhrzeit, sowie die aktuelle Lautstärke angezeigt. 
In den beiden unteren Zeilen sind die Informationen zum laufenden Programm, die mit dem Audiostream mitgeschickt werden. 
Die Lautstärkeregelung erfolgt ebenso wie die Senderwahl über einen Rotary-Encoder. Die Konfiguration kann
auch über einen Browser erfolgen. Über diesen Weg ist die Senderliste veränder- und erweiterbar. 
Da nicht jede Sender-URL abspielbar ist, kann die URL über die Browserkonfiguration vor dem speichern vorab getestet werden. 

Internetradio 

 ![Bild](pic/Iradio0.png)


---

## Hardware

| Anzahl | Bezeichnung | 
| -------- | -------- | 
| 1  | ESP32vn IoT UNO |
| 1  |  Shield  |
|  2 |  I2S Digitalverstärker mit MAX98357A  |
| 2  |  Lautsprecher  |
| 1  |  Widerstand 470 kOhm  |
| 1  |  Widerstand 10 kOhm  |
| 1  |  Elko 1000uF / 10V  |
| 2  | Drehgeber Encoder  |
| 2  | Drehknöpfe für 6mm Achse   |
|  1 | TFT 1,88"   |
|  1 | altern. LCD 4x20   |
| 1  | Gehäuse   |
|  1 |  5V-Netzteil  |
|   | Kabel   |
|  --- |  ---  |


---

## Verdrahtung

Mit LCD-Display

![Bild](pic/Schaltplan1.png)

Mit TFT-Display

![Bild](pic/Schaltplan2.png)


![Bild](pic/Iradio2.png)

---



### Inbetriebnahme

Bei der ersten Inbetriebnahme ist noch keine SSID und kein WLAN-Passwort vorhanden. Es kann daher keine Verbindung zum lokalen WLAN hergestellt werden. 
Ein Accesspoint mit der SSID „Internetradio“ wird gestartet. Mit einem Smartphone oder einem Tablet kann nun eine Verbindung zu diesem 
Accesspoint hergestellt werden. Danach kann in einem Browser über die Adresse 192.168.4.1 die Konfigurationsseite aufgerufen werden.

Nach dem Neustart sollte die Verbindung zum lokalen WLAN erfolgreich hergestellt werden können. 
Die Wiedergabe der ersten Station aus der Senderliste sollte mit einer Lautstärke von 50% starten. 
Mit dem Encoder für die Lautstärke kann die Verstärkung eingestellt werden. Änderungen werden in den Präferenzen gespeichert, 
sodass beim nächsten Einschalten dieselbe Lautstärke eingestellt wird. Mit dem anderen Encoder kann ein Sender aus der Senderliste gewählt werden. 
Beim Drehen des Encoders wird in der zweiten Zeile des Displays der Name der Station angezeigt. 
Durch Drücken des Kopfes am Encoder wird die gerade angezeigte Station gespeichert und die Wiedergabe gestartet. 
Auch dieser Wert wird in den Präferenzen gespeichert und beim nächsten Start die zuletzt gewählte Station wiedergegeben. 
Wird der Knopf am Encoder innerhalb von 10 Sekunden nicht gedrückt, springt die Anzeige auf die aktuelle Station zurück.

## WLAN-Daten speichern

Aufruf "Internetradio" in den WLAN-Einstellungen

![Bild](pic/Accesspoint0.png)

Im Browser 192.168.4.1 eingeben

![Bild](pic/Accesspoint1.png)

Im Browser die Zugangsdaten eingeben und neu starten

![Bild](pic/Accesspoint3.png)

Kontrolle mit dem Seriellen Monitor

![Bild](pic/sermonitor.png)

  ![Bild](pic/Iradio4.png)
  


---


### Konfigurations Update

Über die URL http://Internetradio/ sollte die Konfigurationsseite abrufbar sein. Im oberen Teil können die Zugangsdaten und der NTP-Server geändert werden. 
Die Änderungen werden erst dann wirksam, wenn der Knopf „Speichern“ geklickt wurde.
Mit dem Knopf „Neustart“ kann ein Neustart ausgelöst werden.

Die Dropdown-Liste enthält alle Sender der Senderliste. Auswählbare Sender haben vor dem Namen einen schwarzen Punkt. 
Im Formular darunter sind die Daten zur ausgewählten Station gelistet und können geändert werden. 
Ist das Häkchen bei „Verwenden“ nicht gesetzt, ist die Station im Gerät nicht wählbar.
Da manche URLs nicht funktionieren, sollte man die neue URL testen (Testen-Button). 
Ein Klicken auf diesen Knopf startet die Wiedergabe der URL am Gerät. 
Sollte die Wiedergabe nicht funktionieren, wird sofort wieder auf den aktuellen Sender zurückgeschaltet und eine Meldung angezeigt. 
Ist die Wiedergabe möglich, wird eine Box mit einem Knopf angezeigt. Ein Klicken auf diesen Knopf schließt die Box und beendet den Test. 
Es wird wieder die aktuelle Station wiedergegeben.  Mit dem Knopf „Ändern“ können die Änderungen für die ausgewählte Station dauerhaft geändert werden.

---


 ## Programmierung über OTA


 ![Bild](pic/OTA.png)

 ![Bild](pic/OTA2.png)
 
  ![Bild](pic/OTA3.png)




 ---
 

## Voreingestellte Senderliste

1* Spitalradio LuZ	https://s10.streamingcloud.online:13552/radioluz320.mp3

2 Bayern1		http://dispatcher.rndfnk.com/br/br1/nbopf/mp3/low

3 Antenne Bayern	http://stream.antenne.de/antenne

4 NRW Rockradio	http://rnrw.cast.addradio.de/rnrw-0182/deinrock/low/stream.mp3

5 RT1 Rock	http://rt1.radio/tu6h1

6* 1A Rock		http://1a-rock.radionetz.de:8000/1a-rock.mp3

7* NDW		http://1a-ndw.radionetz.de/1a-ndw.mp3

8 WDR 2		http://wdr-wdr2-aachenundregion.icecastssl.wdr.de/wdr/wdr2/aachenundregion/mp3/128/stream.mp3

9 WDR3		http://wdr-wdr3-live.icecastssl.wdr.de/wdr/wdr3/live/mp3/128/stream.mp3

10 HR3		http://dispatcher.rndfnk.com/hr/hr3/suedhessen/high

11 MDR		http://mdr-284280-1.cast.mdr.de/mdr/284280/1/mp3/low/stream.mp3

12 RBB		http://dispatcher.rndfnk.com/rbb/rbb888/live/mp3/mid

13 Ant Brandenburg	http://dispatcher.rndfnk.com/rbb/antennebrandenburg/live/mp3/mid

14 N-JOY		http://icecast.ndr.de/ndr/njoy/live/mp3/128/stream.mp3

15 Radino		http://stream01.zogl.net:8906/stream

16 NRW 90er	http://rnrw.cast.addradio.de/rnrw-0182/dein90er/low/stream.mp3

17 1A Deutsche Hits http://stream.1a-webradio.de/saw-deutsch/

18 Bayern Klassik	http://dispatcher.rndfnk.com/br/brklassik/live/mp3/low

19 NRW Schlagerradio http://rnrw.cast.addradio.de/rnrw-0182/deinschlager/low/stream.mp3

20 Hörspiele	http://stream.laut.fm/hoerspiel

21 Jugend		http://stream.laut.fm/jugend_radio

22 NDR2 Niedersachsen http://icecast.ndr.de/ndr/ndr2/niedersachsen/mp3/128/stream.mp3

23 NDR1 Hannover http://icecast.ndr.de/ndr/ndr1niedersachsen/hannover/mp3/128/stream.mp3

24 WDR1 http://wdr-1live-live.icecast.wdr.de/wdr/1live/live/mp3/128/stream.mp3

25 WDR COSMO http://wdr-cosmo-live.icecast.wdr.de/wdr/cosmo/live/mp3/128/stream.mp3

26 Deutschlandfunk http://st01.sslstream.dlf.de/dlf/01/128/mp3/stream.mp3


---
---
<div style="position:absolute; left:2cm; ">  <ol class="breadcrumb" style="border-top: 2px solid black;border-bottom:2px solid black; height: 45px; width: 900px;"> <p align="center"><a href="#oben">nach oben</a></p></ol>
</div> 

---
