# @ohos.wallpaper    
壁纸管理服务是OpenHarmony中的系统服务，主要为系统提供壁纸管理服务能力，支持系统显示、设置、切换壁纸等功能。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import wallpaper from '@ohos.wallpaper'    
```  
    
## WallpaperResourceType<sup>(10+)</sup>    
定义壁纸资源的枚举类型。    
    
 **系统能力:**  SystemCapability.MiscServices.Wallpaper    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DEFAULT | 0 | 默认为图片资源。 |  
| PICTURE | 1 | 图片资源。 |  
| VIDEO | 2 | 视频资源。 |  
| PACKAGE | 3 | 包资源。 |  
    
## getColorsSync<sup>(9+)</sup>    
获取指定类型壁纸的主要颜色信息。  
 **调用形式：**     
- getColorsSync(wallpaperType: WallpaperType): Array\<RgbaColor>  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MiscServices.Wallpaper    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| wallpaperType | WallpaperType | true | 壁纸类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<RgbaColor> | 返回壁纸的主要颜色信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
    
 **示例代码：**   
```ts    
try {  
    let colors = wallpaper.getColorsSync(wallpaper.WallpaperType.WALLPAPER_SYSTEM);  
    console.log(`success to getColorsSync: ${JSON.stringify(colors)}`);  
} catch (error) {  
    console.error(`failed to getColorsSync because: ${JSON.stringify(error)}`);  
}  
    
```    
  
    
## getMinHeightSync<sup>(9+)</sup>    
获取壁纸的最小高度值。  
 **调用形式：**     
- getMinHeightSync(): number  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MiscServices.Wallpaper    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回壁纸的最小高度值，单位是像素。如果返回值等于0，说明没有设置壁纸，调用者应该使用默认显示的高度值代替。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
    
 **示例代码：**   
```ts    
let minWidth = wallpaper.getMinWidthSync();    
```    
  
    
## getMinWidthSync<sup>(9+)</sup>    
获取壁纸的最小宽度值。  
 **调用形式：**     
- getMinWidthSync(): number  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MiscServices.Wallpaper    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 壁纸的最小宽度值，单位是像素。如果返回值等于0，说明没有设置壁纸，调用者应该使用默认显示的宽度值代替。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
    
 **示例代码：**   
```ts    
let minWidth = wallpaper.getMinWidthSync();    
```    
  
    
## restore<sup>(9+)</sup>    
移除指定类型的壁纸，恢复为默认显示的壁纸。使用callback异步回调。  
 **调用形式：**     
    
- restore(wallpaperType: WallpaperType, callback: AsyncCallback\<void>): void    
起始版本： 9    
- restore(wallpaperType: WallpaperType): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MiscServices.Wallpaper  
 **需要权限：** ohos.permission.SET_WALLPAPER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| wallpaperType | WallpaperType | true | 壁纸类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，移除壁纸成功，error为undefined，否则返回error信息。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 201 |  |  
| 202 |  |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
wallpaper.restore(wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error: BusinessError) => {  
    if (error) {  
        console.error(`failed to restore because: ${JSON.stringify(error)}`);  
        return;  
    }  
    console.log(`success to restore.`);  
});  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
   
wallpaper.restore(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then(() => {  
    console.log(`success to restore.`);  
  }).catch((error: BusinessError) => {  
    console.error(`failed to restore because: ${JSON.stringify(error)}`);  
});  
    
```    
  
    
## setImage<sup>(9+)</sup>    
将指定资源设置为指定类型的壁纸。使用callback异步回调。  
 **调用形式：**     
    
- setImage(source: string | image.PixelMap, wallpaperType: WallpaperType, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setImage(source: string | image.PixelMap, wallpaperType: WallpaperType): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MiscServices.Wallpaper  
 **需要权限：** ohos.permission.SET_WALLPAPER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| source | string | true | 是。<span style="letter-spacing: 0px;">JPEG或PNG文件的Uri路径，或者PNG格式文件的位图。</span> |  
| wallpaperType | WallpaperType | true | 壁纸类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，设置壁纸成功，error为undefined，否则返回error信息。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 201 |  |  
| 202 |  |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
import image from '@ohos.multimedia.image';  
  
// source类型为string  
let wallpaperPath = "/data/storage/el2/base/haps/entry/files/js.jpeg";  
wallpaper.setImage(wallpaperPath, wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error: BusinessError) => {  
    if (error) {  
        console.error(`failed to setImage because: ${JSON.stringify(error)}`);  
        return;  
     }  
    console.log(`success to setImage.`);  
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
    wallpaper.setImage(pixelMap, wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error: BusinessError) => {  
        if (error) {  
            console.error(`failed to setImage because: ${JSON.stringify(error)}`);  
            return;  
        }  
        console.log(`success to setImage.`);  
    });  
}).catch((error: BusinessError) => {  
    console.error(`failed to createPixelMap because: ${JSON.stringify(error)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
import image from '@ohos.multimedia.image';  
  
// source类型为string  
let wallpaperPath = "/data/storage/el2/base/haps/entry/files/js.jpeg";  
wallpaper.setImage(wallpaperPath, wallpaper.WallpaperType.WALLPAPER_SYSTEM).then(() => {  
    console.log(`success to setImage.`);  
}).catch((error: BusinessError) => {  
    console.error(`failed to setImage because: ${JSON.stringify(error)}`);  
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
    wallpaper.setImage(pixelMap, wallpaper.WallpaperType.WALLPAPER_SYSTEM).then(() => {  
        console.log(`success to setImage.`);  
    }).catch((error: BusinessError) => {  
        console.error(`failed to setImage because: ${JSON.stringify(error)}`);  
    });  
}).catch((error: BusinessError) => {  
    console.error(`failed to createPixelMap because: ${JSON.stringify(error)}`);  
});  
    
```    
  
    
## getPixelMap<sup>(deprecated)</sup>    
获取壁纸图片的像素图。  
 **调用形式：**     
- getPixelMap(wallpaperType: WallpaperType, callback: AsyncCallback\<image.PixelMap>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MiscServices.Wallpaper  
 **需要权限：** ohos.permission.GET_WALLPAPER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| wallpaperType<sup>(deprecated)</sup> | WallpaperType | true | 壁纸类型。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<image.PixelMap> | true | 回调函数，调用成功则返回壁纸图片的像素图对象，调用失败则返回error信息。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
import image from '@ohos.multimedia.image';  
  
wallpaper.getPixelMap(wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error: BusinessError, data: image.PixelMap) => {  
    if (error) {  
        console.error(`failed to getPixelMap because: ${JSON.stringify(error)}`);  
        return;  
    }  
    console.log(`success to getPixelMap : ${JSON.stringify(data)}`);  
  });  
    
```    
  
    
## getPixelMap<sup>(deprecated)</sup>    
获取壁纸图片的像素图。  
 **调用形式：**     
- getPixelMap(wallpaperType: WallpaperType): Promise\<image.PixelMap>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MiscServices.Wallpaper  
 **需要权限：** ohos.permission.GET_WALLPAPER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| wallpaperType<sup>(deprecated)</sup> | WallpaperType | true | 壁纸类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<image.PixelMap> | 调用成功则返回壁纸图片的像素图对象，调用失败则返回error信息。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
import image from '@ohos.multimedia.image';  
  
wallpaper.getPixelMap(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data: image.PixelMap) => {  
    console.log(`success to getPixelMap : ${JSON.stringify(data)}`);  
  }).catch((error: BusinessError) => {  
    console.error(`failed to getPixelMap because: ${JSON.stringify(error)}`);  
});  
    
```    
  
    
## getImage<sup>(9+)</sup>    
获取壁纸图片的像素图。使用callback异步回调。  
 **调用形式：**     
    
- getImage(wallpaperType: WallpaperType, callback: AsyncCallback\<image.PixelMap>): void    
起始版本： 9    
- getImage(wallpaperType: WallpaperType): Promise\<image.PixelMap>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MiscServices.Wallpaper  
 **需要权限：** ohos.permission.GET_WALLPAPER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| wallpaperType | WallpaperType | true | 壁纸类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，调用成功则返回壁纸图片的像素图对象，调用失败则返回error信息。 |  
| Promise<image.PixelMap> | 调用成功则返回壁纸图片的像素图对象，调用失败则返回error信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 201 |  |  
| 202 |  |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
import image from '@ohos.multimedia.image';  
  
wallpaper.getImage(wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error: BusinessError, data: image.PixelMap) => {  
    if (error) {  
        console.error(`failed to getImage because: ${JSON.stringify(error)}`);  
        return;  
    }  
    console.log(`success to getImage: ${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
import image from '@ohos.multimedia.image';  
  
wallpaper.getImage(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data: image.PixelMap) => {  
    console.log(`success to getImage: ${JSON.stringify(data)}`);  
  }).catch((error: BusinessError) => {  
    console.error(`failed to getImage because: ${JSON.stringify(error)}`);  
});  
    
```    
  
    
## setVideo<sup>(10+)</sup>    
将视频资源设置为桌面或锁屏的动态壁纸。使用callback异步回调。  
 **调用形式：**     
    
- setVideo(source: string, wallpaperType: WallpaperType, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setVideo(source: string, wallpaperType: WallpaperType): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MiscServices.Wallpaper  
 **需要权限：** ohos.permission.SET_WALLPAPER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| source | string | true | mp4文件的Uri路径。 |  
| wallpaperType | WallpaperType | true | 壁纸类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，设置壁纸成功，error为undefined，否则返回error信息。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 201 |  |  
| 202 |  |  
    
 **示例代码1：**   
  
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let wallpaperPath = "/data/storage/el2/base/haps/entry/files/test.mp4";  
try {  
    wallpaper.setVideo(wallpaperPath, wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error: BusinessError) => {  
        if (error) {  
            console.error(`failed to setVideo because: ${JSON.stringify(error)}`);  
            return;  
        }  
        console.log(`success to setVideo.`);  
    });  
} catch (error) {  
    console.error(`failed to setVideo because: ${JSON.stringify(error)}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let wallpaperPath = "/data/storage/el2/base/haps/entry/files/test.mp4";  
try {  
    wallpaper.setVideo(wallpaperPath, wallpaper.WallpaperType.WALLPAPER_SYSTEM).then(() => {  
        console.log(`success to setVideo.`);  
    }).catch((error: BusinessError) => {  
        console.error(`failed to setVideo because: ${JSON.stringify(error)}`);  
    });  
} catch (error) {  
    console.error(`failed to setVideo because: ${JSON.stringify(error)}`);  
}  
    
```    
  
    
## setCustomWallpaper<sup>(10+)</sup>    
将指定uri的内容设置为壁纸资源，仅当com.ohos.sceneboard存在时，支持使用该接口。使用callback异步回调。  
 **调用形式：**     
    
- setCustomWallpaper(source: string, wallpaperType: WallpaperType, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setCustomWallpaper(source: string, wallpaperType: WallpaperType): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MiscServices.Wallpaper  
 **需要权限：** ohos.permission.SET_WALLPAPER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| source | string | true | 自定义壁纸的Uri路径。 |  
| wallpaperType | WallpaperType | true | 壁纸类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，设置壁纸成功，error为undefined，否则返回error信息。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 201 |  |  
| 202 |  |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let wallpaperPath = "/data/storage/el2/base/haps/entry/files/test.zip";  
try {  
    wallpaper.setCustomWallpaper(wallpaperPath, wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error: BusinessError) => {  
        if (error) {  
            console.error(`failed to setCustomWallpaper because: ${JSON.stringify(error)}`);  
            return;  
        }  
        console.log(`success to setCustomWallpaper.`);  
    });  
} catch (error) {  
    console.error(`failed to setCustomWallpaper because: ${JSON.stringify(error)}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let wallpaperPath = "/data/storage/el2/base/haps/entry/files/test.zip";  
try {  
    wallpaper.setCustomWallpaper(wallpaperPath, wallpaper.WallpaperType.WALLPAPER_SYSTEM).then(() => {  
        console.log(`success to setCustomWallpaper.`);  
    }).catch((error: BusinessError) => {  
        console.error(`failed to setCustomWallpaper because: ${JSON.stringify(error)}`);  
    });  
} catch (error) {  
    console.error(`failed to setCustomWallpaper because: ${JSON.stringify(error)}`);  
}  
    
```    
  
    
## on('wallpaperChange')<sup>(10+)</sup>    
订阅壁纸变化通知事件。  
 **调用形式：**     
    
- on(    type: 'wallpaperChange',    callback: (wallpaperType: WallpaperType, resourceType: WallpaperResourceType, uri?: string) => void  ): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MiscServices.Wallpaper    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型。支持的事件为'wallpaperChange'，完成壁纸切换后触发该事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 壁纸变化触发该回调方法，返回壁纸类型和壁纸资源类型。<br/>- wallpaperType：壁纸类型。<br/>- resourceType：壁纸资源类型。<br/>- uri：壁纸资源地址。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
    
 **示例代码：**   
```ts    
try {  
    let listener = (wallpaperType: wallpaper.WallpaperType, resourceType: wallpaper.WallpaperResourceType): void => {  
        console.log(`wallpaper color changed.`);  
    };  
    wallpaper.on('wallpaperChange', listener);  
} catch (error) {  
    console.error(`failed to on because: ${JSON.stringify(error)}`);  
}  
    
```    
  
    
## off('wallpaperChange')<sup>(10+)</sup>    
取消订阅壁纸变化通知事件。  
 **调用形式：**     
    
- off(    type: 'wallpaperChange',    callback?: (wallpaperType: WallpaperType, resourceType: WallpaperResourceType, uri?: string) => void  ): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MiscServices.Wallpaper    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型。支持的事件为'wallpaperChange'，完成壁纸切换后触发该事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示要取消的壁纸变化回调，不填写该参数则取消订阅该type对应的所有回调。<br/>- wallpaperType：壁纸类型。<br/>- resourceType：壁纸资源类型。<br/>- uri：壁纸资源地址。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
    
 **示例代码：**   
```ts    
let listener = (wallpaperType: wallpaper.WallpaperType, resourceType: wallpaper.WallpaperResourceType): void => {  
    console.log(`wallpaper color changed.`);  
};  
try {  
    wallpaper.on('wallpaperChange', listener);  
} catch (error) {  
    console.error(`failed to on because: ${JSON.stringify(error)}`);  
}  
  
try {  
    // 取消订阅listener  
    wallpaper.off('wallpaperChange', listener);  
} catch (error) {  
    console.error(`failed to off because: ${JSON.stringify(error)}`);  
}  
  
try {  
    // 取消所有'wallpaperChange'类型的订阅  
    wallpaper.off('wallpaperChange');  
} catch (error) {  
    console.error(`failed to off because: ${JSON.stringify(error)}`);  
}  
    
```    
  
