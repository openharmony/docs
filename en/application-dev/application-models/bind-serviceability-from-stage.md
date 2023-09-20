# Connecting to a ServiceAbility from the Stage Model


This topic describes how the two application components of the stage model connect to the ServiceAbility component of the FA model.


## UIAbility Accessing a ServiceAbility

A UIAbility accesses a ServiceAbility in the same way as it accesses a ServiceExtensionAbility.


```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import common from '@ohos.app.ability.common';
import Want from '@ohos.app.ability.Want';
import window from '@ohos.window';

export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
        console.info("EntryAbility onCreate");
    }
    onDestroy() {
        console.info("EntryAbility onDestroy")
    }
    onWindowStageCreate(windowStage: window.WindowStage) {
        console.info("EntryAbility onWindowStageCreate")
        let want: Want = {
            bundleName: "com.ohos.fa",
            abilityName: "ServiceAbility",
        };

        let options: common.ConnectOptions = {
            onConnect: (elementName, proxy) => {
                console.info("onConnect called.");
            },
            onDisconnect: (elementName) => {
                console.info("onDisconnect called.");
            },
            onFailed: (code) => {
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
import Extension from '@ohos.app.ability.ServiceExtensionAbility';
import common from '@ohos.app.ability.common';
import Want from '@ohos.app.ability.Want';

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
            abilityName: "ServiceAbility",
        };
        let options: common.ConnectOptions = {
            onConnect: (elementName, proxy) => {
                console.info("onConnect called.");
            },
            onDisconnect: (elementName) => {
                console.info("onDisconnect called.");
            },
            onFailed: (code) => {
                console.info("onFailed code is: " + code);
            }
        };
        let connectionId = this.context.connectServiceExtensionAbility(wantFA, options);
    }
}
```
