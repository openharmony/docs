# Wallpaper

The **wallpaper** module is part of the theme framework and provides the system-level wallpaper management service in OpenHarmony. You can use the APIs of this module to show, set, and switch between wallpapers.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```
import wallpaper from '@ohos.wallpaper';
```


## WallpaperType

Enumerates the wallpaper types.

**System capability**: SystemCapability.MiscServices.Wallpaper

| Name| Value|Description|
| -------- | -------- |-------- |
| WALLPAPER_SYSTEM | 0 |Home screen wallpaper.|
| WALLPAPER_LOCKSCREEN | 1 |Lock screen wallpaper.|


## wallpaper.getColors

getColors(wallpaperType: WallpaperType, callback: AsyncCallback&lt;Array&lt;RgbaColor&gt;&gt;): void

Obtains the main color information of the wallpaper of the specified type. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [wallpaper.getColorsSync<sup>9+</sup>](#wallpapergetcolorssync9) instead.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | Yes| Wallpaper type.|
| callback | AsyncCallback&lt;Array&lt;[RgbaColor](#rgbacolor)&gt;&gt; | Yes| Callback used to return the main color information of the wallpaper.|

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

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [wallpaper.getColorsSync<sup>9+</sup>](#wallpapergetcolorssync9) instead.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | Yes| Wallpaper type.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;Array&lt;[RgbaColor](#rgbacolor)&gt;&gt; | Promise used to return the main color information of the wallpaper.|

**Example**

  ```js
  wallpaper.getColors(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data) => {
      console.log(`success to getColors.`);
  }).catch((error) => {
      console.error(`failed to getColors because: ` + JSON.stringify(error));
  });
  ```


## wallpaper.getColorsSync<sup>9+</sup>

getColorsSync(wallpaperType: WallpaperType): Array&lt;RgbaColor&gt;

Obtains the main color information of the wallpaper of the specified type. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | Yes| Wallpaper type.|

**Return value**

| Type| Description|
| -------- | -------- |
| Array&lt;[RgbaColor](#rgbacolor)&gt; | Promise used to return the main color information of the wallpaper.|

**Example**

  ```js
  var colors = wallpaper.getColorsSync(wallpaper.WallpaperType.WALLPAPER_SYSTEM);
  ```


## wallpaper.getId

getId(wallpaperType: WallpaperType, callback: AsyncCallback&lt;number&gt;): void

Obtains the ID of the wallpaper of the specified type. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [wallpaper.getIdSync<sup>9+</sup>](#wallpapergetidsync9) instead.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | Yes| Wallpaper type.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the wallpaper ID. If the wallpaper of the specified type is configured, a number greater than or equal to **0** is returned. Otherwise, **-1** is returned. The value ranges from -1 to 2^31-1.|

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

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [wallpaper.getIdSync<sup>9+</sup>](#wallpapergetidsync9) instead.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | Yes| Wallpaper type.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;number&gt; | Promise used to return the wallpaper ID. If this type of wallpaper is configured, a number greater than or equal to **0** is returned. Otherwise, **-1** is returned. The value ranges from -1 to 2^31-1.|

**Example**

  ```js
  wallpaper.getId(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data) => {
      console.log(`success to getId: ` + JSON.stringify(data));
  }).catch((error) => {
      console.error(`failed to getId because: ` + JSON.stringify(error));
  });
  ```


## wallpaper.getIdSync<sup>9+</sup>

getIdSync(wallpaperType: WallpaperType): number

Obtains the ID of the wallpaper of the specified type. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | Yes| Wallpaper type.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | ID of the wallpaper. If this type of wallpaper is configured, a number greater than or equal to **0** is returned. Otherwise, **-1** is returned. The value ranges from -1 to 2^31-1.|

**Example**

  ```js
  var id = wallpaper.getIdSync(wallpaper.WallpaperType.WALLPAPER_SYSTEM);
  ```


## wallpaper.getMinHeight

getMinHeight(callback: AsyncCallback&lt;number&gt;): void

Obtains the minimum height of this wallpaper. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [wallpaper.getMinHeightSync<sup>9+</sup>](#wallpapergetminheightsync9) instead.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the minimum wallpaper height, in pixels. If the return value is **0**, no wallpaper is set. In this case, the default height should be used instead.|

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

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [wallpaper.getMinHeightSync<sup>9+</sup>](#wallpapergetminheightsync9) instead.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;number&gt; | Promise used to return the minimum wallpaper height, in pixels. If the return value is **0**, no wallpaper is set. In this case, the default height should be used instead.|

**Example**

  ```js
  wallpaper.getMinHeight().then((data) => {
      console.log(`success to getMinHeight: ` + JSON.stringify(data));
  }).catch((error) => {
      console.error(`failed to getMinHeight because: ` + JSON.stringify(error));
  });
  ```


## wallpaper.getMinHeightSync<sup>9+</sup>

getMinHeightSync(): number

Obtains the minimum height of this wallpaper. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Return value**

| Type| Description|
| -------- | -------- |
| number | Promise used to return the minimum wallpaper height, in pixels. If the return value is **0**, no wallpaper is set. In this case, the default height should be used instead.|

**Example**

  ```js
  var minHeight = wallpaper.getMinHeightSync();
  ```


## wallpaper.getMinWidth

getMinWidth(callback: AsyncCallback&lt;number&gt;): void

Obtains the minimum width of this wallpaper. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [wallpaper.getMinWidthSync<sup>9+</sup>](#wallpapergetminwidthsync9) instead.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the minimum wallpaper width, in pixels. If the return value is **0**, no wallpaper is set. In this case, the default width should be used instead.|

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

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [wallpaper.getMinWidthSync<sup>9+</sup>](#wallpapergetminwidthsync9) instead.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;number&gt; | Promise used to return the minimum wallpaper width, in pixels. If the return value is **0**, no wallpaper is set. In this case, the default width should be used instead.|

**Example**

  ```js
  wallpaper.getMinWidth().then((data) => {
      console.log(`success to getMinWidth: ` + JSON.stringify(data));
  }).catch((error) => {
      console.error(`failed to getMinWidth because: ` + JSON.stringify(error));
  });
  ```


## wallpaper.getMinWidthSync<sup>9+</sup>

getMinWidthSync(): number

Obtains the minimum width of this wallpaper. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Return value**

| Type| Description|
| -------- | -------- |
| number | Promise used to return the minimum wallpaper width, in pixels. If the return value is **0**, no wallpaper is set. In this case, the default width should be used instead.|

**Example**

  ```js
  var minWidth = wallpaper.getMinWidthSync();
  ```


## wallpaper.isChangePermitted

isChangePermitted(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether to allow the application to change the wallpaper for the current user. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [wallpaper.isChangeAllowed<sup>9+</sup>](#wallpaperischangeallowed9) instead.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return whether to allow the application to change the wallpaper for the current user. The value **true** means that the operation is allowed, and **false** means the opposite.|

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

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [wallpaper.isChangeAllowed<sup>9+</sup>](#wallpaperischangeallowed9) instead.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise used to return whether to allow the application to change the wallpaper for the current user. The value **true** means that the operation is allowed, and **false** means the opposite.|

**Example**

  ```js
  wallpaper.isChangePermitted().then((data) => {
      console.log(`success to isChangePermitted: ` + JSON.stringify(data));
  }).catch((error) => {
      console.error(`failed to isChangePermitted because: ` + JSON.stringify(error));
  });
  ```


## wallpaper.isChangeAllowed<sup>9+</sup>

isChangeAllowed(): boolean

Checks whether to allow the application to change the wallpaper for the current user. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Whether to allow the application to change the wallpaper for the current user. The value **true** means that the operation is allowed, and **false** means the opposite.|

**Example**

  ```js
  var isChangeAllowed = wallpaper.isChangeAllowed();
  ```


## wallpaper.isOperationAllowed

isOperationAllowed(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether the user is allowed to set wallpapers. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [wallpaper.isUserChangeAllowed<sup>9+</sup>](#wallpaperisuserchangeallowed9) instead.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return whether the user is allowed to set wallpapers. The value **true** means that the operation is allowed, and **false** means the opposite.|

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

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [wallpaper.isUserChangeAllowed<sup>9+</sup>](#wallpaperisuserchangeallowed9) instead.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise used to return whether the user is allowed to set wallpapers. The value **true** means that the operation is allowed, and **false** means the opposite.|

**Example**

  ```js
  wallpaper.isOperationAllowed().then((data) => {
      console.log(`success to isOperationAllowed: ` + JSON.stringify(data));
  }).catch((error) => {
      console.error(`failed to isOperationAllowed because: ` + JSON.stringify(error));
  });
  ```


## wallpaper.isUserChangeAllowed<sup>9+</sup>

isUserChangeAllowed(): boolean

Checks whether the user is allowed to set wallpapers. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Whether the user is allowed to set wallpapers. The value **true** means that the operation is allowed, and **false** means the opposite.|

**Example**

  ```js
  var isUserChangeAllowed = wallpaper.isUserChangeAllowed();
  ```


## wallpaper.reset

reset(wallpaperType: WallpaperType, callback: AsyncCallback&lt;void&gt;): void

Resets the wallpaper of the specified type to the default wallpaper. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [wallpaper.restore<sup>9+</sup>](#wallpaperrestore9) instead.

**Required permissions**: ohos.permission.SET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | Yes| Wallpaper type.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, the result of removal is returned. Otherwise, error information is returned.|

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

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [wallpaper.restore<sup>9+</sup>](#wallpaperrestore9) instead.

**Required permissions**: ohos.permission.SET_WALLPAPER

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
  wallpaper.reset(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data) => {
      console.log(`success to reset.`);
  }).catch((error) => {
      console.error(`failed to reset because: ` + JSON.stringify(error));
  });
  ```


## wallpaper.restore<sup>9+</sup>

restore(wallpaperType: WallpaperType, callback: AsyncCallback&lt;void&gt;): void

Resets the wallpaper of the specified type to the default wallpaper. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.SET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | Yes| Wallpaper type.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, the result of removal is returned. Otherwise, error information is returned.|

**Example**

  ```js
  wallpaper.restore(wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error, data) => {
      if (error) {
          console.error(`failed to restore because: ` + JSON.stringify(error));
          return;
      }
      console.log(`success to restore.`);
  });
  ```


## wallpaper.restore<sup>9+</sup>

restore(wallpaperType: WallpaperType): Promise&lt;void&gt;

Resets the wallpaper of the specified type to the default wallpaper. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.SET_WALLPAPER

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
  wallpaper.restore(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data) => {
      console.log(`success to restore.`);
  }).catch((error) => {
      console.error(`failed to restore because: ` + JSON.stringify(error));
  });
  ```


## wallpaper.setWallpaper

setWallpaper(source: string | image.PixelMap, wallpaperType: WallpaperType, callback: AsyncCallback&lt;void&gt;): void

Sets a specified source as the wallpaper of a specified type. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [wallpaper.setImage<sup>9+</sup>](#wallpapersetimage9) instead.

**Required permissions**: ohos.permission.SET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| source | string \|[image.PixelMap](js-apis-image.md#pixelmap7) | Yes| URI of a JPEG or PNG file, or bitmap of a PNG file.|
| wallpaperType | [WallpaperType](#wallpapertype) | Yes| Wallpaper type.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, the setting result is returned. Otherwise, error information is returned.|

**Example**

  ```js
  //The source type is string.
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

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [wallpaper.setImage<sup>9+</sup>](#wallpapersetimage9) instead.

**Required permissions**: ohos.permission.SET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| source | string \|[image.PixelMap](js-apis-image.md#pixelmap7) | Yes| URI of a JPEG or PNG file, or bitmap of a PNG file.|
| wallpaperType | [WallpaperType](#wallpapertype) | Yes| Wallpaper type.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result. If the operation is successful, the setting result is returned. Otherwise, error information is returned.|

**Example**

  ```js
  //The source type is string.
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


## wallpaper.setImage<sup>9+</sup>

setImage(source: string | image.PixelMap, wallpaperType: WallpaperType, callback: AsyncCallback&lt;void&gt;): void

Sets a specified source as the wallpaper of a specified type. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.SET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| source | string \|[image.PixelMap](js-apis-image.md#pixelmap7) | Yes| URI of a JPEG or PNG file, or bitmap of a PNG file.|
| wallpaperType | [WallpaperType](#wallpapertype) | Yes| Wallpaper type.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, the setting result is returned. Otherwise, error information is returned.|

**Example**

  ```js
  //The source type is string.
  let wallpaperPath = "/data/data/ohos.acts.aafwk.plrdtest.form/files/Cup_ic.jpg";
  wallpaper.setImage(wallpaperPath, wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error, data) => {    
      if (error) {        
          console.error(`failed to setImage because: ` + JSON.stringify(error));       
          return;   
      }    
      console.log(`success to setImage.`);
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
      wallpaper.setImage(pixelMap, wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error, data) => {    
          if (error) {       
              console.error(`failed to setImage because: ` + JSON.stringify(error));
              return;
          }    
          console.log(`success to setImage.`);
      });
  }).catch((error) => {       
      console.error(`failed to createPixelMap because: ` + JSON.stringify(error));
  });
  ```


## wallpaper.setImage<sup>9+</sup>

setImage(source: string | image.PixelMap, wallpaperType: WallpaperType): Promise&lt;void&gt;

Sets a specified source as the wallpaper of a specified type. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.SET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| source | string \|[image.PixelMap](js-apis-image.md#pixelmap7) | Yes| URI of a JPEG or PNG file, or bitmap of a PNG file.|
| wallpaperType | [WallpaperType](#wallpapertype) | Yes| Wallpaper type.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result. If the operation is successful, the setting result is returned. Otherwise, error information is returned.|

**Example**

  ```js
  //The source type is string.
  let wallpaperPath = "/data/data/ohos.acts.aafwk.plrdtest.form/files/Cup_ic.jpg";
  wallpaper.setImage(wallpaperPath, wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data) => {
      console.log(`success to setImage.`);
  }).catch((error) => {
      console.error(`failed to setImage because: ` + JSON.stringify(error));
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
      wallpaper.setImage(pixelMap, wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data) => {
          console.log(`success to setImage.`);
      }).catch((error) => {
          console.error(`failed to setImage because: ` + JSON.stringify(error));
      });
  }).catch((error) => {       
      console.error(`failed to createPixelMap because: ` + JSON.stringify(error));
  });
  ```


## wallpaper.getFile<sup>8+</sup>

getFile(wallpaperType: WallpaperType, callback: AsyncCallback&lt;number&gt;): void

Obtains the wallpaper of the specified type. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [wallpaper.getFileSync<sup>9+</sup>](#wallpapergetfilesync9) instead.

**Required permissions**: ohos.permission.GET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | Yes| Wallpaper type.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the result. If the operation is successful, the file descriptor ID to the wallpaper is returned. Otherwise, error information is returned.|

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

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [wallpaper.getFileSync<sup>9+</sup>](#wallpapergetfilesync9) instead.

**Required permissions**: ohos.permission.GET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | Yes| Wallpaper type.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;number&gt; | Promise used to return the result. If the operation is successful, the file descriptor ID to the wallpaper is returned. Otherwise, error information is returned.|

**Example**

  ```js
  wallpaper.getFile(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data) => {
      console.log(`success to getFile: ` + JSON.stringify(data));
  }).catch((error) => {
      console.error(`failed to getFile because: ` + JSON.stringify(error));
  });
  ```


## wallpaper.getFileSync<sup>9+</sup>

getFileSync(wallpaperType: WallpaperType): number;

Obtains the wallpaper of the specified type. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | Yes| Wallpaper type.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Promise used to return the result. If the operation is successful, the file descriptor ID to the wallpaper is returned. Otherwise, error information is returned.|

**Example**

  ```js
  var file = wallpaper.getFileSync(wallpaper.WallpaperType.WALLPAPER_SYSTEM);
  ```


## wallpaper.getPixelMap

getPixelMap(wallpaperType: WallpaperType, callback: AsyncCallback&lt;image.PixelMap&gt;): void;

Obtains the pixel map for the wallpaper of the specified type. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [wallpaper.getImage<sup>9+</sup>](#wallpapergetimage9) instead.

**Required permissions**: ohos.permission.GET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | Yes| Wallpaper type.|
| callback | AsyncCallback&lt;image.PixelMap&gt; | Yes| Callback used to return the result. Returns the pixel map size of the wallpaper if the operation is successful; returns an error message otherwise.|

**Example**

  ```js
  wallpaper.getPixelMap(wallpaper.WallpaperType.WALLPAPER_SYSTEM, function (err, data) {
      console.info('wallpaperXTS ===> testGetPixelMapCallbackSystem err : ' + JSON.stringify(err));
      console.info('wallpaperXTS ===> testGetPixelMapCallbackSystem data : ' + JSON.stringify(data));
  });
  ```


## wallpaper.getPixelMap

getPixelMap(wallpaperType: WallpaperType): Promise&lt;image.PixelMap&gt;

Obtains the pixel map for the wallpaper of the specified type. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [wallpaper.getImage<sup>9+</sup>](#wallpapergetimage9) instead.

**Required permissions**: ohos.permission.GET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | Yes| Wallpaper type.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;image.PixelMap&gt; | Promise used to return the result. Returns the pixel map size of the wallpaper if the operation is successful; returns an error message otherwise.|

**Example**

  ```js
  wallpaper.getPixelMap(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data) => {
      console.info('wallpaperXTS ===> testGetPixelMapPromiseSystem data : ' + data);
      console.info('wallpaperXTS ===> testGetPixelMapPromiseSystem data : ' + JSON.stringify(data));
  }).catch((err) => {
      console.info('wallpaperXTS ===> testGetPixelMapPromiseSystem err : ' + err);
      console.info('wallpaperXTS ===> testGetPixelMapPromiseSystem err : ' + JSON.stringify(err));
  });
  ```


## wallpaper.getImage<sup>9+</sup>

getImage(wallpaperType: WallpaperType, callback: AsyncCallback&lt;image.PixelMap&gt;): void;

Obtains the pixel map for the wallpaper of the specified type. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | Yes| Wallpaper type.|
| callback | AsyncCallback&lt;[image.PixelMap](js-apis-image.md#pixelmap7)&gt; | Yes| Callback used to return the result. Returns the pixel map size of the wallpaper if the operation is successful; returns an error message otherwise.|

**Example**

  ```js
  wallpaper.getImage(wallpaper.WallpaperType.WALLPAPER_SYSTEM, function (err, data) {
      console.info('wallpaperXTS ===> testgetImageCallbackSystem err : ' + JSON.stringify(err));
      console.info('wallpaperXTS ===> testgetImageCallbackSystem data : ' + JSON.stringify(data));
  });
  ```


## wallpaper.getImage<sup>9+</sup>

getImage(wallpaperType: WallpaperType): Promise&lt;image.PixelMap&gt;

Obtains the pixel map for the wallpaper of the specified type. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wallpaperType | [WallpaperType](#wallpapertype) | Yes| Wallpaper type.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[image.PixelMap](js-apis-image.md#pixelmap7)&gt; | Promise used to return the result. Returns the pixel map size of the wallpaper if the operation is successful; returns an error message otherwise.|

**Example**

  ```js
  wallpaper.getImage(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data) => {
      console.info('wallpaperXTS ===> testgetImagePromiseSystem data : ' + data);
      console.info('wallpaperXTS ===> testgetImagePromiseSystem data : ' + JSON.stringify(data));
  }).catch((err) => {
      console.info('wallpaperXTS ===> testgetImagePromiseSystem err : ' + err);
      console.info('wallpaperXTS ===> testgetImagePromiseSystem err : ' + JSON.stringify(err));
  });
  ```


## wallpaper.on('colorChange')<sup>9+</sup>

on(type: 'colorChange', callback: (colors: Array&lt;RgbaColor&gt;, wallpaperType: WallpaperType) =&gt; void): void

Subscribes to the wallpaper color change event.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Type of the event to subscribe to. The value **'colorChange'** indicates subscribing to the wallpaper color change event.|
| callback | function | Yes| Callback triggered when the wallpaper color changes. The wallpaper type and main colors are returned.<br>- colors<br>Main color information of the wallpaper. For details, see [RgbaColor](#rgbacolor).<br>- wallpaperType<br>Wallpaper type.|

**Example**

  ```js
  let listener = (colors, wallpaperType) => {
      console.log(`wallpaper color changed.`);
  };
  wallpaper.on('colorChange', listener);
  ```


## wallpaper.off('colorChange')<sup>9+</sup>

off(type: 'colorChange', callback?: (colors: Array&lt;RgbaColor&gt;, wallpaperType: WallpaperType) =&gt; void): void

Unsubscribes from the wallpaper color change event.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Type of the event to unsubscribe from. The value **colorChange** indicates unsubscribing from the wallpaper color change event.|
| callback | function | No| Callback for the wallpaper color change event. If this parameter is not specified, all callbacks corresponding to the wallpaper color change event are invoked.<br>- colors<br>Main color information of the wallpaper. For details, see [RgbaColor](#rgbacolor).<br>- wallpaperType<br>Wallpaper type.|

**Example**

  ```js
  let listener = (colors, wallpaperType) => {
      console.log(`wallpaper color changed.`);
  };
  wallpaper.on('colorChange', listener);
  // Unsubscribe from the listener.
  wallpaper.off('colorChange', listener);
  // Unsubscribe from all subscriptions of the colorChange type.
  wallpaper.off('colorChange');
  ```


## RgbaColor

**System capability**: SystemCapability.MiscServices.Wallpaper

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| red | number | Yes| Yes| Red color. The value ranges from 0 to 255.|
| green | number | Yes| Yes| Green color. The value ranges from 0 to 255.|
| blue | number | Yes| Yes| Blue color. The value ranges from 0 to 255.|
| alpha | number | Yes| Yes| Alpha value. The value ranges from 0 to 255.|
