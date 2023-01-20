# Connecting to a ServiceAbility from the Stage Model


This topic describes how the two application components of the stage model connect to the ServiceAbility component of the FA model.


## UIAbility Accessing a ServiceAbility

A UIAbility accesses a ServiceAbility in the same way as it accesses a ServiceExtensionAbility.


```ts
import UIAbility from '@ohos.app.ability.UIAbility';

export default class EntryAbility extends UIAbility {
    onCreate(want, launchParam) {
        console.info("EntryAbility onCreate");
    }
    onDestroy() {
        console.info("EntryAbility onDestroy")
    }
    onWindowStageCreate(windowStage) {
        console.info("EntryAbility onWindowStageCreate")
        let want = {
            bundleName: "com.ohos.fa",
            abilityName: "ServiceAbility",
        };

        let options = {
            onConnect:function (elementName, proxy) {
                console.info("onConnect called.");
            },
            onDisconnect:function (elementName) {
                console.info("onDisconnect called.");
            },
            onFailed:function (code) {
                console.info("onFailed code is: " + code);
            }
        };
        let connectionId = this.context.connectServiceExtensionAbility(want, options);
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


## ExtensionAbility Accessing a ServiceAbility

The following uses the ServiceExtensionAbility component as an example to describe how an ExtensionAbility accesses a ServiceAbility. A ServiceExtensionAbility accesses a ServiceAbility in the same way as it accesses another ServiceExtensionAbility.


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
            abilityName: "ServiceAbility",
        };
        let options = {
            onConnect:function (elementName, proxy) {
                console.info("onConnect called.");
            },
            onDisconnect:function (elementName) {
                console.info("onDisconnect called.");
            },
            onFailed:function (code) {
                console.info("onFailed code is: " + code);
            }
        };
        let connectionId = this.context.connectServiceExtensionAbility(wantFA, options);
    }
}
```
