# @ohos.multimodalAwareness.spatialAwareness (空间感知)(系统接口)
<!--Kit: Multimodal Awareness Kit-->
<!--Subsystem: MultimodalAwareness-->
<!--Owner: @dilligencer-->
<!--Designer: @saga2025-->
<!--Tester: @judan-->
<!--Adviser: @hu-zhiqiong-->

本模块提供对测距的感知能力，支持超声信号测试。

> **说明：**
>
> 本模块首批接口从API version 23开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { spatialAwareness } from '@kit.MultimodalAwarenessKit';
```

## spatialAwareness.TechnologyType

提供输入信号的类型。接口根据输入信号类型，执行对应算法。

**系统能力**：SystemCapability.MultimodalAwareness.DistanceMeasurement

| 名称                | 值   | 说明                    |
| ------------------- | ---- | ----------------------- |
| BLE_RSSI            | 0    | 表示蓝牙强度。      |
| WIFI_RSSI           | 1    | 表示WIFI强度。      |
| ULTRASOUND          | 2    | 表示超声强度。      |
| NEAR_LINK           | 3    | 表示星闪强度。  |
| WIFI_BLE_RSSI       | 4    | 表示WIFI和蓝牙强度。|

## spatialAwareness.ReportingMode

测距接口执行完成后结果的上报模式。

**系统能力**：SystemCapability.MultimodalAwareness.DistanceMeasurement

| 名称                                 | 值   | 说明                   |
| ------------------------------------ | ---- | -----------------------|
| REPORT_MODE_PERIODIC_REPORTING       | 0    | 表示周期性上报。   |
| REPORT_MODE_TRIGGERED_REPORTING      | 1    | 表示触发式上报。       |

## spatialAwareness.DistanceRank

测距结果的距离挡位，不同的挡位对应不同的距离范围。

**系统能力**：SystemCapability.MultimodalAwareness.DistanceMeasurement

| 名称                                 | 值                | 说明                   |
| ------------------------------------ | ------------------| -----------------------|
| RANK_ULTRA_SHORT_RANGE               | rankUltraShort    | 表示超短距。单位：cm，范围：[0:5]。    |
| RANK_SHORT_RANGE                     | rankShort         | 表示短距。单位：cm，范围：(5:100]。     |
| RANK_SHORT_MEDIUM_RANGE              | rankMediumShort   | 表示中短距。单位：cm，范围：(100:500]。 |
| RANK_MEDIUM_RANGE                    | rankMedium        | 表示中距。单位：cm，范围：(500:1000]。  |

## spatialAwareness.DistanceMeasurementResponse

测距接口执行完成后的回调结果。

**系统能力**：SystemCapability.MultimodalAwareness.DistanceMeasurement

| 名称               | 类型            | 只读   | 可选   | 说明     |
| -------------------| ---------------| -------|------  |-------------|
| rank               | DistanceRank   | 是     | 否     | 表示距离档位。|
| distance           | float          | 是     | 否     | 表示距离，结果≥0。|
| confidence         | float          | 是     | 否     | 表示置信度，取值范围：[0,1]。|
| deviceId           | string         | 是     | 否     | 表示设备Id号，字符串长度：[1,128]。|

## spatialAwareness.PositionRelativeToDoor

门内外识别接口返回结果中表示门内或门外位置的枚举。

**系统能力**：SystemCapability.MultimodalAwareness.DistanceMeasurement

| 名称               | 值             | 说明                   |
| -------------------| ---------------| -----------------------|
| OUTDOOR            | 0              | 表示门外。         |
| INDOOR             | 1              | 表示门内。             |

## spatialAwareness.DoorPositionResponse

门内外识别接口执行完成后的回调结果。

**系统能力**：SystemCapability.MultimodalAwareness.DistanceMeasurement

| 名称               | 类型                   | 只读      | 可选       | 说明     |
| -------------------| ----------------------| ----------|----------|--------|
| doorLockCode       | int                   | 是        | 否         | 表示门锁校验码，结果≥0。|
| position           | PositionRelativeToDoor| 是        | 否          | 表示门内外位置信息。|
| deviceId           | string                | 是        | 否         | 表示设备Id号，字符串长度：[1,128]。  |

## spatialAwareness.DistanceMeasurementConfigParams

测距接口的输入参数配置。根据不同的参数配置，执行对应的算法。

**系统能力**：SystemCapability.MultimodalAwareness.DistanceMeasurement

| 名称               |  类型                   | 只读      | 可选       | 说明     |
| -------------------| ----------------------| -----------|------------|----------|
| deviceList         | string[]              | 是         | 否 | 表示设备列表，设备唯一标识符，字符串长度取值范围：[1,128]，数组长度取值范围：[1,128]。|
| techType           | TechnologyType        | 是         | 否 | 表示信号类型。|
| reportMode         | ReportingMode         | 是         | 否  | 表示结果上报模式。|
| reportFrequency    | int                   | 是         | 否  | 表示结果上报频率，单位：Hz，取值范围：[0,999999]。|

## spatialAwareness.onDistanceMeasure<sup>23+</sup>

onDistanceMeasure(configParams: DistanceMeasurementConfigParams, callback: Callback&lt;DistanceMeasurementResponse&gt;): void;

订阅测距接口。触发测距算法执行，并返回测距结果。

**需要权限**：ohos.permission.ACCESS_SENSING_WITH_ULTRASOUND

**系统能力**：SystemCapability.MultimodalAwareness.DistanceMeasurement

**参数**：

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| configParams | DistanceMeasurementConfigParams | 是 | 测距接口配置参数 |
| callback | Callback&lt;[DistanceMeasurementResponse](#spatialawarenessdistancemeasurementresponse)&gt; | 是   | 回调函数，返回测距结果。                                   |

**错误码**：

以下错误码的详细介绍请参见[空间感知错误码](errorcode-spatialAwareness.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. |
| 202      | Not system application. |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities. |
| 35100001 | Service exception. |
| 35100002 | Subscription failed. |
| 35100004 | Parameter invalid. |

**示例**：

```ts
import { spatialAwareness } from '@kit.MultimodalAwarenessKit';
   console.info('call onDistanceMeasure before');
   let configParams: spatialAwareness.DistanceMeasurementConfigParams = {
      deviceList: ["123456"],
      techType: 2,
      reportMode: 0,
      reportFrequency: 340
   };
   console.info('call onDistanceMeasure start');
   try {
      spatialAwareness.onDistanceMeasure(configParams, (data:spatialAwareness.DistanceMeasurementResponse) => {
         console.info(`result = ${data.distance}`);
      });
   } catch (err) {
      console.error(`call onDistanceMeasure failed, Code: ${err.code}, message: ${err.message}`);
   }
```

## spatialAwareness.offDistanceMeasure<sup>23+</sup>

offDistanceMeasure(configParams: DistanceMeasurementConfigParams, callback?: Callback&lt;DistanceMeasurementResponse&gt;): void;

取消订阅测距接口。停止运行已订阅的测距算法。

**需要权限**：ohos.permission.ACCESS_SENSING_WITH_ULTRASOUND

**系统能力**：SystemCapability.MultimodalAwareness.DistanceMeasurement

**参数**：

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| configParams | DistanceMeasurementConfigParams | 是 | 测距接口配置参数 |
| callback | Callback&lt;[DistanceMeasurementResponse](#spatialawarenessdistancemeasurementresponse)&gt; | 否   | 表示取消指定的callback通知。如果输入空、undefined或null，则取消configParams订阅的所有测距通知事件。                                 |

**错误码**：

以下错误码的详细介绍请参见[空间感知错误码](errorcode-spatialAwareness.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. |
| 202      | Not system application. |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities. |
| 35100001 | Service exception. |
| 35100003 | Unsubscription failed. |
| 35100004 | Parameter invalid. |

**示例**：

```ts
import { spatialAwareness } from '@kit.MultimodalAwarenessKit';
   console.info('call offDistanceMeasure before');
   let configParams: spatialAwareness.DistanceMeasurementConfigParams = {
      deviceList: ["123456"],
      techType: 2,
      reportMode: 0,
      reportFrequency: 340
   };
   console.info('call offDistanceMeasure start');
   try {
      spatialAwareness.offDistanceMeasure(configParams, (data:spatialAwareness.DistanceMeasurementResponse) => {
         console.info(`result = ${data.distance}`);
      });
   } catch (err) {
      console.error(`call offDistanceMeasure failed, Code: ${err.code}, message: ${err.message}`);
   }
```

## spatialAwareness.onIndoorOrOutdoorIdentify<sup>23+</sup>

onIndoorOrOutdoorIdentify(configParams: DistanceMeasurementConfigParams, callback: Callback&lt;DoorPositionResponse&gt;): void;

订阅门内外识别接口。触发门内外识别算法执行，并返回设备在门内还是门外的信息。

**需要权限**：ohos.permission.ACCESS_SENSING_WITH_ULTRASOUND

**系统能力**：SystemCapability.MultimodalAwareness.DistanceMeasurement

**参数**：

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| configParams | DistanceMeasurementConfigParams | 是 | 测距接口配置参数 |
| callback | Callback&lt;[DoorPositionResponse](#spatialawarenessdoorpositionresponse)&gt; | 是   | 回调函数，返回门内外信息。                                   |

**错误码**：

以下错误码的详细介绍请参见[空间感知错误码](errorcode-spatialAwareness.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. |
| 202      | Not system application. |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities. |
| 35100001 | Service exception. |
| 35100002 | Subscription failed. |
| 35100004 | Parameter invalid. |

**示例**：

```ts
import { spatialAwareness } from '@kit.MultimodalAwarenessKit';
   console.info('call onIndoorOrOutdoorIdentify before');
   let configParams: spatialAwareness.DistanceMeasurementConfigParams = {
      deviceList: ["123456"],
      techType: 2,
      reportMode: 0,
      reportFrequency: 340
   };
   console.info('call onIndoorOrOutdoorIdentify start');
   try {
      spatialAwareness.onIndoorOrOutdoorIdentify(configParams, (data:spatialAwareness.DoorPositionResponse) => {
         console.info(`result = ${data.position}`);
      });
   } catch (err) {
      console.error(`call onIndoorOrOutdoorIdentify failed, Code: ${err.code}, message: ${err.message}`);
   }
```

## spatialAwareness.offIndoorOrOutdoorIdentify<sup>23+</sup>

offIndoorOrOutdoorIdentify(configParams: DistanceMeasurementConfigParams, callback?: Callback&lt;DoorPositionResponse&gt;): void;

取消订阅门内外识别接口。停止运行已订阅的门内外识别算法。

**需要权限**：ohos.permission.ACCESS_SENSING_WITH_ULTRASOUND

**系统能力**：SystemCapability.MultimodalAwareness.DistanceMeasurement

**参数**：

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| configParams | DistanceMeasurementConfigParams | 是 | 测距接口配置参数 |
| callback | Callback&lt;[DoorPositionResponse](#spatialawarenessdoorpositionresponse)&gt; | 否   | 表示取消指定的callback通知。如果输入空、undefined或null，则取消configParams订阅的所有门内外识别通知事件。                                   |

**错误码**：

以下错误码的详细介绍请参见[空间感知错误码](errorcode-spatialAwareness.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. |
| 202      | Not system application. |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities. |
| 35100001 | Service exception. |
| 35100003 | Unsubscription failed. |
| 35100004 | Parameter invalid. |

**示例**：

```ts
import { spatialAwareness } from '@kit.MultimodalAwarenessKit';
   console.info('call offIndoorOrOutdoorIdentify before');
   let configParams: spatialAwareness.DistanceMeasurementConfigParams = {
      deviceList: ["123456"],
      techType: 2,
      reportMode: 0,
      reportFrequency: 340
   };
   console.info('call offIndoorOrOutdoorIdentify start');
   try {
      spatialAwareness.offIndoorOrOutdoorIdentify(configParams, (data:spatialAwareness.DoorPositionResponse) => {
         console.info(`result = ${data.position}`);
      });
   } catch (err) {
      console.error(`call offIndoorOrOutdoorIdentify failed, Code: ${err.code}, message: ${err.message}`);
   }
```
