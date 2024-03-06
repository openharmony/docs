# Starting a PageAbility from the Stage Model


This topic describes how the two application components of the stage model start the PageAbility component of the FA model.


## UIAbility Starting a PageAbility

A UIAbility starts a PageAbility in the same way as it starts another UIAbility.

> **NOTE**
> 
> In the FA model, **abilityName** consists of **bundleName** and **AbilityName**. For details, see the code snippet below.

```ts
import common from '@ohos.app.ability.common';
import hilog from '@ohos.hilog';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
import common from '@ohos.app.ability.common';

const TAG: string = '[EntryAbility]';
const DOMAIN_NUMBER: number = 0xFF00;

@Entry
@Component
struct Index {
  private context = getContext(this) as common.UIAbilityContext;

  build() {
    Button('StartFAModel')
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
  
  // ...
}
```


## UIAbility Accessing a PageAbility (startAbilityForResult)

Different from **startAbility()**, **startAbilityForResult()** obtains the execution result when the PageAbility is destroyed.

A UIAbility starts a PageAbility through **startAbilityForResult()** in the same way as it starts another UIAbility through **startAbilityForResult()**.


```ts
import common from '@ohos.app.ability.common';
import hilog from '@ohos.hilog';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
import common from '@ohos.app.ability.common';

const TAG: string = '[EntryAbility]';
const DOMAIN_NUMBER: number = 0xFF00;

@Entry
@Component
struct Index {
  private context = getContext(this) as common.UIAbilityContext;

  build() {
    Button('StartFAModelWithResult')
      .onClick(() => {
        let want: Want = {
          bundleName: 'com.samples.stagemodelabilitydevelop',
          abilityName: 'LifecycleAbility',
        };
        // context is the UIAbilityContext of the initiator UIAbility.
        this.context.startAbility(want).then(() => {
          hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded in starting LifecycleAbility.');
        }).catch((err: BusinessError) => {
          hilog.error(DOMAIN_NUMBER, TAG, `Failed to start LifecycleAbility. Code is ${err.code}, message is ${err.message}`);
        });
      })
  }

  // ...
}
```


## ExtensionAbility Starting a PageAbility

The following uses the ServiceExtensionAbility component as an example to describe how an ExtensionAbility starts a PageAbility. A ServiceExtensionAbility starts a PageAbility in the same way as it starts a UIAbility.


```ts
import Extension from '@ohos.app.ability.ServiceExtensionAbility'
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

export default class ServiceExtension extends Extension {
    onCreate(want: Want) {
        console.info("ServiceExtension onCreate")
    }
    onDestroy() {
        console.info("ServiceExtension onDestroy")
    }
    onRequest(want: Want, startId: number) {
        console.info("ServiceExtension onRequest")
        let wantFA: Want = {
            bundleName: "com.ohos.fa",
            abilityName: "EntryAbility",
        };
        this.context.startAbility(wantFA).then(() => {
            console.info('Start Ability successfully.');
        }).catch((error: BusinessError) => {
            console.error("Ability failed: " + JSON.stringify(error));
        });
    }
}
```
