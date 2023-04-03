# Updates (OpenHarmony 3.2 Beta2 -> OpenHarmony 3.2 Beta3)

## Bundle Management Framework

The privilege control capability is added for preset applications. The capability can be divided into two parts: permission control for preset applications and configuration of preset applications.
Application privileges are high-level capabilities of an application, for example, restricting an application from being uninstalled or restricting application data from being deleted.
OpenHarmony provides both general and device-specific application privileges. The latter can be configured by device vendors for applications on different devices. OpenHarmony supports differentiated configuration of preset applications on different devices. In addition, OpenHarmony provides **GetCfgDirList** for your application to obtain the preset directories, such as **system**, **chipset**, **sys_prod**, and **chip_prod**, in ascending order of priority. For example, the priority of **chip_prod** is higher than that of **system**.

### Changed Installation Mode for Preset Applications

In earlier versions, preset applications are installed by automatically scanning and installing HAP files in the **/system/app** directory. From this version, preset applications are configured based on the trustlist. Specifically, only the HAP file configured with **app-dir** in the **install_list.json** file can be automatically installed as a preset application.

**Change Impacts**

JS and native APIs are not involved, and application development is not affected.

**Key API/Component Changes**

N/A

**Adaptation Guide**

Configure related fields in the [/system/etc/app/install_list.json](https://gitee.com/openharmony/vendor_hihope/blob/master/rk3568/preinstall-config/install_list.json) file. The **app_dir** field specifies the directory where the HAP file is located, and **removable** specifies whether the HAP file can be uninstalled after being installed. 

Example:

```json
{
    "install_list" : [
        {
            "app_dir" : "/system/app/com.ohos.systemui",
            "removable" : false
        },
        {
            "app_dir" : "/system/app/demo.hap",
            "removable" : true
        }
    ]
}
```

### Changes in General Application Privilege Control

For a specific application, the general application privileges remain unchanged on all types of devices. The general application privileges are as follows:
| Permission| Description                                                      |
| ---------------- | ------------------------------------------------------------ |
| AllowAppDataNotCleared | Allows application data to be deleted.|
| AllowAppMultiProcess | Allows the application to run on multiple processes.|
| AllowAppDesktopIconHide | Allows the application icon to be hidden from the home screen.|
| AllowAbilityPriorityQueried | Allows an ability to configure and query the priority.    |
| AllowAbilityExcludeFromMissions | Allows an ability to be hidden in the mission stack.|
| AllowAppUsePrivilegeExtension | Allows the application to use ServiceExtensionAbilities and DataExtensionAbilities.|
| AllowFormVisibleNotify | Allows a widget to be visible on the home screen.|

In earlier versions, these privileges are configured in the **config.json** or **module.json** file and distinguished based on the application type (preset or system application). From this version, the privileges are configured based on the signing certificate and preset trustlist.

**Change Impacts**

JS and native APIs are not involved. If your application needs to use any of these privileges, apply for it. For details about how to apply for and configure the privileges, see [Application Privilege Configuration](../../../device-dev/subsystems/subsys-app-privilege-config-guide.md).

**Key API/Component Changes**

N/A

**Adaptation Guide**

See [Application Privilege Configuration](../../../device-dev/subsystems/subsys-app-privilege-config-guide.md).

```json
{
    "version-name": "1.0.0",
    ...
    "bundle-info": {
        "developer-id": "OpenHarmony",
        ...
    },
    "issuer": "pki_internal",
    "app-privilege-capabilities": ["AllowAppDataNotCleared", "AllowAppDesktopIconHide"] // The application data cannot be deleted, and the icon can be hidden on the home screen.
}
```

### Changes in Device-specific Application Privilege Control
In addition to general application privileges, device vendors can define device-specific privileges for an application, as described in the table below.

| Permission                 | Type    | Default Value| Description                                             |
| --------------------- | -------- | ------ | ------------------------------------------------- |
| removable             | bool     | true   | Allows the application to be uninstalled. This permission takes effect only for preset applications.               |
| keepAlive             | bool     | false  | Allows the application to remain resident in the background.                                 |
| singleton             | bool     | false  | Allows the application to be installed for a single user (User 0).                   |
| allowCommonEvent      | string[] | -      | Allows the application to be started by a static broadcast.                             |
| associatedWakeUp      | bool     | false  | Allows the application in the FA model to be woken up by an associated application.                     |
| runningResourcesApply | bool     | false  | Allows the application to request running resources, such as CPU, event notifications, and Bluetooth.|

In earlier versions, these privileges are configured in the **config.json** or **module.json** file and distinguished based on the application type (preset or system application). From this version, the privileges can be configured based on the preset trustlist. For details, see [install_list_capability.json](https://gitee.com/openharmony/vendor_hihope/blob/master/rk3568/preinstall-config/install_list_capability.json).

**Change Impacts**

JS and native APIs are not involved. If your application needs to use any of these privileges, apply for it. For details, see [Configuration Mode](../../../device-dev/subsystems/subsys-app-privilege-config-guide.md#configuration-1).

**Key API/Component Changes**

N/A

**Adaptation Guide**

See [Configuration Mode](../../../device-dev/subsystems/subsys-app-privilege-config-guide.md#configuration-1).

```json
{
    "install_list": [
        {
            "bundleName": "com.example.kikakeyboard",
            "singleton": true, // The application is installed for a single user.
            "keepAlive": true, // The application remains resident in the background.
            "runningResourcesApply": true, // The application can apply for running resources such as CPU, event notifications, and Bluetooth.
            "associatedWakeUp": true, // The application in the FA model can be woken up by an associated application.
            "app_signature": ["8E93863FC32EE238060BF69A9B37E2608FFFB21F93C862DD511CBAC"], // The setting takes effect only when the configured certificate fingerprint is the same as the HAP certificate fingerprint.
            "allowCommonEvent": ["usual.event.SCREEN_ON", "usual.event.THERMAL_LEVEL_CHANGED"]
        }
}
```

### Fingerprint Verification for Pre-authorization Trustlist

The pre-authorization file [install_list_permissions.json](https://gitee.com/openharmony/vendor_hihope/blob/master/rk3568/preinstall-config/install_list_permissions.json) is moved from **system/etc/permission** to **system/etc/app/** on the development board. The **app_signature** field is added to specify the fingerprint of the HAP file. Multiple fingerprints can be configured. Authorization can be performed only when the fingerprint is matched.

**Change Impacts**

JS and native APIs are not involved. If your application uses pre-authorization, add the fingerprint to the pre-authorization file.

**Key API/Component Changes**

N/A

**Adaptation Guide**

Refer to the following code:

```json
{
[
    {
        "bundleName" : "com.ohos.screenshot",
        "app_signature" : ["8E93863FC32EE238060BF69A9B37E2608FFFB21F93C862DD511CBAC9F30024B5"],
        "permissions" : [
            {
                "name" : "ohos.permission.MEDIA_LOCATION",
                "userCancellable" : true
            },
            {
                "name" : "ohos.permission.READ_MEDIA",
                "userCancellable" : true
            },
            {
                "name" : "ohos.permission.WRITE_MEDIA",
                "userCancellable" : true
            }
        ]
    }
}
```

## ArkUI Development Framework

### Rectified Variable Sharing Issue of the Common Module in Release HAP Mode During Building in the FA Model

Assume that two pages depend on the same object (foodData) of a file. If page A modifies the object, page B obtains the new value when reading the object. This implements object sharing for the common module.

**Change Impacts**

Application compilation is not affected, and no interface adaptation is required.

**Key API/Component Changes**

N/A

### Restrictions on Declaring Multiple Data Types of State Variables

If a **@State**, **@Provide**, **@Link**, or **@Consume** decorated state variable supports multiple data types, they must be all simple data types or references at one time.

Example:

```ts
@Entry
@Component
struct Index {
  // Incorrect: @State message: string | Resource = 'Hello World'
  @State message: string = 'Hello World'

  build() {
    Row() {
      Column() {
        Text(`${ this.message }`)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

**Change Impacts**

When the defined state variable type contains both the simple data types and references, an error is reported during compilation.

**Key API/Component Changes**

If the defined state variable type contains both the simple data types and references, change the type to one of them, as shown in the preceding sample code.

## Globalization Subsystem

### Added Validity Verification for Color Values in Color.json

Validity verification is added for color values in the **color.json** file. The verification rules are as follows:

- The hexadecimal color code is used in any of the following formats:
    - #rgb: red(0-f) green(0-f) blue(0-f)
    - #argb: transparency(0-f) red(0-f) green(0-f) blue(0-f)
    - #rrggbb: red(00-ff) green(00-ff) blue(00-ff)
    - #aarrggbb: transparency(00-ff) red(00-ff) green(00-ff) blue(00-ff)
- The dollar sign ($) is used to reference resources defined in the application. The format is as follows:
    - $color:xxx

**Change Impacts**

If the verification rules are not met, an error is reported during compilation.

**Key API/Component Changes**

N/A

## Power Management Subsystem

### File Name Changed

The name of the API declaration file is changed from **@ohos.batteryinfo.d.ts** to **@ohos.batteryInfo.d.ts**.

**Change Impacts**

When you reference the statement in a JS or TS file, use **import batteryInfo from '@ohos.batteryInfo';** instead of **import batteryInfo from '@ohos.batteryinfo'**.

**Key API/Component Changes**

N/A

### File Name Changed

The name of the API declaration file is changed from **@ohos.runninglock.d.ts** to **@ohos.runningLock.d.ts**.

**Change Impacts**

When you reference the statement in a JS or TS file, use **import runningLock from '@ohos.runningLock';** instead of **import runningLock from '@ohos.runninglock';**.

**Key API/Component Changes**

N/A
