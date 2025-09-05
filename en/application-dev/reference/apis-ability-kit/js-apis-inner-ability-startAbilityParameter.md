# StartAbilityParameter

The module defines the parameters for starting an ability. The parameters can be used as input parameters in [startAbility](js-apis-ability-featureAbility.md#featureabilitystartability) to start the specified ability.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> The APIs of this module can be used only in the FA model.

## Modules to Import

```ts
import ability from '@ohos.ability.ability';
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

| Name              |   Type  | Mandatory  | Description                                   |
| ------------------- | -------- | ---- | -------------------------------------- |
| want                | [Want](js-apis-app-ability-want.md)|   Yes  | Want information about the target ability.                    |
| abilityStartSetting | { [key: string]: any } | No   | Special attribute of the target ability. This attribute can be passed in the call.|
| abilityStartSettings<sup>11+<sup> | Record\<string, Object> | No   | Special attribute of the target ability. This attribute can be passed in the call. You are advised to use this attribute to replace **abilityStartSetting**. When this attribute is set, **abilityStartSetting** does not take effect.|

**Example**

<!--code_no_check_fa-->
```ts
import ability from '@ohos.ability.ability';
import featureAbility from '@ohos.ability.featureAbility';
import Want from '@ohos.app.ability.Want';

let want: Want = {
    bundleName: 'com.example.abilityStartSettingApp2',
    abilityName: 'com.example.abilityStartSettingApp.EntryAbility',
};

let startAbilityParameter: ability.StartAbilityParameter = {
    want : want,
    abilityStartSettings : {
        abilityBounds : [100,200,300,400],
        windowMode :
        featureAbility.AbilityWindowConfiguration.WINDOW_MODE_UNDEFINED,
        displayId : 1,
    }
};

try {
    featureAbility.startAbility(startAbilityParameter, (error, data) => {
        if (error && error.code !== 0) {
            console.error(`startAbility fail, error: ${JSON.stringify(error)}`);
        } else {
            console.log(`startAbility success, data: ${JSON.stringify(data)}`);
        }
    });
} catch(error) {
    console.error(`startAbility error: ${JSON.stringify(error)}`);
}
```
