# Stage模型绑定FA模型ServiceAbility


本小节介绍Stage模型的两种应用组件如何绑定FA模型ServiceAbility组件。


## UIAbility关联访问ServiceAbility

UIAbility关联访问ServiceAbility和UIAbility关联访问ServiceExtensionAbility的方式完全相同。


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


## ExtensionAbility关联访问ServiceAbility

下面以ServiceExtensionAbility为例来说明ExtensionAbility关联访问ServiceAbility。ServiceExtensionAbility关联访问ServiceAbility和ServiceExtensionAbility关联访问ServiceExtensionAbility的方式完全相同。


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
