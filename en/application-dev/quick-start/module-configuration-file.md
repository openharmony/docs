# module.json5 Configuration File

<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @memghaiyang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=74dbad5c7db60e1e7acbdd97ecfcb9536c7d7b13 translatedAt=2026-08-13T09:10:14.953Z pushedAt=2026-08-13T15:12:15.712Z -->

A module-level configuration file provides the basic configuration of the module, information about the **UIAbility** and **ExtensionAbility** components, and permissions required during application running for the compilation tool, OS, and AppGallery. Each module must contain a **module.json5** configuration file, which is stored in the ***project or module name*/src/main/module.json5** directory, for example, **entry/src/main/module.json5**.

>
> **NOTE**
>
> Using the sample code in the actual project may cause a compilation failure. You need to configure the code as required. For example, if the resource file referenced by the **$** symbol does not exist in the project, you need to manually add the resource file or replace it with the actual one.
>
> In the configuration file, fields can be repeated. The last field is used.
>

## Configuration File Example

This topic gives an overview of the **module.json5** configuration file. To start with, let's go through an example of what this file contains.

<!-- @[module_all](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/ModuleConfigurationFile01/entry/src/main/module.json5) -->

``` JSON5
{
  "module": {
    "name": "entry",
    "type": "entry",
    "description": "$string:module_desc",
    "mainElement": "EntryAbility",
    "deviceTypes": [
      "tv",
      "tablet"
    ],
    "deliveryWithInstall": true,
    "pages": "$profile:main_pages", // Resource configuration, pointing to the main_pages.json configuration file defined in the profile.
    "appStartup": "$profile:app_startup_config",
    "metadata": [
      {
        "name": "string",
        "value": "string",
        "resource": "$profile:distributionFilter_config"
      },
      // ...
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
          // ...
          {
            "entities": [
              "entity.system.home"
            ],
            "actions": [
              "ohos.want.action.home"
            ]
          }
        ],
        // ...
        "continueType": [
          "continueType1"
        ],
        "continueBundleName": [
          "com.example.myapplication1",
          "com.example.myapplication2"
        ],
      }
    ],
    "requestPermissions": [
      {
        "name": "ohos.permission.ACCESS_BLUETOOTH",
        "reason": "$string:reason",
        "usedScene": {
          "abilities": [
            "EntryAbility"
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
    "fileContextMenu": "$profile:menu", // Resource configuration, which points to the menu.json configuration file defined in the profile.
    "crossAppSharedConfig": "$profile:shared_config",
    "skillProfiles": [
      {
        "name": "my-skill",
        "abilityName": "EntryAbility",
        "version": "1.0.0",
        "visibility": "public",
        "srcEntries": [
          "../../my-skill/scripts/Test.ets"
        ],
        "permissions": []
      }
    ],
    // ...
  }
}
```

## Tags in the Configuration File

As shown above, the **module.json5** file contains several tags.

  **Table 1** Tags in the module.json5 file

| Attribute Name | Description | Data Type | Whether It Can Be Omitted |
| -------- | -------- | -------- | -------- |
| name | Identifies the name of the current module. The name must be unique within the entire app. The naming rules are as follows&nbsp;:<br/>-&nbsp;It consists of letters, digits, and underscores, and must start with a letter.<br/>-&nbsp;The maximum length is 128 bytes.<br/>You can change the name during an app upgrade, but the app must adapt to the migration of the module-related data directories. For details, see [@ohos.file.fs (File Management)](../reference/apis-core-file-kit/js-apis-file-fs.md).<br/>**Note:**<br/>When creating a module in DevEco Studio, the module name cannot exceed 31 characters. If this length does not meet your requirements, you can change this tag in the configuration file. | string | This tag cannot be omitted. |
| type | Identifies the type of the current module. The supported values are as follows:<br/>-&nbsp;entry: the main module of the app.<br/>-&nbsp;feature: the dynamic feature module of the app.<br/>-&nbsp;har: the static shared package module.<br/>-&nbsp;shared: the dynamic shared package module.<br/>-&nbsp;skill: the skill package module, used to define the skill capabilities of an AI agent. A module of this type must have the [skillProfiles](#skillprofiles) tag configured. Only when [bundleType](./app-configuration-file.md#tags-in-the-configuration-file) of the app is set to skill, that is, when bundleType in the app.json5 configuration file is skill, can the type of the module be set to skill. In this case, the app can contain only one module. This tag is supported since API version 26.0.0. It takes effect only for preset apps. | string | This tag cannot be omitted. |
| srcEntry | Identifies the code path of the AbilityStage component. For details, see [AbilityStage Component Container](../application-models/abilitystage.md). The value is a string of no more than 127 bytes. | string | This tag can be omitted. The default value is empty. |
| description | Identifies the description of the current module. You can use this tag to describe the functions and purpose of the current module. The value is a string of no more than 255 bytes, and can be in the string resource index format. | string | This tag can be omitted. The default value is empty. |
| <!--DelRow-->process | Identifies the process name of the current module. The value is a string of no more than 31 bytes. If process is configured under the HAP tag, all UIAbility, DataShareExtensionAbility, and ServiceExtensionAbility of the module run in this process.<br/>**Note:**<br/>This takes effect only when the [multi-instance privilege](../../device-dev/subsystems/subsys-app-privilege-config-guide.md#privileges-that-can-be-configured-by-device-vendors) is enabled. The configuration does not take effect for third-party applications. | string | This tag can be omitted. The default value is bundleName under the app tag in the app.json5 file. |
| mainElement | Identifies the name of the entry UIAbility of the current module. The value is a string of no more than 255 bytes. For details, see [Configuration Priority and Build Policy](./layered-image.md#configuration-priority-and-build-policy) in Configuring the App Icon and Name. | string | This tag can be omitted. The default value is empty. |
| [deviceTypes](#devicetypes) | Identifies the types of devices on which the current module can run.<br/>**Note:**<br/>When there are multiple modules, the configuration of each module can be different, but each must include the device types on which it will be installed to ensure normal running. | string array | This tag cannot be omitted. |
| deliveryWithInstall | Indicates whether the current module is installed when the user actively installs the app, that is, whether the HAP/HSP corresponding to the module is installed together with the app.<br/>-&nbsp;true: installed together with the app.<br/>-&nbsp;false: not installed together with the app.<!--RP11--><!--RP11End--> | boolean | When the current module type is HAP or HSP, this tag cannot be omitted. |
| installationFree | Indicates whether the current module supports the installation-free feature.<br/>-&nbsp;true: the installation-free feature is supported and the installation-free constraints are met.<br/>-&nbsp;false: the installation-free feature is not supported. | boolean | This tag can be omitted. It is automatically generated during compilation and building, and manual configuration does not take effect.<br/>**Note:**<br/>When [bundleType](./app-configuration-file.md#tags-in-the-configuration-file) is an atomic service, this tag is automatically set to true. Otherwise, it is automatically set to false. |
| virtualMachine | Identifies the target virtual machine type on which the current module runs, for cloud distribution, such as the app market and distribution center. If the target virtual machine type is the ArkTS engine, the value is "ark+version number". | string | This tag can be omitted. Manual configuration does not take effect, and it is automatically generated during compilation and building. |
| [pages](#pages) | Identifies the profile resource of the current module, used to list the information of each page. The value is a string of no more than 255 bytes. | string | This tag can be omitted. The default value is empty. |
| [metadata](#metadata) | Identifies the custom metadata of the current module. You can configure [distributionFilter](#distributionfilter), [shortcuts](#shortcuts), and other information by referencing resources. It takes effect only for the current module, UIAbility, and ExtensionAbility. | object array | This tag can be omitted. The default value is empty. |
| [abilities](#abilities) | Identifies the configuration information of UIAbility in the current module. It takes effect only for the current UIAbility. | object array | This tag can be omitted. The default value is empty. |
| [extensionAbilities](#extensionabilities) | Identifies the configuration information of ExtensionAbility in the current module. It takes effect only for the current ExtensionAbility. | object array | This tag can be omitted. The default value is empty. |
| <!--DelRow-->[definePermissions](#definepermissions) | Identifies the permissions defined by the system resource HAP. Custom permissions of apps are not supported. | object array | This tag can be omitted. The default value is empty. |
| [requestPermissions](../security/AccessToken/declare-permissions.md#declaring-permissions-in-the-configuration-file)| Identifies the set of permissions that the current app needs to request from the system at runtime. | object array | This tag can be omitted. The default value is empty. |
| [testRunner](#testrunner) | Identifies the configuration of the test framework used to test the current module. For details, see [test](../tools/aa-tool.md#test). | object | This tag can be omitted. The default value is empty. |
| [atomicService](#atomicservice)| Identifies the configuration related to the atomic service when the current app is an atomic service.| object | This tag can be omitted. The default value is empty.  |
| [dependencies](#dependencies)| Identifies the list of shared libraries that the current module depends on at runtime.| object array | This tag can be omitted. The default value is empty. Manual configuration does not take effect, and it is automatically generated during compilation and building.  |
| targetModuleName | Identifies the target module specified by the current package. The value is a string of no more than 128 bytes, and Chinese characters are not supported. A module with this tag configured has the overlay feature. It applies only to dynamic shared packages (HSPs). |string|This tag can be omitted. The default value is empty.|
| targetPriority | Identifies the priority of the current module. The value range is 1 to 100. This tag needs to be configured only after the targetModuleName tag is configured. It applies only to dynamic shared packages (HSPs). |integer value|This tag can be omitted. The default value is 1.|
| [proxyData](#proxydata) | Identifies the list of data proxies provided by the current module.| object array | This tag can be omitted. The default value is empty.|
| isolationMode | Identifies the multi-process configuration item of the current module. The supported values are as follows:<br/>-&nbsp;nonisolationFirst: run in a non-isolated process first.<br/>-&nbsp;isolationFirst: run in an isolated process first.<br/>-&nbsp;isolationOnly: run only in an isolated process.<br/>-&nbsp;nonisolationOnly: run only in a non-isolated process.<br/>**Note:**<br/>1. Only 2in1 and tablet devices support setting the current module to an isolated process.<br/>2. This tag takes effect only for HAPs. |string|This tag can be omitted. The default value is nonisolationFirst.|
| generateBuildHash |Indicates whether the current HAP/HSP has a hash value generated by the packaging tool. When set to true, if the app versionCode remains unchanged during an OTA upgrade, the system can determine whether the app needs to be upgraded based on the hash value.<br/>This tag is enabled only when the generateBuildHash tag in the [app.json5 file](./app-configuration-file.md) is false.<br/>**Note:**<br/>This tag takes effect only for preset apps.|boolean|This tag can be omitted. The default value is false.|
| compressNativeLibs | When packaging a HAP, this tag indicates whether the libs library is packaged into the HAP in a compressed manner.<br/>-&nbsp;true: the libs library is stored in a compressed manner.<br/>-&nbsp;false: the libs library is stored in an uncompressed manner. | boolean | This tag can be omitted. When packaging a HAP, the default value is false. |
| extractNativeLibs | Indicates whether the libs library is extracted to the app installation directory when the app is installed. When both compressNativeLibs and extractNativeLibs are set to false, the app is installed without extracting the libs library. In other scenarios, the app is installed with the libs library extracted.<br/>**Note:**<br/>This tag is supported since API version 20. | boolean | This tag can be omitted. The default value is true. |
| libIsolation | Indicates whether a directory named after the module is generated under the libs directory to store .so files, so as to distinguish the .so files of different HAPs in the same app and prevent .so file conflicts.<br/>-&nbsp;true: the .so files of the current HAP are stored in the path named after the module under the libs directory.<br/>-&nbsp;false: the .so files of the current HAP are stored directly in the libs directory. | boolean | This tag can be omitted. The default value is false. |
| [fileContextMenu](#filecontextmenu) | Identifies the context menu configuration item of the current HAP. It is a profile file resource. The value is a string of no more than 255 bytes.<br/>**Note:**<br/>It takes effect only on PC/2in1 devices.<br/>It can be configured only in modules of the entry type. | string | This tag can be omitted. The default value is empty. |
| querySchemes | Identifies the URL schemes that the current app is allowed to query for redirection. It can be configured only in modules of the entry type. Each string value is no more than 128 bytes.<br/>**Note:**<br/>Since API version 21, a maximum of 200 URL schemes can be configured. In API version 20 and earlier, a maximum of 50 URL schemes can be configured.  | string array | This tag can be omitted. The default value is empty. |
| [routerMap](#routermap) | Identifies the path of the route table configured for the current module. The value is a string of no more than 255 bytes. | string | This tag can be omitted. The default value is empty. |
| [appEnvironments](#appenvironments) | Identifies the app environment variables configured for the current module. It can be configured only in modules of the entry and feature types. | object array | This tag can be omitted. The default value is empty. |
| appStartup | Identifies the configuration path of the [startup framework](../application-models/app-startup.md) of the current module. It can be configured only in modules of the entry type.<br>Since API version 18, configuration in HSPs and HARs is supported.<br>Since API version 20, configuration in modules of the feature type is supported. | string | This tag can be omitted. The default value is empty. |
| [hnpPackages](#hnppackages) | Identifies the information of the native software packages included in the current app. It can be configured only in modules of the entry type. | object array | This tag can be omitted. The default value is empty. |
| [systemTheme](#systemtheme) | Identifies the system theme configuration item currently in use. It can be configured only in modules of the entry type. The value is a string of no more than 255 bytes.<br/>**Note:** <br/>This tag is supported since API version 20. | string | This tag can be omitted. The default value is empty. |
| abilitySrcEntryDelegator | Identifies the name of the UIAbility to which the current module needs to be redirected. It is used together with the abilityStageSrcEntryDelegator tag to specify the redirection target.<br/>**Note:**<br/>1. This tag is supported since API version 17.<br/>2. This tag does not take effect when the UIAbility is started through the [startAbilityByCall](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#startabilitybycall) API.<br/>3. This tag cannot be configured in the configuration file of a HAR, and redirection to the UIAbility of a HAR is not supported. | string | This tag can be omitted. The default value is empty. |
| abilityStageSrcEntryDelegator | Identifies the name of the module corresponding to the UIAbility to which the current module needs to be redirected (it cannot be the name of the current module). It is used together with the abilitySrcEntryDelegator tag to specify the redirection target.<br/>**Note:**<br/>1. This tag is supported since API version 17.<br/>2. This tag does not take effect when the UIAbility is started through the [startAbilityByCall](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#startabilitybycall) API.<br/>3. This tag cannot be configured in the configuration file of a HAR, and redirection to the UIAbility of a HAR is not supported. | string | This tag can be omitted. The default value is empty. |
| crossAppSharedConfig | Identifies the name of the configuration file for cross-app shared configuration. The value is a string of no more than 255 bytes. It is used to publish the configuration for other apps to read. It takes effect when the app is installed and becomes invalid when the app is uninstalled. For details about how to use it, see [Configuring the Publisher](../database/share-config.md#configuring-the-publisher).<br/>**Note:**<br/>This tag is supported since API version 20. | string | This tag can be omitted. The default value is empty. |
| formWidgetModule | In an [independent widget package](../form/arkts-ui-widget-creation.md#method-2-creating-a-standalone-package), the app package needs to configure this tag to associate with the widget package. The value is the module name of the widget package, corresponding to the name tag in the module.json5 file of the widget package. For details about how to use it, see [FormExtensionAbility Configuration](../form/arkts-ui-widget-configuration.md#formextensionability-configuration).<br/>**Note:**<br/> 1. This tag is supported since API version 20.<br/> 2. This tag takes effect only in the app package of an independent widget package, and the corresponding widget package module must have the formExtensionModule tag configured. | string | This tag can be omitted. The default value is empty.  |
| formExtensionModule | In an [independent widget package](../form/arkts-ui-widget-creation.md#method-2-creating-a-standalone-package), the widget package needs to configure this tag to associate with the app package. The value is the module name of the app package, corresponding to the name tag in the module.json5 file of the app package. For details about how to use it, see [Standalone Widget Package Configuration](../form/arkts-ui-widget-configuration.md#standalone-widget-package-configuration).<br/>**Note:**<br/>1. This tag is supported since API version 20.<br/>2. This tag takes effect only in the widget package of an independent widget package, and the corresponding app package module must have the formWidgetModule tag configured. | string | This tag can be omitted. The default value is empty.  |
| shareFiles | Identifies the configuration file path of the shared directory in the app sandbox. It is used to provide a secure open scope for app files and protect app assets. It can be configured only in modules of the entry type. The value is a string of no more than 255 bytes. For details about how to use it, see [App Shared Directory Configuration](../file-management/share-app-file-configuration.md).<br/>**Note:**<br/>This tag is supported since API version 23. | string | This tag can be omitted. The default value is empty.  |
| [skillProfiles](#skillprofiles) | Identifies the skill configuration information of the current module, used to define the skill capabilities of an AI agent. It can be configured only in modules whose type field is entry, feature, shared, or skill. For modules of the skill type, this tag must be configured.<br/>**Note:**<br/>This tag is supported since API version 26.0.0. | object array | For modules of the skill type, this tag cannot be omitted. For modules of other types, this tag can be omitted. The default value is empty. |
| [executableBinaryPaths](#executablebinarypaths) | Identifies the path information of executable binary files in the app.<br/>**Note:** <br/>1. This tag is supported since API version 24.<br/>2. It takes effect only on PC/2in1 devices. | object array | This tag can be omitted. The default value is empty. |
| uiSyntax<sup>(deprecated)</sup> | Identifies the syntax type of the JS&nbsp;Component defined by the current Module&nbsp;syntax.<br/>-&nbsp;hml: indicates that the JS&nbsp;Component is developed using hml/css/js.<br/>-&nbsp;ets: indicates that the JS&nbsp;Component is developed using the ArkTS declarative syntax.<br/>**Note:**<br/>This tag is deprecated since API version 9. | string | This tag can be omitted. The default value is hml. |
| srcEntrance<sup>(deprecated)</sup> | Identifies the code path corresponding to the current module. The value is a string of no more than 127 bytes.<br/>**Note:**<br/>This tag is deprecated since API version 9. Use the srcEntry field instead. | string | This tag can be omitted. The default value is empty. |

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
| Default device| default | Default device type. For details, see [Standard-System Development Boards](../../device-dev/dev-board-on-the-master.md#standard-system-development-boards).|

<!--RP2End-->

Example of the **deviceTypes** structure:

<!-- @[module_deviceTypes](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/ModuleConfigurationFile01/myHapName/src/main/module.json5) -->

``` JSON5
{
  "module": {
    "name": "myHapName",
    "type": "feature",
    "deviceTypes": [
      "tv",
      "tablet"
    ],
    // ...
  }
}
```

## pages

The **pages** tag is a profile that represents information about specified pages.

<!-- @[module_pages](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/ModuleConfigurationFile01/entry/src/main/module.json5) -->

``` JSON5
{
  "module": {
    // ...
    "pages": "$profile:main_pages", // Resource configuration, pointing to the main_pages.json configuration file defined in the profile.
    // ...
  }
}
```

Define the **main_pages.json** file under **resources/base/profile** in the development view. The file name (**main_pages** in this example) can be customized, but must be consistent with the information specified by the **pages** tag. The file lists the page information of the current application, including the route information and the window-related configuration.

  **Table 3** pages

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| src | Route information about all pages in the module, including the page path and page name. The page path is relative to the **src/main/ets** directory of the current module. The value is a string array, each element of which represents a page.| String array| No|
| window | Window-related configuration.| Object| Yes (initial value: left empty)|

  **Table 4** window

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| designWidth | Baseline width for page design. The size of an element is scaled by the actual device width.| Number| Yes (initial value: **720px**)|
| autoDesignWidth | Whether to automatically calculate the baseline width for page design. If it is set to **true**, the **designWidth** attribute becomes invalid. The baseline width is calculated based on the device width and screen density. If it is set to **false**, the baseline width uses the value of **designWidth**.| Boolean| Yes (initial value: **false**)|

```json
{
  "src": [
    "pages/Index"
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

<!-- @[module_metadata](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/ModuleConfigurationFile01/entry/src/main/module.json5) -->

``` JSON5
{
  "module": {
    // ...
    "metadata": [
      // ...
      {
        "name": "pageConfig",
        "value": "main page config of application",
        "resource": "$profile:main_pages" // Resource configuration, pointing to the main_pages.json configuration file defined in the profile.
      }
    ],
    // ...
  }
}
```

## abilities

The **abilities** tag represents the **UIAbility** configuration of the module, which is valid only for the current **UIAbility** component.

  **Table 6** abilities

<!--Table: 15%; 60%; 10%; 15%-->

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| name | Name of the **UIAbility**, which must be unique in the entire application. The value is a string with a maximum of 127 bytes. It must start with a letter and can contain letters, digits, underscores (_), and periods (.).| String| No|
| srcEntry | Code path of the **UIAbility**. The value is a string with a maximum of 127 bytes.| String| No|
| [launchType](../application-models/uiability-launch-type.md) | Launch type of the **UIAbility**. The options are as follows:<br>- **multiton**: A **UIAbility** instance is created each time the **UIAbility** is started.<br>- **singleton**: A **UIAbility** instance is created only when the **UIAbility** is started for the first time.<br>- **specified**: You can determine whether to create a **UIAbility** instance when the application is running.<br>- **standard**: original name of **multiton**. The effect is the same as that multiton mode. <!--RP1--><!--RP1End--> | String| Yes (initial value: **"singleton"**)|
| description | Description of the **UIAbility** component, used to describe the component functions. The value is a string with a maximum of 255 bytes. It is advised to use a resource index to support multiple languages.| String| Yes (initial value: left empty)|
| icon | Icon of the current UIAbility component. The value is the index of an icon resource file. Both single-layer icons and layered icons are supported. For the configuration rules and examples, see [Configuring an Application Icon and Label](layered-image.md). | String | This tag can be omitted, and the default value is empty. |
| label | Name of the current UIAbility component displayed to users. The value is the index of a string resource to support multiple languages, and it is a string of no more than 255 bytes. For details, see [Configuring an Application Icon and Label](layered-image.md). | String | This tag can be omitted, and the default value is empty. |
| permissions | Permissions required for another application to access the **UIAbility** component. When other applications access the **UIAbility**, they need to apply for the corresponding permissions.<br>Each array element is a permission name with a maximum of 255 bytes. For details about the value, see [Application Permissions](../security/AccessToken/app-permissions.md).| String array| Yes (initial value: left empty)|
| [metadata](#metadata)|Metadata information of the **UIAbility**. For details about the typical use scenarios, see [metadata](../windowmanager/window-config-m.md#metadata).| Object array| Yes (initial value: left empty)|
| exported | Whether the **UIAbility** component can be started by other applications.<br>- **true**: The **UIAbility** component can be started by other applications. (It is recommended that this tag be set to **true** for the entry **UIAbility**.)<br>- **false**: The **UIAbility** component can be started only by the same application or an application with the ohos.permission.START_INVISIBLE_ABILITY permission (only system applications can request this permission).<br> For example, if this attribute is set to **false**, the **UIAbility** component can be started through the application icon, shortcut, or push notification on the home screen which has the permission. However, it cannot be started by the Ability Assistant, which does not have this permission.| Boolean| Yes (initial value: **false**)|
| continuable | Whether the **UIAbility** can be continued on another device.<br>- **true**: The **UIAbility** can be continued on another device.<br>- **false**: The **UIAbility** cannot be continued on another device.| Boolean| Yes (initial value: **false**)|
| [skills](#skills) | A set of [wants](../application-models/want-overview.md) that can be received by the **UIAbility**.<br>Configuration rules:<br>- For HAPs of the entry type, you can configure multiple **skills** tags with the entry capability for an application. (A **skills** tag with the entry capability is the one that has **ohos.want.action.home** and **entity.system.home** configured.)<br>- For HAPs of the feature type, you can configure the **skills** tag with the entry capability for an application, but not for a service.| Object array| Yes (initial value: left empty)|
| backgroundModes | Continuous tasks of the **UIAbility**.<br>For details about the continuous task types, see [Continuous Task (ArkTS)](../task-management/continuous-task.md).| String array| Yes (initial value: left empty)|
| [startWindow](#startwindow)| Profile resource of the **UIAbility** startup page. The value is a string with a maximum of 255 bytes. If this tag is set, the **startWindowIcon** and **startWindowBackground** tags do not take effect.<!--RP4--><br>**NOTE**<br>Since API version 20, this tag can be used to configure an enhanced starting window.<!--RP4End--> | String| Yes (initial value: left empty)|
| startWindowIcon | Index to the icon file of the **UIAbility** startup page. The value is a string with a maximum of 255 bytes.| String| No|
| startWindowBackground | Index to the background color resource file of the **UIAbility** startup page. The value is a string with a maximum of 255 bytes.<br>Example: **$color:red**.| String| No|
| removeMissionAfterTerminate | Whether to remove the relevant mission from the mission list after the **UIAbility** is destroyed.<br>- **true**: Remove the relevant mission from the mission list after the **UIAbility** is destroyed.<br>- **false**: Do not remove the relevant mission from the task mission list after the **UIAbility** is destroyed.<br>**NOTE**<br>This attribute is invalid in freeform window mode on 2-in-1 devices and tablets, and tasks are removed by default.| Boolean| Yes (initial value: **false**)|
| allowSelfRedirect | Whether the application can be redirected to itself through <!--RP16-->[App Linking](../application-models/app-linking-startup.md)<!--RP16End-->.<br>- **true**: Self-redirection is allowed.<br>- **false**: Self-redirection is not allowed.<br>**NOTE**<br>This tag is supported since API version 23.| Boolean| Yes (initial value: **true**)|
| orientation | Startup direction of the **UIAbility** component. The enum and startup direction resource index can be configured.<br>The enum values are as follows:<br>- **unspecified**: automatically determined by the system.<br>- **landscape**: landscape mode.<br>- **portrait**: portrait mode.<br>- **follow_recent**: rotation mode following the background window.<br>- **landscape_inverted**: inverted landscape mode.<br>- **portrait_inverted**: inverted portrait mode.<br>- **auto_rotation**: determined by the sensor.<br>- **auto_rotation_landscape**: determined by the sensor in the horizontal direction, including landscape and inverted landscape modes.<br>- **auto_rotation_portrait**: determined by the sensor in the vertical direction, including portrait and inverted portrait modes.<br>- **auto_rotation_restricted**: determined by the sensor when the sensor switch is enabled.<br>- **auto_rotation_landscape_restricted**: determined by the sensor in the horizontal direction, including landscape and inverted landscape modes, when the sensor switch is enabled.<br>- **auto_rotation_portrait_restricted**: determined by the sensor in the vertical direction, including portrait and inverted portrait modes, when the sensor switch is enabled.<br>- **locked**: auto-rotation disabled.<br>- **auto_rotation_unspecified**: auto-rotation controlled by the switch and determined by the system.<br>- **follow_desktop**: following the orientation of the home screen.<br>To configure the startup direction resource index, the value should be a string with a maximum of 255 bytes, for example, **$string:orientation**.<br>**NOTE**<br>- The startup direction resource index is supported since API version 14.| String| Yes (initial value: **"unspecified"**)|
| supportWindowMode | Window modes supported by the current UIAbility component. The supported values are as follows:<br/>-&nbsp;fullscreen: full-screen mode.<br/>-&nbsp;split: split-screen mode.<br/>-&nbsp;floating: floating window mode.<br/>When both fullscreen and split are configured in the [freeform window](../windowmanager/window-terminology.md#freeform-window) state, if the [targetAPIVersion](./app-configuration-file.md#tags-in-the-configuration-file) of the app is earlier than 15, the window starts in floating window mode; if the [targetAPIVersion](./app-configuration-file.md#tags-in-the-configuration-file) of the app is 15 or later, the window starts in full-screen mode.<br/>In addition, the window mode can be configured through metadata. For the configuration rules and priority, see [metadata](#metadata). | String array | This tag can be omitted, and the default value is<br/>["fullscreen",&nbsp;"split",&nbsp;"floating"]. |
| <!--DelRow-->priority | Priority of the **UIAbility** component. In the case of [implicit query](../application-models/explicit-implicit-want-mappings.md), **UIAbility** components with a higher priority are at the higher place of the returned list. The value ranges from 0 to 10. The greater the value, the higher the priority.<br>**NOTE**<br>For the configuration to take effect for third-party applications, you need to apply for the application privilege **AllowAbilityPriorityQueried**. For details, see [Application Privilege Configuration](../../device-dev/subsystems/subsys-app-privilege-config-guide.md).| Integer| Yes (initial value: **0**)|
| maxWindowRatio | Maximum aspect ratio supported by the **UIAbility** component. The minimum value is **0**.| Number| Yes (initial value: maximum aspect ratio supported by the platform)|
| minWindowRatio | Minimum aspect ratio supported by the **UIAbility** component. The minimum value is **0**.| Number| Yes (initial value: minimum aspect ratio supported by the platform)|
| maxWindowWidth | Maximum window width supported by the **UIAbility**, in vp.<br>The value cannot be less than the value of **minWindowWidth** or greater than the maximum window width allowed by the platform. For details about the window size, see [Constraints](../windowmanager/window-overview.md#constraints).| Number| Yes (initial value: maximum window width supported by the platform)|
| minWindowWidth | Minimum window width supported by the **UIAbility**, in vp.<br>The value cannot be less than the minimum window width allowed by the platform or greater than the value of **maxWindowWidth**. For details about the window size, see [Constraints](../windowmanager/window-overview.md#constraints).| Number| Yes (initial value: minimum window width supported by the platform)|
| maxWindowHeight | Maximum window height supported by the **UIAbility**, in vp.<br>The value cannot be less than the value of **minWindowHeight** or greater than the maximum window height allowed by the platform. For details about the window size, see [Constraints](../windowmanager/window-overview.md#constraints).| Number| Yes (initial value: maximum window height supported by the platform)|
| minWindowHeight | Minimum window height supported by the **UIAbility**, in vp.<br>The value cannot be less than the minimum window height allowed by the platform or greater than the value of **maxWindowHeight**. For details about the window size, see [Constraints](../windowmanager/window-overview.md#constraints).| Number| Yes (initial value: minimum window height supported by the platform)|
| excludeFromMissions | Whether the **UIAbility** component is displayed in Recents.<br>- **true**: not displayed in Recents.<br>- **false**: displayed in Recents.<br>**NOTE**<br>Configurations of third-party applications do not take effect; the current configurations are only valid for system applications. To make system application configurations take effect, you need to apply for the application privilege<!--Del-->** AllowAbilityExcludeFromMissions**. For details, see [Application Privilege Configuration](../../device-dev/subsystems/subsys-app-privilege-config-guide.md)<!--DelEnd-->. Privilege application is not open to third-party applications.| Boolean| Yes (initial value: **false**)|
| recoverable | Whether the current UIAbility component can be restored to the original UI after an app fault is detected. For details, see [Development of Application Recovery](../dfx/apprecovery-guidelines.md).<br/>-&nbsp;true: The original UI can be restored after a fault is detected.<br/>-&nbsp;false: The original UI cannot be restored after a fault is detected. | Boolean | This tag can be omitted, and the default value is false. |
| <!--DelRow-->unclearableMission | Whether the **UIAbility** is unclearable in Recents.<br>- **true**: The **UIAbility** is unclearable in Recents.<br>- **false**: The **UIAbility** is clearable in Recents.<br>**NOTE**<br>This configuration does not take effect for third-party applications but for system applications. For the configuration to take effect for system applications, you need to apply for the application privilege **AllowMissionNotCleared**. For details, see [Application Privilege Configuration](../../device-dev/subsystems/subsys-app-privilege-config-guide.md).| Boolean| Yes (initial value: **false**)|
| isolationProcess | Whether the component can run in an isolated process.<br>- **true**: The component can run in an isolated process.<br>- **false**: The component cannot run in an isolated process.<br>**NOTE**<br>The **UIAbility** can serve as an isolated process on 2-in-1 devices and tablets.| Boolean| Yes (initial value: **false**)|
| excludeFromDock | Whether the **UIAbility** can be hidden from the dock.<br>- **true**: The **UIAbility** can be hidden from the dock.<br>- **false**: The **UIAbility** cannot be hidden from the dock.<br>**NOTE**<br>The configuration of this tag does not take effect.| Boolean| Yes (initial value: **false**)|
| preferMultiWindowOrientation | Multi-window orientation of the **UIAbility**.<br>- **default**: default value. Do not set this parameter to the default value. You are advised to set this parameter for other applications.<br>- **portrait**: portrait. This option is recommended for games in portrait mode.<br>- **landscape**: landscape. This option is recommended for games in landscape mode. With this option, the floating window and upper and lower split screens are supported in landscape mode.<br>- **landscape_auto**: automatically landscape. This option is recommended for video applications. It must be used together with the **enableLandScapeMultiWindow/disableLandScapeMultiWindow** API.| String| Yes (initial value: **default**)|
| continueType | Continuation type of the **UIAbility**.| String array| Yes (initial value: name of the **UIAbility**)|
| continueBundleName | List of other applications that support cross-device migration.<br>**NOTE**<br>This parameter cannot be set to the application bundle name. It is used only for migration with different bundle names.<br>This tag is supported since API version 13.| String array| Yes (initial value: left empty)|
| process | Name of the process where the component runs. For details, see "Statically specified process" in [Process Model (Stage Model)](../application-models/process-model-stage.md#other-process-types).<br>**NOTE**<br>1. This tag takes effect only on [PCs/2-in-1 devices](./module-configuration-file.md#devicetypes) and [tablets](./module-configuration-file.md#devicetypes).<br>2. The **UIAbility** component and the **ExtensionAbility** component whose type is **embeddedUI** run in the same process when their tags are the same.<br>3. This tag is supported since API version 14.| String| Yes (initial value: left empty)|

Example of the **abilities** structure:

<!-- @[module_abilities](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/ModuleConfigurationFile01/myHapName/src/main/module.json5) -->

``` JSON5
{
  // ...
    "abilities": [
      {
        "name": "EntryAbility",
        "srcEntry": "./ets/entryability/EntryAbility.ets",
        "launchType": "singleton",
        "description": "$string:description_main_ability",
        "icon": "$media:layered_image",
        "label": "$string:EntryAbility_label",
        "permissions": [],
        "metadata": [],
        "exported": true,
        "continuable": true,
        "skills": [
          {
            "actions": [
              "ohos.want.action.home"
            ],
            "entities": [
              "entity.system.home"
            ],
            "uris": []
          }
        ],
        "backgroundModes": [
          "dataTransfer"
        ],
        "startWindowIcon": "$media:icon",
        "startWindowBackground": "$color:red",
        "removeMissionAfterTerminate": true,
        "allowSelfRedirect": true, // This tag is supported starting from API version 23.
        "orientation": "$string:orientation",
        "supportWindowMode": [
          "fullscreen",
          "split",
          "floating"
        ],
        "maxWindowRatio": 3.5,
        "minWindowRatio": 0.5,
        "maxWindowWidth": 2560,
        "minWindowWidth": 1400,
        "maxWindowHeight": 300,
        "minWindowHeight": 200,
        "excludeFromMissions": false,
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
      }
    ],
    // ...
}
```

## skills

The **skills** tag represents the feature set of [wants](../application-models/want-overview.md) that can be received by the **UIAbility** or **ExtensionAbility** component.

For example, when downloading a PDF file in a browser, you can configure the **skills** tag to open the specified PDF file. For details, see [Using startAbility to Start a File Application](../application-models/file-processing-apps-startup.md).

  **Table 7** skills

<!--Table: 15%; 60%; 10%; 15%-->

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| actions | Actions of wants that can be received, which can be predefined or customized.<br>You are advised not to configure multiple **actions** for a **skill**. Otherwise, the expected scenario may not be matched. For details, see [Common action and entities Values](../application-models/actions-entities.md).| String array| Yes (initial value: left empty)|
| entities | Entities of wants that can be received.<br>You are advised not to configure multiple **entities** for a **skill**. Otherwise, the expected scenario may not be matched. For details, see [Common action and entities Values](../application-models/actions-entities.md).| String array| Yes (initial value: left empty)|
| uris | URIs that match the wants.| Object array| Yes (initial value: left empty)|
| permissions | Permissions required for another application to access the **UIAbility** or **ExtensionAbility** component.<br>Each array element is a permission name with a maximum of 255 bytes. For details about the value, see [Application Permissions](../security/AccessToken/app-permissions.md).| String array| Yes (initial value: left empty)|
| domainVerify | Whether to enable <!--RP7-->[domain name verification](../application-models/app-linking-startup.md#working-principles)<!--RP7End-->.<br>- **true**: Domain name verification is enabled.<br>- **false**: Domain name verification is disabled.| Boolean| Yes (initial value: **false**)|

  **Table 8** uris

> **NOTE**
>
> The following tags of the string type cannot be configured using resource indexes (**$string**).

<!--Table: 15%; 60%; 10%; 15%-->

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| scheme | Scheme of the URI, such as HTTP, HTTPS, file, and FTP.<br>**NOTE**<br>This tag is case-insensitive when it is used for implicit Want matching since API version 18.| String| Yes when only **type** is set in **uris** (initial value: left empty)|
| host | Host address of the URI. This tag is valid only when **scheme** is set. Common methods:<br>- domain name, for example, **example.com**.<br>- IP address, for example, **10.10.10.1**.<br>**NOTE**<br>This tag is case-insensitive when it is used for implicit Want matching since API version 18.| String| Yes (initial value: left empty)|
| port | Port number of the URI. For example, the default HTTP port number is 80, the default HTTPS port number is 443, and the default FTP port number is 21. This tag takes effect only when both **scheme** and **host** are configured.| String| Yes (initial value: left empty)|
| path&nbsp;\|&nbsp;pathStartWith&nbsp;\|&nbsp;pathRegex | Path of the URI. **path**, **pathStartWith**, and **pathRegex** represent different matching modes between the paths in the URI and the want. Set any one of them as needed. **path** indicates full matching, **pathStartWith** indicates prefix matching, and **pathRegex** indicates regular expression matching. This tag takes effect only when both **scheme** and **host** are configured.| String| Yes (initial value: left empty)|
| type | Data type that matches the want. The value complies with the Multipurpose Internet Mail Extensions (MIME) and [UniformDataType](../reference/apis-arkdata/js-apis-data-uniformTypeDescriptor.md#uniformdatatype) specifications. This tag can be configured together with **scheme** or configured separately.| String| Yes (initial value: left empty)|
| utd | Standardized data type that matches the Want. For details, see [@ohos.data.uniformTypeDescriptor (Uniform Data Definition and Description)](../reference/apis-arkdata/js-apis-data-uniformTypeDescriptor.md). This field is applicable to scenarios such as sharing.| String| Yes (initial value: left empty)|
| maxFileSupported | Maximum number of files of a specified type that can be received or opened at a time. This tag is applicable to scenarios such as sharing and must be used together with **utd**.| Integer| Yes (initial value: **0**)|
| linkFeature | Feature type provided by the URI. It is used to implement redirection between applications. The value is a string with a maximum of 127 bytes. The number of **linkFeature** declared in a bundle cannot exceed 150. For details, see [Description of linkFeature](../application-models/app-uri-config.md#description-of-linkfeature)| String| Yes (initial value: left empty)|

Example of the **skills** structure:

>
> **NOTE**
>
> The following example is a common configuration. Some components and modules are different in actual configuration.<!--RP15--><!--RP15End--> For details, see the corresponding document.
>

<!-- @[module_abilities_skills](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/ModuleConfigurationFile01/entry/src/main/module.json5) -->

``` JSON5
{
  // ...
    "abilities": [
      {
        // ...
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
          },
          // ...
        ],
        // ...
      }
    ],
    // ...
}
```

## extensionAbilities

The **extensionAbilities** tag represents the configuration of **ExtensionAbilities**, which is valid only for the current **ExtensionAbility**.

  **Table 9** extensionAbilities

<!--Table: 15%; 60%; 10%; 15%-->

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| name | Name of the **ExtensionAbility**. This name must be unique in the entire application. The value is a string with a maximum of 127 bytes.| String| No|
| srcEntry | Code path of the **ExtensionAbility**. The value is a string with a maximum of 127 bytes.| String| No|
| description | Description of the **ExtensionAbility** component, used to describe the component functions. The value is a string with a maximum of 255 bytes. It can be a resource index to support multiple languages.| String| Yes (initial value: left empty)|
| icon | Icon of the **ExtensionAbility**. The value is the index of the icon resource file.| String| Yes (initial value: left empty)|
| label | Name of the **ExtensionAbility** displayed to users. The value must be a resource index to support multiple languages. It contains a maximum of 255 bytes.| String| Yes (initial value: left empty)|
| <!--DelRow-->priority | Priority of the **ExtensionAbility** component. In the case of [implicit query](../application-models/explicit-implicit-want-mappings.md), the higher the priority, the earlier the **ExtensionAbility** appears in the returned list. The value ranges from 0 to 10. The greater the value, the higher the priority.<br>**NOTE**<br>For the configuration to take effect for third-party applications, you need to apply for the application privilege **AllowAbilityPriorityQueried**. For details, see [Application Privilege Configuration](../../device-dev/subsystems/subsys-app-privilege-config-guide.md).| Integer| Yes (initial value: **0**)|
| type | Identifies the type of the current ExtensionAbility component. For details, see [type Tag](#type). | string | This tag is mandatory. |
| permissions | Permissions required for another application to access the **ExtensionAbility** component.<br>Each permission name is an array element, with a maximum of 255 bytes. For details about the value, see [Application Permissions](../security/AccessToken/app-permissions.md).| String array| Yes (initial value: left empty)|
| appIdentifierAllowList | Identifies the list of apps that are allowed to start this ExtensionAbility.<br/>Each array element is the appIdentifier of an app. For details about appIdentifier, see [What Is appIdentifier](../quick-start/common-problem-of-application.md#what-is-appidentifier).<br/>**Note:**<br/>This tag can be configured only when the type of the ExtensionAbility component is appService or embeddedUI.<br/>This tag is supported since API version 20.<br/>Since API version 26.0.0, embeddedUI supports this tag and allows configuring allow_all (allowing any app to start this ExtensionAbility). | string array | This tag is optional. The default value is empty. |
| readPermission | Permission required for reading data in the **ExtensionAbility**. The value is a string with a maximum of 255 bytes. This tag takes effect only when **type** of the preset **ExtensionAbility** of the system application is set to **dataShare**. The **dataShare** type is invalid for third-party applications.| String| Yes (initial value: left empty)|
| writePermission | Permission required for writing data to the **ExtensionAbility**. The value is a string with a maximum of 255 bytes. This tag takes effect only when **type** of the preset **ExtensionAbility** of the system application is set to **dataShare**. The **dataShare** type is invalid for third-party applications.| String| Yes (initial value: left empty)|
| uri | Data URI provided by the **ExtensionAbility**. The value is a string with a maximum of 255 bytes, in the reverse domain name notation.<br>**NOTE**<br>This tag is mandatory when the type of the **ExtensionAbility** is set to **dataShare**.| String| Yes (initial value: left empty)|
|skills | A set of [wants](../application-models/want-overview.md) that can be received by the **ExtensionAbility**.<br>Configuration rule: In an entry package, you can configure multiple **skills** attributes with the entry capability. (A **skills** attribute with the entry capability is the one that has **ohos.want.action.home** and **entity.system.home** configured.) The label and icon of the first **ExtensionAbility** that has **skills** configured are used as the label and icon of the entire service/application.<br>**NOTE**<br>The feature package of a service does not support the **skills** tag with the entry capability.<br>The feature package of an application supports the **skills** tag with entry capability.| Array| Yes (initial value: left empty)|
| [metadata](#metadata)| Metadata of the **ExtensionAbility** component.<br>**NOTE**<br>When **type** is set to **form**, this tag cannot be left empty. In addition, an object value **ohos.extension.form** must exist. Its corresponding resource value cannot be left empty and is the level-2 resource reference of the service widgets.| Object array| Yes (initial value: left empty)|
| exported | Whether the **ExtensionAbility** can be called by other applications.<br>- **true**: The **ExtensionAbility** can be called by other applications.<br>- **false**: The **UIAbility** cannot be called by other applications, not even by Ability Assistant.| Boolean| Yes (initial value: **false**)|
| extensionProcessMode | Identifies the process model of the current ExtensionAbility component. The supported configuration items vary depending on the type of the ExtensionAbility. The supported value range is as follows, and the default value is bundle.<br/>-&nbsp;instance: Each instance of this ExtensionAbility runs in a separate process.<br/>-&nbsp;type: All instances of this ExtensionAbility run in the same independent process, and run in a different process from ExtensionAbility component instances with other names.<br/>-&nbsp;bundle: The instances of this ExtensionAbility run in the same process as the ExtensionAbility instances with the same extensionType under the same bundle name.<!--Del--><br/>-&nbsp;callerInstance: The instances of this ExtensionAbility run in a separate process, and the process isolation granularity is the caller. Instances of the ExtensionAbility started by the same caller run in the same process, and instances of the ExtensionAbility started by different callers run in different processes. This tag is supported since API version 26.0.0.<!--DelEnd--><br/>For UIExtensionAbility and its subclasses, the three process models instance, type, and bundle are supported.<br/>For an ExtensionAbility of the appService type, the two process models type and bundle are supported.<!--Del--><br/>For an ExtensionAbility of the sysPicker/mediaControl type, the four process models bundle, type, instance, and callerInstance are supported.<!--DelEnd--><!--RP10--><!--RP10End--> | string | This tag is optional. The default value is bundle. |
| dataGroupIds | Data group IDs of the **ExtensionAbility**. If the application where the current **ExtensionAbility** component is located also applies for a **dataGroupId** in the **groupIds** of the certificate applied by the AppGallery, the current **ExtensionAbility** component can share the directory generated by the **dataGroupId** with the application, therefore, the **dataGroupId** of the **ExtensionAbility** component takes effect only when it is configured in the **groupIds** tag in the signing certificate. This tag takes effect only when the **ExtensionAbility** component has an independent sandbox directory.<!--RP8--><!--RP8End--> | String array| Yes (initial value: left empty)|
| process | Name of the process where the component runs. This tag can be configured only when **type** is set to **embeddedUI**. For details, see "Statically specified process" in [Process Model (Stage Model)](../application-models/process-model-stage.md#other-process-types).<br>**NOTE**<br>1. This tag takes effect only on [PCs/2-in-1 devices](./module-configuration-file.md#devicetypes) and [tablets](./module-configuration-file.md#devicetypes).<br>2. The **UIAbility** and **ExtensionAbility** components run in the same process when their tags are the same.<br>3. This tag is supported since API version 14.| String| Yes (initial value: left empty)|
| isolationProcess | Whether the **ExtensionAbility** component can run in an isolated process.<br>- **true**: The component can run in an isolated process.<br>- **false**: The component cannot run in an isolated process.<br>**NOTE**<br>This tag takes effect only when **type** of **ExtensionAbility** is set to **sys/commonUI** (for system applications only).<br>This tag is supported since API version 20.| Boolean| Yes (initial value: **false**)|
| skipAbilityStageLifecycle | Whether an **ExtensionAbility** component of the **backup** type skips [AbilityStage](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md) lifecycle callbacks.<br>- **true**: Skips the **AbilityStage** lifecycle and does not execute callbacks such as **onCreate** and **onDestroy**.<br>- **false**: Does not skip the **AbilityStage** lifecycle and executes lifecycle callbacks normally.<br>**NOTE**<br>1. This tag takes effect only when the type of the **ExtensionAbility** is **backup**.<br>2. This tag is supported starting from API version 26.0.0.| Boolean| Yes (initial value: **false**)|

Example of the **extensionAbilities** structure:

<!-- @[module_extensionAbilities](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/ModuleConfigurationFile01/myHapName/src/main/module.json5) -->

``` JSON5
{
  // ...
    "extensionAbilities": [
      {
        "name": "FormName",
        "srcEntry": "./ets/form/MyForm.ets",
        "icon": "$media:icon",
        "label" : "$string:extension_name",
        "description": "$string:form_description",
        "type": "form",
        "permissions": ["ohos.permission.ACCESS_BLUETOOTH"],
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
    ],
    // ...
}
```

### type

Indicates the type of the current ExtensionAbility component. The supported values are as follows:

<!--Table: 30%; 70%; -->

| Tag Value | Description |
| --- | -------- | 
|form|The ExtensionAbility of a widget.|
|workScheduler|The ExtensionAbility of a deferred task.|
|inputMethod|The ExtensionAbility of an input method.|
|share|The [ShareExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-shareExtensionAbility.md) that provides the content sharing processing capability.|
|service|The service component running in the background. A third-party configuration cannot install the app, and the privilege must be requested<!--Del--> (allowAppUsePrivilegeExtension). For details, see [Application Privilege Configuration](../../device-dev/subsystems/subsys-app-privilege-config-guide.md)<!--DelEnd-->. The privilege request is not open to third-party applications.|
|accessibility|The ExtensionAbility of accessibility capabilities.|
|fileAccess|The ExtensionAbility for public data access, which allows an application to provide files and folders for display by file management applications. The configuration does not take effect for third-party applications, and it is valid only in system applications.|
|dataShare|The ExtensionAbility for data sharing. A third-party configuration cannot install the app, and the privilege must be requested<!--Del--> (allowAppUsePrivilegeExtension). For details, see [Application Privilege Configuration](../../device-dev/subsystems/subsys-app-privilege-config-guide.md).<!--DelEnd-->. The privilege request is not open to third-party applications.|
|staticSubscriber|The ExtensionAbility of a static broadcast. The configuration does not take effect for third-party applications, and it is valid only in system applications.|
|fileShare|The ExtensionAbility for file sharing.<!--Del-->|
|sysPicker/camera|The ExtensionAbility that launches the camera picker.<!--DelEnd-->|
|vpn|The ExtensionAbility that provides [@ohos.app.ability.VpnExtensionAbility (Third-Party VPN Capability)](../reference/apis-network-kit/js-apis-VpnExtensionAbility.md) for developers.|
|wallpaper|The ExtensionAbility of wallpapers.|
|backup|The ExtensionAbility for data backup.|
|enterpriseAdmin|The ExtensionAbility for [enterprise device management](../mdm/mdm-kit-admin.md). An enterprise device management app must have an ExtensionAbility of this type.|
|window|This ExtensionAbility creates a window during startup to provide UI development for developers. The UI developed by developers is combined into the windows of other apps through the UIExtensionComponent control. The configuration does not take effect for third-party applications, and it is valid only in system applications.|
|thumbnail|The ExtensionAbility for obtaining file thumbnails. Developers can provide thumbnails for files of custom file types.|
|preview|This ExtensionAbility parses a file and displays it in a window. Developers can combine this window into the windows of other apps.|
|print|The ExtensionAbility of the print framework.|
|push|The ExtensionAbility for push.|
|driver|The ExtensionAbility of the driver framework. An app with an ExtensionAbility of the driver type configured is regarded as a driver app. A driver app does not distinguish users during installation, uninstallation, and restoration, and existing driver apps on the device are also installed when a new user is created. For example, when a child user is created, the existing driver apps of the primary user are installed by default. When a driver app is uninstalled on a child user, the corresponding driver app on the primary user is also uninstalled.|
|remoteNotification|The ExtensionAbility for remote notifications.|
|remoteLocation|The ExtensionAbility for remote location.|
|voip|The ExtensionAbility for network audio and video calls.|
|action|The ExtensionAbility of the custom operation business template, which provides developers with a custom operation business template based on UIExtension.|
|adsService|The ExtensionAbility of the advertising service, which provides the advertising service framework. The configuration does not take effect for third-party applications, and it is valid only in system applications.|
|embeddedCashier<sup>23+</sup>|The ExtensionAbility of the payment service. It is used together with the CashierComponent control to display the payment page in other apps. The configuration does not take effect for third-party applications, and it is valid only in system applications. It is supported only on TV devices, and the configuration does not take effect on other devices.|
|embeddedUI|The embedded UI extension capability, which provides the capability of embedding UIs across processes.|
|insightIntentUI|The extension capability that provides developers with content that can be invoked by system entries and presented in a window.|
|ads|The ExtensionAbility of the advertising service. It is used together with the AdComponent control to display the advertising page in other apps. It is supported only for device vendors.|
|photoEditor|The ExtensionAbility of the image editing service, which provides developers with an image editing business template based on UIExtension.|
|appAccountAuthorization|The ExtensionAbility of the app account authorization extension capability, used to process account authorization requests, such as account login authorization.|
|autoFill/password|The ExtensionAbility for the account and password autofill service, which supports data saving and filling.|
|hms/account|The ExtensionAbility of the app account management capability.|
|sysDialog/atomicServicePanel|The ExtensionAbility that provides the basic capability of building an atomic service panel. It is implemented based on UIExtensionAbility. The configuration does not take effect for third-party applications, and it is valid only in system applications.|
|sysDialog/userAuth|The ExtensionAbility for local user authentication. The configuration does not take effect for third-party applications, and it is valid only in system applications.|
|sysDialog/common|The ExtensionAbility of a general dialog box. The configuration does not take effect for third-party applications, and it is valid only in system applications.|
|sysDialog/power|The ExtensionAbility of the power-off and restart dialog box. The configuration does not take effect for third-party applications, and it is valid only in system applications.|
|sysDialog/print|The ExtensionAbility of the print modal dialog box. The configuration does not take effect for third-party applications, and it is valid only in system applications.|
|sysDialog/meetimeCall|The ExtensionAbility of MeeTime calls. The configuration does not take effect for third-party applications, and it is valid only in system applications.|
|sysDialog/meetimeContact|The ExtensionAbility of MeeTime contacts. The configuration does not take effect for third-party applications, and it is valid only in system applications.|
|sysDialog/meetimeMessage|The ExtensionAbility of MeeTime messages. The configuration does not take effect for third-party applications, and it is valid only in system applications.|
|sysPicker/meetimeContact|The ExtensionAbility of the MeeTime contact list. The configuration does not take effect for third-party applications, and it is valid only in system applications.|
|sysPicker/meetimeCallLog|The ExtensionAbility of the MeeTime call log list. The configuration does not take effect for third-party applications, and it is valid only in system applications.|
|sysPicker/share|The ExtensionAbility of system sharing. The configuration does not take effect for third-party applications, and it is valid only in system applications.|
|sysPicker/mediaControl|The ExtensionAbility of the casting component. The configuration does not take effect for third-party applications, and it is valid only in system applications.|
|sysPicker/photoPicker|A third-party application launches the gallery picker UI through the corresponding UIExtensionType. The configuration does not take effect for third-party applications, and it is valid only in system applications.|
|sysPicker/filePicker|The ExtensionAbility of the file download dialog box. The configuration does not take effect for third-party applications, and it is valid only in system applications.|
|sysPicker/audioPicker|The ExtensionAbility of the audio management dialog box. The configuration does not take effect for third-party applications, and it is valid only in system applications.|
|sysPicker/photoEditor|The ExtensionAbility of the image editing dialog box. The configuration does not take effect for third-party applications, and it is valid only in system applications.|
|sys/commonUI|A non-general ExtensionAbility that provides embedded display or dialog boxes strongly related to business attributes. The configuration does not take effect for third-party applications, and it is valid only in system applications.|
|autoFill/smart|The ExtensionAbility for the autofill service in contextual scenarios, which supports data saving and filling.|
|modularObject|The ExtensionAbility for [modular object](../application-models/modular-object-extension-overview.md) management. This tag is supported since API version 26.0.0.|
|uiService|The dialog box service component, which creates a Window during startup and supports bidirectional communication. The configuration does not take effect for third-party applications, and it is valid only in system applications. |
|recentPhoto|The ExtensionAbility for recent photo recommendations.|
|fence|The ExtensionAbility for geofencing.|
|callerInfoQuery|The ExtensionAbility for enterprise contact query.|
|assetAcceleration|The ExtensionAbility for resource pre-download.|
|formEdit|The ExtensionAbility for widget editing.|
|distributed|The ExtensionAbility for distributed extension.|
|liveForm<sup>20+</sup>|The [ExtensionAbility](../reference/apis-form-kit/js-apis-app-form-LiveFormExtensionAbility.md) of an interactive widget.|
|appService<sup>20+</sup>|The [AppServiceExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-appServiceExtensionAbility.md) that provides background service-related extension capabilities for apps, including lifecycle callbacks such as creation, destruction, connection, and disconnection of background services.|
|webNativeMessaging<sup>21+</sup>|The [ExtensionAbility](../reference/apis-arkweb/arkts-apis-web-webNativeMessagingExtensionAbility.md) that provides Web message communication capabilities for developers.|
|faultLog<sup>21+</sup>|The [ExtensionAbility](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-FaultLogExtensionAbility.md) for delayed fault notification.|
|notificationSubscriber<sup>22+</sup>|The [ExtensionAbility](../reference/apis-notification-kit/js-apis-notificationSubscriberExtensionAbility.md) that provides notification subscription-related functions.|
|crypto<sup>22+</sup>|The [ExtensionAbility](../security/UniversalKeystoreKit/huks-extension-ability-support-dev.md) for external key management extension.|
|partnerAgent<sup>23+</sup>|The [ExtensionAbility](../reference/apis-connectivity-kit/js-apis-fusionConnectivity-partnerAgentExtensionAbility.md) that provides device discovery and device offline notification functions based on Bluetooth communication technology.|
|contentEmbed<sup>24+</sup>|The [ExtensionAbility](../content-embed/content-embed-server-guidelines.md) of the object insertion editing framework.|
|selection|The [ExtensionAbility](../reference/apis-basic-services-kit/js-apis-selectionInput-selectionExtensionAbility.md) for text selection extension. Since API version 20, it is supported only for system applications, and the configuration does not take effect for third-party applications. Since API version 24, configuration by third-party applications is supported.|
|awc/webpage|The ExtensionAbility for general web page browsing.|
|awc/newsfeed|The ExtensionAbility of the news feed service.|
|assetCache<sup>24+</sup>|The ExtensionAbility that provides general app data caching capabilities. The configuration does not take effect for third-party applications, and it is valid only in system applications.|

<!--RP9--><!--RP9End-->

## shortcuts

The **shortcuts** tag provides the shortcut information of an application. The value is an array and consists of four sub-attributes: **shortcutId**, **label**, **icon**, and **wants**.

The **shortcut** information is specified in **metadata**, where:

- **name** indicates the name of the shortcut, identified by **ohos.ability.shortcuts**.

- **resource** indicates where the resources of the shortcut are stored.

<!--RP17--><!--RP17End-->

**Table 10** Shortcuts

<!--Table: 15%; 60%; 10%; 15%-->

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

2. In the **abilities** tag of the **module.json5** file, configure the **metadata** tag for the **UIAbility** component to which a shortcut needs to be added so that the shortcut configuration file takes effect for the **UIAbility**.

   <!-- @[module_abilities_metadata](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/ModuleConfigurationFile01/entry/src/main/module.json5)  -->

   ``` JSON5
   {
     "module": {
       // ...
       "abilities": [
         {
           "name": "EntryAbility",
           "srcEntry": "./ets/entryability/EntryAbility.ets",
           // ...
           "skills": [
             // ...
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
           ],
           // ...
         }
       ],
       // ...
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

Example of the **wants** tag:

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
> This tag is supported since API version 10. For API version 9 and earlier, the **distroFilter** tag is used.

- **Application scenario**: If a project has multiple entry-type modules and the values of **deviceType** configured for these modules overlap, you need to use this tag to distinguish the modules. In the following example, both entry-type modules support the tablet type, and therefore the **distributionFilter** tag is required.

  <!-- @[module_distributionFilter_01](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/ModuleConfigurationFile03/entry1/src/main/module.json5) -->

  ``` JSON5
  // Device types supported by entry1
  {
    "module": {
      "name": "entry1",
      "type": "entry",
      "deviceTypes": [
        "tv",
        "tablet"
      ],
      // ...
    }
  }
  ```

  <!-- @[module_distributionFilter_02](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/ModuleConfigurationFile02/entry2/src/main/module.json5) -->

  ``` JSON5
  // Device types supported by entry2
  {
    "module": {
      "name": "entry2",
      "type": "entry",
      "deviceTypes": [
        "tv",
        "tablet"
      ],
      // ...
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

<!--Table: 15%; 60%; 10%; 15%-->

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| policy | Rule for the sub-attribute value.<br>- **exclude**: Exclude the matches of the sub-attribute value.<br>- **include**: Include the matches of the sub-attribute value.| String| No|
| value | Identifies the pixel density (dpi: Dot Per Inch) of the screen. The options are as follows:<br>- **sdpi**: small-scale DPI. This value is applicable to devices with a DPI range of (0, 120].<br>- **mdpi**: medium-scale DPI. This value is applicable to devices with a DPI range of (120, 160].<br>- **ldpi**: large-scale DPI. This value is applicable to devices with a DPI range of (160, 240].<br>- **xldpi**: extra-large-scale DPI. This value is applicable to devices with a DPI range of (240, 320].<br>- **xxldpi**: extra-extra-large-scale DPI. This value is applicable to devices with a DPI range of (320, 480].<br>- **xxxldpi**: extra-extra-extra-large-scale DPI. This value is applicable to devices with a DPI range of (480, 640]. | string array | No |

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
       "countryCode": {
         "policy": "include",
         "value": [
           "CN"
         ]
       }
     }
   }
   ```

2. Configure **metadata** in the **module** tag in the **module.json5** file.

  <!-- @[module_distributionFilter_metadata](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/ModuleConfigurationFile03/entry1/src/main/module.json5)   -->

  ``` JSON5
  {
    "module": {
      // ...
      "metadata": [
        {
          "name": "ohos.module.distribution",
          "resource": "$profile:distributionFilter_config"
        }
      ],
      // ...
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

<!-- @[module_testRunner](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/ModuleConfigurationFile01/myHapName/src/main/module.json5) -->

``` JSON5
{
  "module": {
    // ...
    "testRunner": {
      "name": "myTestRunnerName",
      "srcPath": "etc/test/TestRunner.ts"
    },
    // ...
  }
}
```

## atomicService

The **atomicService** tag represents the atomic service configuration. It takes effect only when **bundleType** is set to **atomicService** in the **app.json5** file.

**Table 18** atomicService

<!--Table: 15%; 60%; 10%; 15%-->

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| preloads | List of modules to preload.| Object array| Yes (initial value: left empty)|
| resizeable | Whether an atomic service supports adaptive window. If this tag is set to **true**, the width and height of the window automatically adapt to the screen when the tablet is switched from landscape mode to portrait mode or the foldable screen is folded.<br>**NOTE**<br>1. This tag is supported since API version 20.<br>2. If the window has adapted to the tablet (landscape) and foldable screen (unfolded), you are advised to set this tag to **true**.<br>- **true**: The atomic service supports adaptive window.<br>- **false**: The atomic service does not support adaptive window.| Boolean| Yes (initial value: **false**)|

**Table 19** preloads

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| moduleName | Name of the module to be preloaded when the current module is loaded in the atomic service. The value must match an existing module other than the current one. It contains a maximum of 31 bytes.| String| No|

Example of the **atomicService** structure:

<!-- @[module_atomicService](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/ModuleConfigurationFile04/entry/src/main/module.json5) -->

``` JSON5
{
  "module": {
    // ...
    "atomicService": {
      "preloads":[
        {
          "moduleName":"feature"
        }
      ],
      "resizeable": true
    },
    // ...
  }
}
```

## dependencies

The **dependencies** tag identifies the list of shared libraries that the module depends on when it is running.

**Table 20** dependencies

| Name| Description| Data Type| Initial Value Allowed|
| ----------- | ------------------------------ | -------- | ---------- |
| bundleName  | Name of the shared bundle on which the current module depends. The value is a string of 7 to 128 bytes.| String  | Yes (initial value: left empty)|
| moduleName  | Module name of the shared bundle on which the current module depends. The value is a string with a maximum of 31 bytes.| String  | No|
| versionCode | Version number of the shared bundle on which the current module depends. The value ranges from 0 to 2147483647.| Number| Yes (initial value: left empty)|

Example of the **dependencies** structure:

<!-- @[module_dependencies](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/ModuleConfigurationFile01/myHapName/src/main/module.json5) -->

``` JSON5
{
  "module": {
    // ...
    "dependencies": [
      {
        "bundleName":"com.share.library",
        "moduleName": "library",
        "versionCode": 10001
      }
    ],
    // ...
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

<!-- @[module_proxyData](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/ModuleConfigurationFile01/myHapName/src/main/module.json5) -->

``` JSON5
{
  "module": {
    // ...
    "proxyData": [
      {
        "uri":"datashareproxy://ohos.app.hap.myapplication/event/Meeting",
        "requiredReadPermission": "ohos.permission.SYSTEM_FLOAT_WINDOW",
        "requiredWritePermission": "ohos.permission.SYSTEM_FLOAT_WINDOW",
        "metadata": {
          "name": "datashare_metadata",
          "resource": "$profile:datashare"
        }
      }
    ],
    // ...
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
| name          | Name of the environment variable. The value is a string with a maximum of 4,096 bytes.| String | Yes (initial value: left empty)|
| value         | Value of the environment variable. The value is a string with a maximum of 4,096 bytes.      | String | Yes (initial value: left empty)|

Example of the **appEnvironments** structure:

<!-- @[module_appEnvironments](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/ModuleConfigurationFile01/entry/src/main/module.json5) -->

``` JSON5
{
  "module": {
    // ...
    "appEnvironments": [
      {
        "name": "name1",
        "value": "value1"
      }
    ],
    // ...
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
| independentSign | Whether a native software package supports independent signature.<br>**NOTE**<br>This tag is supported since API version 23.| Boolean| Yes (initial value: **false**)|

Example of the **hnpPackages** structure:

<!-- @[module_hnpPackages](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/ModuleConfigurationFile05/entry/src/main/module.json5) -->

``` JSON5
{
  "module": {
    // ...
    "hnpPackages": [
      {
        "package": "hnpsample.hnp",
        "type": "public",
        "independentSign": true
      }
    ],
    // ...
  },
}
```

## fileContextMenu

The **fileContextMenu** tag provides configuration options for the context menu (displayed upon right-clicking) of the current HAP. It is a profile that contains the context menu configuration registered by the application. This tag takes effect only on PCs/2-in-1 devices and can be configured only in entry modules.

Example of the **fileContextMenu** structure:

<!-- @[module_fileContextMenu](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/ModuleConfigurationFile01/entry/src/main/module.json5) -->

``` JSON5
{
  "module": {
    // ...
    "fileContextMenu": "$profile:menu", // Resource configuration, which points to the menu.json configuration file defined in the profile.
    // ...
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
| fileSupportType | Supported types of files. The context menu is displayed when the selected file list contains files of these types.<br>If the value of this tag is set to **["*"]**, the **fileNotSupportType** tag is read.<br>When the value is left empty, no processing is performed.| String array| No (This tag is read when **menuKind** is set to **1**.)|
| fileNotSupportType | Types of files not supported. The context menu is not displayed when the selected file list contains files of these types.<br>This tag is read only when **menuKind** is set to **1** and **fileSupportType** is set to **["*"]**.| String array| Yes (initial value: left empty)|

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

This tag points to a profile resource and is used to define the configuration file **start_window.json** of the **UIAbility** startup page in **resources/base/profile**. If this tag is set, the **startWindowIcon** and **startWindowBackground** tags do not take effect.

<!--RP4-->

> **NOTE**
>
> Since API version 20, this tag can be used to configure an enhanced starting window.<!--RP4End-->

**Table 28** startWindow

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| startWindowType | Visibility type of the **UIAbility** startup page.<br>This tag is supported only on 2-in-1 devices or tablets in freeform mode.<br>The options are as follows:<br>\- **REQUIRED_SHOW**: The starting window is displayed. This setting is not affected by the setting of the **hideStartWindow** tag in [StartOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md#startoptions).<br>\- **REQUIRED_HIDE**: The starting window is hidden. This setting is not affected by the setting of the **hideStartWindow** tag in [StartOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md#startoptions).<br>\- **OPTIONAL_SHOW**: The starting window is displayed by default, but it can be hidden if the **hideStartWindow** tag in [StartOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md#startoptions) is set to hide it.<br>\- The default value is **REQUIRED_SHOW**.<br>This tag is supported since API version 20.| String| Yes (initial value: **REQUIRED_SHOW**)|
| startWindowAppIcon | Index to the icon file of the **UIAbility** startup page. The value is a string with a maximum of 255 bytes.<br><!--RP12-->This tag is supported since API version 20.<!--RP12End-->| String| Yes (initial value: left empty)|
| startWindowIllustration | Index to the illustration file of the **UIAbility** startup page. The value is a string with a maximum of 255 bytes.<br><!--RP12-->This tag is supported since API version 20.<!--RP12End--> | String| Yes (initial value: left empty)|
| startWindowBrandingImage | Index to the brand logo file of the **UIAbility** startup page. The value is a string with a maximum of 255 bytes.<br><!--RP12-->This tag is supported since API version 20.<!--RP12End--> | String| Yes (initial value: left empty)|
| startWindowBackgroundColor | Index to the background color resource file of the **UIAbility** startup page. The value is a string with a maximum of 255 bytes.<br><!--RP12-->This tag is supported since API version 20.<!--RP12End--> | String| No|
| startWindowBackgroundImage | Index to the background image file of the **UIAbility** startup page. The value is a string with a maximum of 255 bytes.<br><!--RP12-->This tag is supported since API version 20.<!--RP12End--> | String| Yes (initial value: left empty)|
| startWindowBackgroundImageFit | Background image adaptation mode of the **UIAbility** startup page. The options are as follows:<br>- **Contain**: Proportionally scaled based on the aspect ratio, the image is fully contained within the display area.<br>- **Cover**: Proportionally scaled based on the aspect ratio, both width and height of the image are greater than or equal to that of the display area.<br>- **Auto**: adaptive display.<br>- **Fill**: The image fills the display area without any aspect ratio scaling applied.<br>- **ScaleDown**: The image is displayed in accordance with its aspect ratio, either scaled down or kept unchanged.<br>- **None**: The image is displayed in its original size.<br><!--RP12-->This tag is supported since API version 20.<!--RP12End--> | String| Yes (initial value: **Cover**)|

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

<!-- @[module_systemTheme](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/ModuleConfigurationFile01/entry/src/main/module.json5) -->

``` JSON5
{
  "module": {
    // ...
    "systemTheme": "$profile:theme_config", // Resource configuration, which points to the theme_config.json configuration file defined in the profile.
  }
}
```

Define the **theme_config.json** configuration file in **resources/base/profile**. The file's base name can be customized but must be either **theme_config** or a name that starts with **theme_config** (e.g. **theme_config_1**). The configuration file specifies the system theme used by the current application, corresponding to the information specified by the **systemTheme** tag.

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

<!--Table: 15%; 60%; 10%; 15%-->

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| name | Name of the permission. The value can contain a maximum of 255 bytes.| String| No|
| grantMode | Permission grant mode. The options are as follows:<br>- **system_grant**: The permission is automatically granted by the system after the application is installed.<br>- **user_grant**: The permission is dynamically requested when needed and must be granted by the user.<br>- **manual_settings**: The permission must be manually granted by the user on the system settings page. This option is supported since API version 21.| String| Yes (initial value: **system_grant**)|
| availableLevel | Permission type. The options are as follows:<br>- **system_core**: system core permission.<br>- **system_basic**: basic system permission.<br>- **normal**: normal permission, which can be requested by all applications.| String| Yes (initial value: **normal**)|
| provisionEnable | Whether the permission (including high-level permissions) can be requested through a profile. The value **true** indicates that you can request permissions through a profile; **false** indicates the opposite.| Boolean| Yes (initial value: **true**)|
| distributedSceneEnable | Whether the permission can be used in distributed scenarios. The value **true** indicates that you can use the permission in distributed scenarios; **false** indicates the opposite.| Boolean| Yes (initial value: **false**)|
| label | Brief description of the permission. The value is a resource index to the description.| String| Yes (initial value: left empty)|
| description | Detailed description of the permission. The value is a string or a resource index to the description.| String| Yes (initial value: left empty)|

Example of the **definePermissions** structure:

<!-- @[module_definePermissions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/ModuleConfigurationFile05/entry/src/main/module.json5) -->

``` JSON5
{
  "module": {
    // ...
    "definePermissions": [
      {
        "name": "ohos.permission.ACCESS_BLUETOOTH",
        "grantMode": "system_grant",
        "availableLevel": "system_core",
        "provisionEnable": true,
        "distributedSceneEnable": false,
        "label": "$string:EntryAbility_label"
      }
    ],
    // ...
  },
}
```

<!--DelEnd-->

## executableBinaryPaths

Identifies the path information of executable binary files in the application and takes effect only on PCs/2-in-1 devices. This tag is supported since API version 24.

**Table 31** executableBinaryPaths

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| path | Path of the executable file. This path is a relative path and must start with the `libs/{abi}/` prefix, where `{abi}` indicates the device CPU architecture type, such as **arm64-v8a**, **x86_64**, or **armeabi-v7a**. Executable binary files must be placed in the `libs/{abi}/` directory.| String| No|

Example of the **executableBinaryPaths** structure:

<!-- @[module_executableBinaryPaths](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/ModuleConfigurationFile05/entry/src/main/module.json5) -->

``` JSON5
{
  "module": {
    // ...
    "executableBinaryPaths": [
      {
        "path": "libs/arm64-v8a/test.bin"
      }
    ],
    // ...
  },
}
```

## skillProfiles

Starting from API version 26.0.0, the **skillProfiles** tag is added. This tag identifies the skill configuration information of the current module and is used to define the skill capabilities of an AI agent. By defining skills, an application can expose the capabilities of its AI agent to the system or other applications, allowing the skills to be discovered and invoked by other applications. This tag takes effect only for modules whose type is **entry**, **feature**, **shared**, or **skill**.

**Table 32** skillProfiles

<!--Table: 15%; 60%; 10%; 15%-->

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| name | Identifies the name of the skill. Ensure that the name is unique within the current module. The naming rules are as follows:<br/>-&nbsp;Only lowercase letters, digits, and hyphens (-) are allowed.<br/>-&nbsp;It must start with a lowercase letter or digit.<br/>-&nbsp;It must end with a lowercase letter or digit.<br/>-&nbsp;It cannot start or end with a hyphen, and consecutive hyphens are not allowed.<br/>-&nbsp;The maximum length is 64 bytes. | string | This tag cannot be omitted. |
| abilityName | Name of the component associated with the skill. The value must be configured as the name of a **UIAbility** under the [abilities](#abilities) tag or the name of a **ServiceExtension** component whose type is **service** under the [extensionabilities](#extensionabilities) tag. The value is a string with a maximum of 127 bytes. It must start with a letter and can contain letters, digits, underscores (_), and periods (.).<br>**NOTE**<br>This field applies only to modules of the **entry**, **feature**, and **shared** types. This field is not supported for modules of the **skill** type.| String| Yes (initial value: name of the entry ability; if no entry ability exists, the value is an empty string.)|
| srcEntries | List of code file paths that implement the skill and points to **.ets** files that contain the skill implementation logic. Each element in the array is a file path relative to the skills directory of the current module.<br>**NOTE**<br>The **.ets** files specified by **srcEntries** must be placed in the **skills/{skill-name}/scripts** directory, where **{skill-name}** is the skill name configured in **skillProfiles**. For example, if the skill name is **my-skill**, the **.ets** files must be placed in the **skills/my-skill/scripts/** directory under the module root directory. Up to 100 file paths are supported.| String array| Yes (initial value: left empty)|
| permissions | List of permissions required to invoke the skill. Other applications must request the corresponding permissions before invoking the skill. Each array element is a permission name with a maximum of 255 bytes. For details about the value, see [Application Permissions](../security/AccessToken/app-permissions.md).| String array| Yes (initial value: left empty)|
| version | Identifies the version number of the skill, in the format of `major.minor.patch`, where each version number is a non-negative integer and cannot start with 0 (unless it is 0 itself).<br/>**Example:** "1.0.1", "0.1.1" | string | This tag cannot be omitted. |
| visibility | Identifies the visibility of the skill, which controls the visibility scope of the skill. The supported values are as follows:<br/>-&nbsp;"private": private, visible only to the current app.<br/>-&nbsp;"system": system-level, visible to system apps and the current app.<br/>-&nbsp;"public": public, visible to all apps.<br/>**Note:**<br/>The default value of this tag is "system". | string | This tag can be omitted. The default value is "system". |

Example:

<!-- @[module_skillProfiles](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/ModuleConfigurationFile01/entry/src/main/module.json5) -->

``` JSON5
{
  "module": {
    // ...
    "skillProfiles": [
      {
        "name": "my-skill",
        "abilityName": "EntryAbility",
        "version": "1.0.0",
        "visibility": "public",
        "srcEntries": [
          "../../my-skill/scripts/Test.ets"
        ],
        "permissions": []
      }
    ],
    // ...
  }
}
```

<!--no_check-->
