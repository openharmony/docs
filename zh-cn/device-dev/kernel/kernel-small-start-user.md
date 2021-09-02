# 用户态启动<a name="ZH-CN_TOPIC_0000001123640059"></a>

-   [用户态根进程启动](#section79911135647)
    -   [根进程的启动过程](#section1184317581349)
    -   [根进程的职责](#section1590220321759)

-   [用户态程序运行](#section194576310611)

## 用户态根进程启动<a name="section79911135647"></a>

根进程是系统第一个用户态进程，进程ID为1，它是所有用户态进程的祖先。

**图 1**  进程树示意图<a name="fig427516409375"></a>  
![](figure/进程树示意图.png "进程树示意图")

### 根进程的启动过程<a name="section1184317581349"></a>

使用链接脚本将如下init启动代码放置到系统镜像指定位置。

```
#define LITE_USER_SEC_ENTRY   __attribute__((section(".user.entry")))
LITE_USER_SEC_ENTRY VOID OsUserInit(VOID *args)
{
#ifdef LOSCFG_KERNEL_DYNLOAD
    sys_call3(__NR_execve, (UINTPTR)g_initPath, 0, 0);
#endif
    while (true) {
    }
}
```

系统启动阶段，OsUserInitProcess启动init进程。具体过程如下：

1.  由内核OsLoadUserInit加载上述代码。
2.  创建新的进程空间，启动/bin/init进程。

### 根进程的职责<a name="section1590220321759"></a>

-   启动关键系统程序或服务，如交互进程shell。

    >![](../public_sys-resources/icon-note.gif) **说明：** 
    >在OpenHarmony 中**init**进程通过读取/etc/init.cfg，根据配置执行指定命令，或启动指定进程（详见：[init启动引导](../subsystems/subsys-boot-init.md)）。


-   监控回收孤儿进程，清理子进程中的僵尸进程。

## 用户态程序运行<a name="section194576310611"></a>

用户态程序常见编译方式有如下两种：

1.  [利用框架编译用户态进程](../quick-start/quickstart-lite-steps-hi3516-running.md)。
2.  手动编译

    实例：

    ```
    clang --target=arm-liteos --sysroot=prebuilts/lite/sysroot -o helloworld helloworld.c
    ```

    **clang**：参考[LLVM安装指导](https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/quick-start/quickstart-lite-env-setup-linux.md)安装LLVM编译器。

    **--target**：--target=arm-liteos，指定编译平台为arm-liteos。

    **--sysroot**：--sysroot=$\{YOUR\_ROOT\_PATH\}/prebuilts/lite/sysroot，指定头文件以及依赖标准库搜索路径为prebuilts下的指定路径。


用户态程序启动有如下常见方式：

-   shell命令启动进程。

    ```
    OHOS $ exec helloworld
    OHOS $ ./helloworld
    OHOS $ /bin/helloworld
    ```


-   通过POSIX接口启动新进程。

    Fork方法创建一个新的进程，exec类接口执行一个全新的进程。


