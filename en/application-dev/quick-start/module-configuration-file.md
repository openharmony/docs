# module.json5 Configuration File
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

## Configuration File Example

This topic gives an overview of the **module.json5** configuration file. To start with, let's go through an example of what this file contains.
<!--RP1-->
```json
{
  "module": {
    "name": "entry",
    "type": "entry",
    "description": "$string:module_desc",
    "srcEntry": "./ets/entryability/EntryAbility.ets",
    "mainElement": "EntryAbility",
    "deviceTypes": [
      "default",
      "tablet"
    ],
    "deliveryWithInstall": true,
    "installationFree": false,
    "pages": "$profile:main_pages",
    "virtualMachine": "ark",
    "appStartup": "$profile:app_startup_config",
    "metadata": [
      {
        "name": "string",
        "value": "string",
        "resource": "$profile:distributionFilter_config"
      }
    ],
    "abilities": [
      {
        "name": "EntryAbility",
        "srcEntry": "./ets/entryability/EntryAbility.ets",
        "description": "$string:EntryAbility_desc",
        "icon": "$media:layered_image",
        "label": "$string:EntryAbility_label",
        "startWindow": "$profile:start_window",
        "startWindowIcon": "$media:icon",
        "startWindowBackground": "$color:start_window_background",
        "exported": true,
        "skills": [
          {
            "entities": [
              "entity.system.home"
            ],
            "actions": [
              "ohos.want.action.home"
            ]
          }
        ],
        "continueType": [
          "continueType1"
        ],
        "continueBundleName": [
          "com.example.myapplication1",
          "com.example.myapplication2"
        ]
      }
    ],
    "requestPermissions": [
      {
        "name": "ohos.permission.ACCESS_BLUETOOTH",
        "reason": "$string:reason",
        "usedScene": {
          "abilities": [
            "FormAbility"
          ],
          "when": "inuse"
        }
      }
    ],
    "querySchemes": [
      "app1Scheme",
      "app2Scheme"
    ],
    "routerMap": "$profile:router_map",
    "appEnvironments": [
      {
        "name": "name1",
        "value": "value1"
      }
    ],
    "hnpPackages": [
      {
        "package": "hnpsample.hnp",
        "type": "public"
      }
    ],
    "fileContextMenu": "$profile:menu",
    "crossAppSharedConfig": "$profile:shared_config"
  }
}
```
<!--RP1End-->

## Tags in the Configuration File

As shown above, the **module.json5** file contains several tags.


  **Table 1** Tags in the module.json5 file

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| name | Name of the module. This name must be unique in the entire application. The value must comply with the following rules:<br>- Starts with a letter and consists of letters, digits, underscores (_).<br>- The maximum length is 128 bytes.<br>This name can be changed during application updates. However, if it is changed, directories related to the module must be migrated. You can use the [file management API](../reference/apis-core-file-kit/js-apis-file-fs.md) for migration.| String| No|
| type | Type of the module. The options are as follows:<br>- **entry**: main module of the application.<br>- **feature**: feature module of the application.<br>- **har**: static shared module.<br>- **shared**: dynamic shared module.| String| No|
| srcEntry | Code path of the AbilityStage component. The value is a string with a maximum of 127 bytes. For details, see [AbilityStage Component Container](../application-models/abilitystage.md).| String| Yes (initial value: left empty)|
| description | Description of the module, used to describe the module functions. The value is a string with a maximum of 255 bytes. It can be a resource reference.| String| Yes (initial value: left empty)|
| <!--DelRow-->process | Process name of the module. The value is a string with a maximum of 31 bytes. If **process** is configured under **HAP**, all UIAbilities, DataShareExtensionAbilities, and ServiceExtensionAbilities of the module will run in the specified process.<br>**NOTE**<br>The [device-specific application privileges](../../device-dev/subsystems/subsys-app-privilege-config-guide.md#device-specific-application-privileges) takes effect, but the third-party application configuration does not take effect.| String| Yes (initial value: value of **bundleName** under **app** in the **app.json5** file)|
| mainElement | Name of the entry UIAbility of the module. The value is a string with a maximum of 255 bytes.<br>**NOTE**<br>If multiple entry [UIAbilities](../application-models/uiability-overview.md) are configured in the [abilities](#abilities) tag, the home screen icon, name, and entry are subject to the configuration of this tag. If this tag is left empty or no matching is found, the UIAbility **name** tag is sorted in ascending order based on the ASCII, and the first UIAbility's icon, name, and entry are used.| String| Yes (initial value: left empty)|
| [deviceTypes](#devicetypes) | Types of the devices on which the module can run.<br>**NOTE**<br>When there are multiple modules, the configuration of each module can be different, but the required device type must be included to ensure the proper running.| String array| No|
| deliveryWithInstall | Whether the current module is installed during active installation, that is, whether the HAP or HSP corresponding to the module is installed together with the application.<br>- **true**: The HAP or HSP of the module is installed together with the application.<br>- **false**: The HAP or HSP of the module is not installed together with the application.<!--RP11--><!--RP11End--> | Boolean| No<br>This tag is mandatory when the current module is a HAP or an HSP.|
| installationFree | Whether the module supports the installation-free feature.<br>- **true**: The module supports the installation-free feature and meets installation-free constraints.<br>- **false**: The module does not support the installation-free feature.| Boolean| Yes<br> This tag is automatically generated during compilation and build. Manual configuration does not take effect.<br>**NOTE**<br>If [bundleType](./app-configuration-file.md#tags-in-the-configuration-file) is set to **atomicService**, this tag is automatically set to **true**; otherwise, this tag is automatically set to **false**.|
| virtualMachine | Type of the target virtual machine (VM) where the module can run. It is used for cloud distribution, such as distribution by the application market and distribution center. If the target VM type is ArkTS engine, the value is **ark**+*version number*.| String| Yes<br>This tag is automatically generated during compilation and build. Manual configuration does not take effect.|
| [pages](#pages)| Profile that represents information about each page in the module. The value is a string with a maximum of 255 bytes.| String| Yes (initial value: left empty)|
| [metadata](#metadata)| Custom metadata of the module. You can configure [distributionFilter](#distributionfilter) and [shortcuts](#shortcuts) by referencing resources. The setting is effective only for the current module, UIAbility, and ExtensionAbility.| Object array| Yes (initial value: left empty)|
| [abilities](#abilities) | UIAbility configuration of the module. The setting is effective only for the current UIAbility.| Object array| Yes (initial value: left empty)|
| [extensionAbilities](#extensionabilities) | ExtensionAbility configuration of the module. The setting is effective only for the current ExtensionAbility.| Object array| Yes (initial value: left empty)|
| <!--DelRow-->[definePermissions](#definepermissions)| Permissions defined for the system resource HAP. Custom permissions are not supported.| Object array| Yes (initial value: left empty)|
| [requestPermissions](../security/AccessToken/declare-permissions.md#declaring-permissions-in-the-configuration-file)| A set of permissions that the application needs to request from the system for running correctly.| Object array| Yes (initial value: left empty)|
| [testRunner](#testrunner) | Test runner of the module. For details, see [test Command](../tools/aa-tool.md#test-command).| Object| Yes (initial value: left empty)|
| [atomicService](#atomicservice)| Atomic service configuration.| Object| Yes (initial value: left empty) |
| [dependencies](#dependencies)| List of shared libraries on which the module depends during running.| Object array| Yes (initial value: left empty)<br> This tag is automatically generated during compilation and build. Manual configuration does not take effect. |
| targetModuleName | Target module name. The value is a string with a maximum of 128 bytes. The module that has this tag set provides the overlay feature. This tag is applicable only to HSPs.|String|Yes (initial value: left empty)|
| targetPriority | Priority of the module. The value ranges from 1 to 100. This tag can be configured only after the **targetModuleName** tag is configured. This tag is applicable only to HSPs.|Integer|Yes (initial value: **1**)|
| [proxyData](#proxydata) | List of data proxies provided by the module.| Object array| Yes (initial value: left empty)|
| isolationMode | Multi-process configuration of the module. The options are as follows:<br>- **nonisolationFirst**: The module preferentially runs in a non-isolated process.<br>- **isolationFirst**: The module preferentially runs in an isolated process.<br>- **isolationOnly**: The module runs only in an isolated process.<br>- **nonisolationOnly**: The module runs only in a non-isolated process.<br>**NOTE**<br>1. The current module can serve as an isolated process on 2-in-1 devices and tablets.<br>2. This tag takes effect only for HAPs.|String|Yes (initial value: **nonisolationFirst**)|
| generateBuildHash |Whether the hash value of the HAP or HSP is generated by the packing tool. If the value is set to **true**, the hash value (if any) is used to determine whether the application needs to be updated when the system is updated in OTA mode but the **versionCode** value of the application remains unchanged.<br>This tag takes effect only when **generateBuildHash** in the [app.json5](./app-configuration-file.md) file is set to **false**.<br>**NOTE**<br>This tag takes effect only for pre-installed applications.|Boolean|Yes (initial value: **false**)|
| compressNativeLibs | During HAP packaging, whether libraries are packaged to HAP after being compressed.<br>- **true**: Libraries are stored in the HAP file after being compressed.<br>- **false**: Libraries are stored without being compressed.| Boolean| Yes (initial value: **false**)|
| extractNativeLibs | During application installation, whether libraries are decompressed to the application installation directory. If both **compressNativeLibs** and **extractNativeLibs** are set to **false**, the application is installed without decompressing libraries. In other scenarios, the application is installed with libraries decompressed.<br>**NOTE**<br>This tag is supported since API version 20.| Boolean| Yes (initial value: **true**)|
| libIsolation | Whether to save the .so files of the current HAP to a separate folder. This is intended to avoid .so file conflicts between HAPs.<br>- **true**: The .so files of the current HAP are stored in a separate folder (named after the module) in the **libs** directory.<br>- **false**: The .so files of the current HAP are directly stored in the **libs** directory.| Boolean| Yes (initial value: **false**)|
| [fileContextMenu](#filecontextmenu)| Context menu of the current HAP. It is a profile resource. The value is a string with a maximum of 255 bytes.<br>**NOTE**<br>This tag takes effect only on the PCs/2-in-1 devices.<br>It can be configured only in entry modules.| String| Yes (initial value: left empty)|
| querySchemes | URL schemes that the current application can query for redirection. This tag is only available for the entry modules. The value is a string with a maximum of 128 bytes.<br>**NOTE**<br>Since API version 21, a maximum of 200 URL schemes can be configured. In API version 20 and earlier versions, a maximum of 50 URL schemes can be configured. | String array| Yes (initial value: left empty)|
| [routerMap](#routermap) | Path of the routing table for the current module. The value is a string with a maximum of 255 bytes.| String| Yes (initial value: left empty)|
| [appEnvironments](#appenvironments) | Application environments for the current module. This tag is only available for the entry and feature modules.| Object array| Yes (initial value: left empty)|
| appStartup | Configuration path of the current [AppStartup](../application-models/app-startup.md). This tag can be configured only in the entry module.<br>Since API version 18, this tag can be configured in HSPs and HARs.<br>Since API version 20, this tag can be configured in feature modules.| String| Yes (initial value: left empty)|
| [hnpPackages](#hnppackages) | Native software package information of the current application. This tag is only available for the entry modules.| Object array| Yes (initial value: left empty)|
| [systemTheme](#systemtheme)| System theme that is being used. This tag is only available for the entry modules. The value is a string with a maximum of 255 bytes.<br>**NOTE**<br>This tag is supported since API version 20.| String| Yes (initial value: left empty)|
| abilitySrcEntryDelegator | Name of the UIAbility to which the current module redirects. It is used together with the **abilityStageSrcEntryDelegator** tag to specify the target object for redirection.<br>**NOTE**<br>1. This tag is supported since API version 17.<br>2. This tag does not take effect when the UIAbility is started through the [startAbilityByCall](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#startabilitybycall) API.<br>3. Configuration in the HAR and redirection to the UIAbility of the HAR are not supported.| String| Yes (initial value: left empty)|
| abilityStageSrcEntryDelegator | Name of the target module corresponding to the UIAbility that the current module redirects to (different from the current module name). It is used together with the **abilitySrcEntryDelegator** tag to specify the target object for redirection.<br>**NOTE**<br>1. This tag is supported since API version 17.<br>2. This tag does not take effect when the UIAbility is started through the [startAbilityByCall](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#startabilitybycall) API.<br>3. Configuration in the HAR and redirection to the UIAbility of the HAR are not supported.| String| Yes (initial value: left empty)|
| crossAppSharedConfig | Name of the configuration file for inter-application sharing. The value is a string with a maximum of 255 bytes. It is used to release configurations for other applications to read. The configurations take effect when the application is installed and become invalid when the application is uninstalled. For details, see [Sharing Configurations Between Applications (ArkTS)](../database/share-config.md#configuring-the-publisher).<br>**NOTE**<br>This tag is supported since API version 20.| String| Yes (initial value: left empty)|
| formWidgetModule | In [standalone widget package](../form/arkts-ui-widget-creation.md#method-2-creating-a-standalone-package), this tag needs to be configured for the application package to associate with the widget package. The value is the module name of the widget package, corresponding to the **name** tag in the **module.json5** file of the widget package. For details, see [FormExtensionAbility Configuration](../form/arkts-ui-widget-configuration.md#formextensionability-configuration).<br>**NOTE**<br> 1. This tag is supported since API version 20.<br> 2. This tag takes effect only in the application package of a standalone widget package. The **formExtensionModule** tag must be configured for the corresponding widget package module.| String| Yes (initial value: left empty) |
| formExtensionModule | In [standalone widget package](../form/arkts-ui-widget-creation.md#method-2-creating-a-standalone-package), this tag needs to be configured for the widget package to associate with the application package. The value is the module name of the application package, corresponding to the **name** tag in the **module.json5** file of the application package. For details, see [Standalone Widget Package Configuration](../form/arkts-ui-widget-configuration.md#independent-widget-package-configuration).<br>**NOTE**<br>1. This tag is supported since API version 20.<br>2. This tag takes effect only in the widget package of a standalone widget package. The **formWidgetModule** tag must be configured for the corresponding application package module.| String| Yes (initial value: left empty) |
<!--RP6--><!--RP6End-->

## deviceTypes

  **Table 2** deviceTypes
<!--RP2-->
| Device Type| Value| Description|
| -------- | -------- | -------- |
| Tablet| tablet | - |
| Smart TV| tv | - |
| Smart watch| wearable | Watch that provides call features.|
| Head unit| car | - |
| PC/2-in-1 device| 2in1 | PC, mainly used for multi-window and multi-task interactions, and keyboard and mouse operations. It fully showcases the device productivity. In the OpenHarmony topics, "2-in-1" indicates PC/2-in-1 device.|
| Default device| default | Device that provides full access to system capabilities.|
<!--RP2End-->

Example of the **deviceTypes** structure:


```json
{
  "module": {
    "name": "myHapName",
    "type": "feature",
    "deviceTypes" : [
       "tablet"
    ]
  }
}
```


## pages

The **pages** tag is a profile that represents information about specified pages.


```json
{
  "module": {
    // ...
    "pages": "$profile:main_pages", // Configured through the resource file in the profile
  }
}
```

Define the **main_pages.json** file under **resources/base/profile** in the development view. The file name (**main_pages** in this example) can be customized, but must be consistent with the information specified by the **pages** tag. The file lists the page information of the current application, including the route information and the window-related configuration.

  **Table 3** pages

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| src | Route information about all pages in the module, including the page path and page name. The page path is relative to the **src/main/ets** directory of the current module. The value is a string array, each element of which represents a page.| String array| No|
| window | Window-related configuration.	 | Object| Yes (initial value: left empty)|


  **Table 4** window

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| designWidth | Baseline width for page design. The size of an element is scaled by the actual device width.| Number| Yes (initial value: **720px**)|
| autoDesignWidth | Whether to automatically calculate the baseline width for page design. If it is set to **true**, the **designWidth** attribute becomes invalid. The baseline width is calculated based on the device width and screen density. If it is set to **false**, the baseline width uses the value of **designWidth**.| Boolean| Yes (initial value: **false**)|

```json
{
  "src": [
    "pages/index/mainPage",
    "pages/second/payment",
    "pages/third/shopping_cart",
    "pages/four/owner"
  ],
  "window": {
    "designWidth": 720,
    "autoDesignWidth": false
  }
}
```


## metadata

The **metadata** tag represents the custom metadata of the HAP. The tag value is an array and contains three subtags: **name**, **value**, and **resource**.

**Table 5** metadata

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| name | Name of the data item. The value is a string with a maximum of 255 bytes.| String| Yes (initial value: left empty)|
| value | Value of the data item. The value is a string with a maximum of 255 bytes.| String| Yes (initial value: left empty)|
| resource | Custom data, which is a resource index. The value is a string with a maximum of 255 bytes. For example, **$profile:shortcuts_config** indicates that the data points to the **/resources/base/profile/shortcuts_config.json** configuration file.| String| Yes (initial value: left empty)|

```json
{
  "module": {
    "metadata": [{
      "name": "module_metadata",
      "value": "a test demo for module metadata",
      "resource": "$profile:shortcuts_config"
    }]
  }
}
```

## abilities

The **abilities** tag represents the UIAbility configuration of the module, which is valid only for the current UIAbility component.

  **Table 6** abilities

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| name | Name of the UIAbility, which must be unique in the entire application. The value is a string with a maximum of 127 bytes. It must start with a letter and can contain letters, digits, underscores (_), and periods (.).| String| No|
| srcEntry | Code path of the UIAbility. The value is a string with a maximum of 127 bytes.| String| No|
| [launchType](../application-models/uiability-launch-type.md) | Launch type of the UIAbility. The options are as follows:<br>- **multiton**: A UIAbility instance is created each time the UIAbility is started.<br>- **singleton**: A UIAbility instance is created only when the UIAbility is started for the first time.<br>- **specified**: You can determine whether to create a UIAbility instance when the application is running.<br>- **standard**: original name of **multiton**. The effect is the same as that multiton mode.| String| Yes (initial value: **"singleton"**)|
| description | Description of the UIAbility component, used to describe the component functions. The value is a string with a maximum of 255 bytes. It is advised to use a resource index to support multiple languages.| String| Yes (initial value: left empty)|
| icon | [Icon](layered-image.md) of the UIAbility. The value is the index of the icon resource file.| String| Yes (initial value: left empty)|
| label | [Name](layered-image.md) of the UIAbility displayed to users. The value is an index of a string with a maximum of 255 bytes to support multiple languages.| String| Yes (initial value: left empty)|
| permissions | Permissions required for another application to access the UIAbility. When other applications access the UIAbility, they need to apply for the corresponding permissions.<br>Each array element is a permission name with a maximum of 255 bytes. For details about the value, see [Application Permissions](../security/AccessToken/app-permissions.md).| String array| Yes (initial value: left empty)|
| [metadata](#metadata)|Metadata information of the UIAbility. For details about the typical use scenarios, see [metadata](../windowmanager/window-config-m.md#metadata).| Object array| Yes (initial value: left empty)|
| exported | Whether the UIAbility component can be started by other applications.<br>- **true**: The UIAbility component can be started by other applications. (It is recommended that this tag be set to **true** for the entry UIAbility.)<br>- **false**: The UIAbility component can be started only by the same application or an application with the ohos.permission.START_INVISIBLE_ABILITY permission (only system applications can request this permission).<br> For example, if this attribute is set to **false**, the UIAbility component can be started through the application icon, shortcut, or push notification on the home screen which has the permission. However, it cannot be started by the Ability Assistant, which does not have this permission.| Boolean| Yes (initial value: **false**)|
| continuable | Whether the UIAbility can be continued on another device.<br>- **true**: The UIAbility can be continued on another device.<br>- **false**: The UIAbility cannot be continued on another device.| Boolean| Yes (initial value: **false**)|
| [skills](#skills) | A set of [wants](../application-models/want-overview.md) that can be received by the UIAbility.<br>Configuration rules:<br>- For HAPs of the entry type, you can configure multiple **skills** tags with the entry capability for an application. (A **skills** tag with the entry capability is the one that has **ohos.want.action.home** and **entity.system.home** configured.)<br>- For HAPs of the feature type, you can configure the **skills** tag with the entry capability for an application, but not for a service.| Object array| Yes (initial value: left empty)|
| backgroundModes | [Continuous task](../task-management/continuous-task.md) set of the UIAbility component.<br>Continuous tasks are classified into the following types:<br>- **dataTransfer**: data transfer<br>- **audioPlayback**: audio playback<br>- **audioRecording**: audio recording<br>- **location**: location and navigation<br>- **bluetoothInteraction**: Bluetooth interaction<br>- **multiDeviceConnection**: multi-device connection<br>- **wifiInteraction**: WLAN services (for system applications only)<br>- **voip**: audio and video calls<br>- **taskKeeping**: computation (for PCs and 2-in-1 devices only)| String array| Yes (initial value: left empty)|
| [startWindow](#startwindow)| Profile resource of the UIAbility startup page. The value is a string with a maximum of 255 bytes. If this tag is set, the **startWindowIcon** and **startWindowBackground** tags do not take effect.<!--RP4--><br>**NOTE**<br>Since API version 20, this tag can be used to configure an enhanced starting window.<!--RP4End--> | String| Yes (initial value: left empty)|
| startWindowIcon | Index to the icon file of the UIAbility startup page. The value is a string with a maximum of 255 bytes.| String| No|
| startWindowBackground | Index to the background color resource file of the UIAbility startup page. The value is a string with a maximum of 255 bytes.<br>Example: **$color:red**.| String| No|
| removeMissionAfterTerminate | Whether to remove the relevant mission from the mission list after the UIAbility is destroyed.<br>- **true**: Remove the relevant mission from the mission list after the UIAbility is destroyed.<br>- **false**: Do not remove the relevant mission from the task mission list after the UIAbility is destroyed.<br>**NOTE**<br>This attribute is invalid in freeform window mode on 2-in-1 devices and tablets, and tasks are removed by default.| Boolean| Yes (initial value: **false**)|
| orientation | Startup direction of the UIAbility component. The enum and startup direction resource index can be configured.<br>The enum values are as follows:<br>- **unspecified**: automatically determined by the system.<br>- **landscape**: landscape mode.<br>- **portrait**: portrait mode.<br>- **follow_recent**: rotation mode following the background window.<br>- **landscape_inverted**: inverted landscape mode.<br>- **portrait_inverted**: inverted portrait mode.<br>- **auto_rotation**: determined by the sensor.<br>- **auto_rotation_landscape**: determined by the sensor in the horizontal direction, including landscape and inverted landscape modes.<br>- **auto_rotation_portrait**: determined by the sensor in the vertical direction, including portrait and inverted portrait modes.<br>- **auto_rotation_restricted**: determined by the sensor when the sensor switch is enabled.<br>- **auto_rotation_landscape_restricted**: determined by the sensor in the horizontal direction, including landscape and inverted landscape modes, when the sensor switch is enabled.<br>- **auto_rotation_portrait_restricted**: determined by the sensor in the vertical direction, including portrait and inverted portrait modes, when the sensor switch is enabled.<br>- **locked**: auto-rotation disabled.<br>- **auto_rotation_unspecified**: auto-rotation controlled by the switch and determined by the system.<br>- **follow_desktop**: following the orientation of the home screen.<br>To configure the startup direction resource index, the value should be a string with a maximum of 255 bytes, for example, **$string:orientation**.<br>**NOTE**<br>- The startup direction resource index is supported since API version 14.| String| Yes (initial value: **"unspecified"**)|
| supportWindowMode | Window mode supported by the UIAbility. The options are as follows:<br>- **fullscreen**: full-screen mode.<br>- **split**: split-screen mode.<br>- **floating**: floating window mode.<br>When **fullscreen** and **split** are both configured for a [freeform window](../windowmanager/window-terminology.md#freeform-window), the window will be started in floating window mode if the value of [targetAPIVersion](./app-configuration-file.md#tags-in-the-configuration-file) is less than 15, and in full-screen mode if the value is greater than or equal to 15.<br>In addition, you can configure the window mode through **metadata**. For details about the configuration rules and priorities, see [metadata](#metadata).| String array| Yes (initial value:<br>**["fullscreen",&nbsp;"split",&nbsp;"floating"]**)|
| <!--DelRow-->priority | Priority of the UIAbility component. In the case of [implicit query](../application-models/explicit-implicit-want-mappings.md), UIAbility components with a higher priority are at the higher place of the returned list. The value ranges from 0 to 10. The greater the value, the higher the priority.<br>**NOTE**<br>This configuration does not take effect in third-party applications but in system applications.| Integer| Yes (initial value: **0**)|
| maxWindowRatio | Maximum aspect ratio supported by the UIAbility component. The minimum value is **0**.| Number| Yes (initial value: maximum aspect ratio supported by the platform)|
| minWindowRatio | Minimum aspect ratio supported by the UIAbility component. The minimum value is **0**.| Number| Yes (initial value: minimum aspect ratio supported by the platform)|
| maxWindowWidth | Maximum window width supported by the UIAbility, in vp.<br>The value cannot be less than the value of **minWindowWidth** or greater than the maximum window width allowed by the platform. For details about the window size, see [Constraints](../windowmanager/window-overview.md#constraints).| Number| Yes (initial value: maximum window width supported by the platform)|
| minWindowWidth | Minimum window width supported by the UIAbility, in vp.<br>The value cannot be less than the minimum window width allowed by the platform or greater than the value of **maxWindowWidth**. For details about the window size, see [Constraints](../windowmanager/window-overview.md#constraints).| Number| Yes (initial value: minimum window width supported by the platform)|
| maxWindowHeight | Maximum window height supported by the UIAbility, in vp.<br>The value cannot be less than the value of **minWindowHeight** or greater than the maximum window height allowed by the platform. For details about the window size, see [Constraints](../windowmanager/window-overview.md#constraints).| Number| Yes (initial value: maximum window height supported by the platform)|
| minWindowHeight | Minimum window height supported by the UIAbility, in vp.<br>The value cannot be less than the minimum window height allowed by the platform or greater than the value of **maxWindowHeight**. For details about the window size, see [Constraints](../windowmanager/window-overview.md#constraints).| Number| Yes (initial value: minimum window height supported by the platform)|
| <!--DelRow-->excludeFromMissions | Whether the UIAbility component is displayed in Recents.<br>- **true**: displayed in Recents.<br>- **false**: not displayed in Recents.<br>**NOTE**<br>This configuration does not take effect in third-party applications but in system applications. To enable the configuration in system applications, apply for the application privilege **AllowAbilityExcludeFromMissions**. For details, see [Application Privilege Configuration](../../device-dev/subsystems/subsys-app-privilege-config-guide.md).| Boolean| Yes (initial value: **false**)|
| recoverable | Whether the application can be recovered to its previous state in case of faults.<br>- **true**: The application can be recovered to its previous state in case of faults.<br>- **false**: The application cannot be recovered to its previous state in case of faults.| Boolean| Yes (initial value: **false**)|
| <!--DelRow-->unclearableMission | Whether the UIAbility is unclearable in Recents.<br>- **true**: The UIAbility is unclearable in Recents.<br>- **false**: The UIAbility is clearable in Recents.<br>**NOTE**<br>This configuration does not take effect in third-party applications but in system applications. To enable the configuration in system applications, apply for the application privilege **AllowMissionNotCleared**. For details, see [Application Privilege Configuration](../../device-dev/subsystems/subsys-app-privilege-config-guide.md).| Boolean| Yes (initial value: **false**)|
| isolationProcess | Whether the component can run in an isolated process.<br>- **true**: The component can run in an isolated process.<br>- **false**: The component cannot run in an isolated process.<br>**NOTE**<br>The UIAbility can serve as an isolated process on 2-in-1 devices and tablets.| Boolean| Yes (initial value: **false**)|
| excludeFromDock | Whether the UIAbility can be hidden from the dock.<br>- **true**: The UIAbility can be hidden from the dock.<br>- **false**: The UIAbility cannot be hidden from the dock.| Boolean| Yes (initial value: **false**)|
| preferMultiWindowOrientation | Multi-window orientation of the UIAbility.<br>- **default**: default value. Do not set this parameter to the default value. You are advised to set this parameter for other applications.<br>- **portrait**: portrait. This option is recommended for games in portrait mode.<br>- **landscape**: landscape. This option is recommended for games in landscape mode. With this option, the floating window and upper and lower split screens are supported in landscape mode.<br>- **landscape_auto**: automatically landscape. This option is recommended for video applications. It must be used together with the **enableLandScapeMultiWindow/disableLandScapeMultiWindow** API.| String| Yes (initial value: **default**)|
| continueType | Continuation type of the UIAbility.| String array| Yes (initial value: name of the UIAbility)|
| continueBundleName | List of other applications that support cross-device migration.<br>**NOTE**<br>This parameter cannot be set to the application bundle name. It is used only for migration with different bundle names.<br>This tag is supported since API version 13.| String array| Yes (initial value: left empty)|
| process | Name of the process where the component runs. For details, see "Statically specified process" in [Process Model](../application-models/process-model-stage.md#other-process-types).<br>**NOTE**<br>1. This tag takes effect only on [PCs/2-in-1 devices](./module-configuration-file.md#devicetypes) and [tablets](./module-configuration-file.md#devicetypes).<br>2. The UIAbility component and the ExtensionAbility component whose type is **embeddedUI** run in the same process when their tags are the same.<br>3. This tag is supported since API version 14.| String| Yes (initial value: left empty)|

Example of the **abilities** structure:

<!--RP3-->
```json
{
  "abilities": [{
    "name": "EntryAbility",
    "srcEntry": "./ets/entryability/EntryAbility.ets",
    "launchType":"singleton",
    "description": "$string:description_main_ability",
    "icon": "$media:layered_image",
    "label": "$string:EntryAbility_label",
    "permissions": [],
    "metadata": [],
    "exported": true,
    "continuable": true,
    "skills": [{
      "actions": ["ohos.want.action.home"],
      "entities": ["entity.system.home"],
      "uris": []
    }],
    "backgroundModes": [
      "dataTransfer"
    ],
    "startWindow": "$profile:start_window",
    "startWindowIcon": "$media:icon",
    "startWindowBackground": "$color:red",
    "removeMissionAfterTerminate": true,
    "orientation": "$string:orientation",
    "supportWindowMode": ["fullscreen", "split", "floating"],
    "maxWindowRatio": 3.5,
    "minWindowRatio": 0.5,
    "maxWindowWidth": 2560,
    "minWindowWidth": 1400,
    "maxWindowHeight": 300,
    "minWindowHeight": 200,
    "excludeFromMissions": false,
    "unclearableMission": false,
    "excludeFromDock": false,
    "preferMultiWindowOrientation": "default",
    "isolationProcess": false,
    "continueType": [
      "continueType1",
      "continueType2"
    ],
    "continueBundleName": [
      "com.example.myapplication1",
      "com.example.myapplication2"
    ],
    "process": ":processTag"
  }]
}
```
<!--RP3End-->

## skills

The **skills** tag represents the feature set of [wants](../application-models/want-overview.md) that can be received by the UIAbility or ExtensionAbility component.

  **Table 7** skills

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| actions | Actions of wants that can be received, which can be predefined or customized.<br>You are advised not to configure multiple **actions** for a **skill**. Otherwise, the expected scenario may not be matched. For details, see [Common action and entities Values](../application-models/actions-entities.md).| String array| Yes (initial value: left empty)|
| entities | Entities of wants that can be received.<br>You are advised not to configure multiple **entities** for a **skill**. Otherwise, the expected scenario may not be matched. For details, see [Common action and entities Values](../application-models/actions-entities.md).| String array| Yes (initial value: left empty)|
| uris | URIs that match the wants.| Object array| Yes (initial value: left empty)|
| permissions | Permissions required for another application to access the UIAbility or ExtensionAbility.<br>Each array element is a permission name with a maximum of 255 bytes. For details about the value, see [Application Permissions](../security/AccessToken/app-permissions.md).| String array| Yes (initial value: left empty)|
| domainVerify | Whether to enable <!--RP7-->[domain name verification](../application-models/app-linking-startup.md#working-principles)<!--RP7End-->.<br>- **true**: Domain name verification is enabled.<br>- **false**: Domain name verification is disabled.| Boolean| Yes (initial value: **false**)|


  **Table 8** uris

> **NOTE**
>
> The following tags of the string type cannot be configured using resource indexes (**$string**).

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| scheme | Scheme of the URI, such as HTTP, HTTPS, file, and FTP.<br>**NOTE**<br>This tag is case-insensitive when it is used for implicit Want matching since API version 18.| String| Yes when only **type** is set in **uris** (initial value: left empty)|
| host | Host address of the URI. This tag is valid only when **scheme** is set. Common methods:<br>- domain name, for example, **example.com**.<br>- IP address, for example, **10.10.10.1**.<br>**NOTE**<br>This tag is case-insensitive when it is used for implicit Want matching since API version 18.| String| Yes (initial value: left empty)|
| port | Port number of the URI. For example, the default HTTP port number is 80, the default HTTPS port number is 443, and the default FTP port number is 21. This tag takes effect only when both **scheme** and **host** are configured.| String| Yes (initial value: left empty)|
| path&nbsp;\|&nbsp;pathStartWith&nbsp;\|&nbsp;pathRegex | Path of the URI. **path**, **pathStartWith**, and **pathRegex** represent different matching modes between the paths in the URI and the want. Set any one of them as needed. **path** indicates full matching, **pathStartWith** indicates prefix matching, and **pathRegex** indicates regular expression matching. This tag takes effect only when both **scheme** and **host** are configured.| String| Yes (initial value: left empty)|
| type | Data type that matches the want. The value complies with the Multipurpose Internet Mail Extensions (MIME) and [UniformDataType](../reference/apis-arkdata/js-apis-data-uniformTypeDescriptor.md) type specifications. This tag can be configured together with **scheme** or configured separately.| String| Yes (initial value: left empty)|
| utd | [Uniform data types](../reference/apis-arkdata/js-apis-data-uniformTypeDescriptor.md) that match the wants. This tag is applicable to scenarios such as sharing.| String| Yes (initial value: left empty)|
| maxFileSupported | Maximum number of files of a specified type that can be received or opened at a time. This tag is applicable to scenarios such as sharing and must be used together with **utd**.| Integer| Yes (initial value: **0**)|
| linkFeature | Feature type provided by the URI. It is used to implement redirection between applications. The value is a string with a maximum of 127 bytes. The number of **linkFeature** declared in a bundle cannot exceed 150. For details, see [Description of linkFeature](../application-models/app-uri-config.md#description-of-linkfeature)| String| Yes (initial value: left empty)|

Example of the **skills** structure:


```json
{
  "abilities": [
    {
      "skills": [
        {
          "actions": [
            "ohos.want.action.home"
          ],
          "entities": [
            "entity.system.home"
          ],
          "uris": [
            {
              "scheme":"http",
              "host":"example.com",
              "port":"80",
              "path":"path",
              "type": "text/*",
              "linkFeature": "Login"
            }
          ],
          "permissions": [],
          "domainVerify": false
        }
      ]
    }
  ]
}
```

## extensionAbilities

The **extensionAbilities** tag represents the configuration of ExtensionAbilities, which is valid only for the current ExtensionAbility.

  **Table 9** extensionAbilities

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| name | Name of the ExtensionAbility. This name must be unique in the entire application. The value is a string with a maximum of 127 bytes.| String| No|
| srcEntry | Code path of the ExtensionAbility. The value is a string with a maximum of 127 bytes.| String| No|
| description | Description of the ExtensionAbility component, used to describe the component functions. The value is a string with a maximum of 255 bytes. It can be a resource index to support multiple languages.| String| Yes (initial value: left empty)|
| icon | Icon of the ExtensionAbility. The value is the index of the icon resource file.| String| Yes (initial value: left empty)|
| label | Name of the ExtensionAbility displayed to users. The value must be a resource index to support multiple languages. It contains a maximum of 255 bytes.| String| Yes (initial value: left empty)|
| type | Type of the ExtensionAbility. The options are as follows:<br>- **form**: ExtensionAbility of a widget.<br>- **workScheduler**: ExtensionAbility of a deferred task.<br>- **inputMethod**: ExtensionAbility of an input method.<!--Del--><br>- **service**: service component running in the background.<!--DelEnd--><br>- **accessibility**: ExtensionAbility of an accessibility feature.<!--Del--><br>- **fileAccess**: ExtensionAbility for public data access, allowing files and folders to be provided for file management applications to display.<br>- **dataShare**: ExtensionAbility for data sharing.<br>- **staticSubscriber**: ExtensionAbility for static broadcast.<!--DelEnd--><br>- **wallpaper**: ExtensionAbility of the wallpaper.<br>- **backup**: ExtensionAbility for data backup.<br>- **enterpriseAdmin**: ExtensionAbility for [enterprise device management](../mdm/mdm-kit-admin.md). An enterprise device management application must have such ExtensionAbility.<!--Del--><br>- **window**: ExtensionAbility of a window. This type of ExtensionAbility creates a window during startup for which you can develop the GUI. The GUI you develop is combined with the windows of other applications through the **UIExtensionComponent**.<!--DelEnd--><br>- **thumbnail**: ExtensionAbility for obtaining file thumbnails. You can provide thumbnails for files of customized file types.<br>- **preview**: ExtensionAbility for preview. This type of ExtensionAbility can parse the file and display it in a window. You can combine the window with other application windows.<br>- **print**: ExtensionAbility for the print framework.<br>- **push**: ExtensionAbility for the push service.<br>- **driver**: ExtensionAbility for the driver framework. When an application configures an ExtensionAbility of the driver type, it is recognized as a driver application. Driver applications do not differentiate between users during installation, uninstall, and recovery. Moreover, when a new user account is created, the existing driver applications on the device are installed for that user. For example, when a sub-user is created, the driver applications already installed by the primary user is automatically installed for the sub-user. If a driver application is uninstalled for a sub-user, it is also removed for the primary user.<br>- **remoteNotification**: ExtensionAbility for remote notifications.<br>- **remoteLocation**: ExtensionAbility for remote location.<br>- **voip**: ExtensionAbility for VoIP calls.<br>- **action**: ExtensionAbility for custom service operations, which provides custom service operation templates based on UIExtension.<!--Del--><br>- **adsService**: ExtensionAbility for the ad service, which provides the ad service framework.<!--DelEnd--><br>- **embeddedUI**: embedded UI extension, which allows for UI embedding across processes.<br>- **insightIntentUI**: APIs that enable applications to be called by Celia intents so as to be displayed in windows.<br>- **ads**: ExtensionAbility for the ad service, which is used with the AdComponent to display the ad page in other applications. This option is only available for device manufacturers.<br>- **photoEditor**: ExtensionAbility for the image editing service, which provides an image editing service template based on UIExtension.<br>- **appAccountAuthorization**: ExtensionAbility for application account authorization extension, which is used to process account authorization requests, for example, account login authorization.<br>- **autoFill/password**: ExtensionAbility for automatically filling in usernames and passwords.<br>- **hms/account**: ExtensionAbility for application account management.<!--Del--><br>- **sysDialog/atomicServicePanel**: ExtensionAbility that provides the basic capability for building an atomic service panel. It is implemented based on UIExtensionAbility.<br>- **sysDialog/userAuth**: ExtensionAbility for local user authentication.<br>- **sysDialog/common**: ExtensionAbility for common dialog boxes.<br>- **sysDialog/power**: ExtensionAbility for the shutdown and restart dialog boxes.<br>- **sysDialog/print**: ExtensionAbility for the print modals.<br>- **sysDialog/meetimeCall**: ExtensionAbility for MeeTime calls.<br>- **sysDialog/meetimeContact**: ExtensionAbility for MeeTime contacts.<br>- **sysPicker/meetimeMessage**: ExtensionAbility for MeeTime messages.<br>- **sysPicker/meetimeContact**: ExtensionAbility for the MeeTime contact list.<br>- **sysPicker/meetimeCallLog**: ExtensionAbility for the MeeTime call history.<br>- **sysPicker/share**: ExtensionAbility for sharing.<br>- **sysPicker/mediaControl**: ExtensionAbility for media control.<br>- **sysPicker/photoPicker**: ExtensionAbility that allows a third-party application to use the corresponding UIExtensionType to open the gallery photo picker.<br>- **sysPicker/filePicker**: ExtensionAbility for file download dialog boxes.<br>- **sysPicker/audioPicker**: ExtensionAbility for the audio management dialog box.<br>- **sysPicker/photoEditor**: ExtensionAbility for the photo editor.<br>- **sys/commonUI**: non-common ExtensionAbility, which provides embedded display or dialog boxes closely related to service attributes.<!--DelEnd--><br>- **autoFill/smart**: ExtensionAbility for scenario-specific autofill services.<!--Del--><br>- **uiService**: ExtensionAbility for pop-up window service, which creates a window during the startup and supports bidirectional communication.<!--DelEnd--> <!--RP9--><!--RP9End--><br>- **recentPhoto**: ExtensionAbility for recommended recent photos.<br>- **fence**: ExtensionAbility for geofencing.<br>- **callerInfoQuery**: ExtensionAbility for enterprise contacts.<br>- **assetAcceleration**: ExtensionAbility for resource pre-download.<br>- **formEdit**: ExtensionAbility for widget editing.<br>- **distributed**: ExtensionAbility for distributed extension.<br>- **liveForm**: [ExtensionAbility](../reference/apis-form-kit/js-apis-app-form-LiveFormExtensionAbility.md) for interactive widgets. This tag is supported since API version 20.<br>- **appService**: [AppServiceExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-appServiceExtensionAbility.md) for background services, which provides lifecycle callbacks to manage background services, including creation, destruction, connection, and disconnection. This tag is supported since API version 20.<!--Del--><br>- **awc/webpage**: ExtensionAbility for common web browsing.<br>- **awc/newsfeed**: ExtensionAbility for news feed.<br>- **selection**: [ExtensionAbility](../reference/apis-basic-services-kit/js-apis-selectionInput-selectionExtensionAbility-sys.md) for word selection. This tag is supported since API version 20.<br>**NOTE**<br>For **service**, **adsService**, **staticSubscriber**, **window**, **sys/commonUI**, **fileAccess**, **selection**, **sysDialog**, **sysPicker**, **dataShare**, and **uiService** types, this configuration does not take effect in third-party applications but in system applications.<!--DelEnd--> | String| No|
| permissions | Permissions required for another application to access the ExtensionAbility.<br>Each permission name is an array element, with a maximum of 255 bytes. For details about the value, see [Application Permissions](../security/AccessToken/app-permissions.md).| String array| Yes (initial value: left empty)|
| appIdentifierAllowList | List of applications that are allowed to start the ExtensionAbility.<br>Each **appIdentifier** is an array element. For details about **appIdentifier**, see [What is appIdentifier](../quick-start/common_problem_of_application.md#what-is-appidentifier).<br>**NOTE**<br>This tag is available only when the type of the ExtensionAbility is set to **appService**.<br>This tag is supported since API version 20.| String array| Yes (initial value: left empty)|
| readPermission | Permission required for reading data in the ExtensionAbility. The value is a string with a maximum of 255 bytes. This tag is available only when the type of the ExtensionAbility is set to **dataShare**.| String| Yes (initial value: left empty)|
| writePermission | Permission required for writing data to the ExtensionAbility. The value is a string with a maximum of 255 bytes. This tag is available only when the type of the ExtensionAbility is set to **dataShare**.| String| Yes (initial value: left empty)|
| uri | Data URI provided by the ExtensionAbility. The value is a string with a maximum of 255 bytes, in the reverse domain name notation.<br>**NOTE**<br>This tag is mandatory when the type of the ExtensionAbility is set to **dataShare**.| String| Yes (initial value: left empty)|
|skills | A set of [wants](../application-models/want-overview.md) that can be received by the ExtensionAbility.<br>Configuration rule: In an entry package, you can configure multiple **skills** attributes with the entry capability. (A **skills** attribute with the entry capability is the one that has **ohos.want.action.home** and **entity.system.home** configured.) The label and icon of the first ExtensionAbility that has **skills** configured are used as the label and icon of the entire service/application.<br>**NOTE**<br>The feature package of a service does not support the **skills** tag with the entry capability.<br>The feature package of an application supports the **skills** tag with entry capability.| Array| Yes (initial value: left empty)|
| [metadata](#metadata)| Metadata of the ExtensionAbility component.<br>**NOTE**<br>When **type** is set to **form**, this tag cannot be left empty. In addition, an object value **ohos.extension.form** must exist. Its corresponding resource value cannot be left empty and is the level-2 resource reference of the service widgets.| Object array| Yes (initial value: left empty)|
| exported | Whether the ExtensionAbility can be called by other applications.<br>- **true**: The ExtensionAbility can be called by other applications.<br>- **false**: The UIAbility cannot be called by other applications, not even by Ability Assistant.| Boolean| Yes (initial value: **false**)|
| extensionProcessMode | Multi-process instance model of the ExtensionAbility. Currently, this tag is effective only for UIExtensionAbilities and ExtensionAbilities extended from UIExtensionAbilities.<br>- **instance**: Each instance of the ExtensionAbility has a process.<br>- **type**: All instances of the ExtensionAbility run in the same process, separated from other ExtensionAbility instances.<br>- **bundle**: All instances of the ExtensionAbility run in the same process as instances of other ExtensionAbilities using the **bundle** model.<!--RP10--><!--RP10End--> | String| Yes (initial value: left empty)|
| dataGroupIds | Data group IDs of the ExtensionAbility. If the application where the current ExtensionAbility component is located also applies for a **dataGroupId** in the **groupIds** of the certificate applied by the AppGallery, the current ExtensionAbility component can share the directory generated by the **dataGroupId** with the application, therefore, the **dataGroupId** of the ExtensionAbility component takes effect only when it is configured in the **groupIds** tag in the signing certificate. This tag takes effect only when the ExtensionAbility component has an independent sandbox directory.<!--RP8--><!--RP8End--> | String array| Yes (initial value: left empty)|
| process | Name of the process where the component runs. This tag can be configured only when **type** is set to **embeddedUI**. For details, see "Statically specified process" in [Process Model](../application-models/process-model-stage.md#other-process-types).<br>**NOTE**<br>1. This tag takes effect only on [PCs/2-in-1 devices](./module-configuration-file.md#devicetypes) and [tablets](./module-configuration-file.md#devicetypes).<br>2. The UIAbility and ExtensionAbility components run in the same process when their tags are the same.<br>3. This tag is supported since API version 14.| String| Yes (initial value: left empty)|
| isolationProcess | Whether the ExtensionAbility component can run in an isolated process.<br>- **true**: The component can run in an isolated process.<br>- **false**: The component cannot run in an isolated process.<br>**NOTE**<br>This tag takes effect only when **type** of ExtensionAbility is set to **sys/commonUI** (for system applications only).<br>This tag is supported since API version 20.| Boolean| Yes (initial value: **false**)|

Example of the **extensionAbilities** structure:


```json
{
  "extensionAbilities": [
    {
      "name": "FormName",
      "srcEntry": "./form/MyForm.ts",
      "icon": "$media:icon",
      "label" : "$string:extension_name",
      "description": "$string:form_description",
      "type": "form",
      "permissions": ["ohos.permission.ACCESS_BLUETOOTH"],
      "readPermission": "",
      "writePermission": "",
      "exported": true,
      "uri":"scheme://authority/path/query",
      "skills": [{
        "actions": [],
        "entities": [],
        "uris": [],
        "permissions": []
      }],
      "metadata": [
        {
          "name": "ohos.extension.form",
          "resource": "$profile:form_config",
        }
      ],
      "extensionProcessMode": "instance",
      "dataGroupIds": [
        "testGroupId1"
      ]
    }
  ]
}
```

## shortcuts

The **shortcuts** tag provides the shortcut information of an application. The value is an array and consists of four sub-attributes: **shortcutId**, **label**, **icon**, and **wants**.

The **shortcut** information is specified in **metadata**, where:

- **name** indicates the name of the shortcut, identified by **ohos.ability.shortcuts**.

- **resource** indicates where the resources of the shortcut are stored.

**Table 10** Shortcuts

| Name| Description| Data Type | Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| shortcutId | ID of the shortcut. The value is a string with a maximum of 63 bytes. **This tag cannot be configured using the resource index ($string).**| String| No|
| label | Label of the shortcut, that is, the text description displayed for the shortcut. The value is a string with a maximum of 255 bytes. It can be descriptive content or a resource index.| String| Yes (initial value: left empty)|
| icon | Icon of the shortcut. The value is the index of the icon resource file.<br>**NOTE**<br>Icons are classified into single-layer icons and layered icons. A single-layer icon contains only one image, and a layered icon contains a foreground image and a background image. The following configurations are recommended:<br>1. Foreground image: a transparent layer whose icon size is 450 × 450 px and resource size is 1024 × 1024 px.<br>2. Background image: The size is 1024 × 1024 px.<br>| String| Yes (initial value: left empty)|
| visible | Whether the shortcut is visible. The value **true** indicates that the shortcut is visible; **false** indicates the opposite.<br>**NOTE**<br>This tag is supported since API version 20.<br>| Boolean| Yes (initial value: **true**)|
| [wants](#wants) | Wants to which the shortcut points. If the **startShortcut** API of **launcherBundleManager** is called, the first target component in the wants is started. As such, you are advised to configure only one element for **wants**.| Object| Yes (initial value: left empty)|


1. Configure the **shortcuts_config.json** file in **/resources/base/profile/**.

   ```json
   {
     "shortcuts": [
       {
         "shortcutId": "id_test1",
         "label": "$string:shortcut",
         "icon": "$media:aa_icon",
         "visible": true,
         "wants": [
           {
             "bundleName": "com.ohos.hello",
             "moduleName": "entry",
             "abilityName": "EntryAbility",
             "parameters": {
               "testKey": "testValue"
             }
           }
         ]
       }
     ]
   }
   ```

2. In the **abilities** tag of the **module.json5** file, configure the **metadata** tag for the UIAbility component to which a shortcut needs to be added so that the shortcut configuration file takes effect for the UIAbility.

   ```json
   {
     "module": {
       // ...
       "abilities": [
         {
           "name": "EntryAbility",
           "srcEntry": "./ets/entryability/EntryAbility.ets",
           // ...
           "skills": [
             {
               "entities": [
                 "entity.system.home"
               ],
               "actions": [
                 "ohos.want.action.home"
               ]
             }
           ],
           "metadata": [
             {
               "name": "ohos.ability.shortcuts",
               "resource": "$profile:shortcuts_config"
             }
           ]
         }
       ]
     }
   }
   ```
### wants

The **wants** tag provides wants information for a shortcut.

**Table 11** wants

| Name| Description| Data Type | Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| bundleName | Target bundle name of the shortcut.| String| Yes|
| moduleName | Target module name of the shortcut.| String| Yes|
| abilityName| Target ability name of the shortcut.| String| Yes|
| parameters | Custom data when the shortcut is started. The data must be strings. A key can contain a maximum of 1024 characters.| Object| Yes|

Example of the **data** structure:

```json
{
  "wants": [
    {
      "bundleName": "com.ohos.hello",
      "moduleName": "entry",
      "abilityName": "EntryAbility",
      "parameters": {
        "testKey": "testValue"
      }
    }
  ]
}
```

## distributionFilter

The **distributionFilter** tag defines the rules for distributing HAP files based on different device specifications, so that precise matching can be performed when the application market distributes applications.

> **NOTE**
> This tag is supported since API version 10. In earlier versions, the **distroFilter** tag is used.

- **Application scenario**: If a project has multiple entry-type modules and the values of **deviceType** configured for these modules overlap, you need to use this tag to distinguish the modules. In the following example, both entry-type modules support the tablet type, and therefore the **distributionFilter** tag is required.
  ```json
  // Device types supported by entry1
  {
    "module": {
      "name": "entry1",
      "type": "entry",
      "deviceTypes" : [
        "tv",
        "tablet"
      ]
    }
  }
  ```
  ```json
  // Device types supported by entry2
  {
    "module": {
      "name": "entry2",
      "type": "entry",
      "deviceTypes" : [
        "car",
        "tablet"
      ]
    }
  }
  ```

- **Configuration rule**: This tag consists of four attributes, including [screenShape](#screenshape), [screenWindow](#screenwindow), [screenDensity](#screendensity), and [countryCode](#countrycode). For details, see the following table.

  During distribution, a unique HAP is determined based on the mapping between **deviceTypes** and the preceding attributes.

  * When configuring this tag, include at least one of the attributes.
  * If any one or more attributes are set for one entry-type module, the same attributes must be set for all other entry-type modules.
  * The **screenShape** and **screenWindow** attributes are available only for lite wearables.

- **Configuration**: This tag must be configured in the **/resources/base/profile** directory and be referenced in the **resource** tag of **metadata**.


**Table 12** distributionFilter

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| [screenShape](#screenshape) | Supported screen shapes.| Object array| Yes (initial value: left empty)|
| [screenWindow](#screenwindow) | Supported application window resolutions.| Object array| Yes (initial value: left empty)|
| [screenDensity](#screendensity)| Pixel density of the screen, in dots per inch (DPI).| Object array| Yes (initial value: left empty)|
| [countryCode](#countrycode)| Code of the country or region to which the application is to be distributed. The value is subject to the ISO-3166-1 standard. Enumerated definitions of multiple countries and regions are supported.| Object array| Yes (initial value: left empty)|

### screenShape

**Table 13** screenShape

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| policy | Rule for the sub-attribute value.<br>- **exclude**: Exclude the matches of the sub-attribute value.<br>- **include**: Include the matches of the sub-attribute value.| String| No|
| value | Screen shapes. The value can be **circle**, **rect**, or both. For example, different HAPs can be provided for a smart watch with a circular face and that with a rectangular face.| String array| No|

### screenWindow

**Table 14** screenWindow

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| policy | Rule for the sub-attribute value. Currently, the value can only be **include**.<br>- **include**: Include the matches of the sub-attribute value.| String| No|
| value | Screen width and height, in pixels. The value is an array of supported width and height pairs, each in the "width * height" format, for example, **"454 * 454"**.| String array| No|

### screenDensity

**Table 15** screenDensity

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| policy | Rule for the sub-attribute value.<br>- **exclude**: Exclude the matches of the sub-attribute value.<br>- **include**: Include the matches of the sub-attribute value.| String| No|
| value | Pixel density of the screen, in DPI. The options are as follows:<br>- **sdpi**: small-scale DPI. This value is applicable to devices with a DPI range of (0, 120].<br>- **mdpi**: medium-scale DPI. This value is applicable to devices with a DPI range of (120, 160].<br>- **ldpi**: large-scale DPI. This value is applicable to devices with a DPI range of (160, 240].<br>- **xldpi**: extra-large-scale DPI. This value is applicable to devices with a DPI range of (240, 320].<br>- **xxldpi**: extra-extra-large-scale DPI. This value is applicable to devices with a DPI range of (320, 480].<br>- **xxxldpi**: extra-extra-extra-large-scale DPI. This value is applicable to devices with a DPI range of (480, 640].| String array| No|

### countryCode

**Table 16** countryCode

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| policy | Rule for the sub-attribute value.<br>- **exclude**: Exclude the matches of the sub-attribute value.<br>- **include**: Include the matches of the sub-attribute value.| String| No|
| value | Code of the country or region to which the application is to be distributed.| String array| No|


Example:

1. Configure the **distributionFilter_config.json** file (this file name is customizable) in **resources/base/profile** under the development view.
   ```json
   {
     "distributionFilter": {
       "screenShape": {
         "policy": "include",
         "value": [
           "circle",
           "rect"
         ]
       },
       "screenWindow": {
         "policy": "include",
         "value": [
           "454*454",
           "466*466"
         ]
       },
       "screenDensity": {
         "policy": "exclude",
         "value": [
           "ldpi",
           "xldpi"
         ]
       },
       "countryCode": {// Distribution in China is supported.
         "policy": "include",
         "value": [
           "CN"
         ]
       }
     }
   }
   ```


2. Configure **metadata** in the **module** tag in the **module.json5** file.


    ```json
    {
      "module": {
        // ...
        "metadata": [
          {
            "name": "ohos.module.distribution",
            "resource": "$profile:distributionFilter_config",
          }
        ]
      }
    }
    ```


## testRunner

The **testRunner** tag represents the supported test runner.

**Table 17** testRunner

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| name | Name of the test runner object. The value is a string with a maximum of 255 bytes.| String| No|
| srcPath | Code path of the test runner. The value is a string with a maximum of 255 bytes.	| String| No|

Example of the **testRunner** structure:


```json
{
  "module": {
    // ...
    "testRunner": {
      "name": "myTestRunnerName",
      "srcPath": "etc/test/TestRunner.ts"
    }
  }
}
```

## atomicService

The **atomicService** tag represents the atomic service configuration. It is available only when **bundleType** is set to **atomicService** in the **app.json** file.

**Table 18** atomicService

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| preloads | List of modules to preload.| Object array| Yes (initial value: left empty)|
| resizeable | Whether an atomic service supports adaptive window. If this tag is set to **true**, the width and height of the window automatically adapt to the screen when the tablet is switched from landscape mode to portrait mode or the foldable screen is folded.<br>**NOTE**<br>1. This tag is supported since API version 20.<br>2. If the window has adapted to the tablet (landscape) and foldable screen (unfolded), you are advised to set this tag to **true**.<br>- **true**: The atomic service supports adaptive window.<br>- **false**: The atomic service does not support adaptive window.| Boolean| Yes (initial value: **false**)|


**Table 19** preloads

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| moduleName | Name of the module to be preloaded when the current module is loaded in the atomic service. The value must match an existing module other than the current one. It contains a maximum of 31 bytes.| String| No|


Example of the **atomicService** structure:

```json
{
  "module": {
    "atomicService": {
      "preloads":[
        {
          "moduleName":"feature"
        }
      ],
      "resizeable": true
    }
  }
}
```

## dependencies

The **dependencies** tag identifies the list of shared libraries that the module depends on when it is running.

**Table 20** dependencies

| Name   | Description                          | Data Type| Initial Value Allowed|
| ----------- | ------------------------------ | -------- | ---------- |
| bundleName  | Name of the shared bundle on which the current module depends. The value is a string of 7 to 128 bytes.| String  | Yes (initial value: left empty)|
| moduleName  | Module name of the shared bundle on which the current module depends. The value is a string with a maximum of 31 bytes.| String  | No|
| versionCode | Version number of the shared bundle on which the current module depends. The value ranges from 0 to 2147483647.| Number    | Yes (initial value: left empty)|

Example of the **dependencies** structure:

```json
{
  "module": {
    "dependencies": [
      {
        "bundleName":"com.share.library",
        "moduleName": "library",
        "versionCode": 10001
      }
    ]
  }
}
```

## proxyData

The **proxyDatas** tag provides the list of data proxies provided by the module. It can be configured only for entry and feature modules.

**Table 21** proxyData
| Name   | Description                          | Data Type| Initial Value Allowed|
| ----------- | ------------------------------ | -------- | ---------- |
| uri | URI of the data proxy. The URIs configured for different data proxies must be unique and must be in the *datashareproxy://Current application bundle name/xxx* format. The value is a string with a maximum of 255 bytes.| String  | No|
| requiredReadPermission  | Permission required for reading data from the data proxy. If it is not specified, other applications will not be able to use the data proxy. For non-system applications, the level of the set permission must be **system_basic** or **system_core**. For system applications, the permission level is not limited. For details about the permission levels, see [Application Permissions](../security/AccessToken/app-permissions.md). The value is a string with a maximum of 255 bytes.| String  | Yes (initial value: left empty)|
| requiredWritePermission | Permission required for writing data to the data proxy. If it is not specified, other applications will not be able to use the data proxy. For non-system applications, the level of the set permission must be **system_basic** or **system_core**. For system applications, the permission level is not limited. For details about the permission levels, see [Application Permissions](../security/AccessToken/app-permissions.md). The value is a string with a maximum of 255 bytes.| String  | Yes (initial value: left empty)|
| [metadata](#metadata)| Metadata of the data proxy. Only the **name** and **resource** tags can be configured.| Object| Yes (initial value: left empty)|

Example of the **proxyData** structure:

```json
{
  "module": {
    "proxyData": [
      {
        "uri":"datashareproxy://com.ohos.datashare/event/Meeting",
        "requiredReadPermission": "ohos.permission.ACCESS_BLUETOOTH",
        "requiredWritePermission": "ohos.permission.ACCESS_BLUETOOTH",
        "metadata": {
          "name": "datashare_metadata",
          "resource": "$profile:datashare"
        }
      }
    ]
  }
}
```

## routerMap

The **routerMap** tag represents the path to the routing table for the module.

The **routerMap** configuration file provides the routing table information of the module. The value of the **routerMap** tag is an array.

**Table 22** routerMap

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| name          | Name of the page to be redirected to. The value is a string with a maximum of 1023 bytes.| String | No      |
| pageSourceFile| Path of the page in the module. The value is a string with a maximum of 255 bytes.| String| No |
| buildFunction | Function decorated by @Builder. The function describes the UI of the page. The value is a string with a maximum of 1023 bytes.| String | No  |
| [data](#data)  | Custom data of the string type. You can extend capabilities and obtain the content from the **data** field in **routerMap** of the [HapModuleInfo](../reference/apis-ability-kit/js-apis-bundleManager-hapModuleInfo.md) object. This tag has been parsed by the system. Each piece of custom data cannot exceed 128 bytes.| Object  | Yes (initial value: left empty)  |
| [customData](#customdata)  | Custom data of any type. You can extend capabilities and obtain the content from the **customData** field in **routerMap** of the [HapModuleInfo](../reference/apis-ability-kit/js-apis-bundleManager-hapModuleInfo.md) object. You have to call the **JSON.parse** function to parse this tag. The total length of the value cannot exceed 4096 bytes. | Object  | Yes (initial value: left empty)  |

Example:

1. Define a routing table configuration file under **resources/base/profile** in the development view. The file name can be customized, for example, **router_map.json**.

    ```json
    {
      "routerMap": [
        {
          "name": "DynamicPage1",
          "pageSourceFile": "src/main/ets/pages/pageOne.ets",
          "buildFunction": "myFunction",
          "customData": {
            "stringKey": "data1",
            "numberKey": 123,
            "booleanKey": true,
            "objectKey": {
              "name": "test"
            },
            "arrayKey": [
              {
                "id": 123
              }
            ]
          }
        },
        {
          "name": "DynamicPage2",
          "pageSourceFile": "src/main/ets/pages/pageTwo.ets",
          "buildFunction": "myBuilder",
          "data": {
            "key1": "data1",
            "key2": "data2"
          }
        }
      ]
    }
    ```

2. Define the **routerMap** tag under **module** of the **module.json5** file, set it to point to the defined routing table configuration file, for example, set it to **"routerMap": "$profile:router_map"**.

### data

The **data** tag is used to configure custom string data in the routing table.

Example of the **data** structure:

```json
{
  "routerMap": [
    {
      "name": "DynamicPage",
      "pageSourceFile": "src/main/ets/pages/pageOne.ets",
      "buildFunction": "myBuilder",
      "data": {
        "key1": "data1",
        "key2": "data2"
      }
    }
  ]
}
```

### customData

The **data** tag represents custom data in the routing table.
The **customData** tag is used to configure custom data of any type.

Example of the **customData** structure:

```json
{
  "routerMap": [
    {
      "name": "DynamicPage",
      "pageSourceFile": "src/main/ets/pages/pageOne.ets",
      "buildFunction": "myBuilder",
      "customData": {
        "stringKey": "data1",
        "numberKey": 123,
        "booleanKey": true,
        "objectKey": {
          "name": "test"
        },
        "arrayKey": [
          {
            "id": 123
          }
        ]
      }
    }
  ]
}
```

## appEnvironments

The **appEnvironments** tag represents the application environment variables configured for the module.

**Table 23** appEnvironments

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| name          | Name of the environment variable. The value is a string with a maximum of 4096 bytes.| String | Yes (initial value: left empty)|
| value         | Value of the environment variable. The value is a string with a maximum of 4096 bytes.      | String | Yes (initial value: left empty)|

Example of the **appEnvironments** structure:

```json
{
  "module": {
    "appEnvironments": [
      {
        "name":"name1",
        "value": "value1"
      }
    ]
  }
}
```


## hnpPackages

The **hnpPackages** tag provides information about the native software package contained in the application.

**Table 24** hnpPackages

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| package | Name of the native software package.| String| No|
| type | Type of the native software package. The options are as follows:<br>- **public**: public type.<br>- **private**: private type. | String| No|

Example of the **hnpPackages** structure:


```json
{
  "module" : {
    "hnpPackages": [
      {
        "package": "hnpsample.hnp",
        "type": "public"
      }
    ]
  }
}
```

## fileContextMenu

The **fileContextMenu** tag provides configuration options for the context menu (displayed upon right-clicking) of the current HAP. It is a profile that contains the context menu configuration registered by the application. This tag takes effect only on the PCs/2-in-1 devices. and can be configured only in entry modules.

Example of the **fileContextMenu** structure:

```json
{
  "module": {
    // ...
    "fileContextMenu": "$profile:menu" // Configured through the resource file in the profile
  }
}
```

Define the **menu.json** file under **resources/base/profile** in the development view. The file name (**menu.json** in this example) can be customized, but must be consistent with the information specified by the **fileContextMenu** tag. The file describes the items and response behavior of the context menu registered by the application.
The root node of the file is **fileContextMenu**, which is an object array and indicates the number of context menus registered by the current module. (The number must not exceed 5 per module and per application. If the number exceeds 5, only five random menus are parsed.)

**Table 25** fileContextMenu

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| abilityName | Name of the ability to be started for the context menu.| String| No|
| menuItem | Information displayed on the context menu. Naming rules:<br>Rule 1: [Action] + [Application name]. Example: **Open with {*application*}**, or **Open with {*application*} ({*plugin*})**.<br>Rule 2: [Action] + [Purpose]. Example: **Compress to {*file name*}**, **Compress to {*path*}**, or **Convert to {*format*} with {*application*}**.| Resource ID| No|
| menuHandler | Context menu handler. An ability can be used to create multiple shortcut menus. Each tag corresponds to one shortcut menu item, so you can customize the value of this tag to ensure that each tag is unique in the ability. When a user right-clicks a context menu to start an application, this tag is passed to the application as a parameter.| String| No|
| menuContext | Context required for displaying the context menu. Multiple contexts are supported.| Object array| No|

**Table 26** menuContext

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| menuKind | Condition in which the context menu is displayed. The options are as follows:<br>- **0**: blank area<br>- **1**: file<br>- **2**: folder<br>- **3**: file and folder| Number| No|
| menuRule | Operations that can trigger context menu. The options are as follows:<br>- **single**: Single file or folder is selected.<br>- **multi**: Multiple files or folders are selected.<br>- **both**: Both.| String| No (This tag is read when **menuKind** is set to **1** or **2**.)|
| fileSupportType | Supported types of files. The context item is displayed when the selected file list contains files of these types.<br>If the value of this tag is set to **["*"]**, the **fileNotSupportType** tag is read.<br>When the value is left empty, no processing is performed.| String array| No (This tag is read when **menuKind** is set to **1**.)|
| fileNotSupportType | 	Types of files not supported. The context item is not displayed when the selected file list contains files of these types.<br>This tag is read only when **menuKind** is set to **1** and **fileSupportType** is set to **["*"]**.| String array| Yes (initial value: left empty)|

Example of the **menu.json** file in the **resources/base/profile** directory:
```json
{
  "fileContextMenu": [
    {
      "abilityName": "EntryAbility",
      "menuItem": "$string:module_desc",
      "menuHandler": "openCompress",
      "menuContext": [
        {
          "menuKind": 0
        },
        {
          "menuKind": 1,
          "menuRule": "both",
          "fileSupportType": [
            ".rar",
            ".zip"
          ],
          "fileNotSupportType": [
            ""
          ]
        },
        {
          "menuKind": 2,
          "menuRule": "single"
        },
        {
          "menuKind": 3
        }
      ]
    }
  ]
}
```

**Response Behavior**

After a context menu is registered, the **More** option of the menu, when clicked, displays a sublist of menu items specified in **menuItem**. After you click any of the items, the file manager starts the third-party application using **startAbility** by default. In addition to the bundle name and ability name of the third-party application, the following tags are also passed in **parameter** of **want**:

**Table 27** parameter field in want

| Name| Value| Data Type|
| -------- | -------- | -------- |
| menuHandler | Value of **menuHandler** in the registration configuration file.| String|
| uriList | URIs for redirection when the user right-clicks files. If the context menu is displayed by right-clicking a blank area, the value is null. If the context menu is displayed by right-clicking a single file, the array length is 1. If the context menu is displayed by right-clicking multiple files, the URIs of all files should be passed in.| String array|

## startWindow

This tag points to a profile resource and is used to define the configuration file **start_window.json** of the UIAbility startup page in **resources/base/profile**. If this tag is set, the **startWindowIcon** and **startWindowBackground** tags do not take effect.<!--RP4--><br>**NOTE**<br>Since API version 20, this tag can be used to configure an enhanced starting window.<!--RP4End-->

**Table 28** startWindow

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| startWindowType | Visibility type of the UIAbility startup page.<br>This tag is supported only on 2-in-1 devices or tablets in freeform mode.<br>The options are as follows:<br>\- **REQUIRED_SHOW**: Mandatory display of the startup page. This setting is not affected by the setting of the **hideStartWindow** tag in [StartOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md#startoptions).<br>\- **REQUIRED_HIDE**: Mandatory hiding of the startup page. This setting is not affected by the setting of the **hideStartWindow** tag in [StartOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md#startoptions).<br>\- **OPTIONAL_SHOW**: The starting window is displayed by default, but it can be hidden if the **hideStartWindow** tag in [StartOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md#startoptions) is set to hide it.<br>\- The default value is **REQUIRED_SHOW**.<br>This tag is supported since API version 20.| String| Yes (initial value: **REQUIRED_SHOW**)|
| startWindowAppIcon | Index to the icon file of the UIAbility startup page. The value is a string with a maximum of 255 bytes.<br><!--RP12-->This tag is supported since API version 20.<!--RP12End-->| String| Yes (initial value: left empty)|
| startWindowIllustration | Index to the illustration file of the UIAbility startup page. The value is a string with a maximum of 255 bytes.<br><!--RP12-->This tag is supported since API version 20.<!--RP12End--> | String| Yes (initial value: left empty)|
| startWindowBrandingImage | Index to the brand logo file of the UIAbility startup page. The value is a string with a maximum of 255 bytes.<br><!--RP12-->This tag is supported since API version 20.<!--RP12End--> | String| Yes (initial value: left empty)|
| startWindowBackgroundColor | Index to the background color resource file of the UIAbility startup page. The value is a string with a maximum of 255 bytes.<br><!--RP12-->This tag is supported since API version 20.<!--RP12End--> | String| No|
| startWindowBackgroundImage | Index to the background image file of the UIAbility startup page. The value is a string with a maximum of 255 bytes.<br><!--RP12-->This tag is supported since API version 20.<!--RP12End--> | String| Yes (initial value: left empty)|
| startWindowBackgroundImageFit | Background image adaptation mode of the UIAbility startup page. The options are as follows:<br>- **Contain**: Proportionally scaled based on the aspect ratio, the image is fully contained within the display area.<br>- **Cover**: Proportionally scaled based on the aspect ratio, both width and height of the image are greater than or equal to that of the display area.<br>- **Auto**: adaptive display.<br>- **Fill**: The image fills the display area without any aspect ratio scaling applied.<br>- **ScaleDown**: The image is displayed in accordance with its aspect ratio, either scaled down or kept unchanged.<br>- **None**: The image is displayed in its original size.<br><!--RP12-->This tag is supported since API version 20.<!--RP12End--> | String| Yes (initial value: **Cover**)|
<!--RP13--><!--RP13End-->

Example of the **start_window.json** file in the **resources/base/profile** directory:
<!--RP14-->
```json
{
  "startWindowType": "REQUIRED_SHOW",
  "startWindowAppIcon": "$media:start_window_app_icon",
  "startWindowIllustration": "$media:start_window_illustration",
  "startWindowBrandingImage": "$media:start_window_branding_image",
  "startWindowBackgroundColor": "$color:start_window_back_ground_color",
  "startWindowBackgroundImage": "$media:start_window_back_ground_image",
  "startWindowBackgroundImageFit": "Cover"
}
```
<!--RP14End-->

## systemTheme

The **systemTheme** tag points to a profile resource, which is used to specify the system theme configuration file used by the current application. This tag is supported since API version 20.

Example:

```json
{
  "module": {
    // ...
    "systemTheme": "$profile:theme_config", // Configure through the resource file of profile.
  }
}
```

Define the **theme_config.json** configuration file in **resources/base/profile**. The file name is customizable, for example, **theme_config** or **theme_config_1**. The configuration file specifies the system theme used by the current application, corresponding to the information specified by the **systemTheme** tag.

  **Table 29** theme_config.json


| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| systemTheme | System theme used by the current application. The value is an enum of the system theme name. The options are as follows:<br>- **$ohos:theme:ohos_theme**: default system theme| String| No|

Example of the **theme_config.json** file in the **resources/base/profile** directory:
```json
{
  "systemTheme": "$ohos:theme:ohos_theme"
}
```

<!--RP5--><!--RP5End-->

<!--Del-->
## definePermissions

The **definePermissions** tag represents a set of permissions defined for the system resource HAP, which cannot be custom permissions. For details about how to define permissions, see the [config.json](https://gitcode.com/openharmony/utils_system_resources/blob/master/systemres/main/config.json) file.

**Table 30** definePermissions

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| name | Name of the permission. The value can contain a maximum of 255 bytes.| String| No|
| grantMode | Permission grant mode. The options are as follows:<br>- **system_grant**: The permission is automatically granted by the system after the application is installed.<br>- **user_grant**: The permission is dynamically requested when needed and must be granted by the user.| String| Yes (initial value: **"system_grant"**)|
| availableLevel | Permission type. The options are as follows:<br>- **system_core**: system core permission.<br>- **system_basic**: basic system permission.<br>- **normal**: normal permission, which can be requested by all applications.| String| Yes (initial value: **"normal"**)|
| provisionEnable | Whether the permission (including high-level permissions) can be requested through a profile. The value **true** indicates that you can request permissions through a profile; **false** indicates the opposite.| Boolean| Yes (initial value: **true**)|
| distributedSceneEnabled | Whether the permission can be used in distributed scenarios. The value **true** indicates that you can use the permission in distributed scenarios; **false** indicates the opposite.| Boolean| Yes (initial value: **false**)|
| label | Brief description of the permission. The value is a resource index to the description.| String| Yes (initial value: left empty)|
| description | Detailed description of the permission. The value is a string or a resource index to the description.| String| Yes (initial value: left empty)|

Example of the **definePermissions** structure:

```json
{
  "module" : {
    "definePermissions": [
      {
        "name": "ohos.permission.ACCESS_BLUETOOTH",
        "grantMode": "system_grant",
        "availableLevel": "system_core",
        "provisionEnable": true,
        "distributedSceneEnable": false,
        "label": "$string:EntryAbility_label"
      }
    ]
  }
}
```
<!--DelEnd-->
