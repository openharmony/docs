# WLAN Service Development Overview

## Overview
A wireless local area network (WLAN) uses the radio, infrared, or other technologies to transmit data between devices that are not physically connected with each other. It is widely used in offices and public places where mobile devices are used.

Wireless Fidelity (Wi-Fi) is a communication technology that transmits data between devices through radio waves. It allows users to access the Internet and share data without the need for wired connections. 

The WLAN system provides users with WLAN access (STA mode), peer-to-peer data transmission (P2P mode), and hotspot sharing (AP mode).

## Working Principles
WLAN uses radio electromagnetic waves to transmit data. Currently, it operates in 2.4 GHz and 5 GHz bands. A WLAN involves both wired connections, in which the Ethernet protocol is used to connect access points (APs) to the Internet, and wireless connections, in which IEEE 802.11 is used to connect stations (STAs) and APs.

## WLAN Modes
- STA mode 

  In STA mode, a Wi-Fi device, such as a smartphone or tablet, works as a client. It connects to a routing network, such as a home router, to access the Internet. For details, see [@ohos.wifiManager](../../reference/apis-connectivity-kit/js-apis-wifiManager.md).

- P2P mode (Wi-Fi Direct)

  The P2P mode is also referred to as Wi-Fi Direct, which allows a TCP/IP connection between two STAs without an AP. In a P2P connection, one STA functions as a traditional AP and is called a group owner (GO). The other STA is called a group client (GC), which is connected to the GO like an AP. For details, see [@ohos.wifiManager](../../reference/apis-connectivity-kit/js-apis-wifiManager.md).

- AP mode (hotspot mode)

  In AP mode, a Wi-Fi device acts as a wireless AP and creates its own network (hotspot) that other devices (STAs) can connect to. It allows multiple devices to connect simultaneously. For details, see [@ohos.wifiManager](../../reference/apis-connectivity-kit/js-apis-wifiManager.md).
