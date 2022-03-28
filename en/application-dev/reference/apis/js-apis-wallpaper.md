# Wallpaper


> ![icon-note.gif](public_sys-resources/icon-note.gif) **Note：**
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```
import wallpaper from '@ohos.wallpaper';
```


## WallpaperType

Defines the wallpaper type.

**System capability**: SystemCapability.MiscServices.Wallpaper

| Name | Description |
| -------- | -------- |
| WALLPAPER_LOCKSCREEN | Lock&nbsp;screen&nbsp;wallpaper. |
| WALLPAPER_SYSTEM | Home&nbsp;screen&nbsp;wallpaper. |


## wallpaper.getColors

getColors(wallpaperType: WallpaperType, callback: AsyncCallback&lt;Array&lt;RgbaColor&gt;&gt;): void

Obtains the main color information of the wallpaper of a specified type.

**System capability**: SystemCapability.MiscServices.Wallpaper

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | wallpaperType | [WallpaperType](#wallpapertype) | Yes | Wallpaper&nbsp;type. |
  | callback | AsyncCallback&lt;Array&lt;[RgbaColor](#rgbacolor)&gt;&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;main&nbsp;color&nbsp;information&nbsp;of&nbsp;the&nbsp;wallpaper. |

- Example
  
  ```
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

Obtains the main color information of the wallpaper of a specified type.

**System capability**: SystemCapability.MiscServices.Wallpaper

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | wallpaperType | [WallpaperType](#wallpapertype) | Yes | Wallpaper&nbsp;type. |

- Return values
    | Type | Description |
  | -------- | -------- |
  | Promise&lt;Array&lt;[RgbaColor](#rgbacolor)&gt;&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;main&nbsp;color&nbsp;information&nbsp;of&nbsp;the&nbsp;wallpaper. |

- Example
  
  ```
  wallpaper.getColors(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data) => {
      console.log(`success to getColors.`);
  }).catch((error) => {
      console.error(`failed to getColors because: ` + JSON.stringify(error));
  });
  ```


## wallpaper.getId

getId(wallpaperType: WallpaperType, callback: AsyncCallback&lt;number&gt;): void

Obtains the ID of the wallpaper of the specified type.

**System capability**: SystemCapability.MiscServices.Wallpaper

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | wallpaperType | [WallpaperType](#wallpapertype) | Yes | Wallpaper&nbsp;type. |
  | callback | AsyncCallback&lt;number&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;wallpaper&nbsp;ID.&nbsp;If&nbsp;the&nbsp;wallpaper&nbsp;of&nbsp;the&nbsp;specified&nbsp;type&nbsp;is&nbsp;configured,&nbsp;a&nbsp;number&nbsp;greater&nbsp;than&nbsp;or&nbsp;equal&nbsp;to&nbsp;**0**&nbsp;is&nbsp;returned.&nbsp;Otherwise,&nbsp;**-1**&nbsp;is&nbsp;returned.&nbsp;The&nbsp;value&nbsp;ranges&nbsp;from&nbsp;-1&nbsp;to&nbsp;2^31-1. |

- Example
  
  ```
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

Obtains the ID of the wallpaper of the specified type.

**System capability**: SystemCapability.MiscServices.Wallpaper


- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | wallpaperType | [WallpaperType](#wallpapertype) | Yes | Wallpaper&nbsp;type. |

- Return values
    | Type | Description |
  | -------- | -------- |
  | Promise&lt;number&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;wallpaper&nbsp;ID.&nbsp;If&nbsp;this&nbsp;type&nbsp;of&nbsp;wallpaper&nbsp;is&nbsp;configured,&nbsp;a&nbsp;number&nbsp;greater&nbsp;than&nbsp;or&nbsp;equal&nbsp;to&nbsp;**0**&nbsp;is&nbsp;returned.&nbsp;Otherwise,&nbsp;**-1**&nbsp;is&nbsp;returned.&nbsp;The&nbsp;value&nbsp;ranges&nbsp;from&nbsp;-1&nbsp;to&nbsp;2^31-1. |

- Example
  
  ```
  wallpaper.getId(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data) => {
      console.log(`success to getId: ` + JSON.stringify(data));
  }).catch((error) => {
      console.error(`failed to getId because: ` + JSON.stringify(error));
  });
  ```


## wallpaper.getMinHeight

getMinHeight(callback: AsyncCallback&lt;number&gt;): void

Obtains the minimum height of the wallpaper.

**System capability**: SystemCapability.MiscServices.Wallpaper

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;number&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;minimum&nbsp;wallpaper&nbsp;height,&nbsp;in&nbsp;pixels.&nbsp;If&nbsp;the&nbsp;return&nbsp;value&nbsp;is&nbsp;**0**,&nbsp;no&nbsp;wallpaper&nbsp;is&nbsp;set.&nbsp;In&nbsp;this&nbsp;case,&nbsp;the&nbsp;default&nbsp;height&nbsp;should&nbsp;be&nbsp;used&nbsp;instead. |

- Example
  
  ```
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

Obtains the minimum height of the wallpaper.

**System capability**: SystemCapability.MiscServices.Wallpaper


- Return values
    | Type | Description |
  | -------- | -------- |
  | Promise&lt;number&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;minimum&nbsp;wallpaper&nbsp;height,&nbsp;in&nbsp;pixels.&nbsp;If&nbsp;the&nbsp;return&nbsp;value&nbsp;is&nbsp;**0**,&nbsp;no&nbsp;wallpaper&nbsp;is&nbsp;set.&nbsp;In&nbsp;this&nbsp;case,&nbsp;the&nbsp;default&nbsp;height&nbsp;should&nbsp;be&nbsp;used&nbsp;instead. |

- Example
  
  ```
  wallpaper.getMinHeight().then((data) => {
      console.log(`success to getMinHeight: ` + JSON.stringify(data));
  }).catch((error) => {
      console.error(`failed to getMinHeight because: ` + JSON.stringify(error));
  });
  ```


## wallpaper.getMinWidth

getMinWidth(callback: AsyncCallback&lt;number&gt;): void

Obtains the minimum width of the wallpaper.

**System capability**: SystemCapability.MiscServices.Wallpaper


- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;number&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;minimum&nbsp;wallpaper&nbsp;width,&nbsp;in&nbsp;pixels.&nbsp;If&nbsp;the&nbsp;return&nbsp;value&nbsp;is&nbsp;**0**,&nbsp;no&nbsp;wallpaper&nbsp;is&nbsp;set.&nbsp;In&nbsp;this&nbsp;case,&nbsp;the&nbsp;default&nbsp;width&nbsp;should&nbsp;be&nbsp;used&nbsp;instead. |

- Example
  
  ```
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

Obtains the minimum width of the wallpaper.

**System capability**: SystemCapability.MiscServices.Wallpaper

- Return values
    | Type | Description |
  | -------- | -------- |
  | Promise&lt;number&gt; | Promised&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;minimum&nbsp;wallpaper&nbsp;width,&nbsp;in&nbsp;pixels.&nbsp;If&nbsp;the&nbsp;return&nbsp;value&nbsp;is&nbsp;**0**,&nbsp;no&nbsp;wallpaper&nbsp;is&nbsp;set.&nbsp;In&nbsp;this&nbsp;case,&nbsp;the&nbsp;default&nbsp;width&nbsp;should&nbsp;be&nbsp;used&nbsp;instead. |

- Example
  
  ```
  wallpaper.getMinWidth().then((data) => {
      console.log(`success to getMinWidth: ` + JSON.stringify(data));
  }).catch((error) => {
      console.error(`failed to getMinWidth because: ` + JSON.stringify(error));
  });
  ```


## wallpaper.isChangePermitted

isChangePermitted(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether to allow the application to change the wallpaper for the current user.

**System capability**: SystemCapability.MiscServices.Wallpaper

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;queried&nbsp;result.&nbsp;Returns&nbsp;**true**&nbsp;if&nbsp;it&nbsp;is&nbsp;allowed;&nbsp;returns&nbsp;**false**&nbsp;otherwise. |

- Example
  
  ```
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

Checks whether to allow the application to change the wallpaper for the current user.

**System capability**: SystemCapability.MiscServices.Wallpaper

- Return values
    | Type | Description |
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;whether&nbsp;to&nbsp;allow&nbsp;the&nbsp;application&nbsp;to&nbsp;change&nbsp;the&nbsp;wallpaper&nbsp;for&nbsp;the&nbsp;current&nbsp;user.&nbsp;Returns&nbsp;**true**&nbsp;if&nbsp;it&nbsp;is&nbsp;allowed;&nbsp;returns&nbsp;**false**&nbsp;otherwise. |

- Example
  
  ```
  wallpaper.isChangePermitted().then((data) => {
      console.log(`success to isChangePermitted: ` + JSON.stringify(data));
  }).catch((error) => {
      console.error(`failed to isChangePermitted because: ` + JSON.stringify(error));
  });
  ```


## wallpaper.isOperationAllowed

isOperationAllowed(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether the user is allowed to set wallpapers.

**System capability**: SystemCapability.MiscServices.Wallpaper

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;whether&nbsp;the&nbsp;user&nbsp;is&nbsp;allowed&nbsp;to&nbsp;set&nbsp;wallpapers.&nbsp;Returns&nbsp;**true**&nbsp;if&nbsp;it&nbsp;is&nbsp;allowed;&nbsp;returns&nbsp;**false**&nbsp;otherwise. |

- Example
  
  ```
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

Checks whether the user is allowed to set wallpapers.

**System capability**: SystemCapability.MiscServices.Wallpaper

- Return values
    | Type | Description |
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;whether&nbsp;the&nbsp;user&nbsp;is&nbsp;allowed&nbsp;to&nbsp;set&nbsp;wallpapers.&nbsp;Returns&nbsp;**true**&nbsp;if&nbsp;it&nbsp;is&nbsp;allowed;&nbsp;returns&nbsp;**false**&nbsp;otherwise. |

- Example
  
  ```
  wallpaper.isOperationAllowed().then((data) => {
      console.log(`success to isOperationAllowed: ` + JSON.stringify(data));
  }).catch((error) => {
      console.error(`failed to isOperationAllowed because: ` + JSON.stringify(error));
  });
  ```


## wallpaper.reset

reset(wallpaperType: WallpaperType, callback: AsyncCallback&lt;void&gt;): void

Removes a wallpaper of the specified type and restores the default one.

**Required permission**: ohos.permission.SET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | wallpaperType | [WallpaperType](#wallpapertype) | Yes | Wallpaper&nbsp;type. |
  | callback | AsyncCallback&lt;void&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;result.&nbsp;If&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful,&nbsp;the&nbsp;result&nbsp;of&nbsp;removal&nbsp;is&nbsp;returned.&nbsp;Otherwise,&nbsp;error&nbsp;information&nbsp;is&nbsp;returned. |

- Example
  
  ```
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

Removes a wallpaper of the specified type and restores the default one.

**Required permission**: ohos.permission.SET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | wallpaperType | [WallpaperType](#wallpapertype) | Yes | Wallpaper&nbsp;type. |

- Return values
    | Type | Description |
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;result.&nbsp;If&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful,&nbsp;the&nbsp;result&nbsp;of&nbsp;removal&nbsp;is&nbsp;returned.&nbsp;Otherwise,&nbsp;error&nbsp;information&nbsp;is&nbsp;returned. |

- Example
  
  ```
  wallpaper.reset(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data) => {
      console.log(`success to reset.`);
  }).catch((error) => {
      console.error(`failed to reset because: ` + JSON.stringify(error));
  });
  ```


## wallpaper.setWallpaper

setWallpaper(source: string | image.PixelMap, wallpaperType: WallpaperType, callback: AsyncCallback&lt;void&gt;): void

Sets a specified source as the wallpaper of a specified type.

**Required permission**: ohos.permission.SET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | source | string&nbsp;\| [PixelMap](js-apis-image.md#pixelmap7) | Yes | Uri&nbsp;path&nbsp;of&nbsp;the&nbsp;JPEG&nbsp;or&nbsp;PNG&nbsp;file,&nbsp;or&nbsp;bitmap&nbsp;of&nbsp;the&nbsp;PNG&nbsp;file. |
  | wallpaperType | [WallpaperType](#wallpapertype) | Yes | Wallpaper&nbsp;type. |
  | callback | AsyncCallback&lt;void&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;result.&nbsp;If&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful,&nbsp;the&nbsp;setting&nbsp;result&nbsp;is&nbsp;returned.&nbsp;Otherwise,&nbsp;error&nbsp;information&nbsp;is&nbsp;returned. |

- Example
  
  ```
  //The source type is string.
  let wallpaperPath = "/data/data/ohos.acts.aafwk.plrdtest.form/files/Cup_ic.jpg";
  wallpaper.setWallpaper(wallpaperPath, wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error, data) => {   
      if (error) {        
          console.error(`failed to setWallpaper because: ` + JSON.stringify(error));       
          return;   
      }    
      console.log(`success to setWallpaper.`);
  });
  
  //The source type is image.PixelMap.
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

Sets a specified source as the wallpaper of a specified type.

**Required permission**: ohos.permission.SET_WALLPAPER

**System capability**: SystemCapability.MiscServices.Wallpaper

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | source | string&nbsp;\|&nbsp;[PixelMap](js-apis-image.md#pixelmap7) | Yes | Uri&nbsp;path&nbsp;of&nbsp;the&nbsp;JPEG&nbsp;or&nbsp;PNG&nbsp;file,&nbsp;or&nbsp;bitmap&nbsp;of&nbsp;the&nbsp;PNG&nbsp;file. |
  | wallpaperType | [WallpaperType](#wallpapertype) | Yes | Wallpaper&nbsp;type. |

- Return values
    | Type | Description |
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;result.&nbsp;If&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful,&nbsp;the&nbsp;setting&nbsp;result&nbsp;is&nbsp;returned.&nbsp;Otherwise,&nbsp;error&nbsp;information&nbsp;is&nbsp;returned. |

- Example
  
  ```
  //The source type is string.
  let wallpaperPath = "/data/data/ohos.acts.aafwk.plrdtest.form/files/Cup_ic.jpg";
  wallpaper.setWallpaper(wallpaperPath, wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data) => {
      console.log(`success to setWallpaper.`);
  }).catch((error) => {
      console.error(`failed to setWallpaper because: ` + JSON.stringify(error));
  });
  
  //The source type is image.PixelMap.
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

Obtains the wallpaper of the specified type.

**Required permissions**: ohos.permission.GET_WALLPAPER and ohos.permission.READ_USER_STORAGE

**System capability**: SystemCapability.MiscServices.Wallpaper

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | wallpaperType | [WallpaperType](#wallpapertype) | Yes | Wallpaper&nbsp;type. |
  | callback | AsyncCallback&lt;number&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;result.&nbsp;If&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful,&nbsp;the&nbsp;file&nbsp;descriptor&nbsp;ID&nbsp;to&nbsp;the&nbsp;wallpaper&nbsp;is&nbsp;returned.&nbsp;Otherwise,&nbsp;error&nbsp;information&nbsp;is&nbsp;returned. |

- Example
  
  ```
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

Obtains the wallpaper of the specified type.

**Required permissions**: ohos.permission.GET_WALLPAPER and ohos.permission.READ_USER_STORAGE

**System capability**: SystemCapability.MiscServices.Wallpaper

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | wallpaperType | [WallpaperType](#wallpapertype) | Yes | Wallpaper&nbsp;type. |

- Return values
    | Type | Description |
  | -------- | -------- |
  | Promise&lt;number&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;result.&nbsp;If&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful,&nbsp;the&nbsp;file&nbsp;descriptor&nbsp;ID&nbsp;to&nbsp;the&nbsp;wallpaper&nbsp;is&nbsp;returned.&nbsp;Otherwise,&nbsp;error&nbsp;information&nbsp;is&nbsp;returned. |

- Example
  
  ```
  wallpaper.getFile(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data) => {
      console.log(`success to getFile: ` + JSON.stringify(data));
  }).catch((error) => {
      console.error(`failed to getFile because: ` + JSON.stringify(error));
  });
  ```


## wallpaper.on('colorChange')

on(type: 'colorChange', callback: (colors: Array&lt;RgbaColor&gt;, wallpaperType: WallpaperType) =&gt; void): void

Subscribes to the wallpaper color change event.

**System capability**: SystemCapability.MiscServices.Wallpaper

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | type | string | Yes | Type&nbsp;of&nbsp;the&nbsp;event&nbsp;to&nbsp;subscribe&nbsp;to.&nbsp;The&nbsp;value&nbsp;**colorChange**&nbsp;indicates&nbsp;subscribing&nbsp;to&nbsp;the&nbsp;wallpaper&nbsp;color&nbsp;change&nbsp;event. |
  | callback | function | Yes | Callback&nbsp;triggered&nbsp;when&nbsp;the&nbsp;wallpaper&nbsp;color&nbsp;changes.&nbsp;The&nbsp;wallpaper&nbsp;type&nbsp;and&nbsp;main&nbsp;colors&nbsp;are&nbsp;returned.<br/>-&nbsp;colors<br/>&nbsp;&nbsp;Main&nbsp;color&nbsp;information&nbsp;of&nbsp;the&nbsp;wallpaper.&nbsp;For&nbsp;details,&nbsp;see&nbsp;[RgbaColor](#rgbacolor).<br/>-&nbsp;wallpaperType<br/>&nbsp;&nbsp;Wallpaper&nbsp;type. |

- Example
  
  ```
  let listener = (colors, wallpaperType) => {
      console.log(`wallpaper color changed.`);
  };
  wallpaper.on('colorChange', listener);
  ```


## wallpaper.off('colorChange')

off(type: 'colorChange', callback?: (colors: Array&lt;RgbaColor&gt;, wallpaperType: WallpaperType) =&gt; void): void

Unsubscribes from the wallpaper color change event.

**System capability**: SystemCapability.MiscServices.Wallpaper

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | type | string | Yes | Type&nbsp;of&nbsp;the&nbsp;event&nbsp;to&nbsp;unsubscribe&nbsp;from.&nbsp;The&nbsp;value&nbsp;**colorChange**&nbsp;indicates&nbsp;unsubscribing&nbsp;from&nbsp;the&nbsp;wallpaper&nbsp;color&nbsp;change&nbsp;event. |
  | callback | function | No | &nbsp;&nbsp;Callback&nbsp;for&nbsp;the&nbsp;wallpaper&nbsp;color&nbsp;change&nbsp;event.&nbsp;If&nbsp;this&nbsp;parameter&nbsp;is&nbsp;not&nbsp;specified,&nbsp;all&nbsp;callbacks&nbsp;corresponding&nbsp;to&nbsp;the&nbsp;wallpaper&nbsp;color&nbsp;change&nbsp;event&nbsp;are&nbsp;invoked.<br/>-&nbsp;colors<br/>&nbsp;&nbsp;Main&nbsp;color&nbsp;information&nbsp;of&nbsp;the&nbsp;wallpaper.&nbsp;For&nbsp;details,&nbsp;see&nbsp;[RgbaColor](#rgbacolor).<br/>-&nbsp;wallpaperType<br/>&nbsp;&nbsp;Wallpaper&nbsp;type. |

- Example
  
  ```
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
| red | number | Yes | Yes | Red&nbsp;color.&nbsp;The&nbsp;value&nbsp;ranges&nbsp;from&nbsp;0&nbsp;to&nbsp;255. |
| green | number | Yes | Yes | Green&nbsp;color.&nbsp;The&nbsp;value&nbsp;ranges&nbsp;from&nbsp;0&nbsp;to&nbsp;255. |
| blue | number | Yes | Yes | Blue&nbsp;color.&nbsp;The&nbsp;value&nbsp;ranges&nbsp;from&nbsp;0&nbsp;to&nbsp;255. |
| alpha | number | Yes | Yes | Alpha&nbsp;value.&nbsp;The&nbsp;value&nbsp;ranges&nbsp;from&nbsp;0&nbsp;to&nbsp;255. |
