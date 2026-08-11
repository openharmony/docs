# Class (PointUtils)

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @dreamyhhh-->
<!--Designer: @wanyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

本Class是提供处理坐标点的工具类，支持对坐标点进行取反、偏移等操作，适用于需要对坐标点进行变换处理的图形绘制场景。

> **说明：**
>
> - 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本Class首批接口从API版本26.0.0开始支持。
>
> - 本模块使用屏幕物理像素单位px。
>
> - 本模块为单线程模型策略，需要调用方自行管理线程安全和上下文状态的切换。

## 导入模块

```ts
import { drawing } from '@kit.ArkGraphics2D';
```

## negate

static negate(point: common2D.Point): void

对点的坐标取反。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型    | 必填 | 说明           |
| ------ | ------ | ---- | -------------- |
| point   | [common2D.Point](js-apis-graphics-common2D.md#point12) | 是   | 要取反的点。 |

**示例：**

```ts
import { common2D, drawing } from '@kit.ArkGraphics2D';

let point: common2D.Point = { x: 10, y: 20 };
drawing.PointUtils.negate(point);
console.info('point.x:', point.x);
console.info('point.y:', point.y);
```

## offset

static offset(point: common2D.Point, dx: number, dy: number): void

将指定坐标点沿着x轴和y轴方向偏移一定距离。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型    | 必填 | 说明           |
| ------ | ------ | ---- | -------------- |
| point   | [common2D.Point](js-apis-graphics-common2D.md#point12) | 是   | 要偏移的点。 |
| dx   | number | 是   | x轴方向平移距离，正数表示往x轴正方向平移，负数表示往x轴负方向平移，该参数为浮点数。单位为物理像素px。 |
| dy    | number | 是   | y轴方向平移距离，正数表示往y轴正方向平移，负数表示往y轴负方向平移，该参数为浮点数。单位为物理像素px。 |

**示例：**

```ts
import { common2D, drawing } from '@kit.ArkGraphics2D';

let point: common2D.Point = { x: 10, y: 20 };
drawing.PointUtils.offset(point, 5, 10);
console.info('point.x:', point.x);
console.info('point.y:', point.y);
```
