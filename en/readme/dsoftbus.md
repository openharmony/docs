# DSoftBus<a name="EN-US_TOPIC_0000001090266209"></a>

## Introduction<a name="section11660541593"></a>

The DSoftBus subsystem provides communication capabilities for OpenHarmony, including WLAN, Bluetooth, DSoftBus, and remote procedure call \(RPC\).

WLAN: basic WLAN functions, peer-to-peer \(P2P\) connection, and WLAN notification, enabling your application to communicate with other devices through a WLAN

Bluetooth: classic Bluetooth and Bluetooth Low Energy \(BLE\)

DSoftBus: distributed communications between near-field devices, and device discovery, connection setup, networking, and data transmission capabilities regardless of communication modes

RPC: communications between processes on a device or across devices

## Architecture<a name="section342962219551"></a>

**Figure  1**  DSoftBus subsystem architecture<a name="fig4460722185514"></a>  


![](figures/dsoftbus.png)

## Directory Structure<a name="section161941989596"></a>

The main code directory structure of the DSoftBus subsystem is as follows:

```
/foundation/communication
├── bluetooth       # Bluetooth code
├── dsoftbus        # DSoftBus code
├── ipc             # IPC code
└── wifi            # WLAN code
```

## Constraints<a name="section119744591305"></a>

-   Networking: Devices must be in the same LAN.

## Usage Guidelines<a name="section1312121216216"></a>

### RPC<a name="section129654513264"></a>

In RPC, the requesting process \(client\) can obtain the proxy of the process that provides the service \(server\). Through the proxy, the two processes can communicate with each other.

1.  Implement the server and its capabilities.
2.  To be more specific, the client obtains a proxy of the server. This proxy provides the same capabilities as the server. Then the client can call a method of the server by accessing the corresponding method of the proxy. The proxy forwards the request to the server.
3.  The server processes the received request and returns the result to the proxy via the driver.
4.  The proxy returns the result to the client.

### DSoftBus<a name="section36252592710"></a>

-   Networking

1.  After the service is started, obtain the list of online devices.
2.  Register a listener for device status changes.
3.  Obtain the device ID, name, and type.
4.  Obtain extended information about the device, such as the device type, networking type, and device capability.
5.  Delete the registered listener.

-   Transmission

1.  Create a session server and register a callback.
2.  After a device goes online, open a session with the device.
3.  Send data through the session.
4.  Close the session if you no longer need it.
5.  Remove the created session server if you no longer want to use distributed transmission \(such as exiting the process\).

## Repositories Involved<a name="section1371113476307"></a>

**DSoftBus subsystem**

[communication\_bluetooth](https://gitee.com/openharmony/communication_bluetooth)

[communication\_dsoftbus](https://gitee.com/openharmony/communication_dsoftbus)

[communication\_ipc](https://gitee.com/openharmony/communication_ipc)

[communication\_wifi](https://gitee.com/openharmony/communication_wifi)

