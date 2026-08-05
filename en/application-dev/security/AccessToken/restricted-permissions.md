# Restricted Permissions

<!--Kit: Ability Kit-->
<!--Subsystem: Security-->
<!--Owner: @xia-bubai-->
<!--Designer: @linshuqing; @hehehe-li-->
<!--Tester: @leiyuqian-->
<!--Adviser: @zengyawen-->

## How to Request

<!--RP1-->

Restricted permissions are permissions available to normal applications but must be requested via [access control list (ACL)](app-permission-mgmt-overview.md#basic-concepts-in-the-permission-mechanism).

To change the APL of a normal application to system_basic or higher, modify the HarmonyAppProvision file (**Toolchains / _{Version} _/ lib / UnsignedReleasedProfileTemplate.json** file in the SDK directory) of the application when developing the application installation package, and sign the application again.

**Modification mode**:

Modify the **"bundle-info"** &gt; **"apl"** field in the file.

```json5
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

Allows an application to access the audio files in a user public directory.

<!--RP26--><!--RP26End-->

**Permission level**: system_basic

**Authorization mode**: user_grant

**Since**: 9

## ohos.permission.WRITE_AUDIO

Allows an application to modify the audio files in a user public directory.

<!--RP28--><!--RP28End-->

**Permission level**: system_basic

**Authorization mode**: user_grant

**Since**: 9

## ohos.permission.READ_IMAGEVIDEO

Allows an application to read image or video files from users' local public directories. 

<!--RP27--><!--RP27End-->

**Permission level**: system_basic

**Authorization mode**: user_grant

**Since**: 9

**Changelog**: In API versions 9 to 24, this permission allows an application to access images or videos stored on the cloud or locally. From API version 26.0.0, this permission allows an application to read only images or videos in users' local public directories.

## ohos.permission.WRITE_IMAGEVIDEO

Allows an application to modify the images/videos in a user public directory.

<!--RP29--><!--RP29End-->

**Permission level**: system_basic

**Authorization mode**: user_grant

**Since**: 9

<!--Del-->
## ohos.permission.WRITE_DOCUMENT

Allows an application to modify the documents in a user public directory.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Since**: 9

**Deprecated from**: 12

**Alternative solution**:

See the [alternative solution of the **Files** permission group](app-permission-group-list.md#filesdeprecated).

## ohos.permission.READ_DOCUMENT

Allows an application to access the documents in a user public directory.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Since**: 9

**Deprecated from**: 12

**Alternative solution**:

See the [alternative solution of the **Files** permission group](app-permission-group-list.md#filesdeprecated).
<!--DelEnd-->

## ohos.permission.READ_WRITE_DESKTOP_DIRECTORY

Allows an application to access the **Desktop** directory and its subdirectories in the user public directory.

Currently, only applications on 2-in-1 devices and tablets can request this permission.

<!--RP15--><!--RP15End-->

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

**Supported devices**: Phone | TV | Wearable | PC/2in1 | Tablet | Car

**Since**: 11

## ohos.permission.FILE_ACCESS_PERSIST

Allows an application to support persistent access to file URIs.

> **NOTE**
>
> In API 12 and later versions, the permission level is changed to normal, and applications can directly [declare permissions](declare-permissions.md). If compatibility with versions earlier than API 12 is required, the permission must still be used following the [request method for restricted permissions](declare-permissions-in-acl.md).

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

**Supported devices**: general devices

**Since**: 11

**Changelog**: The permission level is system_core in API version 11, and is changed to system_basic since API version 12. Since API version 26.0.0, this permission is available on all devices.

## ohos.permission.INPUT_MONITORING

Allows an application to listen for input events.

<!--RP23--><!--RP23End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Since**: 7

**Changelog**: The permission level is system_core in API versions 7 to 11, and is changed to system_basic since API version 12.

## ohos.permission.SHORT_TERM_WRITE_IMAGEVIDEO

Allows an application to save images and videos to the user public directory within

up to 30 minutes after obtaining the permission. If it exceeds 30 minutes, a dialog box will be displayed again to request user authorization.

<!--RP21--><!--RP21End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

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

## ohos.permission.SET_TELEPHONY_ESIM_STATE_OPEN

Allows a carrier application to add eSIM configuration files.

<!--RP86--><!--RP86End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Since**: 13

**Changelog**: The permission level is **normal** in API versions 13 and **system_basic** since API version 14.

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

After the application has this permission, the system JS engine can request anonymous executable memory with MAP_FORT for just-in-time (JIT) compilation, which increases the runtime execution efficiency.

<!--RP13--><!--RP13End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Since**: 14

## ohos.permission.MANAGE_PASTEBOARD_APP_SHARE_OPTION

Allows an application to set or remove the pasteable range of pasteboard data.

<!--RP16--><!--RP16End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: Phone | TV | Wearable | PC/2in1 | Tablet | Car

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

**Supported devices**: PCs/2-in-1 devices | tablets

**Since**: 15

**Changelog**: Since API version 26.0.0, this permission is also available on tablets.

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

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Since**: 15

## ohos.permission.START_PROVISIONING_MESSAGE

Allows an application to start the device management service deployment process, which activates the application as a personal device administrator application.

<!--RP8--><!--RP8End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: phones | PCs/2-in-1 devices | tablets

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

Allows an application to persist the virtual address corresponding to the MAC address of the peer Bluetooth device.

With this permission and the [access.addPersistentDeviceId](../../reference/apis-connectivity-kit/js-apis-bluetooth-access.md#accessaddpersistentdeviceid16) method, the application can persist the virtual address of the peer Bluetooth device obtained via BLE scanning, BR scanning, or listening for connections. The persistent virtual address can still be used even if Bluetooth is enabled or disabled, or the Bluetooth device is restarted.

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

**Since**: 16

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

## ohos.permission.GET_ETHERNET_LOCAL_MAC

Allows an application to obtain the current MAC address of the Ethernet.

<!--RP51--><!--RP51End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Since**: 13

**Changelog**: This permission is available only to MDM applications in API version 13. From API version 14, this permission is available to normal enterprise applications. From API version 16, this permission is available to normal applications on PCs/2-in-1 devices, and is available only to system applications on other devices.

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

<!--RP82--><!--RP82End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Extra data**: Yes. For details about the configuration method, see [UI-based Driver Development](../../device/driver/externaldevice-guidelines.md#application-signing).

**Since**: 18

## ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

Allows a peripheral extension driver to access the SCSI DDK APIs to implement development of SCSI extended peripheral drivers.

The APIs can be used to develop the following types of peripheral extension drivers:

Peripherals connected to the host via a USB bus and:

1. InterfaceClass of the peripheral is Mass Storage (0x08) and InterfaceSubClass is SCSI Transparent Command Set (0x06).
2. The peripheral can simulate a SCSI device in a way that is transparent to the operating system.

<!--RP83--><!--RP83End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Since**: 18

## ohos.permission.ACCESS_DDK_USB_SERIAL

Allows a peripheral extension driver to access the USB Serial DDK APIs.

The USB Serial DDK APIs can be used to develop the following types of peripheral extension drivers:

Peripherals connected to the host via a USB bus and:

1. InterfaceClass of the peripheral is Communication Device Control Class (0x02) and InterfaceSubClass follows ACMSubClass model(0x02).
2. The peripheral can simulate traditional serial communication through a USB interface.

<!--RP101--><!--RP101End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices: ** PCs/2-in-1 devices | tablets

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

## ohos.permission.atomicService.MANAGE_STORAGE

Allows a mini game of the atomic service type to manage its storage space.

<!--RP96--><!--RP96End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Since**: 20

## ohos.permission.MANAGE_SCREEN_TIME_GUARD

Allows an application to call the screen time guard APIs to restrict screen usage, apply application access control, and control the screen usage time.

<!--RP40--><!--RP40End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: phones | tablets

**Since**: 20

## ohos.permission.CUSTOMIZE_SAVE_BUTTON

Allows an application to customize the icon and text of **SaveButton**.

<!--RP41--><!--RP41End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: general devices

**Since**: 20

## ohos.permission.GET_ABILITY_INFO

Allows an application to query **Ability** information based on the URI or **FileType**.

<!--RP42--><!--RP42End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: PCs/2-in-1 devices

**Since**: 20

## ohos.permission.ACCESS_FIDO2_ONLINEAUTH

Allows an application to use the Native Development Kit (NDK) of the passkey service.

<!--RP45--><!--RP45End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Since**: 20

## ohos.permission.USE_FLOAT_BALL

Allows an application to use the global floating ball.

<!--RP46--><!--RP46End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Since**: 20

**Changelog**: Since API version 26.0.0, this permission is also available on PCs/2-in-1 devices.

## ohos.permission.AUTO_RESTORE_MAIN_WINDOW

Allows an application to automatically restore its main window through the global floating ball.

**Prerequisites**: This permission can only be requested together with the [ohos.permission.USE_FLOAT_BALL](#ohospermissionuse_float_ball) permission.

<!--RP69--><!--RP69End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: phones | tablets

**Since**: 24

## ohos.permission.DLP_GET_HIDE_STATUS

Allows an application to use the information hiding APIs to obtain the information hiding status.

With this permission, the application can obtain the current screen peeping state, that is, whether the screen is being peeped by others.

<!--RP44--><!--RP44End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: phones

**Since**: 18

**Changelog**: This permission is available only to system applications in API versions 18 to 19. From API version 20, it's also available to normal applications.

## ohos.permission.READ_LOCAL_DEVICE_NAME

Allows an application to obtain the local device name.

With this permission, the application can obtain the device name on the **About** screen in **Settings**. Without this permission, the application can only obtain the default device name.

<!--RP47--><!--RP47End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Since**: 20

<!--Del-->
## ohos.permission.atomicService.MANAGE_STORAGE

Allows an atomic service to request differentiated storage space.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Since**: 20
<!--DelEnd-->

## ohos.permission.KEEP_BACKGROUND_RUNNING_SYSTEM

Allows an application to request continuous tasks of special types, such as computing tasks.

<!--RP48--><!--RP48End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: general devices

**Since**: 20

## ohos.permission.LINKTURBO

Allows an application to achieve multipath transmission.

With this permission, the application can initiate operations such as multi-network activation, monitoring, and release for multipath transmission.

<!--RP49--><!--RP49End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Since**: 20

## ohos.permission.ACCESS_NET_TRACE_INFO

Allows an application to detect the network and obtain the TraceRoute information to determine the possible causes of high network latency.

<!--RP50--><!--RP50End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: general devices

**Since**: 20

## ohos.permission.READ_WHOLE_CALENDAR

Allows an application to read all calendar information.

<!--RP84--><!--RP84End-->

**Permission level**: system_basic

**Authorization mode**: user_grant

**Since**: 9

**Changelog**: This permission is available only to system applications in API versions 9 to 19. From API version 20, it's also available to normal applications.

## ohos.permission.WRITE_WHOLE_CALENDAR

Allows an application to add, remove, or change all calendar events.

<!--RP85--><!--RP85End-->

**Permission level**: system_basic

**Authorization mode**: user_grant

**Since**: 9

**Changelog**: This permission is available only to system applications in API versions 9 to 19. From API version 20, it's also available to normal applications.

## ohos.permission.SET_SYSTEMSHARE_APPLAUNCHTRUSTLIST

Allows an application to set the trustlist of target applications for system sharing.

With this permission, the application can choose the target applications for system sharing.

<!--RP53--><!--RP53End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: phones | PCs/2-in-1 devices | tablets | TVs

**Since**: 21

## ohos.permission.HOOK_KEY_EVENT

Allows an application to intercept keyboard input events.

With this permission, the application can integrate its custom key handling process into the system's key handling process prior to the key event being dispatched to the application window.

<!--RP52--><!--RP52End-->

**Permission level**: system_basic

**Authorization mode**: manual_settings

**Supported devices**: PCs/2-in-1 devices | tablets

**Since**: 21

## ohos.permission.WEB_NATIVE_MESSAGING

Allows an application to use the web native messaging capability.

With this permission, the application can enable communication between browser extensions and local applications.

<!--RP54--><!--RP54End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Since**: 21

**Changelog**: Since API version 24, this permission is also available on mobile phones and tablets.

## ohos.permission.SUBSCRIBE_NOTIFICATION

Allows an application to read notifications published by the system or installed applications.

<!--RP55--><!--RP55End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: phones | tablets

**Since**: 22

## ohos.permission.CUSTOM_SCREEN_RECORDING

Allows an application to record the screen without displaying any pop-up.

With this permission, the application can record the screen without showing a privacy pop-up each time recording is initiated.

<!--RP56--><!--RP56End-->

**Permission level**: system_basic

**Authorization mode**: manual_settings

**Supported devices**: PCs/2-in-1 devices | TVs

**Since**: 22

**Changelog**: Since API version 26.0.0, this permission is also available on TVs.

## ohos.permission.ALLOW_EXTERNAL_NATIVE_CODE

Allows an application to use external native programs.

With this permission, the application can load external dynamic link libraries (.so), binary files (.bin), etc.

<!--RP57--><!--RP57End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: PCs/2-in-1 devices

**Since**: 23

## ohos.permission.GET_IP_MAC_INFO

Allows an application to obtain the IP address and MAC address of a network device.

<!--RP58-->
This permission is applicable only to network connection or identification, not to device location.
<!--RP58End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: general devices

**Since**: 22

## ohos.permission.atomicService.MANAGE_AGING

Allows an atomic service to request differentiated aging policies.

<!--RP59--><!--RP59End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Since**: 23

## ohos.permission.ACCESS_USER_FULL_DISK

Allows an application to access the user public directory without a dialog.

With this permission, the application can access the public directory without having to notify the user via a pop-up every time.

<!--RP60--><!--RP60End-->

**Permission level**: system_basic

**Authorization mode**: manual_settings

**Supported devices**: PCs/2-in-1 devices

**Since**: 22

## ohos.permission.kernel.LOAD_INDEPENDENT_LIBRARY

Allows an application to load shared libraries signed with binary certificates.

<!--RP61--><!--RP61End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: PCs/2-in-1 devices

**Since**: 20

**Changelog**: This permission is available only to system applications in API versions 20 to 21. From API version 22, it's also available to normal applications.

## ohos.permission.CRYPTO_EXTENSION_REGISTER

Allows an application to register and unregister the crypto extension.

<!--RP62--><!--RP62End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: PCs/2-in-1 devices | tablets | phones

**Since**: 22

**Changelog**: This permission is also available on tablets since API version 24 and on mobile phones since API version 26.0.0.

## ohos.permission.MANAGE_MEDIA_RESOURCES_FOR_PUBLIC

Allows an application to obtain and manage the media resources playing on a device.

<!--RP63--><!--RP63End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: phones | PCs/2-in-1 devices | tablets | TVs | cars

**Since**: 23

## ohos.permission.MANAGE_RECENT_SNAPSHOT

Allows an application to set the preview image displayed when a mouse hovers over its icon in the Dock or recent tasks are viewed.

When the mouse hovers over an application icon in the Dock or recent tasks are viewed, a real-time preview image of the application will be displayed. With this permission, the application is authorized to customize this image.

<!--RP72--><!--RP72End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: PCs/2-in-1 devices

**Since**: 26.0.0

## ohos.permission.SET_WINDOW_ALPHA

Allows an application to set the main window container to be transparent.

With this permission, the application can set the background color of the main window container.

<!--RP73--><!--RP73End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: PCs/2-in-1 devices

**Since**: 26.0.0

## ohos.permission.MANAGE_CALL_FOR_DEVICES

Allows an application to manage call status, such as retrieving incoming call numbers, answering, rejecting, and ending calls.

<!--RP64--><!--RP64End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Since**: 23

## ohos.permission.SET_WINDOW_TOUCH_AREAS

Allows an application to configure a touch target for window events. Events occurring outside the touch target will be passed through.

<!--RP75--><!--RP75End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: PCs/2-in-1 devices

**Since**: 26.0.0

## ohos.permission.MANAGE_BLUETOOTH_ADVERTISER_NAME

Allows an application to customize the BLE broadcast name.

<!--RP65--><!--RP65End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: general devices

**Since**: 23

## ohos.permission.INPUT_DEVICE_CONFIGURATOR

Allows an application to bind input devices to displays.

With this permission, the driver application can bind external input devices connected via USB or Bluetooth with specific display screens.

<!--RP66--><!--RP66End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: PCs/2-in-1 devices

**Since**: 24

## ohos.permission.REGISTER_OBJECTEDITOR_EXTENSION

Allows an application to register **ObjectEditorExtensionAbility** components.

With this permission, the application can provide embedded content editing services for use by other applications.

<!--RP67--><!--RP67End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Since**: 24

## ohos.permission.ALLOW_ACCESSORY_ACCESS

Allow an application to use the accessory connection service for pairing and auto-wake functions.

<!--RP70--><!--RP70End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: phones | PCs/2-in-1 devices | tablets | cars

**Since**: 26.0.0

## ohos.permission.CHECK_CALL_LOG

Allows an application to query the system for matching call records within a specified period based on specific criteria (such as the mobile number and call duration).

<!--RP71--><!--RP71End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: general devices

**Since**: 24

## ohos.permission.GET_NETWORK_STATS

Allows an application to query the traffic data of other applications.

<!--RP81--><!--RP81End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: general devices

**Since**: 10

**Changelog**: **Enable via ACL** is **false** for this permission in API versions 10 to 11, and is changed to **true** since API version 12. For API versions 10 to 24, this permission is available to system applications. Since API version 26.0.0, this permission is available to normal applications.

## ohos.permission.ACCESS_DLP_SERVICE

Allows an application or a service to use the DLP to register or unregister the plugin for connecting the server.

<!--RP74--><!--RP74End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: phones | PCs/2-in-1 devices | tablets | TVs

**Since**: 26.0.0

## ohos.permission.CONTROL_DEVICE

Allows an application to inject input events to control the device.

<!--RP79--><!--RP79End-->

**Permission level**: system_basic

**Authorization mode**: manual_settings

**Supported devices**: PCs/2-in-1 devices

**Since**: 26.0.0

## ohos.permission.KEEP_BACKGROUND_RUNNING_SPECIAL_SCENARIO

Allows an application to apply for a continuous task of the special type.

<!--RP76--><!--RP76End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Since**: 24

## ohos.permission.FLOAT_VIEW

Allows an application to use floating windows. 

<!--RP78--><!--RP78End-->

**Permission level**: system_basic

**Authorization mode**: user_grant

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Since**: 26.0.0

## ohos.permission.GET_CALL_TRANSFER_INFO

Allows an application to query the call forwarding status.

<!--RP80--><!--RP80End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Since**: 26.0.0

## ohos.permission.MANAGE_SKILL
    
Allows an application to use Skills.

With this permission, the application can:

- Query information about skill packages.
- Listen for events such as the installation, update, and uninstallation of skill packages.
- Access the sandbox directory where skill packages are installed.

<!--RP87--><!--RP87End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: PCs/2-in-1 devices

**Since**: 26.0.0

## ohos.permission.kernel.AS_LDK_DRIVER

Allows an application to install the PCIe driver.

<!--RP77--><!--RP77End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: PCs/2-in-1 devices

**Since**: 26.0.0

## ohos.permission.ACCESS_GAME_BUDDY_SERVICE

Allows an application to access the game buddy service. 
With this permission, the application can utilize the APIs provided by the game buddy service, such as capturing screenshots of running games and capturing user voice data via the microphone.

<!--RP93--><!--RP93End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: phones

**Since**: 26.0.0

## ohos.permission.KNOCK_COLLABORATION

Allows an application to connect to a specific device using Tap-to-Transfer for information exchange and cross-device interaction.

<!--RP88--><!--RP88End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: phones

**Since**: 26.0.0

## ohos.permission.PRINTER_DRIVER

Allows an application to manage the printing system.

<!--RP89--><!--RP89End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: PCs/2-in-1 devices | phones | tablets

**Since**: 24

## ohos.permission.kernel.SUPPORT_LOCAL_PLUGIN

Allows an application to install and load self-distributed plug-ins.

<!--RP90--><!--RP90End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: PCs/2-in-1 devices

**Since**: 26.0.0

## ohos.permission.ALLOW_USE_BM

Allows an application to call BM tools in developer mode.

<!--RP94--><!--RP94End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: PCs/2-in-1 devices

**Since**: 26.0.0

## ohos.permission.ACCESS_DIGITAL_IDENTITY

Allows an application to import digital credentials using the digital identity service.

With this permission, the application can import the user's digital identity credentials into the device for secure storage and convenient presentation afterward.

<!--RP91--><!--RP91End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: phones | tablets

**Since**: 26.0.0

## ohos.permission.CAPTURE_PLAYBACK_DOWNLINK

Allows an application to record downlink data of cellular calls.

<!--RP95--><!--RP95End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: phones | tablets

**Since**: 26.0.0

## ohos.permission.MANAGE_SANDBOX_BUNDLE

Allows an application to manage sandbox applications.

<!--RP97--><!--RP97End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: PCs/2-in-1 devices

**Since**: 26.0.0

## ohos.permission.DETECT_DEVICE

Allows an application to invoke the smart diagnosis service to obtain data.

<!--RP98--><!--RP98End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Since**: 26.0.0

## ohos.permission.ACCESS_SE_KEY

Allows an application to generate, use, and delete secure element keys.

<!--RP100--><!--RP100End-->

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: phones | wearables | TVs | PCs/2-in-1 devices | tablets | cars   

**Since**: 26.0.0