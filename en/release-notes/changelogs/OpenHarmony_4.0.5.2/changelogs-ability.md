# Ability Framework Changelog

## Added the saveAppState API to cl.ability.appRecovery

The API **saveAppState (context?: UIAbilityContext): boolean;** is added.

**Change Impact**

When developing an application based on OpenHarmony 4.0.5.2 or a later SDK version, you can use **saveAppState** with the ability context specified to save the state of the specified ability.

**Key API/Component Changes**

The **saveAppState** API is added to the **@ohos.app.ability.appRecovery.d.ts** file.

| Module| Class| Method/Attribute/Enum/Constant| Change Type|
|  -- | -- | -- | -- |
| @ohos.app.ability.appRecovery.d.ts | appRecovery | saveAppState(context?: UIAbilityContext): boolean; | Added|

**Adaptation Guide**

Call **saveAppState** with the UIAbility context specified to save the ability state.

```ts
import appRecovery from '@ohos.app.ability.appRecovery';
onBackground() {
    hilog.info(0x0000, '[demo]', '%{public}s', 'EntryAbility onBackground');
    appRecovery.saveAppState(this.context)
}
```
## Added the setRestartWant API to cl.ability.appRecovery.

The API **setRestartWant (want: Want): void;** is added.

**Change Impact**

To develop an application based on OpenHarmony 4.0.5.2 or a later SDK version, you can use **setRestartWant** to set the ability to recover.

**Key API/Component Changes**

The **setRestartWant** API is added to the **@ohos.app.ability.appRecovery.d.ts** file.

| Module| Class| Method/Attribute/Enum/Constant| Change Type|
|  -- | -- | -- | -- |
| @ohos.app.ability.appRecovery.d.ts | appRecovery | setRestartWant(want: Want): void; | Added|

**Adaptation Guide**

Call **setRestartWant** to set the ability to recover.

```ts
import appRecovery from '@ohos.app.ability.appRecovery';
Button ("Start to Recover Ability")
    .fontSize(40)
    .fontWeight(FontWeight.Bold)
    .onClick(()=> {
        // set restart want
        let want = {
            bundleName: "ohos.samples.recovery",
            abilityName: "RecoveryAbility"
        };

        appRecovery.setRestartWant(want);
    })
```
