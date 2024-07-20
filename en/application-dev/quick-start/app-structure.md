# Structure of the app Tag


The **app** tag contains application-wide configuration. The following table describes its internal structure.

**Table 1** Internal structure of the app tag

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| bundleName | Bundle name, which uniquely identifies an application.<br>The bundle name must start with a letter and can contain only letters, digits, underscores (_), and periods (.).<br>The bundle name is represented as a reverse domain name of 7 to 128 bytes, for example, **"com.example.myapplication"**. It is recommended that the first level be the domain suffix "com" and the second level be the vendor/individual name. More levels are also accepted.| String| No|
| vendor | Vendor of the application. The value is a string with a maximum of 255 bytes.| String| Yes (initial value: left empty)|
|version | Version of the application.| Object| No|
| apiVersion | Operating system and API version on which the application depends.| Object| Yes (initial value: left empty)|
| smartWindowSize | Screen size used when the application runs in the emulator.| String| Yes (initial value: left empty)|
| smartWindowDeviceType | Types of emulated devices on which the application can run.| String array| Yes (initial value: left empty)|
| asanEnabled |   Whether to enable AddressSanitizer (ASan) to detect memory corruption issues such as buffer overflows.<br>- **true**: ASan is enabled.<br>- **false**: ASan is disabled.| Boolean| Yes (initial value: **false**)|

## Internal Structure of the version Attribute

**Table 2** Internal structure of the version attribute

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| name | Application version number displayed to users. The value can be customized and cannot exceed 127 bytes. The configuration rules are as follows:<br>For API version 5 and earlier versions, use the three-part format *A.B.C* (compatible with a two-part format *A.B*), where A, B, and C are integers ranging from 0 to 999.  <br>*A* indicates the major version number.<br>*B* indicates the minor version number.<br>*C* indicates the patch version number. <br>For API version 6 and later versions, the four-part format *A.B.C.D* is recommended, where A, B, and C are integers ranging from 0 to 99, and D is an integer ranging from 0 to 999.<br>*A* indicates the major version number.<br>*B* indicates the minor version number.<br>*C* indicates the feature version number.<br>*D* indicates the patch version number.| Number| No|
| code | Application version number used only for application management by the operating system. It is not visible to end users. The configuration rules are as follows:<br>API version 5 and earlier versions: The value is a non-negative integer within 32 binary digits, which is converted from the value of **version.name**. The conversion rule is as follows: Value of **code** = A * 1,000,000 + B * 1,000 + C. For example, if the value of **version.name** is 2.2.1, the value of **code** is 2002001. <br>API version 6 and later versions: The value of **code** is not associated with the value of **version.name** and can be customized. The value is a non-negative integer less than 2 to the power of 31. Note that the value must be updated each time the application version is updated, and the value for a later version must be greater than that for an earlier version.| Number| No|
| minCompatibleVersionCode | Earliest version compatible with the application. It is used in the cross-device scenario to check whether the application is compatible with a specific version on other devices. The value rules are the same as those of **version.code**.| Number| No (initial value: value of **code**)|

## Internal Structure of the apiVersion Attribute

**Table 3** Internal structure of the apiVersion attribute

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| compatible | Minimum API version required for running the application. The value ranges from 0 to 2147483647.| Number| Yes (initial value: configured in **build.profile** and filled in **config.json** by DevEco Studio during packaging)|
| target | Target API version required for running the application. The value ranges from 0 to 2147483647.| Number| Yes (initial value: configured in **build.profile** and filled in **config.json** by DevEco Studio during packaging)|
| releaseType | SDK status when the application is running.<br>**canary**: preliminary release open only to specific developers. This release does not promise API stability and may require tolerance of instability.<br>**beta**: release open to all developers. This release does not promise API stability and may require tolerance of instability. After several releases, the beta version is declared as an API stability milestone through Release Notes, and APIs of later versions are frozen.<br>**release**: official release open to all developers. This release promises that all APIs are stable. When a version is in this state, ths stage is not displayed in the version number.| String| Yes (initial value: configured in **build.profile** and filled in **config.json** by DevEco Studio during packaging)|

Example of the **app** tag:

```json
"app": {
    "bundleName": "com.example.myapplication",
    "vendor": "example",
    "version": {
      "code": 8,
      "name": "8.0.1"
    },
    "apiVersion": {
      "compatible": 8,
      "target": 9,
      "releaseType": "Beta1"
    }
  }
```
