# HID Device Development

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=14ca614ebb030bf413b2d8393352ad7521a1d1b9 translatedAt=2026-08-15T01:40:45.953Z pushedAt=2026-08-15T04:20:55.556Z -->

## Overview

This guide primarily provides development instructions for simulating a device as a Bluetooth keyboard, mouse, gamepad, or other input device based on the Human Interface Device Profile ([HID](terminology.md#hid)). In the HID device communication model, roles can be distinguished as [HID host](terminology.md#hid-host) and [HID device](terminology.md#hid-device) based on device capabilities. This guide focuses on how to provide HID device capabilities for an app, connect to other Bluetooth HID hosts (such as PCs, tablets, and phones), and perform data interaction.

## Implementation Principles

As the provider of input capabilities, the HID device must first register HID device capabilities for the local application and declare its function type (such as keyboard or mouse) and the corresponding HID report descriptor.

After obtaining the device address of the HID host, the HID device can actively initiate a connection to the paired HID host. The HID host address can be obtained through the device discovery process. For details, see [Device Discovery](br-discovery-development-guide.md). After the connection is successfully established, the HID device can actively send HID reports (such as keyboard key presses and mouse movement data) to the host through the established channel. Upon receiving the report, the host parses it into standard input events.

Either the HID device or the HID host can actively disconnect. The application needs to determine which side performs the disconnection based on the actual scenario.

## How to Develop

### Requesting Bluetooth Permissions

The **ohos.permission.ACCESS_BLUETOOTH** permission must be requested. For details about how to configure and request permissions, see [Declaring Permissions](../../security/AccessToken/declare-permissions.md) and [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).

### Importing Required Modules

Import the **baseProfile**, **hid**, and **common** modules.

```ts
import { baseProfile, hid, common } from '@kit.ConnectivityKit';
```

### Device Side

**1. Register an HID device.**<br>
The application first registers the HID device capabilities. After receiving the registration request, the system binds the application to the HID device role at the Bluetooth layer and publishes the corresponding HID service record in the Service Discovery Protocol. The registration result is returned via a callback function. After successful registration, the application enters a connectable state, awaiting subsequent operations.

```ts
let descriptors: Uint8Array = new Uint8Array([
    // Descriptor example, which must comply with the USB HID specification
    0x05, 0x01,        // Generic desktop control
    0x09, 0x06,        // Keyboard
    0xA1, 0x01,        // Application collection begins
    
    // Key field definition
    0x05, 0x07,        // Switch to keyboard/keypad
    0x19, 0x00,        // Define the minimum key code as 0 (no key pressed)
    0x29, 0x01,        // Define the maximum key code as 1 (only supports 2 values)
    0x15, 0x00,        // Logical minimum 0 (lower limit of the data range)
    0x25, 0x01,        // Logical maximum 1 (upper limit of the data range)
    0x75, 0x08,        // Eight bits per field
    0x95, 0x01,        // Only one field
    0x81, 0x00,        // Define input field: data field (key array)
    
    // End device definition
    0xC0               // End application collection
]);
// Take the keyboard as an example
let sdp: hid.HidDeviceSdp = {
    "name": "testName",
    "description": "testDescription",
    "provider": "testProvider",
    "subclass": hid.Subclass.SUBCLASS_KEYBOARD,
    "descriptors": descriptors,
};
let inqos: hid.HidDeviceQos = {
    "serviceType": hid.ServiceType.SERVICE_BEST_EFFORT,
    "tokenRate": 0,
    "tokenBucketSize": 0,
    "peakBandwidth": 0,
    "latency": -1,
    "delayVariation": -1,
};

let outqos: hid.HidDeviceQos = {};
function registerStateCallback(callback: boolean) {
    console.info(`state: ${callback}`);
}

try {
    let hidDevice: hid.HidDeviceProfile = hid.createHidDeviceProfile();
    hidDevice.registerHidDevice(sdp, inqos, outqos, registerStateCallback)
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

**2. Connect to an HID host.**<br>

After the application discovers the target device through the device discovery process, it can initiate a connection. Upon receiving the connection request, the system checks whether the target device supports the HID host role and has established the necessary security pairing. After verification, the system automatically establishes the HID control channel and interrupt data transfer channel. Once the connection is successfully established, the application receives a connection status callback notification. At this point, a complete protocol link has been established between the HID device and the host, enabling report transmission capabilities.

```ts
function onConnectionStateChangedevent(callback: baseProfile.StateChangeParam) {
    let StateChangeParam = callback;
    console.info(`deviceId: ${StateChangeParam.deviceId}, state: ${StateChangeParam.state}`);
}

let device: common.BluetoothAddress = {
    "address": "11:22:33:44:55:66",
    "addressType": common.BluetoothAddressType.REAL,
}
try {
    let hidDevice: hid.HidDeviceProfile = hid.createHidDeviceProfile();
    hidDevice.onConnectionStateChange(onConnectionStateChangedevent); // Subscribe to connection state callback events.
    hidDevice.connect(device);
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

**3. Transmit data.**<br>

**3.1 Send data.**<br>
After the connection is established, the application can exchange data with the HID host. [sendReport](../../reference/apis-connectivity-kit/js-apis-bluetooth-hid.md#sendreport23) is used to actively send input reports (such as key events and coordinate data) to the host. [replyReport](../../reference/apis-connectivity-kit/js-apis-bluetooth-hid.md#replyreport23) is used to respond to the host's request for report retrieval, returning the current device status or characteristic data. [reportError](../../reference/apis-connectivity-kit/js-apis-bluetooth-hid.md#reporterror23) is used to notify the host of exceptions when report transmission fails or a format error occurs.

```ts
let hidDevice: hid.HidDeviceProfile = hid.createHidDeviceProfile();

let reportData: Uint8Array = new Uint8Array([0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77]);
let id: number = 0;
try {
    hidDevice.sendReport(id, reportData);  // Send input reports.
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}

let type = hid.ReportType.REPORT_TYPE_INPUT;
let replyData: Uint8Array = new Uint8Array([0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77]);
try {
    hidDevice.replyReport(type, id, replyData);  // Respond to get report requests.
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}

let error = hid.ErrorReason.RSP_SUCCESS;
try {
    hidDevice.reportError(error);  // Report abnormal situations.
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

**3.2 Receive data.**<br>
The HID device can subscribe to relevant events to respond to requests from the HID host in real time and receive sent data.

- **GET_REPORT** event: a host-initiated data read request, used to obtain status information from the HID device.

- **SET_REPORT** event: a host-initiated data write request, used to send control commands to the HID device.

- **SET_PROTOCOL** event: a host-initiated protocol mode switch request.

- Interrupt data receive event: handles real-time data sent by the HID host through the interrupt channel.

- Virtual link status event: handles virtual link status change notifications.

```ts
function onGetReportReceiveEvent(callback: hid.GetReportData) {
    console.info(`type: ${callback.type}, id: ${callback.id}, bufferSize: ${callback.bufferSize}`);
}

function onSetReportReceiveEvent(callback: hid.SetReportData) {
    console.info(`type: ${callback.type}, id: ${callback.id}, dataSize: ${callback.data.length}`);
}

function onInterruptDataReceiveEvent(callback: hid.InterruptData) {
    console.info(`id: ${callback.id}, dataSize: ${callback.data.length}`);
}

function onSetProtocolReceiveEvent(callback: hid.ProtocolData) {
    console.info(`protocol: ${callback.protocol}`);
}

function onVirtualCableUnplugReceiveEvent() {
    console.info(`onVirtualCableUnplug`);
}

try {
    let hidDevice: hid.HidDeviceProfile = hid.createHidDeviceProfile();
    hidDevice.onGetReport(onGetReportReceiveEvent);    // Subscribe to GET_REPORT events.
    hidDevice.onSetReport(onSetReportReceiveEvent); // Subscribe to SET_REPORT events.
    hidDevice.onInterruptDataReceived(onInterruptDataReceiveEvent); // Subscribe to interrupt data receive events.
    hidDevice.onSetProtocol(onSetProtocolReceiveEvent); // Subscribe to SET_PROTOCOL events.
    hidDevice.onVirtualCableUnplug(onVirtualCableUnplugReceiveEvent);   // Subscribe to virtual link status events.
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

**4. Disconnect from the HID host.**<br>
The application can actively disconnect from the current HID host. After the connection is disconnected, the system will release the relevant protocol channel resources, and the application will receive a connection state change callback. At this point, the application can choose to reconnect to another host or remain in the ready state to wait for a new connection.

```ts
try {
    let hidDevice: hid.HidDeviceProfile = hid.createHidDeviceProfile();
    hidDevice.disconnect();
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

**5. Unregister the HID device.**<br>
When the application no longer needs to provide HID device capabilities, it can actively unregister. This operation removes the HID device role binding from the system Bluetooth service, clears service discovery records, and releases all related resources. After unregistration, the application can no longer be identified as an HID device, all existing connections will be forcibly disconnected, and new connections cannot be established.

```ts
try {
    let hidDevice: hid.HidDeviceProfile = hid.createHidDeviceProfile();
    hidDevice.unregisterHidDevice();
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

## Example

### Device Side

```ts
import { baseProfile, hid, common } from '@kit.ConnectivityKit';

class HidDeviceManager {
    device: common.BluetoothAddress = {
        "address": "11:22:33:44:55:66",
        "addressType": common.BluetoothAddressType.REAL,
    }
    descriptors: Uint8Array = new Uint8Array([
        // Descriptor example, must comply with USB HID specifications
        0x05, 0x01,        // Generic desktop control
        0x09, 0x06,        // Keyboard
        0xA1, 0x01,        // Application collection begins

        // Key field definition
        0x05, 0x07,        // Switch to keyboard/keypad
        0x19, 0x00,        // Define the minimum key code as 0 (no key pressed)
        0x29, 0x01,        // Define the maximum key code as 1 (supports only 2 values)
        0x15, 0x00,        // Logical minimum 0 (lower limit of the data range)
        0x25, 0x01,        // Logical maximum 1 (upper limit of the data range)
        0x75, 0x08,        // Eight bits per field
        0x95, 0x01,        // Only one field
        0x81, 0x00,        // Define input field: data field (key array)

        // End device definition
        0xC0               // End application collection
    ]);
    // Take keyboard as an example
    sdp: hid.HidDeviceSdp = {
        "name": "testName",
        "description": "testDescription",
        "provider": "testProvider",
        "subclass": hid.Subclass.SUBCLASS_KEYBOARD,
        "descriptors": this.descriptors,
    };
    inqos: hid.HidDeviceQos = {
        "serviceType": hid.ServiceType.SERVICE_BEST_EFFORT,
        "tokenRate": 0,
        "tokenBucketSize": 0,
        "peakBandwidth": 0,
        "latency": -1,
        "delayVariation": -1,
    };
    outqos: hid.HidDeviceQos = {};
    hidDevice: hid.HidDeviceProfile | undefined = undefined;

// Register HID device
  public registerHidDevice() {
    this.hidDevice = hid.createHidDeviceProfile();  // Construct the HID device. Subsequent interactions require the use of this instance.
    try {
        this.hidDevice.registerHidDevice(this.sdp, this.inqos, this.outqos, this.registerStateCallback);
        this.hidDevice.onGetReport(this.onGetReportReceiveEvent);    // Subscribe to GET_REPORT events.
        this.hidDevice.onSetReport(this.onSetReportReceiveEvent); // Subscribe to SET_REPORT events.
        this.hidDevice.onInterruptDataReceived(this.onInterruptDataReceiveEvent); // Subscribe to interrupt data receive events.
        this.hidDevice.onSetProtocol(this.onSetProtocolReceiveEvent); // Subscribe to SET_PROTOCOL events.
        this.hidDevice.onVirtualCableUnplug(this.onVirtualCableUnplugReceiveEvent);   // Subscribe to virtual link status events.
        this.hidDevice.onConnectionStateChange(this.onConnectionStateChangedevent); // Subscribe to connection state change events.
    } catch (err) {
        console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
    }
  }

  // Unregister HID device
  public unregisterHidDevice() {
    if (!this.hidDevice) {
        console.error('hid device not exist');
        return;
    }
    try {
        this.hidDevice.unregisterHidDevice();
        this.hidDevice.offGetReport(this.onGetReportReceiveEvent);    // Unsubscribe from GET_REPORT Event
        this.hidDevice.offSetReport(this.onSetReportReceiveEvent); // Unsubscribe from SET_REPORT events.
        this.hidDevice.offInterruptDataReceived(this.onInterruptDataReceiveEvent); // Unsubscribe from interrupt data receive events.
        this.hidDevice.offSetProtocol(this.onSetProtocolReceiveEvent); // Unsubscribe from SET_PROTOCOL events.
        this.hidDevice.offVirtualCableUnplug(this.onVirtualCableUnplugReceiveEvent);   // Unsubscribe from virtual link status events.
        this.hidDevice.offConnectionStateChange(this.onConnectionStateChangedevent); // Unsubscribe from connection state change events.
    } catch (err) {
        console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
    }
  }

    registerStateCallback = (callback: boolean) => {
        console.info(`state: ${callback}`);
    };

    onGetReportReceiveEvent = (callback: hid.GetReportData) => {
        console.info(`type: ${callback.type}, id: ${callback.id}, bufferSize: ${callback.bufferSize}`);
    };


    onSetReportReceiveEvent = (callback: hid.SetReportData) => {
        console.info(`type: ${callback.type}, id: ${callback.id}, dataSize: ${callback.data.length}`);
    };

    onInterruptDataReceiveEvent = (callback: hid.InterruptData) =>  {
        console.info(`id: ${callback.id}, dataSize: ${callback.data.length}`);
    };

    onSetProtocolReceiveEvent = (callback: hid.ProtocolData) => {
        console.info(`protocol: ${callback.protocol}`);
    };

    onVirtualCableUnplugReceiveEvent = () => {
        console.info(`onVirtualCableUnplug`);
    };

    onConnectionStateChangedevent = (callback : baseProfile.StateChangeParam) => {
        let StateChangeParam = callback;
        console.info(`deviceId: ${StateChangeParam.deviceId}, state: ${StateChangeParam.state}`);
    };

  // Connect to HID host
  public hidConnect(device: common.BluetoothAddress) {
    if (!this.hidDevice) {
        console.error('hid device not exist');
        return;
    }
    try {
        this.hidDevice.connect(device);
    } catch (err) {
        console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
    }
  }

  // Disconnect HID connection
  public hidDisconnect() {
    if (!this.hidDevice) {
        console.error('hid device not exist');
        return;
    }
    try {
        this.hidDevice.disconnect();
    } catch (err) {
        console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
    }
  }

  // Send report
  public hidSendReport() {
    if (!this.hidDevice) {
        console.error('hid device not exist');
        return;
    }
    let reportData: Uint8Array = new Uint8Array([0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77]);
    let id: number = 0;
    try {
        this.hidDevice.sendReport(id, reportData);
    } catch (err) {
        console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
    }
  }

  // Reply report
  public hidReplyReport() {
    if (!this.hidDevice) {
        console.error('hid device not exist');
        return;
    }
    let type = hid.ReportType.REPORT_TYPE_INPUT;
    let id: number = 0;
    let reportData: Uint8Array = new Uint8Array([0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77]);
    try {
        this.hidDevice.replyReport(type, id, reportData);
    } catch (err) {
        console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
    }
  }

  // Report error
  public hidReportError() {
    if (!this.hidDevice) {
        console.error('hid device not exist');
        return;
    }
    let error = hid.ErrorReason.RSP_SUCCESS;
    try {
        this.hidDevice.reportError(error);
    } catch (err) {
        console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
    }
  }
}

let hidDeviceServerManager = new HidDeviceManager();
export default hidDeviceServerManager as HidDeviceManager;
```