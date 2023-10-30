# Worker Startup

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

The worker thread is an independent thread running in parallel with the main thread. The thread that creates the worker thread is referred to as the host thread. The URL file passed in during worker creation is executed in the worker thread. The worker thread can process time-consuming operations, but cannot directly operate the UI.

## Modules to Import

```
import worker from '@ohos.worker';
```


## Attributes

**System capability**: SystemCapability.Utils.Lang

| Name      | Type                                                 | Readable| Writable| Description                                |
| ---------- | --------------------------------------------------------- | ---- | ---- | ------------------------------------ |
| parentPort | [DedicatedWorkerGlobalScope](#dedicatedworkerglobalscope) | Yes  | Yes  | Object of the worker thread used to communicate with the host thread.|


## WorkerOptions

Provides options that can be set for the **Worker** instance to create.

**System capability**: SystemCapability.Utils.Lang

| Name| Type | Readable| Writable| Description                  |
| ---- | --------- | ---- | ---- | ---------------------- |
| type | "classic" | Yes  | Yes  | Mode in which the worker thread executes the script.|
| name | string    | Yes  | Yes  | Name of the worker thread.        |


## Worker

Before using the following APIs, you must create a **Worker** instance. The **Worker** class inherits from [EventTarget](#eventtarget).


### constructor

constructor(scriptURL: string, options?: WorkerOptions)

A constructor used to create a **Worker** instance.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type                           | Mandatory| Description                                                        |
| --------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| scriptURL | string                          | Yes  | URL of the script to be executed by the Worker thread. The script is stored in the **workers** directory, which is in the same directory as the **pages** directory of the new DevEco Studio project. If the **workers** directory does not exist, you need to create it.|
| options   | [WorkerOptions](#workeroptions) | No  | Options that can be set for the **Worker** instance.                                          |

**Return value**

| Type  | Description                                                     |
| ------ | --------------------------------------------------------- |
| Worker | Returns the **Worker** instance created; returns **undefined** if the **Worker** instance fails to be created.|

**Example**

```
const workerInstance = new worker.Worker("workers/worker.js", {name:"first worker"});
```


### postMessage

postMessage(message: Object, options?: PostMessageOptions): void

Sends a message to the worker thread. The message data is transferred using the structured clone algorithm.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type                                     | Mandatory| Description                                                        |
| ------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| message | Object                                    | Yes  | Message to be sent to the worker thread.                                        |
| options | [PostMessageOptions](#postmessageoptions) | No  | **ArrayBuffer** instances that can be transferred. The **transferList** array cannot contain **null**.|

**Example**

```
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.postMessage("hello world");
```

```
const workerInstance= new worker.Worker("workers/worker.js");
var buffer = new ArrayBuffer(8);
workerInstance.postMessage(buffer, [buffer]);
```


### on

on(type: string, listener: EventListener): void

Adds an event listener for the worker thread.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type                           | Mandatory| Description            |
| -------- | ------------------------------- | ---- | ---------------- |
| type     | string                          | Yes  | Type of the event to listen for.|
| listener | [EventListener](#eventlistener) | Yes  | Callback to invoke when an event of the specified type occurs.    |

**Example**

```
const workerInstance = new worker.Worker("workers/worker.js")
workerInstance.on("alert", (e)=>{
    console.log("alert listener callback");
})
```


### once

once(type: string, listener: EventListener): void

Adds an event listener for the worker thread and removes the event listener after it is invoked once.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type                           | Mandatory| Description            |
| -------- | ------------------------------- | ---- | ---------------- |
| type     | string                          | Yes  | Type of the event to listen for.|
| listener | [EventListener](#eventlistener) | Yes  | Callback to invoke when an event of the specified type occurs.    |

**Example**

```
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.once("alert", (e)=>{
    console.log("alert listener callback");
})
```


### off

off(type: string, listener?: EventListener): void

Removes an event listener for the worker thread.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type                           | Mandatory| Description                  |
| -------- | ------------------------------- | ---- | ---------------------- |
| type     | string                          | Yes  | Type of the event for which the event listener is removed.  |
| listener | [EventListener](#eventlistener) | No  | Callback of the event listener to remove.|

**Example**

```
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.off("alert");
```


### terminate

terminate(): void

Terminates the worker thread to stop it from receiving messages.

**System capability**: SystemCapability.Utils.Lang

**Example**

```
const workerInstance = new worker.Worker("workers/worker.js")
workerInstance.terminate()
```


### onexit

onexit?: (code: number) =&gt; void

Defines the event handler to be called when the worker thread exits. The handler is executed in the host thread.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| code   | number | No  | Code indicating the worker thread exit state.|

**Example**

```
const workerInstance = new worker.Worker("workers/worker.js")
workerInstance.onexit = function(e) {
    console.log("onexit")
}
```


### onerror

onerror?: (err: ErrorEvent) =&gt; void

Defines the event handler to be called when an exception occurs during worker execution. The event handler is executed in the host thread.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type                     | Mandatory| Description      |
| ------ | ------------------------- | ---- | ---------- |
| err    | [ErrorEvent](#errorevent) | No  | Error data.|

**Example**

```
const workerInstance = new worker.Worker("workers/worker.js")
workerInstance.onerror = function(e) {
    console.log("onerror")
}
```


### onmessage

onmessage?: (event: MessageEvent) =&gt; void

Defines the event handler to be called when the host thread receives a message sent by the worker thread through **parentPort.postMessage**. The event handler is executed in the host thread.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type                         | Mandatory| Description                  |
| ------ | ----------------------------- | ---- | ---------------------- |
| event  | [MessageEvent](#messageevent) | No  | Message received.|

**Example**

```
const workerInstance = new worker.Worker("workers/worker.js")
workerInstance.onmessage = function(e) {
    console.log("onerror")
}
```


### onmessageerror

onmessageerror?: (event: MessageEvent) =&gt; void

Defines the event handler to be called when the worker thread receives a message that cannot be serialized. The event handler is executed in the host thread.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type                         | Mandatory| Description      |
| ------ | ----------------------------- | ---- | ---------- |
| event  | [MessageEvent](#messageevent) | No  | Error data.|

**Example**

```
const workerInstance = new worker.Worker("workers/worker.js")
workerInstance.onmessageerror= function(e) {
    console.log("onmessageerror")
}
```


## EventTarget


### addEventListener

addEventListener(type: string, listener: EventListener): void

Adds an event listener for the worker thread.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type                           | Mandatory| Description            |
| -------- | ------------------------------- | ---- | ---------------- |
| type     | string                          | Yes  | Type of the event to listen for.|
| listener | [EventListener](#eventlistener) | Yes  | Callback to invoke when an event of the specified type occurs.    |

**Example**

```
const workerInstance = new worker.Worker("workers/worker.js")
workerInstance.addEventListener("alert", (e)=>{
    console.log("alert listener callback");
})
```


### removeEventListener

removeEventListener(type: string, callback?: EventListener): void

Removes an event listener for the worker thread.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type                           | Mandatory| Description                  |
| -------- | ------------------------------- | ---- | ---------------------- |
| type     | string                          | Yes  | Type of the event for which the event listener is removed.  |
| callback | [EventListener](#eventlistener) | No  | Callback of the event listener to remove.|

**Example**

```
const workerInstance = new worker.Worker("workers/worker.js")
workerInstance.removeEventListener("alert")
```


### dispatchEvent

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

```
const workerInstance = new worker.Worker("workers/worker.js")
workerInstance.dispatchEvent({type:"alert"})
```


### removeAllListener

removeAllListener(): void

Removes all event listeners for the worker thread.

**System capability**: SystemCapability.Utils.Lang

**Example**

```
const workerInstance = new worker.Worker("workers/worker.js")
workerInstance.removeAllListener({type:"alert"})
```


## DedicatedWorkerGlobalScope

Implements communication between the worker thread and the host thread. The **postMessage** API is used to send messages to the host thread, and the **close** API is used to terminate the worker thread. The **DedicatedWorkerGlobalScope** class inherits from [WorkerGlobalScope](#workerglobalscope).


### postMessage

postMessage(message: Object, options?: PostMessageOptions): void

Sends a message to the host thread from the worker thread.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type                                     | Mandatory| Description                                                        |
| ------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| message | Object                                    | Yes  | Message to be sent to the worker thread.                                        |
| options | [PostMessageOptions](#postmessageoptions) | No  | **ArrayBuffer** instances that can be transferred. The **transferList** array cannot contain **null**.|

**Example**

```
// main.js
import worker from '@ohos.worker';
const workerInstance = new worker.Worker("workers/worker.js")
workerInstance.postMessage("hello world")
workerInstance.onmessage = function(e) {
    console.log("receive data from worker.js")
}
```

```
// worker.js
import worker from '@ohos.worker';
const parentPort = worker.parentPort;
parentPort.onmessage = function(e){
    parentPort.postMessage("receive data from main.js")
}
```


### close

close(): void

Terminates the worker thread to stop it from receiving messages.

**System capability**: SystemCapability.Utils.Lang

**Example**

```
// main.js
import worker from '@ohos.worker';
const workerInstance = new worker.Worker("workers/worker.js")
```

```
// worker.js
import worker from '@ohos.worker';
const parentPort = worker.parentPort;
parentPort.onmessage = function(e) {
    parentPort.close()
}
```


### onmessage

onmessage?: (event: MessageEvent) =&gt; void

Defines the event handler to be called when the worker thread receives a message sent by the host thread through **worker.postMessage**. The event handler is executed in the worker thread.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type                         | Mandatory| Description                  |
| ------ | ----------------------------- | ---- | ---------------------- |
| event  | [MessageEvent](#messageevent) | No  | Message received.|

**Example**

```
// main.js
import worker from '@ohos.worker';
const workerInstance = new worker.Worker("workers/worker.js")
workerInstance.postMessage("hello world")
```

```
// worker.js
import worker from '@ohos.worker';
const parentPort = worker.parentPort;
parentPort.onmessage = function(e) {
    console.log("receive main.js message")
}
```


### onmessageerror

onmessageerror?: (event: MessageEvent) =&gt; void

Defines the event handler to be called when the worker thread receives a message that cannot be deserialized. The event handler is executed in the worker thread.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type                         | Mandatory| Description      |
| ------ | ----------------------------- | ---- | ---------- |
| event  | [MessageEvent](#messageevent) | No  | Error data.|

**Example**

```
// main.js
import worker from '@ohos.worker';
const workerInstance = new worker.Worker("workers/worker.js")
```

```
// worker.js
import worker from '@ohos.worker';
const parentPort = worker.parentPort;
parentPort.onmessageerror= function(e) {
    console.log("worker.js onmessageerror")
}
```


## PostMessageOptions

Specifies the object whose ownership needs to be transferred during data transfer. The object must be **ArrayBuffer**.

**System capability**: SystemCapability.Utils.Lang

| Name    | Type| Readable| Writable| Description                             |
| -------- | -------- | ---- | ---- | --------------------------------- |
| transfer | Object[] | Yes  | Yes  | **ArrayBuffer** array used to transfer the ownership.|


## Event

Defines the event.

**System capability**: SystemCapability.Utils.Lang

| Name     | Type| Readable| Writable| Description                              |
| --------- | -------- | ---- | ---- | ---------------------------------- |
| type      | string   | Yes  | No  | Type of the event.                  |
| timeStamp | number   | Yes  | No  | Timestamp (accurate to millisecond) when the event is created.|


## EventListener

Implements event listening.


### (evt: Event): void | Promise&lt;void&gt;

Specifies the callback to invoke.

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

```
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.addEventListener("alert", (e)=>{
    console.log("alert listener callback");
})
```


## ErrorEvent

Provides detailed information about the exception that occurs during worker execution. The **ErrorEvent** class inherits from [Event](#event).

**System capability**: SystemCapability.Utils.Lang

| Name    | Type| Readable| Writable| Description                |
| -------- | -------- | ---- | ---- | -------------------- |
| message  | string   | Yes  | No  | Information about the exception.|
| filename | string   | Yes  | No  | File where the exception is located.|
| lineno   | number   | Yes  | No  | Serial number of the line where the exception is located.    |
| colno    | number   | Yes  | No  | Serial number of the column where the exception is located.    |
| error    | Object   | Yes  | No  | Type of the exception.          |


## MessageEvent

Holds the data transferred between worker threads.

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Readable| Writable| Description              |
| ---- | -------- | ---- | ---- | ------------------ |
| data | T        | Yes  | No  | Data transferred between threads.|


## WorkerGlobalScope

Implements the running environment of the worker thread. The **WorkerGlobalScope** class inherits from [EventTarget](#eventtarget).

### Attributes

**System capability**: SystemCapability.Utils.Lang

| Name| Type                                                    | Readable| Writable| Description                                   |
| ---- | ------------------------------------------------------------ | ---- | ---- | --------------------------------------- |
| name | string                                                       | Yes  | No  | **Worker** instance specified when there is a new **Worker** instance.|
| self | [WorkerGlobalScope](#workerglobalscope)&nbsp;&amp;&nbsp;typeof&nbsp;globalThis | Yes  | No  | **WorkerGlobalScope**.                |


### onerror

onerror?: (ev: ErrorEvent) =&gt; void

Defines the event handler to be called when an exception occurs during worker execution. The event handler is executed in the worker thread.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type                     | Mandatory| Description      |
| ------ | ------------------------- | ---- | ---------- |
| ev     | [ErrorEvent](#errorevent) | No  | Error data.|

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
## Sample Code

```js
// Main thread (The following assumes that the workers directory and pages directory are at the same level.)
import worker from '@ohos.worker';
// Create a Worker instance in the main thread.
const workerInstance = new worker.Worker("workers/worker.ts");

// The main thread transfers information to the worker thread.
workerInstance.postMessage("123");

// The main thread receives information from the worker thread.
workerInstance.onmessage = function(e) {
    // data carries the information sent by the worker thread.
    let data = e.data;
    console.log("main thread onmessage");

    // Terminate the Worker instance.
    workerInstance.terminate();
}

// Call onexit().
workerInstance.onexit = function() {
    console.log("main thread terminate");
}
```

```js
// worker.ts
import worker from '@ohos.worker';

// Create an object in the worker thread for communicating with the main thread.
const parentPort = worker.parentPort

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
        "./src/main/ets/entryability/workers/worker.ts"
      ]
    }
  }

```
