# Theme Framework Subsystem – Wallpaper Management Service Changelog


## cl.wallpaper.1 Permission Change of getColorsSync, getMinHeightSync, getMinWidthSync, restore, and setImage
Changed the **getColorsSync**, **getMinHeightSync**, **getMinWidthSync**, restore, and **setImage** APIs to system APIs since API version 9.

You need to adapt your application based on the following information.

**Change Impact**

The JS API needs to be adapted for applications developed based on earlier versions. Otherwise, relevant functions will be affected.

- Involved APIs:

```js
    function getColorsSync(wallpaperType: WallpaperType): Array<RgbaColor>;
    function getMinHeightSync(): number;
    function getMinWidthSync(): number;
    function restore(wallpaperType: WallpaperType, callback: AsyncCallback<void>): void;
    function restore(wallpaperType: WallpaperType): Promise<void>;
    function setImage(source: string | image.PixelMap, wallpaperType: WallpaperType, callback: AsyncCallback<void>): void;
    function setImage(source: string | image.PixelMap, wallpaperType: WallpaperType): Promise<void>;
```

- Before change:

```js
    /**
     * Obtains the wallpaper colors for the wallpaper of the specified type. Returns rgbaColor type of array callback function.
     * @param wallpaperType Indicates the wallpaper type.
     * @returns { Array<RgbaColor> } the Array<RgbaColor> returned by the function.
     * @throws {BusinessError} 401 - parameter error.
     * @throws {BusinessError} 202 - permission verification failed, application which is not a system application uses system API.
     * @syscap SystemCapability.MiscServices.Wallpaper
     * @systemapi Hide this for inner system use.
     * @since 9
     */
    function getColorsSync(wallpaperType: WallpaperType): Array<RgbaColor>;

    /**
     * Obtains the minimum height of the wallpaper. in pixels. returns 0 if no wallpaper has been set.
     * @returns { number } the number returned by the function.
     * @throws {BusinessError} 202 - permission verification failed, application which is not a system application uses system API.
     * @syscap SystemCapability.MiscServices.Wallpaper
     * @systemapi Hide this for inner system use.
     * @since 9
     */
    function getMinHeightSync(): number;

    /**
     * Obtains the minimum width of the wallpaper. in pixels. returns 0 if no wallpaper has been set.
     * @returns { number } the number returned by the function.
     * @throws {BusinessError} 202 - permission verification failed, application which is not a system application uses system API.
     * @syscap SystemCapability.MiscServices.Wallpaper
     * @systemapi Hide this for inner system use.
     * @since 9
     */
    function getMinWidthSync(): number;

    /**
     * Removes a wallpaper of the specified type and restores the default one.
     * @param wallpaperType Indicates the wallpaper type.
     * @throws {BusinessError} 401 - parameter error.
     * @throws {BusinessError} 201 - permission denied.
     * @throws {BusinessError} 202 - permission verification failed, application which is not a system application uses system API.
     * @permission ohos.permission.SET_WALLPAPER
     * @syscap SystemCapability.MiscServices.Wallpaper
     * @systemapi Hide this for inner system use.
     * @since 9
     */
    function restore(wallpaperType: WallpaperType, callback: AsyncCallback<void>): void;

    /**
     * Removes a wallpaper of the specified type and restores the default one.
     * @param wallpaperType Indicates the wallpaper type.
     * @throws {BusinessError} 401 - parameter error.
     * @throws {BusinessError} 201 - permission denied.
     * @throws {BusinessError} 202 - permission verification failed, application which is not a system application uses system API.
     * @permission ohos.permission.SET_WALLPAPER
     * @syscap SystemCapability.MiscServices.Wallpaper
     * @systemapi Hide this for inner system use.
     * @since 9
     */
    function restore(wallpaperType: WallpaperType): Promise<void>;
  
    /**
     * Sets a wallpaper of the specified type based on the uri path from a JPEG or PNG file or the pixel map of a PNG file.
     * @param source Indicates the uri path from a JPEG or PNG file or the pixel map of the PNG file.
     * @param wallpaperType Indicates the wallpaper type.
     * @throws {BusinessError} 401 - parameter error.
     * @throws {BusinessError} 201 - permission denied.
     * @throws {BusinessError} 202 - permission verification failed, application which is not a system application uses system API.
     * @permission ohos.permission.SET_WALLPAPER
     * @syscap SystemCapability.MiscServices.Wallpaper
     * @systemapi Hide this for inner system use.
     * @since 9
     */
    function setImage(source: string | image.PixelMap, wallpaperType: WallpaperType, callback: AsyncCallback<void>): void;

    /**
     * Sets a wallpaper of the specified type based on the uri path from a JPEG or PNG file or the pixel map of a PNG file.
     * @param source Indicates the uri path from a JPEG or PNG file or the pixel map of the PNG file.
     * @param wallpaperType Indicates the wallpaper type.
     * @throws {BusinessError} 401 - parameter error.
     * @throws {BusinessError} 201 - permission denied.
     * @throws {BusinessError} 202 - permission verification failed, application which is not a system application uses system API.
     * @permission ohos.permission.SET_WALLPAPER
     * @syscap SystemCapability.MiscServices.Wallpaper
     * @systemapi Hide this for inner system use.
     * @since 9
     */
    function setImage(source: string | image.PixelMap, wallpaperType: WallpaperType): Promise<void>;
```

- After change:

```js
    /**
     * Obtains the wallpaper colors for the wallpaper of the specified type. Returns rgbaColor type of array callback function.
     * @param wallpaperType Indicates the wallpaper type.
     * @returns { Array<RgbaColor> } the Array<RgbaColor> returned by the function.
     * @throws {BusinessError} 401 - parameter error.
     * @syscap SystemCapability.MiscServices.Wallpaper
     * @since 9
     */
    function getColorsSync(wallpaperType: WallpaperType): Array<RgbaColor>;

    /**
     * Obtains the minimum height of the wallpaper. in pixels. returns 0 if no wallpaper has been set.
     * @returns { number } the number returned by the function.
     * @syscap SystemCapability.MiscServices.Wallpaper
     * @since 9
     */
    function getMinHeightSync(): number;

    /**
     * Obtains the minimum width of the wallpaper. in pixels. returns 0 if no wallpaper has been set.
     * @returns { number } the number returned by the function.
     * @syscap SystemCapability.MiscServices.Wallpaper
     * @since 9
     */
    function getMinWidthSync(): number;

    /**
     * Removes a wallpaper of the specified type and restores the default one.
     * @param wallpaperType Indicates the wallpaper type.
     * @throws {BusinessError} 401 - parameter error.
     * @throws {BusinessError} 201 - permission denied.
     * @permission ohos.permission.SET_WALLPAPER
     * @syscap SystemCapability.MiscServices.Wallpaper
     * @since 9
     */
    function restore(wallpaperType: WallpaperType, callback: AsyncCallback<void>): void;

    /**
     * Removes a wallpaper of the specified type and restores the default one.
     * @param wallpaperType Indicates the wallpaper type.
     * @throws {BusinessError} 401 - parameter error.
     * @throws {BusinessError} 201 - permission denied.
     * @permission ohos.permission.SET_WALLPAPER
     * @syscap SystemCapability.MiscServices.Wallpaper
     * @since 9
     */
    function restore(wallpaperType: WallpaperType): Promise<void>;
  
    /**
     * Sets a wallpaper of the specified type based on the uri path from a JPEG or PNG file or the pixel map of a PNG file.
     * @param source Indicates the uri path from a JPEG or PNG file or the pixel map of the PNG file.
     * @param wallpaperType Indicates the wallpaper type.
     * @throws {BusinessError} 401 - parameter error.
     * @throws {BusinessError} 201 - permission denied.
     * @permission ohos.permission.SET_WALLPAPER
     * @syscap SystemCapability.MiscServices.Wallpaper
     * @since 9
     */
    function setImage(source: string | image.PixelMap, wallpaperType: WallpaperType, callback: AsyncCallback<void>): void;

    /**
     * Sets a wallpaper of the specified type based on the uri path from a JPEG or PNG file or the pixel map of a PNG file.
     * @param source Indicates the uri path from a JPEG or PNG file or the pixel map of the PNG file.
     * @param wallpaperType Indicates the wallpaper type.
     * @throws {BusinessError} 401 - parameter error.
     * @throws {BusinessError} 201 - permission denied.
     * @permission ohos.permission.SET_WALLPAPER
     * @syscap SystemCapability.MiscServices.Wallpaper
     * @since 9
     */
    function setImage(source: string | image.PixelMap, wallpaperType: WallpaperType): Promise<void>;
```


**Adaptation Guide**

Make sure the APIs are only invoked by system applications.

The code snippet is as follows:

```js
    try {
        let colors = wallpaper.getColorsSync(wallpaper.WallpaperType.WALLPAPER_SYSTEM);
        console.log(`success to getColorsSync: ${JSON.stringify(colors)}`);
    } catch (error) {
        console.error(`failed to getColorsSync because: ${JSON.stringify(error)}`);
    }
```

```js
    let minHeight = wallpaper.getMinHeightSync();
```

```js
    let minWidth = wallpaper.getMinWidthSync();
```

```js
    wallpaper.restore(wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error) => {
        if (error) {
            console.error(`failed to restore because: ${JSON.stringify(error)}`);
            return;
        }
        console.log(`success to restore.`);
    });
```

```js
    wallpaper.restore(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then(() => {
        console.log(`success to restore.`);
      }).catch((error) => {
        console.error(`failed to restore because: ${JSON.stringify(error)}`);
    });
```

```js
    // The source type is string.
    let wallpaperPath = "/data/data/ohos.acts.aafwk.plrdtest.form/files/Cup_ic.jpg";
    wallpaper.setImage(wallpaperPath, wallpaper.WallpaperType.WALLPAPER_SYSTEM, (error) => {
        if (error) {
            console.error(`failed to setImage because: ${JSON.stringify(error)}`);
            return;
        }
        console.log(`success to setImage.`);
    });
```

```js
    // The source type is string.
    let wallpaperPath = "/data/data/ohos.acts.aafwk.plrdtest.form/files/Cup_ic.jpg";
    wallpaper.setImage(wallpaperPath, wallpaper.WallpaperType.WALLPAPER_SYSTEM).then(() => {
        console.log(`success to setImage.`);
    }).catch((error) => {
        console.error(`failed to setImage because: ${JSON.stringify(error)}`);
    });
```


## cl.wallpaper.2 Deprecation of getIdSync, getFileSync, isChangeAllowed, isUserChangeAllowed, on, off, and RgbaColor
Deprecated the **getIdSync**, **getFileSync**, **isChangeAllowed**, **isUserChangeAllowed**, **on**, **off**, and **RgbaColor** APIs since API version 9.

You need to adapt your application based on the following information.

**Change Impact**

The APIs can no longer be used after being deleted.

- Involved APIs:

```js
    function getIdSync(wallpaperType: WallpaperType): number;
    function getFileSync(wallpaperType: WallpaperType): number;
    function isChangeAllowed(): boolean;
    function isUserChangeAllowed(): boolean;
    function on(type: 'colorChange', callback: (colors: Array<RgbaColor>, wallpaperType: WallpaperType) => void): void;
    function off(type: 'colorChange', callback?: (colors: Array<RgbaColor>, wallpaperType: WallpaperType) => void): void;
    interface RgbaColor {
        red: number;
        green: number;
        blue: number;
        alpha: number;
        }
```

- Before change:

```js
    function getIdSync(wallpaperType: WallpaperType): number;
    function getFileSync(wallpaperType: WallpaperType): number;
    function isChangeAllowed(): boolean;
    function isUserChangeAllowed(): boolean;
    function on(type: 'colorChange', callback: (colors: Array<RgbaColor>, wallpaperType: WallpaperType) => void): void;
    function off(type: 'colorChange', callback?: (colors: Array<RgbaColor>, wallpaperType: WallpaperType) => void): void;
    interface RgbaColor {
        red: number;
        green: number;
        blue: number;
        alpha: number;
        }
```

- After change:

  The APIs are deleted.


**Adaptation Guide**

Update the code so that the deprecated APIs are not used.
