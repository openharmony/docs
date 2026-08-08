# @ohos.bluetooth.pan (蓝牙pan模块)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->

本模块提供基于蓝牙个人局域网协议（Personal Area Networking，[PAN](../../connectivity/bluetooth/terminology.md#pan)）的蓝牙共享网络能力，支持获取连接状态等方法。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import { pan } from '@kit.ConnectivityKit';
```

## BaseProfile

type BaseProfile = baseProfile.BaseProfile

基础Profile接口定义，提供订阅和获取连接状态等公共能力。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 类型                            | 说明         |
| ----------------------------- | ---------- |
| [baseProfile.BaseProfile](js-apis-bluetooth-baseProfile.md#baseprofile) | 基础Profile接口定义。 |

## pan.createPanProfile

createPanProfile(): PanProfile

创建蓝牙[PAN](../../connectivity/bluetooth/terminology.md#pan)实例。通过该实例可使用本端作为[NAP](../../connectivity/bluetooth/terminology.md#nap)设备和[PANU](../../connectivity/bluetooth/terminology.md#panu)设备的接口，如：获取和其他设备间的蓝牙个人局域网服务连接状态。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**返回值**：

| 类型                            | 说明         |
| ----------------------------- | ---------- |
| PanProfile | 返回PAN实例。该类继承于[BaseProfile](#baseprofile)，因此可以使用其父类中的方法。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**示例**：

```js
try {
    let panProfile : pan.PanProfile= pan.createPanProfile();
    console.info('pan success');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## PanProfile

表示蓝牙PAN通信的实例。
- 使用PanProfile方法之前需要创建该类的实例进行操作，通过[createPanProfile](#pancreatepanprofile)方法构造此实例。
- 该类继承于[BaseProfile](#baseprofile)，因此可以使用其父类中的方法。

### isPanSupported

isPanSupported(): boolean

本端作为NAP角色时使用，获取本端网络共享状态。

**起始版本**：26.0.0

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**返回值**：

| 类型      | 说明                  |
| --------------------- | --------------------------------- |
| boolean | 当前设备支持PAN时返回true，不支持时返回false。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|2900099 | Operation failed.                        |

**示例**：

```js
try {
    let panProfile: pan.PanProfile = pan.createPanProfile();
    let isPanSupported: boolean = panProfile.isPanSupported();
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

### isTetheringOn

isTetheringOn(): boolean

本端作为NAP时使用，获取本端网络共享状态。

**起始版本**：26.0.0

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**返回值**：

| 类型      | 说明                  |
| --------------------- | --------------------------------- |
| boolean | 网络共享开启返回true，网络共享关闭返回false。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported. Only can be called on phone, tablet, and 2in1 devices. Failed to call the API when the short-range chip is not inserted on 2in1 device.          |


**示例**：

```js
try {
    let panProfile: pan.PanProfile = pan.createPanProfile();
    let isTetheringOn: boolean = panProfile.isTetheringOn();
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```
