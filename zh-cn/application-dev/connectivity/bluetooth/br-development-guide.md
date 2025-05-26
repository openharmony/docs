# 蓝牙设置

## 简介
主要提供了开启蓝牙、关闭蓝牙和获取蓝牙开关状态的开发指导。开发者在使用蓝牙其他功能时，应确保蓝牙子系统已正常开启。

## 开发步骤

### 申请蓝牙权限
需要申请权限ohos.permission.ACCESS_BLUETOOTH。如何配置和申请权限，具体操作请参考[声明权限](../../security/AccessToken/declare-permissions.md)和[向用户申请授权](../../security/AccessToken/request-user-authorization.md)。

### 导入所需API模块
导入access和错误码模块。
```ts
import { access } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';
```

### 订阅蓝牙开关状态变化事件
通过订阅开关状态变化事件，可以获取实时的蓝牙开关状态。蓝牙开启或者关闭过程中，涉及多种蓝牙状态的跃迁。其中[STATE_OFF](../../reference/apis-connectivity-kit/js-apis-bluetooth-access.md#bluetoothstate)表示蓝牙已关闭，此状态下，应用不可以使用蓝牙其他功能；[STATE_ON](../../reference/apis-connectivity-kit/js-apis-bluetooth-access.md#bluetoothstate)表示蓝牙已打开，此状态下，应用可以使用蓝牙其他功能。
```ts
// 定义蓝牙开关状态变化函数回调
function onReceiveEvent(data: access.BluetoothState) {
  let btStateMessage = '';
  switch (data) {
    case access.BluetoothState.STATE_OFF:
      // 表示蓝牙是关闭的
      btStateMessage += 'STATE_OFF';
      break;
    case access.BluetoothState.STATE_TURNING_ON:
      btStateMessage += 'STATE_TURNING_ON';
      break;
    case access.BluetoothState.STATE_ON:
      // 表示蓝牙是开启的，此时应用才可以使用蓝牙其他功能
      btStateMessage += 'STATE_ON';
      break;
    case access.BluetoothState.STATE_TURNING_OFF:
      btStateMessage += 'STATE_TURNING_OFF';
      break;
    case access.BluetoothState.STATE_BLE_TURNING_ON:
      btStateMessage += 'STATE_BLE_TURNING_ON';
      break;
    case access.BluetoothState.STATE_BLE_ON:
      btStateMessage += 'STATE_BLE_ON';
      break;
    case access.BluetoothState.STATE_BLE_TURNING_OFF:
      btStateMessage += 'STATE_BLE_TURNING_OFF';
      break;
    default:
      btStateMessage += 'unknown state';
      break;
  }
  console.info('bluetooth state: ' + btStateMessage);
}

try {
    // 发起订阅
    access.on('stateChange', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### 开启蓝牙
若应用获取到的蓝牙开关状态是关闭的，当需要使用蓝牙时，则需要主动开启蓝牙。通过订阅蓝牙开关状态，判断蓝牙是否开启成功。

系统弹出对话框并提示应用“想要开启蓝牙”，如下图1。若用户同意授权，将开启蓝牙。

![enable bluetooth dialog](figures/enable-bluetooth-dialog.png)

**图1** 开启蓝牙对话框
```ts
try {
    // 主动获取蓝牙当前的开关状态
    let state = access.getState();
    if (state == access.BluetoothState.STATE_OFF) {
        // 若蓝牙是关闭的，则主动开启蓝牙
        access.enableBluetooth();
    }
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### 关闭蓝牙
若应用不需要使用蓝牙时，可根据实际情况判断是否需要主动关闭蓝牙。通过订阅蓝牙开关状态，判断蓝牙是否关闭成功。

系统弹出对话框并提示应用“想要关闭蓝牙”，如下图2。若用户同意授权，将关闭蓝牙。

![disable bluetooth dialog](figures/disable-bluetooth-dialog.png)

**图2** 关闭蓝牙对话框
```ts
try {
   // 主动获取蓝牙当前的开关状态
   let state = access.getState();
   if (state == access.BluetoothState.STATE_ON) {
     // 若蓝牙是开启的，则主动关闭蓝牙
     access.disableBluetooth();
  }
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## 完整示例
```ts
import { access } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export class AdapterManager {
  // 定义蓝牙开关状态变化函数回调
  onReceiveEvent(data: access.BluetoothState) {
    let btStateMessage = '';
    switch (data) {
      case access.BluetoothState.STATE_OFF:
        // 表示蓝牙是关闭的
        btStateMessage += 'STATE_OFF';
        break;
      case access.BluetoothState.STATE_TURNING_ON:
        btStateMessage += 'STATE_TURNING_ON';
        break;
      case access.BluetoothState.STATE_ON:
        // 表示蓝牙是开启的，此时应用才可以使用蓝牙其他功能
        btStateMessage += 'STATE_ON';
        break;
      case access.BluetoothState.STATE_TURNING_OFF:
        btStateMessage += 'STATE_TURNING_OFF';
        break;
      case access.BluetoothState.STATE_BLE_TURNING_ON:
        btStateMessage += 'STATE_BLE_TURNING_ON';
        break;
      case access.BluetoothState.STATE_BLE_ON:
        btStateMessage += 'STATE_BLE_ON';
        break;
      case access.BluetoothState.STATE_BLE_TURNING_OFF:
        btStateMessage += 'STATE_BLE_TURNING_OFF';
        break;
      default:
        btStateMessage += 'unknown state';
        break;
    }
    console.info('bluetooth state: ' + btStateMessage);
  }

  // 开启蓝牙
  public openBluetooth() {
    try {
      access.on('stateChange', this.onReceiveEvent);
    } catch (err) {
      console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
    try {
      // 主动获取蓝牙当前的开关状态
      let state = access.getState();
      if (state == access.BluetoothState.STATE_OFF) {
        // 若蓝牙是关闭的，则主动开启蓝牙
        access.enableBluetooth();
      }
    } catch (err) {
      console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 关闭蓝牙
  public closeBluetooth() {
    try {
      // 主动获取蓝牙当前的开关状态
      let state = access.getState();
      if (state == access.BluetoothState.STATE_ON) {
        // 若蓝牙是开启的，则主动关闭蓝牙
        access.disableBluetooth();
      }
    } catch (err) {
      console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }
}

let adapterManager = new AdapterManager();
export default adapterManager as AdapterManager;
```