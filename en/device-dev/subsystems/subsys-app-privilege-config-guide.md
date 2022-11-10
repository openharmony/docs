# Application Privilege Configuration Guide

Application privileges are high-level capabilities of an application, for example, restricting an application from being uninstalled or restricting application data from being deleted.

OpenHarmony provides both general and device-specific application privileges. The latter can be configured by device vendors for applications on different devices.

Note: To avoid user dissatisfaction or even infringement, do not abuse application privileges.

## General Application Privileges

### Introduction

General application privileges are privileges available to applications on all types of devices. The general application privileges include the following:

| Privilege| Description                                                      |
| ---------------- | ------------------------------------------------------------ |
| AllowAppDataNotCleared | Allows application data not to be deleted.|
| AllowAppMultiProcess | Allows the application to run on multiple processes.|
| AllowAppDesktopIconHide | Allows the application icon to be hidden from the home screen.|
| AllowAbilityPriorityQueried | Allows an ability to configure and query the priority.    |
| AllowAbilityExcludeFromMissions | Allows an ability to be hidden in the mission stack.|
| AllowAppUsePrivilegeExtension | Allows the application to use Service Extension and Data Extension abilities.|
| AllowFormVisibleNotify | Allows a widget to be visible on the home screen.|

### Configuration

1. In the [HarmonyAppProvision file](https://gitee.com/openharmony/docs/blob/master/en/application-dev/quick-start/app-provision-structure.md), configure the general privileges in the **app-privilege-capabilities** field.
2. Use the signing tool to sign the HarmonyAppProvision file and generate a **.p7b** file.
3. Use the **.p7b** file to sign the HAP.

Reference: [hapsigner](https://gitee.com/openharmony/developtools_hapsigner#README.md)

### Example

```
{
    "version-name": "1.0.0",
    ...
    "bundle-info": {
        "developer-id": "OpenHarmony",
        ...
    },
    "issuer": "pki_internal",
    "app-privilege-capabilities": ["AllowAppDataNotCleared", "AllowAppDesktopIconHide"] // The application data cannot be deleted, and icons can be hidden on the home screen.
}
```



## Device-specific Application Privileges

### Introduction

In addition to general application privileges, device vendors can define device-specific privileges for an application, as described in the table below.

| Privilege                 | Type    | Default Value| Description                                             |
| --------------------- | -------- | ------ | ------------------------------------------------- |
| removable             | bool     | true   | Allows the application to be uninstalled. This privilege takes effect only for preset applications.               |
| keepAlive             | bool     | false  | Allows the application to keep running in the background.                                 |
| singleton             | bool     | false  | Allows the application to be installed for a single user (U0).                   |
| allowCommonEvent      | string[] | -      | Allows the application to be started by a static broadcast.                             |
| associatedWakeUp      | bool     | false  | Allows the application in the FA model to be woken up by an associated application.                     |
| runningResourcesApply | bool     | false  | Allows the application to request running resources, such as the CPU, event notifications, and Bluetooth.|

### Configuration

Configure the required privileges in the [configuration files](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568/preinstall-config).

### Example

#### Configuration in **install_list_capability.json**

```
{
    "install_list": [
        {
            "bundleName": "com.example.kikakeyboard",
            "singleton": true, // The application is installed for a single user.
            "keepAlive": true, // The application is running in the background.
            "runningResourcesApply": true, // The application can apply for running resources such as the CPU, event notifications, and Bluetooth.
            "associatedWakeUp": true, // The application in the FA model can be woken up by an associated application.
            "app_signature": ["8E93863FC32EE238060BF69A9B37E2608FFFB21F93C862DD511CBAC"], // The settings take effect only when the configured certificate fingerprint is the same as the HAP certificate fingerprint.
            "allowCommonEvent": ["usual.event.SCREEN_ON", "usual.event.THERMAL_LEVEL_CHANGED"]
        },
}
```

**Obtaining the Certificate Fingerprint**

1. Create the **profile.cer** file, and copy the certificate content under the **distribution-certificate** field of the HarmonyAppProvision file to the **profile.cer** file.

   Example:

   ```
   {
       ...
       "bundle-info": {
           "distribution-certificate": "-----BEGIN CERTIFICATE----\nMIICMzCCAbegAwIBAgIEaOC/zDAMBggqhkjOPQQDAwUAMk..." / Certificate content.
           ...
       }
       ...
   }
   ```

   

2. Apply line breaks in the **profile.cer** content and remove the newline characters.

   Example:

   ```
   -----BEGIN CERTIFICATE-----
   MIICMzCCAbegAwIBAgIEaOC/zDAMBggqhkjOPQQDAwUAMGMxCzAJBgNVBAYTAkNO
   MRQwEgYDVQQKEwtPcGVuSGFybW9ueTEZMBcGA1UECxMQT3Blbkhhcm1vbnkgVGVh
   bTEjMCEGA1UEAxMaT3Blbkhhcm1vbnkgQXBwbGljYXRpb24gQ0EwHhcNMjEwMjAy
   MTIxOTMxWhcNNDkxMjMxMTIxOTMxWjBoMQswCQYDVQQGEwJDTjEUMBIGA1UEChML
   T3Blbkhhcm1vbnkxGTAXBgNVBAsTEE9wZW5IYXJtb255IFRlYW0xKDAmBgNVBAMT
   H09wZW5IYXJtb255IEFwcGxpY2F0aW9uIFJlbGVhc2UwWTATBgcqhkjOPQIBBggq
   hkjOPQMBBwNCAATbYOCQQpW5fdkYHN45v0X3AHax12jPBdEDosFRIZ1eXmxOYzSG
   JwMfsHhUU90E8lI0TXYZnNmgM1sovubeQqATo1IwUDAfBgNVHSMEGDAWgBTbhrci
   FtULoUu33SV7ufEFfaItRzAOBgNVHQ8BAf8EBAMCB4AwHQYDVR0OBBYEFPtxruhl
   cRBQsJdwcZqLu9oNUVgaMAwGCCqGSM49BAMDBQADaAAwZQIxAJta0PQ2p4DIu/ps
   LMdLCDgQ5UH1l0B4PGhBlMgdi2zf8nk9spazEQI/0XNwpft8QAIwHSuA2WelVi/o
   zAlF08DnbJrOOtOnQq5wHOPlDYB4OtUzOYJk9scotrEnJxJzGsh/
   -----END CERTIFICATE-----
   ```

   

3. Use keytool to print the certificate fingerprint.

   Example:

   ```
   keytool -printcert -file profile.cer
   result:
   Issued To: CN=OpenHarmony Application Release, OU=OpenHarmony Team, O=OpenHarmony, C=CN
   Issued By: CN=OpenHarmony Application CA, OU=OpenHarmony Team, O=OpenHarmony, C=CN
   SN: 68e0bfcc
   Valid From: Tue Feb 02 20:19:31 CST 2021, Valid To: Fri Dec 31 20:19:31 CST 2049
   Fingerprints:
            SHA1 fingerprint: E3:E8:7C:65:B8:1D:02:52:24:6A:06:A4:3C:4A:02:39:19:92:D1:F5
            SHA256 fingerprint: 8E:93:86:3F:C3:2E:E2:38:06:0B:F6:9A:9B:37:E2:60:8F:FF:B2:1F:93:C8:62:DD:51:1C:BA:C9:F3:00:24:B5 // After the colons are removed, the fingerprint is 8E93863FC32EE238060BF69A9B37E2608FFFB21F93C862DD511CBAC9F30024B5.
   ...
   ```

   

#### Configuration in **install_list.json**

```
{
     "install_list" : [
        {
            "app_dir" : "/system/app/com.ohos.launcher",
            "removable": true // The application can be uninstalled.
        }
     ]
}
```
