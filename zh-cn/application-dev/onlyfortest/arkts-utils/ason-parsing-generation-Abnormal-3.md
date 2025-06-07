# 验证示例代码同源--异常场景3

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
<!--@[promise_async_operation](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTs/ArkTsConcurrent/AsyncConcurrencyOverview/entry/src/main/ets/pages/Index.ets)-->