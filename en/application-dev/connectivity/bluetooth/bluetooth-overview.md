# Bluetooth Overview

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=629268201a1c74f349a992cd6b5c92758af41f29 translatedAt=2026-08-15T01:40:19.311Z pushedAt=2026-08-15T03:05:26.551Z -->

## Introduction

Bluetooth is a wireless communication technology that enables short-range data transmission. Its technical specifications are developed by the Bluetooth Special Interest Group (SIG). It can be used to connect a variety of devices, including smartphones, headsets, speakers, keyboards, mouse devices, and printers. Currently, Bluetooth has two common technical categories: Bluetooth Classic (BR/EDR) and Bluetooth Low Energy (BLE).

Bluetooth is a short-range communication protocol based on radio technologies. It uses radio waves in the 2.4 GHz band for communication and uses the Frequency Hopping Spread Spectrum (FHSS) to prevent interference with other wireless devices. During the communication process, the Bluetooth device sends and receives data packets, and uses different Bluetooth profiles to control the communication process and data transmission.

## Bluetooth Classic

Bluetooth Classic is also known as Basic Rate/Enhanced Data Rate (BR/EDR). Bluetooth EDR is an enhanced version of Bluetooth BR technology, featuring a higher data transmission rate—2 to 3 times faster than BR, with a maximum speed of 2 to 3 Mbit/s. Under ideal conditions, its communication range is approximately 100 meters.

Bluetooth Classic offers diverse and mature technical profiles. Examples include profiles for advanced audio distribution, hands-free calling, personal area network (PAN), and phonebook access. Leveraging these profiles, Bluetooth Classic can meet diverse needs across various application scenarios. For instance, it enables listening to music via Bluetooth headsets, speakers, and other devices; accessing data such as phonebooks and text messages from smartphones through car systems; and realizing data sharing between devices.

## Bluetooth Low Energy

BLE is a technology supported starting from Bluetooth 4.0. Compared with Bluetooth Classic, BLE features lower power consumption while ensuring a certain transmission rate, making it widely used in Bluetooth devices with high requirements for battery life. Its maximum transmission rate can reach 1 Mbit/s, and its communication range is usually around 10 meters.

Compared with Bluetooth Classic, BLE, with its low power consumption feature, is widely applied in fields such as wearable devices, smart homes, and Internet of Things (IoT) sensors.

## Bluetooth Device Address Type

During Bluetooth service development, two types of address are defined.

![bluetooth address type](figures/bt_address_type.png)

**Figure 1** Bluetooth device address types

- Bluetooth device address type defined by the Bluetooth subsystem. The actual MAC address of a Bluetooth device is considered user private information. During device discovery, the Bluetooth subsystem assigns a virtual MAC address to each Bluetooth device and saves the mapping between the virtual MAC address and the actual MAC address.

- Bluetooth device address type defined by the Bluetooth protocol. The Bluetooth device address types defined by the Bluetooth protocol are classified into two subtypes: public address and random address. Classic Bluetooth devices use public addresses, while Bluetooth Low Energy (BLE) devices can use public addresses or random addresses. Random addresses include static random addresses and private random addresses. Private random addresses are further classified into non-resolvable private addresses and resolvable private addresses. The following table describes each address type.

| Type               | Description    |
| ------------------ |  ------ |
| Public Address       | Public device address, which is allocated by the IEEE and is unique. The address remains unchanged permanently.|
| Static Random Address       | Static random address, which is randomly generated when the Bluetooth device is powered on and initialized. The address does not change in the current power-on period.|
| Resolvable Private Address      | Resolvable private address, which is generated based on an Identity Resolving Key (IRK) and changes periodically (every 15 minutes according to the Bluetooth protocol). If Bluetooth device A has the IRK of Bluetooth device B, device A can identify device B by resolving the resolvable private address of device B.|
| Non-resolvable Private Address       | Unresolvable private address, which is a completely random temporary address that changes periodically (every 15 minutes according to the Bluetooth protocol) and is difficult to trace.|

## Device Roles

During Bluetooth pairing and connection establishment, devices can be classified into two roles based on whether they actively initiate or passively respond to the connection process: Central and Peripheral.

In Bluetooth Classic, a device that discovers nearby devices through inquiry and actively initiates pairing and connections is referred to as a Central device. A device that responds to inquiries and accepts pairing and connection requests from other devices is referred to as a Peripheral device.

In BLE, a device that scans for other devices and actively initiates connections is referred to as a Central device. A device that advertises and accepts connection requests from other devices is referred to as a Peripheral device.

<!--RP1-->

<!--RP1End-->