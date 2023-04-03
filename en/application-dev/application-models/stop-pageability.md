# Stopping a PageAbility


The **terminateSelf()** method in the **featureAbility** class is used to stop a PageAbility.

**Table 1** featureAbility APIs

| API| Description|
| -------- | -------- |
| terminateSelf() | Terminates this ability.|
| terminateSelfWithResult(parameter:&nbsp;AbilityResult) | Terminates this ability and returns the execution result.|


The following code snippet shows how to stop an ability.

```ts
import featureAbility from '@ohos.ability.featureAbility'

(async () => {
  try {
    console.info('Begin to terminateSelf')
    await featureAbility.terminateSelf()
    console.info('terminateSelf succeed')
  } 
  catch (error) {
    console.error('terminateSelf failed with ' + error)
  }
})()
```
