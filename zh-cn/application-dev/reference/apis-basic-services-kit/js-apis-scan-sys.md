# @ohos.scan (扫描)(系统接口)

<!--Kit: Basic Services Kit-->
<!--Subsystem: Print-->
<!--Owner: @guoshengbang-->
<!--Designer: @Q-haosu-->
<!--Tester:@Q-haosu-->
<!--Adviser: @fang-jinxu-->

该模块为扫描框架的js-api接口文档，提供发现和连接扫描仪的能力。

> **说明：**  
> 本模块首批接口从API version 20开始支持。
> 当前界面仅包含本模块的系统接口，其他公开接口参见[@ohos.scan (扫描)](./js-apis-scan.md)。

## 导入模块

```ts
import { scan } from '@kit.BasicServicesKit';
```
## scan.addScanner

addScanner(uniqueId: string, discoveryMode: ScannerDiscoveryMode): Promise&lt;void&gt;

添加扫描仪（系统API），使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| uniqueId | string | 是 | 扫描仪的唯一ID。 |
| discoveryMode | [ScannerDiscoveryMode](./js-apis-scan.md#scannerdiscoverymode) | 是 | 发现模式。 |

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;void&gt; | 添加扫描仪完成结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application. |

**示例：**

```ts
import { scan } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let uniqueId: string = 'unique_scanner_001';
let discoveryMode: scan.ScannerDiscoveryMode = scan.ScannerDiscoveryMode.TCP_STR;
scan.addScanner(uniqueId, discoveryMode).then(() => {
    console.log('add scanner success');
}).catch((error: BusinessError) => {
    console.error('add scanner failed: ' + JSON.stringify(error));
})
```

## scan.deleteScanner

deleteScanner(uniqueId: string, discoveryMode: ScannerDiscoveryMode): Promise&lt;void&gt;

删除扫描仪（系统API），使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| uniqueId | string | 是 | 扫描仪的唯一ID。 |
| discoveryMode | [ScannerDiscoveryMode](./js-apis-scan.md#scannerdiscoverymode) | 是 | 发现模式。 |

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;void&gt; | 删除扫描仪完成结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application. |

**示例：**

```ts
import { scan } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let uniqueId: string = 'unique_scanner_001';
let discoveryMode: scan.ScannerDiscoveryMode = scan.ScannerDiscoveryMode.TCP_STR;
scan.deleteScanner(uniqueId, discoveryMode).then(() => {
    console.log('delete scanner success');
}).catch((error: BusinessError) => {
    console.error('delete scanner failed: ' + JSON.stringify(error));
})
```

## scan.getAddedScanners

getAddedScanners(): Promise&lt;ScannerDevice[]&gt;

获取已添加的扫描仪（系统API），使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;[ScannerDevice](./js-apis-scan.md#scannerdevice)[]&gt; | 获取已添加的扫描仪完成结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application. |

**示例：**

```ts
import { scan } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

scan.getAddedScanners().then((scanners: scan.ScannerDevice[]) => {
    console.log('get added scanners success: ' + JSON.stringify(scanners));
}).catch((error: BusinessError) => {
    console.error('get added scanners failed: ' + JSON.stringify(error));
})
```

## scan.on

on(type: 'scanDeviceAdd', callback: Callback&lt;ScannerDevice&gt;): void

注册扫描仪设备添加事件回调（系统API），使用callback回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | 'scanDeviceAdd' | 是 | 事件类型。 |
| callback | Callback&lt;[ScannerDevice](./js-apis-scan.md#scannerdevice)&gt; | 是 | 扫描仪设备添加事件的回调。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application. |

**示例：**

```ts
import { scan } from '@kit.BasicServicesKit';

scan.on('scanDeviceAdd', (device: scan.ScannerDevice) => {
    console.log('scan device add: ' + JSON.stringify(device));
})
```

## scan.off

off(type: 'scanDeviceAdd', callback?: Callback&lt;ScannerDevice&gt;): void

取消注册扫描仪设备添加事件回调（系统API），使用callback回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | 'scanDeviceAdd' | 是 | 事件类型。 |
| callback | Callback&lt;[ScannerDevice](./js-apis-scan.md#scannerdevice)&gt; | 否 | 要取消注册的回调函数。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application. |

**示例：**

```ts
import { scan } from '@kit.BasicServicesKit';

let callback = (device: scan.ScannerDevice) => {
    console.log('scan device add: ' + JSON.stringify(device));
};
scan.on('scanDeviceAdd', callback);
// 取消注册
scan.off('scanDeviceAdd', callback);
```

## scan.on

on(type: 'scanDeviceDel', callback: Callback&lt;ScannerDevice&gt;): void

注册扫描仪设备删除事件回调（系统API），使用callback回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | 'scanDeviceDel' | 是 | 事件类型。 |
| callback | Callback&lt;[ScannerDevice](./js-apis-scan.md#scannerdevice)&gt; | 是 | 扫描仪设备删除事件的回调。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application. |

**示例：**

```ts
import { scan } from '@kit.BasicServicesKit';

scan.on('scanDeviceDel', (device: scan.ScannerDevice) => {
    console.log('scan device delete: ' + JSON.stringify(device));
})
```

## scan.off

off(type: 'scanDeviceDel', callback?: Callback&lt;ScannerDevice&gt;): void

取消注册扫描仪设备删除事件回调（系统API），使用callback回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | 'scanDeviceDel' | 是 | 事件类型。 |
| callback | Callback&lt;[ScannerDevice](./js-apis-scan.md#scannerdevice)&gt; | 否 | 要取消注册的回调函数。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | the application does not have permission to call this function. |
| 202 | not system application. |

**示例：**

```ts
import { scan } from '@kit.BasicServicesKit';

let callback = (device: scan.ScannerDevice) => {
    console.log('scan device delete: ' + JSON.stringify(device));
};
scan.on('scanDeviceDel', callback);
// 取消注册
scan.off('scanDeviceDel', callback);
```