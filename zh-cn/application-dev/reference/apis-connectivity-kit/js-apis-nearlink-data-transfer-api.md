# @ohos.nearlink.dataTransfer (星闪数传能力)
<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @CCCZKing-->
<!--Designer: @lilong32; @CCCZKing-->
<!--Tester: @zhangjiaji111-->
<!--Adviser: @zhang_yixin13-->


本模块提供了星闪数据传输的功能，包括端口通道的注册与销毁、远端设备连接管理、连接状态查询与订阅、数据的发送与接收等。


**起始版本：** 26.0.0


## 导入模块

```typescript
import { dataTransfer } from '@kit.ConnectivityKit';
```


## ConnectionState

type ConnectionState = nearlinkConstant.ConnectionState

表示和远端设备的连接状态，为枚举值。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 类型 | 说明 |
| -------- | -------- |
| [nearlinkConstant.ConnectionState](js-apis-nearlink-constant.md#connectionstate) | 和远端设备的连接状态。 |


## dataTransfer.createPort

createPort(uuid: string): void

注册端口通道。端口通道注册后方可用于连接远端设备，不再使用时需通过[dataTransfer.destroyPort](#datatransferdestroyport)销毁。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.ACCESS_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| uuid | string | 是 | 星闪服务UUID，长度必须为36个字符，由32个十六进制数字和4个连字符（-）组成，例如： FFFFFFFF-1234-5678-ABCD-000000001234，表示一个128位标识符。 不允许使用星闪标准UUID。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[NearLink错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 801 | Capability not supported because the chip does not support it. |
| 36100003 | NearLink disabled. |
| 36100020 | The UUID is already registered. |
| 36100021 | Port exceeds the upper limit. |
| 36100043 | Invalid UUID. |
| 36100044 | NearLink standard UUID not allowed. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { dataTransfer} from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let uuid: string = 'FFFFFFFF-FC70-11EA-B720-000078951234'; // 星闪服务UUID
  dataTransfer.createPort(uuid);
  console.info('create port success');
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## dataTransfer.destroyPort

destroyPort(uuid: string): void

销毁端口通道。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.ACCESS_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| uuid | string | 是 | 星闪服务UUID，长度必须为36个字符，由32个十六进制数字和4个连字符（-）组成，例如： FFFFFFFF-1234-5678-ABCD-000000001234，表示一个128位标识符。 不允许使用星闪标准UUID。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[NearLink错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 801 | Capability not supported because the chip does not support it. |
| 36100003 | NearLink disabled. |
| 36100022 | The UUID is not registered. |
| 36100043 | Invalid UUID. |
| 36100044 | NearLink standard UUID not allowed. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { dataTransfer} from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let uuid: string = 'FFFFFFFF-FC70-11EA-B720-000078951234'; // 星闪服务UUID
  dataTransfer.destroyPort(uuid);
  console.info('destroy port success');
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## dataTransfer.connect

connect(params: ConnectionParams): Promise&lt;void&gt;

连接远端设备。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.ACCESS_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| params | [ConnectionParams](#connectionparams) | 是 | 指明端口的连接参数。 |

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
| 36100041 | Invalid address. |
| 36100043 | Invalid UUID. |
| 36100044 | NearLink standard UUID not allowed. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { dataTransfer} from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // 构造连接参数
  let connectionParams:dataTransfer.ConnectionParams = {
    address: '01:02:03:04:05:06', // 星闪远端设备地址，可通过扫描获取
    uuid: 'FFFFFFFF-1234-5678-ABCD-000000001234', // 星闪服务UUID
  };
  dataTransfer.connect(connectionParams).then(() => {
    console.info('connect success');
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## dataTransfer.disconnect

disconnect(params: ConnectionParams): Promise&lt;void&gt;

断连远端设备。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.ACCESS_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| params | [ConnectionParams](#connectionparams) | 是 | 指明端口的连接参数。 |

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
| 36100041 | Invalid address. |
| 36100043 | Invalid UUID. |
| 36100044 | NearLink standard UUID not allowed. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { dataTransfer} from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // 构造连接参数，用于指定要断开的连接
  let connectionParams:dataTransfer.ConnectionParams = {
    address: '01:02:03:04:05:06', // 星闪远端设备地址，可通过扫描获取
    uuid: 'FFFFFFFF-1234-5678-ABCD-000000001234', // 星闪服务UUID
  };
  dataTransfer.disconnect(connectionParams).then(() => {
    console.info('disconnect success');
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## dataTransfer.onConnectionStateChanged

onConnectionStateChanged(callback: Callback&lt;ConnectionResult&gt;): void

订阅端口通道连接状态变更事件。使用callback异步回调。

应用需具备ohos.permission.ACCESS_NEARLINK权限，方可接收此事件上报。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[ConnectionResult](#connectionresult)&gt; | 是 | 回调函数，返回与远端设备端口连接参数的协商结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[NearLink错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 801 | Capability not supported because the chip does not support it. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { dataTransfer} from '@kit.ConnectivityKit';
import { BusinessError, Callback } from '@kit.BasicServicesKit';

let callback: Callback<dataTransfer.ConnectionResult> = (data: dataTransfer.ConnectionResult) => {
  console.info('data: ' + JSON.stringify(data));
};
try {
  dataTransfer.onConnectionStateChanged(callback);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## dataTransfer.offConnectionStateChanged

offConnectionStateChanged(callback?: Callback&lt;ConnectionResult&gt;): void

取消订阅端口通道连接状态变更事件。使用callback异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[ConnectionResult](#connectionresult)&gt; | 否 | 回调函数，返回与远端设备端口连接参数的协商结果。<br>填写该参数则取消当前callback订阅。不填写该参数则取消该事件对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[NearLink错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 801 | Capability not supported because the chip does not support it. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { dataTransfer} from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  dataTransfer.offConnectionStateChanged();
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## dataTransfer.getConnectionState

getConnectionState(params: ConnectionStateParams): ConnectionState

获取与远端设备之间的端口通道连接状态。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.ACCESS_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| params | [ConnectionStateParams](#connectionstateparams) | 是 | 指明端口的连接参数。 |

**返回值：** 

| 类型 | 说明 |
| -------- | -------- |
| [ConnectionState](js-apis-nearlink-constant.md#connectionstate) | 和远端设备的星闪端口通道连接状态。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[NearLink错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 801 | Capability not supported because the chip does not support it. |
| 36100003 | NearLink disabled. |
| 36100041 | Invalid address. |
| 36100043 | Invalid UUID in connection parameters. |
| 36100044 | NearLink standard UUID not allowed. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { dataTransfer } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let connectionStateParams:dataTransfer.ConnectionStateParams = {
    address: '01:02:03:04:05:06', // 扫描获取到的远端设备地址
    uuid: 'FFFFFFFF-FC70-11EA-B720-000078951234' // 星闪服务UUID示例
  };
  let state:dataTransfer.ConnectionState = dataTransfer.getConnectionState(connectionStateParams);
  console.info('state:' + JSON.stringify(state));
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## dataTransfer.writeData

writeData(params: DataParams): Promise&lt;void&gt;

通过设备地址和UUID向远端设备发送数据。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.ACCESS_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| params | [DataParams](#dataparams) | 是 | 指明发送数据的参数，包含远端设备地址、服务UUID以及发送的数据包。 |

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
| 36100023 | Write data congestion. |
| 36100041 | Invalid address. |
| 36100043 | Invalid UUID. |
| 36100044 | NearLink standard UUID not allowed. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { dataTransfer} from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // 构造发送数据参数
  let transferValueBuffer: Uint8Array = new Uint8Array(4);
  transferValueBuffer[0] = 1;
  transferValueBuffer[1] = 2;
  transferValueBuffer[2] = 3;
  transferValueBuffer[3] = 4;
  let dataParams: dataTransfer.DataParams = {
    address: '01:02:03:04:05:06', // 星闪远端设备地址
    uuid: 'FFFFFFFF-1234-5678-ABCD-000000001234', // 星闪服务UUID
    data: transferValueBuffer.buffer // 星闪设备间传输的数据
  };
  dataTransfer.writeData(dataParams).then(() => {
    console.info('writeData success');
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## dataTransfer.onReadData

onReadData(callback: Callback&lt;DataParams&gt;): void

订阅端口通道数据接收事件。使用callback异步回调。

应用需具备ohos.permission.ACCESS_NEARLINK权限，方可接收此事件上报。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[DataParams](#dataparams)&gt; | 是 | 回调函数，返回端口通道接收到的数据参数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[NearLink错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 801 | Capability not supported because the chip does not support it. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { dataTransfer} from '@kit.ConnectivityKit';
import { BusinessError, Callback } from '@kit.BasicServicesKit';

let callback: Callback<dataTransfer.DataParams> = (data: dataTransfer.DataParams) => {
  console.info('data: ' + JSON.stringify(data));
};
try {
  dataTransfer.onReadData(callback);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## dataTransfer.offReadData

offReadData(callback?: Callback&lt;DataParams&gt;): void

取消订阅端口通道数据接收事件。使用callback异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[DataParams](#dataparams)&gt; | 否 | 回调函数，返回端口通道接收到的数据参数。<br>填写该参数则取消当前callback订阅。不填写该参数则取消该事件对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[NearLink错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 801 | Capability not supported because the chip does not support it. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { dataTransfer} from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  dataTransfer.offReadData();
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## ConnectionParams

发起端口连接的参数。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| address | string | 否 | 否 | 远端设备的星闪地址。地址格式参考：11:22:33:AA:BB:FF。 |
| uuid | string | 否 | 否 | 星闪服务UUID，长度必须为36个字符，由32个十六进制数字和4个连字符（-）组成，例如： FFFFFFFF-1234-5678-ABCD-000000001234，表示一个128位标识符。 不允许使用星闪标准UUID。 |
| transferMode | [TransferMode](#transfermode) | 否 | 是 | 表示和远端设备的数据传输模式。默认值是BASIC。 |


## DataParams

端口数据发送和接收的参数。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| address | string | 否 | 否 | 远端设备的星闪地址。地址格式参考：11:22:33:AA:BB:FF。 |
| uuid | string | 否 | 否 | 星闪服务UUID，长度必须为36个字符，由32个十六进制数字和4个连字符（-）组成，例如： FFFFFFFF-1234-5678-ABCD-000000001234，表示一个128位标识符。 不允许使用星闪标准UUID。 |
| data | ArrayBuffer | 否 | 否 | 数据包。通过[dataTransfer.writeData](#datatransferwritedata)发送时表示待发送的数据，通过[dataTransfer.onReadData](#datatransferonreaddata)接收时表示接收到的数据。 |


## ConnectionResult

与远端设备端口连接参数的协商结果

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| address | string | 否 | 否 | 远端设备的星闪地址。地址格式参考：11:22:33:AA:BB:FF。 |
| uuid | string | 否 | 否 | 星闪服务UUID，长度必须为36个字符，由32个十六进制数字和4个连字符（-）组成，例如： FFFFFFFF-1234-5678-ABCD-000000001234，表示一个128位标识符。 不允许使用星闪标准UUID。 |
| mtu | number | 否 | 否 | 协商后的发送和接收数据的包长，单位为byte，范围[0, 65535]。 |
| state | [ConnectionState](js-apis-nearlink-constant.md#connectionstate) | 否 | 否 | 与远端设备的连接状态。 |


## ConnectionStateParams

获取端口通道连接状态所需参数。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| address | string | 否 | 否 | 远端设备的星闪地址。地址格式参考：11:22:33:AA:BB:FF。 |
| uuid | string | 否 | 否 | 星闪服务UUID，长度必须为36个字符，由32个十六进制数字和4个连字符（-）组成，例如： FFFFFFFF-1234-5678-ABCD-000000001234，表示一个128位标识符。 不允许使用星闪标准UUID。 |


## TransferMode

表示和远端设备的数据传输模式，为枚举值。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| BASIC | 0 | 表示基础模式，无数据重传机制。 |
| RELIABLE | 1 | 表示可靠模式，有数据重传机制。 |
