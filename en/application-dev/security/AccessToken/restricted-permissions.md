# Restricted Permissions

<!--Kit: ArkUI-->
<!--Subsystem: Security-->
<!--Owner: @harylee-->
<!--SE: @linshuqing; @hehehe-li-->
<!--TSE: @leiyuqian-->

## How to Request

<!--RP1-->

Restricted permissions are permissions available to normal applications but must be requested via [access control list (ACL)](app-permission-mgmt-overview.md#basic-concepts-in-the-permission-mechanism).

To change the APL of a normal application to system_basic or system_core, modify the HarmonyAppProvision file (**Toolchains / _{Version} _/ lib / UnsgnedReleasedProfileTemplate.json** file in the SDK directory) of the application when developing the application installation package, and sign the application again.

**Modification mode**:

Modify the **"bundle-info"** &gt; **"apl"** field in the file.

```json
"bundle-info" : {
    // ...
    "apl": "system_basic",
    // ...
},
```

> **NOTE**
> Modifying the HarmonyAppProvision configuration file applies to the applications in the debug phase, but not to the applications released to the app market. For a commercial application, apply for a release certificate and profile in the app market.

<!--RP1End-->

## ohos.permission.SYSTEM_FLOAT_WINDOW

Allows an application to be displayed in a floating window on top of other applications.

<!--RP25--><!--RP25End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Since**: 7

## ohos.permission.READ_CONTACTS

Allows an application to read **Contacts**.

<!--RP33--><!--RP33End-->

**Permission level**: system_basic

**Authorization mode**: user_grant

**Since**: 8

## ohos.permission.WRITE_CONTACTS

Allows an application to add, remove, and modify **Contacts**.

<!--RP34--><!--RP34End-->

**Permission level**: system_basic

**Authorization mode**: user_grant

**Since**: 8

## ohos.permission.READ_AUDIO

Allows an application to access the audio files in a user directory.

<!--RP26--><!--RP26End-->

**Permission level**: system_basic

**Authorization mode**: user_grant

**Since**: 9

## ohos.permission.WRITE_AUDIO

Allows an application to modify the audio files in a user directory.

<!--RP28--><!--RP28End-->

**Permission level**: system_basic

**Authorization mode**: user_grant

**Since**: 9

## ohos.permission.READ_IMAGEVIDEO

Allows an application to access the images/videos in a user directory.

<!--RP27--><!--RP27End-->

**Permission level**: system_basic

**Authorization mode**: user_grant

**Since**: 9

## ohos.permission.WRITE_IMAGEVIDEO

Allows an application to modify the images/videos in a user directory.

<!--RP29--><!--RP29End-->

**Permission level**: system_basic

**Authorization mode**: user_grant

**Since**: 9

<!--Del-->
## ohos.permission.WRITE_DOCUMENT

Allows an application to modify the documents in a user directory.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Since**: 9

**Deprecated from**: 12

**Alternative solution**:

See the [alternative solution of the **Files** permission group](app-permission-group-list.md#filesdeprecated).

## ohos.permission.READ_DOCUMENT

Allows an application to access the documents in a user directory.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Since**: 9

**Deprecated from**: 12

**Alternative solution**:

See the [alternative solution of the **Files** permission group](app-permission-group-list.md#filesdeprecated).
<!--DelEnd-->

## ohos.permission.READ_WRITE_DESKTOP_DIRECTORY

Allows an application to access the **Desktop** directory and its subdirectories in the user directory.

<!--RP15-->
Currently, only applications on 2-in-1 devices and tablets can request this permission.
<!--RP15End-->

**Permission level**: system_basic

**Authorization mode**: user_grant

**Since**: 11

## ohos.permission.ACCESS_DDK_USB

Allows extended peripheral drivers to access the USB DDK interfaces to implement development of USB extended peripheral drivers.

<!--RP31--><!--RP31End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Since**: 11

## ohos.permission.ACCESS_DDK_HID

Allows extended peripheral drivers to access the HID DDK interfaces to implement development of HID extended peripheral drivers.

<!--RP30--><!--RP30End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Since**: 11

## ohos.permission.READ_PASTEBOARD

Allows an application to read **Pasteboard** data.

<!--RP32--><!--RP32End-->

**Permission level**: system_basic

**Authorization mode**: user_grant

**Since**: 11

## ohos.permission.FILE_ACCESS_PERSIST

Allows an application to support persistent access to file URIs.

<!--RP18--><!--RP18End-->

**Permission level**: normal

**Authorization mode**: system_grant

**Since**: 11

**Changelog**: The permission level is system_basic in API version 11, and is changed to normal since API version 12.

## ohos.permission.INTERCEPT_INPUT_EVENT

Allows an application to intercept input events.

<!--RP24--><!--RP24End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Since**: 11

**Changelog**: The permission level is system_core in API version 11, and is changed to system_basic since API version 12.

## ohos.permission.INPUT_MONITORING

Allows an application to listen for input events.

<!--RP23--><!--RP23End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Since**: 7

**Changelog**: The permission level is system_core in API versions 7 to 11, and is changed to system_basic since API version 12.

## ohos.permission.SHORT_TERM_WRITE_IMAGEVIDEO

Allows an application to save images and videos to the user's directory within

up to 30 minutes after obtaining the permission. If it exceeds 30 minutes, a dialog box will be displayed again to request user authorization.

<!--RP21--><!--RP21End-->

**Permission level**: system_basic

**Authorization mode**: user_grant

**Since**: 12

## ohos.permission.READ_WRITE_USER_FILE

Allows an application to access and modify files in user directories.

<!--RP19-->
Currently, this permission is available only to 2-in-1 device applications.
<!--RP19End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Since**: 13

## ohos.permission.READ_WRITE_USB_DEV

Allows an application to connect to a device and read and write the device data via USB for debugging purposes.

<!--RP20-->
Currently, this permission is available only to 2-in-1 device applications.
<!--RP20End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Since**: 13

## ohos.permission.GET_WIFI_PEERS_MAC

Allows an application to obtain the MAC address of the peer Wi-Fi device.

This permission is required if you want to obtain the MAC address of the peer device when obtaining the Wi-Fi scanning result.

<!--RP14--><!--RP14End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Since**: 8

**Changelog**: The permission level is system_core in API versions 8 to 13, and is changed to system_basic since API version 14.

## ohos.permission.kernel.DISABLE_CODE_MEMORY_PROTECTION

Allows an application to disable its runtime code integrity protection.

<!--RP11-->
For the application developed using the cross-platform framework, this permission allows the application to disable its runtime code integrity protection. Currently, this permission is available only to applications running on tablets and 2-in-1 devices.
<!--RP11End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Since**: 14

## ohos.permission.kernel.ALLOW_WRITABLE_CODE_MEMORY

Allows an application to apply for writable and executable anonymous memory.

<!--RP10-->
For the application developed using the cross-platform framework, this permission allows the application to apply for writable and executable anonymous memory. Currently, this permission is available only to applications running on tablets and 2-in-1 devices.
<!--RP10End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Since**: 14

## ohos.permission.kernel.ALLOW_EXECUTABLE_FORT_MEMORY

Allows an application to have its system JS engine to apply for anonymous executable memory with the MAP_FORT identifier.

After the application has this permission, the system JS engine can request anonymous executable memory with MAP_FORT for just-in-time (JIT) compilation, which increase the runtime execution efficiency.

<!--RP13--><!--RP13End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Since**: 14

## ohos.permission.MANAGE_PASTEBOARD_APP_SHARE_OPTION

Allows an application to set or remove the pasteable range of pasteboard data.

<!--RP16--><!--RP16End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Since**: 14

## ohos.permission.MANAGE_UDMF_APP_SHARE_OPTION

Allows an application to set or remove the sharing range of the data supported by the UDMF.

<!--RP17--><!--RP17End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Since**: 14

## ohos.permission.ACCESS_DISK_PHY_INFO

Allows an application to obtain the disk hardware information.

<!--RP3--><!--RP3End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Since**: 15

## ohos.permission.PRELOAD_FILE

Allows an application to preload files to improve the file opening speed.

<!--RP9--><!--RP9End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Since**: 15

## ohos.permission.SET_PAC_URL

Allows an application to set the URL of the proxy auto config (PAC) script.

After the script address is configured, other applications can read and parse this script and determine whether to use a proxy based on the parsing result.

<!--RP4--><!--RP4End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Since**: 15

## ohos.permission.PERSONAL_MANAGE_RESTRICTIONS

Allows a device administrator application to manage personal device restrictions.

<!--RP7--><!--RP7End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Since**: 15

## ohos.permission.START_PROVISIONING_MESSAGE

Allows an application to start the device management service deployment process, which activates the application as a personal device administrator application.

<!--RP8--><!--RP8End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Since**: 15

## ohos.permission.USE_FRAUD_CALL_LOG_PICKER

Allows an application to use the fraud call log Picker to obtain call logs.

<!--RP5--><!--RP5End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Since**: 15

## ohos.permission.USE_FRAUD_MESSAGES_PICKER

Allows an application to use the fraud message Picker to obtain SMS messages.

<!--RP6--><!--RP6End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Since**: 15

## ohos.permission.PERSISTENT_BLUETOOTH_PEERS_MAC

Allows an application to persist the virtual random address corresponding to the MAC address of the peer Bluetooth device.

With this permission, the application can persist the virtual random address of the peer Bluetooth device obtained via BLE scanning, BR scanning, or listening for connections. The persistent virtual random address can still be used even if Bluetooth is enabled or disabled, or the Bluetooth device is restarted.

<!--RP36--><!--RP36End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Since**: 16

## ohos.permission.ACCESS_VIRTUAL_SCREEN

Allows an application to manage virtual screens.

With this permission, the application can call APIs to perform virtual screen management, including creating, using, and destroying a virtual screen.

<!--RP37--><!--RP37End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Since**: 18

## ohos.permission.MANAGE_APN_SETTING

Allows an application to read or set APN information.

<!--RP38--><!--RP38End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Since**: 16

## ohos.permission.GET_WIFI_LOCAL_MAC

Allows an application to obtain the MAC address of the local Wi-Fi device.

<!--RP43--><!--RP43End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Since**: 8

**Change history:** For API versions 8 to 15, this permission is available only to system applications. For API versions 16 and later, this permission is available to common applications on PCs/2-in-1 devices, and is available only to system applications on other devices.

## ohos.permission.kernel.ALLOW_USE_JITFORT_INTERFACE

Allows an application to call the JITFort API to update the content in MAP_FORT.

<!--RP12--><!--RP12End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Since**: 16

## ohos.permission.kernel.DISABLE_GOTPLT_RO_PROTECTION

Allows an application to disable the read-only protection on .got.plt.

<!--RP22--><!--RP22End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Since**: 17

## ohos.permission.USE_FRAUD_APP_PICKER

Allows an application to use the fraud app Picker to obtain application information.

<!--RP2--><!--RP2End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Since**: 18

## ohos.permission.ACCESS_DDK_DRIVERS

Allows a peripheral extension driver client to bind to the driver server.

This permission can be requested successfully only when:

1. The target extension driver server in the value field of the permission declaration for the peripheral extension driver client has been launched or both the server and client have been launched.
2. The capabilities provided by the target extension driver server comply with the requirements of the peripheral extension driver client.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Extra data**: Yes. For details about the configuration method, see [UI-based Driver Development](../../device/driver/externaldevice-guidelines.md#application-signing).

**Since**: 18

## ohos.permission.kernel.SUPPORT_PLUGIN

Allows an application to install plugins.

<!--RP35--><!--RP35End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Since**: 19

## ohos.permission.CUSTOM_SANDBOX

Allows an application to set the sandbox type to dynamic sandbox.

<!--RP39--><!--RP39End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Since**: 18

## ohos.permission.MANAGE_SCREEN_TIME_GUARD

Allows an application to call the screen time guard APIs to restrict screen usage, apply application access control, and control the screen usage time.

<!--RP40--><!--RP40End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Since**: 20

## ohos.permission.CUSTOMIZE_SAVE_BUTTON

Allows an application to customize the icon and text of **SaveButton**.

<!--RP41--><!--RP41End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Device**: general devices

**Since**: 20

## ohos.permission.GET_ABILITY_INFO

Allows an application to obtain **Ability** information based on a URI or the file type.

<!--RP42--><!--RP42End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Device**: PCs/2-in-1 devices

**Since**: 20

## ohos.permission.ACCESS_FIDO2_ONLINEAUTH

Allows an application to use the Native Development Kit (NDK) of the passkey service.

<!--RP45--><!--RP45End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Device**: phones | PCs/2-in-1 devices | tablets

**Since**: 20

## ohos.permission.USE_FLOAT_BALL

Allows an application to use the global float ball.

<!--RP46--><!--RP46End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Device**: phones | tablets

**Since**: 20

## ohos.permission.DLP_GET_HIDE_STATUS

Allows an application to use the information hiding APIs to obtain the information hiding status.

With this permission, the application can obtain the current screen peeping state, that is, whether the screen is being peeped by others.

<!--RP44--><!--RP44End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Device**: phones

**Since**: 18

**Changelog**: This permission is available only to system applications in API versions 18 to 19. From API version 20, it's also available to normal applications.

## ohos.permission.READ_LOCAL_DEVICE_NAME

Allows an application to obtain the local device name.

With this permission, the application can obtain the device name on the **About** screen in **Settings**. Without this permission, the application can only obtain the default device name.

<!--RP47--><!--RP47End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Device**: phones | PCs/2-in-1 devices | tablets

**Since**: 20

<!--Del-->
## ohos.permission.atomicService.MANAGE_STORAGE

Allows an atomic service to request differentiated storage space.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Device**: phones | PCs/2-in-1 devices | tablets

**Since**: 20
<!--DelEnd-->

## ohos.permission.KEEP_BACKGROUND_RUNNING_SYSTEM

Allows an application to request continuous tasks of special types, such as computing tasks.

<!--RP48--><!--RP48End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Device**: general devices

**Since**: 20

## ohos.permission.LINKTURBO

Allows an application to achieve multipath transmission.

With this permission, the application can initiate operations such as multi-network activation, monitoring, and release for multipath transmission.

<!--RP49--><!--RP49End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Device**: phones | PCs/2-in-1 devices | tablets

**Since**: 20

## ohos.permission.ACCESS_NET_TRACE_INFO

Allows an application to detect the network and obtain the TraceRoute information to determine the possible causes of high network latency.

<!--RP50--><!--RP50End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Device**: general devices

**Since**: 20

## ohos.permission.SET_SYSTEMSHARE_APPLAUNCHTRUSTLIST

Allows an application to set the trust list of target applications for system sharing.

With this permission, the application can choose the target applications for system sharing.

<!--RP53--><!--RP53End-->

**Permission level**：system_basic

**Authorization mode**：system_grant

**Device**：Phone | PC/2in1 | Tablet

**Since**：21

## ohos.permission.HOOK_KEY_EVENT

Allows an application to intercept keyboard input events.

With this permission, the application can integrate its custom key handling process into the system's key handling process prior to the key event being dispatched to the application window.

<!--RP52--><!--RP52End-->

**Permission level**: system_basic

**Authorization mode**: manual_settings

**Device**: PC/2in1 | Tablet

**Since**: 21