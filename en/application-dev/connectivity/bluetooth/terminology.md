# Bluetooth Glossary

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->

## A
### A2DP
Advanced Audio Distribution Profile. This profile supports high-quality audio transmission and is suitable for music playback on Bluetooth headsets, speakers, and similar devices. It defines two roles: [A2DP Source](#a2dp-source) and [A2DP Sink](#a2dp-sink).
### A2DP Sink
The audio receiving device in the [A2DP](#a2dp) profile. It is responsible for decoding and playing audio. Typical devices include Bluetooth headsets and speakers.
### A2DP Source
The audio source device in the [A2DP](#a2dp) profile. It is responsible for encoding and sending audio data. Typical devices include phones and tablets.
### ACL
Asynchronous Connectionless Link. In the Bluetooth subsystem, it indicates the connection status of the physical link between devices.
## B
### BLE
Bluetooth Low Energy. This protocol has been supported since Bluetooth 4.0. Compared with classic Bluetooth, it is a Bluetooth communication technology designed for low power consumption and long battery life.
### BR
Basic Rate. This is a Bluetooth wireless communication technology used to refer to classic Bluetooth. It is mainly used for file transfer and audio streaming.
### Bluetooth SIG
Bluetooth Special Interest Group. This organization publishes Bluetooth technical specifications. You can obtain detailed Bluetooth technical documents from its official website.
## C
### Characteristic
The core data unit of a [GATT](#gatt) service ([Service](#service)). It is the basic unit for data read/write and notification in GATT communication and is uniquely identified by a [UUID](#uuid).
## D
### Descriptor
The data unit of a [GATT](#gatt) characteristic ([Characteristic](#characteristic)). It describes additional information and attributes of the characteristic, supports data read/write, and is identified by a [UUID](#uuid).
## E
### EDR
Enhanced Data Rate. This is an enhanced version of Bluetooth [BR](#br) with a higher data transmission rate. Together with BR, it is referred to as classic Bluetooth.
## G
### GATT
Generic Attribute Profile. This is the core protocol of [BLE](#ble). It defines the mechanism for Bluetooth communication and data transmission based on services ([Service](#service)), characteristics ([Characteristic](#characteristic)), and descriptors ([Descriptor](#descriptor)).
## H
### HF
Hands-Free unit. This is the hands-free device in the [HFP](#hfp) profile. It serves as the remote control end in Bluetooth call audio and provides physical interaction interfaces, such as buttons, and audio input/output capabilities, such as microphones and speakers. Typical devices include Bluetooth headsets and in-vehicle Bluetooth systems.
### HFP
Hands-Free Profile. This profile is used to implement hands-free calling between Bluetooth devices and supports functions such as two-way voice calls and call control. It defines two roles: [HFP AG](#hfp-ag) and [HF](#hf).
### HFP AG
Hands-Free Audio Gateway. This is the audio gateway in the [HFP](#hfp) profile. It serves as the audio processing center in Bluetooth call audio and is responsible for functions such as call control, for example, answering or hanging up a call, and managing audio input/output. Typical devices include phones and tablets.
### HID
Human Interface Device Profile. This profile is designed for classic Bluetooth and can be used to implement low-latency bidirectional communication between Bluetooth wireless human interface devices. For example, it can be used to transfer data between devices such as keyboards, mice, and game controllers and a host such as a phone or tablet. This profile defines two roles: [HID Host](#hid-host) and [HID Device](#hid-device).

In the HID profile, data transmission channels are classified into two types: the interrupt channel and the control channel. The interrupt channel is used to transmit one-way low-latency real-time data. The control channel is used to transmit two-way reliable real-time data and includes the following three requests:
- GET_REPORT: A data read request initiated by the HID host to obtain the status information of the HID device.
- SET_REPORT: A data write request initiated by the HID host to send control instructions to the HID device.
- SET_PROTOCOL: A protocol mode switching request initiated by the HID host.

### HID Device
An [HID](#hid) device that provides human interface data input/output for an [HID Host](#hid-host) device. Typical devices include mice and keyboards.
### HID Host
The host device in the [HID](#hid) profile. It is responsible for receiving and processing input data from an [HID Device](#hid-device) and performing the corresponding operations. Typical devices include phones and tablets.
### HOGP
HID over GATT Profile. This [HID](#hid) specification is implemented over the GATT protocol of Bluetooth Low Energy. It ports classic [HID](#hid) capabilities to [BLE](#ble) devices for reuse and is compatible with the [HID](#hid) interaction logic of [BLE](#ble) devices such as keyboards, mice, and selfie sticks.
## L
### L2CAP
Logical Link Control and Adaptation Protocol. This protocol can meet multiple transmission requirements of upper-layer protocols and applications, provide connection-oriented and connectionless data services, and support multiplexing, segmentation, and reassembly.
## M
### MAP
Message Access Profile. This profile can be used to implement message synchronization between Bluetooth devices and supports data transmission for text messages, emails, and similar content. It defines two roles: [MCE](#mce) and [MSE](#mse).
### MCE
Message Client Equipment. This is the message client in the [MAP](#map) profile and can view and manage messages on the [MSE](#mse). A typical device is an in-vehicle Bluetooth system.
### MSE
Message Server Equipment. This is the message server in the [MAP](#map) profile and stores original message data, such as text messages or emails. A typical device is a phone.
### MTU
Maximum Transmission Unit. It indicates the maximum size of a single data packet transmitted over a network, in bytes.
## N
### NAP
Network Access Point. This is the network access point in the [PAN](#pan) profile. It acts as a gateway device and provides Internet access or local network sharing. Typical devices include phones and tablets.
## O
### OOB
Out of Band. This refers to transmitting information through channels independent of the main data channel. For example, during Bluetooth pairing, devices can exchange security keys through non-Bluetooth channels such as a Wi-Fi network or NFC to improve pairing security.
### OPP
Object Push Profile. This profile is built on the Generic Object Exchange Profile (GOEP) and can be used to transfer data such as images and documents between devices.
## P
### PAN
Personal Area Network. This Bluetooth personal area network profile supports network sharing between devices. In this profile, [NAP](#nap) and [PANU](#panu) are the two core roles.
### PANU
Personal Area Network User. This is the personal area network user in the [PAN](#pan) profile. As a client device, it proactively connects to a [NAP](#nap) to obtain network services.
### PBAP
Phone Book Access Profile. This profile can be used to implement phone book data synchronization between Bluetooth devices and supports data transmission for contacts, call logs, and similar content. It defines two roles: [PCE](#pce) and [PSE](#pse).
### PCE
Phone Book Client Equipment. This is the phone book client in the [PBAP](#pbap) profile. As the data requester, it can obtain phone book data from the [PSE](#pse). A typical device is an in-vehicle Bluetooth system.
### PSE
Phone Book Server Equipment. This is the phone book server in the [PBAP](#pbap) profile and stores original phone book data, such as contacts and call logs. A typical device is a phone.
### Profile
In the Bluetooth subsystem, this term usually refers to a Bluetooth technical protocol or capability, for example, [A2DP](#a2dp), [HFP](#hfp), and [HID](#hid).
### PSM
Protocol/Service Multiplexer. As a parameter on an [L2CAP](#l2cap) link, it is used to identify the data transmission channel of a specific service. By using PSM to distinguish different upper-layer services, multiple service data streams can be multiplexed over a single L2CAP link.
## R
### RFCOMM
Radio Frequency Communication. This protocol is used to simulate traditional RS232 serial communication, a common wired data transmission standard. It provides upper-layer applications with a simple and reliable data transmission method and supports multiple simultaneously connected channels.
### RSSI
Received Signal Strength Indicator. It quantifies the signal strength at the receiving end in wireless communication by using a relative value, in dBm. It can be used to evaluate the distance between devices and signal quality.
### SCO
Synchronous Connection-Oriented. This is a connection-oriented synchronous data link in the Bluetooth protocol stack. It is mainly used to transmit time-sensitive audio data, such as voice calls.
### SDP
Service Discovery Protocol. This protocol in the Bluetooth protocol stack is used for service discovery. It is used to discover and identify the services and capabilities supported by other Bluetooth devices, and to negotiate communication parameters during Bluetooth pairing and connection.
### Service
In Bluetooth protocols, this term usually refers to a service in the [GATT](#gatt) profile. It is a data structure that contains multiple [Characteristic](#characteristic) values and other dependent services, represents a capability of a [BLE](#ble) device, and is uniquely identified by a [UUID](#uuid).
### SPP
Serial Port Profile. This protocol in the Bluetooth protocol stack provides serial port emulation services based on [RFCOMM](#rfcomm) and can be used to implement communication connections and data transmission between Bluetooth devices.
## U
### UUID
Universally Unique Identifier. This is a standardized 128-bit (16-byte) string. In Bluetooth technology, it can be used to identify different [Profile](#profile) protocols, as well as services ([Service](#service)), characteristics ([Characteristic](#characteristic)), and descriptors ([Descriptor](#descriptor)) in the [GATT](#gatt) profile.
