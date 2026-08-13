# app.json5 Configuration File

<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @memghaiyang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=74dbad5c7db60e1e7acbdd97ecfcb9536c7d7b13 translatedAt=2026-08-13T08:49:18.174Z pushedAt=2026-08-13T11:14:41.106Z -->

An application-level configuration file provides the global configuration of an application and configuration of a specific device type for the compilation tool, OS, and AppGallery. Each project must contain an **app.json5** configuration file, which is stored in the ***project name*/AppScope/app.json5** directory.

>
> **NOTE**
>
> Using the sample code in the actual project may cause a compilation failure. You need to configure the code as required. For example, if the resource file referenced by the **$** symbol does not exist in the project, you need to manually add the resource file or replace it with the actual one.
>
> In the configuration file, fields can be repeated. The last field is used.
>

## Configuration File Example

The following example describes the structure and content of the **app.json5** configuration file.

<!-- @[app_json5](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/AppConfigurationFile/AppScope/app.json5) -->

``` JSON5
{
  "app": {
    "bundleName": "com.application.myapplication",
    "vendor": "example",
    "versionCode": 1000000,
    "versionName": "1.0.0",
    "icon": "$media:layered_image",
    "alternateIcons": [
      {
        "name": "summer_theme",
        "icon": "$media:layered_image"
      },
      {
        "name": "winter_theme",
        "icon": "$media:background"
      }
    ],
    "label": "$string:app_name",
    "description": "$string:description_application",
    "minAPIVersion": 9,
    "targetAPIVersion": 9,
    "debug": false,
    "car": {
      "minAPIVersion": 8
    },
    "appEnvironments": [
      {
        "name":"name1",
        "value": "value1"
      }
    ],
    "maxChildProcess": 5,
    "multiAppMode": {
      "multiAppModeType": "appClone",
      "maxCount": 5
    },
    "hwasanEnabled": false,
    "ubsanEnabled": false,
    "cloudFileSyncEnabled": false,
    "cloudStructuredDataSyncEnabled": false,
    "configuration": "$profile:configuration",
    "assetAccessGroups": [
      "com.ohos.photos",
      "com.ohos.screenshot",
      "com.ohos.note"
    ],
    "startMode": "mainTask",
    "buildVersion": "1.0.0",
    "allowListenBundleChangedEvent": [
      "5628971256935874952"
    ]
  }
}
```

## Tags in the Configuration File

As shown above, the **app.json5** file contains several tags.

**Table 1** Tags in the app.json5 file

<!--Table: 15%; 60%; 10%; 15%-->

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| bundleName | Bundle name, which uniquely identifies an application. The value must comply with the following rules:<br>- The bundle name contains at least three segments, separated by periods (.). Each segment can contain only letters, digits, and underscores (_).<br>- The first segment starts with a letter, and other segments start with a digit or letter. Each segment ends with a digit or letter.<br>- Consecutive periods (.) are not allowed.<br>- Contains 7 to 128 bytes.<br>You are advised to use the reverse domain name notation, for example, *com.example.demo*, where the first part is the domain suffix **com**, the second part is the vendor/individual name, and the third part is the application name, which can be of multiple levels.| String| No|
| bundleType| Identifies the Bundle type of the app. The supported values are as follows:<br/>-&nbsp;app: The current Bundle is an app.<br/>-&nbsp;atomicService: The current Bundle is an atomic service.<br/>-&nbsp;shared: The current Bundle is a shared library app. It can be configured only for system apps. If a third-party application configures it, the app cannot be installed.<br/>-&nbsp;appService: The current Bundle is a system-level shared library app. It takes effect only for system apps.<br/>-&nbsp;appPlugin: The current Bundle is a plugin package of an app. This tag is supported since API version 19.<br/>-&nbsp;skill: The current Bundle is a skill package app, which is used to encapsulate the skill capabilities of an AI agent and can be discovered and invoked by other apps. When the type is configured as skill, the app can contain only one module, and the module type must be configured as skill, that is, the type field in module.json5 must be configured as skill. For usage instructions, see the module [type](./module-configuration-file.md#tags-in-the-configuration-file) field. This tag is supported since API version 26.0.0. This tag takes effect only for preset apps. | String| This tag can be omitted, and the default value is app. |
| debug | Whether the application can be debugged.<br>-&nbsp;**true**: Can be debugged. Used in the development phase.<br>-&nbsp;**false**: Cannot be debugged. Used in the release phase.| Boolean| Generated by DevEco Studio during compilation and building. Yes (initial value: **false**)|
| icon | Application icon. The value is the index to an icon resource file. Single-layer icons and layered icons can be configured. For details about the configuration rules and examples, see [Configuring Layered Icons](layered-image.md).| String| No|
| [alternateIcons](#alternateicons)| Alternate icon list of the application, which is used to dynamically switch application icons at runtime. Each alternate icon contains the icon name and index of the icon resource file.<br>**NOTE**<br>This tag is supported starting from API version 26.0.0.<br>This tag can be configured only when **bundleType** is **app**.| Object array| Yes (initial value: left empty)|
| label | Application name. The value is the index to a string resource with a maximum of 63 bytes, supporting multiple languages. For details, see [Configuring Layered Icons](layered-image.md).| String| No|
| description | Description of an application. The value is a string of a maximum of 255 bytes, indicating the description string or the string resource index of the description. This tag can be used to display application information on, for example, the **About** page.| String| Yes (initial value: left empty)|
| vendor | Vendor of the application. The value is a string with a maximum of 255 bytes. This tag can be used to display the vendor information on, for example, the **About** page.| String| Yes (initial value: left empty)|
| versionCode | Version number of an application. The value ranges from 0 to 2147483647. It is used only to determine whether a version is later than another version. A larger value indicates a later version.<br>Ensure that a new version of the application uses a value greater than any of its predecessors.| Number| No|
| versionName | Version number of the application displayed to users.<br>The value is a string with a maximum of 127 bytes:<br>1. Consists of numbers and dots only. You are advised to use the four-part format of "A.B.C.D", wherein:<br>Part 1 (*A*): major version number. A major version consists of major new features or large changes.<br>Part 2 (*B*): minor version number. A minor version consists of some new features and large bug fixes.<br>Part 3 (*C*): feature version number. A feature version consists of scheduled new features.<br>Part 4 (*D*): patch version number. A patch version consists of some bug fixes.<br>2. Consists of digits, letters, underscores (_), periods (.), and curly braces ({}) only.| String| No|
| minCompatibleVersionCode | Minimum historical version compatible with the application. It is used for collaboration across devices, data migration, and cross-device compatibility determination. This tag is reserved and the value ranges from 0 to 2147483647.| Number| Yes (initial value: value of **versionCode**)|
| minAPIVersion | Minimum SDK API version required for running an application. The value ranges from 0 to 2147483647.| Number| Yes (This tag is automatically generated during application build and cannot be manually configured. It corresponds to the **compatibleSdkVersion** tag in the [project-level build-profile.json5 file](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-hvigor-build-profile-app#section45865492619).)<!--RP1--><!--RP1End--> |
| targetAPIVersion | Target API version required for running the application. The value ranges from 0 to 2147483647.| Number| Yes (This tag is automatically generated during application build and cannot be manually configured. It corresponds to the **targetSdkVersion** tag in the [project-level build-profile.json5 file](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-hvigor-build-profile-app#section45865492619). If the **targetSdkVersion** tag is not configured, this tag will be generated by **compileSdkVersion**.) <!--RP1--><!--RP1End--> |
| apiReleaseType | Type of the target API version required for running the application. The value can be **"CanaryN"**, **"BetaN"**, or **"ReleaseN"**, where **N** represents a positive integer.<br>- **Canary**: indicates a restricted release.<br>- **Beta**: indicates a publicly released beta version.<br>- **Release**: indicates a publicly released official version.| String| Yes (This tag is automatically generated during application build and cannot be manually configured.)|
| accessible | Whether an application can access the installation directory. This field takes effect only for the preset system applications but not the third-party applications.<br>- **true**: The application installation directory is accessible.<br>- **false**: The application installation directory is not accessible.| Boolean| Yes (initial value: **false**)|
| multiProjects | Whether the application supports joint development of multiple projects.<br>- **true**: The application supports joint development of multiple projects. For details about multi-project development, see [Implementing Multi-project Builds](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-hvigor-multi-projects).<br>- **false**: The application does not support joint development of multiple projects.| Boolean| Yes (This tag is automatically generated during application build and cannot be manually configured. It corresponds to the **multiProjects** tag in the [project-level build-profile.json5 file](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-hvigor-build-profile-app).)|
| asanEnabled | Whether to enable [Address Sanitizer (ASan)](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-asan) to detect memory corruption issues such as buffer overflows.<br>- **true**: ASan is enabled.<br>- **false**: ASan is disabled.| Boolean| Yes (initial value: **false**)|
| tablet | Tablet-specific configuration, which includes the **minAPIVersion** attribute.<br>If this attribute is used for tablet devices, the application will adopt the attribute value configured here on tablet devices and ignore the attribute value in the public area of **app.json5**.| Object| Yes (initial value: attribute value in the public area of **app.json5** file)|
| tv | TV-specific configuration, which includes the **minAPIVersion** attribute.<br>If this attribute is used for TVs, the application will adopt the attribute value configured here on TVs and ignore the attribute value in the public area of **app.json5**.| Object| Yes (initial value: attribute value in the public area of **app.json5** file)|
| wearable | Wearable-specific configuration, which includes the **minAPIVersion** attribute.<br>If this attribute is used for wearables, the application will adopt the attribute value configured here on wearables and ignore the attribute value in the public area of **app.json5**.| Object| Yes (initial value: attribute value in the public area of **app.json5** file)|
| car | Telematics–specific configuration, which includes the **minAPIVersion** attribute. <br>If this attribute is used for telematics devices, the application will adopt the attribute value configured here on telematics devices and ignore the attribute value in the public area of **app.json5**.| Object| Yes (initial value: attribute value in the public area of **app.json5** file)|
| default | Default device–specific configuration, which includes the **minAPIVersion** attribute.<br>If this attribute is used for default devices, the application will adopt the attribute value configured here on default devices and ignore the attribute value in the public area of **app.json5**.| Object| Yes (initial value: attribute value in the public area of **app.json5** file)|
|targetBundleName|Target bundle name. The value rule and range are the same as those of **bundleName**. When a value is specified, the target application becomes one with the overlay feature.|String|Yes (initial value: left empty)|
|targetPriority|Priority of the application. The value ranges from 1 to 100. This tag can be configured only after the **targetBundleName** tag is configured.|Number|Yes (initial value: **1**)|
|generateBuildHash |Whether to generate hash values for all HAP and HSP files of the application by using the packaging tool.<br>If this tag is set to **true**, the packaging tool generates hash values for all HAP and HSP files of the application. The hash values (if any) are used to determine whether the application needs to be updated when the system is updated in OTA mode but the **versionCode** value of the application remains unchanged.<br>- **true**: The packaging tool generates hash values for all HAPs and HSPs of the current application.<br>- **false**: The packaging tool does not generate hash values for all HAPs and HSPs of the current application.<br>**NOTE**<br>This tag takes effect only for pre-installed applications.|Boolean|Yes (initial value: **false**)|
| 2in1 | Special configurations for PCs/2-in-1 devices. The configurable attribute tag is **minAPIVersion**.<br>When running on PCs/2-in-1 devices, the application applies the attribute settings under this tag and ignores the general settings in the **app.json5** file.| Object| Yes (initial value: general settings in the **app.json5** file)|
| GWPAsanEnabled | Whether to enable GWP-ASan for detecting memory safety violations, including use-after-free and out-of-bounds memory read/write operations.<br>- **true**: The GWP-asan detection is enabled for the application.<br>- **false**: The GWP-asan detection is disabled for the application.| Boolean| Yes (initial value: **false**)|
| [appEnvironments](#appenvironments) | Application environment variables configured for the current application.| Object array| Yes (initial value: left empty)|
| maxChildProcess | Maximum number of child processes that can be created by the current application. The value ranges from 0 to 512. The value **0** indicates that the number is not limited. If the application has multiple modules, use the configuration of the **entry** module.| Number| Yes (initial value: <!--RP2-->**1**<!--RP2End-->)|
| [multiAppMode](#multiappmode)| Multi-app mode of the application. This tag takes effect only for the entry or feature module of the application whose **bundleType** is **app**. If there are multiple modules, use the configuration of the **entry** module.| Object| Yes (initial value: left empty)|
| hwasanEnabled | Whether [Hardware-assisted Address Sanitizer (HWASan)](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-hwasan) is enabled for an application. HWAsan is an enhanced Asan improved by the Top-Byte-Ignore feature. Compared with Asan, HWAsan has a lower memory overhead and a larger range of detection for memory errors.<br>- **true**: HWAsan is enabled.<br>- **false**: HWAsan is disabled.<br>**NOTE**<br>This tag is supported since API version 14.| Boolean| Yes (initial value: **false**)|
| tsanEnabled | Whether TSan is enabled for the application to detect thread-related errors.<br>[ThreadSanitizer (TSan)](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-tsan) is a tool used to detect data races.<br>- **true**: TSan is enabled.<br>- **false**: TSan is disabled.| Boolean| Yes (initial value: **false**)|
| ubsanEnabled | Identifies whether the app [uses UBSan to detect undefined behavior](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-ubsan).<br/>UBsan (Undefined Behavior Sanitizer) is a tool for detecting undefined behavior in programs at runtime, designed to help developers find potential errors and vulnerabilities in code.<br/>-&nbsp;true: UBSan detection is enabled for the current project.<br/>- **false**: UBSan detection is not enabled for the current project.<br/>**Note:** <br/>This tag is supported since API version 14. | Boolean | This tag can be omitted, and the default value is false. |
| cloudFileSyncEnabled | Whether device-cloud file synchronization is enabled for the application.<br>-&nbsp;**true**: The device-cloud file synchronization is enabled.<br>-&nbsp;**false**: The device-cloud file synchronization is disabled.| Boolean| Yes (initial value: **false**) |
| cloudStructuredDataSyncEnabled | Whether device-cloud structured data synchronization is enabled for the application.<br>- **true**: The device-cloud structured data synchronization is enabled.<br>- **false**: The device-cloud structured data synchronization is disabled.<br>**NOTE**<br>This tag is supported since API version 20.| Boolean| Yes (initial value: **false**) |
| [configuration](#configuration)| Whether the font size of the current application follows the system.<br>This tag is a **profile** file resource that used to specify the configuration file that describes the application font size changes with the system.| String| Yes (initial value: **nonFollowSystem**)|
| assetAccessGroups | Group ID of an application (configured by the developer), which forms group information with the Developer ID (allocated by AGC).<br>When HAP is packaged, DevEco Studio uses the developer certificate to sign the group information.<br>**NOTE**<br>This tag takes effect only in the main module (that is, the **type** field in **module.json5** is set to **entry**).<br>This tag is supported since API version 18.| String array| Yes (initial value: left empty)|
| appPreloadPhase | The stage at which the [application is preloaded](../application-models/preload-application.md). The options are as follows:<br>- **processCreated**: preload the application to the stage where process is created.<br>- **abilityStageCreated**: preload the application to the stage where [AbilityStage](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md) is created.<br>- **windowStageCreated**: preload the application to the stage where [WindowStage](../reference/apis-arkui/arkts-apis-window-WindowStage.md) is created.<br>**NOTE**<br>This tag is supported since API version 20.<br>This tag takes effect only on the PCs/2-in-1 devices.<br>This field is valid only in the entry module of the application.<br>This tag only indicates whether the application is ready for preloading to the configured stage. Whether preloading can be performed is determined by the system based on user habits and other information.| String| Yes (If the value is not specified, preloading is not performed.)|
| [startMode](../application-models/application-component-configuration-stage.md#configuring-the-launch-mode)| Launch mode of the application. The options are as follows:<br>- **mainTask**: main task mode, indicating that the main UIAbility of the application is always started when the icon is tapped.<br>- **recentTask**: recent task mode, indicating that the most recently used UIAbility is started when the icon is tapped.<br>**NOTE**<br>This tag is supported since API version 20.<br>This field is valid only when launchType is set to [singleton](../application-models/uiability-launch-type.md#singleton).<br>This tag is supported only on phones and tablets (excluding freeform windows).| String| Yes (initial value: **mainTask**)|
| buildVersion | Build version number of the application. The three-segment format A.B.C is recommended. The recommended meaning for each segment is as follows:<br>First segment: major version number, used for releases with significant modifications, such as major new features or fundamental changes.<br>Second segment: minor version number, used for notable feature updates, such as adding new capabilities or fixing critical issues.<br>Third segment: feature version number, used to identify planned new feature iterations in releases.<br>**NOTE**<br>This tag is supported since API version 23.<br>String format requirements:<br>- Minimum length: 1 character; maximum length: 18 characters.<br>- Composed only of digits and dots (.).<br>- Allowed 0 to 2 dots; cannot start with a dot, end with a dot, or contain consecutive dots.<br>- Numeric segments may be 0 alone, but must not have leading zeros (for example, "02", "0123" are invalid).| String| Yes (initial value: left empty)|
| profileable | Identifies whether the [tuning tool](../dfx/hiperf.md) is allowed to perform performance analysis on apps whose <!--RP3-->[profile signing file](../security/app-provision-structure.md) type is release<!--RP3End-->.<br/>-&nbsp;true: The tuning tool is allowed to perform performance analysis on the app.<br/>-&nbsp;false: The tuning tool is not allowed to perform performance analysis on the app.<br/>**Note:**<br/>This tag is supported since API version 24.<br/>This tag can be configured only when bundleType is app or atomicService. | Boolean | This tag can be omitted, and the default value is false. |
| allowListenBundleChangedEvent | List of third-party applications that are allowed to listen for public events related to the installation, update, uninstallation, and cache clearing of the current application.<br>Each array element represents the [appIdentifier](../quick-start/common-problem-of-application.md#what-is-appidentifier) of an application.<br>**NOTE**<br>This tag is supported starting from API version 26.0.0.<br>This configuration takes effect only when <!--RP4-->**app-distribution-type** in the application's [HarmonyAppProvision Configuration File](../security/app-provision-structure.md) is **enterprise**<!--RP4End-->.<br>This tag can be configured only when **bundleType** is **app** or **atomicService**. Configuring this tag for other bundle types causes compilation to fail.| String array| Yes (initial value: left empty)|
| distributedNotificationEnabled<sup>(deprecated)</sup> | Whether distributed notification is enabled for the application. When distributed notification is enabled and device A and device B where the application is installed are on the same distributed network, the devices behave in this way: If device A receives a message, device B will receive a distributed notification prompting the user to check the message received on device A.<br>- **true**: Distributed notification is enabled.<br>- **false**: Distributed notification is not enabled.<br>**NOTE**<br>This tag is deprecated since API version 9.| Boolean| Yes (initial value: **false**)|
| entityType<sup>(deprecated)</sup> | Application category. Available values are as follows:<br>- **game**<br>- **media**<br>- **communication**<br>- **news**<br>- **travel**<br>- **utility**<br>- **shopping**<br>- **education**<br>- **kids**<br>- **business**<br>- **photography**<br>- **unspecified**<br>**NOTE**<br>This tag is deprecated since API version 9.| String| Yes (initial value: **unspecified**)|
| keepAlive<sup>(deprecated)</sup> | Whether the application remains active. This attribute takes effect only for system applications or privileged applications and is not available to third-party applications.<br>**NOTE**<br>This tag is deprecated since API version 9.| Boolean| Yes (initial value: **false**)|
| removable<sup>(deprecated)</sup> | Whether the application can be removed. This attribute takes effect only for system applications or privileged applications and is not available to third-party applications.<br>**NOTE**<br>This tag is deprecated since API version 9.| Boolean| Yes (initial value: **true**)|
| singleton<sup>(deprecated)</sup> | Whether the application is in singleton mode. This attribute takes effect only for system applications or privileged applications and is not available to third-party applications.<br>**NOTE**<br>This tag is deprecated since API version 9.| Boolean| Yes (initial value: **false**)|
| userDataClearable<sup>(deprecated)</sup> | Whether the application is allowed to clear user data. This attribute takes effect only for system applications or privileged applications and is not available to third-party applications.<br>**NOTE**<br>This tag is deprecated since API version 9.| Boolean| Yes (initial value: **true**)|

## appEnvironments

The **appEnvironments** tag represents the application environment variables. Running applications tend to depend on some third-party libraries that use custom environment variables. To avoid modifying the implementation logic of the third-party libraries, you can customize environment variables in the project configuration file for use during runtime.

**Table 2** appEnvironments

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| name          | Name of the environment variable. The value is a string with a maximum of 4096 bytes.| String | Yes (initial value: left empty)|
| value         | Value of the environment variable. The value is a string with a maximum of 4096 bytes.      | String | Yes (initial value: left empty)|

Example of the **appEnvironments** structure:

<!-- @[app_json5_appEnvironments](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/AppConfigurationFile/AppScope/app.json5) -->

``` JSON5
{
  "app": {
    // ...
    "appEnvironments": [
      {
        "name":"name1",
        "value": "value1"
      }
    ],
    // ...
  }
}
```

## multiAppMode

The **multiAppMode** tag represents the multi-app mode of the application.

**Table 3** multiAppMode

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| multiAppModeType          | Multi-open mode. The options are as follows:<br>- **multiInstance**: multi-instance mode. This tag is supported only on 2-in-1 devices and does not apply to resident processes.<br>- **appClone**: app clone mode.| String | No|
| maxCount         | Maximum number of applications that can be opened. The options are as follows:<br>- In **multiInstance** mode, the value ranges from 1 to 10.<br>- In **appClone** mode, the value ranges from 1 to 5.     | Number | No|

Example of the **multiAppMode** structure:

<!-- @[app_json5_multiAppMode](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/AppConfigurationFile/AppScope/app.json5) -->

``` JSON5
{
  "app": {
    // ...
    "multiAppMode": {
      "multiAppModeType": "appClone",
      "maxCount": 5
    },
    // ...
  }
}
```

## configuration

This tag corresponds to a profile resource, which is used to configure whether the font size of an application changes with the system.

Example of the **configuration** structure:

<!-- @[app_json5_configuration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/AppConfigurationFile/AppScope/app.json5) -->

``` JSON5
{
  "app": {
    // ...
    "configuration": "$profile:configuration",
    // ...
  }
}
```

Define the **configuration.json** file under **AppScope/resources/base/profile** in the development view. The file name (**configuration** in this example) can be customized, but must be consistent with the file specified by the **configuration** tag. The configuration file lists the attributes that enable the application font size to change with the system.

   **Table 4** configuration

<!--Table: 15%; 50%; 10%; 25%-->

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| fontSizeScale | Settings of the application font size. The options are as follows:<br>- **followSystem**: The font size follows the system.<br>- **nonFollowSystem**: The font size does not follow the system.| String| Yes (initial value: **nonFollowSystem**)|
| fontSizeMaxScale | Maximum ratio of the application font size after the font size is set to follow the system. The options are as follows: **1**, **1.15**, **1.3**, **1.45**, **1.75**, **2**, and **3.2**.<br> For example, the value is set to **1.75** and the system font size is 10 fp, the application font size changes as follows:<br>(1) If the system font size is set to 1.5 times its original size in Settings, the application font size also changes to 15 fp, in line with the system.<br>(2) If the system font size is set to 2 times its original size in Settings, the system font size is 20 fp. However, the application font size is 17.5 fp because the maximum ratio of the application font size is set to 1.75.<br> **NOTE**<br> If **fontSizeScale** is set to **nonFollowSystem**, this attribute does not take effect.| String| Yes (initial value: **3.2**)|

Example of the **configuration** structure:

```json
{
  "configuration": {
    "fontSizeScale": "followSystem",
    "fontSizeMaxScale": "3.2"
  }
}
```

## alternateIcons

This tag is used to configure the list of alternate application icons and supports dynamically switching application icons at runtime. You can preconfigure multiple alternate icons, and the application can dynamically switch icons based on scenarios such as user preferences, holiday themes, and branding campaigns.

This tag is supported starting from API version 26.0.0.

**Table 5** alternateIcons

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| name | Name of the alternate icon and is used to distinguish different alternate icons. The value is a string of no more than 255 bytes.| String| No|
| icon | Index of the icon resource file for the alternate icon. The value is the index of the icon resource file in the format **$media:icon_name**. Both layered icons and single-layer icons are supported. For configuration rules, see [Configuring an Application Icon and Label](layered-image.md).| String| No|

Example:

<!-- @[app_json5_alternateIcons](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/AppConfigurationFile/AppScope/app.json5) -->

``` JSON5
{
  "app": {
    // ...
    "alternateIcons": [
      {
        "name": "summer_theme",
        "icon": "$media:layered_image"
      },
      {
        "name": "winter_theme",
        "icon": "$media:background"
      }
    ],
    // ...
  }
}
```