# Stage模型绑定FA模型ServiceAbility


本小节介绍Stage模型的两种应用组件如何绑定FA模型ServiceAbility组件。


## UIAbility关联访问ServiceAbility

UIAbility关联访问ServiceAbility和UIAbility关联访问ServiceExtensionAbility的方式完全相同。


```ts
import common from '@ohos.app.ability.common';
import hilog from '@ohos.hilog';
import promptAction from '@ohos.promptAction'
import Want from '@ohos.app.ability.Want';

const TAG: string = '[Page_StartFAModel]';
const DOMAIN_NUMBER: number = 0xFF00;

@Entry
@Component
struct Page_StartFAModel {
  private context = getContext(this) as common.UIAbilityContext;

  build() {
    Column() {
      // ...
      List({ initialIndex: 0 }) {
        // ...
        ListItem() {
          Row() {
            // ...
          }
          .onClick(() => {
            let want: Want = {
              bundleName: 'com.samples.famodelabilitydevelop',
              abilityName: 'com.samples.famodelabilitydevelop.ServiceAbility',
            }
            let options: common.ConnectOptions = {
              onConnect: (elementName, proxy) => {
                hilog.info(DOMAIN_NUMBER, TAG, 'onConnect called.');
                promptAction.showToast({
                  message: $r('app.string.ConnectFAServiceAbility')
                });
              },
              onDisconnect: (elementName) => {
                hilog.info(DOMAIN_NUMBER, TAG, 'onDisconnect called.');
              },
              onFailed: (code) => {
                hilog.info(DOMAIN_NUMBER, TAG, 'onFailed code is: ' + code);
              }
            };
            let connectionId = this.context.connectServiceExtensionAbility(want, options);
            hilog.info(DOMAIN_NUMBER, TAG, 'connectionId is ' + JSON.stringify(connectionId));
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


## ExtensionAbility关联访问ServiceAbility

下面以ServiceExtensionAbility为例来说明ExtensionAbility关联访问ServiceAbility。ServiceExtensionAbility关联访问ServiceAbility和ServiceExtensionAbility关联访问ServiceExtensionAbility的方式完全相同。


```ts
import common from '@ohos.app.ability.common';
import hilog from '@ohos.hilog';
import promptAction from '@ohos.promptAction'
import Want from '@ohos.app.ability.Want';

const TAG: string = '[Page_StartFAModel]';
const DOMAIN_NUMBER: number = 0xFF00;

@Entry
@Component
struct Page_StartFAModel {
  private context = getContext(this) as common.UIAbilityContext;

  build() {
    Column() {
      // ...
      List({ initialIndex: 0 }) {
        // ...
        ListItem() {
          Row() {
            // ...
          }
          .onClick(() => {
            let want: Want = {
              bundleName: 'com.samples.famodelabilitydevelop',
              abilityName: 'com.samples.famodelabilitydevelop.ServiceAbility',
            }
            let options: common.ConnectOptions = {
              onConnect: (elementName, proxy) => {
                hilog.info(DOMAIN_NUMBER, TAG, 'onConnect called.');
                promptAction.showToast({
                  message: $r('app.string.ConnectFAServiceAbility')
                });
              },
              onDisconnect: (elementName) => {
                hilog.info(DOMAIN_NUMBER, TAG, 'onDisconnect called.');
              },
              onFailed: (code) => {
                hilog.info(DOMAIN_NUMBER, TAG, 'onFailed code is: ' + code);
              }
            };
            let connectionId = this.context.connectServiceExtensionAbility(want, options);
            hilog.info(DOMAIN_NUMBER, TAG, 'connectionId is ' + JSON.stringify(connectionId));
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
