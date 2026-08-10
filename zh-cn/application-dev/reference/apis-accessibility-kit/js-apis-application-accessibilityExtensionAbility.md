# @ohos.application.AccessibilityExtensionAbility (辅助功能扩展能力)

<!--Kit: Accessibility Kit-->
<!--Subsystem: BarrierFree-->
<!--Owner: @qiiiiiiian-->
<!--Designer: @z7o-->
<!--Tester: @A_qqq-->
<!--Adviser: @w_Machine_cc-->

AccessibilityExtensionAbility基于ExtensionAbility框架，提供辅助功能扩展业务的能力。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';
```

## AccessibilityEvent

无障碍事件信息。无障碍事件由系统无障碍服务在用户操作或界面变化时生成，通过eventType标识事件类别（包括无障碍事件类型、窗口变化类型、触摸浏览事件类型、手势事件类型、页面更新类型），辅助功能扩展可通过onAccessibilityEvent回调接收并处理这些事件。

### 属性

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

| 名称      | 类型              | 只读             | 可选                      | 说明                       |
| --------- |----------------------------------------------------------------|------------------------------------------------------------------------------|------------------------------------| ------------------------------------------------------------ |
| eventType | [accessibility.EventType](js-apis-accessibility.md#eventtype) \| [accessibility.WindowUpdateType](js-apis-accessibility.md#windowupdatetype) \| [TouchGuideType](#touchguidetype) \| [GestureType](#gesturetype) \| [PageUpdateType](#pageupdatetype) | 否   | 否   | 具体事件类型，用于标识当前无障碍事件的类别。<br>EventType：无障碍事件类型；<br>WindowUpdateType：窗口变化类型；<br>TouchGuideType：触摸浏览事件类型；<br>GestureType：手势事件类型；<br>PageUpdateType：页面更新类型。 |
| target    | [AccessibilityElement](js-apis-inner-application-accessibilityExtensionContext.md#accessibilityelement) | 否  | 是    | 发生事件的目标元素。当无障碍事件涉及具体元素时，此属性包含该元素信息。  |
| timeStamp | number              | 否        | 是         | 事件时间戳，取值范围为非负整数，单位为毫秒，默认值为0。                          |
| elementId<sup>12+</sup> | number            | 否             | 是             | 主动聚焦的元素ID。主动聚焦指应用通过无障碍服务主动将焦点聚焦到指定元素上，与用户手动导航聚焦不同。默认值为0。                 |
| textAnnouncedForAccessibility<sup>12+</sup> | string    | 否           | 是     | 主动播报的内容。当应用需要主动播报时根据实际场景设置播报内容，无特殊限制，默认为空字符串。                  |
| extraInfo<sup>20+</sup> | string    | 否           | 是     | 针对TextArea、TextInput、SearchField、RichEdit组件，当文本内容有新增或删除时，携带新增或删除的文本内容。根据实际场景设置，无特殊限制，默认为空字符串。                 |


## AccessibilityElement<sup>10+</sup>

type AccessibilityElement = _AccessibilityElement

表示无障碍节点元素，请参考[AccessibilityElement](js-apis-inner-application-accessibilityExtensionContext.md#accessibilityelement)。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

| 类型                      | 说明                     |
| ----------------------- |------------------------|
| _AccessibilityElement  | 表示无障碍节点元素，请参考[AccessibilityElement](js-apis-inner-application-accessibilityExtensionContext.md#accessibilityelement)。 |

**示例：**

```ts
import { AccessibilityElement } from '@kit.AccessibilityKit';

let accessibilityElement: AccessibilityElement;
```

## ElementAttributeValues<sup>10+</sup>

type ElementAttributeValues = _ElementAttributeValues

表示节点元素具备的属性名称及属性值类型信息，请参考[ElementAttributeValues](js-apis-inner-application-accessibilityExtensionContext.md#elementattributevalues)。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

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

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

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

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

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

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

| 类型                      | 说明                     |
| ----------------------- |------------------------|
| _FocusType | 表示查询焦点元素的类型，请参考[FocusType](js-apis-inner-application-accessibilityExtensionContext.md#focustype)。 |

**示例：**

```ts
import { FocusType } from '@kit.AccessibilityKit';

let focusType: FocusType;
```

## WindowType<sup>10+</sup>

type WindowType = _WindowType

表示窗口的类型，请参考[WindowType](js-apis-inner-application-accessibilityExtensionContext.md#windowtype)。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

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

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

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

表示辅助功能扩展的上下文环境，请参考[AccessibilityExtensionContext](js-apis-inner-application-accessibilityExtensionContext.md#accessibilityextensioncontext)。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

| 类型                      | 说明                     |
| ----------------------- |------------------------|
| _AccessibilityExtensionContext.default | 表示辅助功能扩展的上下文环境，请参考[AccessibilityExtensionContext](js-apis-inner-application-accessibilityExtensionContext.md#accessibilityextensioncontext)。 |

**示例：**

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';

class EntryAbility extends AccessibilityExtensionAbility {
  onConnect(): void {
    let accessibilityContext = this.context;
  } 
}
```

## GestureType

type GestureType = 'left' | 'leftThenRight' | 'leftThenUp' | 'leftThenDown' | 'right' | 'rightThenLeft' | 'rightThenUp' | 'rightThenDown' | 'up' | 'upThenLeft' | 'upThenRight' | 'upThenDown' | 'down' | 'downThenLeft' | 'downThenRight' | 'downThenUp' | 'twoFingerSingleTap' | 'twoFingerDoubleTap' | 'twoFingerDoubleTapAndHold' | 'twoFingerTripleTap' | 'twoFingerTripleTapAndHold' | 'threeFingerSingleTap' | 'threeFingerDoubleTap' | 'threeFingerDoubleTapAndHold' | 'threeFingerTripleTap' | 'threeFingerTripleTapAndHold' | 'fourFingerSingleTap' | 'fourFingerDoubleTap' | 'fourFingerDoubleTapAndHold' | 'fourFingerTripleTap' | 'fourFingerTripleTapAndHold' | 'threeFingerSwipeUp' | 'threeFingerSwipeDown' | 'threeFingerSwipeLeft' | 'threeFingerSwipeRight' | 'fourFingerSwipeUp' | 'fourFingerSwipeDown' | 'fourFingerSwipeLeft' | 'fourFingerSwipeRight' | 'oneFingerDoubleTap'

手势事件类型。手势事件在用户执行特定手势操作时由无障碍服务触发，辅助功能扩展可通过onAccessibilityEvent回调接收并处理对应的手势事件。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

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
| 'oneFingerDoubleTap'         | 表示单指双击的手势。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。 |

## PageUpdateType

type PageUpdateType = 'pageContentUpdate' | 'pageStateUpdate'

页面更新类型。页面更新事件在页面内容或状态发生变化时由无障碍服务触发，辅助功能扩展可通过onAccessibilityEvent回调接收并处理对应的页面更新事件。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

| 类型                | 说明            |
| ----------------- | ---------------- |
| 'pageContentUpdate' | 表示页面内容更新。 |
| 'pageStateUpdate' | 表示页面状态更新。 |

## TouchGuideType

type TouchGuideType = 'touchBegin' | 'touchEnd' | 'touchGuideGesture'

触摸浏览事件类型。触摸浏览是无障碍辅助功能中的一种交互模式，用户在该模式下通过触摸探索界面元素而非直接激活。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

| 类型                | 说明                  |
| ---------- | ------------------- |
| 'touchBegin' | 表示触摸浏览时开始触摸。 |
| 'touchEnd' | 表示触摸浏览时结束触摸。 |
| 'touchGuideGesture' | 表示触摸浏览手势。 <br>**起始版本：** 26.0.0|

## AccessibilityExtensionAbility

AccessibilityExtensionAbility基于ExtensionAbility框架，提供辅助功能扩展业务的能力。

### 属性

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

| 名称      | 类型                                                                                          | 只读   | 可选   | 说明           |
| ------- |---------------------------------------------------------------------------------------------| ---- | ---- | ------------ |
| context | [AccessibilityExtensionContext](js-apis-inner-application-accessibilityExtensionContext.md#accessibilityextensioncontext) | 否    | 否    | 表示辅助功能扩展的上下文环境。 |

### onConnect<sup>(deprecated)</sup>

onConnect(): void

用户启用AccessibilityExtensionAbility时，系统服务完成连接后回调此接口，可在该方法中执行初始化业务逻辑操作。该方法可选择性重写。

> **说明：**
>
> 从API version 9开始支持，从API version 12开始废弃。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**示例：**

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';

class MyAccessibilityExtensionAbility extends AccessibilityExtensionAbility {
  onConnect(): void {
    console.info('AxExtensionAbility onConnect');
  }
}
```

### onDisconnect<sup>(deprecated)</sup>

onDisconnect(): void

用户停用AccessibilityExtensionAbility时，系统服务完成断开连接后回调此接口，可在该方法中执行资源回收和退出业务操作。该方法可选择性重写。

> **说明：**
>
> 从API version 9开始支持，从API version 12开始废弃。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**示例：**

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';

class MyAccessibilityExtensionAbility extends AccessibilityExtensionAbility {
  onDisconnect(): void {
    console.info('AxExtensionAbility onDisconnect');
  }
}
```

### onAccessibilityEvent<sup>(deprecated)</sup>

onAccessibilityEvent(event: AccessibilityEvent): void

当无障碍事件发生时回调此接口，可在该方法中根据事件信息进行业务逻辑处理。通常需要重写该方法。

> **说明：**
>
> 从API version 9开始支持，从API version 12开始废弃。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名   | 类型                                       | 必填   | 说明              |
| ----- | ---------------------------------------- | ---- | --------------- |
| event | [AccessibilityEvent](#accessibilityevent) | 是    | 无障碍事件信息。 |

**示例：**

```ts
import { AccessibilityExtensionAbility, AccessibilityEvent } from '@kit.AccessibilityKit';

class MyAccessibilityExtensionAbility extends AccessibilityExtensionAbility {
  onAccessibilityEvent(event: AccessibilityEvent): void {
    console.info('AxExtensionAbility onAccessibilityEvent');
    if (event.eventType === 'click') {
      console.info('AxExtensionAbility onAccessibilityEvent: click');
    }
  }
}
```

### onKeyEvent<sup>(deprecated)</sup>

onKeyEvent(keyEvent: KeyEvent): boolean

在按键按下时回调此接口，可在该方法中根据业务判断是否消费事件。该方法可选择性重写。

> **说明：**
>
> 从API version 9开始支持，从API version 12开始废弃。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名      | 类型                                               | 必填   | 说明                      |
| -------- |--------------------------------------------------| ---- | ----------------------- |
| keyEvent | [KeyEvent](../apis-input-kit/js-apis-keyevent.md#keyevent) | 是    | 按键事件。|

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回true表示此事件被消费，不会继续传递。<br>返回false表示此事件未被消费，会继续传递。|

**示例：**

```ts
import { AccessibilityExtensionAbility } from '@kit.AccessibilityKit';
import { KeyEvent } from '@kit.InputKit';

class MyAccessibilityExtensionAbility extends AccessibilityExtensionAbility {
  onKeyEvent(keyEvent: KeyEvent): boolean {
    console.info('AxExtensionAbility onKeyEvent');
    if (keyEvent.key.code === 16) {
      console.info('AxExtensionAbility onKeyEvent: intercept 16');
      return true;
    }
    return false;
  }
}
```
