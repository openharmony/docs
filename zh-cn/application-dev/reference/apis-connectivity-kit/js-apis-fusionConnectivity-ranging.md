# @ohos.FusionConnectivity.ranging (融合测距模块)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->

本模块基于星闪技术，为应用提供设备测距功能，适用于智能防丢、近场找物、数字钥匙等需要获取设备间精确距离的场景。主要功能特性包括：

- 支持近场链路星闪[HADM](../../connectivity/fusion-connectivity/fusion-connectivity-terminology.md#hadm)测距类型，实现高精度距离测量。
- 支持主动测距模式，获取目标设备的距离、角度和信号强度信息。
- 支持被动测距模式，设备可作为测距信标被其他设备发现和测量。
- 支持测距状态变化订阅，实时监听设备测距开始、停止等状态通知。

**起始版本**：26.0.0

## 导入模块

```js
import { ranging } from '@kit.ConnectivityKit';
```

## ranging.isRangingSupported

isRangingSupported(): boolean

判断本端设备是否支持测距特性。

建议在调用本模块其他接口前先调用此接口检查设备是否支持测距特性，避免因不支持而导致功能异常。

**起始版本**：26.0.0

**系统能力**：SystemCapability.Communication.FusionConnectivity.Core

**模型约束**：此接口仅可在Stage模型下使用。

**返回值**：

| 类型     | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 是否支持测距功能。true表示支持，false表示不支持。 |

**示例**：

```js
import { ranging } from '@kit.ConnectivityKit';
try {
  let isSupport = ranging.isRangingSupported();
  console.info(`This device does support ranging: ${isSupport}`);
} catch (err) {
  console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

## ranging.getRangingCapability

getRangingCapability(): Promise&lt;RangingCapabilitySupported&gt;

查询本端设备支持的测距能力，使用Promise异步回调。

- 建议先使用[isRangingSupported](#rangingisrangingsupported)判断本端是否支持测距特性。仅在特性支持的情况下才能使用融合测距的功能。
- 获取成功后，使用Promise异步返回测距类型是否支持。仅当[nearlinkHadm](#rangingcapabilitysupported)值为true，才可以使用[startRanging](#rangingstartranging)发起星闪[HADM](../../connectivity/fusion-connectivity/fusion-connectivity-terminology.md#hadm)测距，或使用[startPassiveRanging](#rangingstartpassiveranging)启动被动测距。

**起始版本**：26.0.0

**需要权限**：ohos.permission.ACCESS_NEARLINK

**系统能力**：SystemCapability.Communication.FusionConnectivity.Core

**模型约束**：此接口仅可在Stage模型下使用。

**返回值**：

| 类型                                                         | 说明                         |
| ---------------------------------------------------------- | -------------------------- |
| Promise&lt;[RangingCapabilitySupported](#rangingcapabilitysupported)&gt; | Promise对象，返回本端设备支持的测距类型。 |

**错误码**：

以下错误码的详细介绍请参见[融合短距服务子系统错误码](../apis-connectivity-kit/errorcode-fusionConnectivity.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | ---------------------------------- |
| 201      | Permission denied.                 |
| 801      | Capability not supported.          |
| 34900053 | The ranging service is disabled.   |

**示例**：

```js
import { ranging } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';
try {
  ranging.getRangingCapability().then((capability) => {
    console.info(`nearlink HADM supported: ${capability.nearlinkHadm}`);
  }).catch((err: BusinessError) => {
    console.error(`getRangingCapability errCode: ${err.code}, errMessage: ${err.message}`);
  });
} catch (err) {
  console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

## ranging.startRanging

startRanging(params: RangingParams, callback: Callback&lt;RangingResult&gt;): void

向指定设备发起主动测距，获取目标设备的距离和信号强度等信息。典型应用场景包括：智能防丢与寻找、近场找物、数字钥匙等。

该接口的执行流程取决于本端设备与目标设备的星闪连接状态：

- 若本端设备已与目标设备建立了星闪连接，调用此接口会直接向目标设备发起测距。
- 若本端设备与目标设备未建立星闪连接，该接口将执行以下流程：
  1. 融合测距服务内部先尝试与目标设备建立连接，连接成功后进行配对和加密操作。配对时需要用户主动在设备上操作授权。如果用户拒绝授权或者超时未授权，本次测距将会停止，停止状态会通过[onRangingStateChange](#rangingonrangingstatechange)接口注册的callback通知，停止后需在应用侧主动调用[stopRanging](#rangingstopranging)接口停止测距并释放测距资源。
  2. 连接完成后，测距服务会先查询目标设备是否支持对应的测距服务[UUID](../../connectivity/bluetooth/terminology.md#uuid)，确认服务支持后自动发起测距；如果在连接后，对端设备不支持测距服务[UUID](../../connectivity/bluetooth/terminology.md#uuid)，融合测距服务内部会主动断开与对端设备已建立的连接，并通过回调通知测距停止。

开始测距后，可通过[onRangingStateChange](#rangingonrangingstatechange)实时监听测距状态变化，测距结果通过本接口中的入参callback返回。

成功启动测距后结果会频繁回调上报，建议根据实际需要在获取测距结果后及时调用stopRanging停止测距，业务需要时可再次发起测距，避免不必要的功耗损失。

**起始版本**：26.0.0

> **说明：**
>
> - 使用测距接口前，需先通过[getRangingCapability](#ranginggetrangingcapability)确认设备支持对应的测距类型。
> - 使用星闪[HADM](../../connectivity/fusion-connectivity/fusion-connectivity-terminology.md#hadm)测距时，本端设备在发起主动测距后，无法使用被动测距模式。如需使用被动测距，需先调用[stopRanging](#rangingstopranging)停止主动测距。
> - 对同一设备连续重复调用[startRanging](#rangingstartranging)会提示设备已发起测距并返回错误码34900051。如需对同一设备再次发起测距，需先调用[stopRanging](#rangingstopranging)停止之前的测距后重新调用。
> - 如果启动测距时，对应类型的测距服务已下线，那么调用本接口时会抛出服务未使能错误码34900053。
> - 接口入参需要按照要求填写，如果不符合要求接口会返回对应的错误码，详细要求见参数的定义。

**需要权限**：ohos.permission.ACCESS_NEARLINK

**系统能力**：SystemCapability.Communication.FusionConnectivity.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名          | 类型                                   | 必填 | 说明                    |
| ------------- | ------------------------------------ | ---- | --------------------- |
| params        | [RangingParams](#rangingparams)            | 是   | 目标设备的测距参数，包含设备的地址和测距能力类型。如果填入的参数不符合要求，接口会按照参数要求返回对应的错误码。   |
| callback      | Callback&lt;[RangingResult](#rangingresult)&gt; | 是   | 测距结果回调，每次测距结果产生时触发回调。同时作为测距目标标识，需在调用[stopRanging](#rangingstopranging)时传入相同引用以关联已启动的测距，因此在应用侧不要使用临时callback作为入参。同一callback可关联多个设备的测距会话，但如果调用[stopRanging](#rangingstopranging)接口停止测距时未指定[params](#rangingparams)，接口将根据callback停止全部关联的测距设备，不建议多个设备共用同一测距回调。    |

**错误码**：

以下错误码的详细介绍请参见[融合短距服务子系统错误码](../apis-connectivity-kit/errorcode-fusionConnectivity.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                    |
| -------- | -------------------------------------------------------------- |
| 201      | Permission denied.                                              |
| 801      | Capability not supported.                                       |
| 34900051 | The device has already initiated ranging.                       |
| 34900052 | The specified type of ranging service is not supported.         |
| 34900053 | The ranging service is disabled.                                |
| 34900054 | The parameter value does not meet specifications.               |
| 34900099 | Internal system error. For example, Internal object is invalid. |

**示例**：

```js
import { ranging } from '@kit.ConnectivityKit';

let rangingCallback = (result: ranging.RangingResult) => {
  console.info(`deviceId: ${result.deviceId}`);
  console.info(`distance value: ${result.distance.value} cm`);
  console.info(`distance confidence: ${result.distance.confidence}`);
  console.info(`angle value: ${result.angle.value}`);
  console.info(`angle confidence: ${result.angle.confidence}`);
  console.info(`rssi: ${result.rssi}`);
};

let params: ranging.RangingParams = {
  deviceId: '11:22:33:44:55:66',   // 请替换为实际的目标设备地址
  capabilityType: ranging.RangingTypes.NEARLINK_HADM
};
try {
  ranging.startRanging(params, rangingCallback);
} catch (err) {
  console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

## ranging.stopRanging

stopRanging(callback: Callback&lt;RangingResult&gt;, params?: RangingParams): void

停止正在进行中的主动测距。

需与[startRanging](#rangingstartranging)配合使用，传入的callback必须与启动测距时的callback为同一引用对象。

> **说明：**
>
> - 此方法同时释放测距占用的资源。为实现正确的资源管理，[startRanging](#rangingstartranging)测距启动后必须调用stopRanging停止测距，避免测距资源泄漏。
> - 测距状态的变化通过[onRangingStateChange](#rangingonrangingstatechange)回调进行通知。
> - 如果未调用过[startRanging](#rangingstartranging)直接调用[stopRanging](#rangingstopranging)将抛出设备未发起测距错误34900050。

**起始版本**：26.0.0

**需要权限**：ohos.permission.ACCESS_NEARLINK

**系统能力**：SystemCapability.Communication.FusionConnectivity.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名    | 类型                                         | 必填 | 说明                      |
| ------- | ------------------------------------------ | ---- | ----------------------- |
| callback | Callback&lt;[RangingResult](#rangingresult)&gt; | 是 | 测距结果回调，需与[startRanging](#rangingstartranging)传入的callback为同一引用对象，否则将无法停止已启动的测距。该入参要求与[startRanging](#rangingstartranging)中的callback要求相同。   |
| params   | [RangingParams](#rangingparams) | 否 | 测距参数，包含deviceId和测距能力类型，与[startRanging](#rangingstartranging)接口中的params相同。默认值：undefined。指定此参数时仅停止与指定目标设备的测距；不传入此参数时停止与callback关联的所有设备的测距。 |

**错误码**：

以下错误码的详细介绍请参见[融合短距服务子系统错误码](../apis-connectivity-kit/errorcode-fusionConnectivity.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                   |
| -------- | ------------------------------------------------------------------------ |
| 201      | Permission denied.                                                         |
| 801      | Capability not supported.                                                  |
| 34900050 | The device has not initiated ranging.                                   |
| 34900052 | The specified type of ranging service is not supported.                    |
| 34900054 | The parameter value does not meet specifications.                          |
| 34900099 | Internal system error. For example, Internal object is invalid.            |

**示例**：

```js
import { ranging } from '@kit.ConnectivityKit';

let rangingCallback = (result: ranging.RangingResult) => {
  console.info(`deviceId: ${result.deviceId}`);
  console.info(`distance value: ${result.distance.value} cm`);
  console.info(`distance confidence: ${result.distance.confidence}`);
  console.info(`angle value: ${result.angle.value}`);
  console.info(`angle confidence: ${result.angle.confidence}`);
  console.info(`rssi: ${result.rssi}`);
};

let params: ranging.RangingParams = {
  deviceId: '11:22:33:44:55:66',   // 请替换为实际的目标设备地址
  capabilityType: ranging.RangingTypes.NEARLINK_HADM
};
try {
  // 停止指定设备的测距
  ranging.stopRanging(rangingCallback, params);
  // 停止该callback关联的所有设备的测距
  // ranging.stopRanging(rangingCallback);
} catch (err) {
  console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

## ranging.startPassiveRanging

startPassiveRanging(capabilityType: RangingTypes): Promise&lt;number&gt;

启动被动测距模式。本端设备将作为测距信标广播测距数据包，允许其他支持对应测距类型的主动测距设备发现本端设备。典型应用场景包括：本端设备作为被定位标签或防丢贴片、固定信标部署等，适用于本端需要被其他设备测量距离的场景。

> **说明：**
>
> - 使用测距接口前，需先通过[getRangingCapability](#ranginggetrangingcapability)确认设备支持对应的测距类型。
> - 使用星闪[HADM](../../connectivity/fusion-connectivity/fusion-connectivity-terminology.md#hadm)测距时，本端设备在发起被动测距后，无法使用主动测距模式。如需使用主动测距，需先调用[stopPassiveRanging](#rangingstoppassiveranging)停止被动测距。
> - 同一测距能力类型仅支持单次调用[startPassiveRanging](#rangingstartpassiveranging)，成功后返回的handle对应独立的广播会话。
> - 如需对同一测距能力再次调用[startPassiveRanging](#rangingstartpassiveranging)，需要先调用[stopPassiveRanging](#rangingstoppassiveranging)结束本次的被动测距，如果直接再次调用，接口将返回错误码34900099。
> - 如果启动测距时，对应类型的测距服务已下线，那么调用本接口时会抛出服务未使能错误码34900053。

**起始版本**：26.0.0

**需要权限**：ohos.permission.ACCESS_NEARLINK

**系统能力**：SystemCapability.Communication.FusionConnectivity.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名         | 类型                         | 必填 | 说明         |
| ------------ | -------------------------- | ---- | ---------- |
| capabilityType | [RangingTypes](#rangingtypes) | 是   | 测距能力类型。参数必须要填入有效值，否则接口会抛出[34900052](errorcode-fusionConnectivity.md#34900052-不支持指定类型的测距服务)错误码。   |

**返回值**：

| 类型               | 说明         |
| ---------------- | ---------- |
| Promise&lt;number&gt; | Promise对象，返回被动测距会话的句柄标识符handle，数值范围[0, 2147483647)。<br> 该句柄用于：1. 在[stopPassiveRanging](#rangingstoppassiveranging)中指定要停止的被动测距会话。2. 在[onRangingStateChange](#rangingonrangingstatechange)回调的[stateInfo.handle](#rangingstatechangeinfo)中标识对应的被动测距会话。   |

**错误码**：

以下错误码的详细介绍请参见[融合短距服务子系统错误码](../apis-connectivity-kit/errorcode-fusionConnectivity.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                         |
| -------- | --------------------------------------------------------------- |
| 201      | Permission denied.                                             |
| 801      | Capability not supported.                                       |
| 34900052 | The specified type of ranging service is not supported.         |
| 34900053 | The ranging service is disabled.                                |
| 34900099 | Internal system error. For example, Internal object is invalid. |

**示例**：

```js
import { ranging } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let passiveHandle = -1;  // -1表示无效句柄
try {
  ranging.startPassiveRanging(ranging.RangingTypes.NEARLINK_HADM).then((handle) => {
    if (handle >= 0) {
      passiveHandle = handle;
      console.info(`startPassiveRanging handle: ${handle}`);
    }
  }).catch((err: BusinessError) => {
    console.error(`startPassiveRanging errCode: ${err.code}, errMessage: ${err.message}`);
  });
} catch (err) {
  console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

## ranging.stopPassiveRanging

stopPassiveRanging(handle: number, capabilityType: RangingTypes): void

停止被动测距模式。根据指定的句柄和测距类型停止对应的被动测距广播，并清理相关资源。

> **说明：**
> 
> - 只有[startPassiveRanging](#rangingstartpassiveranging)接口调用成功之后，才需要调用本接口停止被动测距广播。如果未调用过[startPassiveRanging](#rangingstartpassiveranging)直接调用[stopPassiveRanging](#rangingstoppassiveranging)，由于handle无效将抛出参数不符合规格错误34900054。为实现正确的资源管理，[startPassiveRanging](#rangingstartpassiveranging)启动被动测距后必须调用[stopPassiveRanging](#rangingstoppassiveranging)停止被动测距，避免测距资源泄漏。
> - 停止测距的状态变化通过[onRangingStateChange](#rangingonrangingstatechange)回调通知。

**起始版本**：26.0.0

**需要权限**：ohos.permission.ACCESS_NEARLINK

**系统能力**：SystemCapability.Communication.FusionConnectivity.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名         | 类型                         | 必填 | 说明         |
| ------------ | -------------------------- | ---- | ---------- |
| handle       | number                     | 是   | 测距监控句柄，应为[startPassiveRanging](#rangingstartpassiveranging)返回的有效句柄，否则会抛出[34900054](errorcode-fusionConnectivity.md#34900054-参数不符合业务规格)错误；停止后该handle不再有效，不可重复使用。   |
| capabilityType | [RangingTypes](#rangingtypes) | 是   | 测距能力类型，参数需与[startPassiveRanging](#rangingstartpassiveranging)接口传入的capabilityType保持一致。   |

**错误码**：

以下错误码的详细介绍请参见[融合短距服务子系统错误码](../apis-connectivity-kit/errorcode-fusionConnectivity.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                   |
| -------- | ------------------------------------------------------------------------ |
| 201      | Permission denied.                                                         |
| 801      | Capability not supported.                                                  |
| 34900052 | The specified type of ranging service is not supported.                    |
| 34900054 | The parameter value does not meet specifications.                          |
| 34900099 | Internal system error. For example, Internal object is invalid.            |

**示例**：

```js
import { ranging } from '@kit.ConnectivityKit';

// passiveHandle为startPassiveRanging返回的有效句柄
let passiveHandle = 0;

try {
  ranging.stopPassiveRanging(passiveHandle, ranging.RangingTypes.NEARLINK_HADM);
} catch (err) {
  console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

## ranging.onRangingStateChange

onRangingStateChange(callback: Callback&lt;RangingStateChangeInfo&gt;): void

注册测距状态变化回调，监听测距状态通知。

通知主动测距或者被动测距操作的状态变化。回调中通过不同字段区分：

- 主动测距场景：通过[stateInfo.deviceId](#rangingstatechangeinfo)标识发生状态变化的设备。
- 被动测距场景：通过[stateInfo.handle](#rangingstatechangeinfo)标识发生状态变化的被动测距会话。

> **说明：**
>
> - 多次调用将注册多个回调，每个回调都会收到状态变化通知。
> - 当测距状态变为[RANGING_STOPPED](#rangingstate)时，[cause](#rangingstoppedcause)字段表示停止原因。

**起始版本**：26.0.0

**需要权限**：ohos.permission.ACCESS_NEARLINK

**系统能力**：SystemCapability.Communication.FusionConnectivity.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名     | 类型                                           | 必填 | 说明      |
| ------- | -------------------------------------------- | ---- | ------- |
| callback | Callback&lt;[RangingStateChangeInfo](#rangingstatechangeinfo)&gt; | 是   | 测距状态回调，当测距状态发生变化时触发。该参数可用于[offRangingStateChange](#rangingoffrangingstatechange)接口的入参取消注册测距状态回调。   |

**错误码**：

以下错误码的详细介绍请参见[融合短距服务子系统错误码](../apis-connectivity-kit/errorcode-fusionConnectivity.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息      |
| -------- | ----------- |
| 201      | Permission denied. |
| 801      | Capability not supported. |
| 34900099 | Internal system error. For example, Internal object is invalid. |

**示例**：

```js
import { ranging } from '@kit.ConnectivityKit';

let stateChangeCallback = (stateInfo: ranging.RangingStateChangeInfo) => {
  console.info(`ranging state: ${stateInfo.state}`);
  if (stateInfo.state === ranging.RangingState.RANGING_STOPPED) {
    console.info(`ranging stopped cause: ${stateInfo.cause}`);
  }
  if (stateInfo.deviceId) {
    console.info(`active ranging deviceId: ${stateInfo.deviceId}`);
  }
  if (stateInfo.handle !== undefined) {
    console.info(`passive ranging handle: ${stateInfo.handle}`);
  }
};
try {
  ranging.onRangingStateChange(stateChangeCallback);
} catch (err) {
  console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

## ranging.offRangingStateChange

offRangingStateChange(callback?: Callback&lt;RangingStateChangeInfo&gt;): void

注销测距状态变化回调。

> **说明：**
>
> - 该接口只有在[onRangingStateChange](#rangingonrangingstatechange)之后调用才会有效。

**起始版本**：26.0.0

**需要权限**：ohos.permission.ACCESS_NEARLINK

**系统能力**：SystemCapability.Communication.FusionConnectivity.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名     | 类型                                           | 必填 | 说明      |
| ------- | -------------------------------------------- | ---- | ------- |
| callback | Callback&lt;[RangingStateChangeInfo](#rangingstatechangeinfo)&gt; | 否   | 测距状态回调。传入此参数时仅取消通过[onRangingStateChange](#rangingonrangingstatechange)接口使用相同入参已注册的回调，如果传入的callback未注册过，该接口不会处理；不传入此参数时接口会取消所有通过[onRangingStateChange](#rangingonrangingstatechange)接口已注册过的回调。   |

**错误码**：

以下错误码的详细介绍请参见[融合短距服务子系统错误码](../apis-connectivity-kit/errorcode-fusionConnectivity.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息      |
| -------- | ----------- |
| 201      | Permission denied. |
| 801      | Capability not supported. |
| 34900099 | Internal system error. For example, Internal object is invalid. |

**示例**：

```js
import { ranging } from '@kit.ConnectivityKit';

let stateChangeCallback = (stateInfo: ranging.RangingStateChangeInfo) => {
  console.info(`ranging state: ${stateInfo.state}`);
  if (stateInfo.state === ranging.RangingState.RANGING_STOPPED) {
    console.info(`ranging stopped cause: ${stateInfo.cause}`);
  }
  if (stateInfo.deviceId) {
    console.info(`active ranging deviceId: ${stateInfo.deviceId}`);
  }
  if (stateInfo.handle !== undefined) {
    console.info(`passive ranging handle: ${stateInfo.handle}`);
  }
};
let isRegistered = false;
try {
  ranging.onRangingStateChange(stateChangeCallback);
  isRegistered = true;
} catch (err) {
  console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}

if (isRegistered) {
  try {
    // 取消指定回调的订阅
    ranging.offRangingStateChange(stateChangeCallback);
    // 取消所有已注册回调的订阅
    // ranging.offRangingStateChange();
  } catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
  }
}
```

## RangingParams

测距参数，用于指定主动测距的目标设备和测距类型。

**起始版本**：26.0.0

**系统能力**：SystemCapability.Communication.FusionConnectivity.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 名称            | 类型                     | 只读 | 可选 | 说明        |
| ------------- | ---------------------- | ---- | ---- | --------- |
| deviceId      | string                 | 否   | 否   | 目标测距设备的地址，格式为xx:xx:xx:xx:xx:xx，其中x为十六进制数字，范围为0~9和A~F，分隔符为冒号，示例："11:22:33:44:55:66"。该参数需要按照指定格式填写，如果填入的参数不合法，会抛出[34900054](errorcode-fusionConnectivity.md#34900054-参数不符合业务规格)的错误码。  |
| capabilityType | [RangingTypes](#rangingtypes) | 否   | 否   | 测距能力类型，用于指定使用的测距技术。该参数必须要填入定义的有效值，否则引用该参数的接口会抛出[34900052](errorcode-fusionConnectivity.md#34900052-不支持指定类型的测距服务)错误。 |

## RangingStateChangeInfo

描述测距状态变化信息，主动测距和被动测距的状态变化共用此结构。

**起始版本**：26.0.0

**系统能力**：SystemCapability.Communication.FusionConnectivity.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 名称    | 类型                                   | 只读 | 可选 | 说明        |
| ----- | ------------------------------------ | ---- | ---- | --------- |
| state  | [RangingState](#rangingstate)              | 否   | 否   | 测距状态。    |
| cause  | [RangingStoppedCause](#rangingstoppedcause) | 否   | 否   | 测距停止原因，仅在state为RANGING_STOPPED时有意义。  |
| deviceId | string           | 否   | 是   | 测距设备地址，主动测距场景下标识发生状态变化的目标设备。被动测距场景下该字段不适用，默认值为undefined。  |
| handle | number           | 否   | 是   | 测距监控句柄，被动测距场景下标识发生状态变化的被动测距会话。主动测距场景下该字段不适用，默认值为undefined。  |

## RangingResult

描述测距结果，每次测距测量完成后通过[startRanging](#rangingstartranging)的callback回调返回。

**起始版本**：26.0.0

**系统能力**：SystemCapability.Communication.FusionConnectivity.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 名称     | 类型                               | 只读 | 可选 | 说明          |
| ------ | -------------------------------- | ---- | ---- | ----------- |
| deviceId | string                           | 否   | 否   | 测距设备地址。    |
| distance | [RangingMeasurement](#rangingmeasurement) | 否   | 否   | 测距输出的距离测量结果，value单位：cm。  |
| angle   | [RangingMeasurement](#rangingmeasurement) | 否   | 否   | 测距输出的方位角，value单位：度，有效值的取值范围：[0, 360)，返回-1表示不支持测角。   |
| rssi    | number                           | 否   | 否   | 接收信号强度指示[RSSI](../../connectivity/bluetooth/terminology.md#rssi)，单位：dBm。    |

## RangingCapabilitySupported

描述设备支持的测距类型。

**起始版本**：26.0.0

**系统能力**：SystemCapability.Communication.FusionConnectivity.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 名称         | 类型     | 只读 | 可选 | 说明                      |
| ---------- | ------ | ---- | ---- | ----------------------- |
| nearlinkHadm | boolean | 否   | 否   | 星闪[HADM](../../connectivity/fusion-connectivity/fusion-connectivity-terminology.md#hadm)测距类型是否支持。值为true时可使用[startRanging](#rangingstartranging)或[startPassiveRanging](#rangingstartpassiveranging)发起测距。 |

## RangingMeasurement

描述测量结果，包含测量值和对应的置信度。测量结果可用于距离测量或角度测量。

**起始版本**：26.0.0

**系统能力**：SystemCapability.Communication.FusionConnectivity.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 名称       | 类型                                 | 只读 | 可选 | 说明             |
| -------- | ---------------------------------- | ---- | ---- | -------------- |
| value    | number                             | 否   | 否   | 测量结果值。距离测量时单位：cm，角度测量时单位：度。 |
| confidence | [RangingConfidence](#rangingconfidence) | 否   | 否   | 测量结果的置信度，表示本次测量值的可信程度。   |

## RangingTypes

枚举，测距能力类型。

**起始版本**：26.0.0

**系统能力**：SystemCapability.Communication.FusionConnectivity.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 名称           | 值   | 说明                                        |
| ------------ | ---- | ----------------------------------------- |
| NEARLINK_HADM | 1    | 星闪[HADM](../../connectivity/fusion-connectivity/fusion-connectivity-terminology.md#hadm)测距类型。  |

## RangingState

枚举，测距状态。

**起始版本**：26.0.0

**系统能力**：SystemCapability.Communication.FusionConnectivity.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 名称           | 值   | 说明      |
| ------------ | ---- | ------- |
| RANGING_STOPPED | 0   | 已停止。停止原因参见[RangingStoppedCause](#rangingstoppedcause)。 |
| RANGING_STARTED | 1   | 已启动，测距正在进行中。 |

## RangingStoppedCause

枚举，测距停止原因。

**起始版本**：26.0.0

**系统能力**：SystemCapability.Communication.FusionConnectivity.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 名称              | 值 | 说明 |
| --------------- | ---- | ----- |
| NO_ERROR         | 0 | 正常停止，无错误。通常由应用主动调用stopRanging或stopPassiveRanging触发。 |
| INTERNAL_ERROR   | 1 | 发生内部错误，测距服务异常导致停止。 |
| BUSINESS_CONFLICT | 2 | 发生业务冲突，其他服务占用导致测距停止。 |
| BACKGROUND_PAUSED | 3 | 应用退到后台时测距暂停。应用回到前台会自动恢复测距。 |

## RangingConfidence

枚举，测距测量置信度，表示测量结果值的可信程度。

**起始版本**：26.0.0

**系统能力**：SystemCapability.Communication.FusionConnectivity.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 名称    | 值 | 说明 |
| ----- | ---- | ----- |
| HIGH   | 0 | 高置信度测量，测量值可信度高，可直接使用。 |
| MEDIUM | 1 | 中置信度测量，测量值有一定可信度，建议结合其他信息综合判断。 |
| LOW    | 2 | 低置信度测量，测量值可信度低，建议谨慎使用。 |