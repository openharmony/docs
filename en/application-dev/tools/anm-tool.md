# Advanced Notification Manager
<!--Kit: Notification Kit-->
<!--Subsystem: Notification-->
<!--Owner: @michael_woo888-->
<!--Designer: @dongqingran; @wulong158-->
<!--Tester: @wanghong1997-->
<!--Adviser: @huipeizi-->

The Advanced Notification Manager enables you to print notifications and set notification parameters. It provides the notification debugging and testing capabilities, for example, printing published notification details, setting the number of notification caches, and enabling the notification functionality.

## Environment Requirements

Before using this tool, you must obtain the <!--Del-->[<!--DelEnd-->hdc tool<!--Del-->](../../device-dev/subsystems/subsys-toolchain-hdc-guide.md)<!--DelEnd--> and run the hdc shell command.

This tool can be used only in the eng version. If it is used in the user version, the error `/bin/sh: anm: inaccessible or not found.` is reported.

## anm Commands

| Command| Description|
| ---- | --- |
| help | Displays the anm help information.|
| dump | Dumps notification information.|
| setting | Sets notification parameters.|

## help

  ```bash
  # Display the anm help information.
  anm help
  ```

## dump

  ```bash
  # Dumps notification information.
  anm dump [<options>]
  ```

  **Parameters**

  | Name            | Description                          |
  | ---------------- | ---------------------------------- |
  | -A/--active      | Information about all active notifications.            |
  | -R/--recent      | Information about recent notifications.                |
  | -D/--distributed | Information about distributed notifications from other devices.  |
  | -b/--bundle      | Bundle name. Optional.|
  | -u/--user-id     | User ID. Optional.    |
  | -h/--help        | Help information.                          |

  **Example**

  ```bash
  # Display information about all active notifications.
  anm dump -A
  ```
  
## setting

  ```bash
  # Sets notification parameters.
  anm setting [<options>]
  ```

  **Parameters**

  | Name                    | Description                            |
  | ------------------------ | ------------------------------------ |
  | -c/--recent-count        | Maximum number of recent notifications stored in the memory.|
  | -e/--enable-notification | Whether to enable the notification capability.                    |
  | -k/--collaboration-switch        | Whether notifications can be sent to devices of a specified type through cross-device collaboration.<br>`anm setting -k <deviceType>:<status>`<br>**Note**: This parameter is supported since API version 18.<br>**deviceType**: device type. The value can be **wearable**, **litewearable**, or **headset**.<br>**status**: status of the cross-device collaboration switch. The value **0** indicates that the cross-device collaboration is disabled, and the value **1** indicates the opposite.
  | -b/--collaboration-switch-bundle | Whether notifications of a specified bundle can be sent to devices of a specified type through cross-device collaboration.<br>`anm setting -b <deviceType>:<bundleName>:<uid>:<status>`<br>**Note**: This parameter is supported since API version 18.<br>**deviceType**: device type. The value can be **wearable**, **litewearable**, or **headset**.<br>**status**: status of the cross-device collaboration switch. The value **0** indicates that the cross-device collaboration is disabled, and the value **1** indicates the opposite.|
  | -o/--collaboration-switch-slot   | Whether notifications of a specified slot can be sent to devices of a specified type through cross-device collaboration.<br>`anm setting -o <deviceType>:<slotType>:<status>`<br>**Note**: This parameter is supported since API version 18.<br>**deviceType**: device type. The value can be **wearable**, **litewearable**, or **headset**.<br>**slotType**: notification slot type. For details about the value range, see [SlotType](../reference/apis-notification-kit/js-apis-notificationManager.md#slottype).<br>**status**: status of the cross-device collaboration switch. The value **0** indicates that the cross-device collaboration is disabled, and the value **1** indicates the opposite.|
  | -h/--help                | Help information.                            |

  **Example**

  ```bash
  # Set the maximum number of recent notifications stored in the memory to 100.
  anm setting -c 100

  # Enable the notification through cross-device collaboration for wearable devices.
  anm setting -k wearable:1

  # Disable the notification through cross-device collaboration for the application whose bundle name is example and UID is 10100.
  anm setting -b litewearable:example:10100:0

  # Enable the notification through cross-device collaboration for headset devices whose slot type is 0.
  anm setting -o headset:0:1
  ```
