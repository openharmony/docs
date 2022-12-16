# 错误管理开发指导

## 场景介绍

当应用的代码存在规范问题或错误时，会在运行中产生异常和错误，如应用未捕获异常、应用生命周期超时等。在错误产生后，应用会异常退出。错误日志通常会保存在用户本地存储上，不方便开发者定位问题。所以，应用开发者可以使用错误管理的接口，在应用退出前，及时将相关错误及日志上报到开发者的服务平台来定位问题。

## 接口说明

应用错误管理接口由errorManager模块提供，开发者可以通过import引入，详见[开发示例](#开发示例)。

**错误管理接口功能介绍：**

| 接口名称                                                       | 说明                                                 |
| ------------------------------------------------------------ | ---------------------------------------------------- |
| registerErrorObserver(observer: ErrorObserver): number       | 注册错误监听接口，当系统监测到应用异常时会回调该监听。该接口为同步接口，返回值为注册的监听对象对应的序号。 |
| unregisterErrorObserver(observerId: number,  callback: AsyncCallback\<void\>): void | 以callback的形式解除注册监听，传入的number为之前注册监听时返回的序号。  |
| unregisterErrorObserver(observerId: number): Promise\<void\> | 以Promise的形式解除注册监听，传入的number为之前注册监听时返回的序号。  |

当采用callback作为异步回调时，可以在callback中进行下一步处理。当采用Promise对象返回时，可以在Promise对象中类似地处理接口返回值。具体结果码说明见[解除注册结果码](#解除注册结果码)。


**错误监听(ErrorObserver)接口功能介绍：**

| 接口名称                         | 说明                                                         |
| ------------------------------ | ------------------------------------------------------------ |
| onUnhandledException(errMsg: string): void | 系统回调接口，应用注册后，当应用产生未捕获的异常时的回调。 |


### 解除注册结果码

| 结果码 | 原因                        |
| ------ | ---------------------------  |
| 0      |  正常返回                          |
| -1     | 传入的number不存在              |
| -2     | 参数错误       |

## 开发示例
```ts
import Ability from '@ohos.application.Ability'
import errorManager from '@ohos.application.errorManager'

var registerId = -1;
var callback = {
    onUnhandledException: function (errMsg) {
        console.log(errMsg);
    }
}

export default class MainAbility extends Ability {
    onCreate(want, launchParam) {
        console.log("[Demo] MainAbility onCreate")
        registerId = errorManager.registerErrorObserver(callback);
        globalThis.abilityWant = want;
    }

    onDestroy() {
        console.log("[Demo] MainAbility onDestroy")
        errorManager.unregisterErrorObserver(registerId, (result) => {
            console.log("[Demo] result " + result.code + ";" + result.message)
        });
    }

    onWindowStageCreate(windowStage) {
        // Main window is created, set main page for this ability
        console.log("[Demo] MainAbility onWindowStageCreate")

        windowStage.loadContent("pages/index", (err, data) => {
            if (err.code) {
                console.error('Failed to load the content. Cause:' + JSON.stringify(err));
                return;
            }
            console.info('Succeeded in loading the content. Data: ' + JSON.stringify(data))
        });
    }

    onWindowStageDestroy() {
        // Main window is destroyed, release UI related resources
        console.log("[Demo] MainAbility onWindowStageDestroy")
    }

    onForeground() {
        // Ability has brought to foreground
        console.log("[Demo] MainAbility onForeground")
    }

    onBackground() {
        // Ability has back to background
        console.log("[Demo] MainAbility onBackground")
    }
};
```