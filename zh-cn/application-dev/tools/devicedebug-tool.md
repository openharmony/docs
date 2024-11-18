# devicedebug工具


devicedebug工具向开发者提供对调试应用发送信号的能力，目前只支持向AMS里管理的debug类型的应用进程的pid发送signal信号，达到终止对应pid进程的能力。

> **说明：**
>
> 在使用本工具前，开发者需要先获取<!--Del-->[<!--DelEnd-->hdc工具<!--Del-->](../../device-dev/subsystems/subsys-toolchain-hdc-guide.md)<!--DelEnd-->，执行hdc shell。

**表1** devicedebug工具命令列表

| 命令 | 描述 |
| -------- | -------- |
| help/-h | 帮助命令，显示devicedebug支持的命令信息。 |
| kill | 终止进程命令，用来终止对应pid进程。 |


## 帮助命令
```bash
devicedebug help
```

**表2** help命令列表

| 命令    | 描述       |
| ------- | ---------- |
| devicedebug help | 显示devicedebug支持的命令信息。 |

示例：

```bash
# 显示帮助信息。
devicedebug help
```


## 终止进程命令

```bash
devicedebug kill
```
用于向debug类型的应用进程发送pid与signal（1-64）信号，应用进程接受到信号后终止对应pid进程。

**表3** kill命令列表
  | 命令 | 描述 |
  | -------- |-------------------|
  | help/-h | 帮助信息。|
  | -\<signal\> \<pid\> |  必选字段，signal（1-64）为终止信号，终止pid对应的debug类型的应用进程。 |

  **返回值**：

  当pid对应的进程为非应用进程时，返回"devicedebug: kill: {pid}: No such app process"；当pid对应的进程为非debug类型的应用进程时，返回"devicedebug: kill: process: {pid} is not debuggable app"。

示例：
  ```bash
  # 以终止12111进程，signal信号9为例。
  devicedebug kill -9 12111
  ```

