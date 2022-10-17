# Ability Framework Development

## Is a guide similar to the Data ability development in the FA model available for the stage model?

Applicable to: OpenHarmony SDK 3.2.3.5, stage model of API version 9

A guide is available for the **DataShareExtensionAbility** class in the stage model, which provides APIs for sharing data with other applications and managing the data.

Reference: [DataShare Development](../database/database-datashare-guidelines.md)

## What should I do if the UI does not respond when an ability is started?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

1. If the ability is started using **startAbility**, check whether the **abilityName** field in **want** uses the bundle name as the prefix. If yes, delete the bundle name.

2. Make sure the ability's home page file configured by **onWindowStageCreate** in the **MainAbility.ts** file is defined in the **main_pages.json** file.

3. You are advised to use the SDK and OpenHarmony SDK versions released on the same day.

Reference: [Release Testing Version](https://gitee.com/openharmony-sig/oh-inner-release-management/blob/master/Release-Testing-Version.md)

## How do I prevent "this" in a method from changing to "undefined" when the method is called?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

Method 1: Add **.bind(this)** when calling the method.

Method 2: Use the arrow function.

## What should I do when the message "must have required property 'startWindowIcon'" is displayed?

Applicable to: OpenHarmony SDK 3.2.3.5, stage model of API version 9

Configure the **startWindowIcon** attribute under **abilities** in the **module.json5** file.

Reference: [Application Package Structure Configuration File](../quick-start/stage-structure.md)

  Example:

```
{
  "module": {
    // Do something.
    "abilities": [{
      // Do something.
      "startWindowIcon": "$media:space",
      "startWindowBackground": "$color:white",
    }]
  }
}
```

## How do I obtain a notification when the device orientation changes?

Applicable to: OpenHarmony SDK 3.2.3.5, stage model of API version 9

Implement the **onConfigurationUpdated** callback in the **Ability** class. The callback is triggered when the system language, color mode, or display parameters (such as the orientation and density) change.

Reference: [Ability Development](../ability/stage-ability.md)
