# 无障碍控制操作
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wangyinhua-->
<!--Designer: @dutie123-->
<!--Tester: @fredyuan0912-->
<!--Adviser: @Brilliantry_Rui-->

在开启无障碍模式后，本模块提供无障碍控制操作拦截和无障碍节点获焦/失焦状态监听能力。开发者可通过onAccessibilityFocus监听组件的获焦与失焦状态变化，通过onAccessibilityActionIntercept在无障碍控制操作触发前进行拦截判断，适用于需要在无障碍模式下自定义组件交互逻辑的场景。

> **说明：**
>
> - 本模块首批接口从API version 18开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口仅可在Stage模型下使用。
>
> - 目前仅支持通过开启无障碍模式触发。

## onAccessibilityFocus

onAccessibilityFocus(callback: AccessibilityFocusCallback): T

该接口在无障碍模式下，设置无障碍节点获焦、失焦状态的回调函数。当无障碍焦点移入或移出当前组件，导致获焦、失焦状态发生变化时，触发回调函数。

**卡片能力：** 从API version 18开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型    | 必填 | 说明                                                         |
| -------- | ------- | ---- | ------------------------------------------------------------ |
| callback | [AccessibilityFocusCallback](#accessibilityfocuscallback) | 是   | 在无障碍模式下，当组件获焦、失焦状态发生变化时，向注册方通知当前状态。入参设置undefined时取消回调注册。 |

**返回值：**

| 类型    | 说明              |
| ------ | ---------------- |
| T | 返回当前组件。 |

## AccessibilityFocusCallback

type AccessibilityFocusCallback = (isFocus: boolean) => void

定义onAccessibilityFocus中使用的回调类型。

**卡片能力：** 从API version 18开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型    | 必填 | 说明              |
| ------ | ------ | ---- | ---------------- |
| isFocus | boolean | 是 | 用于表示组件是否获焦。<br>true：当前组件获焦。<br>false：当前组件失焦。|

## onAccessibilityActionIntercept<sup>20+</sup>

onAccessibilityActionIntercept(callback: AccessibilityActionInterceptCallback): T

该接口在无障碍模式下，可在无障碍控制操作触发前通知注册的回调函数，由注册方决定是否拦截该次无障碍控制操作。对不支持点击操作的组件，即使注册该回调也不会被触发。

**卡片能力：** 从API version 20开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型    | 必填 | 说明                                                         |
| -------- | ------- | ---- | ------------------------------------------------------------ |
| callback | [AccessibilityActionInterceptCallback](#accessibilityactioninterceptcallback20) | 是   | 在无障碍模式且组件支持点击的前提下，在无障碍控制操作触发前通知注册方该次无障碍控制操作，由注册方决定是否拦截该操作。未开启无障碍模式或组件不支持点击时，回调均不会触发。<br> 入参设置为undefined时，取消回调注册。 |

**返回值：**

| 类型    | 说明              |
| ------ | ---------------- |
| T | 返回当前组件。 |

## AccessibilityActionInterceptCallback<sup>20+</sup>

type AccessibilityActionInterceptCallback = (action: AccessibilityAction) => AccessibilityActionInterceptResult

定义onAccessibilityActionIntercept中使用的回调类型。

**卡片能力：** 从API version 20开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型    | 必填 | 说明              |
| ------ | ------ | ---- | ---------------- |
| action | [AccessibilityAction](#accessibilityaction20枚举说明) | 是 | 当前触发的无障碍控制操作类型。 |

**返回值：**

| 类型    | 说明              |
| ------ | ---------------- |
| [AccessibilityActionInterceptResult](#accessibilityactioninterceptresult20枚举说明) | 无障碍控制操作拦截结果，用于决定是否拦截当前组件的无障碍控制操作及后续处理方式。 |

## AccessibilityAction<sup>20+</sup>枚举说明

定义组件当前触发的无障碍控制操作类型。

**卡片能力：** 从API version 20开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值  | 说明             |
| ---- | ---- | ------------------ |
| UNDEFINED_ACTION | 0 | 未定义的无障碍控制操作。 |
| ACCESSIBILITY_CLICK | 1 | 无障碍点击操作。 |

## AccessibilityActionInterceptResult<sup>20+</sup>枚举说明

定义AccessibilityActionInterceptCallback的无障碍控制操作拦截结果。

**卡片能力：** 从API version 20开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值  | 说明             |
| ---- | ---- | ------------------ |
| ACTION_INTERCEPT | 0 | 拦截当前组件接收的无障碍控制操作，回调处理结束后，不允许当前组件响应无障碍控制操作。 |
| ACTION_CONTINUE | 1 | 不拦截当前组件接收的无障碍控制操作，回调处理结束后，允许当前组件响应无障碍控制操作，执行当前组件的处理逻辑。 |
| ACTION_RISE | 2 | 不拦截当前组件接收的无障碍控制操作，回调处理结束后，仍然需要组件做出响应，执行当前组件的处理逻辑，并且将无障碍控制操作信息向父组件传递。传递到下一个使用了onAccessibilityActionIntercept的组件时，触发该组件中注册的回调，但不触发该组件处理逻辑。处理完成后，可以继续使用ACTION_RISE向父组件传递无障碍控制操作信息。 |

## 示例

### 示例1（设置onAccessibilityActionIntercept拦截点击事件）

该示例演示在无障碍模式下，通过onAccessibilityActionIntercept事件在Toggle组件点击事件触发前进行拦截，并由开发者确认是否放行该点击事件。

```ts
// xxx.ets
@Entry
@Component
struct OnAccessibilityActionInterceptExample {
  @State private isOn: boolean = false;

  build() {
    NavDestination() {
      Column() {
        Text('onAccessibilityActionIntercept')
        Row() {
          Text('Label message')
          Blank()
          Toggle({ type: ToggleType.Switch, isOn: $$this.isOn })
            .onAccessibilityActionIntercept((action: AccessibilityAction) => {
              // 无障碍点击操作触发时，弹出确认对话框由用户决定是否放行
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
                });
                // 拦截本次点击，阻止组件默认点击行为
                return AccessibilityActionInterceptResult.ACTION_INTERCEPT;
              } else {
                // 其他无障碍操作不拦截，直接放行
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

### 示例2（设置onAccessibilityFocus回调函数）

从API version 18开始，当获焦、失焦状态发生变化时，触发该回调函数。本示例展示了[onAccessibilityFocus](#onaccessibilityfocus)的基本用法，聚焦到"onAccessibilityFocus takes effect"时，会打印"[testingTag] isFocus current is true"，当聚焦到"onAccessibilityFocus takes effect"以外的位置时，会打印"[testingTag] isFocus current is false"。

```ts
// xxx.ets
@Entry
@Component
struct OnAccessibilityFocusExample {

  build() {
    NavDestination() {
      Column() {
        Text("onAccessibilityFocus doesn't take effect")
        Text('onAccessibilityFocus takes effect')
        .onAccessibilityFocus((isFocus: boolean) => {
          console.info(`[testingTag] isFocus current is ${isFocus}`);
        })
      }
      .padding(24)
      .width('100%')
    }
  }
}
```