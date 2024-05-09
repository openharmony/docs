# Bluetooth Overview

## Introduction
Bluetooth, first proposed by Ericsson in 1994, is a wireless technology used for exchanging data between devices over a distance of up to 10 meters. It employs the ISM bands in 2.4 GHz, and can be used to connect a variety of devices, including smartphones, headsets, speakers, keyboards, mouse devices, and printers. Bluetooth features low power consumption, low cost, and ease of use. Now, the latest Bluetooth 5 supports higher transfer speeds and wider range.

## Working Principles
Bluetooth is a short-range communication protocol based on radio technologies. It uses radio waves in the 2.4 GHz band for communication and uses the Frequency Hopping Spread Spectrum (FHSS) to prevent interference with other wireless devices. During the communication process, the Bluetooth device sends and receives data packets, and uses different Bluetooth profiles to control the communication process and data transmission.


## Modules
- **a2dp** module: Advanced Audio Distribution Profile (A2DP) allows high-quality multimedia audio (such as music and voice) to be streamed between devices over a Bluetooth connection. It supports bidirectional communication and can be used in devices such as headsets, speakers, and car audio devices. For details about the APIs, see [@ohos.bluetooth.a2dp](../../reference/apis-connectivity-kit/js-apis-bluetooth-a2dp.md).

- **ble** module: Bluetooth Low Energy (BLE) is a power-conserving Bluetooth technology. Compared with Bluetooth Classic, BLE allows for lower power consumption and is applicable to devices with long standby time, such as smart watches, healthcare devices, smart home devices. For details about the APIs, see [@ohos.bluetooth.ble](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md).

- **hfp** module: Hands-Free Profile (HFP) allows hands-free calls and voice control to be implemented between devices via a Bluetooth link. For details about the APIs, see [@ohos.bluetooth.hfp](../../reference/apis-connectivity-kit/js-apis-bluetooth-hfp.md).

- **hid** module: allows connections to Human Interface Devices (HIDs) such as a keyboard, a mouse, or a game controller over Bluetooth. Wireless control and input can be implemented by connecting the HID devices to a Bluetooth host. For details about the APIs, see [@ohos.bluetooth.hid](../../reference/apis-connectivity-kit/js-apis-bluetooth-hid.md).

- **pan** module: Personal Area Network (PAN) is a wireless communication technology used to connect devices within an individual person's workspace. For example, connect devices such as a smartphone, computer, and printer to a PAN to enable files to be shared and printed. For details about the APIs, see [@ohos.bluetooth.pan](../../reference/apis-connectivity-kit/js-apis-bluetooth-pan.md).

- **gatt** module: Generic Attribute Profile (GATT) provides profile discovery and description services for BLE protocol. It defines how ATT attributes are organized and exchanged over a BLE connection. For details about the APIs, see [@ohos.bluetooth.ble](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md).

- **spp** module: Serial Port Profile (SPP) establishes serial communication connections between Bluetooth devices. With SPP, Bluetooth devices can transmit data, such as files and text, just like using a serial port. For details about the APIs, see [@ohos.bluetooth.socket](../../reference/apis-connectivity-kit/js-apis-bluetooth-socket.md).
