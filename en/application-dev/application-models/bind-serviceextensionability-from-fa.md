# Connecting to a ServiceExtensionAbility from the FA Model


This topic describes how the three application components of the FA model connect to the ServiceExtensionAbility component of the stage model.


## PageAbility Accessing a ServiceExtensionAbility

A PageAbility accesses a ServiceExtensionAbility in the same way as it accesses a ServiceAbility.


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
              hilog.info(domain, TAG, 'Ability verify code: ' + JSON.stringify(code));
            }).catch((error: BusinessError) => {
              hilog.error(domain, TAG, 'Ability failed: ' + JSON.stringify(error));
            });
            let serviceWant: Want = {
              bundleName: 'com.samples.stagemodelabilityinteraction',
              abilityName: 'ServiceExtAbility'
            };
            let faConnect: common.ConnectOptions = {
              onConnect: (elementName, proxy) => {
                hilog.info(domain, TAG, "FaConnection onConnect called.");
              },
              onDisconnect: (elementName) => {
                hilog.info(domain, TAG, "FaConnection onDisconnect called.");
              },
              onFailed: (code) => {
                hilog.info(domain, TAG, "FaConnection onFailed code is: " + code);
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


## ServiceAbility or DataAbility Accessing a ServiceExtensionAbility

A ServiceAbility or DataAbility accesses a ServiceExtensionAbility in the same way as it accesses a ServiceAbility.


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

    // Access the ServiceExtensionAbility.
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
    hilog.info(domain, TAG, 'ServiceAbilityStartUIAbility ServiceAbility onStart');
  }
};

export default new ServiceAbilityStartUiAbility();
```
