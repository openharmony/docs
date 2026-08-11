# @ohos.FusionConnectivity.ranging (Fusion Connectivity Ranging Module)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=f27c946fc782ac1d031692b6ff0d2063a86e9e01 translatedAt=2026-08-03T02:20:03.749Z pushedAt=2026-08-03T09:44:12.023Z -->

This module uses the NearLink technology to provide the device ranging function for apps. The main features are as follows:

- Supports NearLink [HADM](../../connectivity/terminology.md#high-accuracy-distance-measurement-hadm)) ranging, enabling high-precision distance measurement.

- Supports the active ranging mode, in which the distance, angle, and signal strength of the target device can be obtained.

- Supports the passive ranging mode, in which the device can be discovered and measured by other devices as a ranging beacon.

- Supports subscription to ranging state change events, enabling listening for state changes such as ranging start and stop in real time.

**Since**: 26.0.0

## Modules to Import

```js
import { ranging } from '@kit.ConnectivityKit';
```

## ranging.isRangingSupported

isRangingSupported(): boolean

Checks whether the local device supports ranging.

You are advised to call this API first to check whether the device supports ranging. This prevents function exceptions caused by lack of support.

**Since**: 26.0.0

**System capability**: SystemCapability.Communication.FusionConnectivity.Core

**Model restriction**: This API can be used only in the stage model.

**Return value**

| Type    | Description                                      |
| ------- | ------------------------------------------------ |
| boolean | Whether the ranging feature is supported. The value **true** indicates ranging is supported, and **false** indicates otherwise. |

**Example**

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

Queries the ranging capability supported by the local device. This API uses a promise to return the result.

- You are advised to call [isRangingSupported](#rangingisrangingsupported) to check whether the local device supports ranging first. The fusion connectivity ranging feature can be used only when range is supported.

- If the query is successful, a promise is used to return whether the ranging type is supported. You can call [startRanging](#rangingstartranging) to start NearLink [HADM](../../connectivity/terminology.md#high-accuracy-distance-measurement-hadm)) ranging or call [startPassiveRanging](#rangingstartpassiveranging) to start passive ranging only when the value of [nearlinkHadm](#rangingcapabilitysupported) is **true**.

**Since**: 26.0.0

**Required permissions**: ohos.permission.ACCESS_NEARLINK

**System capability**: SystemCapability.Communication.FusionConnectivity.Core

**Model restriction**: This API can be used only in the stage model.

**Return value**

| Type                                                        | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------------ |
| Promise&lt;[RangingCapabilitySupported](#rangingcapabilitysupported)&gt; | Promise used to return the ranging types supported by the local device. |

**Error codes**

For details about the error codes, see [Error Codes of the Converged Short-Range Service Subsystem](../apis-connectivity-kit/errorcode-fusionConnectivity.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                      |
| -------- | ---------------------------------- |
| 201      | Permission denied.                 |
| 801      | Capability not supported.          |
| 34900053 | The ranging service is disabled.   |

**Example**

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

Starts active ranging to a specified device.

The execution flow of this API depends on the NearLink connection status between the local device and the target device:

- If a NearLink connection has been established between the local device and the target device, calling this API will directly initiate ranging to the target device.

- If no NearLink connection has been established between the local device and the target device, this API performs the following process:

  1. The fusion connectivity ranging service attempts to establish a connection with the target device first and performs pairing and encryption upon successful connection. During pairing, the user needs to proactively authorize the operation on the device. If the user rejects authorization or the authorization times out, the ranging will be stopped. The stop status will be notified through the callback registered using the [onRangingStateChange](#rangingonrangingstatechange) API. After the ranging is stopped, the app needs to proactively call [stopRanging](#rangingstopranging) to release the ranging resources.

  2. After the connection is established, the ranging service checks whether the target device supports the corresponding ranging service [UUID](../../connectivity/terminology.md#uuid). If supported, the ranging service automatically initiates ranging. If not, the fusion connectivity ranging service automatically disconnects from the peer device and notifies the ranging stop through a callback.

After ranging starts, you can listen for the ranging state changes in real time by calling [onRangingStateChange](#rangingonrangingstatechange). This API uses a callback to return the ranging result.

After ranging is started successfully, the ranging result will be frequently reported through a callback. After obtaining the ranging result, you are advised to call stopRanging to stop ranging as required to avoid unnecessary power consumption caused by meaningless ranging result reporting. You can start ranging again when necessary.

**Since**: 26.0.0

> **NOTE**
>
> - Before using this API, call [getRangingCapability](#ranginggetrangingcapability) to check whether the device supports the corresponding ranging type.
> - When using the NearLink [HADM](../../connectivity/terminology.md#high-accuracy-distance-measurement-hadm)) to perform ranging, the local device cannot use the passive ranging mode after initiating active ranging. To use passive ranging, call [stopRanging](#rangingstopranging) to stop active ranging first.
> - If [startRanging](#rangingstartranging) is repeatedly called for the same device, a message will be displayed indicating that the device has initialized ranging, and error code 34900051 will be returned.
> - If the ranging service of the corresponding type has been taken offline when ranging is started, error code 34900053 will be returned when this API is called.
> - The input parameters of this API must be set as required. If the input parameters do not meet the requirements, the API will return the corresponding error code. For details, see the parameter definition.

**Required permissions**: ohos.permission.ACCESS_NEARLINK

**System capability**: SystemCapability.Communication.FusionConnectivity.Core

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name          | Type                                   | Mandatory | Description                    |
| ------------- | ------------------------------------ | ---- | --------------------- |
| params        | [RangingParams](#rangingparams)            | Yes   | Ranging parameters of the target device, including the device address and ranging type. If the input parameters do not meet the requirements, the API returns the corresponding error code as specified.   |
| callback      | Callback&lt;[RangingResult](#rangingresult)&gt; | Yes   | Callback used to return the ranging result. This callback is triggered each time a ranging result is generated. It is also used as the ranging target ID. When calling [stopRanging](#rangingstopranging), you need to pass the same value of this parameter to associate with the started ranging. Therefore, do not use a temporary callback as the input parameter on the app side. A callback can be associated with ranging sessions of multiple devices. However, if [params](#rangingparams) is not specified when [stopRanging](#rangingstopranging) is called to stop ranging, the API will stop ranging for all associated devices based on the callback. It is not recommended that multiple devices share the same ranging callback.   |

**Error codes**

For details about the error codes, see [Error Codes of the Converged Short-Range Service Subsystem](../apis-connectivity-kit/errorcode-fusionConnectivity.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                                                    |
| -------- | -------------------------------------------------------------- |
| 201      | Permission denied.                                              |
| 801      | Capability not supported.                                       |
| 34900051 | The device has already initiated ranging.                       |
| 34900052 | The specified type of ranging service is not supported.         |
| 34900053 | The ranging service is disabled.                                |
| 34900054 | The parameter value does not meet specifications.               |
| 34900099 | Internal system error. For example, Internal object is invalid. |

**Example**

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
  deviceId: "11:22:33:44:55:66",   // Replace it with the actual address of the target device.
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

Stops the ongoing active ranging.

This API must be used together with [startRanging](#rangingstartranging). The passed callback must be the same referenced object as the callback used when ranging is started.

> **NOTE**
>
> - This method also releases the resources occupied by ranging. To ensure proper resource management, **stopRanging** must be called to stop ranging after [startRanging](#rangingstartranging) is called to start ranging, preventing ranging resource leak.
> - The ranging state change is notified through the [onRangingStateChange](#rangingonrangingstatechange) callback.
> - If [stopRanging](#rangingstopranging) is called without [startRanging](#rangingstartranging) being called first, error code 34900050 will be thrown, indicating that the device is not initialized.

**Since**: 26.0.0

**Required permissions**: ohos.permission.ACCESS_NEARLINK

**System capability**: SystemCapability.Communication.FusionConnectivity.Core

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name    | Type                                         | Mandatory | Description                      |
| ------- | ------------------------------------------ | ---- | ----------------------- |
| callback | Callback&lt;[RangingResult](#rangingresult)&gt; | Yes | Callback used to return the ranging result. The callback must be the same referenced object as that passed when [startRanging](#rangingstartranging) is called. Otherwise, the started ranging cannot be stopped. The requirements for this parameter are the same as those for the callback parameter in [startRanging](#rangingstartranging).   |
| params   | [RangingParams](#rangingparams) | No | Ranging parameters, including **deviceId** and ranging types. The parameters are the same as those in **params** of the [startRanging](#rangingstartranging) API. The default value is **undefined**. If this parameter is specified, only the ranging with the specified target device is stopped. If this parameter is not passed, the ranging with all devices associated with the callback is stopped. |

**Error codes**

For details about the error codes, see [Error Codes of the Converged Short-Range Service Subsystem](../apis-connectivity-kit/errorcode-fusionConnectivity.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                                                                   |
| -------- | ------------------------------------------------------------------------ |
| 201      | Permission denied.                                                         |
| 801      | Capability not supported.                                                  |
| 34900050 | The device has not initiated ranging.                                   |
| 34900052 | The specified type of ranging service is not supported.                    |
| 34900054 | The parameter value does not meet specifications.                          |
| 34900099 | Internal system error. For example, Internal object is invalid.            |

**Example**

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
  deviceId: "11:22:33:44:55:66",   // Replace it with the actual address of the target device.
  capabilityType: ranging.RangingTypes.NEARLINK_HADM
};
try {
  // Stop ranging for a specified device.
  ranging.stopRanging(rangingCallback, params);
  // Stop ranging for all devices associated with this callback.
  // ranging.stopRanging(rangingCallback);
} catch (err) {
  console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

## ranging.startPassiveRanging

startPassiveRanging(capabilityType: RangingTypes): Promise&lt;number&gt;

Starts the passive ranging mode. The local device broadcasts ranging data packets as a ranging beacon, allowing other active ranging devices that support the corresponding ranging type to discover the local device.

> **NOTE**
>
> - Before using the ranging API, call [getRangingCapability](#ranginggetrangingcapability) to check whether the device supports the corresponding ranging type.
> - When using the NearLink [HADM](../../connectivity/terminology.md#high-accuracy-distance-measurement-hadm) to perform ranging, the local device cannot use the active ranging mode after initiating passive ranging. To use active ranging, call [stopPassiveRanging](#rangingstoppassiveranging) to stop passive ranging first.
> - The [startPassiveRanging](#rangingstartpassiveranging) API can be called only once for the same ranging capability. After the call is successful, the returned handle corresponds to an independent broadcast session.
> - To call [startPassiveRanging](#rangingstartpassiveranging) again for the same ranging capability, you need to call [stopPassiveRanging](#rangingstoppassiveranging) to stop the current passive ranging first. If you call [startPassiveRanging](#rangingstartpassiveranging) again without stopping the current passive ranging, the API will return error code 34900099.
> - If the ranging service of the corresponding type has been taken offline when ranging is started, error code 34900053 will be returned when this API is called.

**Since**: 26.0.0

**Required permissions**: ohos.permission.ACCESS_NEARLINK

**System capability**: SystemCapability.Communication.FusionConnectivity.Core

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name         | Type                         | Mandatory | Description         |
| ------------ | -------------------------- | ---- | ---------- |
| capabilityType | [RangingTypes](#rangingtypes) | Yes   | The parameter must be set to a valid value. Otherwise, error code [34900052](errorcode-fusionConnectivity.md#34900052-specified-ranging-service-unsupported) will be returned.   |

**Return value**

| Type               | Description         |
| ---------------- | ---------- |
| Promise&lt;number&gt; | Promise used to return the handle ID of a passive ranging session. The value range is [0, INT_MAX).<br> This handle is used to: 1. specify the passive ranging session to be stopped in [stopPassiveRanging](#rangingstoppassiveranging). 2. identify the corresponding passive ranging session in the [stateInfo.handle](#rangingstatechangeinfo) of the [onRangingStateChange](#rangingonrangingstatechange) callback.   |

**Error codes**

For details about the error codes, see [Error Codes of the Converged Short-Range Service Subsystem](../apis-connectivity-kit/errorcode-fusionConnectivity.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                                                         |
| -------- | --------------------------------------------------------------- |
| 201      | Permission denied.                                             |
| 801      | Capability not supported.                                       |
| 34900052 | The specified type of ranging service is not supported.         |
| 34900053 | The ranging service is disabled.                                |
| 34900099 | Internal system error. For example, Internal object is invalid. |

**Example**

```js
import { ranging } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let passiveHandle = -1;  // -1 indicates an invalid handle.
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

Stops the passive ranging mode. This API is used to stop the passive ranging broadcast based on the specified handle and ranging type, and release related resources.

> **NOTE**
> 
> - This API can be called to stop the passive ranging broadcast only after the [startPassiveRanging](#rangingstartpassiveranging) API is successfully called.
> - The [onRangingStateChange](#rangingonrangingstatechange) callback is used to notify the state change of stopping ranging.

**Since**: 26.0.0

**Required permissions**: ohos.permission.ACCESS_NEARLINK

**System capability**: SystemCapability.Communication.FusionConnectivity.Core

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name         | Type                         | Mandatory | Description         |
| ------------ | -------------------------- | ---- | ---------- |
| handle       | number                     | Yes   | Ranging monitoring handle, which is returned by **startPassiveRanging**. The handle must be a valid handle returned by [startPassiveRanging](#rangingstartpassiveranging). Otherwise, error 34900054 is thrown. After the handle is stopped, it becomes invalid and cannot be reused.   |
| capabilityType | [RangingTypes](#rangingtypes) | Yes   | Ranging capability type. The parameter requirements are the same as those for capabilityType in [startPassiveRanging](#rangingstartpassiveranging), and the value must be the same as that passed to [startPassiveRanging](#rangingstartpassiveranging).   |

**Error codes**

For details about the error codes, see [Error Codes of the Converged Short-Range Service Subsystem](../apis-connectivity-kit/errorcode-fusionConnectivity.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                                                                   |
| -------- | ------------------------------------------------------------------------ |
| 201      | Permission denied.                                                         |
| 801      | Capability not supported.                                                  |
| 34900052 | The specified type of ranging service is not supported.                    |
| 34900054 | The parameter value does not meet specifications.                          |
| 34900099 | Internal system error. For example, Internal object is invalid.            |

**Example**

```js
import { ranging } from '@kit.ConnectivityKit';

// passiveHandle is a valid handle returned by startPassiveRanging.
let passiveHandle = 0;

try {
  ranging.stopPassiveRanging(passiveHandle, ranging.RangingTypes.NEARLINK_HADM);
} catch (err) {
  console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

## ranging.onRangingStateChange

onRangingStateChange(callback: Callback&lt;RangingStateChangeInfo&gt;): void

Registers a callback to listen for ranging state changes.

The state change of active or passive ranging is notified. Different fields are used in the callback to distinguish the following scenarios:

- Active ranging: The [stateInfo.deviceId](#rangingstatechangeinfo) field identifies the device whose status has changed.

- Passive ranging: The [stateInfo.handle](#rangingstatechangeinfo) field identifies the passive ranging session whose status has changed.

> **NOTE**
>
> - If this method is called multiple times, multiple callbacks will be registered, and each callback will receive a state change notification.
> - When the ranging state changes to [RANGING_STOPPED](#rangingstate), the [cause](#rangingstoppedcause) field indicates the reason for the stop.

**Since**: 26.0.0

**Required permissions**: ohos.permission.ACCESS_NEARLINK

**System capability**: SystemCapability.Communication.FusionConnectivity.Core

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                                           | Mandatory | Description      |
| ------- | -------------------------------------------- | ---- | ------- |
| callback | Callback&lt;[RangingStateChangeInfo](#rangingstatechangeinfo)&gt; | Yes   | Callback used to return the ranging state. This callback is triggered when the ranging state changes. This parameter can be used as the input parameter of the [offRangingStateChange](#rangingoffrangingstatechange) API to unregister the callback for ranging state changes.   |

**Error codes**

For details about the error codes, see [Error Codes of the Converged Short-Range Service Subsystem](../apis-connectivity-kit/errorcode-fusionConnectivity.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message      |
| -------- | ----------- |
| 201      | Permission denied. |
| 801      | Capability not supported. |
| 34900099 | Internal system error. For example, Internal object is invalid. |

**Example**

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

Unregisters the callback for ranging state changes.

> **NOTE**
>
> - This method is valid only after [onRangingStateChange](#rangingonrangingstatechange) is called.

**Since**: 26.0.0

**Required permissions**: ohos.permission.ACCESS_NEARLINK

**System capability**: SystemCapability.Communication.FusionConnectivity.Core

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                                           | Mandatory | Description      |
| ------- | -------------------------------------------- | ---- | ------- |
| callback | Callback&lt;[RangingStateChangeInfo](#rangingstatechangeinfo)&gt; | No   | Callback used to return the ranging state. If this parameter is passed, only the callback registered through [onRangingStateChange](#rangingonrangingstatechange) using the same input parameters will be canceled. If the passed callback has not been registered, this API will not process it. If this parameter is not passed, this API will cancel all callbacks that have been registered through [onRangingStateChange](#rangingonrangingstatechange).  |

**Error codes**

For details about the error codes, see [Error Codes of the Converged Short-Range Service Subsystem](../apis-connectivity-kit/errorcode-fusionConnectivity.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message      |
| -------- | ----------- |
| 201      | Permission denied. |
| 801      | Capability not supported. |
| 34900099 | Internal system error. For example, Internal object is invalid. |

**Example**

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
    // Unregister the specified callback.
    ranging.offRangingStateChange(stateChangeCallback);
    // Unregister all registered callbacks.
    // ranging.offRangingStateChange();
  } catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
  }
}
```

## RangingParams

Defines the ranging parameters, which specify the target device and ranging type for active ranging.

**Since**: 26.0.0

**System capability**: SystemCapability.Communication.FusionConnectivity.Core

**Model restriction**: This API can be used only in the stage model.

| Name           | Type                    | Read-Only | Optional | Description |
| -------------- | ----------------------- | --------- | -------- | ----------- |
| deviceId       | string                  | No        | No       | Address of the target ranging device. The value is in the format of **xx:xx:xx:xx:xx:xx**, where **x** is a hexadecimal number. The value can only consist of digits (0-9) and uppercase letters (A-F), separated by colons (:), for example, **11:22:33:44:55:66**. This parameter must be set in the specified format. If the value is invalid, error code [34900054](errorcode-fusionConnectivity.md#34900054-invalid-parameters) will be thrown. |
| capabilityType | [RangingTypes](#rangingtypes) | No        | No       | Ranging capability type, which specifies the ranging technology to be used. This parameter must be set to a valid value. Otherwise, [34900052](errorcode-fusionConnectivity.md#34900052-specified-ranging-service-unsupported) will be thrown by the API that references this parameter. |

## RangingStateChangeInfo

Describes the ranging state change information. This struct is shared by the state changes of active and passive ranging.

**Since**: 26.0.0

**System capability**: SystemCapability.Communication.FusionConnectivity.Core

**Model restriction**: This API can be used only in the stage model.

| Name    | Type                                   | Read-Only | Optional | Description        |
| ----- | ------------------------------------ | ---- | ---- | --------- |
| state  | [RangingState](#rangingstate)              | No   | No   | Ranging status.    |
| cause  | [RangingStoppedCause](#rangingstoppedcause) | No   | No   | Reason why the ranging stops. This parameter is valid only when **state** is set to **RANGING_STOPPED**.  |
| deviceId | string           | No   | Yes   | Address of the ranging device. In active ranging scenarios, this parameter identifies the target device whose status has changed.  |
| handle | number           | No   | Yes   | Ranging monitoring handle, which identifies the passive ranging session whose status has changed in passive ranging scenarios.  |

## RangingResult

Describes the ranging result, which is returned through the callback of [startRanging](#rangingstartranging) each time a ranging measurement is complete.

**Since**: 26.0.0

**System capability**: SystemCapability.Communication.FusionConnectivity.Core

**Model restriction**: This API can be used only in the stage model.

| Name     | Type                               | Read-Only | Optional | Description          |
| ------ | -------------------------------- | ---- | ---- | ----------- |
| deviceId | string                           | No   | No   | Address of the ranging device.    |
| distance | [RangingMeasurement](#rangingmeasurement) | No   | No   | Distance measurement result output by the ranging device, in cm.  |
| angle   | [RangingMeasurement](#rangingmeasurement) | No   | No   | Azimuth output by the ranging device, in degrees. The value range is [0, 360).   |
| rssi    | number                           | No   | No   | Received signal strength indicator [RSSI](../../connectivity/terminology.md#rssi), in dBm.    |

## RangingCapabilitySupported

Describes the ranging types supported by the device.

**Since**: 26.0.0

**System capability**: SystemCapability.Communication.FusionConnectivity.Core

**Model restriction**: This API can be used only in the stage model.

| Name         | Type    | Read-Only | Optional | Description                      |
| ---------- | ------ | ---- | ---- | ----------------------- |
| nearlinkHadm | boolean | No   | No   | Whether the NearLink [HADM](../../connectivity/terminology.md#high-accuracy-distance-measurement-hadm)) ranging type is supported. If the value is true, you can call [startRanging](#rangingstartranging) or [startPassiveRanging](#rangingstartpassiveranging) to start ranging. |

## RangingMeasurement

Describes the measurement result, including the measurement value and its confidence.

**Since**: 26.0.0

**System capability**: SystemCapability.Communication.FusionConnectivity.Core

**Model restriction**: This API can be used only in the stage model.

| Name       | Type                                 | Read-Only | Optional | Description             |
| -------- | ---------------------------------- | ---- | ---- | -------------- |
| value    | number                             | No   | No   | Measurement result value. The unit is cm for distance measurement and degree for angle measurement. |
| confidence | [RangingConfidence](#rangingconfidence) | No   | No   | Confidence of the measurement result, indicating the reliability of this measurement value.   |

## RangingTypes

Enumerates the ranging capability types.

**Since**: 26.0.0

**System capability**: SystemCapability.Communication.FusionConnectivity.Core

**Model restriction**: This API can be used only in the stage model.

| Name           | Value   | Description                                        |
| ------------ | ---- | ----------------------------------------- |
| NEARLINK_HADM | 1    | NearLink [HADM](../../connectivity/terminology.md#high-accuracy-distance-measurement-hadm)) ranging type. |

## RangingState

Enumerates the ranging states.

**Since**: 26.0.0

**System capability**: SystemCapability.Communication.FusionConnectivity.Core

**Model restriction**: This API can be used only in the stage model.

| Name           | Value | Description      |
| ------------ | ---- | ------- |
| RANGING_STOPPED | 0   | Ranging stopped. For the stop cause, see [RangingStoppedCause](#rangingstoppedcause). |
| RANGING_STARTED | 1   | Ranging started. Ranging is in progress. |

## RangingStoppedCause

Enumerates the ranging stop causes.

**Since**: 26.0.0

**System capability**: SystemCapability.Communication.FusionConnectivity.Core

**Model restriction**: This API can be used only in the stage model.

| Name              | Value | Description |
| --------------- | ---- | ----- |
| NO_ERROR         | 0 | The ranging is stopped normally without any error. This is usually triggered when the app proactively calls **stopRanging** or **stopPassiveRanging**. |
| INTERNAL_ERROR   | 1 | An internal error occurs, which causes the ranging service to stop. |
| BUSINESS_CONFLICT | 2 | A service conflict occurs, and the ranging stops because other services are occupying the resources. |
| BACKGROUND_PAUSED | 3 | The ranging is paused when the app is switched to the background. The ranging automatically resumes when the app is brought back to the foreground. |

## RangingConfidence

Enumerates the ranging measurement confidences, indicating the reliability of the measurement result.

**Since**: 26.0.0

**System capability**: SystemCapability.Communication.FusionConnectivity.Core

**Model restriction**: This API can be used only in the stage model.

| Name   | Value | Description |
| ------ | ----- | ----------- |
| HIGH   | 0     | High-confidence measurement. The measurement value is highly reliable and can be used directly. |
| MEDIUM | 1     |Medium-confidence measurement. The measurement result is moderately reliable. You are advised to make a comprehensive judgment based on other information. |
| LOW    | 2     | Low-confidence measurement. The measurement result is not reliable. Exercise caution when using the result. |