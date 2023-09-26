# Stage模型启动FA模型PageAbility


本小节介绍Stage模型的两种应用组件如何启动FA模型的PageAbility组件。


## UIAbility启动PageAbility

  UIAbility启动PageAbility和UIAbility启动UIAbility的方式完全相同。

> **说明：**
> 需注意FA模型中abilityName由bundleName + AbilityName组成，具体见示例。

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import Want from '@ohos.app.ability.Want';
import window from '@ohos.window';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
        console.info("EntryAbility onCreate")
    }
    onDestroy() {
        console.info("EntryAbility onDestroy")
    }
    onWindowStageCreate(windowStage: window.WindowStage) {
        console.info("EntryAbility onWindowStageCreate")
        windowStage.loadContent('pages/Index', (err, data) => {
            // ...
        });
        let want: Want = {
            bundleName: "com.ohos.fa",
            abilityName: "com.ohos.fa.EntryAbility",
        };
        this.context.startAbility(want).then(() => {
            console.info('Start Ability successfully.');
        }).catch((error: BusinessError) => {
            console.error("Ability failed: " + JSON.stringify(error));
        });
    }
    onWindowStageDestroy() {
        console.info("EntryAbility onWindowStageDestroy")
    }
    onForeground() {
        console.info("EntryAbility onForeground")
    }
    onBackground() {
        console.info("EntryAbility onBackground")
    }
}
```


## UIAbility访问PageAbility（startAbilityForResult）

startAbilityForResult和startAbility的区别是当PageAbility销毁的时候会返回执行结果。

UIAbility通过startAbilityForResult启动PageABility和UIAbility通过startAbilityForResult启动UIAbility的代码一样，没有任何区别。


```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import Want from '@ohos.app.ability.Want';
import window from '@ohos.window';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
        console.info("EntryAbility onCreate")
    }
    onDestroy() {
        console.info("EntryAbility onDestroy")
    }
    onWindowStageCreate(windowStage: window.WindowStage) {
        console.info("EntryAbility onWindowStageCreate")
        windowStage.loadContent('pages/Index', (err, data) => {
            // ...
        });
        let want: Want = {
            bundleName: "com.ohos.fa",
            abilityName: "EntryAbility",
        };
        this.context.startAbilityForResult(want).then((result) => {
            console.info('Ability verify result: ' + JSON.stringify(result));
        }).catch((error: BusinessError) => {
            console.error("Ability failed: " + JSON.stringify(error));
        });
    }
    onWindowStageDestroy() {
        console.info("EntryAbility onWindowStageDestroy")
    }
    onForeground() {
        console.info("EntryAbility onForeground")
    }
    onBackground() {
        console.info("EntryAbility onBackground")
    }
}
```


## ExtensionAbility启动PageAbility

下面以ServiceExtensionAbility为例来说明ExtensionAbility启动PageAbility。ServiceExtensionAbility启动PageAbility和ServiceExtensionAbility启动UIAbility的方式完全相同。


```ts
import Extension from '@ohos.app.ability.ServiceExtensionAbility'
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

export default class ServiceExtension extends Extension {
    onCreate(want: Want) {
        console.info("ServiceExtension onCreate")
    }
    onDestroy() {
        console.info("ServiceExtension onDestroy")
    }
    onRequest(want: Want, startId: number) {
        console.info("ServiceExtension onRequest")
        let wantFA: Want = {
            bundleName: "com.ohos.fa",
            abilityName: "EntryAbility",
        };
        this.context.startAbility(wantFA).then(() => {
            console.info('Start Ability successfully.');
        }).catch((error: BusinessError) => {
            console.error("Ability failed: " + JSON.stringify(error));
        });
    }
}
```
