# Bluetooth Setting

## Introduction

This topic walks you through on how to implement basic Bluetooth settings, including enabling and disabling Bluetooth and obtaining Bluetooth status.

## When to Use

You can use the APIs provided by the **access** module to:

- Enable and disable Bluetooth.

## Available APIs

For details about the APIs and sample code, see [@ohos.bluetooth.access](../../reference/apis-connectivity-kit/js-apis-bluetooth-access.md).

The following table describes the related APIs.

| API                            | Description                                                                      |
| ---------------------------------- | ------------------------------------------------------------------------------ |
| enableBluetooth()                  | Enables Bluetooth.                                                                      |
| disableBluetooth()                 | Disables Bluetooth.                                                                      |
| getState()                         | Obtains the Bluetooth state.                                                               |
| on(type: 'stateChange')            | Subscribes to Bluetooth state changes.                                                        |
| off(type: 'stateChange')           | Unsubscribes from Bluetooth state changes.                                                    |


## How to Develop

### Enabling and Disabling Bluetooth
1. Import the **access** module.
2. Check that the SystemCapability.Communication.Bluetooth.Core capability is available.
3. Apply for the **ohos.permission.ACCESS_BLUETOOTH** permission.
4. Enables Bluetooth.
5. Disables Bluetooth.
6. Example:

    ```ts
    import { access } from '@kit.ConnectivityKit';
    import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';

    // Enable Bluetooth.
    access.enableBluetooth();
    access.on('stateChange', (data) => {
      let btStateMessage = '';
      switch (data) {
        case 0:
          btStateMessage += 'STATE_OFF';
          break;
        case 1:
          btStateMessage += 'STATE_TURNING_ON';
          break;
        case 2:
          btStateMessage += 'STATE_ON';
          break;
        case 3:
          btStateMessage += 'STATE_TURNING_OFF';
          break;
        case 4:
          btStateMessage += 'STATE_BLE_TURNING_ON';
          break;
        case 5:
          btStateMessage += 'STATE_BLE_ON';
          break;
        case 6:
          btStateMessage += 'STATE_BLE_TURNING_OFF';
          break;
        default:
          btStateMessage += 'unknown status';
          break;
      }
      if (btStateMessage == 'STATE_ON') {
        access.off('stateChange');
      }
      console.info('bluetooth statues: ' + btStateMessage);
    })

    // Disable Bluetooth.
    access.disableBluetooth();
    access.on('stateChange', (data) => {
      let btStateMessage = '';
      switch (data) {
        case 0:
          btStateMessage += 'STATE_OFF';
          break;
        case 1:
          btStateMessage += 'STATE_TURNING_ON';
          break;
        case 2:
          btStateMessage += 'STATE_ON';
          break;
        case 3:
          btStateMessage += 'STATE_TURNING_OFF';
          break;
        case 4:
          btStateMessage += 'STATE_BLE_TURNING_ON';
          break;
        case 5:
          btStateMessage += 'STATE_BLE_ON';
          break;
        case 6:
          btStateMessage += 'STATE_BLE_TURNING_OFF';
          break;
        default:
          btStateMessage += 'unknown status';
          break;
      }
      if (btStateMessage == 'STATE_OFF') {
        access.off('stateChange');
      }
      console.info("bluetooth statues: " + btStateMessage);
    })
    ```

6. For details about the error codes, see [Bluetooth Error Codes](../../reference/apis-connectivity-kit/errorcode-bluetoothManager.md).
7. Verification:
Execute the code for enabling Bluetooth.<br>If "bluetooth statues: STATE_ON" is logged, Bluetooth is enabled. Execute the code for disabling Bluetooth.<br>If "bluetooth statues: STATE_OFF" is logged, Bluetooth is disabled.
