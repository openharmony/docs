# @ohos.wallpaper    
壁纸管理服务是OpenHarmony中的系统服务，主要为系统提供壁纸管理服务能力，支持系统显示、设置、切换壁纸等功能。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import wallpaper from '@ohos.wallpaper'    
```  
    
## RgbaColor<sup>(deprecated)</sup>    
定义壁纸颜色信息结构。    
从API version 7 开始支持，从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Wallpaper    
### 属性    
 **系统能力:**  SystemCapability.MiscServices.Wallpaper    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| red<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示红色值，范围为 0 到 255。 |  
| green<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示绿色值，范围为 0 到 255。 |  
| blue<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示蓝色值，范围为 0 到 255。 |  
| alpha<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示 alpha 值，范围为 0 到 255。 |  
    
## WallpaperType    
定义壁纸的枚举类型。    
    
 **系统能力:**  SystemCapability.MiscServices.Wallpaper    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| WALLPAPER_SYSTEM | 0 | 主屏幕壁纸标识。 |  
| WALLPAPER_LOCKSCREEN | 1 | 锁屏壁纸标识。 |  
    
## getColors<sup>(deprecated)</sup>    
获取指定类型壁纸的主要颜色信息。  
 **调用形式：**     
- getColors(wallpaperType: WallpaperType, callback: AsyncCallback\<Array\<RgbaColor>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Wallpaper    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| wallpaperType<sup>(deprecated)</sup> | WallpaperType | true | 壁纸类型。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<RgbaColor>> | true | 回调函数，返回壁纸的主要颜色信息。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
wallpaper.getColors(wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error: BusinessError, data: Array<wallpaper.RgbaColor>) => {  
    if (error) {  
        console.error(`failed to getColors because: ${JSON.stringify(error)}`);  
        return;  
    }  
    console.log(`success to getColors: ${JSON.stringify(data)}`);  
});  
    
```    
  
    
## getColors<sup>(deprecated)</sup>    
获取指定类型壁纸的主要颜色信息。  
 **调用形式：**     
- getColors(wallpaperType: WallpaperType): Promise\<Array\<RgbaColor>>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Wallpaper    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| wallpaperType<sup>(deprecated)</sup> | WallpaperType | true | 壁纸类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<RgbaColor>> | 返回壁纸的主要颜色信息。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
wallpaper.getColors(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data: Array<wallpaper.RgbaColor>) => {  
    console.log(`success to getColors: ${JSON.stringify(data)}`);  
  }).catch((error: BusinessError) => {  
    console.error(`failed to getColors because: ${JSON.stringify(error)}`);  
});  
    
```    
  
    
## getId<sup>(deprecated)</sup>    
获取指定类型壁纸的ID。  
 **调用形式：**     
- getId(wallpaperType: WallpaperType, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Wallpaper    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| wallpaperType<sup>(deprecated)</sup> | WallpaperType | true | 壁纸类型。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 回调函数，返回壁纸的ID。如果配置了指定类型的壁纸就返回一个大于等于0的数，否则返回-1。取值范围是-1到（2^31-1）。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
wallpaper.getId(wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error: BusinessError, data: Number) => {  
    if (error) {  
        console.error(`failed to getId because: ${JSON.stringify(error)}`);  
        return;  
    }  
    console.log(`success to getId: ${JSON.stringify(data)}`);  
});  
    
```    
  
    
## getId<sup>(deprecated)</sup>    
获取指定类型壁纸的ID。  
 **调用形式：**     
- getId(wallpaperType: WallpaperType): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Wallpaper    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| wallpaperType<sup>(deprecated)</sup> | WallpaperType | true | 壁纸类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | 壁纸的ID。如果配置了这种壁纸类型的壁纸就返回一个大于等于0的数，否则返回-1。取值范围是-1到（2^31-1）。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
wallpaper.getId(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data: Number) => {  
    console.log(`success to getId: ${JSON.stringify(data)}`);  
  }).catch((error: BusinessError) => {  
    console.error(`failed to getId because: ${JSON.stringify(error)}`);  
});  
    
```    
  
    
## getFile<sup>(deprecated)</sup>    
获取指定类型的壁纸文件。  
 **调用形式：**     
- getFile(wallpaperType: WallpaperType, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Wallpaper  
 **需要权限：** ohos.permission.GET_WALLPAPER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| wallpaperType<sup>(deprecated)</sup> | WallpaperType | true | 壁纸类型。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 回调函数，调用成功则返回壁纸文件描述符ID，调用失败则返回error信息。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
wallpaper.getFile(wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error: BusinessError, data: number) => {  
    if (error) {  
        console.error(`failed to getFile because: ${JSON.stringify(error)}`);  
        return;  
    }  
    console.log(`success to getFile: ${JSON.stringify(data)}`);  
});  
    
```    
  
    
## getFile<sup>(deprecated)</sup>    
获取指定类型的壁纸文件。  
 **调用形式：**     
- getFile(wallpaperType: WallpaperType): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Wallpaper  
 **需要权限：** ohos.permission.GET_WALLPAPER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| wallpaperType<sup>(deprecated)</sup> | WallpaperType | true | 壁纸类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | 调用成功则返回壁纸文件描述符ID，调用失败则返回error信息。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
wallpaper.getFile(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data: number) => {  
    console.log(`success to getFile: ${JSON.stringify(data)}`);  
  }).catch((error: BusinessError) => {  
    console.error(`failed to getFile because: ${JSON.stringify(error)}`);  
});  
    
```    
  
    
## getMinHeight<sup>(deprecated)</sup>    
获取壁纸的最小高度值。  
 **调用形式：**     
- getMinHeight(callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Wallpaper    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 回调函数，返回壁纸的最小高度值，单位是像素。如果返回值等于0，说明没有设置壁纸，调用者应该使用默认显示的高度值代替。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
wallpaper.getMinHeight((error: BusinessError, data: Number) => {  
    if (error) {  
        console.error(`failed to getMinHeight because: ${JSON.stringify(error)}`);  
        return;  
    }  
    console.log(`success to getMinHeight: ${JSON.stringify(data)}`);  
});  
    
```    
  
    
## getMinHeight<sup>(deprecated)</sup>    
获取壁纸的最小高度值。  
 **调用形式：**     
- getMinHeight(): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Wallpaper    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | 返回壁纸的最小高度值，单位是像素。如果返回值等于0，说明没有设置壁纸，调用者应该使用默认显示的高度值代替。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
wallpaper.getMinHeight().then((data: Number) => {  
    console.log(`success to getMinHeight: ${JSON.stringify(data)}`);  
}).catch((error: BusinessError) => {  
    console.error(`failed to getMinHeight because: ${JSON.stringify(error)}`);  
});  
    
```    
  
    
## getMinWidth<sup>(deprecated)</sup>    
获取壁纸的最小宽度值。  
 **调用形式：**     
- getMinWidth(callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Wallpaper    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 回调函数，壁纸的最小宽度值，单位是像素。如果返回值等于0，说明没有设置壁纸，调用者应该使用默认显示的宽度值代替。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
wallpaper.getMinWidth((error: BusinessError, data: Number) => {  
    if (error) {  
        console.error(`failed to getMinWidth because: ${JSON.stringify(error)}`);  
        return;  
    }  
    console.log(`success to getMinWidth: ${JSON.stringify(data)}`);  
});  
    
```    
  
    
## getMinWidth<sup>(deprecated)</sup>    
获取壁纸的最小宽度值。  
 **调用形式：**     
- getMinWidth(): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Wallpaper    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | 壁纸的最小宽度值，单位是像素。如果返回值等于0，说明没有设置壁纸，调用者应该使用默认显示的宽度值代替。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
wallpaper.getMinWidth().then((data: Number) => {  
    console.log(`success to getMinWidth: ${JSON.stringify(data)}`);  
  }).catch((error: BusinessError) => {  
    console.error(`failed to getMinWidth because: ${JSON.stringify(error)}`);  
});  
    
```    
  
    
## isChangePermitted<sup>(deprecated)</sup>    
是否允许应用改变当前用户的壁纸。  
 **调用形式：**     
- isChangePermitted(callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Wallpaper    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 回调函数，返回是否允许应用改变当前用户的壁纸。如果允许返回true，否则返回false。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
wallpaper.isChangePermitted((error: BusinessError, data: Boolean) => {  
    if (error) {  
        console.error(`failed to isChangePermitted because: ${JSON.stringify(error)}`);  
        return;  
    }  
    console.log(`success to isChangePermitted: ${JSON.stringify(data)}`);  
});  
    
```    
  
    
## isChangePermitted<sup>(deprecated)</sup>    
是否允许应用改变当前用户的壁纸。  
 **调用形式：**     
- isChangePermitted(): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Wallpaper    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | 返回是否允许应用改变当前用户的壁纸。如果允许返回true，否则返回false。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
wallpaper.isChangePermitted().then((data: Boolean) => {  
    console.log(`success to isChangePermitted: ${JSON.stringify(data)}`);  
}).catch((error: BusinessError) => {  
    console.error(`failed to isChangePermitted because: ${JSON.stringify(error)}`);  
});  
    
```    
  
    
## isOperationAllowed<sup>(deprecated)</sup>    
是否允许用户设置壁纸。  
 **调用形式：**     
- isOperationAllowed(callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Wallpaper    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 回调函数，返回是否允许用户设置壁纸。如果允许返回true，否则返回false。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
wallpaper.isOperationAllowed((error: BusinessError, data: Boolean) => {  
    if (error) {  
        console.error(`failed to isOperationAllowed because: ${JSON.stringify(error)}`);  
        return;  
    }  
    console.log(`success to isOperationAllowed: ${JSON.stringify(data)}`);  
});  
    
```    
  
    
## isOperationAllowed<sup>(deprecated)</sup>    
是否允许用户设置壁纸。  
 **调用形式：**     
- isOperationAllowed(): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Wallpaper    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | 异步回调函数，返回是否允许用户设置壁纸。如果允许返回true，否则返回false。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
wallpaper.isOperationAllowed().then((data: Boolean) => {  
    console.log(`success to isOperationAllowed: ${JSON.stringify(data)}`);  
  }).catch((error: BusinessError) => {  
    console.error(`failed to isOperationAllowed because: ${JSON.stringify(error)}`);  
});  
    
```    
  
    
## reset<sup>(deprecated)</sup>    
移除指定类型的壁纸，恢复为默认显示的壁纸。  
 **调用形式：**     
- reset(wallpaperType: WallpaperType, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Wallpaper  
 **需要权限：** ohos.permission.SET_WALLPAPER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| wallpaperType<sup>(deprecated)</sup> | WallpaperType | true | 壁纸类型。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数，移除壁纸成功，error为undefined，否则返回error信息。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
wallpaper.reset(wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error: BusinessError) => {  
    if (error) {  
        console.error(`failed to reset because: ${JSON.stringify(error)}`);  
        return;  
    }  
    console.log(`success to reset.`);  
});  
    
```    
  
    
## reset<sup>(deprecated)</sup>    
移除指定类型的壁纸，恢复为默认显示的壁纸。  
 **调用形式：**     
- reset(wallpaperType: WallpaperType): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Wallpaper  
 **需要权限：** ohos.permission.SET_WALLPAPER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| wallpaperType<sup>(deprecated)</sup> | WallpaperType | true | 壁纸类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
wallpaper.reset(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then(() => {  
    console.log(`success to reset.`);  
}).catch((error: BusinessError) => {  
    console.error(`failed to reset because: ${JSON.stringify(error)}`);  
});  
    
```    
  
    
## setWallpaper<sup>(deprecated)</sup>    
将指定资源设置为指定类型的壁纸。  
 **调用形式：**     
- setWallpaper(    source: string | image.PixelMap,    wallpaperType: WallpaperType,    callback: AsyncCallback\<void>  ): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Wallpaper  
 **需要权限：** ohos.permission.SET_WALLPAPER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| source<sup>(deprecated)</sup> | string | true | JPEG或PNG文件的Uri路径，或者PNG格式文件的位图。 |  
| wallpaperType<sup>(deprecated)</sup> | WallpaperType | true | 壁纸类型。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数，设置壁纸成功，error为undefined，否则返回error信息。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
import image from '@ohos.multimedia.image';  
  
// source类型为string  
let wallpaperPath = "/data/storage/el2/base/haps/entry/files/js.jpeg";  
wallpaper.setWallpaper(wallpaperPath, wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error: BusinessError) => {  
    if (error) {  
        console.error(`failed to setWallpaper because: ${JSON.stringify(error)}`);  
       return;  
       }  
    console.log(`success to setWallpaper.`);  
});  
  
// source类型为image.PixelMap  
let imageSource = image.createImageSource("file://" + wallpaperPath);  
let opts: image.DecodingOptions = {  
    desiredSize: {  
        height: 3648,  
        width: 2736  
    }  
};  
imageSource.createPixelMap(opts).then((pixelMap: image.PixelMap) => {  
    wallpaper.setWallpaper(pixelMap, wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error: BusinessError) => {  
        if (error) {  
            console.error(`failed to setWallpaper because: ${JSON.stringify(error)}`);  
            return;  
        }  
        console.log(`success to setWallpaper.`);  
    });  
}).catch((error: BusinessError) => {  
    cons  
    
```    
  
    
## setWallpaper<sup>(deprecated)</sup>    
将指定资源设置为指定类型的壁纸。  
 **调用形式：**     
- setWallpaper(source: string | image.PixelMap, wallpaperType: WallpaperType): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Wallpaper  
 **需要权限：** ohos.permission.SET_WALLPAPER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| source<sup>(deprecated)</sup> | string | true | JPEG或PNG文件的Uri路径，或者PNG格式文件的位图。 |  
| wallpaperType<sup>(deprecated)</sup> | WallpaperType | true | 壁纸类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
import image from '@ohos.multimedia.image';  
  
// source类型为string  
let wallpaperPath = "/data/storage/el2/base/haps/entry/files/js.jpeg";  
wallpaper.setWallpaper(wallpaperPath, wallpaper.WallpaperType.WALLPAPER_SYSTEM).then(() => {  
    console.log(`success to setWallpaper.`);  
  }).catch((error: BusinessError) => {  
    console.error(`failed to setWallpaper because: ${JSON.stringify(error)}`);  
});  
    
// source类型为image.PixelMap  
let imageSource = image.createImageSource("file://" + wallpaperPath);  
let opts: image.DecodingOptions = {  
    desiredSize: {  
        height: 3648,  
        width: 2736  
    }  
};  
imageSource.createPixelMap(opts).then((pixelMap: image.PixelMap) => {  
    wallpaper.setWallpaper(pixelMap, wallpaper.WallpaperType.WALLPAPER_SYSTEM).then(() => {  
        console.log(`success to setWallpaper.`);  
    }).catch((error: BusinessError) => {  
        console.error(`failed to setWallpaper because: ${JSON.stringify(error)}`);  
    });  
  }).catch((error: BusinessError) => {  
    console.error(`failed to createPixelMap because: ${JSON.stringify(error)}`);  
});  
    
```    
  
    
## on('colorChange')<sup>(deprecated)</sup>    
订阅壁纸颜色变化结果上报事件。  
 **调用形式：**     
- on(type: 'colorChange', callback: (colors: Array\<RgbaColor>, wallpaperType: WallpaperType) => void): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Wallpaper    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 取值为'colorChange'，表示壁纸颜色变化结果上报事件。 |  
| callback<sup>(deprecated)</sup> | (colors: Array<RgbaColor>, wallpaperType: WallpaperType) => void | true | 壁纸颜色变化触发该回调方法，返回壁纸类型和壁纸的主要颜色信息。<br/>- colors<br/>  壁纸的主要颜色信息，其类型见[RgbaColor](#rgbacolor)。<br/>- wallpaperType<br/>  壁纸类型。 |  
    
 **示例代码：**   
```ts    
try {  
    let listener = (colors: Array<wallpaper.RgbaColor>, wallpaperType: wallpaper.WallpaperType): void => {  
        console.log(`wallpaper color changed.`);  
    };  
    wallpaper.on('colorChange', listener);  
} catch (error) {  
    console.error(`failed to on because: ${JSON.stringify(error)}`);  
}  
    
```    
  
    
## off('colorChange')<sup>(deprecated)</sup>    
取消订阅壁纸颜色变化结果上报事件。  
 **调用形式：**     
- off(type: 'colorChange', callback?: (colors: Array\<RgbaColor>, wallpaperType: WallpaperType) => void): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Wallpaper    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 取值为'colorChange'，表示取消订阅壁纸颜色变化结果上报事件。 |  
| callback<sup>(deprecated)</sup> | (colors: Array<RgbaColor>, wallpaperType: WallpaperType) => void | false | 表示要取消的壁纸颜色变化的回调，不填写该参数则取消订阅该type对应的所有回调。<br/>- colors<br/>  壁纸的主要颜色信息，其类型见[RgbaColor](#rgbacolor)。<br/>- wallpaperType<br/>  壁纸类型。 |  
    
 **示例代码：**   
```ts    
let listener = (colors: Array<wallpaper.RgbaColor>, wallpaperType: wallpaper.WallpaperType): void => {  
    console.log(`wallpaper color changed.`);  
};  
try {  
    wallpaper.on('colorChange', listener);  
} catch (error) {  
    console.error(`failed to on because: ${JSON.stringify(error)}`);  
}  
  
try {  
    // 取消订阅listener  
    wallpaper.off('colorChange', listener);  
} catch (error) {  
    console.error(`failed to off because: ${JSON.stringify(error)}`);  
}  
  
try {  
    // 取消所有'colorChange'类型的订阅  
    wallpaper.off('colorChange');  
} catch (error) {  
    console.error(`failed to off because: ${JSON.stringify(error)}`);  
}  
    
```    
  
