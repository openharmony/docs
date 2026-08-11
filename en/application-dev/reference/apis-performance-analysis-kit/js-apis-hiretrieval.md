# @ohos.hiviewdfx.hiRetrieval (Application Grayscale)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @lyj_love_code-->
<!--Designer: @jiangwenhao-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->

This module provides maintenance and debugging capabilities for application grayscale faults. The following fault types are supported: RSS memory leak, ArkTS-OOM, FD memory leak, and GPU memory leak. The application grayscale feature is an O&M function used to accurately collect fault logs. After you integrate the grayscale function of an application on the device, the application can participate in grayscale activities. You can release an application grayscale task on the cloud platform and select some devices to enable precise fault log collection, helping you quickly locate faults.

**Since:** 26.0.0

## Modules to Import

```ts
import { hiRetrieval } from '@kit.PerformanceAnalysisKit';
```

## HiRetrievalConfig

Configures the application grayscale activity.

**Since:** 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.HiviewDFX.HiRetrieval

| Name| Type| Read-Only| Optional| Description|
| -------- | ------ | -- | ---- | ------- |
| userType | string | No| No| User type. You can customize the value of this parameter. There is no restriction on the format and character type. The value can contain a maximum of 128 characters. If this limit is exceeded, the excess part will be truncated.|
| deviceType | string | No| No| Device type. You can customize the value of this parameter. There is no restriction on the format and character type. The value can contain a maximum of 128 characters. If this limit is exceeded, the excess part will be truncated.|
| deviceModel | string | No| No| Device model. You can customize the value of this parameter. There is no restriction on the format and character type. The value can contain a maximum of 128 characters. If this limit is exceeded, the excess part will be truncated.|

## hiRetrieval.init

init(): void

Initializes the application grayscale module.

**Since:** 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.HiviewDFX.HiRetrieval

**Error codes**

For details about the error codes, see [Application Grayscale Error Codes](errorcode-hiviewdfx-hiretrieval.md).

| ID| Error Message|
| -------- | ----------------------------------------------------------------------------------------------------------------------------------- |
| 36000002 | Multi-instance applications not supported error. Possibly caused by invoking this function in a multi-instance application.         |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { hiRetrieval } from '@kit.PerformanceAnalysisKit';

try {
  hiRetrieval.init();
} catch (err) {
  console.error(`error code: ${(err as BusinessError).code}, error msg: ${(err as BusinessError).message}`);
}
// Other grayscale APIs can be called later.
```

## hiRetrieval.participate

participate(config: HiRetrievalConfig): void

Sets the device to participate in an application grayscale activity. After this API is called, a message indicating that the device participates in the grayscale activity and the application grayscale activity configuration are sent to the server. The server marks the device as selectable and records the application grayscale activity configuration as an algorithm parameter. If this API is called multiple times, the latest application grayscale activity configuration will be used.

**Since:** 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.HiviewDFX.HiRetrieval

**Parameters**

| Name   | Type                     | Mandatory| Description                    |
| --------- | ------------------------- | ---- | ---------------------- |
| config | [HiRetrievalConfig](#hiretrievalconfig) | Yes| Application grayscale activity configuration specified by you.|

**Error codes**

For details about the error codes, see [Application Grayscale Error Codes](errorcode-hiviewdfx-hiretrieval.md).

| ID| Error Message|
| -------- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 36000001 | Initialization error. Possibly caused by invoking this function before invoking init function.                                                  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { hiRetrieval } from '@kit.PerformanceAnalysisKit';

let config: hiRetrieval.HiRetrievalConfig = {
  'userType': "testUserType",
  'deviceType': "deviceType",
  'deviceModel': "deviceModel"
}
try {
  hiRetrieval.init();
  hiRetrieval.participate(config);
} catch (err) {
  console.error(`error code: ${(err as BusinessError).code}, error msg: ${(err as BusinessError).message}`);
}
```

## hiRetrieval.quit

quit(): void

Sets the device to exit an application grayscale activity. After the device exits the activity, it cannot be selected on the cloud.

**Since:** 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.HiviewDFX.HiRetrieval

**Error codes**

For details about the error codes, see [Application Grayscale Error Codes](errorcode-hiviewdfx-hiretrieval.md).

| ID| Error Message|
| -------- | ----------------------------------------------------------------------------------------------- |
| 36000001 | Initialization error. Possibly caused by invoking this function before invoking init function.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { hiRetrieval } from '@kit.PerformanceAnalysisKit';

try {
  hiRetrieval.init();
  hiRetrieval.quit();
} catch (err) {
  console.error(`error code: ${(err as BusinessError).code}, error msg: ${(err as BusinessError).message}`);
}
```

## hiRetrieval.isParticipant

isParticipant(): boolean

Checks whether the device is participating in an application grayscale activity.

**Since:** 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.HiviewDFX.HiRetrieval

**Return value**

| Type               | Description                                                        |
| ------------------- | ----------------------------------------------------------- |
| boolean | Whether the device is participating in a grayscale activity. The value true means **yes** and false means **no**.|

**Example**

```ts
import { hiRetrieval } from '@kit.PerformanceAnalysisKit';

let isParticipant = hiRetrieval.isParticipant();
```

## hiRetrieval.getLastParticipationTimestamp

getLastParticipationTimestamp(): number

Obtains the Unix timestamp when the device last participated in an application grayscale activity. If the device has never participated in the activity, **0** is returned.

**Since:** 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.HiviewDFX.HiRetrieval

**Return value**

| Type               | Description                                                        |
| ------------------- | ------------------------------------------------------------ |
| number | Unix timestamp of the last time the device participated in an application grayscale release activity, in milliseconds.|

**Example**

```ts
import { hiRetrieval } from '@kit.PerformanceAnalysisKit';

let ts = hiRetrieval.getLastParticipationTimestamp();
```

## hiRetrieval.run

run(): void

Runs the application grayscale module if the device is participating in an application grayscale activity. Otherwise, calling this API does not take effect.

**Since:** 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.HiviewDFX.HiRetrieval

**Error codes**

For details about the error codes, see [Application Grayscale Error Codes](errorcode-hiviewdfx-hiretrieval.md).

| ID| Error Message|
| -------- | -------------------------------------------------------------------------------------------------- |
| 36000001 | Initialization error. Possibly caused by invoking this function before invoking init function.     |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { hiRetrieval } from '@kit.PerformanceAnalysisKit';

try {
  hiRetrieval.init();
  hiRetrieval.run();
} catch (err) {
  console.error(`error code: ${(err as BusinessError).code}, error msg: ${(err as BusinessError).message}`);
}
```

## hiRetrieval.getCurrentConfig

getCurrentConfig(): HiRetrievalConfig

Obtains the current configuration of the application grayscale activity.

**Since:** 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.HiviewDFX.HiRetrieval

**Return value**

| Type               | Description                                                        |
| ------------------- | ------------------------------------------------------------ |
| [HiRetrievalConfig](#hiretrievalconfig) | Current configuration of the application grayscale activity.|

**Example**

```ts
import { hiRetrieval } from '@kit.PerformanceAnalysisKit';

let cfg = hiRetrieval.getCurrentConfig();
```
