# @ohos.wallpaper (壁纸)

<!--Kit: Basic Services Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @gcw_jQMboB9m-->
<!--Designer: @gcw_jQMboB9m-->
<!--Tester: @murphy84-->
<!--Adviser: @fang-jinxu-->

壁纸管理服务为OpenHarmony系统服务，提供壁纸切换功能。从API 9开始壁纸管理的接口调整为系统API，壁纸的切换只能通过系统应用来完成。壁纸管理提供壁纸切换通道，使用壁纸的应用（如：桌面）需订阅壁纸变化通知并刷新壁纸显示。

> **说明：**
> 
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块


```ts
import { wallpaper } from '@kit.BasicServicesKit';
```

## WallpaperType

定义壁纸的枚举类型。

**系统能力**: SystemCapability.MiscServices.Wallpaper

| 名称 | 值 |说明 |
| -------- | -------- |-------- |
| WALLPAPER_SYSTEM | 0 |主屏幕壁纸标识。 |
| WALLPAPER_LOCKSCREEN | 1 |锁屏壁纸标识。 |


## RgbaColor<sup>(deprecated)</sup>

定义壁纸颜色信息结构。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。

**系统能力**: SystemCapability.MiscServices.Wallpaper

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| red | number | 否 | 否 | 表示红色值，范围为 0 到 255。 |
| green | number | 否 | 否 | 表示绿色值，范围为 0 到 255。 |
| blue | number | 否 | 否 | 表示蓝色值，范围为 0 到 255。 |
| alpha | number | 否 | 否 | 表示 alpha 值，范围为 0 到 255。 |


## wallpaper.on('colorChange')<sup>(deprecated)</sup>

on(type: 'colorChange', callback: (colors: Array&lt;RgbaColor&gt;, wallpaperType: WallpaperType) =&gt; void): void

订阅壁纸颜色变化结果上报事件。不支持多线程并发调用。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 取值为'colorChange'，表示壁纸颜色变化结果上报事件。 |
| callback | function | 是 | 壁纸颜色变化触发该回调方法，返回壁纸类型和壁纸的主要颜色信息。<br/>- colors<br/>  壁纸的主要颜色信息，其类型见[RgbaColor](#rgbacolordeprecated)。<br/>- wallpaperType<br/>  壁纸类型。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let listener = (colors: Array<wallpaper.RgbaColor>, wallpaperType: wallpaper.WallpaperType): void => {
        console.info(`wallpaper color changed.`);
    };
    wallpaper.on('colorChange', listener);
} catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to on. Code: ${err.code}, message: ${err.message}`);
}
```

## wallpaper.off('colorChange')<sup>(deprecated)</sup>

off(type: 'colorChange', callback?: (colors: Array&lt;RgbaColor&gt;, wallpaperType: WallpaperType) =&gt; void): void

取消订阅壁纸颜色变化结果上报事件。不支持多线程并发调用。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 取值为'colorChange'，表示取消订阅壁纸颜色变化结果上报事件。 |
| callback | function | 否 |   表示要取消的壁纸颜色变化的回调，不填写该参数则取消订阅该type对应的所有回调。<br/>- colors<br/>  壁纸的主要颜色信息，其类型见[RgbaColor](#rgbacolordeprecated)。<br/>- wallpaperType<br/>  壁纸类型。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let listener = (colors: Array<wallpaper.RgbaColor>, wallpaperType: wallpaper.WallpaperType): void => {
    console.info(`wallpaper color changed.`);
};
try {
    wallpaper.on('colorChange', listener);
} catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to on. Code: ${error.code}, message: ${error.message}`);
}

try {
    // 取消订阅listener
    wallpaper.off('colorChange', listener);
} catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to off. Code: ${err.code}, message: ${err.message}`);
}

try {
    // 取消所有'colorChange'类型的订阅
    wallpaper.off('colorChange');
} catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to off. Code: ${error.code}, message: ${error.message}`);
}
```

## wallpaper.getColors<sup>(deprecated)</sup>

getColors(wallpaperType: WallpaperType, callback: AsyncCallback&lt;Array&lt;RgbaColor&gt;&gt;): void

获取指定类型壁纸的主要颜色信息。使用callback异步回调。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | 是 | 壁纸类型。 |
| callback | AsyncCallback&lt;Array&lt;[RgbaColor](#rgbacolordeprecated)&gt;&gt; | 是 | 回调函数。当获取壁纸主要颜色信息成功，err为undefined，data为获取到的壁纸主要颜色信息；否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

wallpaper.getColors(wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error: BusinessError, data: Array<wallpaper.RgbaColor>) => {
    if (error) {
        console.error(`Failed to getColors. Code: ${error.code}, message: ${error.message}`);
        return;
    }
    console.info(`success to getColors: ${JSON.stringify(data)}`);
});
```

## wallpaper.getColors<sup>(deprecated)</sup>

getColors(wallpaperType: WallpaperType): Promise&lt;Array&lt;RgbaColor&gt;&gt;

获取指定类型壁纸的主要颜色信息。使用Promise异步回调。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | 是 | 壁纸类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;Array&lt;[RgbaColor](#rgbacolordeprecated)&gt;&gt; | Promise对象，返回壁纸的主要颜色信息。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

wallpaper.getColors(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data: Array<wallpaper.RgbaColor>) => {
    console.info(`success to getColors: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`Failed to getColors. Code: ${error.code}, message: ${error.message}`);
});
```

## wallpaper.getId<sup>(deprecated)</sup>

getId(wallpaperType: WallpaperType, callback: AsyncCallback&lt;number&gt;): void

获取指定类型壁纸的ID。使用callback异步回调。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | 是 | 壁纸类型。 |
| callback | AsyncCallback&lt;number&gt; | 是 | 回调函数。当获取壁纸ID成功，err为undefined，data为获取到的壁纸ID；否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

wallpaper.getId(wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error: BusinessError, data: number) => {
    if (error) {
        console.error(`Failed to getId. Code: ${error.code}, message: ${error.message}`);
        return;
    }
    console.info(`success to getId: ${JSON.stringify(data)}`);
});
```

## wallpaper.getId<sup>(deprecated)</sup>

getId(wallpaperType: WallpaperType): Promise&lt;number&gt;

获取指定类型壁纸的ID。使用Promise异步回调。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | 是 | 壁纸类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;number&gt; | Promise对象，返回壁纸的ID。如果配置了这种壁纸类型的壁纸就返回一个大于等于0的数，否则返回-1。取值范围是-1到（2^31-1）。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

wallpaper.getId(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data: number) => {
    console.info(`success to getId: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`Failed to getId. Code: ${error.code}, message: ${error.message}`);
});
```

## wallpaper.getMinHeight<sup>(deprecated)</sup>

getMinHeight(callback: AsyncCallback&lt;number&gt;): void

获取壁纸的最小高度值。使用callback异步回调。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;number&gt; | 是 | 回调函数。当获取壁纸的最小高度值（单位为像素）成功，err为undefined，data为获取到的壁纸的最小高度值；否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

wallpaper.getMinHeight((error: BusinessError, data: number) => {
    if (error) {
        console.error(`Failed to getMinHeight. Code: ${error.code}, message: ${error.message}`);
        return;
    }
    console.info(`success to getMinHeight: ${JSON.stringify(data)}`);
});
```

## wallpaper.getMinHeight<sup>(deprecated)</sup>

getMinHeight(): Promise&lt;number&gt;

获取壁纸的最小高度值。使用Promise异步回调。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;number&gt; | Promise对象，返回壁纸的最小高度值，单位为像素。如果返回值等于0，说明没有设置壁纸，调用者应该使用默认显示的高度值代替。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

wallpaper.getMinHeight().then((data: number) => {
    console.info(`success to getMinHeight: ${JSON.stringify(data)}`);
}).catch((error: BusinessError) => {
    console.error(`Failed to getMinHeight. Code: ${error.code}, message: ${error.message}`);
});
```

## wallpaper.getMinWidth<sup>(deprecated)</sup>

getMinWidth(callback: AsyncCallback&lt;number&gt;): void

获取壁纸的最小宽度值。使用callback异步回调。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;number&gt; | 是 | 回调函数。当获取壁纸的最小宽度值（单位为像素）成功，err为undefined，data为获取到的壁纸的最小宽度值；否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

wallpaper.getMinWidth((error: BusinessError, data: number) => {
    if (error) {
        console.error(`Failed to getMinWidth. Code: ${error.code}, message: ${error.message}`);
        return;
    }
    console.info(`success to getMinWidth: ${JSON.stringify(data)}`);
});
```

## wallpaper.getMinWidth<sup>(deprecated)</sup>

getMinWidth(): Promise&lt;number&gt;

获取壁纸的最小宽度值。使用Promise异步回调。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;number&gt; | Promise对象，返回壁纸的最小宽度值（单位为像素）。如果返回值等于0，说明没有设置壁纸，调用者应该使用默认显示的宽度值代替。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

wallpaper.getMinWidth().then((data: number) => {
    console.info(`success to getMinWidth: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`Failed to getMinWidth. Code: ${error.code}, message: ${error.message}`);
});
```

## wallpaper.getFile<sup>(deprecated)</sup>

getFile(wallpaperType: WallpaperType, callback: AsyncCallback&lt;number&gt;): void

获取指定类型的壁纸文件。使用callback异步回调。

> **说明：**
> 
> 从 API version 8开始支持，从API version 9开始废弃。

**需要权限**：ohos.permission.GET_WALLPAPER

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | 是 | 壁纸类型。 |
| callback | AsyncCallback&lt;number&gt; | 是 | 回调函数。当获取壁纸文件成功，err为undefined，data为获取到的壁纸文件描述符ID；否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

wallpaper.getFile(wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error: BusinessError, data: number) => {
    if (error) {
        console.error(`Failed to getFile. Code: ${error.code}, message: ${error.message}`);
        return;
    }
    console.info(`success to getFile: ${JSON.stringify(data)}`);
});
```

## wallpaper.getFile<sup>(deprecated)</sup>

getFile(wallpaperType: WallpaperType): Promise&lt;number&gt;

获取指定类型的壁纸文件。使用Promise异步回调。

> **说明：**
>
> 从 API version 8开始支持，从API version 9开始废弃。

**需要权限**：ohos.permission.GET_WALLPAPER

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | 是 | 壁纸类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;number&gt; | Promise对象，返回壁纸文件描述符ID。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

wallpaper.getFile(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data: number) => {
    console.info(`success to getFile: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`Failed to getFile. Code: ${error.code}, message: ${error.message}`);
});
```

## wallpaper.isChangePermitted<sup>(deprecated)</sup>

isChangePermitted(callback: AsyncCallback&lt;boolean&gt;): void

是否允许应用改变当前用户的壁纸。使用callback异步回调。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。返回true表示允许应用改变当前用户的壁纸；返回false表示不允许。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

wallpaper.isChangePermitted((error: BusinessError, data: boolean) => {
    if (error) {
        console.error(`Failed to isChangePermitted. Code: ${error.code}, message: ${error.message}`);
        return;
    }
    console.info(`success to isChangePermitted: ${JSON.stringify(data)}`);
});
```

## wallpaper.isChangePermitted<sup>(deprecated)</sup>

isChangePermitted(): Promise&lt;boolean&gt;

是否允许应用改变当前用户的壁纸。使用Promise异步回调。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示允许应用改变当前用户的壁纸；返回false表示不允许。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

wallpaper.isChangePermitted().then((data: boolean) => {
    console.info(`success to isChangePermitted: ${JSON.stringify(data)}`);
}).catch((error: BusinessError) => {
    console.error(`Failed to isChangePermitted. Code: ${error.code}, message: ${error.message}`);
});
```

## wallpaper.isOperationAllowed<sup>(deprecated)</sup>

isOperationAllowed(callback: AsyncCallback&lt;boolean&gt;): void

是否允许用户设置壁纸。使用callback异步回调。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。返回true表示允许用户设置壁纸；返回false表示不允许。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

wallpaper.isOperationAllowed((error: BusinessError, data: boolean) => {
    if (error) {
        console.error(`Failed to isOperationAllowed. Code: ${error.code}, message: ${error.message}`);
        return;
    }
    console.info(`success to isOperationAllowed: ${JSON.stringify(data)}`);
});
```

## wallpaper.isOperationAllowed<sup>(deprecated)</sup>

isOperationAllowed(): Promise&lt;boolean&gt;

是否允许用户设置壁纸。使用Promise异步回调。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示允许用户设置壁纸；返回false表示不允许。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

wallpaper.isOperationAllowed().then((data: boolean) => {
    console.info(`success to isOperationAllowed: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`Failed to isOperationAllowed. Code: ${error.code}, message: ${error.message}`);
});
```

## wallpaper.reset<sup>(deprecated)</sup>

reset(wallpaperType: WallpaperType, callback: AsyncCallback&lt;void&gt;): void

移除指定类型的壁纸，恢复为默认显示的壁纸。使用callback异步回调。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。

**需要权限**：ohos.permission.SET_WALLPAPER

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | 是 | 壁纸类型。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当移除壁纸成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

wallpaper.reset(wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error: BusinessError) => {
    if (error) {
        console.error(`Failed to reset. Code: ${error.code}, message: ${error.message}`);
        return;
    }
    console.info(`success to reset.`);
});
```

## wallpaper.reset<sup>(deprecated)</sup>

reset(wallpaperType: WallpaperType): Promise&lt;void&gt;

移除指定类型的壁纸，恢复为默认显示的壁纸。使用Promise异步回调。

> **说明：**
>
> 从 API version 7开始支持，从API version 9开始废弃。

**需要权限**：ohos.permission.SET_WALLPAPER

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | 是 | 壁纸类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

wallpaper.reset(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then(() => {
    console.info(`success to reset.`);
}).catch((error: BusinessError) => {
    console.error(`Failed to reset. Code: ${error.code}, message: ${error.message}`);
});
```

## wallpaper.setWallpaper<sup>(deprecated)</sup>

setWallpaper(source: string | image.PixelMap, wallpaperType: WallpaperType, callback: AsyncCallback&lt;void&gt;): void

将指定资源设置为指定类型的壁纸。使用callback异步回调。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。

**需要权限**：ohos.permission.SET_WALLPAPER

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| source | string \| [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | 是 | JPEG或PNG文件的Uri路径，或者PNG格式文件的位图。 |
| wallpaperType | [WallpaperType](#wallpapertype) | 是 | 壁纸类型。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当设置壁纸成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

// source类型为string
let wallpaperPath = '/data/storage/el2/base/haps/entry/files/js.jpeg';
wallpaper.setWallpaper(wallpaperPath, wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error: BusinessError) => {
    if (error) {
        console.error(`Failed to setWallpaper. Code: ${error.code}, message: ${error.message}`);
        return;
    }
    console.info(`success to setWallpaper.`);
});

// source类型为image.PixelMap
let imageSource = image.createImageSource('file://' + wallpaperPath);
let opts: image.DecodingOptions = {
    desiredSize: {
        height: 3648,
        width: 2736
    }
};
imageSource.createPixelMap(opts).then((pixelMap: image.PixelMap) => {
    wallpaper.setWallpaper(pixelMap, wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error: BusinessError) => {
        if (error) {
            console.error(`Failed to setWallpaper. Code: ${error.code}, message: ${error.message}`);
            return;
        }
        console.info(`success to setWallpaper.`);
    });
}).catch((error: BusinessError) => {
    console.error(`Failed to createPixelMap. Code: ${error.code}, message: ${error.message}`);
});
```

## wallpaper.setWallpaper<sup>(deprecated)</sup>

setWallpaper(source: string | image.PixelMap, wallpaperType: WallpaperType): Promise&lt;void&gt;

将指定资源设置为指定类型的壁纸。使用Promise异步回调。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。

**需要权限**：ohos.permission.SET_WALLPAPER

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| source | string \| [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | 是 | JPEG或PNG文件的Uri路径，或者PNG格式文件的位图。 |
| wallpaperType | [WallpaperType](#wallpapertype) | 是 | 壁纸类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

// source类型为string
let wallpaperPath = '/data/storage/el2/base/haps/entry/files/js.jpeg';
wallpaper.setWallpaper(wallpaperPath, wallpaper.WallpaperType.WALLPAPER_SYSTEM).then(() => {
    console.info(`success to setWallpaper.`);
  }).catch((error: BusinessError) => {
    console.error(`Failed to setWallpaper. Code: ${error.code}, message: ${error.message}`);
});
  
// source类型为image.PixelMap
let imageSource = image.createImageSource('file://' + wallpaperPath);
let opts: image.DecodingOptions = {
    desiredSize: {
        height: 3648,
        width: 2736
    }
};
imageSource.createPixelMap(opts).then((pixelMap: image.PixelMap) => {
    wallpaper.setWallpaper(pixelMap, wallpaper.WallpaperType.WALLPAPER_SYSTEM).then(() => {
        console.info(`success to setWallpaper.`);
    }).catch((error: BusinessError) => {
        console.error(`Failed to setWallpaper. Code: ${error.code}, message: ${error.message}`);
    });
  }).catch((error: BusinessError) => {
    console.error(`Failed to createPixelMap. Code: ${error.code}, message: ${error.message}`);
});
```