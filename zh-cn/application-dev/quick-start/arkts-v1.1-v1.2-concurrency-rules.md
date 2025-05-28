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
eaw.run<void>(() => {
    console.info("hello, eaworker!");
});

eaw.join();
```

## 共享模块不需要use shared修饰

**规则：** arkts-limited-stdlib-no-use-shared

**级别：** error

新增对象天然共享特性，无需添加use shared。

**ArkTS1.1**
```typescript
"use shared"
export function test() {}
```

**ArkTS1.2**
```typescript
export function test() {}
```

## 共享函数不需要use concurrent修饰

**规则：** arkts-limited-stdlib-no-use-concurrent

**级别：** error

新增对象天然共享特性，无需添加use concurrent。

**ArkTS1.1**
```typescript
function func() {
"use concurrent" 
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

新增对象天然共享特性，不再依赖Sendable特性，ASON可直接更改为JSON，且删除ArkTSUtils.前缀。

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
let arr = new Array(1, 2, 3);
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
let pres = pro.getUidForName("tool");
```

**ArkTS1.2**
```typescript
let result = StdProcess.is64Bit();
let pro = new StdProcess.ProcessManager();
let pres = pro.getUidForName("tool");
```

## 移除taskpool setCloneList接口

**规则：** arkts-limited-stdlib-no-setCloneList

**级别：** error

内存默认共享，不需要提供setCloneList来拷贝传递对象。

**ArkTS1.1**
```typescript
let baseInstance1: BaseClass = new BaseClass();
let array1 = new Array<BaseClass>();
array1.push(baseInstance1);
let task1 = new taskpool.Task(testFunc, array1, 10);
task1.setCloneList(array1);
```

**ArkTS1.2**
```typescript
let baseInstance1: BaseClass = new BaseClass();
let array1 = new Array<BaseClass>();
array1.push(baseInstance1);
let task1 = new taskpool.Task(testFunc, array1, 10);
```

## 移除taskpool setTransferList接口

**规则：** arkts-limited-stdlib-no-setTransferList

**级别：** error

内存默认共享，不需要提供setTransferList来跨线程传递ArrayBuffer对象。

**ArkTS1.1**
```typescript
let buffer: ArrayBuffer = new ArrayBuffer(8);
let view: Uint8Array = new Uint8Array(buffer);
let buffer1: ArrayBuffer = new ArrayBuffer(16);
let view1: Uint8Array = new Uint8Array(buffer1);
let task: taskpool.Task = new taskpool.Task(testTransfer, view, view1);
task.setTransferList([view.buffer, view1.buffer]);
```

**ArkTS1.2**
```typescript
let buffer: ArrayBuffer = new ArrayBuffer(8);
let view: Uint8Array = new Uint8Array(buffer);
let buffer1: ArrayBuffer = new ArrayBuffer(16);
let view1: Uint8Array = new Uint8Array(buffer1);
let task: taskpool.Task = new taskpool.Task(testTransfer, view, view1);
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
  console.info("sendableFunc")
}

if (ArkTSUtils.isSendable(sendableFunc)) {
  console.info("sendableFunc is Sendable");
} else {
  console.info("sendableFunc is not Sendable");
}
```

**ArkTS1.2**
内存共享，不需要判断是否为Sendable对象。