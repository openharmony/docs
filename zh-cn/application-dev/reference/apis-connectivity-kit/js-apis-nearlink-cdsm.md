# @ohos.nearlink.cdsm (星闪合作设备集合管理能力)
<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @CCCZKing-->
<!--Designer: @lilong32; @CCCZKing-->
<!--Tester: @zhangjiaji111-->
<!--Adviser: @zhang_yixin13-->


本模块提供了星闪合作设备集合管理（Coordinated Devices Set Management，CDSM）的能力，包括查询和订阅星闪合作设备集合信息的功能。


**起始版本：** 26.0.0


## 导入模块

```typescript
import { cdsm } from '@kit.ConnectivityKit';
```


## cdsm.createCdsmClient

createCdsmClient(address: string): CdsmClient

创建CDSM客户端实例。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.ACCESS_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| address | string | 是 | 已配对连接的合作设备集合的成员设备地址。地址格式参考：11:22:33:AA:BB:FF，需为6段、每段2位十六进制字符，各段以冒号分隔。 |

**返回值：** 

| 类型 | 说明 |
| -------- | -------- |
| [CdsmClient](#cdsmclient) | 用于查询和订阅远端设备合作设备集合信息的CDSM客户端实例。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[NearLink错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 801 | Capability not supported because the chip does not support it. |
| 36100003 | NearLink disabled. |
| 36100041 | Invalid address. |
| 36100050 | Coordinated Devices Set Management not supported. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { cdsm } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // 已配对连接的合作设备集合的成员设备地址
let client: cdsm.CdsmClient;
try {
  client = cdsm.createCdsmClient(addr);
  console.info('client: ' + JSON.stringify(client));
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## CdsmClient

CDSM客户端类，提供了获取远端设备的合作设备集合信息等操作方法。

- 使用该类的方法前，需通过[cdsm.createCdsmClient](#cdsmcreatecdsmclient)方法构造该类的实例。

适用于需要获知一组星闪设备（合作设备集合）的成员组成及连接状态变化并据此进行业务联动的场景。

同一应用针对同一远端设备创建一个 [CdsmClient](#cdsmclient) 实例即可，重复创建会增加不必要的资源开销。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base



### getCdsmInfo

getCdsmInfo(): CdsmInfo

查询远端设备的合作设备集合信息。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.ACCESS_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**返回值：** 

| 类型 | 说明 |
| -------- | -------- |
| [CdsmInfo](#cdsminfo) | 远端设备的合作设备集合信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[NearLink错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**示例：** 
```typescript
import { cdsm } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // 已配对连接的合作设备集合的成员设备地址
let client: cdsm.CdsmClient;
try {
  client = cdsm.createCdsmClient(addr); // 同一应用针对同一远端设备只需创建一个实例
  let cdsmInformation: cdsm.CdsmInfo = client.getCdsmInfo();
  console.info('cdsmInformation:' + JSON.stringify(cdsmInformation));
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### onCdsmInfoChange

onCdsmInfoChange(callback: Callback&lt;CdsmInfo&gt;): void

订阅远端设备合作设备集合信息变化事件。使用callback异步回调。

应用需具备ohos.permission.ACCESS_NEARLINK权限，方可接收此事件上报。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[CdsmInfo](#cdsminfo)&gt; | 是 | 事件回调类型，返回远端设备合作设备集合信息。 |

**示例：** 
```typescript
import { cdsm } from '@kit.ConnectivityKit';
import { BusinessError, Callback } from '@kit.BasicServicesKit';

let callback: Callback<cdsm.CdsmInfo> = (data: cdsm.CdsmInfo) => {
  console.info('CdsmInfo:' + JSON.stringify(data));
};

let addr: string = '00:11:22:33:AA:FF'; // 已配对连接的合作设备集合的成员设备地址
let client: cdsm.CdsmClient;
try {
  client = cdsm.createCdsmClient(addr); // 同一应用针对同一远端设备只需创建一个实例
  client.onCdsmInfoChange(callback);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### offCdsmInfoChange

offCdsmInfoChange(callback?: Callback&lt;CdsmInfo&gt;): void

取消订阅远端设备合作设备集合信息变化事件。使用callback异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[CdsmInfo](#cdsminfo)&gt; | 否 | 事件回调类型，返回远端设备合作设备集合信息。<br>填写该参数则取消当前callback订阅。不填写该参数则取消远端设备合作设备集合信息变化事件对应的所有回调。 |

**示例：** 
```typescript
import { cdsm } from '@kit.ConnectivityKit';
import { BusinessError, Callback } from '@kit.BasicServicesKit';

let callback: Callback<cdsm.CdsmInfo> = (data: cdsm.CdsmInfo) => {
  console.info('CdsmInfo:' + JSON.stringify(data));
};

let addr: string = '00:11:22:33:AA:FF'; // 已配对连接的合作设备集合的成员设备地址
let client: cdsm.CdsmClient;
try {
  client = cdsm.createCdsmClient(addr); // 同一应用针对同一远端设备只需创建一个实例
  client.onCdsmInfoChange(callback);
  client.offCdsmInfoChange(callback);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## CdsmInfo

表示合作设备集合信息。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| members | [CdsmMemberInfo](#cdsmmemberinfo)[] | 否 | 否 | 合作设备集合的成员信息数组，每个成员包含设备地址及其连接状态。 |


## CdsmMemberInfo

表示合作设备集合的成员信息。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| address | string | 否 | 否 | 成员设备地址。 |
| state | [CdsmConnectionState](#cdsmconnectionstate) | 否 | 否 | 成员设备连接状态。 |


## CdsmConnectionState

表示合作设备集合中成员设备的连接状态，为枚举值。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| DISCONNECTED | 0 | 表示已断连。 |
| CONNECTED | 1 | 表示已连接。 |
