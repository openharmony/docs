# Enums

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## WindowType<sup>7+</sup>

窗口类型枚举。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称                                  | 值 | 说明                                                                                     |
|-------------------------------------| ------ |----------------------------------------------------------------------------------------|
| TYPE_APP                            | 0      | 表示应用子窗口。<br>**模型约束：** 此接口仅可在FA模型下使用。                                                   |
| TYPE_SYSTEM_ALERT                   | 1      | 表示系统告警窗口。<br>- **说明：** 从API version 11开始废弃。<br>- 从API version 7开始支持。                               |
| TYPE_FLOAT<sup>9+</sup>             | 8      | 表示悬浮窗。<br>**模型约束：** 此接口仅可在Stage模型下使用。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| TYPE_DIALOG<sup>10+</sup>           | 16      | 表示模态窗口。<br>**模型约束：** 此接口仅可在Stage模型下使用。                                                 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| TYPE_MAIN<sup>18+</sup>             | 32      | 表示应用主窗口。<br>此窗口类型不支持在创建窗口时使用，仅可在getWindowProperties接口的返回值中用于读取。                               |

## AvoidAreaType<sup>7+</sup>

窗口内容需要规避区域的类型枚举。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

| 名称                             | 值   | 说明                                                         |
| -------------------------------- | ---- | ------------------------------------------------------------ |
| TYPE_SYSTEM                      | 0    | 表示系统默认区域。<!--RP11-->包含状态栏和三键导航栏区域。<!--RP11End-->       |
| TYPE_CUTOUT                      | 1    | 表示刘海屏区域。                                                              |
| TYPE_SYSTEM_GESTURE<sup>9+</sup> | 2    | 表示手势区域。当前，各设备均无此类型避让区域。                                    |
| TYPE_KEYBOARD<sup>9+</sup>       | 3    | 表示软键盘区域。                                                              |
| TYPE_NAVIGATION_INDICATOR<sup>11+</sup> | 4    | 表示底部导航区域。<!--RP12-->OpenHarmony各设备不支持此能力。<!--RP12End-->                             |

## Orientation<sup>9+</sup>

窗口显示方向类型枚举。

| 名称                                  | 值   | 说明                          |
| ------------------------------------- | ---- | ----------------------------- |
| UNSPECIFIED                           | 0    | 表示未定义方向模式，由系统判定。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| PORTRAIT                              | 1    | 表示竖屏显示模式。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core<br> **原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| LANDSCAPE                             | 2    | 表示横屏显示模式。<br> **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| PORTRAIT_INVERTED                     | 3    | 表示反向竖屏显示模式。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core<br> **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| LANDSCAPE_INVERTED                    | 4    | 表示反向横屏显示模式。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core<br> **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| AUTO_ROTATION                         | 5    | 跟随传感器自动旋转，可以旋转到竖屏、横屏、反向竖屏、反向横屏四个方向。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core<br> **原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| AUTO_ROTATION_PORTRAIT                | 6    | 跟随传感器自动竖向旋转，可以旋转到竖屏、反向竖屏，无法旋转到横屏、反向横屏。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| AUTO_ROTATION_LANDSCAPE               | 7    | 跟随传感器自动横向旋转，可以旋转到横屏、反向横屏，无法旋转到竖屏、反向竖屏。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core。<br> **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| AUTO_ROTATION_RESTRICTED              | 8    | 跟随传感器自动旋转，可以旋转到竖屏、横屏、反向竖屏、反向横屏四个方向，且受控制中心的旋转开关控制。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core<br> **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| AUTO_ROTATION_PORTRAIT_RESTRICTED     | 9    | 跟随传感器自动竖向旋转，可以旋转到竖屏、反向竖屏，无法旋转到横屏、反向横屏，且受控制中心的旋转开关控制。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| AUTO_ROTATION_LANDSCAPE_RESTRICTED    | 10   | 跟随传感器自动横向旋转，可以旋转到横屏、反向横屏，无法旋转到竖屏、反向竖屏，且受控制中心的旋转开关控制。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| LOCKED                                | 11   | 表示锁定模式。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| AUTO_ROTATION_UNSPECIFIED<sup>12+</sup>        | 12   | 跟随传感器自动旋转，受控制中心的旋转开关控制，且可旋转方向受系统判定（如在某种设备，可以旋转到竖屏、横屏、反向横屏三个方向，无法旋转到反向竖屏）。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br> **系统能力：** SystemCapability.Window.SessionManager|
| USER_ROTATION_PORTRAIT<sup>12+</sup>           | 13   | 调用时临时旋转到竖屏，之后跟随传感器自动旋转，受控制中心的旋转开关控制，且可旋转方向受系统判定。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br> **系统能力：** SystemCapability.Window.SessionManager|
| USER_ROTATION_LANDSCAPE<sup>12+</sup>          | 14   | 调用时临时旋转到横屏，之后跟随传感器自动旋转，受控制中心的旋转开关控制，且可旋转方向受系统判定。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br> **系统能力：** SystemCapability.Window.SessionManager|
| USER_ROTATION_PORTRAIT_INVERTED<sup>12+</sup>  | 15   | 调用时临时旋转到反向竖屏，之后跟随传感器自动旋转，受控制中心的旋转开关控制，且可旋转方向受系统判定。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br> **系统能力：** SystemCapability.Window.SessionManager|
| USER_ROTATION_LANDSCAPE_INVERTED<sup>12+</sup> | 16   | 调用时临时旋转到反向横屏，之后跟随传感器自动旋转，受控制中心的旋转开关控制，且可旋转方向受系统判定。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br> **系统能力：** SystemCapability.Window.SessionManager|
| FOLLOW_DESKTOP<sup>12+</sup>                   | 17   | 表示跟随桌面的旋转模式。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br> **系统能力：** SystemCapability.Window.SessionManager|

## RectChangeReason<sup>12+</sup>

窗口矩形（窗口位置及窗口大小）变化的原因。

**系统能力：** SystemCapability.Window.SessionManager

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| 名称                  | 值   | 说明                                                         |
| --------------------- | ---- | ------------------------------------------------------------ |
| UNDEFINED                 | 0    | 默认值。                                                   |
| MAXIMIZE                | 1    | 窗口最大化。                                                   |
| RECOVER              | 2    | 窗口恢复到上一次的状态。                                                   |
| MOVE | 3    | 窗口拖拽移动。 |
| DRAG  | 4    | 窗口拖拽缩放。 |
| DRAG_START  | 5    | 窗口开始拖拽缩放。 |
| DRAG_END  | 6    | 窗口结束拖拽缩放。 |

## ColorSpace<sup>8+</sup>

色域模式。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称       | 值 | 说明           |
| ---------- | ------ | -------------- |
| DEFAULT    | 0      | 默认SRGB色域模式。 |
| WIDE_GAMUT | 1      | 广色域模式。   |

## WindowEventType<sup>10+</sup>

窗口生命周期。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

| 名称       | 值 | 说明       |
| ---------- | ------ | ---------- |
| WINDOW_SHOWN      | 1      | 切到前台。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| WINDOW_ACTIVE     | 2      | 获焦状态。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| WINDOW_INACTIVE   | 3      | 失焦状态。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| WINDOW_HIDDEN     | 4      | 切到后台。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| WINDOW_DESTROYED<sup>11+</sup>  | 7      | 窗口销毁。<br> **系统能力：** SystemCapability.Window.SessionManager|

## WindowStatusType<sup>11+</sup>

窗口模式枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称       | 值   | 说明                          |
| ---------- | ---- | ----------------------------- |
| UNDEFINED  | 0    | 表示APP未定义窗口模式。       |
| FULL_SCREEN | 1    | 表示APP全屏模式。             |
| MAXIMIZE    | 2    | 表示APP窗口最大化模式。   |
| MINIMIZE    | 3    | 表示APP窗口最小化模式。   |
| FLOATING    | 4    | 表示APP自由悬浮形式窗口模式。   |
| SPLIT_SCREEN  | 5    | 表示APP分屏模式。   |

## MaximizePresentation<sup>12+</sup>

窗口最大化时的布局枚举。

**系统能力：**  SystemCapability.Window.SessionManager

| 名称       | 值   | 说明                          |
| ---------- | ---- | ----------------------------- |
| FOLLOW_APP_IMMERSIVE_SETTING  | 0    | 最大化时，跟随应用app当前设置的沉浸式布局。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。       |
| EXIT_IMMERSIVE | 1    | 最大化时，如果当前窗口设置了沉浸式布局会退出沉浸式布局。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。             |
| ENTER_IMMERSIVE    | 2    | 最大化时，进入沉浸式布局，鼠标Hover在热区上显示窗口标题栏和dock栏。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。   |
| ENTER_IMMERSIVE_DISABLE_TITLE_AND_DOCK_HOVER<sup>14+</sup>    | 3    | 最大化时，进入沉浸式布局，鼠标Hover在热区上不显示窗口标题栏和dock栏。<br/>**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。   |

## WindowAnimationCurve<sup>20+</sup>

窗口动画曲线类型。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.Window.SessionManager

| 名称                | 值   | 说明                                                         |
| ------------------- | ---- | ------------------------------------------------------------ |
| LINEAR              | 0    | 表示动画从头到尾的速度都是相同的。<br/>使用该曲线类型时[WindowAnimationConfig](arkts-apis-window-i.md#windowanimationconfig20)中duration必填。<br/>使用该曲线类型时[WindowAnimationConfig](arkts-apis-window-i.md#windowanimationconfig20)中param选填，且不生效。 |
| INTERPOLATION_SPRING | 1    | 表示插值器弹簧曲线，一条从0到1的动画曲线，实际动画值根据曲线进行插值计算。动画时间由曲线参数决定，不受[WindowAnimationConfig](arkts-apis-window-i.md#windowanimationconfig20)中的duration参数控制。<br/>使用该曲线类型时[WindowAnimationConfig](arkts-apis-window-i.md#windowanimationconfig20)中duration选填，且不生效。<br/>使用该曲线类型时[WindowAnimationConfig](arkts-apis-window-i.md#windowanimationconfig20)中param必填。 |

## WindowTransitionType<sup>20+</sup>

窗口转场动画类型枚举。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.Window.SessionManager

| 名称    | 值   | 说明                       |
| ------- | ---- | -------------------------- |
| DESTROY | 0    | 表示窗口销毁时的转场动画。 |

## AnimationType<sup>20+</sup>

窗口动画类型枚举。

**系统能力：**  SystemCapability.Window.SessionManager

| 名称    | 值   | 说明                       |
| ------- | ---- | -------------------------- |
| FADE_IN_OUT | 0    | 表示窗口动画类型为淡入淡出。 |

## WindowAnchor<sup>20+</sup>

窗口锚点枚举。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.Window.SessionManager

| 名称       | 值   | 说明                          |
| ---------- | ---- | ----------------------------- |
| TOP_START  | 0    | 窗口左上角。|
| TOP  | 1    | 窗口上边界横向居中点。|
| TOP_END  | 2    | 窗口右上角。|
| START  | 3    | 窗口左边界纵向居中点。|
| CENTER  | 4    | 窗口横向和纵向居中点。|
| END  | 5    | 窗口右边界纵向居中点。|
| BOTTOM_START  | 6    | 窗口左下角。|
| BOTTOM  | 7    | 窗口下边界横向居中点。|
| BOTTOM_END  | 8    | 窗口右下角。|

## RotationChangeType<sup>19+</sup>

窗口旋转事件类型。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.Window.SessionManager

| 名称   |  值 | 说明                   |
| ------ | ---- | --------------------- |
| WINDOW_WILL_ROTATE| 0 | 窗口即将旋转。 |
| WINDOW_DID_ROTATE | 1 | 窗口旋转结束。 |

## RectType<sup>19+</sup>

窗口矩形区域坐标系类型。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.Window.SessionManager

| 名称   | 值 | 说明                   |
| ------ | ---- | --------------------- |
| RELATIVE_TO_SCREEN | 0 | 窗口矩形区域相对于屏幕坐标系。 |
| RELATIVE_TO_PARENT_WINDOW | 1 | 窗口矩形区域相对于父窗口坐标系。 |

## GlobalWindowMode<sup>20+</sup>

窗口模式。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.Window.SessionManager

| 名称   | 值 | 说明                    |
| ------ | --- | ------------------------ |
| FULLSCREEN | 1 | 全屏窗口。 |
| SPLIT  | 1 << 1 | 分屏窗口。 |
| FLOAT   | 1 << 2  | 悬浮窗。 |
| PIP   | 1 << 3  | 画中画。 |

## WindowStageEventType<sup>9+</sup>

WindowStage生命周期。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

| 名称       | 值 | 说明       |
| ---------- | ------ | ---------- |
| SHOWN      | 1      | 切到前台，例如点击应用图标启动，无论是首次启动还是从后台启动均会触发。 |
| ACTIVE     | 2      | 获焦状态，例如应用窗口处理点击事件后的状态、应用启动后的状态。 |
| INACTIVE   | 3      | 失焦状态，例如打开新应用或点击其他窗口后，原获焦窗口的状态。 |
| HIDDEN     | 4      | 切到后台，例如应用上滑退出、应用窗口关闭。 |
| RESUMED<sup>11+</sup> | 5      | 前台可交互状态，例如应用打开后，可以与用户交互的状态。 |
| PAUSED<sup>11+</sup>  | 6      | 前台不可交互状态，例如从屏幕底部上划，应用进入到多任务界面后的状态。 |

## ModalityType<sup>14+</sup>

子窗口模态类型枚举。

**系统能力：** SystemCapability.Window.SessionManager

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

| 名称                 | 值      | 说明       |
| -------------------- | ------ | ---------- |
| WINDOW_MODALITY      | 0      | 模态子窗类型为模窗口子窗，当仅需要其父级窗口不响应用户操作时，可选此参数。 |
| APPLICATION_MODALITY | 1      | 模态子窗类型为模应用子窗，除其父级窗口外还需要该应用其他实例的窗口不响应用户操作时，可选此参数。<br> 此接口仅支持在2in1设备下使用。 |
