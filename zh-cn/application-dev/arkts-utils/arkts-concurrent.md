# \@Concurrent装饰器：声明并校验并发函数

在使用[TaskPool](../reference/apis-arkts/js-apis-taskpool.md)时，执行的并发函数需要使用该装饰器修饰，否则无法通过相关校验。


> **说明：**
>
> 从API version 9开始，支持使用@Concurrent装饰器声明并校验并发函数。


## 装饰器说明
| \@Concurrent并发装饰器 | 说明                                                                                       |
| --------------------- | ------------------------------------------------------------------------------------------ |
| 装饰器参数             | 无。                                                                                       |
| 使用场景               | 仅支持在Stage模型的工程中使用。仅支持在.ets文件中使用。                                        |
| 装饰的函数类型         | 允许标注async函数或普通函数。禁止标注generator、箭头函数、method。不支持类成员函数或者匿名函数。  |
| 装饰的函数内的变量类型  | 允许使用local变量、入参和通过import引入的变量。禁止使用闭包变量。                               |
| 装饰的函数内的返回值类型  | 支持的类型请查[序列化支持类型](serialization-support-types.md)。    |


## 装饰器使用示例

### 并发函数一般使用

并发函数为一个计算两数之和的普通函数，taskpool执行该函数并返回结果。

**示例：**

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


### 并发函数返回Promise

并发函数中返回Promise的表现需关注，其中并发同步函数会处理返回该Promise并返回结果，如下例所示。

**示例：**

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

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        Button(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            testConcurrentFunc();
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

输出结果如下所示：
```
task1 res is: 3
task2 catch e: Error: Can't return Promise in pending state
task3 res is: 3
task4 res is: 1
task5 res is: 1
task6 res is: Promise setTimeout after resolve
```


### 并发函数中使用自定义类或函数

并发函数中使用自定义类或函数时需定义在不同文件，否则会被认为是闭包，如下例所示。

**示例：**

```ts
// Index.ets
import { taskpool } from '@kit.ArkTS';
import { BusinessError } from '@kit.BasicServicesKit';
import { testAdd, MyTestA, MyTestB } from './Test';

function add(arg: number) {
  return ++arg;
}

class TestA {
  constructor(name: string) {
    this.name = name;
  }
  name: string = 'ClassA';
}

class TestB {
  static nameStr: string = 'ClassB';
}

@Concurrent
function TestFunc() {
  // case1：在并发函数中直接调用同文件内定义的类或函数

  // 直接调用同文件定义的函数add()，add飘红报错：Only imported variables and local variables can be used in @Concurrent decorated functions. <ArkTSCheck>
  // add(1);
  // 直接使用同文件定义的TestA构造，TestA飘红报错：Only imported variables and local variables can be used in @Concurrent decorated functions. <ArkTSCheck>
  // let a = new TestA("aaa");
  // 直接访问同文件定义的TestB的成员nameStr，TestB飘红报错：Only imported variables and local variables can be used in @Concurrent decorated functions. <ArkTSCheck>
  // console.info("TestB name is: " + TestB.nameStr);

  // case2：在并发函数中调用定义在Test.ets文件并导入当前文件的类或函数

  // 输出结果：res1 is: 2
  console.info("res1 is: " + testAdd(1));
  let tmpStr = new MyTestA("TEST A");
  // 输出结果：res2 is: TEST A
  console.info("res2 is: " + tmpStr.name);
  // 输出结果：res3 is: MyTestB
  console.info("res3 is: " + MyTestB.nameStr);
}


@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    RelativeContainer() {
      Text(this.message)
        .id('HelloWorld')
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .alignRules({
          center: { anchor: '__container__', align: VerticalAlign.Center },
          middle: { anchor: '__container__', align: HorizontalAlign.Center }
        })
        .onClick(() => {
          let task = new taskpool.Task(TestFunc);
          taskpool.execute(task).then(() => {
            console.info("taskpool: execute task success!");
          }).catch((e:BusinessError) => {
            console.error(`taskpool: execute: Code: ${e.code}, message: ${e.message}`);
          })
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

```ts
// Test.ets
export function testAdd(arg: number) {
  return ++arg;
}

@Sendable
export class MyTestA {
  constructor(name: string) {
    this.name = name;
  }
  name: string = 'MyTestA';
}

export class MyTestB {
  static nameStr:string = 'MyTestB';
}
```


### 并发异步函数中使用Promise

并发异步函数中如果使用Promise，建议搭配await使用捕获Promise中可能发生的异常。推荐使用示例如下。

**示例：**

```ts
import { taskpool } from '@kit.ArkTS'

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

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        Button(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            testConcurrentFunc();
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

输出结果如下所示：
```
task1 catch e: Error: testPromise Error
task2 catch e: testPromiseError1 Error msg
task3 catch e: testPromiseError2 Error msg
```