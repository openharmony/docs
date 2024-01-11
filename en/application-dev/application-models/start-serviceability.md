# Starting a ServiceAbility


A ServiceAbility is started in the same way other abilities. You can start a ServiceAbility by calling **featureAbility.startAbility()** in the PageAbility or calling **particleAbility.startAbility()** in another ServiceAbility. For details about the startup rules, see [Component Startup Rules](component-startup-rules.md).


The following example shows how to use **startAbility()** to start the ServiceAbility whose **bundleName** is **com.example.myapplication** and **abilityName** is **ServiceAbility** in a PageAbility. When starting the ServiceAbility, concatenate the **bundleName** string before **abilityName**.

```ts
import featureAbility from '@ohos.ability.featureAbility'
import Want from '@ohos.app.ability.Want';
import promptAction from '@ohos.promptAction';
```
```ts
async startServiceAbility(): Promise<void> {
  try {
    Logger.info(TAG, 'Begin to start ability');
    let want: Want = {
      bundleName: 'com.samples.famodelabilitydevelop',
      abilityName: 'com.samples.famodelabilitydevelop.ServiceAbility'
    };
    await featureAbility.startAbility({ want });
    promptAction.showToast({
      message: $r('app.string.start_service_success_toast')
    });
    Logger.info(TAG, `Start ability succeed`);
  } catch (error) {
    Logger.error(TAG, 'Start ability failed with ' + error);
  }
}
```


In the preceding code, [startAbility()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability) is used to start the ServiceAbility.


- If the ServiceAbility is not running, the system calls **onStart()** to initialize the ServiceAbility, and then calls **onCommand()** on the ServiceAbility.

- If the ServiceAbility is running, the system directly calls **onCommand()** on the ServiceAbility.
