# @ohos.test.PerfTest

PerfTest provides white-box performance testing capabilities. It can test performance data of specified code segments or scenarios, automatically execute test code segments, and collect performance data such as time consumption, CPU, memory, latency, and frame rate.

> **NOTE**
> - The initial APIs of this module are supported since API version 20. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs of this module can be used only in <!--RP1-->[arkxtest](../../application-test/arkxtest-guidelines.md)<!--RP1End-->.
> - The APIs of this module do not support concurrent calls.
> - The APIs of this module are applicable to phones, tablets, PCs/2-in-1 devices, smart TVs, and head units.


## Modules to Import

```ts
import { PerfMetric, PerfTest, PerfTestStrategy, PerfMeasureResult } from '@kit.TestKit';
```

## PerfMetric

Represents performance metrics that can be collected by the framework.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Test.PerfTest

| Name      | Value  | Description    |
| ---------- | ---- | -------- |
| DURATION                  | 0 | Execution duration of a code segment, in milliseconds. |
| CPU_LOAD                  | 1 | CPU load of the application process, in percentage. |
| CPU_USAGE                 | 2 | CPU usage of the application process, in percentage. |
| MEMORY_RSS                | 3 | Physical memory (including the shared library) occupied by the application process when a code segment is executed, in KB. |
| MEMORY_PSS                | 4 | Physical memory (excluding the shared library) occupied by the application process when a code segment is executed, in KB. |
| APP_START_RESPONSE_TIME   | 5 | Response latency of application startup, in milliseconds. |
| APP_START_COMPLETE_TIME   | 6 | Completion latency of application startup, in milliseconds. |
| PAGE_SWITCH_COMPLETE_TIME | 7 | Completion latency of page switching in an application, in milliseconds. |
| LIST_SWIPE_FPS            | 8 | List scrolling frame rate in an application, in frames per second (fps).|

> **NOTE**
>
> 1. The preceding metrics collect performance data for a specified application process, not for the system.
> 2. Description of collecting the CPU data (**CPU_LOAD**/**CPU_USAGE**) and memory (**MEMORY_RSS**/**MEMORY_PSS**):
> - During the test, the CPU and memory data of the specified application process is collected before and after the code segment execution. Therefore, ensure that the application process to be tested exists during the test.
> 3. Description of collecting the application startup latency data (**APP_START_RESPONSE_TIME**/**APP_START_COMPLETE_TIME**):
> - Application startup latency data is affected by system log reporting. The start time is when the tap event is reported, the end time of the response latency is when the first frame is displayed on the screen after the tap, and the end time of the completion latency is when the first frame is displayed on the screen after the application is started. The latency is different from what users perceive.
> - Application startup latency data can be collected in the following scenarios: tapping an application icon on the home screen, tapping an application icon on the dock bar, and tapping an application icon in the application center.
> - During a test, only the first startup latency of the specified application is collected.
> 4. Description of collecting the page switching latency data (**PAGE_SWITCH_COMPLETE_TIME**):
> - The page switching latency calculation is affected by the system log reporting. The start time is when the tap event is reported, and the end time is when the first frame is displayed on the screen after the page switching, which is different from what users perceive.
> - Page switching latency data can be collected in the **Router** and **Navigation** components.
> - During a test, only the first page switching latency in the specified application is collected.
> 5. Description of collecting the list scrolling frame rate (**LIST_SWIPE_FPS**):
> - **LIST_SWIPE_FPS**: The number of frames rendered and updated on the screen per second when the list is scrolled.
> - Supported scenarios: list scrolling of the **List**, **Grid**, **Scroll**, and **WaterFlow** components in the ArkUI subsystem.
> - During a test, only the first list scrolling frame rate in the specified application is collected.


## PerfTestStrategy

Represents the performance test strategy.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Test.PerfTest

| Name| Type  | Read-Only|  Optional| Description       |
| ---- | ------ | ---- | ---- |-----------|
| metrics     | Array\<[PerfMetric](#perfmetric)>           | No| No| List of performance metrics to test. |
| actionCode  | Callback\<Callback\<boolean>> | No| No| Code segment to test. |
| resetCode   | Callback\<Callback\<boolean>> | No| Yes| Code segment for resetting the environment after the test is complete. The default value is empty. This code segment is not executed when the framework is running. |
| bundleName  | string                      | No| Yes| Bundle name of the application to test. The default value is "". The framework tests the performance data of the current application. |
| iterations  | number                      | No| Yes| Number of test iterations. The default value is 5. |
| timeout     | number                      | No| Yes| Timeout interval for executing a code segment (**actionCode**/**resetCode**) at a time. The default value is 10,000 ms. |

> **NOTE**
>
> The input parameter type of the **actionCode** and **resetCode** attributes is the **Callback\<boolean>**. You need to call this callback in the code segment to notify the framework that the code segment execution is complete. Otherwise, the code segment execution times out.
> The callback parameter is of the **Boolean** type. The value **true** indicates that the code segment execution meets the expectation, and false indicates the opposite. For details, see [code example](#create)

## PerfMeasureResult

Represents the measurement result data corresponding to the performance metric.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Test.PerfTest

| Name  | Type  | Read-Only| Optional| Description                     |
| ------ | ------ | ---- | ---- | ------------------------- |
| metric        | [PerfMetric](#perfmetric)    | Yes| No| Performance metric to test. |
| roundValues   | Array\<number> | Yes| No| Measurement data value of each round of the tested performance metric. If data collection fails, the value **-1** is returned. |
| maximum       | number        | Yes| No| Maximum value of the measurement data of each round (the value **-1** is excluded). |
| minimum       | number        | Yes| No| Minimum value of the measurement data of each round (the value **-1** is excluded). |
| average       | number        | Yes| No| Average value of the measurement data of each round (the value **-1** is excluded). |


## PerfTest

Represents the general entry of the white-box performance test framework. It provides capabilities such as test task creation, test code segment execution, data collection, and measurement result obtaining.

### create

static create(strategy: PerfTestStrategy): PerfTest

Creates a **PerfTest** object and returns the object created. This API is a static API.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Test.PerfTest

**Parameters**

| Name  | Type  | Mandatory| Description                           |
| -------- | ------ | ---- | ------------------------------- |
| strategy | [PerfTestStrategy](#perfteststrategy) | Yes  | Performance test strategy.|

**Return value**

| Type| Description          |
| -------- | ---------------------- |
| [PerfTest](#perftest)   | **PerfTest** object created.|

**Error codes**

For details about the error codes, see [PerfTest Error Codes](errorcode-perftest.md).

| Error Code| Error Message              |
| -------- | ---------------------- |
| 32400001 | Initialization failed. |
| 32400002 | Internal error. Possible causes: 1. IPC connection failed. 2. The object does not exist. |
| 32400003 | Parameter verification failed. |
| 32400007 | The API does not support concurrent calls. |

**Example**

```ts
import { PerfMetric, PerfTest, PerfTestStrategy } from '@kit.TestKit';

async function demo() {
  let metrics: Array<PerfMetric> = [PerfMetric.DURATION];
  let num = 0;
  let actionCode = async (finish: Callback<boolean>) => { // Define the test code segment. The input parameter type is Callback<boolean> and the name is finish.
    for (let index = 0; index < 10000; index++) {
      num++;
    }
    finish(true); // Call the finish callback to notify that the code segment is executed successfully and as expected.
  }
  let resetCode = async (finish: Callback<boolean>) => {  // Define the code segment for resetting the environment after the test ends.
    num = 0;
    finish(true);
  }
  let perfTestStrategy: PerfTestStrategy = {
    metrics: metrics,
    actionCode: actionCode,
    resetCode: resetCode,
    timeout: 30000,
    iterations: 10,
  };
  let perfTest: PerfTest = PerfTest.create(perfTestStrategy); // Construct a PerfTest object and create a test task.
}
```

### run

run(): Promise\<void>

Runs a performance test, iteratively executes test code segments, and collects performance data. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Test.PerfTest

**Return value**

| Type| Description          |
| -------- | ---------------------- |
| Promise\<void>   | Promise that returns no value.|

**Error codes**

For details about the error codes, see [PerfTest Error Codes](errorcode-perftest.md).

| Error Code| Error Message              |
| -------- | ---------------------- |
| 32400002 | Internal error. Possible causes: 1. IPC connection failed. 2. The object does not exist. |
| 32400004 | Failed to execute the callback. Possible causes: 1. An exception is thrown in the callback. 2. Callback execution timed out.  |
| 32400005 | Failed to collect metric data. |
| 32400007 | The API does not support concurrent calls. |

**Example**

```ts
import { PerfMetric, PerfTest, PerfTestStrategy } from '@kit.TestKit';

async function demo() {
  let metrics: Array<PerfMetric> = [PerfMetric.DURATION];
  let num = 0;
  let actionCode = async (finish: Callback<boolean>) => {
    for (let index = 0; index < 10000; index++) {
      num++;
    }
    finish(true);
  }
  let perfTestStrategy: PerfTestStrategy = {
    metrics: metrics,
    actionCode: actionCode
  };
  let perfTest: PerfTest = PerfTest.create(perfTestStrategy);
  await perfTest.run(); // Run the performance test.
}
```

### getMeasureResult

getMeasureResult(metric: PerfMetric): PerfMeasureResult

Obtains the measurement data of a specified performance metric.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Test.PerfTest

**Parameters**

| Name  | Type  | Mandatory| Description                           |
| -------- | ------ | ---- | ------------------------------- |
| metric | [PerfMetric](#perfmetric) | Yes  | Performance metric.|

**Return value**

| Type| Description          |
| -------- | ---------------------- |
| [PerfMeasureResult](#perfmeasureresult)   | Measurement result data corresponding to the performance metric.|

**Error codes**

For details about the error codes, see [PerfTest Error Codes](errorcode-perftest.md).

| Error Code| Error Message              |
| -------- | ---------------------- |
| 32400002 | Internal error. Possible causes: 1. IPC connection failed. 2. The object does not exist. |
| 32400003 | Parameter verification failed. |
| 32400006 | Failed to obtain the measurement result. |
| 32400007 | The API does not support concurrent calls. |

**Example**

```ts
import { PerfMetric, PerfTest, PerfTestStrategy } from '@kit.TestKit';

async function demo() {
  let metrics: Array<PerfMetric> = [PerfMetric.DURATION];
  let num = 0;
  let actionCode = async (finish: Callback<boolean>) => {
    for (let index = 0; index < 10000; index++) {
      num++;
    }
    finish(true);
  }
  let perfTestStrategy: PerfTestStrategy = {
    metrics: metrics,
    actionCode: actionCode
  };
  let perfTest: PerfTest = PerfTest.create(perfTestStrategy);
  await perfTest.run();
  let res = perfTest.getMeasureResult(PerfMetric.DURATION); // Obtain the measurement data of a specified performance metric.
}
```

### destroy

destroy(): void

Destroys the **PerfTest** object.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Test.PerfTest

**Error codes**

For details about the error codes, see [PerfTest Error Codes](errorcode-perftest.md).

| Error Code| Error Message              |
| -------- | ---------------------- |
| 32400002 | Internal error. Possible causes: 1. IPC connection failed. 2. The object does not exist. |
| 32400007 | The API does not support concurrent calls. |

**Example**

```ts
import { PerfMetric, PerfTest, PerfTestStrategy } from '@kit.TestKit';

async function demo() {
  let metrics: Array<PerfMetric> = [PerfMetric.DURATION];
  let num = 0;
  let actionCode = async (finish: Callback<boolean>) => {
    for (let index = 0; index < 10000; index++) {
      num++;
    }
    finish(true);
  }
  let perfTestStrategy: PerfTestStrategy = {
    metrics: metrics,
    actionCode: actionCode
  };
  let perfTest: PerfTest = PerfTest.create(perfTestStrategy);
  await perfTest.run();
  perfTest.destroy(); // Destroy the PerfTest object.
}
```
