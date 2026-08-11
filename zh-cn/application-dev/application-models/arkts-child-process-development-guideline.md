# ArkTS子进程开发指导
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @SKY2001-->
<!--Designer: @jsjzju-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

## 概述

在多任务处理场景中，开发者常面临主进程负载过重、任务阻塞UI线程等问题。[ArkTS子进程](ability-terminology.md#arkts子进程)机制允许应用创建独立运行的子进程，将耗时任务、数据处理等业务逻辑隔离到子进程中执行，提升应用的响应速度和稳定性。本模块提供了两种创建[ArkTS子进程](ability-terminology.md#arkts子进程)的方式：
- [创建基础ArkTS子进程](#创建基础arkts子进程)：以指定模式创建ArkTS子进程，适用于不需要传递参数的简单子进程场景。
- [创建支持参数传递的ArkTS子进程](#创建支持参数传递的arkts子进程)：创建ArkTS子进程，并传递字符串和fd句柄参数到子进程。适用于需要传递参数到子进程的场景。

> **说明：**
>
> - 创建的子进程会随着父进程的退出而退出，无法脱离父进程独立运行。
> - 本模块接口仅可在[Stage模型](ability-terminology.md#stage模型)下使用。

## 约束限制

- 通过本模块中接口创建的子进程有如下限制：
  - 创建的子进程不支持创建UI界面。
  - 创建的子进程不支持依赖Context的API调用（包括Context模块自身API及将Context实例作为入参的API）。
  - 创建的子进程内不支持再次创建子进程。

- 通过[childProcessManager](../reference/apis-ability-kit/js-apis-app-ability-childProcessManager.md)中定义的创建子进程的接口和[native_child_process.h](../reference/apis-ability-kit/capi-native-child-process-h.md)中定义的创建子进程的接口启动的子进程总数最大为512个（系统资源充足情况下），其中[startChildProcess](../reference/apis-ability-kit/js-apis-app-ability-childProcessManager.md#childprocessmanagerstartchildprocess)接口在SELF_FORK模式下启动的子进程不计入总数内。

## 创建基础ArkTS子进程

### 场景介绍

本章节介绍如何在主进程中创建ArkTS子进程，适用于不需要传递参数的简单子进程场景。

### 接口说明

| 名称 | 描述 |
| --- | --- |
| [childProcessManager.startChildProcess](../reference/apis-ability-kit/js-apis-app-ability-childProcessManager.md#childprocessmanagerstartchildprocess)(srcEntry: string, startMode: [StartMode](../reference/apis-ability-kit/js-apis-app-ability-childProcessManager.md#startmode)): Promise\<number\> | 启动ArkTS子进程，使用Promise异步回调返回子进程pid。 |
| [childProcessManager.startChildProcess](../reference/apis-ability-kit/js-apis-app-ability-childProcessManager.md#childprocessmanagerstartchildprocess)(srcEntry: string, startMode: [StartMode](../reference/apis-ability-kit/js-apis-app-ability-childProcessManager.md#startmode), callback: AsyncCallback\<number\>): void | 启动ArkTS子进程，使用callback异步回调返回子进程pid。 |

> **说明：**
>
> - 调用上述接口创建子进程成功会返回子进程pid，然后执行子进程的[ChildProcess.onStart](../reference/apis-ability-kit/js-apis-app-ability-childProcess.md#childprocessonstart)函数，[ChildProcess.onStart](../reference/apis-ability-kit/js-apis-app-ability-childProcess.md#childprocessonstart)函数执行完后子进程会自动销毁。
> - 调用上述接口创建的子进程不支持异步ArkTS API调用，仅支持同步ArkTS API调用。

### 开发步骤

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

### 场景介绍

本章节介绍如何创建ArkTS子进程，并传递字符串和fd句柄参数到子进程。适用于需要传递参数到子进程的场景。

### 接口说明

| 名称 | 描述 |
| --- | --- |
| [childProcessManager.startArkChildProcess](../reference/apis-ability-kit/js-apis-app-ability-childProcessManager.md#childprocessmanagerstartarkchildprocess12)(srcEntry: string, args: [ChildProcessArgs](../reference/apis-ability-kit/js-apis-app-ability-childProcessArgs.md), options?: [ChildProcessOptions](../reference/apis-ability-kit/js-apis-app-ability-childProcessOptions.md)): Promise\<number\> | 启动ArkTS子进程，使用Promise异步回调返回子进程pid。 |

> **说明：**
>
> - 调用该接口创建的子进程不会继承父进程资源，子进程创建成功会返回子进程pid，然后执行子进程的[ChildProcess.onStart](../reference/apis-ability-kit/js-apis-app-ability-childProcess.md#childprocessonstart)函数。[ChildProcess.onStart](../reference/apis-ability-kit/js-apis-app-ability-childProcess.md#childprocessonstart)函数执行完后子进程不会自动销毁，需要子进程调用[process.abort](../reference/apis-arkts/js-apis-process.md#processabort)销毁。调用该接口的进程销毁后，所创建的子进程也会一并销毁。

### 开发步骤

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
