# Configuring ArkTS Widget Configuration Files

<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @Qian-Win-->
<!--Designer: @cx983299475-->
<!--Tester: @mahailong123456-->
<!--Adviser: @HelloShuo-->
<!-- md-trans-meta sourceCommit=6d7419f1dd9729a9ceaeb24a3a1f1c514f7b60b3 translatedAt=2026-08-15T01:50:17.171Z pushedAt=2026-08-15T07:56:26.479Z -->

Widget-related configuration files include the [FormExtensionAbility](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md) configuration and the widget configuration. For [standalone widget packages](./arkts-ui-widget-creation.md#method-2-creating-a-standalone-package), the [standalone widget package configuration](./arkts-ui-widget-configuration.md#standalone-widget-package-configuration) is also included.
> **NOTE**
>
>- The widget quintuple is the set of elements that uniquely identify a widget. The quintuple consists of `bundleName`, `moduleName`, `abilityName`, `formName`, and `formDimension`. Specifically, `bundleName` corresponds to the `bundleName` configuration item in the [app.json5 configuration file tags](../quick-start/app-configuration-file.md#tags-in-the-configuration-file), `moduleName` corresponds to the `name` configuration item in the [module.json5 configuration file tags](../quick-start/module-configuration-file.md#tags-in-the-configuration-file), `abilityName` corresponds to the `name` configuration item in the [abilities tag](../quick-start/module-configuration-file.md#abilities), `formName` corresponds to the `name` configuration item in [fields in the configuration file](#fields-in-configuration-file), and `formDimension` corresponds to the `supportDimensions` configuration item in [fields in the configuration file](#fields-in-configuration-file).
>- It is not recommended to use resource file imports for the quintuple. When resource files are used for import, any addition of fields in the resource file will cause the corresponding IDs to change, which will be considered a change in the quintuple.
>- If the quintuple changes after an app upgrade, the corresponding widget in the system will be deleted and will disappear from the screen.

## FormExtensionAbility Configuration

Configure `FormExtensionAbility` information under `extensionAbilities` in the [module.json5 file](../quick-start/module-configuration-file.md). For `FormExtensionAbility`, you must specify `metadata`. Specifically, set **name** to **ohos.extension.form** (fixed), and set **resource** to the [index of the widget configuration information](#widget-configuration).

   Example:

  <!-- @[module_config_formCreate](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Form/FormStandaloneDemo/entry/src/main/module.json5) --> 

  ``` JSON5
  {
    "module": {
      // ...
      "extensionAbilities": [
        {
          "name": "EntryFormAbility",
          "srcEntry": "./ets/entryformability/EntryFormAbility.ets",
          "label": "$string:EntryFormAbility_label",
          "description": "$string:EntryFormAbility_desc",
          "type": "form",
          "metadata": [
            {
              "name": "ohos.extension.form",
              "resource": "$profile:form_config"
            }
          ]
        }
      ],
      // This configuration is only applicable to the standalone widget package form and is used to associate the corresponding widget package module.
      "formWidgetModule": "library"
    }
  }
  ```

## Standalone Widget Package Configuration

In the [module.json5 file](../quick-start/module-configuration-file.md) of a widget package, the `formExtensionModule` field is used to associate with the `module` of the application bundle.<br>
Example:

<!-- @[standalone_config](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Form/FormStandaloneDemo/library/src/main/module.json5) --> 

``` JSON5
{
  "module": {
    "name": "library",
    "type": "shared",
    "description": "$string:shared_desc",
    "deviceTypes": [
      "phone"
    ],
    "deliveryWithInstall": true,
    // This configuration is only applicable to the standalone widget package form and is used to associate the corresponding application bundle module.
    "formExtensionModule": "entry"
  }
}
```

## Widget Configuration

In the **metadata** configuration item of FormExtensionAbility, you can specify the resource index of specific configuration information of the widget. For example, if **resource** is set to **$profile:form_config**, **form_config.json** in the **resources/base/profile/** directory of the development view is used as the profile configuration file of the widget. The **form_config.json** configuration file is automatically generated when you [create a widget](./arkts-ui-widget-creation.md).

### Fields in Configuration File

**Table 1** form_config.json file

| Name | Description | Type | Mandatory |
| -------- | -------- | -------- | -------- |
| forms | All widget configuration information of the app.<br/>A maximum of 16 widgets can be configured. If more than 16 are configured, only the first 16 are retained. | Array | No |
| name | Name of the widget, with a maximum string length of 127 bytes. Used by developers to distinguish different widgets.<br/>**Note:**<br/>It is not recommended to reference resource files for this field. | String | No |
| displayName | Display name of the widget. It is mainly displayed on the widget management page, corresponding to <!--RP3-->"ArkTSCard"<!--RP3End--> in the widget preview [widget management page](./formkit-overview.md#scenarios-for-widget-usage), and is used to present widget information. It is recommended that the name reflect the core function or purpose of the widget. Supports a string or a string resource index. Using a string resource index is recommended to support full multi-language capabilities. The minimum string length is 1 byte and the maximum is 30 bytes. | String | No |
| description | Description of the widget. It is used to display the widget function description on the widget management page, corresponding to <!--RP4-->"This is a ArkTS card game by canvas."<!--RP4End--> in the widget preview [widget management page](./formkit-overview.md#scenarios-for-widget-usage). Supports a string or a string resource index. Using a string resource index is recommended to support full multi-language capabilities. The maximum string length is 255 bytes. | String | Yes, default is empty. |
| src | Full path to the UI code corresponding to the widget. For an ArkTS widget, the full path must include the widget file extension, for example: "./ets/widget/pages/WidgetCard.ets". For a JS widget, the full path does not need to include the widget file extension, for example: "./js/widget/pages/WidgetCard". | String | No |
| uiSyntax | Type of the widget. The following two types are supported:<br/>-&nbsp;arkts: The widget is an ArkTS widget.<br/>-&nbsp;hml: The widget is a JS widget. | String | Yes, default value is "hml". |
| window | Used to define configurations related to the display window.<br/>**Note:**<br/>This field takes effect only for JS widgets. | Object | Yes. For default values, refer to the [window Field](#window-field) table. |
| isDefault | Whether the widget is the default widget (the widget that is preferentially displayed in the widget center). Each app has exactly one default widget.<br/>-&nbsp;true: Default widget.<br/>-&nbsp;false: Non-default widget.<br/>**Note:**<br/>When an app is released, only one default widget is allowed per app. | Boolean | No |
| colorMode<sup>(deprecated)</sup> | Theme style of the widget. The value range is as follows:<br/>-&nbsp;auto: The theme is selected based on the system color mode.<br/>-&nbsp;dark: Dark theme.<br/>-&nbsp;light: Light theme.<br/>**Note:**<br/>1. This configuration item is supported since API version 12 and deprecated since API version 20. The widget theme style now uniformly follows the system color mode.<br/>2. This field takes effect only for JS widgets. | String | Yes, default value is "auto". |
| supportDimensions | Supported appearance specifications of the widget. The value range is as follows:<!--RP5--><!--RP5End--><br/>-&nbsp;1&nbsp;\*&nbsp;2: 1-row 2-column, two-grid.<br/>-&nbsp;2&nbsp;\*&nbsp;2: 2-row 2-column, four-grid.<br/>-&nbsp;2&nbsp;\*&nbsp;4: 2-row 4-column, eight-grid.<br/>-&nbsp;2&nbsp;\*&nbsp;3: 2-row 3-column, six-grid.<br/>-&nbsp;3&nbsp;\*&nbsp;3: 3-row 3-column, nine-grid.<br/>-&nbsp;4&nbsp;\*&nbsp;4: 4-row 4-column, sixteen-grid.<br/>-&nbsp;6&nbsp;\*&nbsp;4: 6-row 4-column, twenty-four-grid.<br>**Note:** For device-specific support, refer to the [supportDimensions Field and Device Support Relationship Table](#supportdimensions-field-and-device-support-relationship-table). | String array | No |
| defaultDimension | Default size of the widget. The value must be in the supportDimensions configuration list of the widget. | String | No |
| updateEnabled | Whether the widget supports periodic refresh (including timed refresh and scheduled refresh). The value range is as follows:<br/>-&nbsp;true: Periodic refresh is supported. Either timed refresh (updateDuration) or scheduled refresh (scheduledUpdateTime) can be selected. When both are configured, timed refresh takes effect preferentially.<br/>-&nbsp;false: Periodic refresh is not supported. | Boolean | No |
| scheduledUpdateTime | Scheduled time for [scheduled widget refresh](./arkts-ui-widget-passive-refresh.md#time-specific-update), in 24-hour format, accurate to the minute, for example: "10:30".<br/>**Note:**<br/>The updateDuration parameter has a higher priority than scheduledUpdateTime. When both are configured, the refresh time configured by updateDuration prevails. | String | Yes, default value is "0:0". No scheduled refresh is performed by default. |
| updateDuration | Update interval for [timed widget refresh](./arkts-ui-widget-passive-refresh.md#interval-based-update), in units of 30 minutes. The value is a natural number.<br/>When the value is 0, this parameter does not take effect.<br/>When the value is a positive integer N, the refresh interval is 30\*N minutes.<br/>**Note:**<br/>The updateDuration parameter has a higher priority than scheduledUpdateTime. When both are configured, the refresh time configured by updateDuration prevails. | Number | Yes, default value is 0. |
| formConfigAbility | Ability path to be launched after tapping Edit on the home screen, in URI format. | String | Yes, default is empty. |
| metadata | Custom information of the widget. For details, refer to [Metadata](../reference/apis-ability-kit/js-apis-bundleManager-metadata.md) array tag. | Object | Yes, default is empty. |
| dataProxyEnabled | Whether the widget supports proxy refresh. The value range is as follows:<br/>-&nbsp;true: Proxy refresh is supported.<br/>-&nbsp;false: Proxy refresh is not supported.<br/>When set to true, [timed refresh and next refresh](./arkts-ui-widget-passive-refresh.md#interval-based-update) do not take effect, but [scheduled refresh](./arkts-ui-widget-passive-refresh.md#time-specific-update) is not affected.<br/>**Note:**<br/>This field is supported since API version 12. | Boolean | Yes, default value is false. |
| isDynamic | Whether this widget is a dynamic widget (takes effect only for ArkTS widgets).<br/>-&nbsp;true: [Dynamic widget](./arkts-form-overview.md#dynamic-widget).<br/>-&nbsp;false: [Static widget](./arkts-form-overview.md#static-widget).<br/>| Boolean | Yes, default value is true. |
| fontScaleFollowSystem | Whether the font of this widget set by the widget user supports following system changes.<br/>-&nbsp;true: Following system font size changes is supported.<br/>-&nbsp;false: Following system font size changes is not supported.<br/>| Boolean | Yes, default value is true. |
| supportShapes | Display shapes of the widget. The value range is as follows:<br/>-&nbsp;rect: Rectangular widget.<br/>-&nbsp;circle: Circular widget. | String array | Yes, default value: ["rect"]. |
| previewImages | Widget preview images, corresponding one-to-one with the `supportDimensions` configuration items. This must be configured for smart wearable widgets and is currently supported only on smart wearables. | String array | Yes, default value: []. |
| <!--DelRow-->formVisibleNotify | Whether to notify the widget provider of visibility state changes (takes effect only for widgets of system apps).<br/>-&nbsp;true: Notify the widget provider of visibility state changes.<br/>-&nbsp;false: Do not notify the widget provider of visibility state changes. | Boolean | Yes, default value is false. |
| transparencyEnabled | Whether the widget is a transparent-background widget (takes effect only for system apps or ArkTS widgets that have applied for the transparent-background widget capability).<br/>-&nbsp;true: Transparent-background widget.<br/>-&nbsp;false: Non-transparent-background widget.<br/>| Boolean | Yes, default value is false. |
|enableBlurBackground|Whether the widget uses a blurred background.<br/>-&nbsp;true: Blurred background enabled.<br/>-&nbsp;false: Blurred background disabled.<br/>**Note:**<br/>This feature has high requirements on product power consumption and performance. Starting from API version 23, it is supported only on flagship models. Calling it on unsupported models has no effect.|Boolean|Yes, default value is false.|
|renderingMode|Rendering mode of the widget. The value range is as follows:<br/>-&nbsp;autoColor: Automatic mode. The rendering effect can be determined by the widget user as either full-color mode or single-color mode<!--RP7--><!--RP7End-->. In this mode, the colors and images in the widget can be modified by the widget user. A widget configured with this mode can be added to the home screen or lock screen.<br/>-&nbsp;fullColor: Full-color mode<!--RP7--><!--RP7End-->. In this mode, the colors and images in the widget cannot be modified by the widget user. A widget configured with this mode can be added to the home screen.<br/>-&nbsp;singleColor: Single-color mode, which uses transparency and blur to distinguish elements without using any hue<!--RP7--><!--RP7End-->. In this mode, the colors and images in the widget can be modified by the widget user. A widget configured with this mode can be added to the lock screen.<br/>**Note:**<br/>This field is supported since API version 15.|String|Yes, default value is "fullColor".|
|multiScheduledUpdateTime|Multiple scheduled refresh times of the widget, as an additional parameter for single-point refresh, in 24-hour format, accurate to the minute. Multiple times are separated by commas, with a maximum of 24 times, for example, "10:30,10:50,11:00".<br/>**Note:**<br/>This field is supported since API version 18. multiScheduledUpdateTime must be used together with scheduledUpdateTime.|String|Yes, no multi-scheduled refresh is performed by default.|
|conditionUpdate|Conditional refresh supported by the widget. The currently supported values are as follows:<br/>-&nbsp;network: Network refresh is supported.<br/>**Note:**<br/>This field configuration is supported since API version 18<!--Del-->, and the feature is supported only for system apps<!--DelEnd-->. Starting from API version 26.0.0, the feature takes effect after configuration.|String array|Yes, default value is an empty string array.|
|[funInteractionParams](#funinteractionparams-field)|Extended field for fun interaction type interactive widgets.<br/>**Note:**<br/>This field is supported since API version 20.|Object|Yes, default is empty. When both funInteractionParams and sceneAnimationParams are configured, the widget is identified as a fun interaction type interactive widget.|
|[sceneAnimationParams](#sceneanimationparams-field)|Extended field for [scene-based interactive widgets](./arkts-ui-liveform-sceneanimation-development.md). This field is supported since API version 20.|Object|Yes, default is empty. When both funInteractionParams and sceneAnimationParams are configured, the widget is identified as a fun interaction type interactive widget.|
| resizable | Whether the widget can be resized by dragging. The adjusted value must be in the supportDimensions configuration list of this widget or widgets with the same groupId.<br/>-&nbsp;true: Resizing is supported.<br/>-&nbsp;false: Resizing is not supported.<br/>**Note:**<br/>This field is supported since API version 20.| Boolean | Yes, default value is false. |
| groupId | Common ID of a group of widgets. When multiple widgets have the same groupId and resizable is true, the supportDimensions configurations of the multiple widgets are shared. This is recommended when multiple widgets have the same function and widget size adjustment is needed.<br>Example 1: Widget A has groupId configured as '1', resizable configured as true, and supportDimension as 2\*2. Widget B has groupId configured as '1', resizable configured as true, and supportDimension as 2\*4. In this case, resizing between widgets A and B is supported.<br>Example 2: When supportDimension has multiple values and resizable is set to true, resizing within the same widget takes priority. Widget A has resizable configured as true and supportDimension as 2\*2 and 2\*4. Resizing between the two sizes of widget A is supported.<br>Example 3: Widget A has groupId configured as '1', resizable configured as true, and supportDimension as 1\*2. Widget B has groupId configured as '1', resizable configured as true, and supportDimension as 2\*2, 2\*4, and 4\*4. Widget A can be resized to the default size of widget B, but widget B only supports resizing among the three sizes supported by widget B and cannot be resized to widget A.<br/>**Note:**<br/>This field is supported since API version 20.| String | Yes, empty string. |
| [supportDeviceTypes](#supportdevicetypes-field) | Device types supported by a specific widget. For example, if the supportDeviceTypes field of a widget is configured with "phone", "tablet", and "tv", the widget can be displayed on phones, tablets, and large screens.<br/>**Note:**<br/>This field is supported since API version 22.| String array | Yes, default value: ["phone", "tablet", "tv", "wearable", "car", "2in1"]. |
| [supportDevicePerformanceClasses](#supportdeviceperformanceclasses-field) | Device performance class information supported by a specific widget. For example, if the supportDevicePerformanceClasses field of a widget is configured with "high", "medium", and "low", the widget can be displayed on devices with performance classes "high", "medium", and "low".<br/>**Note:**<br/>This field is supported since API version 22.| String array | Yes, default value: ["high", "medium", "low"]. |
| [standby](#standby-field) | Extended field for the standby screen saver display page widget.<br/>**Note:**<br/>This field is supported since API version 23. It depends on the system implementing the standby screen saver display app before being displayed.| Object | Yes. For default values of attributes, see the [standby Field](#standby-field). |

### supportDeviceTypes Field

Specifies the device type supported by the widget.

   | Field| Description  | Data Type                     |
   | ---- | ---- | -------------------------- |
   | phone | Smartphone| String|
   | tablet | Tablet| String|
   | tv | Vision| String|
   | wearable | Wearable| String|
   | car | Head unit| String|
   | 2in1 | PC/2-in-1 device| String|

### supportDevicePerformanceClasses Field

Specifies the device performance class supported by the widget.

   | Field| Description  | Data Type                     |
   | ---- | ---- | -------------------------- |
   | high | High| String|
   | medium | Medium| String|
   | low | Low| String|

### window Field

Defines the internal structure of the **window** object. This field is supported only in JS widgets.

   | Field| Description| Data Type| Default Value Allowed|
   | -------- | -------- | -------- | -------- |
   | designWidth | Specifies the base width for page design. Based on this width, element sizes are scaled according to the actual device width. The value range is greater than or equal to 0 and less than 2^16. Unit: px. | Number | Yes (initial value: 720px) |
   | autoDesignWidth | Whether to automatically calculate the baseline width for page design. If it is set to **true**, the **designWidth** attribute will be ignored, and the baseline width will be calculated based on the device width and screen density.| Boolean| Yes (initial value: **false**)|

### funInteractionParams Field

Specifies a fun-based widget. If **funInteractionParams** and **sceneAnimationParams** are both configured, the interactive widget is a fun-based widget.

| Name               | Type | Mandatory| Description                                                                                                                                 |
|-------------------|-----|----|-------------------------------------------------------------------------------------------------------------------------------------|
| abilityName       | String| No | LiveFormExtensionAbility name. This parameter is left empty by default.                                                                                             |
| targetBundleName  | String| Yes | Main bundle name.      |
| subBundleName     | String| No | Sub bundle name.|
| keepStateDuration | Number | No | Duration for which the active state is retained when there is no interaction in an interactive scenario. The default value is 10000, in ms. The value is an integer in the range (0, 60000]. If the value exceeds this range, the maximum value 60000 is used.<br/>**Note:** Before API version 26.0.0, this field is an integer in the range (0, 10000]. If the value exceeds this range, the default value 10000 is used. |

```json5
{
  "forms": [
    {
       // ...
      "funInteractionParams": {
         "targetBundleName": "com.example.funInteraction",
         "subBundleName": "com.example.subFunInteraction"
      }
    }
  ]
}
```

### sceneAnimationParams Field

Specifies a scene-based widget. If **funInteractionParams** and **sceneAnimationParams** are both configured, the interactive widget is a fun-based widget.

| Name                                   | Type    | Mandatory| Description|
|---------------------------------------|--------|----|----------------------------|
| abilityName                           | String| Yes | LiveFormExtensionAbility name of the scene-based widget.|
| disabledDesktopBehaviors | Array of strings | No  | Supported values include SWIPE_DESKTOP (swipe on the home screen), PULL_DOWN_SEARCH (pull down for global search), LONG_CLICK (long press), and DRAG (drag). One or more values can be specified. The default value means no behavior is disabled.<br/>**Note:**<br/>This field is supported since API version 20 and is effective only for system apps. |
| triggerTypes                           | Array of strings | No  | Scene animation trigger type. Supported values include shake.<br/>**Note:**<br/>This field is supported since API version 26.0.0.|

<!--RP2-->

   ```json5
   {
     "forms": [
       {
          // ...
         "sceneAnimationParams": {
            "abilityName": "MyLiveFormExtensionAbility",
            "disabledDesktopBehaviors": [
              "SWIPE_DESKTOP",
              "PULL_DOWN_SEARCH",
              "LONG_CLICK",
              "DRAG"
            ],
            "triggerTypes": [
              "shake"
            ]
         }          
       }
     ]
   }
   ```

<!--RP2End-->

### standby Field

This tag identifies the internal structure of the standby object. The app must apply for the open capability, and the widget's isSupported configuration must be set to true for it to be displayed on the standby screen saver display interface.

| Field| Description| Data Type| Default Value Allowed|
| -------- | -------- | -------- | -------- |
| isSupported | Whether the widget supports display on the standby screen saver interface.<br/>-&nbsp;true: The widget supports display on the standby screen saver interface.<br/>-&nbsp;false: The widget does not support display on the standby screen saver interface. | Boolean | Yes. The default value is **true**. |
| isAdapted | Whether the widget has been adapted for the standby screen saver interface. If set to **true**, the `backgroundImage` in the widget layout component will be removed.<br/>-&nbsp;true: The widget has been adapted for the standby screen saver interface.<br/>-&nbsp;false: The widget has not been adapted for the standby screen saver interface. | Boolean | Yes. The default value is **false**. |
| isPrivacySensitive | Whether the widget is privacy-sensitive. A privacy-sensitive widget displayed on the standby screen saver interface will be covered by a mask layer.<br/>-&nbsp;true: The widget is privacy-sensitive.<br/>-&nbsp;false: The widget is not privacy-sensitive. | Boolean | Yes. The default value is **false**. |

   ```json5
   {
     "forms": [
       {
         // ...
         "standby": {
           "isSupported": true,
           "isAdapted": false,
           "isPrivacySensitive": false
         }          
       }
     ]
   }
   ```

### Configuration File Example

<!--RP1-->

   ```json5
   {
     "forms": [
       {
         "name": "widget",
         "displayName": "$string:widget_display_name",
         "description": "$string:widget_desc",
         "src": "./ets/widget/pages/WidgetCard.ets",
         "uiSyntax": "arkts",
         "window": {
           "designWidth": 720,
           "autoDesignWidth": true
         },
         "renderingMode": "fullColor",
         "isDefault": true,
         "updateEnabled": true,
         "scheduledUpdateTime": "10:30",
         "updateDuration": 1,
         "defaultDimension": "2*2",
         "supportDimensions": [
           "2*2"
         ],
         "formConfigAbility": "ability://EntryAbility",
         "isDynamic": true,
         "metadata": []
       }
     ]
   }
   ```

<!--RP1End-->

### supportDimensions Field and Device Support Relationship Table

Widget size specifications supported by each device type. "Lock screen only" indicates that the size is applicable only to lock screen scenarios. "Some models" indicates that specific support depends on the device's home screen grid configuration.

| Widget Size | Phone | PC | 2-in-1 Device | Tablet | TV | Car | Wearable |
|-------------|-------|----|------|------|------|------|------|
|"1*2"|Yes|Yes|Yes|Yes|Yes|Yes|Yes|
|"2*2"|Yes|Yes|Yes|Yes|Yes|Yes|Yes|
|"2*4"|Yes|Yes|Yes|Yes|Yes|Yes|No|
|"4*4"|Yes|Yes|Yes|Yes|Yes|Yes|No|
|"1*1"|Yes (lock screen only)|No|No|Yes (lock screen only)|No|No|Yes|
|"6*4"|Yes (some models)|Yes|Yes|Yes (some models)|No|No|No|
|"2*3"|No|No|No|No|No|No|Yes|
|"3*3"|No|No|No|No|No|No|Yes|