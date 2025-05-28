# 查找设备

## 简介
主要提供查找设备相关的开发指导，包括如何扫描周边设备、设置本机蓝牙扫描模式以及查找已配对设备信息。

## 开发步骤

### 申请蓝牙权限
需要申请权限ohos.permission.ACCESS_BLUETOOTH。如何配置和申请权限，具体操作请参考[声明权限](../../security/AccessToken/declare-permissions.md)和[向用户申请授权](../../security/AccessToken/request-user-authorization.md)。

### 导入所需API模块
导入connection和错误码模块。
```ts
import { connection } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';
```

### 扫描周边蓝牙设备
用于扫描周边支持蓝牙能力的设备，并获取到蓝牙设备的部分信息。此过程也可被称为“搜索”、“发现”或“查找”。只有周边蓝牙设备处于可被发现的状态时，才能被本机蓝牙设备扫描到。

#### 订阅扫描设备结果上报事件
- 推荐使用API version 18及以上的扫描结果上报方式。该方式可获取到更多设备信息，包括设备地址、设备信号强度、设备名称和设备类型。详情请见[connection.on('discoveryResult')](../../reference/apis-connectivity-kit/js-apis-bluetooth-connection.md#connectionondiscoveryresult18)。
```ts
// 定义扫描结果上报回调函数
function onReceiveEvent(data: Array<connection.DiscoveryResult>) {
  console.info('bluetooth device: '+ JSON.stringify(data));
}

try {
  // 发起订阅
  connection.on('discoveryResult', onReceiveEvent);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```
- API version 17及以前的扫描结果上报方式只支持获取设备地址信息。详情请见[connection.on('bluetoothDeviceFind')](../../reference/apis-connectivity-kit/js-apis-bluetooth-connection.md#connectiononbluetoothdevicefind)。
```ts
// 定义扫描结果上报回调函数
function onReceiveEvent(data: Array<string>) {
  console.info('bluetooth device: '+ JSON.stringify(data));
}

try {
  // 发起订阅
  connection.on('bluetoothDeviceFind', onReceiveEvent);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

#### 发起设备扫描
应用发起扫描后，整个扫描过程大约持续12s。应用可以对扫描到的蓝牙设备发起配对、连接和传输数据流程。具体操作请参考[配对连接设备](br-pair-device-development-guide.md)和[传输数据](spp-development-guide.md)。
```ts
try {
  // 判断本机设备是否正在进行扫描
  let scan = connection.isBluetoothDiscovering();
  if (!scan) {
    // 若当前不处于扫描过程，则开始扫描设备
    connection.startBluetoothDiscovery();
  }
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

#### 停止设备扫描
扫描是一个很消耗蓝牙硬件资源的过程。当扫描到应用所需的蓝牙设备后，在发起连接前，必须停止设备扫描。
```ts
// 定义扫描结果上报回调函数
function onReceiveEvent(data: Array<string>) {
  console.info('bluetooth device: '+ JSON.stringify(data));
}

try {
  // 判断本机设备是否正在进行扫描
  let scan = connection.isBluetoothDiscovering();
  if (scan) {
    // 若当前处于扫描过程，则停止扫描设备
    connection.stopBluetoothDiscovery();
  }
  // 若不再需要使用扫描，可以取消订阅扫描上报结果
  connection.off('bluetoothDeviceFind', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### 设置本机蓝牙扫描模式
本机蓝牙扫描模式用于控制本机设备是否可以被周边其他蓝牙设备扫描到或连接上。非系统应用一般不用关注这个模式，系统设置应用会决定如何设置。
- 系统设置应用打开蓝牙后，若系统蓝牙设置界面在前台，会将本机蓝牙扫描模式设置为可被扫描和可被连接，即[SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE](../../reference/apis-connectivity-kit/js-apis-bluetooth-connection.md#scanmode)。
- 系统设置应用打开蓝牙后，若系统蓝牙设置界面在后台，会将本机蓝牙扫描模式设置为可被连接，即[SCAN_MODE_CONNECTABLE](../../reference/apis-connectivity-kit/js-apis-bluetooth-connection.md#scanmode)。

```ts
try {
  // 获取当前本机的扫描模式
  let scanMode: connection.ScanMode = connection.getBluetoothScanMode();
  console.info('scanMode: ' + scanMode);
  if (scanMode != connection.ScanMode.SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE) {
    // 将本机设备的扫描模式设置为可被发现和可被连接
    connection.setBluetoothScanMode(connection.ScanMode.SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE, 0);
  }
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### 查找已配对设备信息
在发起扫描设备前，可以查找该设备是否是已配对的设备，以减少扫描设备的流程。也可以对已配对设备发起连接和传输数据流程，具体操作请参考[配对连接设备](br-pair-device-development-guide.md)和[传输数据](spp-development-guide.md)。

```ts
try {
  // 获取已配对设备信息
  let devices = connection.getPairedDevices();
  console.info('pairedDevices: ' + JSON.stringify(devices));
  // 若已知道设备地址，可主动查询该设备是否是已配对的
  if (devices.length > 0) {
    let pairState = connection.getPairState(devices[0]);
    console.info('device: '+ devices[0] + ' pairState is ' + pairState);
  }
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## 完整示例
```ts
import { connection } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export class DiscoveryDeviceManager {
  // 定义扫描结果上报回调函数
  onReceiveEvent(data: Array<string>) {
    console.info('bluetooth device: '+ JSON.stringify(data));
  }

  public startDiscovery() {
    try {
      connection.on('bluetoothDeviceFind', this.onReceiveEvent);
    } catch (err) {
      console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
    try {
      // 判断本机设备是否正在进行扫描
      let scan = connection.isBluetoothDiscovering();
      if (!scan) {
        // 若当前不处于扫描过程，则开始扫描设备
        connection.startBluetoothDiscovery();
      }
    } catch (err) {
      console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  public stopDiscovery() {
    try {
      // 判断本机设备是否正在进行扫描
      let scan = connection.isBluetoothDiscovering();
      if (scan) {
        // 若当前处于扫描过程，则停止扫描设备
        connection.stopBluetoothDiscovery();
      }
      // 若不再需要使用扫描，可以取消订阅扫描上报结果
      connection.off('bluetoothDeviceFind', this.onReceiveEvent);
    } catch (err) {
      console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  public setScanMode() {
    try {
      // 获取当前本机的扫描模式
      let scanMode: connection.ScanMode = connection.getBluetoothScanMode();
      console.info('scanMode: ' + scanMode);
      if (scanMode != connection.ScanMode.SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE) {
        // 将本机设备的扫描模式设为可被发现和可被连接
        connection.setBluetoothScanMode(connection.ScanMode.SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE, 0);
      }
    } catch (err) {
      console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  public getPairedDevices() {
    try {
      // 获取已配对设备信息
      let devices = connection.getPairedDevices();
      console.info('pairedDevices: ' + JSON.stringify(devices));
      // 若已知道设备地址，可主动查询该设备是否是已配对的
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