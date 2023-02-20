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
(async () => {
  try {
    console.info('Begin to start ability')
    let param = {
      want: {
        bundleName: "com.example.myapplication",
        moduleName: "entry",
        abilityName: "com.example.myapplication.EntryAbility"
      }
    }
    await featureAbility.startAbility(param)
    console.info(`Start ability succeed`)
  } 
  catch (error) {
    console.error('Start ability failed with ' + error)
  }
})()
```
