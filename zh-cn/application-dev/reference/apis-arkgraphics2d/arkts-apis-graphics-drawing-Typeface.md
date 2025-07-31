# Class (Typeface)

> **说明：**
>
> - 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块使用屏幕物理像素单位px。
>
> - 本模块为单线程模型策略，需要调用方自行管理线程安全和上下文状态的切换。

字体，如宋体、楷体等。

## 导入模块

```ts
import { drawing } from '@kit.ArkGraphics2D';
```

## getFamilyName

getFamilyName(): string

获取字体的族名，即一套字体设计的名称。

**系统能力：** SystemCapability.Graphics.Drawing

**返回值：**

| 类型   | 说明                 |
| ------ | -------------------- |
| string | 返回字体的族名。 |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

const font = new drawing.Font();
let typeface = font.getTypeface();
let familyName = typeface.getFamilyName();
```

## makeFromCurrent<sup>20+</sup>

makeFromCurrent(typefaceArguments: TypefaceArguments): Typeface

基于当前字体结合字体属性构造新的字体对象。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**
| 参数名         | 类型                                       | 必填   | 说明                  |
| ----------- | ---------------------------------------- | ---- | ------------------- |
| typefaceArguments | [TypefaceArguments](arkts-apis-graphics-drawing-TypefaceArguments.md)           | 是   | 字体属性。 |

**返回值：**

| 类型   | 说明                  |
| ------ | -------------------- |
| [Typeface](arkts-apis-graphics-drawing-Typeface.md) | 返回字体对象（异常情况下会返回空指针）。 |

**示例：**

```ts
import { RenderNode } from '@kit.ArkUI';
import { drawing } from '@kit.ArkGraphics2D';

class TextRenderNode extends RenderNode {
  async draw(context: DrawContext) {
    const canvas = context.canvas;
    let typeArguments = new drawing.TypefaceArguments();
    typeArguments.addVariation("wght", 100);
    const myTypeFace = drawing.Typeface.makeFromFile("/system/fonts/HarmonyOS_Sans_SC.ttf");
    const typeFace1 = myTypeFace.makeFromCurrent(typeArguments);
    let font = new drawing.Font();
    font.setTypeface(typeFace1);
    const textBlob = drawing.TextBlob.makeFromString("Hello World", font, drawing.TextEncoding.TEXT_ENCODING_UTF8);
    canvas.drawTextBlob(textBlob, 60, 100);
  }
}
```

## makeFromFile<sup>12+</sup>

static makeFromFile(filePath: string): Typeface

从指定字体文件构造字体。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名         | 类型                                       | 必填   | 说明                  |
| ----------- | ---------------------------------------- | ---- | ------------------- |
| filePath | string           | 是   | 表示字体资源存放的路径。应用沙箱路径和真实物理路径的对应关系请参考[应用沙箱路径和真实物理路径的对应关系](../../file-management/app-sandbox-directory.md#应用沙箱路径和真实物理路径的对应关系)。 |

**返回值：**

| 类型   | 说明                 |
| ------ | -------------------- |
| [Typeface](arkts-apis-graphics-drawing-Typeface.md) | 返回Typeface对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**示例：**

```ts
import { RenderNode } from '@kit.ArkUI';
import { drawing } from '@kit.ArkGraphics2D';

class TextRenderNode extends RenderNode {
  async draw(context: DrawContext) {
    const canvas = context.canvas;
    let font = new drawing.Font();
    let str = "/system/fonts/HarmonyOS_Sans_Italic.ttf";
    const mytypeface = drawing.Typeface.makeFromFile(str);
    font.setTypeface(mytypeface);
    const textBlob = drawing.TextBlob.makeFromString("Hello World", font, drawing.TextEncoding.TEXT_ENCODING_UTF8);
    canvas.drawTextBlob(textBlob, 60, 100);
  }
}
```

## makeFromRawFile<sup>18+</sup>

static makeFromRawFile(rawfile: Resource): Typeface

使用指定的字体文件构造字体，其中要求指定的字体文件需保存在应用资源文件夹的rawfile路径下。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名         | 类型                                       | 必填   | 说明                  |
| ----------- | ---------------------------------------- | ---- | ------------------- |
| rawfile | [Resource](../apis-arkui/arkui-ts/ts-types.md#resource)           | 是   | 指定字体文件对应的资源对象。当前只支持``$rawfile``格式引用的资源对象，对应格式写为``$rawfile('filePath')``，其中filePath为指定字体文件相对于工程中resources/rawfile目录的相对路径。如将字体文件直接存放在resources/rawfile目录下，则引用格式应写为：``$rawfile('HarmonyOS_Sans_Bold.ttf')``；也可以创建子目录，将字体文件存放在resources/rawfile/ttf下，则引用格式应写为：``$rawfile('ttf/HarmonyOS_Sans_Bold.ttf')``。 |

**返回值：**

| 类型   | 说明                 |
| ------ | -------------------- |
| [Typeface](arkts-apis-graphics-drawing-Typeface.md) | 返回Typeface对象（异常情况下会返回空指针）。 |

**示例：**

```ts
import { RenderNode } from '@kit.ArkUI';
import { drawing } from '@kit.ArkGraphics2D';

class TextRenderNode extends RenderNode {
  async draw(context: DrawContext) {
    const canvas = context.canvas;
    let font = new drawing.Font();
    const myTypeFace = drawing.Typeface.makeFromRawFile($rawfile('HarmonyOS_Sans_Bold.ttf'));
    font.setTypeface(myTypeFace);
    const textBlob = drawing.TextBlob.makeFromString("Hello World", font, drawing.TextEncoding.TEXT_ENCODING_UTF8);
    canvas.drawTextBlob(textBlob, 60, 100);
  }
}

```
## makeFromFileWithArguments<sup>20+</sup>

static makeFromFileWithArguments(filePath: string, typefaceArguments: TypefaceArguments): Typeface

根据字体文件路径和字体属性构造新的字体。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名         | 类型                                       | 必填   | 说明                  |
| ----------- | ---------------------------------------- | ---- | ------------------- |
| filePath | string           | 是   | 表示字体资源存放的路径。应用沙箱路径和真实物理路径的对应关系请参考[应用沙箱路径和真实物理路径的对应关系](../../file-management/app-sandbox-directory.md#应用沙箱路径和真实物理路径的对应关系)。 |
| typefaceArguments | [TypefaceArguments](arkts-apis-graphics-drawing-TypefaceArguments.md) | 是  | 表示字体属性。 |

**返回值：**

| 类型   | 说明                  |
| ------ | -------------------- |
| [Typeface](arkts-apis-graphics-drawing-Typeface.md) | 返回字体对象（异常情况下会返回空指针）。 |

**示例：**

```ts
import { RenderNode } from '@kit.ArkUI';
import { drawing } from '@kit.ArkGraphics2D';

class TextRenderNode extends RenderNode {
  async draw(context: DrawContext) {
    const canvas = context.canvas;
    let font = new drawing.Font();
    let str = "/system/fonts/HarmonyOS_Sans_Italic.ttf";
    let typeFaceArgument = new drawing.TypefaceArguments();
    const myTypeFace = drawing.Typeface.makeFromFileWithArguments(str, typeFaceArgument);
    font.setTypeface(myTypeFace);
    const textBlob = drawing.TextBlob.makeFromString("Hello World", font, drawing.TextEncoding.TEXT_ENCODING_UTF8);
    canvas.drawTextBlob(textBlob, 60, 100);
  }
}
```

## makeFromRawFileWithArguments<sup>20+</sup>

static makeFromRawFileWithArguments(rawfile: Resource, typefaceArguments: TypefaceArguments): Typeface

使用指定的字体文件和字体属性构造字体，其中要求指定的字体文件需保存在应用资源文件夹的rawfile路径下。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名         | 类型                                       | 必填   | 说明                  |
| ----------- | ---------------------------------------- | ---- | ------------------- |
| rawfile | [Resource](../apis-arkui/arkui-ts/ts-types.md#resource)           | 是   | 指定字体文件对应的资源对象。当前只支持``$rawfile``格式引用的资源对象，对应格式写为``$rawfile('filePath')``，其中filePath为指定字体文件相对于工程中resources/rawfile目录的相对路径。 |
| typefaceArguments | [TypefaceArguments](arkts-apis-graphics-drawing-TypefaceArguments.md) | 是 | 表示字体属性。 |

**返回值：**

| 类型   | 说明                 |
| ------ | ------------------- |
| [Typeface](arkts-apis-graphics-drawing-Typeface.md) | 返回字体对象（异常情况下会返回空指针）。 |

**示例：**

```ts
import { RenderNode } from '@kit.ArkUI';
import { drawing } from '@kit.ArkGraphics2D';

class TextRenderNode extends RenderNode {
  async draw(context: DrawContext) {
    const canvas = context.canvas;
    let font = new drawing.Font();
    let typeFaceArgument = new drawing.TypefaceArguments();
    const myTypeFace = drawing.Typeface.makeFromRawFileWithArguments($rawfile('HarmonyOS_Sans_Bold.ttf'), typeFaceArgument);
    font.setTypeface(myTypeFace);
    const textBlob = drawing.TextBlob.makeFromString("Hello World", font, drawing.TextEncoding.TEXT_ENCODING_UTF8);
    canvas.drawTextBlob(textBlob, 60, 100);
  }
}
```