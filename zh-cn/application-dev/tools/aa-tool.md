# aa工具


Ability assistant（Ability助手，简称为aa），是实现应用及测试用例启动功能的工具，为开发者提供基本的应用调试和测试的能力。通过该工具，开发者可以在hdc shell中，发送命令以执行各种系统操作，例如启动应用组件、强制停止进程、打印应用组件相关信息等。


- help
  用于显示aa相关的帮助信息。

  返回值：

  返回对应的帮助信息。

  使用方法：

  
  ```bash
  aa help
  ```


- start
  用于启动一个应用组件，目标组件可以是FA模型的PageAbility和ServiceAbility组件，也可以是Stage模型的UIAbility和ServiceExtensionAbility组件，且目标组件相应配置文件中的visible标签不能配置为false。

  | 参数 | 参数说明 |
  | -------- | -------- |
  | -h/--help | 帮助信息。 |
  | -d | 可选参数，deviceId。 |
  | -a | 必选参数，abilityName。 |
  | -b | 必选参数，bundleName。 |
  | -D | 可选参数，调试模式。 |

  返回值：

  当启动成功时，返回"start ability successfully."；当启动失败时，返回"error: failed to start ability."，同时会包含相应的失败信息。

  使用方法：

  
  ```bash
  aa start [-d <deviceId>] -a <abilityName> -b <bundleName> [-D]
  ```

- stop-service
  用于停止ServiceAbility。

  | 参数 | 参数说明 |
  | -------- | -------- |
  | -h/--help | 帮助信息。 |
  | -d | 可选参数，deviceId。 |
  | -a | 必选参数，abilityName。 |
  | -b | 必选参数，bundleName。 |

  返回值：

  当成功停止ServiceAbility时，返回"stop service ability successfully."；当停止失败时，返回"error: failed to stop service ability."。

  使用方法：

  
  ```bash
  aa stop-service [-d <deviceId>] -a <abilityName> -b <bundleName>
  ```

- dump
    用于打印应用组件的相关信息。
    | 参数 | 二级参数 | 参数说明 |
  | -------- | -------- | -------- |
  | -h/--help | - | 帮助信息。 |
  | -a/--all | - | 打印所有mission内的应用组件信息。 |
  | -l/--mission-list | type（缺省打印全部） | 打印任务栈信息。<br/>可取值：<br/>-&nbsp;NORMAL<br/>-&nbsp;DEFAULT_STANDARD<br/>-&nbsp;DEFAULT_SINGLE<br/>-&nbsp;LAUNCHER |
  | -e/--extension | elementName | 打印扩展组件信息。 |
  | -u/--userId | UserId | 打印指定UserId的栈信息，需要和其他参数组合使用，例如aa&nbsp;dump&nbsp;-a&nbsp;-u&nbsp;100、aa&nbsp;dump&nbsp;-d&nbsp;-u&nbsp;100。 |
  | -d/--data | - | 打印DataAbility相关信息。 |
  | -i/--ability | AbilityRecord&nbsp;ID | 打印指定应用组件详细信息。 |
  | -c/--client | - | 打印应用组件详细信息，需要和其他参数组合使用，例如aa&nbsp;dump&nbsp;-a&nbsp;-c、aa&nbsp;dump&nbsp;-i&nbsp;21&nbsp;-c。 |

  使用方法：

  
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
  通过bundleName强制停止一个进程。

  返回值：

  当成功强制停止该进程时，返回"force stop process successfully."；当强制停止失败时，返回"error: failed to force stop process."。

  使用方法：

  
  ```bash
  aa force-stop <bundleName>
  ```
