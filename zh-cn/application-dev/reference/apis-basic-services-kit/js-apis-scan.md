# @ohos.scan (扫描)

<!--Kit: Basic Services Kit-->
<!--Subsystem: Print-->
<!--Owner: @guoshengbang-->
<!--Designer: @Q-haosu-->
<!--Tester:@Q-haosu-->
<!--Adviser: @fang-jinxu-->

该模块为扫描框架的js-api接口文档，提供发现和连接扫描仪的能力。

> **说明：**  
> 本模块首批接口从API version 20开始支持。
> 当前界面仅包含本模块的公开接口。

## 导入模块

```ts
import { scan } from '@kit.BasicServicesKit';
```

## ScanErrorCode

定义扫描错误码的枚举。

**系统能力：** SystemCapability.Print.PrintFramework

| **名称** | **值** | **说明** |
| -------- | ------ | -------- |
| SCAN_ERROR_NO_PERMISSION | 201 | 无权限。 |
| SCAN_ERROR_NOT_SYSTEM_APPLICATION | 202 | 非系统应用。 |
| SCAN_ERROR_INVALID_PARAMETER | 401 | 无效参数。 |
| SCAN_ERROR_GENERIC_FAILURE | 13100001 | 通用失败。 |
| SCAN_ERROR_RPC_FAILURE | 13100002 | RPC失败。 |
| SCAN_ERROR_SERVER_FAILURE | 13100003 | 服务失败。 |
| SCAN_ERROR_UNSUPPORTED | 13100004 | 不支持的操作。 |
| SCAN_ERROR_CANCELED | 13100005 | 操作取消。 |
| SCAN_ERROR_DEVICE_BUSY | 13100006 | 设备忙。 |
| SCAN_ERROR_INVALID | 13100007 | 无效操作。 |
| SCAN_ERROR_JAMMED | 13100008 | 卡纸。 |
| SCAN_ERROR_NO_DOCS | 13100009 | 缺纸。 |
| SCAN_ERROR_COVER_OPEN | 13100010 | 盖子打开。 |
| SCAN_ERROR_IO_ERROR | 13100011 | I/O错误。 |
| SCAN_ERROR_NO_MEMORY | 13100012 | 内存不足。 |

## ConstraintType

定义参数限制类型的枚举。

**系统能力：** SystemCapability.Print.PrintFramework

| **名称** | **值** | **说明** |
| -------- | ------ | -------- |
| SCAN_CONSTRAINT_NONE | 0 | 无限制。 |
| SCAN_CONSTRAINT_RANGE | 1 | 范围限制。 |
| SCAN_CONSTRAINT_WORD_LIST | 2 | 数字列表。 |
| SCAN_CONSTRAINT_STRING_LIST | 3 | 字符串列表。 |

## PhysicalUnit

定义物理单位的枚举。

**系统能力：** SystemCapability.Print.PrintFramework

| **名称** | **值** | **说明** |
| -------- | ------ | -------- |
| SCAN_UNIT_NONE | 0 | 无单位。 |
| SCAN_UNIT_PIXEL | 1 | 像素单位。 |
| SCAN_UNIT_BIT | 2 | 位单位。 |
| SCAN_UNIT_MM | 3 | 毫米单位。 |
| SCAN_UNIT_DPI | 4 | DPI单位。 |
| SCAN_UNIT_PERCENT | 5 | 百分比单位。 |
| SCAN_UNIT_MICROSECOND | 6 | 微秒单位。 |

## OptionValueType

定义选项值类型的枚举。

**系统能力：** SystemCapability.Print.PrintFramework

| **名称** | **值** | **说明** |
| -------- | ------ | -------- |
| SCAN_TYPE_BOOL | 0 | 布尔类型。 |
| SCAN_TYPE_INT | 1 | 整数类型。 |
| SCAN_TYPE_FIXED | 2 | 定点数类型。 |
| SCAN_TYPE_STRING | 3 | 字符串类型。 |

## ScannerSyncMode

定义扫描仪同步码的枚举。

**系统能力：** SystemCapability.Print.PrintFramework

| **名称** | **值** | **说明** |
| -------- | ------ | -------- |
| UPDATE_STR | 'update' | 更新码，表示扫描仪id的变化。 |
| DELETE_STR | 'delete' | 删除码，表示扫描仪掉线。 |

## ScannerDiscoveryMode

定义扫描仪发现方式的枚举。

**系统能力：** SystemCapability.Print.PrintFramework

| **名称** | **值** | **说明** |
| -------- | ------ | -------- |
| TCP_STR | 'TCP' | 网络扫描仪的发现模式。 |
| USB_STR | 'USB' | USB扫描仪的发现模式。 |

## Range

定义范围的接口。

**系统能力：** SystemCapability.Print.PrintFramework

**属性：**
| **名称** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| minValue | number | 是 | 范围的最小值。 |
| maxValue | number | 是 | 范围的最大值。 |
| quantValue | number | 是 | 范围的量化值。 |

## ScannerParameter

定义扫描仪参数的接口。

**系统能力：** SystemCapability.Print.PrintFramework

**属性：**
| **名称** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| optionName | string | 是 | 选项名称。 |
| optionIndex | number | 是 | 选项索引。 |
| optionTitle | string | 是 | 选项标题。 |
| optionDesc | string | 是 | 选项描述。 |
| optionType | [OptionValueType](#optionvaluetype) | 是 | 选项值类型。 |
| optionUnit | [PhysicalUnit](#physicalunit) | 是 | 选项物理单位。 |
| optionConstraintType | [ConstraintType](#constrainttype) | 是 | 选项约束类型。 |
| optionConstraintString | string[] | 否 | 选项字符串约束。 |
| optionConstraintInt | number[] | 否 | 选项整数约束。 |
| optionConstraintRange | [Range](#range) | 否 | 选项范围约束。 |

## ScannerOptionValue

定义扫描仪选项值的接口。

**系统能力：** SystemCapability.Print.PrintFramework

**属性：**
| **名称** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| valueType | [OptionValueType](#optionvaluetype) | 是 | 值类型。 |
| numValue | number | 否 | 数值。 |
| strValue | string | 否 | 字符串值。 |
| boolValue | boolean | 否 | 布尔值。 |

## PictureScanProgress

定义图片扫描进度的接口。

**系统能力：** SystemCapability.Print.PrintFramework

**属性：**
| **名称** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| progress | number | 是 | 当前进度百分比，范围从0~100。 |
| pictureFd | number | 是 | 扫描图片的文件描述符。 |
| isFinal | boolean | 是 | 是否是本次扫描的最后一张图片。 |

## ScannerDevice

定义扫描仪设备的接口。

**系统能力：** SystemCapability.Print.PrintFramework

**属性：**
| **名称** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| scannerId | string | 是 | 扫描仪的唯一标识符。 |
| discoveryMode | [ScannerDiscoveryMode](#scannerdiscoverymode) | 是 | 扫描仪的发现模式。 |
| uniqueId | string | 是 | 扫描仪的唯一ID。 |
| manufacturer | string | 是 | 扫描仪的制造商。 |
| model | string | 是 | 扫描仪的型号。 |
| deviceName | string | 是 | 扫描仪的设备名称。 |

## ScannerSyncDevice

定义扫描仪同步设备的接口。

**系统能力：** SystemCapability.Print.PrintFramework

**属性：**
| **名称** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| scannerId | string | 是 | 扫描仪ID。 |
| discoveryMode | [ScannerDiscoveryMode](#scannerdiscoverymode) | 是 | 发现模式。 |
| uniqueId | string | 是 | 唯一ID。 |
| syncMode | [ScannerSyncMode](#scannersyncmode) | 是 | 同步模式。 |
| oldScannerId | string | 否 | 旧的扫描仪ID，仅在syncMode为"update"时有效。 |

## scan.init

init(): Promise&lt;void&gt;

初始化扫描服务，使用Promise异步回调。

**需要权限：** ohos.permission.PRINT

**系统能力：** SystemCapability.Print.PrintFramework

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;void&gt; | 初始化扫描服务完成结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | the application does not have permission to call this function. |

**示例：**

```ts
import { scan } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

scan.init().then(() => {
    console.log('scan init success');
}).catch((error: BusinessError) => {
    console.error('scan init failed: ' + JSON.stringify(error));
})
```

## scan.exit

exit(): Promise&lt;void&gt;

退出扫描服务，使用Promise异步回调。

**需要权限：** ohos.permission.PRINT

**系统能力：** SystemCapability.Print.PrintFramework

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;void&gt; | 退出扫描服务完成结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | the application does not have permission to call this function. |

**示例：**

```ts
import { scan } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

scan.exit().then(() => {
    console.log('scan exit success');
}).catch((error: BusinessError) => {
    console.error('scan exit failed: ' + JSON.stringify(error));
})
```

## scan.startScannerDiscovery

startScannerDiscovery(): Promise&lt;void&gt;

开始发现扫描仪，使用Promise异步回调。

**需要权限：** ohos.permission.PRINT

**系统能力：** SystemCapability.Print.PrintFramework

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;void&gt; | 开始发现扫描仪完成结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | the application does not have permission to call this function. |

**示例：**

```ts
import { scan } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

scan.startScannerDiscovery().then(() => {
    console.log('start scanner discovery success');
}).catch((error: BusinessError) => {
    console.error('start scanner discovery failed: ' + JSON.stringify(error));
})
```

## scan.openScanner

openScanner(scannerId: string): Promise&lt;void&gt;

打开扫描仪，使用Promise异步回调。

**需要权限：** ohos.permission.PRINT

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| scannerId | string | 是 | 要打开的扫描仪的ID。 |

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;void&gt; | 打开扫描仪完成结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | the application does not have permission to call this function. |

**示例：**

```ts
import { scan } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let scannerId: string = 'scanner_001';
scan.openScanner(scannerId).then(() => {
    console.log('open scanner success');
}).catch((error: BusinessError) => {
    console.error('open scanner failed: ' + JSON.stringify(error));
})
```

## scan.closeScanner

closeScanner(scannerId: string): Promise&lt;void&gt;

关闭扫描仪，使用Promise异步回调。

**需要权限：** ohos.permission.PRINT

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| scannerId | string | 是 | 要关闭的扫描仪的ID。 |

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;void&gt; | 关闭扫描仪完成结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | the application does not have permission to call this function. |

**示例：**

```ts
import { scan } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let scannerId: string = 'scanner_001';
scan.closeScanner(scannerId).then(() => {
    console.log('close scanner success');
}).catch((error: BusinessError) => {
    console.error('close scanner failed: ' + JSON.stringify(error));
})
```

## scan.getScannerParameter

getScannerParameter(scannerId: string): Promise&lt;ScannerParameter[]&gt;

获取扫描仪参数，使用Promise异步回调。

**需要权限：** ohos.permission.PRINT

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| scannerId | string | 是 | 扫描仪的ID。 |

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;[ScannerParameter](#scannerparameter)[]&gt; | 获取扫描仪参数完成结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | the application does not have permission to call this function. |

**示例：**

```ts
import { scan } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let scannerId: string = 'scanner_001';
scan.getScannerParameter(scannerId).then((parameters: scan.ScannerParameter[]) => {
    console.log('get scanner parameters success: ' + JSON.stringify(parameters));
}).catch((error: BusinessError) => {
    console.error('get scanner parameters failed: ' + JSON.stringify(error));
})
```

## scan.setScannerParameter

setScannerParameter(scannerId: string, optionIndex: number, value: ScannerOptionValue): Promise&lt;void&gt;

设置扫描仪参数，使用Promise异步回调。

**需要权限：** ohos.permission.PRINT

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| scannerId | string | 是 | 扫描仪的ID。 |
| optionIndex | number | 是 | 要设置的选项的索引。 |
| value | [ScannerOptionValue](#scanneroptionvalue) | 是 | 要设置的值。 |

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;void&gt; | 设置扫描仪参数完成结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | the application does not have permission to call this function. |

**示例：**

```ts
import { scan } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let scannerId: string = 'scanner_001';
let optionIndex: number = 1;
let value: scan.ScannerOptionValue = {
    valueType: scan.OptionValueType.SCAN_TYPE_INT,
    numValue: 100
};
scan.setScannerParameter(scannerId, optionIndex, value).then(() => {
    console.log('set scanner parameter success');
}).catch((error: BusinessError) => {
    console.error('set scanner parameter failed: ' + JSON.stringify(error));
})
```

## scan.setScanAutoOption

setScanAutoOption(scannerId: string, optionIndex: number): Promise&lt;void&gt;

设置扫描选项为自动模式，使用Promise异步回调。

**需要权限：** ohos.permission.PRINT

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| scannerId | string | 是 | 扫描仪的ID。 |
| optionIndex | number | 是 | 要设置为自动的选项的索引。 |

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;void&gt; | 设置扫描选项为自动完成结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | the application does not have permission to call this function. |

**示例：**

```ts
import { scan } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let scannerId: string = 'scanner_001';
let optionIndex: number = 1;
scan.setScanAutoOption(scannerId, optionIndex).then(() => {
    console.log('set scan auto option success');
}).catch((error: BusinessError) => {
    console.error('set scan auto option failed: ' + JSON.stringify(error));
})
```

## scan.getScannerCurrentSetting

getScannerCurrentSetting(scannerId: string, optionIndex: number): Promise&lt;ScannerOptionValue&gt;

获取当前扫描仪设置，使用Promise异步回调。

**需要权限：** ohos.permission.PRINT

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| scannerId | string | 是 | 扫描仪的ID。 |
| optionIndex | number | 是 | 要获取的选项的索引。 |

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;[ScannerOptionValue](#scanneroptionvalue)&gt; | 获取当前扫描仪设置完成结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | the application does not have permission to call this function. |

**示例：**

```ts
import { scan } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let scannerId: string = 'scanner_001';
let optionIndex: number = 1;
scan.getScannerCurrentSetting(scannerId, optionIndex).then((value: scan.ScannerOptionValue) => {
    console.log('get scanner current setting success: ' + JSON.stringify(value));
}).catch((error: BusinessError) => {
    console.error('get scanner current setting failed: ' + JSON.stringify(error));
})
```

## scan.startScan

startScan(scannerId: string, batchMode: boolean): Promise&lt;void&gt;

开始扫描，使用Promise异步回调。

**需要权限：** ohos.permission.PRINT

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| scannerId | string | 是 | 扫描仪的ID。 |
| batchMode | boolean | 是 | 是否使用批处理模式。 |

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;void&gt; | 开始扫描完成结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | the application does not have permission to call this function. |

**示例：**

```ts
import { scan } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let scannerId: string = 'scanner_001';
let batchMode: boolean = true;
scan.startScan(scannerId, batchMode).then(() => {
    console.log('start scan success');
}).catch((error: BusinessError) => {
    console.error('start scan failed: ' + JSON.stringify(error));
})
```

## scan.cancelScan

cancelScan(scannerId: string): Promise&lt;void&gt;

取消扫描，使用Promise异步回调。

**需要权限：** ohos.permission.PRINT

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| scannerId | string | 是 | 扫描仪的ID。 |

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;void&gt; | 取消扫描完成结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | the application does not have permission to call this function. |

**示例：**

```ts
import { scan } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let scannerId: string = 'scanner_001';
scan.cancelScan(scannerId).then(() => {
    console.log('cancel scan success');
}).catch((error: BusinessError) => {
    console.error('cancel scan failed: ' + JSON.stringify(error));
})
```

## scan.getPictureScanProgress

getPictureScanProgress(scannerId: string): Promise&lt;PictureScanProgress&gt;

获取图片扫描进度，使用Promise异步回调。

**需要权限：** ohos.permission.PRINT

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| scannerId | string | 是 | 扫描仪的ID。 |

**返回值：**
| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;[PictureScanProgress](#picturescanprogress)&gt; | 获取图片扫描进度完成结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | the application does not have permission to call this function. |

**示例：**

```ts
import { scan } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let scannerId: string = 'scanner_001';
scan.getPictureScanProgress(scannerId).then((progress: scan.PictureScanProgress) => {
    console.log('get picture scan progress success: ' + JSON.stringify(progress));
}).catch((error: BusinessError) => {
    console.error('get picture scan progress failed: ' + JSON.stringify(error));
})
```

## scan.on

on(type: 'scanDeviceFound', callback: Callback&lt;ScannerDevice&gt;): void

注册扫描仪设备发现事件回调，使用callback回调。

**需要权限：** ohos.permission.PRINT

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | 'scanDeviceFound' | 是 | 事件类型。 |
| callback | Callback&lt;[ScannerDevice](#scannerdevice)&gt; | 是 | 扫描仪设备发现事件的回调。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | the application does not have permission to call this function. |

**示例：**

```ts
import { scan } from '@kit.BasicServicesKit';

scan.on('scanDeviceFound', (device: scan.ScannerDevice) => {
    console.log('scan device found: ' + JSON.stringify(device));
})
```

## scan.off

off(type: 'scanDeviceFound', callback?: Callback&lt;ScannerDevice&gt;): void

取消注册扫描仪设备发现事件回调，使用callback回调。

**需要权限：** ohos.permission.PRINT

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名 | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | 'scanDeviceFound' | 是 | 事件类型。 |
| callback | Callback&lt;[ScannerDevice](#scannerdevice)&gt; | 否 | 要取消注册的回调函数。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | the application does not have permission to call this function. |

**示例：**

```ts
import { scan } from '@kit.BasicServicesKit';

let callback = (device: scan.ScannerDevice) => {
    console.log('scan device found: ' + JSON.stringify(device));
};
scan.on('scanDeviceFound', callback);
// 取消注册
scan.off('scanDeviceFound', callback);
```

## scan.on

on(type: 'scanDeviceSync', callback: Callback&lt;ScannerSyncDevice&gt;): void

注册扫描仪设备同步事件回调，使用callback回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | 'scanDeviceSync' | 是 | 事件类型。 |
| callback | Callback&lt;[ScannerSyncDevice](#scannersyncdevice)&gt; | 是 | 扫描仪设备同步事件的回调。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | the application does not have permission to call this function. |

**示例：**

```ts
import { scan } from '@kit.BasicServicesKit';

scan.on('scanDeviceSync', (device: scan.ScannerSyncDevice) => {
    console.log('scan device sync: ' + JSON.stringify(device));
})
```

## scan.off

off(type: 'scanDeviceSync', callback?: Callback&lt;ScannerSyncDevice&gt;): void

取消注册扫描仪设备同步事件回调，使用callback回调。

**需要权限：** ohos.permission.MANAGE_PRINT_JOB

**系统能力：** SystemCapability.Print.PrintFramework

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | 'scanDeviceSync' | 是 | 事件类型。 |
| callback | Callback&lt;[ScannerSyncDevice](#scannersyncdevice)&gt; | 否 | 要取消注册的回调函数。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | the application does not have permission to call this function. |

**示例：**

```ts
import { scan } from '@kit.BasicServicesKit';

let callback = (device: scan.ScannerSyncDevice) => {
    console.log('scan device sync: ' + JSON.stringify(device));
};
scan.on('scanDeviceSync', callback);
// 取消注册
scan.off('scanDeviceSync', callback);
```