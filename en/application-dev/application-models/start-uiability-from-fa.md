# Starting a UIAbility from the FA Model


This topic describes how the three application components of the FA model start the UIAbility component of the stage model.


## PageAbility Starting a UIAbility

A PageAbility starts a UIAbility in the same way as it starts another PageAbility.

```ts
import featureAbility from '@ohos.ability.featureAbility';
import { BusinessError } from '@ohos.base';
import Want from '@ohos.app.ability.Want';
import Logger from '../../utils/Logger';

const TAG: string = 'PageInterflowFaAndStage';

let want: Want = {
  bundleName: 'ohos.samples.etsclock',
  abilityName: 'MainAbility'
};
featureAbility.startAbility({ want }).then((code) => {
  Logger.info(TAG, 'Ability verify code: ' + JSON.stringify(code));
}).catch((error: BusinessError) => {
  Logger.error(TAG, 'Ability failed: ' + JSON.stringify(error));
});
```


## PageAbility Accessing a UIAbility (startAbilityForResult)

Different from **startAbility()**, **startAbilityForResult()** obtains the execution result when the UIAbility is destroyed.

A PageAbility starts a UIAbility through **startAbilityForResult()** in the same way as it starts another PageAbility through **startAbilityForResult()**.


```ts
import featureAbility from '@ohos.ability.featureAbility';
import { BusinessError } from '@ohos.base';
import Want from '@ohos.app.ability.Want';
import Logger from '../../utils/Logger';

const TAG: string = 'PageInterflowFaAndStage';

let want: Want = {
  bundleName: 'ohos.samples.etsclock',
  abilityName: 'MainAbility'
};
featureAbility.startAbilityForResult({ want }).then((result) => {
  Logger.info(TAG, 'Ability verify result: ' + JSON.stringify(result));
}).catch((error: BusinessError) => {
  Logger.error(TAG, 'Ability failed: ' + JSON.stringify(error));
});
```


## ServiceAbility or DataAbility Starting a UIAbility

A ServiceAbility or DataAbility starts a UIAbility in the same way as it starts a PageAbility.


```ts
import particleAbility from '@ohos.ability.particleAbility';
import { BusinessError } from '@ohos.base';
import Want from '@ohos.app.ability.Want';
import hilog from '@ohos.hilog';

const TAG: string = '[Sample_FAModelAbilityDevelop]';

let want: Want = {
  bundleName: 'ohos.samples.etsclock',
  abilityName: 'MainAbility'
};
particleAbility.startAbility({ want }).then(() => {
  hilog.info(TAG, 'StartUIAbility Start Ability successfully.');
}).catch((error: BusinessError) => {
  hilog.error(TAG, 'StartUIAbility Ability failed: ' + JSON.stringify(error));
});
hilog.info(TAG, 'StartUIAbility ServiceAbility onStart');
```
