<a name="oben"></a>
# Internetradio
Internetradio mit WEB-Server, TFT 1,88 oder LCD 4 Zeilen Display

## Story
Das Internetradio steht mit dem Display TFT 1,88" oder einem LCD 4x20 mit I2C Schnittstelle zur Verfügung.
Neben dem gerade gespielten Sender werden Datum und Uhrzeit, sowie die aktuelle Lautstärke angezeigt. 
In den beiden unteren Zeilen sind die Informationen zum laufenden Programm, die mit dem Audiostream mitgeschickt werden. 
Die Lautstärkeregelung erfolgt ebenso, wie die Senderwahl über einen Rotary-Encoder. Die Konfiguration kann
auch über einen Browser erfolgen. Über diesen Weg ist die Senderliste veränder- und erweiterbar. 
Da manche URLs nicht abspielbar sind, kann eine URL über die Browserkonfiguration getestet werden, 
ehe sie gespeichert wird. Ein Firmwareupdate ist auch über WLAN (Over The Air = OTA) möglich.

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

![Bild](pic/Schaltplan2.png)


## Inbetriebnahme
Bei der ersten Inbetriebnahme sind noch keine Präferenzen vorhanden. Es kann daher keine Verbindung zum lokalen WLAN hergestellt werden. 
Ein Accesspunkt mit der SSID „Internetradio“ ohne Passwort wird gestartet. Mit z.B. einem Smartphone kann nun eine Verbindung zu diesem 
Accesspoint hergestellt werden. Danach kann in einem Browser über die Adresse 192.168.4.1 die Konfigurationsseite aufgerufen werden.

In den WLAN-Einstellungen „webradioconf“ auswählen

 ![Bild](pic/Accesspoint0.png)

WLAN SSID und Password eingeben

 ![Bild](pic/Accesspoint1.png)

 Nach der Eingabe "Neustart" auswählen
 
 ![Bild](pic/Accesspoint3.png)

Kontrolle am Seriellen Monitor

 ![Bild](pic/sermonitor.png)

Aufruf des WEB-Servers mit einem Browser

 ![Bild](pic/Internetradion2.png)

---
 

## Senderliste



http://dispatcher.rndfnk.com/br/br1/nbopf/mp3/low
http://dispatcher.rndfnk.com/br/br3/live/mp3/low
http://stream.antenne.de/antenne
http://dispatcher.rndfnk.com/rbb/antennebrandenburg/live/mp3/mid
http://dispatcher.rndfnk.com/rbb/rbb888/live/mp3/mid
http://rnrw.cast.addradio.de/rnrw-0182/deinrock/low/stream.mp3
http://icecast.ndr.de/ndr/ndr2/niedersachsen/mp3/128/stream.mp3
http://icecast.ndr.de/ndr/ndr1niedersachsen/hannover/mp3/128/stream.mp3
http://wdr-1live-live.icecast.wdr.de/wdr/1live/live/mp3/128/stream.mp3
http://wdr-cosmo-live.icecast.wdr.de/wdr/cosmo/live/mp3/128/stream.mp3
http://st01.sslstream.dlf.de/dlf/01/128/mp3/stream.mp3
http://stream.1a-webradio.de/saw-deutsch/
http://streams.80s80s.de/ndw/mp3-192/streams.80s80s.de/
http://dispatcher.rndfnk.com/br/brklassik/live/mp3/low
http://mdr-284280-1.cast.mdr.de/mdr/284280/1/mp3/low/stream.mp3
http://wdr-wdr3-live.icecastssl.wdr.de/wdr/wdr3/live/mp3/128/stream.mp3
http://wdr-wdr2-aachenundregion.icecastssl.wdr.de/wdr/wdr2/aachenundregion/mp3/128/stream.mp3
http://rnrw.cast.addradio.de/rnrw-0182/deinschlager/low/stream.mp3
http://rnrw.cast.addradio.de/rnrw-0182/dein90er/low/stream.mp3


---
---

<div style="position:absolute; left:2cm; ">   
<ol class="breadcrumb" style="border-top: 2px solid black;border-bottom:2px solid black; height: 45px; width: 900px;"> <p align="center"><a href="#oben">nach oben</a></p></ol>
</div> 

---
