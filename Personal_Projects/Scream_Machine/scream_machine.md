# Arduino Scream Machine

A simple Arduino-based scare machine that plays a scream through a speaker when you turn the lights turn on.

## Hardware I Used

- Arduino Uno R3
- DFPlayer Mini HW-247A V3.1 (diagram in repo)
- MicroSD card
- Photoresistor
- 10K resistor
- 3.5mm TRRS breakout board
- 3.5mm AUX cable
- AUX Speaker
- Breadboard and jumper wires
- Power supply

## Wiring

### DFPlayer → Arduino

| DFPlayer | Arduino |
|---|---|
| VCC | 5V |
| GND | GND |
| TX | D10 |
| RX | D11 through 1KΩ resistor |

DFPlayer RX voltage divider:
- Arduino D11 → 1KΩ → DFPlayer RX
- DFPlayer RX/junction → 2KΩ → GND

### Photoresistor

```text
5V
 |
Photoresistor
 |
 +------ A0
 |
10KΩ
 |
GND
```

The photoresistor has no polarity.

### DFPlayer audio → TRRS breakout

- DFPlayer DAC_L → TIP
- DFPlayer DAC_R → RING1
- DFPlayer GND → RING2
- SLEEVE → disconnected

Connect the breakout to the speaker with a normal 3.5mm AUX cable.

## MicroSD Card

Format the card as **MS-DOS (FAT/FAT32)**.

Place the audio file in the root of the card:

```text
0001.mp3
```

The sketch uses `dfPlayer.play(1);`.

## Arduino Code

```cpp
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

SoftwareSerial dfPlayerSerial(10, 11);
DFRobotDFPlayerMini dfPlayer;

void setup() {
  Serial.begin(115200);
  dfPlayerSerial.begin(9600);
  delay(1000);

  if (dfPlayer.begin(dfPlayerSerial)) {
    Serial.println("DFPlayer connected");
    dfPlayer.volume(30);
    dfPlayer.outputDevice(DFPLAYER_DEVICE_SD);
  }
}

void loop() {
  int lightLevel = analogRead(A0);
  Serial.println(lightLevel);

  if (lightLevel > 800) {
    dfPlayer.play(1);
    delay(5000);
  }

  delay(250);
}
```

## Reproduction Steps

1. Connect the Arduino Uno and DFPlayer as shown above.
2. Build the photoresistor voltage divider.
3. Connect A0 to the junction between the photoresistor and 10KΩ resistor.
4. Wire DFPlayer audio to the TRRS breakout.
5. Connect the breakout to the speaker AUX input.
6. Format the MicroSD card as MS-DOS (FAT/FAT32).
7. Copy `0001.mp3` to the root of the card.
8. Insert the card into the DFPlayer.
9. Upload the sketch with Arduino IDE.
10. Open Serial Monitor at **115200 baud**.
11. Confirm `DFPlayer connected`.
12. Observe the light-level readings.
13. In the final installation location, record the reading with the lights off and with the lights on.
14. Set the threshold in `if (lightLevel > 800)` between those two readings.
15. Upload the adjusted sketch.
16. When the light level rises above the threshold, `0001.mp3` plays.

## Calibration

The photoresistor reading depends on room lighting, sensor placement, and sensor direction.

Do not assume `800` will work everywhere. Measure the actual dark and lights-on readings at the final installation location and choose a threshold between them.

## Troubleshooting

### Serial Monitor shows diamond/question-mark characters

The Serial Monitor baud rate must match:

```cpp
Serial.begin(115200);
```

Set it to **115200 baud**.

### Light reading is always 1023

A reading of 1023 means A0 is seeing approximately 5V. Check the divider:

```text
5V → photoresistor → A0 → 10KΩ → GND
```

Make sure the 10KΩ resistor actually connects the A0 junction to GND.

### DFPlayer connects but produces no sound

Make sure these are present:

```cpp
dfPlayer.volume(30);
dfPlayer.outputDevice(DFPLAYER_DEVICE_SD);
```

Also verify that `0001.mp3` is playable and is in the MicroSD card's root directory.

### It triggers repeatedly

The current code waits five seconds after triggering. If the light remains above the threshold, it can trigger again after the delay.

A future improvement would be an edge-based trigger: play once when the lights turn on, then wait until the room becomes dark again before allowing another trigger.
