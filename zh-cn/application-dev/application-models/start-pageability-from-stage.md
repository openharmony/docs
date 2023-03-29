# Stage模型启动FA模型PageAbility


本小节介绍Stage模型的两种应用组件如何启动FA模型的PageAbility组件。


## UIAbility启动PageAbility

  UIAbility启动PageAbility和UIAbility启动UIAbility的方式完全相同。

```ts
import UIAbility from '@ohos.app.ability.UIAbility'

export default class MainAbility extends UIAbility {
    onCreate(want, launchParam) {
        console.info("MainAbility onCreate")
    }
    onDestroy() {
        console.info("MainAbility onDestroy")
    }
    onWindowStageCreate(windowStage) {
        console.info("MainAbility onWindowStageCreate")
        windowStage.loadContent('pages/Index', (err, data) => {
            // ...
        });
        let want = {
            bundleName: "com.ohos.fa",
            abilityName: "MainAbility",
        };
        this.context.startAbility(want).then(() => {
            console.info('Start Ability successfully.');
        }).catch((error) => {
            console.error("Ability failed: " + JSON.stringify(error));
        });
    }
    onWindowStageDestroy() {
        console.info("MainAbility onWindowStageDestroy")
    }
    onForeground() {
        console.info("MainAbility onForeground")
    }
    onBackground() {
        console.info("MainAbility onBackground")
    }
}
```


## UIAbility访问PageAbility（startAbilityForResult）

startAbilityForResult和startAbility的区别是当PageAbility销毁的时候会返回执行结果。

UIAbility通过startAbilityForResult启动PageABility和UIAbility通过startAbilityForResult启动UIAbility的代码一样，没有任何区别。


```ts
import UIAbility from '@ohos.app.ability.UIAbility'

export default class MainAbility extends UIAbility {
    onCreate(want, launchParam) {
        console.info("MainAbility onCreate")
    }
    onDestroy() {
        console.info("MainAbility onDestroy")
    }
    onWindowStageCreate(windowStage) {
        console.info("MainAbility onWindowStageCreate")
        windowStage.loadContent('pages/Index', (err, data) => {
            // ...
        });
        let want = {
            bundleName: "com.ohos.fa",
            abilityName: "MainAbility",
        };
        this.context.startAbilityForResult(want).then((result) => {
            console.info('Ability verify result: ' + JSON.stringify(result));
        }).catch((error) => {
            console.error("Ability failed: " + JSON.stringify(error));
        });
    }
    onWindowStageDestroy() {
        console.info("MainAbility onWindowStageDestroy")
    }
    onForeground() {
        console.info("MainAbility onForeground")
    }
    onBackground() {
        console.info("MainAbility onBackground")
    }
}
```


## ExtensionAbility启动PageAbility

下面以ServiceExtensionAbility为例来说明ExtensionAbility启动PageAbility。ServiceExtensionAbility启动PageAbility和ServiceExtensionAbility启动UIAbility的方式完全相同。


```ts
import Extension from '@ohos.app.ability.ServiceExtensionAbility'

export default class ServiceExtension extends Extension {
    onCreate(want) {
        console.info("ServiceExtension onCreate")
    }
    onDestroy() {
        console.info("ServiceExtension onDestroy")
    }
    onRequest(want, startId) {
        console.info("ServiceExtension onRequest")
        let wantFA = {
            bundleName: "com.ohos.fa",
            abilityName: "MainAbility",
        };
        this.context.startAbility(wantFA).then(() => {
            console.info('Start Ability successfully.');
        }).catch((error) => {
            console.error("Ability failed: " + JSON.stringify(error));
        });
    }
}
```
