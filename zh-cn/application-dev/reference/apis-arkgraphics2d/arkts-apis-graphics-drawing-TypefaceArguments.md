# Class (TypefaceArguments)

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @dreamyhhh-->
<!--Designer: @wanyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

提供字体属性配置的类，用于配置可变字体的属性参数（如字重维度等轴标签及对应属性值）。

> **说明：**
>
> - 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本Class首批接口从API version 20开始支持。
>
> - 本模块使用屏幕物理像素单位px。
>
> - 本模块为单线程模型策略，需要调用方自行管理线程安全和上下文状态的切换。

## 导入模块

```ts
import { drawing } from '@kit.ArkGraphics2D';
```

## constructor<sup>20+</sup>

constructor()

字体属性的构造函数。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Graphics.Drawing

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';
let typefaceArgument = new drawing.TypefaceArguments();
```

## addVariation<sup>20+</sup>

addVariation(axis: string, value: number)

给字体属性添加可变维度轴标签及对应的属性值。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**
| 参数名         | 类型                                       | 必填   | 说明             |
| ----------- | ---------------------------------------- | ---- | -------------------   |
| axis  | string           | 是   | 字体属性对象可变维度轴标签。具体支持哪些标签取决于加载的字体文件。具体支持的属性及标签值请参考对应的字体文件。   |
| value | number           | 是   | 字体属性对象可变维度字重的标签'wght'对应的属性值，需要在字体文件支持的范围内，否则不会生效。如果属性值小于支持的最小值，则默认和最小值一致。如果属性值大于支持的最大值，则默认和最大值效果一致。请打开对应的字体文件具体查看支持的属性值。    |

**错误码：**

以下错误码的详细介绍请参见[图形绘制与显示错误码](../apis-arkgraphics2d/errorcode-drawing.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 25900001 | Parameter error.Possible causes: Incorrect parameter range. |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let typefaceArgument = new drawing.TypefaceArguments();
typefaceArgument.addVariation('wght', 10);
```
