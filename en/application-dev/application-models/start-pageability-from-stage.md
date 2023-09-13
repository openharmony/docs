# Starting a PageAbility from the Stage Model


This topic describes how the two application components of the stage model start the PageAbility component of the FA model.


## UIAbility Starting a PageAbility

A UIAbility starts a PageAbility in the same way as it starts another UIAbility.

> **NOTE**
> 
> In the FA model, **abilityName** consists of **bundleName** and **AbilityName**. For details, see the code snippet below.

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


## UIAbility Accessing a PageAbility (startAbilityForResult)

Different from **startAbility()**, **startAbilityForResult()** obtains the execution result when the PageAbility is destroyed.

A UIAbility starts a PageAbility through **startAbilityForResult()** in the same way as it starts another UIAbility through **startAbilityForResult()**.


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


## ExtensionAbility Starting a PageAbility

The following uses the ServiceExtensionAbility component as an example to describe how an ExtensionAbility starts a PageAbility. A ServiceExtensionAbility starts a PageAbility in the same way as it starts a UIAbility.


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
