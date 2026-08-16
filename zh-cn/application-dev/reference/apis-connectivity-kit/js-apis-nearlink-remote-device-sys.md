# @ohos.nearlink.remoteDevice (星闪远端设备连接能力)(系统接口)
<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @CCCZKing-->
<!--Designer: @lilong32; @CCCZKing-->
<!--Tester: @zhangjiaji111-->
<!--Adviser: @zhang_yixin13-->


本模块提供了星闪远端设备的连接与管理能力，包括连接与断开远端设备、可信配对与确认、调整连接间隔、订阅配对请求等。

**起始版本：** 26.0.0

> **说明：**
>
> 本模块接口为系统接口。


## 导入模块

```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
```

## ConnectionInterval

type ConnectionInterval = nearlinkConstant.ConnectionInterval

表示连接间隔，为枚举值。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 类型 | 说明 |
| -------- | -------- |
| [nearlinkConstant.ConnectionInterval](js-apis-nearlink-constant-sys.md#connectioninterval) | 连接间隔。 |

## DeviceModel

描述远端设备的型号信息。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| modelId | string | 否 | 否 | 远端设备的型号ID。 |
| subModelId | string | 否 | 否 | 远端设备的子型号ID。 |
| iconId | string | 否 | 否 | 远端设备的图标ID。 |

## RemoteDevice

提供远端设备的操作方法，使用前需要使用[remoteDevice.createRemoteDevice](js-apis-nearlink-remote-device.md#remotedevicecreateremotedevice)方法创建一个远端设备[RemoteDevice](js-apis-nearlink-remote-device.md#remotedevice)实例。一个设备只需要创建一次，无需多次创建。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base


### startCrediblePairing

startCrediblePairing(): Promise&lt;void&gt;

向可信远端设备发起免弹窗配对。使用Promise异步回调。

**起始版本：** 26.0.0

**系统接口：**  此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_NEARLINK and ohos.permission.MANAGE_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[星闪错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications are not allowed to use system APIs. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**示例：**
```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@ohos.base';

try {
  let addr: string = '11:22:33:44:AA:FF';
  let device: remoteDevice.RemoteDevice = remoteDevice.createRemoteDevice(addr);
  device.startCrediblePairing().then(() => {
    console.info('start pairing success');
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### removePairedDevice

removePairedDevice(): Promise&lt;void&gt;

删除已配对设备。使用Promise异步回调。

**起始版本：** 26.0.0

**系统接口：**  此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_NEARLINK and ohos.permission.MANAGE_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[星闪错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications are not allowed to use system APIs. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**示例：**
```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@ohos.base';

try {
  let addr: string = '11:22:33:44:AA:FF';
  let device: remoteDevice.RemoteDevice = remoteDevice.createRemoteDevice(addr);
  device.removePairedDevice().then(() => {
    console.info('remove paired device success');
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### setPairingConfirmation

setPairingConfirmation(accept: boolean): void

设置配对请求的确认结果。对端设备的配对请求通过[remoteDevice.onPairingRequest](#remotedeviceonpairingrequest)获取。

**起始版本：** 26.0.0

**系统接口：**  此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_NEARLINK and ohos.permission.MANAGE_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| accept | boolean | 是 | 配对确认。true：接受配对。false：拒绝配对。| 

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[星闪错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications are not allowed to use system APIs. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**示例：**
```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@ohos.base';

try {
  let addr: string = '11:22:33:44:AA:FF';
  let device: remoteDevice.RemoteDevice = remoteDevice.createRemoteDevice(addr);
  device.setPairingConfirmation(true);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### connect

connect(): Promise&lt;void&gt;

向远端设备发起连接。使用Promise异步回调。

**起始版本：** 26.0.0

**系统接口：**  此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_NEARLINK and ohos.permission.MANAGE_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[星闪错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications are not allowed to use system APIs. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**示例：**
```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@ohos.base';

try {
  let addr: string = '11:22:33:44:AA:FF';
  let device: remoteDevice.RemoteDevice = remoteDevice.createRemoteDevice(addr);
  device.connect().then(() => {
    console.info('connect success');
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### disconnect

disconnect(): Promise&lt;void&gt;

断开远端设备的连接。使用Promise异步回调。

**起始版本：** 26.0.0

**系统接口：**  此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_NEARLINK and ohos.permission.MANAGE_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[星闪错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications are not allowed to use system APIs. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**示例：**
```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@ohos.base';

try {
  let addr: string = '11:22:33:44:AA:FF';
  let device: remoteDevice.RemoteDevice = remoteDevice.createRemoteDevice(addr);
  device.disconnect().then(() => {
    console.info('disconnect success');
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### setDeviceAlias

setDeviceAlias(alias: string): void

设置远端设备别名。

**起始版本：** 26.0.0

**系统接口：**  此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_NEARLINK and ohos.permission.MANAGE_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| alias | string | 是 | 远端设备别名。最大长度为64个字符，不能为空。| 

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[星闪错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications are not allowed to use system APIs. |
| 36100003 | NearLink disabled. |
| 36100046 | String exceeds maximum length. |
| 36100099 | Operation failed. |

**示例：**
```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@ohos.base';

let addr: string = '11:22:33:44:AA:FF'; // 扫描获取到的远端设备地址
let device: remoteDevice.RemoteDevice = remoteDevice.createRemoteDevice(addr);
try {
  let alias: string = 'test';
  device.setDeviceAlias(alias);
  console.info('set alias success');
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### getDeviceAlias

getDeviceAlias(): string

获取远端设备别名。

**起始版本：** 26.0.0

**系统接口：**  此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_NEARLINK and ohos.permission.MANAGE_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 远端设备别名。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[星闪错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications are not allowed to use system APIs. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**示例：**
```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@ohos.base';

let addr: string = '11:22:33:44:AA:FF'; // 扫描获取到的远端设备地址
let device: remoteDevice.RemoteDevice = remoteDevice.createRemoteDevice(addr);
try {
  let alias: string = 'test';
  device.setDeviceAlias(alias);
  let ret: string = device.getDeviceAlias();
  console.info('get alias success, ret:' + ret);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### getDeviceModel

getDeviceModel(): DeviceModel

获取远端设备型号。

**起始版本：** 26.0.0

**系统接口：**  此接口为系统接口。

**系统能力：** SystemCapability.Communication.NearLink.Base

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [DeviceModel](#devicemodel) | 远端设备的型号。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[星闪错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 202 | Non-system applications are not allowed to use system APIs. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**示例：**
```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let addr: string = '00:11:22:33:AA:FF';
  let device: remoteDevice.RemoteDevice = remoteDevice.createRemoteDevice(addr);
  let model: remoteDevice.DeviceModel = device.getDeviceModel();
  console.info('modelId:' + JSON.stringify(model.modelId));
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### cancelDevicePairing

cancelDevicePairing(): Promise&lt;void&gt;

取消正在进行的配对请求。使用Promise异步回调。

**起始版本：** 26.0.0

**系统接口：**  此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_NEARLINK and ohos.permission.MANAGE_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[星闪错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications are not allowed to use system APIs. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**示例：**
```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let addr: string = '00:11:22:33:AA:FF';
  let device: remoteDevice.RemoteDevice = remoteDevice.createRemoteDevice(addr);
  device.cancelDevicePairing().then(() => {
    console.info('cancelDevicePairing success');
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### setPairingPasscode

setPairingPasscode(passcode: string): Promise&lt;void&gt;

设置配对通行码。使用Promise异步回调。

**起始版本：** 26.0.0

**系统接口：**  此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_NEARLINK and ohos.permission.MANAGE_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| passcode | string | 是 | 用户输入的配对通行码，必须为六位数字。| 

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[星闪错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications are not allowed to use system APIs. |
| 36100003 | NearLink disabled. |
| 36100045 | Passcode must be a 6-digit number. |
| 36100099 | Operation failed. |

**示例：**
```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let addr: string = '00:11:22:33:AA:FF';
  let passcode: string = '123456';
  let device: remoteDevice.RemoteDevice = remoteDevice.createRemoteDevice(addr);
  device.setPairingPasscode(passcode).then(() => {
    console.info('setPairingPasscode success');
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### getRssiValue

getRssiValue(): Promise&lt;number&gt;

获取远端设备的信号强度（RSSI）。使用Promise异步回调。

**起始版本：** 26.0.0

**系统接口：**  此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;number&gt; | Promise对象，返回RSSI值。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[星闪错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications are not allowed to use system APIs. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**示例：**
```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let addr: string = '00:11:22:33:AA:FF';
  let device: remoteDevice.RemoteDevice = remoteDevice.createRemoteDevice(addr);
  device.getRssiValue().then((rssi: number) => {
    console.info('getRssiValue: ' + rssi);
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### setConnectionInterval

setConnectionInterval(interval: ConnectionInterval): void

设置和远端设备的连接间隔。

**起始版本：** 26.0.0

**系统接口：**  此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| interval | [ConnectionInterval](#connectioninterval) | 是 | 要设置的连接间隔。| 

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[星闪错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications are not allowed to use system APIs. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**示例：**
```typescript
import { remoteDevice, nearlinkConstant } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let addr: string = '00:11:22:33:AA:FF';
  let device: remoteDevice.RemoteDevice = remoteDevice.createRemoteDevice(addr);
  let interval: nearlinkConstant.ConnectionInterval = nearlinkConstant.ConnectionInterval.HIGH_SPEED_INTERVAL_4_5;
  device.setConnectionInterval(interval);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### remoteDevice.onPairingRequest

onPairingRequest(callback: Callback&lt;PairingRequestParam&gt;): void

订阅配对请求事件。使用callback异步回调。

应用需具备ohos.permission.ACCESS_NEARLINK权限，方可接收此事件上报。

事件默认返回随机地址；应用若具备系统权限ohos.permission.GET_NEARLINK_PEER_MAC，则返回设备真实地址。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：**  此接口为系统接口。

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[PairingRequestParam](js-apis-nearlink-remote-device.md#pairingrequestparam)&gt; | 是 | 回调函数，返回配对请求字段。| 

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[星闪错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 202 | Non-system applications are not allowed to use system APIs. |
| 801 | Capability not supported because the chip does not support it. |
| 36100099 | Operation failed. |

**示例：**
```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError, Callback } from '@ohos.base';

let callback: Callback<remoteDevice.PairingRequestParam> = (data: remoteDevice.PairingRequestParam) => {
  console.info('pairing request param: ' + JSON.stringify(data));
};

try {
  remoteDevice.onPairingRequest(callback);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### remoteDevice.offPairingRequest

offPairingRequest(callback?: Callback&lt;PairingRequestParam&gt;): void

取消订阅配对请求事件。使用callback异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：**  此接口为系统接口。

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[PairingRequestParam](js-apis-nearlink-remote-device.md#pairingrequestparam)&gt; | 否 | 回调函数，返回配对请求字段。<br>填写该参数则取消当前callback订阅。不填写该参数则取消该事件对应的所有回调。| 

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[星闪错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 202 | Non-system applications are not allowed to use system APIs. |
| 801 | Capability not supported because the chip does not support it. |
| 36100099 | Operation failed. |

**示例：**
```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@ohos.base';

try {
  remoteDevice.offPairingRequest();
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```