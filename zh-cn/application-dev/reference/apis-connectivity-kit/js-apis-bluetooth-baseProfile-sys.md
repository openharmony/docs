# @ohos.bluetooth.baseProfile (蓝牙baseProfile模块)（系统接口）

baseProfile模块提供了基础的profile方法。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.bluetooth.baseProfile (蓝牙baseProfile模块)](js-apis-bluetooth-baseProfile.md)


## 导入模块

```js
import { baseProfile } from '@kit.ConnectivityKit';
```


## ConnectionStrategy

枚举，表示Profile的连接策略。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称                             | 值      | 说明            |
| -------------------------------- | ------ | --------------- |
| CONNECTION_STRATEGY_UNSUPPORTED   | 0 | 当设备未配对时的默认连接策略。<br/>此接口为系统接口。 |
| CONNECTION_STRATEGY_ALLOWED  | 1 |  设备允许接受或发起配对时的连接策略。<br/>此接口为系统接口。 |
| CONNECTION_STRATEGY_FORBIDDEN  | 2 | 设备不允许接受或发起配对时的连接策略。<br/>此接口为系统接口。  |



## baseProfile.setConnectionStrategy

setConnectionStrategy(deviceId: string, strategy: ConnectionStrategy, callback: AsyncCallback&lt;void&gt;): void

设置该设备Profile的连接策略。使用Callback异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型     | 必填   | 说明                                  |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | 是    | 表示配对的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |
| strategy | [ConnectionStrategy](#connectionstrategy)   | 是    |Profile的连接策略。 |
| callback | AsyncCallback&lt;void&gt;  | 是    | 回调函数。当设置成功，err为undefined，否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile not supported.                |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
import { a2dp } from '@kit.ConnectivityKit';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    a2dpSrc.setConnectionStrategy('XX:XX:XX:XX:XX:XX', 0, (err: BusinessError) => {
        console.info('setConnectionStrategy, err: ' + JSON.stringify(err));
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## baseProfile.setConnectionStrategy

setConnectionStrategy(deviceId: string, strategy: ConnectionStrategy): Promise&lt;void&gt;

设置该设备Profile的连接策略。使用Promise异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型     | 必填   | 说明                                  |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | 是    | 表示配对的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |
| strategy | [ConnectionStrategy](#connectionstrategy)   | 是    |Profile的连接策略。 |

**返回值：**

| 类型                  | 说明            |
| ------------------- | ------------- |
| Promise&lt;void&gt; | 返回promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile not supported.                |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
import { a2dp } from '@kit.ConnectivityKit';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    a2dpSrc.setConnectionStrategy('XX:XX:XX:XX:XX:XX', 1).then(() => {
        console.info('setConnectionStrategy');
    }, (err: BusinessError) => {
        console.error('setConnectionStrategy errCode: ' + err.code + ', errMessage: ' + err.message);
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## baseProfile.getConnectionStrategy

getConnectionStrategy(deviceId: string, callback: AsyncCallback&lt;ConnectionStrategy&gt;): void

获取该Profile的连接策略。使用Callback异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型     | 必填   | 说明                                  |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | 是    | 表示配对的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |
| callback | AsyncCallback&lt;[ConnectionStrategy](#connectionstrategy)&gt; | 是    | 回调函数。当获取策略成功，err为undefined，否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile not supported.                |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
import { a2dp } from '@kit.ConnectivityKit';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    a2dpSrc.getConnectionStrategy('XX:XX:XX:XX:XX:XX', 0, (err: BusinessError, data: baseProfile.ConnectionStrategy) => {
        console.info('getConnectionStrategy, err: ' + JSON.stringify(err) + ', data: ' + JSON.stringify(data));
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## baseProfile.getConnectionStrategy

getConnectionStrategy(deviceId: string): Promise&lt;ConnectionStrategy&gt;

获取该Profile的连接策略。使用Promise异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型     | 必填   | 说明                                  |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | 是    | 表示配对的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |

**返回值：**

| 类型                  | 说明            |
| ------------------- | ------------- |
|   Promise&lt;[ConnectionStrategy](js-apis-bluetooth-baseProfile-sys.md#connectionstrategy)&gt; | 返回promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|2900001 | Service stopped.                  
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |       |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile not supported.                |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
import { a2dp } from '@kit.ConnectivityKit';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    a2dpSrc.getConnectionStrategy('XX:XX:XX:XX:XX:XX', 1).then((data: baseProfile.ConnectionStrategy) => {
        console.info('getConnectionStrategy');
    }, (err: BusinessError) => {
        console.error('getConnectionStrategy errCode: ' + err.code + ', errMessage: ' + err.message);
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```