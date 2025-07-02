# ArkTS1.2并发特性变更

本指南旨在讲述ArkTS新的并发特性和使用方法。

## 共享对象不添加装饰器@Sendable

**规则：** arkts-limited-stdlib-no-sendable-decorator

**级别：** error

新增对象天然共享特性，不再依赖Sendable特性，无需添加@Sendable装饰器。

**ArkTS1.1**
```typescript
@Sendable
class A {}
```

**ArkTS1.2**
```typescript
class A {}
```

## 共享函数不添加装饰器@Concurrent

**规则：** arkts-limited-stdlib-no-concurrent-decorator

**级别：** error

新增对象天然共享特性，不再依赖Concurrent特性，无需添加@Concurrent装饰器。

**ArkTS1.1**
```typescript
@Concurrent
function func() {}
```

**ArkTS1.2**
```typescript
function func() {}
```

## 不支持Worker

**规则：** arkts-no-need-stdlib-worker

**级别：** error

内存天然共享，不需要基于Actor模型实现ThreadWorker。使用ArkTS1.2提供的新线程api-EAWorker。

**ArkTS1.1**
```typescript
import { worker } from '@kit.ArkTS';

const workerInstance: worker.ThreadWorker = new worker.ThreadWorker('entry/ets/workers/Worker.ets')
```

**ArkTS1.2**
```typescript
let eaw = new EAWorker();
eaw.run<void>(():void => {
    console.info('hello, eaworker!');
});

eaw.join();
```

## 共享模块不需要use shared修饰

**规则：** arkts-limited-stdlib-no-use-shared

**级别：** error

新增对象天然共享特性，无需添加use shared。

**ArkTS1.1**
```typescript
// test.ets
export let num = 1;
// shared.ets
'use shared'
export {num} from './test';
```

**ArkTS1.2**
```typescript
export let num = 1;
```

## 共享函数不需要use concurrent修饰

**规则：** arkts-limited-stdlib-no-use-concurrent

**级别：** error

新增对象天然共享特性，无需添加use concurrent。

**ArkTS1.1**
```typescript
function func() {
'use concurrent' 
}
```

**ArkTS1.2**
```typescript
function func() {}
```

## 原生容器默认共享，不需要Sendable容器

**规则：** arkts-no-need-stdlib-sendable-containers

**级别：** error

新增对象天然共享特性，不再依赖Sendable特性。可直接使用ArkTS1.2原生容器，删除collections.前缀。

**ArkTS1.1**
```typescript
import { collections } from '@kit.ArkTS';

let array = new collections.Array<number>();
```

**ArkTS1.2**
```typescript
let array = new Array<number>();
```

## 内存默认共享，不提供ASON

**规则：** arkts-no-need-stdlib-ason

**级别：** error

新增对象天然共享特性，不再依赖Sendable特性，ASON.stringify()方法调用可直接更改为JSON.stringify()，且删除ArkTSUtils.前缀。

**ArkTS1.1**
```typescript
import { collections } from '@kit.ArkTS';
import { ArkTSUtils } from '@kit.ArkTS';
let arr = new collections.Array(1, 2, 3);
let str = ArkTSUtils.ASON.stringify(arr);
console.info(str);
```

**ArkTS1.2**
```typescript
let arr = new Array<number>(1, 2, 3);
let str = JSON.stringify(arr);
console.info(str);
```

## 内存默认共享，不提供SharedArrayBuffer

**规则：** arkts-no-need-stdlib-sharedArrayBuffer

**级别：** error

新增对象天然共享特性，ArrayBuffer默认共享，不需要SharedArrayBuffer。

**ArkTS1.1**
```typescript
let sab: SharedArrayBuffer = new SharedArrayBuffer(20);
let int32 = new Int32Array(sab);
```

**ArkTS1.2**
```typescript
let sab: ArrayBuffer = new ArrayBuffer(20);
let int32 = new Int32Array(sab);
```

## 不提供isConcurrent接口

**规则：** arkts-limited-stdlib-no-support-isConcurrent

**级别：** error

新增对象天然共享特性，所有函数都是共享的，不需要提供isConcurrent。

**ArkTS1.1**
```typescript
import { taskpool } from '@kit.ArkTS';
@Concurrent
function test() {}
let result: Boolean = taskpool.isConcurrent(test);
```

**ArkTS1.2**
不支持isConcurrent接口。

## taskpool不需要import

**规则：** arkts-limited-stdlib-no-import-concurrency

**级别：** error

taskpool实现基于ArkTS提供，不依赖其他模块，不再需要import。

**ArkTS1.1**
```typescript
import { taskpool } from '@kit.ArkTS';

@Concurrent
function test() {}

taskpool.execute(test);
```

**ArkTS1.2**
```typescript
function test() {}

taskpool.execute(test);
```

## AsyncLock不需要import

**规则：** arkts-limited-stdlib-no-import-concurrency

**级别：** error

AsyncLock实现基于ArkTS提供，不依赖其他模块，不再需要import，且不需要添加ArkTSUtils.locks.前缀。

**ArkTS1.1**
```typescript
import { ArkTSUtils } from '@kit.ArkTS'

let lock: ArkTSUtils.locks.AsyncLock = new ArkTSUtils.locks.AsyncLock();
```

**ArkTS1.2**
```typescript
let lock: AsyncLock = new AsyncLock();
```

## process更名为StdProcess，且不需要import

**规则：** arkts-change-process-to-StdProcess

**级别：** error

StdProcess实现基于ArkTS提供，不依赖其他模块，不再需要import。为避免占用process关键字，更名为StdProcess。

**ArkTS1.1**
```typescript
import { process } from '@kit.ArkTS';

let result = process.is64Bit();
let pro = new process.ProcessManager();
let pres = pro.getUidForName('tool');
```

**ArkTS1.2**
```typescript
let result = StdProcess.is64Bit();
let pro = new StdProcess.ProcessManager();
let pres = pro.getUidForName('tool');
```

## 移除taskpool setCloneList接口

**规则：** arkts-limited-stdlib-no-setCloneList

**级别：** error

内存默认共享，不需要提供setCloneList来拷贝传递对象。

**ArkTS1.1**
```typescript
import { taskpool } from '@kit.ArkTS';

@Sendable
class BaseClass {
  public str: string = 'sendable: BaseClass';
}

@Concurrent
function testFunc(array: Array<BaseClass>) {
  let baseInstance = array[0];
  console.info('sendable: str1 is: ' + baseInstance.str);
  return baseInstance.str;
}

let baseInstance: BaseClass = new BaseClass();
let array = new Array<BaseClass>();
array.push(baseInstance);
let task = new taskpool.Task(testFunc, array);
task.setCloneList(array);
taskpool.execute(task).then((res: Object):void => {
  console.info('sendable: task res is: ' + res)
});
```

**ArkTS1.2**
```typescript
class BaseClass {
  public str: string = 'BaseClass';
}

function testFunc(array: Array<BaseClass>) {
  let baseInstance = array[0];
  console.info('str1 is: ' + baseInstance.str);
  return baseInstance.str;
}


let baseInstance: BaseClass = new BaseClass();
let array = new Array<BaseClass>();
array.push(baseInstance);
let task = new taskpool.Task(testFunc, array);
taskpool.execute(task).then((res: NullishType):void => {
  console.info('task res is: ' + res)
});
```

## 移除taskpool setTransferList接口

**规则：** arkts-limited-stdlib-no-setTransferList

**级别：** error

内存默认共享，不需要提供setTransferList来跨线程传递ArrayBuffer对象。

**ArkTS1.1**
```typescript
import { taskpool } from '@kit.ArkTS';

@Concurrent
function testTransfer(arg1: ArrayBuffer, arg2: ArrayBuffer): number {
  console.info('testTransfer arg1 byteLength: ' + arg1.byteLength);
  console.info('testTransfer arg2 byteLength: ' + arg2.byteLength);
  return 100;
}

let buffer: ArrayBuffer = new ArrayBuffer(8);
let view: Uint8Array = new Uint8Array(buffer);
let buffer1: ArrayBuffer = new ArrayBuffer(16);
let view1: Uint8Array = new Uint8Array(buffer1);

console.info('testTransfer view byteLength: ' + view.byteLength);
console.info('testTransfer view1 byteLength: ' + view1.byteLength);
// 执行结果为：
// testTransfer view byteLength: 8
// testTransfer view1 byteLength: 16

let task: taskpool.Task = new taskpool.Task(testTransfer, view, view1);
task.setTransferList([view.buffer, view1.buffer]);
taskpool.execute(task).then((res: Object) => {
  console.info('test result: ' + res);
}).catch((e: string) => {
  console.error('test catch: ' + e);
})
console.info('testTransfer view2 byteLength: ' + view.byteLength);
console.info('testTransfer view3 byteLength: ' + view1.byteLength);
// 经过transfer转移之后值为0，执行结果为：
// testTransfer view2 byteLength: 0
// testTransfer view3 byteLength: 0
```

**ArkTS1.2**
```typescript
function testTransfer(arg1: Uint8Array, arg2: Uint8Array): number {
  console.info('testTransfer arg1 byteLength: ' + arg1.byteLength);
  console.info('testTransfer arg2 byteLength: ' + arg2.byteLength);
  return 100.0;
}

let buffer: ArrayBuffer = new ArrayBuffer(8);
let view: Uint8Array = new Uint8Array(buffer);
let buffer1: ArrayBuffer = new ArrayBuffer(16);
let view1: Uint8Array = new Uint8Array(buffer1);

let task: taskpool.Task = new taskpool.Task(testTransfer, view, view1);
taskpool.execute(task).then((res: NullishType):void => {
  console.info('test result: ' + res);
}).catch((e: Error): void => {
  console.error('test catch: ' + e);
})
// 内存共享，此处可直接访问view,view1的内容，不需要使用setTransferList
// 执行结果为：
// testTransfer arg1 byteLength: 8
// testTransfer arg2 byteLength: 16
```

## 删除ISendable接口

**规则：** arkts-no-need-stdlib-ISendable

**级别：** error

新增对象天然共享特性，无需实现ISendable接口。

**ArkTS1.1**
```typescript
import { lang } from '@kit.ArkTS';

@Sendable
class CustomData implements lang.ISendable {
    data1: number;
    data2: string;
    constructor(data1: number, data2: string) {
        this.data1 = data1;
        this.data2 = data2;
    }
}
```

**ArkTS1.2**
```typescript
class CustomData {
    data1: number;
    data2: string;
    constructor(data1: number, data2: string) {
        this.data1 = data1;
        this.data2 = data2;
    }
}
```

## 删除isSendable接口

**规则：** arkts-no-need-stdlib-isSendable

**级别：** error

新增对象天然共享特性，无需判断是否为Sendable数据类型。

**ArkTS1.1**
```typescript
import { ArkTSUtils } from '@kit.ArkTS'

@Sendable
function sendableFunc() {
  console.info('sendableFunc')
}

if (ArkTSUtils.isSendable(sendableFunc)) {
  console.info('sendableFunc is Sendable');
} else {
  console.info('sendableFunc is not Sendable');
}
```

**ArkTS1.2**
内存共享，不需要判断是否为Sendable对象，不再提供isSendable接口。

## taskpool.execute()返回类型由Promise\<Object>变更为Promise\<NullishType>

**规则：** arkts-taskpool-execute-generic-type-object-to-nullishtype

**级别：** error

ArkTS1.1中taskpool execute返回值声明为Promise\<Object>，但实际可以返回值为undefined的Promise。ArkTS1.2中undefined和Object为不同类型，相互之间无法进行类型转换。

**ArkTS1.1**
```typescript
import { taskpool } from '@kit.ArkTS';

// 场景一:
@Concurrent
function printLog(str: number): number {
  console.info("printLog called: " + str);
  return str;
}

async function test1() {
  let task = new taskpool.Task(printLog, 10.0);
  let a3: Object = await taskpool.execute(task);
}

// 场景二：
async function test2() {
  let task = new taskpool.Task(printLog, 10.0);
  let a3 = taskpool.execute(task);
  a3.then((res: Object) => {
    // ...
  })
}
```

**ArkTS1.2**
```typescript
// 场景一：
function printLog(str: number): number {
    console.info("printLog called: " + str);
    return str;
}
async function test1() {
    let task = new taskpool.Task(printLog, 10.0);
    let a3: Object = (await taskpool.execute(task)) as Object;

    // or let a3: NullishType = await taskpool.execute(task);
}

// 场景二：
async function test2() {
    let task = new taskpool.Task(printLog, 10.0);
    let a3 = taskpool.execute(task);
    a3.then((res: NullishType) => {
        console.info("d");
    })
}
```

## Promise的reject函数只能接受Error类型作为参数

**规则：** arkts-limited-stdlib-promise-reject-type-error

**级别：** error

ArkTS1.2中加强类型限制，有以下规格限制：

1. throw只能抛出Error及其子类。

2. await Promise对象时，如果该Promise被reject，需要抛出其被reject的原因。

3. Promise构造函数中的reject方法，和静态reject方法，需要使用Error及其子类作为入参。

**ArkTS1.1**
```typescript
let p = new Promise<string>((resolve, reject) => {
    reject("error")
});
Promise.reject("error");
```

**ArkTS1.2**
```typescript
let p = new Promise<string>((resolve, reject) => {
    reject(new Error("error"))
});
Promise.reject(new Error("error"));
```

## Promise的then和catch方法的onrejected回调参数类型只能标注为Error或其父类类型

**规则：** arkts-limited-stdlib-promise-onrejected-type-error

**级别：** error

ArkTS1.2中加强类型限制，且类型转换具有运行时语义。为了保证类型安全，规格中限制函数间赋值遵循逆变原则，子类型入参回调无法赋值给父类型入参回调。

**ArkTS1.1**
```typescript
import { BusinessError } from "@kit.BasicServicesKit";

let p = new Promise<string>((resolve, reject) => {
  reject(new Error("error"))
});
p.then(() => {}, (e: BusinessError) => {
  console.info(String(e))})
p.catch((e: BusinessError) => { console.info(String(e))})
```

**ArkTS1.2**
```typescript
import { BusinessError } from "@ohos.base";

let p = new Promise<string>((resolve, reject) => {
    reject(new BusinessError())
});
p.then(() => { }, (e: Error) => {
    let err = e as BusinessError;
    console.info(String(err));
})
p.catch((e: Error) => {
    let err = e as BusinessError;
    console.info(String(err));
})
```

## 不支持用户自定义声明PromiseFulfilledResult、PromiseRejectedResult、PromiseSettledResult 

**规则：** arkts-not-support-PromiseSettledResult-customization

**级别：** error

ArkTS1.2不支持用户自定义声明PromiseFulfilledResult、PromiseRejectedResult、PromiseSettledResult。

**ArkTS1.1**
```typescript
interface PromiseFulfilledResult<T> {
  status: "fulfilled";
  value: T;
}

interface PromiseRejectedResult {
  status: "rejected";
  reason: string;
}

type PromiseSettledResult\<T> = PromiseFulfilledResult\<T> | PromiseRejectedResult;
```

**ArkTS1.2**

删除用户自定义的PromiseFulfilledResult、PromiseRejectedResult、PromiseSettledResult。


## 不支持编译阶段根据PromiseSettledResult的status值确定其实际类型

**规则：** arkts-not-support-PromiseSettledResult-smartcast

**级别：** error

arkts1.2中不支持对类的成员变量进行智能转换（智能类型差异arkts-no-ts-like-smart-type）。

**智能转换：** 编译器会在某些场景下（如instanceof、null检查、上下文推导等）识别出对象的具体类型，自动将变量转换为相应类型，而无需手动转换。

**ArkTS1.1**
```typescript
let f1 = Promise.resolve<string>('fulfilled 1');
Promise.allSettled<string>([f1])
  .then((results: PromiseSettledResult<string>[]) => {
    results.forEach((result: PromiseSettledResult<string>) => {
      if (result.status === 'fulfilled') {
        console.log(`${result.value} `);
      } else {
        console.log(`${result.reason.message} `);
      }
    });
  })
```

**ArkTS1.2**
```typescript
let f1 = Promise.resolve<string>('fulfilled 1');
Promise.allSettled<string>([f1])
  .then((results: PromiseSettledResult<string>[]) => {
    results.forEach((result: PromiseSettledResult<string>) => {
      if (result.status === 'fulfilled') {
          let result1 = result as PromiseFulfilledResult<string>;
          console.log(result1.value);
            } else {
             let result1 = result as PromiseRejectedResult;
             console.log(result1.reason.message);
            }
      });
   })
```

## 不支持Promise\<Promise\<T>>的then方法调用 

**规则：** arkts-no-support-nested-promise

**级别：** error

静态类型导致回调运行时类型转换失败，回调无法执行。

**ArkTS1.1**
```typescript
let p = new Promise<Promise<number>>((res, rej) => { res(Promise.resolve(1.0)) });
p.then((res: Promise<number>) => { console.info(res+"") })
```

**ArkTS1.2**
```typescript
let p = new Promise<number>((res, rej) => { res(Promise.resolve(1.0))});
p.then((res: number) => { console.info(res)})
```

## Task的function属性改名为taskFunction

**规则：** arkts-change-taskpool-Task-to-taskFunction

**级别：** error

function在ArkTS1.2中为关键字，不能作为类属性（限定关键字(arkts-invalid-identifier)）。

**ArkTS1.1**
```typescript
import { taskpool } from '@kit.ArkTS';

function testString(str: string) {
  console.info(str);

}
let task: taskpool.Task = new taskpool.Task(testString, "hello");
let func = task.function;
```

**ArkTS1.2**
```typescript
let func1 = (str: string): string => {
    return str;
};
let task: taskpool.Task = new taskpool.Task(func1, "hello");
let func = task.taskFunction;
```

## taskpool不提供GenericsTask

**规则：** arkts-not-supprot-genericstask

**级别：** error

 1. arkts1.2中不支持以泛型数组的形式对回调参数类型进行校验。

 2. arkts1.2不支持将非可变参数类型回调赋值给可变参数函数。

**ArkTS1.1**
```typescript
import { taskpool } from '@kit.ArkTS';
@Concurrent
function testWithThreeParams(a: number, b: string, c: number): string {
  return b;
}
let task1: taskpool.Task = new taskpool.GenericsTask<[number, string, number], string>(testWithThreeParams, 100, "test", 100);
```

**ArkTS1.2**
```typescript
function testWithThreeParams(a: number, b: string, c: number): string {
  return b;
}
```

## 不支持在全局空间直接或间接调用async函数

**规则：** arkts-not-support-global-async-call

**级别：** error

根据ArkTS1.2规格，全局初始化阶段不可以调用异步函数，否则会导致初始化结果难以推导。

**ArkTS1.1**
```typescript
async  function asynctest() {}
asynctest();
function f1() { asynctest(); }
f1();
```

**ArkTS1.2**
```typescript
async  function asynctest() {}
function f1() { asynctest(); }
function main() {
    asynctest();
    f1();
}
```

## Promise\<void>构造器中只支持使用resolve(undefined)

**规则：** arkts-promise-with-void-type-need-undefined-as-resolve-arg

**级别：** error

ArkTS1.2中void不能作为变量类型声明；作为泛型时，在类实例化时会自动转换为undefined。
**ArkTS1.1**
```typescript
let p1 = new Promise<void>((resolve, reject) => {
    resolve();
})
let p2 = new Promise<void>((resolve, reject) => {
    setTimeout(resolve, 10);
})
```

**ArkTS1.2**
```typescript
let p1 = new Promise<void>((resolve, reject) => {
    resolve();
})
let p2 = new Promise<void>((resolve, reject) => {
    setTimeout(() => {resolve(undefined)}, 10);
})    
```