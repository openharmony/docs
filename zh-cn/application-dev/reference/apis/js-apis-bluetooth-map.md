# @ohos.bluetooth.map (蓝牙map模块)

map模块提供了访问信息相关功能的方法。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。



## 导入模块

```js
import map from '@ohos.bluetooth.map';
```


## map.createMapMseProfile<a name="createMapMseProfile"></a>

createMapMseProfile(): MapMseProfile

创建mapMse profile实例。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**返回值：**

| 类型                            | 说明         |
| ----------------------------- | ---------- |
| MapMseProfile | 返回该profile的实例。 |

**示例：**

```js
import { BusinessError } from '@ohos.base';
try {
    let mapMseProfile = map.createMapMseProfile();
    console.info('MapMse success');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## mapMseProfile

使用mapMseProfile方法之前需要创建该类的实例进行操作，通过createMapMseProfile()方法构造此实例。


### disconnect<a name="MapMseProfile-disconnect"></a>

disconnect(deviceId: string): void

断开连接设备的map服务。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 远端设备地址。 |

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
try {
    let mapMseProfile = map.createMapMseProfile();
    mapMseProfile.disconnect('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### setMessageAccessAuthorization<a name="MapMseProfile-setMessageAccessAuthorization"></a>

setMessageAccessAuthorization(deviceId: string, authorization: AccessAuthorization): Promise&lt;void&gt;

设置信息的访问权限。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型     | 必填   | 说明                                  |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | 是    | 表示远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |
| authorization | [AccessAuthorization](js-apis-bluetooth-constant.md#AccessAuthorization) | 是    | 表示访问权限枚举值。 |

**返回值：**

| 类型                                              | 说明                |
| ------------------------------------------------- | ------------------- |
| Promise&lt;void&gt; | 以Promise的形式返回结果。如果成功，err为undefined的，否则为错误对象。 |

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
try {
    let mapMseProfile = map.createMapMseProfile();
    mapMseProfile.setMessageAccessAuthorization('XX:XX:XX:XX:XX:XX', 0).then(() => {
        console.info('setMessageAccessAuthorization');
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### getMessageAccessAuthorization<a name="MapMseProfile-getMessageAccessAuthorization"></a>

getMessageAccessAuthorization(deviceId: string): Promise&lt;AccessAuthorization&gt;

获取信息的访问权限。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型     | 必填   | 说明                                  |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | 是    | 表示远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |

**返回值：**

| 类型                                              | 说明                |
| ------------------------------------------------- | ------------------- |
| Promise&lt;[AccessAuthorization](js-apis-bluetooth-constant.md#AccessAuthorization)&gt; | 以Promise的形式返回结果。如果成功，err为undefined的，否则为错误对象。 |

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
try {
    let mapMseProfile = map.createMapMseProfile();
    mapMseProfile.getMessageAccessAuthorization('XX:XX:XX:XX:XX:XX').then((authorization) => {
        console.info('authorization ' + authorization);
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```