# 子进程开发指导（ArkTS）
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @SKY2001-->
<!--Designer: @jsjzju-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

## 概述

在多任务处理场景中，开发者常面临主进程负载过重、任务阻塞UI线程等问题。子进程机制允许应用创建独立运行的子进程，将耗时任务、数据处理等业务逻辑隔离到子进程中执行，提升应用的响应速度和稳定性。本模块提供了通过ArkTS API创建子进程的方式，三种创建方式的接口选型和能力差异请参见[子进程创建方式选择](#子进程创建方式选择)。

> **说明：**
>
> 创建的子进程会随着父进程的退出而退出，无法脱离父进程独立运行。

## 子进程创建方式选择

| 对比项 | [创建基础ArkTS子进程](#创建基础arkts子进程) | [创建支持参数传递的ArkTS子进程](#创建支持参数传递的arkts子进程)| [创建支持参数传递的Native子进程](#创建支持参数传递的native子进程) |
| --- | --- | --- | --- |
| 涉及接口 | [startChildProcess](../reference/apis-ability-kit/js-apis-app-ability-childProcessManager.md#childprocessmanagerstartchildprocess) | [startArkChildProcess](../reference/apis-ability-kit/js-apis-app-ability-childProcessManager.md#childprocessmanagerstartarkchildprocess12)<sup>12+</sup> | [startNativeChildProcess](../reference/apis-ability-kit/js-apis-app-ability-childProcessManager.md#childprocessmanagerstartnativechildprocess13)<sup>13+</sup> |
| 适用场景 | 适用于无需传参的轻量ArkTS后台任务，如本地日志归档、配置解析、启动期数据预处理等。| 适用于需要传参或长时运行的ArkTS任务，如接收文件fd进行文档或图片解析、依据参数执行长时数据加工等。| 适用于高性能C/C++计算或复用现有Native库，如音视频编解码、图像处理、计算密集型任务等。|
| 子进程运行环境 | ArkTS运行时，可调用ArkTS API | ArkTS运行时，可调用ArkTS API | C/C++运行时，无ArkTS运行时 |
| 是否继承父进程资源 | 仅SELF_FORK模式继承，APP_SPAWN_FORK模式不继承 | 不继承 | 不继承 |
| 是否支持Binder IPC | SELF_FORK模式不支持，APP_SPAWN_FORK模式支持 | 支持 | 支持 |
| 子进程销毁方式 | [onStart](../reference/apis-ability-kit/js-apis-app-ability-childProcess.md#childprocessonstart)执行完后自动销毁 | 不自动销毁，需子进程调用[process.abort](../reference/apis-arkts/js-apis-process.md#processabort)销毁 | 入口函数返回后自动销毁 |
| 是否支持异步ArkTS API | 不支持，仅支持同步 | 支持 | 不适用（子进程为C/C++环境） |
| 进程隔离模式配置 | 不支持 | 支持（[ChildProcessOptions](../reference/apis-ability-kit/js-apis-app-ability-childProcessOptions.md)的isolationMode） | 支持（[ChildProcessOptions](../reference/apis-ability-kit/js-apis-app-ability-childProcessOptions.md)的isolationMode） |
| 查询设备是否支持创建子进程 | [childProcessManager.isArkChildProcessSupported](../reference/apis-ability-kit/js-apis-app-ability-childProcessManager.md#childprocessmanagerisarkchildprocesssupported) | [childProcessManager.isArkChildProcessSupported](../reference/apis-ability-kit/js-apis-app-ability-childProcessManager.md#childprocessmanagerisarkchildprocesssupported) | [childProcessManager.isNativeChildProcessSupported](../reference/apis-ability-kit/js-apis-app-ability-childProcessManager.md#childprocessmanagerisnativechildprocesssupported) |

> **说明：**
>
> 上述三种创建方式均未提供父子进程间的IPC通道；表中“是否支持Binder IPC”仅表示子进程运行环境具备该能力，并不代表接口本身已向应用层开放父子通信API，如需实现父子进程间的Binder IPC通信，请直接调用[OH_Ability_CreateNativeChildProcessWithConfigs](../reference/apis-ability-kit/capi-native-child-process-h.md#oh_ability_createnativechildprocesswithconfigs)接口。

## 创建基础ArkTS子进程

通过[startChildProcess](../reference/apis-ability-kit/js-apis-app-ability-childProcessManager.md#childprocessmanagerstartchildprocess)接口创建[ArkTS子进程](ability-terminology.md#arkts子进程)，需定义继承[ChildProcess](../reference/apis-ability-kit/js-apis-app-ability-childProcess.md)的入口类并实现[onStart](../reference/apis-ability-kit/js-apis-app-ability-childProcess.md#childprocessonstart)方法。子进程onStart方法执行完后自动退出。


1. 创建子进程类。

    在entry模块下创建子进程源文件，继承[ChildProcess](../reference/apis-ability-kit/js-apis-app-ability-childProcess.md)类并实现[onStart](../reference/apis-ability-kit/js-apis-app-ability-childProcess.md#childprocessonstart)方法。

    <!-- @[arkts_child_process_noarg_child](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/ArkTsChildProcess/entry/src/main/ets/process/DemoProcessNoArg.ets) -->
    
    ``` TypeScript
    import { ChildProcess } from '@kit.AbilityKit';
    
    export default class DemoProcessNoArg extends ChildProcess {
      onStart() {
        console.info('DemoProcess onStart');
        // 实现子进程业务逻辑
        // ...
      }
    }
    ```

2. 主进程启动子进程。

    在主进程中导入子进程类并调用[startChildProcess](../reference/apis-ability-kit/js-apis-app-ability-childProcessManager.md#childprocessmanagerstartchildprocess)方法启动子进程。需要注意，必须在代码中引用子进程类，防止子进程源文件被构建工具优化掉。

    [startChildProcess](../reference/apis-ability-kit/js-apis-app-ability-childProcessManager.md#childprocessmanagerstartchildprocess)接口支持两种子进程启动模式：
    - **SELF_FORK**：从应用自身进程Fork子进程。以该模式启动的子进程会继承父进程资源，不能使用Binder IPC和其他进程通信，否则会导致子进程崩溃退出。
    - **APP_SPAWN_FORK**：从AppSpawn Fork子进程。以该模式启动的子进程不会继承父进程资源，可以使用Binder IPC和其他进程通信。

    启动后可在HiLog中搜索“startChildProcess”关键字，查看到“startChildProcess success, pid: xxx”日志表示子进程创建成功；再搜索“DemoProcess onStart”关键字，查看到该日志表示子进程入口函数已执行。

    使用Promise异步回调：

    <!-- @[arkts_child_process_noarg_one](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/ArkTsChildProcess/entry/src/main/ets/pages/Index.ets) --> 
    
    ``` TypeScript
    import { childProcessManager } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    import DemoProcessNoArg from '../process/DemoProcessNoArg';
    // ...
    @Entry
    @Component
    struct Index {
    
      build() {
        Scroll() {
          Column() {
            Text("StartArkChildProcessNoArg_Promise")
              .fontSize($r('app.float.page_text_font_size'))
              .fontWeight(FontWeight.Bold)
              .alignRules({
                center: { anchor: '__container__', align: VerticalAlign.Center },
                middle: { anchor: '__container__', align: HorizontalAlign.Center }
              })
              .onClick(() => {
                try {
                  DemoProcessNoArg.toString(); // 引用子进程类，防止被构建工具优化掉
                  childProcessManager.startChildProcess("./ets/process/DemoProcessNoArg.ets", childProcessManager.StartMode.SELF_FORK)
                    .then((pid) => {
                      console.info(`startChildProcess success, pid: ${pid}`);
                    })
                    .catch((err: BusinessError) => {
                      console.error(`startChildProcess error, errorCode: ${err.code}`);
                    });
                } catch (err) {
                  console.error(`startChildProcess error, errorCode: ${(err as BusinessError).code}`);
                }
              })
    // ...
          }
          .width('100%')
        }
        .height('100%')
      }
    }
    ```

    使用callback异步回调：

    <!-- @[arkts_child_process_noarg_two](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/ArkTsChildProcess/entry/src/main/ets/pages/Index.ets) --> 
    
    ``` TypeScript
    import { childProcessManager } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    import DemoProcessNoArg from '../process/DemoProcessNoArg';
    // ...
    @Entry
    @Component
    struct Index {
    
      build() {
        Scroll() {
          Column() {
    // ...
            Text("StartArkChildProcessNoArg_Callback")
              .fontSize($r('app.float.page_text_font_size'))
              .fontWeight(FontWeight.Bold)
              .alignRules({
                center: { anchor: '__container__', align: VerticalAlign.Center },
                middle: { anchor: '__container__', align: HorizontalAlign.Center }
              })
              .onClick(() => {
                try {
                  DemoProcessNoArg.toString(); // 引用子进程类，防止被构建工具优化掉
                  childProcessManager.startChildProcess("./ets/process/DemoProcessNoArg.ets", childProcessManager.StartMode.SELF_FORK, (err, data) => {
                    if (data) {
                      console.info(`startChildProcess success, pid: ${data}`);
                    } else {
                      console.error(`startChildProcess error, errorCode: ${err.code}`);
                    }
                  });
                } catch (err) {
                  console.error(`startChildProcess error, errorCode: ${(err as BusinessError).code}`);
                }
              })
    // ...
          }
          .width('100%')
        }
        .height('100%')
      }
    }
    ```

## 创建支持参数传递的ArkTS子进程

通过[startArkChildProcess](../reference/apis-ability-kit/js-apis-app-ability-childProcessManager.md#childprocessmanagerstartarkchildprocess12)接口创建ArkTS子进程，需定义继承[ChildProcess](../reference/apis-ability-kit/js-apis-app-ability-childProcess.md)的入口类，通过[ChildProcessArgs](../reference/apis-ability-kit/js-apis-app-ability-childProcessArgs.md)传递字符串参数和fd句柄。子进程不自动退出，需主动调用[process.abort](../reference/apis-arkts/js-apis-process.md#processabort)销毁。


1. 创建子进程类。

    在模块下创建子进程源文件，继承[ChildProcess](../reference/apis-ability-kit/js-apis-app-ability-childProcess.md)类并实现[onStart](../reference/apis-ability-kit/js-apis-app-ability-childProcess.md#childprocessonstart)方法。onStart方法的参数为[ChildProcessArgs](../reference/apis-ability-kit/js-apis-app-ability-childProcessArgs.md)，用于接收主进程传递的参数。

    <!-- @[arkts_child_process_arg_child](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/ArkTsChildProcess/entry/src/main/ets/process/DemoProcessArg.ets) -->
    
    ``` TypeScript
    import { ChildProcess, ChildProcessArgs } from '@kit.AbilityKit';
    
    export default class DemoProcessArg extends ChildProcess {
      onStart(args?: ChildProcessArgs) {
        // 获取主进程传递的entryParams
        let entryParams = args?.entryParams;
        console.info(`DemoProcess onStart, entryParams: ${entryParams}`);
        // 获取主进程传递的fd句柄
        let fd = args?.fds?.key1;
        // 实现子进程业务逻辑
        // ...
      }
    }
    ```

2. 主进程启动子进程。

    在主进程中导入子进程类并调用[startArkChildProcess](../reference/apis-ability-kit/js-apis-app-ability-childProcessManager.md#childprocessmanagerstartarkchildprocess12)方法启动子进程。需要注意，必须在代码中引用子进程类，防止子进程源文件被构建工具优化掉。示例中的context的获取方式请参见[获取UIAbility的上下文信息](uiability-usage.md#获取uiability的上下文信息)。

    启动后可在HiLog中搜索“startArkChildProcess”关键字，查看到“startArkChildProcess success, pid: xxx”日志表示子进程创建成功；再搜索“DemoProcess onStart”关键字，查看到该日志表示子进程入口函数已执行。

    <!-- @[arkts_child_process_arg](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/ArkTsChildProcess/entry/src/main/ets/pages/Index.ets) --> 
    
    ``` TypeScript
    import { childProcessManager } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    // ...
    import DemoProcessArg from  '../process/DemoProcessArg';
    import { fileIo } from '@kit.CoreFileKit';
    import { common, ChildProcessArgs, ChildProcessOptions } from '@kit.AbilityKit';
    @Entry
    @Component
    struct Index {
    
      build() {
        Scroll() {
          Column() {
    // ...
            Text("StartArkChildProcessWithArg")
              .fontSize($r('app.float.page_text_font_size'))
              .fontWeight(FontWeight.Bold)
              .alignRules({
                center: { anchor: '__container__', align: VerticalAlign.Center },
                middle: { anchor: '__container__', align: HorizontalAlign.Center }
              })
              .onClick(() => {
                try {
                  DemoProcessArg.toString(); // 引用子进程类，防止被构建工具优化掉
                  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
                  let path = context.filesDir + "/test.txt";
                  let file = fileIo.openSync(path, fileIo.OpenMode.READ_ONLY | fileIo.OpenMode.CREATE);
                  let args: ChildProcessArgs = {
                    entryParams: "testParam",
                    fds: {
                      "key1": file.fd
                    }
                  };
                  let options: ChildProcessOptions = {
                    isolationMode: false
                  };
                  childProcessManager.startArkChildProcess("module1/ets/process/DemoProcess.ets", args, options)
                    .then((pid) => {
                      console.info(`startArkChildProcess success, pid: ${pid}`);
                    })
                    .catch((err: BusinessError) => {
                      console.error(`startArkChildProcess error, errorCode: ${err.code}, errorMsg:${err.message}`);
                    });
                } catch (err) {
                  console.error(`startArkChildProcess error, errorCode: ${(err as BusinessError).code}`);
                }
              })
          }
          .width('100%')
        }
        .height('100%')
      }
    }
    ```

## 创建支持参数传递的Native子进程

通过[startNativeChildProcess](../reference/apis-ability-kit/js-apis-app-ability-childProcessManager.md#childprocessmanagerstartnativechildprocess13)接口创建[Native子进程](ability-terminology.md#native子进程)，需在C/C++中实现入口函数并编译为动态链接库，通过[ChildProcessArgs](../reference/apis-ability-kit/js-apis-app-ability-childProcessArgs.md)传递字符串参数和fd句柄。入口函数返回后子进程自动退出。


1. 在子进程中实现入口函数。

    在子进程中，实现参数为[NativeChildProcess_Args](../reference/apis-ability-kit/capi-nativechildprocess-args.md)的入口函数并导出（假设代码所在的文件名为ChildProcessSample.cpp）。子进程启动后会调用该入口函数，该函数返回后子进程随即退出。

    <!-- @[child_process_necessary_export_impl](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/NativeChildProcessParams/entry/src/main/cpp/ChildProcessFunc.cpp) -->
    
    ``` C++
    #include <AbilityKit/native_child_process.h>
    #include <hilog/log.h>
    #include "loghelper.h"

    extern "C" {
    /**
     * 子进程的入口函数，实现子进程的业务逻辑
     * 函数名称可以自定义，在主进程调用OH_Ability_StartNativeChildProcess方法时指定，此示例中为Main
     * 函数返回后子进程退出
     */
    void Main(NativeChildProcess_Args args)
    {
        OH_LOG_INFO(LOG_APP, "Main started");
        // 获取传入的entryParams
        char *entryParams = args.entryParams;
        // 获取传入的fd列表
        NativeChildProcess_Fd *current = args.fdList.head;
        while (current != nullptr) {
            char *fdName = current->fdName;
            int32_t fd = current->fd;
            current = current->next;
            // 实现业务逻辑
        }
    }
    } // extern "C"
    ```

2. 编译动态链接库。

    修改CMakeLists.txt文件，编译为动态链接库（假设需要编译出的库文件名称为libchildprocesssample.so），并添加元能力动态库依赖。

    ```txt
    add_library(childprocesssample SHARED
        # 实现必要导出方法的源文件
        ChildProcessSample.cpp
        
        # 其它代码源文件
        # ...
    )

    target_link_libraries(childprocesssample PUBLIC
        # 添加依赖的元能力动态库
        libchild_process.so

        # 其它所依赖的动态库
        # ...
    )
    ```

3. 在主进程中启动Native子进程。

    在主进程中调用[startNativeChildProcess](../reference/apis-ability-kit/js-apis-app-ability-childProcessManager.md#childprocessmanagerstartnativechildprocess13)方法启动Native子进程。示例中的context的获取方式请参见[获取UIAbility的上下文信息](uiability-usage.md#获取uiability的上下文信息)。

    启动后可在HiLog中搜索“startNativeChildProcess”关键字，查看到“startNativeChildProcess success, pid: xxx”日志表示子进程创建成功；再搜索“Main started”关键字，查看到该日志表示子进程入口函数已执行。
    
    <!-- @[child_get_start_params_index](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/NativeChildProcessParams/entry/src/main/ets/pages/Index.ets) -->
    
    ``` TypeScript
    import { common, ChildProcessArgs, ChildProcessOptions, childProcessManager } from '@kit.AbilityKit';
    import { fileIo } from '@kit.CoreFileKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    
    @Entry
    @Component
    struct Index {
      build() {
        Scroll() {
          Column() {
            Text("StartNativeChildProcess")
              .fontSize($r('app.float.page_text_font_size'))
              .fontWeight(FontWeight.Bold)
              .alignRules({
                center: { anchor: '__container__', align: VerticalAlign.Center },
                middle: { anchor: '__container__', align: HorizontalAlign.Center }
              })
              .onClick(() => {
                try {
                  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
                  let path = context.filesDir + "/test.txt";
                  let file = fileIo.openSync(path, fileIo.OpenMode.READ_ONLY | fileIo.OpenMode.CREATE);
                  let args: ChildProcessArgs = {
                    entryParams: "testParam",
                    fds: {
                      "key1": file.fd
                    }
                  };
                  let options: ChildProcessOptions = {
                    isolationMode: false
                  };
                  childProcessManager.startNativeChildProcess("libchildprocesssample.so:Main", args, options)
                    .then((pid) => {
                      console.info(`startNativeChildProcess success, pid: ${pid}`);
                    })
                    .catch((err: BusinessError) => {
                      console.error(`startNativeChildProcess error, errorCode: ${err.code}, errorMsg:${err.message}`);
                    });
                } catch (err) {
                  console.error(`startNativeChildProcess error, errorCode: ${(err as BusinessError).code}`);
                }
              })
          }
          .width('100%')
        }
        .height('100%')
      }
    }
    ```
