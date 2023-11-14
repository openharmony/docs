# @ohos.bluetooth.baseProfile (蓝牙baseProfile模块)

baseProfile模块提供了基础的profile方法。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。



## 导入模块

```js
import baseProfile from '@ohos.bluetooth.baseProfile';
```


## ConnectionStrategy<a name="ConnectionStrategy"></a>

枚举，表示Profile的连接策略。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称                             | 值      | 说明            |
| -------------------------------- | ------ | --------------- |
| CONNECTION_STRATEGY_UNSUPPORTED   | 0 | 当设备未配对时的默认连接策略。<br/>此接口为系统接口。 |
| CONNECTION_STRATEGY_ALLOWED  | 1 |  设备允许接受或发起配对时的连接策略。<br/>此接口为系统接口。 |
| CONNECTION_STRATEGY_FORBIDDEN  | 2 | 设备不允许接受或发起配对时的连接策略。<br/>此接口为系统接口。  |


## StateChangeParam<a name="StateChangeParam"></a>

描述profile状态改变参数。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称     | 类型                           | 可读 | 可写 | 说明                            |
| -------- | ----------------------------- | ---- | ---- | ------------------------------- |
| deviceId | string                        | 是   | 否   | 表示蓝牙设备地址。   |
| state    | ProfileConnectionState        | 是   | 否   | 表示蓝牙设备的profile连接状态。 |


## baseProfile.setConnectionStrategy<a name="setConnectionStrategy"></a>

setConnectionStrategy(deviceId: string, strategy: ConnectionStrategy, callback: AsyncCallback&lt;void&gt;): void

设置该设备Profile的连接策略。

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

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](../errorcodes/errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900004 | Profile is not supported.                |
|2900099 | Operation failed.                        |

**示例：**

```js
import { BusinessError } from '@ohos.base';
import a2dp from '@ohos.bluetooth.a2dp';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    a2dpSrc.setConnectionStrategy('XX:XX:XX:XX:XX:XX', 0, (err: BusinessError) => {
        console.info('setConnectionStrategy, err: ' + JSON.stringify(err));
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## baseProfile.setConnectionStrategy<a name="setConnectionStrategy"></a>

setConnectionStrategy(deviceId: string, strategy: ConnectionStrategy): Promise&lt;void&gt;

设置该设备Profile的连接策略。

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

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](../errorcodes/errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900004 | Profile is not supported.                |
|2900099 | Operation failed.                        |

**示例：**

```js
import { BusinessError } from '@ohos.base';
import a2dp from '@ohos.bluetooth.a2dp';
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

## baseProfile.getConnectionStrategy<a name="getConnectionStrategy"></a>

getConnectionStrategy(deviceId: string, callback: AsyncCallback&lt;ConnectionStrategy&gt;): void

获取该Profile的连接策略。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型     | 必填   | 说明                                  |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | 是    | 表示配对的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |
| callback | AsyncCallback&lt;[ConnectionStrategy](#connectionstrategy)&gt; | 是    | 回调函数。当获取策略成功，err为undefined，否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](../errorcodes/errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900004 | Profile is not supported.                |
|2900099 | Operation failed.                        |

**示例：**

```js
import { BusinessError } from '@ohos.base';
import a2dp from '@ohos.bluetooth.a2dp';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    a2dpSrc.getConnectionStrategy('XX:XX:XX:XX:XX:XX', 0, (err: BusinessError, data: baseProfile.ConnectionStrategy) => {
        console.info('getConnectionStrategy, err: ' + JSON.stringify(err) + ', data: ' + JSON.stringify(data));
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## baseProfile.getConnectionStrategy<a name="getConnectionStrategy"></a>

getConnectionStrategy(deviceId: string): Promise&lt;ConnectionStrategy&gt;

获取该Profile的连接策略。

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
|   Promise&lt;[ConnectionStrategy](#connectionstrategy)&gt; | 返回promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](../errorcodes/errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900004 | Profile is not supported.                |
|2900099 | Operation failed.                        |

**示例：**

```js
import { BusinessError } from '@ohos.base';
import a2dp from '@ohos.bluetooth.a2dp';
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


## baseProfile.getConnectedDevices<a name="getConnectedDevices"></a>

getConnectedDevices(): Array&lt;string&gt;

获取已连接设备列表。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**返回值：**

| 类型                  | 说明                  |
| ------------------- | ------------------- |
| Array&lt;string&gt; | 返回当前已连接设备的地址。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](../errorcodes/errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900004 | Profile is not supported.                |
|2900099 | Operation failed.                        |

**示例：**

```js
import { BusinessError } from '@ohos.base';
import a2dp from '@ohos.bluetooth.a2dp';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    let retArray = a2dpSrc.getConnectedDevices();
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## baseProfile.getConnectionState<a name="getConnectionState"></a>

getConnectionState(deviceId: string): ProfileConnectionState

获取设备profile的连接状态。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 远端设备地址。 |

**返回值：**

| 类型                                              | 说明                    |
| ------------------------------------------------- | ----------------------- |
| [ProfileConnectionState](js-apis-bluetooth-constant.md#profileconnectionstate) | 返回profile的连接状态。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](../errorcodes/errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900004 | Profile is not supported.                |
|2900099 | Operation failed.                        |

**示例：**

```js
import { BusinessError } from '@ohos.base';
import a2dp from '@ohos.bluetooth.a2dp';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    let ret = a2dpSrc.getConnectionState('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## baseProfile.on('connectionStateChange')

on(type: 'connectionStateChange', callback: Callback&lt;StateChangeParam&gt;): void

订阅连接状态变化事件。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 填写"connectionStateChange"字符串，表示连接状态变化事件。 |
| callback | Callback&lt;[StateChangeParam](#statechangeparam)&gt; | 是    | 表示回调函数的入参。                               |

**示例：**

```js
import { BusinessError } from '@ohos.base';
import a2dp from '@ohos.bluetooth.a2dp';
function onReceiveEvent(data: baseProfile.StateChangeParam) {
    console.info('a2dp state = '+ JSON.stringify(data));
}
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    a2dpSrc.on('connectionStateChange', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## baseProfile.off('connectionStateChange')

off(type: 'connectionStateChange', callback?: Callback&lt;[StateChangeParam](#StateChangeParam)&gt;): void

取消订阅连接状态变化事件。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 填写"connectionStateChange"字符串，表示连接状态变化事件。 |
| callback | Callback&lt;[StateChangeParam](#StateChangeParam)&gt; | 否    | 表示回调函数的入参。                               |

**示例：**

```js
import { BusinessError } from '@ohos.base';
import a2dp from '@ohos.bluetooth.a2dp';
function onReceiveEvent(data: baseProfile.StateChangeParam) {
    console.info('a2dp state = '+ JSON.stringify(data));
}
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    a2dpSrc.on('connectionStateChange', onReceiveEvent);
    a2dpSrc.off('connectionStateChange', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```