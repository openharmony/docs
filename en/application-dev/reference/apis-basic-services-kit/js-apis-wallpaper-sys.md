# @ohos.wallpaper (Wallpaper) (System API)

The **wallpaper** module provides APIs for switching between wallpapers. Since API version 9, the APIs of this module function as system APIs, and only system applications are allowed to switch between wallpapers. Applications that use the wallpaper, for example, the home screen, need to subscribe to wallpaper changes and update the wallpaper accordingly.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.wallpaper (Wallpaper)](js-apis-wallpaper.md).


## Modules to Import


```ts
import { wallpaper } from '@kit.BasicServicesKit';
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

## FoldState<sup>14+</sup>

Enumerates the types of the folding state of a device.

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

| Name| Value|Description|
| -------- | -------- |-------- |
| NORMAL | 0 |Default state.|
| UNFOLD_ONCE_STATE | 1 |Initial unfolded state.|
| UNFOLD_TWICE_STATE | 2 |Secondary unfolded state.|

## RotateState<sup>14+</sup>

Enumerates the landscape or portrait mode of a device.

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

| Name| Value|Description|
| -------- | -------- |-------- |
| PORTRAIT | 0 |Portrait mode (default).|
| LANDSCAPE | 1 |Landscape mode.|

## WallpaperInfo<sup>14+</sup>

Defines the wallpaper information structure.

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

| Name| Type| Description|
| -------- | -------- |  -------- |
| [FoldState](#foldstate14) | enum | Folding state of a device.|
| [RotateState](#rotatestate14) | enum | Landscape/portrait mode of a device.|
| source | string | Wallpaper resource URI. Only the application sandbox directory is supported.|

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
| wallpaperType | [WallpaperType](js-apis-wallpaper.md#wallpapertype7) | Yes| Wallpaper type.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the wallpaper is set, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 201          | permission denied.                                                                              |
| 202          | permission verification failed, application which is not a system application uses system API.  |
| 401          | 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed.  |

**Example**

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

Sets a video resource as the home screen wallpaper or lock screen wallpaper. This API uses a promise to return the result.

**Required permissions**: ohos.permission.SET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| source | string | Yes| URI of an MP4 file.|
| wallpaperType | [WallpaperType](js-apis-wallpaper.md#wallpapertype7) | Yes| Wallpaper type.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 201          | permission denied.                                                                              |
| 202          | permission verification failed, application which is not a system application uses system API.  |
| 401          | 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed.  |

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

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

Sets a specific ZIP file as the wallpaper. This API works only when **com.ohos.sceneboard** is set. Applications with the **ohos.permission.GET_WALLPAPER** permission have access to the **/data/wallpaper/** directory. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.SET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| source | string | Yes| ZIP file to set as the wallpaper.|
| wallpaperType | [WallpaperType](js-apis-wallpaper.md#wallpapertype7) | Yes| Wallpaper type.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the wallpaper is set, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 201          | permission denied.                                                                              |
| 202          | permission verification failed, application which is not a system application uses system API.  |
| 401          | 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed.  |

**Example**

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

Sets a specific ZIP file as the wallpaper. This API works only when **com.ohos.sceneboard** is set. Applications with the **ohos.permission.GET_WALLPAPER** permission have access to the **/data/wallpaper/** directory. This API uses a promise to return the result.

**Required permissions**: ohos.permission.SET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| source | string | Yes| ZIP file to set as the wallpaper.|
| wallpaperType | [WallpaperType](js-apis-wallpaper.md#wallpapertype7) | Yes| Wallpaper type.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 201          | permission denied.                                                                              |
| 202          | permission verification failed, application which is not a system application uses system API.  |
| 401          | 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed.  |

**Example**

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

Subscribes to wallpaper change events. Multi-thread concurrent calls are not supported.

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is fixed at **'wallpaperChange'**.|
| callback | function | Yes| Callback used to return the wallpaper type and wallpaper resource type.<br>- **wallpaperType**: wallpaper type.<br>- **resourceType**: wallpaper resource type.<br>- **uri**: URI of the wallpaper resource.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 202          | permission verification failed, application which is not a system application uses system API.  |
| 401          | 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed.  |

**Example**

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

Unsubscribes from wallpaper change events. Multi-thread concurrent calls are not supported.

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is fixed at **'wallpaperChange'**.|
| callback | function | No|   Callback used for unsubscription. If this parameter is not set, this API unsubscribes from all callbacks of the specified event type.<br>- **wallpaperType**: wallpaper type.<br>- **resourceType**: wallpaper resource type.<br>- **uri**: URI of the wallpaper resource.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 202          | permission verification failed, application which is not a system application uses system API.  |
| 401          | 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed.  |

**Example**

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
| wallpaperType | [WallpaperType](js-apis-wallpaper.md#wallpapertype7) | Yes| Wallpaper type.|

**Return value**

| Type| Description|
| -------- | -------- |
| Array&lt;[RgbaColor](js-apis-wallpaper.md#rgbacolordeprecated)&gt; | Promise used to return the main color information of the wallpaper.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 202          | permission verification failed, application which is not a system application uses system API.  |
| 401          | 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed.  |

**Example**

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

Obtains the minimum height of this wallpaper.

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

**Return value**

| Type| Description|
| -------- | -------- |
| number | Promise used to return the minimum wallpaper height, in pixels. If the return value is **0**, no wallpaper is set. In this case, the default height should be used instead.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 202          | permission verification failed, application which is not a system application uses system API.  |

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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 202          | permission verification failed, application which is not a system application uses system API.  |

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
| wallpaperType | [WallpaperType](js-apis-wallpaper.md#wallpapertype7) | Yes| Wallpaper type.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the wallpaper is reset, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 201          | permission denied.                                                                              |
| 202          | permission verification failed, application which is not a system application uses system API.  |
| 401          | 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed.  |

**Example**

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

Resets the wallpaper of the specified type to the default wallpaper. This API uses a promise to return the result.

**Required permissions**: ohos.permission.SET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](js-apis-wallpaper.md#wallpapertype7) | Yes| Wallpaper type.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 201          | permission denied.                                                                              |
| 202          | permission verification failed, application which is not a system application uses system API.  |
| 401          | 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed.  |

**Example**

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

Sets a specified source as the wallpaper of a specified type. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.SET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| source | string \| [image.PixelMap](../apis-image-kit/js-apis-image.md) | Yes| URI of a JPEG or PNG file, or pixel map of a PNG file.|
| wallpaperType | [WallpaperType](js-apis-wallpaper.md#wallpapertype7) | Yes| Wallpaper type.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the wallpaper is set, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 201          | permission denied.                                                                              |
| 202          | permission verification failed, application which is not a system application uses system API.  |
| 401          | 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

// The source type is string.
let wallpaperPath = "/data/storage/el2/base/haps/entry/files/js.jpeg";
wallpaper.setImage(wallpaperPath, wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error: BusinessError) => {
    if (error) {
        console.error(`failed to setImage because: ${JSON.stringify(error)}`);
        return;
     }
    console.info(`success to setImage.`);
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
        console.info(`success to setImage.`);
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
| source | string \| [image.PixelMap](../apis-image-kit/js-apis-image.md) | Yes| URI of a JPEG or PNG file, or pixel map of a PNG file.|
| wallpaperType | [WallpaperType](js-apis-wallpaper.md#wallpapertype7) | Yes| Wallpaper type.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 201          | permission denied.                                                                              |
| 202          | permission verification failed, application which is not a system application uses system API.  |
| 401          | 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

// The source type is string.
let wallpaperPath = "/data/storage/el2/base/haps/entry/files/js.jpeg";
wallpaper.setImage(wallpaperPath, wallpaper.WallpaperType.WALLPAPER_SYSTEM).then(() => {
    console.info(`success to setImage.`);
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
        console.info(`success to setImage.`);
    }).catch((error: BusinessError) => {
        console.error(`failed to setImage because: ${JSON.stringify(error)}`);
    });
}).catch((error: BusinessError) => {
    console.error(`failed to createPixelMap because: ${JSON.stringify(error)}`);
});
```

## wallpaper.getImage<sup>9+</sup>

getImage(wallpaperType: WallpaperType, callback: AsyncCallback&lt;image.PixelMap&gt;): void;

Obtains the pixel map for the wallpaper of the specified type. This API only works for the static wallpaper set using **setImage**. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](js-apis-wallpaper.md#wallpapertype7) | Yes| Wallpaper type.|
| callback | AsyncCallback&lt;[image.PixelMap](../apis-image-kit/js-apis-image.md)&gt; | Yes| Callback used to return the result. If the operation is successful, the pixel map of the wallpaper is returned. Otherwise, error information is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 201          | permission denied.                                                                              |
| 202          | permission verification failed, application which is not a system application uses system API.  |
| 401          | 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed.  |

**Example**

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

Obtains the pixel map for the wallpaper of the specified type. This API only works for the static wallpaper set using **setImage**. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](js-apis-wallpaper.md#wallpapertype7) | Yes| Wallpaper type.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[image.PixelMap](../apis-image-kit/js-apis-image.md)&gt; | Promise used to return the result. If the operation is successful, the pixel map of the wallpaper is returned. Otherwise, error information is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 201          | permission denied.                                                                              |
| 202          | permission verification failed, application which is not a system application uses system API.  |
| 401          | 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed.  |

**Example**

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

Obtains the pixel map of the wallpaper of a specific type, folding state, or landscape/portrait mode. If the specified wallpaper does not exist, the matching follows a degrading order: unfolded-land > unfolded-port > normal-port. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](js-apis-wallpaper.md#wallpapertype7) | Yes| Wallpaper type.|
| foldState | [FoldState](#foldstate14) | Yes| Folding state type.|
| rotateState | [RotateState](#rotatestate14) | Yes| Landscape/portrait mode.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[image.PixelMap](../apis-image-kit/js-apis-image.md)&gt; | Promise used to return the result. If the operation is successful, the pixel map of the wallpaper is returned. Otherwise, error information is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 201          | permission denied.                                                                              |
| 202          | permission verification failed, application which is not a system application uses system API.  |
| 401          | 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed.  |

**Example**

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

Sets all wallpaper to a specific folding state, landscape/portrait mode, and resource path, where **wallpaper.FoldState.NORMAL** and **wallpaper.RotateState.PORTRAIT** are mandatory. This API uses a promise to return the result.  

**Required permissions**: ohos.permission.SET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperInfos | Array<[WallpaperInfo](#wallpaperinfo14)> | Yes| Information structure of all wallpapers.|
| wallpaperType | [WallpaperType](js-apis-wallpaper.md#wallpapertype7) | Yes| Wallpaper type.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 201          | permission denied.                                                                              |
| 202          | permission verification failed, application which is not a system application uses system API.  |
| 401          | 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed.|

**Example**

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

getPixelMap(wallpaperType: WallpaperType, callback: AsyncCallback&lt;image.PixelMap&gt;): void;

Obtains the pixel map for the wallpaper of the specified type.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9.

**Required permissions**: ohos.permission.GET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](js-apis-wallpaper.md#wallpapertype7) | Yes| Wallpaper type.|
| callback | AsyncCallback&lt;image.PixelMap&gt; | Yes| Callback used to return the result. If the operation is successful, the pixel map of the wallpaper is returned. Otherwise, error information is returned.|

**Example**

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

Obtains the pixel map for the wallpaper of the specified type.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9.

**Required permissions**: ohos.permission.GET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](js-apis-wallpaper.md#wallpapertype7) | Yes| Wallpaper type.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;image.PixelMap&gt; | Promise used to return the result. If the operation is successful, the pixel map of the wallpaper is returned. Otherwise, error information is returned.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

wallpaper.getPixelMap(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data: image.PixelMap) => {
    console.info(`success to getPixelMap : ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`failed to getPixelMap because: ${JSON.stringify(error)}`);
});
```
