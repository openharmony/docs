# Worker Startup

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

The worker thread is an independent thread running in parallel with the main thread. The thread that creates the worker thread is referred to as the host thread. The URL file passed in during worker creation is executed in the worker thread. The worker thread can process time-consuming operations, but cannot directly operate the UI.

## Modules to Import

```js
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

| Name  | Type | Readable| Writable| Description                  |
| ------ | --------- | ---- | ---- | ---------------------- |
| name   | string    | Yes  | Yes  | Name of the worker thread.        |


## Worker

Before using the following APIs, you must create a **Worker** instance. The **Worker** class inherits from [EventTarget](#eventtarget).


### constructor

constructor(scriptURL: string, options?: WorkerOptions)

A constructor used to create a **Worker** instance.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type                           | Mandatory| Description                                                        |
| --------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| scriptURL | string                          | Yes  | Directory of the script to be executed by the **Worker** instance.<br>In the FA or stage model, DevEco Studio creates a **Worker** project in either of the following scenarios:<br>(a) The script directory is at the same level as the **pages** directory.<br>(b) The script directory is at a different level from the **pages** directory.
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
### postMessage

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
const workerInstance = new worker.Worker("workers/worker.js");

workerInstance.postMessage("hello world");

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
| listener | [EventListener](#eventlistener) | Yes  | Callback to invoke when an event of the specified type occurs.     |

**Example**

```js
const workerInstance = new worker.Worker("workers/worker.js");
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
| listener | [EventListener](#eventlistener) | Yes  | Callback to invoke when an event of the specified type occurs.     |

**Example**

```js
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
| type     | string                          | Yes  | Type of the event for which the event listener is to be removed.  |
| listener | [EventListener](#eventlistener) | No  | Callback of the event listener to remove.      |

**Example**

```js
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.off("alert");
```


### terminate

terminate(): void

Terminates the worker thread to stop it from receiving messages.

**System capability**: SystemCapability.Utils.Lang

**Example**

```js
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.terminate();
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

```js
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.onexit = function(e) {
    console.log("onexit");
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

```js
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.onerror = function(e) {
    console.log("onerror");
}
```


### onmessage

onmessage?: (event: MessageEvent\<T>) =&gt; void

Defines the event handler to be called when the host thread receives a message sent by the worker thread through **parentPort.postMessage**. The event handler is executed in the host thread.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type                         | Mandatory| Description                  |
| ------ | ----------------------------- | ---- | ---------------------- |
| event  | [MessageEvent](#messageevent) | No  | Message received.|

**Example**

```js
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.onmessage = function(e) {
    // e: MessageEvent<T>. The usage is as follows:
    // let data = e.data;
    console.log("onmessage");
}
```


### onmessageerror

onmessageerror?: (event: MessageEvent\<T>) =&gt; void

Defines the event handler to be called when the worker thread receives a message that cannot be serialized. The event handler is executed in the host thread.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type                         | Mandatory| Description      |
| ------ | ----------------------------- | ---- | ---------- |
| event  | [MessageEvent](#messageevent) | No  | Error data.|

**Example**

```js
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.onmessageerror= function(e) {
    console.log("onmessageerror");
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

```js
const workerInstance = new worker.Worker("workers/worker.js");
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
| type     | string                          | Yes  | Type of the event for which the event listener is to be removed.|
| callback | [EventListener](#eventlistener) | No  | Callback of the event listener to remove.       |

**Example**

```js
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.removeEventListener("alert");
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

```js
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.dispatchEvent({type:"alert"});
```


### removeAllListener

removeAllListener(): void

Removes all event listeners for the worker thread.

**System capability**: SystemCapability.Utils.Lang

**Example**

```js
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.removeAllListener();
```


## DedicatedWorkerGlobalScope

Implements communication between the worker thread and the host thread. The **postMessage** API is used to send messages to the host thread, and the **close** API is used to terminate the worker thread. This class inherits from [WorkerGlobalScope](#workerglobalscope).


### postMessage

postMessage(messageObject: Object, options?: PostMessageOptions): void

Sends a message to the host thread from the worker thread.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type                                     | Mandatory| Description                                                        |
| ------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| message | Object                                    | Yes  | Message to be sent to the worker thread.                                        |
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


### close

close(): void

Terminates the worker thread to stop it from receiving messages.

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


### onmessage

onmessage?: (event: MessageEvent\<T>) =&gt; void

Defines the event handler to be called when the worker thread receives a message sent by the host thread through **postMessage**. The event handler is executed in the worker thread.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type                         | Mandatory| Description                  |
| ------ | ----------------------------- | ---- | ---------------------- |
| event  | [MessageEvent](#messageevent) | No  | Message received.|

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


### onmessageerror

onmessageerror?: (event: MessageEvent\<T>) =&gt; void

Defines the event handler to be called when the worker thread receives a message that cannot be deserialized. The event handler is executed in the worker thread.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type                         | Mandatory| Description      |
| ------ | ----------------------------- | ---- | ---------- |
| event  | [MessageEvent](#messageevent) | No  | Error data.|

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

(evt: Event): void | Promise&lt;void&gt;

Implements event listening.

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

## More Information

### Sequenceable Data Types
| Type                | Remarks                                                     | Supported            |
| ------------------- | -------------------------------------------------------- | -------------------- |
| All primitive types | The Symbol type is not included.                                             | Yes                  |
| Date                |                                                          | Yes                  |
| String              |                                                          | Yes                  |
| RegExp              |                                                          | Yes                  |
| Array               |                                                          | Yes                  |
| Map                 |                                                          | Yes                  |
| Set                 |                                                          | Yes                  |
| Object              | Only plain objects are supported. Objects with functions are not supported.                  | Yes                  |
| ArrayBuffer         | The transfer capability is provided.                                        | Yes                  |
| TypedArray          |                                                          | Yes                  |

Exception: When an object created through a custom class is passed, no serialization error occurs. However, the attributes (such as Function) of the custom class cannot be passed through serialization.
```js
// main.js
import worker from '@ohos.worker';
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.postMessage("message from main to worker");
workerInstance.onmessage = function(d) {
  // When the worker thread passes obj2, data contains obj2, excluding the Init or SetName method.
  let data = d.data;
}
```
```js
// worker.js
import worker from '@ohos.worker';
const parentPort = worker.parentPort;
class MyModel {
    Init() {
        this.name = "wzy"
        this.age = 18
    }
    SetName() {
        this.name = "WZY"
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
- If the number of workers exceeds the upper limit, the error message "Too many workers, the number of workers exceeds the maximum." is displayed.
- To proactively destroy a worker thread, you can call **terminate()** or **parentPort.close()** of the newly created **Worker** instance.
- Creating and terminating worker threads consume performance. Therefore, you are advised to manage available workers and reuse them.

## Sample Code
### FA Model
```js
// main.js (The following assumes that the worker script directory and pages directory are at the same level.)
import worker from '@ohos.worker';
// Create a Worker instance in the main thread.
const workerInstance = new worker.Worker("workers/worker.ts");
// Create either a .json or .ts file.
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
// worker.js
import worker from '@ohos.worker';

// Create an object in the worker thread for communicating with the main thread.
const parentPort = worker.parentPort

// The worker thread receives information from the main thread.
parentPort.onmessage = function(e) {
    // data carries the information sent by the main thread.
    let data = e.data;
    console.log("worker.js onmessage");

    // The worker thread sends information to the main thread.
    parentPort.postMessage("123")
}

// Trigger a callback when an error occurs in the worker thread.
parentPort.onerror= function(e) {
    console.log("worker.js onerror");
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
const workerInstance = new worker.Worker("entry/ets/pages/workers/worker.ts");
// Create either a .json or .ts file.
// const workerInstance = new worker.Worker("entry/ets/pages/workers/worker.js");

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
// worker.js
import worker from '@ohos.worker';

// Create an object in the worker thread for communicating with the main thread.
const parentPort = worker.parentPort

// The worker thread receives information from the main thread.
parentPort.onmessage = function(e) {
    // data carries the information sent by the main thread.
    let data = e.data;
    console.log("worker.js onmessage");

    // The worker thread sends information to the main thread.
    parentPort.postMessage("123")
}

// Trigger a callback when an error occurs in the worker thread.
parentPort.onerror= function(e) {
    console.log("worker.js onerror");
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
