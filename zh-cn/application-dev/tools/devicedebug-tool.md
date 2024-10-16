# devicedebug工具


devicedebug工具向开发者提供对调试应用发送信号的能力，目前只支持向AMS里管理的debuggable应用进程的pid发送signal信号，达到终止对应pid进程的能力。

> **说明：**
>
> 在使用本工具前，开发者需要先获取<!--Del-->[<!--DelEnd-->hdc工具<!--Del-->](../../device-dev/subsystems/subsys-toolchain-hdc-guide.md)<!--DelEnd-->，执行hdc shell。


## help
  用于显示devicedebug相关的帮助信息。

  **返回值**：

  返回对应的帮助信息。

  **使用方法**：

  
  ```bash
  devicedebug help
  ```


## kill
  用于向应用进程发送pid与signal信号，应用进程接受到信号后终止对应pid进程。

  | 命令 | 描述 |
  | -------- |-------------------|
  | help/-h | 帮助信息。|
  | -\<signal\> \<pid\> |  必选字段，signal为终止信号，终止pid进程。 | 

  **返回值**：

  无返回值。执行成功后对应进程会被终止。

  **使用方法**：

  ```bash
  devicedebug kill -<signal> <pid>
  ```
  **示例**：
  以终止12111进程，signal信号9为例。
  ```bash
  devicedebug kill -9 12111
  ```

