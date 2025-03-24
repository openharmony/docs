# Configuring Widget Configuration Files


Widget-related configuration includes **FormExtensionAbility** configuration and widget configuration.


1. Configure FormExtensionAbility information under **extensionAbilities** in the [module.json5 file](../quick-start/module-configuration-file.md). For a FormExtensionAbility, you must specify **metadata**. Specifically, set **name** to **ohos.extension.form** (fixed), and set **resource** to the index of the widget configuration information.

   Example configuration:


   ```json
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
       ]
     }
   }
   ```

2. Configure the widget configuration information. In the **metadata** configuration item of FormExtensionAbility, you can specify the resource index of specific configuration information of the widget. For example, if **resource** is set to **$profile:form_config**, **form_config.json** in the **resources/base/profile/** directory of the development view is used as the profile configuration file of the widget. The following table describes the internal structure of the profile configuration file.

   **Table 1** form_config.json file

   | Field| Description| Data Type| Default Value Allowed|
   | -------- | -------- | -------- | -------- |
   | forms | Configuration about all application widgets.<br>A maximum of 16 widgets can be configured. If more than 16 widgets are configured, the first 16 widgets are retained.| Array| No|
   | name | Name of the widget. The value is a string with a maximum of 127 bytes.| String| No|
   | displayName | Display name of the widget. The value can be a string or a resource index to the name in multiple languages. The string must contain 1 to 30 bytes.| String| No|
   | description | Description of the widget. The value can be a string or a resource index to descriptions in multiple languages. The value is a string with a maximum of 255 bytes.| String| Yes (initial value: left empty)|
   | src | Full path of the UI code corresponding to the widget. For an ArkTS widget, the full path must contain the widget file name extension, for example, **./ets/widget/pages/WidgetCard.ets**. For a JS widget, the full path does not need to contain the widget file name extension, for example, **./js/widget/pages/WidgetCard**.| String| No|
   | uiSyntax | Type of the widget.<br>- **arkts**: ArkTS widget<br>- **hml**: JS widget| String| Yes (initial value: **hml**)|
   | [window](#window-field)| Window-related configurations.| Object| Yes (initial value: see Table 2)|
   | isDefault | Whether the widget is a default one. Each UIAbility has only one default widget.<br>- **true**: The widget is the default one.<br>- **false**: The widget is not the default one.| Boolean| No|
   | colorMode | Color mode of the widget.<br>- **auto**: following the system color mode<br>- **dark**: dark color mode<br>- **light**: light color mode| String| Yes (initial value: **auto**)|
   | supportDimensions | Grid styles supported by the widget.<br>- **1 * 2**: indicates a grid with one row and two columns.<br>- **2 * 2**: indicates a grid with two rows and two columns.<br>- **2 * 4**: indicates a grid with two rows and four columns.<br>- **4 * 4**: indicates a grid with four rows and four columns.<br>- **1 * 1**: indicates a round widget with one row and one column.<br>- **6 * 4**: indicates a grid with six rows and four columns.| String array| No|
   | defaultDimension | Default grid style of the widget. The value must be available in the **supportDimensions** array of the widget.| String| No|
   | updateEnabled | Whether the widget can be updated periodically.<br>- **true**: The widget can be updated at a specified interval (**updateDuration**) or at the scheduled time (**scheduledUpdateTime**). **updateDuration** takes precedence over **scheduledUpdateTime**. If both are specified, the value specified by **updateDuration** is used.<br>- **false**: The widget cannot be updated periodically.| Boolean| No|
   | scheduledUpdateTime | Scheduled time to update the widget. The value is in 24-hour format and accurate to minute.<br>**NOTE**<br>**updateDuration** takes precedence over **scheduledUpdateTime**. If both are specified, the value specified by **updateDuration** is used.| String| Yes (initial value: The widget is not updated at the scheduled time.)|
   | updateDuration | Interval to update the widget. The value is a natural number, in the unit of 30 minutes.<br>If the value is **0**, this field does not take effect.<br>If the value is a positive integer *N*, the interval is calculated by multiplying *N* and 30 minutes.<br>**NOTE**<br>**updateDuration** takes precedence over **scheduledUpdateTime**. If both are specified, the value specified by **updateDuration** is used.| Number| Yes (initial value: **0**)|
   | formConfigAbility | Link to a specific page of the application. The value is a URI.| String| Yes (initial value: left empty)|
   | metadata | Metadata of the widget. For details, see [Metadata](../reference/apis-ability-kit/js-apis-bundleManager-metadata.md).| Object| Yes (initial value: left empty)|
   | dataProxyEnabled | Whether the widget supports the update-through-proxy feature.<br>- **true**: The widget supports the update-through-proxy feature.<br>- **false**: The widget does not support the update-through-proxy feature.<br>If this tag is set to **true**, [the settings for the scheduled update time will still take effect, but the settings for the update interval and next update time will not](./arkts-ui-widget-update-by-time.md).| Boolean| Yes (initial value: **false**)|
   | [isDynamic](#isdynamic-field)| Whether the widget is a dynamic widget. This tag applies only to ArkTS widgets.<br>- **true**: The widget is a dynamic widget.<br>- **false**: The widget is a static widget.<br>| Boolean| Yes (initial value: **true**)|
   | fontScaleFollowSystem | Whether the font size of the widget changes with the system font size.<br>- **true**: The font size varies with the system font size.<br>- **false**: The font size cannot change with the system font size.<br>| Boolean| Yes (initial value: **true**)|
   | supportShapes | Shapes that the widget can be displayed. The options are as follows:<br>- **rect**: square widget.<br>- **circle**: circular widget.| String| Yes (initial value: **rect**)|
   | previewImages | Preview images of the widget, corresponding to the **supportDimensions** parameter.| String| Yes (mandatory for smart wearables and currently valid only for wearables)|
   | <!--DelRow-->formVisibleNotify | Whether the widget is allowed to use the widget visibility notification. This parameter is valid only for widgets of system applications.| Boolean| Yes (initial value: **false**)|
   | <!--DelRow-->transparencyEnabled | Whether the widget host is allowed to set the background transparency of the widget. This tag applies only to ArkTS widgets.  <br>- **true**: The widget host is allowed to set the background transparency of the widget.<br>- **false**: The widget host is not allowed to set the background transparency of the widget.<br>| Boolean| Yes (initial value: **false**)|
   |enableBlurBackground|Whether a blur background is enabled for the widget.<br>- **true**: A blur background is enabled.<br>- **false**: A blur background is disabled.|Boolean|Yes (initial value: **false**)|
   |renderingMode|Rendering mode of the widget.<br>- **autoColor**: automatic mode, where the widget is visible in both the lock screen widget center and the home screen widget center/widget management.<br>- **fullColor**: full-color mode, where the widget is visible in the home screen widget center/widget management.<br>- **singleColor**: monochrome mode, where the widget is visible in the lock screen widget center.	|String|Yes (initial value: **fullColor**)|
   |multiScheduledUpdateTime|Times for updating the widget. As an additional parameter for single-point update, it follows the 24-hour format, precise to the minute. It allows up to 24 distinct times, with every two times separated by a comma (,).<br>**NOTE**<br>It must be used together with **scheduledUpdateTime**.|String|Yes (initial value: The widget is not updated at the scheduled times.)|
   |conditionUpdate|Conditional update capabilities supported by the widget (valid only for ArkTS widgets of system applications).  <br>- **network**: Network update is supported.|String|Yes (initial value: an empty string)|

## isDynamic Field

Specifies whether the widget is a dynamic widget. It applies only to ArkTS widgets.

| Widget Type| Supported Capabilities| Use Case| Pros and Cons|
| ------- | ------ | ------- | ------- | 
| Static widget| Limited to UI components and layout capabilities.| Suitable for presenting static information (with a stable UI), allowing navigation to a specific UIAbility via the **FormLink** component.| Offers basic functionality with efficient memory management.|
| Dynamic widget| Common event and custom animation capabilities in addition to UI components and layout capabilities.| Suitable for scenarios requiring complex logic and interactions, such as updating images or content on a widget.| Provides enhanced capabilities at the cost of high memory overhead.|

## window Field

Describes the internal structure of a window object.

   | Field| Description| Data Type| Default Value Allowed|
   | -------- | -------- | -------- | -------- |
   | designWidth | Baseline width for page design. The size of an element is scaled by the actual device width.| Number| Yes (initial value: **720px**)|
   | autoDesignWidth | Whether to automatically calculate the baseline width for page design. If it is set to **true**, the **designWidth** attribute will be ignored, and the baseline width will be calculated based on the device width and screen density.| Boolean| Yes (initial value: **false**)|

   Example configuration:


   ```json
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
         "colorMode": "auto",
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
         "dataProxyEnabled": false,
         "isDynamic": true,
         "transparencyEnabled": false,
         "metadata": []
       }
     ]
   }
   ```
