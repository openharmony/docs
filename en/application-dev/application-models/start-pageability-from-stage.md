# Starting a PageAbility from the Stage Model


This topic describes how the two application components of the stage model start the PageAbility component of the FA model.


## UIAbility Starting a PageAbility

A UIAbility starts a PageAbility in the same way as it starts another UIAbility.

> **NOTE**
> 
> In the FA model, **abilityName** consists of **bundleName** and **AbilityName**. For details, see the code snippet below.

```ts
import { common, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = '[Page_StartFAModel]';
const DOMAIN_NUMBER: number = 0xFF00;

@Entry
@Component
struct Page_StartFAModel {
  private context = getContext(this) as common.UIAbilityContext;

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
              bundleName: 'com.samples.famodelabilitydevelop',
              abilityName: 'com.samples.famodelabilitydevelop.MainAbility'
            };
            this.context.startAbility(want).then(() => {
              hilog.info(DOMAIN_NUMBER, TAG, 'Start Ability successfully.');
            }).catch((error: BusinessError) => {
              hilog.error(DOMAIN_NUMBER, TAG, `Ability failed: ` + JSON.stringify(error));
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


## UIAbility Accessing a PageAbility (startAbilityForResult)

Different from **startAbility()**, **startAbilityForResult()** obtains the execution result when the PageAbility is destroyed.

A UIAbility starts a PageAbility through **startAbilityForResult()** in the same way as it starts another UIAbility.


```ts
import { common, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { promptAction } from '@kit.ArkUI';

const TAG: string = '[Page_StartFAModel]';
const DOMAIN_NUMBER: number = 0xFF00;

@Entry
@Component
struct Page_StartFAModel {
  private context = getContext(this) as common.UIAbilityContext;

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
              bundleName: 'com.samples.famodelabilitydevelop',
              abilityName: 'com.samples.famodelabilitydevelop.MainAbility',
            };
            this.context.startAbilityForResult(want).then((result) => {
              hilog.info(DOMAIN_NUMBER, TAG, 'Ability verify result: ' + JSON.stringify(result));
              if (result !== null) {
                promptAction.showToast({
                  message: JSON.stringify(result)
                });
              }
            }).catch((error: BusinessError) => {
              hilog.error(DOMAIN_NUMBER, TAG, `Ability failed: ` + JSON.stringify(error));
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


## ExtensionAbility Starting a PageAbility

The following uses the ServiceExtensionAbility component as an example to describe how an ExtensionAbility starts a PageAbility. A ServiceExtensionAbility starts a PageAbility in the same way as it starts a UIAbility.


```ts
import { Want, ServiceExtensionAbility } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { rpc } from '@kit.IPCKit';
import ServiceExtImpl from '../IdlServiceExt/idl_service_ext_impl';

const TAG: string = '[ServiceExtAbility]';
const DOMAIN_NUMBER: number = 0xFF00;

export default class ServiceExtAbility extends ServiceExtensionAbility {
  serviceExtImpl: ServiceExtImpl = new ServiceExtImpl('ExtImpl');

  onCreate(want: Want): void {
    let serviceExtensionContext = this.context;
    hilog.info(DOMAIN_NUMBER, TAG, `onCreate, want: ${want.abilityName}`);
  };

  onRequest(want: Want, startId: number): void {
    hilog.info(DOMAIN_NUMBER, TAG, `onRequest, want: ${want.abilityName}`);
    if (want.parameters?.key === 'ConnectFaPageAbility') {
      let wantFA: Want = {
        bundleName: 'com.samples.famodelabilitydevelop',
        abilityName: 'com.samples.famodelabilitydevelop.MainAbility',
      };
      this.context.startAbility(wantFA).then(() => {
        hilog.info(DOMAIN_NUMBER, TAG, 'Start Ability successfully.');
      }).catch((error: BusinessError) => {
        hilog.info(DOMAIN_NUMBER, TAG, `Ability failed: ${JSON.stringify(error)}`);
      });
    }
  };

  onConnect(want: Want): rpc.RemoteObject {
    hilog.info(DOMAIN_NUMBER, TAG, `onConnect, want: ${want.abilityName}`);
    // Return the ServiceExtImpl object, through which the client can communicate with the ServiceExtensionAbility.
    return this.serviceExtImpl as rpc.RemoteObject;
  };

  onDisconnect(want: Want): void {
    hilog.info(DOMAIN_NUMBER, TAG, `onDisconnect, want: ${want.abilityName}`);
  };

  onDestroy(): void {
    hilog.info(DOMAIN_NUMBER, TAG, 'onDestroy');
  };
}
```
