# Stopping a PageAbility


The **terminateSelf()** method in the **featureAbility** class is used to stop a PageAbility.

**Table 1** featureAbility APIs

| API| Description|
| -------- | -------- |
| terminateSelf() | Terminates this ability.|
| terminateSelfWithResult(parameter:&nbsp;AbilityResult) | Terminates this ability and returns the execution result.|


The following code snippet shows how to stop an ability.

```ts
import featureAbility from '@ohos.ability.featureAbility';
import Logger from '../../utils/Logger';

const TAG: string = 'PagePageAbilityFirst';
```
```ts
(async (): Promise<void> => {
  try {
    Logger.info(TAG, 'Begin to terminateSelf');
    await featureAbility.terminateSelf();
    Logger.info(TAG, 'terminateSelf succeed');
  } catch (error) {
    Logger.error(TAG, 'terminateSelf failed with ' + error);
  }
})()
```
