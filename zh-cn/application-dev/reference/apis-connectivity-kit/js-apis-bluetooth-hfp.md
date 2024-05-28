# @ohos.bluetooth.hfp (蓝牙hfp模块)

hfp模块提供了访问蓝牙呼叫接口的方法。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。



## 导入模块

```js
import hfp from '@ohos.bluetooth.hfp';
```


## hfp.createHfpAgProfile

createHfpAgProfile(): HandsFreeAudioGatewayProfile

创建hfp profile实例。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**返回值：**

| 类型                            | 说明         |
| ----------------------------- | ---------- |
| HandsFreeAudioGatewayProfile | 返回该profile的实例。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900004 | Profile is not supported.                |
|2900099 | Operation failed.                        |

**示例：**

```js
import { BusinessError } from '@ohos.base';
try {
    let hfpAgProfile = hfp.createHfpAgProfile();
    console.info('hfpAg success');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## HandsFreeAudioGatewayProfile

使用HandsFreeAudioGatewayProfile方法之前需要创建该类的实例进行操作，通过createHfpAgProfile()方法构造此实例。
