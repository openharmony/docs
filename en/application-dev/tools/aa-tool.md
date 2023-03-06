# Ability Assistant


The ability assistant enables you to start applications and test cases. It provides basic application debugging and testing capabilities, for example, starting application components, forcibly stopping processes, and printing application component information.

> **NOTE**
>
> Before using this tool, you must obtain the [hdc tool](../../device-dev/subsystems/subsys-toolchain-hdc-guide.md) and run the hdc shell command.


- help

  Displays help information for the Ability Assistant.

  **Return value**

  Returns the help information.

  **Method**

    ```bash
    aa help
    ```


- start

  Starts an application component. The target component can be the PageAbility and ServiceAbility components of the FA model or the UIAbility and ServiceExtensionAbility components of the Stage model. The **visible** tag in the configuration file of the target component cannot be set to **false**.

  | Name| Description|
  | -------- | -------- |
  | -h/--help | Help information.|
  | -d | Device ID. Optional.|
  | -a | Ability name. Mandatory.|
  | -b | Bundle name. Mandatory.|
  | -D | Debugging mode. Optional.|

  **Return value**

  Returns "start ability successfully." if the ability is started; returns "error: failed to start ability." and the corresponding error information otherwise.

  **Method**

    ```bash
    aa start [-d <deviceId>] -a <abilityName> -b <bundleName> [-D]
    ```

- stop-service

  Stops a ServiceAbility.

  | Name| Description|
  | -------- | -------- |
  | -h/--help | Help information.|
  | -d | Device ID. Optional.|
  | -a | Ability name. Mandatory.|
  | -b | Bundle name. Mandatory.|

  **Return value**

  Returns "stop service ability successfully." if the ServiceAbility is stopped; returns "error: failed to stop service ability." otherwise.

  **Method**

    ```bash
    aa stop-service [-d <deviceId>] -a <abilityName> -b <bundleName>
    ```

- dump
  
  Prints information about an application component.
  
  | Name| Level-2 Parameter| Description|
  | -------- | -------- | -------- |
  | -h/--help | - | Help information.|
  | -a/--all | - | Application component information in all missions.|
  | -l/--mission-list | type (All logs are printed if this parameter is left unspecified.)| For better management, the service side maintains four types of MissionLists, as described below:<br>- **NORMAL**: MissionList that is started normally. For example, if A starts B and C, the corresponding MissionList is A->B->C.<br>- **DEFAULT_STANDARD**: If a MissionList is damaged, missions with the launch type set to **standard** are removed to this MissionList. The Missions in it are not associated with each other.<br>- **DEFAULT_SINGLE**: If a MissionList is damaged, missions with the launch type set to **singleton** are removed to this MissionList. The Missions in it are not associated with each other.<br>- **LAUNCHER**: MissionList for launcher abilities. |
  | -e/--extension | elementName | Extended component information.|
  | -u/--userId | UserId | Mission stack information of a specified user ID. This parameter must be used together with other parameters. Example commands: **aa dump -a -u 100** and **aa dump -d -u 100**.|
  | -d/--data | - | DataAbility information.|
  | -i/--ability | AbilityRecord ID | Detailed information about an application component.|
  | -c/--client | - | Detailed information about an application component. This parameter must be used together with other parameters. Example commands: **aa dump -a -c** and **aa dump -i 21 -c**.|

  **Method**

    ```bash
  aa dump -a
    ```

    ![aa-dump-a](figures/aa-dump-a.png)
  
  
    ```bash
  aa dump -l
    ```

    ![aa-dump-l](figures/aa-dump-l.png)
  
  
    ```bash
  aa dump -i 12
    ```

      ![aa-dump-i](figures/aa-dump-i.png)
  
- force-stop

  Forcibly stops a process based on the bundle name.

  **Return value**

  Returns "force stop process successfully." if the process is forcibly stopped; returns "error: failed to force stop process." otherwise.

  **Method**

    ```bash
    aa force-stop <bundleName>
    ```
