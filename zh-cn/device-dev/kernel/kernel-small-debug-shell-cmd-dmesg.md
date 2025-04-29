# dmesg

## 命令功能

dmesg命令用于显示开机信息，以及系统启动过程和运行过程中的信息。

## 命令格式

dmesg

dmesg [_-c/-C/-D/-E/-L/-U_]

dmesg -s [_size_]

dmesg -l [_level_]

dmesg &gt; [_fileA_]

## 参数说明

**表1** 参数说明

| 参数            | 参数说明                                 | 取值范围        |
| --------------- | ---------------------------------------- | --------------- |
| -c              | 打印缓存区内容并清空缓存区。             | N/A             |
| -C              | 清空缓存区。                             | N/A             |
| -D/-E           | 关闭/开启控制台打印。                    | N/A             |
| -L/-U           | 关闭/开启串口打印。                      | N/A             |
| -s&nbsp;size    | 设置缓存区大小&nbsp;size是要设置的大小。 | N/A             |
| -l&nbsp;level   | 设置缓存等级。                           | [0, 5] |
| &gt;&nbsp;fileA | 将缓存区内容重定向写入文件。             | N/A             |

## 使用指南

- 该命令依赖于LOSCFG_SHELL_DMESG，在kernel/liteos_a中输入make menuconfig命令。此时会弹出配置项，找到Debug选项并进入，然后在配置项中开启"Enable Shell dmesg"：
  Debug  ---&gt; Enable a Debug Version ---&gt; Enable Shell ---&gt; Enable Shell dmesg。

- dmesg参数缺省时，默认打印缓存区内容。

- 各“ - ”选项不能混合使用。
  1. 写入文件需确保已挂载文件系统。
  2. 关闭串口打印会影响shell使用，建议先连接telnet再尝试关闭串口。

## 使用实例

举例：输入dmesg &gt; dmesg.log。

## 输出说明

**示例** dmesg重定向到文件。

```
OHOS # dmesg > dmesg.log
Dmesg write log to dmesg.log success
```