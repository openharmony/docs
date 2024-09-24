# 设备调试工具（devicedebug工具）

设备调试工具，（devicedebug工具）是2D调试特权命令，为开发者提供调试应用发送信号的能力，目前支持杀死进程能力

## 环境要求

使用本工具前，开发者需要先获取hdc工具，执行hdc shell。

## devicedebug工具命令

**表1** devicedebug工具命令列表
  | 命令 | 描述 |
  | -------- |-------------------|
  | help/-h | 帮助命令，显示devicedebug工具支持的命令信息。|
  | kill |  杀死进程命令| 

### 杀死进程命令

  ```bash
  devicedebug kill -<signal> <pid>
  ```

**表2** 杀死进程命令列表
  | 命令 | 描述 |
  | -------- |-------------------|
  | devicedebug kill help/-h | 显示kill支持的命令信息。-h为非必选字段。             |
  | devicedebug kill -\<signal\> \<pid\>  | signal只支持传入signal数字，为必选字段，pid是进程id，为必选字段    |

  **示例**：
  ```bash
  # 向进程12111发送signal为9的信号
  devicedebug kill -9 12111
  ```

