# Stage模型启动FA模型PageAbility


本小节介绍Stage模型的两种应用组件如何启动FA模型的PageAbility组件。


## UIAbility启动PageAbility

  UIAbility启动PageAbility和UIAbility启动UIAbility的方式完全相同。

> **说明：**
> 需注意FA模型中abilityName由bundleName + AbilityName组成，具体见示例。

```ts
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import hilog from '@ohos.hilog';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

const TAG: string = '[EntryAbility]';
const DOMAIN_NUMBER: number = 0xFF00;

@Entry
@Component
struct Index {
  private context = getContext(this) as common.UIAbilityContext;

  build() {
    Button('StartFAModel'){
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
  }
  
  // ...
}
```


## UIAbility访问PageAbility（startAbilityForResult）

startAbilityForResult和startAbility的区别是当PageAbility销毁的时候会返回执行结果。

UIAbility通过startAbilityForResult启动PageABility和UIAbility通过startAbilityForResult启动UIAbility的代码一样，没有任何区别。


```ts
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import hilog from '@ohos.hilog';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

const TAG: string = '[EntryAbility]';
const DOMAIN_NUMBER: number = 0xFF00;

@Entry
@Component
struct Index {
  private context = getContext(this) as common.UIAbilityContext;

  build() {
    Button('StartFAModelWithResult'){
      .onClick(() => {
        let context: common.UIAbilityContext = getContext(this) as common.UIAbilityContext; // UIAbilityContext
        let want: Want = {
          bundleName: 'com.samples.stagemodelabilitydevelop',
          abilityName: 'LifecycleAbility',
        };
        // context为调用方UIAbility的UIAbilityContext
        context.startAbility(want).then(() => {
          hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded in starting LifecycleAbility.');
        }).catch((err: BusinessError) => {
          hilog.error(DOMAIN_NUMBER, TAG, `Failed to start LifecycleAbility. Code is ${err.code}, message is ${err.message}`);
        });
      })
    }
  }
  
  // ...
}
```


## ExtensionAbility启动PageAbility

下面以ServiceExtensionAbility为例来说明ExtensionAbility启动PageAbility。ServiceExtensionAbility启动PageAbility和ServiceExtensionAbility启动UIAbility的方式完全相同。


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
