# Ability助手使用指导

Ability assistant（Ability助手，简称为aa）是实现应用、原子化服务、及测试用例启动功能的工具，为开发者提供基本的应用调试和测试的能力。通过该工具，开发者可以在hdc shell中，发送命令以执行各种系统操作，比如启动Ability、强制停止进程、打印Ability相关信息等。

## 查询相关

- **help**

  用于显示aa相关的帮助信息。

  **返回值：**

  返回对应的帮助信息。

  **使用方法：**

  ```
  aa help
  ```

## Ability相关

- **start**

  用于启动一个ability。

  | 参数      | 参数说明                   |
  | --------- | -------------------------- |
  | -h/--help | 帮助信息。                 |
  | -d        | 可选参数，`device id`。    |
  | -a        | 必选参数，`ability name`。 |
  | -b        | 必选参数，`bundle name`。  |
  | -D        | 可选参数，调试模式。       |

  **返回值：**

  当成功启动Ability时，返回“start ability successfully.”；当启动失败时，返回“error: failed to start ability.”。

  **使用方法：**

  ```
  aa start [-d <device-id>] -a <ability-name> -b <bundle-name> [-D]
  ```
  
- **stop-service**

  用于停止Service Ability。

  | 参数      | 参数说明                 |
  | --------- | ------------------------ |
  | -h/--help | 帮助信息。               |
  | -d        | 可选参数，device id。    |
  | -a        | 必选参数，ability name。 |
  | -b        | 必选参数，bundle name。  |

  **返回值：**

  当成功停止Service Ability时，返回“stop service ability successfully.”；当停止失败时，返回“error: failed to stop service ability.”。

  **使用方法：**

  ```
  aa stop-service [-d <device-id>] -a <ability-name> -b <bundle-name>
  ```
  
- **dump**

  用于打印Ability的相关信息。

  | 参数              | 二级参数             | 参数说明                                                     |
  | ----------------- | -------------------- | ------------------------------------------------------------ |
  | -h/--help         | -                    | 帮助信息。                                                   |
  | -a/--all          | -                    | 打印所有mission内的Ability。                                 |
  | -l/--mission-list | type（缺省打印全部） | 打印任务栈信息。<br />type：<br />NORMAL <br />DEFAULT_STANDARD<br />DEFAULT_SINGLE<br />LAUNCHER |
  | -e/--extension    | elementName          | 打印扩展组件信息。                                           |
  | -u/--userId       | UserId               | 打印指定UserId的栈信息，需要和其他参数组合使用，例如 `aa dump -a -u 100`、`aa dump -d -u 100` |
  | -d/--data         | -                    | 打印Data Ability。                                           |
  | -i/--ability      | AbilityRecord ID     | 打印指定Ability详细信息。                                    |
  | -c/--client       | -                    | 打印Ability详细信息，需要和其他参数组合使用，例如 `aa dump -a -c`、`aa dump -i 21 -c` |
  
  **使用方法：**
  
  ```
  aa dump -a
  ```
  ![aa-dump-a](figures/aa-dump-a.PNG)
  ```
  aa dump -l
  ```
  ![aa-dump-l](figures/aa-dump-l.PNG)
  ```
  aa dump -i 12
  ```
  ![aa-dump-i](figures/aa-dump-i.PNG)
- **force-stop**

  通过bundle name强制停止一个进程。

  **返回值：**

  当成功强制停止该进程时，返回“force stop process successfully.”；当强制停止失败时，返回“error: failed to force stop process.”。

  **使用方法：**

  ```
  aa force-stop <bundle-name>
  ```