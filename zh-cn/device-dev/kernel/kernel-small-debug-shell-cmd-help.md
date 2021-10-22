# help<a name="ZH-CN_TOPIC_0000001134006250"></a>

-   [命令功能](#section01)
-   [命令格式](#section02)
-   [参数说明](#section03)
-   [使用指南](#section04)
-   [使用实例](#section05)
-   [输出说明](#section06)

## 命令功能<a name="section01"></a>

help命令用于显示当前操作系统内所有操作指令和部分toybox指令。

## 命令格式<a name="section02"></a>

help

## 参数说明<a name="section03"></a>

无。

## 使用指南<a name="section04"></a>

help用于显示当前操作系统内所有操作指令。

## 使用实例<a name="section05"></a>

举例：输入help。

## 输出说明<a name="section06"></a>

**示例1**  查看系统内所有操作指令

```shell
OHOS:/$ help
*******************shell commands:*************************

arp           cat           cat_logmpp    cd            chgrp         chmod         chown         cp
cpup          date          dhclient      dmesg         dns           format        free          help
hi3881        hwi           ifconfig      ipdebug       kill          log           ls            lsfd
memcheck      mkdir         mount         netstat       oom           panicreset    partinfo      partition
ping          ping6         pmm           pwd           reset         rm            rmdir         sem
shm           stack         statfs        su            swtmr         sync          systeminfo    task
telnet        touch         umount        uname         v2p           vmm           watch         writeproc
usage: help [command]

Show usage information for toybox commands.
Run "toybox" with no arguments for a list of available commands.
```

**内容声明：**

展示toybox指令请使用toybox。

**示例2**  toybox指令集

```shell
OHOS:/$ toybox
chgrp chmod chown cp date du free help ifconfig kill ls mkdir mount
mv ping ps reboot rm rmdir top touch umount uname
```



