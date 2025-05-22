# @ohos.wallpaper (壁纸)(系统接口)

壁纸管理服务为OpenHarmony系统服务，提供壁纸切换功能。从API 9开始壁纸管理的接口调整为系统API，壁纸的切换只能通过系统应用来完成。壁纸管理提供壁纸切换通道，使用壁纸的应用（如：桌面）需订阅壁纸变化通知并刷新壁纸显示。

> **说明：**
> 
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.wallpaper (壁纸)](js-apis-wallpaper.md)。


## 导入模块


```ts
import { wallpaper } from '@kit.BasicServicesKit';
```
## WallpaperResourceType<sup>10+</sup>

定义壁纸资源的枚举类型。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**系统接口**：此接口为系统接口。

| 名称 | 值 |说明 |
| -------- | -------- |-------- |
| DEFAULT | 0 |默认为图片资源。 |
| PICTURE | 1 |图片资源。 |
| VIDEO | 2 |视频资源。 |
| PACKAGE | 3 |包资源。 |

## FoldState<sup>14+</sup>

定义设备的折展状态枚举类型。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**系统接口**：此接口为系统接口。

| 名称 | 值 |说明 |
| -------- | -------- |-------- |
| NORMAL | 0 |设备默认状态。 |
| UNFOLD_ONCE_STATE | 1 |一次展开态。 |
| UNFOLD_TWICE_STATE | 2 |二次展开态。 |

## RotateState<sup>14+</sup>

定义设备的横竖屏状态枚举类型。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**系统接口**：此接口为系统接口。

| 名称 | 值 |说明 |
| -------- | -------- |-------- |
| PORTRAIT | 0 |设备默认为竖屏状态。 |
| LANDSCAPE | 1 |横屏状态。 |

## WallpaperInfo<sup>14+</sup>

定义壁纸的信息结构。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**系统接口**：此接口为系统接口。

| 名称 | 类型 | 说明 |
| -------- | -------- |  -------- |
| [FoldState](#foldstate14) | enum | 表示设备的折展状态。 |
| [RotateState](#rotatestate14) | enum | 表示设备的横竖屏状态。 |
| source | string | 表示壁纸资源uri，只支持应用沙箱目录。 |

## wallpaper.setVideo<sup>10+</sup>

setVideo(source: string, wallpaperType: WallpaperType, callback: AsyncCallback&lt;void&gt;): void

将视频资源设置为桌面或锁屏的动态壁纸。使用callback异步回调。

**需要权限**：ohos.permission.SET_WALLPAPER

**系统能力**: SystemCapability.MiscServices.Wallpaper

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| source | string | 是 | mp4文件的Uri路径。 |
| wallpaperType | [WallpaperType](js-apis-wallpaper.md#wallpapertype7) | 是 | 壁纸类型。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，设置壁纸成功，error为undefined，否则返回error信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                |
| ------------ | ------------------------------------------- |
| 201          | permission denied.                                                                              |
| 202          | permission verification failed, application which is not a system application uses system API.  |
| 401          | 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let wallpaperPath = "/data/storage/el2/base/haps/entry/files/test.mp4";
try {
    wallpaper.setVideo(wallpaperPath, wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error: BusinessError) => {
        if (error) {
            console.error(`failed to setVideo because: ${JSON.stringify(error)}`);
            return;
        }
        console.info(`success to setVideo.`);
    });
} catch (error) {
    console.error(`failed to setVideo because: ${JSON.stringify(error)}`);
}

```

## wallpaper.setVideo<sup>10+</sup>

setVideo(source: string, wallpaperType: WallpaperType): Promise&lt;void&gt;

将视频资源设置为桌面或锁屏的动态壁纸。使用promise异步回调。

**需要权限**：ohos.permission.SET_WALLPAPER

**系统能力**: SystemCapability.MiscServices.Wallpaper

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| source | string | 是 | mp4文件的Uri路径。 |
| wallpaperType | [WallpaperType](js-apis-wallpaper.md#wallpapertype7) | 是 | 壁纸类型。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                |
| ------------ | ------------------------------------------- |
| 201          | permission denied.                                                                              |
| 202          | permission verification failed, application which is not a system application uses system API.  |
| 401          | 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed.  |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let wallpaperPath = "/data/storage/el2/base/haps/entry/files/test.mp4";
try {
    wallpaper.setVideo(wallpaperPath, wallpaper.WallpaperType.WALLPAPER_SYSTEM).then(() => {
        console.info(`success to setVideo.`);
    }).catch((error: BusinessError) => {
        console.error(`failed to setVideo because: ${JSON.stringify(error)}`);
    });
} catch (error) {
    console.error(`failed to setVideo because: ${JSON.stringify(error)}`);
}
```

## wallpaper.setCustomWallpaper<sup>10+</sup>

setCustomWallpaper(source: string, wallpaperType: WallpaperType, callback: AsyncCallback&lt;void&gt;): void

将指定的zip资源包设置为桌面或锁屏的壁纸资源，仅当com.ohos.sceneboard存在时，支持使用该接口。且具有ohos.permission.GET_WALLPAPER权限的应用可以访问/data/wallpaper/目录获取设置的资源。使用callback异步回调。

**需要权限**：ohos.permission.SET_WALLPAPER

**系统能力**: SystemCapability.MiscServices.Wallpaper

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| source | string | 是 | 指定的zip资源包。 |
| wallpaperType | [WallpaperType](js-apis-wallpaper.md#wallpapertype7) | 是 | 壁纸类型。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，设置壁纸成功，error为undefined，否则返回error信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                |
| ------------ | ------------------------------------------- |
| 201          | permission denied.                                                                              |
| 202          | permission verification failed, application which is not a system application uses system API.  |
| 401          | 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let wallpaperPath = "/data/storage/el2/base/haps/entry/files/test.zip";
try {
    wallpaper.setCustomWallpaper(wallpaperPath, wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error: BusinessError) => {
        if (error) {
            console.error(`failed to setCustomWallpaper because: ${JSON.stringify(error)}`);
            return;
        }
        console.info(`success to setCustomWallpaper.`);
    });
} catch (error) {
    console.error(`failed to setCustomWallpaper because: ${JSON.stringify(error)}`);
}

```

## wallpaper.setCustomWallpaper<sup>10+</sup>

setCustomWallpaper(source: string, wallpaperType: WallpaperType): Promise&lt;void&gt;

将指定的zip资源包设置为桌面或锁屏的壁纸资源，仅当com.ohos.sceneboard存在时，支持使用该接口。且具有ohos.permission.GET_WALLPAPER权限的应用可以访问/data/wallpaper/目录获取设置的资源。使用Promise异步回调。

**需要权限**：ohos.permission.SET_WALLPAPER

**系统能力**: SystemCapability.MiscServices.Wallpaper

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| source | string | 是 | 指定的zip资源包。 |
| wallpaperType | [WallpaperType](js-apis-wallpaper.md#wallpapertype7) | 是 | 壁纸类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                |
| ------------ | ------------------------------------------- |
| 201          | permission denied.                                                                              |
| 202          | permission verification failed, application which is not a system application uses system API.  |
| 401          | 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let wallpaperPath = "/data/storage/el2/base/haps/entry/files/test.zip";
try {
    wallpaper.setCustomWallpaper(wallpaperPath, wallpaper.WallpaperType.WALLPAPER_SYSTEM).then(() => {
        console.info(`success to setCustomWallpaper.`);
    }).catch((error: BusinessError) => {
        console.error(`failed to setCustomWallpaper because: ${JSON.stringify(error)}`);
    });
} catch (error) {
    console.error(`failed to setCustomWallpaper because: ${JSON.stringify(error)}`);
}
```

## wallpaper.on('wallpaperChange')<sup>10+</sup>

on(type: 'wallpaperChange', callback: (wallpaperType: WallpaperType, resourceType: WallpaperResourceType, uri?: string) =&gt; void): void

订阅壁纸变化通知事件。不支持多线程并发调用。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 事件回调类型。支持的事件为'wallpaperChange'，完成壁纸切换后触发该事件。 |
| callback | function | 是 | 壁纸变化触发该回调方法，返回壁纸类型和壁纸资源类型。<br/>- wallpaperType：壁纸类型。<br/>- resourceType：壁纸资源类型。<br/>- uri：壁纸资源地址。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                |
| ------------ | ------------------------------------------- |
| 202          | permission verification failed, application which is not a system application uses system API.  |
| 401          | 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed.  |

**示例：**

```ts
try {
    let listener = (wallpaperType: wallpaper.WallpaperType, resourceType: wallpaper.WallpaperResourceType): void => {
        console.info(`wallpaper color changed.`);
    };
    wallpaper.on('wallpaperChange', listener);
} catch (error) {
    console.error(`failed to on because: ${JSON.stringify(error)}`);
}
```

## wallpaper.off('wallpaperChange')<sup>10+</sup>

off(type: 'wallpaperChange', callback?: (wallpaperType: WallpaperType, resourceType: WallpaperResourceType, uri?: string) =&gt; void): void

取消订阅壁纸变化通知事件。不支持多线程并发调用。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 事件回调类型。支持的事件为'wallpaperChange'，完成壁纸切换后触发该事件。 |
| callback | function | 否 |   表示要取消的壁纸变化回调，不填写该参数则取消订阅该type对应的所有回调。<br/>- wallpaperType：壁纸类型。<br/>- resourceType：壁纸资源类型。<br/>- uri：壁纸资源地址。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                |
| ------------ | ------------------------------------------- |
| 202          | permission verification failed, application which is not a system application uses system API.  |
| 401          | 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed.  |

**示例：**

```ts
let listener = (wallpaperType: wallpaper.WallpaperType, resourceType: wallpaper.WallpaperResourceType): void => {
    console.info(`wallpaper color changed.`);
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

## wallpaper.getColorsSync<sup>9+</sup>

getColorsSync(wallpaperType: WallpaperType): Array&lt;RgbaColor&gt;

获取指定类型壁纸的主要颜色信息。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](js-apis-wallpaper.md#wallpapertype7) | 是 | 壁纸类型。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| Array&lt;[RgbaColor](js-apis-wallpaper.md#rgbacolordeprecated)&gt; | 返回壁纸的主要颜色信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                |
| ------------ | ------------------------------------------- |
| 202          | permission verification failed, application which is not a system application uses system API.  |
| 401          | 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed.  |

**示例**：

```ts
try {
    let colors = wallpaper.getColorsSync(wallpaper.WallpaperType.WALLPAPER_SYSTEM);
    console.info(`success to getColorsSync: ${JSON.stringify(colors)}`);
} catch (error) {
    console.error(`failed to getColorsSync because: ${JSON.stringify(error)}`);
}
```

## wallpaper.getMinHeightSync<sup>9+</sup>

getMinHeightSync(): number

获取壁纸的最小高度值。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**系统接口**：此接口为系统接口。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回壁纸的最小高度值，单位是像素。如果返回值等于0，说明没有设置壁纸，调用者应该使用默认显示的高度值代替。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                |
| ------------ | ------------------------------------------- |
| 202          | permission verification failed, application which is not a system application uses system API.  |

**示例：**

```ts
let minHeight = wallpaper.getMinHeightSync();
```

## wallpaper.getMinWidthSync<sup>9+</sup>

getMinWidthSync(): number

获取壁纸的最小宽度值。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**系统接口**：此接口为系统接口。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 壁纸的最小宽度值，单位是像素。如果返回值等于0，说明没有设置壁纸，调用者应该使用默认显示的宽度值代替。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                |
| ------------ | ------------------------------------------- |
| 202          | permission verification failed, application which is not a system application uses system API.  |

**示例：**

```ts
let minWidth = wallpaper.getMinWidthSync();
```

## wallpaper.restore<sup>9+</sup>

restore(wallpaperType: WallpaperType, callback: AsyncCallback&lt;void&gt;): void

移除指定类型的壁纸，恢复为默认显示的壁纸。使用callback异步回调。

**需要权限**：ohos.permission.SET_WALLPAPER

**系统能力**: SystemCapability.MiscServices.Wallpaper

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](js-apis-wallpaper.md#wallpapertype7) | 是 | 壁纸类型。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，移除壁纸成功，error为undefined，否则返回error信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                |
| ------------ | ------------------------------------------- |
| 201          | permission denied.                                                                              |
| 202          | permission verification failed, application which is not a system application uses system API.  |
| 401          | 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

wallpaper.restore(wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error: BusinessError) => {
    if (error) {
        console.error(`failed to restore because: ${JSON.stringify(error)}`);
        return;
    }
    console.info(`success to restore.`);
});
```

## wallpaper.restore<sup>9+</sup>

restore(wallpaperType: WallpaperType): Promise&lt;void&gt;

移除指定类型的壁纸，恢复为默认显示的壁纸。使用promise异步回调。

**需要权限**：ohos.permission.SET_WALLPAPER

**系统能力**: SystemCapability.MiscServices.Wallpaper

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](js-apis-wallpaper.md#wallpapertype7) | 是 | 壁纸类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                |
| ------------ | ------------------------------------------- |
| 201          | permission denied.                                                                              |
| 202          | permission verification failed, application which is not a system application uses system API.  |
| 401          | 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
 
wallpaper.restore(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then(() => {
    console.info(`success to restore.`);
  }).catch((error: BusinessError) => {
    console.error(`failed to restore because: ${JSON.stringify(error)}`);
});
```

## wallpaper.setImage<sup>9+</sup>

setImage(source: string | image.PixelMap, wallpaperType: WallpaperType, callback: AsyncCallback&lt;void&gt;): void

将指定资源设置为指定类型的壁纸。使用callback异步回调。

**需要权限**：ohos.permission.SET_WALLPAPER

**系统能力**: SystemCapability.MiscServices.Wallpaper

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| source | string \| [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | 是 | JPEG或PNG文件的Uri路径，或者PNG格式文件的位图。 |
| wallpaperType | [WallpaperType](js-apis-wallpaper.md#wallpapertype7) | 是 | 壁纸类型。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，设置壁纸成功，error为undefined，否则返回error信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                |
| ------------ | ------------------------------------------- |
| 201          | permission denied.                                                                              |
| 202          | permission verification failed, application which is not a system application uses system API.  |
| 401          | 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

// source类型为string
let wallpaperPath = "/data/storage/el2/base/haps/entry/files/js.jpeg";
wallpaper.setImage(wallpaperPath, wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error: BusinessError) => {
    if (error) {
        console.error(`failed to setImage because: ${JSON.stringify(error)}`);
        return;
     }
    console.info(`success to setImage.`);
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
        console.info(`success to setImage.`);
    });
}).catch((error: BusinessError) => {
    console.error(`failed to createPixelMap because: ${JSON.stringify(error)}`);
});
```

## wallpaper.setImage<sup>9+</sup>

setImage(source: string | image.PixelMap, wallpaperType: WallpaperType): Promise&lt;void&gt;

将指定资源设置为指定类型的壁纸。使用promise异步回调。

**需要权限**：ohos.permission.SET_WALLPAPER

**系统能力**: SystemCapability.MiscServices.Wallpaper

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| source | string \| [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | 是 | JPEG或PNG文件的Uri路径，或者PNG格式文件的位图。 |
| wallpaperType | [WallpaperType](js-apis-wallpaper.md#wallpapertype7) | 是 | 壁纸类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                |
| ------------ | ------------------------------------------- |
| 201          | permission denied.                                                                              |
| 202          | permission verification failed, application which is not a system application uses system API.  |
| 401          | 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

// source类型为string
let wallpaperPath = "/data/storage/el2/base/haps/entry/files/js.jpeg";
wallpaper.setImage(wallpaperPath, wallpaper.WallpaperType.WALLPAPER_SYSTEM).then(() => {
    console.info(`success to setImage.`);
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
        console.info(`success to setImage.`);
    }).catch((error: BusinessError) => {
        console.error(`failed to setImage because: ${JSON.stringify(error)}`);
    });
}).catch((error: BusinessError) => {
    console.error(`failed to createPixelMap because: ${JSON.stringify(error)}`);
});
```

## wallpaper.getImage<sup>9+</sup>

getImage(wallpaperType: WallpaperType, callback: AsyncCallback&lt;image.PixelMap&gt;): void

获取壁纸图片的像素图，且只能获取使用setImage设置的静态壁纸。使用callback异步回调。

**需要权限**：ohos.permission.GET_WALLPAPER

**系统能力**: SystemCapability.MiscServices.Wallpaper

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](js-apis-wallpaper.md#wallpapertype7) | 是 | 壁纸类型。 |
| callback | AsyncCallback&lt;[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)&gt; | 是 | 回调函数，调用成功则返回壁纸图片的像素图对象，调用失败则返回error信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                |
| ------------ | ------------------------------------------- |
| 201          | permission denied.                                                                              |
| 202          | permission verification failed, application which is not a system application uses system API.  |
| 401          | 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

wallpaper.getImage(wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error: BusinessError, data: image.PixelMap) => {
    if (error) {
        console.error(`failed to getImage because: ${JSON.stringify(error)}`);
        return;
    }
    console.info(`success to getImage: ${JSON.stringify(data)}`);
});
```

## wallpaper.getImage<sup>9+</sup>

getImage(wallpaperType: WallpaperType): Promise&lt;image.PixelMap&gt;

获取壁纸图片的像素图，且只能获取使用setImage设置的静态壁纸。使用promise异步回调。

**需要权限**：ohos.permission.GET_WALLPAPER

**系统能力**: SystemCapability.MiscServices.Wallpaper

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](js-apis-wallpaper.md#wallpapertype7) | 是 | 壁纸类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)&gt; | 调用成功则返回壁纸图片的像素图对象，调用失败则返回error信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                |
| ------------ | ------------------------------------------- |
| 201          | permission denied.                                                                              |
| 202          | permission verification failed, application which is not a system application uses system API.  |
| 401          | 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

wallpaper.getImage(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data: image.PixelMap) => {
    console.info(`success to getImage: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`failed to getImage because: ${JSON.stringify(error)}`);
});
```
## wallpaper.getWallpaperByState<sup>14+</sup>

getWallpaperByState(wallpaperType:WallpaperType, foldState:FoldState, rotateState:RotateState): Promise&lt;image.PixelMap&gt;

获取指定壁纸类型、折展态、横竖屏的壁纸图片的像素图，如果指定的壁纸不存在，会逐步降级匹配，unfolded-land -> unfolded-port ->normal-port。使用promise异步回调。

**需要权限**：ohos.permission.GET_WALLPAPER

**系统能力**: SystemCapability.MiscServices.Wallpaper

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](js-apis-wallpaper.md#wallpapertype7) | 是 | 壁纸类型。 |
| foldState | [FoldState](#foldstate14) | 是 | 折展状态类型。 |
| rotateState | [RotateState](#rotatestate14) | 是 | 横竖屏状态类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)&gt; | 调用成功则返回壁纸图片的像素图对象，调用失败则返回error信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                |
| ------------ | ------------------------------------------- |
| 201          | permission denied.                                                                              |
| 202          | permission verification failed, application which is not a system application uses system API.  |
| 401          | 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { wallpaper } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

wallpaper.getWallpaperByState(wallpaper.WallpaperType.WALLPAPER_SYSTEM,wallpaper.FoldState.NORMAL,wallpaper.RotateState.PORTRAIT).then((data:image.PixelMap) => {
  console.info(`success to getWallpaperByState: ${JSON.stringify(data)}`);
}).catch((error: BusinessError) => {
  console.error(`failed to getWallpaperByState because: ${JSON.stringify(error)}`);
});
```

## wallpaper.setAllWallpapers<sup>14+</sup>

setAllWallpapers(wallpaperInfos: Array\<WallpaperInfo>\, wallpaperType: WallpaperType): Promise&lt;void&gt;

设置设备所有形态的壁纸。使用promise异步回调。（包括折展状态、横竖屏状态、资源路径，其中NORMAL-PORT为必选）

**需要权限**：ohos.permission.SET_WALLPAPER

**系统能力**: SystemCapability.MiscServices.Wallpaper

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wallpaperInfos | Array<[WallpaperInfo](#wallpaperinfo14)> | 是 | 所有壁纸的信息结构。 |
| wallpaperType | [WallpaperType](js-apis-wallpaper.md#wallpapertype7) | 是 | 壁纸类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                |
| ------------ | ------------------------------------------- |
| 201          | permission denied.                                                                              |
| 202          | permission verification failed, application which is not a system application uses system API.  |
| 401          | 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { wallpaper } from '@kit.BasicServicesKit';

let wallpaperInfos: Array<wallpaper.WallpaperInfo>
wallpaperInfos = [
  {
    foldState: wallpaper.FoldState.NORMAL,
    rotateState: wallpaper.RotateState.PORTRAIT,
    source: '/data/storage/el2/base/haps/entry/files/normal.jpeg'
  },
  {
    foldState: wallpaper.FoldState.UNFOLD_ONCE_STATE,
    rotateState: wallpaper.RotateState.LANDSCAPE,
    source: '/data/storage/el2/base/haps/entry/files/unfold_once_state.jpeg'
  },
  {
    foldState: wallpaper.FoldState.UNFOLD_TWICE_STATE,
    rotateState: wallpaper.RotateState.PORTRAIT,
    source: '/data/storage/el2/base/haps/entry/files/unfold_twice_state.jpeg'
  }
];
wallpaper.setAllWallpapers(wallpaperInfos, wallpaper.WallpaperType.WALLPAPER_SYSTEM).then(() => {
  console.info(`success to setAllWallpapers.`);
}).catch((error: BusinessError) => {
  console.error(`failed to setAllWallpapers because: ${JSON.stringify(error)}`);
});
```

## wallpaper.getPixelMap<sup>(deprecated)</sup>

getPixelMap(wallpaperType: WallpaperType, callback: AsyncCallback&lt;image.PixelMap&gt;): void

获取壁纸图片的像素图。

> **说明：**
>
> 从 API version 7开始支持，从API version 9开始废弃。

**需要权限**：ohos.permission.GET_WALLPAPER

**系统能力**: SystemCapability.MiscServices.Wallpaper

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](js-apis-wallpaper.md#wallpapertype7) | 是 | 壁纸类型。 |
| callback | AsyncCallback&lt;image.PixelMap&gt; | 是 | 回调函数，调用成功则返回壁纸图片的像素图对象，调用失败则返回error信息。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

wallpaper.getPixelMap(wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error: BusinessError, data: image.PixelMap) => {
    if (error) {
        console.error(`failed to getPixelMap because: ${JSON.stringify(error)}`);
        return;
    }
    console.info(`success to getPixelMap : ${JSON.stringify(data)}`);
  });
```

## wallpaper.getPixelMap<sup>(deprecated)</sup>

getPixelMap(wallpaperType: WallpaperType): Promise&lt;image.PixelMap&gt;

获取壁纸图片的像素图。

> **说明：**
>
> 从 API version 7开始支持，从API version 9开始废弃。

**需要权限**：ohos.permission.GET_WALLPAPER

**系统能力**: SystemCapability.MiscServices.Wallpaper

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](js-apis-wallpaper.md#wallpapertype7) | 是 | 壁纸类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;image.PixelMap&gt; | 调用成功则返回壁纸图片的像素图对象，调用失败则返回error信息。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

wallpaper.getPixelMap(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data: image.PixelMap) => {
    console.info(`success to getPixelMap : ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`failed to getPixelMap because: ${JSON.stringify(error)}`);
});
```