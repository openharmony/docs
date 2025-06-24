# Asynchronous Concurrency (Promise and Async/Await)


Promise and async/await are standard JavaScript asynchronous syntax that provides asynchronous concurrency capabilities. Asynchronous code is suspended and continues to execute later, ensuring that only one piece of code is executed at any given moment. The following are typical scenarios of asynchronous concurrency:

- Non-blocking I/O operations: network requests, file reading and writing, and timers.

- Lightweight tasks without CPU blocking: tasks with short execution times.

- Clear logical dependencies: tasks with explicit order or parallel relationships.

Asynchronous concurrency is a feature of programming languages that allows programs to continue executing other operations without waiting for certain operations to complete.

## Promise

A Promise is an object used to process asynchronous operations. It converts asynchronous operations into a style similar to synchronous operations for easier code writing and maintenance. A Promise provides a state mechanism to manage different phases of asynchronous operations. There are three states for a Promise: pending (in progress), fulfilled (completed, also called resolved), and rejected (failed). After creation, a Promise is in the pending state and transitions to the fulfilled or rejected state upon completion of the asynchronous operation.

Promises offer **then** and **catch** methods to register callback functions for handling the success or failure of asynchronous operations. Changes in the Promise state trigger callbacks to be added to the microtask queue, awaiting execution. These callbacks rely on the event loop mechanism, which prioritizes microtasks after macro tasks have completed, ensuring asynchronous scheduling of callbacks.

The most basic usage involves instantiating a Promise object through its constructor, passing in a function (usually named **executor**) with two parameters. The two parameters are **resolve** and **reject**, which represent the callback functions for the success and failure of the asynchronous operation, respectively. For example, the code snippet below creates a Promise object and simulates an asynchronous operation:

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

In the above code, the **setTimeout** function simulates an asynchronous operation and generates a random number after 1 second. If the random number is greater than 0.5, the **resolve** callback is invoked with the random number; otherwise, the **reject** callback is invoked with an error object.

After a Promise object is created, you can use the **then** and **catch** methods to specify callback functions for the fulfilled and rejected states. The **then** method can accept two parameters: one for handling the fulfilled state and the other for handling the rejected state. If only one parameter is passed in, the **then** method automatically calls the callback function when the Promise object state changes to **fulfilled**, with the result of the Promise object passed as a parameter. The **catch** method receives a callback function to handle failures, that is, capturing the Promise's transition to the rejected state or any exceptions thrown during the operation. The code snippet below shows the use of the **then** and **catch** methods.

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Use the then method to define success and failure callbacks.
promise.then((result: number) => {
  console.info(`The number for success is ${result}`); // Executed on success.
}, (error: BusinessError) => {
  console.error(error.message); // Executed on failure.
}
);

// Use the then method to define a success callback and the catch method to define a failure callback.
promise.then((result: number) => {
  console.info(`Random number is ${result}`); // Executed on success.
}).catch((error: BusinessError) => {
  console.error(error.message); // Executed on failure.
});
```
<!-- @[promise_then_catch_handling](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTs/ArkTsConcurrent/AsyncConcurrencyOverview/entry/src/main/ets/pages/Index.ets) -->

In this example, the callback function of the **then** method receives the successful result of the Promise object as a parameter and outputs it to the console. If the Promise object enters the rejected state, the callback function of the **catch** method receives the error object as a parameter and outputs it to the console.

> **NOTE**
>
> When a Promise object is rejected and not handled by the **catch** method, it triggers the **unhandledRejection** event. You can use the [errorManager.on('unhandledrejection')](../reference/apis-ability-kit/js-apis-app-ability-errorManager.md#errormanageroffunhandledrejection12) interface to listen for this event and globally capture unhandled Promise rejects.

## Async/Await

Async/Await is syntactic sugar for handling asynchronous operations with Promises, making it easier and more readable to write asynchronous code. By declaring a function as asynchronous with the **async** keyword and using the **await** keyword to wait for the resolution of a Promise (fulfilled or rejected), you can write asynchronous operations in a synchronous style.

An **async** function implements asynchronous operations by returning a Promise object. It can contain zero or more **await** keywords, pausing execution until the associated Promise completes its state transition (fulfilled/rejected). If an exception is thrown during function execution, the exception directly triggers the returned Promise to enter the rejected state, and the error object can be captured using the **.catch()** method or the second callback parameter of **then**.

The code snippet below uses async/await to simulate an asynchronous operation that returns a string after 3 seconds.

```ts
async function myAsyncFunction(): Promise<string> {
  const result: string = await new Promise((resolve: Function) => {
    setTimeout(() => {
      resolve('Hello, world!');
    }, 3000);
  });
  console.info(result); // Output: Hello, world!
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

In this code, the await keyword is used to wait for the resolution of the Promise object and store its resolved value in the **result** variable.

Note that when waiting for asynchronous operations, the entire operation should be wrapped in an **async** function and used with **await**. You can also use **try/catch** blocks to catch exceptions in asynchronous operations.

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

<!--no_check-->