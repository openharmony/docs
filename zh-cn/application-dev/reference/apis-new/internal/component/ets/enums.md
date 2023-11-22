# enums    
枚举说明。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## Color    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| White | 0 | 0xffffff |  
| Black | 1 | 0x000000 |  
| Blue | 2 |  |  
| Brown | 3 | 0xa52a2a |  
| Gray | 4 | 0x808080 |  
| Green | 5 | 0x008000 |  
| Grey | 6 | 0x808080 |  
| Orange | 7 | 0xffa500 |  
| Pink | 8 | 0xffc0cb |  
| Red | 9 | 0xff0000 |  
| Yellow | 10 | 0xffff00 |  
| Transparent<sup>(9+)</sup> | 11 | rgba(0,0,0,0) |  
    
## ColoringStrategy<sup>(10+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| INVERT | invert |  |  
    
## ImageFit    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Contain | 0 | 保持宽高比进行缩小或者放大，使得图片完全显示在显示边界内。 |  
| Cover | 1 | 保持宽高比进行缩小或者放大，使得图片两边都大于或等于显示边界。 |  
| Auto | 2 | 自适应显示 |  
| Fill | 3 | 不保持宽高比进行放大缩小，使得图片充满显示边界。 |  
| ScaleDown | 4 | 保持宽高比显示，图片缩小或者保持不变。 |  
| None | 5 | 保持原有尺寸显示。 |  
    
## BorderStyle    
。    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Dotted | 0 | 显示为一系列圆点，圆点半径为borderWidth的一半。<br/> |  
| Dashed | 1 | 显示为一系列短的方形虚线。 |  
| Solid | 2 | 显示为一条实线。 |  
    
## LineJoinStyle    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Miter | 0 | 使用尖角连接路径段。 |  
| Round | 1 | 使用圆角连接路径段。 |  
| Bevel | 2 | 使用斜角连接路径段。 |  
    
## TouchType    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Down | 0 | 手指按下时触发。 |  
| Up | 1 | 手指抬起时触发。 |  
| Move | 2 | 手指按压态在屏幕上移动时触发。 |  
| Cancel | 3 | 触摸事件取消时触发。 |  
    
## MouseButton<sup>(8+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Left | 0 | 鼠标左键。 |  
| Right | 1 | 鼠标右键。 |  
| Middle | 2 | 鼠标中键。 |  
| Back | 3 | 鼠标左侧后退键。 |  
| Forward | 4 | 鼠标左侧前进键。 |  
| None | 5 | 无按键。 |  
    
## MouseAction<sup>(8+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Press | 0 | 鼠标按键按下。 |  
| Release | 1 | 鼠标按键松开。 |  
| Move | 2 | 鼠标移动。 |  
| Hover | 3 | 鼠标悬浮。 |  
    
## AnimationStatus    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Initial | 0 | 动画初始状态。 |  
| Running | 1 | 动画处于播放状态。 |  
| Paused | 2 | 动画处于暂停状态。 |  
| Stopped | 3 | 动画处于停止状态。 |  
    
## Curve    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Linear | 0 | 表示动画从头到尾的速度都是相同的。 |  
| Ease | 1 | 表示动画以低速开始，然后加快，在结束前变慢，CubicBezier(0.25, 0.1, 0.25, 1.0)。 |  
| EaseIn | 2 | 表示动画以低速开始，CubicBezier(0.42, 0.0, 1.0, 1.0)。 |  
| EaseOut | 3 | 表示动画以低速结束，CubicBezier(0.0, 0.0, 0.58, 1.0)。 |  
| EaseInOut | 4 | 表示动画以低速开始和结束，CubicBezier(0.42, 0.0, 0.58, 1.0)。 |  
| FastOutSlowIn | 5 | 标准曲线，cubic-bezier(0.4, 0.0, 0.2, 1.0)。 |  
| LinearOutSlowIn | 6 | 减速曲线，cubic-bezier(0.0, 0.0, 0.2, 1.0)。 |  
| FastOutLinearIn | 7 | 加速曲线，cubic-bezier(0.4, 0.0, 1.0, 1.0)。 |  
| ExtremeDeceleration | 8 | 急缓曲线，cubic-bezier(0.0, 0.0, 0.0, 1.0)。 |  
| Sharp | 9 | 锐利曲线，cubic-bezier(0.33, 0.0, 0.67, 1.0)。 |  
| Rhythm | 10 | 节奏曲线，cubic-bezier(0.7, 0.0, 0.2, 1.0)。 |  
| Smooth | 11 | 平滑曲线，cubic-bezier(0.4, 0.0, 0.4, 1.0)。 |  
| Friction | 12 | 阻尼曲线，CubicBezier(0.2, 0.0, 0.2, 1.0)。 |  
    
## FillMode    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| None | 0 | 动画未执行时不会将任何样式应用于目标，动画播放完成之后恢复初始默认状态。 |  
| Forwards | 1 | 目标将保留动画执行期间最后一个关键帧的状态。 |  
| Backwards | 2 | 动画将在应用于目标时立即应用第一个关键帧中定义的值，并在delay期间保留此值。第一个关键帧取决于playMode，playMode为Normal或Alternate时为from的状态，playMode为Reverse或AlternateReverse时为to的状态。 |  
| Both | 3 | 动画将遵循Forwards和Backwards的规则，从而在两个方向上扩展动画属性。 |  
    
## PlayMode    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Normal | 0 | 动画按正向播放。 |  
| Reverse | 1 | 动画反向播放。 |  
| Alternate | 2 | 动画在奇数次（1、3、5...）正向播放，在偶数次（2、4、6...）反向播放。 |  
| AlternateReverse | 3 | 动画在奇数次（1、3、5...）反向播放，在偶数次（2、4、6...）正向播放。 |  
    
## KeyType    
按键按下。    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Down | 0 | 按键按下。 |  
| Up | 1 | 按键松开。 |  
    
## KeySource    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Unknown | 0 | 输入设备类型未知。 |  
| Keyboard | 1 | 输入设备类型为键盘。 |  
    
## Edge    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Top | 0 | 竖直方向上边缘 |  
| Center<sup>(deprecated)</sup> | 1 | 从API version 7 开始支持，从API version 9 开始废弃。<br>竖直方向居中位置 |  
| Bottom | 2 | 竖直方向下边缘 |  
| Baseline<sup>(deprecated)</sup> | 3 | 从API version 7 开始支持，从API version 9 开始废弃。<br>交叉轴方向文本基线位置 |  
| Start | 4 | 水平方向起始位置 |  
| Middle<sup>(deprecated)</sup> | 5 | 从API version 7 开始支持，从API version 9 开始废弃。<br>水平方向居中位置 |  
| End | 6 | 水平方向末尾位置 |  
    
## Week    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Mon | 0 | 星期一 |  
| Tue | 1 | 星期二 |  
| Wed | 2 | 星期三 |  
| Thur | 3 | 星期四 |  
| Fri | 4 | 星期五 |  
| Sat | 5 | 星期六 |  
| Sun | 6 | 星期日 |  
    
## Direction    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Ltr | 0 | 元素从左到右布局。 |  
| Rtl | 1 | 元素从右到左布局。 |  
| Auto | 2 | 使用系统默认布局方向。 |  
    
## BarState    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Off | 0 | 不显示。 |  
| Auto | 1 | 常驻显示。 |  
| On | 2 | 按需显示(触摸时显示，2s后消失)。 |  
    
## EdgeEffect    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Spring | 0 | 弹性物理动效，滑动到边缘后可以根据初始速度或通过触摸事件继续滑动一段距离，松手后回弹。 |  
| Fade | 1 | 阴影效果，滑动到边缘后会有圆弧状的阴影。 |  
| None | 2 | 滑动到边缘后无效果。 |  
    
## Alignment    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| TopStart | 0 | 顶部起始端。 |  
| Top | 1 | 顶部横向居中。 |  
| TopEnd | 2 | 顶部尾端。 |  
| Start | 3 | 起始端纵向居中。 |  
| Center | 4 | 横向和纵向居中。 |  
| End | 5 | 尾端纵向居中。 |  
| BottomStart | 6 | 底部起始端。 |  
| Bottom | 7 | 底部横向居中。 |  
| BottomEnd | 8 | 底部尾端。 |  
    
## TransitionType    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| All | 0 | 指定当前的Transition动效生效在组件的所有变化场景。 |  
| Insert | 1 | 指定当前的Transition动效生效在组件的插入显示场景。 |  
| Delete | 2 | 指定当前的Transition动效生效在组件的删除隐藏场景。 |  
    
## RelateType    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| FILL | 0 | 缩放当前子组件以填充满父组件 |  
| FIT | 1 | 缩放当前子组件以自适应父组件 |  
    
## Visibility    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Visible | 0 | 显示。 |  
| Hidden | 1 | 隐藏，但参与布局进行占位。 |  
| None | 2 | 隐藏，但不参与布局，不进行占位。 |  
    
## LineCapStyle    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Butt | 0 | 线条两端为平行线，不额外扩展。 |  
| Round | 1 | 在线条两端延伸半个圆，直径等于线宽。 |  
| Square | 2 | 在线条两端延伸一个矩形，宽度等于线宽的一半，高度等于线宽。 |  
    
## Axis    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Vertical | 0 | 方向为纵向。 |  
| Horizontal | 1 | 方向为横向。 |  
    
## HorizontalAlign    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Start | 0 | 按照语言方向起始端对齐。 |  
| Center | 1 | 居中对齐，默认对齐方式。 |  
| End | 2 | 按照语言方向末端对齐。 |  
    
## FlexAlign    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Start | 0 | 元素在主轴方向首端对齐，第一个元素与行首对齐，同时后续的元素与前一个对齐。 |  
| Center | 1 | 元素在主轴方向中心对齐，第一个元素与行首的距离与最后一个元素与行尾距离相同。 |  
| End | 2 | 元素在主轴方向尾部对齐，最后一个元素与行尾对齐，其他元素与后一个对齐。 |  
| SpaceBetween | 3 | Flex主轴方向均匀分配弹性元素，相邻元素之间距离相同。第一个元素与行首对齐，最后一个元素与行尾对齐。 |  
| SpaceAround | 4 | Flex主轴方向均匀分配弹性元素，相邻元素之间距离相同。第一个元素到行首的距离和最后一个元素到行尾的距离是相邻元素之间距离的一半。 |  
| SpaceEvenly | 5 | Flex主轴方向均匀分配弹性元素，相邻元素之间的距离、第一个元素与行首的间距、最后一个元素到行尾的间距都完全一样。 |  
    
## ItemAlign    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Auto | 0 | 使用Flex容器中默认配置。 |  
| Start | 1 | 元素在Flex容器中，交叉轴方向首部对齐。 |  
| Center | 2 | 元素在Flex容器中，交叉轴方向居中对齐。 |  
| End | 3 | 元素在Flex容器中，交叉轴方向底部对齐。 |  
| Baseline | 4 | 元素在Flex容器中，交叉轴方向文本基线对齐。 |  
| Stretch | 5 | 元素在Flex容器中，交叉轴方向拉伸填充。容器为Flex且设置Wrap为FlexWrap.Wrap或FlexWrap.WrapReverse时，元素拉伸到与当前行/列交叉轴长度最长的元素尺寸。其余情况在元素未设置尺寸时，拉伸到容器尺寸。 |  
    
## FlexDirection    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Row | 0 | 主轴与行方向一致作为布局模式。 |  
| Column | 1 | 主轴与列方向一致作为布局模式。 |  
| RowReverse | 2 | 与Row方向相反方向进行布局。 |  
| ColumnReverse | 3 | 与Column相反方向进行布局。 |  
    
## FlexWrap    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NoWrap | 0 | Flex容器的元素单行/列布局，子项不允许超出容器。 |  
| Wrap | 1 | Flex容器的元素多行/列排布，子项允许超出容器。 |  
| WrapReverse | 2 | Flex容器的元素反向多行/列排布，子项允许超出容器。 |  
    
## VerticalAlign    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Top | 0 | 顶部对齐。 |  
| Center | 1 | 居中对齐，默认对齐方式。 |  
| Bottom | 2 | 底部对齐。 |  
    
## ImageRepeat    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NoRepeat | 0 | 不重复绘制图片。 |  
| X | 1 | 只在水平轴上重复绘制图片。 |  
| Y | 2 | 只在水平轴上重复绘制图片。 |  
| XY | 3 | 在两个轴上重复绘制图片。 |  
    
## ImageSize    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Auto | 0 | 保持原图的比例不变。 |  
| Cover | 1 | 默认值，保持宽高比进行缩小或者放大，使得图片两边都大于或等于显示边界。 |  
| Contain | 2 | 保持宽高比进行缩小或者放大，使得图片完全显示在显示边界内。 |  
    
## GradientDirection    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Left | 0 | 从右向左。 |  
| Top | 1 | 从下向上。 |  
| Right | 2 | 从左向右。 |  
| Bottom | 3 | 从上向下。 |  
| LeftTop | 4 | 左上。 |  
| LeftBottom | 5 | 左下。 |  
| RightTop | 6 | 右上。 |  
| RightBottom | 7 | 右下。 |  
| None | 8 | 无。 |  
    
## SharedTransitionEffectType    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Static | 0 | 目标页面元素的位置保持不变，可以配置透明度动画。目前，只有为重定向到目标页面而配置的静态效果才会生效。 |  
| Exchange | 1 | 将源页面元素移动到目标页面元素位置并适当缩放。 |  
    
## FontStyle    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Normal | 0 | 标准的字体样式。 |  
| Italic | 1 | 斜体的字体样式。 |  
    
## FontWeight    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Lighter | 0 | 字体较细。 |  
| Normal | 1 | 字体粗细正常。 |  
| Regular | 2 | 字体粗细正常。 |  
| Medium | 3 | 字体粗细适中。 |  
| Bold | 4 | 字体较粗。 |  
| Bolder | 5 | 字体非常粗。 |  
    
## TextAlign    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Center | 0 | 水平居中对齐。 |  
| Start | 1 | 水平对齐首部。 |  
| End | 2 | 水平对齐尾部。 |  
| JUSTIFY<sup>(10+)</sup> | 3 | 双端对齐。 |  
    
## TextOverflow    
  
    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| None | 0 | 文本超长时裁剪显示。<br/> |  
| Clip | 1 | 文本超长时进行裁剪显示。 |  
| Ellipsis | 2 | 文本超长时显示不下的文本用省略号代替。 |  
| MARQUEE<sup>(10+)</sup> | 3 | 文本超长时以跑马灯的方式展示。 |  
    
## TextDecorationType    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| None | 0 | 不使用文本装饰线。 |  
| Underline | 1 | 文字下划线修饰。 |  
| Overline | 2 | 文字上划线修饰。 |  
| LineThrough | 3 | 穿过文本的修饰线。 |  
    
## TextCase    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Normal | 0 | 保持文本原有大小写。 |  
| LowerCase | 1 | 文本采用全小写。 |  
| UpperCase | 2 | 文本采用全大写。 |  
    
## TextHeightAdaptivePolicy<sup>(10+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| MAX_LINES_FIRST | 0 | 设置文本高度自适应方式为以MaxLines优先。 |  
| MIN_FONT_SIZE_FIRST | 1 | 设置文本高度自适应方式为以缩小字体优先。 |  
| LAYOUT_CONSTRAINT_FIRST | 2 | 设置文本高度自适应方式为以布局约束（高度）优先。 |  
    
## ResponseType<sup>(8+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| RightClick | 0 | 通过鼠标右键触发菜单弹出。 |  
| LongPress | 1 | 通过长按触发菜单弹出。 |  
    
## HoverEffect<sup>(8+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Auto | 0 | 使用组件的系统默认悬浮效果。 |  
| Scale | 1 | 放大缩小效果。 |  
| Highlight | 2 | 背景淡入淡出的强调效果。 |  
| None | 3 | 不设置效果。 |  
    
## Placement<sup>(8+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Left | 0 | 气泡提示位于组件左侧，与组件左侧中心对齐。 |  
| Right | 1 | 气泡提示位于组件右侧，与组件右侧中心对齐。 |  
| Top | 2 | 气泡提示位于组件上侧，与组件上侧中心对齐。 |  
| Bottom | 3 | 气泡提示位于组件下侧，与组件下侧中心对齐。 |  
| TopLeft | 4 | 气泡提示位于组件上侧，从API Version 9开始，与组件左侧边缘对齐。 |  
| TopRight | 5 | 气泡提示位于组件上侧，从API Version 9开始，与组件右侧边缘对齐。 |  
| BottomLeft | 6 | 气泡提示位于组件下侧，从API Version 9开始，与组件左侧边缘对齐。 |  
| BottomRight | 7 | 气泡提示位于组件下侧，从API Version 9开始，与组件右侧边缘对齐。 |  
| LeftTop<sup>(9+)</sup> | 8 | 气泡提示位于组件左侧，与组件上侧边缘对齐。   |  
| LeftBottom<sup>(9+)</sup> | 9 | 气泡提示位于组件左侧，与组件下侧边缘对齐。 |  
| RightTop<sup>(9+)</sup> | 10 | 气泡提示位于组件右侧，与组件上侧边缘对齐。 |  
| RightBottom<sup>(9+)</sup> | 11 | 气泡提示位于组件右侧，与组件下侧边缘对齐。 |  
    
## CopyOptions<sup>(9+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| None | 0 | 不支持复制。 |  
| InApp | 1 | 支持应用内复制。 |  
| LocalDevice | 2 | 支持设备内复制。 |  
    
## HitTestMode<sup>(9+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Default | 0 | 自身节点和子节点都响应触摸事件的命中测试，但会阻止被该节点屏蔽的其他节点的命中测试。 |  
| Block | 1 | 自身节点响应触摸事件的命中测试，但阻止被该节点屏蔽的子节点和其他节点的命中测试。 |  
| Transparent | 2 | 自身节点和子节点响应触摸事件的命中测试，并允许对被该节点屏蔽的其他节点进行命中测试。 |  
| None | 3 | 自身节点不会响应触摸事件的命中测试，但子节点会对触摸事件进行命中测试。 |  
    
## TitleHeight<sup>(9+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| MainOnly | 0 |  |  
| MainWithSub | 1 |  |  
    
## ModifierKey<sup>(10+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CTRL | 0 |  |  
| SHIFT | 1 |  |  
| ALT | 2 |  |  
    
## FunctionKey<sup>(10+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| ESC | 0 |  |  
| F1 | 1 |  |  
| F2 | 2 |  |  
| F3 | 3 |  |  
| F4 | 4 |  |  
| F5 | 5 |  |  
| F6 | 6 |  |  
| F7 | 7 |  |  
| F8 | 8 |  |  
| F9 | 9 |  |  
| F10 | 10 |  |  
| F11 | 11 |  |  
| F12 | 12 |  |  
    
## ImageSpanAlignment<sup>(10+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| BASELINE | 0 |  |  
| BOTTOM | 1 |  |  
| CENTER | 2 |  |  
| TOP | 3 |  |  
    
## ObscuredReasons<sup>(10+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| PLACEHOLDER | 0 | 显示的数据为通用占位符。 |  
    
## TextContentStyle<sup>(10+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DEFAULT | 0 | 默认风格，光标宽1.5vp，光标高度与文本选中底板高度和字体大小相关。 |  
| INLINE | 1 | 内联输入风格。文本选中底板高度与输入框高度相同。<br/>不支持showError属性。 |  
    
## ClickEffectLevel<sup>(10+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| LIGHT | 0 | 小面积（轻盈）；弹簧动效， 刚性：410，阻尼：38，初始速度：1；默认缩放比：90%<br/> |  
| MIDDLE | 1 | 中面积（稳定）；弹簧动效， 刚性：350，阻尼：35，初始速度：0.5；默认缩放比：95%<br/> |  
| HEAVY | 2 | 大面积（厚重）；弹簧动效， 刚性：240，阻尼：28，初始速度：0；默认缩放比：95%。 |  
    
## XComponentType<sup>(10+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SURFACE | 0 |  |  
| COMPONENT | 1 |  |  
| TEXTURE | 2 |  |  
    
## NestedScrollMode<sup>(10+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SELF_ONLY | 0 |  |  
| SELF_FIRST | 1 |  |  
| PARENT_FIRST | 2 |  |  
| PARALLEL | 3 |  |  
    
## RenderFit<sup>(10+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CENTER | 0 |  |  
| TOP | 1 |  |  
| BOTTOM | 2 |  |  
| LEFT | 3 |  |  
| RIGHT | 4 |  |  
| TOP_LEFT | 5 |  |  
| TOP_RIGHT | 6 |  |  
| BOTTOM_LEFT | 7 |  |  
| BOTTOM_RIGHT | 8 |  |  
| RESIZE_FILL | 9 |  |  
| RESIZE_CONTAIN | 10 |  |  
| RESIZE_CONTAIN_TOP_LEFT | 11 |  |  
| RESIZE_CONTAIN_BOTTOM_RIGHT | 12 |  |  
| RESIZE_COVER | 13 |  |  
| RESIZE_COVER_TOP_LEFT | 14 |  |  
| RESIZE_COVER_BOTTOM_RIGHT | 15 |  |  
    
## DialogButtonStyle<sup>(10+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DEFAULT | 0 |  |  
| HIGHLIGHT | 1 |  |  
