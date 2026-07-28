# About This Kit

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @chengguohong; @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=f27c946fc782ac1d031692b6ff0d2063a86e9e01 translatedAt=2026-07-25T11:35:19.292Z pushedAt=2026-07-27T08:00:50.041Z -->

## Overview

Mobile devices have become an integral part of everyday life. Connecting Bluetooth headsets to listen to music, using Wi-Fi for Internet access, and tapping NFC-enabled devices to unlock doors are all common user experiences.

To support these scenarios, Bluetooth provides fundamental connectivity capabilities for music playback, voice calls, and content sharing. Wi-Fi provides basic wireless networking capabilities, while NFC enables tap-to-read and tap-to-card interactions.

Connectivity Kit provides these foundational communication capabilities for you to build connected experiences that integrate seamlessly into users' daily lives.

### Bluetooth

Bluetooth is a wireless communication technology that implements short-range data transmission. The Bluetooth technical specifications are formulated by the Bluetooth Special Interest Group (SIG). It can be used to connect a variety of devices, including smartphones, headsets, speakers, keyboards, mouse devices, and printers. Bluetooth features low power consumption, low cost, and ease of use.

Different Bluetooth modules provide APIs applicable to different scenarios, helping developers develop Bluetooth-related features.

- **ACCESS module**<br>

  Provides capabilities such as enabling and disabling Bluetooth and obtaining the Bluetooth status. You need to enable Bluetooth through this module before using other Bluetooth functions. For details, see [@ohos.bluetooth.access](../reference/apis-connectivity-kit/js-apis-bluetooth-access.md).

- **CONNECTION module**<br>

  Provides capabilities such as discovering and pairing Bluetooth devices, as well as obtaining information about the local and peer devices. For details, see [@ohos.bluetooth.connection](../reference/apis-connectivity-kit/js-apis-bluetooth-connection.md).

- **BLE module**<br>

  Provides Bluetooth Low Energy (BLE) capabilities, such as discovering devices, sending advertising packets, discovering services, and transmitting data. For details, see [@ohos.bluetooth.ble](../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md).

- **SOCKET module**<br>

  Provides capabilities such as connecting and transmitting data between Bluetooth devices over Serial Port Profile (SPP). For details, see [@ohos.bluetooth.socket](../reference/apis-connectivity-kit/js-apis-bluetooth-socket.md).

- **A2DP module**<br>

  Establishes Bluetooth connections between devices and transmits high-quality audio over Advanced Audio Distribution Profile (A2DP). For example, this module enables transmission of audio data streams between a phone and audio peripherals (such as headsets and speakers) for music streaming playback. For details, see [@ohos.bluetooth.a2dp](../reference/apis-connectivity-kit/js-apis-bluetooth-a2dp.md).

- **HFP module**<br>

  Establishes connections between Bluetooth devices and enables hands-free calls over the Hands-Free Profile (HFP), supporting functions such as two-way voice call and control. For details, see [@ohos.bluetooth.hfp](../reference/apis-connectivity-kit/js-apis-bluetooth-hfp.md).

- **HID module**<br>

  Implements communication, wireless control, and data transmission between Bluetooth devices over Human Interface Device Profile (HID). For example, this module enables low-latency bidirectional communication between devices such as keyboards, mouse devices, and gamepads and hosts (such as phones, tablets, and PCs). For details, see [@ohos.bluetooth.hid](../reference/apis-connectivity-kit/js-apis-bluetooth-hid.md).

- **PAN module**<br>

  Implements network sharing between devices over Personal Area Network (PAN). For example, this module supports Internet sharing between a phone and a PC. For details, see [@ohos.bluetooth.pan](../reference/apis-connectivity-kit/js-apis-bluetooth-pan.md).

- **MAP module**<br>

  Implements message sharing between devices over Message Access Profile (MAP). For example, this module supports SMS message synchronization between a phone and a head unit. For details, see [@ohos.bluetooth.map](../reference/apis-connectivity-kit/js-apis-bluetooth-map.md).

- **PBAP module**<br>

  Implements phone book data sharing between devices over Phone Book Access Profile (PBAP). For example, this module supports synchronization of contact and call log data between a phone and a head unit. For details, see [@ohos.bluetooth.pbap](../reference/apis-connectivity-kit/js-apis-bluetooth-pbap.md).

### WLAN

Wireless Local Area Networks (WLANs) are local area networks that transmit and receive data over wireless technologies such as radio waves, infrared signals, or other wireless media. WLANs enable network communication between nodes without requiring physical connections, making them well suited for mobile devices in workplaces and public environments.

The WLAN system provides users with WLAN access (STA mode), peer-to-peer data transmission (P2P mode), and hotspot sharing (AP mode).

- STA (Station) mode<br>

Enables a device to operate as a client in a wireless network. A device operating in this mode can connect to another network, such as a home router, and is typically used to provide upstream network connectivity. For details, see [@ohos.wifiManager (WLAN)](../reference/apis-connectivity-kit/js-apis-wifiManager.md).

- P2P mode<br>

Also known as Wi-Fi Direct, is a peer-to-peer connection technology that enables two STA devices to establish a TCP/IP connection directly without requiring an access point (AP). One STA acts as the Group Owner (GO), performing the role of a traditional AP, while the other STA acts as the Group Client (GC) and connects to the GO in the same way it connects to an AP. For details, see [@ohos.wifiManager (WLAN)](../reference/apis-connectivity-kit/js-apis-wifiManager.md).

- AP mode<br>

Provides downstream network services for client devices in a WLAN. In this mode, the device serves as the central node of the WLAN. For details, see [@ohos.wifiManager (WLAN)](../reference/apis-connectivity-kit/js-apis-wifiManager.md).

### NFC

The Near Field Communication (NFC) service provides functionalities such as NFC switch control, NFC tag reading and writing, and NFC card emulation.

- NFC switch control<br/>

Provides APIs for enabling and disabling NFC. Applications that enable or disable NFC must declare the **ohos.permission.MANAGE_SECURE_SETTINGS** permission. Since only system applications can declare this permission, only system applications can enable or disable NFC. For details, see [@ohos.nfc.controller (Standard NFC)](../reference/apis-connectivity-kit/js-apis-nfcController.md).

- NFC tag read/write<br>

Provides capabilities for discovering NFC tags, dispatching them to applications, and allowing applications to access NFC tags through tag read/write APIs. Applications must declare NFC tag read/write capabilities in the required format before they can receive dispatched NFC tags. For details, see [@ohos.nfc.tag (Standard NFC Tags)](../reference/apis-connectivity-kit/js-apis-nfcTag.md).

- NFC card emulation<br>

Provides card emulation capabilities, allowing electronic devices to complete card interactions by tapping an NFC reader. Applications must declare NFC card emulation capabilities in the required format before they can perform card emulation. For details, see [@ohos.nfc.cardEmulation (Standard NFC Card Emulation)](../reference/apis-connectivity-kit/js-apis-cardEmulation.md).

### Converged Short-Range Communication

The converged short-range communication service provides unified management of short-range communication technologies in the OpenHarmony system.

- **PartnerAgent service module**<br/>

Provides interconnection services between partner devices and OpenHarmony devices. Within the module, interconnection services such as media control, phone call reverse control, and health monitoring can be implemented. For details, see [@ohos.FusionConnectivity.partnerAgent (Device Status Notification Module)](../reference/apis-connectivity-kit/js-apis-fusionConnectivity-partnerAgent.md).

- **Fusion connectivity module**<br/>

  Provides the NearLink [HADM](terminology.md#high-accuracy-distance-measurement-hadm) ranging service. Within the module, the NearLink HADM ranging capability can be used. For details, see [@ohos.FusionConnectivity.ranging](../reference/apis-connectivity-kit/js-apis-fusionConnectivity-ranging.md).

### Working Principles

Connectivity Kit provides basic communication services for applications. Before a communication service is used by an application, the related feature must be enabled or a connection must be set up. When the service ends, the connection must be closed actively.

### Constraints

Device capabilities can be used only after the related switch is enabled after user authorization. Otherwise, the system does not provide services for third-party applications.

### Samples

For Bluetooth services, the following sample is available:

- [Bluetooth](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/Bluetooth)

<!--no_check-->