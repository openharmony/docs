# @ohos.nearlink.manager (星闪基础管理能力)
<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @CCCZKing-->
<!--Designer: @lilong32; @CCCZKing-->
<!--Tester: @zhangjiaji111-->
<!--Adviser: @zhang_yixin13-->


本模块提供了星闪基础管理能力，包括查询是否支持星闪、获取本端设备信息、管理星闪开关状态及订阅状态变化事件等。


**起始版本：** 26.0.0


## 导入模块

```typescript
import { manager } from '@kit.ConnectivityKit';
```


## manager.getState

getState(): NearlinkState

查询星闪开关状态。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

**返回值：** 

| 类型 | 说明 |
| -------- | -------- |
| [NearlinkState](#nearlinkstate) | 表示星闪开关状态。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[星闪错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 801 | Capability not supported because the chip does not support it. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { manager } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let state: manager.NearlinkState = manager.getState();
  console.info('state:' + JSON.stringify(state));
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## manager.isNearLinkSupported

isNearLinkSupported(): boolean

查询当前设备是否支持星闪服务。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

**返回值：** 

| 类型 | 说明 |
| -------- | -------- |
| boolean | 表示当前设备是否支持星闪。返回true：设备支持星闪。返回false：设备不支持星闪。 |

**示例：** 
```typescript
import { manager } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let isSupported: boolean = manager.isNearLinkSupported();
  if (isSupported) {
    console.info('NearLink is supported on this device.');
  } else {
    console.info('NearLink is not supported on this device.');
  }
} catch (err) {
  console.error('Error occurred: ' + (err as BusinessError).code + ', ' + (err as BusinessError).message);
}
```


## manager.getLocalName

getLocalName(): string

查询本机星闪名称。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.ACCESS_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**返回值：** 

| 类型 | 说明 |
| -------- | -------- |
| string | 表示星闪设备本地名称。最大长度为30个字符。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[星闪错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 801 | Capability not supported because the chip does not support it. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { manager } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let name: string = manager.getLocalName();
  console.info('name:' + JSON.stringify(name));
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## manager.getPairedDevices

getPairedDevices(): string[]

获取与当前设备配对的设备列表。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.ACCESS_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**返回值：** 

| 类型 | 说明 |
| -------- | -------- |
| string[] | 配对设备地址的列表。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[星闪错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 801 | Capability not supported because the chip does not support it. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { manager } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let pairedDevices: string[] = manager.getPairedDevices();
  if (pairedDevices.length > 0) {
        console.info('getPairedDevices return: ' + JSON.stringify(pairedDevices));
    } else {
        console.info('No Paired Devices found.');
    }
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## manager.onStateChange

onStateChange(callback: Callback&lt;NearlinkState&gt;): void

订阅星闪开关状态变化事件。使用callback异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[NearlinkState](#nearlinkstate)&gt; | 是 | 回调函数，返回星闪的开关状态。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[星闪错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 801 | Capability not supported because the chip does not support it. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { manager } from '@kit.ConnectivityKit';
import { BusinessError, Callback } from '@kit.BasicServicesKit';

let callback: Callback<manager.NearlinkState> = (data: manager.NearlinkState) => {
  if (data === manager.NearlinkState.STATE_TURNING_ON) {
    console.info('nearlink STATE_TURNING_ON');
  } else if (data === manager.NearlinkState.STATE_ON) {
    console.info('nearlink STATE_ON');
  } else if (data === manager.NearlinkState.STATE_TURNING_OFF) {
    console.info('nearlink STATE_TURNING_OFF');
  } else if (data === manager.NearlinkState.STATE_OFF) {
    console.info('nearlink STATE_OFF');
  }
};
try {
  manager.onStateChange(callback);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## manager.offStateChange

offStateChange(callback?: Callback&lt;NearlinkState&gt;): void

取消订阅星闪开关状态变化事件。使用callback异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[NearlinkState](#nearlinkstate)&gt; | 否 | 回调函数，返回星闪的开关状态。<br>填写该参数则取消当前callback订阅。不填写该参数则取消该事件对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[星闪错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 801 | Capability not supported because the chip does not support it. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { manager } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  manager.offStateChange();
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## NearlinkState

星闪的开关状态，为枚举值。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| STATE_TURNING_ON | 0 | 表示星闪正在打开。 |
| STATE_ON | 1 | 表示星闪已打开。 |
| STATE_TURNING_OFF | 2 | 表示星闪正在关闭。 |
| STATE_OFF | 3 | 表示星闪已关闭。 |
