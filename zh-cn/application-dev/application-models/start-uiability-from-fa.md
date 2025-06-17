# FA模型启动Stage模型UIAbility


本文介绍FA模型的三种应用组件如何启动Stage模型的UIAbility组件。


## PageAbility启动UIAbility

  在PageAbility中启动UIAbility和在PageAbility中启动PageAbility的方式完全相同。

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
              hilog.info(domain, TAG, `Ability verify code: ${code}`);
            }).catch((error: BusinessError) => {
              hilog.error(domain, TAG, `Ability failed, error code: ${error.code}, error msg: ${error.message}.`);
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


## PageAbility访问UIAbility（startAbilityForResult）

startAbilityForResult和startAbility的区别是当UIAbility销毁的时候会返回执行结果。

在PageAbility中通过startAbilityForResult启动UIAbility和在PageAbility中通过startAbilityForResult启动PageAbility的方式完全相同。


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
              hilog.info(domain, TAG, `Ability verify result: ${JSON.stringify(result)}.`);
            }).catch((error: BusinessError) => {
              hilog.error(domain, TAG, `Ability failed, error code: ${error.code}, error msg: ${error.message}.`);
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


## ServiceAbility/DataAbility启动UIAbility

在ServiceAbility/DataAbility中启动UIAbility和在ServiceAbility/DataAbility中启动PageAbility的方式完全相同。


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
    // 启动UIAbility
    let want: Want = {
      bundleName: 'ohos.samples.etsclock',
      abilityName: 'MainAbility'
    };
    particleAbility.startAbility({ want }).then(() => {
      hilog.info(domain, TAG, `ServiceAbilityStartUIAbility Start Ability successfully.`);
    }).catch((error: BusinessError) => {
      hilog.error(domain, TAG, `ServiceAbilityStartUIAbility Ability failed, error code: ${error.code}, error msg: ${error.message}.`);
    });
  }
};

export default new ServiceAbilityStartUiAbility();
```
