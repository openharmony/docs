# 线程间通信场景

## 简介

在应用开发中，经常会需要处理一些耗时的任务，如果全部放在UI主线程中执行就会导致阻塞，从而引起卡顿或者掉帧现象，降低用户体验，此时就可以将这些耗时操作放到子线程中处理。通常情况下，子线程可以独立完成自己的任务，但是很多时候需要将数据从宿主线程传递到子线程，或者将子线程的执行结果返回给宿主线程。本篇文章将通过以下几种场景和示例，呈现如何在OpenHarmony应用开发中实现宿主线程和子线程的数据通信。

## 独立的耗时任务

如果耗时任务是可以独立执行的，只需要在任务执行完毕后将结果返回给宿主线程，可以通过以下方式实现。

首先，引入TaskPool模块。

```typescript
import { taskpool } from '@kit.ArkTS';
```
然后，实现子线程需要执行的任务。
```typescript
@Concurrent // 在Task中执行的方法，需要添加@Concurrent注解，否则无法正常调用。
export function loadPicture(count: number): IconItemSource[] {
  let iconItemSourceList: IconItemSource[] = [];
  // 遍历添加6*count个IconItem的数据
  for (let index = 0; index < count; index++) {
    const numStart: number = index * 6;
    // 此处循环使用6张图片资源
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
最后，通过TaskPool中的execute方法执行Task。
```typescript
......
// 创建Task
let lodePictureTask: taskpool.Task = new taskpool.Task(loadPicture, 30);
// 执行Task，并返回结果
taskpool.execute(lodePictureTask).then((res: IconItemSource[]) => {
  // loadPicture方法的执行结果
  this.iconItemSourceList = res; 
})
......
```

## 多个任务同时执行

如果有多个任务同时执行，由于任务的复杂度不同，执行时间会不一样，返回数据的时间也是不可控的。如果宿主线程需要所有任务执行完毕的数据，可以通过下面这种方式实现。
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
在该场景中，将需要执行的Task放到了一个TaskGroup里面，当TaskGroup中所有的Task都执行完毕后，会把每个Task运行的结果都放在一个数组中返回到宿主线程，而不是每执行完一个Task就返回一次，这样就可以在返回的数据里拿到所有的Task执行结果，方便宿主线程使用。

除此以外，如果Task需要处理的数据量较大（比如一个列表中有10000条数据），把这些数据都放在一个Task中处理也是比较耗时的。那么就可以将原始数据拆分成多个列表，并将每个子列表分配给一个独立的Task进行执行，并且等待全部执行完毕后拼成完整的数据，这样可以节省处理时间，提升用户体验。

## Task任务与宿主线程通信

如果一个Task，不仅需要返回最后的执行结果，而且需要定时通知宿主线程状态、数据的变化，或者需要分段返回数量级较大的数据（比如从数据库中读取大量数据），可以通过下面这种方式实现。

首先，实现一个方法，用来接收Task发送的消息。
```typescript
function notice(data: number): void {
  console.info("子线程任务已执行完，共加载图片: ", data);
}
```
然后，在需要执行的Task任务中，添加sendData()接口将消息发送给宿主线程。
```typescript
// 通过Task的sendData方法，即时通知宿主线程信息
@Concurrent
export function loadPictureSendData(count: number): IconItemSource[] {
  let iconItemSourceList: IconItemSource[] = [];
  // 遍历添加6*count个IconItem的数据
  for (let index = 0; index < count; index++) {
    const numStart: number = index * 6;
    // 此处循环使用6张图片资源
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
最后，在宿主线程通过onReceiveData()接口接收消息。
```typescript
......
let lodePictureTask: taskpool.Task = new taskpool.Task(loadPictureSendData, 30);
// 设置notice方法接收Task发送的消息
lodePictureTask.onReceiveData(notice);
taskpool.execute(lodePictureTask).then((res: IconItemSource[]) => {
  this.iconItemSourceList = res;
})
......
```
这样宿主线程就可以通过notice()接口接收到Task发送的数据。

## Worker和宿主线程的即时消息通信

在ArkTS中，Worker相对于Taskpool存在一定的差异性，有数量限制但是可以长时间存在。一个[Worker](https://docs.openharmony.cn/pages/v4.0/zh-cn/application-dev/arkts-utils/worker-introduction.md/)中可能会执行多个不同的任务，每个任务执行的时长或者返回的结果可能都不相同，宿主线程需要根据情况调用Worker中的不同方法，Worker则需要及时地将结果返回给宿主线程，此时可以通过下面的方法实现。

首先，创建一个Worker，可以根据参数执行不同的任务。
```typescript
import { worker, MessageEvents, ThreadWorkerGlobalScope } from '@kit.ArkTS';
 
const workerPort: ThreadWorkerGlobalScope = worker.workerPort;
// Worker接收宿主线程的消息，根据数据类型调用对应的方法
workerPort.onmessage = (e: MessageEvents): void => {
  if (typeof e.data === "string") {
    try {
      // 调用方法无入参
      let res: string = workerPort.callGlobalCallObjectMethod("picData", "setUp", 0) as string;
      console.error("worker: ", res);
    } catch (error) {
      // 异常处理
      console.error("worker: error code is " + error.code + " error message is " + error.message);
    }
  } else if (e.data instanceof Array) {
    // 将数据的前4条返回回去
    workerPort.postMessage(e.data.slice(0, 4));
  }
}
```
然后在宿主线程中创建这个Worker的对象，在点击Button的时候调用postMessage向Worker发送消息，通过Worker的onmessage方法接收Worker返回的数据。
```typescript
import { worker, MessageEvents } from '@kit.ArkTS';
......
@State iconItemSourceList: IconItemSource[] = [];
// 创建Worker对象
workerInstance: worker.ThreadWorker = new worker.ThreadWorker("entry/ets/pages/workers/Worker.ts");
aboutToAppear() {
  // 初始化Worker
  this.initWorker();
  for (let index = 0; index < 20; index++) {
    const numStart: number = index * 6;
    // 此处循环使用6张图片资源
    this.iconItemSourceList.push(new IconItemSource($r('app.media.nearby'), `item${numStart + 1}`));
    this.iconItemSourceList.push(new IconItemSource($r('app.media.scan'), `item${numStart + 2}`));
    this.iconItemSourceList.push(new IconItemSource($r('app.media.shop'), `item${numStart + 3}`));
    this.iconItemSourceList.push(new IconItemSource($r('app.media.cards'), `item${numStart + 4}`));
    this.iconItemSourceList.push(new IconItemSource($r('app.media.album'), `item${numStart + 5}`));
    this.iconItemSourceList.push(new IconItemSource($r('app.media.applet'), `item${numStart + 6}`));
  }
}
initWorker(){
  // 通过onmessage方法接收Worker返回的数据
  this.workerInstance.onmessage = (e: MessageEvents): void => {
    if (e.data instanceof Array) {
      this.iconItemSourceList = e.data;
    }
 }
}
......
Button('将图片变成5个', { type: ButtonType.Normal, stateEffect: true })
  .fontSize(14)
  .borderRadius(8)
  .backgroundColor('# 317aff')
  .width(250)
  .height(60)
  .margin({
    top: 30
  })
  .onClick(() => {
    // 将数据传到Worker中
    this.workerInstance.postMessage(this.iconItemSourceList);
  })
......
```
在这段示例代码中，Worker做了2种不同的处理：当传入的数据是个string类型时，调用callGlobalCallObjectMethod同步调用宿主线程中的接口，此处宿主线程为UI主线程；当传入Array类型的时候，将Array的前4条数据返回给宿主线程。这样就可以实现宿主线程和Worker间的即时通信，方便宿主线程使用Worker的运行结果。

## Worker子线程同步调用宿主线程的接口

如果一个接口在宿主线程中已经实现了，Worker需要调用该接口，那么可以使用下面这种方式实现。

首先，在宿主线程实现需要调用的接口，并且创建Worker对象，在Worker上注册需要调用的接口。
```typescript
import { worker } from '@kit.ArkTS';
// 创建Worker对象
const workerInstance: worker.ThreadWorker = new worker.ThreadWorker("entry/ets/pages/workers/Worker.ts");
 
class PicData {
  public iconItemSourceList: IconItemSource[] = [];
  
  public setUp(): string {
    for (let index = 0; index < 20; index++) {
      const numStart: number = index * 6;
      // 此处循环使用6张图片资源
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
// 在Worker上注册需要调用的对象
workerInstance.registerGlobalCallObject("picData", picData);
workerInstance.postMessage("run setUp in picData");
```
然后，在Worker中通过[callGlobalCallObjectMethod](../reference/apis-arkts/js-apis-worker.md#callglobalcallobjectmethod11)接口就可以调用主线程中的setUp()方法了。
```typescript
......
try {
  // 调用方法无入参
  let res: string = workerPort.callGlobalCallObjectMethod("picData", "setUp", 0) as string;
  console.error("worker: ", res);
} catch (error) {
  // 异常处理
  console.error("worker: error code is " + error.code + " error message is " + error.message);
}
......
```

## 相关实例

针对线程间通信开发，有以下相关实例可供参考：

[线程间通信（ArkTS）（API11）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/Performance/PerformanceLibrary/feature/ThreadCommunication)