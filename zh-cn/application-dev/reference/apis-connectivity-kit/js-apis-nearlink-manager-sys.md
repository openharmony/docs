# @ohos.nearlink.manager (星闪基础管理能力)(系统接口)
<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @CCCZKing-->
<!--Designer: @lilong32; @CCCZKing-->
<!--Tester: @zhangjiaji111-->
<!--Adviser: @zhang_yixin13-->


本模块提供了星闪基础管理能力，包括打开/关闭星闪、获取本机MAC地址、设置连接模式等能力。


**起始版本：** 26.0.0

> **说明：**
>
> 本模块接口为系统接口。


## 导入模块

```typescript
import { manager } from '@kit.ConnectivityKit';
```


## manager.enable

enable(): void

打开星闪。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：**  此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_NEARLINK and ohos.permission.MANAGE_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[星闪错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications are not allowed to use system APIs. |
| 203 | EDM denied. |
| 801 | Capability not supported because the chip does not support it. |
| 36100099 | Operation failed. |

**示例：**
```typescript
import { manager } from '@kit.ConnectivityKit';
import { BusinessError } from '@ohos.base';

try {
  manager.enable();
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## manager.disable

disable(): void

关闭星闪。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：**  此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_NEARLINK and ohos.permission.MANAGE_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[星闪错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications are not allowed to use system APIs. |
| 801 | Capability not supported because the chip does not support it. |
| 36100099 | Operation failed. |

**示例：**
```typescript
import { manager } from '@kit.ConnectivityKit';
import { BusinessError } from '@ohos.base';

try {
  manager.disable();
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## manager.getLocalAddress

getLocalAddress(): string

查询本机MAC地址。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：**  此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_NEARLINK and ohos.permission.GET_NEARLINK_LOCAL_MAC

**系统能力：** SystemCapability.Communication.NearLink.Base

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 表示本地MAC地址。例如'11:22:33:AA:BB:FF'。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[星闪错误码](errorcode-nearlink-service.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications are not allowed to use system APIs. |
| 801 | Capability not supported because the chip does not support it. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**示例：**
```typescript
import { manager } from '@kit.ConnectivityKit';
import { BusinessError } from '@ohos.base';

try {
  let addr: string = manager.getLocalAddress();
  console.info('getLocalAddress addr:' + addr);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## manager.factoryReset

factoryReset(): Promise&lt;void&gt;

恢复出厂设置。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：**  此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_NEARLINK

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
| 801 | Capability not supported because the chip does not support it. |
| 36100099 | Operation failed. |

**示例：**
```typescript
import { manager } from '@kit.ConnectivityKit';
import { BusinessError } from '@ohos.base';

try {
  manager.factoryReset().then(() => {
    console.info('factoryReset success');
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## ConnectionMode

连接模式的枚举值。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Communication.NearLink.Base

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| SLE_MODE_UNCONNECTABLE | 0 | 表示该设备不可连接。 |
| SLE_MODE_CONNECTABLE | 1 | 表示该设备可连接。 |

## manager.setConnectionMode

setConnectionMode(mode: ConnectionMode, duration: number): Promise&lt;void&gt;

设置连接模式。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：**  此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_NEARLINK and ohos.permission.MANAGE_NEARLINK

**系统能力：** SystemCapability.Communication.NearLink.Base

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| mode | [ConnectionMode](#connectionmode) | 是 | 表示要设置的连接模式。| 
| duration | number | 是 | 表示设置模式的持续时间，单位为s，取值范围为大于等于0的整数，若为0则表示无限制。|

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
| 801 | Capability not supported because the chip does not support it. |
| 36100003 | NearLink disabled. |
| 36100040 | Integer out of range. |
| 36100099 | Operation failed. |

**示例：**
```typescript
import { manager } from '@kit.ConnectivityKit';
import { BusinessError } from '@ohos.base';

try {
  let mode: manager.ConnectionMode = manager.ConnectionMode.SLE_MODE_CONNECTABLE;
  let duration: number = 100;
  manager.setConnectionMode(mode, duration).then(() => {
    console.info('setConnectionMode success');
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```
