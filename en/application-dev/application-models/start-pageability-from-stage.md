# Starting a PageAbility from the Stage Model


This topic describes how the two application components of the stage model start the PageAbility component of the FA model.


## UIAbility Starting a PageAbility

A UIAbility starts a PageAbility in the same way as it starts another UIAbility.

> **NOTE**
> 
> In the FA model, **abilityName** consists of **bundleName** and **AbilityName**. For details, see the code snippet below.

```ts
import UIAbility from '@ohos.app.ability.UIAbility';

export default class EntryAbility extends UIAbility {
    onCreate(want, launchParam) {
        console.info("EntryAbility onCreate")
    }
    onDestroy() {
        console.info("EntryAbility onDestroy")
    }
    onWindowStageCreate(windowStage) {
        console.info("EntryAbility onWindowStageCreate")
        windowStage.loadContent('pages/Index', (err, data) => {
            ...
        });
        let want = {
            bundleName: "com.ohos.fa",
            abilityName: "com.ohos.fa.EntryAbility",
        };
        this.context.startAbility(want).then(() => {
            console.info('Start Ability successfully.');
        }).catch((error) => {
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

export default class EntryAbility extends UIAbility {
    onCreate(want, launchParam) {
        console.info("EntryAbility onCreate")
    }
    onDestroy() {
        console.info("EntryAbility onDestroy")
    }
    onWindowStageCreate(windowStage) {
        console.info("EntryAbility onWindowStageCreate")
        windowStage.loadContent('pages/Index', (err, data) => {
            ...
        });
        let want = {
            bundleName: "com.ohos.fa",
            abilityName: "EntryAbility",
        };
        this.context.startAbilityForResult(want).then((result) => {
            console.info('Ability verify result: ' + JSON.stringify(result));
        }).catch((error) => {
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
            abilityName: "EntryAbility",
        };
        this.context.startAbility(wantFA).then(() => {
            console.info('Start Ability successfully.');
        }).catch((error) => {
            console.error("Ability failed: " + JSON.stringify(error));
        });
    }
}
```
