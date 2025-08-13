# 验证示例代码同源--异常场景4

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
<!--@[Start promise_async_operation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTs/ArkTsConcurrent/MultithreadedConcurrency/MultiThreadConcurrencyOverview/entry/src/main/ets/pages/Index.ets)-->


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

<!--@[Start promise_async_operation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTs/ArkTsConcurrent/MultithreadedConcurrency/MultiThreadConcurrencyOverview/entry/src/main/ets/pages/Index.ets)-->

## 嵌套的ID，docs中不含嵌套部分

```ts
import { BusinessError } from '@kit.BasicServicesKit';



promise.then((result: number) => {
  console.info(`Random number is ${result}`);
}).catch((error: BusinessError) => {
  console.error(error.message);
});
```
<!--@[promise_then_catch_handling](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTs/ArkTsConcurrent/AsyncConcurrencyOverview/entry/src/main/ets/pages/Index.ets)-->


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
<!--@[async_await_sync_operation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTs/ArkTsConcurrent/AsyncConcurrencyOverview/entry/src/main/ets/pages/Index.ets)-->

### sample代码，start和end未同时出现

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
<!--@[test-promise_async_operation](https://gitcode.com/albee1213/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/MultithreadedConcurrency/TaskPoolIntroduction/entry/src/main/ets/managers/asynchronousfunctions.ets)-->


```ts
async function myAsyncFunction(): Promise<string> {
  const result: string = await new Promise((resolve: Function) => {
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
<!--@[test-async_await_sync_operation](https://gitcode.com/albee1213/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/MultithreadedConcurrency/TaskPoolIntroduction/entry/src/main/ets/managers/asynchronousfunctions.ets)-->