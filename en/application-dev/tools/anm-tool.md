# Advanced Notification Manager

The Advanced Notification Manager provides the notification debugging and testing capabilities that enable you to print notifications and set notification parameters. With this tool, you can send commands (started with **anm**) in the hdc shell to perform various system operations, such as printing notification details, setting the number of cached notifications, and enabling the notification capability.

### help

* **Function**

  Prints help information.

* **Method**

  ```bash
  anm help
  ```

### dump

* **Function**

  Prints information about notifications.

* **Method**

  ```bash
  anm dump [<options>]
  ```

  The table below describes the available options.

  | Name            | Description                          |
  | ---------------- | ---------------------------------- |
  | -A/--active      | Information about all active notifications.            |
  | -R/--recent      | Information about recent notifications.                |
  | -D/--distributed | Information about distributed notifications from other devices.  |
  | -b/--bundle      | Bundle name. Optional.|
  | -u/--user-id     | User ID. Optional.    |
  | -h/--help        | Help information.                          |

* **Example**: Print information about active notifications.

  ```bash
  anm dump -A
  ```
  ![anm-dump-A](figures/anm-dump-A.png)

### Setting

* **Function**

  Sets notification parameters.

* **Method**

  ```bash
  anm setting [<options>]
  ```

  The table below describes the available options.

  | Name                    | Description                            |
  | ------------------------ | ------------------------------------ |
  | -c/--recent-count        | Maximum number of recent notifications stored in the memory.|
  | -e/--enable-notification | Whether to enable the notification capability.                    |
  | -h/--help                | Help information.                            |

* **Example**: Set the maximum number of recent notifications stored in the memory to 100.

  ```bash
  anm setting -c 100
  ```
