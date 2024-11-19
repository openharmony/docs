# 错误管理开发指导

## 场景介绍

当应用的代码存在规范问题或错误时，会在运行中产生异常和错误，如应用未捕获异常、应用生命周期超时等。在错误产生后，应用会异常退出。错误日志通常会保存在用户本地存储上，不方便开发者定位问题。所以，应用开发者可以使用错误管理的接口，在应用退出前，及时将相关错误及日志上报到开发者的服务平台来定位问题。
使用errormanager接口监听异常和错误后，应用不会退出，建议在回调函数执行完后，增加同步退出操作，如果只是为了获取错误日志，建议使用[hiappevent](hiappevent-watcher-crash-events-arkts.md)。

## 接口说明

应用错误管理接口由[errorManager](../reference/apis-ability-kit/js-apis-app-ability-errorManager.md)模块提供，开发者可以通过import引入，详见[开发示例](#开发示例)。

**错误管理接口功能介绍：**

| 接口名称                                                       | 说明                                                 |
| ------------------------------------------------------------ | ---------------------------------------------------- |
| on(type: "error", observer: ErrorObserver): number       | 注册错误监听接口，当系统监测到应用异常时会回调该监听。该接口为同步接口，返回值为注册的监听对象对应的序号。 |
| off(type: "error", observerId: number,  callback: AsyncCallback\<void\>): void | 以callback的形式解除注册监听，传入的number为之前注册监听时返回的序号。  |
| off(type: "error", observerId: number): Promise\<void\> | 以Promise的形式解除注册监听，传入的number为之前注册监听时返回的序号。  |
| on(type: 'loopObserver', timeout: number, observer: LoopObserver): void<sup>12+</sup> | 注册主线程消息处理耗时监听器，当系统监测到应用主线程事件处理超时时会回调该监听。只能在主线程调用，多次注册后，后一次的注册会覆盖前一次的。  |
| off(type: 'loopObserver', observer?: LoopObserver): void<sup>12+</sup> | 解除应用主线程消息处理耗时监听。  |

当采用callback作为异步回调时，可以在callback中进行下一步处理。当采用Promise对象返回时，可以在Promise对象中类似地处理接口返回值。具体结果码说明见[解除注册结果码](#解除注册结果码)。


**错误监听(ErrorObserver)接口功能介绍：**

> **说明：**
>
> 在主线程注册errormanager.on接口，当前版本不支持捕获子线程（如：taskpool）中的异常。

| 接口名称                         | 说明                                                         |
| ------------------------------ | ------------------------------------------------------------ |
| onUnhandledException(errMsg: string): void | 系统回调接口，应用注册后，当应用产生未捕获的异常时的回调。 |
| onException?(errObject: Error): void | 系统回调接口，应用注册后，当应用产生异常上报js层时的回调。 |


**应用主线程监听(LoopObserver)接口功能介绍：**

| 接口名称                         | 说明                                                         |
| ------------------------------ | ------------------------------------------------------------ |
| onLoopTimeOut?(timeout: number): void<sup>12+</sup> | 系统回调接口，应用注册后，当应用主线程处理事件超时的回调。 |


### 解除注册结果码

| 结果码 | 原因                        |
| ------ | ---------------------------  |
| 0      |  正常返回                          |
| -1     | 传入的number不存在              |
| -2     | 参数错误       |

## 开发示例

> **注意：**
> 建议在异常回调函数处理的最后，增加同步退出操作，否则可能出现多次异常回调的现象。

```ts
import { AbilityConstant, errorManager, UIAbility, Want } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import process from '@ohos.process';

let registerId = -1;
let callback: errorManager.ErrorObserver = {
    onUnhandledException: (errMsg) => {
        console.log(errMsg);
    },
    onException: (errorObj) => {
        console.log('onException, name: ', errorObj.name);
        console.log('onException, message: ', errorObj.message);
        if (typeof(errorObj.stack) === 'string') {
            console.log('onException, stack: ', errorObj.stack);
        }
        //回调函数执行完，采用同步退出方式，避免多次触发
        let pro = new process.ProcessManager();
        pro.exit(0);
    }
}

let abilityWant: Want;

export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
        console.log("[Demo] EntryAbility onCreate");
        registerId = errorManager.on("error", callback);
        abilityWant = want;
    }

    onDestroy() {
        console.log("[Demo] EntryAbility onDestroy");
        errorManager.off("error", registerId, (result) => {
            console.log("[Demo] result " + result.code + ";" + result.message);
        });
    }

    onWindowStageCreate(windowStage: window.WindowStage) {
        // Main window is created, set main page for this ability
        console.log("[Demo] EntryAbility onWindowStageCreate");

        windowStage.loadContent("pages/index", (err, data) => {
            if (err.code) {
                console.error('Failed to load the content. Cause:' + JSON.stringify(err));
                return;
            }
            console.info('Succeeded in loading the content. Data: ' + JSON.stringify(data));
        });
    }

    onWindowStageDestroy() {
        // Main window is destroyed, release UI related resources
        console.log("[Demo] EntryAbility onWindowStageDestroy");
    }

    onForeground() {
        // Ability has brought to foreground
        console.log("[Demo] EntryAbility onForeground");
    }

    onBackground() {
        // Ability has back to background
        console.log("[Demo] EntryAbility onBackground");
    }
};
```
