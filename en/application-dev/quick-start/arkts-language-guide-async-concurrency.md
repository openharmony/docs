# Asynchronous Concurrency

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=c25b60c237b212cfc232b5aee67d2c42ba90278a translatedAt=2026-08-13T08:52:17.422Z pushedAt=2026-08-13T12:02:50.462Z -->

Asynchronous concurrent programming is an important part of modern app development, as it improves program performance and responsiveness. Built on TypeScript, ArkTS inherits the asynchronous programming mechanism of JavaScript and provides powerful asynchronous processing tools such as async/await and Promise.

## Basic Concepts of Concurrency

Concurrency allows a program to advance multiple tasks simultaneously without blocking the main thread. ArkTS implements asynchronous concurrency through async/await and Promise.

### Definition and Core Value of Concurrency

Concurrency allows a program to handle multiple tasks at the same time, delivering benefits in four dimensions: fully utilizing computing resources and avoiding blocking to improve performance, maintaining responsiveness and avoiding UI freezes to improve the experience, allocating system resources reasonably, and supporting modular, decoupled architecture design.

<!-- @[sync_vs_async](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Async.ets) -->

``` TypeScript
// Synchronous execution: blocking wait
function syncOperation(): void {
  console.info('Starting operation');
  // Simulate a time-consuming operation
  let start = Date.now();
  while (Date.now() - start < 1000) {
    // Block for 1 second.
  }
  console.info('Operation completed.');
}

syncOperation();
console.info('Continue executing other tasks.');
// Output order: Start operation -> Operation completed -> Continue executing other tasks.

// Asynchronous execution: non-blocking.
function asyncOperation(): Promise<void> {
  console.info('Start asynchronous operation');
  return new Promise((resolve) => {
    setTimeout(() => {
      console.info('Asynchronous operation completed');
      resolve();
    }, 1000);
  });
}

asyncOperation();
console.info('Continue executing other tasks immediately');
// Output order: Start asynchronous operation -> Continue executing other tasks immediately -> Asynchronous operation completed (after 1 second)
```

### Difference Between Concurrency and Parallelism

Concurrency advances multiple tasks alternately through asynchronous I/O, while parallelism executes computations simultaneously through multiple threads.

<!-- @[concurrent_vs_parallel](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ConcurrentVsParallel.ets) -->

``` TypeScript
import http from '@ohos.net.http';
import { worker } from '@kit.ArkTS';

// Concurrency example: asynchronous I/O operations.
async function concurrentExample(): Promise<void> {
  console.info('Start concurrent tasks');
  
  // Start multiple asynchronous tasks (without waiting).
  let task1 = http.createHttp().request('/api/users');
  let task2 = http.createHttp().request('/api/products');
  let task3 = http.createHttp().request('/api/orders');
  
  // Execute concurrently and wait for all tasks to complete.
  let responses = await Promise.all([task1, task2, task3]);
  let users = responses[0];
  let products = responses[1];
  let orders = responses[2];
  
  console.info('All concurrent tasks completed.');
}

// Parallel example: multi-thread computation.
function parallelExample(): void {
  console.info('Start parallel tasks.');
  
  // Create a Worker thread for parallel computation.
  let worker1 = new worker.ThreadWorker('entry/ets/workers/ComputeWorker.ets');
  let worker2 = new worker.ThreadWorker('entry/ets/workers/ComputeWorker.ets');
  
  worker1.postMessage({ task: 'calculate1' });
  worker2.postMessage({ task: 'calculate2' });
  
  worker1.onmessage = (e) => console.info(`Worker 1 completed: ${e.data}`);
  worker2.onmessage = (e) => console.info(`Worker 2 completed: ${e.data}`);
}
```

### ArkTS Concurrency Implementation Mechanism

The asynchronous mechanism of ArkTS is based on the event loop: synchronous code runs first, microtasks (Promise.then) run after the current task, and macro tasks (setTimeout) run in the next round.

<!-- @[event_loop_mechanism](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Async.ets) -->

``` TypeScript
// Event loop mechanism
console.info('1. Start');

// Macro task: setTimeout, setInterval, I/O, etc.
setTimeout(() => {
  console.info('2. setTimeout (macro task)');
}, 0);

// Micro task: Promise, queueMicrotask, etc.
Promise.resolve().then(() => {
  console.info('3. Promise (micro task)');
});

console.info('4. Synchronous code ends');

// Output order:
// 1. Start
// 4. Synchronous code ends
// 3. Promise (microtask)
// 2. setTimeout (macrotask)
```

## Asynchronous Functions

An async function automatically wraps its return value in a Promise and, together with `await`, enables synchronous-style asynchronous code.

### Declaring Asynchronous Functions

Add `async` before the `function` keyword to declare an asynchronous function. This also applies to arrow functions.

<!-- @[async_function_declaration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Async.ets) -->

``` TypeScript
// Basic asynchronous function declaration
async function fetchData(): Promise<string> {
  return 'Data loaded';
}

// Asynchronous function in arrow function form
const fetchUserData = async (): Promise<User> => {
  return { id: 1, name: 'Alice' };
};

// Asynchronous function in class method form
class DataService {
  async getData(): Promise<string> {
    return 'Data from service';
  }
}

interface User {
  id: number;
  name: string;
}

// Use an asynchronous function.
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

### Return Value Characteristics of Asynchronous Functions

The return value of an async function is automatically wrapped in a Promise. `return 'Hello'` is equivalent to `return Promise.resolve('Hello')`.

<!-- @[async_function_return_value](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Async.ets) -->

``` TypeScript
// Asynchronous functions automatically wrap the return value in a Promise.
async function returnString(): Promise<string> {
  return 'Hello'; // Automatically wrapped as Promise.resolve('Hello').
}

async function returnNumber(): Promise<number> {
  return 42; // Automatically wrapped as Promise.resolve(42).
}

interface ReturnObjectResult {
  id: number;
}

async function returnObject(): Promise<ReturnObjectResult> {
  return { id: 1 }; // Automatically wrap the return value in Promise.resolve({ id: 1 }).
}

// Use the return value.
returnString().then((data: string) => console.info(data)); // Hello
returnNumber().then((num: number) => console.info(`${num}`));   // 42
returnObject().then((obj: ReturnObjectResult) => console.info(`${obj.id}`)); // 1

// An asynchronous function returns a Promise.
async function returnPromise(): Promise<string> {
  return Promise.resolve('Already a Promise');
}

returnPromise().then((data: string) => console.info(data)); // Already a Promise
```

### Differences Between Asynchronous Functions and Regular Functions

A regular function executes synchronously, and the caller waits for the result. An async function executes asynchronously, and the caller immediately obtains a Promise without blocking subsequent code.

<!-- @[sync_vs_async_function](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Async.ets) -->

``` TypeScript
// Normal function: synchronous execution
function normalFunction(): string {
  console.info('Normal function executing');
  return 'Result';
}

let result1 = normalFunction();
console.info(`After normal function: ${result1}`);
// Output order:
// Normal function executing
// After normal function: Result

// Asynchronous function: asynchronous execution
async function asyncFunction(): Promise<string> {
  console.info('Async function executing');
  return 'AsyncResult';
}

let result2 = asyncFunction();
console.info(`After async function: ${result2}`);
// Output order:
// Async function executing
// After async function: Promise { 'AsyncResult' }

// An asynchronous function requires await or .then() to obtain the result.
asyncFunction().then(result => console.info('Async result:', result));
// Output: Async result: AsyncResult
```

### Error Handling in Asynchronous Functions

Wrap the `await` expression in a `try-catch` block inside an `async` function to catch the `Promise` rejection.

<!-- @[async_function_error_handling](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AsyncErrorHandling.ets) -->

``` TypeScript
import http from '@ohos.net.http';

// Error handling in an asynchronous function.
async function fetchDataWithError(): Promise<string> {
  try {
    // Simulate an asynchronous operation that may fail.
    let response = await http.createHttp().request('/api/data');
    
    if (response.responseCode !== 200) {
      throw new Error(`HTTP ${response.responseCode}`);
    }
    
    let data = response.result;
    return JSON.stringify(data);
  } catch (error) {
    console.error('Fetch error:', (error as Error).message);
    throw new Error((error as Error).message); // Rethrow the error.
  }
}

// Use try-catch to handle errors in the asynchronous function.
async function handleFetch(): Promise<void> {
  try {
    let data = await fetchDataWithError();
    console.info(`Data: ${data}`);
  } catch (error) {
    console.error('Handler error:', (error as Error).message);
  }
}

// Use Promise.catch() to handle errors.
fetchDataWithError()
  .then(data => console.info(`Success: ${data}`))
  .catch((error: Error) => console.error(`Catch: ${error.message}`));
```

## await Keyword

`await` waits for an asynchronous operation to complete, suspending function execution until the Promise is resolved.

### Rules for Using await

The `await` keyword is used to wait for a Promise to complete and obtain its result. It can only be used inside an async function.

<!-- @[ts_await_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Async.ts) -->

``` TypeScript
async function example(): Promise<void> {
  // await can only be used inside an async function.
  let result = await Promise.resolve('Hello');
  console.info(`${result}`);
}

// Incorrect example: using await in a normal function.
function normalFunction() {
    let result = await Promise.resolve('Hello'); // Compilation error.
}

// await can be used with any Promise.
async function awaitExample(): Promise<void> {
  // Wait for Promise.resolve().
  let result1 = await Promise.resolve('Immediate');
  console.info(`${result1}`);

  // Wait for Promise.reject() (error handling required).
  try {
    let result2 = await Promise.reject('Error');
  } catch (error) {
    console.error('Caught:', error);
  }

  // Wait for the Promise created by setTimeout.
  let result3 = await new Promise<string>((resolve) => {
    setTimeout(() => resolve('Delayed'), 1000);
  });
  console.info(`${result3}`);
}

awaitExample();
```

### Relationship Between await and Promise

`await` waits for a Promise to complete and retrieves the resolved value. If the Promise is rejected, an exception is thrown and caught by `try-catch`.

<!-- @[await_promise](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/AwaitPromise.ets) -->

``` TypeScript
import http from '@ohos.net.http';

async function awaitPromise(): Promise<void> {
  // await waits for the Promise to complete and obtains the resolved value.
  let promise1 = Promise.resolve(42);
  let value1 = await promise1;
  console.info(`Value 1: ${value1}`); // 42
  
  // await catches the error of the Promise.
  let promise2 = Promise.reject(new Error('Failed'));
  try {
    let value2 = await promise2;
  } catch (error) {
    console.error(`Error 2: ${(error as Error).message}`); // Failed
  }
  
  // await waits for the fetch request.
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

### Serial Execution of Multiple await

Multiple await expressions are executed in sequence, with each one running only after the previous one completes. This is suitable for asynchronous tasks that have dependencies.

<!-- @[await_serial_execution](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Async.ets) -->

``` TypeScript
async function serialExecution(): Promise<void> {
  console.info('Start');
  
  // Serial execution: one after another
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
// Output order:
// Start
// Task 1 completed (after 1 second)
// Task 2 completed (after 2 seconds)
// Task 3 completed (after 3 seconds)
// All tasks completed: Result 1 Result 2 Result 3
```

### Non-blocking Nature of await

await suspends the execution of the current async function instead of blocking the thread. Control is returned to the event loop, and execution resumes after the Promise is fulfilled.

<!-- @[await_non_blocking](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Async.ets) -->

``` TypeScript
async function nonBlockingExample(): Promise<void> {
  console.info('1. Async function start');
  
  // await waits for the Promise but does not block external code.
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

// Output order:
// 1. Async function start
// 4. External code continues (without waiting)
// 2. Promise resolved (after 1 second)
// 3. Async function end
```

## Promise Object

A Promise represents the result of an asynchronous operation and supports chaining and error handling.

### Promise States

A promise has three states: pending, fulfilled, and rejected, which indicate that the asynchronous operation is in progress, successful, or failed.

<!-- @[promise_states](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Async.ets) -->

``` TypeScript
// Pending state
let pendingPromise: Promise<void> = new Promise<void>((resolve: () => void, reject: (reason: Error) => void) => {
  // Neither resolve nor reject is called, so the promise remains in the pending state.
});

console.info('Promise is in the pending state'); // Promise { <pending> }

// Fulfilled state (success)
let fulfilledPromise: Promise<string> = new Promise<string>((resolve: (value: string) => void) => {
  resolve('Success');
});

fulfilledPromise.then((value: string) => console.info(value)); // Success

// Rejected state (failure)
let rejectedPromise: Promise<string> = new Promise<string>(
  (resolve: (value: string) => void, reject: (reason: Error) => void) => {
    reject(new Error('Failure'));
  }
);

rejectedPromise.catch((error: Error) => console.error(error.message)); // Failure

// State transition: only from Pending -> Fulfilled or Pending -> Rejected
let irreversiblePromise: Promise<string> = new Promise<string>(
  (resolve: (value: string) => void, reject: (reason: Error) => void) => {
    resolve('First resolve');
    reject(new Error('Second reject')); // Invalid; the Promise state is already settled
  }
);

irreversiblePromise.then((value: string) => console.info(value)); // First resolve
```

### Creating a Promise

A Promise is created with `new Promise((resolve, reject) => {...})`. You can also use `Promise.resolve` and `Promise.reject` to quickly create a Promise that is already settled.

<!-- @[promise_creation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Async.ets) -->

``` TypeScript
// Method 1: Use the Promise constructor.
let promise1 = new Promise<string>((resolve, reject) => {
  // Asynchronous operation.
  setTimeout(() => {
    let success = true;
    if (success) {
      resolve('Operation succeeded');
    } else {
      reject(new Error('Operation failed'));
    }
  }, 1000);
});

// Method 2: Use Promise.resolve().
let promise2 = Promise.resolve('Immediately resolved');

// Method 3: Use Promise.reject()
let promise3 = Promise.reject(new Error('Immediately rejected'));

// Method 4: Wrap an asynchronous operation as a Promise
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

### Promise Chaining

Promise chaining uses the `then` method to link multiple asynchronous operations for sequential execution.

<!-- @[promise_chaining](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Async.ets) -->

``` TypeScript
// Promise chaining
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

// Output:
// Step 1: 1
// Step 2: 2
// Step 3: 4
// Final result: Final: 4

// Error handling chain
Promise.resolve(1)
  .then((value: number): number => {
    if (value < 10) {
      throw new Error('Value too small');
    }
    return value;
  })
  .catch((error: Error): number => {
    console.error(`Error caught: ${error.message}`);
    return 10; // Resume the chain call.
  })
  .then((value: number): number => {
    console.info(`Recovered value: ${value}`);
    return value * 2;
  })
  .then((finalValue: number): void => {
    console.info(`Final value: ${finalValue}`);
  });

// Output:
// Error caught: Value too small
// Recovered value: 10
// Final value: 20
```

### Static Methods of Promise

Promise provides static methods such as `resolve`, `reject`, `all`, and `race` for creating and combining Promise instances.

<!-- @[promise_static_methods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Async.ets) -->

``` TypeScript
// Promise.resolve() and Promise.reject()
let resolvedPromise: Promise<string> = Promise.resolve('Resolved value');
let staticRejectedPromise: Promise<string> = Promise.reject(new Error('Rejected error'));

resolvedPromise.then((value: string): void => console.info(value)); // Resolved value
staticRejectedPromise.catch((error: Error): void => console.error(error.message)); // Rejected error

// Promise.all(): Wait for all promises to complete.
let staticPromise1: Promise<number> = Promise.resolve(1);
let staticPromise2: Promise<number> = Promise.resolve(2);
let staticPromise3: Promise<number> = Promise.resolve(3);

Promise.all([staticPromise1, staticPromise2, staticPromise3])
  .then((values: number[]): void => console.info(`All values: ${values.join(', ')}`)); // 1, 2, 3

// Example of Promise.all() failure
let failedPromise: Promise<number> = Promise.reject(new Error('Failed'));

Promise.all([staticPromise1, failedPromise, staticPromise3])
  .catch((error: Error): void => console.error(`One promise failed: ${error.message}`));

// Promise.race(): Returns the first Promise to settle.
let fastPromise: Promise<string> = new Promise<string>((resolve: (value: string) => void) => {
  setTimeout(() => resolve('Fast'), 100);
});

let slowPromise: Promise<string> = new Promise<string>((resolve: (value: string) => void) => {
  setTimeout(() => resolve('Slow'), 200);
});

Promise.race([fastPromise, slowPromise])
  .then((value: string): void => console.info(`Race winner: ${value}`)); // Fast

// Promise.allSettled(): Returns the results of all Promises (whether fulfilled or rejected).
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

// Promise.any(): Returns the first fulfilled Promise (ES2021).
let promiseA: Promise<string> = Promise.reject(new Error('A failed'));
let promiseB: Promise<string> = Promise.resolve('B succeeded');
let promiseC: Promise<string> = Promise.resolve('C succeeded');

Promise.any([promiseA, promiseB, promiseC])
  .then((value: string): void => console.info(`First success: ${value}`)) // B succeeded
  .catch((_error: Error): void => console.error('All promises rejected'));
```

## Concurrent Task Execution

Concurrent task execution coordinates the execution order and resource usage of multiple asynchronous operations through mechanisms such as Promise.all and concurrency limiters, ensuring throughput while avoiding resource exhaustion.

### Using Promise.all

`Promise.all` is a method for executing multiple promises concurrently. It accepts an array of promises and returns a new promise.

<!-- @[promise_all_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/PromiseAllUsage.ets) -->

``` TypeScript
import http from '@ohos.net.http';

// Promise.all: Execute multiple asynchronous tasks in parallel.
async function fetchAllData(): Promise<void> {
  console.info('Fetching all data...');
  
  let startTime = Date.now();
  
  // Initiate three requests in parallel.
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

// Handle Promise.all failures.
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

### Using Promise.race

`Promise.race` is a method that runs multiple promises in a race and returns the result of the promise that settles first (whether fulfilled or rejected).

<!-- @[promise_race_timeout](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/PromiseRaceTimeout.ets) -->

``` TypeScript
import http from '@ohos.net.http';

// Promise.race: race mode, returns the promise that settles first.
async function fetchWithTimeout(url: string, timeoutMs: number): Promise<string> {
  // Create a timeout promise.
  let timeoutPromise: Promise<string> = new Promise<string>((_resolve, reject) => {
    setTimeout(() => reject(new Error('Timeout')), timeoutMs);
  });

  // Create a request promise.
  let fetchPromise: Promise<string> = http.createHttp().request(url)
    .then((res: http.HttpResponse) => res.result as string);

  // Race: timeout or request completion
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

// Usage example
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

### Using Promise.allSettled

`Promise.allSettled` is a method that executes multiple promises and collects all results, waiting for all promises to complete regardless of success or failure.

<!-- @[promise_allsettled_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/PromiseAllSettledUsage.ets) -->

``` TypeScript
import http from '@ohos.net.http';

interface FetchError {
  error: string;
}

// Promise.allSettled: Obtain the results of all promises.
async function fetchMultipleUrls(urls: string[]): Promise<void> {
  let fetchPromises = urls.map(url => 
    http.createHttp().request(url)
      .then(res => res.result)
      .catch((error: Error): FetchError => ({ error: error.message }))
  );
  
  let results = await Promise.allSettled(fetchPromises);
  
  // Count the number of successes and failures.
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

// Example usage
let urls = [
  '/api/users',
  '/api/products',
  '/api/orders',
  '/api/inventory'
];

fetchMultipleUrls(urls);
```

### Using Promise.any

`Promise.any` is a method that executes multiple promises and returns the first successful result. Unlike `Promise.race`, it only cares about successful results and ignores rejections.

<!-- @[promise_any_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/PromiseAnyUsage.ets) -->

``` TypeScript
import http from '@ohos.net.http';

// Promise.any: Return the first fulfilled promise.
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
    // Use the first successful response.
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

## Generators and Asynchronous Iteration

TypeScript supports `function*`, `yield`, asynchronous generators, and `for await...of`. ArkTS does not support generator functions. Asynchronous flows are preferably expressed through `Promise`, `async`/`await`, array iteration, and explicit task queues.

### TypeScript Generator Comparison

The `function*` generator in TypeScript is not supported in ArkTS. Use arrays and regular functions instead.

**TypeScript Comparison**

<!-- @[ts_generator_note](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Async.ts) -->

``` TypeScript
// TypeScript equivalent, not supported in ArkTS:
function* numberGenerator() {
    yield 1;
    yield 2;
    yield 3;
}
```

### Using Arrays and Ordinary Functions Instead of Generators

When you need to generate sequence data on demand, you can use an ordinary function that returns an array instead of a generator, for example, `createRange(start, end)` returns `number[]`.

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

### Using Promise to Process Asynchronous Sequences

Use `for...of` together with `await` to process multiple asynchronous data sources serially, waiting for the previous one to complete before processing the next.

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

`for await...of` is used to iterate over an iterable object, automatically `await`ing each element. When the data source is an array of `Promise` objects, `for await...of` waits for each `Promise` to complete in sequence, which is suitable for scenarios where asynchronous results must be processed in order.

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

You can also use `for...of` to iterate over an array of `Promise` objects and manually `await` each one, which is equivalent to `for await...of`:

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

## Concurrency Control

A concurrency limiter controls the number of asynchronous tasks executed simultaneously to avoid resource exhaustion.

### Limiting the Number of Concurrent Requests

A concurrency limiter maintains a fixed-size execution pool to ensure that the number of concurrently running asynchronous tasks does not exceed a set threshold. A typical implementation uses a counter combined with a Promise queue.

<!-- @[concurrency_limiter](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Async.ets) -->

``` TypeScript
// Concurrency limiter.
class RequestConcurrencyLimiter {
  private maxConcurrency: number;
  private currentConcurrency: number = 0;
  private queue: (() => Promise<void>)[] = [];
  
  constructor(maxConcurrency: number) {
    this.maxConcurrency = maxConcurrency;
  }
  
  async run<T>(task: () => Promise<T>): Promise<T> {
    // If the current concurrency reaches the limit, add the task to the queue and wait.
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
      
      // Execute the next task in the queue.
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

// Usage example
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
fetchWithLimit(limiterUrls, 5); // Limit to a maximum of 5 concurrent requests.
```

### Implementing a Task Queue

A task queue queues asynchronous tasks for serial execution, ensuring that the next task starts only after the previous one completes.

<!-- @[task_queue](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Async.ets) -->

``` TypeScript
// Task queue
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

// Usage example
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

// Output (serial execution):
// Task 1 started
// Task 1 completed (after 1 second)
// Task 2 started
// Task 2 completed (after 1.5 seconds)
// Task 3 started
// Task 3 completed (after 2.3 seconds)
```

### Simulating the Semaphore Mechanism

A semaphore controls access to concurrent resources through a counter, limiting the number of tasks that can run simultaneously.

<!-- @[semaphore](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Async.ets) -->

``` TypeScript
// Semaphore
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
    
    // Wait for a permit.
    return new Promise<number>((resolve) => {
      this.waitQueue.push(resolve);
    });
  }
  
  release(): void {
    this.permits++;
    
    // Notify the first task in the wait queue.
    if (this.waitQueue.length > 0) {
      let nextWaiter: ((permit: number) => void) | undefined = this.waitQueue.shift();
      if (nextWaiter !== undefined) {
        this.permits--;
        nextWaiter(this.permits);
      }
    }
  }
}

// Usage example
async function limitedResourceAccess(semaphore: Semaphore): Promise<void> {
  let permit = await semaphore.acquire();
  
  console.info('Accessing resource...');
  await new Promise<void>((resolve: () => void) => setTimeout(resolve, 1000));
  console.info('Resource access completed');
  
  semaphore.release();
}

let semaphore = new Semaphore(3); // Allow up to 3 concurrent accesses

// Start multiple concurrent tasks
for (let i: number = 0; i < 10; i++) {
  limitedResourceAccess(semaphore);
}

// Output: up to 3 tasks access the resource at the same time
```

### Approaches to Avoiding Race Conditions

Use a mutex or atomic operations to ensure that shared state is not modified simultaneously during concurrent access, thereby preventing race conditions.

<!-- @[race_condition_mutex](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Async.ets) -->

``` TypeScript
interface SharedCounter {
  value: number;
}

// Race condition example
let sharedData: SharedCounter = { value: 0 };

async function incrementWithoutLock(): Promise<void> {
  let current: number = sharedData.value;
  await new Promise<void>((resolve: () => void) => setTimeout(resolve, 10)); // Simulate a delay.
  sharedData.value = current + 1;
}

// Without a lock: may cause a race condition.
async function raceConditionExample(): Promise<void> {
  sharedData.value = 0;
  
  await Promise.all([
    incrementWithoutLock(),
    incrementWithoutLock(),
    incrementWithoutLock()
  ]);
  
  console.info(`Final value (race condition): ${sharedData.value}`); // May be less than 3.
}

raceConditionExample();

// Use a mutex to avoid race conditions.
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