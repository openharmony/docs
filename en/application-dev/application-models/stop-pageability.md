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
import hilog from '@ohos.hilog';

const TAG: string = 'PagePageAbilityFirst';
const domain: number = 0xFF00;
```
```ts
//...
(async (): Promise<void> => {
  try {
    hilog.info(domain, TAG, 'Begin to terminateSelf');
    await featureAbility.terminateSelf();
    hilog.info(domain, TAG, 'terminateSelf succeed');
  } catch (error) {
    hilog.error(domain, TAG, 'terminateSelf failed with ' + error);
  }
})()
//...
```
