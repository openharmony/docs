# 异步并发
<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

异步并发编程是现代应用程序开发的重要组成部分，能够提高程序的性能和响应能力。ArkTS基于TypeScript，继承了JavaScript的异步编程机制，提供了async/await、Promise等强大的异步处理工具。

## 并发的基础概念

并发让程序同时推进多个任务而不阻塞主线程，ArkTS通过async/await和Promise实现异步并发。

### 并发的定义与核心价值

并发让程序同时处理多个任务，从四个维度带来收益：充分利用计算资源避免阻塞以提升性能，保持响应性避免界面卡顿以改善体验，合理分配系统资源，并支持模块化、解耦的架构设计。

<!-- @[sync_vs_async](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Async.ets) -->

``` TypeScript
// 同步执行：阻塞等待
function syncOperation(): void {
  console.info('开始操作');
  // 模拟耗时操作
  let start = Date.now();
  while (Date.now() - start < 1000) {
    // 阻塞1秒
  }
  console.info('操作完成');
}

syncOperation();
console.info('继续执行其他任务');
// 输出顺序：开始操作 -> 操作完成 -> 继续执行其他任务

// 异步执行：不阻塞
function asyncOperation(): Promise<void> {
  console.info('开始异步操作');
  return new Promise((resolve) => {
    setTimeout(() => {
      console.info('异步操作完成');
      resolve();
    }, 1000);
  });
}

asyncOperation();
console.info('立即继续执行其他任务');
// 输出顺序：开始异步操作 -> 立即继续执行其他任务 -> 异步操作完成（1秒后）
```

### 并发与并行的区别

并发通过异步I/O交替推进多任务，并行通过多线程同时执行计算。

<!-- @[concurrent_vs_parallel](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ConcurrentVsParallel.ets) -->

``` TypeScript
import http from '@ohos.net.http';
import { worker } from '@kit.ArkTS';

// 并发示例：异步I/O操作
async function concurrentExample(): Promise<void> {
  console.info('开始并发任务');
  
  // 启动多个异步任务（不等待）
  let task1 = http.createHttp().request('/api/users');
  let task2 = http.createHttp().request('/api/products');
  let task3 = http.createHttp().request('/api/orders');
  
  // 并发执行，等待所有任务完成
  let responses = await Promise.all([task1, task2, task3]);
  let users = responses[0];
  let products = responses[1];
  let orders = responses[2];
  
  console.info('所有并发任务完成');
}

// 并行示例：多线程计算
function parallelExample(): void {
  console.info('开始并行任务');
  
  // 创建Worker线程进行并行计算
  let worker1 = new worker.ThreadWorker('entry/ets/workers/ComputeWorker.ets');
  let worker2 = new worker.ThreadWorker('entry/ets/workers/ComputeWorker.ets');
  
  worker1.postMessage({ task: 'calculate1' });
  worker2.postMessage({ task: 'calculate2' });
  
  worker1.onmessage = (e) => console.info(`Worker 1 完成: ${e.data}`);
  worker2.onmessage = (e) => console.info(`Worker 2 完成: ${e.data}`);
}
```

### ArkTS并发的实现机制

ArkTS的异步机制基于事件循环：同步代码先执行，微任务（Promise.then）在当前任务后执行，宏任务（setTimeout）在下一轮执行。

<!-- @[event_loop_mechanism](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Async.ets) -->

``` TypeScript
// 事件循环机制
console.info('1. 开始');

// 宏任务（Macro Task）：setTimeout、setInterval、I/O等
setTimeout(() => {
  console.info('2. setTimeout（宏任务）');
}, 0);

// 微任务（Micro Task）：Promise、queueMicrotask等
Promise.resolve().then(() => {
  console.info('3. Promise（微任务）');
});

console.info('4. 同步代码结束');

// 输出顺序：
// 1. 开始
// 4. 同步代码结束
// 3. Promise（微任务）
// 2. setTimeout（宏任务）
```

## 异步函数

async函数自动将返回值包装为Promise，配合await实现同步风格的异步代码。

### 异步函数的声明语法

在function关键字前添加async即声明异步函数，也可用于箭头函数。

<!-- @[async_function_declaration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Async.ets) -->

``` TypeScript
// 基本异步函数声明
async function fetchData(): Promise<string> {
  return 'Data loaded';
}

// 箭头函数形式的异步函数
const fetchUserData = async (): Promise<User> => {
  return { id: 1, name: 'Alice' };
};

// 类方法形式的异步函数
class DataService {
  async getData(): Promise<string> {
    return 'Data from service';
  }
}

interface User {
  id: number;
  name: string;
}

// 使用异步函数
async function main(): Promise<void> {
  let data = await fetchData();
  console.info(`${data}`);
  
  let user = await fetchUserData();
  console.info(`${user.name}`);
  
  let service = new DataService();
  let serviceData = await service.getData();
  console.info(`${serviceData}`);
}

main();
```

### 异步函数的返回值特性

async函数的返回值自动包装为Promise，return 'Hello'等价于return Promise.resolve('Hello')。

<!-- @[async_function_return_value](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Async.ets) -->

``` TypeScript
// 异步函数自动将返回值包装为Promise
async function returnString(): Promise<string> {
  return 'Hello'; // 自动包装为Promise.resolve('Hello')
}

async function returnNumber(): Promise<number> {
  return 42; // 自动包装为Promise.resolve(42)
}

interface ReturnObjectResult {
  id: number;
}

async function returnObject(): Promise<ReturnObjectResult> {
  return { id: 1 }; // 自动包装为Promise.resolve({ id: 1 })
}

// 使用返回值
returnString().then((data: string) => console.info(data)); // Hello
returnNumber().then((num: number) => console.info(`${num}`));   // 42
returnObject().then((obj: ReturnObjectResult) => console.info(`${obj.id}`)); // 1

// 异步函数返回Promise
async function returnPromise(): Promise<string> {
  return Promise.resolve('Already a Promise');
}

returnPromise().then((data: string) => console.info(data)); // Already a Promise
```

### 异步函数与普通函数的区别

普通函数同步执行，调用方等待结果返回；async函数异步执行，调用方立即获得Promise，不阻塞后续代码。

<!-- @[sync_vs_async_function](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Async.ets) -->

``` TypeScript
// 普通函数：同步执行
function normalFunction(): string {
  console.info('Normal function executing');
  return 'Result';
}

let result1 = normalFunction();
console.info(`After normal function: ${result1}`);
// 输出顺序：
// Normal function executing
// After normal function: Result

// 异步函数：异步执行
async function asyncFunction(): Promise<string> {
  console.info('Async function executing');
  return 'AsyncResult';
}

let result2 = asyncFunction();
console.info(`After async function: ${result2}`);
// 输出顺序：
// Async function executing
// After async function: Promise { 'AsyncResult' }

// 异步函数需要await或 .then() 获取结果
asyncFunction().then(result => console.info('Async result:', result));
// 输出：Async result: AsyncResult
```

### 异步函数的错误处理

在async函数中用try-catch包裹await表达式，捕获Promise rejection。

<!-- @[async_function_error_handling](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AsyncErrorHandling.ets) -->

``` TypeScript
import http from '@ohos.net.http';

// 异步函数中的错误处理
async function fetchDataWithError(): Promise<string> {
  try {
    // 模拟可能失败的异步操作
    let response = await http.createHttp().request('/api/data');
    
    if (response.responseCode !== 200) {
      throw new Error(`HTTP ${response.responseCode}`);
    }
    
    let data = response.result;
    return JSON.stringify(data);
  } catch (error) {
    console.error('Fetch error:', (error as Error).message);
    throw new Error((error as Error).message); // 重新抛出错误
  }
}

// 使用try-catch处理异步函数的错误
async function handleFetch(): Promise<void> {
  try {
    let data = await fetchDataWithError();
    console.info(`Data: ${data}`);
  } catch (error) {
    console.error('Handler error:', (error as Error).message);
  }
}

// 使用Promise.catch() 处理错误
fetchDataWithError()
  .then(data => console.info(`Success: ${data}`))
  .catch((error: Error) => console.error(`Catch: ${error.message}`));
```

## await关键字

await等待异步操作完成，暂停函数执行直到Promise解决。

### await的使用规则

`await`关键字用于等待Promise完成并获取其结果，只能在async函数内部使用。

<!-- @[ts_await_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Async.ts) -->

``` TypeScript
async function example(): Promise<void> {
  // await只能在async函数内使用
  let result = await Promise.resolve('Hello');
  console.info(`${result}`);
}

// 错误示例：在普通函数中使用await
function normalFunction() {
    let result = await Promise.resolve('Hello'); // 编译错误
}

// await可以用于任何Promise
async function awaitExample(): Promise<void> {
  // 等待Promise.resolve()
  let result1 = await Promise.resolve('Immediate');
  console.info(`${result1}`);

  // 等待Promise.reject()（需要错误处理）
  try {
    let result2 = await Promise.reject('Error');
  } catch (error) {
    console.error('Caught:', error);
  }

  // 等待setTimeout创建的Promise
  let result3 = await new Promise<string>((resolve) => {
    setTimeout(() => resolve('Delayed'), 1000);
  });
  console.info(`${result3}`);
}

awaitExample();
```

### await与Promise的关联

await等待Promise完成并取出resolve的值，被reject时抛出异常由try-catch捕获。

<!-- @[await_promise](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AwaitPromise.ets) -->

``` TypeScript
import http from '@ohos.net.http';

async function awaitPromise(): Promise<void> {
  // await等待Promise完成，获取resolve的值
  let promise1 = Promise.resolve(42);
  let value1 = await promise1;
  console.info(`Value 1: ${value1}`); // 42
  
  // await捕获Promise的错误
  let promise2 = Promise.reject(new Error('Failed'));
  try {
    let value2 = await promise2;
  } catch (error) {
    console.error(`Error 2: ${(error as Error).message}`); // Failed
  }
  
  // await等待fetch请求
  try {
    let response = await http.createHttp().request('/api/data');
    let data = response.result;
    console.info(`Data: ${data}`);
  } catch (error) {
    console.error(`Fetch failed: ${(error as Error).message}`);
  }
}

awaitPromise();
```

### 多个await的串行执行

多个await按顺序执行，前一个完成后才执行下一个，适用于依赖关系的异步任务。

<!-- @[await_serial_execution](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Async.ets) -->

``` TypeScript
async function serialExecution(): Promise<void> {
  console.info('Start');
  
  // 串行执行：一个接一个
  let result1 = await new Promise<string>((resolve) => {
    setTimeout(() => {
      console.info('Task 1 completed');
      resolve('Result 1');
    }, 1000);
  });
  
  let result2 = await new Promise<string>((resolve) => {
    setTimeout(() => {
      console.info('Task 2 completed');
      resolve('Result 2');
    }, 1000);
  });
  
  let result3 = await new Promise<string>((resolve) => {
    setTimeout(() => {
      console.info('Task 3 completed');
      resolve('Result 3');
    }, 1000);
  });
  
  console.info(`All tasks completed: ${result1}, ${result2}, ${result3}`);
}

serialExecution();
// 输出顺序：
// Start
// Task 1 completed（1秒后）
// Task 2 completed（2秒后）
// Task 3 completed（3秒后）
// All tasks completed: Result 1 Result 2 Result 3
```

### await的非阻塞特性

await暂停当前async函数的执行而非阻塞线程，控制权交回事件循环，Promise完成后恢复执行。

<!-- @[await_non_blocking](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Async.ets) -->

``` TypeScript
async function nonBlockingExample(): Promise<void> {
  console.info('1. Async function start');
  
  // await等待Promise，但不阻塞外部代码
  await new Promise<void>((resolve: () => void) => {
    setTimeout(() => {
      console.info('2. Promise resolved');
      resolve();
    }, 1000);
  });
  
  console.info('3. Async function end');
}

nonBlockingExample();
console.info('4. External code continues');

// 输出顺序：
// 1. Async function start
// 4. External code continues（不等待）
// 2. Promise resolved（1秒后）
// 3. Async function end
```

## Promise对象

Promise表示异步操作的结果，支持链式调用和错误处理。

### Promise的三种状态

Promise有pending、fulfilled、rejected三种状态，表示异步操作的进行、成功和失败。

<!-- @[promise_states](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Async.ets) -->

``` TypeScript
// Pending状态
let pendingPromise: Promise<void> = new Promise<void>((resolve: () => void, reject: (reason: Error) => void) => {
  // 未调用resolve或reject，保持Pending状态
});

console.info('Promise 处于 Pending 状态'); // Promise { <pending> }

// Fulfilled状态（成功）
let fulfilledPromise: Promise<string> = new Promise<string>((resolve: (value: string) => void) => {
  resolve('Success');
});

fulfilledPromise.then((value: string) => console.info(value)); // Success

// Rejected状态（失败）
let rejectedPromise: Promise<string> = new Promise<string>(
  (resolve: (value: string) => void, reject: (reason: Error) => void) => {
    reject(new Error('Failure'));
  }
);

rejectedPromise.catch((error: Error) => console.error(error.message)); // Failure

// 状态转换：只能从Pending -> Fulfilled或Pending -> Rejected
let irreversiblePromise: Promise<string> = new Promise<string>(
  (resolve: (value: string) => void, reject: (reason: Error) => void) => {
    resolve('First resolve');
    reject(new Error('Second reject')); // 无效，Promise状态已确定
  }
);

irreversiblePromise.then((value: string) => console.info(value)); // First resolve
```

### Promise的创建方式

Promise通过new Promise((resolve, reject) => {...})创建，也可用Promise.resolve和Promise.reject快捷创建已完成的Promise。

<!-- @[promise_creation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Async.ets) -->

``` TypeScript
// 方式1：使用Promise构造函数
let promise1 = new Promise<string>((resolve, reject) => {
  // 异步操作
  setTimeout(() => {
    let success = true;
    if (success) {
      resolve('Operation succeeded');
    } else {
      reject(new Error('Operation failed'));
    }
  }, 1000);
});

// 方式2：使用Promise.resolve()
let promise2 = Promise.resolve('Immediately resolved');

// 方式3：使用Promise.reject()
let promise3 = Promise.reject(new Error('Immediately rejected'));

// 方式4：封装异步操作为Promise
function delay(ms: number): Promise<void> {
  return new Promise((resolve) => {
    setTimeout(resolve, ms);
  });
}

async function useDelay(): Promise<void> {
  console.info('Waiting...');
  await delay(1000);
  console.info('Done waiting');
}

useDelay();
```

### Promise的链式调用

Promise链式调用通过then方法串联多个异步操作，实现顺序执行。

<!-- @[promise_chaining](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Async.ets) -->

``` TypeScript
// Promise链式调用
Promise.resolve(1)
  .then((value: number): number => {
    console.info(`Step 1: ${value}`);
    return value + 1;
  })
  .then((value: number): number => {
    console.info(`Step 2: ${value}`);
    return value * 2;
  })
  .then((value: number): string => {
    console.info(`Step 3: ${value}`);
    return `Final: ${value}`;
  })
  .then((result: string): void => {
    console.info(`Final result: ${result}`);
  });

// 输出：
// Step 1: 1
// Step 2: 2
// Step 3: 4
// Final result: Final: 4

// 错误处理链
Promise.resolve(1)
  .then((value: number): number => {
    if (value < 10) {
      throw new Error('Value too small');
    }
    return value;
  })
  .catch((error: Error): number => {
    console.error(`Error caught: ${error.message}`);
    return 10; // 恢复链式调用
  })
  .then((value: number): number => {
    console.info(`Recovered value: ${value}`);
    return value * 2;
  })
  .then((finalValue: number): void => {
    console.info(`Final value: ${finalValue}`);
  });

// 输出：
// Error caught: Value too small
// Recovered value: 10
// Final value: 20
```

### Promise的静态方法

Promise提供resolve、reject、all、race等静态方法，用于创建和组合Promise实例。

<!-- @[promise_static_methods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Async.ets) -->

``` TypeScript
// Promise.resolve() 和Promise.reject()
let resolvedPromise: Promise<string> = Promise.resolve('Resolved value');
let staticRejectedPromise: Promise<string> = Promise.reject(new Error('Rejected error'));

resolvedPromise.then((value: string): void => console.info(value)); // Resolved value
staticRejectedPromise.catch((error: Error): void => console.error(error.message)); // Rejected error

// Promise.all()：等待所有Promise完成
let staticPromise1: Promise<number> = Promise.resolve(1);
let staticPromise2: Promise<number> = Promise.resolve(2);
let staticPromise3: Promise<number> = Promise.resolve(3);

Promise.all([staticPromise1, staticPromise2, staticPromise3])
  .then((values: number[]): void => console.info(`All values: ${values.join(', ')}`)); // 1, 2, 3

// Promise.all() 失败示例
let failedPromise: Promise<number> = Promise.reject(new Error('Failed'));

Promise.all([staticPromise1, failedPromise, staticPromise3])
  .catch((error: Error): void => console.error(`One promise failed: ${error.message}`));

// Promise.race()：返回最先完成的Promise
let fastPromise: Promise<string> = new Promise<string>((resolve: (value: string) => void) => {
  setTimeout(() => resolve('Fast'), 100);
});

let slowPromise: Promise<string> = new Promise<string>((resolve: (value: string) => void) => {
  setTimeout(() => resolve('Slow'), 200);
});

Promise.race([fastPromise, slowPromise])
  .then((value: string): void => console.info(`Race winner: ${value}`)); // Fast

// Promise.allSettled()：返回所有Promise的结果（无论成功或失败）
let successPromise: Promise<string> = Promise.resolve('Success');
let failurePromise: Promise<string> = Promise.reject(new Error('Failure'));

Promise.allSettled([successPromise, failurePromise])
  .then((results): void => {
    results.forEach((result): void => {
      if (result.status === 'fulfilled') {
        console.info(`Fulfilled: ${result.value}`);
      } else {
        console.info(`Rejected: ${result.reason}`);
      }
    });
  });

// Promise.any()：返回第一个成功的Promise（ES2021）
let promiseA: Promise<string> = Promise.reject(new Error('A failed'));
let promiseB: Promise<string> = Promise.resolve('B succeeded');
let promiseC: Promise<string> = Promise.resolve('C succeeded');

Promise.any([promiseA, promiseB, promiseC])
  .then((value: string): void => console.info(`First success: ${value}`)) // B succeeded
  .catch((_error: Error): void => console.error('All promises rejected'));
```

## 并发任务执行

并发任务执行通过Promise.all、并发限制器等机制协调多个异步操作的执行顺序和资源占用，在保证吞吐量的同时避免资源耗尽。

### Promise.all的使用

`Promise.all`是一个并发执行多个Promise的方法，它接受一个Promise数组，返回一个新的Promise。

<!-- @[promise_all_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/PromiseAllUsage.ets) -->

``` TypeScript
import http from '@ohos.net.http';

// Promise.all：并行执行多个异步任务
async function fetchAllData(): Promise<void> {
  console.info('Fetching all data...');
  
  let startTime = Date.now();
  
  // 并行发起三个请求
  let results = await Promise.all([
    http.createHttp().request('/api/users').then(res => res.result),
    http.createHttp().request('/api/products').then(res => res.result),
    http.createHttp().request('/api/orders').then(res => res.result)
  ]);
  let users = results[0];
  let products = results[1];
  let orders = results[2];
  
  let endTime = Date.now();
  console.info(`All requests completed in ${endTime - startTime}ms`);
  
  console.info(`Users: ${users}`);
  console.info(`Products: ${products}`);
  console.info(`Orders: ${orders}`);
}

fetchAllData();

// Promise.all失败处理
async function fetchAllWithErrorHandling(): Promise<void> {
  try {
    let results = await Promise.all([
      http.createHttp().request('/api/data1').then(res => res.result),
      http.createHttp().request('/api/data2').then(res => res.result),
      http.createHttp().request('/api/data3').then(res => res.result)
    ]);
    let data1 = results[0];
    let data2 = results[1];
    let data3 = results[2];
    
    console.info(`All data fetched successfully: ${data1}, ${data2}, ${data3}`);
  } catch (error) {
    console.error(`At least one request failed: ${(error as Error).message}`);
  }
}
```

### Promise.race的使用

`Promise.race`是一个竞赛执行多个Promise的方法，它返回最先完成（成功或失败）的Promise结果。

<!-- @[promise_race_timeout](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/PromiseRaceTimeout.ets) -->

``` TypeScript
import http from '@ohos.net.http';

// Promise.race：竞赛模式，返回最先完成的Promise
async function fetchWithTimeout(url: string, timeoutMs: number): Promise<string> {
  // 创建超时Promise
  let timeoutPromise: Promise<string> = new Promise<string>((_resolve, reject) => {
    setTimeout(() => reject(new Error('Timeout')), timeoutMs);
  });

  // 创建请求Promise
  let fetchPromise: Promise<string> = http.createHttp().request(url)
    .then((res: http.HttpResponse) => res.result as string);

  // 竞赛：超时或请求完成
  try {
    let result: string = await Promise.race<string>([fetchPromise, timeoutPromise]);
    return result;
  } catch (error) {
    if ((error as Error).message === 'Timeout') {
      console.error('Request timed out');
    } else {
      console.error(`Request failed: ${(error as Error).message}`);
    }
    throw new Error((error as Error).message);
  }
}

// 使用示例
async function testRace(): Promise<void> {
  try {
    let data = await fetchWithTimeout('/api/data', 5000);
    console.info(`Data: ${data}`);
  } catch (error) {
    console.error('Failed to fetch data');
  }
}

testRace();
```

### Promise.allSettled的使用

`Promise.allSettled`是一个执行多个Promise并收集所有结果的方法，无论成功或失败都会等待所有Promise完成。

<!-- @[promise_allsettled_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/PromiseAllSettledUsage.ets) -->

``` TypeScript
import http from '@ohos.net.http';

interface FetchError {
  error: string;
}

// Promise.allSettled：获取所有Promise的结果
async function fetchMultipleUrls(urls: string[]): Promise<void> {
  let fetchPromises = urls.map(url => 
    http.createHttp().request(url)
      .then(res => res.result)
      .catch((error: Error): FetchError => ({ error: error.message }))
  );
  
  let results = await Promise.allSettled(fetchPromises);
  
  // 统计成功和失败数量
  let successCount = 0;
  let failureCount = 0;
  
  results.forEach((result, index) => {
    if (result.status === 'fulfilled') {
      successCount++;
      console.info(`URL ${index} success: ${result.value}`);
    } else {
      failureCount++;
      console.error(`URL ${index} failed: ${result.reason}`);
    }
  });
  
  console.info(`Summary: ${successCount} successes, ${failureCount} failures`);
}

// 使用示例
let urls = [
  '/api/users',
  '/api/products',
  '/api/orders',
  '/api/inventory'
];

fetchMultipleUrls(urls);
```

### Promise.any的使用

`Promise.any`是一个执行多个Promise并返回第一个成功结果的方法，与Promise.race不同的是它只关心成功结果而忽略拒绝(reject)。

<!-- @[promise_any_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/PromiseAnyUsage.ets) -->

``` TypeScript
import http from '@ohos.net.http';

// Promise.any：返回第一个成功的Promise
async function fetchFromMultipleSources(): Promise<Object> {
  let sources = [
    'EXAMPLE_API_URL_1',
    'EXAMPLE_API_URL_2',
    'EXAMPLE_API_URL_3'
  ];
  
  let fetchPromises = sources.map((source: string): Promise<Object> => 
    http.createHttp().request(source)
      .then((res): Object => {
        if (res.responseCode !== 200) {
          throw new Error(`HTTP ${res.responseCode}`);
        }
        return res.result as Object;
      })
  );
  
  try {
    // 使用第一个成功的响应
    let data = await Promise.any(fetchPromises);
    console.info(`Data from first successful source: ${data}`);
    return data;
  } catch (error) {
    console.error(`All sources failed: ${(error as Error).message}`);
    throw new Error((error as Error).message);
  }
}

fetchFromMultipleSources();
```

## 生成器与异步迭代

TypeScript支持`function*`、`yield`、异步生成器和`for await...of`。ArkTS不支持生成器函数，异步流程优先通过`Promise`、`async`/`await`、数组遍历和显式任务队列表达。

### TypeScript生成器对照

TypeScript的function*生成器在ArkTS中不支持，使用数组和普通函数替代。

**TypeScript对照**

<!-- @[ts_generator_note](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Async.ts) -->

``` TypeScript
// TypeScript对照写法，ArkTS不支持：
function* numberGenerator() {
    yield 1;
    yield 2;
    yield 3;
}
```

### 使用数组和普通函数替代生成器

当需要按需生成序列数据时，可用返回数组的普通函数替代生成器，如`createRange(start, end)`返回`number[]`。

<!-- @[create_range](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Async.ets) -->

``` TypeScript
function createRange(start: number, end: number): number[] {
  let result: number[] = [];
  for (let i: number = start; i <= end; i++) {
    result.push(i);
  }
  return result;
}

let rangeValues: number[] = createRange(1, 5);
for (let value of rangeValues) {
  console.info(`${value}`);
}
```

### 使用Promise处理异步序列

通过`for...of`配合`await`串行处理多个异步数据源，每次等待前一个完成后再处理下一个。

<!-- @[async_data_sources](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Async.ets) -->

``` TypeScript
async function fetchDataSource1(): Promise<string> {
  return 'Data 1';
}

async function fetchDataSource2(): Promise<string> {
  return 'Data 2';
}

async function fetchDataSource3(): Promise<string> {
  return 'Data 3';
}

async function processAsyncSources(): Promise<void> {
  let sources: Promise<string>[] = [
    fetchDataSource1(),
    fetchDataSource2(),
    fetchDataSource3()
  ];

  for (let source of sources) {
    try {
      let data: string = await source;
      console.info(`Processed: ${data}`);
    } catch (error) {
      console.error(`Source failed: ${(error as Error).message}`);
    }
  }
}
```

### for await...of

`for await...of`用于遍历可迭代对象，自动`await`每个元素。当数据源是`Promise`数组时，`for await...of`会依次等待每个`Promise`完成，适用于需要按顺序处理异步结果的场景。

<!-- @[for_await_of](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Async.ets) -->

``` TypeScript
async function processAsyncItems(): Promise<void> {
  let asyncItems: Promise<string>[] = [
    Promise.resolve('item1'),
    Promise.resolve('item2'),
    Promise.resolve('item3')
  ];

  for await (const item of asyncItems) {
    console.info(`${item}`); // item1, item2, item3
  }
}

processAsyncItems();
```

也可以使用`for...of`遍历`Promise`数组并手动`await`，效果与`for await...of`等价：

<!-- @[for_of_await](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Async.ets) -->

``` TypeScript
async function processAsyncItemsManually(): Promise<void> {
  let asyncItems: Promise<string>[] = [
    Promise.resolve('item1'),
    Promise.resolve('item2'),
    Promise.resolve('item3')
  ];

  for (let itemPromise of asyncItems) {
    let item: string = await itemPromise;
    console.info(`${item}`); // item1, item2, item3
  }
}

processAsyncItemsManually();
```

## 并发控制

并发限制器控制同时执行的异步任务数量，避免资源耗尽。

### 限制并发请求数量

并发限制器通过维护一个固定大小的执行池，确保同时运行的异步任务不超过设定阈值，典型实现使用计数器配合Promise队列。

<!-- @[concurrency_limiter](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Async.ets) -->

``` TypeScript
// 并发限制器
class RequestConcurrencyLimiter {
  private maxConcurrency: number;
  private currentConcurrency: number = 0;
  private queue: (() => Promise<void>)[] = [];
  
  constructor(maxConcurrency: number) {
    this.maxConcurrency = maxConcurrency;
  }
  
  async run<T>(task: () => Promise<T>): Promise<T> {
    // 如果当前并发数已达上限，加入队列等待
    if (this.currentConcurrency >= this.maxConcurrency) {
      return new Promise<T>((resolve: (value: T) => void, reject: (reason: Error) => void) => {
        this.queue.push(async (): Promise<void> => {
          try {
            let result: T = await this.executeTask<T>(task);
            resolve(result);
          } catch (error) {
            reject(error as Error);
          }
        });
      });
    }
    
    return this.executeTask<T>(task);
  }
  
  private async executeTask<T>(task: () => Promise<T>): Promise<T> {
    this.currentConcurrency++;
    
    try {
      let result: T = await task();
      return result;
    } finally {
      this.currentConcurrency--;
      
      // 执行队列中的下一个任务
      if (this.queue.length > 0) {
        let nextTask: (() => Promise<void>) | undefined = this.queue.shift();
        if (nextTask) {
          nextTask();
        }
      }
    }
  }
}

function fetchWithLimitRequest(url: string): Promise<string> {
  return Promise.resolve(`response from ${url}`);
}

// 使用示例
async function fetchWithLimit(limiterUrls: string[], maxConcurrency: number): Promise<void> {
  let limiter: RequestConcurrencyLimiter = new RequestConcurrencyLimiter(maxConcurrency);
  
  let tasks: Promise<string>[] = limiterUrls.map((url: string): Promise<string> => 
    limiter.run<string>((): Promise<string> => fetchWithLimitRequest(url))
  );
  
  let results: string[] = await Promise.all(tasks);
  console.info(`All requests completed: ${results.length}`);
}

let limiterUrls: string[] = [];
for (let i: number = 0; i < 20; i++) {
  limiterUrls.push(`/api/data/${i}`);
}
fetchWithLimit(limiterUrls, 5); // 限制最多5个并发请求
```

### 任务队列的实现

任务队列将异步任务排队串行执行，确保前一个完成后再启动下一个。

<!-- @[task_queue](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Async.ets) -->

``` TypeScript
// 任务队列
class TaskQueue {
  private tasks: (() => Promise<void>)[] = [];
  private processing: boolean = false;
  
  addTask(task: () => Promise<void>): void {
    this.tasks.push(task);
    this.processQueue();
  }
  
  private async processQueue(): Promise<void> {
    if (this.processing || this.tasks.length === 0) {
      return;
    }
    
    this.processing = true;
    
    while (this.tasks.length > 0) {
      let task: (() => Promise<void>) | undefined = this.tasks.shift();
      if (task === undefined) {
        continue;
      }
      try {
        await task();
      } catch (error) {
        console.error(`Task failed: ${(error as Error).message}`);
      }
    }
    
    this.processing = false;
  }
}

// 使用示例
let taskQueue = new TaskQueue();

taskQueue.addTask(async () => {
  console.info('Task 1 started');
  await new Promise<void>((resolve: () => void) => setTimeout(resolve, 1000));
  console.info('Task 1 completed');
});

taskQueue.addTask(async () => {
  console.info('Task 2 started');
  await new Promise<void>((resolve: () => void) => setTimeout(resolve, 500));
  console.info('Task 2 completed');
});

taskQueue.addTask(async () => {
  console.info('Task 3 started');
  await new Promise<void>((resolve: () => void) => setTimeout(resolve, 800));
  console.info('Task 3 completed');
});

// 输出（串行执行）：
// Task 1 started
// Task 1 completed（1秒后）
// Task 2 started
// Task 2 completed（1.5秒后）
// Task 3 started
// Task 3 completed（2.3秒后）
```

### 信号量机制的模拟

信号量通过计数器控制并发资源访问，限制同时执行的任务数量。

<!-- @[semaphore](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Async.ets) -->

``` TypeScript
// 信号量（Semaphore）
class Semaphore {
  private permits: number;
  private waitQueue: ((permit: number) => void)[] = [];
  
  constructor(permits: number) {
    this.permits = permits;
  }
  
  async acquire(): Promise<number> {
    if (this.permits > 0) {
      this.permits--;
      return this.permits;
    }
    
    // 等待许可
    return new Promise<number>((resolve) => {
      this.waitQueue.push(resolve);
    });
  }
  
  release(): void {
    this.permits++;
    
    // 通知等待队列中的第一个任务
    if (this.waitQueue.length > 0) {
      let nextWaiter: ((permit: number) => void) | undefined = this.waitQueue.shift();
      if (nextWaiter !== undefined) {
        this.permits--;
        nextWaiter(this.permits);
      }
    }
  }
}

// 使用示例
async function limitedResourceAccess(semaphore: Semaphore): Promise<void> {
  let permit = await semaphore.acquire();
  
  console.info('Accessing resource...');
  await new Promise<void>((resolve: () => void) => setTimeout(resolve, 1000));
  console.info('Resource access completed');
  
  semaphore.release();
}

let semaphore = new Semaphore(3); // 最多3个并发访问

// 启动多个并发任务
for (let i: number = 0; i < 10; i++) {
  limitedResourceAccess(semaphore);
}

// 输出：最多同时3个任务访问资源
```

### 避免竞态条件的方案

通过互斥锁或原子操作确保共享状态在并发访问时不被同时修改，防止竞态条件。

<!-- @[race_condition_mutex](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Async.ets) -->

``` TypeScript
interface SharedCounter {
  value: number;
}

// 竞态条件示例
let sharedData: SharedCounter = { value: 0 };

async function incrementWithoutLock(): Promise<void> {
  let current: number = sharedData.value;
  await new Promise<void>((resolve: () => void) => setTimeout(resolve, 10)); // 模拟延迟
  sharedData.value = current + 1;
}

// 不加锁：可能导致竞态条件
async function raceConditionExample(): Promise<void> {
  sharedData.value = 0;
  
  await Promise.all([
    incrementWithoutLock(),
    incrementWithoutLock(),
    incrementWithoutLock()
  ]);
  
  console.info(`Final value (race condition): ${sharedData.value}`); // 可能小于3
}

raceConditionExample();

// 使用互斥锁（Mutex）避免竞态条件
class Mutex {
  private locked: boolean = false;
  private queue: (() => void)[] = [];
  
  async lock(): Promise<void> {
    if (!this.locked) {
      this.locked = true;
      return;
    }
    
    return new Promise<void>((resolve: () => void) => {
      this.queue.push(resolve);
    });
  }
  
  unlock(): void {
    if (this.queue.length > 0) {
      let nextWaiter: (() => void) | undefined = this.queue.shift();
      if (nextWaiter) {
        nextWaiter();
      }
    } else {
      this.locked = false;
    }
  }
}

async function incrementWithLock(mutex: Mutex): Promise<void> {
  await mutex.lock();
  
  try {
    let current: number = sharedData.value;
    await new Promise<void>((resolve: () => void) => setTimeout(resolve, 10));
    sharedData.value = current + 1;
  } finally {
    mutex.unlock();
  }
}

async function safeIncrementExample(): Promise<void> {
  sharedData.value = 0;
  let mutex: Mutex = new Mutex();
  
  await Promise.all([
    incrementWithLock(mutex),
    incrementWithLock(mutex),
    incrementWithLock(mutex)
  ]);
  
  console.info(`Final value (with lock): ${sharedData.value}`); // 3
}

safeIncrementExample();
```
