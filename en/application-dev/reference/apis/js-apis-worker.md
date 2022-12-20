# @ohos.worker

The worker thread is an independent thread running in parallel with the main thread. The thread that creates the worker thread is referred to as the host thread. The URL file passed in during worker creation is executed in the worker thread. The worker thread can process time-consuming operations, but cannot directly operate the UI.

With the **Worker** module, you can provide a multithreading environment for an application, so that the application can perform a time-consuming operation in a background thread. This greatly prevents a computing-intensive or high-latency task from blocking the running of the main thread. A **Worker** instance will not be proactively destroyed once it is created. It consumes resources to keep running. Therefore, you should call the API to terminate it in a timely manner.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import worker from '@ohos.worker';
```


## Attributes

**System capability**: SystemCapability.Utils.Lang

| Name                             | Type                                                     | Readable| Writable| Description                                                        |
| --------------------------------- | --------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| workerPort<sup>9+</sup>           | [ThreadWorkerGlobalScope](#threadworkerglobalscope9)      | Yes  | Yes  | Object of the worker thread used to communicate with the host thread.                        |
| parentPort<sup>(deprecated)</sup> | [DedicatedWorkerGlobalScope](#dedicatedworkerglobalscope) | Yes  | Yes  | Object of the worker thread used to communicate with the host thread.<br>This attribute is supported since API version 7 and deprecated since API version 9.<br>You are advised to use **workerPort<sup>9+</sup>** instead.|


## WorkerOptions

Provides options that can be set for the **Worker** instance to create.

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Readable| Writable| Description          |
| ---- | -------- | ---- | ---- | -------------- |
| type | "classic" \| "module" | Yes  | Yes  | Mode in which the **Worker** instance executes the script. The default value is **classic**. The module **type** is not supported yet.|
| name | string   | Yes  | Yes  | Name of the worker thread.|
| shared | boolean | Yes  | Yes  | Sharing of the **Worker** instance is not supported yet.|


## ThreadWorker<sup>9+</sup>

Before using the following APIs, you must create a **Worker** instance. The **Worker** class inherits from [WorkerEventTarget](#workereventtarget9).

### constructor<sup>9+</sup>

constructor(scriptURL: string, options?: WorkerOptions)

A constructor used to create a **Worker** instance.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type                           | Mandatory| Description                                                        |
| --------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| scriptURL | string                          | Yes  | Directory of the script to be executed by the **Worker** instance.<br>In the FA or stage model, DevEco Studio creates a **Worker** project in either of the following scenarios:<br>(a) The script directory is at the same level as the **pages** directory.<br>(b) The script directory is at a different level from the **pages** directory.|
| options   | [WorkerOptions](#workeroptions) | No  | Options that can be set for the **Worker** instance.                                          |

**Return value**

| Type  | Description                                                     |
| ------ | --------------------------------------------------------- |
| Worker | Returns the **Worker** instance created; returns **undefined** if the **Worker** instance fails to be created.|

**Example**

```js
import worker from '@ohos.worker';
// Create a Worker instance.

// In the FA model, the worker script directory and pages directory are at the same level.
const workerFAModel01 = new worker.ThreadWorker("workers/worker.js", {name:"first worker in FA model"});
// In the FA model, the worker script directory and pages directory are at different levels.
const workerFAModel02 = new worker.ThreadWorker("../workers/worker.js");

// In the stage model, the worker script directory and pages directory are at the same level.
const workerStageModel01 = new worker.ThreadWorker('entry/ets/workers/worker.ts', {name:"first worker in Stage model"});
// In the stage model, the worker script directory and pages directory are at different levels.
const workerStageModel02 = new worker.ThreadWorker('entry/ets/pages/workers/worker.ts');

// For the script URL "entry/ets/workers/worker.ts" in the stage model:
// entry is the value of the name attribute under module in the module.json5 file.
// ets indicates the programming language in use.
```

Depending on whether the worker script directory and **pages** directory are at the same level, you may need to configure the **buildOption** attribute in the **build-profile.json5** file.

(1) The worker script directory and **pages** directory are at the same level.

In the FA model:

```json
  "buildOption": {
    "sourceOption": {
      "workers": [
        "./src/main/ets/MainAbility/workers/worker.ts"
      ]
    }
  }
```

In the stage model:

```json
  "buildOption": {
    "sourceOption": {
      "workers": [
        "./src/main/ets/workers/worker.ts"
      ]
    }
  }
```

(2) The worker script directory and **pages** directory are at different levels.

In the FA model:

```json
  "buildOption": {
    "sourceOption": {
      "workers": [
        "./src/main/ets/workers/worker.ts"
      ]
    }
  }
```

In the stage model:

```json
  "buildOption": {
    "sourceOption": {
      "workers": [
        "./src/main/ets/pages/workers/worker.ts"
      ]
    }
  }
```


### postMessage<sup>9+</sup>

postMessage(message: Object, options?: PostMessageOptions): void

Sends a message to the worker thread. The data type of the message must be sequenceable. For details about the sequenceable data types, see [More Information](#more-information).

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type                                     | Mandatory| Description                                                        |
| ------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| message | Object                                    | Yes  | Message to be sent to the worker thread.                                        |
| options | [PostMessageOptions](#postmessageoptions) | No  | **ArrayBuffer** instances that can be transferred. The **transferList** array cannot contain **null**.|

**Example**

```js
const workerInstance = new worker.ThreadWorker("workers/worker.js");

workerInstance.postMessage("hello world");

var buffer = new ArrayBuffer(8);
workerInstance.postMessage(buffer, [buffer]);
```


### on<sup>9+</sup>

on(type: string, listener: WorkerEventListener): void

Adds an event listener for the worker thread. This API provides the same functionality as [addEventListener<sup>9+</sup>](#addeventlistener9).

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type                                        | Mandatory| Description                  |
| -------- | -------------------------------------------- | ---- | ---------------------- |
| type     | string                                       | Yes  | Type of the event to listen for.      |
| listener | [WorkerEventListener](#workereventlistener9) | Yes| Callback to invoke when an event of the specified type occurs. Callback to invoke when an event of the specified type occurs.|

**Example**

```js
const workerInstance = new worker.ThreadWorker("workers/worker.js");
workerInstance.on("alert", (e)=>{
    console.log("alert listener callback");
})
```


### once<sup>9+</sup>

once(type: string, listener: WorkerEventListener): void

Adds an event listener for the worker thread and removes the event listener after it is invoked once.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type                                        | Mandatory| Description                  |
| -------- | -------------------------------------------- | ---- | ---------------------- |
| type     | string                                       | Yes  | Type of the event to listen for.      |
| listener | [WorkerEventListener](#workereventlistener9) | Yes| Callback to invoke when an event of the specified type occurs. Callback to invoke when an event of the specified type occurs.|

**Example**

```js
const workerInstance = new worker.ThreadWorker("workers/worker.js");
workerInstance.once("alert", (e)=>{
    console.log("alert listener callback");
})
```


### off<sup>9+</sup>

off(type: string, listener?: WorkerEventListener): void

Removes an event listener for the worker thread. This API provides the same functionality as [removeEventListener<sup>9+</sup>](#removeeventlistener9).

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type                                        | Mandatory| Description                        |
| -------- | -------------------------------------------- | ---- | ---------------------------- |
| type     | string                                       | Yes  | Type of the event for which the event listener is to be removed.        |
| listener | [WorkerEventListener](#workereventlistener9) | No| Callback to invoke when an event of the specified type occurs. Callback of the event listener to remove.|

**Example**

```js
const workerInstance = new worker.ThreadWorker("workers/worker.js");
// Use on, once, or addEventListener to add a listener for the "alert" event, and use off to remove the listener.
workerInstance.off("alert");
```


### terminate<sup>9+</sup>

terminate(): void

Terminates the worker thread to stop it from receiving messages.

**System capability**: SystemCapability.Utils.Lang

**Example**

```js
const workerInstance = new worker.ThreadWorker("workers/worker.js");
workerInstance.terminate();
```


### onexit<sup>9+</sup>

onexit?: (code: number) =&gt; void

Defines the event handler to be called when the worker thread exits. The handler is executed in the host thread.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| code   | number | Yes  | Code indicating the worker thread exit state.|

**Example**

```js
const workerInstance = new worker.ThreadWorker("workers/worker.js");
workerInstance.onexit = function(e) {
    console.log("onexit");
}

// onexit is executed in either of the following ways:
// Main thread:
workerInstance.terminate();

// Worker thread:
//parentPort.close()
```


### onerror<sup>9+</sup>

onerror?: (err: ErrorEvent) =&gt; void

Defines the event handler to be called when an exception occurs during worker execution. The event handler is executed in the host thread.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type                     | Mandatory| Description      |
| ------ | ------------------------- | ---- | ---------- |
| err    | [ErrorEvent](#errorevent) | Yes  | Error data.|

**Example**

```js
const workerInstance = new worker.ThreadWorker("workers/worker.js");
workerInstance.onerror = function(e) {
    console.log("onerror");
}
```


### onmessage<sup>9+</sup>

onmessage?: (event: MessageEvents) =&gt; void

Defines the event handler to be called when the host thread receives a message sent by the worker thread through **parentPort.postMessage**. The event handler is executed in the host thread.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type                            | Mandatory| Description                  |
| ------ | -------------------------------- | ---- | ---------------------- |
| event  | [MessageEvents](#messageevents9) | Yes  | Message received.|

**Example**

```js
const workerInstance = new worker.ThreadWorker("workers/worker.js");
workerInstance.onmessage = function(e) {
    // e: MessageEvents. The usage is as follows:
    // let data = e.data;
    console.log("onmessage");
}
```


### onmessageerror<sup>9+</sup>

onmessageerror?: (event: MessageEvents) =&gt; void

Defines the event handler to be called when the worker thread receives a message that cannot be serialized. The event handler is executed in the host thread.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type                            | Mandatory| Description      |
| ------ | -------------------------------- | ---- | ---------- |
| event  | [MessageEvents](#messageevents9) | Yes  | Error data.|

**Example**

```js
const workerInstance = new worker.ThreadWorker("workers/worker.js");
workerInstance.onmessageerror= function(e) {
    console.log("onmessageerror");
}
```


## WorkerEventTarget<sup>9+</sup>

### addEventListener<sup>9+</sup>

addEventListener(type: string, listener: WorkerEventListener): void

Adds an event listener for the worker thread. This API provides the same functionality as [on<sup>9+</sup>](#on9).

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type                                        | Mandatory| Description            |
| -------- | -------------------------------------------- | ---- | ---------------- |
| type     | string                                       | Yes  | Type of the event to listen for.|
| listener | [WorkerEventListener](#workereventlistener9) | Yes  | Callback to invoke when an event of the specified type occurs.    |

**Example**

```js
const workerInstance = new worker.ThreadWorker("workers/worker.js");
workerInstance.addEventListener("alert", (e)=>{
    console.log("alert listener callback");
})
```


### removeEventListener<sup>9+</sup>

removeEventListener(type: string, callback?: WorkerEventListener): void

Removes an event listener for the worker thread. This API provides the same functionality as [off<sup>9+</sup>](#off9).

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type                                        | Mandatory| Description                        |
| -------- | -------------------------------------------- | ---- | ---------------------------- |
| type     | string                                       | Yes  | Type of the event for which the event listener is to be removed.    |
| callback | [WorkerEventListener](#workereventlistener9) | No| Callback to invoke when an event of the specified type occurs. Callback of the event listener to remove.|

**Example**

```js
const workerInstance = new worker.ThreadWorker("workers/worker.js");
workerInstance.addEventListener("alert", (e)=>{
    console.log("alert listener callback");
})
workerInstance.removeEventListener("alert");
```


### dispatchEvent<sup>9+</sup>

dispatchEvent(event: Event): boolean

Dispatches the event defined for the worker thread.

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

```js
const workerInstance = new worker.ThreadWorker("workers/worker.js");
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
workerInstance.dispatchEvent({type:"alert_once", timeStamp:0});
// The event listener created by on will be always valid and will not be proactively deleted.
workerInstance.dispatchEvent({type:"alert_on", timeStamp:0});
workerInstance.dispatchEvent({type:"alert_on", timeStamp:0});
// The event listener created by addEventListener will be always valid and will not be proactively deleted.
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


### removeAllListener<sup>9+</sup>

removeAllListener(): void

Removes all event listeners for the worker thread.

**System capability**: SystemCapability.Utils.Lang

**Example**

```js
const workerInstance = new worker.ThreadWorker("workers/worker.js");
workerInstance.addEventListener("alert", (e)=>{
    console.log("alert listener callback");
})
workerInstance.removeAllListener();
```


## ThreadWorkerGlobalScope<sup>9+</sup>

Implements communication between the worker thread and the host thread. The **postMessage** API is used to send messages to the host thread, and the **close** API is used to terminate the worker thread. The **ThreadWorkerGlobalScope** class inherits from [GlobalScope<sup>9+</sup>](#globalscope9).


### postMessage<sup>9+</sup>

postMessage(messageObject: Object, options?: PostMessageOptions): void

Sends a message to the host thread from the worker thread.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type                                     | Mandatory| Description                                                        |
| ------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| message | Object                                    | Yes  | Message to be sent to the worker thread.                                      |
| options | [PostMessageOptions](#postmessageoptions) | No  | **ArrayBuffer** instances that can be transferred. The **transferList** array cannot contain **null**.|

**Example**

```js
// main.js
import worker from '@ohos.worker';
const workerInstance = new worker.ThreadWorker("workers/worker.js");
workerInstance.postMessage("hello world");
workerInstance.onmessage = function(e) {
    // let data = e.data;
    console.log("receive data from worker.js");
}
```

```js
// worker.js
import worker from '@ohos.worker';
const parentPort = worker.workerPort;
parentPort.onmessage = function(e){
    // let data = e.data;
    parentPort.postMessage("receive data from main.js");
}
```


### close<sup>9+</sup>

close(): void

Terminates the worker thread to stop it from receiving messages.

**System capability**: SystemCapability.Utils.Lang

**Example**

```js
// main.js
import worker from '@ohos.worker';
const workerInstance = new worker.ThreadWorker("workers/worker.js");
```

```js
// worker.js
import worker from '@ohos.worker';
const parentPort = worker.workerPort;
parentPort.onmessage = function(e) {
    parentPort.close()
}
```


### onmessage<sup>9+</sup>

onmessage?: (this: ThreadWorkerGlobalScope, event: MessageEvents) =&gt; void

Defines the event handler to be called when the worker thread receives a message sent by the host thread through **postMessage**. The event handler is executed in the worker thread.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type                                                | Mandatory| Description                    |
| ------ | ---------------------------------------------------- | ---- | ------------------------ |
| this   | [ThreadWorkerGlobalScope](#threadworkerglobalscope9) | Yes  | Caller.        |
| event  | [MessageEvents](#messageevents9)                     | Yes  | Message received.|

**Example**

```js
// main.js
import worker from '@ohos.worker';
const workerInstance = new worker.ThreadWorker("workers/worker.js");
workerInstance.postMessage("hello world");
```

```js
// worker.js
import worker from '@ohos.worker';
const parentPort = worker.workerPort;
parentPort.onmessage = function(e) {
    console.log("receive main.js message");
}
```


### onmessageerror<sup>9+</sup>

onmessageerror?: (this: ThreadWorkerGlobalScope, event: MessageEvents) =&gt; void

Defines the event handler to be called when the worker thread receives a message that cannot be deserialized. The event handler is executed in the worker thread.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type                            | Mandatory| Description      |
| ------ | -------------------------------- | ---- | ---------- |
| this   | [ThreadWorkerGlobalScope](#threadworkerglobalscope9) | Yes  | Caller.        |
| event  | [MessageEvents](#messageevents9) | Yes  | Error data.|

**Example**

```js
// main.js
import worker from '@ohos.worker';
const workerInstance = new worker.ThreadWorker("workers/worker.js");
```

```js
// worker.js
import worker from '@ohos.worker';
const parentPort = worker.workerPort;
parentPort.onmessageerror = function(e) {
    console.log("worker.js onmessageerror")
}
```


## WorkerEventListener<sup>9+</sup>

(event: Event): void | Promise&lt;void&gt;

Implements event listening.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description          |
| ------ | --------------- | ---- | -------------- |
| event  | [Event](#event) | Yes  | Event class for the callback to invoke.|

**Return value**

| Type                                 | Description                           |
| ------------------------------------- | ------------------------------- |
| void&nbsp;\|&nbsp;Promise&lt;void&gt; | Returns no value or returns a **Promise**.|

**Example**

```js
const workerInstance = new worker.ThreadWorker("workers/worker.js");
workerInstance.addEventListener("alert", (e)=>{
    console.log("alert listener callback");
})
```


## GlobalScope<sup>9+</sup>

Implements the running environment of the worker thread. The **GlobalScope** class inherits from [WorkerEventTarget](#workereventtarget9).

### Attributes

**System capability**: SystemCapability.Utils.Lang

| Name| Type                                                        | Readable| Writable| Description                                 |
| ---- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------- |
| name | string                                                       | Yes  | No  | **Worker** instance specified when there is a new **Worker** instance.|
| self | [GlobalScope](#globalscope9)&nbsp;&amp;&nbsp;typeof&nbsp;globalThis | Yes  | No  | **GlobalScope** itself.                    |


### onerror<sup>9+</sup>

onerror?: (ev: ErrorEvent) =&gt; void

Defines the event handler to be called when an exception occurs during worker execution. The event handler is executed in the worker thread.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type                     | Mandatory| Description      |
| ------ | ------------------------- | ---- | ---------- |
| ev     | [ErrorEvent](#errorevent) | Yes  | Error data.|

**Example**

```js
// main.js
import worker from '@ohos.worker';
const workerInstance = new worker.ThreadWorker("workers/worker.js")
```

```js
// worker.js
import worker from '@ohos.worker';
const parentPort = worker.workerPort
parentPort.onerror = function(e){
    console.log("worker.js onerror")
}
```

## MessageEvents<sup>9+</sup>

Holds the data transferred between worker threads.

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Readable| Writable| Description              |
| ---- | ---- | ---- | ---- | ------------------ |
| data | any  | Yes  | No  | Data transferred between threads.|

## Worker<sup>(deprecated)</sup>


Before using the following APIs, you must create a **Worker** instance. The **Worker** class inherits from [EventTarget](#eventtarget).

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
| scriptURL | string                          | Yes  | Directory of the script to be executed by the **Worker** instance.<br>In the FA or stage model, DevEco Studio creates a **Worker** project in either of the following scenarios:<br>(a) The script directory is at the same level as the **pages** directory.<br>(b) The script directory is at a different level from the **pages** directory.|
| options   | [WorkerOptions](#workeroptions) | No  | Options that can be set for the **Worker** instance.                                          |

**Return value**

| Type  | Description                                                     |
| ------ | --------------------------------------------------------- |
| Worker | Returns the **Worker** instance created; returns **undefined** if the **Worker** instance fails to be created.|

**Example**

```js
import worker from '@ohos.worker';
// Create a Worker instance.

// In the FA model, the worker script directory and pages directory are at the same level.
const workerFAModel01 = new worker.Worker("workers/worker.js", {name:"first worker in FA model"});
// In the FA model, the worker script directory and pages directory are at different levels.
const workerFAModel02 = new worker.Worker("../workers/worker.js");

// In the stage model, the worker script directory and pages directory are at the same level.
const workerStageModel01 = new worker.Worker('entry/ets/workers/worker.ts', {name:"first worker in Stage model"});
// In the stage model, the worker script directory and pages directory are at different levels.
const workerStageModel02 = new worker.Worker('entry/ets/pages/workers/worker.ts');

// For the script URL "entry/ets/workers/worker.ts" in the stage model:
// entry is the value of the name attribute under module in the module.json5 file.
// ets indicates the programming language in use.
```
Depending on whether the worker script directory and **pages** directory are at the same level, you may need to configure the **buildOption** attribute in the **build-profile.json5** file.

(1) The worker script directory and **pages** directory are at the same level.

In the FA model:

```json
  "buildOption": {
    "sourceOption": {
      "workers": [
        "./src/main/ets/MainAbility/workers/worker.ts"
      ]
    }
  }
```
In the stage model:
```json
  "buildOption": {
    "sourceOption": {
      "workers": [
        "./src/main/ets/workers/worker.ts"
      ]
    }
  }
```
(2) The worker script directory and **pages** directory are at different levels.

In the FA model:
```json
  "buildOption": {
    "sourceOption": {
      "workers": [
        "./src/main/ets/workers/worker.ts"
      ]
    }
  }
```
In the stage model:
```json
  "buildOption": {
    "sourceOption": {
      "workers": [
        "./src/main/ets/pages/workers/worker.ts"
      ]
    }
  }
```
### postMessage<sup>(deprecated)</sup>

postMessage(message: Object, options?: PostMessageOptions): void

Sends a message to the worker thread. The data type of the message must be sequenceable. For details about the sequenceable data types, see [More Information](#more-information).

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [ThreadWorker.postMessage<sup>9+</sup>](#postmessage9) instead.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type                                     | Mandatory| Description                                                        |
| ------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| message | Object                                    | Yes  | Message to be sent to the worker thread.                                        |
| options | [PostMessageOptions](#postmessageoptions) | No  | **ArrayBuffer** instances that can be transferred. The **transferList** array cannot contain **null**.|

**Example**

```js
const workerInstance = new worker.Worker("workers/worker.js");

workerInstance.postMessage("hello world");

var buffer = new ArrayBuffer(8);
workerInstance.postMessage(buffer, [buffer]);
```


### on<sup>(deprecated)</sup>

on(type: string, listener: EventListener): void

Adds an event listener for the worker thread. This API provides the same functionality as [addEventListener<sup>(deprecated)</sup>](#addeventlistenerdeprecated).

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [ThreadWorker.on<sup>9+</sup>](#on9) instead.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type                           | Mandatory| Description            |
| -------- | ------------------------------- | ---- | ---------------- |
| type     | string                          | Yes  | Type of the event to listen for.|
| listener | [EventListener](#eventlistener) | Yes  | Callback to invoke when an event of the specified type occurs.      |

**Example**

```js
const workerInstance = new worker.Worker("workers/worker.js");
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

| Name  | Type                           | Mandatory| Description            |
| -------- | ------------------------------- | ---- | ---------------- |
| type     | string                          | Yes  | Type of the event to listen for.|
| listener | [EventListener](#eventlistener) | Yes  | Callback to invoke when an event of the specified type occurs.      |

**Example**

```js
const workerInstance = new worker.Worker("workers/worker.js");
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

| Name  | Type                           | Mandatory| Description                |
| -------- | ------------------------------- | ---- | -------------------- |
| type     | string                          | Yes  | Type of the event for which the event listener is to be removed.|
| listener | [EventListener](#eventlistener) | No  | Callback of the event listener to remove.    |

**Example**

```js
const workerInstance = new worker.Worker("workers/worker.js");
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

```js
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.terminate();
```


### onexit<sup>(deprecated)</sup>

onexit?: (code: number) =&gt; void

Defines the event handler to be called when the worker thread exits. The handler is executed in the host thread.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [ThreadWorker.onexit<sup>9+</sup>](#onexit9) instead.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| code   | number | Yes  | Code indicating the worker thread exit state.|

**Example**

```js
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.onexit = function(e) {
    console.log("onexit");
}

// onexit is executed in either of the following ways:
// Main thread:
workerInstance.terminate();

// Worker thread:
//parentPort.close()
```


### onerror<sup>(deprecated)</sup>

onerror?: (err: ErrorEvent) =&gt; void

Defines the event handler to be called when an exception occurs during worker execution. The event handler is executed in the host thread.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [ThreadWorker.onerror<sup>9+</sup>](#onerror9) instead.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type                     | Mandatory| Description      |
| ------ | ------------------------- | ---- | ---------- |
| err    | [ErrorEvent](#errorevent) | Yes  | Error data.|

**Example**

```js
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.onerror = function(e) {
    console.log("onerror");
}
```


### onmessage<sup>(deprecated)</sup>

onmessage?: (event: MessageEvent) =&gt; void

Defines the event handler to be called when the host thread receives a message sent by the worker thread through **parentPort.postMessage**. The event handler is executed in the host thread.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [ThreadWorker.onmessage<sup>9+</sup>](#onmessage9) instead.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type                          | Mandatory| Description                  |
| ------ | ------------------------------ | ---- | ---------------------- |
| event  | [MessageEvent](#messageeventt) | Yes  | Message received.|

**Example**

```js
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.onmessage = function(e) {
    // e: MessageEvent. The usage is as follows:
    // let data = e.data;
    console.log("onmessage");
}
```


### onmessageerror<sup>(deprecated)</sup>

onmessageerror?: (event: MessageEvent) =&gt; void

Defines the event handler to be called when the worker thread receives a message that cannot be serialized. The event handler is executed in the host thread.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [ThreadWorker.onmessageerror<sup>9+</sup>](#onmessageerror9) instead.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type                          | Mandatory| Description      |
| ------ | ------------------------------ | ---- | ---------- |
| event  | [MessageEvent](#messageeventt) | Yes  | Error data.|

**Example**

```js
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.onmessageerror= function(e) {
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

| Name  | Type                           | Mandatory| Description            |
| -------- | ------------------------------- | ---- | ---------------- |
| type     | string                          | Yes  | Type of the event to listen for.|
| listener | [EventListener](#eventlistener) | Yes  | Callback to invoke when an event of the specified type occurs.    |

**Example**

```js
const workerInstance = new worker.Worker("workers/worker.js");
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

| Name  | Type                           | Mandatory| Description                    |
| -------- | ------------------------------- | ---- | ------------------------ |
| type     | string                          | Yes  | Type of the event for which the event listener is to be removed.|
| callback | [EventListener](#eventlistener) | No  | Callback of the event listener to remove.        |

**Example**

```js
const workerInstance = new worker.Worker("workers/worker.js");
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

```js
const workerInstance = new worker.Worker("workers/worker.js");

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
workerInstance.dispatchEvent({type:"alert_once", timeStamp:0});
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

```js
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.addEventListener("alert", (e)=>{
    console.log("alert listener callback");
})
workerInstance.removeAllListener();
```


## DedicatedWorkerGlobalScope<sup>(deprecated)</sup>

Implements communication between the worker thread and the host thread. The **postMessage** API is used to send messages to the host thread, and the **close** API is used to terminate the worker thread. This class inherits from [WorkerGlobalScope](#workerglobalscope).

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [ThreadWorkerGlobalScope<sup>9+</sup>](#threadworkerglobalscope9) instead.

### postMessage<sup>(deprecated)</sup>

postMessage(messageObject: Object, options?: PostMessageOptions): void

Sends a message to the host thread from the worker thread.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [ThreadWorkerGlobalScope<sup>9+</sup>](#threadworkerglobalscope9).postMessage<sup>9+</sup> instead.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type                                     | Mandatory| Description                                                        |
| ------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| message | Object                                    | Yes  | Message to be sent to the worker thread.                                      |
| options | [PostMessageOptions](#postmessageoptions) | No  | **ArrayBuffer** instances that can be transferred. The **transferList** array cannot contain **null**.|

**Example**

```js
// main.js
import worker from '@ohos.worker';
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.postMessage("hello world");
workerInstance.onmessage = function(e) {
    // let data = e.data;
    console.log("receive data from worker.js");
}
```
```js
// worker.js
import worker from '@ohos.worker';
const parentPort = worker.parentPort;
parentPort.onmessage = function(e){
    // let data = e.data;
    parentPort.postMessage("receive data from main.js");
}
```


### close<sup>(deprecated)</sup>

close(): void

Terminates the worker thread to stop it from receiving messages.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [ThreadWorkerGlobalScope<sup>9+</sup>](#threadworkerglobalscope9).close<sup>9+</sup> instead.

**System capability**: SystemCapability.Utils.Lang

**Example**

```js
// main.js
import worker from '@ohos.worker';
const workerInstance = new worker.Worker("workers/worker.js");
```
```js
// worker.js
import worker from '@ohos.worker';
const parentPort = worker.parentPort;
parentPort.onmessage = function(e) {
    parentPort.close()
}
```


### onmessage<sup>(deprecated)</sup>

onmessage?: (this: DedicatedWorkerGlobalScope, event: MessageEvent) =&gt; void

Defines the event handler to be called when the worker thread receives a message sent by the host thread through **postMessage**. The event handler is executed in the worker thread.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [ThreadWorkerGlobalScope<sup>9+</sup>](#threadworkerglobalscope9).onmessage<sup>9+</sup> instead.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type                                                        | Mandatory| Description                    |
| ------ | ------------------------------------------------------------ | ---- | ------------------------ |
| this   | [DedicatedWorkerGlobalScope](#dedicatedworkerglobalscopedeprecated) | Yes  | Caller.        |
| event  | [MessageEvent](#messageeventt)                               | Yes  | Message received.|

**Example**

```js
// main.js
import worker from '@ohos.worker';
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.postMessage("hello world");
```
```js
// worker.js
import worker from '@ohos.worker';
const parentPort = worker.parentPort;
parentPort.onmessage = function(e) {
    console.log("receive main.js message");
}
```


### onmessageerror<sup>(deprecated)</sup>

onmessageerror?: (this: DedicatedWorkerGlobalScope, event: MessageEvent) =&gt; void

Defines the event handler to be called when the worker thread receives a message that cannot be deserialized. The event handler is executed in the worker thread.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [ThreadWorkerGlobalScope<sup>9+</sup>](#threadworkerglobalscope9).onmessageerror<sup>9+</sup> instead.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type                          | Mandatory| Description      |
| ------ | ------------------------------ | ---- | ---------- |
| this   | [DedicatedWorkerGlobalScope](#dedicatedworkerglobalscopedeprecated) | Yes  | Caller.|
| event  | [MessageEvent](#messageeventt) | Yes  | Error data.|

**Example**

```js
// main.js
import worker from '@ohos.worker';
const workerInstance = new worker.Worker("workers/worker.js");
```
```js
// worker.js
import worker from '@ohos.worker';
const parentPort = worker.parentPort;
parentPort.onmessageerror = function(e) {
    console.log("worker.js onmessageerror")
}
```


## PostMessageOptions

Specifies the object whose ownership needs to be transferred during data transfer. The object must be **ArrayBuffer**.

**System capability**: SystemCapability.Utils.Lang

| Name    | Type    | Readable| Writable| Description                             |
| -------- | -------- | ---- | ---- | --------------------------------- |
| transfer | Object[] | Yes  | Yes  | **ArrayBuffer** array used to transfer the ownership.|


## Event

Defines the event.

**System capability**: SystemCapability.Utils.Lang

| Name     | Type  | Readable| Writable| Description                              |
| --------- | ------ | ---- | ---- | ---------------------------------- |
| type      | string | Yes  | No  | Type of the event.                  |
| timeStamp | number | Yes  | No  | Timestamp (accurate to millisecond) when the event is created.|


## EventListener<sup>(deprecated)</sup>

(evt: Event): void | Promise&lt;void&gt;

Implements event listening.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [WorkerEventListener<sup>9+</sup>](#workereventlistener9) instead.

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

```js
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.addEventListener("alert", (e)=>{
    console.log("alert listener callback");
})
```


## ErrorEvent

Provides detailed information about the exception that occurs during worker execution. The **ErrorEvent** class inherits from [Event](#event).

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

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Readable| Writable| Description              |
| ---- | ---- | ---- | ---- | ------------------ |
| data | T    | Yes  | No  | Data transferred between threads.|


## WorkerGlobalScope<sup>(deprecated)</sup>

Implements the running environment of the worker thread. The **WorkerGlobalScope** class inherits from [EventTarget](#eventtarget).

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [GlobalScope<sup>9+</sup>](#globalscope9) instead.

### Attributes

**System capability**: SystemCapability.Utils.Lang

| Name| Type                                                        | Readable| Writable| Description                                 |
| ---- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------- |
| name | string                                                       | Yes  | No  | **Worker** instance specified when there is a new **Worker** instance.|
| self | [WorkerGlobalScope](#workerglobalscope)&nbsp;&amp;&nbsp;typeof&nbsp;globalThis | Yes  | No  | **WorkerGlobalScope**.              |


### onerror<sup>(deprecated)</sup>

onerror?: (ev: ErrorEvent) =&gt; void

Defines the event handler to be called when an exception occurs during worker execution. The event handler is executed in the worker thread.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [GlobalScope<sup>9+</sup>](#globalscope9).onerror instead.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type                     | Mandatory| Description      |
| ------ | ------------------------- | ---- | ---------- |
| ev     | [ErrorEvent](#errorevent) | Yes  | Error data.|

**Example**

```js
// main.js
import worker from '@ohos.worker';
const workerInstance = new worker.Worker("workers/worker.js")
```
```js
// worker.js
import worker from '@ohos.worker';
const parentPort = worker.parentPort
parentPort.onerror = function(e){
    console.log("worker.js onerror")
}
```


## More Information

### Sequenceable Data Types
| Type               | Remarks                                  | Supported|
| ------------------ | -------------------------------------- | -------- |
| All primitive types| The Symbol type is not included.                          | Yes      |
| Date               |                                        | Yes      |
| String             |                                        | Yes      |
| RegExp             |                                        | Yes      |
| Array              |                                        | Yes      |
| Map                |                                        | Yes      |
| Set                |                                        | Yes      |
| Object             | Only plain objects are supported. Objects with functions are not supported.| Yes      |
| ArrayBuffer        | The transfer capability is provided.                      | Yes      |
| TypedArray         |                                        | Yes      |

Exception: When an object created through a custom class is passed, no serialization error occurs. However, the attributes (such as Function) of the custom class cannot be passed through serialization.
> **NOTE**<br>
> An FA project of API version 9 is used as an example.

```js
// main.js
import worker from '@ohos.worker';
const workerInstance = new worker.ThreadWorker("workers/worker.js");
workerInstance.postMessage("message from main to worker");
workerInstance.onmessage = function(d) {
  // When the worker thread passes obj2, data contains obj2, excluding the Init or SetName method.
  let data = d.data;
}
```
```js
// worker.js
import worker from '@ohos.worker';
const parentPort = worker.workerPort;
class MyModel {
    name = "undefined"
    Init() {
        this.name = "MyModel"
    }
}
parentPort.onmessage = function(d) {
    console.log("worker.js onmessage");
    let data = d.data;
    let func1 = function() {
        console.log("post message is function");
    }
    let obj1 = {
        "index": 2,
        "name1": "zhangshan",
        setName() {
            this.index = 3;
        }
    }
    let obj2 = new MyModel();
    // parentPort.postMessage(func1); A serialization error occurs when passing func1.
    // parentPort.postMessage(obj1); A serialization error occurs when passing obj1.
    parentPort.postMessage(obj2);     // No serialization error occurs when passing obj2.
}
parentPort.onmessageerror = function(e) {
    console.log("worker.js onmessageerror");
}
parentPort.onerror = function(e) {
    console.log("worker.js onerror");
}
```

### Memory Model
The worker thread is implemented based on the actor model. In the worker interaction process, the JS main thread can create multiple worker threads, each of which are isolated and transfer data through sequentialization. They complete computing tasks and return the result to the main thread.

Each actor concurrently processes tasks of the main thread. For each actor, there is a message queue and a single-thread execution module. The message queue receives requests from the main thread and other actors; the single-thread execution module serially processes requests, sends requests to other actors, and creates new actors. These isolated actors use the asynchronous mode and can run concurrently.

### Precautions
- Currently, a maximum of seven workers can co-exist.
- In API version 8 and earlier versions, when the number of **Worker** instances exceeds the upper limit, the error "Too many workers, the number of workers exceeds the maximum." is thrown.
- Since API version 9, when the number of **Worker** instances exceeds the upper limit, the business error "Worker initialization failure, the number of workers exceeds the maximum" is thrown.
- To proactively destroy a worker thread, you can call **terminate()** or **parentPort.close()** of the newly created **Worker** instance.
- Since API version 9, if a **Worker** instance in a non-running state (such as destroyed or being destroyed) calls an API, a business error is thrown.
- Creating and terminating worker threads consume performance. Therefore, you are advised to manage available workers and reuse them.
- Do not use both **new worker.Worker** and **new worker.ThreadWorker** to create a **Worker** project. Otherwise, **Worker** functions abnormally. Since API version 9, you are advised to use [new worker.ThreadWorker](#constructor9). In API version 8 and earlier versions, you are advised to use [new worker.Worker](#constructordeprecated).

## Sample Code
> **NOTE**<br>
> Two projects of API version 9 are used as an example. <br>Only the FA model is supported in API version 8 and earlier versions. If you want to use API version 8 or earlier, change the API for constructing the **Worker** instance and the API for creating an object in the worker thread for communicating with the main thread.
### FA Model

```js
// main.js (The following assumes that the worker script directory and pages directory are at the same level.)
import worker from '@ohos.worker';
// Create a Worker instance in the main thread.
const workerInstance = new worker.ThreadWorker("workers/worker.ts");
// Create either a .json or .ts file.
// const workerInstance = new worker.ThreadWorker("workers/worker.js");

// In versions earlier than API version 9, use the following to create a Worker instance in the main thread.
// const workerInstance = new worker.Worker("workers/worker.js");

// The main thread transfers information to the worker thread.
workerInstance.postMessage("123");

// The main thread receives information from the worker thread.
workerInstance.onmessage = function(e) {
    // data carries the information sent by the worker thread.
    let data = e.data;
    console.log("main.js onmessage");

    // Terminate the Worker instance.
    workerInstance.terminate();
}

// Call onexit().
workerInstance.onexit = function() {
    console.log("main.js terminate");
}
```
```js
// worker.ts
import worker from '@ohos.worker';

// Create an object in the worker thread for communicating with the main thread.
const parentPort = worker.workerPort

// In versions earlier than API version 9, use the following to create an object in the worker thread for communicating with the main thread.
// const parentPort = worker.parentPort

// The worker thread receives information from the main thread.
parentPort.onmessage = function(e) {
    // data carries the information sent by the main thread.
    let data = e.data;
    console.log("worker.ts onmessage");

    // The worker thread sends information to the main thread.
    parentPort.postMessage("123")
}

// Trigger a callback when an error occurs in the worker thread.
parentPort.onerror= function(e) {
    console.log("worker.ts onerror");
}
```
Configuration of the **build-profile.json5** file:
```json
  "buildOption": {
    "sourceOption": {
      "workers": [
        "./src/main/ets/MainAbility/workers/worker.ts"
      ]
    }
  }
```
### Stage Model
```js
// main.js (The following assumes that the worker script directory and pages directory are at different levels.)
import worker from '@ohos.worker';

// Create a Worker instance in the main thread.
const workerInstance = new worker.ThreadWorker("entry/ets/pages/workers/worker.ts");
// Create either a .json or .ts file.
// const workerInstance = new worker.ThreadWorker("entry/ets/pages/workers/worker.js");

// The main thread transfers information to the worker thread.
workerInstance.postMessage("123");

// The main thread receives information from the worker thread.
workerInstance.onmessage = function(e) {
    // data carries the information sent by the worker thread.
    let data = e.data;
    console.log("main.js onmessage");

    // Terminate the Worker instance.
    workerInstance.terminate();
}
// Call onexit().
workerInstance.onexit = function() {
    console.log("main.js terminate");
}
```
```js
// worker.ts
import worker from '@ohos.worker';

// Create an object in the worker thread for communicating with the main thread.
const parentPort = worker.workerPort

// The worker thread receives information from the main thread.
parentPort.onmessage = function(e) {
    // data carries the information sent by the main thread.
    let data = e.data;
    console.log("worker.ts onmessage");

    // The worker thread sends information to the main thread.
    parentPort.postMessage("123")
}

// Trigger a callback when an error occurs in the worker thread.
parentPort.onerror= function(e) {
    console.log("worker.ts onerror");
}
```
Configuration of the **build-profile.json5** file:
```json
  "buildOption": {
    "sourceOption": {
      "workers": [
        "./src/main/ets/pages/workers/worker.ts"
      ]
    }
  }
```
<!--no_check-->
