# Media Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## DTS2025010983858

### quetsion one
Test DTS2025010983858 quesiton one

1. list-One
   according UserAgent {OSName} and {OSVersion} recognise OpenHarmonyOS.The format: OpenHarmony + Vesion

   ```ts
   const matches = navigator.userAgent.match(/OpenHarmony (\d+\.?\d*)/);  
   matches?.length && Number(matches[1]) >= 5;  
   ```

2. list-Two
    according UserAgent {OSName} recognise OpenHarmonyOS.

   ```ts
   const isOpenHarmony = () => /OpenHarmony/i.test(navigator.userAgent);   
   ```

### question two

For exampl:

```ts
import { taskpool } from '@kit.ArkTS';

@Concurrent
async function testPromiseError() {
  await new Promise<number>((resolve, reject) => {
    resolve(1);
  }).then(()=>{
    throw new Error('testPromise Error');
  })
}

@Concurrent
async function testPromiseError1() {
  await new Promise<string>((resolve, reject) => {
    reject('testPromiseError1 Error msg');
  })
}

@Concurrent
function testPromiseError2() {
  return new Promise<string>((resolve, reject) => {
    reject('testPromiseError2 Error msg');
  })
}

async function testConcurrentFunc() {
  let task1: taskpool.Task = new taskpool.Task(testPromiseError);
  let task2: taskpool.Task = new taskpool.Task(testPromiseError1);
  let task3: taskpool.Task = new taskpool.Task(testPromiseError2);

  taskpool.execute(task1).then((d:object)=>{
    console.info('task1 res is: ' + d);
  }).catch((e:object)=>{
    console.info('task1 catch e: ' + e);
  })
  taskpool.execute(task2).then((d:object)=>{
    console.info('task2 res is: ' + d);
  }).catch((e:object)=>{
    console.info('task2 catch e: ' + e);
  })
  taskpool.execute(task3).then((d:object)=>{
    console.info('task3 res is: ' + d);
  }).catch((e:object)=>{
    console.info('task3 catch e: ' + e);
  })
}

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        Button(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            testConcurrentFunc();
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
<!--@[concurrent_taskpool_async_promise_usage](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/MultithreadedConcurrency/TaskPoolIntroduction/entry/src/main/ets/managers/asynchronousfunctions.ets)-->

Test DTS2025010983858 quesiton two

**Table 1**
|Name|age|city|
|---|---|---|
| <!--DelRow-->formVisibleNotify | 15 | beijing |
| <!--DelRow-->transparencyEnabled | 18| shagnhai |
|fontScaleFollowSystem|20|London|

**Table 2**
|Name|age|city|
|---|---|---|
|fontScaleFollowSystem|20|London|
| <!--DelRow-->formVisibleNotify | 15 | beijing |
| <!--DelRow-->transparencyEnabled | 18| shagnhai |
|fontScaleFollowSystemeternal|25|Pairs|

1. List-One
    **Table 3**
    |Name|age|city|
    |---|---|---|
    | <!--DelRow-->formVisibleNotify | 15 | beijing |
    | <!--DelRow-->transparencyEnabled | 18| shagnhai |
    |fontScaleFollowSystem|20|London|

2. List-One
    **Table 4**
    |Name|age|city|
    |---|---|---|
    |fontScaleFollowSystem|20|London|
    | <!--DelRow-->formVisibleNotify | 15 | beijing |
    | <!--DelRow-->transparencyEnabled | 18| shagnhai |
    |fontScaleFollowSystemeternal|25|Pairs|

3. List-Three
    * ul-list-1
        **Table 5**
        |Name|age|city|
        |---|---|---|
        | <!--DelRow-->formVisibleNotify | 15 | beijing |
        | <!--DelRow-->transparencyEnabled | 18| shagnhai |
        |fontScaleFollowSystem|20|London|

    * ul-list-2
        **Table 6**
        |Name|age|city|
        |---|---|---|
        |fontScaleFollowSystem|20|London|
        | <!--DelRow-->formVisibleNotify | 15 | beijing |
        | <!--DelRow-->transparencyEnabled | 18| shagnhai |
        |fontScaleFollowSystemeternal|25|Pairs|

4. List-Four
    ```ts
    export function testAdd(arg: number) {
        return ++arg;
    }

    @Sendable
    export class MyTestA {
        constructor(name: string) {
            this.name = name;
        }
        name: string = 'MyTestA';
    }

    export class MyTestB {
        static nameStr:string = 'MyTestB';
    }
    ```
    <!--@[concurrent_taskpool_test_resources](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/MultithreadedConcurrency/TaskPoolIntroduction/entry/src/main/ets/managers/Test.ets)-->


## 5400101 Memory Allocation Failed

**Error Message**

No memory.

**Description**

Failed to allocate memory.

**Possible Causes**

1. The number of instances exceeds 16.
2. The new or malloc process fails, causing a null pointer.

**Solution**

Destroy this instance and re-create it. If the re-creation fails, stop related operations.

## 5400102 Unsupported Operation

**Error Message**

Operation not allowed.

**Description**

This operation is not allowed.

**Possible Causes**

This operation is not allowed in the current state.

**Solution**

Switch the instance to the correct state and perform the operation.

## 5400103 I/O Error

**Error Message**

I/O error.

**Description**

An I/O error occurs.

**Possible Causes**

The data interaction between the media and other modules (graphics, audio, network, HDI, and camera) is abnormal.

**Solution**

Ensure that the network is normal, destroy this instance, and re-create it. If the re-creation fails, stop related operations.

## 5400104 Operation Timeout

**Error Message**

Operation timeout.

**Description**

The operation timed out.

**Possible Causes**

1. The network connection times out. (The default network timeout period is 15 seconds, and the timer starts after the buffered event is reported.)
2. Accessing other modules times out.

**Solution**

1. Check whether the network is normal.
2. Destroy this instance and re-create it. If the re-creation fails, stop related operations.

## 5400105 Play Service Dead

**Error Message**

Service died.

**Description**

The playback service is dead.

**Possible Causes**

The playback service is dead.

**Solution**

Destroy this instance and re-create it. If the re-creation fails, stop related operations.

## 5400106 Format Not Supported

**Error Message**

Unsupported format.

**Description**

The format is not supported.

**Possible Causes**

The file format is not supported.

**Solution**

Use a supported format.

## 5400107 Audio Focus Conflict

**Error Message**

Audio interrupted.

**Description**

Recording fails due to audio focus conflicts.

**Possible Causes**

Another process occupies the audio focus.

**Solution**

Destroy the current instance and check whether another process is recording. If you can stop the other process, you can create the current instance again.

### test

#### codehub

For example:

```ts
import { taskpool } from '@kit.ArkTS';

@Concurrent
function add(num1: number, num2: number): number {
  return num1 + num2;
}

async function ConcurrentFunc(): Promise<void> {
  try {
    let task: taskpool.Task = new taskpool.Task(add, 1, 2);
    console.info("taskpool res is: " + await taskpool.execute(task));
  } catch (e) {
    console.error("taskpool execute error is: " + e);
  }
}

@Entry
@Component
struct Index {
  @State message: string = 'Hello World'

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            ConcurrentFunc();
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
<!--@[concurrent_taskpool_common_usage](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/MultithreadedConcurrency/TaskPoolIntroduction/entry/src/main/ets/managers/generaluse.ets)-->
