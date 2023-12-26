# FA模型绑定Stage模型ServiceExtensionAbility


本文介绍FA模型的三种应用组件如何绑定Stage模型的ServiceExtensionAbility组件。


## PageAbility关联访问ServiceExtensionAbility

PageAbility关联访问ServiceExtensionAbility和PageAbility关联访问ServiceAbility的方式完全相同。


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


## ServiceAbility/DataAbility关联访问ServiceExtensionAbility

ServiceAbility/DataAbility关联访问ServiceExtensionAbility和ServiceAbility/DataAbility关联访问ServiceAbility的方式完全相同。


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
