# ArkTS Changelog

## cl.ArkTS.1 Lazy Import Now Does Not Affect the Timing of Asynchronous Task Execution

**Access Level**

Other

**Reason for Change**

The use of lazy import variables changes the timing of asynchronous task execution.

**Change Impact**

This change is a non-compatible change.

Before change: Using lazy import variables changes the timing of asynchronous task execution.

After change: Using lazy import variables does not change the timing of asynchronous task execution.

**Start API Level**

12

**Change Since**

OpenHarmony SDK 5.0.1.44

**Key API/Component Changes**

N/A

**Adaptation Guide**

Check all the scenarios where lazy import variables are used.

An example use scenario is as follows:
```typescript
// myLog.ets
export class MyLog {
    static log(s:string) {
        console.log(s);
    }
}

// test.ets
import lazy { MyLog } from './myLog'

async function asyncFunc(f?:string): Promise<number> {
    MyLog.log("asyncFunc start");
    return new Promise(resolve => {
        resolve(0);
    });
}
export async function taskTest() {
    MyLog.log("taskTest start");
    asyncFunc().then((res) => {
        MyLog.log("asyncFunc then");
    });
    MyLog.log("taskTest end");
}
```
Before the change, lazy import affects the timing of asynchronous task execution. The output is as follows:
```
taskTest start
asyncFunc start
asyncFunc then
taskTest end
```
After the change, the output is as follows:
```
taskTest start
asyncFunc start
taskTest end
asyncFunc then
```
This change fixes the defect so that lazy import does not affect the timing of asynchronous task execution.
