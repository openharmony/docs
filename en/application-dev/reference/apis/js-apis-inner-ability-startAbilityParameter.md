# StartAbilityParameter

The **StartAbilityParameter** module defines the parameters for starting an ability.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module can be used only in the FA model.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

| Name              |   Type  | Mandatory  | Description                                   |
| ------------------- | -------- | ---- | -------------------------------------- |
| want                | [Want](js-apis-application-want.md)|   Yes  | Information about the ability to start.                    |
| abilityStartSetting | {[key: string]: any} | No   | Special attribute of the ability to start. This attribute can be passed in the method call.|

**Example**
```ts
import featureAbility from '@ohos.ability.featureAbility'

let Want = {
    bundleName: "com.example.abilityStartSettingApp2",
    abilityName: "com.example.abilityStartSettingApp.MainAbility",
}

let abilityStartSetting ={
    [featureAbility.AbilityStartSetting.BOUNDS_KEY] : [100,200,300,400],
    [featureAbility.AbilityStartSetting.WINDOW_MODE_KEY] :
    featureAbility.AbilityWindowConfiguration.WINDOW_MODE_UNDEFINED,
    [featureAbility.AbilityStartSetting.DISPLAY_ID_KEY] : 1,
}

let startAbilityParameter = {
    want:Want,
    abilityStartSetting:abilityStartSetting
}

featureAbility.startAbility(startAbilityParameter, (err,data)=>{
    console.log('errCode : ' + JSON.stringify(err));
    console.log('data : ' + JSON.stringify(data));
} catch(error) {
    console.log("startAbility error: " + JSON.stringify(error));
}
```
