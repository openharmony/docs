# @ohos.nearlink.scan (星闪扫描能力)
<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @CCCZKing-->
<!--Designer: @lilong32; @CCCZKing-->
<!--Tester: @zhangjiaji111-->
<!--Adviser: @zhang_yixin13-->


本模块提供了星闪扫描相关功能，包括发起/停止扫描、订阅扫描结果等。


**起始版本：** 26.0.0


## 导入模块

```typescript
import { scan } from '@kit.ConnectivityKit';
```

## scan.startScan

startScan(filters: ScanFilters[] | null, options?: ScanOptions): Promise&lt;void&gt;

发起星闪扫描。使用Promise异步回调。需先调用[scan.onDeviceFound](#scanondevicefound)订阅扫描结果回调，本接口发起扫描后，扫描到的设备信息通过[scan.onDeviceFound](#scanondevicefound)回调上报。扫描完成后可调用[scan.stopScan](#scanstopscan)停止扫描。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.ACCESS_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| filters | [ScanFilters](#scanfilters)[] \| null | 是 | 扫描星闪广播的过滤条件集合，符合过滤条件的设备会被上报。若不使能过滤器则传入null。<br>若该参数设置为null，将扫描所有可发现的周边星闪设备，但是不建议使用此方式，可能扫描到非预期设备，并增加功耗。 |
| options | [ScanOptions](#scanoptions) | 否 | 表示扫描选项。默认为低功耗模式。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[NearLink错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 801 | Capability not supported because the chip does not support it. |
| 36100003 | NearLink disabled. |
| 36100040 | Integer out of range. |
| 36100041 | Invalid address. |
| 36100042 | Empty array. |
| 36100099 | Operation failed. |

**示例：**
```typescript
import { scan } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 不使用过滤器进行扫描
try {
  scan.startScan(null).then(() => {
    console.info('start scan without filter success');
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}

// 使用过滤器进行扫描
let scanFilter: scan.ScanFilters = {
  address: '11:22:33:44:AA:FF',
  deviceName: 'device name'
};
try {
  scan.startScan([scanFilter]).then(() => {
    console.info('start scan with filter success');
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## scan.stopScan

stopScan(): Promise&lt;void&gt;

停止星闪扫描。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.ACCESS_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**返回值：** 

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[NearLink错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 801 | Capability not supported because the chip does not support it. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { scan } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  scan.stopScan().then(() => {
    console.info('stop scan success');
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## scan.onDeviceFound

onDeviceFound(callback: Callback\<ScanResults[]\>): void

订阅星闪扫描结果。使用callback异步回调。

应用需具备ohos.permission.ACCESS_NEARLINK权限，方可接收此事件上报。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&zwnj;\<&zwnj;&zwnj;[ScanResults](#scanresults)&zwnj;[]&zwnj;\> | 是 | 回调函数，返回星闪扫描结果数组对象。扫描结果默认返回随机地址；应用若具备系统权限ohos.permission.GET_NEARLINK_PEER_MAC，则返回设备真实地址。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 801 | Capability not supported because the chip does not support it. |

**示例：** 
```typescript
import { scan } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let onReceiveEvent:(data: scan.ScanResults[]) => void = (data: scan.ScanResults[]) => {
  console.info('scan result addr:' + data[0].address + 'name:' + data[0].deviceName);
};
try {
  scan.onDeviceFound(onReceiveEvent);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## scan.offDeviceFound

offDeviceFound(callback?: Callback\<ScanResults[]\>): void

取消订阅星闪扫描结果。使用callback异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;&zwnj;[ScanResults](#scanresults)&zwnj;[]&gt; | 否 | 回调函数，返回星闪扫描结果数组对象。<br>填写该参数则取消当前callback订阅。不填写该参数则取消该事件对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 801 | Capability not supported because the chip does not support it. |

**示例：** 
```typescript
import { scan } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  scan.offDeviceFound();
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## ScanResults

表示扫描结果。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| address | string | 否 | 否 | 表示扫描到设备地址。地址格式参考：11:22:33:AA:BB:FF。 |
| rssi | number | 否 | 否 | 表示扫描到的设备rssi值，取值范围[-128, 127]，单位：dBm，其中127表示无效值。 |
| data | ArrayBuffer | 否 | 否 | 表示广播包数据。 |
| deviceName | string | 否 | 否 | 表示扫描到的设备名称。字符串长度范围[0, 30]。 |
| isConnectable | boolean | 否 | 否 | 表示扫描到的广播是否可连接。true：可连接，false：不可连接 |
| deviceClass | [nearlinkConstant.DeviceClass](js-apis-nearlink-constant.md#deviceclass) | 否 | 是 | 表示扫描到的设备类型。设备广播未携带设备类型信息时该字段不返回。 |


## ScanFilters

表示扫描过滤条件。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| address | string | 否 | 是 | 表示设备地址，若未配置则默认不过滤该字段。地址格式参考：11:22:33:AA:BB:FF。 |
| deviceName | string | 否 | 是 | 表示设备名称，字符串长度范围[0, 30]。若未配置则默认不过滤该字段。 |
| manufacturerId | number | 否 | 是 | 表示厂商ID，取值范围[1, 65535]，若未配置则默认不过滤该字段。 |
| manufacturerData | ArrayBuffer | 否 | 是 | 表示厂商数据，若未配置则默认不过滤该字段。配置该字段需同时配置manufacturerId。 |
| manufacturerDataMask | ArrayBuffer | 否 | 是 | 表示厂商数据掩码，若未配置则默认不过滤该字段。配置该字段需同时配置manufacturerData，且二者长度必须一致。掩码与厂商数据按位与运算，用于精确匹配厂商数据中指定比特位。 |
| rssi | number | 否 | 是 | 过滤信号强度大于或等于该信号强度门限值的广播报文，取值范围[-128, 127]，单位：dBm。建议设置[-90, 20]范围内的门限值。若未配置则默认不对信号强度进行过滤。 |


## ScanOptions

表示扫描选项。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| scanMode | [ScanMode](#scanmode) | 否 | 是 | 表示扫描模式。默认值为'SCAN_MODE_LOW_POWER'。 |
| duration | number | 否 | 是 | 表示扫描持续时间。单位：秒，取值范围[10, 60]，默认值为全时段扫描。 |


## ScanMode

表示扫描模式，为枚举值。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| SCAN_MODE_LOW_POWER | 0 | 表示低功耗扫描模式，扫描频率低，功耗低。默认值。 |
| SCAN_MODE_BALANCED | 1 | 表示均衡扫描模式，扫描频率中等，功耗中等。 |
