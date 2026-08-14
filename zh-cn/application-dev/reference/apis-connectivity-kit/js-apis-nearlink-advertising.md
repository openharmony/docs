# @ohos.nearlink.advertising (星闪广播能力)
<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @CCCZKing-->
<!--Designer: @lilong32; @CCCZKing-->
<!--Tester: @zhangjiaji111-->
<!--Adviser: @zhang_yixin13-->



本模块提供了发送星闪广播的相关功能，包括启动广播、停止广播、订阅广播状态等。


**起始版本：** 26.0.0


## 导入模块

```typescript
import { advertising } from '@kit.ConnectivityKit';
```


## AdvertisingParams

表示发送广播携带的参数。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| advertisingSettings | [AdvertisingSettings](#advertisingsettings) | 否 | 否 | 广播配置参数。 |
| advertisingData | [AdvertisingData](#advertisingdata) | 否 | 否 | 广播数据包。 |


## AdvertisingSettings

表示广播配置参数。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| interval | number | 否 | 是 | 广播间隔配置参数。单位slot，范围160-16777215，默认值为5000。1个slot对应的时间长度是0.125ms，例如：5000\*0.125=625ms。 |
| power | [TxPowerMode](#txpowermode) | 否 | 是 | 广播发射功率配置参数。如果不配置，则默认值为ADV_TX_POWER_LOW。 |
| isConnectable | boolean | 否 | 是 | 表示广播能否连接。true: 表示可连接的广播。false：表示不可连接的广播。默认值为true。 |


## AdvertisingData

表示广播数据包。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| serviceUuids | string[] | 否 | 是 | 服务UUID列表。UUID长度必须为36个字符，由32个十六进制数字和4个连字符（-）组成。若未配置则默认不携带该字段。 |
| manufacturerData | [ManufacturerData](#manufacturerdata)[] | 否 | 是 | 厂商数据。若未配置则默认不携带该字段。 |
| serviceData | [ServiceData](#servicedata)[] | 否 | 是 | 服务数据。若未配置则默认不携带该字段。 |
| includeDeviceName | boolean | 否 | 是 | 指示广播数据中是否携带本机设备名。true：表示包含设备名称。false：表示不包含设备名称。默认值为false。 |


## ManufacturerData

表示厂商数据。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| manufacturerId | number | 否 | 否 | 厂商ID。取值范围[1, 65535]。 |
| manufacturerData | ArrayBuffer | 否 | 否 | 厂商数据。 |


## ServiceData

表示服务相关数据。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| serviceUuid | string | 否 | 否 | 表示服务的UUID。UUID长度必须为36个字符，由32个十六进制数字和4个连字符（-）组成。 |
| serviceData | ArrayBuffer | 否 | 否 | 表示服务数据。 |


## AdvertisingStateChangeInfo

表示广播启停状态变化信息。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| advertisingId | number | 否 | 否 | 表示广播ID。取值范围[0, 255]。 |
| state | [AdvertisingState](#advertisingstate) | 否 | 否 | 表示当前广播状态。 |


## TxPowerMode

表示广播发送模式，为枚举值。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| ADV_TX_POWER_LOW | 1 | 表示低功耗模式。 |
| ADV_TX_POWER_MEDIUM | 2 | 表示中等功耗模式。 |
| ADV_TX_POWER_HIGH | 3 | 表示高功耗模式。 |


## AdvertisingState

表示广播状态，为枚举值。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| STARTED | 1 | 表示广播已启动。 |
| STOPPED | 2 | 表示广播已停止。 |


## advertising.startAdvertising

startAdvertising(advertisingParams: AdvertisingParams): Promise&lt;number&gt;

发送星闪广播。使用Promise异步回调。适用于设备发现、设备信息广播等需要将本端设备能力或数据对外发布的业务场景，配合[advertising.onAdvertisingStateChange](#advertisingonadvertisingstatechange)可监听广播启停状态。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.ACCESS_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| advertisingParams | [AdvertisingParams](#advertisingparams) | 是 | 广播相关参数。 |

**返回值：** 

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;number&gt; | Promise对象，返回本次开启的广播ID。广播ID是随机分配的唯一标识值，范围[0, 255]，与[advertising.stopAdvertising](#advertisingstopadvertising)参数及[AdvertisingStateChangeInfo](#advertisingstatechangeinfo).advertisingId一致，可用于区分本次广播实例。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[NearLink错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 801 | Capability not supported because the chip does not support it. |
| 36100003 | NearLink disabled. |
| 36100040 | Integer out of range. |
| 36100043 | Invalid UUID. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { advertising } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let manufactureValueBuffer = new Uint8Array(4);
manufactureValueBuffer[0] = 1;
manufactureValueBuffer[1] = 2;
manufactureValueBuffer[2] = 3;
manufactureValueBuffer[3] = 4;
let serviceValueBuffer = new Uint8Array(4);
serviceValueBuffer[0] = 4;
serviceValueBuffer[1] = 6;
serviceValueBuffer[2] = 7;
serviceValueBuffer[3] = 8;
console.info('manufactureValueBuffer = ' + JSON.stringify(manufactureValueBuffer));
console.info('serviceValueBuffer = ' + JSON.stringify(serviceValueBuffer));
let setting: advertising.AdvertisingSettings = {
  interval:5000,
  power:advertising.TxPowerMode.ADV_TX_POWER_LOW
};
let manufactureDataUnit: advertising.ManufacturerData = {
  manufacturerId:4567,
  manufacturerData:manufactureValueBuffer.buffer
};
let serviceDataUnit: advertising.ServiceData = {
  serviceUuid:'FFFFFFFF-1234-5678-ABCD-000000001234',
  serviceData:serviceValueBuffer.buffer
};
let advData: advertising.AdvertisingData = {
  serviceUuids:['FFFFFFFF-1234-5678-ABCD-000000001234'],
  manufacturerData:[manufactureDataUnit],
  serviceData:[serviceDataUnit]
};
let advertisingParams: advertising.AdvertisingParams = {
  advertisingSettings: setting,
  advertisingData: advData
};
let advId = -1;
try {
  advertising.startAdvertising(advertisingParams).then((advertisingId:number) => {
    advId = advertisingId;
    console.info('advertising id:' + JSON.stringify(advId));
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## advertising.stopAdvertising

stopAdvertising(advertisingId: number): Promise&lt;void&gt;

停止发送星闪广播。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.ACCESS_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| advertisingId | number | 是 | 广播ID，开启广播时获取。取值范围[0, 255]。 |

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
| 36100040 | Invalid advertising ID. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { advertising } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let advId: number = 1; // advId在开启广播时获取，参考startAdvertising接口返回值
  advertising.stopAdvertising(advId).then(() => {
    console.info('stop advertising success');
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## advertising.onAdvertisingStateChange

onAdvertisingStateChange(callback: Callback&lt;AdvertisingStateChangeInfo&gt;): void

订阅星闪广播状态变化事件。使用callback异步回调。当调用[advertising.startAdvertising](#advertisingstartadvertising)启动广播或[advertising.stopAdvertising](#advertisingstopadvertising)停止广播时，回调函数会被触发，返回对应的广播ID与广播状态。需与[advertising.offAdvertisingStateChange](#advertisingoffadvertisingstatechange)配对使用。

应用需具备ohos.permission.ACCESS_NEARLINK权限，方可接收此事件上报。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[AdvertisingStateChangeInfo](#advertisingstatechangeinfo)&gt; | 是 | 回调函数，返回广播状态变化信息。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 801 | Capability not supported because the chip does not support it. |

**示例：** 
```typescript
import { advertising } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let onReceiveEvent:(data: advertising.AdvertisingStateChangeInfo) => void =
  (data: advertising.AdvertisingStateChangeInfo) => {
  console.info('advertisingId:' + data.advertisingId);
  console.info('advertisingState:' + data.state);
};
try {
  advertising.onAdvertisingStateChange(onReceiveEvent);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## advertising.offAdvertisingStateChange

offAdvertisingStateChange(callback?: Callback&lt;AdvertisingStateChangeInfo&gt;): void

取消订阅星闪广播状态变化事件。使用callback异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[AdvertisingStateChangeInfo](#advertisingstatechangeinfo)&gt; | 否 | 回调函数，返回广播启停状态变化信息。<br>填写该参数则取消当前callback订阅。不填写该参数则取消该事件对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 801 | Capability not supported because the chip does not support it. |

**示例：** 
```typescript
import { advertising } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  advertising.offAdvertisingStateChange();
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```
