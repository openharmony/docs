# Class (PathIterator)

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @dreamyhhh-->
<!--Designer: @wanyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

表示路径操作迭代器，可通过遍历迭代器逐段读取路径的操作指令。迭代器按顺序遍历路径中的操作指令，便于实现对路径的细粒度分析与自定义处理。

> **说明：**
>
> - 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本Class首批接口从API version 18开始支持。
>
> - 本模块使用屏幕物理像素单位px。
>
> - 本模块为单线程模型策略，需要调用方自行管理线程安全和上下文状态的切换。

## 导入模块

```ts
import { drawing } from '@kit.ArkGraphics2D';
```

## constructor<sup>18+</sup>

constructor(path: Path)

构造迭代器并绑定路径。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                            |
| -------- | -------------------------------------------- | ---- | ------------------------------- |
| path | [Path](arkts-apis-graphics-drawing-Path.md) | 是   | 迭代器绑定的路径对象，绑定后迭代器将遍历该路径中的操作指令，可通过next、peek、hasNext等方法读取路径的操作类型和坐标数据。 |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let path: drawing.Path = new drawing.Path();
let iter: drawing.PathIterator = new drawing.PathIterator(path);
console.info('PathIterator created successfully');
```

## next<sup>18+</sup>

next(points: Array\<common2D.Point>, offset?: number): PathIteratorVerb

返回当前路径的下一个操作，并将迭代器推进至该操作，同时将路径坐标点数据按操作类型写入传入的points数组。若仅需预览下一个操作而不改变迭代器状态，请使用[peek](#peek18)。通常与[hasNext](#hasnext18)方法配合使用实现路径遍历。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                            |
| -------- | -------------------------------------------- | ---- | ------------------------------- |
| points | Array\<[common2D.Point](js-apis-graphics-common2D.md#point12)>   | 是   | 坐标点数组，长度必须至少为偏移量加4，以确保能容纳所有类型的路径数据。操作执行后，该数组会被覆盖。填入的坐标点数量取决于操作类型，其中，MOVE填入1个坐标点，LINE填入2个坐标点，QUAD填入3个坐标点，CONIC填入3个坐标点 + 1个权重值（共3.5组），CUBIC填入4个坐标点，CLOSE和DONE不填入任何点。 |
| offset | number   | 否   | 数组中写入位置相对起始点的偏移量，默认为0，取值范围为[0, size-4]，size是指坐标点数组长度。 |

**返回值：**

| 类型                  | 说明           |
| --------------------- | -------------- |
| [PathIteratorVerb](arkts-apis-graphics-drawing-e.md#pathiteratorverb18) | 当前路径段的操作类型。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { common2D, drawing } from '@kit.ArkGraphics2D';

let path: drawing.Path = new drawing.Path();
path.moveTo(10, 20);
let iter: drawing.PathIterator = new drawing.PathIterator(path);
let verbStr: Array<string> = ['MOVE', 'LINE', 'QUAD', 'CONIC', 'CUBIC', 'CLOSE', 'DONE'];
let pointCount: Array<number> = [1, 2, 3, 4, 4, 0, 0];
let points: Array<common2D.Point> = [{x: 0, y: 0}, {x: 0, y: 0}, {x: 0, y: 0}, {x: 0, y: 0}];
let offset = 0;
let verb = iter.next(points, offset);
let outputMessage: string = 'pathIteratorNext: ';
outputMessage += 'verb =' + verbStr[verb] + '; has ' + pointCount[verb] + ' pairs: ';
for (let j = 0; j < pointCount[verb] + offset; j++) {
  outputMessage += '[' + points[j].x + ', ' + points[j].y + ']';
}
console.info(outputMessage);
```

## peek<sup>18+</sup>

peek(): PathIteratorVerb

返回当前路径的下一个操作，迭代器保持在原操作。与next不同，peek不会推进迭代器位置。

**系统能力：** SystemCapability.Graphics.Drawing

**返回值：**

| 类型                  | 说明           |
| --------------------- | -------------- |
| [PathIteratorVerb](arkts-apis-graphics-drawing-e.md#pathiteratorverb18) | 当前路径段的操作类型。 |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let path: drawing.Path = new drawing.Path();
let iter: drawing.PathIterator = new drawing.PathIterator(path);
let res = iter.peek();
```

## hasNext<sup>18+</sup>

hasNext(): boolean

判断迭代器中是否还有下一个操作。通常与next()或peek()方法配合使用实现路径遍历。

**系统能力：** SystemCapability.Graphics.Drawing

**返回值：**

| 类型    | 说明           |
| ------- | -------------- |
| boolean | 迭代器是否还有下一个操作可遍历。true表示还有后续路径操作可读取，false表示已遍历至路径末尾，无更多操作。 |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let path: drawing.Path = new drawing.Path();
let iter: drawing.PathIterator = new drawing.PathIterator(path);
let res = iter.hasNext();
```