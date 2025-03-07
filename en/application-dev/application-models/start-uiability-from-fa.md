# Starting a UIAbility from the FA Model


This topic describes how the three application components of the FA model start the UIAbility component of the stage model.


## PageAbility Starting a UIAbility

A PageAbility starts a UIAbility in the same way as it starts another PageAbility.

```ts
import featureAbility from '@ohos.ability.featureAbility';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';

const TAG: string = 'PageInterflowFaAndStage';

const domain: number = 0xFF00;

@Entry
@Component
struct PageInterflowFaAndStage {
  build() {
    Column() {
      //...
      List({ initialIndex: 0 }) {
        ListItem() {
          Row() {
            //...
          }
          .onClick(() => {
            let want: Want = {
              bundleName: 'ohos.samples.etsclock',
              abilityName: 'MainAbility'
            };
            featureAbility.startAbility({ want }).then((code) => {
              hilog.info(domain, TAG, 'Ability verify code: ' + JSON.stringify(code));
            }).catch((error: BusinessError) => {
              hilog.error(domain, TAG, 'Ability failed: ' + JSON.stringify(error));
            });
            //...
          })
        }
        //...
      }
      //...
    }
    //...
  }
}
```


## PageAbility Accessing a UIAbility (startAbilityForResult)

Different from **startAbility()**, **startAbilityForResult()** obtains the execution result when the UIAbility is destroyed.

A PageAbility starts a UIAbility through **startAbilityForResult()** in the same way as it starts another PageAbility through **startAbilityForResult()**.


```ts
import featureAbility from '@ohos.ability.featureAbility';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';

const TAG: string = 'PageInterflowFaAndStage';

const domain: number = 0xFF00;

@Entry
@Component
struct PageInterflowFaAndStage {
  build() {
    Column() {
      //...
      List({ initialIndex: 0 }) {
        ListItem() {
          Row() {
            //...
          }
          .onClick(() => {
            let want: Want = {
              bundleName: 'ohos.samples.etsclock',
              abilityName: 'MainAbility'
            };
            featureAbility.startAbilityForResult({ want }).then((result) => {
              hilog.info(domain, TAG, 'Ability verify result: ' + JSON.stringify(result));
            }).catch((error: BusinessError) => {
              hilog.error(domain, TAG, 'Ability failed: ' + JSON.stringify(error));
            });
          })
        }
        //...
      }
      //...
    }
    //...
  }
}
```


## ServiceAbility or DataAbility Starting a UIAbility

A ServiceAbility or DataAbility starts a UIAbility in the same way as it starts a PageAbility.


```ts
import type common from '@ohos.app.ability.common';
import particleAbility from '@ohos.ability.particleAbility';
import type Want from '@ohos.app.ability.Want';
import type { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';

const TAG: string = '[Sample_FAModelAbilityDevelop]';

const domain: number = 0xFF00;

class ServiceAbilityStartUiAbility {
  onStart(): void {
    // Start the UIAbility.
    let want: Want = {
      bundleName: 'ohos.samples.etsclock',
      abilityName: 'MainAbility'
    };
    particleAbility.startAbility({ want }).then(() => {
      hilog.info(domain, TAG, 'ServiceAbilityStartUIAbility Start Ability successfully.');
    }).catch((error: BusinessError) => {
      hilog.info(domain, TAG, 'ServiceAbilityStartUIAbility Ability failed: ' + JSON.stringify(error));
    });
  }
};

export default new ServiceAbilityStartUiAbility();
```
