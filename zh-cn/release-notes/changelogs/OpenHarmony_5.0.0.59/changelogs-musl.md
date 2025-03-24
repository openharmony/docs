# 方舟编译运行时子系统变更说明

## cl.arkcompiler.1 信号处理方法注册接口sigaction支持SA_RESETHAND标志位变更

**访问级别**

公开接口

**变更原因**

sigaction是由C库提供的用于注册信号处理方法的接口，开发者可通过调用此接口,指定应用在接收到特定信号时采取的处理方式。

本次变更是对齐[POSIX标准](https://pubs.opengroup.org/onlinepubs/007904875/functions/sigaction.html)，信号处理方法注册接口sigaction支持SA_RESETHAND标志位。


**变更影响**

此变更涉及应用适配。

若应用调用sigaction接口设置信号处理方法时，未指定SA_RESETHAND标志位，则变更前后无影响。

若应用设置信号处理方法时，指定了SA_RESETHAND标志位，则变更前后存在如下差异：

变更前：sigaction接口未支持SA_RESETHAND标志位，应用每次收到信号，均会执行其注册的信号处理方法。

变更后：sigaction接口支持SA_RESETHAND标志位，应用首次收到信号会执行其注册的信号处理方法，其后根据POSIX标准，处理方法被重置为默认值
SIG_DFL，后续收到信号会按照内核默认方式处理。内核默认处理方式与信号编号有关，包括忽略信号、终止进程、终止进程并生成转储文件，若误用了SA_RESETHAND标志位，在本次变更后，可能会导致应用退出，请开发者务必重视排查。

**起始 API Level**

API 11

**变更发生版本**

从OpenHarmony SDK 5.0.0.59

**变更的接口/组件**

musl/signal.h中sigaction接口

**适配指导**

1. 全局搜索sigaction接口调用，查看设置信号处理方法相关代码。

2. 排查入参sigaction结构体中sa_flags中是否指定了SA_RESETHAND标志位(SA_RESETHAND是POSIX标准名字，SA_ONESHOT是过时的非标准名字，二者作用一致)。

3. 若应用的预期是信号处理方法只生效一次，需要显式指定SA_RESETHAND标志位，若应用预期信号处理方法多次生效，则移除SA_RESETHAND标志位，避免该标志位使能后信号处理方法恢复为默认值SIG_DFL，对应用造成闪退影响。

4. 在调用sigaction方法前，请按需设置sa_flags标志位，避免未初始化的随机值(可能包含SA_RESETHAND标志位)产生应用预期外的行为。

示例代码：

```cpp
// 情况一：若应用预期是信号处理方法注册后只生效一次，其后恢复为默认值SIG_DFL，需要显式指定SA_RESETHAND标志位
struct sigaction sa;

// 请重点排查sigaction结构体的sa_flags标志位，该示例中显式指定SA_RESETHAND标志位，此处可根据业务需要，合理添加其它标志位
sa.sa.sa_flags = SA_RESETHAND;
sa.sa_handler = func;
ret = sigaction(SIGUSR1, &sa, NULL);
if (ret < 0) {
    perror("sigaction error");
    return -1;
}

//情况二：若应用预期是信号处理方法注册后持续生效，则sa_flags不允许包含SA_RESETHAND标志位
struct sigaction sa;

// 请重点排查sigaction结构体的sa_flags标志位，确保不包含SA_RESETHAND标志位，此处可根据业务需要，合理添加其它标志位，此处示例为0
sa.sa_flags = 0              
sa.sa_handler = func;
ret = sigaction(SIGUSR1, &sa, NULL);
if (ret < 0) {
    perror("sigaction error");
    return -1;
}
```

