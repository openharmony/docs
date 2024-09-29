# @ohos.worker (Starting the Worker)

The worker thread is an independent thread running in parallel with the main thread. The thread that creates the worker thread is referred to as the host thread. The URL file passed in during worker creation is executed in the worker thread. The worker thread can process time-consuming operations, but cannot directly operate the UI.

With the **Worker** module, you can provide a multithreading environment for an application, so that the application can perform a time-consuming operation in a background thread. This greatly prevents a computing-intensive or high-latency task from blocking the running of the main thread. A **Worker** instance will not be proactively destroyed once it is created. It consumes resources to keep running. Therefore, you should call the API to terminate it in a timely manner.

The **Context** object of the worker thread is different from that of the main thread. The worker thread does not support UI operations.

For details about the precautions for using **Worker**, see [Precautions for Worker](../../arkts-utils/worker-introduction.md#precautions-for-worker).

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { worker } from '@kit.ArkTS';
```


## Attributes

**System capability**: SystemCapability.Utils.Lang

| Name                             | Type                                                        | Readable| Writable| Description                                                        |
| --------------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| workerPort<sup>9+</sup>           | [ThreadWorkerGlobalScope](#threadworkerglobalscope9)         | Yes  | Yes  | Object of the worker thread used to communicate with the host thread. **Atomic service API**: This API can be used in atomic services since API version 11.                        |
| parentPort<sup>(deprecated)</sup> | [DedicatedWorkerGlobalScope](#dedicatedworkerglobalscopedeprecated) | Yes  | Yes  | Object of the worker thread used to communicate with the host thread.<br>This attribute is supported since API version 7 and deprecated since API version 9.<br>You are advised to use **workerPort<sup>9+</sup>** instead.|


## WorkerOptions

Provides options that can be set for the **Worker** instance to create.

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Read-only| Optional| Description|
| ---- | -------- | ---- | ---- | -------------- |
| type | "classic" \| "module" | Yes  | Yes| Mode in which the **Worker** instance executes the script. The **module** type is not supported yet. The default value is **classic**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| name | string   | Yes  | Yes| Name of the worker thread. The default value is **undefined**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| shared | boolean | Yes  | Yes| Whether sharing of the **Worker** instance is enabled. Currently, sharing is not supported.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

## ThreadWorker<sup>9+</sup>

Before using the following APIs, you must create a **ThreadWorker** instance. The **ThreadWorker** class inherits from [WorkerEventTarget](#workereventtarget9).

### constructor<sup>9+</sup>

constructor(scriptURL: string, options?: WorkerOptions)

A constructor used to create a **ThreadWorker** instance.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type                           | Mandatory| Description                                                        |
| --------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| scriptURL | string                          | Yes  | URL of the worker thread file.<br>For details about the rules, see [Precautions for File URLs](../../arkts-utils/worker-introduction.md#precautions-for-file-urls).|
| options   | [WorkerOptions](#workeroptions) | No  | Options that can be set for the **Worker** instance.                                          |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200003 | Worker initialization failed. |
| 10200007 | The worker file path is invalid. |

**Example**

The following code snippet shows how to load the worker thread file of the ability in the stage model. For details about how to use the library to load the worker thread file, see [Precautions for File URLs](../../arkts-utils/worker-introduction.md#precautions-for-file-urls).

```ts
import { worker } from '@kit.ArkTS';

// Two scenarios are involved.

// Scenario 1: URL of the worker thread file: "entry/src/main/ets/workers/worker.ets"
const workerStageModel01 = new worker.ThreadWorker('entry/ets/workers/worker.ets', {name:"first worker in Stage model"});

// Scenario 2: URL of the worker thread file: "phone/src/main/ets/ThreadFile/workers/worker.ets"
const workerStageModel02 = new worker.ThreadWorker('phone/ets/ThreadFile/workers/worker.ets');
```


### postMessage<sup>9+</sup>

postMessage(message: Object, transfer: ArrayBuffer[]): void

Sends a message from the host thread to the worker thread by transferring object ownership.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type         | Mandatory| Description                                                        |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| message  | Object        | Yes  | Data to be sent to the worker thread. The data object must be sequenceable. For details about the supported parameter types, see [Sequenceable Data Types](#sequenceable-data-types).|
| transfer | ArrayBuffer[] | Yes  | **ArrayBuffer** instance holding an array of objects for which the ownership is transferred to the worker thread. After the transfer, the objects are available only in the worker thread. The array cannot be null.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                               |
| -------- | ----------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200004 | The Worker instance is not running.           |
| 10200006 | An exception occurred during serialization. |

**Example**

```ts
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ets");

let buffer = new ArrayBuffer(8);
workerInstance.postMessage(buffer, [buffer]);
```

### postMessage<sup>9+</sup>

postMessage(message: Object, options?: PostMessageOptions): void

Sends a message from the host thread to the worker thread by transferring object ownership or copying data.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type                                     | Mandatory| Description                                                        |
| ------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| message | Object                                    | Yes  | Data to be sent to the worker thread. The data object must be sequenceable. For details about the supported parameter types, see [Sequenceable Data Types](#sequenceable-data-types).|
| options | [PostMessageOptions](#postmessageoptions) | No  | If this parameter is specified, it functions the same as **ArrayBuffer[]**. Specifically, the ownership of the objects in the array is transferred to the worker thread and becomes unavailable in the host thread. The objects are available only in the worker thread.<br>If this parameter is not specified, the default value **undefined** is used, and information is transferred to the worker thread by copying data.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                               |
| -------- | ----------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200004 | The Worker instance is not running.           |
| 10200006 | An exception occurred during serialization. |

**Example**

```ts
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ets");

workerInstance.postMessage("hello world");

let buffer = new ArrayBuffer(8);
workerInstance.postMessage(buffer, [buffer]);
```


### postMessageWithSharedSendable<sup>12+</sup>

postMessageWithSharedSendable(message: Object, transfer?: ArrayBuffer[]): void

Sends a message from the host thread to the worker thread. In the message, a sendable object is passed by reference, and a non-sendable object is passed by serialization.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type                                     | Mandatory| Description                                                        |
| --------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| message   | Object	     | Yes  | Data to be sent to the worker thread. The data object must be sequenceable or sendable. For details about the supported sequenceable types, see [Sequenceable Data Types](#sequenceable-data-types). For details about the supported sendable types, see [Sendable Data Types](../../arkts-utils/arkts-sendable.md#sendable-data).|
| transfer  | ArrayBuffer[] | No  | **ArrayBuffer** instance holding an array of objects for which the ownership is transferred to the worker thread. After the transfer, the objects are available only in the worker thread. The array cannot be null. The default value is an empty array.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                               |
| -------- | ----------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200004 | The Worker instance is not running.           |
| 10200006 | An exception occurred during serialization. |

**Example**

<!--code_no_check-->
```ts
// index.ets
// Create a SendableObject instance and pass it to the worker thread through the host thread.

import { worker } from '@kit.ArkTS';
import { SendableObject } from './sendable'

const workerInstance = new worker.ThreadWorker("entry/ets/workers/Worker.ets");
let object: SendableObject = new SendableObject();
workerInstance.postMessageWithSharedSendable(object);
```

```ts
// sendable.ets
// Define SendableObject.

@Sendable
export class SendableObject {
  a:number = 45;
}
```

<!--code_no_check-->
```ts
// The worker file path is entry/src/main/ets/workers/Worker.ets.
// Worker.ets
// Receive and access the data passed from the host thread to the worker thread.

import { SendableObject } from '../pages/sendable'
import { worker, ThreadWorkerGlobalScope, MessageEvents, ErrorEvent } from '@kit.ArkTS';

const workerPort: ThreadWorkerGlobalScope = worker.workerPort;
workerPort.onmessage = (e: MessageEvents) => {
  let obj: SendableObject = e.data;
  console.info("sendable obj is: " + obj.a);
}
```


### on<sup>9+</sup>

on(type: string, listener: WorkerEventListener): void

Adds an event listener for the worker thread. This API provides the same functionality as [addEventListener<sup>9+</sup>](#addeventlistener9).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type                                        | Mandatory| Description                  |
| -------- | -------------------------------------------- | ---- | ---------------------- |
| type     | string                                       | Yes  | Type of the event to listen for.      |
| listener | [WorkerEventListener](#workereventlistener9) | Yes| Callback to invoke when an event of the specified type occurs.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                  |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200004 | Worker instance is not running.              |
| 10200005 | The invoked API is not supported in workers. |

**Example**

```ts
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ets");
workerInstance.on("alert", (e)=>{
    console.log("alert listener callback");
})
```


### once<sup>9+</sup>

once(type: string, listener: WorkerEventListener): void

Adds an event listener for the worker thread and removes the event listener after it is invoked once.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type                                        | Mandatory| Description                  |
| -------- | -------------------------------------------- | ---- | ---------------------- |
| type     | string                                       | Yes  | Type of the event to listen for.      |
| listener | [WorkerEventListener](#workereventlistener9) | Yes| Callback to invoke when an event of the specified type occurs.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                  |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200004 | Worker instance is not running.              |
| 10200005 | The invoked API is not supported in workers. |

**Example**

```ts
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ets");
workerInstance.once("alert", (e)=>{
    console.log("alert listener callback");
})
```


### off<sup>9+</sup>

off(type: string, listener?: WorkerEventListener): void

Removes an event listener for the worker thread. This API provides the same functionality as [removeEventListener<sup>9+</sup>](#removeeventlistener9).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type                                        | Mandatory| Description                        |
| -------- | -------------------------------------------- | ---- | ---------------------------- |
| type     | string                                       | Yes  | Type of the event for which the event listener is to be removed.        |
| listener | [WorkerEventListener](#workereventlistener9) | No| Callback to invoke when the listener is removed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                  |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200004 | Worker instance is not running.              |
| 10200005 | The invoked API is not supported in workers. |

**Example**

```ts
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ets");
// Use on, once, or addEventListener to add a listener for the "alert" event, and use off to remove the listener.
workerInstance.off("alert");
```

### registerGlobalCallObject<sup>11+</sup>

registerGlobalCallObject(instanceName: string, globalCallObject: Object): void

Registers an object with the **ThreadWorker** instance of the host thread. In this way, the methods of the object can be called in the worker thread through [callGlobalCallObjectMethod](#callglobalcallobjectmethod11).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type         | Mandatory| Description                                                        |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| instanceName  | string        | Yes  | Key used for registration, based on which the registered object is identified during method calling.|
| globalCallObject | Object | Yes  | Object to register. The **ThreadWorker** instance holds a strong reference to the object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                               |
| -------- | ----------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200004 | Worker instance is not running.           |

**Example**
```ts
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ets");
class TestObj {
  private message : string = "this is a message from TestObj"
  public getMessage() : string {
    return this.message;
  }
  public getMessageWithInput(str : string) : string {
    return this.message + " with input: " + str;
  }
}
let registerObj = new TestObj();
// Register registerObj with the ThreadWorker instance.
workerInstance.registerGlobalCallObject("myObj", registerObj);
workerInstance.postMessage("start worker")
```

### unregisterGlobalCallObject<sup>11+</sup>

unregisterGlobalCallObject(instanceName?: string): void

Unregisters an object with the **ThreadWorker** instance of the host thread. This API releases the strong reference between the ThreadWorker instance and the target object. No error is reported if no object is matched.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type         | Mandatory| Description                                                        |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| instanceName  | string        | No  | Key used for registration. If this parameter is left blank, all registered objects registered in the **ThreadWorker** instance are unregistered.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                               |
| -------- | ----------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200004 | Worker instance is not running. |

**Example**
```ts
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ets");
class TestObj {
  private message : string = "this is a message from TestObj"
  public getMessage() : string {
    return this.message;
  }
  public getMessageWithInput(str : string) : string {
    return this.message + " with input: " + str;
  }
}
let registerObj = new TestObj();
workerInstance.registerGlobalCallObject("myObj", registerObj);
// Unregister the object.
workerInstance.unregisterGlobalCallObject("myObj");
// Unregister all objects from the ThreadWorker instance.
//workerInstance.unregisterGlobalCallObject();
workerInstance.postMessage("start worker")
```

### terminate<sup>9+</sup>

terminate(): void

Terminates the worker thread to stop it from receiving messages.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                     |
| -------- | ------------------------------- |
| 10200004 | The Worker instance is not running. |

**Example**

```ts
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ets");
workerInstance.terminate();
```


### onexit<sup>9+</sup>

onexit?: (code: number) =&gt; void

Called when the worker thread exits. The event handler is executed in the host thread. In the callback function, the **code** value is of the number type, where the value **1** indicates abnormal exit and **0** indicates normal exit.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                  |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 10200004 | The Worker instance is not running.              |
| 10200005 | The called API is not supported in the worker thread. |

**Example**

```ts
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ets");
workerInstance.onexit = (code) => {
 console.log("onexit");
}

// onexit is executed in either of the following ways:
// Main thread
workerInstance.terminate();

// Worker thread
//workerPort.close()
```


### onerror<sup>9+</sup>

onerror?: (err: ErrorEvent) =&gt; void

Called when an exception occurs during worker execution. The event handler is executed in the host thread. In the callback function, the **err** type is [ErrorEvent](#errorevent), indicating the received abnormal data.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                  |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 10200004 | The Worker instance is not running.              |
| 10200005 | The called API is not supported in the worker thread. |

**Example**

```ts
import { worker, ErrorEvent } from '@kit.ArkTS';

const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ets");
workerInstance.onerror = (err: ErrorEvent) => {
  console.log("onerror" + err.message);
}
```


### onmessage<sup>9+</sup>

onmessage?: (event: MessageEvents) =&gt; void

Called when the host thread receives a message sent by the worker thread through **workerPort.postMessage**. The event handler is executed in the host thread. In the callback function, the **event** type is [MessageEvents](#messageevents9), indicating the received message data.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                  |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 10200004 | The Worker instance is not running.              |
| 10200005 | The called API is not supported in the worker thread. |

**Example**

```ts
import { worker, MessageEvents } from '@kit.ArkTS';

const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ets");
workerInstance.onmessage = (e: MessageEvents): void => {
 // e: MessageEvents. The usage is as follows:
 // let data = e.data;
 console.log("onmessage");
}
```


### onmessageerror<sup>9+</sup>

onmessageerror?: (event: MessageEvents) =&gt; void

Called when the worker thread receives a message that cannot be serialized. The event handler is executed in the host thread. In the callback function, the **event** type is [MessageEvents](#messageevents9), indicating the received message data.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                  |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 10200004 | The Worker instance is not running.              |
| 10200005 | The called API is not supported in the worker thread. |

**Example**

```ts
import { worker, MessageEvents } from '@kit.ArkTS';

const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ets");
workerInstance.onmessageerror = (err: MessageEvents) => {
  console.log("onmessageerror");
}
```

### addEventListener<sup>9+</sup>

addEventListener(type: string, listener: WorkerEventListener): void

Adds an event listener for the worker thread. This API provides the same functionality as [on<sup>9+</sup>](#on9).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type                                        | Mandatory| Description            |
| -------- | -------------------------------------------- | ---- | ---------------- |
| type     | string                                       | Yes  | Type of the event to listen for.|
| listener | [WorkerEventListener](#workereventlistener9) | Yes  | Callback to invoke when an event of the specified type occurs.    |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                  |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200004 | Worker instance is not running.              |
| 10200005 | The invoked API is not supported in workers. |

**Example**

```ts
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ets");
workerInstance.addEventListener("alert", (e)=>{
    console.log("alert listener callback");
})
```


### removeEventListener<sup>9+</sup>

removeEventListener(type: string, callback?: WorkerEventListener): void

Removes an event listener for the worker thread. This API provides the same functionality as [off<sup>9+</sup>](#off9).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type                                        | Mandatory| Description                        |
| -------- | -------------------------------------------- | ---- | ---------------------------- |
| type     | string                                       | Yes  | Type of the event for which the event listener is to be removed.    |
| callback | [WorkerEventListener](#workereventlistener9) | No| Callback to invoke when the listener is removed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                     |
| -------- | ------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200004 | Worker instance is not running. |

**Example**

```ts
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ets");
workerInstance.addEventListener("alert", (e)=>{
    console.log("alert listener callback");
})
workerInstance.removeEventListener("alert");
```


### dispatchEvent<sup>9+</sup>

dispatchEvent(event: Event): boolean

Dispatches the event defined for the worker thread.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description            |
| ------ | --------------- | ---- | ---------------- |
| event  | [Event](#event) | Yes  | Event to dispatch.|

**Return value**

| Type   | Description                           |
| ------- | ------------------------------- |
| boolean | Returns **true** if the event is dispatched; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                     |
| -------- | ------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200004 | Worker instance is not running. |

**Example**

```ts
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ets");

workerInstance.dispatchEvent({type:"eventType", timeStamp:0}); // timeStamp is not supported yet.
```

The **dispatchEvent** API can be used together with the **on**, **once**, and **addEventListener** APIs. The sample code is as follows:

```ts
import { worker, MessageEvents } from '@kit.ArkTS';

const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ets");

// Usage 1:
workerInstance.on("alert_on", (e)=>{
    console.log("alert listener callback");
})
workerInstance.once("alert_once", (e)=>{
    console.log("alert listener callback");
})
workerInstance.addEventListener("alert_add", (e)=>{
    console.log("alert listener callback");
})

// The event listener created by once is removed after being executed once.
workerInstance.dispatchEvent({type:"alert_once", timeStamp:0});// timeStamp is not supported yet.
// The event listener created by on will not be proactively deleted.
workerInstance.dispatchEvent({type:"alert_on", timeStamp:0});
workerInstance.dispatchEvent({type:"alert_on", timeStamp:0});
// The event listener created by addEventListener will not be proactively deleted.
workerInstance.dispatchEvent({type:"alert_add", timeStamp:0});
workerInstance.dispatchEvent({type:"alert_add", timeStamp:0});

// Usage 2:
// The event type can be customized, and the special types "message", "messageerror", and "error" exist.
// When type = "message", the event handler defined by onmessage will also be executed.
// When type = "messageerror", the event handler defined by onmessageerror will also be executed.
// When type = "error", the event handler defined by onerror will also be executed.
// removeEventListener or off can be used to remove an event listener that is created by addEventListener, on, or once.

workerInstance.addEventListener("message", (e)=>{
    console.log("message listener callback");
})
workerInstance.onmessage = (e: MessageEvents): void => {
    console.log("onmessage : message listener callback");
}
// When dispatchEvent is called to distribute the "message" event, the callback passed in addEventListener and onmessage will be invoked.
workerInstance.dispatchEvent({type:"message", timeStamp:0});
```


### removeAllListener<sup>9+</sup>

removeAllListener(): void

Removes all event listeners for the worker thread.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                     |
| -------- | ------------------------------- |
| 10200004 | Worker instance is not running. |

**Example**

```ts
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ets");
workerInstance.addEventListener("alert", (e)=>{
    console.log("alert listener callback");
})
workerInstance.removeAllListener();
```

## WorkerEventTarget<sup>9+</sup>

Processes worker listening events.

### addEventListener<sup>9+</sup>

addEventListener(type: string, listener: WorkerEventListener): void

Adds an event listener for the worker thread. This API provides the same functionality as [on<sup>9+</sup>](#on9).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type                                        | Mandatory| Description            |
| -------- | -------------------------------------------- | ---- | ---------------- |
| type     | string                                       | Yes  | Type of the event to listen for.|
| listener | [WorkerEventListener](#workereventlistener9) | Yes  | Callback to invoke when an event of the specified type occurs.    |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                  |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200004 | The Worker instance is not running.              |
| 10200005 | The called API is not supported in the worker thread. |

**Example**

```ts
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ets");
workerInstance.addEventListener("alert", (e)=>{
    console.log("alert listener callback");
})
```


### removeEventListener<sup>9+</sup>

removeEventListener(type: string, callback?: WorkerEventListener): void

Removes an event listener for the worker thread. This API provides the same functionality as [off<sup>9+</sup>](#off9).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type                                        | Mandatory| Description                        |
| -------- | -------------------------------------------- | ---- | ---------------------------- |
| type     | string                                       | Yes  | Type of the event for which the event listener is to be removed.    |
| callback | [WorkerEventListener](#workereventlistener9) | No| Callback to invoke when the listener is removed.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                     |
| -------- | ------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200004 | The Worker instance is not running. |

**Example**

```ts
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ets");
workerInstance.addEventListener("alert", (e)=>{
    console.log("alert listener callback");
})
workerInstance.removeEventListener("alert");
```


### dispatchEvent<sup>9+</sup>

dispatchEvent(event: Event): boolean

Dispatches the event defined for the worker thread.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description            |
| ------ | --------------- | ---- | ---------------- |
| event  | [Event](#event) | Yes  | Event to dispatch.|

**Return value**

| Type   | Description                           |
| ------- | ------------------------------- |
| boolean | Returns **true** if the event is dispatched successfully; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                     |
| -------- | ------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200004 | The Worker instance is not running. |

**Example**

```ts
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ets");

workerInstance.dispatchEvent({type:"eventType", timeStamp:0}); // timeStamp is not supported yet.
```

The **dispatchEvent** API can be used together with the **on**, **once**, and **addEventListener** APIs. The sample code is as follows:

```ts
import { worker, MessageEvents } from '@kit.ArkTS';

const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ets");

// Usage 1:
workerInstance.on("alert_on", (e)=>{
    console.log("alert listener callback");
})
workerInstance.once("alert_once", (e)=>{
    console.log("alert listener callback");
})
workerInstance.addEventListener("alert_add", (e)=>{
    console.log("alert listener callback");
})

// The event listener created by once is removed after being executed once.
workerInstance.dispatchEvent({type:"alert_once", timeStamp:0});// timeStamp is not supported yet.
// The event listener created by on will not be proactively deleted.
workerInstance.dispatchEvent({type:"alert_on", timeStamp:0});
workerInstance.dispatchEvent({type:"alert_on", timeStamp:0});
// The event listener created by addEventListener will not be proactively deleted.
workerInstance.dispatchEvent({type:"alert_add", timeStamp:0});
workerInstance.dispatchEvent({type:"alert_add", timeStamp:0});

// Usage 2:
// The event type can be customized, and the special types "message", "messageerror", and "error" exist.
// When type = "message", the event handler defined by onmessage will also be executed.
// When type = "messageerror", the event handler defined by onmessageerror will also be executed.
// When type = "error", the event handler defined by onerror will also be executed.
// removeEventListener or off can be used to remove an event listener that is created by addEventListener, on, or once.

workerInstance.addEventListener("message", (e)=>{
    console.log("message listener callback");
})
workerInstance.onmessage = (e: MessageEvents): void => {
    console.log("onmessage : message listener callback");
}
// When dispatchEvent is called to distribute the "message" event, the callback passed in addEventListener and onmessage will be invoked.
workerInstance.dispatchEvent({type:"message", timeStamp:0});
```


### removeAllListener<sup>9+</sup>

removeAllListener(): void

Removes all event listeners for the worker thread.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                     |
| -------- | ------------------------------- |
| 10200004 | The Worker instance is not running. |

**Example**

```ts
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ets");
workerInstance.addEventListener("alert", (e)=>{
    console.log("alert listener callback");
})
workerInstance.removeAllListener();
```


## ThreadWorkerGlobalScope<sup>9+</sup>

Implements communication between the worker thread and the host thread. The **postMessage** API is used to send messages to the host thread, and the **close** API is used to terminate the worker thread. The **ThreadWorkerGlobalScope** class inherits from [GlobalScope<sup>9+</sup>](#globalscope9).

### postMessage<sup>9+</sup>

postMessage(messageObject: Object, transfer: ArrayBuffer[]): void;

Sends a message from the worker thread to the host thread by transferring object ownership.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type         | Mandatory| Description                                                        |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| messageObject  | Object        | Yes  | Data to be sent to the host thread. The data object must be sequenceable. For details about the supported parameter types, see [Sequenceable Data Types](#sequenceable-data-types).|
| transfer | ArrayBuffer[] | Yes  | **ArrayBuffer** instance holding an array of objects for which the ownership is transferred to the host thread. After the transfer, the objects are available only in the host thread. The array cannot be null.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                               |
| -------- | ----------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200004 | The Worker instance is not running.           |
| 10200006 | An exception occurred during serialization. |

**Example**

```ts
// Main thread
import { worker, MessageEvents } from '@kit.ArkTS';

const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ets");
workerInstance.postMessage("hello world");
workerInstance.onmessage = (e: MessageEvents): void => {
    console.log("receive data from worker.ets");
}
```

```ts
// worker.ets
import { worker, MessageEvents } from '@kit.ArkTS';

const workerPort = worker.workerPort;
workerPort.onmessage = (e: MessageEvents): void => {
    let buffer = new ArrayBuffer(8);
    workerPort.postMessage(buffer, [buffer]);
}
```

### postMessage<sup>9+</sup>

postMessage(messageObject: Object, options?: PostMessageOptions): void

Sends a message from the worker thread to the host thread by transferring object ownership or copying data.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type                                     | Mandatory| Description                                                        |
| ------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| messageObject | Object                                    | Yes  | Data to be sent to the host thread. The data object must be sequenceable. For details about the supported parameter types, see [Sequenceable Data Types](#sequenceable-data-types).|
| options | [PostMessageOptions](#postmessageoptions) | No  | If this parameter is specified, it functions the same as **ArrayBuffer[]**. Specifically, the ownership of the objects in the array is transferred to the host thread and becomes unavailable in the worker thread. The objects are available only in the host thread.<br>If this parameter is not specified, the default value **undefined** is used, and information is transferred to the host thread by copying data.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                               |
| -------- | ----------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200004 | The Worker instance is not running.           |
| 10200006 | An exception occurred during serialization. |

**Example**

```ts
// Main thread
import { worker, MessageEvents } from '@kit.ArkTS';

const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ets");
workerInstance.postMessage("hello world");
workerInstance.onmessage = (e: MessageEvents): void => {
    console.log("receive data from worker.ets");
}
```

```ts
// worker.ets
import { worker, MessageEvents } from '@kit.ArkTS';

const workerPort = worker.workerPort;
workerPort.onmessage = (e: MessageEvents): void => {
    workerPort.postMessage("receive data from main thread");
}
```


### postMessageWithSharedSendable<sup>12+</sup>

postMessageWithSharedSendable(message: Object, transfer?: ArrayBuffer[]): void

Sends a message from the worker thread to the host thread. In the message, a sendable object is passed by reference, and a non-sendable object is passed by serialization.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type                                     | Mandatory| Description                                                        |
| --------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| message   | Object	     | Yes  | Data to be sent to the host thread. The data object must be sequenceable or sendable. For details about the supported sequenceable types, see [Sequenceable Data Types](#sequenceable-data-types). For details about the supported sendable types, see [Sendable Data Types](../../arkts-utils/arkts-sendable.md#sendable-data).|
| transfer  | ArrayBuffer[] | No  | **ArrayBuffer** instance holding an array of objects for which the ownership is transferred to the host thread. After the transfer, the objects are available only in the host thread. The array cannot be null. The default value is an empty array.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                               |
| -------- | ----------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200004 | The Worker instance is not running.           |
| 10200006 | An exception occurred during serialization. |

**Example**

<!--code_no_check-->
```ts
// The worker file path is entry/src/main/ets/workers/Worker.ets.
// Worker.ets
// Create a SendableObject instance and pass it to the host thread through the worker thread.

import { SendableObject } from '../pages/sendable'
import { worker, ThreadWorkerGlobalScope, MessageEvents, ErrorEvent } from '@kit.ArkTS';

const workerPort: ThreadWorkerGlobalScope = worker.workerPort;
workerPort.onmessage = (e: MessageEvents) => {
  let object: SendableObject = new SendableObject();
  workerPort.postMessageWithSharedSendable(object);
}
```

```ts
// sendable.ets
// Define SendableObject.

@Sendable
export class SendableObject {
  a:number = 45;
}
```

<!--code_no_check-->
```ts
// Index.ets
// Receive the data passed from the worker thread to the host thread and access its properties.

import { worker, MessageEvents } from '@kit.ArkTS';
import { SendableObject } from './sendable'

const workerInstance = new worker.ThreadWorker("entry/ets/workers/Worker.ets");
workerInstance.postMessage(1);
workerInstance.onmessage = (e: MessageEvents) => {
  let obj: SendableObject = e.data;
  console.info("sendable index obj is: " + obj.a);
}
```


### callGlobalCallObjectMethod<sup>11+</sup>

callGlobalCallObjectMethod(instanceName: string, methodName: string, timeout: number, ...args: Object[]): Object

Calls a method of an object registered with the host thread. This API is called by the worker thread. The invoking is synchronous for the worker thread and asynchronous for the host thread. The return value is transferred through serialization.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type                                     | Mandatory| Description                                                        |
| ------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| instanceName | string                                    | Yes  | Key used for registration. It is used to search for the object in the host thread.|
| methodName | string | Yes| Name of the method to call. Note that the method cannot be modified by async or generator, or return results asynchronously by using the asynchronous mechanism at the bottom layer. Otherwise, an exception is thrown.|
| timeout | number | Yes| Maximum duration that the current synchronous invoking waits, in ms. The value is an integer ranging from 1 to 5000. The value **0** means that the 5000 ms duration is used.|
| args | Object[] | No| Array of parameters in the method.|

**Return value**

| Type                                 | Description                           |
| ------------------------------------- | ------------------------------- |
| Object | Return value of the method in the host thread. The return value must be serializable. For details, see [Sequenceable Data Types](#sequenceable-data-types).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                               |
| -------- | ----------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200004 | Worker instance is not running.           |
| 10200006 | An exception occurred during serialization. |
| 10200019 | The globalCallObject is not registered. |
| 10200020 | The method to be called is not callable or is an async method or a generator. |
| 10200021 | The global call exceeds the timeout. |

**Example**
```ts
// worker.ets
import { worker, MessageEvents } from '@kit.ArkTS';

const workerPort = worker.workerPort;
workerPort.onmessage = (e: MessageEvents): void => {
  try {
    // The method to call does not carry an input parameter.
    let res : string = workerPort.callGlobalCallObjectMethod("myObj", "getMessage", 0) as string;
    console.info("worker:", res) // worker: this is a message from TestObj
  } catch (error) {
    // Exception handling.
    console.error("worker: error code is " + error.code + " error message is " + error.message);
  }
  try {
    // The method to call carries input parameters.
    let res : string = workerPort.callGlobalCallObjectMethod("myObj", "getMessageWithInput", 0, "hello there!") as string;
    console.info("worker:", res) //worker: this is a message from TestObj with input: hello there!
  } catch (error) {
    // Exception handling.
    console.error("worker: error code is " + error.code + " error message is " + error.message);
  }
}
```

### close<sup>9+</sup>

close(): void

Terminates the worker thread to stop it from receiving messages.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                     |
| -------- | ------------------------------- |
| 10200004 | The Worker instance is not running. |

**Example**

```ts
// Main thread
import { worker } from '@kit.ArkTS';

const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ets");
```

```ts
// worker.ets
import { worker, MessageEvents } from '@kit.ArkTS';

const workerPort = worker.workerPort;
workerPort.onmessage = (e: MessageEvents): void => {
    workerPort.close()
}
```


### onmessage<sup>9+</sup>

onmessage?: (this: ThreadWorkerGlobalScope, ev: MessageEvents) =&gt; void

Called when the worker thread receives a message sent by the host thread through **postMessage**. The event handler is executed in the worker thread. In the callback function, **this** indicates the caller's [ThreadWorkerGlobalScope](#threadworkerglobalscope9), and the **ev** type is [MessageEvents](#messageevents9), indicating the received message data.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                  |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 10200004 | The Worker instance is not running.              |
| 10200005 | The called API is not supported in the worker thread. |

**Example**

```ts
// Main thread
import { worker } from '@kit.ArkTS';

const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ets");
workerInstance.postMessage("hello world");
```

```ts
// worker.ets
import { worker, MessageEvents } from '@kit.ArkTS';

const workerPort = worker.workerPort;
workerPort.onmessage = (e: MessageEvents): void => {
    console.log("receive main thread message");
}
```


### onmessageerror<sup>9+</sup>

onmessageerror?: (this: ThreadWorkerGlobalScope, ev: MessageEvents) =&gt; void

Called when the worker thread receives a message that cannot be deserialized. The event handler is executed in the worker thread. In the callback function, **this** indicates the caller's [ThreadWorkerGlobalScope](#threadworkerglobalscope9), and the **ev** type is [MessageEvents](#messageevents9), indicating the received message data.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                  |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 10200004 | The Worker instance is not running.              |
| 10200005 | The called API is not supported in the worker thread. |

**Example**

```ts
// Main thread
import { worker } from '@kit.ArkTS';

const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ets");
```

```ts
// worker.ets
import { worker, MessageEvents } from '@kit.ArkTS';

const workerPort = worker.workerPort;
workerPort.onmessageerror = (err: MessageEvents) => {
    console.log("worker.ets onmessageerror");
}
```


## WorkerEventListener<sup>9+</sup>

Implements event listening.

### (event: Event)<sup>9+</sup>

(event: Event): void | Promise&lt;void&gt;

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description          |
| ------ | --------------- | ---- | -------------- |
| event  | [Event](#event) | Yes  | Event class for the callback to invoke.|

**Return value**

| Type                                 | Description                           |
| ------------------------------------- | ------------------------------- |
| void&nbsp;\|&nbsp;Promise&lt;void&gt; | Returns no value or returns a **Promise**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                  |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200004 | The Worker instance is not running.              |
| 10200005 | The called API is not supported in the worker thread. |

**Example**

```ts
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ets");
workerInstance.addEventListener("alert", (e)=>{
    console.log("alert listener callback");
})
```


## GlobalScope<sup>9+</sup>

Implements the running environment of the worker thread. The **GlobalScope** class inherits from [WorkerEventTarget](#workereventtarget9).

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

| Name| Type                                                        | Readable| Writable| Description                                 |
| ---- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------- |
| name | string                                                       | Yes  | No  | **Worker** instance specified when there is a new **Worker** instance.|
| self | [GlobalScope](#globalscope9)&nbsp;&amp;&nbsp;typeof&nbsp;globalThis | Yes  | No  | **GlobalScope** itself.                    |


### onerror<sup>9+</sup>

onerror?: (ev: ErrorEvent) =&gt; void

Called when an exception occurs during worker execution. The event handler is executed in the worker thread. In the callback function, the **ev** type is [ErrorEvent](#errorevent), indicating the received abnormal data.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
// Main thread
import { worker } from '@kit.ArkTS';

const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ets")
```

```ts
// worker.ets
import { worker, ErrorEvent } from '@kit.ArkTS';

const workerPort = worker.workerPort
workerPort.onerror = (err: ErrorEvent) => {
    console.log("worker.ets onerror" + err.message)
}
```

## MessageEvents<sup>9+</sup>

Holds the data transferred between worker threads.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Readable| Writable| Description              |
| ---- | ---- | ---- | ---- | ------------------ |
| data | any  | Yes  | No  | Data transferred between threads.|

## RestrictedWorker<sup>11+</sup>

The RestrictedWorker class inherits [ThreadWorker<sup>9+</sup>](#threadworker9) and supports all APIs in **ThreadWorker**.
**RestrictedWorker** provides a restricted environment for running the worker thread. In this environment, only the **Worker** module can be imported.

### constructor<sup>11+</sup>

constructor(scriptURL: string, options?: WorkerOptions)

A constructor used to create a **RestrictedWorker** instance. Before using the following APIs, you must create a **RestrictedWorker** instance.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type                           | Mandatory| Description                                                        |
| --------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| scriptURL | string                          | Yes  | URL of the worker thread file. For details about the rules, see [Precautions for File URLs](../../arkts-utils/worker-introduction.md#precautions-for-file-urls).|
| options   | [WorkerOptions](#workeroptions) | No  | Options that can be set for the **RestrictedWorker** instance.                                          |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200003 | Worker initialization failure. |
| 10200007 | The worker file patch is invalid path. |

**Example**

The following code snippet shows how to load the worker thread file of the ability in the stage model. For details about how to use the library to load the worker thread file, see [Precautions for File URLs](../../arkts-utils/worker-introduction.md#precautions-for-file-urls).

Only the **Worker** module can be imported to the restricted worker thread file. Other APIs cannot be imported. The following is sample code:

```ts
import { worker } from '@kit.ArkTS';

// Two scenarios are involved.

// Scenario 1: URL of the worker thread file: "entry/src/main/ets/workers/worker.ets"
const workerStageModel01 = new worker.RestrictedWorker('entry/ets/workers/worker.ets', {name:"first worker in Stage model"});

// Scenario 2: URL of the worker thread file: "phone/src/main/ets/ThreadFile/workers/worker.ets"
const workerStageModel02 = new worker.RestrictedWorker('phone/ets/ThreadFile/workers/worker.ets');
```

```ts
// Restricted worker thread file
import { worker, MessageEvents } from '@kit.ArkTS';

//import { process } from '@kit.ArkTS'; // Only worker APIs can be imported to the restricted worker thread file.

const workerPort = worker.workerPort;

workerPort.onmessage = (e : MessageEvents) : void => {
  console.info("worker:: This is worker thread.")
  // console.info("worker:: worker tid: "+ process.tid) // Run process.tid. The main thread reports the corresponding error.
}
```

## Worker<sup>(deprecated)</sup>


Before using the following APIs, you must create a **Worker** instance. The **Worker** class inherits from [EventTarget](#eventtargetdeprecated).

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [ThreadWorker<sup>9+</sup>](#threadworker9) instead.

### constructor<sup>(deprecated)</sup>

constructor(scriptURL: string, options?: WorkerOptions)

A constructor used to create a **Worker** instance.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [ThreadWorker.constructor<sup>9+</sup>](#constructor9) instead.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type                           | Mandatory| Description                                                        |
| --------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| scriptURL | string                          | Yes  | URL of the worker thread file. For details about the rules, see [Precautions for File URLs](../../arkts-utils/worker-introduction.md#precautions-for-file-urls).|
| options   | [WorkerOptions](#workeroptions) | No  | Options that can be set for the **Worker** instance.                                          |

**Example**

The following code snippet shows how to load the worker thread file of the ability in the stage model. For details about how to use the library to load the worker thread file, see [Precautions for File URLs](../../arkts-utils/worker-introduction.md#precautions-for-file-urls).


```ts
import { worker } from '@kit.ArkTS';

// Two scenarios are involved.

// Scenario 1: URL of the worker thread file: "entry/src/main/ets/workers/worker.ets"
const workerStageModel01 = new worker.ThreadWorker('entry/ets/workers/worker.ets', {name:"first worker in Stage model"});

// Scenario 2: URL of the worker thread file: "phone/src/main/ets/ThreadFile/workers/worker.ets"
const workerStageModel02 = new worker.ThreadWorker('phone/ets/ThreadFile/workers/worker.ets');
```

### postMessage<sup>(deprecated)</sup>

postMessage(message: Object, transfer: ArrayBuffer[]): void

Sends a message from the host thread to the worker thread by transferring object ownership.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [ThreadWorker.postMessage<sup>9+</sup>](#postmessage9) instead.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type         | Mandatory| Description                                                        |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| message  | Object        | Yes  | Data to be sent to the worker thread. The data object must be sequenceable. For details about the supported parameter types, see [Sequenceable Data Types](#sequenceable-data-types).|
| transfer | ArrayBuffer[] | Yes  | **ArrayBuffer** instance holding an array of objects for which the ownership is transferred to the worker thread. After the transfer, the objects are available only in the worker thread. The array cannot be null.|

**Example**

```ts
const workerInstance = new worker.Worker("workers/worker.ets");

let buffer = new ArrayBuffer(8);
workerInstance.postMessage(buffer, [buffer]);
```

### postMessage<sup>(deprecated)</sup>

postMessage(message: Object, options?: PostMessageOptions): void

Sends a message from the host thread to the worker thread by transferring object ownership or copying data.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [ThreadWorker.postMessage<sup>9+</sup>](#postmessage9-1) instead.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type                                     | Mandatory| Description                                                        |
| ------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| message | Object                                    | Yes  | Data to be sent to the worker thread. The data object must be sequenceable. For details about the supported parameter types, see [Sequenceable Data Types](#sequenceable-data-types).|
| options | [PostMessageOptions](#postmessageoptions) | No  | If this parameter is specified, it functions the same as **ArrayBuffer[]**. Specifically, the ownership of the objects in the array is transferred to the worker thread and becomes unavailable in the host thread. The objects are available only in the worker thread.<br>If this parameter is not specified, the default value **undefined** is used, and information is transferred to the worker thread by copying data.|

**Example**

```ts
const workerInstance = new worker.Worker("workers/worker.ets");

workerInstance.postMessage("hello world");

let buffer = new ArrayBuffer(8);
workerInstance.postMessage(buffer, [buffer]);
```


### on<sup>(deprecated)</sup>

on(type: string, listener: EventListener): void

Adds an event listener for the worker thread. This API provides the same functionality as [addEventListener<sup>(deprecated)</sup>](#addeventlistenerdeprecated).

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [ThreadWorker.on<sup>9+</sup>](#on9) instead.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type                                     | Mandatory| Description            |
| -------- | ----------------------------------------- | ---- | ---------------- |
| type     | string                                    | Yes  | Type of the event to listen for.|
| listener | [EventListener](#eventlistenerdeprecated) | Yes  | Callback to invoke when an event of the specified type occurs.      |

**Example**

```ts
const workerInstance = new worker.Worker("workers/worker.ets");
workerInstance.on("alert", (e)=>{
    console.log("alert listener callback");
})
```


### once<sup>(deprecated)</sup>

once(type: string, listener: EventListener): void

Adds an event listener for the worker thread and removes the event listener after it is invoked once.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [ThreadWorker.once<sup>9+</sup>](#once9) instead.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type                                     | Mandatory| Description            |
| -------- | ----------------------------------------- | ---- | ---------------- |
| type     | string                                    | Yes  | Type of the event to listen for.|
| listener | [EventListener](#eventlistenerdeprecated) | Yes  | Callback to invoke when an event of the specified type occurs.      |

**Example**

```ts
const workerInstance = new worker.Worker("workers/worker.ets");
workerInstance.once("alert", (e)=>{
    console.log("alert listener callback");
})
```


### off<sup>(deprecated)</sup>

off(type: string, listener?: EventListener): void

Removes an event listener for the worker thread. This API provides the same functionality as [removeEventListener<sup>(deprecated)</sup>](#removeeventlistenerdeprecated).

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [ThreadWorker.off<sup>9+</sup>](#off9) instead.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type                                     | Mandatory| Description                |
| -------- | ----------------------------------------- | ---- | -------------------- |
| type     | string                                    | Yes  | Type of the event for which the event listener is to be removed.|
| listener | [EventListener](#eventlistenerdeprecated) | No  | Callback to invoke when the listener is removed.|

**Example**

```ts
const workerInstance = new worker.Worker("workers/worker.ets");
// Use on, once, or addEventListener to add a listener for the "alert" event, and use off to remove the listener.
workerInstance.off("alert");
```


### terminate<sup>(deprecated)</sup>

terminate(): void

Terminates the worker thread to stop it from receiving messages.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [ThreadWorker.terminate<sup>9+</sup>](#terminate9) instead.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
const workerInstance = new worker.Worker("workers/worker.ets");
workerInstance.terminate();
```


### onexit<sup>(deprecated)</sup>

onexit?: (code: number) =&gt; void

Called when the worker thread exits. The event handler is executed in the host thread. In the callback function, the **code** value is of the number type, where the value **1** indicates abnormal exit and **0** indicates normal exit.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [ThreadWorker.onexit<sup>9+</sup>](#onexit9) instead.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
const workerInstance = new worker.Worker("workers/worker.ets");
workerInstance.onexit = (code) => {
    console.log("onexit");
}

// onexit is executed in either of the following ways:
// Main thread
workerInstance.terminate();

// Worker thread
//parentPort.close()
```


### onerror<sup>(deprecated)</sup>

onerror?: (err: ErrorEvent) =&gt; void

Called when an exception occurs during worker execution. The event handler is executed in the host thread. In the callback function, the **err** type is [ErrorEvent](#errorevent), indicating the received abnormal data.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [ThreadWorker.onerror<sup>9+</sup>](#onerror9) instead.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
import { worker, ErrorEvent } from '@kit.ArkTS';

const workerInstance = new worker.Worker("workers/worker.ets");
workerInstance.onerror = (err: ErrorEvent) => {
  console.log("onerror" + err.message);
}
```


### onmessage<sup>(deprecated)</sup>

onmessage?: (event: MessageEvent) =&gt; void

Called when the host thread receives a message sent by the worker thread through **workerPort.postMessage**. The event handler is executed in the host thread. In the callback function, the **event** type is [MessageEvent](#messageeventt), indicating the received message data.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [ThreadWorker.onmessage<sup>9+</sup>](#onmessage9) instead.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
import { worker } from '@kit.ArkTS';

const workerInstance = new worker.Worker("workers/worker.ets");
workerInstance.onmessage = (e): void => {
    console.log("onmessage");
}
```


### onmessageerror<sup>(deprecated)</sup>

onmessageerror?: (event: MessageEvent) =&gt; void

Called when the worker thread receives a message that cannot be serialized. The event handler is executed in the host thread. In the callback function, the **event** type is [MessageEvent](#messageeventt), indicating the received message data.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [ThreadWorker.onmessageerror<sup>9+</sup>](#onmessageerror9) instead.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
import { worker } from '@kit.ArkTS';

const workerInstance = new worker.Worker("workers/worker.ets");
workerInstance.onmessageerror = (err) => {
    console.log("onmessageerror");
}
```


## EventTarget<sup>(deprecated)</sup>
> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [WorkerEventTarget<sup>9+</sup>](#workereventtarget9) instead.

### addEventListener<sup>(deprecated)</sup>

addEventListener(type: string, listener: EventListener): void

Adds an event listener for the worker thread. This API provides the same functionality as [on<sup>(deprecated)</sup>](#ondeprecated).

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [addEventListener<sup>9+</sup>](#addeventlistener9) instead.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type                                     | Mandatory| Description            |
| -------- | ----------------------------------------- | ---- | ---------------- |
| type     | string                                    | Yes  | Type of the event to listen for.|
| listener | [EventListener](#eventlistenerdeprecated) | Yes  | Callback to invoke when an event of the specified type occurs.    |

**Example**

```ts
const workerInstance = new worker.Worker("workers/worker.ets");
workerInstance.addEventListener("alert", (e)=>{
    console.log("alert listener callback");
})
```


### removeEventListener<sup>(deprecated)</sup>

removeEventListener(type: string, callback?: EventListener): void

Removes an event listener for the worker thread. This API provides the same functionality as [off<sup>(deprecated)</sup>](#offdeprecated).

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [removeEventListener<sup>9+</sup>](#removeeventlistener9) instead.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type                                     | Mandatory| Description                    |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Type of the event for which the event listener is to be removed.|
| callback | [EventListener](#eventlistenerdeprecated) | No  | Callback to invoke when the listener is removed.|

**Example**

```ts
const workerInstance = new worker.Worker("workers/worker.ets");
workerInstance.addEventListener("alert", (e)=>{
    console.log("alert listener callback");
})
workerInstance.removeEventListener("alert");
```


### dispatchEvent<sup>(deprecated)</sup>

dispatchEvent(event: Event): boolean

Dispatches the event defined for the worker thread.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [dispatchEvent<sup>9+</sup>](#dispatchevent9) instead.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description            |
| ------ | --------------- | ---- | ---------------- |
| event  | [Event](#event) | Yes  | Event to dispatch.|

**Return value**

| Type   | Description                           |
| ------- | ------------------------------- |
| boolean | Returns **true** if the event is dispatched successfully; returns **false** otherwise.|

**Example**

```ts
const workerInstance = new worker.Worker("workers/worker.ets");

workerInstance.dispatchEvent({type:"eventType", timeStamp:0}); // timeStamp is not supported yet.
```

The **dispatchEvent** API can be used together with the **on**, **once**, and **addEventListener** APIs. The sample code is as follows:

```ts
const workerInstance = new worker.Worker("workers/worker.ets");

// Usage 1:
workerInstance.on("alert_on", (e)=>{
    console.log("alert listener callback");
})
workerInstance.once("alert_once", (e)=>{
    console.log("alert listener callback");
})
workerInstance.addEventListener("alert_add", (e)=>{
    console.log("alert listener callback");
})

// The event listener created by once is removed after being executed once.
workerInstance.dispatchEvent({type:"alert_once", timeStamp:0});// timeStamp is not supported yet.
// The event listener created by on will not be proactively deleted.
workerInstance.dispatchEvent({type:"alert_on", timeStamp:0});
workerInstance.dispatchEvent({type:"alert_on", timeStamp:0});
// The event listener created by addEventListener will not be proactively deleted.
workerInstance.dispatchEvent({type:"alert_add", timeStamp:0});
workerInstance.dispatchEvent({type:"alert_add", timeStamp:0});

// Usage 2:
// The event type can be customized, and the special types "message", "messageerror", and "error" exist.
// When type = "message", the event handler defined by onmessage will also be executed.
// When type = "messageerror", the event handler defined by onmessageerror will also be executed.
// When type = "error", the event handler defined by onerror will also be executed.
// removeEventListener or off can be used to remove an event listener that is created by addEventListener, on, or once.

workerInstance.addEventListener("message", (e)=>{
    console.log("message listener callback");
})
workerInstance.onmessage = function(e) {
    console.log("onmessage : message listener callback");
}
// When dispatchEvent is called to distribute the "message" event, the callback passed in addEventListener and onmessage will be invoked.
workerInstance.dispatchEvent({type:"message", timeStamp:0});
```
### removeAllListener<sup>(deprecated)</sup>

removeAllListener(): void

Removes all event listeners for the worker thread.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [removeAllListener<sup>9+</sup>](#removealllistener9) instead.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
const workerInstance = new worker.Worker("workers/worker.ets");
workerInstance.addEventListener("alert", (e)=>{
    console.log("alert listener callback");
})
workerInstance.removeAllListener();
```


## DedicatedWorkerGlobalScope<sup>(deprecated)</sup>

Implements communication between the worker thread and the host thread. The **postMessage** API is used to send messages to the host thread, and the **close** API is used to terminate the worker thread. This class inherits from [WorkerGlobalScope](#workerglobalscopedeprecated).

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [ThreadWorkerGlobalScope<sup>9+</sup>](#threadworkerglobalscope9) instead.

### postMessage<sup>(deprecated)</sup>

postMessage(messageObject: Object, transfer: Transferable[]): void

Sends a message from the worker thread to the host thread by transferring object ownership.

> **NOTE**<br>
> This API is deprecated since API version 9. You are advised to use [ThreadWorkerGlobalScope<sup>9+</sup>.postMessage<sup>9+</sup>](#postmessage9-2).

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type                                     | Mandatory| Description                                                        |
| ------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| messageObject | Object                                    | Yes  | Data to be sent to the host thread. The data object must be sequenceable. For details about the supported parameter types, see [Sequenceable Data Types](#sequenceable-data-types).|
| transfer| Transferable[]                            | Yes  | Currently, this parameter is not supported.                                        |

### postMessage<sup>9+</sup>

postMessage(messageObject: Object, transfer: ArrayBuffer[]): void

Sends a message from the worker thread to the host thread by transferring object ownership.

> **NOTE**
>
> The **DedicatedWorkerGlobalScope** class is deprecated since API version 9. You are advised to use [ThreadWorkerGlobalScope<sup>9+</sup>.postMessage<sup>9+</sup>](#postmessage9-2).

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type         | Mandatory| Description                                                        |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| messageObject  | Object        | Yes  | Data to be sent to the host thread. The data object must be sequenceable. For details about the supported parameter types, see [Sequenceable Data Types](#sequenceable-data-types).|
| transfer | ArrayBuffer[] | Yes  | **ArrayBuffer** instance holding an array of objects for which the ownership is transferred to the host thread. After the transfer, the objects are available only in the host thread. The array cannot be null.|

**Example**

```ts
// Main thread
import { worker } from '@kit.ArkTS';

const workerInstance = new worker.Worker("workers/worker.ets");
workerInstance.postMessage("hello world");
workerInstance.onmessage = (e): void => {
    // let data = e.data;
    console.log("receive data from worker.ets");
}
```
```ts
// worker.ets
import { worker } from '@kit.ArkTS';

const workerPort = worker.workerPort;
workerPort.onmessage = (e): void => {
    // let data = e.data;
    let buffer = new ArrayBuffer(5)
    workerPort.postMessage(buffer, [buffer]);
}
```

### postMessage<sup>(deprecated)</sup>

postMessage(messageObject: Object, options?: PostMessageOptions): void

Sends a message from the worker thread to the host thread by transferring object ownership or copying data.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [ThreadWorkerGlobalScope<sup>9+</sup>.postMessage<sup>9+</sup>](#postmessage9-3).

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type                                     | Mandatory| Description                                                        |
| ------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| messageObject | Object                                    | Yes  | Data to be sent to the host thread. The data object must be sequenceable. For details about the supported parameter types, see [Sequenceable Data Types](#sequenceable-data-types).|
| options | [PostMessageOptions](#postmessageoptions) | No  | If this parameter is specified, it functions the same as **ArrayBuffer[]**. Specifically, the ownership of the objects in the array is transferred to the host thread and becomes unavailable in the worker thread. The objects are available only in the host thread.<br>If this parameter is not specified, the default value **undefined** is used, and information is transferred to the host thread by copying data.|

**Example**

<!--no_check-->
```ts
// Main thread
import { worker } from '@kit.ArkTS';

const workerInstance = new worker.Worker("entry/ets/workers/worker.ets");
workerInstance.postMessage("hello world");
workerInstance.onmessage = (): void => {
    console.log("receive data from worker.ets");
}
```
```ts
// worker.ets
import { ErrorEvent, MessageEvents, worker } from '@kit.ArkTS';

const parentPort = worker.parentPort;
parentPort.onmessage = (e: MessageEvents) => {
  parentPort.postMessage("receive data from main thread");
}
```

### close<sup>(deprecated)</sup>

close(): void

Terminates the worker thread to stop it from receiving messages.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [ThreadWorkerGlobalScope<sup>9+</sup>.close<sup>9+</sup>](#close9).

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
// Main thread
import { worker } from '@kit.ArkTS';

const workerInstance = new worker.Worker("workers/worker.ets");
```
```ts
// worker.ets
import { worker } from '@kit.ArkTS';

const parentPort = worker.parentPort;
parentPort.onmessage = (e): void => {
    parentPort.close()
}
```


### onmessage<sup>(deprecated)</sup>

onmessage?: (this: DedicatedWorkerGlobalScope, ev: MessageEvent) =&gt; void

Called when the worker thread receives a message sent by the host thread through **postMessage**. The event handler is executed in the worker thread. In the callback function, **this** indicates the caller's [DedicatedWorkerGlobalScope](#dedicatedworkerglobalscopedeprecated), and the **ev** type is [MessageEvent](#messageeventt), indicating the received message data.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [ThreadWorkerGlobalScope<sup>9+</sup>.onmessage<sup>9+</sup>](#onmessage9-1).

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
// Main thread
import { worker } from '@kit.ArkTS';

const workerInstance = new worker.Worker("workers/worker.ets");
workerInstance.postMessage("hello world");
```
```ts
// worker.ets
import { worker } from '@kit.ArkTS';

const parentPort = worker.parentPort;
parentPort.onmessage = (e): void => {
    console.log("receive main thread message");
}
```


### onmessageerror<sup>(deprecated)</sup>

onmessageerror?: (this: DedicatedWorkerGlobalScope, ev: MessageEvent) =&gt; void

Called when the worker thread receives a message that cannot be deserialized. The event handler is executed in the worker thread. In the callback function, **this** indicates the caller's [DedicatedWorkerGlobalScope](#threadworkerglobalscope9), and the **ev** type is [MessageEvent](#dedicatedworkerglobalscopedeprecated), indicating the received message data.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [ThreadWorkerGlobalScope<sup>9+</sup>.onmessageerror<sup>9+</sup>](#onmessageerror9-1).

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
// Main thread
import { worker } from '@kit.ArkTS';

const workerInstance = new worker.Worker("workers/worker.ets");
```
```ts
// worker.ets
import { worker } from '@kit.ArkTS';

const parentPort = worker.parentPort;
parentPort.onmessageerror = (e) => {
    console.log("worker.ets onmessageerror")
}
```


## PostMessageOptions

Defines the object for which the ownership is to be transferred during data transfer. The object must be an **ArrayBuffer** instance. After the ownership is transferred, the object becomes unavailable in the sender and can be used only in the receiver.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

| Name    | Type    | Readable| Writable| Description                             |
| -------- | -------- | ---- | ---- | --------------------------------- |
| transfer | Object[] | Yes  | Yes  | **ArrayBuffer** array used to transfer the ownership. The array cannot be **null**.|


## Event

Defines the event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name     | Type  | Readable| Writable| Description                                        |
| --------- | ------ | ---- | ---- | -------------------------------------------- |
| type      | string | Yes  | No  | Type of the event.                            |
| timeStamp | number | Yes  | No  | Timestamp (accurate to millisecond) when the event is created. This parameter is not supported yet.|


## EventListener<sup>(deprecated)</sup>

Implements event listening.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [WorkerEventListener<sup>9+</sup>](#workereventlistener9) instead.

### (evt: Event)<sup>(deprecated)</sup>

(evt: Event): void | Promise&lt;void&gt;

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [(event:Event)<sup>9+</sup>](#event-event9) instead.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description          |
| ------ | --------------- | ---- | -------------- |
| evt    | [Event](#event) | Yes  | Event class for the callback to invoke.|

**Return value**

| Type                                 | Description                           |
| ------------------------------------- | ------------------------------- |
| void&nbsp;\|&nbsp;Promise&lt;void&gt; | Returns no value or returns a **Promise**.|

**Example**

```ts
const workerInstance = new worker.Worker("workers/worker.ets");
workerInstance.addEventListener("alert", (e)=>{
    console.log("alert listener callback");
})
```


## ErrorEvent

Provides detailed information about the exception that occurs during worker execution. The **ErrorEvent** class inherits from [Event](#event).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

| Name    | Type  | Readable| Writable| Description                |
| -------- | ------ | ---- | ---- | -------------------- |
| message  | string | Yes  | No  | Information about the exception.|
| filename | string | Yes  | No  | File where the exception is located.|
| lineno   | number | Yes  | No  | Serial number of the line where the exception is located.    |
| colno    | number | Yes  | No  | Serial number of the column where the exception is located.    |
| error    | Object | Yes  | No  | Type of the exception.          |


## MessageEvent\<T\>

Holds the data transferred between worker threads.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Readable| Writable| Description              |
| ---- | ---- | ---- | ---- | ------------------ |
| data | T    | Yes  | No  | Data transferred between threads.|


## WorkerGlobalScope<sup>(deprecated)</sup>

Implements the running environment of the worker thread. The **WorkerGlobalScope** class inherits from [EventTarget](#eventtargetdeprecated).

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [GlobalScope<sup>9+</sup>](#globalscope9) instead.

### Attributes

**System capability**: SystemCapability.Utils.Lang

| Name| Type                                                        | Readable| Writable| Description                                 |
| ---- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------- |
| name | string                                                       | Yes  | No  | **Worker** instance specified when there is a new **Worker** instance.|
| self | [WorkerGlobalScope](#workerglobalscopedeprecated)&nbsp;&amp;&nbsp;typeof&nbsp;globalThis | Yes  | No  | **WorkerGlobalScope**.              |


### onerror<sup>(deprecated)</sup>

onerror?: (ev: ErrorEvent) =&gt; void

Called when an exception occurs during worker execution. The event handler is executed in the worker thread. In the callback function, the **ev** type is [ErrorEvent](#errorevent), indicating the received abnormal data.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [GlobalScope<sup>9+</sup>.onerror<sup>9+</sup>](#onerror9-1).

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
// Main thread
import { worker } from '@kit.ArkTS';

const workerInstance = new worker.Worker("workers/worker.ets")
```
```ts
// worker.ets
import { worker, ErrorEvent } from '@kit.ArkTS';

const parentPort = worker.parentPort
parentPort.onerror = (err: ErrorEvent) => {
    console.log("worker.ets onerror" + err.message)
}
```


## More Information

### Sequenceable Data Types

The following object types are supported: basic types except Symbol, Date, String, RegExp, Array, Map, Set, Object (simple objects only, for example, objects created using **{}** or **new Object**), ArrayBuffer, and typedArray. (Note that only attributes can be transferred for common objects. Prototypes and methods cannot be transferred.)

Exception: When an object created through a custom class is passed, no serialization error occurs. However, the attributes (such as Function) of the custom class cannot be passed through serialization.
> **NOTE**<br>
> An FA project of API version 9 is used as an example.

```ts
// Main thread
import { worker, MessageEvents } from '@kit.ArkTS';

const workerInstance = new worker.ThreadWorker("workers/worker.ets");
workerInstance.postMessage("message from main thread to worker");
workerInstance.onmessage = (d: MessageEvents): void => {
  // When the worker thread passes obj2, data contains obj2, excluding the Init or SetName method.
  let data: string  = d.data;
}
```
```ts
// worker.ets
import { worker, MessageEvents, ErrorEvent } from '@kit.ArkTS';

const workerPort = worker.workerPort;
class MyModel {
    name = "undefined"
    Init() {
        this.name = "MyModel"
    }
}
workerPort.onmessage = (d: MessageEvents): void => {
  console.log("worker.ets onmessage");
  let data: string = d.data;
  let func1 = () => {
    console.log("post message is function");
  }
  // workerPort.postMessage(func1); A serialization error occurs when passing func1.
  // let obj1: obj | null = null;
  // if (obj1) {
  //   workerPort.postMessage(obj1 as obj);  // A serialization error occurs when passing obj1.
  // }
  let obj2 = new MyModel();
  workerPort.postMessage(obj2);     // No serialization error occurs when passing obj2.
}
workerPort.onmessageerror = () => {
    console.log("worker.ets onmessageerror");
}
workerPort.onerror = (err: ErrorEvent) => {
    console.log("worker.ets onerror" + err.message);
}
```

### Memory Model
The worker thread is implemented based on the actor model. In the worker interaction process, the JS main thread can create multiple worker threads, each of which are isolated and transfer data through serialization. They complete computing tasks and return the result to the main thread.

Each actor concurrently processes tasks of the main thread. For each actor, there is a message queue and a single-thread execution module. The message queue receives requests from the main thread and other actors; the single-thread execution module serially processes requests, sends requests to other actors, and creates new actors. These isolated actors use the asynchronous mode and can run concurrently.

## Sample Code
> **NOTE**<br>
> Two projects of API version 9 are used as an example.<br> Only the FA model is supported in API version 8 and earlier versions. If you want to use API version 8 or earlier, change the API for constructing the **Worker** instance and the API for creating an object in the worker thread for communicating with the main thread.
### FA Model

```ts
// Main thread (The following assumes that the workers directory and pages directory are at the same level.)
import { worker, MessageEvents, ErrorEvent } from '@kit.ArkTS';

// Create a Worker instance in the main thread.
const workerInstance = new worker.ThreadWorker("workers/worker.ets");

// The main thread transfers information to the worker thread.
workerInstance.postMessage("123");

// The main thread receives information from the worker thread.
workerInstance.onmessage = (e: MessageEvents): void => {
    // data carries the information sent by the worker thread.
    let data: string = e.data;
    console.log("main thread onmessage");

    // Terminate the Worker instance.
    workerInstance.terminate();
}

// Call onexit().
workerInstance.onexit = (code) => {
    console.log("main thread terminate");
}

workerInstance.onerror = (err: ErrorEvent) => {
    console.log("main error message " + err.message);
}
```
```ts
// worker.ets
import { worker, MessageEvents, ErrorEvent } from '@kit.ArkTS';

// Create an object in the worker thread for communicating with the main thread.
const workerPort = worker.workerPort

// The worker thread receives information from the main thread.
workerPort.onmessage = (e: MessageEvents): void => {
    // data carries the information sent by the main thread.
    let data: string = e.data;
    console.log("worker.ets onmessage");

    // The worker thread sends information to the main thread.
    workerPort.postMessage("123")
}

// Trigger a callback when an error occurs in the worker thread.
workerPort.onerror = (err: ErrorEvent) => {
    console.log("worker.ets onerror");
}
```
Configuration of the **build-profile.json5** file:
```json
  "buildOption": {
    "sourceOption": {
      "workers": [
        "./src/main/ets/entryability/workers/worker.ets"
      ]
    }
  }
```
### Stage Model
```ts
// Main thread (The following assumes that the workers directory and pages directory are at different levels.)
import { worker, MessageEvents, ErrorEvent } from '@kit.ArkTS';

// Create a Worker instance in the main thread.
const workerInstance = new worker.ThreadWorker("entry/ets/pages/workers/worker.ets");

// The main thread transfers information to the worker thread.
workerInstance.postMessage("123");

// The main thread receives information from the worker thread.
workerInstance.onmessage = (e: MessageEvents): void => {
    // data carries the information sent by the worker thread.
    let data: string = e.data;
    console.log("main thread onmessage");

    // Terminate the Worker instance.
    workerInstance.terminate();
}
// Call onexit().
workerInstance.onexit = (code) => {
    console.log("main thread terminate");
}

workerInstance.onerror = (err: ErrorEvent) => {
    console.log("main error message " + err.message);
}
```
```ts
// worker.ets
import { worker, MessageEvents, ErrorEvent } from '@kit.ArkTS';

// Create an object in the worker thread for communicating with the main thread.
const workerPort = worker.workerPort

// The worker thread receives information from the main thread.
workerPort.onmessage = (e: MessageEvents): void => {
    // data carries the information sent by the main thread.
    let data: string = e.data;
    console.log("worker.ets onmessage");

    // The worker thread sends information to the main thread.
    workerPort.postMessage("123")
}

// Trigger a callback when an error occurs in the worker thread.
workerPort.onerror = (err: ErrorEvent) => {
    console.log("worker.ets onerror" + err.message);
}
```
Configuration of the **build-profile.json5** file:
```json
  "buildOption": {
    "sourceOption": {
      "workers": [
        "./src/main/ets/pages/workers/worker.ets"
      ]
    }
  }
```
<!--no_check-->
