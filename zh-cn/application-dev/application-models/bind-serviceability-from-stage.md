# Stage模型绑定FA模型ServiceAbility


本小节介绍Stage模型的两种应用组件如何绑定FA模型ServiceAbility组件。


## UIAbility关联访问ServiceAbility

UIAbility关联访问ServiceAbility和UIAbility关联访问ServiceExtensionAbility的方式完全相同。


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


## ExtensionAbility关联访问ServiceAbility

下面以ServiceExtensionAbility为例来说明ExtensionAbility关联访问ServiceAbility。ServiceExtensionAbility关联访问ServiceAbility和ServiceExtensionAbility关联访问ServiceExtensionAbility的方式完全相同。


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
