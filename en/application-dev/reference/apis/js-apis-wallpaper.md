# Wallpaper


> **NOTE**<br>The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```
import wallpaper from '@ohos.wallpaper';
```


## WallpaperType

Defines the wallpaper type.

**System capability**: SystemCapability.MiscServices.Wallpaper

| Name | Description |
| -------- | -------- |
| WALLPAPER_LOCKSCREEN | Lock screen wallpaper. |
| WALLPAPER_SYSTEM | Home screen wallpaper. |


## wallpaper.getColors

getColors(wallpaperType: WallpaperType, callback: AsyncCallback&lt;Array&lt;RgbaColor&gt;&gt;): void

Obtains the main color information of the wallpaper of the specified type. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**
| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | Yes | Wallpaper type. |
| callback | AsyncCallback&lt;Array&lt;[RgbaColor](#rgbacolor)&gt;&gt; | Yes | Callback used to return the main color information of the wallpaper. |

**Example**

  ```js
  wallpaper.getColors(wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error, data) => {
      if (error) {
          console.error(`failed to getColors because: ` + JSON.stringify(error));
          return;
      }
      console.log(`success to getColors.`);
  });
  ```


## wallpaper.getColors

getColors(wallpaperType: WallpaperType): Promise&lt;Array&lt;RgbaColor&gt;&gt;

Obtains the main color information of the wallpaper of the specified type. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | Yes | Wallpaper type. |

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;Array&lt;[RgbaColor](#rgbacolor)&gt;&gt; | Promise used to return the main color information of the wallpaper. |

**Example**

  ```js
  wallpaper.getColors(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data) => {
      console.log(`success to getColors.`);
  }).catch((error) => {
      console.error(`failed to getColors because: ` + JSON.stringify(error));
  });
  ```


## wallpaper.getId

getId(wallpaperType: WallpaperType, callback: AsyncCallback&lt;number&gt;): void

Obtains the ID of the wallpaper of the specified type. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | Yes | Wallpaper type. |
| callback | AsyncCallback&lt;number&gt; | Yes | Callback used to return the wallpaper ID. If the wallpaper of the specified type is configured, a number greater than or equal to **0** is returned. Otherwise, **-1** is returned. The value ranges from -1 to 2^31-1. |

**Example**

  ```js
  wallpaper.getId(wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error, data) => {
      if (error) {
          console.error(`failed to getId because: ` + JSON.stringify(error));
          return;
      }
      console.log(`success to getId: ` + JSON.stringify(data));
  });
  ```


## wallpaper.getId

getId(wallpaperType: WallpaperType): Promise&lt;number&gt;

Obtains the ID of the wallpaper of the specified type. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Wallpaper


**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | Yes | Wallpaper type. |

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;number&gt; | Promise used to return the wallpaper ID. If this type of wallpaper is configured, a number greater than or equal to **0** is returned. Otherwise, **-1** is returned. The value ranges from -1 to 2^31-1. |

**Example**

  ```js
  wallpaper.getId(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data) => {
      console.log(`success to getId: ` + JSON.stringify(data));
  }).catch((error) => {
      console.error(`failed to getId because: ` + JSON.stringify(error));
  });
  ```


## wallpaper.getMinHeight

getMinHeight(callback: AsyncCallback&lt;number&gt;): void

Obtains the minimum height of this wallpaper. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;number&gt; | Yes | Callback used to return the minimum wallpaper height, in pixels. If the return value is **0**, no wallpaper is set. In this case, the default height should be used instead. |

**Example**

  ```js
  wallpaper.getMinHeight((error, data) => {
      if (error) {
          console.error(`failed to getMinHeight because: ` + JSON.stringify(error));
          return;
      }
      console.log(`success to getMinHeight: ` + JSON.stringify(data));
  });
  ```


## wallpaper.getMinHeight

getMinHeight(): Promise&lt;number&gt;

Obtains the minimum height of this wallpaper. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Wallpaper


**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;number&gt; | Promise used to return the minimum wallpaper height, in pixels. If the return value is **0**, no wallpaper is set. In this case, the default height should be used instead. |

**Example**

  ```js
  wallpaper.getMinHeight().then((data) => {
      console.log(`success to getMinHeight: ` + JSON.stringify(data));
  }).catch((error) => {
      console.error(`failed to getMinHeight because: ` + JSON.stringify(error));
  });
  ```


## wallpaper.getMinWidth

getMinWidth(callback: AsyncCallback&lt;number&gt;): void

Obtains the minimum width of this wallpaper. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;number&gt; | Yes | Callback used to return the minimum wallpaper width, in pixels. If the return value is **0**, no wallpaper is set. In this case, the default width should be used instead. |

**Example**

  ```js
  wallpaper.getMinWidth((error, data) => {
      if (error) {
          console.error(`failed to getMinWidth because: ` + JSON.stringify(error));
          return;
      }
      console.log(`success to getMinWidth: ` + JSON.stringify(data));
  });
  ```


## wallpaper.getMinWidth

getMinWidth(): Promise&lt;number&gt;

Obtains the minimum width of this wallpaper. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;number&gt; | Promised used to return the minimum wallpaper width, in pixels. If the return value is **0**, no wallpaper is set. In this case, the default width should be used instead. |

**Example**

  ```js
  wallpaper.getMinWidth().then((data) => {
      console.log(`success to getMinWidth: ` + JSON.stringify(data));
  }).catch((error) => {
      console.error(`failed to getMinWidth because: ` + JSON.stringify(error));
  });
  ```


## wallpaper.isChangePermitted

isChangePermitted(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether to allow the application to change the wallpaper for the current user. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes | Returns **true** if the application is allowed to change the wallpaper for the current user; returns **false** otherwise. |

**Example**

  ```js
  wallpaper.isChangePermitted((error, data) => {
      if (error) {
          console.error(`failed to isChangePermitted because: ` + JSON.stringify(error));
          return;
      }
      console.log(`success to isChangePermitted: ` + JSON.stringify(data));
  });
  ```


## wallpaper.isChangePermitted

isChangePermitted(): Promise&lt;boolean&gt;

Checks whether to allow the application to change the wallpaper for the current user. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;boolean&gt; | Returns **true** if the application is allowed to change the wallpaper for the current user; returns **false** otherwise. |

**Example**

  ```js
  wallpaper.isChangePermitted().then((data) => {
      console.log(`success to isChangePermitted: ` + JSON.stringify(data));
  }).catch((error) => {
      console.error(`failed to isChangePermitted because: ` + JSON.stringify(error));
  });
  ```


## wallpaper.isOperationAllowed

isOperationAllowed(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether the user is allowed to set wallpapers. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes | Returns **true** if the user is allowed to set wallpapers; returns **false** otherwise. |

**Example**

  ```js
  wallpaper.isOperationAllowed((error, data) => {
      if (error) {
          console.error(`failed to isOperationAllowed because: ` + JSON.stringify(error));
          return;
      }
      console.log(`success to isOperationAllowed: ` + JSON.stringify(data));
  });
  ```


## wallpaper.isOperationAllowed

isOperationAllowed(): Promise&lt;boolean&gt;

Checks whether the user is allowed to set wallpapers. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;boolean&gt; | Returns **true** if the user is allowed to set wallpapers; returns **false** otherwise. |

**Example**

  ```js
  wallpaper.isOperationAllowed().then((data) => {
      console.log(`success to isOperationAllowed: ` + JSON.stringify(data));
  }).catch((error) => {
      console.error(`failed to isOperationAllowed because: ` + JSON.stringify(error));
  });
  ```


## wallpaper.reset

reset(wallpaperType: WallpaperType, callback: AsyncCallback&lt;void&gt;): void

Resets the wallpaper of the specified type to the default wallpaper. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.SET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | Yes | Wallpaper type. |
| callback | AsyncCallback&lt;void&gt; | Yes | Callback used to return the result. If the operation is successful, the result is returned. Otherwise, error information is returned. |

**Example**

  ```js
  wallpaper.reset(wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error, data) => {
      if (error) {
          console.error(`failed to reset because: ` + JSON.stringify(error));
          return;
      }
      console.log(`success to reset.`);
  });
  ```


## wallpaper.reset

reset(wallpaperType: WallpaperType): Promise&lt;void&gt;

Resets the wallpaper of the specified type to the default wallpaper. This API uses a promise to return the result.

**Required permissions**: ohos.permission.SET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | Yes | Wallpaper type. |

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result. If the operation is successful, the result is returned. Otherwise, error information is returned. |

**Example**

  ```js
  wallpaper.reset(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data) => {
      console.log(`success to reset.`);
  }).catch((error) => {
      console.error(`failed to reset because: ` + JSON.stringify(error));
  });
  ```


## wallpaper.setWallpaper

setWallpaper(source: string | image.PixelMap, wallpaperType: WallpaperType, callback: AsyncCallback&lt;void&gt;): void

Sets a specified source as the wallpaper of a specified type. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.SET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| source | string \| [PixelMap](js-apis-image.md#pixelmap7) | Yes | URI of a JPEG or PNG file, or bitmap of a PNG file. |
| wallpaperType | [WallpaperType](#wallpapertype) | Yes | Wallpaper type. |
| callback | AsyncCallback&lt;void&gt; | Yes | Callback used to return the result. If the operation is successful, the setting result is returned. Otherwise, error information is returned. |

**Example**

```js
// The source type is string.
let wallpaperPath = "/data/data/ohos.acts.aafwk.plrdtest.form/files/Cup_ic.jpg";
wallpaper.setWallpaper(wallpaperPath, wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error, data) => {   
    if (error) {        
        console.error(`failed to setWallpaper because: ` + JSON.stringify(error));       
        return;   
    }    
    console.log(`success to setWallpaper.`);
});

// The source type is image.PixelMap.
import image from '@ohos.multimedia.image';
let imageSource = image.createImageSource("file://" + wallpaperPath);
let opts = {
    "desiredSize": {
        "height": 3648,
        "width": 2736
    }
};
imageSource.createPixelMap(opts).then((pixelMap) => {      
    wallpaper.setWallpaper(pixelMap, wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error, data) => {    
        if (error) {       
            console.error(`failed to setWallpaper because: ` + JSON.stringify(error));
            return;
        }    
        console.log(`success to setWallpaper.`);
    });
}).catch((error) => {       
    console.error(`failed to createPixelMap because: ` + JSON.stringify(error));
});
```


## wallpaper.setWallpaper

setWallpaper(source: string | image.PixelMap, wallpaperType: WallpaperType): Promise&lt;void&gt;

Sets a specified source as the wallpaper of a specified type. This API uses a promise to return the result.

**Required permissions**: ohos.permission.SET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| source | string \| [PixelMap](js-apis-image.md#pixelmap7) | Yes | URI path of the JPEG or PNG file, or bitmap of the PNG file. |
| wallpaperType | [WallpaperType](#wallpapertype) | Yes | Wallpaper type. |

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result. If the operation is successful, the setting result is returned. Otherwise, error information is returned. |

**Example**

```js
// The source type is string.
let wallpaperPath = "/data/data/ohos.acts.aafwk.plrdtest.form/files/Cup_ic.jpg";
wallpaper.setWallpaper(wallpaperPath, wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data) => {
    console.log(`success to setWallpaper.`);
}).catch((error) => {
    console.error(`failed to setWallpaper because: ` + JSON.stringify(error));
});

// The source type is image.PixelMap.
import image from '@ohos.multimedia.image';
let imageSource = image.createImageSource("file://" + wallpaperPath);
let opts = {
    "desiredSize": {
        "height": 3648,
        "width": 2736
    }
};
imageSource.createPixelMap(opts).then((pixelMap) => {      
    wallpaper.setWallpaper(pixelMap, wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data) => {
        console.log(`success to setWallpaper.`);
    }).catch((error) => {
        console.error(`failed to setWallpaper because: ` + JSON.stringify(error));
    });
}).catch((error) => {       
    console.error(`failed to createPixelMap because: ` + JSON.stringify(error));
});
```

## wallpaper.getFile<sup>8+</sup>

getFile(wallpaperType: WallpaperType, callback: AsyncCallback&lt;number&gt;): void

Obtains the wallpaper of the specified type. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.SET_WALLPAPER and ohos.permission.READ_USER_STORAGE

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | Yes | Wallpaper type. |
| callback | AsyncCallback&lt;number&gt; | Yes | Callback used to return the result. If the operation is successful, the file descriptor ID to the wallpaper is returned. Otherwise, error information is returned. |

**Example**

  ```js
  wallpaper.getFile(wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error, data) => {
      if (error) {
          console.error(`failed to getFile because: ` + JSON.stringify(error));
          return;
      }
      console.log(`success to getFile: ` + JSON.stringify(data));
  });
  ```

## wallpaper.getFile<sup>8+</sup>

getFile(wallpaperType: WallpaperType): Promise&lt;number&gt;

Obtains the wallpaper of the specified type. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_WALLPAPER and ohos.permission.READ_USER_STORAGE

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | Yes | Wallpaper type. |

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;number&gt; | Promise used to return the result. If the operation is successful, the file descriptor ID to the wallpaper is returned. Otherwise, error information is returned. |

**Example**

  ```js
  wallpaper.getFile(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data) => {
      console.log(`success to getFile: ` + JSON.stringify(data));
  }).catch((error) => {
      console.error(`failed to getFile because: ` + JSON.stringify(error));
  });
  ```


## wallpaper.getPixelMap

getPixelMap(wallpaperType: WallpaperType, callback: AsyncCallback&lt;image.PixelMap&gt;): void;

Obtains the pixel image for the wallpaper of the specified type. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_WALLPAPER and ohos.permission.READ_USER_STORAGE

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | Yes| Wallpaper type.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, the result is returned. Otherwise, error information is returned.|

**Example**

  ```js
  wallpaper.getPixelMap(WALLPAPER_SYSTEM, function (err, data) {
      console.info('wallpaperXTS ===> testGetPixelMapCallbackSystem err : ' + JSON.stringify(err));
      console.info('wallpaperXTS ===> testGetPixelMapCallbackSystem data : ' + JSON.stringify(data));
  });
  ```


## wallpaper.getPixelMap

getPixelMap(wallpaperType: WallpaperType): Promise&lt;image.PixelMap&gt;

Obtains the pixel image for the wallpaper of the specified type. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_WALLPAPER and ohos.permission.READ_USER_STORAGE

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | Yes| Wallpaper type.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result. If the operation is successful, the result is returned. Otherwise, error information is returned.|

**Example**

  ```js
  wallpaper.getPixelMap(WALLPAPER_SYSTEM).then((data) => {
      console.info('wallpaperXTS ===> testGetPixelMapPromiseSystem data : ' + data);
      console.info('wallpaperXTS ===> testGetPixelMapPromiseSystem data : ' + JSON.stringify(data));
  }).catch((err) => {
      console.info('wallpaperXTS ===> testGetPixelMapPromiseSystem err : ' + err);
      console.info('wallpaperXTS ===> testGetPixelMapPromiseSystem err : ' + JSON.stringify(err));
  });
  ```


## wallpaper.on('colorChange')

on(type: 'colorChange', callback: (colors: Array&lt;RgbaColor&gt;, wallpaperType: WallpaperType) =&gt; void): void

Subscribes to the wallpaper color change event.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Type of the event to subscribe to. The value **colorChange** indicates subscribing to the wallpaper color change event. |
| callback | function | Yes | Callback triggered when the wallpaper color changes. The wallpaper type and main colors are returned.<br>- colors<br>  Main color information of the wallpaper. For details, see [RgbaColor](#rgbacolor).<br>- wallpaperType<br>  Wallpaper type. |

**Example**

```js
let listener = (colors, wallpaperType) => {
    console.log(`wallpaper color changed.`);
};
wallpaper.on('colorChange', listener);
```


## wallpaper.off('colorChange')

off(type: 'colorChange', callback?: (colors: Array&lt;RgbaColor&gt;, wallpaperType: WallpaperType) =&gt; void): void

Unsubscribes from the wallpaper color change event.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Type of the event to unsubscribe from. The value **colorChange** indicates unsubscribing from the wallpaper color change event. |
| callback | function | No |   Callback for the wallpaper color change event. If this parameter is not specified, all callbacks corresponding to the wallpaper color change event are invoked.<br>- colors<br>  Main color information of the wallpaper. For details, see [RgbaColor](#rgbacolor).<br>- wallpaperType<br>  Wallpaper type. |

**Example**

```js
let listener = (colors, wallpaperType) => {
    console.log(`wallpaper color changed.`);
};
wallpaper.on('colorChange', listener);
// Unsubscribe from the listener.
wallpaper.off('colorChange', listener);
//Unsubscribe from all subscriptions of the colorChange type.
wallpaper.off('colorChange');
```


## RgbaColor

**System capability**: SystemCapability.MiscServices.Wallpaper

| Name | Type | Readable | Writable | Description |
| -------- | -------- | -------- | -------- | -------- |
| red | number | Yes | Yes | Red color. The value ranges from 0 to 255. |
| green | number | Yes | Yes | Green color. The value ranges from 0 to 255. |
| blue | number | Yes | Yes | Blue color. The value ranges from 0 to 255. |
| alpha | number | Yes | Yes | Alpha value. The value ranges from 0 to 255. |
