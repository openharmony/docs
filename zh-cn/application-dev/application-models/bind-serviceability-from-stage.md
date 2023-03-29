# Stage模型绑定FA模型ServiceAbility


本小节介绍Stage模型的两种应用组件如何绑定FA模型ServiceAbility组件。


## UIAbility关联访问ServiceAbility

UIAbility关联访问ServiceAbility和UIAbility关联访问ServiceExtensionAbility的方式完全相同。


```ts
import UIAbility from '@ohos.app.ability.UIAbility';

export default class MainAbility extends UIAbility {
    onCreate(want, launchParam) {
        console.info("MainAbility onCreate");
    }
    onDestroy() {
        console.info("MainAbility onDestroy")
    }
    onWindowStageCreate(windowStage) {
        console.info("MainAbility onWindowStageCreate")
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


## ExtensionAbility关联访问ServiceAbility

下面以ServiceExtensionAbility为例来说明ExtensionAbility关联访问ServiceAbility。ServiceExtensionAbility关联访问ServiceAbility和ServiceExtensionAbility关联访问ServiceExtensionAbility的方式完全相同。


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
