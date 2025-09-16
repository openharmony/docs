# Ability Assistant

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @lidongrui-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

Ability Assistant (aa) is a tool used to start applications and test cases. It provides basic application debugging and testing capabilities, for example, starting application components, forcibly stopping processes, and printing application component information.

## Environment Setup

Before using this tool, you need to obtain [hdc](../dfx/hdc.md) and run the hdc shell.

The commands in this topic are used in the interactive CLI. To run the hdc shell [aa command] directly, use quotation marks ("") to wrap the aa command to ensure that the input parameters in the command can be correctly identified. The sample code is as follows:

```bash
# The start command:
hdc shell "aa start -A ohos.want.action.viewData -U 'https://www.example.com'"

# The process command:
hdc shell "aa process -b com.example.myapplication -a EntryAbility -p perf-cmd"
```

## aa Commands

| Command| Description|
|--------|--------|
| -h/help |  Displays the help information of the aa tool.|
| start |  Starts an application component. The target component can be the PageAbility and ServiceAbility components of the FA model or the UIAbility and ServiceExtensionAbility components of the Stage model. The **exported** tag in the configuration file of the target component cannot be set to **false**.|
| stop-service |  Stops a ServiceAbility.|
| dump<sup>(deprecated)</sup> |  Prints information about an application component.|
| force-stop |  Forcibly stops a process based on the bundle name.|
| test |  Starts the test framework based on the carried parameters.|
| attach |  Attaches an application to enable it to enter the debugging mode.|
| detach |  Detaches an application to enable it to exit the debugging mode.|
| appdebug |  Sets or cancels the waiting-for-debugging state of an application, and obtains the bundle name and persistence flag of an application in the waiting-for-debugging state. The waiting-for-debugging state takes effect only for debugging applications. The setting command of **appdebug** takes effect only for a single application. Once the command is executed repeatedly, the bundle name and persistence flag are replaced with the latest settings.|
| process |  Debugs or optimizes an application. In DevEco Studio, this command is used to integrate debugging and optimization tools.|
| send-memory-level | onMemoryLevel callback command. Specifies the PID and memory usage level of a process to trigger the onMemoryLevel lifecycle callback of the process.|

## help Command

```bash
# Display the help information.
aa help
```

## start Command

Starts an application component. The target component can be the PageAbility and ServiceAbility components of the FA model or the UIAbility and ServiceExtensionAbility components of the Stage model. The **exported** tag in the configuration file of the target component cannot be set to **false**.

```bash
# Display the ability started.
aa start [-d <deviceId>] [-a <abilityName> -b <bundleName>] [-m <moduleName>] [-D] [-R] [-S] [--pi <key> <integer-value>] [--pb <key> <bool-value: true/false/t and f are case insensitive] [--ps <key> <value>] [--psn <key>] [--wl <windowLeft>] [--wt <windowTop>] [--wh <windowHeight>] [--ww <windowWidth>] [-p <perf-cmd>]

# Implicitly start an ability. If none of the parameters in the command is set, the startup fails.
aa start [-d <deviceId>] [-U <URI>] [-t <type>] [-A <action>] [-e <entity>] [-D] [-R] [--pi <key> <integer-value>] [--pb <key> <bool-value: true/false/t and f are case insensitive] [--ps <key> <value>] [--psn <key>] [--wl <windowLeft>] [--wt <windowTop>] [--wh <windowHeight>] [--ww <windowWidth>] [-p <perf-cmd>]
```

  **Parameters**

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
  | --pi  | Key-value pair of the integer type. This parameter is optional.    |
  | --pb  | Key-value pair of the Boolean type. This parameter is optional.    |
  | --ps  | Key-value pair of the string type. This parameter is optional.   |
  | --psn | Keyword of an empty string. This parameter is optional.    |
  | --wl | Left margin of the window, in px. This parameter is optional.<br>**Constraints**:<br>This field is valid only when the 2-in-1 device is in developer mode and the application to start uses a debug signature.|
  | --wt | Top margin of the window, in px. This parameter is optional.<br>**Constraints**:<br>This field is valid only when the 2-in-1 device is in developer mode and the application to start uses a debug signature.|
  | --wh | Window height, in px. This parameter is optional.<br>**Constraints**:<br>This field is valid only when the 2-in-1 device is in developer mode and the application to start uses a debug signature.|
  | --ww | Window width, in px. This parameter is optional.<br>**Constraints**:<br>This field is valid only when the 2-in-1 device is in developer mode and the application to start uses a debug signature.|
  | -R | Whether to enable multi-thread error detection during debugging. This parameter is optional. The detection is enabled when this parameter is passed in.<br>**NOTE**: This parameter is supported since API version 14.|
  | -S | Whether to enter the application sandbox during debugging. This parameter is optional. If this parameter is carried, the application sandbox is entered. Otherwise, the application sandbox is not entered.|
  | -D | Debugging mode. This parameter is optional.       |
  | -p | Optimization mode. This parameter is optional. This command can be customized.       |
  | -W | Optimization mode. This parameter is optional. Measures the time required for the UIAbility to switch from the startup state to the foreground state.<br>**NOTE**<br>&emsp; - This parameter is supported since API version 20.<br>&emsp; - This parameter is valid only when the UIAbility is started explicitly (the -b and -a parameters must be carried).<br>**In normal cases, the following information is displayed:** <br>&emsp; - StartMode: UIAbility startup mode. The value can be Cold or Hot.<br>&emsp; - BundleName: bundle name of the target application.<br>&emsp; - AbilityName: ability name of the target application.<br>&emsp; - ModuleName: module name of the target application. If the command contains the -m parameter, the module name is displayed. Otherwise, no information is displayed.<br>&emsp; - TotalTime:<br>Duration from the time when the system receives a request from the AA to start the UIAbility to the time when the UIAbility completes the first frame drawing in the &emsp;&emsp;&emsp; cold start scenario, in milliseconds.<br>Duration from the time when the system receives a UIAbility startup request from the AA to the time when the UIAbility status is switched to the foreground in the &emsp;&emsp;&emsp; hot start scenario, in milliseconds.<br>&emsp; - WaitTime: duration from the time when the command is started to the time when the command execution is complete, in milliseconds.<br>**If an exception occurs, the following information is displayed:**<br>&emsp; - "The wait option does not support starting implict": Implicit startup is not supported.<br>&emsp; - "The wait option does not support starting non-uiability": Non-UIAbility components cannot be started.  |

  **Return value**

  Returns "start ability successfully." if the ability is started; returns "error: failed to start ability." and the corresponding error information otherwise.

  **Error codes**

  | ID| Error Message|
  | ------- | -------- |
  | 10103001 | Failed to verify the visibility of the target ability. |
  | 10104001 | The specified ability does not exist. |
  | 10105001 | Failed to connect to the ability service. |
  | 10105002 | Failed to obtain ability information. |
  | 10106002 | The aa start command's window option or the aa test command does not support app with release signature. |
  | 10100101 | Failed to obtain application information. |
  | 10100102 | The aa start command cannot be used to launch a UIExtensionAbility. |
  | 10103101 | Failed to find a matching application for implicit launch. |
  | 10103102 | The passed appCloneIndex is invalid. |
  | 10106101 | The current ability will be placed in the queue to wait for the previous ability to finish launching. |
  | 10106102 | The device screen is locked during the application launch. |
  | 10106103 | The target application is an expired crowdtesting application. |
  | 10106105 | The target application is under control. |
  | 10106106 | The target application is managed by EDM. |
  | 10106107 | The current device does not support using window options. |
  | 10107102 | Permission verification failed for the specified process. |
  | 10108101 | An internal error occurs while attempting to launch the ability. |

  **Example**

  The following uses the implicit startup of an ability as an example.

  > **NOTE**
  > 
  > This example describes only the usage of some fields. For details about ability matching rules, see [Matching Rules of Explicit Want and Implicit Want](../application-models/explicit-implicit-want-mappings.md).


  - Configure **uris** for the target ability in the **module.json5** file.

      ```json
      {
        "name": "TargetAbility",
        // ......
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
                "path": "path"
              }
            ]
          }
        ]
      }
      ```


  - Implicitly start the ability.

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
        import { UIAbility, Want, AbilityConstant } from '@kit.AbilityKit';
        import { hilog } from '@kit.PerformanceAnalysisKit';

        export default class TargetAbility extends UIAbility {
          onCreate(want:Want, launchParam: AbilityConstant.LaunchParam) {
            hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
            let paramNumber = want.parameters?.paramNumber;
            let paramBoolean = want.parameters?.paramBoolean;
            let paramString = want.parameters?.paramString;
            let paramNullString = want.parameters?.paramNullString;
          }
        }
        ```

    - Run the **-A -U** command to start the browser and redirect to a specified page.

      The following uses **https://www.example.com** as an example. Replace it with the actual URL.

        ```bash
        aa start -A ohos.want.action.viewData -U https://www.example.com
        ```


## stop-service Command

Stops a ServiceAbility.

```bash
aa stop-service [-d <deviceId>] -a <abilityName> -b <bundleName> [-m <moduleName>]
```

  **Parameters**
  | Name| Description|
  | -------- | -------- |
  | -h/--help | Help information.|
  | -d | Device ID. This parameter is optional.|
  | -a | Ability name. This parameter is mandatory.|
  | -b | Bundle name. This parameter is mandatory.|
  | -m | Module name. This parameter is optional.|

  **Return value**

  Returns "stop service ability successfully." if the ServiceAbility is stopped; returns "error: failed to stop service ability." otherwise.

  **Error codes**

  | ID| Error Message|
  | ------- | -------- |
  | 10103001 | Failed to verify the visibility of the target ability. |
  | 10103201 | The target ability is not of the ServiceAbility type. |
  | 10104001 | The specified ability does not exist. |
  | 10105001 | Failed to connect to the ability service. |
  | 10105002 | Failed to obtain ability information. |

  **Example**
  
  ```bash
  # Stop a ServiceAbility.
  aa stop-service -a EntryAbility -b com.example.myapplication -m entry
  ```

## dump Command <sup>(deprecated)</sup>

Prints information about an application component.

```bash
aa dump -a
```

> **NOTE**
>
> This command is supported since API version 7 and deprecated since API version 9. You are advised to use **[hidumper](../dfx/hidumper.md) -s AbilityManagerService** instead.

  **Parameters**
  | Name| Level-2 Parameter| Description|
  | -------- | -------- | -------- |
  | -h/--help | - | Help information.|
  | -a/--all | - | Application component information in all missions.|
  | -l/--mission-list | type (All logs are printed if this parameter is left unspecified.)| For better management, the service side maintains four types of MissionLists,<br>as described below:<br>- **NORMAL**: MissionList that is started normally. For example, if A starts B and C, the corresponding MissionList is A->B->C.<br>- **DEFAULT_STANDARD**: If a MissionList is damaged, missions with the launch type set to **multiton** are removed to this MissionList. The Missions in it are not associated with each other.<br>- **DEFAULT_SINGLE**: If a MissionList is damaged, missions with the launch type set to **singleton** are removed to this MissionList. The Missions in it are not associated with each other.<br>- **LAUNCHER**: MissionList for launcher abilities.|
  | -e/--extension | elementName | Extended component information.|
  | -u/--userId | UserId | Mission stack information of a specified user ID. This parameter must be used together with other parameters. Example commands: **aa dump -a -u 100** and **aa dump -d -u 100**.|
  | -d/--data | - | DataAbility information.|
  | -i/--ability | AbilityRecord ID | Detailed information about an application component.|
  | -c/--client | - | Detailed information about an application component. This parameter must be used together with other parameters. Example commands: **aa dump -a -c** and **aa dump -i 21 -c**.|
  | -p/--pending | - | Pending Want information. This parameter must be used together with other parameters. Example command: **aa dump -a -p**.|
  | -r/--process | - | Process information. This parameter must be used together with other parameters. Example command: **aa dump -a -r**.|

  **Error codes**

  | ID| Error Message|
  | ------- | -------- |
  | 10105001 | Failed to connect to the ability service. |

  **Example**
  
  ```bash
  # Print the application component information in all missions.
  aa dump -a
  ```

  ![aa-dump-a](figures/aa-dump-a.png)

  
  ```bash
  # Print all task chains.
  aa dump -l
  ```

  ![aa-dump-l](figures/aa-dump-l.png)

  
  ```bash
  # Print the detailed information about an application component.
  aa dump -i 105
  ```

  ![aa-dump-i](figures/aa-dump-i.png)

## force-stop Command

Forcibly stops a process based on the bundle name.

```bash
aa force-stop <bundleName>
```

  **Return value**

  Returns "force stop process successfully." if the process is forcibly stopped; returns "error: failed to force stop process." otherwise.

  **Error codes**

  | ID| Error Message|
  | ------- | -------- |
  | 10105001 | Failed to connect to the ability service. |
  | 10104002 | Failed to retrieve specified package information. |
  | 10106401 | Failed to terminate the process. |
  | 10106402 | Persistent processes cannot be terminated. |

  **Example**

  ```bash
  # Forcibly stop a process based on the bundle name.
  aa force-stop com.example.myapplication
  ```

## test Command

Starts the test framework based on the carried parameters.

```bash
aa test -b <bundleName> [-m <module-name>] [-p <package-name>] [-s class <test-class>] [-s level <test-level>] [-s size <test-size>] [-s testType <test-testType>] [-s timeout <test-timeout>] [-s <any-key> <any-value>] [-w <wait-time>] -s unittest <testRunner>
```

> **NOTE**
> 
> For details about parameters such as **class**, **level**, **size**, and **testType**, see <!--RP2-->[Keywords in the aa test Commands](../application-test/arkxtest-guidelines.md)<!--RP2End-->.

  **Parameters**
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

  **Error codes**

  | ID| Error Message|
  | ------- | -------- |
  | 10104002 | Failed to retrieve specified package information. |
  | 10105001 | Failed to connect to the ability service. |
  | 10106002 | The aa start command's window option or the aa test command does not support app with release signature. |
  | 10108501 | An internal error occurs during the execution of the aa test command. |

  **Example**

  ```bash
  # Start the test framework.
  aa test -b com.example.myapplication -s unittest ActsAbilityTest
  # Start the test framework and set the module name.
  aa test -b com.example.myapplication -m entry_test -s unittest ActsAbilityTest
  # Start the test framework and specify the timeout interval.
  aa test -b com.example.myapplication -m entry_test -s timeout 10000 -s unittest ActsAbilityTest
  ```

## attach Command

Attaches an application to enable it to enter the debugging mode.

```bash
aa attach -b <bundleName>
```

  **Parameters**
  | Name| Description             |
  | -------- |-------------------|
  | -h/--help | Help information.            |
  | -b | Bundle name. This parameter is mandatory. |

  **Return value**

  Returns "attach app debug successfully." if the application enters the debugging mode; returns "fail: unknown option." and prints the help information if the specified parameter is invalid.

  **Error codes**

  | ID| Error Message|
  | ------- | -------- |
  | 10105001 | Failed to connect to the ability service. |
  | 10106001 | The current device is not in developer mode. |
  | 10106002 | The aa start command's window option or the aa test command does not support app with release signature. |
  | 10103601 | The specified bundleName does not exist. |
  | 10108601 | An internal error occurs while attempting to enter/exit debug mode. |

  **Example**

  ```bash
  # Attach an application to enable it to enter the debugging mode.
  aa attach -b com.example.myapplication
  ```

## detach Command

Detaches an application to enable it to exit the debugging mode.

```bash
aa detach -b <bundleName>
```

  **Parameters**
  | Name| Description             |
  | -------- |-------------------|
  | -h/--help | Help information.            |
  | -b | Bundle name. This parameter is mandatory. |

  **Return value**

  Returns "detach app debug successfully." if the application exits the debugging mode; returns "fail: unknown option." and prints the help information if the specified parameter is invalid.

  **Error codes**

  | ID| Error Message|
  | ------- | -------- |
  | 10105001 | Failed to connect to the ability service.|
  | 10106001 | The current device is not in developer mode. |
  | 10106002 | The aa start command's window option or the aa test command does not support app with release signature. |
  | 10103601 | The specified bundleName does not exist. |
  | 10108601 | An internal error occurs while attempting to enter/exit debug mode. |

  **Example**

  ```bash
  # Detach an application to enable it to exit the debugging mode.
  aa detach -b com.example.myapplication
  ```

## appdebug Command

Sets or cancels the waiting-for-debugging state of an application, and obtains the bundle name and persistence flag of an application in the waiting-for-debugging state. The waiting-for-debugging state takes effect only for debugging applications. The setting command of **appdebug** takes effect only for a single application. Once the command is executed repeatedly, the bundle name and persistence flag are replaced with the latest settings.

```bash
aa appdebug -b <bundleName> [-p]
```

  **Parameters**
  | Name| Level-2 Parameter| Description|
  | -------- | -------- | -------- |
  | -h/--help | - | Help information.|
  | -b/--bundlename | bundleName | Bundle name for which the waiting-for-debugging state is set. The system does not verify the validity of the bundle name.|
  | -p/--persist | - | Persistence flag. This parameter is optional. If this parameter is carried, the application is set to the waiting-for-debugging state persistently. That is, the setting takes effect regardless of whether the device is restarted or the application is reinstalled. If this parameter is not carried, the state takes effect only before the device is restarted. This parameter must be used together with the **-b** parameter. Example command: **aa appdebug -b \<bundleName> -p**.|
  | -c/--cancel | - | Used to cancel the waiting-for-debugging state.|
  | -g/--get | - | Used to obtain the bundle name and persistence flag of an application in the waiting-for-debugging state.|

  **Return value**

  Returns "app debug successfully." if the operation is successful; returns "error: not developer mode." if the operation fails because the application is not in developer mode; returns "error: failed to app debug." if the operation fails due to other reasons.

  **Error codes**

  | ID| Error Message|
  | ------- | -------- |
  | 10105003 | Failed to connect to the app service. |
  | 10106001 | The current device is not in developer mode. |
  | 10106701 | Cannot debug applications using a release certificate. |

  **Example**

  ```bash
  # Display the help information.
  aa appdebug -h

  # Set the waiting-for-debugging state for an application.
  aa appdebug -b com.example.myapplication [-p]

  # Cancel the waiting-for-debugging state.
  aa appdebug -c

  # Obtain the bundle name and persistence flag of an application in the waiting-for-debugging state.
  # Example of the obtained information: bundle name: com.example.publishsystem, persist: false
  aa appdebug -g
  ```

## process Command

Debugs or optimizes an application. In DevEco Studio, this command is used to integrate debugging and optimization tools.

```bash
# Debug an application.
aa process -b <bundleName> -a <abilityName> [-m <moduleName>] [-D <debug-cmd>] [-S]

# Optimize an application.
aa process -b <bundleName> -a <abilityName> [-m <moduleName>] [-p <perf-cmd>] [-S]
```

  **Parameters**
  | Name| Description|
  | -------- | -------- |
  | -h/--help | Help information.|
  | -b | Bundle name. This parameter is mandatory.|
  | -a | Ability name. This parameter is mandatory.|
  | -m | Module name. This parameter is optional.|
  | -p | Optimization mode. This parameter is optional. Either this parameter or **-D** must be specified. This command can be customized.|
  | -D | Debugging mode. This parameter is optional. Either this parameter or **-p** must be specified. This command can be customized.|
  | -S | Used to enter the application sandbox. This parameter is optional.|

  **Return value**

  Returns "start native process successfully." if this command is executed successfully; returns "start native process successfully." if this command fails to be executed; returns "start native process successfully." and prints the help information if the specified parameter is invalid.

  | ID| Error Message|
  | ------- | -------- |
  | 10105002 | Failed to obtain ability information. |
  | 10105003 | Failed to connect to the app service. |
  | 10106002 | The aa start command's window option or the aa test command does not support app with release signature. |

  **Example**

  ```bash
  # Debug an application.
  aa process -b com.example.myapplication -a EntryAbility -D debug_cmd [-S]

  # Optimize an application.
  aa process -b com.example.myapplication -a EntryAbility -p perf-cmd [-S]
  ```

## onMemoryLevel Callback Command (send-memory-level)

Since API version 13, developers can run this command to debug the [onMemoryLevel](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#onmemorylevel) lifecycle of an application. The onMemoryLevel lifecycle callback of a process is triggered by specifying the PID and memory usage level of the process in parameters.

```bash
# Triggers the onMemoryLevel callback.
aa send-memory-level -p <processId> -l <memoryLevel>
```

**Parameters**

| Name| Description|
| -------- | -------- |
| -h/--help | Help information.|
| -p | Specifies the PID of a process. This parameter is mandatory.|
| -l | Memory usage level. This parameter is mandatory. For details, see [AbilityConstant.MemoryLevel](../reference/apis-ability-kit/js-apis-app-ability-abilityConstant.md#memorylevel).|

**Return value**

If the command is executed successfully, the message "send memory level successfully." is returned. If the command fails to be executed, the message " "error: failed to send memory level."" is returned. If the specified parameter value is missing, the message "fail: unknown option." is returned and the help information is printed.

| ID| Error Message|
| ------- | -------- |
| 10104003 | The specified pid does not exist. |
| 10104004 | The specified level does not exist. |

**Example**

```bash
# Trigger the onMemoryLevel callback of the application whose process ID is 6066. The callback level is 0.
aa send-memory-level -p 6066 -l 0
```

## Error Codes

### 10103001 Failed to Verify the Visibility of the Target Ability

**Error Message**

Failed to verify the visibility of the target ability.

**Symptom**

The verification of the target ability visibility fails.

**Possible Causes**

The **exported** field of the [abilities](../quick-start/module-configuration-file.md#abilities) or [extensionAbilities](../quick-start/module-configuration-file.md#extensionabilities) tag in the **module.json5** file is set to **false**. As a result, the corresponding UIAbility or ExtensionAbility component cannot be invoked by other applications or started by the aa command.

**Solution**

Check whether the **exported** field of the ability in the **module.json5** file of the target application is **true**. If not, change it to **true** and try again.

### 10104001 The Ability Does Not Exist
**Error Message**

The specified ability does not exist.

**Symptom**
 
The specified ability name does not exist.

**Possible Causes**

The specified ability is not installed.

**Solution**

1. Check whether the **-a** parameter **abilityName** and the **-b** parameter **bundleName** in the aa command are correct.
2. Checks whether the **application** corresponding to the specified **bundleName** is installed. You can run the following command to query the list of installed applications. If **bundleName** is not in the query result, the application is not installed.
    ```
    hdc shell bm dump -a
    ```
3. For a multi-HAP application, check whether the HAP to which the ability belongs is installed. You can run the following command to query the bundle information. If the installed application does not contain the corresponding HAP and ability, the HAP to which the ability belongs is not installed.
    ```
    hdc shell bm dump -n bundleName
    ```

### 10104003 The Specified PID Does Not Exist

**Error Message**

The specified pid does not exist.

**Symptom**
 
The specified ability name does not exist.

**Possible Causes**

The specified **tokenId** does not exist.

**Solution**

Check whether the process ID specified by the -p parameter exists on the device.

### 10104004 The Specified Memory Usage Level Does Not Exist

**Error Message**

The specified level does not exist.

**Symptom**
 
If the specified memory usage level does not exist, the AA tool returns the error code.

**Possible Causes**

The specified memory usage level does not exist.

**Solution**

Check whether the memory usage level specified by the -l parameter is an integer within the range of [0, 2].

### 10105001 Failed to Connect to the Ability Service

**Error Message**

Failed to connect to the ability service.

**Symptom**

The connection to the Ability service fails.

**Possible Causes**

The Ability service is disconnected when the API is called.

**Solution**

Restart the device and try again.

### 10105002 Failed to Obtain Ability Information

**Error Message**

Failed to obtain ability information.

**Symptom**

The Ability information fails to be obtained.

**Possible Causes**

The **AbilityInfo** obtained through BMS is empty when the ability request is generated.

**Solution**

Checks whether the **application** corresponding to the specified **bundleName** is installed. You can run the following command to query the list of installed applications. If **bundleName** is not in the query result, the application is not installed.

  ```
  hdc shell bm dump -a
  ```

### 10105003 Failed to Connect to the Application Service

**Error Message**

Failed to connect to the app service.

**Symptom**

The connection to the app service fails.

**Possible Causes**

The application service is disconnected when the API is called.

**Solution**

Restart the device.

### 10106001 The Current Device Is Not in Developer Mode

**Error Message**

The current device is not in developer mode.

**Symptom**

The current device is not in developer mode.

**Possible Causes**

The current device is not in developer mode.

**Solution**

Enable the developer mode in **Settings**. The operations are show in the following figures:

Check whether Developer options is available in Settings > System. If the PIN does not exist, go to Settings > About this device and touch Version number for seven consecutive times until the message "Enable developer mode" is displayed. Touch Enable developer mode and enter the PIN (if set). The device will automatically restart. After the device is restarted, you can view the information in Settings > System.

### 10106002 Applications Cannot Be Signed by the Release Certificate

**Error Message**

The aa start command's window option or the aa test command does not support app with release signature.

**Symptom**

The wl, wt, wh, ww, or aa test parameter in the aa start command cannot be used to release signed applications.

**Possible Causes**

The target application is a release signature.

**Solution**

Use the **debug** certificate to re-sign the HAP, install the newly signed HAP, and then run this command.

### 10100101 Failed to Obtain Application Information

**Error Message**

Failed to obtain application information.

**Symptom**

The application information obtained from BMS is abnormal.

**Possible Causes**

The application name or bundle name in the app information obtained from BMS is incorrect.

**Solution**

1. Check whether the **-a** parameter **abilityName** and the **-b** parameter **bundleName** in the aa command are correct.
2. Checks whether the **application** corresponding to the specified **bundleName** is installed. You can run the following command to query the list of installed applications. If **bundleName** is not in the query result, the application is not installed.
    ```
    hdc shell bm dump -a
    ```
3. For a multi-HAP application, check whether the HAP to which the ability belongs is installed. You can run the following command to query the bundle information. If the installed application does not contain the corresponding HAP and ability, the HAP to which the ability belongs is not installed.
    ```
    hdc shell bm dump -n bundleName
    ```

### 10100102 UIExtensionAbility Cannot Be Launched Using the aa start Command

**Error Message**

The aa start command cannot be used to launch a UIExtensionAbility.

**Symptom**

The aa tool cannot launch a UIExtensionAbility.

**Possible Causes**

The aa start command cannot be used to launch the UIExtensionAbility.

**Solution**

Check whether the target ability is a UIExtensionAbility. The aa start command cannot start the UIExtensionAbility.

### 10103101 No Matching Application Is Found During Implicit Launch

**Error Message**

Failed to find a matching application for implicit launch.

**Symptom**

A matching ability is not found during implicit launch.

**Possible Causes**

* The implicit launch parameters are incorrectly configured or the specified HAP is not installed.
* If the application is launched explicitly, it is possible that **bundleName** is specified but **abilityName** is not specified in the command.

**Solution**

* For implicit launch, ensure that the launch parameters are set correctly and the specified HAP is installed.
* For explicit launch, ensure that the value of **abilityName** is correct.

### 10103102 The Value of AppCloneIndex Is Invalid

**Error Message**

The passed appCloneIndex is invalid.

**Symptom**

The value of **appCloneIndex** is invalid.

**Possible Causes**

The **AppCloneIndex** parameter in the aa start command is invalid.

**Solution**

Check whether the **AppCloneIndex** parameter is valid.

### 10106101 Waiting for the Previous Abilities to Finish Startup

**Error Message**

The current ability will be placed in the queue to wait for the previous ability to finish launching.

**Symptom**

Too many abilities need to be started. Due to the limited processing capability of the system, the requests are cached in the queue and processed in sequence.

**Possible Causes**

The system has a large number of concurrent requests.

**Solution**

No action is required. Wait for the previous abilities to finish startup.

### 10106102 The Device Is Locked During Application Launch

**Error Message**

The device screen is locked during the application launch.

**Symptom**

The device is locked during application launch.

**Possible Causes**

The device cannot be unlocked during application launch.

**Solution**

Unlock the device and launch the application.

### 10106103 The Target Application Is an Expired Crowdtesting Application

**Error Message**

The target application is an expired crowdtesting application.

**Symptom**

The target application is an expired crowdtesting application.

**Possible Causes**

The crowdtesting application has expired.

**Solution**

Check whether the crowdtesting application has expired. Expired crowdtesting applications cannot be started.

### 10106105 The Target Application Is Controlled

**Error Message**

The target application is under control.

**Symptom**

The application is controlled by the application market.

**Possible Causes**

The target application is suspected to have malicious behavior and is not allowed to start due to application market control.

**Solution**

It is recommended that end users uninstall the application.

### 10106106 The Target Application Is Managed by EDM

**Error Message**

The target application is managed by EDM.

**Symptom**

This target application is managed by Enterprise Device Management (EDM).

**Possible Causes**

The target application is forbidden to start by EDM.

**Solution**

The device is an enterprise device, and the target application is forbidden to start. You cannot handle it.

### 10106107 The Current Device Does Not Support Window Options

**Error Message**

The current device does not support using window options.

**Symptom**

The device does not support window options.

**Possible Causes**

The device does not support **WindowOptions** specified in the aa start command.

**Solution**

Delete the **wl**, **wt**, **wh**, and **ww** parameters from the aa start command.

### 10107102 Process Permission Verification Failure

**Error Message**

Permission verification failed for the specified process.

**Symptom**

Permission verification for the specified process fails.

**Possible Causes**

Permission verification for the specified process fails.

**Solution**

Check whether the permission of the specified process is correct.

### 10108101 Internal Error During Ability Launch

**Error Message**

An internal error occurs while attempting to launch the ability.

**Symptom**

An error occurs during internal processing, such as memory application or multi-thread processing.

**Possible Causes**

Common kernel errors such as memory application and multi-thread processing errors occur. The specific causes are as follows: empty internal object, processing timeout, failure in obtaining application information, failing in obtaining the system service, and too many started ability instances.

**Solution**

You cannot handle internal errors that occur during system running.

### 10103201 The Target Ability Is Not of the ServiceAbility Type

**Error Message**

The target ability is not of the ServiceAbility type.

**Symptom**

The target ability is not of the ServiceAbility type.

**Possible Causes**

When the **aa stop** command is used to stop a ServiceAbility, the ability specified by **abilityName** in the **-a** parameter is not a ServiceAbility.

**Solution**

Check whether the ability corresponding to the **abilityName** parameter in the **aa -a** command is a ServiceAbility.

### 10104002 Failed to Obtain Information About a Specified Bundle

**Error Message**

Failed to retrieve specified package information.

**Symptom**

Information about the specified bundle fails to be obtained.

**Possible Causes**

The application corresponding to the specified bundle name is not installed.

**Solution**

1. Check whether the specified bundle name is correct.
2. Checks whether the **application** corresponding to the specified **bundleName** is installed. You can run the following command to query the list of installed applications. If **bundleName** is not in the query result, the application is not installed.
    ```
    hdc shell bm dump -a
    ```

### 10106401 Failed to Terminate the Process

**Error Message**

Failed to terminate the process.

**Symptom**

The process fails to be terminated.

**Possible Causes**

1. The application specified by the **aa force-stop** command does not exist.
2. AppManagerService is not connected.

**Solution**

1. Check whether the application corresponding to the specified **bundleName** is installed. You can run the following command to query the list of installed applications. If **bundleName** is not in the query result, the application is not installed.

    ```
    hdc shell bm dump -a
    ```
2. Restart the device.

### 10106402 Persistent Processes Cannot Be Terminated

**Error Message**

Persistent processes cannot be terminated.

**Symptom**

Persistent processes cannot be killed.

**Possible Causes**

The process specified by **bundleName** in the **aa force-stop** command is a persistent process.

**Solution**

Check whether the target application is a persistent process. Persistent processes cannot be terminated by running commands.

**Solution**

Close the multiple instances of the target application and try again.

### 10108501 Internal Error During the Execution of the aa test Command

**Error Message**

An internal error occurs during the execution of the aa test command.

**Symptom**

An error occurs during internal processing, such as memory application or multi-thread processing.

**Possible Causes**

Common kernel errors such as memory application and multi-thread processing errors occur. The specific causes are as follows: empty internal object, processing timeout, and failing in obtaining the system service.

**Solution**

You cannot handle internal errors that occur during system running.

### 10108601 Internal Error During Entering or Exiting the Debug Mode

**Error Message**

An internal error occurs while attempting to enter/exit debug mode.

**Symptom**

An error occurs during internal processing, such as memory application or multi-thread processing.

**Possible Causes**

Common kernel errors such as memory application and multi-thread processing errors occur. The specific causes are as follows: empty internal object, processing timeout, and failing in obtaining the system service.

**Solution**

You cannot handle internal errors that occur during system running.

### 10103601 The Specified Bundle Name Does Not Exist

**Error Message**

The specified bundleName does not exist.

**Symptom**

The specified bundle name is not found.

**Possible Causes**

The bundle name specified by the **aa attach** or **aa detach** command does not exist.

**Solution**

Checks whether the **application** corresponding to the specified **bundleName** is installed. You can run the following command to query the list of installed applications. If **bundleName** is not in the query result, the application is not installed.

  ```
  hdc shell bm dump -a
  ```

### 10106701 The Target Application Is Not a Debug Application

**Error Message**

Cannot debug applications using a release certificate.

**Symptom**

The target application is not a debug application.

**Possible Causes**

The value of the **type** parameter in the signing tool is not **debug**.

**Solution**

Use the **debug** certificate to re-sign the HAP, install the newly signed HAP, and then run this command.
For details about the signing tool and certificate, see [Signing Your App/Atomic Service](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing).
