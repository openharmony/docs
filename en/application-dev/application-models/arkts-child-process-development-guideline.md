# ArkTS Child Process Development

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @SKY2001-->
<!--Designer: @jsjzju-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=73d485de5664db2267ce1c77df771821b164c21d translatedAt=2026-08-18T01:30:05.655Z pushedAt=2026-08-18T08:21:54.139Z -->

## Overview

In multitasking scenarios, developers often face issues such as heavy load on the main process and tasks blocking the UI thread. The [ArkTS child process](ability-terminology.md#arkts-child-process) mechanism allows an app to create child processes that run independently, isolating time-consuming tasks, data processing, and other business logic into child processes to improve the app's responsiveness and stability. This module provides two ways to create an [ArkTS child process](ability-terminology.md#arkts-child-process):

- [Creating a Basic ArkTS Child Process](#creating-a-basic-arkts-child-process): Creates an ArkTS child process in a specified mode. This applies to simple child process scenarios where no parameters need to be passed.

- [Creating an ArkTS Child Process with Parameter Passing](#creating-an-arkts-child-process-with-parameter-passing): Creates an ArkTS child process and passes string and fd handle parameters to it. This applies to scenarios where parameters need to be passed to the child process.

> **NOTE**
>
> - The created child process exits when the parent process exits and cannot run independently of the parent process.
> - The APIs in this module can be used only in the [Stage model](ability-terminology.md#stage-model).

## Constraints

- Child processes created through the APIs in this module have the following constraints:

  - The created child process does not support creating a UI.

  - The created child process does not support API calls that depend on Context (including the APIs of the Context module itself and APIs that take a Context instance as an input parameter).

  - The created child process does not support creating child processes again.

- The total number of child processes started through the child process creation APIs defined in [childProcessManager](../reference/apis-ability-kit/js-apis-app-ability-childProcessManager.md) and the child process creation APIs defined in [native_child_process.h](../reference/apis-ability-kit/capi-native-child-process-h.md) is at most 512 (when system resources are sufficient). Among them, child processes started by the [startChildProcess](../reference/apis-ability-kit/js-apis-app-ability-childProcessManager.md#childprocessmanagerstartchildprocess) API in SELF_FORK mode are not counted in the total.

## Creating a Basic ArkTS Child Process

### Scenario Introduction

This section describes how to create an ArkTS child process in the main process. It applies to simple child process scenarios that do not require parameter passing.

### API Description

| Name | Description |
| --- | --- |
| [childProcessManager.startChildProcess](../reference/apis-ability-kit/js-apis-app-ability-childProcessManager.md#childprocessmanagerstartchildprocess)(srcEntry: string, startMode: [StartMode](../reference/apis-ability-kit/js-apis-app-ability-childProcessManager.md#startmode)): Promise\<number\> | Starts an ArkTS child process. This API uses a promise to return the child process pid. |
| [childProcessManager.startChildProcess](../reference/apis-ability-kit/js-apis-app-ability-childProcessManager.md#childprocessmanagerstartchildprocess)(srcEntry: string, startMode: [StartMode](../reference/apis-ability-kit/js-apis-app-ability-childProcessManager.md#startmode), callback: AsyncCallback\<number\>): void | Starts an ArkTS child process. This API uses an asynchronous callback to return the child process pid. |

> **NOTE**
>
> - After the child process is successfully created by calling the preceding APIs, the child process pid is returned. Then the [ChildProcess.onStart](../reference/apis-ability-kit/js-apis-app-ability-childProcess.md#childprocessonstart) function of the child process is executed. After the [ChildProcess.onStart](../reference/apis-ability-kit/js-apis-app-ability-childProcess.md#childprocessonstart) function is executed, the child process is automatically destroyed.
> - The child process created by calling the preceding APIs does not support asynchronous ArkTS API calls. It supports only synchronous ArkTS API calls.

### How to Develop

1. Create the child process class.

    Create a child process source file under the entry module, inherit the [ChildProcess](../reference/apis-ability-kit/js-apis-app-ability-childProcess.md) class, and implement the [onStart](../reference/apis-ability-kit/js-apis-app-ability-childProcess.md#childprocessonstart) method.

    <!-- @[arkts_child_process_noarg_child](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/ArkTsChildProcess/entry/src/main/ets/process/DemoProcessNoArg.ets) -->

    ``` TypeScript
    import { ChildProcess } from '@kit.AbilityKit';
    
    export default class DemoProcessNoArg extends ChildProcess {
      onStart() {
        console.info('DemoProcess onStart');
        // Implement the child process business logic.
        // ...
      }
    }
    ```

2. Start the child process from the main process.

    In the main process, import the child process class and call [startChildProcess](../reference/apis-ability-kit/js-apis-app-ability-childProcessManager.md#childprocessmanagerstartchildprocess) to start the child process. Note that the child process class must be referenced in the code to prevent the child process source file from being optimized out by the build tool.

    [startChildProcess](../reference/apis-ability-kit/js-apis-app-ability-childProcessManager.md#childprocessmanagerstartchildprocess) supports two child process startup modes:

    - **SELF_FORK**: Forks a child process from the app's own process. A child process started in this mode inherits the parent process resources and cannot use Binder IPC to communicate with other processes. Otherwise, the child process will crash and exit.

    - **APP_SPAWN_FORK**: Forks a child process from AppSpawn. A child process started in this mode does not inherit the parent process resources and can use Binder IPC to communicate with other processes.

    Use a promise to return the result:

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
                  DemoProcessNoArg.toString(); // Reference the child process class to prevent it from being optimized out by the build tool.
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

    Use the callback for asynchronous invocation:

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
                  DemoProcessNoArg.toString(); // Reference the child process class to prevent it from being optimized out by the build tool.
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

## Creating an ArkTS Child Process with Parameter Passing

### Scenario Introduction

This section describes how to create an ArkTS child process and pass string and fd handle parameters to the child process. It applies to scenarios where parameters need to be passed to the child process.

### API Description

| Name | Description |
| --- | --- |
| [childProcessManager.startArkChildProcess](../reference/apis-ability-kit/js-apis-app-ability-childProcessManager.md#childprocessmanagerstartarkchildprocess12)(srcEntry: string, args: [ChildProcessArgs](../reference/apis-ability-kit/js-apis-app-ability-childProcessArgs.md), options?: [ChildProcessOptions](../reference/apis-ability-kit/js-apis-app-ability-childProcessOptions.md)): Promise\<number\> | Starts an ArkTS child process. This API uses a promise to return the child process pid. |

> **NOTE**
>
> - The child process created by calling this API does not inherit the parent process resources. When the child process is created successfully, its pid is returned, and then the [ChildProcess.onStart](../reference/apis-ability-kit/js-apis-app-ability-childProcess.md#childprocessonstart) function of the child process is executed. After the [ChildProcess.onStart](../reference/apis-ability-kit/js-apis-app-ability-childProcess.md#childprocessonstart) function is executed, the child process is not automatically destroyed. The child process needs to call [process.abort](../reference/apis-arkts/js-apis-process.md#processabort) to destroy itself. After the process that calls this API is destroyed, the child process it created is also destroyed.

### How to Develop

1. Create a child process class.

    Create a child process source file under the module, inherit the [ChildProcess](../reference/apis-ability-kit/js-apis-app-ability-childProcess.md) class, and implement the [onStart](../reference/apis-ability-kit/js-apis-app-ability-childProcess.md#childprocessonstart) method. The parameter of the onStart method is [ChildProcessArgs](../reference/apis-ability-kit/js-apis-app-ability-childProcessArgs.md), which is used to receive the parameters passed by the main process.

    <!-- @[arkts_child_process_arg_child](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/ArkTsChildProcess/entry/src/main/ets/process/DemoProcessArg.ets) -->

    ``` TypeScript
    import { ChildProcess, ChildProcessArgs } from '@kit.AbilityKit';
    
    export default class DemoProcessArg extends ChildProcess {
      onStart(args?: ChildProcessArgs) {
        // Obtain the entryParams passed by the main process.
        let entryParams = args?.entryParams;
        console.info(`DemoProcess onStart, entryParams: ${entryParams}`);
        // Obtain the fd handle passed by the main process.
        let fd = args?.fds?.key1;
        // Implement the child process business logic.
        // ...
      }
    }
    ```

2. The main process starts the child process.

    In the main process, import the child process class and call the [startArkChildProcess](../reference/apis-ability-kit/js-apis-app-ability-childProcessManager.md#childprocessmanagerstartarkchildprocess12) method to start the child process. Note that you must reference the child process class in the code to prevent the child process source file from being optimized out by the build tool. For details about how to obtain the context in the example, see [Obtaining the Context of UIAbility](uiability-usage.md#obtaining-the-context-of-uiability).

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
                  DemoProcessArg.toString(); // Reference the child process class to prevent it from being optimized out by the build tool.
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