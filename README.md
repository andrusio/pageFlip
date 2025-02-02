# pageFlip
Arduino (ESP32) project to control page turning over Bluetooth on devices such as tablets, smartphones, and PCs.

## Description

This Arduino (ESP32) project turns your ESP32 into a wireless remote for controlling page turning (PDFs) or scrolling on a web page. It's especially useful for musicians who need to keep their hands on their instruments while reading sheet music or lyrics.

Using Bluetooth Low Energy (BLE), it sends "Page Up" and "Page Down" keystrokes as if it were a keyboard. It's a simple project; the only challenge is preventing false triggers from the button.

## Usage / How to use
A short press goes to the next page ("Page Down"), and a long press (1 second) goes to the previous page ("Page Up").

## Notes
To compile this project, it is necessary to import the [ESP32 BLE Keyboard library](https://github.com/T-vK/ESP32-BLE-Keyboard).
