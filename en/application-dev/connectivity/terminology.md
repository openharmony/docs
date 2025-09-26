# Connectivity Kit Terminology

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @chengguohong; @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->

## A
### A2DP
Advanced Audio Distribution Profile, which is used to support transmission of high-quality audio, for example, listening to music with a Bluetooth headset. This protocol defines two roles: [A2DP source](#a2dp-source) and [A2DP sink](#a2dp-sink).
### A2DP Sink
An audio sink in the [A2DP](#a2dp) protocol, which is responsible for decoding and playing audio. Typical devices include Bluetooth headsets and speakers.
### A2DP Source
An audio source in the [A2DP](#a2dp) protocol, which is responsible for encoding and sending audio data. Typical devices include mobile phones and tablets.
### ACL
Asynchronous connectionless link, which is used to indicate the connection status of physical links between devices in the Bluetooth subsystem.
## B
### BLE
Bluetooth Low Energy, which is supported since Bluetooth 4.0. Compared with traditional Bluetooth, BLE features low power consumption and long battery life.
### BR
Basic Rate, which is a Bluetooth wireless communication technology representing Bluetooth Classic. It is mainly used in scenarios such as file and audio stream transmission.
### Bluetooth SIG
Bluetooth Special Interest Group, which is an organization that releases Bluetooth technical specifications. Developers can obtain detailed Bluetooth technical documentation from their official website.
## C
### Characteristic
Core data unit of a [GATT](#gatt) service. It supports data read/write and is uniquely identified by a [UUID](#uuid).
## D
### Descriptor
Data unit of a [GATT](#gatt) [characteristic](#characteristic). It is used to describe the additional information and attributes of the characteristic. It supports data read/write and is uniquely identified by a [UUID](#uuid).
## E
### EDR
Enhanced Data Rate, which enhances [BR](#br) by offering a higher data transmission rate. Together with BR, they are collectively referred to as traditional Bluetooth.
## G
### GATT
Generic Attribute Profile, which is the core protocol of [BLE](#ble) that defines the mechanism for Bluetooth communication and data transmission based on [services](#service), [characteristics](#characteristic), and [descriptors](#descriptor).
## H
### HF
Hands-Free unit, i.e., the hands-free device in the [HFP](#hfp) protocol. It serves as the remote control terminal in Bluetooth call audio, providing a physical interaction interface (e.g., button) and audio input/output (e.g., microphone, speaker). Typical devices include Bluetooth headsets and Bluetooth car kits.
### HFP
Hands-Free Profile, which is used to enable hands-free calling between Bluetooth devices, supporting bidirectional voice calls and control functions. This protocol defines two roles: [HFP AG](#hfp-ag) and [HF](#hf).
### HFP AG
Hands-Free Audio Gateway, i.e., the audio gateway in the [HFP](#hfp) protocol. It serves as the audio processing center in Bluetooth call audio, responsible for call control (such as executing answer/hang-up instructions) and managing audio input/output. Typical devices include mobile phones and tablets.
### HID
Human Interface Device Profile, which enables low-latency bidirectional communication between Bluetooth-enabled human-computer interaction devices, such as transmitting data between keyboards, mouse devices, and gamepads, and hosts (e.g., mobile phone, tablet). This protocol is specifically designed for Bluetooth Classic. It defines two roles: [HID host](#hid-host) and [HID device](#hid-device).
### HID Device
[HID](#hid) devices that provide human-machine data input/output to the [HID host](#hid-host). Typical devices include mouse devices and keyboards.
### HID Host
[HID](#hid) host that processes and receives input data from [HID devices](#hid-device) and performs corresponding operations. Typical devices include mobile phones and tablets.
### HOGP
HID over GATT Profile, which is an HID specification implemented based on the GATT protocol of BLE. It ports traditional HID functions to BLE devices for reuse and is compatible with the HID interaction logic of BLE devices such as keyboards, mouse devices, and selfie sticks.
## L
### L2CAP
Logical Link Control and Adaptation Protocol, which supports diverse transmission requirements of upper-layer protocols and applications by providing both connection-oriented and connectionless data services. This protocol also facilitates multiplexing, segmentation, and reassembly, ensuring efficient and reliable data transfer over Bluetooth connections.
## M
### MAP
Message Access Profile, which can be used to synchronize data such as SMS and emails between Bluetooth devices. It defines two roles: [MCE](#mce) and [MSE](#mse).
### MCE
Message client equipment, which is the message client in the [MAP](#map) protocol and can view and manage [MSE](#mse) messages. Typical devices include Bluetooth car kits.
### MSE
Message server equipment, which is the message server in the [MAP](#map) protocol and stores original message data such as SMS messages or emails. Typical devices include mobile phones.
### MTU
Maximum transmission unit, which indicates the maximum size of a single data packet transmitted on the network, in bytes.
## N
### NAP
Network access point in the [PAN](#pan) protocol that serves as the gateway device to provide Internet access or local network sharing functions. Typical devices include mobile phones and tablets.
## O
### OPP
Object Push Profile, which is built on the Generic Object Exchange Profile (GOEP) to transmit data (such as images and documents) between devices.
## P
### PAN
Personal Area Network, which implements network sharing between devices. [NAP](#nap) and [PANU](#panu) are two major roles in the protocol.
### PANU
Personal area network user in the [PAN](#pan) protocol. As a client device, it proactively connects to the [NAP](#nap) to obtain network services.
### PBAP
Phone Book Access Profile, which can be used to synchronize phone book data such as contacts and call logs between Bluetooth devices. This protocol defines two roles: [PCE](#pce) and [PSE](#pse).
### PCE
Phone book client equipment in the [PBAP](#pbap) protocol. As the data requester, it can obtain the phone book data of the [PSE](#pse). Typical devices include Bluetooth car kits.
### PSE
Phone book server equipment in the [PBAP](#pbap) protocol that stores original phone book data such as contacts and call logs. Typical devices include mobile phones.
### Profile
Bluetooth technology protocol or capability in the Bluetooth subsystem, Typical examples include [A2DP](#a2dp), [HFP](#hfp), and [HID](#hid).
### PSM
Protocol/service multiplexer, which is used to identify different services or protocols on the [L2CAP](#l2cap) layer.
## R
### RFCOMM
Radio Frequency Communication (RFC) protocol, which is designed to simulate traditional RS232 serial communication (a common wired data transmission standard), while providing a simple and reliable data transmission method and supporting multiple concurrently connected channels.
### RSSI
Received signal strength indicator. It is used in wireless communications to quantify the signal strength at the receiver in dBm.
## S
### Service
Bluetooth [GATT](#gatt) service, which is a data structure containing multiple characteristics and dependent services. It represents a capability of the [BLE](#ble) device and is identified by a UUID.
### SPP
Serial Port Profile, which can be used to implement connection and data transmission between Bluetooth devices.
## U
### UUID
Universally Unique Identifier, which is a 128-bit string that identifies different Bluetooth [profiles](#profile), as well as services, characteristics, and descriptors in the [GATT](#gatt) protocol.
