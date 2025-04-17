# 验证示例代码同源--正常场景

存在Exclude字段
`<!--@[actor_model](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTs/ArkTsConcurrent/MultithreadedConcurrency/MultiThreadConcurrencyOverview/entry/src/main/ets/pages/Index.ets)-->`


存在Exclude字段，存在start嵌套字段，同时存在单一的start字段
`<!--@[async_operation_error_handling_with_try_catch](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTs/ArkTsConcurrent/AsyncConcurrencyOverview/entry/src/main/ets/pages/Index.ets)-->`

`<!--@[async_await_sync_operation](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTs/ArkTsConcurrent/AsyncConcurrencyOverview/entry/src/main/ets/pages/Index.ets)-->`

`<!--@[promise_then_catch_handling](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTs/ArkTsConcurrent/AsyncConcurrencyOverview/entry/src/main/ets/pages/Index.ets)-->`

`<!--@[promise_async_operation](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTs/ArkTsConcurrent/AsyncConcurrencyOverview/entry/src/main/ets/pages/Index.ets)-->`


存在Exclude字段
`<!--@[concurrent_taskpool_common_usage](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/MultithreadedConcurrency/TaskPoolIntroduction/entry/src/main/ets/managers/generaluse.ets)-->`

`<!--@[quickstart1](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/MultithreadedConcurrency/TaskPoolIntroduction/entry/src/main/ets/managers/generaluse.ets)-->`

`<!--@[quickstart](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/MultithreadedConcurrency/TaskPoolIntroduction/entry/src/main/ets/managers/generaluse.ets)-->`


存在Exclude字段
`<!--@[concurrent_taskpool_promise_return](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/MultithreadedConcurrency/TaskPoolIntroduction/entry/src/main/ets/managers/returnpromise.ets)-->`


存在Exclude字段
`<!--@[concurrent_taskpool_async_promise_usage](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/MultithreadedConcurrency/TaskPoolIntroduction/entry/src/main/ets/managers/asynchronousfunctions.ets)-->`


前提：同一文档中，如果出现多次引用同一段代码，则引用代码必须完全相同

## 引用全量代码

### ID无嵌套，代码完全一致

```ts
const promise: Promise<number> = new Promise((resolve: Function, reject: Function) => {
  setTimeout(() => {
    const randomNumber: number = Math.random();
    if (randomNumber > 0.5) {
      resolve(randomNumber);
    } else {
      reject(new Error('Random number is too small'));
    }
  }, 1000);
})
```
<!--@[Start promise_async_operation](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTs/ArkTsConcurrent/MultithreadedConcurrency/MultiThreadConcurrencyOverview/entry/src/main/ets/pages/Index.ets)-->


### ID无嵌套，整段代码缩进不一致

* list 1
* list 2
    ```ts
    const promise: Promise<number> = new Promise((resolve: Function, reject: Function) => {
    setTimeout(() => {
        const randomNumber: number = Math.random();
        if (randomNumber > 0.5) {
        resolve(randomNumber);
        } else {
        reject(new Error('Random number is too small'));
        }
    }, 1000);
    })
    ```
    <!--@[Start promise_async_operation](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTs/ArkTsConcurrent/MultithreadedConcurrency/MultiThreadConcurrencyOverview/entry/src/main/ets/pages/Index.ets)-->
* list 3

### ID存在嵌套

```ts
// 实际开始-promise_then_catch_handling
import { BusinessError } from '@kit.BasicServicesKit';

// 嵌套start-promise_async_operation]
const promise: Promise<number> = new Promise((resolve: Function, reject: Function) => {
  setTimeout(() => {
    const randomNumber: number = Math.random();
    if (randomNumber > 0.5) {
      resolve(randomNumber);
    } else {
      reject(new Error('Random number is too small'));
    }
  }, 1000);
})
// 嵌套end-promise_async_operation]

promise.then((result: number) => {
  console.info(`Random number is ${result}`);
}).catch((error: BusinessError) => {
  console.error(error.message);
});
// 实际结束-promise_then_catch_handling
```
<!--@[promise_then_catch_handling](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTs/ArkTsConcurrent/MultithreadedConcurrency/MultiThreadConcurrencyOverview/entry/src/main/ets/pages/Index.ets)-->


## 引用部分代码（Exclude字段）

### 内容完全一致

```ts
import { taskpool } from '@kit.ArkTS';

// 跨线程并发任务
@Concurrent
async function produce(): Promise<number> {
  // 添加生产相关逻辑
  console.info('producing...');
  return Math.random();
}

class Consumer {
  public consume(value: Object) {
    // 添加消费相关逻辑
    console.info('consuming value: ' + value);
  }
}

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
        Button() {
          Text('start')
        }.onClick(() => {
          let produceTask: taskpool.Task = new taskpool.Task(produce);
          let consumer: Consumer = new Consumer();
          for (let index: number = 0; index < 10; index++) {
            // 执行生产异步并发任务
            taskpool.execute(produceTask).then((res: Object) => {
              consumer.consume(res);
            }).catch((e: Error) => {
              console.error(e.message);
            })
          }
        })
        .width('20%')
        .height('20%')
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
<!--@[actor_model](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTs/ArkTsConcurrent/MultithreadedConcurrency/MultiThreadConcurrencyOverview/entry/src/main/ets/pages/Index.ets)-->


### 注释不一致（新增注释），代码内容一致

```ts
//新增注释
// 开始--async_await_sync_operation
async function myAsyncFunction(): Promise<string> {
  const result: string = await new Promise((resolve: Function) => {
    setTimeout(() => {
      resolve('Hello, world!');
    }, 3000);
  });
  console.info(result); // 输出： Hello, world!
  return result;
}

@Entry
@Component
struct PromiseAsyncAwait {
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(async () => {
            let res = await myAsyncFunction();
            console.info('res is: ' + res);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
// 结束--async_await_sync_operation
```
<!--@[async_await_sync_operation](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTs/ArkTsConcurrent/AsyncConcurrencyOverview/entry/src/main/ets/pages/Index.ets)-->

## 注释不一致（docs：多行注释 vs Sample:单行注释），代码内容一致

```ts
import { taskpool } from '@kit.ArkTS';

// 跨线程并发任务
@Concurrent
async function produce(): Promise<number> {
  // 添加生产相关逻辑
  console.info('producing...');
  return Math.random();
}

class Consumer {
  public consume(value: Object) {
    // 添加消费相关逻辑
    console.info('consuming value: ' + value);
  }
}

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
        Button() {
          Text('start')
        }.onClick(() => {
          let produceTask: taskpool.Task = new taskpool.Task(produce);
          let consumer: Consumer = new Consumer();
          for (let index: number = 0; index < 10; index++) {
            /*
             * 执行生产异步并发任务
             */
            taskpool.execute(produceTask).then((res: Object) => {
              consumer.consume(res);
            }).catch((e: Error) => {
              console.error(e.message);
            })
          }
        })
        .width('20%')
        .height('20%')
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
<!--@[actor_model](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTs/ArkTsConcurrent/MultithreadedConcurrency/MultiThreadConcurrencyOverview/entry/src/main/ets/pages/Index.ets)-->


## 注释不一致（docs：行上 vs Sample:行），代码内容一致

```ts
async function myAsyncFunction(): Promise<string> {
    const result: string = await new Promise((resolve: Function) => {
    setTimeout(() => {
        resolve('Hello, world!');
    }, 3000);
    });
    // 输出： Hello, world!
    console.info(result); 
    return result;
}

@Entry
@Component
struct PromiseAsyncAwait {
    @State message: string = 'Hello World';

    build() {
    Row() {
        Column() {
        Text(this.message)
            .fontSize(50)
            .fontWeight(FontWeight.Bold)
            .onClick(async () => {
            let res = await myAsyncFunction();
            console.info('res is: ' + res);
            })
        }
        .width('100%')
    }
    .height('100%')
    }
}
```
<!--@[async_await_sync_operation](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTs/ArkTsConcurrent/AsyncConcurrencyOverview/entry/src/main/ets/pages/Index.ets)-->