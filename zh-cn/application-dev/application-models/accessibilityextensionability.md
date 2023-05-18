# AccessibilityExtensionAbility开发指南

AccessibilityExtensionAbility基于ExtensionAbility框架，提供无障碍扩展服务，开发者可以基于AccessibilityExtensionAbility模板开发自己的辅助功能应用，协助用户完成一些快捷的交互过程。

> **环境要求**
>
> IDE: DevEco Studio 3.0 Beta3 (3.0.0.900)及以后版本
>
> SDK: API Version 9 及以后版本
>
> Model: Stage

本文档将从以下场景来介绍AccessibilityExtensionAbility的基本开发：

- [如何创建一个无障碍扩展服务](#如何创建一个无障碍扩展服务)
- [如何处理一个无障碍事件](#如何处理一个无障碍事件)
- [如何声明无障碍扩展服务具备的能力](#如何声明无障碍扩展服务具备的能力)
- [如何开启自定义的无障碍扩展服务](#如何开启自定义的无障碍扩展服务)
- [相关示例](#相关示例)

## 如何创建一个无障碍扩展服务

开发者在创建一个无障碍扩展服务时，如工程满足环境要求，开发者可自主选择是否跳过创建工程步骤，在已有工程中新增无障碍扩展服务。

### 创建工程

如需新增独立的无障碍扩展服务应用，可按以下步骤进行。在DevEco Studio中新建一个工程，具体步骤如下：
1. 在DevEco Studio的左上角标签栏，选择`File -> New -> Create Project`新建一个工程；
2. 根据工程创建向导，选择`OpenHarmony`标签页，选择`Empty Ability`模板，点击Next，进入项目详细配置页；
3. 选择项目类型为Application，Compile API（高版本为Compile SDK）为9，Model为`Stage`，然后点击Finish完成工程创建。

### 新建AccessibilityExtAbility文件

在已创建工程的ets文件夹下创建AccessibilityExtAbility文件夹，在该文件夹下创建AccessibilityExtAbility.ts文件，在新增的文件中加入以下代码：

```typescript
import AccessibilityExtensionAbility from '@ohos.application.AccessibilityExtensionAbility';

class AccessibilityExtAbility extends AccessibilityExtensionAbility {
    onConnect() {
        console.info('AccessibilityExtAbility onConnect');
    }

    onDisconnect() {
        console.info('AccessibilityExtAbility onDisconnect');
    }

    onAccessibilityEvent(accessibilityEvent) {
        console.info('AccessibilityExtAbility onAccessibilityEvent: ' + JSON.stringify(accessibilityEvent));
    }
}

export default AccessibilityExtAbility;
```

其中，主要定义了以下接口：

| 接口 | 描述 |
| ---- | ---- |
| onConnect(): void | 当扩展服务连接时回调 |
| onDisconnect(): void | 当扩展服务断开时回调 |
| onAccessibilityEvent(event: AccessibilityEvent): void | 当无障碍事件发生时回调 |

## 如何处理一个无障碍事件

相关无障碍事件可以在`onAccessibilityEvent()`方法中进行业务逻辑处理，具体事件可参考[AccessibilityEvent](../reference/apis/js-apis-application-accessibilityExtensionAbility.md#accessibilityevent)。此处以事件`pageStateUpdate`为例：

```typescript
onAccessibilityEvent(accessibilityEvent) {
    console.info('AccessibilityExtAbility onAccessibilityEvent: ' + JSON.stringify(accessibilityEvent));
    if (accessibilityEvent.eventType === 'pageStateUpdate') {
        console.info('AccessibilityExtAbility onAccessibilityEvent: pageStateUpdate');
        // TODO: 自定义相关逻辑开发
    }
}
```
在相应的无障碍事件中，可以使用[辅助功能扩展上下文（AccessibilityExtensionContext）](../reference/apis/js-apis-inner-application-accessibilityExtensionContext.md)提供的接口进行扩展开发，包括允许配置辅助应用关注信息类型、查询节点信息、手势注入等。

此外，还可在无障碍扩展服务中对物理按键事件进行处理，具体可参考[onKeyEvent](../reference/apis/js-apis-application-accessibilityExtensionAbility.md#accessibilityextensionabilityonkeyevent)。

## 如何声明无障碍扩展服务具备的能力

在完成自定义无障碍扩展服务的逻辑开发后，还需要在工程中Module对应的module.json5文件中加入新增扩展服务的配置信息，其中`srcEntry`标签为`extensionAbility`对应的路径。需要注意的一点是配置信息中的type标签要按照与无障碍子系统的约定进行配置，固定为`accessibility`，否则将无法正常连接。

```json
"extensionAbilities": [
  {
    "name": "AccessibilityExtAbility",
    "srcEntry": "./ets/AccessibilityExtAbility/AccessibilityExtAbility.ts",
    "label": "$string:MainAbility_label",
    "description": "$string:MainAbility_desc",
    "type": "accessibility",
    "metadata": [
      {
        "name": "ohos.accessibleability",
        "resource": "$profile:accessibility_config"
      }
    ]
  }
]
```
另外，配置信息中的`accessibility_config`为无障碍扩展服务的具体配置，需要在`resources/base/profile/`下新建`accessibility_config.json`文件，在该文件中声明此无障碍扩展服务具备的[能力类型](../reference/apis/js-apis-accessibility.md#capability):
```json
{
  "accessibilityCapabilities": [
    "retrieve",
    "gesture"
  ]
}
```
## 如何开启自定义的无障碍扩展服务

目前设置中尚未开放无障碍扩展服务开启关闭功能，需要使用命令行进行开启关闭。
- 开启命令：`accessibility enable -a AccessibilityExtAbility -b com.example.demo -c rg`
- 关闭命令：`accessibility disable -a AccessibilityExtAbility -b com.example.demo`

其中，`AccessibilityExtAbility`为自定义的无障碍扩展服务名，`com.example.demo`为bundleName，`rg`为无障碍扩展服务具体的类型（其中，r为`retrieve`的首字母，其余同理）。

若开启或关闭成功，则会打印`enable ability successfully`或`disable ability successfully`。

## 相关示例

针对AccessibilityExtensionAbility开发，有以下相关示例可供参考：

[AccessibilityExtAbility的创建和使用（ArkTS）（API 9）（Full SDK）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/ApplicationModels/AccessibilityExtAbility)

