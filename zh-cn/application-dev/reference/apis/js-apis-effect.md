# 图像效果处理

> **说明：**
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import effectKit from '@ohos.effectKit';
```

## effectKit.createEffect<sup>9+</sup>
createEffect(source: image.PixelMap): Filter

通过传入的PixelMap创建Filter实例。

**系统能力：** SystemCapability.Graphic.Graphic2D.Effectkit

**参数：**

| 名称    | 类型                                             | 必填 | 说明                                                         |
| ------- | ------------------------------------------------ | ---- | ------------------------------------------------------------ |
| source  | image.PixelMap                                      | 是   | image模块创建的PixelMap实例                                    |

**返回值：**

| 类型                             | 说明           |
| -------------------------------- | -------------- |
| Filter | 返回不带任何效果的Filter链表的头节点,失败时返回null |

**示例：**

```js
const color = new ArrayBuffer(96);
let opts = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts)
    .then((pixelmap) => {
        let headFilter = effectKit.createEffect(pixelmap)
    })
```

## effectKit.createColorPicker<sup>9+</sup>

createColorPicker(source: image.PixelMap): Promise\<ColorPicker>

通过属性创建PixelMap，通过回调函数返回结果。

**系统能力：** SystemCapability.Graphic.Graphic2D.Effectkit

**参数：**

| 名称     | 类型                                             | 必填 | 说明                       |
| -------- | ------------------------------------------------ | ---- | -------------------------- |
| source   | image.PixelMap                                      | 是   |  image模块创建的PixelMap实例                                    |

**示例：**

```js
const color = new ArrayBuffer(96);
let opts = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts, (pixelmap) => {
    effectKit.createColorPicker(pixelMap).then(colorPicker => {
            console.info("color picker=" + colorPicker);
        })
        .catch(ex => console.error(".error=" + ex.toString()))
    })
})
```

## effectKit.createColorPicker<sup>9+</sup>

createColorPicker(source: image.PixelMap, callback: AsyncCallback<ColorPicker>): void

通过属性创建PixelMap，通过回调函数返回结果。

**系统能力：** SystemCapability.Graphic.Graphic2D.Effectkit

**参数：**

| 名称     | 类型                                             | 必填 | 说明                       |
| -------- | ------------------------------------------------ | ---- | -------------------------- |
| source   | image.PixelMap                                      | 是   | BGRA_8888格式的颜色数组。  |
| callback | AsyncCallback\<[ColorPicker](#pixelmap7)>           | 是   | 通过回调返回ColorPicker对象。 |

**示例：**

```js
const color = new ArrayBuffer(96);
let opts = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts, (pixelmap) => {
    effectKit.createColorPicker(pixelMap, (error, colorPicker) ) {
        if(error) {
            console.log('create color picker failed.');
        } else {
            console.log('create color picker succeeded.');
        }
    })
})
```

## Color<sup>9+</sup>

颜色类，用于保存取色的结果。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Graphic.Graphic2D.Effectkit

| 名称   | 类型   | 可读 | 可写 | 说明              |
| ------ | ----- | ---- | ---- | ---------------- |
| red   | number | 是   | 否   | 红色分量值           |
| green | number | 是   | 否   | 绿色分量值           |
| blue  | number | 是   | 否   | 蓝色分量值           |
| alpha | number | 是   | 否   | 透明通道分量值       |

## ColorPicker<sup>9+</sup>

取色类，用于从一张图像数据中获取它的主要颜色。在调用ColorPicker的方法前，需要先通过createColorPicker创建一个ColorPicker实例。

### getMainColor<sup>9+</sup>

getMainColor(): Promise\<Color>;

读取图像主色的颜色值，结果写入Color里，使用Promise形式返回。

**系统能力：** SystemCapability.Graphic.Graphic2D.Effectkit

**返回值：**

| 类型           | 说明                                            |
| :------------- | :---------------------------------------------- |
| Promise\<Color> | Promise实例，用于获取结果，失败时返回错误信息。 |

**示例：**

```js
colorPicker.getMainColor().then(() => {
    console.log('get main color succeeded.');  //符合条件则进入 
}).catch(error => {
    console.log('get main color failed.');  //不符合条件则进入
})
```

### getMainColorSync<sup>9+</sup>

getMainColorSync(): Color;

读取图像主色的颜色值，结果写入Color里，使用同步方式返回。

**系统能力：** SystemCapability.Graphic.Graphic2D.Effectkit

**返回值：**

| 类型     | 说明                                  |
| :------- | :----------------------------------- |
| Color    | Color实例，用于获取结果，失败时返回null |

**示例：**

```js
let color = colorPicker.getMainColorSync()
console.log('get main color =' + color)
```

## Filter<sup>9+</sup>

图像效果类，用于将指定的效果结合到输入的image.PixelMap所存的图像中。在调用的方法前，需要先通过createEffect创建一个Filter实例。

### blur<sup>9+</sup>

blur(radius: number): Filter

将模糊效果添加到效果链表中，结果返回效果链表的头节点。

**系统能力：** SystemCapability.Graphic.Graphic2D.Effectkit

**参数：**

| 参数名 | 类型        | 必填 | 说明                                                         |
| ------ | ----------- | ---- | ------------------------------------------------------------ |
|  radius   | number | 是   | 模糊半径，模糊效果与所设置的值成正比值越大效果越明显。 |

**返回值：**

| 类型           | 说明                                            |
| :------------- | :---------------------------------------------- |
| Filter | Filter链表头，可继续添加效果直到调用获取结果的接口,失败时返回null |

**示例：**

```js
const color = new ArrayBuffer(96);
let opts = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts)
    .then((pixelmap) => {
        let radius = 5;
        let headFilter = effectKit.createEffect(pixelmap)
        if (headFilter != null) {
            headFilter.blur(radius)
        }
    })
```

### brightness<sup>9+</sup>

brightness(bright: number): Filter

将高亮效果添加到效果链表中，结果返回效果链表的头节点。

**系统能力：** SystemCapability.Graphic.Graphic2D.Effectkit

**参数：**

| 参数名 | 类型        | 必填 | 说明                                                         |
| ------ | ----------- | ---- | ------------------------------------------------------------ |
|  bright   | number | 是   | 高亮程度，取值范围在0-1之间，取值为0时图像保持不变。 |

**返回值：**

| 类型           | 说明                                            |
| :------------- | :---------------------------------------------- |
| Filter | Filter链表头，可继续添加效果直到调用获取结果的接口,失败时返回null |

**示例：**

```js
const color = new ArrayBuffer(96);
let opts = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts)
    .then((pixelmap) => {
        let bright = 0.5;
        let headFilter = effectKit.createEffect(pixelmap)
        if (headFilter != null) {
            headFilter.brightness(bright)
        }
    })
```

### grayscale<sup>9+</sup>

grayscale(): Filter

将灰度效果添加到效果链表中，结果返回效果链表的头节点。

**系统能力：** SystemCapability.Graphic.Graphic2D.Effectkit

**返回值：**

| 类型           | 说明                                            |
| :------------- | :---------------------------------------------- |
| Filter | Filter链表头，可继续添加效果直到调用获取结果的接口,失败时返回null |

**示例：**

```js
const color = new ArrayBuffer(96);
let opts = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts)
    .then((pixelmap) => {
        let headFilter = effectKit.createEffect(pixelmap)
        if (headFilter != null) {
            headFilter.brightness(bright)
        }
    })
```

### getPixelMap<sup>9+</sup>

getPixelMap(): image.PixelMap;

获取已经将链表中的效果全部添加到源图像的image.PixelMap。

**系统能力：** SystemCapability.Graphic.Graphic2D.Effectkit

**返回值：**

| 类型           | 说明                                            |
| :------------- | :---------------------------------------------- |
| image.PixelMap | 带有全部添加效果的图片源 |

**示例：**

```js
const color = new ArrayBuffer(96);
let opts = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts)
    .then((pixelmap) => {
        let pixel = effectKit.createEffect(pixelmap).grayscale().getPixelMap()
    })
```
