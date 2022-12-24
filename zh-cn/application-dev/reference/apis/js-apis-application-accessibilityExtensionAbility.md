# @ohos.application.AccessibilityExtensionAbility (辅助功能扩展能力)

**AccessibilityExtensionAbility**基于ExtensionAbility框架，提供辅助功能业务的能力。

> **说明：**
>
> 本模块首批接口从API version 9开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import AccessibilityExtensionAbility from '@ohos.application.AccessibilityExtensionAbility'
```

## 属性

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

| 名称      | 类型 | 可读 | 可写 | 说明                      |
| --------- | -------- | ---- | ---- | ------------------------- |
| context | [AccessibilityExtensionContext](js-apis-inner-application-accessibilityExtensionContext.md) | 是 | 否 | 表示辅助扩展能力上下文。 |

## AccessibilityEvent

辅助事件信息。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Core

### 属性

| 名称        | 类型                                     | 可读   | 可写   | 说明         |
| --------- | ---------------------------------------- | ---- | ---- | ---------- |
| eventType | [accessibility.EventType](js-apis-accessibility.md#EventType) \| [accessibility.WindowUpdateType](js-apis-accessibility.md#WindowUpdateType) \| [TouchGuideType](#touchguidetype) \| [GestureType](#gesturetype) \| [PageUpdateType](#pageupdatetype) | 是    | 否    | 具体事件类型。    |
| target    | [AccessibilityElement](js-apis-inner-application-accessibilityExtensionContext.md#accessibilityelementsup9sup)                     | 是    | 否    | 发生事件的目标组件。 |
| timeStamp | number                                   | 是    | 否    | 事件时间戳。     |

## GestureType

手势事件类型。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Core

| 名称            | 描述           |
| ------------- | ------------ |
| left          | 表示向左的手势。     |
| leftThenRight | 表示先向左再向右的手势。 |
| leftThenUp    | 表示先向左再向上的手势。 |
| leftThenDown  | 表示先向左再向下的手势。 |
| right         | 表示向右的手势。     |
| rightThenLeft | 表示先向右再向左的手势。 |
| rightThenUp   | 表示先向右再向上的手势。 |
| rightThenDown | 表示先向右再向下的手势。 |
| up            | 表示向上的手势。     |
| upThenLeft    | 表示先向上再向左的手势。 |
| upThenRight   | 表示先向上再向右的手势。 |
| upThenDown    | 表示先向上再向下的手势。 |
| down          | 表示向下的手势。     |
| downThenLeft  | 表示先向下再向左的手势。 |
| downThenRight | 表示先向下再向右的手势。 |
| downThenUp    | 表示先向下再向上的手势。 |

## PageUpdateType

页面刷新类型。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Core

| 名称                | 描述        |
| ----------------- | --------- |
| pageContentUpdate | 表示页面内容刷新。 |
| pageStateUpdate   | 表示页面状态刷新。 |

## TouchGuideType

触摸浏览事件类型。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Core

| 名称         | 描述           |
| ---------- | ------------ |
| touchBegin | 表示触摸浏览时开始触摸。 |
| touchEnd   | 表示触摸浏览时结束触摸。 |

## AccessibilityExtensionAbility.onConnect

onConnect(): void;

用户启用AccessibilityExtensionAbility时，系统服务完成连接后，回调此接口，可以该方法中执行初始化业务逻辑操作。该方法可以选择性重写。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**示例：**

```ts
class MyAccessibilityExtensionAbility extends AccessibilityExtensionAbility {
    onConnect() {
        console.log('AxExtensionAbility onConnect');
    }
};
```

## AccessibilityExtensionAbility.onDisconnect

onDisconnect(): void;

用户停用AccessibilityExtensionAbility时，系统服务完成断开连接后，回调此接口，可以该方法中执行资源回收退出业务逻辑操作。该方法可以选择性重写。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**示例：**

```ts
class MyAccessibilityExtensionAbility extends AccessibilityExtensionAbility {
    onDisconnect() {
        console.log('AxExtensionAbility onDisconnect');
    }
};
```

## AccessibilityExtensionAbility.onAccessibilityEvent

onAccessibilityEvent(event: AccessibilityEvent): void;

在关注的应用及事件类型对应的事件发生时回调此接口，可以在该方法中根据事件信息进行业务逻辑处理。一般情况下需要重写该方法完成业务。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名   | 类型                                     | 必填   | 说明              |
| ----- | ---------------------------------------- | ---- | --------------- |
| event | [AccessibilityEvent](#accessibilityevent) | 是    | 无障碍事件回调函数。无返回值。 |

**示例：**

```ts
class MyAccessibilityExtensionAbility extends AccessibilityExtensionAbility {
    onAccessibilityEvent(event) {
        console.log('AxExtensionAbility onAccessibilityEvent');
        if (event.eventType == 'click') {
            console.log('AxExtensionAbility onAccessibilityEvent: click');
        }
    }
};
```

## AccessibilityExtensionAbility.onKeyEvent

onKeyEvent(keyEvent: KeyEvent): boolean;

在物理按键按下时回调此方法，可以在该方法中根据业务判断是否对事件进行拦截。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名      | 类型                                     | 必填   | 说明                      |
| -------- | ---------------------------------------- | ---- | ----------------------- |
| keyEvent | [KeyEvent](js-apis-keyevent.md#KeyEvent) | 是    | 按键事件回调函数。返回true表示拦截此按键。 |

**示例：**

```ts
class MyAccessibilityExtensionAbility extends AccessibilityExtensionAbility {
    onKeyEvent(keyEvent) {
        console.log('AxExtensionAbility onKeyEvent');
        if (keyEvent.keyCode == 22) {
            console.log('AxExtensionAbility onKeyEvent: intercept 22');
            return true;
        }
        return false;
    }
};
```
