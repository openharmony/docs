# OH_MIDI Overview (C/C++)

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @owen_creeper-->
<!--Designer: @trytocalm-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=3120d7a9c5ec148c9e44c3b33dc9c1416da673d1 translatedAt=2026-08-06T01:50:52.942Z pushedAt=2026-08-06T08:48:02.760Z -->

## Introduction to MIDI

Musical Instrument Digital Interface (MIDI) is an international standard protocol for communication between electronic musical instruments, computers, and other devices. It defines the transmission method for music data such as notes and control signals, and is widely used in fields such as music production, stage performance, and game development.

Starting from API version 24, Audio Kit supports MIDI functionality. Applications can use the **OH_MIDI** API to exchange data with external MIDI devices (such as USB MIDI keyboards and Bluetooth MIDI devices). Since **OH_MIDI** adopts Universal MIDI Packet (UMP) as the unified data exchange format, you do not need to concern underlying protocol differences and can simply build applications for music creation, instrument control, and MIDI data processing in a modern way.

### MIDI Protocol Versions

- MIDI 1.0: The classic protocol released in 1983, using 7-bit resolution (value range: [0, 127]), unidirectional communication, and widely compatible with existing devices.

- MIDI 2.0: The next-generation protocol released in 2020, supporting features such as 32-bit high resolution, bidirectional communication, and automatic configuration (MIDI-CI).

**OH_MIDI** supports connecting standard MIDI 1.0 devices and automatically converts traditional MIDI 1.0 byte streams into the 32-bit UMP format through the system service layer, thereby simplifying application development. Meanwhile, this architectural design is compatible with the MIDI 2.0 standard in terms of data format, providing the necessary technical foundation for future system kernels to support high-resolution MIDI devices.

### UMP Data Format Description

The universal MIDI packet is a unified packet format defined in the MIDI 2.0 standard. It adopts a 32-bit aligned structure and can carry both MIDI 1.0 and MIDI 2.0 protocol messages simultaneously.

Relationship between protocol and data format (analogous to "envelope" and "language of the letter content"):

- UMP: unified 32-bit aligned container (envelope format)

- MIDI 1.0/2.0 protocol: traditional/modern semantics (language of the letter content)

Regardless of which protocol is chosen, the data encapsulation format (UMP) is unified.

**OH_MIDI** includes four core concepts: client, device, port, and event. The basic workflow for developing MIDI applications using **OH_MIDI** is: create a client → enumerate/open a device → open a port → send and receive MIDI messages → close the port/device/client. For the detailed development procedure and sample code, see [Using OH_MIDI for MIDI Development (C/C++)](using-ohmidi.md).

Relationships between core concepts:

- **Client**: The entry point for an application to interact with MIDI services. After creating a client, you can register hot-plug and error callbacks, enumerate connected devices, and open device handles.

- **Device**: A MIDI interface device opened through the client, including USB MIDI devices and BLE MIDI devices. Each device can open multiple ports.

- **Port**: A data transmission endpoint on a device, divided into input port (receiving MIDI data) and output port (sending MIDI data).

- **Event**: The basic unit of data sent and received through a port, using the UMP format, containing a timestamp, data length, and data pointer.

## OH_MIDI Client

The client is the entry point for applications to use MIDI services. All MIDI operations require creating a client first. Additionally, the client is responsible for managing the connection with the MIDI service, providing core functions such as device enumeration, device opening, and port management.

After creating a client through the [OH_MIDIClient_Create](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_midiclient_create) interface, the application can obtain a list of all currently connected MIDI devices and listen for device hot-plug events ([OH_MIDICallback_OnDeviceChange](../../reference/apis-audio-kit/capi-native-midi-base-h.md#oh_midicallback_ondevicechange)) and system-level errors ([OH_MIDICallback_OnError](../../reference/apis-audio-kit/capi-native-midi-base-h.md#oh_midicallback_onerror)) through registered callbacks.

When closing the client, the system automatically closes all devices and ports opened under that client (automatic resource reclamation mechanism). It is recommended that applications actively release resources in reverse order (port → device → client) to ensure clear code logic.

## OH_MIDI Device

A MIDI device refers to a physical or virtual MIDI interface device, including USB MIDI keyboards, Bluetooth MIDI controllers, and so on. After a device is connected, the MIDI service assigns it an identifier (`midiDeviceId` in [OH_MIDIDeviceInformation](../../reference/apis-audio-kit/capi-ohmidi-oh-midideviceinformation.md)), which is used to distinguish and manage different devices within the current session.

Device information includes attributes such as device type (USB or Bluetooth), native protocol capability, device name, vendor ID, product ID, and device address.

**Connection method:** USB devices are opened synchronously through the [OH_MIDIClient_OpenDevice](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_midiclient_opendevice) API, while Bluetooth Low Energy (BLE) MIDI devices need to be connected asynchronously through the [OH_MIDIClient_OpenBLEDevice](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_midiclient_openbledevice) API.

**Native protocol capability:** Indicates the current communication protocol mode of the device. In the current version, when a device supports multiple protocols, the system prioritizes communication with the device in MIDI 1.0 mode and encapsulates the data into MIDI 2.0 UMP format at the MIDI service layer for the application.

## OH_MIDI Port

A MIDI port is a data transmission endpoint on a device, categorized into input ports and output ports.

* Input port: Used to receive MIDI data from a device. Open and register the [OH_MIDIDevice_OnReceived](../../reference/apis-audio-kit/capi-native-midi-base-h.md#oh_mididevice_onreceived) callback via the [OH_MIDIDevice_OpenInputPort](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_mididevice_openinputport) API to enable batch message reception.

  Data flow description: The MIDI device sends data to the application, and the application receives it through the callback.

* Output port: Used to send MIDI data to a device. After opening the output port via the [OH_MIDIDevice_OpenOutputPort](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_mididevice_openoutputport) API, use the [OH_MIDIDevice_Send](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_mididevice_send) API to send UMP format messages.

  Data flow description: The application calls the [OH_MIDIDevice_Send](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_mididevice_send) API to send data to the MIDI device.

``` Text
[App] <--Receive-- [Input port] <-- [Device]
[App] --Send--> [Output port] --> [Device]
```

Each device can have multiple input and output ports. When each port is opened, the desired protocol behavior can be configured through the [OH_MIDIPortDescriptor](../../reference/apis-audio-kit/capi-ohmidi-oh-midiportdescriptor.md) structure.

* Data conversion: Regardless of whether the underlying device is MIDI 1.0 or 2.0, the application layer uniformly sends and receives UMP packets.

* Protocol downgrade: If an application requests to send a MIDI 2.0 high-precision message (UMP Type 4), but the underlying device only supports MIDI 1.0, the MIDI service layer automatically downgrades and converts it to a MIDI 1.0 message for sending.

* Automatic conversion note: On the receive side, the system service layer automatically converts the underlying protocol data into UMP format for application processing. However, on the send side, the application must construct the [OH_MIDIEvent](../../reference/apis-audio-kit/capi-ohmidi-oh-midievent.md) data according to the UMP specification.

## OH_MIDI Event

A MIDI event is the basic unit of MIDI data transmission. **OH_MIDI** mandates the use of the UMP format, which uniformly carries MIDI 1.0 and MIDI 2.0 data.

Each event contains three core fields:

* Timestamp: Value range is [0, 2^63-1], in nanoseconds. 0 indicates immediate sending.

* Data length: Indicates the number of 32-bit words in the data array. Value range is [1, 128].

* UMP data pointer: Points to a 4-byte aligned uint32_t array.

### Complete Message Type Reference

The UMP format distinguishes different messages by message type. It is the upper 4 bits of a UMP packet, determining the functional scope, packet size, and status field size of the message.

| MT Value | Name | Size (bit) | Description |
|------|------|------|------|
| 0x0 | Utility Messages | 32 | Utility messages, such as [JR](#glossary) timestamps. |
| 0x1 | System Real Time and System Common Messages | 32 | System real-time messages and system common messages (excluding System Exclusive). |
| 0x2 | MIDI 1.0 Channel Voice Messages | 32 | MIDI 1.0 channel voice messages, compatible with existing devices. |
| 0x3 | Data Messages | 64 | Data messages, such as [SysEx](#glossary) (including System Exclusive). |
| 0x4 | MIDI 2.0 Channel Voice Messages | 64 | MIDI 2.0 high-resolution [Channel Voice](#glossary) messages. |
| 0x5 | Data Messages | 128 | Data messages. |
| 0x6 | Reserved | 32 | Reserved for future use. |
| 0x7 | Reserved | 32 | Reserved for future use. |
| 0x8 | Reserved | 64 | Reserved for future use. |
| 0x9 | Reserved | 64 | Reserved for future use. |
| 0xA | Reserved | 64 | Reserved for future use. |
| 0xB | Reserved | 96 | Reserved for future use. |
| 0xC | Reserved | 96 | Reserved for future use. |
| 0xD | Flex Data Messages | 128 | [Flex Data](#glossary) flexible data messages, such as text and lyrics. |
| 0xE | Reserved | 128 | Reserved for future use. |
| 0xF | UMP Stream Messages | 128 | UMP stream messages, such as endpoint discovery and function block configuration. |

> **NOTE**
>
> - In most application scenarios, you only need to use MT 0x2 (MIDI 1.0 channel voice) and MT 0x4 (MIDI 2.0 channel voice) to send and receive MIDI notes.
> - The `events` array and the `data` pointers it contains in the receive callback are only valid during the callback execution. If the app needs to retain MIDI data for subsequent processing, it must deep copy the data into its own memory before the callback returns to avoid undefined behavior caused by accessing expired pointers.

## Glossary

| Term | Full Name | Description |
|------|------|------|
| UMP | Universal MIDI Packet | A universal MIDI data packet in a 32-bit aligned unified container format. |
| MT | Message Type | Message type, the upper 4 bits of a UMP data packet, which determines the message function and size. |
| SysEx | System Exclusive | System exclusive message used for vendor-defined data transmission. |
| JR | Jitter Reduction | Jitter reduction, a timestamp synchronization mechanism for network/Bluetooth transmission. |
| Channel Voice | Channel Voice | A core message type that controls notes, velocity, controllers, and more. |
| Flex Data | Flex Data | New in MIDI 2.0, supports 128-bit long messages such as text and lyrics. |
| MIDI-CI | MIDI Capability Inquiry | MIDI capability inquiry, an automatic device configuration protocol for MIDI 2.0. |

## Constraints

- Limit on the number of simultaneously opened devices: A single client can open a maximum of 16 MIDI devices at the same time. When the limit is exceeded, the [OH_MIDIClient_OpenDevice](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_midiclient_opendevice) API will return the **OH_MIDI_STATUS_TOO_MANY_OPEN_DEVICES** error.

- Port limit per device: Each MIDI device can have a maximum of 64 ports (total of input and output). A single client can open a maximum of 64 ports simultaneously. When the limit is exceeded, the [OH_MIDIDevice_OpenInputPort](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_mididevice_openinputport) or [OH_MIDIDevice_OpenOutputPort](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_mididevice_openoutputport) API will return the **OH_MIDI_STATUS_TOO_MANY_OPEN_PORTS** error.

- Buffer size limit: The shared memory buffer size is 4 KB. When sending a large number of MIDI messages, if the buffer is full, the [OH_MIDIDevice_Send](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_mididevice_send) API will return **OH_MIDI_STATUS_WOULD_BLOCK**. In this case, send messages in batches and retry after a 10 ms delay.

- Thread model and callback execution environment: All callbacks ([OH_MIDIDevice_OnReceived](../../reference/apis-audio-kit/capi-native-midi-base-h.md#oh_mididevice_onreceived), [OH_MIDICallback_OnDeviceChange](../../reference/apis-audio-kit/capi-native-midi-base-h.md#oh_midicallback_ondevicechange), [OH_MIDICallback_OnError](../../reference/apis-audio-kit/capi-native-midi-base-h.md#oh_midicallback_onerror)) are executed on a high-priority system thread. Avoid performing blocking operations, computationally intensive tasks, or I/O operations in the callback, as they may affect the real-time performance of the MIDI system.

- Memory safety: The `events` array and the data pointers it contains in the [OH_MIDIDevice_OnReceived](../../reference/apis-audio-kit/capi-native-midi-base-h.md#oh_mididevice_onreceived) callback are only valid during the callback. If data needs to be retained, it must be copied before the callback returns. Accessing invalid or expired pointers results in undefined behavior, which may cause crashes or memory corruption.

- Resource management order: All devices and ports are automatically closed when the client is closed. It is recommended that applications close resources in reverse order to ensure clear code logic.

  - Step 1: Close all ports ([OH_MIDIDevice_CloseInputPort](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_mididevice_closeinputport)/[OH_MIDIDevice_CloseOutputPort](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_mididevice_closeoutputport)).

  - Step 2: Close all devices ([OH_MIDIClient_CloseDevice](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_midiclient_closedevice)).

  - Step 3: Destroy the client ([OH_MIDIClient_Destroy](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_midiclient_destroy)).

  The order is recommended to keep the code clear and maintainable. The system automatically reclaims resources to ensure that they are released properly.

- Differences in device type characteristics:

  - USB MIDI device: Connects via USB, supports low-latency transmission, and device enumeration is completed through the system USB driver.

  - Bluetooth MIDI device: Connects via Bluetooth BLE, requires the `ohos.permission.ACCESS_BLUETOOTH` permission, and is opened asynchronously using [OH_MIDIClient_OpenBLEDevice](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_midiclient_openbledevice).

## References

- [Using OH_MIDI for MIDI Development (C/C++)](using-ohmidi.md)

- [OHMIDI API Reference](../../reference/apis-audio-kit/capi-ohmidi.md)

- MIDI status code enums: [OH_MIDIStatusCode](../../reference/apis-audio-kit/capi-native-midi-base-h.md#oh_midistatuscode)