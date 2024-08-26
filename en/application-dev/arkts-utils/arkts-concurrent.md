# \@Concurrent Decorator: Declaring and Verifying Concurrent Functions

To pass function verification, the concurrent functions executed in a [TaskPool](../reference/apis-arkts/js-apis-taskpool.md) must be decorated using \@Concurrent.


> **NOTE**
>
> Since API version 9, the @Concurrent decorator can be used to declare and verify concurrent functions.


## Decorator Description
| \@Concurrent Decorator| Description                                                                                      |
| --------------------- | ------------------------------------------------------------------------------------------ |
| Decorator parameters            | None.                                                                                      |
| Application scenarios              | This decorator can be used only in projects of the stage model. It can be used only in .ets files.                                       |
| Decorated function types        | This decorator can be used for asynchronous functions and common functions. It cannot be used for generators, arrow functions, or methods. It does not support class member functions or anonymous functions. |
| Variable types in decorated functions | Local variables, input parameters, and variables imported through **import** are supported. Closure variables are not allowed.                              |
| Return value types in decorated functions | For details about the supported return value types, see [Serialization Types Supported by TaskPool and Worker](serialization-support-types.md).   |

> **NOTE**
>
> Pay attention to the performance of returning Promise in the concurrent function. The concurrent synchronous function processes and returns Promise with the result.

**Example**

```ts
import { taskpool } from '@kit.ArkTS';

@Concurrent
function testPromise(args1: number, args2: number): Promise<number> {
  return new Promise<number>((testFuncA, testFuncB)=>{
    testFuncA(args1 + args2);
  });
}

@Concurrent
async function testPromise1(args1: number, args2: number): Promise<number> {
  return new Promise<number>((testFuncA, testFuncB)=>{
    testFuncA(args1 + args2);
  });
}

@Concurrent
async function testPromise2(args1: number, args2: number): Promise<number> {
  return await new Promise<number>((testFuncA, testFuncB)=>{
    testFuncA(args1 + args2)
  });
}

@Concurrent
function testPromise3() {
  return Promise.resolve(1);
}

@Concurrent
async function testPromise4(): Promise<number> {
  return 1;
}

@Concurrent
async function testPromise5(): Promise<string> {
  return await new Promise((resolve) => {
    setTimeout(()=>{
      resolve("Promise setTimeout after resolve");
    }, 1000)
  });
}

async function testConcurrentFunc() {
  let task1: taskpool.Task = new taskpool.Task(testPromise, 1, 2);
  let task2: taskpool.Task = new taskpool.Task(testPromise1, 1, 2);
  let task3: taskpool.Task = new taskpool.Task(testPromise2, 1, 2);
  let task4: taskpool.Task = new taskpool.Task(testPromise3);
  let task5: taskpool.Task = new taskpool.Task(testPromise4);
  let task6: taskpool.Task = new taskpool.Task(testPromise5);

  taskpool.execute(task1).then((d:object)=>{
    console.info("task1 res is: " + d)
  }).catch((e:object)=>{
    console.info("task1 catch e: " + e)
  })
  taskpool.execute(task2).then((d:object)=>{
    console.info("task2 res is: " + d)
  }).catch((e:object)=>{
    console.info("task2 catch e: " + e)
  })
  taskpool.execute(task3).then((d:object)=>{
    console.info("task3 res is: " + d)
  }).catch((e:object)=>{
    console.info("task3 catch e: " + e)
  })
  taskpool.execute(task4).then((d:object)=>{
    console.info("task4 res is: " + d)
  }).catch((e:object)=>{
    console.info("task4 catch e: " + e)
  })
  taskpool.execute(task5).then((d:object)=>{
    console.info("task5 res is: " + d)
  }).catch((e:object)=>{
    console.info("task5 catch e: " + e)
  })
  taskpool.execute(task6).then((d:object)=>{
    console.info("task6 res is: " + d)
  }).catch((e:object)=>{
    console.info("task6 catch e: " + e)
  })
}

testConcurrentFunc();
```

The output is as follows:
```
task1 res is: 3
task2 catch e: Error: Can't return Promise in pending state
task3 res is: 3
task4 res is: 1
task5 res is: 1
task6 res is: Promise setTimeout after resolve
```

> **NOTE**
>
> If Promise is used in the concurrent asynchronous function, you are advised to use await to capture exceptions that may occur in Promise. A recommended example is provided below.

**Example**

```ts
@Concurrent
async function testPromiseError() {
  await new Promise<number>((resolve, reject) => {
    resolve(1);
  }).then(()=>{
    throw new Error("testPromise Error");
  })
}

@Concurrent
async function testPromiseError1() {
  await new Promise<string>((resolve, reject) => {
    reject("testPromiseError1 Error msg");
  })
}

@Concurrent
function testPromiseError2() {
  return new Promise<string>((resolve, reject) => {
    reject("testPromiseError2 Error msg");
  })
}

async function testConcurrentFunc() {
  let task1: taskpool.Task = new taskpool.Task(testPromiseError);
  let task2: taskpool.Task = new taskpool.Task(testPromiseError1);
  let task3: taskpool.Task = new taskpool.Task(testPromiseError2);

  taskpool.execute(task1).then((d:object)=>{
    console.info("task1 res is: " + d)
  }).catch((e:object)=>{
    console.info("task1 catch e: " + e)
  })
  taskpool.execute(task2).then((d:object)=>{
    console.info("task2 res is: " + d)
  }).catch((e:object)=>{
    console.info("task2 catch e: " + e)
  })
  taskpool.execute(task3).then((d:object)=>{
    console.info("task3 res is: " + d)
  }).catch((e:object)=>{
    console.info("task3 catch e: " + e)
  })
}

testConcurrentFunc()
```

The output is as follows:
```
task1 catch e: Error: testPromise Error
task2 catch e: testPromiseError1 Error msg
task3 catch e: testPromiseError2 Error msg
```


## Example
  ```ts
  import { taskpool } from '@kit.ArkTS';
  
  @Concurrent
  function add(num1: number, num2: number): number {
    return num1 + num2;
  }
  
  async function ConcurrentFunc(): Promise<void> {
    try {
      let task: taskpool.Task = new taskpool.Task(add, 1, 2);
      console.info("taskpool res is: " + await taskpool.execute(task));
    } catch (e) {
      console.error("taskpool execute error is: " + e);
    }
  }
  
  @Entry
  @Component
  struct Index {
    @State message: string = 'Hello World'
  
    build() {
      Row() {
        Column() {
          Text(this.message)
            .fontSize(50)
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
              ConcurrentFunc();
            })
        }
        .width('100%')
      }
      .height('100%')
    }
  }
  ```
