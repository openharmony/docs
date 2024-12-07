# Connecting to a ServiceAbility from the Stage Model


This topic describes how the two application components of the stage model connect to the ServiceAbility component of the FA model.


## UIAbility Accessing a ServiceAbility

A [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) accesses a ServiceAbility in the same way as it accesses a [ServiceExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-serviceExtensionAbility-sys.md).


```ts
import { common, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { promptAction } from '@kit.ArkUI';

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
            };
            let options: common.ConnectOptions = {
              onConnect: (elementName, proxy) => {
                hilog.info(DOMAIN_NUMBER, TAG, 'onConnect called.');
                promptAction.showToast({
                  message: 'ConnectFAServiceAbility'
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


## ExtensionAbility Accessing a ServiceAbility

The following uses the [ServiceExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-serviceExtensionAbility-sys.md) component as an example to describe how an [ExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-extensionAbility.md) accesses a ServiceAbility. A ServiceExtensionAbility accesses a ServiceAbility in the same way as it accesses another ServiceExtensionAbility.


```ts
import { common, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { promptAction } from '@kit.ArkUI';

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
            };
            let options: common.ConnectOptions = {
              onConnect: (elementName, proxy) => {
                hilog.info(DOMAIN_NUMBER, TAG, 'onConnect called.');
                promptAction.showToast({
                  message: 'ConnectFAServiceAbility'
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
