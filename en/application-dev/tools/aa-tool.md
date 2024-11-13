# Ability Assistant


Ability Assistant (AA) is a tool used to start applications and test cases. It provides basic application debugging and testing capabilities, for example, starting application components, forcibly stopping processes, and printing application component information.

> **NOTE**
>
> Before using this tool, you must obtain the <!--Del-->[<!--DelEnd-->hdc tool<!--Del-->](../../device-dev/subsystems/subsys-toolchain-hdc-guide.md)<!--DelEnd--> and run the hdc shell command.


## help
  Displays help information for the Ability Assistant.

  **Return value**

  Returns the help information.

  **Method**

  
  ```bash
  aa help
  ```


## start
  Starts an application component. The target component can be the PageAbility and ServiceAbility components of the FA model or the UIAbility and ServiceExtensionAbility components of the Stage model. The **exported** tag in the configuration file of the target component cannot be set to **false**.

  | Name| Description             |
  | -------- |-------------------|
  | -h/--help | Help information.            |
  | -d | Device ID. This parameter is optional.   |
  | -a | Ability name. This parameter is optional.|
  | -b | Bundle name. This parameter is optional. |
  | -m | Module name. This parameter is optional. |
  | -U | URI. This parameter is optional.        |
  | -A | Action. This parameter is optional.     |
  | -e | Entity. This parameter is optional.     |
  | -t | Type. This parameter is optional.       |
  | -S | Whether to enter the application sandbox during debugging. This parameter is optional. If this parameter is carried, the application sandbox is entered. Otherwise, the application sandbox is not entered.|
  | --pi  | Key-value pair of the integer type. This parameter is optional.    |
  | --pb  | Key-value pair of the Boolean type. This parameter is optional.    |
  | --ps  | Key-value pair of the string type. This parameter is optional.   |
  | --psn | Keyword of an empty string. This parameter is optional.    |
  | --wl | Left margin of the window, in px. This parameter is optional.<br>**Constraints**:<br>This field is valid only when the 2-in-1 device is in developer mode and the application to start uses a debug signature.|
  | --wt | Top margin of the window, in px. This parameter is optional.<br>**Constraints**:<br>This field is valid only when the 2-in-1 device is in developer mode and the application to start uses a debug signature.|
  | --wh | Window height, in px. This parameter is optional.<br>**Constraints**:<br>This field is valid only when the 2-in-1 device is in developer mode and the application to start uses a debug signature.|
  | --ww | Window width, in px. This parameter is optional.<br>**Constraints**:<br>This field is valid only when the 2-in-1 device is in developer mode and the application to start uses a debug signature.|
  | -D | Debugging mode. This parameter is optional.       |

  **Return value**

  Returns "start ability successfully." if the ability is started; returns "error: failed to start ability." and the corresponding error information otherwise.

  **Method**

  
  ```bash
  # Display the ability started.
  aa start [-d <deviceId>] [-a <abilityName> -b <bundleName>] [-m <moduleName>] [-D] [-S] [--pi <key> <integer-value>] [--pb <key> <bool-value: true/false/t/f, case insensitive] [--ps <key> <value>] [--psn <key>] [--wl <windowLeft>] [--wt <windowTop>] [--wh <windowHeight>] [--ww <windowWidth>]
  
  # Implicitly start an ability. If none of the parameters in the command is set, the startup fails.
  aa start [-d <deviceId>] [-U <URI>] [-t <type>] [-A <action>] [-e <entity>] [-D] [--pi <key> <integer-value>] [--pb <key> <bool-value: true/false/t/f, case insensitive] [--ps <key> <value>] [--psn <key>] [--wl <windowLeft>] [--wt <windowTop>] [--wh <windowHeight>] [--ww <windowWidth>]
  ```

  **Example**

The following uses the implicit startup of an ability as an example.
  > **NOTE**
  > 
  > This example describes only the usage of some fields. For details about ability matching rules, see [Matching Rules of Explicit Want and Implicit Want](../application-models/explicit-implicit-want-mappings.md).


1. Configure **uris** for the target ability in the **module.json5** file.

      ```json
      {
        "name": "TargetAbility",
        ......
        "exported": true,
        "skills": [
          {
            "actions":[
              "ohos.want.action.viewData"
            ],
            "uris":[
              {
                "scheme": "myscheme",
                "host": "www.test.com",
                "port": "8080",
                "path": "path",
              }
            ]
          }
        ]
      }
      ```


2. Implicitly start the ability.

    - Run the **-U** command to start an application page.

        ```bash
        aa start -U myscheme://www.test.com:8080/path
        ```

    - If parameters need to be carried, run the following command:

        ```bash
        aa start -U myscheme://www.test.com:8080/path --pi paramNumber 1 --pb paramBoolean true --ps paramString teststring  --psn paramNullString
        ```

      The following is an example for the UIAbility to obtain input parameters:
  
        ```ts
        import UIAbility from '@ohos.app.ability.UIAbility';
        import hilog from '@ohos.hilog';
        import Want from '@ohos.app.ability.Want';

        export default class TargetAbility extends UIAbility {
          onCreate(want:Want, launchParam) {
            hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
            let paramNumber = want.parameters.paramNumber
            let paramBoolean = want.parameters.paramBoolean
            let paramString = want.parameters.paramString
            let paramNullString = want.parameters.paramNullString
          }
        }
        ```

    - Run the **-A -U** command to start the browser and redirect to a specified page.

      The following uses **https://www.example.com** as an example. Replace it with the actual URL.

        ```bash
        aa start -A ohos.want.action.viewData -U https://www.example.com
        ```


## stop-service
  Stops a ServiceAbility.

  | Name| Description|
  | -------- | -------- |
  | -h/--help | Help information.|
  | -d | Device ID. This parameter is optional.|
  | -a | Ability name. This parameter is mandatory.|
  | -b | Bundle name. This parameter is mandatory.|
  | -m | Module name. This parameter is optional.|

  **Return value**

  Returns "stop service ability successfully." if the ServiceAbility is stopped; returns "error: failed to stop service ability." otherwise.

  **Method**

  
  ```bash
  aa stop-service [-d <deviceId>] -a <abilityName> -b <bundleName> [-m <moduleName>]
  ```

## dump<sup>(deprecated)</sup>
  > **NOTE**
  >
  > This command is supported since API version 7 and deprecated since API version 9. You are advised to use **[hidumper](../dfx/hidumper.md) -s AbilityManagerService** instead.

  Prints information about an application component.
  | Name| Level-2 Parameter| Description|
  | -------- | -------- | -------- |
  | -h/--help | - | Help information.|
  | -a/--all | - | Application component information in all missions.|
| -l/--mission-list | type (All logs are printed if this parameter is left unspecified.)| For better management, the service side maintains four types of MissionLists, as described below:<br>- **NORMAL**: MissionList that is started normally. For example, if A starts B and C, the corresponding MissionList is A->B->C.<br>- **DEFAULT_STANDARD**: If a MissionList is damaged, missions with the launch type set to **multiton** are removed to this MissionList. The Missions in it are not associated with each other.<br>- **DEFAULT_SINGLE**: If a MissionList is damaged, missions with the launch type set to **singleton** are removed to this MissionList. The Missions in it are not associated with each other.<br>- **LAUNCHER**: MissionList for launcher abilities.|
  | -e/--extension | elementName | Extended component information.|
  | -u/--userId | UserId | Mission stack information of a specified user ID. This parameter must be used together with other parameters. Example commands: **aa dump -a -u 100** and **aa dump -d -u 100**.|
  | -d/--data | - | DataAbility information.|
  | -i/--ability | AbilityRecord ID | Detailed information about an application component.|
  | -c/--client | - | Detailed information about an application component. This parameter must be used together with other parameters. Example commands: **aa dump -a -c** and **aa dump -i 21 -c**.|
  | -p/--pending | - | Pending Want information. This parameter must be used together with other parameters. Example command: **aa dump -a -p**.|
  | -r/--process | - | Process information. This parameter must be used together with other parameters. Example command: **aa dump -a -r**.|

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

## force-stop
  Forcibly stops a process based on the bundle name.

  **Return value**

  Returns "force stop process successfully." if the process is forcibly stopped; returns "error: failed to force stop process." otherwise.

  **Method**

  
  ```bash
  aa force-stop <bundleName>
  ```

## test

  Starts the test framework based on the carried parameters.

  > **NOTE**
  > 
  > For details about parameters such as **class**, **level**, **size**, and **testType**, see [Keywords in the aa test Commands](../application-test/arkxtest-guidelines.md#in-the-cli).

  | Name| Description|
  | -------- | -------- |
  | -h/--help | Help information.|
  | -b | Bundle name. This parameter is mandatory.|
  | -s unittest | Test runner. This parameter is mandatory.|
  | -p | Package name of the test runner. This parameter is optional.<br>**NOTE**: This parameter can be used only in the FA model.|
  | -m | Module name of the test runner. This parameter is optional.<br>**NOTE**: This parameter can be used only in the stage model.|
  | -s class | Test suite or test case to be executed. This parameter is optional.|
  | -s level | Level of the test case to be executed. This parameter is optional.|
  | -s size | Size of the test case to be executed. This parameter is optional.|
  | -s testType | Type of the test case to be executed. This parameter is optional.|
  | -s timeout | Timeout interval for executing the test case, in ms. The default value is 5000. This parameter is optional.|
  | -s \<any-key> | Any key-value pair. This parameter is optional.|
  | -w | Test running time, in ms. This parameter is optional.|
  | -D | Debugging mode. This parameter is optional.|

  **Return value**

  Returns "user test started." if the test framework is started; returns "error: failed to start user test." and the corresponding error information otherwise.

  **Method**

  ```bash
  aa test -b <bundleName> [-m <module-name>] [-p <package-name>] [-s class <test-class>] [-s level <test-level>] [-s size <test-size>] [-s testType <test-testType>] [-s timeout <test-timeout>] [-s <any-key> <any-value>] [-w <wait-time>] -s unittest <testRunner>
  ```

## attach
  Attaches an application to enable it to enter the debugging mode.

  | Name| Description             |
  | -------- |-------------------|
  | -h/--help | Help information.            |
  | -b | Bundle name. This parameter is mandatory. |


  **Return value**

  Returns "attach app debug successfully." if the application enters the debugging mode; returns "fail: unknown option." and prints the help information if the specified parameter is invalid.

  **Method**

  
  ```bash
  aa attach -b <bundleName>
  ```

## detach
  Detaches an application to enable it to exit the debugging mode.

  | Name| Description             |
  | -------- |-------------------|
  | -h/--help | Help information.            |
  | -b | Bundle name. This parameter is mandatory. |


  **Return value**

  Returns "attach app debug successfully." if the application exits the debugging mode; returns "fail: unknown option." and prints the help information if the specified parameter is invalid.

  **Method**

  
  ```bash
  aa detach -b <bundleName>
  ```

## appdebug
  Sets or cancels the waiting-for-debugging state of an application, and obtains the bundle name and persistence flag of an application in the waiting-for-debugging state. The waiting-for-debugging state takes effect only for debugging applications. The setting command of **appdebug** takes effect only for a single application. Once the command is executed repeatedly, the bundle name and persistence flag are replaced with the latest settings.

  | Name| Level-2 Parameter| Description|
  | -------- | -------- | -------- |
  | -h/--help | - | Help information.|
  | -b/--bundlename | bundleName | Bundle name for which the waiting-for-debugging state is set. The system does not verify the validity of the bundle name.|
  | -p/--persist | - | Persistence flag. This parameter is optional. If this parameter is carried, the application is set to the waiting-for-debugging state persistently. That is, the setting takes effect regardless of whether the device is restarted or the application is reinstalled. If this parameter is not carried, the state takes effect only before the device is restarted. This parameter must be used together with the **-b** parameter. Example command: **aa appdebug -b \<bundleName> -p**.|
  | -c/--cancel | - | Used to cancel the waiting-for-debugging state.|
  | -g/--get | - | Used to obtain the bundle name and persistence flag of an application in the waiting-for-debugging state.|

  **Return value**

  Returns "app debug successfully." if the operation is successful; returns "error: not developer mode." if the operation fails because the application is not in developer mode; returns "error: failed to app debug." if the operation fails due to other reasons.

  **Method**

  ```bash
  # Display the help information.
  aa appdebug -h

  # Set the waiting-for-debugging state for an application.
  aa appdebug -b <bundleName> [-p]

  # Cancel the waiting-for-debugging state.
  aa appdebug -c

  # Obtain the bundle name and persistence flag of an application in the waiting-for-debugging state.
  aa appdebug -g
  # Example of the obtained information: bundle name: com.example.publishsystem, persist: false
  ```
