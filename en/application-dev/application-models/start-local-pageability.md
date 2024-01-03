# Starting a Local PageAbility


The capabilities related to the PageAbility are provided through the **featureAbility** class. For example, **startAbility()** in **featureAbility** is used to the PageAbility.

**Table 1** featureAbility APIs

| API| Description|
| -------- | -------- |
| startAbility(parameter:&nbsp;StartAbilityParameter) | Starts an ability.|
| startAbilityForResult(parameter:&nbsp;StartAbilityParameter) | Starts an ability and returns the execution result when the ability is terminated.|


The following code snippet shows how to explicitly start a PageAbility through **startAbility()**. The parameters passed in for starting an ability include **want**. For details about the **want** parameter as well as implicit startup and explicit startup, see [Want](want-fa.md).

```ts
import featureAbility from '@ohos.ability.featureAbility'
import Want from '@ohos.app.ability.Want';
```
```ts
(async (): Promise<void> => {
  try {
    Logger.info(TAG, 'Begin to start ability');
    let want: Want = {
      bundleName: 'com.samples.famodelabilitydevelop',
      moduleName: 'entry',
      abilityName: 'com.samples.famodelabilitydevelop.PageAbilitySingleton'
    };
    await featureAbility.startAbility({ want: want });
    Logger.info(TAG, `Start ability succeed`);
  }
  catch (error) {
    Logger.error(TAG, 'Start ability failed with ' + error);
  }
})()
```
