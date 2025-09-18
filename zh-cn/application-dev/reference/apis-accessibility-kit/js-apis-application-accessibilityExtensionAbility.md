# @ohos.application.AccessibilityExtensionAbility (辅助功能扩展能力)

<!--Kit: Accessibility Kit-->
<!--Subsystem: BarrierFree-->
<!--Owner: @qiiiiiiian-->
<!--Designer: @z7o-->
<!--Tester: @A_qqq-->
<!--Adviser: @w_Machine_cc-->

AccessibilityExtensionAbility基于ExtensionAbility框架，提供辅助功能业务的能力。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';
```

## AccessibilityExtensionAbility

AccessibilityExtensionAbility基于ExtensionAbility框架，提供辅助功能业务的能力。

### 属性

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

| 名称      | 类型                                                                                          | 只读   | 可选   | 说明           |
| ------- |---------------------------------------------------------------------------------------------| ---- | ---- | ------------ |
| context | [AccessibilityExtensionContext](js-apis-inner-application-accessibilityExtensionContext.md) | 否    | 否    | 表示辅助扩展能力上下文。 |

## AccessibilityEvent

辅助事件信息。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Core

### 属性

| 名称      | 类型              | 只读             | 可选                      | 说明                       |
| --------- |----------------------------------------------------------------|------------------------------------------------------------------------------|------------------------------------| ------------------------------------------------------------ |
| eventType | [accessibility.EventType](js-apis-accessibility.md#eventtype) \| [accessibility.WindowUpdateType](js-apis-accessibility.md#windowupdatetype) \| [TouchGuideType](#touchguidetype) \| [GestureType](#gesturetype) \| [PageUpdateType](#pageupdatetype) | 否   | 否   | 具体事件类型。<br />EventType：无障碍事件类型；<br />WindowUpdateType：窗口变化类型；<br />TouchGuideType：触摸浏览事件类型；<br />GestureType：手势事件类型；<br />PageUpdateType：页面刷新类型。 |
| target    | [AccessibilityElement](js-apis-inner-application-accessibilityExtensionContext.md#accessibilityelement9) | 否  | 是    | 发生事件的目标组件。  |
| timeStamp | number              | 否        | 是         | 事件时间戳，单位是毫秒。默认值为0。                          |
| elementId<sup>12+</sup> | number            | 否             | 是             | 主动聚焦的组件ID。默认值为0。                 |
| textAnnouncedForAccessibility<sup>12+</sup> | string    | 否           | 是     | 主动播报的内容。当应用需要主动播报时根据实际场景设置播报内容，无特殊限制。                  |
| extraInfo<sup>20+</sup> | string    | 否           | 是     | 针对TextArea、TextInput、SearchField、RichEdit组件，当文本内容有新增或删除时，携带的文本内容。根据实际场景设置，无特殊限制。                 |


## AccessibilityElement<sup>10+</sup>

type AccessibilityElement = _AccessibilityElement

表示无障碍节点元素，请参考[AccessibilityElement](js-apis-inner-application-accessibilityExtensionContext.md#accessibilityelement9)。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

| 类型                      | 说明                     |
| ----------------------- |------------------------|
| _AccessibilityElement  | 表示无障碍节点元素，请参考[AccessibilityElement](js-apis-inner-application-accessibilityExtensionContext.md#accessibilityelement9)。 |

**示例：**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';

let accessibilityElement: AccessibilityElement;
```

## ElementAttributeValues<sup>10+</sup>

type ElementAttributeValues = _ElementAttributeValues

表示节点元素具备的属性名称及属性值类型信息，请参考[ElementAttributeValues](js-apis-inner-application-accessibilityExtensionContext.md#elementattributevalues)。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

| 类型                      | 说明                     |
| ----------------------- |------------------------|
| _ElementAttributeValues | 表示节点元素具备的属性名称及属性值类型信息，请参考[ElementAttributeValues](js-apis-inner-application-accessibilityExtensionContext.md#elementattributevalues)。 |

**示例：**

```ts
import { ElementAttributeValues } from '@kit.AccessibilityKit';

let elementAttributeValues: ElementAttributeValues;
```

## FocusDirection<sup>10+</sup>

type FocusDirection = _FocusDirection

表示查询下一焦点元素的方向，请参考[FocusDirection](js-apis-inner-application-accessibilityExtensionContext.md#focusdirection)。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

| 类型                      | 说明                     |
| ----------------------- |------------------------|
| _FocusDirection | 表示查询下一焦点元素的方向，请参考[FocusDirection](js-apis-inner-application-accessibilityExtensionContext.md#focusdirection)。 |

**示例：**

```ts
import { FocusDirection } from '@kit.AccessibilityKit';

let focusDirection: FocusDirection;
```

## ElementAttributeKeys<sup>10+</sup>

type ElementAttributeKeys = keyof ElementAttributeValues

表示[ElementAttributeValues](js-apis-inner-application-accessibilityExtensionContext.md#elementattributevalues)的属性名称。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

| 类型      |         说明             |
| ------- | -------------------------------------------------|
| keyof [ElementAttributeValues](js-apis-inner-application-accessibilityExtensionContext.md#elementattributevalues) | 表示[ElementAttributeValues](js-apis-inner-application-accessibilityExtensionContext.md#elementattributevalues)中所有属性名组成的联合类型。 |

**示例：**

```ts
import { ElementAttributeKeys } from '@kit.AccessibilityKit';

let elementAttributeKeys: ElementAttributeKeys;
```

## FocusType<sup>10+</sup>

type FocusType = _FocusType

表示查询焦点元素的类型，请参考[FocusType](js-apis-inner-application-accessibilityExtensionContext.md#focustype)。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

| 类型                      | 说明                     |
| ----------------------- |------------------------|
| _FocusType | 表示查询焦点元素的类型，请参考[FocusType](js-apis-inner-application-accessibilityExtensionContext.md#focustype)。 |

**示例：**

```ts
import { FocusType } from '@kit.AccessibilityKit';

let focusType: FocusType;
```

## WindowType <sup>10+</sup>

type WindowType = _WindowType

表示窗口的类型，请参考[WindowType](js-apis-inner-application-accessibilityExtensionContext.md#windowtype)。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

| 类型                      | 说明                     |
| ----------------------- |------------------------|
| _WindowType | 表示窗口的类型，请参考[WindowType](js-apis-inner-application-accessibilityExtensionContext.md#windowtype)。 |

**示例：**

```ts
import { WindowType } from '@kit.AccessibilityKit';

let windowType: WindowType;
```

## Rect<sup>10+</sup>

type Rect = _Rect

表示矩形区域，请参考[Rect](js-apis-inner-application-accessibilityExtensionContext.md#rect)。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

| 类型                      | 说明                     |
| ----------------------- |------------------------|
| _Rect | 表示矩形区域，请参考[Rect](js-apis-inner-application-accessibilityExtensionContext.md#rect)。 |

**示例：**

```ts
import { Rect } from '@kit.AccessibilityKit';

let rect: Rect;
```

## AccessibilityExtensionContext<sup>10+</sup>

type AccessibilityExtensionContext = _AccessibilityExtensionContext.default

表示辅助功能扩展的上下文环境，请参考[AccessibilityExtensionContext](js-apis-inner-application-accessibilityExtensionContext.md)。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

| 类型                      | 说明                     |
| ----------------------- |------------------------|
| _AccessibilityExtensionContext.default | 表示辅助功能扩展的上下文环境，请参考[AccessibilityExtensionContext](js-apis-inner-application-accessibilityExtensionContext.md)。 |

**示例：**

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';

class EntryAbility extends AccessibilityExtensionAbility {
  onConnect(): void {
    let axContext = this.context; 
  } 
}
```

## GestureType

type GestureType = 'left' | 'leftThenRight' | 'leftThenUp' | 'leftThenDown' | 'right' | 'rightThenLeft' | 'rightThenUp' | 'rightThenDown' | 'up' | 'upThenLeft' | 'upThenRight' | 'upThenDown' | 'down' | 'downThenLeft' | 'downThenRight' | 'downThenUp' | 'twoFingerSingleTap' | 'twoFingerDoubleTap' | 'twoFingerDoubleTapAndHold' | 'twoFingerTripleTap' | 'twoFingerTripleTapAndHold' | 'threeFingerSingleTap' | 'threeFingerDoubleTap' | 'threeFingerDoubleTapAndHold' | 'threeFingerTripleTap' | 'threeFingerTripleTapAndHold' | 'fourFingerSingleTap' | 'fourFingerDoubleTap' | 'fourFingerDoubleTapAndHold' | 'fourFingerTripleTap' | 'fourFingerTripleTapAndHold' | 'threeFingerSwipeUp' | 'threeFingerSwipeDown' | 'threeFingerSwipeLeft' | 'threeFingerSwipeRight' | 'fourFingerSwipeUp' | 'fourFingerSwipeDown' | 'fourFingerSwipeLeft' | 'fourFingerSwipeRight'

手势事件类型。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Core

| 类型            | 说明                  |
|------------- | ------------------- |
| 'left'            | 表示向左的手势。     |
| 'leftThenRight'   | 表示先向左再向右的手势。 |
| 'leftThenUp'      | 表示先向左再向上的手势。 |
| 'leftThenDown'    | 表示先向左再向下的手势。 |
| 'right'           | 表示向右的手势。     |
| 'rightThenLeft'   | 表示先向右再向左的手势。 |
| 'rightThenUp'     | 表示先向右再向上的手势。 |
| 'rightThenDown'   | 表示先向右再向下的手势。 |
| 'up'              | 表示向上的手势。     |
| 'upThenLeft'      | 表示先向上再向左的手势。 |
| 'upThenRight'     | 表示先向上再向右的手势。 |
| 'upThenDown'      | 表示先向上再向下的手势。 |
| 'down'            | 表示向下的手势。     |
| 'downThenLeft'    | 表示先向下再向左的手势。 |
| 'downThenRight'   | 表示先向下再向右的手势。 |
| 'downThenUp'      | 表示先向下再向上的手势。 |
| 'twoFingerSingleTap'<sup>11+</sup>           | 表示双指单击的手势。 |
| 'twoFingerDoubleTap'<sup>11+</sup>           | 表示双指双击的手势。 |
| 'twoFingerDoubleTapAndHold'<sup>11+</sup>    | 表示双指双击长按的手势。 |
| 'twoFingerTripleTap'<sup>11+</sup>           | 表示双指三击的手势。 |
| 'twoFingerTripleTapAndHold'<sup>11+</sup>    | 表示双指三击长按的手势。 |
| 'threeFingerSingleTap'<sup>11+</sup>         | 表示三指单击的手势。 |
| 'threeFingerDoubleTap'<sup>11+</sup>         | 表示三指双击的手势。 |
| 'threeFingerDoubleTapAndHold'<sup>11+</sup>  | 表示三指双击长按的手势。 |
| 'threeFingerTripleTap'<sup>11+</sup>         | 表示三指三击的手势。 |
| 'threeFingerTripleTapAndHold'<sup>11+</sup>  | 表示三指三击长按的手势。 |
| 'fourFingerSingleTap'<sup>11+</sup>          | 表示四指单击的手势。 |
| 'fourFingerDoubleTap'<sup>11+</sup>          | 表示四指双击的手势。 |
| 'fourFingerDoubleTapAndHold'<sup>11+</sup>   | 表示四指双击长按的手势。 |
| 'fourFingerTripleTap'<sup>11+</sup>          | 表示四指三击的手势。 |
| 'fourFingerTripleTapAndHold'<sup>11+</sup>   | 表示四指三击长按的手势。 |
| 'threeFingerSwipeUp'<sup>11+</sup>           | 表示三指向上滑动的手势。 |
| 'threeFingerSwipeDown'<sup>11+</sup>         | 表示三指向下滑动的手势。 |
| 'threeFingerSwipeLeft'<sup>11+</sup>         | 表示三指向左滑动的手势。 |
| 'threeFingerSwipeRight'<sup>11+</sup>        | 表示三指向右滑动的手势。 |
| 'fourFingerSwipeUp'<sup>11+</sup>            | 表示四指向上滑动的手势。 |
| 'fourFingerSwipeDown'<sup>11+</sup>          | 表示四指向下滑动的手势。 |
| 'fourFingerSwipeLeft'<sup>11+</sup>          | 表示四指向左滑动的手势。 |
| 'fourFingerSwipeRight'<sup>11+</sup>         | 表示四指向右滑动的手势。 |

## PageUpdateType

type PageUpdateType = 'pageContentUpdate' | 'pageStateUpdate'

页面刷新类型。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Core

| 类型                | 说明            |
| ----------------- | ---------------- |
| 'pageContentUpdate' | 表示页面内容刷新。 |
| 'pageStateUpdate' | 表示页面状态刷新。 |

## TouchGuideType

type TouchGuideType = 'touchBegin' | 'touchEnd'

触摸浏览事件类型。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Core

| 类型                | 说明                  |
| ---------- | ------------------- |
| 'touchBegin' | 表示触摸浏览时开始触摸。 |
| 'touchEnd' | 表示触摸浏览时结束触摸。 |

## AccessibilityExtensionAbility.onConnect<sup>(deprecated)</sup>

onConnect(): void;

用户启用AccessibilityExtensionAbility时，系统服务完成连接后，回调此接口，可以该方法中执行初始化业务逻辑操作。该方法可以选择性重写。

> **说明：**
>
> 从API version 12开始废弃。替代接口仅面向系统应用开放。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**示例：**

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';

class MyAccessibilityExtensionAbility extends AccessibilityExtensionAbility {
  onConnect(): void {
    console.log('AxExtensionAbility onConnect');
  }
}
```

## AccessibilityExtensionAbility.onDisconnect<sup>(deprecated)</sup>

onDisconnect(): void;

用户停用AccessibilityExtensionAbility时，系统服务完成断开连接后，回调此接口，可以该方法中执行资源回收退出业务逻辑操作。该方法可以选择性重写。

> **说明：**
>
> 从API version 12开始废弃。替代接口仅面向系统应用开放。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**示例：**

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';

class MyAccessibilityExtensionAbility extends AccessibilityExtensionAbility {
  onDisconnect(): void {
    console.log('AxExtensionAbility onDisconnect');
  }
}
```

## AccessibilityExtensionAbility.onAccessibilityEvent<sup>(deprecated)</sup>

onAccessibilityEvent(event: AccessibilityEvent): void;

在关注的应用及事件类型对应的事件发生时回调此接口，可以在该方法中根据事件信息进行业务逻辑处理。一般情况下需要重写该方法完成业务。

> **说明：**
>
> 从API version 12开始废弃。替代接口仅面向系统应用开放。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名   | 类型                                       | 必填   | 说明              |
| ----- | ---------------------------------------- | ---- | --------------- |
| event | [AccessibilityEvent](#accessibilityevent) | 是    | 无障碍事件。无返回值。 |

**示例：**

```ts
import { AccessibilityExtensionAbility, AccessibilityEvent } from '@kit.AccessibilityKit';

class MyAccessibilityExtensionAbility extends AccessibilityExtensionAbility {
  onAccessibilityEvent(event: AccessibilityEvent): void {
    console.log('AxExtensionAbility onAccessibilityEvent');
    if (event.eventType === 'click') {
      console.log('AxExtensionAbility onAccessibilityEvent: click');
    }
  }
}
```

## AccessibilityExtensionAbility.onKeyEvent<sup>(deprecated)</sup>

onKeyEvent(keyEvent: KeyEvent): boolean;

在物理按键按下时回调此方法，可以在该方法中根据业务判断是否对事件进行拦截。

> **说明：**
>
> 从API version 12开始废弃。替代接口仅面向系统应用开放。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名      | 类型                                               | 必填   | 说明                      |
| -------- |--------------------------------------------------| ---- | ----------------------- |
| keyEvent | [KeyEvent](../apis-input-kit/js-apis-keyevent.md#keyevent) | 是    | 按键事件回调函数。返回true表示拦截此按键。|

**返回值：**
| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回true表示此事件被消费，不会继续传递。<br>返回false表示些事件未被消费，会继续传递。|

**示例：**

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';
import { KeyEvent } from '@kit.InputKit';

class MyAccessibilityExtensionAbility extends AccessibilityExtensionAbility {
  onKeyEvent(keyEvent: KeyEvent): boolean {
    console.log('AxExtensionAbility onKeyEvent');
    if (keyEvent.key.code === 16) {
      console.log('AxExtensionAbility onKeyEvent: intercept 16');
      return true;
    }
    return false;
  }
}
```
