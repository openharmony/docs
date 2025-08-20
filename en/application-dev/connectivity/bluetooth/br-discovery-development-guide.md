# Bluetooth Discovery Development

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @chengguohong; @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->

## Introduction
This document describes how to implement the Bluetooth device discovery capabilities, such as scanning for nearby devices, setting the Bluetooth scan mode, and retrieving information about paired devices.

## How to Develop

### Applying for Required Permissions
Apply for the **ohos.permission.ACCESS_BLUETOOTH** permission. For details about how to configure and apply for permissions, see [Declaring Permissions](../../security/AccessToken/declare-permissions.md) and [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).

### Importing Required Modules
Import the **connection** and **BusinessError** modules.
```ts
import { connection } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';
```

### Scanning for Nearby Bluetooth Devices
This function allows your application to scan for nearby Bluetooth devices and obtain partial information about them. This process can also be referred to as search, discovery, or find. Only nearby Bluetooth devices that are in a discoverable state can be scanned by the local Bluetooth device.

**1. Subscribing to Scan Result Reporting Events**<br>
- You are advised to use the scan result reporting mode supported since API version 18. This allows you to obtain more device information, including the device address, signal strength, name, and type. For details, see [connection.on('discoveryResult')](../../reference/apis-connectivity-kit/js-apis-bluetooth-connection.md#connectionondiscoveryresult18).
```ts
// Define the callback for scan result reporting events.
function onReceiveEvent(data: Array<connection.DiscoveryResult>) {
  console.info('bluetooth device: '+ JSON.stringify(data));
}

try {
  // Subscribe to scan result reporting events.
  connection.on('discoveryResult', onReceiveEvent);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```
- The scan result reporting mode in API version 17 or earlier can retrieve only the device address information. For details, see [connection.on('bluetoothDeviceFind')](../../reference/apis-connectivity-kit/js-apis-bluetooth-connection.md#connectiononbluetoothdevicefind).
```ts
// Define the callback for scan result reporting events.
function onReceiveEvent(data: Array<string>) {
  console.info('bluetooth device: '+ JSON.stringify(data));
}

try {
  // Subscribe to scan result reporting events.
  connection.on('bluetoothDeviceFind', onReceiveEvent);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

**2. Initiating a Device Scan**<br>
A scan process takes about 12 seconds after being initiated. The application can initiate pairing, connection, and data transmission with the discovered Bluetooth device. For details, see [Device Pairing](br-pair-device-development-guide.md) and [SPP-based Connection and Data Transmission](spp-development-guide.md).
```ts
try {
  // Check whether scanning is in progress on the local device.
  let scan = connection.isBluetoothDiscovering();
  if (!scan) {
    // Start scanning for devices if a scan is not in progress.
    connection.startBluetoothDiscovery();
  }
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```
**3. Stopping the Device Scan**<br>
Scanning is a process that consumes a large amount of Bluetooth hardware resources. When the expected Bluetooth device is discovered, the device scanning must be stopped before a connection is initiated.
```ts
// Define the callback for scan result reporting events.
function onReceiveEvent(data: Array<string>) {
  console.info('bluetooth device: '+ JSON.stringify(data));
}

try {
  // Check whether scanning is in progress on the local device.
  let scan = connection.isBluetoothDiscovering();
  if (scan) {
    // Stop scanning for devices if a scan is in progress.
    connection.stopBluetoothDiscovery();
  }
  // If scanning is no longer needed, unsubscribe from scan result reporting events.
  connection.off('bluetoothDeviceFind', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### Setting the Bluetooth Scan Mode of the Local Device
The Bluetooth scan mode of the local device determines whether the local device can be scanned or connected by other Bluetooth devices. Typically, non-system applications do not need to concern themselves with this mode, as the system settings application will handle its configuration.
- If the Bluetooth settings screen is in the foreground when Bluetooth has been enabled, the Bluetooth scan mode of the local device is set to [SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE](../../reference/apis-connectivity-kit/js-apis-bluetooth-connection.md#scanmode). In this mode, the local device can be discovered by other Bluetooth devices and can accept incoming connections
- If the Bluetooth settings screen is in the background when Bluetooth has been enabled, the Bluetooth scan mode of the local device is set to [SCAN_MODE_CONNECTABLE](../../reference/apis-connectivity-kit/js-apis-bluetooth-connection.md#scanmode). In this mode, the local device can accept incoming connections but cannot be discovered by other Bluetooth devices.

```ts
try {
  // Obtain the current scan mode of the local device.
  let scanMode: connection.ScanMode = connection.getBluetoothScanMode();
  console.info('scanMode: ' + scanMode);
  if (scanMode != connection.ScanMode.SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE) {
    // Set the scan mode of the local device to SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE.
    connection.setBluetoothScanMode(connection.ScanMode.SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE, 0);
  }
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### Retrieving Information About Paired Devices
To streamline device scanning, check if the device is paired before initiating a scan. You can also initiate connection and data transmission processes for paired devices. For details, see [Device Pairing](br-pair-device-development-guide.md) and [SPP-based Data Transmission](spp-development-guide.md).

```ts
try {
  // Obtain information about the paired devices.
  let devices = connection.getPairedDevices();
  console.info('pairedDevices: ' + JSON.stringify(devices));
  // If the device address is known, check whether the device has been paired.
  if (devices.length > 0) {
    let pairState = connection.getPairState(devices[0]);
    console.info('device: '+ devices[0] + ' pairState is ' + pairState);
  }
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## Sample Code
```ts
import { connection } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export class DiscoveryDeviceManager {
  // Define the callback for scan result reporting events.
  onReceiveEvent = (data: Array<string>) => {
    console.info('bluetooth device: '+ JSON.stringify(data));
  };

  public startDiscovery() {
    try {
      connection.on('bluetoothDeviceFind', this.onReceiveEvent);
    } catch (err) {
      console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
    try {
      // Check whether scanning is in progress on the local device.
      let scan = connection.isBluetoothDiscovering();
      if (!scan) {
        // Start scanning for devices if a scan is not in progress.
        connection.startBluetoothDiscovery();
      }
    } catch (err) {
      console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  public stopDiscovery() {
    try {
      // Check whether scanning is in progress on the local device.
      let scan = connection.isBluetoothDiscovering();
      if (scan) {
        // Stop scanning for devices if a scan is in progress.
        connection.stopBluetoothDiscovery();
      }
      // If scanning is no longer needed, unsubscribe from scan result reporting events.
      connection.off('bluetoothDeviceFind', this.onReceiveEvent);
    } catch (err) {
      console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  public setScanMode() {
    try {
      // Obtain the current scan mode of the local device.
      let scanMode: connection.ScanMode = connection.getBluetoothScanMode();
      console.info('scanMode: ' + scanMode);
      if (scanMode != connection.ScanMode.SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE) {
        // Set the scan mode of the local device to SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE.
        connection.setBluetoothScanMode(connection.ScanMode.SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE, 0);
      }
    } catch (err) {
      console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  public getPairedDevices() {
    try {
      // Obtain information about the paired devices.
      let devices = connection.getPairedDevices();
      console.info('pairedDevices: ' + JSON.stringify(devices));
      // If the device address is known, check whether the device has been paired.
      if (devices.length > 0) {
        let pairState = connection.getPairState(devices[0]);
        console.info('device: '+ devices[0] + ' pairState is ' + pairState);
      }
    } catch (err) {
      console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }
}

let discoveryDeviceManager = new DiscoveryDeviceManager();
export default discoveryDeviceManager as DiscoveryDeviceManager;
```
