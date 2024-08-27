# Asynchronous Concurrency Overview (Promise and Async/Await)


Promise and async/await are standard JavaScript syntax that provides asynchronous concurrency. Asynchronous code ensures that actions initiated now finish later. It allows the execution of only one segment of code at a time and is therefore applicable to the development of a [single I/O task](single-io-development.md), for example, a network request or a file read/write operation.


Promise and async/await allow an application to perform other operations without waiting for the completion of certain actions.


## Promise

Promise is an object used to process asynchronous operations. It converts asynchronous operations into a style similar to synchronous operations for easier code writing and maintenance. Promise provides a state mechanism to manage different phases of asynchronous operations. It also provides methods to register callback functions to handle the success or failure of these operations.

Promise has three states: pending, fulfilled, and rejected. A Promise object is in the pending state after being created and changes to the fulfilled or rejected state when the asynchronous operation is complete.

The most common usage for Promise is to instantiate a Promise object through a constructor and pass in a function (usually named **executor**) with two parameters. The two parameters are **resolve** and **reject**, which represent the callback functions that should be called when the asynchronous operation succeeds and fails, respectively. The code snippet below creates a Promise object and simulates an asynchronous operation:


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

In the preceding code, the **setTimeout** function simulates an asynchronous operation that generates a random number one second later. If the random number is greater than 0.5, the **resolve** callback function is executed and the random number is passed in as a parameter. Otherwise, the **reject** callback function is executed and an error object is passed in.

After the Promise object is created, you can use the **then** and **catch** methods to register the callback functions for the fulfilled and rejected states. The **then** method can receive two parameters: one for processing the fulfilled state and the other for processing the rejected state. If only one parameter is passed in, the **then** method automatically calls the callback function when the Promise state changes to **fulfilled** and passes in the result of the Promise object in the callback function. The **catch** method receives a callback function to process the failure result, that is, capture the exception thrown when the Promise state changes to **rejected** or the operation fails. The code snippet below shows the use of the **then** and **catch** methods:


```ts
import { BusinessError } from '@kit.BasicServicesKit';

promise.then((result: number) => {
 console.info(`Random number is ${result}`);
}).catch((error: BusinessError) => {
 console.error(error.message);
});
```

In the preceding code, the callback function of the **then** method receives the success result of the Promise object as a parameter and outputs it to the console. If the Promise object enters the rejected state, the callback function of the **catch** method receives the error object as a parameter and outputs it to the console.


## Async/Await

Async/Await is a Promise syntax sugar used to process asynchronous operations, making it easier to read and write asynchronous code. The async keyword is used to declare an asynchronous function, and the await keyword is used to wait for Promise parsing (fulfilled or rejected). In this way, the asynchronous operation logic is coded as a synchronous operation.

The **async** function returns a Promise object to represent an asynchronous operation. Inside the **async** function, you can use the await keyword to wait for the parsing of the Promise object and return its parsed value. If an **async** function throws an exception, the Promise object returned by the function is rejected, and the exception information is passed in to the **onRejected()** method of the Promise object.

The code snippet below uses async/await to simulate the scenario where a synchronous API is called to execute an asynchronous operation that returns a string three seconds later.


```ts
async function myAsyncFunction(): Promise<string> {
  const result: string = await new Promise((resolve: Function) => {
    setTimeout(() => {
      resolve('Hello, world!');
    }, 3000);
  });
  console.info(result); // Output: Hello, world!
  return result
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

In the preceding code, the await keyword is used to wait for the parsing of the Promise object and store its parsed value in the **result** variable.

Note that the entire operation must be packed in the **async** function because the code needs to wait for the asynchronous operation to complete. In addition to **await**, you can use the try/catch block to capture exceptions in asynchronous operations.


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
