# 验证示例代码同源--异常场景3
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

代码不一致（空格不一致，1000关键字对应行）
```ts
const promise: Promise<number> = new Promise((resolve: Function, reject: Function) => {
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
<!--@[promise_async_operation](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTs/ArkTsConcurrent/MultithreadedConcurrency/MultiThreadConcurrencyOverview/entry/src/main/ets/pages/Index.ets)-->