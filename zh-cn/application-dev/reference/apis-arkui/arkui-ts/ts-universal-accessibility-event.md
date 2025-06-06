# 无障碍事件

在开启无障碍模式后，需要判断是否拦截无障碍事件。

>**说明：**
>
>  - 本模块首批接口从API version 18开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。
>  - 目前仅支持通过开启无障碍模式触发。

## onAccessibilityFocus

onAccessibilityFocus(callback: AccessibilityFocusCallback): T

设置无障碍节点获焦、失焦状态的回调函数。当状态发生变化时，触发回调函数。

**卡片能力：** 从API version 18开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型    | 必填 | 说明                                                         |
| -------- | ------- | ---- | ------------------------------------------------------------ |
| callback | [AccessibilityFocusCallback](ts-universal-accessibility-event.md#AccessibilityFocusCallback) | 是   | 向注册回调函数方通知当前获焦、失焦状态。 |

**返回值：**

| 类型    | 说明              |
| ------ | ---------------- |
| T | 返回当前组件。 |

## AccessibilityFocusCallback

type AccessibilityFocusCallback = (isFocus: boolean) => void

定义onAccessibilityFocus中使用的回调类型。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型    | 必填 | 说明              |
| ------ | ------ | ---- | ---------------- |
| isFocus | boolean | 是 | 用于表示组件是否获焦。<br/>true：当前组件获焦。<br/>false：当前组件失焦。|

## onAccessibilityActionIntercept<sup>20+</sup>

onAccessibilityActionIntercept(callback: AccessibilityActionInterceptCallback): T

该接口在无障碍模式下，可在无障碍事件触发前通知注册的回调函数，由注册方决定是否拦截该次无障碍事件。

**卡片能力：** 从API version 20开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型    | 必填 | 说明                                                         |
| -------- | ------- | ---- | ------------------------------------------------------------ |
| callback | [AccessibilityActionInterceptCallback](ts-universal-accessibility-event.md#accessibilityactioninterceptcallback) | 是   | 在无障碍事件触发前，向注册回调函数方通知，由注册方决定是否拦截该次无障碍事件。 |

**返回值：**

| 类型    | 说明              |
| ------ | ---------------- |
| T | 返回当前组件。 |

## AccessibilityActionInterceptCallback<sup>20+</sup>

type AccessibilityActionInterceptCallback = (action: AccessibilityAction) => AccessibilityActionInterceptResult

提供onAccessibilityActionIntercept中使用的回调函数参数类型。

**卡片能力：** 从API version 20开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型    | 必填 | 说明              |
| ------ | ------ | ---- | ---------------- |
| action | [AccessibilityAction](ts-universal-accessibility-event.md#accessibilityaction枚举说明) | 是 | 当前触发的无障碍事件类型。 |

**返回值：**

| 类型    | 说明              |
| ------ | ---------------- |
| [AccessibilityActionInterceptResult](ts-universal-accessibility-event.md#accessibilityactioninterceptresult枚举说明) | 无障碍事件拦截结果。 |

## AccessibilityAction<sup>20+</sup>枚举说明

定义组件当前触发的无障碍事件类型。

**卡片能力：** 从API version 20开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值  | 说明             |
| ---- | ---- | ------------------ |
| UNDEFINED_ACTION | 0 | 未定义的无障碍事件。 |
| ACCESSIBILITY_CLICK | 1 | 无障碍点击事件。 |

## AccessibilityActionInterceptResult<sup>20+</sup>枚举说明

定义AccessibilityActionInterceptCallback的无障碍事件拦截结果。

**卡片能力：** 从API version 20开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值  | 说明             |
| ---- | ---- | ------------------ |
| ACTION_INTERCEPT | 0 | 拦截当前组件接收的无障碍事件。 |
| ACTION_CONTINUE | 1 | 继续执行当前组件接收的无障碍事件。 |
| ACTION_RISE | 2 | 判断本组件当前接收的无障碍事件是否拦截并冒泡查询有onAccessibilityActionIntercept注册的祖先组件并执行其回调，以祖先组件的返回值，来确定本组件的拦截结果。如果祖先组件的拦截结果仍然是ACTION_RISE，则继续冒泡查询和执行。 |

## 示例

该示例主要演示通过使用onAccessibilityActionIntercept事件实现Toggle组件在无障碍模式下于点击事件发生之前拦截点击事件并确认是否拦截该点击事件的操作。

```ts
// xxx.ets
@Entry
@Component
struct SwitchBootcamp {
  @State private isOn: boolean = false;
  isPolygon(event: TouchEvent) {
    return true;
  }

  build() {
    NavDestination() {
      Column() {
        Text('onTouchIntercept')
        Row() {
          Text('Label message')
          Blank()
          Toggle({ type: ToggleType.Switch, isOn: $$this.isOn })
            .onAccessibilityActionIntercept((action : AccessibilityAction) => {
              if (action === AccessibilityAction.ACCESSIBILITY_CLICK) {
                this.getUIContext().showAlertDialog({
                  title: '标题',
                  message: '内容信息',
                  primaryButton: {
                    value: '确认',
                    action: () => {
                      this.isOn = !this.isOn;
                    }
                  },
                  secondaryButton: {
                    value: '取消',
                    action: () => {
                    }
                  }
                })
                return AccessibilityActionInterceptResult.ACTION_INTERCEPT;
              } else {
                return AccessibilityActionInterceptResult.ACTION_CONTINUE;
              }
            })
        }.width('100%')
      }
      .padding(24)
      .width('100%')
    }
  }
}
```