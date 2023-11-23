# @ohos.effectKit    
图像效果提供处理图像的一些基础能力，包括对当前图像的亮度调节、模糊化、灰度调节、智能取色等。  
  
该模块提供以下图像效果相关的常用功能：  
  
- [Filter](#filter)：效果类，用于添加指定效果到图像源。  
- [Color](#color)：颜色类，用于保存取色的结果。  
- [ColorPicker](#colorpicker)：智能取色器。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import effectKit from '@ohos.effectKit'    
```  
    
## Filter    
图像效果类，用于将指定的效果添加到输入图像中。在调用Filter的方法前，需要先通过[createEffect](#effectkitcreateeffect)创建一个Filter实例。  
 **系统能力:**  SystemCapability.Multimedia.Image.Core    
### blur    
将模糊效果添加到效果链表中，结果返回效果链表的头节点。  
 **调用形式：**     
- blur(radius: number): Filter  
  
 **系统能力:**  SystemCapability.Multimedia.Image.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| radius | number | true | 模糊半径，单位是像素。模糊效果与所设置的值成正比，值越大效果越明显。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Filter | 返回已添加的图像效果。 |  
    
 **示例代码：**   
示例：  
```ts    
import image from "@ohos.multimedia.image";  
import effectKit from "@ohos.effectKit";  
  
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
  
![zh-ch_image_Add_Blur.png](figures/zh-ch_image_Add_Blur.png)  
    
### brightness    
将高亮效果添加到效果链表中，结果返回效果链表的头节点。  
 **调用形式：**     
- brightness(bright: number): Filter  
  
 **系统能力:**  SystemCapability.Multimedia.Image.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bright | number | true | 高亮程度，取值范围在0-1之间，取值为0时图像保持不变。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Filter | 返回已添加的图像效果。 |  
    
 **示例代码：**   
示例：  
```ts    
import image from "@ohos.multimedia.image";  
import effectKit from "@ohos.effectKit";  
  
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
  
![zh-ch_image_Add_Brightness.png](figures/zh-ch_image_Add_Brightness.png)  
    
### grayscale    
将灰度效果添加到效果链表中，结果返回效果链表的头节点。  
 **调用形式：**     
- grayscale(): Filter  
  
 **系统能力:**  SystemCapability.Multimedia.Image.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Filter | 返回已添加的图像效果。 |  
    
 **示例代码：**   
示例：  
```ts    
import image from "@ohos.multimedia.image";  
import effectKit from "@ohos.effectKit";  
  
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
  
![zh-ch_image_Add_Grayscale.png](figures/zh-ch_image_Add_Grayscale.png)  
    
### getPixelMap    
获取已添加链表效果的源图像的image.PixelMap。  
 **调用形式：**     
- getPixelMap(): image.PixelMap  
  
 **系统能力:**  SystemCapability.Multimedia.Image.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| image.PixelMap | 已添加效果的源图像的image.PixelMap。 |  
    
 **示例代码：**   
示例：  
```ts    
import image from "@ohos.multimedia.image";  
import effectKit from "@ohos.effectKit";  
  
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
  console.log('getPixelBytesNumber = ', pixel.getPixelBytesNumber());  
})    
```    
  
    
## ColorPicker    
取色类，用于从一张图像数据中获取它的主要颜色。在调用ColorPicker的方法前，需要先通过[createColorPicker](#effectkitcreatecolorpicker)创建一个ColorPicker实例。  
 **系统能力:**  SystemCapability.Multimedia.Image.Core    
### getMainColor    
读取图像主色的颜色值，结果写入[Color](#color)里，使用Promise异步回调。  
 **调用形式：**     
    
- getMainColor(): Promise\<Color>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Multimedia.Image.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<Color> | Promise对象。返回图像主色对应的颜色值，失败时返回错误信息。 |  
    
 **示例代码：**   
示例：  
```ts    
import image from "@ohos.multimedia.image";  
import effectKit from "@ohos.effectKit";  
  
export function test06(): void {  
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
        console.log('Failed to create color picker.');  
      } else {  
        console.log('Succeeded in creating color picker.');  
        colorPicker.getMainColor().then(color => {  
          console.log('Succeeded in getting main color.');  
          console.info(`color[ARGB]=${color.alpha},${color.red},${color.green},${color.blue}`);  
        })  
      }  
    })  
  })  
}  
    
```    
  
    
### getMainColorSync    
读取图像主色的颜色值，结果写入[Color](#color)里，使用同步方式返回。  
 **调用形式：**     
- getMainColorSync(): Color  
  
 **系统能力:**  SystemCapability.Multimedia.Image.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Color | Color实例，即图像主色对应的颜色值，失败时返回null。 | |  
    
 **示例代码：**   
示例：  
```ts    
import image from "@ohos.multimedia.image";  
import effectKit from "@ohos.effectKit";  
  
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
      console.log('Failed to create color picker.');  
    } else {  
      console.log('Succeeded in creating color picker.');  
      let color = colorPicker.getMainColorSync();  
      console.log('get main color =' + color);  
    }  
  })  
})  
    
```    
  
![zh-ch_image_Main_Color.png](figures/zh-ch_image_Main_Color.png)  
    
### getLargestProportionColor<sup>(10+)</sup>    
读取图像占比最多的颜色值，结果写入[Color](#color)里，使用同步方式返回。  
 **调用形式：**     
- getLargestProportionColor(): Color  
  
 **系统能力:**  SystemCapability.Multimedia.Image.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Color | Color实例，即图像占比最多的颜色值，失败时返回null。 |  
    
 **示例代码：**   
示例：  
```ts    
import image from "@ohos.multimedia.image";  
import effectKit from "@ohos.effectKit";  
  
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
      console.log('Failed to create color picker.');  
    } else {  
      console.log('Succeeded in creating color picker.');  
      let color = colorPicker.getLargestProportionColor();  
      console.log('get largest proportion color =' + color);  
    }  
  })  
})  
    
```    
  
![zh-ch_image_Largest_Proportion_Color.png](figures/zh-ch_image_Largest_Proportion_Color.png)  
    
### getHighestSaturationColor<sup>(10+)</sup>    
读取图像饱和度最高的颜色值，结果写入[Color](#color)里，使用同步方式返回。  
 **调用形式：**     
- getHighestSaturationColor(): Color  
  
 **系统能力:**  SystemCapability.Multimedia.Image.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Color | Color实例，即图像饱和度最高的颜色值，失败时返回null。 |  
    
 **示例代码：**   
示例：  
```ts    
import image from "@ohos.multimedia.image";  
import effectKit from "@ohos.effectKit";  
  
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
      console.log('Failed to create color picker.');  
    } else {  
      console.log('Succeeded in creating color picker.');  
      let color = colorPicker.getHighestSaturationColor();  
      console.log('get highest saturation color =' + color);  
    }  
  })  
})  
    
```    
  
![zh-ch_image_Highest_Saturation_Color.png](figures/zh-ch_image_Highest_Saturation_Color.png)  
    
### getAverageColor<sup>(10+)</sup>    
读取图像平均的颜色值，结果写入[Color](#color)里，使用同步方式返回。  
 **调用形式：**     
- getAverageColor(): Color  
  
 **系统能力:**  SystemCapability.Multimedia.Image.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Color | Color实例，即图像平均的颜色值，失败时返回null。 |  
    
 **示例代码：**   
示例：  
```ts    
import image from "@ohos.multimedia.image";  
import effectKit from "@ohos.effectKit";  
  
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
      console.log('Failed to create color picker.');  
    } else {  
      console.log('Succeeded in creating color picker.');  
      let color = colorPicker.getAverageColor();  
      console.log('get average color =' + color);  
    }  
  })  
})  
    
```    
  
![zh-ch_image_Average_Color.png](figures/zh-ch_image_Average_Color.png)  
    
### isBlackOrWhiteOrGrayColor<sup>(10+)</sup>    
判断图像是否为黑白灰颜色，返回true或false。  
 **调用形式：**     
- isBlackOrWhiteOrGrayColor(color: number): boolean  
  
 **系统能力:**  SystemCapability.Multimedia.Image.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| color | number | true | 需要判断是否黑白灰色的颜色值，取值范围[0x0, 0xFFFFFFFF]。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果此图像为黑白灰颜色，则返回true；否则返回false。 |  
    
 **示例代码：**   
示例：  
```null    
import image from "@ohos.multimedia.image";  
import effectKit from "@ohos.effectKit";  
  
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
      console.log('Failed to create color picker.');  
    } else {  
      console.log('Succeeded in creating color picker.');  
      let bJudge = colorPicker.isBlackOrWhiteOrGrayColor(0xFFFFFFFF);  
      console.log('is black or white or gray color[bool](white) =' + bJudge);  
    }  
  })  
})  
    
```    
  
    
## Color    
颜色类，用于保存取色的结果。  
 **系统能力:**  SystemCapability.Multimedia.Image.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.Image.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| red | number | false | true | 红色分量值，取值范围[0x0, 0xFF]。           。 |  
| green | number | false | true | 绿色分量值，取值范围[0x0, 0xFF]。            |  
| blue | number | false | true | 蓝色分量值，取值范围[0x0, 0xFF]。            |  
| alpha | number | false | true | 透明通道分量值，取值范围[0x0, 0xFF]。        |  
    
## createEffect    
通过传入的PixelMap创建Filter实例。  
 **调用形式：**     
- createEffect(source: image.PixelMap): Filter  
  
 **系统能力:**  SystemCapability.Multimedia.Image.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| source | image.PixelMap | true | image模块创建的PixelMap实例。可通过图片解码或直接创建获得，具体可见[图片开发指导](../../media/image-overview.md)。    |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Filter | 返回不带任何效果的Filter链表的头节点，失败时返回null。 |  
    
 **示例代码：**   
示例：  
```ts    
import image from "@ohos.multimedia.image";  
import effectKit from "@ohos.effectKit";  
  
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
  
    
## createColorPicker    
通过传入的PixelMap创建ColorPicker实例，使用Promise异步回调  
 **调用形式：**     
    
- createColorPicker(source: image.PixelMap): Promise\<ColorPicker>    
起始版本： 9    
- createColorPicker(source: image.PixelMap, region: Array\<number>): Promise\<ColorPicker>    
起始版本： 10    
- createColorPicker(source: image.PixelMap, callback: AsyncCallback\<ColorPicker>): void    
起始版本： 9    
- createColorPicker(source: image.PixelMap, region: Array\<number>, callback: AsyncCallback\<ColorPicker>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Multimedia.Image.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| source | image.PixelMap | true | image模块创建的PixelMap实例。可通过图片解码或直接创建获得，具体可见[图片开发指导](../../media/image-overview.md)。  |  
| region<sup>(10+)</sup> | Array<number> | true | 指定图片的取色区域。<br>数组元素个数为4，取值范围为[0, 1]，数组元素分别表示图片区域的左、上、右、下位置，图片最左侧和最上侧对应位置0，最右侧和最下侧对应位置1。数组第三个元素需大于第一个元素，第四个元素需大于第二个元素。<br>此参数不填时，默认值为[0, 0, 1, 1]，表示取色区域为全图。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回创建的ColorPicker实例。 |  
| Promise<ColorPicker> | Promise对象。返回创建的ColorPicker实例。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：参数为：source  
```ts    
import image from "@ohos.multimedia.image";  
import effectKit from "@ohos.effectKit";  
  
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
      console.log('Failed to create color picker.');  
    } else {  
      console.log('Succeeded in creating color picker.');  
    }  
  })  
})  
    
```    
  
    
 **示例代码2：**   
示例（callback）：参数为：source、region  
  
```ts    
import image from "@ohos.multimedia.image";  
import effectKit from "@ohos.effectKit";  
  
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
      console.log('Failed to create color picker.');  
    } else {  
      console.log('Succeeded in creating color picker.');  
    }  
  })  
})  
    
```    
  
    
 **示例代码3：**   
示例（Promise）：参数为：source  
  
```ts    
import image from "@ohos.multimedia.image";  
import effectKit from "@ohos.effectKit";  
  
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
  
    
 **示例代码4：**   
示例（Promise）：参数为：source、region  
  
```ts    
import image from "@ohos.multimedia.image";  
import effectKit from "@ohos.effectKit";  
  
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
  
