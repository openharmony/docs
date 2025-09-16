# Starting a ServiceAbility
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @xialiangwei-->
<!--Designer: @jsjzju-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->
<!--deprecated_code_no_check-->

A ServiceAbility is started in the same way other abilities. You can start a ServiceAbility by calling **featureAbility.startAbility()** in the PageAbility or calling **particleAbility.startAbility()** in another ServiceAbility. For details about the startup rules, see [Component Startup Rules](component-startup-rules.md).


The following example shows how to use **startAbility()** to start the ServiceAbility whose **bundleName** is **com.example.myapplication** and **abilityName** is **ServiceAbility** in a PageAbility. When starting the ServiceAbility, concatenate the **bundleName** string before **abilityName**.

```ts
import featureAbility from '@ohos.ability.featureAbility';
import Want from '@ohos.app.ability.Want';
import promptAction from '@ohos.promptAction';
import hilog from '@ohos.hilog';

const TAG: string = 'PageServiceAbility';
const domain: number = 0xFF00;

@Entry
@Component
struct PageServiceAbility {
  async startServiceAbility(): Promise<void> {
    try {
      hilog.info(domain, TAG, 'Begin to start ability');
      let want: Want = {
        bundleName: 'com.samples.famodelabilitydevelop',
        abilityName: 'com.samples.famodelabilitydevelop.ServiceAbility'
      };
      await featureAbility.startAbility({ want });
      promptAction.showToast({
        message: 'start_service_success_toast'
      });
      hilog.info(domain, TAG, `Start ability succeed`);
    } catch (error) {
      hilog.error(domain, TAG, 'Start ability failed with ' + error);
    }
  }
  build() {
    // ...
  }
}
```


In the preceding code, [startAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#startability) is used to start the ServiceAbility.


- If the ServiceAbility is not running, the system calls **onStart()** to initialize the ServiceAbility, and then calls **onCommand()** on the ServiceAbility.

- If the ServiceAbility is running, the system directly calls **onCommand()** on the ServiceAbility.
