# Connectivity Kit

## Introduction to Connectivity Kit

Mobile devices have become an integral part of every life. For example, people listen to music with Bluetooth headphones, surf the Internet over Wi-Fi, and use their mobile phone as a transit pass or credit card.
In these applications, NFC implements short-range interactions like payments and access control, Bluetooth provides basic wireless connections for devices, such as headphones, wearables, and peripheral devices, and Wi-Fi provides high-speed Internet access.
You can use Connectivity Kit to design mobile applications to meet different user requirements.

### Bluetooth

Bluetooth is a wireless technology used for exchanging data between devices over a distance of up to 10 meters. It can be used to connect a variety of devices, including smartphones, headsets, speakers, keyboards, mouse devices, and printers. Bluetooth features low power consumption, low cost, and ease of use. Now, the latest Bluetooth 5 supports higher transfer speeds and wider range.
The following describes the common modules related to Bluetooth:

- **access** module<br>
  The Bluetooth access module provides APIs for enabling and disabling Bluetooth and obtaining Bluetooth status. To use Bluetooth, you need to enable Bluetooth by using the APIs provided by this module.
  For details, see [@ohos.bluetooth.access](../reference/apis-connectivity-kit/js-apis-bluetooth-access.md).

- **connection** module<br>
  The Bluetooth connection module provides APIs for device discovery, pairing, and obtaining information about the local device and its peripherals. You can use the APIs provided by this module to pair and connect to other devices, and then perform subsequent operations, such as transferring data.
  For details, see [@ohos.bluetooth.connection](../reference/apis-connectivity-kit/js-apis-bluetooth-connection.md).

- **ble** module<br>
  Bluetooth Low Energy (BLE) is a wireless, low-power Bluetooth technology. Compared with Classic Bluetooth, BLE allows for lower power consumption and is applicable to devices with long standby time, such as smart watches, healthcare devices, smart home devices.
  For details, see [@ohos.bluetooth.ble](../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md).

- **socket** module (SPP)<br>
  Serial Port Profile (SPP) is a Bluetooth protocol used to establish serial communication connections between Bluetooth devices. With SPP, Bluetooth devices can transmit data, such as files and text, just like using a serial port.
  For details, see [@ohos.bluetooth.socket](../reference/apis-connectivity-kit/js-apis-bluetooth-socket.md).

- **a2dp** module<br>
  Advanced Audio Distribution Profile (A2DP) allows high-quality multimedia audio (such as music and voice) to be streamed between devices over a Bluetooth connection. It supports bidirectional communication and can be used in devices such as headsets, speakers, and car audio devices.
  For details, see [@ohos.bluetooth.a2dp](../reference/apis-connectivity-kit/js-apis-bluetooth-a2dp.md).

- **hfp** module<br>
  The Hands-Free Profile (HFP) module enables hands-free devices, such as car kits and headphones to communicate with mobile phones over a Bluetooth link.
  For details, see [@ohos.bluetooth.hfp](../reference/apis-connectivity-kit/js-apis-bluetooth-hfp.md).

- **hid** module<br>
  The Human Interface Device (HID) module enables connections to HID devices such as a keyboard, a mouse, or a game controller over Bluetooth. Wireless control and input can be implemented by connecting the HID devices to a Bluetooth host.
  For details, see [@ohos.bluetooth.hid](../reference/apis-connectivity-kit/js-apis-bluetooth-hid.md).

- **pan** module<br>
  Personal Area Network (PAN) is a wireless communication technology used to connect devices to a small-scale network. For example, devices such as a smartphone, computer, and printer can be connected to a PAN to print and share files.
  For details, see [@ohos.bluetooth.pan](../reference/apis-connectivity-kit/js-apis-bluetooth-pan.md).

For details about the development, see [Bluetooth Overview](./bluetooth/bluetooth-overview.md).

### WLAN
A wireless local area network (WLAN) uses the radio, infrared, or other technologies to transmit data between devices that are not physically connected with each other. It is widely used in offices and public places where mobile devices are used.

The WLAN system provides users with WLAN access (STA mode), peer-to-peer data transmission (P2P mode), and hotspot sharing (AP mode).

- STA mode<br>
  The device in Station (STA) mode can be considered as a client of an existing wireless network. It can be connected to another routing network, such as a home router, to provide uplink data services.
  For details, see [@ohos.wifiManager](../reference/apis-connectivity-kit/js-apis-wifiManager.md).

- P2P mode<br>
  The P2P mode is also called Wi-Fi Direct, which allows two devices to establish a direct Wi-Fi connection without an intermediary wireless access point (AP). It can set up a TCP/IP connection between two STAs without an AP. Of the two STAs, one is called the group owner (GO), which serves as a traditional AP; the other is called a group client (GC), which connects to the GO like an AP.
  For details, see [@ohos.wifiManager](../reference/apis-connectivity-kit/js-apis-wifiManager.md).

- AP mode<br>
  In AP mode, the Wi-Fi module provides downlink data services for the devices (clients) that join the WLAN. It creates a WLAN, like a central device, allowing other devices to connect to this network.
  For details, see [@ohos.wifiManager](../reference/apis-connectivity-kit/js-apis-wifiManager.md).

### NFC
The Near Field Communication (NFC) service provides functionalities such as NFC switch control, NFC tag reading and writing, and NFC card emulation.

- NFC controller<br>
  The **nfc. controller** module provides APIs for enabling and disabling NFC. To call the APIs provided by this module, the application must have the ohos.permission.MANAGE_SECURE_SETTINGS permission, which is available only for system applications. That is, only system applications can enable or disable NFC.
  For details, see [@ohos.nfc.controller](../reference/apis-connectivity-kit/js-apis-nfcController.md).

- NFC tag reading and writing<br>
  The **nfc. tag** module provides APIs for discovering NFC tags, dispatching NFC tags to applications, and enabling applications to read or write NFC tags. You need to declare the NFC tag read/write capability for your application in the specified format, so that the application can receive NFC tags dispatched.
  For details, see [@ohos.nfc.tag](../reference/apis-connectivity-kit/js-apis-nfcTag.md).

- NFC card emulation<br>
  The **cardEmulation** module provides APIs for implementing payment card and access card solutions. You need to declare the NFC card emulation capability for your application in the specified format so that the application can implement NFC communications.
  For details, see [@ohos.nfc.cardEmulation](../reference/apis-connectivity-kit/js-apis-cardEmulation.md).

### Working Principles

Connectivity Kit provides basic communication services for applications. Before a communication service is used by an application, the related feature must be enabled or a connection must be set up. When the service ends, the connection must be closed actively.

### Constraints

Device capabilities can be used only after the related switch is enabled after user authorization. Otherwise, the system does not provide services for third-party applications.
