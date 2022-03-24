# Worker Startup

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

A Worker thread is an independent thread running in parallel with the main thread. The thread that creates the Worker thread is referred to as a host thread. The URL file passed in during Worker creation is executed in the Worker thread. The Worker thread can process time-consuming operations, but cannot directly operate the UI.

## Modules to Import

```
import worker from '@ohos.worker';
```


## Attributes

**System capability**: SystemCapability.Utils.Lang

| Name      | Type                                                 | Readable| Writable| Description                                |
| ---------- | --------------------------------------------------------- | ---- | ---- | ------------------------------------ |
| parentPort | [DedicatedWorkerGlobalScope](#dedicatedworkerglobalscope) | Yes  | Yes  | Object of the Worker thread used to communicate with the host thread.|


## WorkerOptions

Provides options that can be set for the **Worker** instance to create.

**System capability**: SystemCapability.Utils.Lang

| Name| Type | Readable| Writable| Description                  |
| ---- | --------- | ---- | ---- | ---------------------- |
| type | "classic" | Yes  | Yes  | Mode in which the Worker thread executes the script.|
| name | string    | Yes  | Yes  | Name of the Worker thread.        |


## Worker

Before using the following APIs, you must construct a **Worker** instance. The **Worker** class inherits from [EventTarget](#eventtarget).


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

Sends a message to the Worker thread. The data is transferred using the structured clone algorithm.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type                                     | Mandatory| Description                                                        |
| ------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| message | Object                                    | Yes  | Data to be sent to the Worker thread.                                        |
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

Adds an event listener for the Worker instance.

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

Adds an event listener for the Worker thread and removes the event listener after it is invoked once.

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

Removes an event listener for the Worker thread.

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

Terminates the Worker thread to stop it from receiving messages.

**System capability**: SystemCapability.Utils.Lang

**Example**

```
const workerInstance = new worker.Worker("workers/worker.js")
workerInstance.terminate()
```


### onexit

onexit?: (code: number) =&gt; void

Defines the event handler to be called when the Worker thread exits. The handler is executed in the host thread.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| code   | number | No  | Code indicating the Worker thread exit state.|

**Example**

```
const workerInstance = new worker.Worker("workers/worker.js")
workerInstance.onexit = function(e) {
    console.log("onexit")
}
```


### onerror

onerror?: (err: ErrorEvent) =&gt; void

Defines the event handler to be called when an exception occurs during Worker execution. The event handler is executed in the host thread.

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

Defines the event handler to be called when the host thread receives a message created by itself and sent by the Worker thread through the **parentPort.postMessage**. The event handler is executed in the host thread.

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

Defines the event handler to be called when the Worker thread receives a message that cannot be serialized. The event handler is executed in the host thread.

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

Adds an event listener for the Worker thread.

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

Removes an event listener for the Worker thread.

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

Dispatches the event defined for the Worker thread.

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

Removes all event listeners for the Worker thread.

**System capability**: SystemCapability.Utils.Lang

**Example**

```
const workerInstance = new worker.Worker("workers/worker.js")
workerInstance.removeAllListener({type:"alert"})
```


## DedicatedWorkerGlobalScope

Implements communication between the Worker thread and the host thread. The **postMessage** API is used to send messages to the host thread, and the **close** API is used to terminate the Worker thread. The **DedicatedWorkerGlobalScope** class inherits from [WorkerGlobalScope](#workerglobalscope).


### postMessage

postMessage(message: Object, options?: PostMessageOptions): void

Sends a message to the host thread from the Worker thread.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type                                     | Mandatory| Description                                                        |
| ------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| message | Object                                    | Yes  | Data to be sent to the Worker thread.                                        |
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

Terminates the Worker thread to stop it from receiving messages.

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

Defines the event handler to be called when the Worker thread receives a message sent by the host thread through **worker.postMessage**. The event handler is executed in the Worker thread.

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

Defines the event handler to be called when the Worker thread receives a message that cannot be deserialized. The event handler is executed in the Worker thread.

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

Provides detailed information about the exception occurred during Worker execution. The **ErrorEvent** class inherits from [Event](#event).

**System capability**: SystemCapability.Utils.Lang

| Name    | Type| Readable| Writable| Description                |
| -------- | -------- | ---- | ---- | -------------------- |
| message  | string   | Yes  | No  | Information about the exception.|
| filename | string   | Yes  | No  | File where the exception is located.|
| lineno   | number   | Yes  | No  | Number of the line where the exception is located.    |
| colno    | number   | Yes  | No  | Number of the column where the exception is located.    |
| error    | Object   | Yes  | No  | Type of the exception.          |


## MessageEvent

Holds the data transferred between Worker threads.

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Readable| Writable| Description              |
| ---- | -------- | ---- | ---- | ------------------ |
| data | T        | Yes  | No  | Data transferred between threads.|


## WorkerGlobalScope

Defines the running environment of the Worker thread. The **WorkerGlobalScope** class inherits from [EventTarget](#eventtarget).

### Attributes

**System capability**: SystemCapability.Utils.Lang

| Name| Type                                                    | Readable| Writable| Description                                   |
| ---- | ------------------------------------------------------------ | ---- | ---- | --------------------------------------- |
| name | string                                                       | Yes  | No  | **Worker** instance specified when there is a new **Worker** instance.|
| self | [WorkerGlobalScope](#workerglobalscope)&nbsp;&amp;&nbsp;typeof&nbsp;globalThis | Yes  | No  | WorkerGlobalScope.                |


### onerror

onerror?: (ev: ErrorEvent) =&gt; void

Defines the event handler to be called when an exception occurs during Worker execution. The event handler is executed in the Worker thread.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type                     | Mandatory| Description      |
| ------ | ------------------------- | ---- | ---------- |
| ev     | [ErrorEvent](#errorevent) | No  | Error data.|

**Example**

```
// main.js
import worker from '@ohos.worker';
const workerInstance = new worker.Worker("workers/worker.js")
```

```
// worker.js
import worker from '@ohos.worker';
const parentPort = worker.parentPort
parentPort.onerror = function(e){
    console.log("worker.js onerror")
}
```
