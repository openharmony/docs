# 验证示例代码同源--异常场景4
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

## ID无嵌套，代码不一致

代码不一致（docs中只有结束的```）

const promise: Promise\<number\> = new Promise((resolve: Function, reject: Function) => {
  setTimeout(() => {
    const randomNumber: number = Math.random();
    if (randomNumber > 0.5) {
      resolve(randomNumber);
    } else {
      reject(new Error('Random number is too small'));
    }
  },  1000);
})
```
<!--@[Start promise_async_operation](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTs/ArkTsConcurrent/MultithreadedConcurrency/MultiThreadConcurrencyOverview/entry/src/main/ets/pages/Index.ets)-->


代码不一致（docs中只有开始的```）

```
const promise: Promise\<number\> = new Promise((resolve: Function, reject: Function) => {
  setTimeout(() => {
    const randomNumber: number = Math.random();
    if (randomNumber > 0.5) {
      resolve(randomNumber);
    } else {
      reject(new Error('Random number is too small'));
    }
  },  1000);
})

<!--@[Start promise_async_operation](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTs/ArkTsConcurrent/MultithreadedConcurrency/MultiThreadConcurrencyOverview/entry/src/main/ets/pages/Index.ets)-->

## 嵌套的ID，docs中将嵌套部分注释掉

```ts
// Star--promise_then_catch_handling
import { BusinessError } from '@kit.BasicServicesKit';

// Start--promise_async_operation
// const promise: Promise<number> = new Promise((resolve: Function, reject: Function) => {
//   setTimeout(() => {
//     const randomNumber: number = Math.random();
//     if (randomNumber > 0.5) {
//       resolve(randomNumber);
//     } else {
//       reject(new Error('Random number is too small'));
//     }
//   }, 1000);
// })
// End--promise_async_operation

promise.then((result: number) => {
  console.info(`Random number is ${result}`);
}).catch((error: BusinessError) => {
  console.error(error.message);
});
// End---promise_then_catch_handling
```
<!--@[promise_then_catch_handling](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTs/ArkTsConcurrent/AsyncConcurrencyOverview/entry/src/main/ets/pages/Index.ets)-->
