# Connecting to a ServiceExtensionAbility from the FA Model


This topic describes how the three application components of the FA model connect to the ServiceExtensionAbility component of the stage model.


## PageAbility Accessing a ServiceExtensionAbility

A PageAbility accesses a ServiceExtensionAbility in the same way as it accesses a ServiceAbility.


```ts
import featureAbility from '@ohos.ability.featureAbility';
import common from '@ohos.app.ability.common';
import Want from '@ohos.app.ability.Want';

let want: Want = {
    bundleName: "com.ohos.stage",
    abilityName: "com.ohos.stage.ServiceExtensionAbility"
};

let faConnect: common.ConnectOptions = {
    onConnect: (elementName, proxy) => {
        console.info("Faconnection onConnect called.");
    },
    onDisconnect: (elementName) => {
        console.info("Faconnection onDisconnect called.");
    },
    onFailed: (code) => {
        console.info("Faconnection onFailed code is: " + code);
    }
};
let connectionId = featureAbility.connectAbility(want, faConnect);
```


## ServiceAbility or DataAbility Accessing a ServiceExtensionAbility

A ServiceAbility or DataAbility accesses a ServiceExtensionAbility in the same way as it accesses a ServiceAbility.


```ts
import particleAbility from '@ohos.ability.particleAbility';
import common from '@ohos.app.ability.common';
import Want from '@ohos.app.ability.Want';

let want: Want = {
    bundleName: "com.ohos.stage",
    abilityName: "com.ohos.stage.ServiceExtensionAbility"
};

let faConnect: common.ConnectOptions = {
    onConnect: (elementName, proxy) => {
        console.info("Faconnection onConnect called.");
    },
    onDisconnect: (elementName) => {
        console.info("Faconnection onDisconnect called.");
    },
    onFailed: (code) => {
        console.info("Faconnection onFailed code is: " + code);
    }
};
let connectionId = particleAbility.connectAbility(want, faConnect);
```
