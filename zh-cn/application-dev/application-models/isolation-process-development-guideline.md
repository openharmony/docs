# 独立进程开发指导
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @SKY2001-->
<!--Designer: @jsjzju-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

## 概述

在多模块应用开发场景中，开发者常面临模块间相互影响、异常传播导致整体崩溃等问题。进程隔离机制允许开发者将不同功能模块配置到独立进程中运行，实现模块间的进程隔离，提升应用的稳定性和安全性。该机制适用于需要模块隔离、故障隔离、安全隔离等场景。

> **说明：**
>
> 本模块接口仅可在[Stage模型](ability-terminology.md#stage模型)下使用。

## 静态指定进程

### 场景介绍

静态指定进程适用于在编译期就能确定进程分配的场景，例如将某些功能组件隔离到独立进程中运行，提高应用的稳定性和安全性。当同一应用中的多个UIAbility或EmbeddedUIExtensionAbility需要运行在不同进程时，开发者可以通过配置[module.json5配置文件](../quick-start/module-configuration-file.md)中的[abilities标签](../quick-start/module-configuration-file.md#abilities标签)或[extensionAbilities标签](../quick-start/module-configuration-file.md#extensionabilities标签)中的process字段静态指定所要运行的进程。系统在启动UIAbility或EmbeddedUIExtensionAbility时，会根据process字段分配进程。

### 约束限制

- 静态指定进程仅对UIAbility和EmbeddedUIExtensionAbility生效。
- 静态指定进程仅支持在PC/2in1和Tablet设备类型上使用。
- [abilities标签](../quick-start/module-configuration-file.md#abilities标签)或[extensionAbilities标签](../quick-start/module-configuration-file.md#extensionabilities标签)中的process字段以":"开头表示应用私有进程，进程名的实际格式为"应用包名:指定字符串"。
- 如果多个UIAbility和EmbeddedUIExtensionAbility的process字段配置为相同的字符串，则它们会运行在同一个进程内。

### 开发步骤

该示例代码以UIAbility为例介绍如何配置静态指定进程。在需要运行在独立进程的UIAbility的[module.json5配置文件](../quick-start/module-configuration-file.md)中，在[abilities标签](../quick-start/module-configuration-file.md#abilities标签)下对应的ability中添加process字段。process字段值以":"开头，表示应用私有进程。配置相同process字段值的多个ability将运行在同一进程中。以下示例中，EntryAbility未配置process字段，运行在默认进程中；EntryAbility1和EntryAbility2的process字段均配置为":processTag"，它们将运行在同一独立进程中，进程名为"应用包名:processTag"：

<!-- @[static_isolation_process_config](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/StaticIsolationProcess/entry/src/main/module.json5) --> 

``` JSON5
{
  "module": {
// ...
    "abilities": [
// ...
      {
        "name": "EntryAbility1",
        "srcEntry": "./ets/entryability1/EntryAbility1.ets",
// ...
        "process": ":processTag"
      },
      {
        "name": "EntryAbility2",
        "srcEntry": "./ets/entryability2/EntryAbility2.ets",
// ...
        "process": ":processTag"
      }
    ],
// ...
  }
}
```

## 动态指定进程

### 场景介绍

动态指定进程适用于在运行阶段去动态确定运行进程的场景，例如将某些组件动态隔离到独立进程中运行，提高应用的稳定性和安全性。针对UIAbility实例，开发者需要将该UIAbility对应的[abilities标签](../quick-start/module-configuration-file.md#abilities标签)中的isolationProcess字段配置为true；系统在启动该UIAbility实例时，[主控进程](ability-terminology.md#masterprocess主控进程)会触发[onNewProcessRequest](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#onnewprocessrequest11)回调方法返回用于标识独立进程的字符串。UIAbility所运行的独立进程名称的拼接规则为"包名:onNewProcessRequest回调方法返回的字符串"。如果返回的字符串是开发者曾创建过的，则复用该标识所对应的进程，否则创建新的进程。
<!--Del-->
针对sys/commonUI类型的UIExtensionAbility，开发者需要将该UIExtensionAbility对应的[extensionAbilities标签](../quick-start/module-configuration-file.md#extensionabilities标签)中的isolationProcess字段配置为true；同样的，系统在启动该sys/commonUI类型的UIExtensionAbility实例时，[主控进程](ability-terminology.md#masterprocess主控进程)会触发[onNewProcessRequest](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#onnewprocessrequest11)回调方法返回用于标识独立进程的字符串。
<!--DelEnd-->

### 约束限制

- 动态指定进程仅对UIAbility<!--Del-->和sys/commonUI类型的UIExtensionAbility<!--DelEnd-->生效。
- 动态指定进程仅支持在PC/2in1和Tablet设备类型上使用。

### 开发步骤

该示例代码以UIAbility为例介绍如何进行动态指定进程的开发。

1. 配置动态指定进程。

    在[module.json5配置文件](../quick-start/module-configuration-file.md)中进行两项配置：首先在[配置文件标签](../quick-start/module-configuration-file.md#配置文件标签)下通过srcEntry指定AbilityStage源文件路径；然后在[abilities标签](../quick-start/module-configuration-file.md#abilities标签)下为需要动态指定进程的UIAbility添加isolationProcess字段并设为true。

    以下示例中，名为EntryAbility1的UIAbility实例配置了isolationProcess为true，其运行进程由AbilityStage的onNewProcessRequest回调方法返回的字符串动态指定

    <!-- @[dynamic_isolation_process_config](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/DynamicIsolationProcess/entry/src/main/module.json5) --> 
    
    ``` JSON5
    {
      "module": {
    // ...
        "srcEntry": "./ets/MyAbilityStage/MyAbilityStage.ets",
    // ...
        "abilities": [
    // ...
          {
            "name": "EntryAbility1",
            "srcEntry": "./ets/entryability1/EntryAbility1.ets",
    // ...
            "isolationProcess": true
          }
        ],
    // ...
      }
    }
    ```

2. 实现AbilityStage的onNewProcessRequest回调方法。

    在srcEntry指定的AbilityStage源文件中，实现[onNewProcessRequest](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#onnewprocessrequest11)回调方法。系统在启动配置isolationProcess为true的UIAbility实例时会触发该回调方法，然后根据该方法返回的字符串来动态的指定UIAbility实例所运行的独立进程。

    <!-- @[dynamic_isolation_process](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/DynamicIsolationProcess/entry/src/main/ets/MyAbilityStage/MyAbilityStage.ets) --> 
    
    ``` TypeScript
    import AbilityStage from '@ohos.app.ability.AbilityStage';
    
    export default class MyAbilityStage extends AbilityStage {
    // ...
      onNewProcessRequest(want: Want): string {
        //返回开发者自定义的字符串，独立进程名称拼接规则：包名:开发者自定义的字符串
        return 'testKey';
      }
    }
    ```

## 模块独立进程

### 场景介绍

对于多HAP的应用，不同HAP可能承载不同的业务功能。当各HAP的业务相对独立、需要隔离运行时，开发者可以通过配置模块独立进程，使不同HAP的UIAbility运行在不同的进程中。这样可以实现业务隔离，避免一个模块的异常影响其他模块的运行。

### 约束限制

- 仅对UIAbility生效。
- 仅支持在PC/2in1和Tablet设备类型上使用。
- 配置isolationMode为isolationOnly时，该HAP中的UIAbility只会在独立进程中运行，不会在主进程中运行。

### 开发步骤

当需要将同一HAP的UIAbility运行在独立进程时，需HAP模块的[module.json5配置文件](../quick-start/module-configuration-file.md)中的[配置文件标签](../quick-start/module-configuration-file.md#配置文件标签)下添加isolationMode字段，将其配置为"isolationOnly"或"isolationFirst"。

以下示例以entry模块配置isolationOnly模式为例：

<!-- @[module_isolation_process_config](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/ModuleIsolationProcess/entry/src/main/module.json5) --> 

``` JSON5
{
  "module": {
    "name": "entry",
// ...
    "isolationMode": "isolationOnly",
// ...
    "abilities": [
// ...
    ],
    "extensionAbilities": [
// ...
    ]
  }
}
```
