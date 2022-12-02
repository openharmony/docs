# FA模型绑定Stage模型ServiceExtensionAbility


本文介绍FA模型的三种应用组件如何绑定Stage模型的ServiceExtensionAbility组件。


## PageAbility关联访问ServiceExtensionAbility

PageAbility关联访问ServiceExtensionAbility和PageAbility关联访问ServiceAbility的方式完全相同。


```ts
import featureAbility from '@ohos.ability.featureAbility';

let want = {
    bundleName: "com.ohos.stage",
    abilityName: "com.ohos.stage.ServiceExtensionAbility"
};

let faConnect = {
    onConnect:function (elementName, proxy) {
        console.info("Faconnection onConnect called.");
    },
    onDisconnect:function (elementName) {
        console.info("Faconnection onDisconnect called.");
    },
    onFailed:function (code) {
        console.info("Faconnection onFailed code is: " + code);
    }
};
let connectionId = featureAbility.connectAbility(want, faConnect);
```


## ServiceAbility/DataAbility关联访问ServiceExtensionAbility

ServiceAbility/DataAbility关联访问ServiceExtensionAbility和ServiceAbility/DataAbility关联访问ServiceAbility的方式完全相同。


```ts
import particleAbility from '@ohos.ability.particleAbility';

let want = {
    bundleName: "com.ohos.stage",
    abilityName: "com.ohos.stage.ServiceExtensionAbility"
};

let faConnect = {
    onConnect:function (elementName, proxy) {
        console.info("Faconnection onConnect called.");
    },
    onDisconnect:function (elementName) {
        console.info("Faconnection onDisconnect called.");
    },
    onFailed:function (code) {
        console.info("Faconnection onFailed code is: " + code);
    }
};
let connectionId = particleAbility.connectAbility(want, faConnect);
```
