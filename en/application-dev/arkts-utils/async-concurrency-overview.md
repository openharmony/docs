# Asynchronous Concurrency Overview


Promise and async/await are standard JavaScript syntax that provides asynchronous concurrency. Asynchronous code ensures that actions initiated now finish later. It allows the execution of only one segment of code at a time and is therefore applicable to the development of a single I/O task, for example, a network request or a file read/write operation.


Promise and async/await allow an application to perform other operations without waiting for the completion of certain actions.


## Promise

Promise is an object used to process asynchronous operations. It converts asynchronous operations into a style similar to synchronous operations for easier code writing and maintenance. Promise provides a state mechanism to manage different phases of asynchronous operations. It also provides methods to register callback functions to handle the success or failure of these operations.

Promise has three states: pending, fulfilled, and rejected. After being created, a Promise object is in the pending state and changes to the fulfilled or rejected state when the asynchronous operation is complete.

The most common usage for Promise is to instantiate a Promise object through a constructor and pass in a function (usually named **executor**) with two parameters. The **executor** function receives two parameters: **resolve** and **reject**, which represent the callback functions that should be called when the asynchronous operation succeeds and fails, respectively. The code snippet below creates a Promise object and simulates an asynchronous operation:


```js
const promise = new Promise((resolve, reject) => {
  setTimeout(() => {
    const randomNumber = Math.random();
    if (randomNumber > 0.5) {
      resolve(randomNumber);
    } else {
      reject(new Error('Random number is too small'));
    }
  }, 1000);
});
```

In the preceding code, the **setTimeout** function simulates an asynchronous operation that randomly generates a number one second later. If the random number is greater than 0.5, the **resolve** callback function is executed and the generated random number is passed in as a parameter. Otherwise, the **reject** callback function is executed and an error object is passed in as a parameter.

After the Promise object is created, you can use the **then** and **catch** methods to register the callback functions for the fulfilled and rejected states. The **then** method can receive two parameters: one for processing the fulfilled state and the other for processing the rejected state. If only one parameter is passed in, the callback function is executed as long as the state changes. The **catch** method receives a callback function to process the failure result, that is, capture the exception thrown when the Promise state changes to **rejected** or the operation fails. The code snippet below shows the use of **then** and **catch** methods:


```js
promise.then(result => {
  console.info(`Random number is ${result}`);
}).catch(error => {
  console.error(error.message);
});
```

In the preceding code, the callback function of the **then** method receives the success result of the Promise object as a parameter and outputs it to the console. If the Promise object enters the rejected state, the callback function of the **catch** method receives the error object as a parameter and outputs it to the console.


## Async/Await

Async/Await is a Promise syntax sugar used to process asynchronous operations, making it easier to read and write asynchronous code. The async keyword is used to declare an asynchronous function, and the await keyword is used to wait for Promise parsing (fulfilled or rejected). In this way, the asynchronous operation logic is coded as a synchronous operation.

The **async** function returns a Promise object to represent an asynchronous operation. Inside the **async** function, you can use the await keyword to wait for the parsing of the Promise object and return its parsed value. If an **async** function throws an exception, the Promise object returned by the function is rejected, and the exception information is passed to the **onRejected()** method of the Promise object.

The code snippet below uses async/await to simulate an asynchronous operation that returns a string three seconds later.


```js
async function myAsyncFunction() {
  const result = await new Promise((resolve) => {
    setTimeout(() => {
      resolve('Hello, world!');
    }, 3000);
  });
  console.info(String(result)); // Output: Hello, world!
}

myAsyncFunction();
```

In the preceding code, the await keyword is used to wait for the parsing of the Promise object and store its parsed value in the **result** variable.

Note that the entire operation must be packaged in the **async** function because the code needs to wait for the asynchronous operation to complete. In addition to **await**, you can use the try/catch block to capture exceptions in asynchronous operations.


```js
async function myAsyncFunction() {
  try {
    const result = await new Promise((resolve) => {
      resolve('Hello, world!');
    });
  } catch (e) {
    console.error(`Get exception: ${e}`);
  }
}

myAsyncFunction();
```
