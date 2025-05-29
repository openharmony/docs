# Asynchronous Concurrency (Promise and Async/Await)


Promise and async/await are standard JavaScript asynchronous syntax that provides asynchronous concurrency capabilities. Asynchronous code can be suspended and resumed later, ensuring that only one piece of code is executed at any given moment. This approach is suitable for single I/O tasks, such as a single network request or file read/write operation, without the need to start additional threads.

Asynchronous syntax is a feature of programming languages that allows programs to continue executing other operations without waiting for certain operations to complete.

## Promise

A Promise is an object used to process asynchronous operations. It converts asynchronous operations into a style similar to synchronous operations for easier code writing and maintenance. Promises provide a state mechanism to manage different phases of asynchronous operations. It also provides methods to register callback functions to handle the success or failure of these operations.

Promises have three states: pending, fulfilled, and rejected. A Promise object starts in the pending state and transitions to either fulfilled or rejected upon completion of the asynchronous operation.

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

In this code, the **setTimeout** function simulates an asynchronous operation that generates a random number one second later. If the random number is greater than 0.5, the **resolve** callback function is executed, with the random number passed as a parameter. Otherwise, the **reject** callback function is executed, with an error object passed as a parameter.

After a Promise object is created, you can use the **then** and **catch** methods to specify callback functions for the fulfilled and rejected states. The **then** method can accept two parameters: one for handling the fulfilled state and the other for handling the rejected state. If only one parameter is passed in, the **then** method automatically calls the callback function when the Promise object state changes to **fulfilled**, with the result of the Promise object passed as a parameter. The **catch** method receives a callback function to handle failures, that is, capturing the Promise's transition to the rejected state or any exceptions thrown during the operation. The code snippet below shows the use of the **then** and **catch** methods.

```ts
import { BusinessError } from '@kit.BasicServicesKit';

promise.then((result: number) => {
 console.info(`Random number is ${result}`);
}).catch((error: BusinessError) => {
 console.error(error.message);
});
```

In this example, the callback function of the **then** method receives the successful result of the Promise object as a parameter and outputs it to the console. If the Promise object enters the rejected state, the callback function of the **catch** method receives the error object as a parameter and outputs it to the console.

> **NOTE**
>
> When a Promise object is rejected and not handled by the **catch** method, it triggers the **unhandledRejection** event. You can use the [errorManager.on('error')](../reference/apis-ability-kit/js-apis-app-ability-errorManager.md#errormanageronerror) interface to listen for this event and globally capture unhandled Promise rejects.

## Async/Await

Async/Await is syntactic sugar for handling asynchronous operations with Promises, making it easier and more readable to write asynchronous code. By declaring a function as asynchronous with the async keyword and using the await keyword to wait for the resolution of a Promise (fulfilled or rejected), you can write asynchronous operations in a synchronous style.

An async function returns a Promise object to represent an asynchronous operation. Inside the async function, you can use the await keyword to wait for the resolution of the Promise object and return its resolved value. If an async function throws an exception, the Promise object returned by the function is rejected, and the exception information is passed to the **onRejected()** method of the Promise object.

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
            console.info("res is: " + res);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

In this code, the await keyword is used to wait for the resolution of the Promise object and store its resolved value in the **result** variable.

Since you need to wait for the completion of the asynchronous operation, the entire operation must be wrapped in an async function and used with the await keyword. In addition to using await within async functions, you can also use try/catch blocks to catch exceptions in asynchronous operations.

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
