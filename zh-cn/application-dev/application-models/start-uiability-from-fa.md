# FA模型启动Stage模型UIAbility


本文介绍FA模型的三种应用组件如何启动Stage模型的UIAbility组件。


## PageAbility启动UIAbility

  在PageAbility中启动UIAbility和在PageAbility中启动PageAbility的方式完全相同。

```ts
import featureAbility from '@ohos.ability.featureAbility';
import { BusinessError } from '@ohos.base';

featureAbility.startAbility(
    {
        want: {
            bundleName: "com.ohos.stage",
            abilityName: "EntryAbility"
        }
    }
).then((code) => {
    console.info('Ability verify code: ' + JSON.stringify(code));
}).catch((error: BusinessError) => {
    console.error("Ability failed: " + JSON.stringify(error));
});
```


## PageAbility访问UIAbility（startAbilityForResult）

startAbilityForResult和startAbility的区别是当UIAbility销毁的时候会返回执行结果。

在PageAbility中通过startAbilityForResult启动UIAbility和在PageAbility中通过startAbilityForResult启动PageAbility的方式完全相同。


```ts
import featureAbility from '@ohos.ability.featureAbility';
import { BusinessError } from '@ohos.base';

featureAbility.startAbilityForResult(
    {
        want: {
            bundleName: "com.ohos.stage",
            abilityName: "com.ohos.stage.EntryAbility"
        }
    }).then((result) => {
    console.info('Ability verify result: ' + JSON.stringify(result));
}).catch((error: BusinessError) => {
    console.error("Ability failed: " + JSON.stringify(error));
});
```


## ServiceAbility/DataAbility启动UIAbility

在ServiceAbility/DataAbility中启动UIAbility和在ServiceAbility/DataAbility中启动PageAbility的方式完全相同。


```ts
import particleAbility from '@ohos.ability.particleAbility';
import { BusinessError } from '@ohos.base';

particleAbility.startAbility(
    {
        want: {
            bundleName: "com.ohos.stage",
            abilityName: "com.ohos.stage.EntryAbility"
        }
    }
).then(() => {
    console.info('Start Ability successfully.');
}).catch((error: BusinessError) => {
    console.error("Ability failed: " + JSON.stringify(error));
});
```
