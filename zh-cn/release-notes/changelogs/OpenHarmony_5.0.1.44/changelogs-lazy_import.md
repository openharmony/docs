# ArkTS方舟编程语言Changelog

## cl.ArkTS.1 延迟加载（lazy import）影响异步任务执行时序变更为不影响异步任务执行时序

**访问级别**

其他

**变更原因**

延迟加载（lazy import）特性在测试过程中发现问题，使用lazy import的变量，会改变异步任务的运行时序。

**变更影响**

该变更为不兼容变更。

变更前： 使用lazy import的变量，会改变异步任务的运行时序。

变更后： 使用lazy import的变量，不会改变异步任务的运行时序。

**起始 API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.1.44 版本开始。

**变更的接口/组件**

不涉及

**适配指导**

排查使用lazy import变量的场景，该功能的时序可能会发生改变。

例如：
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
【提示】修改之前，lazy import会影响异步任务的运行时序，该用例的输出为：
```
taskTest start
asyncFunc start
asyncFunc then
taskTest end
```
修复问题之后，该用例的输出为：
```
taskTest start
asyncFunc start
taskTest end
asyncFunc then
```
本变更修复该问题，使得lazy import不会影响异步任务运行时序。