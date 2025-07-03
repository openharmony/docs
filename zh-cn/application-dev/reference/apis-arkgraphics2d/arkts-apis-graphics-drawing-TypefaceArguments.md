# Class (TypefaceArguments)

> **说明：**
>
> - 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块使用屏幕物理像素单位px。
>
> - 本模块为单线程模型策略，需要调用方自行管理线程安全和上下文状态的切换。

## 导入模块

```ts
import { drawing } from '@kit.ArkGraphics2D';
```

## TypefaceArguments<sup>20+</sup>

提供字体属性配置的结构体。

### constructor<sup>20+</sup>

constructor()

字体属性的构造函数。

**系统能力：** SystemCapability.Graphics.Drawing

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';
let typeFaceArgument = new drawing.TypefaceArguments();
```

### addVariation<sup>20+</sup>

addVariation(axis: string, value: number)

给字体属性设置字重值。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**
| 参数名         | 类型                                       | 必填   | 说明             |
| ----------- | ---------------------------------------- | ---- | -------------------   |
| axis  | string           | 是   | 字体属性对象可变维度字重的标签'wght'。具体是否支持的该标签取决于加载的字体文件。请打开对应的字体文件具体查看支持的属性。   |
| value | number           | 是   | 字体属性对象可变维度字重的标签'wght'对应的属性值，需要在字体文件支持的范围内，否则不会生效。如果属性值小于支持的最小值，则默认和最小值一致。如果属性值大于支持的最大值，则默认和最大值效果一致。请打开对应的字体文件具体查看支持的属性值。    |

**错误码：**

以下错误码的详细介绍请参见[图形绘制与显示错误码](../apis-arkgraphics2d/errorcode-drawing.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 25900001 | Parameter error.Possible causes: Incorrect parameter range. |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let typeFaceArgument = new drawing.TypefaceArguments();
typeFaceArgument.addVariation('wght', 10);
```