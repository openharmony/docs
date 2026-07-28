# @ohos.nearlink.remoteDevice (对端设备的连接能力)
<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @CCCZKing-->
<!--Designer: @lilong32; @CCCZKing-->
<!--Tester: @zhangjiaji111-->
<!--Adviser: @zhang_yixin13-->


本模块提供了查询远端设备信息、发起配对等功能。


**系统能力：** SystemCapability.Communication.NearLink.Base


**起始版本：** 26.0.0


## 导入模块

```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
```


## PairingState

type PairingState = nearlinkConstant.PairingState

表示和远端设备的配对状态，为枚举值。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 类型 | 说明 |
| -------- | -------- |
| [nearlinkConstant.PairingState](js-apis-nearlink-constant.md#pairingstate) | 和远端设备的配对状态。 |


## ConnectionState

type ConnectionState = nearlinkConstant.ConnectionState

表示和远端设备的连接状态，为枚举值。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 类型 | 说明 |
| -------- | -------- |
| [nearlinkConstant.ConnectionState](js-apis-nearlink-constant.md#connectionstate) | 和远端设备的连接状态。 |


## DeviceClass

type DeviceClass = nearlinkConstant.DeviceClass

表示设备类型，为枚举值。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 类型 | 说明 |
| -------- | -------- |
| [nearlinkConstant.DeviceClass](js-apis-nearlink-constant.md#deviceclass) | 设备类型。 |


## AcbState

type AcbState = nearlinkConstant.AcbState

表示和远端设备的逻辑链路连接状态，为枚举值。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 类型 | 说明 |
| -------- | -------- |
| [nearlinkConstant.AcbState](js-apis-nearlink-constant.md#acbstate) | 和远端设备的逻辑链路连接状态。 |


## remoteDevice.createRemoteDevice

createRemoteDevice(address: string): RemoteDevice

创建远端设备实例。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| address | string | 是 | 远端设备地址。地址格式参考：11:22:33:AA:BB:FF。 |

**返回值：** 

| 类型 | 说明 |
| -------- | -------- |
| [RemoteDevice](#remotedevice) | 远端设备实例。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[NearLink错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 801 | Capability not supported because the chip does not support it. |
| 36100041 | Invalid address. |

**示例：** 
```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // 扫描获取到的远端设备地址
let device: remoteDevice.RemoteDevice;
try {
  device = remoteDevice.createRemoteDevice(addr);
  console.info('device: ' + JSON.stringify(device));
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## remoteDevice.onPairingStateChange

onPairingStateChange(callback: Callback&lt;PairingStateParam&gt;): void

订阅配对请求事件。使用callback异步回调。

应用需具备ohos.permission.ACCESS_NEARLINK权限，方可接收此事件上报。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[PairingStateParam](#pairingstateparam)&gt; | 是 | 回调函数，返回订阅的配对状态变化结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[NearLink错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 801 | Capability not supported because the chip does not support it. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { manager } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let onPairingStateEvent:(data: manager.PairingStateParam) => void = (data: manager.PairingStateParam) => {
  console.info('onPairingStateChange addr: ' + data.address + 'state:' + data.state);
};
try {
  manager.onPairingStateChange(onPairingStateEvent);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## remoteDevice.offPairingStateChange

offPairingStateChange(callback?: Callback&lt;PairingStateParam&gt;): void

取消订阅配对请求事件。使用callback异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[PairingStateParam](#pairingstateparam)&gt; | 否 | 回调函数，返回订阅的配对状态变化结果。<br/>填写该参数则取消当前callback订阅。不填写该参数则取消该type对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[NearLink错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 801 | Capability not supported because the chip does not support it. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { manager } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  manager.offPairingStateChange();
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## remoteDevice.onConnectionStateChange

onConnectionStateChange(callback: Callback&lt;ConnectionStateParam&gt;): void

订阅连接状态变化事件。使用callback异步回调。

应用需具备ohos.permission.ACCESS_NEARLINK权限，方可接收此事件上报。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[ConnectionStateParam](#connectionstateparam)&gt; | 是 | 回调函数，返回订阅的连接状态变化事件上报结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[NearLink错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 801 | Capability not supported because the chip does not support it. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { manager } from '@kit.ConnectivityKit';
import { BusinessError, Callback } from '@kit.BasicServicesKit';

let callback: Callback<manager.ConnectionStateParam> = (data: manager.ConnectionStateParam) => {
  console.info('data:' + JSON.stringify(data));
};
try {
  manager.onConnectionStateChange(callback);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## remoteDevice.offConnectionStateChange

offConnectionStateChange(callback?: Callback&lt;ConnectionStateParam&gt;): void

取消订阅连接状态变化事件。使用callback异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[ConnectionStateParam](#connectionstateparam)&gt; | 否 | 回调函数，返回订阅的连接状态变化事件上报结果。<br/>填写该参数则取消当前callback订阅。不填写该参数则取消该type对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[NearLink错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 801 | Capability not supported because the chip does not support it. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { manager } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  manager.offConnectionStateChange();
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## remoteDevice.onAcbStateChange

onAcbStateChange(callback: Callback&lt;AcbStateParam&gt;): void

订阅逻辑链路连接状态变化事件。使用callback异步回调。

应用需具备ohos.permission.ACCESS_NEARLINK权限，方可接收此事件上报。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[AcbStateParam](#acbstateparam)&gt; | 是 | 回调函数，返回订阅的逻辑链路连接状态变化事件上报结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[NearLink错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 801 | Capability not supported because the chip does not support it. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { manager } from '@kit.ConnectivityKit';
import { BusinessError, Callback } from '@kit.BasicServicesKit';

let callback: Callback<manager.AcbStateParam> = (data: manager.AcbStateParam) => {
  console.info('data:' + JSON.stringify(data));
};
try {
  manager.onAcbStateChange(callback);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## remoteDevice.offAcbStateChange

offAcbStateChange(callback?: Callback&lt;AcbStateParam&gt;): void

取消订阅逻辑链路连接状态变化事件。使用callback异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[AcbStateParam](#acbstateparam)&gt; | 否 | 回调函数，返回订阅的逻辑链路连接状态变化事件上报结果。<br/>填写该参数则取消当前callback订阅。不填写该参数则取消该type对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[NearLink错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 801 | Capability not supported because the chip does not support it. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { manager } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  manager.offAcbStateChange();
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## RemoteDevice

提供远端设备的操作方法，使用前需要使用[remoteDevice.createRemoteDevice](#remotedevicecreateremotedevice)方法创建一个远端设备[RemoteDevice](#remotedevice)实例。

一个设备只需要创建一次，无需多次创建。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

### startPairing

startPairing(): Promise&lt;void&gt;

发起与远端设备的配对。使用Promise异步回调。发起配对后，将依据本端与远端设备的输入输出能力标识弹出不同类型的弹窗，需使用者进一步确认。

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
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // 扫描获取到的远端设备地址
let device: remoteDevice.RemoteDevice;
try {
  device = remoteDevice.createRemoteDevice(addr);
  device.startPairing().then(()=>{
    console.info('start pairing success');
  }).catch ((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### getPairingState

getPairingState(): PairingState

获取和远端设备的配对状态。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.ACCESS_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**返回值：** 

| 类型 | 说明 |
| -------- | -------- |
| [PairingState](js-apis-nearlink-constant.md#pairingstate) | 和远端设备的配对状态。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[NearLink错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // 扫描获取到的远端设备地址
let device: remoteDevice.RemoteDevice;
try {
  device = remoteDevice.createRemoteDevice(addr);
  let state: remoteDevice.PairingState = device.getPairingState();
  console.info('state:' + JSON.stringify(state));
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### getDeviceName

getDeviceName(): string

获取远端设备名称。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.ACCESS_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**返回值：** 

| 类型 | 说明 |
| -------- | -------- |
| string | 远端设备名称。最大长度为30。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[NearLink错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // 扫描获取到的远端设备地址
let device: remoteDevice.RemoteDevice;
try {
  device = remoteDevice.createRemoteDevice(addr);
  let name: string = device.getDeviceName();
  console.info('name:' + JSON.stringify(name));
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### getDeviceClass

getDeviceClass(): DeviceClass

获取远端设备类型。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.ACCESS_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**返回值：** 

| 类型 | 说明 |
| -------- | -------- |
| [DeviceClass](js-apis-nearlink-constant.md#deviceclass) | 远端设备类型。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[NearLink错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // 扫描获取到的远端设备地址
let device: remoteDevice.RemoteDevice;
try {
  device = remoteDevice.createRemoteDevice(addr);
  let type: remoteDevice.DeviceClass = device.getDeviceClass();
  console.info('type:' + JSON.stringify(type));
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### getConnectionState

getConnectionState(): ConnectionState

获取本端设备和远端设备的连接状态。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.ACCESS_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**返回值：** 

| 类型 | 说明 |
| -------- | -------- |
| [ConnectionState](js-apis-nearlink-constant.md#connectionstate) | 本端设备和远端设备的连接状态。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[NearLink错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // 扫描获取到的远端设备地址
let device: remoteDevice.RemoteDevice;
try {
  device = remoteDevice.createRemoteDevice(addr);
  let state: remoteDevice.ConnectionState = device.getConnectionState();
  console.info('state:' + JSON.stringify(state));
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### getAcbState

getAcbState(): AcbState

获取和远端设备的逻辑链路连接状态。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.ACCESS_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**返回值：** 

| 类型 | 说明 |
| -------- | -------- |
| [AcbState](js-apis-nearlink-constant.md#acbstate) | 和远端设备的逻辑链路连接状态。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[NearLink错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // 扫描获取到的远端设备地址
let device: remoteDevice.RemoteDevice;
try {
  device = remoteDevice.createRemoteDevice(addr);
  let state: remoteDevice.AcbState = device.getAcbState();
  console.info('state:' + JSON.stringify(state));
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### getDeviceInformation

getDeviceInformation(): DeviceInformation

获取远端设备的设备信息。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.ACCESS_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**返回值：** 

| 类型 | 说明 |
| -------- | -------- |
| [DeviceInformation](#deviceinformation) | 远端设备的设备信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[NearLink错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { buffer } from '@kit.ArkTS';

let addr: string = '00:11:22:33:AA:FF'; // 扫描获取到的远端设备地址
let device: remoteDevice.RemoteDevice;
try {
  device = remoteDevice.createRemoteDevice(addr);
  let deviceInfo: remoteDevice.DeviceInformation = device.getDeviceInformation();
  console.info('deviceInfo.manufacturerData:' + buffer.from(deviceInfo.manufacturerData, 'binary').toString('hex'));
  console.info('deviceInfo.modelData:' + buffer.from(deviceInfo.modelData, 'binary').toString('hex'));
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### DeviceInformation

表示远端设备信息。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| manufacturerData | string | 否 | 否 | 厂商信息。 |
| modelData | string | 否 | 否 | 设备型号信息。 |

### ConnectionStateParam

订阅的连接状态变化事件上报结果。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| address | string | 否 | 否 | 设备地址，表示和该设备的连接状态发生变化。地址格式参考：11:22:33:AA:BB:FF。 |
| preState | [ConnectionState](js-apis-nearlink-constant.md#connectionstate) | 否 | 否 | 本次上报之前的连接状态。 |
| state | [ConnectionState](js-apis-nearlink-constant.md#connectionstate) | 否 | 否 | 当前连接状态。 |
| connectionReason | [ConnectionReason](#connectionreason) | 否 | 否 | 原因值。 |
| reasonMsg | string | 否 | 是 | 原因详情。该字段仅用于日志信息，不应用于逻辑处理。 |

### ConnectionReason

星闪连接状态变化结果的原因值。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| CONNECTION_SUCCESS | 0 | 表示连接成功。 |
| CONNECTION_FAILURE | 1 | 表示连接失败。 |
| CONNECTION_LOCAL_DISCONNECT | 2 | 表示本地设备主动断连。 |
| CONNECTION_REMOTE_DISCONNECT | 3 | 表示远端设备主动断连。 |
| CONNECTION_FAIL_ACB_CONNECTION | 4 | 表示ACB连接失败（可能因为远端设备关闭、设备距离过远）。 |
| CONNECTION_FAIL_SERVICE_DISCOVERY | 5 | 表示服务发现失败（可能服务发现超时）。 |
| CONNECTION_FAIL_NO_AVAILABLE_SERVICE | 6 | 表示没有可连接/可用的profile。 |
| CONNECTION_FAIL_CONNECTION_NUM_LIMITED | 7 | 表示连接数超出限制。 |


### PairingStateParam

订阅的配对状态变化结果。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| address | string | 否 | 否 | 设备地址，表示和该设备的配对状态发生变化。地址格式参考：11:22:33:AA:BB:FF。 |
| preState | [PairingState](js-apis-nearlink-constant.md#pairingstate) | 否 | 否 | 本次上报之前的配对状态。 |
| state | [PairingState](js-apis-nearlink-constant.md#pairingstate) | 否 | 否 | 当前配对状态。 |
| reason | [PairingReason](#pairingreason) | 否 | 否 | 原因值。 |
| reasonMsg | string | 否 | 是 | 原因详情。该字段仅用于日志信息，不应用于逻辑处理。 |


### PairingRequestParam

表示订阅的配对请求事件上报结果。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| address | string | 否 | 否 | 设备地址，表示收到该设备的配对请求上报。地址格式参考：11:22:33:AA:BB:FF。 |
| passkey | string | 否 | 否 | 表示配对交互的配对码，显示给用户确认。长度固定为6，字符串内容为数字。 |
| pairingType | [PairingType](#pairingtype) | 否 | 否 | 表示配对类型。 |


### PairingReason

表示星闪配对状态变化结果的原因值，为枚举值。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| PAIRING_REASON_SUCCESS | 0 | 表示配对成功。 |
| PAIRING_REASON_FAILURE | 1 | 表示配对失败。 |
| PAIRING_REASON_ACB_CONNECTION_FAIL | 2 | 表示ACB连接失败，可能远端设备已断电或超出范围。 |
| PAIRING_REASON_EXCEED_ACB_MAX | 3 | 表示连接设备数已达上限导致配对失败。 |
| PAIRING_REASON_REMOTE_CANCELED | 4 | 表示对端设备取消配对导致配对失败。 |
| PAIRING_REASON_LOCAL_CANCELED | 5 | 表示本端设备取消配对导致配对失败。 |
| PAIRING_REASON_AUTH_FAIL | 6 | 表示身份验证失败。 |


## PairingType

星闪配对类型，为枚举值。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| NO_PASSKEY_CONFIRMATION | 0 | 表示不需要passkey的配对方式，用户无需检查配对码。 |
| PAIRING_TYPE_PASSCODE | 1 | 表示通行码鉴权方式，用户需在一端设备输入另一端设备显示的配对码。 |
| PAIRING_TYPE_NUMBER_COMPARE | 2 | 表示数字比较鉴权方式，用户需在两端设备确认配对码一致。 |


## AcbStateParam

订阅的逻辑链路连接状态变化事件上报结果。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| address | string | 否 | 否 | 设备地址，表示和该设备的逻辑链路连接状态发生变化。地址格式参考：11:22:33:AA:BB:FF。 |
| state | [AcbState](js-apis-nearlink-constant.md#acbstate) | 否 | 否 | 当前逻辑链路连接状态。 |
