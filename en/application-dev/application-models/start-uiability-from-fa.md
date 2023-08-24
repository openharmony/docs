# Starting a UIAbility from the FA Model


This topic describes how the three application components of the FA model start the UIAbility component of the stage model.


## PageAbility Starting a UIAbility

A PageAbility starts a UIAbility in the same way as it starts another PageAbility.

```ts
import featureAbility from '@ohos.ability.featureAbility';

let parameter = {
    "want": {
        bundleName: "com.ohos.stage",
        abilityName: "EntryAbility"
    }
};
featureAbility.startAbility(parameter).then((code) => {
    console.info('Ability verify code: ' + JSON.stringify(code));
}).catch((error) => {
    console.error("Ability failed: " + JSON.stringify(error));
});
```


## PageAbility Accessing a UIAbility (startAbilityForResult)

Different from **startAbility()**, **startAbilityForResult()** obtains the execution result when the UIAbility is destroyed.

A PageAbility starts a UIAbility through **startAbilityForResult()** in the same way as it starts another PageAbility through **startAbilityForResult()**.


```ts
import featureAbility from '@ohos.ability.featureAbility';

let parameter = {
    "want": {
        bundleName: "com.ohos.stage",
        abilityName: "com.ohos.stage.EntryAbility"
    }
};
featureAbility.startAbilityForResult(parameter).then((result) => {
    console.info('Ability verify result: ' + JSON.stringify(result));
}).catch((error) => {
    console.error("Ability failed: " + JSON.stringify(error));
});
```


## ServiceAbility or DataAbility Starting a UIAbility

A ServiceAbility or DataAbility starts a UIAbility in the same way as it starts a PageAbility.


```ts
import particleAbility from '@ohos.ability.particleAbility';

let parameter = {
    "want": {
        bundleName: "com.ohos.stage",
        abilityName: "com.ohos.stage.EntryAbility"
    }
};
particleAbility.startAbility(parameter).then(() => {
    console.info('Start Ability successfully.');
}).catch((error) => {
    console.error("Ability failed: " + JSON.stringify(error));
});
```
