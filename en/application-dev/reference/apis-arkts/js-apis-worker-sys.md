# @ohos.worker (Starting the Worker) (System API)
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @lijiamin2025-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->

The Worker thread is an independent thread running in parallel with the main thread. The thread that creates the Worker thread is referred to as the host thread. The URL file passed in during worker creation is executed in the Worker thread. The Worker thread can process time-consuming operations, but cannot directly operate the UI.

With the Worker module, you can provide a multithreaded environment for an application, so that the application can perform a time-consuming operation in a background thread. This greatly prevents a computing-intensive or high-latency task from blocking the running of the host thread. A Worker instance will not be proactively destroyed once it is created. It consumes resources to keep running. Therefore, you should call the API to terminate it in a timely manner.

The Context object of the Worker thread is different from that of the UI main thread. The Worker thread does not support UI operations.

For details about the precautions for using Worker, see [Precautions for Worker](../../arkts-utils/worker-introduction.md#precautions-for-worker).

> **NOTE**
>
> - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.worker (Starting the Worker)](js-apis-worker.md).

## Modules to Import

```ts
import { worker } from '@kit.ArkTS';
```

## RestrictedWorker<sup>11+</sup>

The RestrictedWorker class inherits [ThreadWorker<sup>9+</sup>](js-apis-worker.md#threadworker9) and supports all APIs in ThreadWorker.
RestrictedWorker provides a restricted environment for running the Worker thread. In this environment, only the Worker module can be imported.

### constructor<sup>11+</sup>

constructor(scriptURL: string, options?: WorkerOptions)

A constructor used to create a RestrictedWorker instance. Before using the following APIs, you must create a RestrictedWorker instance.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System API**: This is a system API.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type                           | Mandatory| Description                                                        |
| --------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| scriptURL | string                          | Yes  | URL of the Worker thread file. For details about the rules, see [Precautions for File URLs](../../arkts-utils/worker-introduction.md#precautions-for-file-urls).|
| options   | [WorkerOptions](js-apis-worker.md#workeroptions) | No  | Options that can be set for the RestrictedWorker instance.                                          |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200003 | Worker initialization failure. |
| 10200007 | The worker file patch is invalid path. |

**Example**

The following code snippet shows how to load the Worker thread file of the ability in the stage model. For details about how to use the library to load the Worker thread file, see [Precautions for File URLs](../../arkts-utils/worker-introduction.md#precautions-for-file-urls).

Only the Worker module can be imported to the restricted Worker thread file. Other APIs cannot be imported. The following is sample code:

```ts
import { worker } from '@kit.ArkTS';

// Two scenarios are involved.

// Scenario 1: URL of the Worker thread file: "entry/src/main/ets/workers/worker.ets"
const workerStageModel01 = new worker.RestrictedWorker('entry/ets/workers/worker.ets', {name:"first worker in Stage model"});

// Scenario 2: URL of the Worker thread file: "testworkers/src/main/ets/ThreadFile/workers/worker.ets"
const workerStageModel02 = new worker.RestrictedWorker('testworkers/ets/ThreadFile/workers/worker.ets');
```

```ts
// Restricted Worker thread file
import { worker, MessageEvents } from '@kit.ArkTS';

//import { process } from '@kit.ArkTS'; // Only worker APIs can be imported to the restricted Worker thread file.

const workerPort = worker.workerPort;

workerPort.onmessage = (e : MessageEvents) : void => {
  console.info("worker:: This is worker thread.");
  // console.info("worker:: worker tid: "+ process.tid) // Run process.tid. The host thread reports the corresponding error.
}
```
