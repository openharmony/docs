# Connecting to a ServiceExtensionAbility from the FA Model


This topic describes how the three application components of the FA model connect to the ServiceExtensionAbility component of the stage model.


## PageAbility Accessing a ServiceExtensionAbility

A PageAbility accesses a ServiceExtensionAbility in the same way as it accesses a ServiceAbility.


```ts
import featureAbility from '@ohos.ability.featureAbility';
import common from '@ohos.app.ability.common';
import Want from '@ohos.app.ability.Want';

let serviceWant: Want = {
  bundleName: 'com.samples.stagemodelabilityinteraction',
  abilityName: 'ServiceExtAbility'
};

let faConnect: common.ConnectOptions = {
  onConnect: (elementName, proxy) => {
    Logger.info(TAG, "FaConnection onConnect called.");
  },
  onDisconnect: (elementName) => {
    Logger.info(TAG, "FaConnection onDisconnect called.");
  },
  onFailed: (code) => {
    Logger.info(TAG, "FaConnection onFailed code is: " + code);
  }
};
let connectionId = featureAbility.connectAbility(serviceWant, faConnect);
```


## ServiceAbility or DataAbility Accessing a ServiceExtensionAbility

A ServiceAbility or DataAbility accesses a ServiceExtensionAbility in the same way as it accesses a ServiceAbility.


```ts
import particleAbility from '@ohos.ability.particleAbility';
import common from '@ohos.app.ability.common';
import Want from '@ohos.app.ability.Want';

let serviceWant: Want = {
  bundleName: 'com.samples.stagemodelabilityinteraction',
  abilityName: 'ServiceExtAbility'
};
let faConnect: common.ConnectOptions = {
  onConnect: (elementName, proxy) => {
    hilog.info(domain, TAG, 'FaConnection onConnect called.');
  },
  onDisconnect: (elementName) => {
    hilog.info(domain, TAG, 'FaConnection onDisconnect called.');
  },
  onFailed: (code) => {
    hilog.info(domain, TAG, 'FaConnection onFailed code is: ' + code);
  }
};
let connectionId = particleAbility.connectAbility(serviceWant, faConnect);
```
