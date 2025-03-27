# Communication Between Threads

## Overview

During application development, some time-consuming tasks are executed in child threads to prevent the UI main thread from being blocked, delivering a better user experience. Generally, a child thread can independently complete its task. However, in most cases, data needs to be transferred from the host thread to the child thread, or the task execution result needs to be returned from the child thread to the host thread. Therefore, communication between the host thread and child thread is necessary. This topic describes several example scenarios to show how to implement data communication between the host thread and child threads in OpenHarmony application development.

## Independent Execution of a Task

If a time-consuming task can be executed independently by a child thread, the child thread only needs to return the execution result to the host thread after the task is executed. You can perform the following operations to implement this scenario.

First, import the TaskPool module.

```typescript
import { taskpool } from '@kit.ArkTS';
```
Then, implement the task that the child thread needs to perform.
```typescript
@Concurrent // Methods executed in the task must be decorated by @Concurrent. Otherwise, they cannot be called.
export function loadPicture(count: number): IconItemSource[] {
  let iconItemSourceList: IconItemSource[] = [];
  // Add six IconItem data records.
  for (let index = 0; index < count; index++) {
    const numStart: number = index * 6;
    // Use six images in the loop.
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
  // Execution result of the loadPicture method.
  this.iconItemSourceList = res; 
})
......
```

## Simultaneous Execution of Multiple Tasks

When multiple tasks are executed concurrently, their execution times can vary due to differences in complexity, and the timing of their completion is unpredictable. If the host thread requires the execution results of all tasks, you can use the following code snippet:
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
In this scenario, all the tasks to be executed are placed in a task group. After all the tasks in the task group are executed, the execution result of each task is placed in an array and returned to the host thread. The host thread can obtain all task execution results at a time.

In addition, if a task needs to process a large amount of data (for example, a list contains 10,000 data records), it is time-consuming to process all the data in one task. Instead, you can split the original data into multiple sublists and assign each sublist to an independent task. After all tasks are completed, you can combine the results into a complete dataset. This approach can reduce processing time and enhance user experience.

## Communication Between the Task and Host Thread

When a task needs to do more than just return a final result—such as periodically updating the host thread on its status, reporting data changes, or returning large volumes of data in segments (for example, fetching large datasets from a database)—you can use the approach described in this topic.

Implement a method to receive messages sent by the task.
```typescript
function notice(data: number): void {
  console.info("Child thread task completed. Total images loaded:", data)
}
```
Then, add **sendData()** to the task to enable the child thread to send messages to the host thread.
```typescript
// Use sendData to notify the host thread of information in real time.
@Concurrent
export function loadPictureSendData(count: number): IconItemSource[] {
  let iconItemSourceList: IconItemSource[] = [];
  // Add six IconItem data records.
  for (let index = 0; index < count; index++) {
    const numStart: number = index * 6;
    // Use six images in the loop.
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
In the host thread, use **onReceiveData()** to receive messages.
```typescript
......
let lodePictureTask: taskpool.Task = new taskpool.Task(loadPictureSendData, 30);
// Use notice to receive messages from the task.
lodePictureTask.onReceiveData(notice);
taskpool.execute(lodePictureTask).then((res: IconItemSource[]) => {
  this.iconItemSourceList = res;
})
......
```
This allows the host thread to receive data sent by the task through **notice()**.

## Real-Time Communication Between the Worker Thread and Host Thread

In ArkTS, Worker differ from TaskPool in that it has a limited number of threads but can run for extended periods. Multiple tasks may be executed in one [Worker thread](https://docs.openharmony.cn/pages/v4.0/en/application-dev/arkts-utils/worker-introduction.md/), and the execution duration or returned result of each task may be different. The host thread needs to call different methods in the Worker thread according to the actual situation, and the Worker thread needs to return the result to the host thread in time. You can perform the following operations to implement this scenario.

First, create a Worker thread to execute different tasks based on parameters.
```typescript
import { worker, MessageEvents, ThreadWorkerGlobalScope } from '@kit.ArkTS';
 
const workerPort: ThreadWorkerGlobalScope = worker.workerPort;
// The Worker thread receives messages from the host thread and calls the corresponding method based on the data type.
workerPort.onmessage = (e: MessageEvents): void => {
  if (typeof e.data === "string") {
    try {
      // Call the method without parameters.
      let res: string = workerPort.callGlobalCallObjectMethod("picData", "setUp", 0) as string;
      console.error("worker: ", res);
    } catch (error) {
      // Handle exceptions.
      console.error("worker: error code is " + error.code + " error message is " + error.message);
    }
  } else if (e.data instanceof Array) {
    // Return the first four data records.
    workerPort.postMessage(e.data.slice(0, 4));
  }
}
```
Then, create a **Worker** object in the host thread. When the button is touched, **postMessage** is called to send a message to the Worker thread, and **onmessage** of the **Worker** class is used to receive data returned by the Worker thread.
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
    // Use six images in the loop.
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
In the sample code, the Worker thread performs two different processing. When the input data is of the string type, it calls **callGlobalCallObjectMethod** to synchronously call the method in the host thread (which is the UI main thread in this case). When the input data is of the array type, it returns the first four data records of the array to the host thread. This enables real-time communication between the host thread and the Worker thread, allowing the host thread to conveniently use the execution results of the Worker.

## Worker Thread Synchronously Calls a Method of the Host Thread

If an interface is already implemented in the host thread and needs to be called by Worker, you can achieve this by using the approach described in this topic.

Implement the interface in the host thread and create a Worker object. Register the interface to be called on the Worker object.
```typescript
import { worker } from '@kit.ArkTS';
// Create a Worker object.
const workerInstance: worker.ThreadWorker = new worker.ThreadWorker("entry/ets/pages/workers/Worker.ts");
 
class PicData {
  public iconItemSourceList: IconItemSource[] = [];
  
  public setUp(): string {
    for (let index = 0; index < 20; index++) {
      const numStart: number = index * 6;
      // Use six images in the loop.
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
// Register the object to be called on the Worker object.
workerInstance.registerGlobalCallObject("picData", picData);
workerInstance.postMessage("run setUp in picData");
```
Then, use [callGlobalCallObjectMethod](../reference/apis-arkts/js-apis-worker.md#callglobalcallobjectmethod11) of the **Worker** object to call **setUp()** in the main thread.
```typescript
......
try {
  // Call the method without parameters.
  let res: string = workerPort.callGlobalCallObjectMethod("picData", "setUp", 0) as string;
  console.error("worker: ", res);
} catch (error) {
  // Handle exceptions.
  console.error("worker: error code is " + error.code + " error message is " + error.message);
}
......
```

