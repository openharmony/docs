# CommonLibrary子系统变更说明

## cl.commonlibrary.1 taskpool传输Sendable数据行为变更

**访问级别**

其他

**变更原因**

taskpool执行并发任务，对于Sendable数据类型，以执行结果返回或sendData接口传输时，将Sendable数据的传输方式由克隆转为共享。考虑到taskpool任务执行后的数据再次使用的场景几乎不存在，从设计上也不推荐，因此从taskpool接口的易用性考虑，对默认的传输行为进行变更。

**变更影响**

此变更为非兼容变更
变更前，使用API11的taskpool.Task.sendData接口发送或直接返回Sendable数据时，会默认拷贝一份。
变更后，在该场景下，Sendable数据会共享传输，此时如果在主线程修改，子线程也会感知到变化。但是由于taskpool以任务维度执行，对一个对象的同时操作场景较少，后续的数据变化对taskpool的影响可控。
如下代码，打印出来的值可能是100，也可能被子线程改成200：
```
import { taskpool } from '@kit.ArkTS'
@Sendable
class A {
    num: number = 100
}
@Concurrent
async function foo(a: A) {
    taskpool.Task.sendData(a)
    a.num = 200
}
let a: A = new A()
let task = new taskpool.Task(foo, a)
task.onReceiveData((val: A) => {
    console.log("num: " + val.num)
})
```

**起始 API Level**

Sendable接口从API 11起启用。

**变更发生版本**

从OpenHarmony SDK 5.0.0.18 开始。

**变更的接口/组件**

不涉及。

**适配指导**

如果不涉及taskpool执行sendData或者返回数据后仍然在两个线程分别读写同一个属性，则不需要适配。
如果taskpool执行sendData或者返回数据后，如果宿主线程与子线程分别读写同一个属性，需要使用锁进行保护（从@arkts.utils导入）。
当前代码：
```
import { taskpool } from '@kit.ArkTS'
@Sendable
class A {
    num: number = 100
}
@Concurrent
async function foo(a: A) {
    taskpool.Task.sendData(a)
    a.num = 200
}
let a: A = new A()
let task = new taskpool.Task(foo, a)
task.onReceiveData((val: A) => {
    console.log("num: " + val.num)
})
```
为了保证class A的num域线程安全，需要增加同步保护，推荐改法：
```
import { taskpool } from '@kit.ArkTS'
@Sendable
class A {
    num: number = 100
    async setNum(num: number) {
        // add lock here
        this.num = num
    }
    async getNum(): Promise<number> {
        // add lock here
        return this.num
    }
}
@Concurrent
async function foo(a: A) {
    taskpool.Task.sendData(a)
    a.setNum(200)
}
let a: A = new A()
let task = new taskpool.Task(foo, a)
task.onReceiveData((val: A) => {
    console.log("num: " + val.getNum())
})
```


## cl.commonlibrary.2 taskpool.getTaskPoolInfo获取到的taskInfos中taskId的类型由BigInt变为number

**访问级别**

其他

**变更原因**

taskpool.getTaskPoolInfo获取到的taskInfos中taskId的大小选用number类型足够使用，不需要使用BigInt。

**变更影响**

此变更为非兼容变更
变更前，taskId的类型为BigInt。
变更后，taskId的类型为number。taskId是通过taskpool.getTaskPoolInfo获取到的TaskPoolInfo类中TaskInfo的成员，成员类型的变化不影响通过taskpool.getTaskPoolInfo接口获取其他属性，对开发者影响较小。

当前代码：
```ts
import { taskpool } from '@kit.ArkTS'

@Concurrent
function delay(): void {
  let start: number = new Date().getTime();
  while (new Date().getTime() - start < 500) {
    continue;
  }
}

let task1: taskpool.Task = new taskpool.Task(delay);
let task2: taskpool.Task = new taskpool.Task(delay);
let task3: taskpool.Task = new taskpool.Task(delay);
taskpool.execute(task1, taskpool.Priority.LOW)
taskpool.execute(task2, taskpool.Priority.MEDIUM)
taskpool.execute(task3, taskpool.Priority.HIGH)
let start: number = new Date().getTime();
while (new Date().getTime() - start < 1000) {
  continue;
}
let taskpoolInfo: taskpool.TaskPoolInfo = taskpool.getTaskPoolInfo();
let taskId: number = 0;
let taskIS = Array.from(taskpoolInfo.taskInfos)
for(let taskInfo of taskIS) {
  taskId = taskInfo.taskId;
  console.info("taskpool---taskId is:" + taskId);
}
```

**起始 API Level**

Sendable接口从API 11起启用。

**变更发生版本**

从OpenHarmony SDK 5.0.0.18 开始。

**变更的接口/组件**

taskpool.getTaskPoolInfo。

**适配指导**

定义taskId时类型为number。