# 主题框架子系统-壁纸管理服务ChangeLog


## cl.wallpaper.1  getColorsSync、getMinHeightSync、getMinWidthSync、restore、setImage接口使用权限变更
从API9开始，变更为systemapi，停止对三方应用开放。

开发者需要根据以下说明对应用进行适配。

**变更影响**

基于此前版本开发的应用，需适配变更的js接口，变更前的接口已经不能正常使用了，否则会影响原有功能。

- 涉及接口

```js
    function getColorsSync(wallpaperType: WallpaperType): Array<RgbaColor>;
    function getMinHeightSync(): number;
    function getMinWidthSync(): number;
    function restore(wallpaperType: WallpaperType, callback: AsyncCallback<void>): void;
    function restore(wallpaperType: WallpaperType): Promise<void>;
    function setImage(source: string | image.PixelMap, wallpaperType: WallpaperType, callback: AsyncCallback<void>): void;
    function setImage(source: string | image.PixelMap, wallpaperType: WallpaperType): Promise<void>;
```

- 变更前：

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

- 变更后：

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


**适配指导**

该接口变更为系统应用后，三方应用已无法使用。
系统应用可正常使用。
示例代码如下：

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
    // source类型为string
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
    // source类型为string
    let wallpaperPath = "/data/data/ohos.acts.aafwk.plrdtest.form/files/Cup_ic.jpg";
    wallpaper.setImage(wallpaperPath, wallpaper.WallpaperType.WALLPAPER_SYSTEM).then(() => {
        console.log(`success to setImage.`);
    }).catch((error) => {
        console.error(`failed to setImage because: ${JSON.stringify(error)}`);
    });
```


## cl.wallpaper.2  getIdSync、getFileSync、isChangeAllowed、isUserChangeAllowed、on、off、RgbaColor接口废弃变更
从API9开始，废弃此接口。

开发者需要根据以下说明对应用进行适配。

**变更影响**

该接口删除无法再使用，请使用进行更新使用，否则会影响原有功能。

- 涉及接口

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

- 变更前：

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

- 变更后：删除接口，停止对外开放。


**适配指导**

该接口删除后无法再使用，请适配更新。
