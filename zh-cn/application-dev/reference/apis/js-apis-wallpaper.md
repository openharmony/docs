# @ohos.wallpaper (壁纸)

壁纸管理服务是OpenHarmony中系统服务，是主题框架的部分组成，主要为系统提供壁纸管理服务能力，支持系统显示、设置、切换壁纸等功能。

> **说明：**
> 
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块


```js
import wallpaper from '@ohos.wallpaper';
```

## WallpaperType

定义壁纸的枚举类型。

**系统能力**: SystemCapability.MiscServices.Wallpaper

| 名称 | 值 |说明 |
| -------- | -------- |-------- |
| WALLPAPER_SYSTEM | 0 |主屏幕壁纸标识。 |
| WALLPAPER_LOCKSCREEN | 1 |锁屏壁纸标识。 |


## RgbaColor

定义壁纸颜色信息结构。

**系统能力**: SystemCapability.MiscServices.Wallpaper

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| red | number | 是 | 是 | 表示红色值，范围为 0 到 255。 |
| green | number | 是 | 是 | 表示绿色值，范围为 0 到 255。 |
| blue | number | 是 | 是 | 表示蓝色值，范围为 0 到 255。 |
| alpha | number | 是 | 是 | 表示 alpha 值，范围为 0 到 255。 |


## wallpaper.getColorsSync<sup>9+</sup>

getColorsSync(wallpaperType: WallpaperType): Array&lt;RgbaColor&gt;

获取指定类型壁纸的主要颜色信息。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | 是 | 壁纸类型。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| Array&lt;[RgbaColor](#rgbacolor)&gt; | 返回壁纸的主要颜色信息。 |

**示例**：

```js
try {
    let colors = wallpaper.getColorsSync(wallpaper.WallpaperType.WALLPAPER_SYSTEM);
    console.log(`success to getColorsSync: ${JSON.stringify(colors)}`);
} catch (error) {
    console.error(`failed to getColorsSync because: ${JSON.stringify(error)}`);
}
```

## wallpaper.getIdSync<sup>9+</sup>

getIdSync(wallpaperType: WallpaperType): number

获取指定类型壁纸的ID。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | 是 | 壁纸类型。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| number | 返回壁纸的ID。如果配置了这种壁纸类型的壁纸就返回一个大于等于0的数，否则返回-1。取值范围是-1到（2^31-1）。 |

**示例**：

```js
try {
    let id = wallpaper.getIdSync(wallpaper.WallpaperType.WALLPAPER_SYSTEM);
    console.log(`success to getIdSync: ${JSON.stringify(id)}`);
} catch (error) {
    console.error(`failed to getIdSync because: ${JSON.stringify(error)}`);
}
```

## wallpaper.getMinHeightSync<sup>9+</sup>

getMinHeightSync(): number

获取壁纸的最小高度值。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回壁纸的最小高度值，单位是像素。如果返回值等于0，说明没有设置壁纸，调用者应该使用默认显示的高度值代替。 |

**示例：**

```js
let minHeight = wallpaper.getMinHeightSync();
```

## wallpaper.getMinWidthSync<sup>9+</sup>

getMinWidthSync(): number

获取壁纸的最小宽度值。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 壁纸的最小宽度值，单位是像素。如果返回值等于0，说明没有设置壁纸，调用者应该使用默认显示的宽度值代替。 |

**示例：**

```js
let minWidth = wallpaper.getMinWidthSync();
```

## wallpaper.isChangeAllowed<sup>9+</sup>

isChangeAllowed(): boolean

是否允许应用改变当前用户的壁纸。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 返回是否允许应用改变当前用户的壁纸。如果允许返回true，否则返回false。 |

**示例：**

```js
let isChangeAllowed = wallpaper.isChangeAllowed();
```

## wallpaper.isUserChangeAllowed<sup>9+</sup>

isUserChangeAllowed(): boolean

是否允许用户设置壁纸。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 返回是否允许用户设置壁纸。如果允许返回true，否则返回false。 |

**示例：**

```js
let isUserChangeAllowed = wallpaper.isUserChangeAllowed();
```

## wallpaper.restore<sup>9+</sup>

restore(wallpaperType: WallpaperType, callback: AsyncCallback&lt;void&gt;): void

移除指定类型的壁纸，恢复为默认显示的壁纸。

**需要权限**：ohos.permission.SET_WALLPAPER

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | 是 | 壁纸类型。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，移除壁纸成功，error为undefined 否则返回error信息。 |

**示例：**

```js
wallpaper.restore(wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error) => {
    if (error) {
        console.error(`failed to restore because: ${JSON.stringify(error)}`);
        return;
    }
    console.log(`success to restore.`);
});
```

## wallpaper.restore<sup>9+</sup>

restore(wallpaperType: WallpaperType): Promise&lt;void&gt;

移除指定类型的壁纸，恢复为默认显示的壁纸。

**需要权限**：ohos.permission.SET_WALLPAPER

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | 是 | 壁纸类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**示例：**

```js 
wallpaper.restore(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then(() => {
    console.log(`success to restore.`);
  }).catch((error) => {
    console.error(`failed to restore because: ${JSON.stringify(error)}`);
});
```

## wallpaper.setImage<sup>9+</sup>

setImage(source: string | image.PixelMap, wallpaperType: WallpaperType, callback: AsyncCallback&lt;void&gt;): void

将指定资源设置为指定类型的壁纸。

**需要权限**：ohos.permission.SET_WALLPAPER

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| source | string \| [image.PixelMap](js-apis-image.md#pixelmap7) | 是 | JPEG或PNG文件的Uri路径，或者PNG格式文件的位图。 |
| wallpaperType | [WallpaperType](#wallpapertype) | 是 | 壁纸类型。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，设置壁纸成功，error为undefined 否则返回error信息。 |

**示例：**

```js
// source类型为string
let wallpaperPath = "/data/data/ohos.acts.aafwk.plrdtest.form/files/Cup_ic.jpg";
wallpaper.setImage(wallpaperPath, wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error) => {
    if (error) {
        console.error(`failed to setImage because: ${JSON.stringify(error)}`);
        return;
     }
    console.log(`success to setImage.`);
});
  
// source类型为image.PixelMap
import image from '@ohos.multimedia.image';
let imageSource = image.createImageSource("file://" + wallpaperPath);
let opts = {
    "desiredSize": {
        "height": 3648,
        "width": 2736
    }
};
imageSource.createPixelMap(opts).then((pixelMap) => {
    wallpaper.setImage(pixelMap, wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error) => {
        if (error) {
            console.error(`failed to setImage because: ${JSON.stringify(error)}`);
            return;
        }
        console.log(`success to setImage.`);
    });
}).catch((error) => {
    console.error(`failed to createPixelMap because: ${JSON.stringify(error)}`);
});
```

## wallpaper.setImage<sup>9+</sup>

setImage(source: string | image.PixelMap, wallpaperType: WallpaperType): Promise&lt;void&gt;

将指定资源设置为指定类型的壁纸。

**需要权限**：ohos.permission.SET_WALLPAPER

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| source | string \| [image.PixelMap](js-apis-image.md#pixelmap7) | 是 | JPEG或PNG文件的Uri路径，或者PNG格式文件的位图。 |
| wallpaperType | [WallpaperType](#wallpapertype) | 是 | 壁纸类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**示例：**

```js
// source类型为string
let wallpaperPath = "/data/data/ohos.acts.aafwk.plrdtest.form/files/Cup_ic.jpg";
wallpaper.setImage(wallpaperPath, wallpaper.WallpaperType.WALLPAPER_SYSTEM).then(() => {
    console.log(`success to setImage.`);
}).catch((error) => {
    console.error(`failed to setImage because: ${JSON.stringify(error)}`);
});

// source类型为image.PixelMap
import image from '@ohos.multimedia.image';
let imageSource = image.createImageSource("file://" + wallpaperPath);
let opts = {
    "desiredSize": {
        "height": 3648,
        "width": 2736
    }
};
imageSource.createPixelMap(opts).then((pixelMap) => {
    wallpaper.setImage(pixelMap, wallpaper.WallpaperType.WALLPAPER_SYSTEM).then(() => {
        console.log(`success to setImage.`);
    }).catch((error) => {
        console.error(`failed to setImage because: ${JSON.stringify(error)}`);
    });
}).catch((error) => {
    console.error(`failed to createPixelMap because: ${JSON.stringify(error)}`);
});
```

## wallpaper.getFileSync<sup>9+</sup>

getFileSync(wallpaperType: WallpaperType): number;

获取指定类型的壁纸文件。

**需要权限**：ohos.permission.GET_WALLPAPER

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | 是 | 壁纸类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 调用成功则返回壁纸文件描述符ID，调用失败则返回error信息。 |

**示例：**

```js
try {
    let file = wallpaper.getFileSync(wallpaper.WallpaperType.WALLPAPER_SYSTEM);
    console.log(`success to getFileSync: ${JSON.stringify(file)}`);
} catch (error) {
    console.error(`failed to getFileSync because: ${JSON.stringify(error)}`);
}
```

## wallpaper.getImage<sup>9+</sup>

getImage(wallpaperType: WallpaperType, callback: AsyncCallback&lt;image.PixelMap&gt;): void;

获取壁纸图片的像素图。

**需要权限**：ohos.permission.GET_WALLPAPER

**系统能力**: SystemCapability.MiscServices.Wallpaper

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | 是 | 壁纸类型。 |
| callback | AsyncCallback&lt;[image.PixelMap](js-apis-image.md#pixelmap7)&gt; | 是 | 回调函数，调用成功则返回壁纸图片的像素图对象，调用失败则返回error信息。 |

**示例：**

```js
wallpaper.getImage(wallpaper.WallpaperType.WALLPAPER_SYSTEM, function (error, data) {
    if (error) {
        console.error(`failed to getImage because: ${JSON.stringify(error)}`);
        return;
    }
    console.log(`success to getImage: ${JSON.stringify(data)}`);
});
```


## wallpaper.getImage<sup>9+</sup>

getImage(wallpaperType: WallpaperType): Promise&lt;image.PixelMap&gt;

获取壁纸图片的像素图。

**需要权限**：ohos.permission.GET_WALLPAPER

**系统能力**: SystemCapability.MiscServices.Wallpaper

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | 是 | 壁纸类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[image.PixelMap](js-apis-image.md#pixelmap7)&gt; | 调用成功则返回壁纸图片的像素图对象，调用失败则返回error信息。 |

**示例：**

```js
wallpaper.getImage(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data) => {
    console.log(`success to getImage: ${JSON.stringify(data)}`);
  }).catch((error) => {
    console.error(`failed to getImage because: ${JSON.stringify(error)}`);
});
```

## wallpaper.on('colorChange')<sup>9+</sup>

on(type: 'colorChange', callback: (colors: Array&lt;RgbaColor&gt;, wallpaperType: WallpaperType) =&gt; void): void

订阅壁纸颜色变化结果上报事件。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 取值为'colorChange'，表示壁纸颜色变化结果上报事件。 |
| callback | function | 是 | 壁纸颜色变化触发该回调方法，返回壁纸类型和壁纸的主要颜色信息。<br/>- colors<br/>  壁纸的主要颜色信息，其类型见[RgbaColor](#rgbacolor)。<br/>- wallpaperType<br/>  壁纸类型。 |

**示例：**

```js
try {
    let listener = (colors, wallpaperType) => {
        console.log(`wallpaper color changed.`);
    };
    wallpaper.on('colorChange', listener);
} catch (error) {
    console.error(`failed to on because: ${JSON.stringify(error)}`);
}
```

## wallpaper.off('colorChange')<sup>9+</sup>

off(type: 'colorChange', callback?: (colors: Array&lt;RgbaColor&gt;, wallpaperType: WallpaperType) =&gt; void): void

取消订阅壁纸颜色变化结果上报事件。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 取值为'colorChange'，表示取消订阅壁纸颜色变化结果上报事件。 |
| callback | function | 否 |   表示要取消的壁纸颜色变化的回调，不填写该参数则取消订阅该type对应的所有回调。<br/>- colors<br/>  壁纸的主要颜色信息，其类型见[RgbaColor](#rgbacolor)。<br/>- wallpaperType<br/>  壁纸类型。 |

**示例：**

```js
let listener = (colors, wallpaperType) => {
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

## wallpaper.getColors<sup>(deprecated)</sup>

getColors(wallpaperType: WallpaperType, callback: AsyncCallback&lt;Array&lt;RgbaColor&gt;&gt;): void

获取指定类型壁纸的主要颜色信息。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[wallpaper.getColorsSync<sup>9+</sup>](#wallpapergetcolorssync9)代替。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | 是 | 壁纸类型。 |
| callback | AsyncCallback&lt;Array&lt;[RgbaColor](#rgbacolor)&gt;&gt; | 是 | 回调函数，返回壁纸的主要颜色信息。 |

**示例：**

```js
wallpaper.getColors(wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error, data) => {
    if (error) {
        console.error(`failed to getColors because: ${JSON.stringify(error)}`);
        return;
    }
    console.log(`success to getColors: ${JSON.stringify(data)}`);
});
```

## wallpaper.getColors<sup>(deprecated)</sup>

getColors(wallpaperType: WallpaperType): Promise&lt;Array&lt;RgbaColor&gt;&gt;

获取指定类型壁纸的主要颜色信息。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[wallpaper.getColorsSync<sup>9+</sup>](#wallpapergetcolorssync9)代替。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | 是 | 壁纸类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;Array&lt;[RgbaColor](#rgbacolor)&gt;&gt; | 返回壁纸的主要颜色信息。 |

**示例：**

```js
wallpaper.getColors(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data) => {
    console.log(`success to getColors: ${JSON.stringify(data)}`);
  }).catch((error) => {
    console.error(`failed to getColors because: ${JSON.stringify(error)}`);
});
```

## wallpaper.getId<sup>(deprecated)</sup>

getId(wallpaperType: WallpaperType, callback: AsyncCallback&lt;number&gt;): void

获取指定类型壁纸的ID。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[wallpaper.getIdSync<sup>9+</sup>](#wallpapergetidsync9)代替。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | 是 | 壁纸类型。 |
| callback | AsyncCallback&lt;number&gt; | 是 | 回调函数，返回壁纸的ID。如果配置了指定类型的壁纸就返回一个大于等于0的数，否则返回-1。取值范围是-1到（2^31-1）。 |

**示例：**

```js
wallpaper.getId(wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error, data) => {
    if (error) {
        console.error(`failed to getId because: ${JSON.stringify(error)}`);
        return;
    }
    console.log(`success to getId: ${JSON.stringify(data)}`);
});
```

## wallpaper.getId<sup>(deprecated)</sup>

getId(wallpaperType: WallpaperType): Promise&lt;number&gt;

获取指定类型壁纸的ID。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[wallpaper.getIdSync<sup>9+</sup>](#wallpapergetidsync9)代替。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | 是 | 壁纸类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;number&gt; | 壁纸的ID。如果配置了这种壁纸类型的壁纸就返回一个大于等于0的数，否则返回-1。取值范围是-1到（2^31-1）。 |

**示例：**

```js
wallpaper.getId(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data) => {
    console.log(`success to getId: ${JSON.stringify(data)}`);
  }).catch((error) => {
    console.error(`failed to getId because: ${JSON.stringify(error)}`);
});
```

## wallpaper.getMinHeight<sup>(deprecated)</sup>

getMinHeight(callback: AsyncCallback&lt;number&gt;): void

获取壁纸的最小高度值。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[wallpaper.getMinHeightSync<sup>9+</sup>](#wallpapergetminheightsync9)代替。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;number&gt; | 是 | 回调函数，返回壁纸的最小高度值，单位是像素。如果返回值等于0，说明没有设置壁纸，调用者应该使用默认显示的高度值代替。 |

**示例：**

```js
wallpaper.getMinHeight((error, data) => {
    if (error) {
        console.error(`failed to getMinHeight because: ${JSON.stringify(error)}`);
        return;
    }
    console.log(`success to getMinHeight: ${JSON.stringify(data)}`);
});
```

## wallpaper.getMinHeight<sup>(deprecated)</sup>

getMinHeight(): Promise&lt;number&gt;

获取壁纸的最小高度值。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[wallpaper.getMinHeightSync<sup>9+</sup>](#wallpapergetminheightsync9)代替。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;number&gt; | 返回壁纸的最小高度值，单位是像素。如果返回值等于0，说明没有设置壁纸，调用者应该使用默认显示的高度值代替。 |

**示例：**

```js
wallpaper.getMinHeight().then((data) => {
    console.log(`success to getMinHeight: ${JSON.stringify(data)}`);
}).catch((error) => {
    console.error(`failed to getMinHeight because: ${JSON.stringify(error)}`);
});
```

## wallpaper.getMinWidth<sup>(deprecated)</sup>

getMinWidth(callback: AsyncCallback&lt;number&gt;): void

获取壁纸的最小宽度值。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[wallpaper.getMinWidthSync<sup>9+</sup>](#wallpapergetminwidthsync9)代替。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;number&gt; | 是 | 回调函数，壁纸的最小宽度值，单位是像素。如果返回值等于0，说明没有设置壁纸，调用者应该使用默认显示的宽度值代替。 |

**示例：**

```js
wallpaper.getMinWidth((error, data) => {
    if (error) {
        console.error(`failed to getMinWidth because: ${JSON.stringify(error)}`);
        return;
    }
    console.log(`success to getMinWidth: ${JSON.stringify(data)}`);
});
```

## wallpaper.getMinWidth<sup>(deprecated)</sup>

getMinWidth(): Promise&lt;number&gt;

获取壁纸的最小宽度值。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[wallpaper.getMinWidthSync<sup>9+</sup>](#wallpapergetminwidthsync9)代替。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;number&gt; | 壁纸的最小宽度值，单位是像素。如果返回值等于0，说明没有设置壁纸，调用者应该使用默认显示的宽度值代替。 |

**示例：**

```js
wallpaper.getMinWidth().then((data) => {
    console.log(`success to getMinWidth: ${JSON.stringify(data)}`);
  }).catch((error) => {
    console.error(`failed to getMinWidth because: ${JSON.stringify(error)}`);
});
```

## wallpaper.isChangePermitted<sup>(deprecated)</sup>

isChangePermitted(callback: AsyncCallback&lt;boolean&gt;): void

是否允许应用改变当前用户的壁纸。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[wallpaper.isChangeAllowed<sup>9+</sup>](#wallpaperischangeallowed9)代替。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数，返回是否允许应用改变当前用户的壁纸。如果允许返回true，否则返回false。 |

**示例：**

```js
wallpaper.isChangePermitted((error, data) => {
    if (error) {
        console.error(`failed to isChangePermitted because: ${JSON.stringify(error)}`);
        return;
    }
    console.log(`success to isChangePermitted: ${JSON.stringify(data)}`);
});
```

## wallpaper.isChangePermitted<sup>(deprecated)</sup>

isChangePermitted(): Promise&lt;boolean&gt;

是否允许应用改变当前用户的壁纸。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[wallpaper.isChangeAllowed<sup>9+</sup>](#wallpaperischangeallowed9)代替。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;boolean&gt; | 返回是否允许应用改变当前用户的壁纸。如果允许返回true，否则返回false。 |

**示例：**

```js
wallpaper.isChangePermitted().then((data) => {
    console.log(`success to isChangePermitted: ${JSON.stringify(data)}`);
}).catch((error) => {
    console.error(`failed to isChangePermitted because: ${JSON.stringify(error)}`);
});
```

## wallpaper.isOperationAllowed<sup>(deprecated)</sup>

isOperationAllowed(callback: AsyncCallback&lt;boolean&gt;): void

是否允许用户设置壁纸。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[wallpaper.isUserChangeAllowed<sup>9+</sup>](#wallpaperisuserchangeallowed9)代替。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数，返回是否允许用户设置壁纸。如果允许返回true，否则返回false。 |

**示例：**

```js
wallpaper.isOperationAllowed((error, data) => {
    if (error) {
        console.error(`failed to isOperationAllowed because: ${JSON.stringify(error)}`);
        return;
    }
    console.log(`success to isOperationAllowed: ${JSON.stringify(data)}`);
});
```

## wallpaper.isOperationAllowed<sup>(deprecated)</sup>

isOperationAllowed(): Promise&lt;boolean&gt;

是否允许用户设置壁纸。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[wallpaper.isUserChangeAllowed<sup>9+</sup>](#wallpaperisuserchangeallowed9)代替。

**系统能力**: SystemCapability.MiscServices.Wallpaper

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;boolean&gt; | 异步回调函数，返回是否允许用户设置壁纸。如果允许返回true，否则返回false。 |

**示例：**

```js
wallpaper.isOperationAllowed().then((data) => {
    console.log(`success to isOperationAllowed: ${JSON.stringify(data)}`);
  }).catch((error) => {
    console.error(`failed to isOperationAllowed because: ${JSON.stringify(error)}`);
});
```

## wallpaper.reset<sup>(deprecated)</sup>

reset(wallpaperType: WallpaperType, callback: AsyncCallback&lt;void&gt;): void

移除指定类型的壁纸，恢复为默认显示的壁纸。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[wallpaper.restore<sup>9+</sup>](#wallpaperrestore9)代替。

**需要权限**：ohos.permission.SET_WALLPAPER

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | 是 | 壁纸类型。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，移除壁纸成功，error为undefined 否则返回error信息。 |

**示例：**

```js
wallpaper.reset(wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error) => {
    if (error) {
        console.error(`failed to reset because: ${JSON.stringify(error)}`);
        return;
    }
    console.log(`success to reset.`);
});
```

## wallpaper.reset<sup>(deprecated)</sup>

reset(wallpaperType: WallpaperType): Promise&lt;void&gt;

移除指定类型的壁纸，恢复为默认显示的壁纸。

> **说明：**
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[wallpaper.restore<sup>9+</sup>](#wallpaperrestore9)代替。

**需要权限**：ohos.permission.SET_WALLPAPER

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | 是 | 壁纸类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**示例：**

```js
wallpaper.reset(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then(() => {
    console.log(`success to reset.`);
}).catch((error) => {
    console.error(`failed to reset because: ${JSON.stringify(error)}`);
});
```

## wallpaper.setWallpaper<sup>(deprecated)</sup>

setWallpaper(source: string | image.PixelMap, wallpaperType: WallpaperType, callback: AsyncCallback&lt;void&gt;): void

将指定资源设置为指定类型的壁纸。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[wallpaper.setImage<sup>9+</sup>](#wallpapersetimage9)代替。

**需要权限**：ohos.permission.SET_WALLPAPER

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| source | string \| [image.PixelMap](js-apis-image.md#pixelmap7) | 是 | JPEG或PNG文件的Uri路径，或者PNG格式文件的位图。 |
| wallpaperType | [WallpaperType](#wallpapertype) | 是 | 壁纸类型。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，设置壁纸成功，error为undefined 否则返回error信息。 |

**示例：**

```js
// source类型为string
let wallpaperPath = "/data/data/ohos.acts.aafwk.plrdtest.form/files/Cup_ic.jpg";
wallpaper.setWallpaper(wallpaperPath, wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error) => {
    if (error) {
        console.error(`failed to setWallpaper because: ${JSON.stringify(error)}`);
       return;
       }
    console.log(`success to setWallpaper.`);
});

// source类型为image.PixelMap
import image from '@ohos.multimedia.image';
let imageSource = image.createImageSource("file://" + wallpaperPath);
let opts = {
    "desiredSize": {
        "height": 3648,
        "width": 2736
    }
};
imageSource.createPixelMap(opts).then((pixelMap) => {
    wallpaper.setWallpaper(pixelMap, wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error) => {
        if (error) {
            console.error(`failed to setWallpaper because: ${JSON.stringify(error)}`);
            return;
        }
        console.log(`success to setWallpaper.`);
    });
}).catch((error) => {
    console.error(`failed to createPixelMap because: ${JSON.stringify(error)}`);
});
```

## wallpaper.setWallpaper<sup>(deprecated)</sup>

setWallpaper(source: string | image.PixelMap, wallpaperType: WallpaperType): Promise&lt;void&gt;

将指定资源设置为指定类型的壁纸。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[wallpaper.setImage<sup>9+</sup>](#wallpapersetimage9)代替。

**需要权限**：ohos.permission.SET_WALLPAPER

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| source | string \| [image.PixelMap](js-apis-image.md#pixelmap7) | 是 | JPEG或PNG文件的Uri路径，或者PNG格式文件的位图。 |
| wallpaperType | [WallpaperType](#wallpapertype) | 是 | 壁纸类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**示例：**

```js
// source类型为string
let wallpaperPath = "/data/data/ohos.acts.aafwk.plrdtest.form/files/Cup_ic.jpg";
wallpaper.setWallpaper(wallpaperPath, wallpaper.WallpaperType.WALLPAPER_SYSTEM).then(() => {
    console.log(`success to setWallpaper.`);
  }).catch((error) => {
    console.error(`failed to setWallpaper because: ${JSON.stringify(error)}`);
});
  
// source类型为image.PixelMap
import image from '@ohos.multimedia.image';
let imageSource = image.createImageSource("file://" + wallpaperPath);
let opts = {
    "desiredSize": {
        "height": 3648,
        "width": 2736
    }
};
imageSource.createPixelMap(opts).then((pixelMap) => {
    wallpaper.setWallpaper(pixelMap, wallpaper.WallpaperType.WALLPAPER_SYSTEM).then(() => {
        console.log(`success to setWallpaper.`);
    }).catch((error) => {
        console.error(`failed to setWallpaper because: ${JSON.stringify(error)}`);
    });
  }).catch((error) => {
    console.error(`failed to createPixelMap because: ${JSON.stringify(error)}`);
});
```


## wallpaper.getFile<sup>(deprecated)</sup>

getFile(wallpaperType: WallpaperType, callback: AsyncCallback&lt;number&gt;): void

获取指定类型的壁纸文件。

> **说明：**
> 
> 从 API version 8开始支持，从API version 9开始废弃。建议使用[wallpaper.getFileSync<sup>9+</sup>](#wallpapergetfilesync9)代替。

**需要权限**：ohos.permission.GET_WALLPAPER

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | 是 | 壁纸类型。 |
| callback | AsyncCallback&lt;number&gt; | 是 | 回调函数，调用成功则返回壁纸文件描述符ID，调用失败则返回error信息。 |

**示例：**

```js
wallpaper.getFile(wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error, data) => {
    if (error) {
        console.error(`failed to getFile because: ${JSON.stringify(error)}`);
        return;
    }
    console.log(`success to getFile: ${JSON.stringify(data)}`);
});
```

## wallpaper.getFile<sup>(deprecated)</sup>

getFile(wallpaperType: WallpaperType): Promise&lt;number&gt;

获取指定类型的壁纸文件。

> **说明：**
>
> 从 API version 8开始支持，从API version 9开始废弃。建议使用[wallpaper.getFileSync<sup>9+</sup>](#wallpapergetfilesync9)代替。

**需要权限**：ohos.permission.GET_WALLPAPER

**系统能力**: SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | 是 | 壁纸类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;number&gt; | 调用成功则返回壁纸文件描述符ID，调用失败则返回error信息。 |

**示例：**

```js
wallpaper.getFile(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data) => {
    console.log(`success to getFile: ${JSON.stringify(data)}`);
  }).catch((error) => {
    console.error(`failed to getFile because: ${JSON.stringify(error)}`);
});
```

## wallpaper.getPixelMap<sup>(deprecated)</sup>

getPixelMap(wallpaperType: WallpaperType, callback: AsyncCallback&lt;image.PixelMap&gt;): void;

获取壁纸图片的像素图。

> **说明：**
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[wallpaper.getImage<sup>9+</sup>](#wallpapergetimage9)代替。

**需要权限**：ohos.permission.GET_WALLPAPER

**系统能力**: SystemCapability.MiscServices.Wallpaper

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | 是 | 壁纸类型。 |
| callback | AsyncCallback&lt;image.PixelMap&gt; | 是 | 回调函数，调用成功则返回壁纸图片的像素图对象，调用失败则返回error信息。 |

**示例：**

```js
wallpaper.getPixelMap(wallpaper.WallpaperType.WALLPAPER_SYSTEM, function (error, data) {
    if (error) {
        console.error(`failed to getPixelMap because: ${JSON.stringify(error)}`);
        return;
    }
    console.log(`success to getPixelMap : ${JSON.stringify(data)}`);
  });
```

## wallpaper.getPixelMap<sup>(deprecated)</sup>

getPixelMap(wallpaperType: WallpaperType): Promise&lt;image.PixelMap&gt;

获取壁纸图片的像素图。

> **说明：**
>
> 从 API version 7开始支持，从API version 9开始废弃。建议使用[wallpaper.getImage<sup>9+</sup>](#wallpapergetimage9)代替。

**需要权限**：ohos.permission.GET_WALLPAPER

**系统能力**: SystemCapability.MiscServices.Wallpaper

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | 是 | 壁纸类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;image.PixelMap&gt; | 调用成功则返回壁纸图片的像素图对象，调用失败则返回error信息。 |

**示例：**

```js
wallpaper.getPixelMap(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data) => {
    console.log(`success to getPixelMap : ${JSON.stringify(data)}`);
  }).catch((error) => {
    console.error(`failed to getPixelMap because: ${JSON.stringify(error)}`);
});
```
