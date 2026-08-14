# @ohos.nearlink.ssap (星闪SSAP连接能力)
<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @CCCZKing-->
<!--Designer: @lilong32; @CCCZKing-->
<!--Tester: @zhangjiaji111-->
<!--Adviser: @zhang_yixin13-->


本模块提供了星闪服务交互协议（SparkLink Service Access Protocol，SSAP）连接功能，包括创建SSAP客户端与服务端、连接与断开、服务发现、属性读写与通知、MTU协商等。

**模型约束：** 此接口仅可在Stage模型下使用。

## 导入模块

```typescript
import { ssap } from '@kit.ConnectivityKit';
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


## ssap.createClient

createClient(address: string): Client

创建SSAP客户端实例。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.ACCESS_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| address | string | 是 | 远端服务端设备地址。地址格式参考：11:22:33:AA:BB:FF。 |

**返回值：** 

| 类型 | 说明 |
| -------- | -------- |
| [Client](#client) | SSAP客户端实例。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[NearLink错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 801 | Capability not supported because the chip does not support it. |
| 36100003 | NearLink disabled. |
| 36100041 | Invalid address. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // 扫描获取到的远端设备地址
let client: ssap.Client;
try {
  client = ssap.createClient(addr);
  console.info('client: ' + JSON.stringify(client));
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## ssap.createServer

createServer(): Server

创建SSAP服务端实例。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.ACCESS_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**返回值：** 

| 类型 | 说明 |
| -------- | -------- |
| [Server](#server) | SSAP服务端实例。 |

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
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let server: ssap.Server;
try {
  server = ssap.createServer();
  console.info('server: ' + JSON.stringify(server));
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## Client

SSAP客户端类，提供了和服务端进行连接和数据传输等操作方法。

- 使用该类的方法前，需通过[ssap.createClient](#ssapcreateclient)方法构造该类的实例。

同一应用针对同一远端设备创建一个 [Client](#client) 实例即可，重复创建会增加不必要的资源开销。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base



### connect

connect(): Promise&lt;void&gt;

向服务端发起连接。使用Promise异步回调。

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
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // 扫描获取到的远端设备地址
let client: ssap.Client;
try {
  client = ssap.createClient(addr); // 同一应用针对同一远端设备只需创建一个实例
  client.connect().then(() => {
    console.info('connect success');
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### disconnect

disconnect(): Promise&lt;void&gt;

向服务端发起断连，断开已有连接或者终止正在建立的连接。使用Promise异步回调。

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
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // 扫描获取到的远端设备地址
let client: ssap.Client;
try {
  client = ssap.createClient(addr); // 同一应用针对同一远端设备只需创建一个实例
  client.connect().then(() => {
    console.info('connect success'); // 建立连接
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
  client.disconnect().then(() => {
    console.info('disconnect success'); // 断开连接
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### close

close(): void

关闭客户端，断开与远端服务端的连接。如仅需断开当前连接而保留实例，请使用[disconnect](#disconnect)方法。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.ACCESS_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[NearLink错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // 扫描获取到的远端设备地址
let client: ssap.Client;
try { 
  client = ssap.createClient(addr); // 同一应用针对同一远端设备只需创建一个实例
  client.close();
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### getServices

getServices(): Promise&lt;Service[]&gt;

获取服务端支持的服务列表。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.ACCESS_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**返回值：** 

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[Service](#service)[]&gt; | Promise对象，返回服务端支持的服务列表。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[NearLink错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // 扫描获取到的远端设备地址
let client: ssap.Client;
try {
  client = ssap.createClient(addr); // 同一应用针对同一远端设备只需创建一个实例
  client.connect().then(() => {
    console.info('connect success');
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
  // 连接耗时较长，等待连接完成才能获取服务，实际开发者根据连接速度调整定时器长度
  setTimeout(() => {
    client.getServices().then((result: ssap.Service[]) => {
      console.info('getServices successfully:' + JSON.stringify(result));
    }).catch((err: BusinessError) => {
      console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
    });
  }, 3000);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### readProperty

readProperty(property: Property): Promise&lt;Property&gt;

读取服务端属性。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.ACCESS_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| property | [Property](#property) | 是 | 服务端属性。 |

**返回值：** 

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[Property](#property)&gt; | Promise对象，返回服务端属性。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[NearLink错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 36100003 | NearLink disabled. |
| 36100043 | Invalid UUID in property. |
| 36100044 | NearLink standard UUID not allowed. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // 扫描获取到的远端设备地址
let client: ssap.Client;
try {
  client = ssap.createClient(addr); // 同一应用针对同一远端设备只需创建一个实例
  client.connect().then(() => {
    console.info('connect success');
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
  // 创建property，实际开发时需要通过getServices接口从服务端获取
  let valueBuffer = new ArrayBuffer(8);
  let propertyValue = new Uint8Array(valueBuffer);
  propertyValue[0] = 1;
  let property: ssap.Property = {
    serviceUuid:'FFFFFFFF-1234-5678-ABCD-000000004386',
    propertyUuid: 'FFFFFFFF-1234-5678-ABCD-000000001234',
    value: valueBuffer
  };
  // 连接耗时较长，等待连接完成才能获取服务，实际开发者根据连接速度调整定时器长度
  setTimeout(() => {
    client.readProperty(property).then((result: ssap.Property) => {
      console.info('readProperty successfully:' + JSON.stringify(result));
    }).catch((err: BusinessError) => {
      console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
    });
  }, 3000);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### writeProperty

writeProperty(property: Property, writeType: PropertyWriteType): Promise&lt;void&gt;

写入服务端属性值。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.ACCESS_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| property | [Property](#property) | 是 | 服务端属性。 |
| writeType | [PropertyWriteType](#propertywritetype) | 是 | 写类型，支持服务端回复响应和不回复响应两种方式。 |

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
| 36100043 | Invalid UUID in property. |
| 36100044 | NearLink standard UUID not allowed. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // 扫描获取到的远端设备地址
let client: ssap.Client;
try {
  client = ssap.createClient(addr); // 同一应用针对同一远端设备只需创建一个实例
  client.connect().then(() => {
    console.info('connect success');
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
  // 创建property,实际开发时需要通过getServices接口从服务端获取
  let valueBuffer = new ArrayBuffer(8);
  // 期望写入的property值
  let propertyValue = new Uint8Array(valueBuffer);
  propertyValue[0] = 1;
  let property: ssap.Property = {
    serviceUuid:'FFFFFFFF-1234-5678-ABCD-000000004386',
    propertyUuid: 'FFFFFFFF-1234-5678-ABCD-000000001234',
    value: valueBuffer
  };
  // 连接耗时较长，等待连接完成才能获取服务，实际开发者根据连接速度调整定时器长度
  setTimeout(() => {
    client.writeProperty(property, ssap.PropertyWriteType.WRITE_NO_RESPONSE).then(() => {
      console.info('writeProperty success');
    }).catch((err: BusinessError) => {
      console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
    });
  }, 3000);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### setPropertyNotification

setPropertyNotification(property: Property, enable: boolean): Promise&lt;void&gt;

设置[Property](#property)变化通知。需在调用[connect](#connect)成功建立连接后使用。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.ACCESS_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| property | [Property](#property) | 是 | 服务端属性。该属性需支持NOTIFY操作（即operation包含NOTIFY，详见Operation）。 |
| enable | boolean | 是 | 是否打开通知功能。true: 打开通知功能。false: 关闭通知功能。 |

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
| 36100043 | Invalid UUID in property. |
| 36100044 | NearLink standard UUID not allowed. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // 扫描获取到的远端设备地址
let client: ssap.Client;
try {
  client = ssap.createClient(addr); // 同一应用针对同一远端设备只需创建一个实例
  client.connect().then(() => {
    console.info('connect success');
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
  // 创建property，实际开发时需要通过getServices接口从服务端获取
  let valueBuffer = new ArrayBuffer(8);
  let propertyValue = new Uint8Array(valueBuffer);
  propertyValue[0] = 1;
  let property: ssap.Property = {
    serviceUuid:'FFFFFFFF-1234-5678-ABCD-000000004386',
    propertyUuid: 'FFFFFFFF-1234-5678-ABCD-000000001234',
    value: valueBuffer
  };
  // 连接耗时较长，等待连接完成才能获取服务，实际开发者根据连接速度调整定时器长度
  setTimeout(() => {
    client.setPropertyNotification(property, true).then(() => {
      console.info('setPropertyNotification success');
    }).catch((err: BusinessError) => {
      console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
    });
  }, 3000);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### requestMtuSize

requestMtuSize(mtu: number): Promise&lt;void&gt;

发起MTU协商请求。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.ACCESS_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| mtu | number | 是 | MTU参数，取值范围[22, 1024]，单位：字节。默认值251。 |

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
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // 扫描获取到的远端设备地址
let client: ssap.Client;
try {
  client = ssap.createClient(addr); // 同一应用针对同一远端设备只需创建一个实例
  client.connect().then(() => {
    console.info('connect success');
  });
  // 连接耗时较长，等待连接完成才能获取服务，实际开发者根据连接速度调整定时器长度
  setTimeout(() => {
    client.requestMtuSize(128).then(() => {
      console.info('requestMtuSize success');
    }).catch((err: BusinessError) => {
      console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
    });
  }, 3000);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### onPropertyChange

onPropertyChange(callback: Callback&lt;Property&gt;): void

订阅属性变化事件。使用callback异步回调。

应用需具备ohos.permission.ACCESS_NEARLINK权限，方可接收此事件上报。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[Property](#property)&gt; | 是 | 回调函数，返回服务的Property。 |

**示例：** 
```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let onPropertyChange:(data: ssap.Property) => void = (data: ssap.Property) => {
  console.info('data:' + JSON.stringify(data));
};
let addr: string = '00:11:22:33:AA:FF'; // 扫描获取到的远端设备地址
let client: ssap.Client;
try {
  client = ssap.createClient(addr); // 同一应用针对同一远端设备只需创建一个实例
  client.onPropertyChange(onPropertyChange);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### offPropertyChange

offPropertyChange(callback?: Callback&lt;Property&gt;): void

取消订阅属性变化事件。使用callback异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[Property](#property)&gt; | 否 | 回调函数，返回服务的Property。<br>填写该参数则取消当前callback订阅。不填写该参数则取消该事件对应的所有回调。 |

**示例：** 
```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let onPropertyChange:(data: ssap.Property) => void = (data: ssap.Property) => {
  console.info('data:' + JSON.stringify(data));
};
let addr: string = '00:11:22:33:AA:FF'; // 扫描获取到的远端设备地址
let client: ssap.Client;
try {
  client = ssap.createClient(addr); // 同一应用针对同一远端设备只需创建一个实例
  client.offPropertyChange(onPropertyChange);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### onConnectionStateChange

onConnectionStateChange(callback: Callback&lt;ConnectionChangeState&gt;): void

订阅连接状态变化事件。使用callback异步回调。

应用需具备ohos.permission.ACCESS_NEARLINK权限，方可接收此事件上报。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[ConnectionChangeState](#connectionchangestate)&gt; | 是 | 回调函数，返回连接状态上报参数。 |

**示例：** 
```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let onConnectionStateChange:(data: ssap.ConnectionChangeState) => void = (data: ssap.ConnectionChangeState) => {
  console.info('data:' + JSON.stringify(data));
};
let addr: string = '00:11:22:33:AA:FF'; // 扫描获取到的远端设备地址
let client: ssap.Client;
try {
  client = ssap.createClient(addr); // 同一应用针对同一远端设备只需创建一个实例
  client.onConnectionStateChange(onConnectionStateChange);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### offConnectionStateChange

offConnectionStateChange(callback?: Callback&lt;ConnectionChangeState&gt;): void

取消订阅连接状态变化事件。使用callback异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[ConnectionChangeState](#connectionchangestate)&gt; | 否 | 回调函数，返回连接状态上报参数。<br>填写该参数则取消当前callback订阅。不填写该参数则取消该事件对应的所有回调。 |

**示例：** 
```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let onConnectionStateChange:(data: ssap.ConnectionChangeState) => void = (data: ssap.ConnectionChangeState) => {
  console.info('data:' + JSON.stringify(data));
};
let addr: string = '00:11:22:33:AA:FF'; // 扫描获取到的远端设备地址
let client: ssap.Client;
try {
  client = ssap.createClient(addr); // 同一应用针对同一远端设备只需创建一个实例
  client.offConnectionStateChange(onConnectionStateChange);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### onMtuChange

onMtuChange(callback: Callback&lt;number&gt;): void

订阅MTU变化事件。使用callback异步回调。

应用需具备ohos.permission.ACCESS_NEARLINK权限，方可接收此事件上报。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;number&gt; | 是 | 回调函数，返回协商后的MTU大小。 |

**示例：** 
```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let onMtuChange:(data: number) => void = (data: number) => {
  console.info('data:' + data);
};
let addr: string = '00:11:22:33:AA:FF'; // 扫描获取到的远端设备地址
let client: ssap.Client;
try {
  client = ssap.createClient(addr); // 同一应用针对同一远端设备只需创建一个实例
  client.onMtuChange(onMtuChange);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### offMtuChange

offMtuChange(callback?: Callback&lt;number&gt;): void

取消订阅MTU变化事件。使用callback异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;number&gt; | 否 | 回调函数，返回协商后的MTU大小。<br>填写该参数则取消当前callback订阅。不填写该参数则取消该事件对应的所有回调。 |

**示例：** 
```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let onMtuChange:(data: number) => void = (data: number) => {
  console.info('data:' + data);
};
let addr: string = '00:11:22:33:AA:FF'; // 扫描获取到的远端设备地址
let client: ssap.Client;
try {
  client = ssap.createClient(addr); // 同一应用针对同一远端设备只需创建一个实例
  client.offMtuChange(onMtuChange);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## Server

SSAP服务端类，提供了和客户端进行连接和数据交互等操作方法。

- 使用该类的方法前，需通过[ssap.createServer](#ssapcreateserver)方法构造该类的实例。

同一应用创建一个 [Server](#server) 实例即可，重复创建会增加不必要的资源开销。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base



### addService

addService(service: Service): void

服务端添加服务。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.ACCESS_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| service | [Service](#service) | 是 | 服务端提供的服务信息，支持添加多个服务，根据不同的UUID区分。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[NearLink错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 36100003 | NearLink disabled. |
| 36100043 | Invalid UUID. |
| 36100044 | NearLink standard UUID not allowed. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 构造descriptor
let descriptorsArray: ssap.PropertyDescriptor[] = [];
let arrayBuffer = new ArrayBuffer(8);
let descValue = new Uint8Array(arrayBuffer);
descValue[0] = 11;
descValue[1] = 22;
let descriptor: ssap.PropertyDescriptor = {
  serviceUuid:'FFFFFFFF-1234-5678-ABCD-000000004386',
  propertyUuid: 'FFFFFFFF-1234-5678-ABCD-000000001234',
  value: arrayBuffer,
  descriptorType: ssap.PropertyDescriptorType.PROPERTY,
  isWriteable: true
};
descriptorsArray[0] = descriptor;
// 构造properties
let propertiesArray: ssap.Property[] = [];
let arrayBufferProperty = new ArrayBuffer(8);
let propertyValue = new Uint8Array(arrayBufferProperty);
propertyValue[0] = 1;
let property1: ssap.Property = {
  serviceUuid:'FFFFFFFF-1234-5678-ABCD-000000004386',
  propertyUuid: 'FFFFFFFF-1234-5678-ABCD-000000001234',
  value: arrayBufferProperty,
  descriptors:descriptorsArray
};
let property2: ssap.Property = {
  serviceUuid:'FFFFFFFF-1234-5678-ABCD-000000004386',
  propertyUuid: 'FFFFFFFF-1234-5678-ABCD-000000003421',
  value: arrayBufferProperty,
  descriptors:descriptorsArray,
  operation:12
};
propertiesArray[0] = property1;
propertiesArray[1] = property2;
// 构造服务
let service: ssap.Service = {
  serviceUuid:'FFFFFFFF-1234-5678-ABCD-000000004386',
  properties:propertiesArray
};
let server: ssap.Server;
try {
  server = ssap.createServer();
  server.addService(service);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### removeService

removeService(serviceUuid: string): void

服务端删除服务。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.ACCESS_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| serviceUuid | string | 是 | 星闪服务UUID，长度必须为36个字符，由32个十六进制数字和4个连字符（-）组成，例如： FFFFFFFF-1234-5678-ABCD-000000001234，表示一个128位标识符。 不允许使用星闪标准UUID。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[NearLink错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 36100003 | NearLink disabled. |
| 36100043 | Invalid UUID. |
| 36100044 | NearLink standard UUID not allowed. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let server: ssap.Server;
try {
  server = ssap.createServer();
  // 服务已通过addService添加，可以通过指定UUID进行删除
  let serviceUuid = 'FFFFFFFF-1234-5678-ABCD-000000004386';
  server.removeService(serviceUuid);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### close

close(): void

关闭服务端，并注销已注册的回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.ACCESS_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[NearLink错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let server: ssap.Server;
try {
  server = ssap.createServer();
  server.close();
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### notifyPropertyChanged

notifyPropertyChanged(address: string, property: Property): Promise&lt;void&gt;

通知客户端属性值更新。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.ACCESS_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| address | string | 是 | 客户端设备地址。地址格式参考：11:22:33:AA:BB:FF。 |
| property | [Property](#property) | 是 | 发生值变化的Property。 |

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
| 36100041 | Invalid address. |
| 36100043 | Invalid UUID in property. |
| 36100044 | NearLink standard UUID not allowed. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 构造descriptor
let descriptorsArray: ssap.PropertyDescriptor[] = [];
let arrayBuffer = new ArrayBuffer(8);
let descValue = new Uint8Array(arrayBuffer);
descValue[0] = 11;
descValue[1] = 22;
let descriptor: ssap.PropertyDescriptor = {
  serviceUuid:'FFFFFFFF-1234-5678-ABCD-000000004386',
  propertyUuid: 'FFFFFFFF-1234-5678-ABCD-000000001234',
  value: arrayBuffer,
  descriptorType:ssap.PropertyDescriptorType.PROPERTY,
  isWriteable:true
};
descriptorsArray[0] = descriptor;
// 构造properties
let arrayBufferProperty = new ArrayBuffer(8);
let propertyValue = new Uint8Array(arrayBufferProperty);
propertyValue[0] = 123; // 本次更新后的值
let property: ssap.Property = {
  serviceUuid:'FFFFFFFF-1234-5678-ABCD-000000004386',
  propertyUuid: 'FFFFFFFF-1234-5678-ABCD-000000001234',
  value: arrayBufferProperty,
  descriptors:descriptorsArray
};
let server: ssap.Server;
try {
  server = ssap.createServer();
  // 地址是服务端缓存的已连接的客户端设备
  server.notifyPropertyChanged('00:11:22:33:AA:FF', property).then(() => {
    console.info('notifyPropertyChanged success');
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### sendResponse

sendResponse(response: ServerResponse): void

回复客户端读写请求。收到[ssap.onPropertyRead](#onpropertyread)或[ssap.onPropertyWrite](#onpropertywrite)上报的请求后，调用本接口向对应客户端回复数据。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.ACCESS_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| response | [ServerResponse](#serverresponse) | 是 | 回复客户端的响应数据。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[NearLink错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 36100003 | NearLink disabled. |
| 36100041 | Invalid address. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 订阅客户端的读写请求，收到请求后通过该接口回复
let arrayBuffer = new ArrayBuffer(8);
let descValue = new Uint8Array(arrayBuffer);
descValue[0] = 11;
descValue[1] = 22;
let resp: ssap.ServerResponse = {
  address: '00:11:22:33:AA:FF', // 请求方的客户端地址
  requestId: 1, // 请求方传入
  value: arrayBuffer // 回复的数据
};
let server: ssap.Server;
try {
  server = ssap.createServer();
  // 地址是服务端缓存的已连接的客户端设备
  server.sendResponse(resp);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### onConnectionStateChange

onConnectionStateChange(callback: Callback&lt;ConnectionChangeState&gt;): void

订阅连接状态变化事件。使用callback异步回调。

应用需具备ohos.permission.ACCESS_NEARLINK权限，方可接收此事件上报。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[ConnectionChangeState](#connectionchangestate)&gt; | 是 | 回调函数，返回连接状态上报参数。 |

**示例：** 
```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let onConnectionStateChange:(data: ssap.ConnectionChangeState) => void = (data: ssap.ConnectionChangeState) => {
  console.info('data:' + JSON.stringify(data));
};
let server: ssap.Server;
try {
  server = ssap.createServer();
  server.onConnectionStateChange(onConnectionStateChange);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### offConnectionStateChange

offConnectionStateChange(callback?: Callback&lt;ConnectionChangeState&gt;): void

取消订阅连接状态变化事件。使用callback异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[ConnectionChangeState](#connectionchangestate)&gt; | 否 | 回调函数，返回连接状态上报参数。<br>填写该参数则取消当前callback订阅。不填写该参数则取消该事件对应的所有回调。 |

**示例：** 
```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let onConnectionStateChange:(data: ssap.ConnectionChangeState) => void = (data: ssap.ConnectionChangeState) => {
  console.info('data:' + JSON.stringify(data));
};
let server: ssap.Server;
try {
  server = ssap.createServer();
  server.offConnectionStateChange(onConnectionStateChange);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### onPropertyRead

onPropertyRead(callback: Callback&lt;PropertyReadRequest&gt;): void

订阅客户端的读属性请求事件。使用callback异步回调。

应用需具备ohos.permission.ACCESS_NEARLINK权限，方可接收此事件上报。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[PropertyReadRequest](#propertyreadrequest)&gt; | 是 | 回调函数，返回客户端的Property读请求参数。 |

**示例：** 
```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let onPropertyReadRequest:(data: ssap.PropertyReadRequest) => void = (data: ssap.PropertyReadRequest) => {
  console.info('data:' + JSON.stringify(data));
};
let server: ssap.Server;
try {
  server = ssap.createServer();
  server.onPropertyRead(onPropertyReadRequest);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### offPropertyRead

offPropertyRead(callback?: Callback&lt;PropertyReadRequest&gt;): void

取消订阅客户端的读属性请求事件。使用callback异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[PropertyReadRequest](#propertyreadrequest)&gt; | 否 | 回调函数，返回客户端的Property读请求参数。<br>填写该参数则取消当前callback订阅。不填写该参数则取消该事件对应的所有回调。 |

**示例：** 
```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let onPropertyReadRequest:(data: ssap.PropertyReadRequest) => void = (data: ssap.PropertyReadRequest) => {
  console.info('data:' + JSON.stringify(data));
};
let server: ssap.Server;
try {
  server = ssap.createServer();
  server.offPropertyRead(onPropertyReadRequest);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### onPropertyWrite

onPropertyWrite(callback: Callback&lt;PropertyWriteRequest&gt;): void

订阅客户端的写属性请求事件。使用callback异步回调。

应用需具备ohos.permission.ACCESS_NEARLINK权限，方可接收此事件上报。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[PropertyWriteRequest](#propertywriterequest)&gt; | 是 | 回调函数，返回客户端的Property写请求参数。 |

**示例：** 
```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let onPropertyWriteRequest:(data: ssap.PropertyWriteRequest) => void = (data: ssap.PropertyWriteRequest) => {
  console.info('data:' + JSON.stringify(data));
};
let server: ssap.Server;
try {
  server = ssap.createServer();
  server.onPropertyWrite(onPropertyWriteRequest);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### offPropertyWrite

offPropertyWrite(callback?: Callback&lt;PropertyWriteRequest&gt;): void

取消订阅客户端的写属性请求事件。使用callback异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[PropertyWriteRequest](#propertywriterequest)&gt; | 否 | 回调函数，返回客户端的Property写请求参数。<br>填写该参数则取消当前callback订阅。不填写该参数则取消该事件对应的所有回调。 |

**示例：** 
```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let onPropertyWriteRequest:(data: ssap.PropertyWriteRequest) => void = (data: ssap.PropertyWriteRequest) => {
  console.info('data:' + JSON.stringify(data));
};
let server: ssap.Server;
try {
  server = ssap.createServer();
  server.offPropertyWrite(onPropertyWriteRequest);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### onMtuChange

onMtuChange(callback: Callback&lt;number&gt;): void

订阅MTU（Maximum Transmission Unit）变化事件。使用callback异步回调。

应用需具备ohos.permission.ACCESS_NEARLINK权限，方可接收此事件上报。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;number&gt; | 是 | 回调函数，返回协商后的MTU大小。 |

**示例：** 
```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let onMtuChange:(data: number) => void = (data: number) => {
  console.info('data:' + data);
};
let server: ssap.Server;
try {
  server = ssap.createServer();
  server.onMtuChange(onMtuChange);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### offMtuChange

offMtuChange(callback?: Callback&lt;number&gt;): void

取消订阅MTU变化事件。使用callback异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;number&gt; | 否 | 回调函数，返回协商后的MTU大小。<br>填写该参数则取消当前callback订阅。不填写该参数则取消该事件对应的所有回调。 |

**示例：** 
```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let onMtuChange:(data: number) => void = (data: number) => {
  console.info('data:' + data);
};
let server: ssap.Server;
try {
  server = ssap.createServer();
  server.offMtuChange(onMtuChange);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## Service

表示星闪服务。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| serviceUuid | string | 否 | 否 | 星闪服务UUID，长度必须为36个字符，由32个十六进制数字和4个连字符（-）组成，例如： FFFFFFFF-1234-5678-ABCD-000000001234，表示一个128位标识符。 不允许使用星闪标准UUID。 |
| properties | [Property](#property)[] | 否 | 否 | 表示服务的Property列表。 |


## Property

表示服务的Property。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| serviceUuid | string | 否 | 否 | 星闪服务UUID，长度必须为36个字符，由32个十六进制数字和4个连字符（-）组成，例如： FFFFFFFF-1234-5678-ABCD-000000001234，表示一个128位标识符。 不允许使用星闪标准UUID。|
| propertyUuid | string | 否 | 否 | 表示Property的UUID，数据格式同serviceUuid。 |
| value | ArrayBuffer | 否 | 否 | 表示Property的数据值。 |
| descriptors | [PropertyDescriptor](#propertydescriptor)[] | 否 | 是 | 表示当前Property的描述符列表。若未配置则默认不携带该字段。 |
| operation | number | 否 | 是 | 表示Property支持的操作方式，默认值为READABLE\|WRITE_NO_RESPONSE，即可读并可写（以无响应方式）。如要使属性支持相应的操作，需要对该字段赋值，例如赋值为：READABLE \| WRITE_NO_RESPONSE \| NOTIFY。取值范围[0, 15]，各比特位对应的操作方式详见[Operation](#operation)。 |


## PropertyDescriptor

表示Property的描述符。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| serviceUuid | string | 否 | 否 | 星闪服务UUID，长度必须为36个字符，由32个十六进制数字和4个连字符（-）组成，例如： FFFFFFFF-1234-5678-ABCD-000000001234，表示一个128位标识符。 不允许使用星闪标准UUID。 |
| propertyUuid | string | 否 | 否 | 表示Property的UUID，数据格式同serviceUuid。 |
| value | ArrayBuffer | 否 | 否 | 表示描述符的数据值。 |
| descriptorType | [PropertyDescriptorType](#propertydescriptortype) | 否 | 否 | 表示Property的描述符类型。 |
| isWriteable | boolean | 否 | 是 | 表示描述符是否是可写的。true：可写，false：不可写。默认值为true。 |


## PropertyReadRequest

表示客户端的Property读请求参数。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| address | string | 否 | 否 | 表示客户端设备地址。地址格式参考：11:22:33:AA:BB:FF。 |
| serviceUuid | string | 否 | 否 | 星闪服务UUID，长度必须为36个字符，由32个十六进制数字和4个连字符（-）组成，例如： FFFFFFFF-1234-5678-ABCD-000000001234，表示一个128位标识符。 不允许使用星闪标准UUID。 |
| propertyUuid | string | 否 | 否 | 表示Property的UUID，数据格式同serviceUuid。 |
| requestId | number | 否 | 否 | 表示请求ID。取值范围[0, 65535]。服务端回复响应时需携带该ID，以便客户端关联请求与响应。 |


## PropertyWriteRequest

表示客户端的Property写请求参数。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| address | string | 否 | 否 | 表示客户端设备地址。地址格式参考：11:22:33:AA:BB:FF。 |
| serviceUuid | string | 否 | 否 | 星闪服务UUID，长度必须为36个字符，由32个十六进制数字和4个连字符（-）组成，例如： FFFFFFFF-1234-5678-ABCD-000000001234，表示一个128位标识符。 不允许使用星闪标准UUID。 |
| propertyUuid | string | 否 | 否 | 表示Property的UUID，数据格式同serviceUuid。 |
| value | ArrayBuffer | 否 | 否 | 表示客户端写入的值。 |
| requestId | number | 否 | 否 | 表示客户端的写请求ID，服务端回复响应时需携带该ID。取值范围[0, 65535]。 |
| writeType | [PropertyWriteType](#propertywritetype) | 否 | 否 | 表示客户端写Property类型。 |


## ServerResponse

表示回复客户端请求的响应。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| address | string | 否 | 否 | 表示客户端设备地址。地址格式参考：11:22:33:AA:BB:FF。 |
| requestId | number | 否 | 否 | 表示请求ID。取值范围[0, 65535]。该ID必须与收到的[PropertyReadRequest](#propertyreadrequest)或[PropertyWriteRequest](#propertywriterequest)中的requestId一致，用于关联请求与响应。 |
| value | ArrayBuffer | 否 | 否 | 表示回复的数据值。 |


## ConnectionChangeState

表示连接状态上报参数。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| address | string | 否 | 否 | 表示远端设备地址。地址格式参考：11:22:33:AA:BB:FF。 |
| state | [ConnectionState](js-apis-nearlink-constant.md#connectionstate) | 否 | 否 | 表示和远端设备的连接状态。 |


## PropertyDescriptorType

表示Property的描述符类型，为枚举值。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| PROPERTY | 1 | 表示Property。 |
| CLIENT_PROPERTY_CONFIG | 2 | 表示客户端Property配置。 |
| SERVER_PROPERTY_CONFIG | 3 | 表示服务端Property配置。 |
| PROPERTY_FORMAT | 4 | 表示Property格式。 |
| TYPE_VENDOR | 255 | 表示厂商自定义字段。 |


## Operation

表示Property支持的操作类型，为枚举值。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| READABLE | 0x01 | 表示可读。 |
| WRITE_NO_RESPONSE | 0x02 | 表示支持无响应的写请求。 |
| WRITE_WITH_RESPONSE | 0x04 | 表示支持有响应的写请求。 |
| NOTIFY | 0x08 | 表示支持通知。 |


## PropertyWriteType

表示Property支持的写类型，为枚举值。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| WRITE | 1 | 表示写属性请求并等待服务端响应回复。 |
| WRITE_NO_RESPONSE | 2 | 表示写属性请求，无需服务端响应回复。 |
