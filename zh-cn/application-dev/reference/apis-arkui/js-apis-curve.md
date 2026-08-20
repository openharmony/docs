# @ohos.curves (插值计算)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

本模块提供设置动画插值曲线功能，用于构造阶梯曲线对象、三阶贝塞尔曲线对象、弹簧曲线对象、弹性动画曲线对象、弹性跟手动画曲线对象、插值器弹簧曲线对象和自定义曲线对象。

> **说明：**
> 
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import { curves } from '@kit.ArkUI';
```


## curves.initCurve<sup>9+</sup>

initCurve(curve?: Curve): ICurve

插值曲线的初始化函数，可以根据入参创建一个插值曲线对象。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型            | 必填 | 说明                                |
| ------ | --------------- | ---- | ----------------------------------- |
| curve  | [Curve](#curve) | 否   | 曲线类型。<br>默认值：Curve.Linear |

**返回值：**

| 类型                           | 说明             |
| ---------------------------------- | ---------------- |
| [ICurve](#icurve9) | 曲线的插值对象，可通过其interpolate方法获取指定归一化时间点的曲线插值。 |

## Curve

插值曲线和动效请参考<!--RP1-->[贝塞尔曲线](../../../design/ux-design/animation-attributes.md)<!--RP1End-->。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

| 名称                | 值 | 说明                                                         |
| ------------------- | -- | ------------------------------------------------------------ |
| Linear              | 0 | 表示动画从头到尾的速度都是相同的。                           |
| Ease                | 1 | 表示动画以低速开始，然后加快，在结束前变慢，cubic-bezier(0.25, 0.1, 0.25, 1.0)。 |
| EaseIn              | 2 | 表示动画以低速开始，cubic-bezier(0.42, 0.0, 1.0, 1.0)。       |
| EaseOut             | 3 | 表示动画以低速结束，cubic-bezier(0.0, 0.0, 0.58, 1.0)。       |
| EaseInOut           | 4 | 表示动画以低速开始和结束，cubic-bezier(0.42, 0.0, 0.58, 1.0)。 |
| FastOutSlowIn       | 5 | 标准曲线，cubic-bezier(0.4, 0.0, 0.2, 1.0)。                 |
| LinearOutSlowIn     | 6 | 减速曲线，cubic-bezier(0.0, 0.0, 0.2, 1.0)。                 |
| FastOutLinearIn     | 7 | 加速曲线，cubic-bezier(0.4, 0.0, 1.0, 1.0)。                 |
| ExtremeDeceleration | 8 | 极缓曲线，cubic-bezier(0.0, 0.0, 0.0, 1.0)。                 |
| Sharp               | 9 | 锐利曲线，cubic-bezier(0.33, 0.0, 0.67, 1.0)。               |
| Rhythm              | 10 | 节奏曲线，cubic-bezier(0.7, 0.0, 0.2, 1.0)。                 |
| Smooth              | 11 | 平滑曲线，cubic-bezier(0.4, 0.0, 0.4, 1.0)。                 |
| Friction            | 12 | 阻尼曲线，cubic-bezier(0.2, 0.0, 0.2, 1.0)。                 |

**示例：**

```ts
import { curves } from '@kit.ArkUI';
curves.initCurve(Curve.EaseIn); // 创建一个默认先慢后快插值曲线
```


## curves.stepsCurve<sup>9+</sup>

stepsCurve(count: number, end: boolean): ICurve

构造阶梯曲线对象，将动画过程划分为若干等距间隔，在每个间隔的起点或终点发生阶跃变化。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ----| ------------------------------------------------------------ |
| count  | number  | 是   | 阶梯的数量，需要为正整数。<br>取值范围：[1, +∞)<br>**说明：** <br>设置小于1的值时，按值为1处理；传入非整数时，向下取整处理。 |
| end    | boolean | 是   | 在每个间隔的起点或终点发生阶跃变化。<br>-true：在终点发生阶跃变化。<br>-false：在起点发生阶跃变化。 |

**返回值：**

| 类型                           | 说明             |
| ---------------------------------- | ---------------- |
| [ICurve](#icurve9) | 曲线的插值对象，可通过其interpolate方法获取指定归一化时间点的曲线插值。 |

**示例：**

```ts
import { curves } from '@kit.ArkUI';
curves.stepsCurve(9, true);  // 创建一个阶梯曲线
```


## curves.cubicBezierCurve<sup>9+</sup>

cubicBezierCurve(x1: number, y1: number, x2: number, y2: number): ICurve

构造三阶贝塞尔曲线对象，曲线的两个控制点横坐标x1、x2的取值范围限定在0到1之间。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| x1     | number | 是   | 确定贝塞尔曲线第一点横坐标。<br>取值范围：[0, 1]<br>**说明：** <br>设置的值小于0时，按0处理；设置的值大于1时，按1处理。 |
| y1     | number | 是   | 确定贝塞尔曲线第一点纵坐标。<br>取值范围：(-∞, +∞)<br>**说明：** <br>值在[0,1]范围内时，曲线不会超出动画起止值；值不在[0,1]范围内时，动画过程中会超出起止值范围。 |
| x2     | number | 是   | 确定贝塞尔曲线第二点横坐标。<br>取值范围：[0, 1]<br>**说明：** <br>设置的值小于0时，按0处理；设置的值大于1时，按1处理。 |
| y2     | number | 是   | 确定贝塞尔曲线第二点纵坐标。<br>取值范围：(-∞, +∞)<br>**说明：** <br>值在[0,1]范围内时，曲线不会超出动画起止值；值不在[0,1]范围内时，动画过程中会超出起止值范围。 |

**返回值：**

| 类型                           | 说明             |
| ---------------------------------- | ---------------- |
| [ICurve](#icurve9) | 曲线的插值对象，可通过其interpolate方法获取指定归一化时间点的曲线插值。 |


**示例：**

```ts
import { curves } from '@kit.ArkUI';
curves.cubicBezierCurve(0.1, 0.0, 0.1, 1.0); // 创建一个三阶贝塞尔曲线
```


## curves.springCurve<sup>9+</sup>

springCurve(velocity: number, mass: number, stiffness: number, damping: number): ICurve

构造弹簧曲线对象，曲线形状由弹簧参数决定，动画时长受动画参数中的时长参数控制。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**
| 参数名    | 类型   | 必填 | 说明                                                         |
| --------- | ------ | ---- | ------------------------------------------------------------ |
| velocity  | number | 是   | 初始速度。外部因素对弹性动效产生的影响参数，目的是保证对象从之前的运动状态平滑地过渡到弹性动效。该速度是归一化速度，其值等于动画开始时的实际速度除以动画属性改变值。<br>取值范围：(-∞, +∞) |
| mass      | number | 是   | 质量。弹性系统的受力对象，会对弹性系统产生惯性影响。质量越大，震荡的幅度越大，恢复到平衡位置的速度越慢。<br>取值范围：(0, +∞)<br>**说明：** <br>设置的值小于等于0时，按1处理。 |
| stiffness | number | 是   | 刚度。物体抵抗施加的力而形变的程度。在弹性系统中，刚度越大，抵抗变形的能力越强，恢复到平衡位置的速度就越快。<br>取值范围：(0, +∞)<br>**说明：** <br>设置的值小于等于0时，按1处理。 |
| damping   | number | 是   | 阻尼。弹性系统中的阻尼系数，用于描述系统在受到扰动后震荡及衰减的情形。阻尼越大，弹性运动的震荡次数越少、震荡幅度越小。<br>取值范围：(0, +∞)<br>**说明：** <br>设置的值小于等于0时，按1处理。 |


**返回值：**

| 类型                           | 说明             |
| ---------------------------------- | ---------------- |
| [ICurve](#icurve9) | 曲线的插值对象，可通过其interpolate方法获取指定归一化时间点的曲线插值。 |


**示例：**

```ts
import { curves } from '@kit.ArkUI';
curves.springCurve(10, 1, 228, 30); // 创建一个弹簧插值曲线
```


## curves.springMotion<sup>9+</sup>

springMotion(response?: number, dampingFraction?: number, overlapDuration?: number): ICurve

构造弹性动画曲线对象。与使用弹簧物理参数的[curves.springCurve](#curvesspringcurve9)不同，springMotion使用响应式参数构造曲线，且支持动画间的速度继承，需要速度继承的连续弹性动画建议使用springMotion。如果对同一对象的同一属性进行多个弹性动画，每个动画会替换掉前一个动画，并继承之前的速度。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名       | 类型     | 必填   | 说明    |
| --------- | ------ | ---- | ----- |
| response  | number | 否    | 弹簧自然振动周期，决定弹簧复位的速度。<br>默认值：0.55<br>单位：秒<br>取值范围：(0, +∞)<br>**说明：** <br>设置小于等于0的值时，按默认值0.55处理。 |
| dampingFraction      | number | 否    | 阻尼系数。<br>0表示无阻尼，一直处于震荡状态；<br>大于0小于1的值为欠阻尼，运动过程中会超出目标值；<br>等于1为临界阻尼；<br>大于1为过阻尼，运动过程中逐渐趋于目标值。<br>默认值：0.825<br>取值范围：[0, +∞)<br>**说明：** <br>设置小于0的值时，按默认值0.825处理。 |
| overlapDuration | number | 否    | 弹性动画衔接时长。发生动画继承时，如果前后两个弹性动画response不一致，response参数会在overlapDuration时间内平滑过渡；当overlapDuration为0时，response参数不会进行平滑过渡，而是立即切换到新的response值。<br>默认值：0<br>单位：秒<br>取值范围：[0, +∞)<br> **说明：**  <br>设置小于0的值时，按默认值0处理。<br>弹性动画曲线为物理曲线，[animation](arkui-ts/ts-animatorproperty.md)、[animateTo](arkui-ts/ts-explicit-animation.md)、[pageTransition](arkui-ts/ts-page-transition-animation.md)中的duration参数不生效，动画持续时间取决于springMotion动画曲线参数和之前的速度。时间不能归一，故不能通过该曲线的interpolate函数获得插值。 |


**返回值：**

| 类型                           | 说明             |
| ---------------------------------- | ---------------- |
| [ICurve](#icurve9) | 曲线对象。<br>**说明：**  <br>弹性动画曲线为物理曲线，[animation](arkui-ts/ts-animatorproperty.md)、[animateTo](arkui-ts/ts-explicit-animation.md)、[pageTransition](arkui-ts/ts-page-transition-animation.md)中的duration参数不生效，动画持续时间取决于springMotion动画曲线参数和之前的速度。时间不能归一，故不能通过该曲线的[interpolate](#interpolate9)函数获得插值。 |

**示例：**

```ts
import { curves } from '@kit.ArkUI';
curves.springMotion(); // 创建一个默认弹性动画曲线
curves.springMotion(0.5); // 创建指定response、其余参数默认的弹性动画曲线
curves.springMotion(0.5, 0.6); // 创建指定response和dampingFraction、其余参数默认的弹性动画曲线
curves.springMotion(0.5, 0.6, 0); // 创建三个参数均自定义的弹性动画曲线
```


## curves.responsiveSpringMotion<sup>9+</sup>

responsiveSpringMotion(response?: number, dampingFraction?: number, overlapDuration?: number): ICurve

构造弹性跟手动画曲线对象，是[springMotion](#curvesspringmotion9)的一种特例，仅默认参数不同，可与springMotion混合使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名       | 类型     | 必填   | 说明    |
| --------- | ------ | ---- | ----- |
| response  | number | 否    | 解释同springMotion中的response。<br>默认值：0.15<br>单位：秒<br>取值范围：(0, +∞)<br>**说明：** <br>设置小于等于0的值时，按默认值0.15处理。 |
| dampingFraction      | number | 否    | 解释同springMotion中的dampingFraction。<br>默认值：0.86<br>取值范围：[0, +∞)<br>**说明：** <br>设置小于0的值时，按默认值0.86处理。 |
| overlapDuration | number | 否    | 解释同springMotion中的overlapDuration。当overlapDuration为0时，response参数不会进行平滑过渡，而是立即切换到新的response值。<br>默认值：0.25<br>单位：秒<br>取值范围：[0, +∞)<br>**说明：** <br>设置小于0的值时，按默认值0.25处理。<br>弹性跟手动画曲线为springMotion的一种特例，仅默认值不同。如果使用自定义参数的弹性曲线，推荐使用springMotion构造曲线。如果使用跟手动画，推荐使用默认参数的弹性跟手动画曲线。<br>[animation](arkui-ts/ts-animatorproperty.md)、[animateTo](arkui-ts/ts-explicit-animation.md)、[pageTransition](arkui-ts/ts-page-transition-animation.md)中的duration参数不生效，动画持续时间取决于responsiveSpringMotion动画曲线参数和之前的速度，也不能通过该曲线的interpolate函数获得插值。 |

**返回值：**

| 类型                           | 说明             |
| ---------------------------------- | ---------------- |
| [ICurve](#icurve9) | 曲线对象。<br>**说明：** <br>1、弹性跟手动画曲线为springMotion的一种特例，仅默认值不同。如果使用自定义参数的弹性曲线，推荐使用springMotion构造曲线；如果使用跟手动画，推荐使用默认参数的弹性跟手动画曲线。<br>2、[animation](arkui-ts/ts-animatorproperty.md)、[animateTo](arkui-ts/ts-explicit-animation.md)、[pageTransition](arkui-ts/ts-page-transition-animation.md)中的duration参数不生效，动画持续时间取决于responsiveSpringMotion动画曲线参数和之前的速度，也不能通过该曲线的[interpolate](#interpolate9)函数获得插值。 |

**示例：**

```ts
import { curves } from '@kit.ArkUI';
curves.responsiveSpringMotion(); // 创建一个默认弹性跟手动画曲线
```


## curves.interpolatingSpring<sup>10+</sup>

interpolatingSpring(velocity: number, mass: number, stiffness: number, damping: number): ICurve

构造插值器弹簧曲线对象，生成一条从0到1的动画曲线，实际动画值根据曲线进行插值计算。动画时间由曲线参数决定，不受动画参数中的时长参数控制。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**
| 参数名       | 类型     | 必填   | 说明    |
| --------- | ------ | ---- | ----- |
| velocity  | number | 是    | 初始速度。外部因素对弹性动效产生的影响参数，目的是保证对象从之前的运动状态平滑地过渡到弹性动效。该速度是归一化速度，其值等于动画开始时的实际速度除以动画属性改变值。<br>取值范围：(-∞, +∞) |
| mass      | number | 是    | 质量。弹性系统的受力对象，会对弹性系统产生惯性影响。质量越大，震荡的幅度越大，恢复到平衡位置的速度越慢。<br>取值范围：(0, +∞)<br>**说明：** <br>设置的值小于等于0时，按1处理。 |
| stiffness | number | 是    | 刚度。表示物体抵抗施加的力而形变的程度。刚度越大，抵抗变形的能力越强，恢复到平衡位置的速度越快。<br>取值范围：(0, +∞)<br>**说明：** <br>设置的值小于等于0时，按1处理。 |
| damping   | number | 是    | 阻尼。弹性系统中的阻尼系数，用于描述系统在受到扰动后震荡及衰减的情形。阻尼越大，弹性运动的震荡次数越少、震荡幅度越小。<br>取值范围：(0, +∞)<br>**说明：** <br>设置的值小于等于0时，按1处理。 |

**返回值：**

| 类型                           | 说明             |
| ---------------------------------- | ---------------- |
| [ICurve](#icurve9) | 曲线对象。<br>**说明：** 弹性动画曲线为物理曲线，[animation](arkui-ts/ts-animatorproperty.md)、[animateTo](arkui-ts/ts-explicit-animation.md)、[pageTransition](arkui-ts/ts-page-transition-animation.md)等动画参数中的duration参数不生效，动画持续时间取决于interpolatingSpring动画曲线参数。时间不能归一，故不能通过该曲线的[interpolate](#interpolate9)函数获得插值。 |

**示例：**

```ts
import { curves } from '@kit.ArkUI';
curves.interpolatingSpring(10, 1, 228, 30); // 创建一个时长由弹簧参数决定的弹簧插值曲线
```

## curves.customCurve<sup>10+</sup>

customCurve(interpolate: (fraction: number) => number): ICurve

构造自定义曲线对象，用户通过自定义插值函数决定曲线的形状。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型                         | 必填 | 说明                                                         |
| ----------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| interpolate | (fraction: number) => number | 是   | 用户自定义的插值回调函数。<br>fraction为插值计算的输入x值，表示动画的归一化时间位置。取值范围：[0,1]<br>返回值为曲线的y值。取值范围：(-∞, +∞)<br>**说明：**<br>fraction等于0时，返回值为0对应动画起点，返回不为0，动画在起点处有跳变效果。<br>fraction等于1时，返回值为1对应动画终点，返回值不为1将导致动画的终值不是状态变量的值，出现大于或者小于状态变量值，再跳变到状态变量值的效果。 |

**返回值：**

| 类型               | 说明             |
| ------------------ | ---------------- |
| [ICurve](#icurve9) | 曲线的插值对象，可通过其interpolate方法获取指定归一化时间点的曲线插值。 |

**示例：**

```ts
import { curves } from '@kit.ArkUI';
let interpolate = (fraction: number): number => {
  return Math.sqrt(fraction);
};
let curve = curves.customCurve(interpolate); // 创建一个用户自定义插值曲线
```

## ICurve<sup>9+</sup>

曲线对象，支持通过本模块中的[curves.initCurve](#curvesinitcurve9)、[curves.stepsCurve](#curvesstepscurve9)、[curves.cubicBezierCurve](#curvescubicbeziercurve9)、[curves.springCurve](#curvesspringcurve9)、[curves.springMotion](#curvesspringmotion9)、[curves.responsiveSpringMotion](#curvesresponsivespringmotion9)、[curves.interpolatingSpring](#curvesinterpolatingspring10)、[curves.customCurve](#curvescustomcurve10)方法创建不同类型的曲线对象，并可通过曲线对象调用其[interpolate](#interpolate9)的成员方法。其中springMotion、responsiveSpringMotion、interpolatingSpring创建的弹性动画曲线为物理曲线，时间不能归一，不能通过interpolate函数获得插值。

### interpolate<sup>9+</sup>

interpolate(fraction:&nbsp;number): number

插值曲线的插值计算函数，可以通过传入的归一化时间参数返回当前的插值。对于springMotion、responsiveSpringMotion、interpolatingSpring等物理曲线，时间不能归一化，调用interpolate函数无法获得有效插值。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| fraction | number | 是   | 当前的归一化时间参数。<br>取值范围：[0,1]<br>**说明：** <br>设置的值小于0时，按0处理；设置的值大于1时，按1处理。<br>对于springMotion、responsiveSpringMotion、interpolatingSpring创建的弹性动画曲线，时间不能归一，此参数无意义，不能通过interpolate函数获得有效插值。 |

**返回值：**

| 类型   | 说明                                 |
| ------ | ------------------------------------ |
| number | 返回归一化时间点对应的曲线插值。 |

**示例：**

```ts
import { curves } from '@kit.ArkUI'
let curveValue = curves.initCurve(Curve.EaseIn); // 创建一个默认先慢后快插值曲线
let interpolatedValue: number = curveValue.interpolate(0.5); // 计算得到时间到一半时的插值
```


## curves.init<sup>(deprecated)</sup>

init(curve?: Curve): string


插值曲线的初始化函数，可以根据入参创建一个插值曲线对象。

> **说明：**  
>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[curves.initCurve](#curvesinitcurve9)替代。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型            | 必填 | 说明                                |
| ------ | --------------- | ---- | ----------------------------------- |
| curve  | [Curve](#curve) | 否   | 曲线类型。<br>默认值：Curve.Linear |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 返回插值曲线对象。 |


## curves.steps<sup>(deprecated)</sup>

steps(count: number, end: boolean): string


构造阶梯曲线对象，阶梯曲线将动画时间等分为指定数量的间隔，在每个间隔内属性值保持不变，在间隔边界处发生阶跃变化。

> **说明：**  
>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[curves.stepsCurve](#curvesstepscurve9)替代。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ----| ------------------------------------------------------------ |
| count  | number  | 是   | 阶梯的数量，需要为正整数。<br>取值范围：[1, +∞)<br>**说明：** <br>设置小于1的值时，按值为1处理。 |
| end    | boolean | 是   | 在每个间隔的起点或终点发生阶跃变化。<br>-true：在终点发生阶跃变化。<br>-false：在起点发生阶跃变化。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 返回阶梯曲线对象。 |


## curves.cubicBezier<sup>(deprecated)</sup>

cubicBezier(x1: number, y1: number, x2: number, y2: number): string


构造三阶贝塞尔曲线对象，曲线的两个控制点横坐标x1、x2的取值范围限定在0到1之间。

> **说明：**  
>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[curves.cubicBezierCurve](#curvescubicbeziercurve9)替代。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**
| 参数名  | 类型     | 必填   | 说明             |
| ---- | ------ | ---- | -------------- |
| x1   | number | 是    | 确定贝塞尔曲线第一点横坐标。<br>取值范围：[0, 1]<br>**说明：** <br>设置的值小于0时，按0处理；设置的值大于1时，按1处理。 |
| y1   | number | 是    | 确定贝塞尔曲线第一点纵坐标。<br>取值范围：(-∞, +∞) |
| x2   | number | 是    | 确定贝塞尔曲线第二点横坐标。<br>取值范围：[0, 1]<br>**说明：** <br>设置的值小于0时，按0处理；设置的值大于1时，按1处理。 |
| y2   | number | 是    | 确定贝塞尔曲线第二点纵坐标。<br>取值范围：(-∞, +∞) |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 返回三阶贝塞尔曲线对象。 |


## curves.spring<sup>(deprecated)</sup>

spring(velocity: number, mass: number, stiffness: number, damping: number): string

构造弹簧曲线对象，曲线形状由弹簧参数决定，动画时长受animation、animateTo中的duration参数控制。与[interpolatingSpring](#curvesinterpolatingspring10)相比，两者参数签名相同但行为不同：springCurve适用于需要固定动画时长的弹簧动画场景；interpolatingSpring适用于由弹簧参数自然决定动画时长的物理弹簧动画场景。

> **说明：**  
>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[curves.springCurve](#curvesspringcurve9)替代。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名       | 类型     | 必填   | 说明    |
| --------- | ------ | ---- | ----- |
| velocity  | number | 是    | 初始速度。外部因素对弹性动效产生的影响参数，目的是保证对象从之前的运动状态平滑地过渡到弹性动效。该速度是归一化速度，其值等于动画开始时的实际速度除以动画属性改变值。<br>取值范围：(-∞, +∞) |
| mass      | number | 是    | 质量。弹性系统的受力对象，会对弹性系统产生惯性影响。质量越大，震荡的幅度越大，恢复到平衡位置的速度越慢。<br>取值范围：(0, +∞)<br>**说明：** <br>设置的值小于等于0时，按1处理。 |
| stiffness | number | 是    | 刚度。物体抵抗施加的力而形变的程度。在弹性系统中，刚度越大，抵抗变形的能力越强，恢复到平衡位置的速度就越快。<br>取值范围：(0, +∞)<br>**说明：** <br>设置的值小于等于0时，按1处理。 |
| damping   | number | 是    | 阻尼。弹性系统中的阻尼系数，用于描述系统在受到扰动后震荡及衰减的情形。阻尼越大，弹性运动的震荡次数越少、震荡幅度越小。<br>取值范围：(0, +∞)<br>**说明：** <br>设置的值小于等于0时，按1处理。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 返回弹簧曲线对象。 |

## 整体示例

```ts
// xxx.ets
import { curves } from '@kit.ArkUI';

@Entry
@Component
struct ImageComponent {
  @State widthSize: number = 200;
  @State heightSize: number = 200;

  build() {
    Column() {
      Text()
        .margin({ top: 100 })
        .width(this.widthSize)
        .height(this.heightSize)
        .backgroundColor(Color.Red)
        .onClick(() => {
          let curve = curves.cubicBezierCurve(0.25, 0.1, 0.25, 1.0);
          // 使用贝塞尔曲线插值计算动画中间状态的宽高尺寸
          this.widthSize = curve.interpolate(0.5) * this.widthSize;
          this.heightSize = curve.interpolate(0.5) * this.heightSize;
        })
        .animation({ duration: 2000, curve: curves.stepsCurve(9, true) })
    }.width('100%').height('100%')
  }
}
```

![zh-cn_image_0000001174104410](figures/curves-spring-example.gif)
