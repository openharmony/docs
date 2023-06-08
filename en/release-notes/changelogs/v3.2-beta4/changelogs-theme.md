# Theme Framework ChangeLog

## cl.theme.1 Support of Exception Handling for APIs in API Version 9

The internal APIs of the following modules used service logic return values to indicate error information, which did not comply with the error code specifications of OpenHarmony. Therefore, they are modified in API version 9 and later.
 - Wallpaper management service: **@ohos.wallpaper.d.ts**

 - Lock screen management service: **@ohos.screenLock.d.ts**

APIs in the preceding modules are changed as follows:
Synchronous API: An error message is returned via an exception.
Asynchronous API: A parameter check error is returned synchronously. A service logic error is returned via **AsyncCallback** or the **error** object of **Promise**.

**Change Impacts**

The application developed based on earlier versions needs to adapt the method for returning API error information. Otherwise, the original service logic will be affected.

**Key API/Component Changes**

Deprecated APIs of the wallpaper management service:
   - getColors(wallpaperType: WallpaperType, callback: AsyncCallback<Array<RgbaColor>>): void;
   - getColors(wallpaperType: WallpaperType): Promise<Array<RgbaColor>>;
   - getId(wallpaperType: WallpaperType, callback: AsyncCallback<number>): void;
   - getId(wallpaperType: WallpaperType): Promise<number>;
   - getMinHeight(callback: AsyncCallback<number>): void;
   - getMinHeight(): Promise<number>;
   - getMinWidth(callback: AsyncCallback<number>): void;
   - getMinWidth(): Promise<number>;
   - isChangePermitted(callback: AsyncCallback<boolean>): void;
   - isChangePermitted(): Promise<boolean>;
   - isOperationAllowed(callback: AsyncCallback<boolean>): void;
   - isOperationAllowed(): Promise<boolean>;
   - reset(wallpaperType: WallpaperType, callback: AsyncCallback<void>): void;
   - reset(wallpaperType: WallpaperType): Promise<void>;
   - setWallpaper(source: string | image.PixelMap, wallpaperType: WallpaperType, callback: AsyncCallback<void>): void;
   - setWallpaper(source: string | image.PixelMap, wallpaperType: WallpaperType): Promise<void>;
   - getFile(wallpaperType: WallpaperType, callback: AsyncCallback<number>): void;
   - getFile(wallpaperType: WallpaperType): Promise<number>;
   - getPixelMap(wallpaperType: WallpaperType, callback: AsyncCallback<image.PixelMap>): void;
   - getPixelMap(wallpaperType: WallpaperType): Promise<image.PixelMap>;

Substitute APIs of the wallpaper management service:
   - getColorsSync(wallpaperType: WallpaperType): Array<RgbaColor>;
   - getIdSync(wallpaperType: WallpaperType): number;
   - getMinHeightSync(): number;
   - getMinWidthSync(): number;
   - isChangeAllowed(): boolean;
   - isUserChangeAllowed(): boolean;
   - restore(wallpaperType: WallpaperType, callback: AsyncCallback<void>): void;
   - restore(wallpaperType: WallpaperType): Promise<void>;
   - setImage(source: string | image.PixelMap, wallpaperType: WallpaperType, callback: AsyncCallback<void>): void;
   - setImage(source: string | image.PixelMap, wallpaperType: WallpaperType): Promise<void>;
   - getFileSync(wallpaperType: WallpaperType): number;
   - getImage(wallpaperType: WallpaperType, callback: AsyncCallback<image.PixelMap>): void;
   - getImage(wallpaperType: WallpaperType): Promise<image.PixelMap>;

Changed APIs of the wallpaper management service:
   - on(type: 'colorChange', callback: (colors: Array<RgbaColor>, wallpaperType: WallpaperType) => void): void
   - off(type: 'colorChange', callback?: (colors: Array<RgbaColor>, wallpaperType: WallpaperType) => void): void

Deprecated APIs of the lock screen management service:
   - isScreenLocked(callback: AsyncCallback<boolean>): void;
   - isScreenLocked(): Promise<boolean>;
   - isSecureMode(callback: AsyncCallback<boolean>): void;
   - isSecureMode(): Promise<boolean>;
   - unlockScreen(callback: AsyncCallback<void>): void;
   - unlockScreen(): Promise<void>;

Substitute APIs of the lock screen management service:
   - isLocked(): boolean;
   - isSecure(): boolean;
   - unlock(callback: AsyncCallback<boolean>): void;
   - unlock():Promise<boolean>;

Deleted APIs of the lock screen management service:
   - lockScreen(callback: AsyncCallback<void>): void;
   - lockScreen(): Promise<void>;

The following APIs are added for the lock screen management service:
   - lock(callback: AsyncCallback<boolean>): void;
   - lock():Promise<boolean>;

Changed APIs of the lock screen management service:
   - onSystemEvent(callback: Callback<SystemEvent>): boolean;
   - sendScreenLockEvent(event: String, parameter: number, callback: AsyncCallback<boolean>): void;
   - sendScreenLockEvent(event: String, parameter: number): Promise<boolean>;

**Adaption Guide for the Wallpaper Management Service**

The following uses **getImage** as an example for asynchronous APIs:

```ts
import pointer from '@ohos.wallpaper';
try {
    wallpaper.getImage(wallpaper.WallpaperType.WALLPAPER_SYSTEM).then((data) => {
        console.log(`success to getImage: ${JSON.stringify(data)}`);
    }).catch((error) => {
        console.error(`failed to getImage because: ${JSON.stringify(error)}`);
    });
} catch (err) {
    console.error(`failed to getImage because: ${JSON.stringify(err)}`);
}

```

The following uses **getFileSync** as an example for synchronous APIs:

```ts
import pointer from '@ohos.wallpaper';
try {
    let file = wallpaper.getFileSync(wallpaper.WallpaperType.WALLPAPER_SYSTEM);
} catch (err) {
    console.error(`failed to getFileSync because: ${err.message}`);
}
```

**Adaption Guide for the Lock Screen Management Service**

The following uses **lock** as an example for asynchronous APIs:

```ts
import screenLock from '@ohos.screenlock';
try {
  screenLock.lock((err, data) => {      
    if (err) {
        console.error(`Failed to lock the screen, because: ${err.message}`);
        return;    
    }
    console.info(`lock the screen successfully. result: ${data}`);
  });
} catch (err) {
    console.error(`Failed to lock the screen, because: ${err.message}`);
}

```

The following uses **onSystemEvent** as an example for synchronous APIs:

```ts
import screenLock from '@ohos.screenlock';
try {
   let isSuccess = screenLock.onSystemEvent((event) => {
       console.log(`Register the system event which related to screenlock successfully. eventType: ${event.eventType}`)
   });
} catch (err) {
   console.error(`Failed to register the system event which related to screenlock, because: ${err.message}`)
}
```
