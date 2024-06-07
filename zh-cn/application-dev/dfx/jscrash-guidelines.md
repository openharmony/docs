# 分析JS Crash（进程崩溃）

当未处理的JS异常导致应用意外退出时，应用会在抛出未处理的异常时崩溃并且会生成对应的JS Crash崩溃日志文件。开发者可通过错误日志查看引起崩溃的代码位置及分析应用崩溃的原因。

本文将分别介绍如何获取进程崩溃日志，以及如何进行崩溃日志分析。

## 获取方式

进程崩溃日志是一种故障日志，与应用无响应日志、JS应用崩溃等都由FaultLogger模块管理，可通过以下方式获取：

- 方式一：通过DevEco Studio获取日志

    DevEco Studio会收集“设备/data/log/faultlog/faultlogger/”路径下的进程崩溃故障日志并归档在FaultLog下，获取日志的方法可参考[DevEco Studio使用指南-FaultLog](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V2/ide-debug-hilog-0000001172459337-V2#section974519209435)。

- 方式二：通过faultlogger接口获取

    faultlogger对外提供了故障查询接口，可以查询各种故障信息，详见[@ohos.faultLogger (故障日志获取)](../reference/apis-performance-analysis-kit/js-apis-faultLogger.md)。
<!--Del-->
- 方式三：通过shell获取日志

    进程崩溃后，JSCrash文件会生成在“设备/data/log/faultlog/faultlogger/”路径下，故障日志文件名格式为“jscrash-进程名-进程UID-秒级时间”，包含设备名、系统版本、进程崩溃调用栈等信息。

    ![](figures/jscrash.png)
<!--DelEnd-->
## 进程崩溃日志分析

以上方式获取到的日志是无差异的。jscrash多为应用问题，开发者可通过崩溃文件中的 Error message 和 StackTrace 来定位问题。

以下是进程崩溃日志信息中对应字段解释。

```
Build info:ALN-AL00 4.1.0.30(SP4C00E30R4P8log) <- 版本信息
Module name:com.example.myapplication <- 模块名
Version:1.0.0 <- 版本号
Pid:579 <- 进程号
Uid:0 <- 用户ID
Reason:TypeError <- 原因
Error message:Cannot read property c of undefined <- 异常信息
Cannot get SourceMap info, dump raw stack: <- js栈通过sourcmap行列号解析失败
SourceCode:
        var a = b.c;   <-异常代码位置
                ^
Stacktrace:
    at onPageShow (entry/src/main/ets/pages/Index.ets:7:13)  <-异常代码调用栈
           ^                                      ^
         函数名异常代码文件行列号位置
```

## 通过日志分析问题

日志分析会有如下两种情况：

- **情况一：可跳转至引起错误的代码行**

  如果FaultLog的堆栈信息中的链接或偏移地址指向的是当前工程中的某行代码，该段信息将被转换为超链接形式，在DevEco Studio中点击后跳转至对应代码行。

- **情况二：不可跳转至引起错误的代码行或者跳转代码位置不存在**

  如出现`Cannot get Source Map info, dump raw stack`信息代表js栈转换ets行列号失败，在DevEco Studio中点击链接会跳转到不正确的代码位置或不存在的代码行位置。

  应用代码运行出错时，会打印错误栈信息。如果ts栈转换ets行列号失败时错误栈的后缀仍显示为ets，开发者需要在build目录下编译中间产物以生成ts代码，在js代码中定位对应错误代码行。可参考：[应用堆栈解析](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V2/release-app-stack-analysis-0000001421224074-V2)。