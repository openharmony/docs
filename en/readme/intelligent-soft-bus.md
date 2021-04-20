# Intelligent Soft Bus<a name="EN-US_TOPIC_0000001051344287"></a>

-   [Overview](#section11660541593)
-   [Directory Structure](#section1464106163817)
-   [Constraints](#section1718733212019)
-   [Usage](#section167037358130)
-   [Repositories Involved](#section4499619123117)

## Overview<a name="section11660541593"></a>

The use of different communication modes \(such as USB, WLAN, and Bluetooth\) varies greatly and is complex. In addition, the convergence, sharing, and conflicts between communication links cannot be resolved, and communication security is difficult to guarantee. The distributed communication subsystem manages unified distributed communication between near-field devices and provides device discovery and data transmission APIs that apply to all links. Currently, the following features are available:

-   Service publishing: After a service is published, peripheral devices can discover and use it.
-   Data transmission: A session is established based on the service name and device ID to transmit data between services.
-   Security: Communication data is encrypted.

You can use APIs of the distributed communication subsystem to implement fast and secure communication between devices without caring about management of communication details, thereby achieving cross-platform development.

## Directory Structure<a name="section1464106163817"></a>

```
/foundation/communication/softbus_lite/
├── authmanager         # Device authentication mechanism and device knowledge library management
├── discovery           # Device discovery based on CoAP
├── os_adapter          # OS adaption code
└── trans_service       # Authentication and transmission channels
```

## Constraints<a name="section1718733212019"></a>

**Language**: C

**Networking**: Devices must be in the same LAN.

**Operating system**: OpenHarmony

## Usage<a name="section167037358130"></a>

1.  **Device discovery**

    When using device discovery, ensure that the device to perform a discovery and the device to discover are in the same LAN and the devices can receive packets from each other.

    a. After a device sends a discovery request, it uses Constrained Application Protocol \(CoAP\) to send a broadcast packet in the LAN.

    b. The discovered device uses the  **PublishService**  API to publish services. After receiving the broadcast packet, the device sends a CoAP unicast packet to the device that performs the discovery.

    c. After receiving the packet, the device that performs the discovery updates device information.

2.  **Transmission**

The soft bus provides unified session-based transmission. Services can receive and send data or obtain basic attributes through  **sessionId**. Currently, services can determine whether to accept a received session based on the service requirements and session attributes. Currently, sessions cannot be enabled.

## Repositories Involved<a name="section4499619123117"></a>

**Intelligent Soft Bus subsystem**

[communication\_softbus\_lite](https://gitee.com/openharmony/communication_softbus_lite/blob/master/README.md)

[communication\_ipc\_lite](https://gitee.com/openharmony/communication_ipc_lite/blob/master/README.md)

[communication\_wifi\_aware](https://gitee.com/openharmony/communication_wifi_aware/blob/master/README.md)

