# @ohos.application.AccessibilityExtensionAbility (辅助功能扩展能力)(系统接口)

AccessibilityExtensionAbility基于ExtensionAbility框架，提供辅助功能业务的能力，能力包括成功连接无障碍服务、断开无障碍服务、处理无障碍服务事件和无障碍按键事件等。

> **说明：**
>
> - 本模块首批接口从API version 20开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口。其他公开接口参见[@ohos.application.AccessibilityExtensionAbility](js-apis-application-accessibilityExtensionAbility.md)。

## 导入模块

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';
```
## AccessibilityEventInfo

无障碍事件信息。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Core

### 属性

| 名称                            | 类型                                       | 只读   | 可选   | 说明                                       |
| ----------------------------- | ---------------------------------------- | ---- | ---- | ---------------------------------------- |
| eventType                     | [AccessibilityEventType](./js-apis-accessibility-sys.md#accessibilityeventtype) | 否    | 否    | 无障碍事件类型。                                 |
| target                        | [AccessibilityElement](js-apis-inner-application-accessibilityExtensionContext-sys.md#accessibilityelement12) | 否    | 是    | 发生事件的目标组件。                               |
| timeStamp                     | number                                   | 否    | 是    | 事件时间戳，单位是毫秒。默认值为0。                       |
| extraInfo                     | string                                   | 否    | 是    | 针对TextArea、TextInput、SearchField、RichEdit组件， 组件文本内容有新增或删除时，新增或删除的文本内容。 |


## AccessibilityExtensionAbility.onAccessibilityConnect

onAccessibilityConnect(): void;

连接无障碍服务成功后的回调函数。
用户启用AccessibilityExtensionAbility时，系统服务完成连接后回调该接口，在该方法中完成初始化业务逻辑操作。 该方法可以选择性重写。 无障碍服务通过该回调，通知Ability已成功连接。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**示例：**

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';

class MyAccessibilityExtensionAbility extends AccessibilityExtensionAbility {
  onAccessibilityConnect(): void {
    console.log('AxExtensionAbility onAccessibilityConnect');
  }
}
```

## AccessibilityExtensionAbility.onAccessibilityDisconnect

onAccessibilityDisconnect(): void;

断开无障碍服务成功后的回调函数。
用户停用AccessibilityExtensionAbility时，系统服务完成断开连接后回调该接口，在该方法中执行资源回收和退出业务操作。该方法可以选择性重写。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**示例：**

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';

class MyAccessibilityExtensionAbility extends AccessibilityExtensionAbility {
  onAccessibilityDisconnect(): void {
    console.log('AxExtensionAbility onAccessibilityDisconnect');
  }
}
```

## AccessibilityExtensionAbility.onAccessibilityEventInfo

onAccessibilityEventInfo(event: AccessibilityEventInfo): void;

在应用和事件发生时回调该接口，根据事件信息处理业务逻辑。通常需要重写。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名   | 类型                                       | 必填   | 说明    |
| ----- | ---------------------------------------- | ---- | ----- |
| event | [AccessibilityEventInfo](#accessibilityeventinfo) | 是    | 无障碍事件 |

**示例：**

```ts
import { AccessibilityExtensionAbility, AccessibilityEventInfo, AccessibilityEventType } from '@kit.AccessibilityKit';

class MyAccessibilityExtensionAbility extends AccessibilityExtensionAbility {
  onAccessibilityEventInfo(event: AccessibilityEventInfo): void {
    console.log('AxExtensionAbility onAccessibilityEventInfo');
    if (event.eventType === AccessibilityEventType.TYPE_CLICK) {
      console.log('AxExtensionAbility onAccessibilityEventInfo: click');
    }
  }
}
```

## AccessibilityExtensionAbility.onAccessibilityKeyEvent

onAccessibilityKeyEvent(keyEvent: KeyEvent): boolean;

在物理按键按下时回调该方法，在该方法中根据业务判断是否消费事件。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明   |
| -------- | ---------------------------------------- | ---- | ---- |
| keyEvent | [KeyEvent](../apis-input-kit/js-apis-keyevent.md#keyevent) | 是    | 按键事件。 |

**返回值：**
| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回true表示此事件被消费，不会继续传递。<br>返回false表示些事件未被消费，会继续传递。|


**示例：**

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';
import { KeyEvent, KeyCode } from '@kit.InputKit';

class MyAccessibilityExtensionAbility extends AccessibilityExtensionAbility {
  onAccessibilityKeyEvent(keyEvent: KeyEvent): boolean {
    console.log('AxExtensionAbility onAccessibilityKeyEvent');
    if (keyEvent.key.code === KeyCode.KEYCODE_VOLUME_UP) {
      console.log('AxExtensionAbility onAccessibilityKeyEvent: intercept 16');
      return true;
    }
    return false;
  }
}
```