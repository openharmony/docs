# @ohos.wallpaper (Wallpaper)

The **wallpaper** module is a system service module in OpenHarmony that provides the wallpaper management service. You can use the APIs of this module to show, set, and switch between wallpapers.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```ts
import wallpaper from '@ohos.wallpaper';
```
## WallpaperResourceType<sup>10+</sup>

Enumerates the types of wallpaper resources.

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

| Name| Value|Description|
| -------- | -------- |-------- |
| DEFAULT | 0 |Default type (image resource).|
| PICTURE | 1 |Image resource.|
| VIDEO | 2 |Video resource.|
| PACKAGE | 3 |Package resource.|


## WallpaperType<sup>7+</sup>

Enumerates the wallpaper types.

**System capability**: SystemCapability.MiscServices.Wallpaper

| Name| Value|Description|
| -------- | -------- |-------- |
| WALLPAPER_SYSTEM | 0 |Home screen wallpaper.|
| WALLPAPER_LOCKSCREEN | 1 |Lock screen wallpaper.|


## RgbaColor<sup>(deprecated)</sup>

Defines the RGBA color space for the wallpaper.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9.

**System capability**: SystemCapability.MiscServices.Wallpaper

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| red | number | Yes| Yes| Red color. The value ranges from 0 to 255.|
| green | number | Yes| Yes| Green color. The value ranges from 0 to 255.|
| blue | number | Yes| Yes| Blue color. The value ranges from 0 to 255.|
| alpha | number | Yes| Yes| Alpha value. The value ranges from 0 to 255.|


## wallpaper.setVideo<sup>10+</sup>

setVideo(source: string, wallpaperType: WallpaperType, callback: AsyncCallback&lt;void&gt;): void

Sets a video resource as the home screen wallpaper or lock screen wallpaper. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.SET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| source | string | Yes| URI of an MP4 file.|
| wallpaperType | [WallpaperType](#wallpapertype7) | Yes| Wallpaper type.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the wallpaper is set, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

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

## wallpaper.setVideo<sup>10+</sup>

setVideo(source: string, wallpaperType: WallpaperType): Promise&lt;void&gt;

Sets a video resource as the home screen wallpaper or lock screen wallpaper. This API uses a promise to return the result.

**Required permissions**: ohos.permission.SET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| source | string | Yes| URI of an MP4 file.|
| wallpaperType | [WallpaperType](#wallpapertype7) | Yes| Wallpaper type.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

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

## wallpaper.setCustomWallpaper<sup>10+</sup>

setCustomWallpaper(source: string, wallpaperType: WallpaperType, callback: AsyncCallback&lt;void&gt;): void

Sets the content from a specified URI as the wallpaper. This API works only when com.ohos.sceneboard is set. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.SET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| source | string | Yes| URI of the custom wallpaper.|
| wallpaperType | [WallpaperType](#wallpapertype7) | Yes| Wallpaper type.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the wallpaper is set, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

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

## wallpaper.setCustomWallpaper<sup>10+</sup>

setCustomWallpaper(source: string, wallpaperType: WallpaperType): Promise&lt;void&gt;

Sets the content from a specified URI as the wallpaper. This API works only when com.ohos.sceneboard is set. This API uses a promise to return the result.

**Required permissions**: ohos.permission.SET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| source | string | Yes| URI of the custom wallpaper.|
| wallpaperType | [WallpaperType](#wallpapertype7) | Yes| Wallpaper type.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

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

## wallpaper.on('wallpaperChange')<sup>10+</sup>

on(type: 'wallpaperChange', callback: (wallpaperType: WallpaperType, resourceType: WallpaperResourceType, uri?: string) =&gt; void): void

Subscribes to wallpaper change events.

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is fixed at **'wallpaperChange'**.|
| callback | function | Yes| Callback used to return the wallpaper type and wallpaper resource type.<br>- **wallpaperType**: wallpaper type.<br>- **resourceType**: wallpaper resource type.<br>- **uri**: URI of the wallpaper resource.|

**Example**

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

## wallpaper.off('wallpaperChange')<sup>10+</sup>

off(type: 'wallpaperChange', callback?: (wallpaperType: WallpaperType, resourceType: WallpaperResourceType, uri?: string) =&gt; void): void

Unsubscribes from wallpaper change events.

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is fixed at **'wallpaperChange'**.|
| callback | function | No|   Callback used for unsubscription. If this parameter is not set, this API unsubscribes from all callbacks of the specified event type.<br>- **wallpaperType**: wallpaper type.<br>- **resourceType**: wallpaper resource type.<br>- **uri**: URI of the wallpaper resource.|

**Example**

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
    // Unsubscribe from the listener.
    wallpaper.off('wallpaperChange', listener);
} catch (error) {
    console.error(`failed to off because: ${JSON.stringify(error)}`);
}

try {
    // Unsubscribe from all callbacks of the 'wallpaperChange' event type.
    wallpaper.off('wallpaperChange');
} catch (error) {
    console.error(`failed to off because: ${JSON.stringify(error)}`);
}
```

## wallpaper.getColorsSync<sup>9+</sup>

getColorsSync(wallpaperType: WallpaperType): Array&lt;RgbaColor&gt;

Obtains the main color information of the wallpaper of the specified type.

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype7) | Yes| Wallpaper type.|

**Return value**

| Type| Description|
| -------- | -------- |
| Array&lt;[RgbaColor](#rgbacolordeprecated)&gt; | Promise used to return the main color information of the wallpaper.|

**Example**

```ts
try {
    let colors = wallpaper.getColorsSync(wallpaper.WallpaperType.WALLPAPER_SYSTEM);
    console.log(`success to getColorsSync: ${JSON.stringify(colors)}`);
} catch (error) {
    console.error(`failed to getColorsSync because: ${JSON.stringify(error)}`);
}
```

## wallpaper.getMinHeightSync<sup>9+</sup>

getMinHeightSync(): number

Obtains the minimum height of this wallpaper.

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

**Return value**

| Type| Description|
| -------- | -------- |
| number | Promise used to return the minimum wallpaper height, in pixels. If the return value is **0**, no wallpaper is set. In this case, the default height should be used instead.|

**Example**

```ts
let minHeight = wallpaper.getMinHeightSync();
```

## wallpaper.getMinWidthSync<sup>9+</sup>

getMinWidthSync(): number

Obtains the minimum width of this wallpaper.

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

**Return value**

| Type| Description|
| -------- | -------- |
| number | Promise used to return the minimum wallpaper width, in pixels. If the return value is **0**, no wallpaper is set. In this case, the default width should be used instead.|

**Example**

```ts
let minWidth = wallpaper.getMinWidthSync();
```

## wallpaper.restore<sup>9+</sup>

restore(wallpaperType: WallpaperType, callback: AsyncCallback&lt;void&gt;): void

Resets the wallpaper of the specified type to the default wallpaper. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.SET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype7) | Yes| Wallpaper type.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the wallpaper is reset, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

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

## wallpaper.restore<sup>9+</sup>

restore(wallpaperType: WallpaperType): Promise&lt;void&gt;

Resets the wallpaper of the specified type to the default wallpaper. This API uses a promise to return the result.

**Required permissions**: ohos.permission.SET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype7) | Yes| Wallpaper type.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts 
import { BusinessError } from '@ohos.base';
 
wallpaper.restore(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then(() => {
    console.log(`success to restore.`);
  }).catch((error: BusinessError) => {
    console.error(`failed to restore because: ${JSON.stringify(error)}`);
});
```

## wallpaper.setImage<sup>9+</sup>

setImage(source: string | image.PixelMap, wallpaperType: WallpaperType, callback: AsyncCallback&lt;void&gt;): void

Sets a specified source as the wallpaper of a specified type. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.SET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| source | string \| [image.PixelMap](js-apis-image.md#pixelmap7) | Yes| URI of a JPEG or PNG file, or pixel map of a PNG file.|
| wallpaperType | [WallpaperType](#wallpapertype7) | Yes| Wallpaper type.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the wallpaper is set, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
import image from '@ohos.multimedia.image';

// The source type is string.
let wallpaperPath = "/data/storage/el2/base/haps/entry/files/js.jpeg";
wallpaper.setImage(wallpaperPath, wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error: BusinessError) => {
    if (error) {
        console.error(`failed to setImage because: ${JSON.stringify(error)}`);
        return;
     }
    console.log(`success to setImage.`);
});
  
// The source type is image.PixelMap.
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

## wallpaper.setImage<sup>9+</sup>

setImage(source: string | image.PixelMap, wallpaperType: WallpaperType): Promise&lt;void&gt;

Sets a specified source as the wallpaper of a specified type. This API uses a promise to return the result.

**Required permissions**: ohos.permission.SET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| source | string \| [image.PixelMap](js-apis-image.md#pixelmap7) | Yes| URI of a JPEG or PNG file, or pixel map of a PNG file.|
| wallpaperType | [WallpaperType](#wallpapertype7) | Yes| Wallpaper type.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
import image from '@ohos.multimedia.image';

// The source type is string.
let wallpaperPath = "/data/storage/el2/base/haps/entry/files/js.jpeg";
wallpaper.setImage(wallpaperPath, wallpaper.WallpaperType.WALLPAPER_SYSTEM).then(() => {
    console.log(`success to setImage.`);
}).catch((error: BusinessError) => {
    console.error(`failed to setImage because: ${JSON.stringify(error)}`);
});

// The source type is image.PixelMap.
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

## wallpaper.getImage<sup>9+</sup>

getImage(wallpaperType: WallpaperType, callback: AsyncCallback&lt;image.PixelMap&gt;): void;

Obtains the pixel map for the wallpaper of the specified type. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype7) | Yes| Wallpaper type.|
| callback | AsyncCallback&lt;[image.PixelMap](js-apis-image.md#pixelmap7)&gt; | Yes| Callback used to return the result. If the operation is successful, the pixel map of the wallpaper is returned. Otherwise, error information is returned.|

**Example**

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


## wallpaper.getImage<sup>9+</sup>

getImage(wallpaperType: WallpaperType): Promise&lt;image.PixelMap&gt;

Obtains the pixel map for the wallpaper of the specified type. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype7) | Yes| Wallpaper type.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[image.PixelMap](js-apis-image.md#pixelmap7)&gt; | Promise used to return the result. If the operation is successful, the pixel map of the wallpaper is returned. Otherwise, error information is returned.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
import image from '@ohos.multimedia.image';

wallpaper.getImage(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data: image.PixelMap) => {
    console.log(`success to getImage: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`failed to getImage because: ${JSON.stringify(error)}`);
});
```

## wallpaper.on('colorChange')<sup>(deprecated)</sup>

on(type: 'colorChange', callback: (colors: Array&lt;RgbaColor&gt;, wallpaperType: WallpaperType) =&gt; void): void

Subscribes to the wallpaper color change event.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Type of the event to subscribe to. The value **'colorChange'** indicates subscribing to the wallpaper color change event.|
| callback | function | Yes| Callback triggered when the wallpaper color changes. The wallpaper type and main colors are returned.<br>- colors<br>  Main color information of the wallpaper. For details, see [RgbaColor](#rgbacolordeprecated).<br>- wallpaperType<br>  Wallpaper type.|

**Example**

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

## wallpaper.off('colorChange')<sup>(deprecated)</sup>

off(type: 'colorChange', callback?: (colors: Array&lt;RgbaColor&gt;, wallpaperType: WallpaperType) =&gt; void): void

Unsubscribes from the wallpaper color change event.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Type of the event to unsubscribe from. The value **'colorChange'** indicates unsubscribing from the wallpaper color change event.|
| callback | function | No|   Callback used for unsubscription. If this parameter is not set, this API unsubscribes from all callbacks of the specified event type.<br>- colors<br>  Main color information of the wallpaper. For details, see [RgbaColor](#rgbacolordeprecated).<br>- wallpaperType<br>  Wallpaper type.|

**Example**

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
    // Unsubscribe from the listener.
    wallpaper.off('colorChange', listener);
} catch (error) {
    console.error(`failed to off because: ${JSON.stringify(error)}`);
}

try {
    // Unsubscribe from all subscriptions of the colorChange type.
    wallpaper.off('colorChange');
} catch (error) {
    console.error(`failed to off because: ${JSON.stringify(error)}`);
}
```

## wallpaper.getColors<sup>(deprecated)</sup>

getColors(wallpaperType: WallpaperType, callback: AsyncCallback&lt;Array&lt;RgbaColor&gt;&gt;): void

Obtains the main color information of the wallpaper of the specified type. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype7) | Yes| Wallpaper type.|
| callback | AsyncCallback&lt;Array&lt;[RgbaColor](#rgbacolordeprecated)&gt;&gt; | Yes| Callback used to return the main color information of the wallpaper.|

**Example**

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

## wallpaper.getColors<sup>(deprecated)</sup>

getColors(wallpaperType: WallpaperType): Promise&lt;Array&lt;RgbaColor&gt;&gt;

Obtains the main color information of the wallpaper of the specified type. This API uses a promise to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype7) | Yes| Wallpaper type.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;Array&lt;[RgbaColor](#rgbacolordeprecated)&gt;&gt; | Promise used to return the main color information of the wallpaper.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

wallpaper.getColors(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data: Array<wallpaper.RgbaColor>) => {
    console.log(`success to getColors: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`failed to getColors because: ${JSON.stringify(error)}`);
});
```

## wallpaper.getId<sup>(deprecated)</sup>

getId(wallpaperType: WallpaperType, callback: AsyncCallback&lt;number&gt;): void

Obtains the ID of the wallpaper of the specified type. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype7) | Yes| Wallpaper type.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the wallpaper ID. If the wallpaper of the specified type is configured, a number greater than or equal to **0** is returned. Otherwise, **-1** is returned. The value ranges from -1 to (2^31-1).|

**Example**

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

## wallpaper.getId<sup>(deprecated)</sup>

getId(wallpaperType: WallpaperType): Promise&lt;number&gt;

Obtains the ID of the wallpaper of the specified type. This API uses a promise to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype7) | Yes| Wallpaper type.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;number&gt; | Promise used to return the wallpaper ID. If this type of wallpaper is configured, a number greater than or equal to **0** is returned. Otherwise, **-1** is returned. The value ranges from -1 to (2^31-1).|

**Example**

```ts
import { BusinessError } from '@ohos.base';

wallpaper.getId(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data: Number) => {
    console.log(`success to getId: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`failed to getId because: ${JSON.stringify(error)}`);
});
```

## wallpaper.getMinHeight<sup>(deprecated)</sup>

getMinHeight(callback: AsyncCallback&lt;number&gt;): void

Obtains the minimum height of this wallpaper. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the minimum wallpaper height, in pixels. If the return value is **0**, no wallpaper is set. In this case, the default height should be used instead.|

**Example**

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

## wallpaper.getMinHeight<sup>(deprecated)</sup>

getMinHeight(): Promise&lt;number&gt;

Obtains the minimum height of this wallpaper. This API uses a promise to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;number&gt; | Promise used to return the minimum wallpaper height, in pixels. If the return value is **0**, no wallpaper is set. In this case, the default height should be used instead.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

wallpaper.getMinHeight().then((data: Number) => {
    console.log(`success to getMinHeight: ${JSON.stringify(data)}`);
}).catch((error: BusinessError) => {
    console.error(`failed to getMinHeight because: ${JSON.stringify(error)}`);
});
```

## wallpaper.getMinWidth<sup>(deprecated)</sup>

getMinWidth(callback: AsyncCallback&lt;number&gt;): void

Obtains the minimum width of this wallpaper. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the minimum wallpaper width, in pixels. If the return value is **0**, no wallpaper is set. In this case, the default width should be used instead.|

**Example**

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

## wallpaper.getMinWidth<sup>(deprecated)</sup>

getMinWidth(): Promise&lt;number&gt;

Obtains the minimum width of this wallpaper. This API uses a promise to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;number&gt; | Promise used to return the minimum wallpaper width, in pixels. If the return value is **0**, no wallpaper is set. In this case, the default width should be used instead.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

wallpaper.getMinWidth().then((data: Number) => {
    console.log(`success to getMinWidth: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`failed to getMinWidth because: ${JSON.stringify(error)}`);
});
```

## wallpaper.isChangePermitted<sup>(deprecated)</sup>

isChangePermitted(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether to allow the application to change the wallpaper for the current user. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return whether to allow the application to change the wallpaper for the current user. The value **true** means that the operation is allowed, and **false** means the opposite.|

**Example**

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

## wallpaper.isChangePermitted<sup>(deprecated)</sup>

isChangePermitted(): Promise&lt;boolean&gt;

Checks whether to allow the application to change the wallpaper for the current user. This API uses a promise to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise used to return whether to allow the application to change the wallpaper for the current user. The value **true** means that the operation is allowed, and **false** means the opposite.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

wallpaper.isChangePermitted().then((data: Boolean) => {
    console.log(`success to isChangePermitted: ${JSON.stringify(data)}`);
}).catch((error: BusinessError) => {
    console.error(`failed to isChangePermitted because: ${JSON.stringify(error)}`);
});
```

## wallpaper.isOperationAllowed<sup>(deprecated)</sup>

isOperationAllowed(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether the user is allowed to set wallpapers. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return whether the user is allowed to set wallpapers. The value **true** means that the operation is allowed, and **false** means the opposite.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

wallpaper.isChangePermitted().then((data: Boolean) => {
    console.log(`success to isChangePermitted: ${JSON.stringify(data)}`);
}).catch((error: BusinessError) => {
    console.error(`failed to isChangePermitted because: ${JSON.stringify(error)}`);
});
```

## wallpaper.isOperationAllowed<sup>(deprecated)</sup>

isOperationAllowed(): Promise&lt;boolean&gt;

Checks whether the user is allowed to set wallpapers. This API uses a promise to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise used to return whether the user is allowed to set wallpapers. The value **true** means that the operation is allowed, and **false** means the opposite.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

wallpaper.isOperationAllowed().then((data: Boolean) => {
    console.log(`success to isOperationAllowed: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`failed to isOperationAllowed because: ${JSON.stringify(error)}`);
});
```

## wallpaper.reset<sup>(deprecated)</sup>

reset(wallpaperType: WallpaperType, callback: AsyncCallback&lt;void&gt;): void

Resets the wallpaper of the specified type to the default wallpaper. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9.

**Required permissions**: ohos.permission.SET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype7) | Yes| Wallpaper type.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the wallpaper is reset, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

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

## wallpaper.reset<sup>(deprecated)</sup>

reset(wallpaperType: WallpaperType): Promise&lt;void&gt;

Resets the wallpaper of the specified type to the default wallpaper. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9.

**Required permissions**: ohos.permission.SET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype7) | Yes| Wallpaper type.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

wallpaper.reset(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then(() => {
    console.log(`success to reset.`);
}).catch((error: BusinessError) => {
    console.error(`failed to reset because: ${JSON.stringify(error)}`);
});
```

## wallpaper.setWallpaper<sup>(deprecated)</sup>

setWallpaper(source: string | image.PixelMap, wallpaperType: WallpaperType, callback: AsyncCallback&lt;void&gt;): void

Sets a specified source as the wallpaper of a specified type. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9.

**Required permissions**: ohos.permission.SET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| source | string \| [image.PixelMap](js-apis-image.md#pixelmap7) | Yes| URI of a JPEG or PNG file, or pixel map of a PNG file.|
| wallpaperType | [WallpaperType](#wallpapertype7) | Yes| Wallpaper type.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the wallpaper is set, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
import image from '@ohos.multimedia.image';

// The source type is string.
let wallpaperPath = "/data/storage/el2/base/haps/entry/files/js.jpeg";
wallpaper.setWallpaper(wallpaperPath, wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error: BusinessError) => {
    if (error) {
        console.error(`failed to setWallpaper because: ${JSON.stringify(error)}`);
       return;
       }
    console.log(`success to setWallpaper.`);
});

// The source type is image.PixelMap.
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
    console.error(`failed to createPixelMap because: ${JSON.stringify(error)}`);
});
```

## wallpaper.setWallpaper<sup>(deprecated)</sup>

setWallpaper(source: string | image.PixelMap, wallpaperType: WallpaperType): Promise&lt;void&gt;

Sets a specified source as the wallpaper of a specified type. This API uses a promise to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9.

**Required permissions**: ohos.permission.SET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| source | string \| [image.PixelMap](js-apis-image.md#pixelmap7) | Yes| URI of a JPEG or PNG file, or pixel map of a PNG file.|
| wallpaperType | [WallpaperType](#wallpapertype7) | Yes| Wallpaper type.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
import image from '@ohos.multimedia.image';

// The source type is string.
let wallpaperPath = "/data/storage/el2/base/haps/entry/files/js.jpeg";
wallpaper.setWallpaper(wallpaperPath, wallpaper.WallpaperType.WALLPAPER_SYSTEM).then(() => {
    console.log(`success to setWallpaper.`);
  }).catch((error: BusinessError) => {
    console.error(`failed to setWallpaper because: ${JSON.stringify(error)}`);
});
  
// The source type is image.PixelMap.
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


## wallpaper.getFile<sup>(deprecated)</sup>

getFile(wallpaperType: WallpaperType, callback: AsyncCallback&lt;number&gt;): void

Obtains the wallpaper of the specified type. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 8 and deprecated since API version 9.

**Required permissions**: ohos.permission.GET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype7) | Yes| Wallpaper type.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the result. If the operation is successful, the file descriptor ID to the wallpaper is returned. Otherwise, error information is returned.|

**Example**

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

## wallpaper.getFile<sup>(deprecated)</sup>

getFile(wallpaperType: WallpaperType): Promise&lt;number&gt;

Obtains the wallpaper of the specified type. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9.

**Required permissions**: ohos.permission.GET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype7) | Yes| Wallpaper type.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;number&gt; | Promise used to return the result. If the operation is successful, the file descriptor ID to the wallpaper is returned. Otherwise, error information is returned.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

wallpaper.getFile(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data: number) => {
    console.log(`success to getFile: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`failed to getFile because: ${JSON.stringify(error)}`);
});

```

## wallpaper.getPixelMap<sup>(deprecated)</sup>

getPixelMap(wallpaperType: WallpaperType, callback: AsyncCallback&lt;image.PixelMap&gt;): void;

Obtains the pixel map for the wallpaper of the specified type. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9.

**Required permissions**: ohos.permission.GET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype7) | Yes| Wallpaper type.|
| callback | AsyncCallback&lt;image.PixelMap&gt; | Yes| Callback used to return the result. If the operation is successful, the pixel map of the wallpaper is returned. Otherwise, error information is returned.|

**Example**

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

## wallpaper.getPixelMap<sup>(deprecated)</sup>

getPixelMap(wallpaperType: WallpaperType): Promise&lt;image.PixelMap&gt;

Obtains the pixel map for the wallpaper of the specified type. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9.

**Required permissions**: ohos.permission.GET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype7) | Yes| Wallpaper type.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;image.PixelMap&gt; | Promise used to return the result. If the operation is successful, the pixel map of the wallpaper is returned. Otherwise, error information is returned.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
import image from '@ohos.multimedia.image';

wallpaper.getPixelMap(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data: image.PixelMap) => {
    console.log(`success to getPixelMap : ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`failed to getPixelMap because: ${JSON.stringify(error)}`);
});
```
