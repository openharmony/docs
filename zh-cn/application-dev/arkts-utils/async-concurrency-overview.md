# 异步并发 (Promise和async/await)


Promise和async/await提供异步并发能力，是标准的JS异步语法。异步代码会被挂起并在之后继续执行，同一时间只有一段代码执行。以下是典型的异步并发使用场景：

- I/O 非阻塞操作​​：网络请求、文件读写、定时器等。

- 任务轻量且无 CPU 阻塞​​：单次任务执行时间短。

- 逻辑依赖清晰​​：任务有明确的顺序或并行关系。

异步并发是一种编程语言的特性，允许程序在执行某些操作时不必等待其完成，可以继续执行其他操作。

## Promise

Promise是一种用于处理异步操作的对象，可以将异步操作转换为类似于同步操作的风格，以方便代码编写和维护。Promise提供了一个状态机制来管理异步操作的不同阶段，并提供了一些方法来注册回调函数以处理异步操作的成功或失败的结果。

Promise有三种状态：pending（进行中）、fulfilled（已完成，也叫resolved）和rejected（已拒绝）。创建后处于pending状态，异步操作完成后转换为fulfilled或rejected。

最基本的用法是通过构造函数实例化一个Promise对象，同时传入一个带有两个参数的函数，通常称为executor函数。executor函数接收两个参数：resolve和reject，分别表示异步操作成功和失败时的回调函数。例如，以下代码创建了一个Promise对象并模拟了一个异步操作：

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
<!-- @[promise_async_operation](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTs/ArkTsConcurrent/AsyncConcurrencyOverview/entry/src/main/ets/pages/Index.ets) -->

在上述代码中，setTimeout函数模拟了一个异步操作，1秒后生成一个随机数。如果随机数大于0.5，调用resolve回调函数并传递该随机数；否则调用reject回调函数并传递一个错误对象。

Promise对象创建后，可以使用then方法和catch方法指定fulfilled状态和rejected状态的回调函数。then方法可接受两个参数，一个处理fulfilled状态的函数，另一个处理rejected状态的函数。只传一个参数则表示当Promise对象状态变为fulfilled时，then方法会自动调用这个回调函数，并将Promise对象的结果作为参数传递给它。使用catch方法注册一个回调函数，用于处理“失败”的结果，即捕获Promise的状态改变为rejected状态或操作失败抛出的异常。例如：

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 使用 then 方法定义成功和失败的回调
promise.then((result: number) => {
  console.info(`Succesed number is ${result}`); // 成功时执行
}, (error: BusinessError) => {
  console.error(error.message); // 失败时执行
}
);

// 使用 then 方法定义成功的回调，catch 方法定义失败的回调
promise.then((result: number) => {
  console.info(`Random number is ${result}`); // 成功时执行
}).catch((error: BusinessError) => {
  console.error(error.message); // 失败时执行
});
```
<!-- @[promise_then_catch_handling](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTs/ArkTsConcurrent/AsyncConcurrencyOverview/entry/src/main/ets/pages/Index.ets) -->

在上述代码中，then方法的回调函数接收Promise对象的成功结果作为参数，并输出到控制台。如果Promise对象进入rejected状态，catch方法的回调函数接收错误对象作为参数，并输出到控制台。

> **说明：**
>
> 当Promise被reject且未通过catch方法处理时，会触发unhandledrejection事件。可使用[errorManager.on('unhandledrejection')](../reference/apis-ability-kit/js-apis-app-ability-errorManager.md#errormanageroffunhandledrejection12)接口监听该事件，以全局捕获未处理的Promise reject。

## async/await

async/await是一种用于处理异步操作的Promise语法糖，使得编写异步代码变得更加简单和易读。通过使用async关键字声明一个函数为异步函数，并使用await关键字等待Promise的解析（完成或拒绝），以同步的方式编写异步操作的代码。

async函数通过返回Promise对象实现异步操作，其内部可以包含零个或者多个await关键字，通过await暂停执行直至关联的Promise完成状态转换（fulfilled/rejected）。若函数执行过程中抛出异常，该异常将直接触发返回的Promise进入rejected状态，错误对象可通过.catch()方法或then的第二个回调参数捕获。

下面是一个使用async/await的例子，其中模拟了一个以同步方式执行异步操作的场景，该操作会在3秒钟后返回一个字符串。

```ts
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
struct Index {
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
<!-- @[async_await_sync_operation](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTs/ArkTsConcurrent/AsyncConcurrencyOverview/entry/src/main/ets/pages/Index.ets) -->

在上述示例代码中，使用了await关键字来等待Promise对象的解析，并将其解析值存储在result变量中。

需要注意的是，等待异步操作时，需将整个操作包在async函数中，并搭配await使用，同时也可使用try/catch块来捕获异步操作中的异常。

```ts
async function myAsyncFunction(): Promise<void> {
  try {
    const result: string = await new Promise((resolve: Function) => {
      resolve('Hello, world!');
    });
  } catch (e) {
    console.error(`Get exception: ${e}`);
  }
}

myAsyncFunction();
```
<!-- @[async_operation_error_handling_with_try_catch](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTs/ArkTsConcurrent/AsyncConcurrencyOverview/entry/src/main/ets/pages/Index.ets) -->
