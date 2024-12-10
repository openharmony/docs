# Communication Between Threads

## Introduction

During application development, some time-consuming tasks are executed in subthreads to prevent the main thread from being blocked, delivering a better user experience. Generally, a subthread can independently complete its task. However, in most cases, data needs to be transferred from the main thread to the subthread, or the task execution result needs to be returned from the subthread to the main thread. Therefore, communication between the main thread and subthread is necessary. This topic describes several example scenarios to show how to implement data communication between the main thread and subthreads in OpenHarmony application development.

## Independent Execution of a Task

If a time-consuming task can be executed independently by a subthread, the subthread only needs to return the execution result to the main thread after the task is executed. You can perform the following operations to implement this scenario.

First, import the TaskPool module.

```typescript
import { taskpool } from '@kit.ArkTS';
```
Then, implement the task that the subthread needs to perform.
```typescript
@Concurrent // Methods executed in the task must be decorated by @Concurrent. Otherwise, they cannot be called.
export function loadPicture(count: number): IconItemSource[] {
  let iconItemSourceList: IconItemSource[] = [];
  // Traverse and add six IconItem data records.
  for (let index = 0; index < count; index++) {
    const numStart: number = index * 6;
    // Six images are used cyclically.
    iconItemSourceList.push(new IconItemSource($r('app.media.nearby'), `item${numStart + 1}`));
    iconItemSourceList.push(new IconItemSource($r('app.media.scan'), `item${numStart + 2}`));
    iconItemSourceList.push(new IconItemSource($r('app.media.shop'), `item${numStart + 3}`));
    iconItemSourceList.push(new IconItemSource($r('app.media.cards'), `item${numStart + 4}`));
    iconItemSourceList.push(new IconItemSource($r('app.media.album'), `item${numStart + 5}`));
    iconItemSourceList.push(new IconItemSource($r('app.media.applet'), `item${numStart + 6}`));
  }
  return iconItemSourceList;
}
```
Finally, call **execute** in the **TaskPool** class to execute the task.
```typescript
......
// Create a task.
let lodePictureTask: taskpool.Task = new taskpool.Task(loadPicture, 30);
// Execute the task and return the result.
taskpool.execute(lodePictureTask).then((res: IconItemSource[]) => {
  // Execution result of the loadPicture API.
  this.iconItemSourceList = res; 
})
......
```

## Simultaneous Execution of Multiple Tasks

If multiple tasks are executed simultaneously, their execution time and result return time vary according to the task complexity. If the main thread requires the execution results of all tasks, you can use the following code snippet:
```typescript
......
let taskGroup: taskpool.TaskGroup = new taskpool.TaskGroup();
taskGroup.addTask(new taskpool.Task(loadPicture, 30));
taskGroup.addTask(new taskpool.Task(loadPicture, 20));
taskGroup.addTask(new taskpool.Task(loadPicture, 10));
taskpool.execute(taskGroup).then((ret: IconItemSource[][]) => {
  for (let i = 0; i < ret.length; i++) {
    for (let j = 0; j < ret[i].length; j++) {
      this.iconItemSourceList.push(ret[i][j]);
    }
  }
})
......
```
In this scenario, all the tasks to be executed are placed in a task group. After all the tasks in the task group are executed, the execution result of each task is placed in an array and returned to the main thread. The main thread can obtain all task execution results at a time.

In addition, if a task needs to process a large amount of data (for example, a list contains 10,000 data records), it is time-consuming to process all the data in one task. In this case, you can split the data into multiple sublists, allocate one task for each sublist, and combine the results of all the tasks. This pattern reduces the processing time and improves user experience.

## Communication with the Main Thread During Task Execution

If a subthread needs to periodically notify the main thread of the task status and data changes, or needs to return a large amount of data by segment (for example, a large amount of data read from the database), you can perform the following operations:

First, implement a method to receive messages sent by the task.
```typescript
function notice(data: number): void {
  console.info("The subthread task has been executed. Total images loaded:", data)
}
```
Then, add **sendData()** to the task to enable the subthread to send messages to the main thread.
```typescript
// Use sendData to notify the main thread of information in real time.
@Concurrent
export function loadPictureSendData(count: number): IconItemSource[] {
  let iconItemSourceList: IconItemSource[] = [];
  // Traverse and add six IconItem data records.
  for (let index = 0; index < count; index++) {
    const numStart: number = index * 6;
    // Six images are used cyclically.
    iconItemSourceList.push(new IconItemSource($r('app.media.nearby'), `item${numStart + 1}`));
    iconItemSourceList.push(new IconItemSource($r('app.media.scan'), `item${numStart + 2}`));
    iconItemSourceList.push(new IconItemSource($r('app.media.shop'), `item${numStart + 3}`));
    iconItemSourceList.push(new IconItemSource($r('app.media.cards'), `item${numStart + 4}`));
    iconItemSourceList.push(new IconItemSource($r('app.media.album'), `item${numStart + 5}`));
    iconItemSourceList.push(new IconItemSource($r('app.media.applet'), `item${numStart + 6}`));
    taskpool.Task.sendData(iconItemSourceList.length);
  }
  return iconItemSourceList;
}
```
Finally, use **onReceiveData()** to enable the main thread to receive messages.
```typescript
......
let lodePictureTask: taskpool.Task = new taskpool.Task(loadPictureSendData, 30);
// Use notice to receive messages sent by the task.
lodePictureTask.onReceiveData(notice);
taskpool.execute(lodePictureTask).then((res: IconItemSource[]) => {
  this.iconItemSourceList = res;
})
......
```
In this way, the main thread can receive the data sent by the task through **notice()**.

## Instant Communication Between the Worker Thread and Main Thread

In ArkTS, Worker provides a limited number of threads that exist for a longer time than TaskPool threads. Multiple tasks may be executed in one [Worker thread](https://docs.openharmony.cn/pages/v4.0/en/application-dev/arkts-utils/worker-introduction.md/), and the execution duration or returned result of each task may be different. The host thread needs to call different methods in the Worker thread according to the actual situation, and the Worker thread needs to return the result to the host thread in time. You can perform the following operations to implement this scenario.

First, create a Worker thread to execute different tasks based on parameters.
```typescript
import { worker, MessageEvents, ThreadWorkerGlobalScope } from '@kit.ArkTS';
 
const workerPort: ThreadWorkerGlobalScope = worker.workerPort;
// The Worker thread receives messages from the main thread and calls the corresponding method based on the data type.
workerPort.onmessage = (e: MessageEvents): void => {
  if (typeof e.data === "string") {
    try {
      // The method to call does not carry an input parameter.
      let res: string = workerPort.callGlobalCallObjectMethod("picData", "setUp", 0) as string;
      console.error("worker: ", res);
    } catch (error) {
      // Exception handling.
      console.error("worker: error code is " + error.code + " error message is " + error.message);
    }
  } else if (e.data instanceof Array) {
    // Return the first four data records.
    workerPort.postMessage(e.data.slice(0, 4));
  }
}
```
Then, create a **Worker** object in the main thread. When the button is touched, **postMessage** is called to send a message to the Worker thread, and **onmessage** of the **Worker** class is used to receive data returned by the Worker thread.
```typescript
import { worker, MessageEvents } from '@kit.ArkTS';
......
@State iconItemSourceList: IconItemSource[] = [];
// Create a Worker object.
workerInstance: worker.ThreadWorker = new worker.ThreadWorker("entry/ets/pages/workers/Worker.ts");
aboutToAppear() {
  // Initialize the Worker object.
  this.initWorker();
  for (let index = 0; index < 20; index++) {
    const numStart: number = index * 6;
    // Six images are used cyclically.
    this.iconItemSourceList.push(new IconItemSource($r('app.media.nearby'), `item${numStart + 1}`));
    this.iconItemSourceList.push(new IconItemSource($r('app.media.scan'), `item${numStart + 2}`));
    this.iconItemSourceList.push(new IconItemSource($r('app.media.shop'), `item${numStart + 3}`));
    this.iconItemSourceList.push(new IconItemSource($r('app.media.cards'), `item${numStart + 4}`));
    this.iconItemSourceList.push(new IconItemSource($r('app.media.album'), `item${numStart + 5}`));
    this.iconItemSourceList.push(new IconItemSource($r('app.media.applet'), `item${numStart + 6}`));
  }
}
initWorker(){
  // Use onmessage to receive data returned by the Worker thread.
  this.workerInstance.onmessage = (e: MessageEvents): void => {
    if (e.data instanceof Array) {
      this.iconItemSourceList = e.data;
    }
 }
}
......
Button ('Change the number of images to five', { type: ButtonType.Normal, stateEffect: true }.)
  .fontSize(14)
  .borderRadius(8)
  .backgroundColor('# 317aff')
  .width(250)
  .height(60)
  .margin({
    top: 30
  })
  .onClick(() => {
    // Transfer data to the Worker thread.
    this.workerInstance.postMessage(this.iconItemSourceList);
  })
......
```
In the sample code, the Worker thread performs two different processing. When the input data is of the string type, it calls **callGlobalCallObjectMethod** to synchronously call the method in the main thread. When the input data is of the array type, it returns the first four data records of the array to the main thread. In this way, instant communication between the main thread and Worker thread can be implemented.

## Worker Thread Synchronously Calls a Method of the Main Thread

If the Worker thread needs to call the method that has been implemented in the main thread, you can perform the following operations:

First, implement the method in the main thread, create a **Worker** object, and register the method on the **Worker** object.
```typescript
import { worker } from '@kit.ArkTS';
// Create a Worker object.
const workerInstance: worker.ThreadWorker = new worker.ThreadWorker("entry/ets/pages/workers/Worker.ts");
 
class PicData {
  public iconItemSourceList: IconItemSource[] = [];
  
  public setUp(): string {
    for (let index = 0; index < 20; index++) {
      const numStart: number = index * 6;
      // Six images are used cyclically.
      this.iconItemSourceList.push(new IconItemSource($r('app.media.nearby'), `item${numStart + 1}`));
      this.iconItemSourceList.push(new IconItemSource($r('app.media.scan'), `item${numStart + 2}`));
      this.iconItemSourceList.push(new IconItemSource($r('app.media.shop'), `item${numStart + 3}`));
      this.iconItemSourceList.push(new IconItemSource($r('app.media.cards'), `item${numStart + 4}`));
      this.iconItemSourceList.push(new IconItemSource($r('app.media.album'), `item${numStart + 5}`));
      this.iconItemSourceList.push(new IconItemSource($r('app.media.applet'), `item${numStart + 6}`));
   }
   return "setUpIconItemSourceList success!";
  }
}
 
let picData = new PicData();
// Register the method on the Worker object.
workerInstance.registerGlobalCallObject("picData", picData);
workerInstance.postMessage("run setUp in picData");
```
Then, use [callGlobalCallObjectMethod](../reference/apis-arkts/js-apis-worker.md#callglobalcallobjectmethod11) of the **Worker** object to call **setUp()** in the main thread.
```typescript
......
try {
  // The method to call does not carry an input parameter.
  let res: string = workerPort.callGlobalCallObjectMethod("picData", "setUp", 0) as string;
  console.error("worker: ", res);
} catch (error) {
  // Exception handling.
  console.error("worker: error code is " + error.code + " error message is " + error.message);
}
......
```


