# 色彩管理

本模块提供管理抽象化色域对象的一些基础能力，包括色域对象的创建与色域基础属性的获取等。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import colorSpaceManager from '@ohos.graphics.colorSpaceManager';
```

## ColorSpace

色域类型枚举。

**系统能力：** SystemCapability.Graphic.Graphic2D.ColorManager.Core

| 名称                         | 值     | 说明                    |
| --------------------------- | ------ | ----------------------- |
| UNKNOWN        | 0      | 未知的色域类型。|
| ADOBE_RGB_1998 | 1      | RGB色域为Adobe RGB(1998)类型。 |
| DCI_P3         | 2      | RGB色域为DCI-P3类型。|
| DISPLAY_P3     | 3      | RGB色域为Display P3类型。 |
| SRGB           | 4      | RGB色域为SRGB类型。<br>系统默认色域类型。 |
| CUSTOM         | 5      | 用户自定义色域类型。|

## ColorSpacePrimaries

色域标准三原色（红、绿、蓝）和白色，使用(x, y)表示其在色彩空间中的位置。

**系统能力：** SystemCapability.Graphic.Graphic2D.ColorManager.Core

| 名称                          | 参数类型 | 可读 | 可写 | 说明                                                         |
| ---------------------------- | -------- | ---- | ---- | ----------------------------------------------------- |
| redX                         | number   | 是   | 是   | 标准红色在色彩空间的x坐标值。 |
| redY                         | number   | 是   | 是   | 标准红色在色彩空间的y坐标值。 |
| greenX                       | number   | 是   | 是   | 标准绿色在色彩空间的x坐标值。 |
| greenY                       | number   | 是   | 是   | 标准绿色在色彩空间的y坐标值。 |
| blueX                        | number   | 是   | 是   | 标准蓝色在色彩空间的x坐标值。 |
| blueY                        | number   | 是   | 是   | 标准蓝色在色彩空间的y坐标值。 |
| whitePointX                  | number   | 是   | 是   | 标准白色在色彩空间的x坐标值。 |
| whitePointY                  | number   | 是   | 是   | 标准白色在色彩空间的y坐标值。 |

## colorSpaceManager.create

create(colorSpaceName: ColorSpace): ColorSpaceManager

创建标准色域对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.ColorManager.Core

**参数：**

| 参数名           | 类型                     | 必填 | 说明                          |
| --------------- | ------------------------ | ---- | -----------------------------|
| colorSpaceName  | [ColorSpace](#colorspace)| 是   | 标准色域类型枚举值。<br>UNKNOWN与CUSTOM不可用于直接创建色域对象。          |

**返回值：**

| 类型                | 说明                     |
| ------------------ | ------------------------ |
| [ColorSpaceManager](#colorspacemanager)  | 返回当前创建的色域对象实例。               |

**错误码：**

以下错误码的详细介绍请参见[色彩管理错误码](../errorcodes/errorcode-colorspace-manager.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 18600001 | Parameter value is abnormal. |

**示例：**

```js
let colorSpace = null;
try {
    colorSpace = colorSpaceManager.create(colorSpaceManager.ColorSpace.SRGB);
} catch (err) {
    console.log(`Failed to create SRGB colorSpace. Cause: ` + JSON.stringify(err));
}
```

## colorSpaceManager.create

create(primaries: ColorSpacePrimaries, gamma: number): ColorSpaceManager

创建用户自定义色域对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.ColorManager.Core

**参数：**

| 参数名           | 类型                                       | 必填 | 说明                          |
| --------------- | ------------------------------------------ | ---- | -----------------------------|
| primaries       | [ColorSpacePrimaries](#colorspaceprimaries)| 是   | 色域标准三原色。               |
| gamma           | number                                     | 是   | 色域gamma值。                 |

**返回值：**

| 类型                | 说明                     |
| ------------------ | ------------------------ |
| [ColorSpaceManager](#colorspacemanager)  | 返回当前创建的色域对象实例。<br>色域类型定义为[ColorSpace](#colorspace)枚举值`CUSTOM`。 |

**错误码：**

以下错误码的详细介绍请参见[色彩管理错误码](../errorcodes/errorcode-colorspace-manager.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 18600001 | Parameter value is abnormal. |

**示例：**

```js
let colorSpace = null;
try {
    let primaries = {
        redX: 0.1,
        redY: 0.1,
        greenX: 0.2,
        greenY: 0.2,
        blueX: 0.3,
        blueY: 0.3,
        whitePointX: 0.4,
        whitePointY: 0.4
    };
    let gamma = 2.2;
    colorSpace = colorSpaceManager.create(primaries, gamma);
} catch (err) {
    console.log(`Failed to create colorSpace with customized primaries and gamma. Cause: ` + JSON.stringify(err));
}
```

## ColorSpaceManager

当前色域对象实例。

下列API示例中都需先使用[create()](#colorspacemanagercreate)获取到ColorSpaceManager实例（i.e. `colorSpace`），再通过此实例调用对应方法。

### getColorSpaceName

getColorSpaceName(): ColorSpace

获取色域类型。

**系统能力：** SystemCapability.Graphic.Graphic2D.ColorManager.Core

**返回值：**

| 类型                | 说明                     |
| ------------------ | ------------------------ |
| [ColorSpace](#colorspace)  | 返回色域类型枚举值。 |

**错误码：**

以下错误码的详细介绍请参见[色彩管理错误码](../errorcodes/errorcode-colorspace-manager.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 18600001 | Parameter value is abnormal. |

**示例：**

```js
try {
    colorSpace.getColorSpaceName();
} catch (err) {
    console.log(`Fail to get colorSpace's name. Cause: ` + JSON.stringify(err));
}
```

### getWhitePoint

getWhitePoint(): Array\<number\>

获取色域白点值。

**系统能力：** SystemCapability.Graphic.Graphic2D.ColorManager.Core

**返回值：**

| 类型                | 说明                     |
| ------------------ | ------------------------ |
| Array\<number\>  | 返回色域白点值[x, y]。 |

**错误码：**

以下错误码的详细介绍请参见[色彩管理错误码](../errorcodes/errorcode-colorspace-manager.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 18600001 | Parameter value is abnormal. |

**示例：**

```js
try {
    colorSpace.getWhitePoint();
} catch (err) {
    console.log(`Failed to get white point. Cause: ` + JSON.stringify(err));
}
```

### getGamma

getGamma(): number

获取色域gamma值。

**系统能力：** SystemCapability.Graphic.Graphic2D.ColorManager.Core

**返回值：**

| 类型                | 说明                     |
| ------------------ | ------------------------ |
| number  | 返回色域gamma值。 |

**错误码：**

以下错误码的详细介绍请参见[色彩管理错误码](../errorcodes/errorcode-colorspace-manager.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 18600001 | Parameter value is abnormal. |

**示例：**

```js
try {
    colorSpace.getGamma();
} catch (err) {
    console.log(`Failed to get gamma. Cause: ` + JSON.stringify(err));
}
```