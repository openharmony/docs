# @ohos.taskpool    
任务池（taskpool）作用是为应用程序提供一个多线程的运行环境，降低整体资源的消耗、提高系统的整体性能，且您无需关心线程实例的生命周期。您可以使用任务池API创建后台任务（Task），并对所创建的任务进行如任务执行、任务取消的操作。理论上您可以使用任务池API创建数量不受限制的任务，但是出于内存因素不建议您这样做。此外，不建议您在任务中执行阻塞操作，特别是无限期阻塞操作，长时间的阻塞操作占据工作线程，可能会阻塞其他任务调度，影响您的应用性能。  
  
您所创建的同一优先级任务的执行顺序可以由您决定，任务真实执行的顺序与您调用任务池API提供的任务执行接口顺序一致。任务默认优先级是MEDIUM。  
  
当同一时间待执行的任务数量大于任务池工作线程数量，任务池会根据负载均衡机制进行扩容，增加工作线程数量，减少整体等待时长。同样，当执行的任务数量减少，工作线程数量大于执行任务数量，部分工作线程处于空闲状态，任务池会根据负载均衡机制进行缩容，减少工作线程数量。  
  
任务池API以数字形式返回错误码。有关各个错误码的更多信息，请参阅文档[语言基础类库错误码](../errorcodes/errorcode-utils.md)。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import taskpool from '@ohos.taskpool'    
```  
    
## Priority    
表示所创建任务（Task）的优先级。    
    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| HIGH | 0 | 任务为高优先级。 |  
| MEDIUM | 1 | 任务为中优先级。 |  
| LOW | 2 | 任务为低优先级。 |  
    
## Task    
表示任务。使用[constructor](#constructor)方法构造Task。  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| function | Function | false | true | 创建任务时需要传入的函数，支持的函数返回值类型请查[序列化支持类型](#序列化支持类型)。 |  
| arguments | unknown[] | false | false | 创建任务传入函数所需的参数，支持的参数类型请查[序列化支持类型](#序列化支持类型)。 |  
    
### isCanceled<sup>(10+)</sup>    
检查当前正在运行的任务是否已取消。使用该方法前需要先构造Task。  
 **调用形式：**     
- static isCanceled(): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果当前正在运行的任务被取消返回true，未被取消返回false。 |  
    
 **示例代码：**   
```ts    
@Concurrent  
function inspectStatus(arg: number): number {  
    // do something  
    if (taskpool.Task.isCanceled()) {  
      console.log("task has been canceled.");  
      // do something  
      return arg + 1;  
    }  
    // do something  
    return arg;  
}  
    
```    
  
    
### setTransferList<sup>(10+)</sup>    
设置任务的传输列表。使用该方法前需要先构造Task。  
 **调用形式：**     
- setTransferList(transfer?: ArrayBuffer[]): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| transfer | ArrayBuffer[] | false | 可传输对象是ArrayBuffer的实例对象，默认为空数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let buffer: ArrayBuffer = new ArrayBuffer(8);  
let view: Uint8Array = new Uint8Array(buffer);  
let buffer1: ArrayBuffer = new ArrayBuffer(16);  
let view1: Uint8Array = new Uint8Array(buffer1);  
  
console.info("testTransfer view byteLength: " + view.byteLength);  
console.info("testTransfer view1 byteLength: " + view1.byteLength);  
@Concurrent  
function testTransfer(arg1: ArrayBuffer, arg2: ArrayBuffer): number {  
  console.info("testTransfer arg1 byteLength: " + arg1.byteLength);  
  console.info("testTransfer arg2 byteLength: " + arg2.byteLength);  
  return 100;  
}  
let task: taskpool.Task = new taskpool.Task(testTransfer, view, view1);  
task.setTransferList([view.buffer, view1.buffer]);  
taskpool.execute(task).then((res: number)=>{  
  console.info("test result: " + res);  
}).catch((e: string)=>{  
  console.error("test catch: " + e);  
})  
console.info("testTransfer view byteLength: " + view.byteLength);  
console.info("testTransfer view1 byteLength: " + view1.byteLength);  
    
```    
  
    
## TaskGroup<sup>(10+)</sup>    
表示任务组。使用[constructor](#constructor10)方法构造TaskGroup。  
 **系统能力:**  SystemCapability.Utils.Lang    
### addTask<sup>(10+)</sup>    
将待执行的函数添加到任务组中。使用该方法前需要先构造TaskGroup。  
 **调用形式：**     
- addTask(func: Function, ...args: unknown[]): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| func | Function | true | 任务执行需要传入函数，支持的函数返回值类型请查[序列化支持类型](#序列化支持类型)。 |  
| args | unknown[] | true | 任务执行函数所需要的参数，支持的参数类型请查[序列化支持类型](#序列化支持类型)。默认值为undefined。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200014 | The function is not mark as concurrent. |  
    
 **示例代码：**   
```ts    
@Concurrent  
function printArgs(args: number): number {  
  console.log("printArgs: " + args);  
  return args;  
}  
  
let taskGroup: taskpool.TaskGroup = new taskpool.TaskGroup();  
taskGroup.addTask(printArgs, 100); // 100: test number  
    
```    
  
    
### addTask<sup>(10+)</sup>    
将创建好的任务添加到任务组中。使用该方法前需要先构造TaskGroup。  
 **调用形式：**     
- addTask(task: Task): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| task | Task | true | 需要添加到任务组中的任务。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200014 | The function is not mark as concurrent. |  
    
 **示例代码：**   
```ts    
@Concurrent  
function printArgs(args: number): number {  
  console.log("printArgs: " + args);  
  return args;  
}  
  
let taskGroup: taskpool.TaskGroup = new taskpool.TaskGroup();  
let task: taskpool.Task = new taskpool.Task(printArgs, 200); // 200: test number  
taskGroup.addTask(task);  
    
```    
  
    
## State<sup>(10+)</sup>    
表示任务（Task）状态的枚举。    
    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| WAITING | 1 | 任务正在等待。 |  
| RUNNING | 2 | 任务正在执行。 |  
| CANCELED | 3 | 任务已被取消。 |  
    
## TaskInfo<sup>(10+)</sup>    
任务的内部信息。  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| taskId<sup>(10+)</sup> | number | false | true | 任务的ID。  |  
| state<sup>(10+)</sup> | State | false | true | 任务的状态。 |  
| duration<sup>(10+)</sup> | number | false | false | 任务执行至当前所用的时间，单位为ms。当返回为0时，表示任务未执行；返回为空时，表示没有任务执行 |  
    
## ThreadInfo<sup>(10+)</sup>    
工作线程的内部信息。  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| tid<sup>(10+)</sup> | number | false | true | 工作线程的标识符。返回为空时，代表没有任务执行。 |  
| taskIds<sup>(10+)</sup> | number[] | false | false | 在当前线程上运行的任务id列表。返回为空时，代表没有任务执行。 |  
| priority<sup>(10+)</sup> | Priority | false | false | 当前线程的优先级。返回为空时，代表没有任务执行。 |  
    
## TaskPoolInfo<sup>(10+)</sup>    
任务池的内部信息。  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| threadInfos<sup>(10+)</sup> | ThreadInfo[] | false | true | 工作线程的内部信息。 |  
| taskInfos<sup>(10+)</sup> | TaskInfo[] | false | true | 任务的内部信息。 |  
    
## execute    
将创建好的任务放入taskpool内部任务队列等待，等待分发到工作线程执行。当前执行模式可尝试调用cancel进行任务取消。  
 **调用形式：**     
    
- execute(func: Function, ...args: unknown[]): Promise\<unknown>    
起始版本： 9    
- execute(task: Task, priority?: Priority): Promise\<unknown>    
起始版本： 9    
- execute(group: TaskGroup, priority?: Priority): Promise\<unknown[]>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| func | Function | true | 执行的逻辑需要传入函数，支持的函数返回值类型请查[序列化支持类型](#序列化支持类型)。 |  
| args | unknown[] | true | 执行逻辑的函数所需要的参数，支持的参数类型请查[序列化支持类型](#序列化支持类型)。默认值为undefined。 |  
| task | Task | true | 需要在任务池中执行的任务。 |  
| priority | Priority | false | 等待执行的任务的优先级，该参数默认值为taskpool.Priority.MEDIUM。 |  
| group<sup>(10+)</sup> | TaskGroup | true | 需要在任务池中执行的任务组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<unknown> | 返回Promise对象。 |  
| Promise<unknown[]> | execute是异步方法，返回Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200003 | Worker initialization failure. |  
| 10200006 | An exception occurred during serialization. |  
| 10200014 | The function is not mark as concurrent. |  
    
 **示例代码1：**   
execute(func: Function, ...args: unknown[]): Promise\<unknown>  
```ts    
@Concurrent  
function printArgs(args: number): number {  
    console.log("printArgs: " + args);  
    return args;  
}  
  
taskpool.execute(printArgs, 100).then((value: number) => { // 100: test number  
  console.log("taskpool result: " + value);  
});  
    
```    
  
    
 **示例代码2：**   
execute(task: Task, priority?: Priority): Promise\<unknown>  
```ts    
@Concurrent  
function printArgs(args: number): number {  
    console.log("printArgs: " + args);  
    return args;  
}  
  
let task: taskpool.Task = new taskpool.Task(printArgs, 100); // 100: test number  
taskpool.execute(task).then((value: number) => {  
  console.log("taskpool result: " + value);  
});  
    
```    
  
    
 **示例代码3：**   
execute(group: TaskGroup, priority?: Priority): Promise<unknown[]>  
```ts    
@Concurrent  
function printArgs(args: number): number {  
    console.log("printArgs: " + args);  
    return args;  
}  
  
let taskGroup1: taskpool.TaskGroup = new taskpool.TaskGroup();  
taskGroup1.addTask(printArgs, 10); // 10: test number  
taskGroup1.addTask(printArgs, 20); // 20: test number  
taskGroup1.addTask(printArgs, 30); // 30: test number  
  
let taskGroup2: taskpool.TaskGroup = new taskpool.TaskGroup();  
let task1: taskpool.Task = new taskpool.Task(printArgs, 100); // 100: test number  
let task2: taskpool.Task = new taskpool.Task(printArgs, 200); // 200: test number  
let task3: taskpool.Task = new taskpool.Task(printArgs, 300); // 300: test number  
taskGroup2.addTask(task1);  
taskGroup2.addTask(task2);  
taskGroup2.addTask(task3);  
taskpool.execute(taskGroup1).then((res: Array<number>) => {  
  console.info("taskpool execute res is:" + res);  
});  
taskpool.execute(taskGroup2).then((res: Array<number>) => {  
  console.info("taskpool execute res is:" + res);  
});  
    
```    
  
    
## cancel    
取消任务池中的任务。  
 **调用形式：**     
- cancel(task: Task): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| task | Task | true | 需要取消执行的任务。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200015 | The task does not exist when it is canceled. |  
| 10200016 | The task is executing when it is canceled. |  
    
 **示例代码：**   
cancel(task: Task): void  
```ts    
@Concurrent  
function inspectStatus(arg: number): number {  
  // 第一时间检查取消并回复  
  if (taskpool.Task.isCanceled()) {  
    console.log("task has been canceled before 2s sleep.");  
    return arg + 2;  
  }  
  // 2s sleep  
  let t: number = Date.now();  
  while (Date.now() - t < 2000) {  
    continue;  
  }  
  // 第二次检查取消并作出响应  
  if (taskpool.Task.isCanceled()) {  
    console.log("task has been canceled after 2s sleep.");  
    return arg + 3;  
  }  
  return arg + 1;  
}  
  
let task1: taskpool.Task = new taskpool.Task(inspectStatus, 100); // 100: test number  
let task2: taskpool.Task = new taskpool.Task(inspectStatus, 200); // 200: test number  
let task3: taskpool.Task = new taskpool.Task(inspectStatus, 300); // 300: test number  
let task4: taskpool.Task = new taskpool.Task(inspectStatus, 400); // 400: test number  
let task5: taskpool.Task = new taskpool.Task(inspectStatus, 500); // 500: test number  
let task6: taskpool.Task = new taskpool.Task(inspectStatus, 600); // 600: test number  
taskpool.execute(task1).then((res: number)=>{  
  console.log("taskpool test result: " + res);  
});  
taskpool.execute(task2);  
taskpool.execute(task3);  
taskpool.execute(task4);  
taskpool.execute(task5);  
taskpool.execute(task6);  
// 1s后取消task  
setTimeout(()=>{  
  taskpool.cancel(task1);  
}, 1000);  
    
```    
  
    
## cancel<sup>(10+)</sup>    
取消任务池中的任务。  
 **调用形式：**     
- cancel(task: Task): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| task | Task | true | 需要取消执行的任务。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200015 | The task does not exist when it is canceled. |  
    
 **示例代码：**   
```ts    
@Concurrent  
function inspectStatus(arg: number): number {  
  // 第一时间检查取消并回复  
  if (taskpool.Task.isCanceled()) {  
    console.log("task has been canceled before 2s sleep.");  
    return arg + 2;  
  }  
  // 2s sleep  
  let t: number = Date.now();  
  while (Date.now() - t < 2000) {  
    continue;  
  }  
  // 第二次检查取消并作出响应  
  if (taskpool.Task.isCanceled()) {  
    console.log("task has been canceled after 2s sleep.");  
    return arg + 3;  
  }  
  return arg + 1;  
}  
  
let task1: taskpool.Task = new taskpool.Task(inspectStatus, 100); // 100: test number  
let task2: taskpool.Task = new taskpool.Task(inspectStatus, 200); // 200: test number  
let task3: taskpool.Task = new taskpool.Task(inspectStatus, 300); // 300: test number  
let task4: taskpool.Task = new taskpool.Task(inspectStatus, 400); // 400: test number  
let task5: taskpool.Task = new taskpool.Task(inspectStatus, 500); // 500: test number  
let task6: taskpool.Task = new taskpool.Task(inspectStatus, 600); // 600: test number  
taskpool.execute(task1).then((res: number)=>{  
  console.log("taskpool test result: " + res);  
});  
taskpool.execute(task2);  
taskpool.execute(task3);  
taskpool.execute(task4);  
taskpool.execute(task5);  
taskpool.execute(task6);  
// 1s后取消task  
setTimeout(()=>{  
  taskpool.cancel(task1);  
}, 1000);  
    
```    
  
    
## cancel<sup>(10+)</sup>    
取消任务池中的任务组。  
 **调用形式：**     
- cancel(group: TaskGroup): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| group | TaskGroup | true | 需要取消执行的任务组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200018 | The task group does not exist when it is canceled. |  
    
 **示例代码：**   
```ts    
@Concurrent  
function printArgs(args: number): number {  
  let t: number = Date.now();  
  while (Date.now() - t < 2000) {  
    continue;  
  }  
  console.log("printArgs: " + args);  
  return args;  
}  
  
let taskGroup1: taskpool.TaskGroup = new taskpool.TaskGroup();  
taskGroup1.addTask(printArgs, 10); // 10: test number  
let taskGroup2: taskpool.TaskGroup = new taskpool.TaskGroup();  
taskGroup2.addTask(printArgs, 100); // 100: test number  
taskpool.execute(taskGroup1).then((res: Array<number>)=>{  
  console.info("taskGroup1 res is:" + res);  
});  
taskpool.execute(taskGroup2).then((res: Array<number>)=>{  
  console.info("taskGroup2 res is:" + res);  
});  
setTimeout(()=>{  
  try {  
    taskpool.cancel(taskGroup2);  
  } catch (e) {  
    console.log("taskGroup.cancel occur error:" + e);  
  }  
}, 1000);  
    
```    
  
    
## getTaskPoolInfo<sup>(10+)</sup>    
获取任务池内部信息。  
 **调用形式：**     
- getTaskPoolInfo(): TaskPoolInfo  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| TaskPoolInfo | 任务池的内部信息。 |  
    
 **示例代码：**   
```ts    
let taskpoolInfo: taskpool.TaskPoolInfo = taskpool.getTaskPoolInfo();    
```    
  
