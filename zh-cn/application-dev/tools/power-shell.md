# power-shell工具


power-shell是实现设备电源状态转换等功能的工具，为开发者提供基本的设备电源状态调试能力，例如：熄屏、唤醒、设置电源模式等。

## 环境要求

<!--RP1-->
在使用本工具前，开发者需要先获取[hdc工具](../dfx/hdc.md)，执行hdc shell。
<!--RP1End-->


## power-shell命令工具列表

| 命令 | 描述 |
| -------- | -------- |
| help | 帮助命令，显示power-shell支持的命令信息。 |
| setmode | 设置电源模式命令，用来设置当前设备的电源模式。 |
| wakeup | 亮屏命令，用来唤醒系统并亮屏。 |
| suspend | 熄屏命令，用来暂停系统并熄屏。|
| timeout | 自动熄屏命令，用来覆盖或恢复系统设置中自动熄屏时间。 |


## 帮助命令

```bash
# 显示帮助信息
power-shell help
```


## 设置电源模式命令

```bash
power-shell setmode
```

**设置电源模式命令列表**

| 命令                                | 描述                       |
| ----------------------------------- | -------------------------- |
| power-shell setmode -h | 显示setmode支持的命令信息。 |
| power-shell setmode 600 | 正常模式。 |
| power-shell setmode 601 | 省电模式。 |
| power-shell setmode 602 | 性能模式。 |
| power-shell setmode 603 | 超级省电模式。 |

示例：
```bash
# 设置设备电源状态为正常模式
power-shell setmode 600
# 设置设备电源状态为省电模式
power-shell setmode 601
# 设置设备电源状态为性能模式
power-shell setmode 602
# 设置设备电源状态为超级省电模式
power-shell setmode 603
```


## 亮屏命令

```bash
power-shell wakeup
```

**亮屏命令列表**

| 命令                          | 描述                     |
| ----------------------------- | ------------------------ |
| power-shell wakeup | 亮屏。 |


示例：

```bash
# shell命令亮屏
power-shell wakeup
```


## 熄屏命令

```bash
power-shell suspend
```


**熄屏命令列表**

| 命令       | 描述                       |
| ---------- | -------------------------- |
| power-shell suspend  | 熄屏。 |


示例：

```bash
# shell命令熄屏
power-shell suspend
```

## 自动熄屏命令

```bash
power-shell timeout
```

**自动熄屏命令参数列表**
| 参数       | 参数说明                       |
| ---------- | -------------------------- |
| -o \<time\> | 必选参数，设置自动熄屏时间。[time]单位为毫秒。 |
| -r | 必选参数，恢复到当前系统设置中的自动熄屏时间。 |

示例：

```bash
# 当前系统设置中自动熄屏时间为30秒
# shell命令设置自动熄屏时间为15000毫秒
power-shell timeout -o 15000
# 恢复系统设置的自动熄屏时间，此时自动熄屏时间为30秒
power-shell timeout -r
```
