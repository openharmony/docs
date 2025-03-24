# Advanced Notification Manager

The Advanced Notification Manager enables you to print notifications and set notification parameters. It provides the notification debugging and testing capabilities, for example, printing published notification details, setting the number of notification caches, and enabling the notification functionality.

## Environment Requirements

Before using this tool, you must obtain the <!--Del-->[<!--DelEnd-->hdc tool<!--Del-->](../../device-dev/subsystems/subsys-toolchain-hdc-guide.md)<!--DelEnd--> and run the hdc shell command.

This tool can be used only in the **eng** edition. If it is used in the **user** edition, the message **error: user version cannot use setting** is reported.

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
  | -h/--help                | Help information.                            |

  **Example**

  ```bash
  # Set the maximum number of recent notifications stored in the memory to 100.
  anm setting -c 100
  ```
