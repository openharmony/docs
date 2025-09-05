# FA模型绑定Stage模型ServiceExtensionAbility

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @wkljy-->
<!--Designer: @li-weifeng2024-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->


本文介绍[FA模型](ability-terminology.md#fa模型)的三种应用组件如何绑定[Stage模型](ability-terminology.md#stage模型)的ServiceExtensionAbility组件。


## PageAbility关联访问ServiceExtensionAbility

PageAbility关联访问ServiceExtensionAbility和PageAbility关联访问ServiceAbility的方式完全相同。


```ts
import featureAbility from '@ohos.ability.featureAbility';
import common from '@ohos.app.ability.common';
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
      // ...
      List({ initialIndex: 0 }) {
        ListItem() {
          Row() {
            // ...
          }
          .onClick(() => {
            let want: Want = {
              bundleName: 'ohos.samples.etsclock',
              abilityName: 'MainAbility'
            };
            featureAbility.startAbility({ want }).then((code) => {
              hilog.info(domain, TAG, `Ability verify code: ${JSON.stringify(code)}.`);
            }).catch((error: BusinessError) => {
              hilog.error(domain, TAG, `Ability failed, error msg: ${JSON.stringify(error)}.`);
            });
            let serviceWant: Want = {
              bundleName: 'com.samples.stagemodelabilityinteraction',
              abilityName: 'ServiceExtAbility'
            };
            let faConnect: common.ConnectOptions = {
              onConnect: (elementName, proxy) => {
                hilog.info(domain, TAG, `FaConnection onConnect called.`);
              },
              onDisconnect: (elementName) => {
                hilog.info(domain, TAG, `FaConnection onDisconnect called.`);
              },
              onFailed: (code) => {
                hilog.error(domain, TAG, `FaConnection onFailed code is: ${code}`);
              }
            };
            let connectionId = featureAbility.connectAbility(serviceWant, faConnect);
          })
        }
        // ...
      }
      // ...
    }
    // ...
  }
}
```


## ServiceAbility/DataAbility关联访问ServiceExtensionAbility

ServiceAbility/DataAbility关联访问ServiceExtensionAbility和ServiceAbility/DataAbility关联访问ServiceAbility的方式完全相同。


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
      hilog.error(domain, TAG, `ServiceAbilityStartUIAbility Ability failed: ${JSON.stringify(error)}.`);
    });

    // 访问ServiceExtensionAbility
    let serviceWant: Want = {
      bundleName: 'com.samples.stagemodelabilityinteraction',
      abilityName: 'ServiceExtAbility'
    };
    let faConnect: common.ConnectOptions = {
      onConnect: (elementName, proxy) => {
        hilog.info(domain, TAG, `FaConnection onConnect called.`);
      },
      onDisconnect: (elementName) => {
        hilog.info(domain, TAG, `FaConnection onDisconnect called.`);
      },
      onFailed: (code) => {
        hilog.error(domain, TAG, `FaConnection onFailed code is: ${code}.`);
      }
    };
    let connectionId = particleAbility.connectAbility(serviceWant, faConnect);
    hilog.info(domain, TAG, `ServiceAbilityStartUIAbility ServiceAbility onStart.`);
  }
};

export default new ServiceAbilityStartUiAbility();
```
