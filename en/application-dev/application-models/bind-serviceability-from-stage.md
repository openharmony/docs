# Connecting to a ServiceAbility from the Stage Model


This topic describes how the two application components of the stage model connect to the ServiceAbility component of the FA model.


## UIAbility Accessing a ServiceAbility

A UIAbility accesses a ServiceAbility in the same way as it accesses a ServiceExtensionAbility.


```ts
import common from '@ohos.app.ability.common';
import hilog from '@ohos.hilog';
import Logger from '../utils/Logger';
import promptAction from '@ohos.promptAction'
import Want from '@ohos.app.ability.Want';

import { BusinessError } from '@ohos.base';

const TAG: string = '[Page_StartFAModel]';
const DOMAIN_NUMBER: number = 0xFF00;

let want: Want = {
  bundleName: 'com.samples.famodelabilitydevelop',
  abilityName: 'com.samples.famodelabilitydevelop.ServiceAbility',
}

let options: common.ConnectOptions = {
  onConnect: (elementName, proxy) => {
    Logger.info('onConnect called.');
    promptAction.showToast({
      message: $r('app.string.ConnectFAServiceAbility')
    });
  },
  onDisconnect: (elementName) => {
    Logger.info('onDisconnect called.');
  },
  onFailed: (code) => {
    Logger.info('onFailed code is: ' + code);
  }
};
let connectionId = this.context.connectServiceExtensionAbility(want, options);
hilog.info(DOMAIN_NUMBER, TAG, 'connectionId is ' + JSON.stringify(connectionId));
```


## ExtensionAbility Accessing a ServiceAbility

The following uses the ServiceExtensionAbility component as an example to describe how an ExtensionAbility accesses a ServiceAbility. A ServiceExtensionAbility accesses a ServiceAbility in the same way as it accesses another ServiceExtensionAbility.


```ts
import common from '@ohos.app.ability.common';
import hilog from '@ohos.hilog';
import Logger from '../utils/Logger';
import promptAction from '@ohos.promptAction'
import Want from '@ohos.app.ability.Want';

import { BusinessError } from '@ohos.base';

const TAG: string = '[Page_StartFAModel]';
const DOMAIN_NUMBER: number = 0xFF00;

let want: Want = {
  bundleName: 'com.samples.famodelabilitydevelop',
  abilityName: 'com.samples.famodelabilitydevelop.ServiceAbility',
}

let options: common.ConnectOptions = {
  onConnect: (elementName, proxy) => {
    Logger.info('onConnect called.');
    promptAction.showToast({
      message: $r('app.string.ConnectFAServiceAbility')
    });
  },
  onDisconnect: (elementName) => {
    Logger.info('onDisconnect called.');
  },
  onFailed: (code) => {
    Logger.info('onFailed code is: ' + code);
  }
};
let connectionId = this.context.connectServiceExtensionAbility(want, options);
hilog.info(DOMAIN_NUMBER, TAG, 'connectionId is ' + JSON.stringify(connectionId));
```
