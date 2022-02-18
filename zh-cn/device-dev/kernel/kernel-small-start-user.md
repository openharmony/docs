# 用户态启动

- [用户态根进程启动](#用户态根进程启动)
  - [根进程的启动过程](#根进程的启动过程)
  - [根进程的职责](#根进程的职责)
- [用户态程序运行](#用户态程序运行)

## 用户态根进程启动

根进程是系统第一个用户态进程，进程ID为1，它是所有用户态进程的祖先。

**图1** 进程树示意图
![zh-cn_image_0000001178108019](figures/zh-cn_image_0000001178108019.png)


### 根进程的启动过程

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

1. 由内核OsLoadUserInit加载上述代码。

2. 创建新的进程空间，启动/bin/init进程。


### 根进程的职责

- 启动关键系统程序或服务，如交互进程shell。
  > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
  > 在OpenHarmony 中**init**进程通过读取/etc/init.cfg，根据配置执行指定命令，或启动指定进程（详见：[init启动引导](../subsystems/subsys-boot.md) 。

- 监控回收孤儿进程，清理子进程中的僵尸进程。

## 用户态程序运行

用户态程序常见编译方式有如下两种：
1. [利用框架编译用户态进程](../quick-start/quickstart-standard-running-rk3568-create.md)。

2. 手动编译
   实例：
   ```
   clang --target=arm-liteos --sysroot=prebuilts/lite/sysroot -o helloworld helloworld.c
   ```

   **clang**：参考[LLVM安装指导](../quick-start/quickstart-lite-package-environment.md#安装llvm-仅openharmony_v1-x分支-标签需要-)安装LLVM编译器。

   **--target**：--target=arm-liteos，指定编译平台为arm-liteos。

   **--sysroot**：--sysroot=${YOUR_ROOT_PATH}/prebuilts/lite/sysroot，指定头文件以及依赖标准库搜索路径为prebuilts下的指定路径。

用户态程序启动有如下常见方式：

- shell命令启动进程。
  ```
  OHOS $ exec helloworld
  OHOS $ ./helloworld
  OHOS $ /bin/helloworld
  ```

- 通过POSIX接口启动新进程。
  Fork方法创建一个新的进程，exec类接口执行一个全新的进程。
