# 枚举说明

>**说明：**
>
>本模块首批接口从API version 7开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。

## Color

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 颜色名称                     | 颜色值           | 颜色示意                                     |
| ------------------------ | ------------- | ---------------------------------------- |
| Black                    | 0x000000      | ![zh-cn_image_0000001219864153](figures/zh-cn_image_0000001219864153.png) |
| Blue                     | 0x0000ff      | ![zh-cn_image_0000001174104404](figures/zh-cn_image_0000001174104404.png) |
| Brown                    | 0xa52a2a      | ![zh-cn_image_0000001219744201](figures/zh-cn_image_0000001219744201.png) |
| Gray                     | 0x808080      | ![zh-cn_image_0000001174264376](figures/zh-cn_image_0000001174264376.png) |
| Grey                     | 0x808080      | ![zh-cn_image_0000001174264376](figures/zh-cn_image_0000001174264376.png) |
| Green                    | 0x008000      | ![zh-cn_image_0000001174422914](figures/zh-cn_image_0000001174422914.png) |
| Orange                   | 0xffa500      | ![zh-cn_image_0000001219662661](figures/zh-cn_image_0000001219662661.png) |
| Pink                     | 0xffc0cb      | ![zh-cn_image_0000001219662663](figures/zh-cn_image_0000001219662663.png) |
| Red                      | 0xff0000      | ![zh-cn_image_0000001219662665](figures/zh-cn_image_0000001219662665.png) |
| White                    | 0xffffff      | ![zh-cn_image_0000001174582866](figures/zh-cn_image_0000001174582866.png) |
| Yellow                   | 0xffff00      | ![zh-cn_image_0000001174582864](figures/zh-cn_image_0000001174582864.png) |
| Transparent<sup>9+</sup> | rgba(0,0,0,0) | 透明色                                      |

## ImageFit

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称        | 描述                              |
| --------- | ------------------------------- |
| Contain   | 保持宽高比进行缩小或者放大，使得图片完全显示在显示边界内。   |
| Cover     | 保持宽高比进行缩小或者放大，使得图片两边都大于或等于显示边界。 |
| Auto      | 自适应显示                           |
| Fill      | 不保持宽高比进行放大缩小，使得图片充满显示边界。        |
| ScaleDown | 保持宽高比显示，图片缩小或者保持不变。             |
| None      | 保持原有尺寸显示。                       |

## BorderStyle

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称     | 描述                            |
| ------ | ----------------------------- |
| Dotted | 显示为一系列圆点，圆点半径为borderWidth的一半。 |
| Dashed | 显示为一系列短的方形虚线。                 |
| Solid  | 显示为一条实线。                      |

## LineJoinStyle

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称    | 描述         |
| ----- | ---------- |
| Bevel | 使用斜角连接路径段。 |
| Miter | 使用尖角连接路径段。 |
| Round | 使用圆角连接路径段。 |

## TouchType

| 名称     | 描述              |
| ------ | --------------- |
| Down   | 手指按下时触发。        |
| Up     | 手指抬起时触发。        |
| Move   | 手指按压态在屏幕上移动时触发。 |
| Cancel | 触摸事件取消时触发。      |

## MouseButton

| 名称      | 描述       |
| ------- | -------- |
| Left    | 鼠标左键。    |
| Right   | 鼠标右键。    |
| Middle  | 鼠标中键。    |
| Back    | 鼠标左侧后退键。 |
| Forward | 鼠标左侧前进键。 |
| None    | 无按键。     |

## MouseAction

| 名称      | 描述      |
| ------- | ------- |
| Press   | 鼠标按键按下。 |
| Release | 鼠标按键松开。 |
| Move    | 鼠标移动。   |
| Hover   | 鼠标悬浮。<br/>**说明：** 该枚举值无效。<br/>   |

## Curve

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称                  | 描述                                       |
| ------------------- | ---------------------------------------- |
| Linear              | 表示动画从头到尾的速度都是相同的。                        |
| Ease                | 表示动画以低速开始，然后加快，在结束前变慢，CubicBezier(0.25, 0.1, 0.25, 1.0)。 |
| EaseIn              | 表示动画以低速开始，CubicBezier(0.42, 0.0, 1.0, 1.0)。 |
| EaseOut             | 表示动画以低速结束，CubicBezier(0.0, 0.0, 0.58, 1.0)。 |
| EaseInOut           | 表示动画以低速开始和结束，CubicBezier(0.42, 0.0, 0.58, 1.0)。 |
| FastOutSlowIn       | 标准曲线，cubic-bezier(0.4, 0.0, 0.2, 1.0)。   |
| LinearOutSlowIn     | 减速曲线，cubic-bezier(0.0, 0.0, 0.2, 1.0)。   |
| FastOutLinearIn     | 加速曲线，cubic-bezier(0.4, 0.0, 1.0, 1.0)。   |
| ExtremeDeceleration | 急缓曲线，cubic-bezier(0.0, 0.0, 0.0, 1.0)。   |
| Sharp               | 锐利曲线，cubic-bezier(0.33, 0.0, 0.67, 1.0)。 |
| Rhythm              | 节奏曲线，cubic-bezier(0.7, 0.0, 0.2, 1.0)。   |
| Smooth              | 平滑曲线，cubic-bezier(0.4, 0.0, 0.4, 1.0)。   |
| Friction            | 阻尼曲线，CubicBezier(0.2, 0.0, 0.2, 1.0)。    |

## AnimationStatus

从API version 10开始，该接口支持在ArkTS卡片中使用。

| 名称      | 描述        |
| ------- | --------- |
| Initial | 动画初始状态。   |
| Running | 动画处于播放状态。 |
| Paused  | 动画处于暂停状态。 |
| Stopped | 动画处于停止状态。 |

## FillMode

从API version 10开始，该接口支持在ArkTS卡片中使用。

| 名称        | 描述                                       |
| --------- | ---------------------------------------- |
| None      | 动画未执行时不会将任何样式应用于目标，动画播放完成之后恢复初始默认状态。     |
| Forwards  | 目标将保留动画执行期间最后一个关键帧的状态。                   |
| Backwards | 动画将在应用于目标时立即应用第一个关键帧中定义的值，并在delay期间保留此值。第一个关键帧取决于playMode，playMode为Normal或Alternate时为from的状态，playMode为Reverse或AlternateReverse时为to的状态。 |
| Both      | 动画将遵循Forwards和Backwards的规则，从而在两个方向上扩展动画属性。 |

## PlayMode

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称               | 描述                                       |
| ---------------- | ---------------------------------------- |
| Normal           | 动画按正向播放。                                 |
| Reverse          | 动画反向播放。                                  |
| Alternate        | 动画在奇数次（1、3、5...）正向播放，在偶数次（2、4、6...）反向播放。 |
| AlternateReverse | 动画在奇数次（1、3、5...）反向播放，在偶数次（2、4、6...）正向播放。 |

## KeyType

| 名称   | 描述    |
| ---- | ----- |
| Down | 按键按下。 |
| Up   | 按键松开。 |

## KeySource

| 名称       | 描述         |
| -------- | ---------- |
| Unknown  | 输入设备类型未知。  |
| Keyboard | 输入设备类型为键盘。 |

## Edge

| 名称                               | 描述                                       |
| -------------------------------- | ---------------------------------------- |
| Top                              | 竖直方向上边缘<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| Center<sup>(deprecated) </sup>   | 竖直方向居中位置<br/> 从API version 9开始废弃         |
| Bottom                           | 竖直方向下边缘<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| Baseline<sup>(deprecated) </sup> | 交叉轴方向文本基线位置<br/> 从API version 9开始废弃      |
| Start                            | 水平方向起始位置<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| Middle<sup>(deprecated) </sup>   | 水平方向居中位置<br/> 从API version 9开始废弃         |
| End                              | 水平方向末尾位置<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |

## Week

| 名称   | 描述   |
| ---- | ---- |
| Mon  | 星期一  |
| Tue  | 星期二  |
| Wed  | 星期三  |
| Thur | 星期四  |
| Fri  | 星期五  |
| Sat  | 星期六  |
| Sun  | 星期日  |

## Direction

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称   | 描述          |
| ---- | ----------- |
| Ltr  | 元素从左到右布局。   |
| Rtl  | 元素从右到左布局。   |
| Auto | 使用系统默认布局方向。 |

## BarState

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称   | 描述                 |
| ---- | ------------------ |
| Off  | 不显示。               |
| On   | 常驻显示。              |
| Auto | 按需显示(触摸时显示，2s后消失)。 |

## EdgeEffect

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称     | 描述                                       |
| ------ | ---------------------------------------- |
| Spring | 弹性物理动效，滑动到边缘后可以根据初始速度或通过触摸事件继续滑动一段距离，松手后回弹。 |
| Fade   | 阴影效果，滑动到边缘后会有圆弧状的阴影。                     |
| None   | 滑动到边缘后无效果。                               |

## Alignment

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称          | 描述       |
| ----------- | -------- |
| TopStart    | 顶部起始端。   |
| Top         | 顶部横向居中。  |
| TopEnd      | 顶部尾端。    |
| Start       | 起始端纵向居中。 |
| Center      | 横向和纵向居中。 |
| End         | 尾端纵向居中。  |
| BottomStart | 底部起始端。   |
| Bottom      | 底部横向居中。  |
| BottomEnd   | 底部尾端。    |

## TransitionType

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称     | 描述                             |
| ------ | ------------------------------ |
| All    | 指定当前的Transition动效生效在组件的所有变化场景。 |
| Insert | 指定当前的Transition动效生效在组件的插入显示场景。 |
| Delete | 指定当前的Transition动效生效在组件的删除隐藏场景。 |

## RelateType

| 名称   | 描述             |
| ---- | -------------- |
| FILL | 缩放当前子组件以填充满父组件 |
| FIT  | 缩放当前子组件以自适应父组件 |

## Visibility

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称      | 描述               |
| ------- | ---------------- |
| Hidden  | 隐藏，但参与布局进行占位。    |
| Visible | 显示。              |
| None    | 隐藏，但不参与布局，不进行占位。 |

## LineCapStyle

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称     | 描述                            |
| ------ | ----------------------------- |
| Butt   | 线条两端为平行线，不额外扩展。               |
| Round  | 在线条两端延伸半个圆，直径等于线宽。            |
| Square | 在线条两端延伸一个矩形，宽度等于线宽的一半，高度等于线宽。 |

## Axis

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称         | 描述     |
| ---------- | ------ |
| Vertical   | 方向为纵向。 |
| Horizontal | 方向为横向。 |

## HorizontalAlign

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称     | 描述           |
| ------ | ------------ |
| Start  | 按照语言方向起始端对齐。 |
| Center | 居中对齐，默认对齐方式。 |
| End    | 按照语言方向末端对齐。  |

## FlexAlign

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称           | 描述                                       |
| ------------ | ---------------------------------------- |
| Start        | 元素在主轴方向首端对齐，第一个元素与行首对齐，同时后续的元素与前一个对齐。    |
| Center       | 元素在主轴方向中心对齐，第一个元素与行首的距离与最后一个元素与行尾距离相同。   |
| End          | 元素在主轴方向尾部对齐，最后一个元素与行尾对齐，其他元素与后一个对齐。      |
| SpaceBetween | Flex主轴方向均匀分配弹性元素，相邻元素之间距离相同。第一个元素与行首对齐，最后一个元素与行尾对齐。 |
| SpaceAround  | Flex主轴方向均匀分配弹性元素，相邻元素之间距离相同。第一个元素到行首的距离和最后一个元素到行尾的距离是相邻元素之间距离的一半。 |
| SpaceEvenly  | Flex主轴方向均匀分配弹性元素，相邻元素之间的距离、第一个元素与行首的间距、最后一个元素到行尾的间距都完全一样。 |

## ItemAlign

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称       | 描述                                       |
| -------- | ---------------------------------------- |
| Auto     | 使用Flex容器中默认配置。                           |
| Start    | 元素在Flex容器中，交叉轴方向首部对齐。                    |
| Center   | 元素在Flex容器中，交叉轴方向居中对齐。                    |
| End      | 元素在Flex容器中，交叉轴方向底部对齐。                    |
| Stretch  | 元素在Flex容器中，交叉轴方向拉伸填充。容器为Flex且设置Wrap为FlexWrap.Wrap或FlexWrap.WrapReverse时，元素拉伸到与当前行/列交叉轴长度最长的元素尺寸。其余情况在元素未设置尺寸时，拉伸到容器尺寸。 |
| Baseline | 元素在Flex容器中，交叉轴方向文本基线对齐。                  |

## FlexDirection

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称            | 描述               |
| ------------- | ---------------- |
| Row           | 主轴与行方向一致作为布局模式。  |
| RowReverse    | 与Row方向相反方向进行布局。  |
| Column        | 主轴与列方向一致作为布局模式。  |
| ColumnReverse | 与Column相反方向进行布局。 |

## FlexWrap

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称          | 描述                          |
| ----------- | --------------------------- |
| NoWrap      | Flex容器的元素单行/列布局，子项不允许超出容器。  |
| Wrap        | Flex容器的元素多行/列排布，子项允许超出容器。   |
| WrapReverse | Flex容器的元素反向多行/列排布，子项允许超出容器。 |

## VerticalAlign

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称     | 描述           |
| ------ | ------------ |
| Top    | 顶部对齐。        |
| Center | 居中对齐，默认对齐方式。 |
| Bottom | 底部对齐。        |

## ImageRepeat

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称       | 描述            |
| -------- | ------------- |
| X        | 只在水平轴上重复绘制图片。 |
| Y        | 只在竖直轴上重复绘制图片。 |
| XY       | 在两个轴上重复绘制图片。  |
| NoRepeat | 不重复绘制图片。      |

## ImageSize

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 类型      | 描述                                  |
| ------- | ----------------------------------- |
| Cover   | 默认值，保持宽高比进行缩小或者放大，使得图片两边都大于或等于显示边界。 |
| Contain | 保持宽高比进行缩小或者放大，使得图片完全显示在显示边界内。       |
| Auto    | 保持原图的比例不变。                          |

## GradientDirection

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称          | 描述    |
| ----------- | ----- |
| Left        | 从右向左。 |
| Top         | 从下向上。 |
| Right       | 从左向右。 |
| Bottom      | 从上向下。 |
| LeftTop     | 左上。   |
| LeftBottom  | 左下。   |
| RightTop    | 右上。   |
| RightBottom | 右下。   |
| None        | 无。    |

## SharedTransitionEffectType

| 名称       | 描述                                       |
| -------- | ---------------------------------------- |
| Static   | 目标页面元素的位置保持不变，可以配置透明度动画。目前，只有为重定向到目标页面而配置的静态效果才会生效。 |
| Exchange | 将源页面元素移动到目标页面元素位置并适当缩放。                  |

## ShadowType<sup>10+<sup>

| 名称       | 描述                                   |
| -------- | ---------------------------------------- |
| COLOR    | 颜色。                                    |
| BLUR     | 模糊。                                    |

## FontStyle

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称     | 描述       |
| ------ | -------- |
| Normal | 标准的字体样式。 |
| Italic | 斜体的字体样式。 |

## FontWeight

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称      | 描述      |
| ------- | ------- |
| Lighter | 字体较细。   |
| Normal  | 字体粗细正常。 |
| Regular | 字体粗细正常。 |
| Medium  | 字体粗细适中。 |
| Bold    | 字体较粗。   |
| Bolder  | 字体非常粗。  |

## TextAlign

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称                    | 描述      |
| --------------------- | ------- |
| Start                 | 水平对齐首部。 |
| Center                | 水平居中对齐。 |
| End                   | 水平对齐尾部。 |
| JUSTIFY<sup>10+</sup> | 双端对齐。   |

## TextOverflow

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称                    | 描述                  |
| --------------------- | ------------------- |
| None                  | 文本超长时裁剪显示。          |
| Clip                  | 文本超长时进行裁剪显示。        |
| Ellipsis              | 文本超长时显示不下的文本用省略号代替。 |
| MARQUEE<sup>10+</sup> | 文本超长时以跑马灯的方式展示。     |

## TextDecorationType

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称          | 描述        |
| ----------- | --------- |
| Underline   | 文字下划线修饰。  |
| LineThrough | 穿过文本的修饰线。 |
| Overline    | 文字上划线修饰。  |
| None        | 不使用文本装饰线。 |

## TextCase

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称        | 描述         |
| --------- | ---------- |
| Normal    | 保持文本原有大小写。 |
| LowerCase | 文本采用全小写。   |
| UpperCase | 文本采用全大写。   |

## ResponseType<sup>8+</sup>

| 名称         | 描述            |
| ---------- | ------------- |
| LongPress  | 通过长按触发菜单弹出。   |
| RightClick | 通过鼠标右键触发菜单弹出。 |

## RichEditorResponseType<sup>11+</sup>

| 名称         | 描述            |
| ---------- | ------------- |
| LONG_PRESS  | 通过长按触发菜单弹出。   |
| RIGHT_CLICK | 通过鼠标右键触发菜单弹出。 |
| SELECT | 通过鼠标选中触发菜单弹出。 |

## HoverEffect<sup>8+</sup>

| 名称        | 描述             |
| --------- | -------------- |
| Auto      | 使用组件的系统默认悬浮效果。 |
| Scale     | 放大缩小效果。        |
| Highlight | 背景淡入淡出的强调效果。   |
| None      | 不设置效果。         |

## Placement<sup>8+</sup>

| 名称            | 描述                                     |
| ------------- | -------------------------------------- |
| Left          | 气泡提示位于组件左侧，与组件左侧中心对齐。                  |
| Right         | 气泡提示位于组件右侧，与组件右侧中心对齐。                  |
| Top           | 气泡提示位于组件上侧，与组件上侧中心对齐。                  |
| Bottom        | 气泡提示位于组件下侧，与组件下侧中心对齐。                  |
| TopLeft       | 气泡提示位于组件上侧，从API Version 9开始，与组件左侧边缘对齐。 |
| TopRight      | 气泡提示位于组件上侧，从API Version 9开始，与组件右侧边缘对齐。 |
| BottomLeft    | 气泡提示位于组件下侧，从API Version 9开始，与组件左侧边缘对齐。 |
| BottomRight   | 气泡提示位于组件下侧，从API Version 9开始，与组件右侧边缘对齐。 |
| LeftTop9+     | 气泡提示位于组件左侧，与组件上侧边缘对齐。                  |
| LeftBottom9+  | 气泡提示位于组件左侧，与组件下侧边缘对齐。                  |
| RightTop9+    | 气泡提示位于组件右侧，与组件上侧边缘对齐。                  |
| RightBottom9+ | 气泡提示位于组件右侧，与组件下侧边缘对齐。                  |

## CopyOptions<sup>9+</sup>

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称          | 描述       |
| ----------- | -------- |
| None        | 不支持复制。   |
| InApp       | 支持应用内复制。 |
| LocalDevice | 支持设备内复制。 |
| CROSS_DEVICE<sup>11+</sup> | 支持跨设备复制。 |

## HitTestMode<sup>9+</sup>

| 名称          | 描述                                       |
| ----------- | ---------------------------------------- |
| Default     | 自身节点和子节点都响应触摸事件的命中测试，但会阻止被该节点屏蔽的其他节点的命中测试。 |
| Block       | 自身节点响应触摸事件的命中测试，但阻止被该节点屏蔽的子节点和其他节点的命中测试。 |
| Transparent | 自身节点和子节点响应触摸事件的命中测试，并允许对被该节点屏蔽的其他节点进行命中测试。 |
| None        | 自身节点不会响应触摸事件的命中测试，但子节点会对触摸事件进行命中测试。      |

## BlurStyle<sup>9+</sup>

该接口支持在ArkTS卡片中使用。

| 名称                   | 描述        |
| -------------------- | --------- |
| Thin                 | 轻薄材质模糊。   |
| Regular              | 普通厚度材质模糊。 |
| Thick                | 厚材质模糊。    |
| BACKGROUND_THIN       | 近距景深模糊。   |
| BACKGROUND_REGULAR    | 中距景深模糊。   |
| BACKGROUND_THICK      | 远距景深模糊。   |
| BACKGROUND_ULTRA_THICK | 超远距景深模糊。  |
| NONE<sup>10+</sup> | 关闭模糊。  |
| COMPONENT_ULTRA_THIN<sup>11+</sup> | 组件超轻薄材质模糊。 |
| COMPONENT_THIN<sup>11+</sup> | 组件轻薄材质模糊。 |
| COMPONENT_REGULAR<sup>11+</sup> | 组件普通材质模糊。 |
| COMPONENT_THICK<sup>11+</sup> | 组件厚材质模糊。 |
| COMPONENT_ULTRA_THICK<sup>11+</sup> | 组件超厚材质模糊。 |

## ThemeColorMode<sup>10+</sup>

| 名称     | 描述         |
| ------ | ---------- |
| SYSTEM | 跟随系统深浅色模式。 |
| LIGHT  | 固定使用浅色模式。  |
| DARK   | 固定使用深色模式。  |

## AdaptiveColor<sup>10+</sup>

| 名称      | 描述                        |
| ------- | ------------------------- |
| DEFAULT | 不使用取色模糊。使用默认的颜色作为蒙版颜色。    |
| AVERAGE | 使用取色模糊。将取色区域的颜色平均值作为蒙版颜色。 |

## TextHeightAdaptivePolicy<sup>10+</sup>

| 名称                      | 描述                       |
| ----------------------- | ------------------------ |
| MAX_LINES_FIRST         | 设置文本高度自适应方式为以MaxLines优先。 |
| MIN_FONT_SIZE_FIRST     | 设置文本高度自适应方式为以缩小字体优先。     |
| LAYOUT_CONSTRAINT_FIRST | 设置文本高度自适应方式为以布局约束（高度）优先。 |

## ObscuredReasons<sup>10+</sup>

该接口支持在ArkTS卡片中使用。

| 名称        | 描述                     |
| ----------- | ------------------------ |
| PLACEHOLDER | 显示的数据为通用占位符。 |

## TransitionEdge<sup>10+<sup>

| 名称     | 描述     |
| ------ | ------ |
| TOP    | 窗口的上边缘 |
| BOTTOM | 窗口的下边缘 |
| START  | 窗口的左边缘 |
| END    | 窗口的右边缘 |

## ClickEffectLevel<sup>10+<sup>

| 名称   | 描述               | 动效参数                          | 默认缩放比                     |
| ------ | --------------------------------- | --------------------------------- | --------------------------------- |
| LIGHT  | 小面积（轻盈） | 弹簧动效， 刚性：410，阻尼：38，初始速度：1 | 90% |
| MIDDLE | 中面积（稳定） | 弹簧动效， 刚性：350，阻尼：35，初始速度：0.5 | 95% |
| HEAVY  | 大面积（厚重） | 弹簧动效， 刚性：240，阻尼：28，初始速度：0 | 95% |

## FoldStatus<sup>11+</sup>

| 名称                      | 描述         |
| ----------------------  | ---------- |
| FOLD_STATUS_UNKNOWN     | 表示设备当前折叠状态未知。 |
| FOLD_STATUS_EXPANDED    | 表示设备当前折叠状态为完全展开。   |
| FOLD_STATUS_FOLDED      | 表示设备当前折叠状态为折叠。   |
| FOLD_STATUS_HALF_FOLDED | 表示设备当前折叠状态为半折叠。半折叠指完全展开和折叠之间的状态。|

## TextContentStyle<sup>10+</sup>

| 名称    | 描述                                                         |
| ------- | ------------------------------------------------------------ |
| DEFAULT | 默认风格，光标宽1.5vp，光标高度与文本选中底板高度和字体大小相关。 |
| INLINE  | 内联输入风格。文本选中底板高度与输入框高度相同。<br/>不支持showError属性。 |

## MenuPreviewMode<sup>11+</sup>

| 名称  | 描述                                   |
| ----- | -------------------------------------- |
| NONE  | 不显示预览内容。                       |
| IMAGE | 预览内容为触发长按悬浮菜单组件的截图。 |

## Nullable <sup>11+</sup>

Nullable\<T> {

(data: T);

}

开发者在使用该类型时候，该类型的对象可以是自定义类型，也可以是undefined。

**系统能力**：SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 必填 | 说明                       |
| ---- | ---- | ---- | -------------------------- |
| data | T    | 是   | 该类型申明的对象可以是自定义类型，也可以是undefined。 |

## WordBreak<sup>11+</sup>
| 名称  | 描述                                   |
| ----- | -------------------------------------- |
| NORMAL  | CJK(中文、日文、韩文)文本可以在任意2个字符间断行,而Non-CJK文本（如英文等）只能在空白符处断行。|
| BREAK_ALL | 对于Non-CJK的文本，可在任意2个字符间断行。对于CJK与NORMAL效果一致。|
| BREAK_WORD | 与BREAK_ALL相同，对于Non-CJK的文本可在任意2个字符间断行。不同点在于一行文本有断行破发点（如空白符）处会换行，在能保证英文单词为一个整体单位时必须保持为一个整体。对于CJK与NORMAL效果一致。|

## GestureJudgeResult<sup>11+</sup>
| 名称  | 描述                                   |
| ----- | -------------------------------------- |
| CONTINUE  | 不影响系统手势判定流程。|
| REJECT  | 对于用户自定义的手势判定结果为失败。|

## GestureType<sup>11+</sup>
| 名称  | 描述                                   |
| ----- | -------------------------------------- |
| TAP_GESTURE   | 点击手势|
| LONG_PRESS_GESTURE  | 长按手势|
| PAN_GESTURE    | 拖动手势|
| PINCH_GESTURE   | 捏合手势|
| SWIPE_GESTURE    | 滑动手势|
| ROTATION_GESTURE   | 旋转手势|
| DRAG    | 拖拽|
| CLICK   | 点击|
## FinishCallbackType<sup>11+</sup>

从API version 11开始，该接口支持在ArkTS卡片中使用。

| 名称       | 描述                                                         |
| --------- | ------------------------------------------------------------ |
| REMOVED   | 当整个动画结束并立即删除时，将触发回调。                         |
| LOGICALLY | 当动画在逻辑上处于下降状态，但可能仍处于其长尾状态时，将触发回调。 |

## BlurOptions<sup>11+<sup>
灰阶模糊参数。
| 名称        |   类型   |   必填 | 说明                        |
| ----        |  ----   |   ---- | --------------------------  |
| grayscale   |  [number, number]   |   是   |  灰阶模糊参数，参数取值范围[0,127] 。 |

## BackgroundBrightnessOptions<sup>11+<sup>
背景光源参数。
 | 名称        |   类型         |   必填 |  说明                        |
| ----         |  ----         |   ---- | --------------------------  |
| radius       | number        |   是   |   背景光源半径，取值范围：[0, +∞)，默认为0。     |
| saturation   | number        |   否   |   背景光源饱和度，取值范围：[0, +∞)，默认为0。     |
| brightness   | number        |   否   |   背景光源亮度，取值范围：[0, +∞)，默认为0。       | 
| color        | [Color](ts-appendix-enums.md#color)        |   否   |   背景光源颜色，默认透明色。  |
| adaptiveColor | [AdaptiveColor](ts-appendix-enums.md#adaptivecolor10) |   否  | 背景模糊效果使用的取色模式,默认为DEFAULT。   |
| blurOptions  | [BlurOptions](ts-appendix-enums.md#bluroptions11) |   否   |   灰阶模糊参数，默认为[0,0]。  |
## EllipsisMode<sup>11+</sup>

从API version 11开始，该接口支持在ArkTS卡片中使用。

| 名称  | 描述                                   |
| ----- | -------------------------------------- |
| START  | 省略行首内容。|
| CENTER | 省略行中内容。|
| END | 省略行末内容。|

## ArrowPointPosition<sup>11+</sup>

| 名称            | 描述                                     |
| ------------- | -------------------------------------- |
| START | 水平方向：位于父组件最左侧，垂直方向：位于父组件最上侧。 |
| CENTER | 位于父组件居中位置。 |
| END | 水平方向：位于父组件最右侧，垂直方向：位于父组件最下侧。 |

## TextDataDetectorType<sup>11+</sup>

| 名称  | 描述                                   |
| ----- | -------------------------------------- |
| PHONE_NUMBER  | 电话号码 |
| URL | 链接 |
| EMAIL | 邮箱 |
| ADDRESS | 地址 |
