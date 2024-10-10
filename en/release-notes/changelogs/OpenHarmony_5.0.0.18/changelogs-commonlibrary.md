# CommonLibrary Subsystem Changelog

## cl.commonlibrary.1 Behavior for the Task Pool to Transfer Sendable Data Is Changed

**Access Level**

Other

**Change Reason**

The task pool is used to execute concurrent tasks. If Sendable data is directly returned in a call or the **sendData** API is called for data transmission, the default transmission mode of the Sendable data is changed from clone to shared. This change is because the data is seldom used after the task in the task pool is executed.

**Change Impact**

This change is a non-compatible change.

Before the change, when **taskpool.Task.sendData** of API version 11 is used to send or directly return Sendable data, one copy is made by default.

After the change, Sendable data is shared in this scenario. If the data is modified in the host thread, the subthread gets notified. However, the task pool is executed by task. There is a low probability that simultaneous operations are performed on the same object, and the impact of subsequent data changes on the task pool is controllable.

In the following code, the printed value may be 100 or changed to 200 by the subthread:

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

**Start API Level**

API version 11

**Change Since**

OpenHarmony SDK 5.0.0.18

**Key API/Component Changes**

N/A

**Adaptation Guide**

If **sendData** is not executed in the task pool or the read and write operations on the same attribute are performed by two independent threads after data is returned, no adaptation is required.

If **sendData** is executed in the task pool or the host thread and its subthread read and write the same attribute after data is returned, a lock must be used (imported from @arkts.utils).

Current code:

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
To ensure the thread safety of the **num** domain of class A, synchronization protection is required. The recommended code snippet is as follows:
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
