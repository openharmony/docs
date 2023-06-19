# app.json5 Configuration File


This document gives an overview of the **app.json5** configuration file. To start with, let's go through an example of what this file contains.

```json
{
  "app": {
    "bundleName": "com.application.myapplication",
    "vendor": "example",
    "versionCode": 1000000,
    "versionName": "1.0.0",
    "icon": "$media:app_icon",
    "label": "$string:app_name",
    "description": "$string:description_application",
    "minAPIVersion": 9,
    "targetAPIVersion": 9,
    "apiReleaseType": "Release",
    "debug": false,
    "car": {
      "minAPIVersion": 8,
    }
  },
}
```


As shown above, the **app.json5** file contains several tags.


**Table 1** Tags in the app.json5 file

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| bundleName | Bundle name, which uniquely identifies an application.  The value must comply with the following rules:<br>- Consists of letters, digits, underscores (_), and periods (.).<br>- Starts with a letter.<br>- Contains 7 to 127 bytes.<br>You are advised to use the reverse domain name notation, for example, *com.example.demo*, where the first part is the domain suffix **com**, the second part is the vendor/individual name, and the third part is the application name, which can be of multiple levels.<br>If an application is built with the system source code, you are advised to name it in *com.ohos.demo* notation, where **ohos** signifies that the application is an OpenHarmony system application.| String| No|
| bundleType| Bundle type, which is used to distinguish applications and atomic services.<br>- **app**: The bundle is a common application.<br>- **atomicService**: The bundle is an atomic service. | String| Yes (initial value: **"app"**)|
| debug | Whether the application can be debugged. This tag is generated during compilation and building in DevEco Studio.<br>- **true**: The application can be debugged.<br>- **false**: The application cannot be debugged.| Boolean| Yes (initial value: **false**)|
| icon | [Icon of the application](../application-models/application-component-configuration-stage.md). The value is an icon resource index.| String| No|
| label | [Name of the application](../application-models/application-component-configuration-stage.md). The value is a string resource index.| String| No|
| description | Description of the application. The value is a string with a maximum of 255 bytes or a resource index to the description.| String| Yes (initial value: left empty)|
| vendor | Vendor of the application. The value is a string with a maximum of 255 bytes.| String| Yes (initial value: left empty)|
| versionCode | Version number of the application. The value is a 32-bit non-negative integer less than 2 to the power of 31. It is used only to determine whether a version is later than another version. A larger value indicates a later version. Ensure that a new version of the application uses a value greater than any of its predecessors.  | Number| No|
| versionName | Version number of the application displayed to users.<br>The value consists of only digits and dots. The four-part format *A.B.C.D* is recommended, wherein:<br>Part 1 (*A*): major version number, which ranges from 0 to 99. A major version consists of major new features or large changes.<br>Part 2 (*B*): minor version number, which ranges from 0 to 99. A minor version consists of some new features and large bug fixes.<br>Part 3 (*C*): feature version number, which ranges from 0 to 99. A feature version consists of scheduled new features.<br>Part 4 (*D*): maintenance release number or patch number, which ranges from 0 to 999. A maintenance release or patch consists of resolution to security flaws or minor bugs.<br>The value contains a maximum of 127 bytes.| String| No|
| minCompatibleVersionCode | Minimum compatible version of the application. It is used to check whether the application is compatible with a version on other devices in the cross-device scenario.| Number| Yes (initial value: value of **versionCode**)|
| minAPIVersion | Minimum API version required for running the application.| Number| Yes (initial value: value of **compatibleSdkVersion** in **build-profile.json5**)|
| targetAPIVersion | Target API version required for running the application.| Number| Yes (initial value: value of **compileSdkVersion** in **build-profile.json5**)|
| apiReleaseType | Type of the target API version required for running the application. The value can be **"CanaryN"**, **"BetaN"**, or **"Release"**, where **N** represents a positive integer.<br>- **Canary**: indicates a restricted release.<br>- **Beta**: indicates a publicly released beta version.<br>- **Release**: indicates a publicly released official version.<br>The value is set by DevEco Studio reading the stage of the SDK in use.| String| Yes (initial value: set by DevEco Studio)|
| multiProjects | Whether the application supports joint development of multiple projects.<br>- **true**: The application supports joint development of multiple projects.<br>- **false**: The application does not support joint development of multiple projects. For details about multi-project development, see [Multi-Project Build](https://developer.harmonyos.com/en/docs/documentation/doc-guides-V3/ohos-building-overview-0000001263360495-V3#section71471033104216).| Boolean| Yes (initial value: **false**)|
| tablet | Tablet-specific configuration, which includes **minAPIVersion** and **distributedNotificationEnabled** attributes.<br>When running on tablets, the application applies the attribute settings under this tag and ignores the general counterparts.| Object| Yes (initial value: general settings in the **app.json5** file)|
| tv | TV-specific configuration, which includes **minAPIVersion** and **distributedNotificationEnabled** attributes.<br>When running on TVs, the application applies the attribute settings under this tag and ignores the general counterparts.| Object| Yes (initial value: general settings in the **app.json5** file)|
| wearable | Wearable-specific configuration, which includes **minAPIVersion** and **distributedNotificationEnabled** attributes.<br>When running on wearables, the application applies the attribute settings under this tag and ignores the general counterparts.| Object| Yes (initial value: general settings in the **app.json5** file)|
| car | Head unit–specific configuration, which includes **minAPIVersion** and **distributedNotificationEnabled** attributes.<br>When running on head units, the application applies the attribute settings under this tag and ignores the general counterparts.| Object| Yes (initial value: general settings in the **app.json5** file)|
| default | Default device–specific configuration, which includes **minAPIVersion** and **distributedNotificationEnabled** attributes.<br>When running on default devices, the application applies the attribute settings under this tag and ignores the general counterparts.| Object| Yes (initial value: general settings in the **app.json5** file)|
