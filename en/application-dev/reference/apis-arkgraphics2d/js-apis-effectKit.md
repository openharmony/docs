# @ohos.effectKit (Image Effects)
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Multimedia-->
<!--Owner: @hanamaru-->
<!--Designer: @gaoweihua-->
<!--Tester: @zhaoxiaoguang2-->
<!--Adviser: @ge-yafang-->

Provides basic capabilities for processing images, including brightness adjustment, blurring, grayscale adjustment, and intelligent color picking. effectKit is used to process images (such as pixelmap, png, and jpeg) offline to obtain visual effects. uiEffect is used to connect to the rendering service in real time and process the screen frame buffer to obtain dynamic visual effects.

This module provides the following classes:

- [Filter](#filter): a class that adds a specified effect to the image source.
- [Color](#color): a class used to store the color picked.
- [ColorPicker](#colorpicker): a smart color picker.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { effectKit } from "@kit.ArkGraphics2D";
```

## effectKit.createEffect
createEffect(source: image.PixelMap): Filter

Creates a **Filter** instance based on a pixel map.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name   | Type              | Mandatory| Description    |
| ------- | ----------------- | ---- | -------- |
| source  | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | Yes  | **PixelMap** instance created by the image module. You can create a ColorPicker instance by decoding an image or directly creating a ColorPicker instance. For details, see [Image Kit Overview](../../media/image/image-overview.md).  |

**Return value**

| Type                            | Description          |
| -------------------------------- | -------------- |
| [Filter](#filter) | Returns the head node of the filter linked list without any effect. If the operation fails, null is returned.|

**Example**

```ts
import { image } from "@kit.ImageKit";
import { effectKit } from "@kit.ArkGraphics2D";

const color = new ArrayBuffer(96);
let opts : image.InitializationOptions = {
  editable: true,
  pixelFormat: 3,
  size: {
    height: 4,
    width: 6
  }
}
image.createPixelMap(color, opts).then((pixelMap) => {
  let headFilter = effectKit.createEffect(pixelMap);
})
```

## effectKit.createColorPicker

createColorPicker(source: image.PixelMap): Promise\<ColorPicker>

Creates a **ColorPicker** instance based on a pixel map. This API uses a promise to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name    | Type        | Mandatory| Description                      |
| -------- | ----------- | ---- | -------------------------- |
| source   | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | Yes  |  **PixelMap** instance created by the image module. You can create a ColorPicker instance by decoding an image or directly creating a ColorPicker instance. For details, see [Image Kit Overview](../../media/image/image-overview.md).|

**Return value**

| Type                  | Description          |
| ---------------------- | -------------- |
| Promise\<[ColorPicker](#colorpicker)>  | Promise used to return the **ColorPicker** instance created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 401      | Input parameter error.             |

**Example**

```ts
import { image } from "@kit.ImageKit";
import { effectKit } from "@kit.ArkGraphics2D";
import { BusinessError } from "@kit.BasicServicesKit";

const color = new ArrayBuffer(96);
let opts : image.InitializationOptions = {
  editable: true,
  pixelFormat: 3,
  size: {
    height: 4,
    width: 6
  }
}

image.createPixelMap(color, opts).then((pixelMap) => {
  effectKit.createColorPicker(pixelMap).then(colorPicker => {
    console.info("color picker=" + colorPicker);
  }).catch( (reason : BusinessError) => {
    console.error("error=" + reason.message);
  })
})
```

## effectKit.createColorPicker<sup>10+</sup>

createColorPicker(source: image.PixelMap, region: Array\<number>): Promise\<ColorPicker>

Creates a **ColorPicker** instance for the selected region based on a pixel map. This API uses a promise to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name    | Type        | Mandatory| Description                      |
| -------- | ----------- | ---- | -------------------------- |
| source   | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | Yes  |  **PixelMap** instance created by the image module. You can obtain the instance by decoding an image or creating one directly. For details, please refer to Image Kit Overview.|
| region   | Array\<number> | Yes  |  Region of the image from which the color is picked.<br>The array contains four elements, each of which is in the range of [0, 1], indicating the left, top, right, and bottom positions of the image area. The leftmost and topmost positions of the image correspond to 0, and the rightmost and bottommost positions correspond to 1. In the array, the third element must be greater than the first element, and the fourth element must be greater than the second element.|

**Return value**

| Type                  | Description          |
| ---------------------- | -------------- |
| Promise\<[ColorPicker](#colorpicker)>  | Promise used to return the **ColorPicker** instance created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 401      | Input parameter error.             |

**Example**

```ts
import { image } from "@kit.ImageKit";
import { effectKit } from "@kit.ArkGraphics2D";
import { BusinessError } from "@kit.BasicServicesKit";

const color = new ArrayBuffer(96);
let opts : image.InitializationOptions = {
  editable: true,
  pixelFormat: 3,
  size: {
    height: 4,
    width: 6
  }
}

image.createPixelMap(color, opts).then((pixelMap) => {
  effectKit.createColorPicker(pixelMap, [0, 0, 1, 1]).then(colorPicker => {
    console.info("color picker=" + colorPicker);
  }).catch( (reason : BusinessError) => {
    console.error("error=" + reason.message);
  })
})
```

## effectKit.createColorPicker

createColorPicker(source: image.PixelMap, callback: AsyncCallback\<ColorPicker>): void

Creates a **ColorPicker** instance based on a pixel map. This API uses an asynchronous callback to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name    | Type               | Mandatory| Description                      |
| -------- | ------------------ | ---- | -------------------------- |
| source   | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | Yes |**PixelMap** instance created by the image module. You can obtain the PixelMap instance by decoding an image or creating one directly. For details, see Introduction to Image Kit. |
| callback | AsyncCallback\<[ColorPicker](#colorpicker)> | Yes | Callback used to return the **ColorPicker** instance created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 401      | Input parameter error.             |

**Example**

```ts
import { image } from "@kit.ImageKit";
import { effectKit } from "@kit.ArkGraphics2D";

const color = new ArrayBuffer(96);
let opts : image.InitializationOptions = {
  editable: true,
  pixelFormat: 3,
  size: {
    height: 4,
    width: 6
  }
}
image.createPixelMap(color, opts).then((pixelMap) => {
  effectKit.createColorPicker(pixelMap, (error, colorPicker) => {
    if (error) {
      console.error('Failed to create color picker.');
    } else {
      console.info('Succeeded in creating color picker.');
    }
  })
})
```

## effectKit.createColorPicker<sup>10+</sup>

createColorPicker(source: image.PixelMap, region:Array\<number>, callback: AsyncCallback\<ColorPicker>): void

Creates a **ColorPicker** instance for the selected region based on a pixel map. This API uses an asynchronous callback to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name    | Type               | Mandatory| Description                      |
| -------- | ------------------ | ---- | -------------------------- |
| source   | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | Yes |**PixelMap** instance created by the image module. You can obtain the PixelMap instance by decoding an image or directly creating one. For details, see [Image Kit Overview](../../media/image/image-overview.md). |
| region   | Array\<number> | Yes  |  Region of the image from which the color is picked.<br>The array consists of four elements, representing the left, top, right, and bottom positions of the image, respectively. The value of each element must be in the range [0, 1]. The leftmost and topmost positions of the image correspond to 0, and the rightmost and bottom positions correspond to 1. In the array, the third element must be greater than the first element, and the fourth element must be greater than the second element.|
| callback | AsyncCallback\<[ColorPicker](#colorpicker)> | Yes | Callback used to return the **ColorPicker** instance created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 401      | Input parameter error.             |

**Example**

```ts
import { image } from "@kit.ImageKit";
import { effectKit } from "@kit.ArkGraphics2D";

const color = new ArrayBuffer(96);
let opts : image.InitializationOptions = {
  editable: true,
  pixelFormat: 3,
  size: {
    height: 4,
    width: 6
  }
}
image.createPixelMap(color, opts).then((pixelMap) => {
  effectKit.createColorPicker(pixelMap, [0, 0, 1, 1], (error, colorPicker) => {
    if (error) {
      console.error('Failed to create color picker.');
    } else {
      console.info('Succeeded in creating color picker.');
    }
  })
})
```

## Color

A class that stores the color picked.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name  | Type  | Read-Only| Optional| Description             |
| ------ | ----- | ---- | ---- | ---------------- |
| red   | number | No  | No  | Value of the red component. The value range is [0x0, 0xFF].          |
| green | number | No  | No  | Value of the green component. The value range is [0x0, 0xFF].          |
| blue  | number | No  | No  | Value of the blue component. The value range is [0x0, 0xFF].          |
| alpha | number | No  | No  | Value of the alpha component. The value range is [0x0, 0xFF].      |

## TileMode<sup>14+</sup>

Enumerates the tile modes of the shader effect.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name                  | Value  | Description                          |
| ---------------------- | ---- | ------------------------------ |
| CLAMP     | 0    | Replicates the edge color if the shader effect draws outside of its original boundary.|
| REPEAT    | 1    | Repeats the shader effect in both horizontal and vertical directions.|
| MIRROR    | 2    | Repeats the shader effect in both horizontal and vertical directions, alternating mirror images.|
| DECAL     | 3    | Renders the shader effect only within the original boundary.|

## ColorPicker

A class used to obtain the color from an image. Before calling any method of **ColorPicker**, use [createColorPicker](#effectkitcreatecolorpicker) to create a **ColorPicker** instance.

### getMainColor

getMainColor(): Promise\<Color>

Obtains the main color from the image and writes the result to a [Color](#color) instance. This API uses a promise to return the result. This API uses the image scaling algorithm to reduce the original image to one pixel based on the weighted calculation of surrounding pixels to obtain the main color.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type          | Description                                           |
| :------------- | :---------------------------------------------- |
| Promise\<[Color](#color)> | Promise used to return the color value of the main color. If the operation fails, an error message is returned.|

**Example**

```ts
import { image } from "@kit.ImageKit";
import { effectKit } from "@kit.ArkGraphics2D";

const color = new ArrayBuffer(96);
let opts: image.InitializationOptions = {
  editable: true,
  pixelFormat: 3,
  size: {
    height: 4,
    width: 6
  }
}
image.createPixelMap(color, opts).then((pixelMap) => {
  effectKit.createColorPicker(pixelMap, (error, colorPicker) => {
    if (error) {
      console.error('Failed to create color picker.');
     } else {
       console.info('Succeeded in creating color picker.');
       colorPicker.getMainColor().then(color => {
        console.info('Succeeded in getting main color.');
         console.info(`color[ARGB]=${color.alpha},${color.red},${color.green},${color.blue}`);
      })
    }
  })
})
```

### getMainColorSync

getMainColorSync(): Color

Obtains the main color from the image and writes the result to a [Color](#color) instance. This API returns the result synchronously. This API uses the image scaling algorithm to calculate the weighted value of the surrounding pixels and shrinks the original image to one pixel to obtain the main color.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type    | Description                                 |
| :------- | :----------------------------------- |
| [Color](#color)    | Color value of the main color. If the operation fails, **null** is returned.|

**Example**

```ts
import { image } from "@kit.ImageKit";
import { effectKit } from "@kit.ArkGraphics2D";

const color = new ArrayBuffer(96);
let opts : image.InitializationOptions = {
  editable: true,
  pixelFormat: 3,
  size: {
    height: 4,
    width: 6
  }
}
image.createPixelMap(color, opts).then((pixelMap) => {
  effectKit.createColorPicker(pixelMap, (error, colorPicker) => {
    if (error) {
      console.error('Failed to create color picker.');
    } else {
      console.info('Succeeded in creating color picker.');
      let color = colorPicker.getMainColorSync();
      console.info('get main color =' + color);
    }
  })
})
```
![image_Main_Color.png](figures/image_Main_Color.png)

### getLargestProportionColor<sup>10+</sup>

getLargestProportionColor(): Color

Reads the most common color value in an image and writes the result to [Color](#color). This API is synchronous. This API uses the median split algorithm to divide the color space and obtain the average color of the most common color space.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type          | Description                                           |
| :------------- | :---------------------------------------------- |
| [Color](#color)       | Color value of the color with the largest proportion. If the operation fails, **null** is returned.|

**Example**

```ts
import { image } from "@kit.ImageKit";
import { effectKit } from "@kit.ArkGraphics2D";

const color = new ArrayBuffer(96);
let opts : image.InitializationOptions = {
  editable: true,
  pixelFormat: 3,
  size: {
    height: 4,
    width: 6
  }
}
image.createPixelMap(color, opts).then((pixelMap) => {
  effectKit.createColorPicker(pixelMap, (error, colorPicker) => {
    if (error) {
      console.error('Failed to create color picker.');
    } else {
      console.info('Succeeded in creating color picker.');
      let color = colorPicker.getLargestProportionColor();
      console.info('get largest proportion color =' + color);
    }
  })
})
```
![image_Largest_Proportion_Color.png](figures/image_Largest_Proportion_Color.png)

### getTopProportionColors<sup>12+</sup>

getTopProportionColors(colorCount: number): Array<Color | null>

Obtains a given number of colors with the top proportions in the image. This API returns the result synchronously.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**
| Name     | Type  | Mandatory| Description             |
| ---------- | ------ | ---- | ------------------------------------------- |
| colorCount | number | Yes  | Number of colors to obtain. The value range is [1, 10]. If a non-integer is passed in, the value will be rounded down.  |

**Return value**

| Type                                    | Description                                           |
| :--------------------------------------- | :---------------------------------------------- |
| Array<[Color](#color) \| null> | Array of colors, sorted by proportion.<br>- If the number of colors obtained is less than the value of **colorCount**, the array size is the actual number obtained.<br>- If the colors fail to be obtained or the number of colors obtained is less than 1, **[null]** is returned.<br>- If the value of **colorCount** is greater than 10, an array holding the first 10 colors with the top proportions is returned.|

**Example**

```js
import { image } from "@kit.ImageKit";
import { effectKit } from "@kit.ArkGraphics2D";

const color = new ArrayBuffer(96);
let opts : image.InitializationOptions = {
  editable: true,
  pixelFormat: 3,
  size: {
    height: 4,
    width: 6
  }
}
image.createPixelMap(color, opts).then((pixelMap) => {
  effectKit.createColorPicker(pixelMap, (error, colorPicker) => {
    if (error) {
      console.error('Failed to create color picker.');
    } else {
      console.info('Succeeded in creating color picker.');
      let colors = colorPicker.getTopProportionColors(2);
      for(let index = 0; index < colors.length; index++) {
        if (colors[index]) {
          console.info('get top proportion colors: index ' + index + ', color ' + colors[index]);
        }
      }
    }
  })
})
```
![image_Top_Proportion_Colors.png](figures/image_Top_Proportion_Colors.png)

### getHighestSaturationColor<sup>10+</sup>

getHighestSaturationColor(): Color

Obtains the color with the highest saturation from the image and writes the result to a [Color](#color) instance. This API returns the result synchronously.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type          | Description                                           |
| :------------- | :---------------------------------------------- |
| [Color](#color)       | Color value of the color with the highest saturation. If the operation fails, **null** is returned.|

**Example**

```ts
import { image } from "@kit.ImageKit";
import { effectKit } from "@kit.ArkGraphics2D";

const color = new ArrayBuffer(96);
let opts: image.InitializationOptions = {
  editable: true,
  pixelFormat: 3,
  size: {
    height: 4,
    width: 6
  }
}
image.createPixelMap(color, opts).then((pixelMap) => {
  effectKit.createColorPicker(pixelMap, (error, colorPicker) => {
    if (error) {
      console.error('Failed to create color picker.');
    } else {
      console.info('Succeeded in creating color picker.');
      let color = colorPicker.getHighestSaturationColor();
      console.info('get highest saturation color =' + color);
    }
  })
})
```
![image_Highest_Saturation_Color.png](figures/image_Highest_Saturation_Color.png)

### getAverageColor<sup>10+</sup>

getAverageColor(): Color

Obtains the average color from the image and writes the result to a [Color](#color) instance. This API returns the result synchronously.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type          | Description                                           |
| :------------- | :---------------------------------------------- |
| [Color](#color)       | Average color value. If the operation fails, **null** is returned.|

**Example**

```ts
import { image } from "@kit.ImageKit";
import { effectKit } from "@kit.ArkGraphics2D";

const color = new ArrayBuffer(96);
let opts: image.InitializationOptions = {
  editable: true,
  pixelFormat: 3,
  size: {
    height: 4,
    width: 6
  }
}
image.createPixelMap(color, opts).then((pixelMap) => {
  effectKit.createColorPicker(pixelMap, (error, colorPicker) => {
    if (error) {
      console.error('Failed to create color picker.');
    } else {
      console.info('Succeeded in creating color picker.');
      let color = colorPicker.getAverageColor();
      console.info('get average color =' + color);
    }
  })
})
```
![image_Average_Color.png](figures/image_Average_Color.png)

### isBlackOrWhiteOrGrayColor<sup>10+</sup>

isBlackOrWhiteOrGrayColor(color: number): boolean

Checks whether a color is black, white, and gray.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name    | Type        | Mandatory| Description                      |
| -------- | ----------- | ---- | -------------------------- |
| color| number | Yes  |  Color to check. The value range is [0x0, 0xFFFFFFFF].|

**Return value**

| Type          | Description                                           |
| :------------- | :---------------------------------------------- |
| boolean              | true if the image is in grayscale; false otherwise.|

**Example**

```ts
import { image } from "@kit.ImageKit";
import { effectKit } from "@kit.ArkGraphics2D";

const color = new ArrayBuffer(96);
let opts: image.InitializationOptions = {
  editable: true,
  pixelFormat: 3,
  size: {
    height: 4,
    width: 6
  }
}
image.createPixelMap(color, opts).then((pixelMap) => {
  effectKit.createColorPicker(pixelMap, (error, colorPicker) => {
    if (error) {
      console.error('Failed to create color picker.');
    } else {
      console.info('Succeeded in creating color picker.');
      let bJudge = colorPicker.isBlackOrWhiteOrGrayColor(0xFFFFFFFF);
      console.info('is black or white or gray color[bool](white) =' + bJudge);
    }
  })
})
```

## Filter

A class used to add a specified effect to an image. Before calling any method of **Filter**, use [createEffect](#effectkitcreateeffect) to create a **Filter** instance.

### blur

blur(radius: number): Filter

Adds the blur effect to the effect linked list and returns the head node of the linked list.

>  **NOTE**
>
>  This API provides the blur effect for static images. To provide the real-time blur effect for components, use [dynamic blur](../../ui/arkts-blur-effect.md).

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type       | Mandatory| Description                                                        |
| ------ | ----------- | ---- | ------------------------------------------------------------ |
|  radius   | number | Yes  | Blur radius, in pixels. The blur effect is proportional to the configured value. A larger value indicates a more obvious effect.|

**Return value**

| Type          | Description                                           |
| :------------- | :---------------------------------------------- |
| [Filter](#filter) | Final image effect.|

**Example**

```ts
import { image } from "@kit.ImageKit";
import { effectKit } from "@kit.ArkGraphics2D";

const color = new ArrayBuffer(96);
let opts : image.InitializationOptions = {
  editable: true,
  pixelFormat: 3,
  size: {
    height: 4,
    width: 6
  }
};
image.createPixelMap(color, opts).then((pixelMap) => {
  let radius = 5;
  let headFilter = effectKit.createEffect(pixelMap);
  if (headFilter != null) {
    headFilter.blur(radius);
  }
})
```
![image_Add_Blur.png](figures/image_Add_Blur.png)

### blur<sup>14+</sup>

blur(radius: number, tileMode: TileMode): Filter

Adds a blur effect to the effect linked list and returns the head node of the linked list.

>  **NOTE**
>
>  This API provides the blur effect for static images. To provide the real-time blur effect for components, use [dynamic blur](../../ui/arkts-blur-effect.md).

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type       | Mandatory| Description                                                        |
| ------ | ----------- | ---- | ------------------------------------------------------------ |
|  radius   | number | Yes  | Blur radius, in pixels. The blur effect is proportional to the configured value. A larger value indicates a more obvious effect.|
|  tileMode   | [TileMode](#tilemode14) | Yes  | Tile mode of the shader effect. The blur effect of image edges is affected. Currently, only CPU rendering is supported. Therefore, the tile mode supports only DECAL.|

**Return value**

| Type          | Description                                           |
| :------------- | :---------------------------------------------- |
| [Filter](#filter) | Final image effect.|

**Example**

```ts
import { image } from "@kit.ImageKit";
import { effectKit } from "@kit.ArkGraphics2D";

const color = new ArrayBuffer(96);
let opts : image.InitializationOptions = {
  editable: true,
  pixelFormat: 3,
  size: {
    height: 4,
    width: 6
  }
};
image.createPixelMap(color, opts).then((pixelMap) => {
  let radius = 30;
  let headFilter = effectKit.createEffect(pixelMap);
  if (headFilter != null) {
    headFilter.blur(radius, effectKit.TileMode.DECAL);
  }
})
```
![image_Add_Blur_With_TileMode.png](figures/image_Add_Blur_With_TileMode.png)

### invert<sup>12+</sup>

invert(): Filter

Adds a reverse effect to the effect linked list and returns the head node of the linked list.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type          | Description                                           |
| :------------- | :---------------------------------------------- |
| [Filter](#filter) | Final image effect.|

**Example**

```ts
import { image } from "@kit.ImageKit";
import { effectKit } from "@kit.ArkGraphics2D";

const color = new ArrayBuffer(96);
let opts : image.InitializationOptions = {
  editable: true,
  pixelFormat: 3,
  size: {
    height: 4,
    width: 6
  }
};
image.createPixelMap(color, opts).then((pixelMap) => {
  let headFilter = effectKit.createEffect(pixelMap);
  if (headFilter != null) {
    headFilter.invert();
  }
})
```
![image_Add_Invert.png](figures/image_Add_Invert.png)

### setColorMatrix<sup>12+</sup>

setColorMatrix(colorMatrix: Array\<number>): Filter

Adds a custom effect to the effect linked list and returns the head node of the linked list.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type       | Mandatory| Description                                                        |
| ------ | ----------- | ---- | ------------------------------------------------------------ |
|  colorMatrix  |   Array\<number> | Yes  | Custom color matrix.<br>A 5 x 4 matrix can be created. The value range of the matrix element is [0, 1], where **0** indicates that the color channel is not involved in the calculation, and **1** indicates that the color channel is involved in the calculation and retains the original weight.|

**Return value**

| Type          | Description                                           |
| :------------- | :---------------------------------------------- |
| [Filter](#filter) | Final image effect.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 401      | Input parameter error.             |

**Example**

```ts
import { image } from "@kit.ImageKit";
import { effectKit } from "@kit.ArkGraphics2D";

const color = new ArrayBuffer(96);
let opts : image.InitializationOptions = {
  editable: true,
  pixelFormat: 3,
  size: {
    height: 4,
    width: 6
  }
};
image.createPixelMap(color, opts).then((pixelMap) => {
  let colorMatrix:Array<number> = [
    0.2126,0.7152,0.0722,0,0,
    0.2126,0.7152,0.0722,0,0,
    0.2126,0.7152,0.0722,0,0,
    0,0,0,1,0
  ];
  let headFilter = effectKit.createEffect(pixelMap);
  if (headFilter != null) {
    headFilter.setColorMatrix(colorMatrix);
  }
})
```

### brightness

brightness(bright: number): Filter

Adds the highlight effect to the effect linked list and returns the head node of the linked list.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type       | Mandatory| Description                                                        |
| ------ | ----------- | ---- | ------------------------------------------------------------ |
|  bright   | number | Yes  | Brightness value, ranging from 0 to 1. When the value is **0**, the image brightness remains unchanged.|

**Return value**

| Type          | Description                                           |
| :------------- | :---------------------------------------------- |
| [Filter](#filter) | Final image effect.|

**Example**

```ts
import { image } from "@kit.ImageKit";
import { effectKit } from "@kit.ArkGraphics2D";

const color = new ArrayBuffer(96);
let opts : image.InitializationOptions = {
  editable: true,
  pixelFormat: 3,
  size: {
    height: 4,
    width: 6
  }
};
image.createPixelMap(color, opts).then((pixelMap) => {
  let bright = 0.5;
  let headFilter = effectKit.createEffect(pixelMap);
  if (headFilter != null) {
    headFilter.brightness(bright);
  }
})
```
![image_Add_Brightness.png](figures/image_Add_Brightness.png)

### grayscale

grayscale(): Filter

Adds the grayscale effect to the effect list and returns the head node of the list.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type          | Description                                           |
| :------------- | :---------------------------------------------- |
| [Filter](#filter) | Final image effect.|

**Example**

```ts
import { image } from "@kit.ImageKit";
import { effectKit } from "@kit.ArkGraphics2D";

const color = new ArrayBuffer(96);
let opts : image.InitializationOptions = {
  editable: true,
  pixelFormat: 3,
  size: {
    height: 4,
    width: 6
  }
};
image.createPixelMap(color, opts).then((pixelMap) => {
  let headFilter = effectKit.createEffect(pixelMap);
  if (headFilter != null) {
    headFilter.grayscale();
  }
})
```
![image_Add_Grayscale.png](figures/image_Add_Grayscale.png)

### getEffectPixelMap<sup>11+</sup>

getEffectPixelMap(): Promise<image.PixelMap>

Obtains the image.PixelMap of the source image that has the linked list effect added. The rendering is performed by the CPU. This API uses an asynchronous callback through a promise.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                  | Description          |
| ---------------------- | -------------- |
| Promise\<image.PixelMap>  | Promise used to return **image.PixelMap** of the source image.|


**Example**

```ts
import { image } from "@kit.ImageKit";
import { effectKit } from "@kit.ArkGraphics2D";

const color = new ArrayBuffer(96);
let opts : image.InitializationOptions = {
  editable: true,
  pixelFormat: 3,
  size: {
    height: 4,
    width: 6
  }
};
image.createPixelMap(color, opts).then((pixelMap) => {
  effectKit.createEffect(pixelMap).grayscale().getEffectPixelMap().then(data => {
    console.info('getPixelBytesNumber = ', data.getPixelBytesNumber());
  })
})
```

### getEffectPixelMap<sup>20+</sup>

getEffectPixelMap(useCpuRender : boolean): Promise<image.PixelMap>

Obtains the image.PixelMap of the source image with the linked list effect. The rendering mode (CPU rendering or GPU rendering) can be specified. This API uses a promise to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 20.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type       | Mandatory| Description                                                        |
| ------ | ----------- | ---- | ------------------------------------------------------------ |
|  useCpuRender   | boolean | Yes  | Rendering mode. true: CPU rendering. false: GPU rendering.|

**Return value**

| Type                  | Description          |
| ---------------------- | -------------- |
| Promise\<[image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)>  | Promise used to return **image.PixelMap** of the source image.|


**Example**

```ts
import { image } from "@kit.ImageKit";
import { effectKit } from "@kit.ArkGraphics2D";

const color = new ArrayBuffer(96);
let opts : image.InitializationOptions = {
  editable: true,
  pixelFormat: 3,
  size: {
    height: 4,
    width: 6
  }
};
image.createPixelMap(color, opts).then((pixelMap) => {
  effectKit.createEffect(pixelMap).grayscale().getEffectPixelMap(false).then(data => {
    console.info('getPixelBytesNumber = ', data.getPixelBytesNumber());
  })
})
```

### getPixelMap<sup>(deprecated)</sup>

getPixelMap(): image.PixelMap

Obtains **image.PixelMap** of the source image to which the filter linked list is added.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 11. You are advised to use [getEffectPixelMap](#geteffectpixelmap11) instead.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type          | Description                                           |
| :------------- | :---------------------------------------------- |
| [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | **image.PixelMap** of the source image.|

**Example**

```ts
import { image } from "@kit.ImageKit";
import { effectKit } from "@kit.ArkGraphics2D";

const color = new ArrayBuffer(96);
let opts : image.InitializationOptions = {
  editable: true,
  pixelFormat: 3,
  size: {
    height: 4,
    width: 6
  }
};
image.createPixelMap(color, opts).then((pixelMap) => {
  let pixel = effectKit.createEffect(pixelMap).grayscale().getPixelMap();
  console.info('getPixelBytesNumber = ', pixel.getPixelBytesNumber());
})
```
