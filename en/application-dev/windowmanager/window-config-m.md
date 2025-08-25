# Window Metadata Configuration
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @waterwin-->
<!--Designer: @nyankomiya-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

## metadata

The **metadata** tag represents custom metadata of a HAP. The tag value is an array and contains three subtags: **name**, **value**, and **resource**.

**Table 1** metadata tag description

| Subtag| Description| Data Type| Optional|
| -------- | -------- | -------- | -------- |
| name | Name of the data item. The value is a string with a maximum of 255 bytes.| String| Optional, defaults to an empty array|
| value | Value of the data item. The value is a string with a maximum of 255 bytes.| String| Optional, defaults to an empty array|
| resource | Custom data, which is a resource index. The value is a string with a maximum of 255 bytes. For example, **$profile:shortcuts_config** indicates that the data points to the **/resources/base/profile/shortcuts_config.json** file.| String| Optional, defaults to an empty array|

Below are several use cases and examples for the **metadata** tag. You can customize the settings based on service requirements.

1. Use the **metadata** tag to configure the default size and position (in vp) of the main window. The following **name** values are available this configuration:

    * **ohos.ability.window.height**: specifies the default height of the main window. **value** indicates the height.
    * **ohos.ability.window.width of name**: specifies the default width of the main window. **value** indicates the width.
    * **ohos.ability.window.left**: specifies the default left position of the main window. **value** indicates the configuration format: alignment mode +/- offset. The alignment mode can be **center**, **left**, or **right**. The default value is **left**. It can be omitted when the offset is **0**.
    * **ohos.ability.window.top**: specifies the default top position of the main window. **value** indicates the configuration format: alignment mode +/- offset. The alignment mode can be **center**, **top**, or **bottom**. The default value is **top**. If both the alignment mode and offset are omitted, the default stacking specifications are used.

2. Use the **metadata** tag to configure whether to remove the starting window. Set **name** to **enable.remove.starting.window**, and set **value** to **true** to remove the starting window, or to **false** to keep it. The default value is **false**.

3. Use the **metadata** tag to configure whether the main window is maximized upon startup. Set **name** to **ohos.ability.window.isMaximize**, and set **value** to **true** to maximize the main window upon startup, or to **false** to start in a non-maximized state. The default value is **false**. This configuration has the following restrictions:

    * The configuration takes effect only on PCs/2-in-1 devices.
    * If the **supportWindowModes** property in [startOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md) is used, the **FULL_SCREEN** option must be configured. In this case, the **metadata** tag can be used to configure the main window to start maximized; otherwise, it does not take effect.
    * If the **supportWindowMode** property in the [module.json5](abilities in../quick-start/module-configuration-file.md) file is used, the **fullscreen** option must be configured. In this case, the **metadata** tag can be used to configure the main window to start maximized; otherwise, it does not take effect.
    * The priorities of the main window display settings are as follows: full-screen display > using [startOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md) to specify the size and position > using [setWindowRectAutoSave()](../reference/apis-arkui/arkts-apis-window-WindowStage.md#setwindowrectautosave14) to enable window size memory > using the **metadata** tag to configure maximization > using the **metadata** tag to configure the size and position. You can configure full-screen display in any of the following ways:
        1. Set the **windowMode** property in [startOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md) to **WINDOW_MODE_FULLSCREEN**.
        2. Set the **supportWindowModes** property in [startOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md) only to **FULL_SCREEN**.
        3. Set the **supportWindowMode** property in [module.json5](../quick-start/module-configuration-file.md#abilities) only to **fullscreen**.

4. Use the **metadata** tag to configure the supported window modes in [free windows](https://developer.huawei.com/consumer/en/doc/design-guides/pad-0000001823654157#section1768267204717) mode. Set **name** to **ohos.ability.window.SupportWindowModeInFreeWindow**, and set **value** to **fullscreen** (full-screen mode), **split** (split-screen mode), **floating** (floating window mode), or any of their combinations (separated by commas, with no space), for example, **fullscreen,split**. This configuration takes effect only on tablets and PCs/2-in-1 devices.

   In free windows mode, the supported window modes can be configured using multiple methods. The configuration priorities are as follows: using [SetSupportedWindowModes](../reference/apis-arkui/arkts-apis-window-WindowStage.md#setsupportedwindowmodes15) to configure the window modes > using **StartAbility** to configure the **SupportWindowMode** property in [StartOption](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md#startoptions) > using the **metadata** tag to configure the window modes > configuring the **SupportWindowMode** property in the [abilities tag](../quick-start/module-configuration-file.md#abilities) of the **module.json5** file.

   In non-free windows mode, only the **SupportWindowMode** property in the **abilities** tag of the **module.json5** file can be used to configure the window modes. Other methods do not take effect.

<!--Del-->
5. Use the **metadata** tag to configure right-angle corners for the main window. Set **name** to **ohos.ability.window.isRightAngle**, and set **value** to **true** for right-angle corners, or to **false** for rounded corners. The default value is **false**. This configuration takes effect only for system applications on PCs/2-in-1 devices.<!--DelEnd-->


```json
{
  "module": {
    "abilities": [{
      "metadata": [{
        "name": "ability_metadata",
        "value": "a test demo for ability",
        "resource": "$profile:config_file"
      },
      {
        "name": "ability_metadata_2",
        "value": "a string test",
        "resource": "$profile:config_file"
      },
      {
        "name": "ohos.ability.window.height",
        "value": "987"
      },
      {
        "name": "ohos.ability.window.width",
        "value": "1300"
      },
      {
        "name": "ohos.ability.window.left",
        "value": "right-50"
      },
      {
        "name": "ohos.ability.window.top",
        "value": "center+50"
      },
      {
        "name": "ohos.ability.window.isMaximize",
        "value": "true"
      },
      {
        "name": "enable.remove.starting.window",
        "value": "true"
      }],
    }],

    "extensionAbilities": [{
      "metadata": [{
        "name": "extensionAbility_metadata",
        "value": "a test for extensionAbility",
        "resource": "$profile:config_file"
      },
      {
        "name": "extensionAbility_metadata_2",
        "value": "a string test",
        "resource": "$profile:config_file"
      },
      {
        "name": "ohos.ability.window.SupportWindowModeInFreeWindow",
        "value": "fullscreen,split,floating",
      }],
    }]
  }
}
```
