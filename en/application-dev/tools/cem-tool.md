# Common Event Manager

<!--Kit: Notification Kit-->
<!--Subsystem: Notification-->
<!--Owner: @peixu-->
<!--Designer: @dongqingran; @wulong158-->
<!--Tester: @wanghong1997-->
<!--Adviser: @huipeizi-->

The Common Event Manager enables you to print common event information and publish common events. It provides the common event debugging and testing capabilities, for example, printing all public event subscribers, sent public events, and recipients, and simulating public event release.

## Environment Requirements

Before using this tool, you need to obtain [hdc](../dfx/hdc.md) and run the hdc shell command.

## cem Commands

| Command| Description|
| ---- | --- |
| help | Displays the cem help information.|
| publish | Publishes a common event.|
| dump | Dumps information about common events.|

## help

  ```bash
  # Display the cem help information.
  cem help
  ```

## publish

  ```bash
  # Publish a common event.
  cem publish [<options>]
  ```

  **Parameters**

  | Name        | Description                                   |
  | ------------ | ------------------------------------------ |
  | -e/--event   | Name of the common event to publish. This parameter is mandatory.                    |
  | -o/--ordered | Indicates that the common event to publish is ordered. By default, non-ordered events are published. This parameter is optional.    |
  | -c/--code    | Result code of the common event. This parameter is optional.                  |
  | -d/--data    | Data carried in the common event. This parameter is optional.                |
  | -h/--help    | Help information.                                |

  **Example**

  ```bash
  # Publish a common event named testevent.
  cem publish --event "testevent"
  ```
  
  ```bash
  # Publish an ordered common event named testevent. The result code of the event is 100 and the data carried is "this is data".
  cem publish -e "testevent" -o -c 100 -d "this is data"
  ```

## dump

> **NOTE**
> 
> The Common Event Manager has two editions: **eng** and **user**. The **dump** command can be used only in the **eng** edition. If it is used in the **user** edition, the message **error: user version cannot use dump** is reported.

  ```bash
  # Dumps information about common events.
  cem dump [<options>]
  ```

  **Parameters**

  | Name      | Description                                    |
  | ---------- | -------------------------------------------- |
  | -a/--all   | Information about all common events that have been sent since system startup.|
  | -e/--event | Information about a specific event.                  |
  | -h/--help  | Help information.                                    |

  **Example**

  ```bash
  # Display details of a common event named testevent.
  cem dump -e "testevent"
  ```
