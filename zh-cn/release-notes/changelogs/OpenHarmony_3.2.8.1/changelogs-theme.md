# 主题框架changeLog

## cl.theme.1 API9接口支持异常处理

下列模块内部接口使用业务逻辑返回值表示错误信息，不符合OpenHarmony接口错误码规范。在API9进行变更。
 - 壁纸管理服务：@ohos.wallpaper.d.ts

 - 锁屏管理服务：@ohos.screenLock.d.ts

以上模块中的接口变更为：
同步接口：通过抛出异常的方式返回错误信息。
异步接口：参数检查错误同步抛出，业务逻辑错误通过AsyncCallback或Promise的error对象抛出。

**变更影响**

基于此前版本开发的应用，需适配接口的错误信息返回方式，否则会影响原有业务逻辑。

**关键接口/组件变更**

以下标记为壁纸管理服务接口废除：
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
   
壁纸管理服务替代接口如下:
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

以下标记为壁纸管理服务接口变更：
   - on(type: 'colorChange', callback: (colors: Array<RgbaColor>, wallpaperType: WallpaperType) => void): void
   - off(type: 'colorChange', callback?: (colors: Array<RgbaColor>, wallpaperType: WallpaperType) => void): void

以下标记为锁屏管理服务接口废除：
   - isScreenLocked(callback: AsyncCallback<boolean>): void;
   - isScreenLocked(): Promise<boolean>;
   - isSecureMode(callback: AsyncCallback<boolean>): void;
   - isSecureMode(): Promise<boolean>;
   - unlockScreen(callback: AsyncCallback<void>): void;
   - unlockScreen(): Promise<void>;

锁屏管理服务替代接口如下:
   - isLocked(): boolean;
   - isSecure(): boolean;
   - unlock(callback: AsyncCallback<boolean>): void;
   - unlock():Promise<boolean>;
   
以下标记为锁屏管理服务接口删除：
   - lockScreen(callback: AsyncCallback<void>): void;
   - lockScreen(): Promise<void>;

以下标记为锁屏管理服务接口新增：
   - lock(callback: AsyncCallback<boolean>): void;
   - lock():Promise<boolean>;

以下标记为锁屏管理服务接口变更：
   - onSystemEvent(callback: Callback<SystemEvent>): boolean;
   - sendScreenLockEvent(event: String, parameter: number, callback: AsyncCallback<boolean>): void;
   - sendScreenLockEvent(event: String, parameter: number): Promise<boolean>;

**壁纸管理服务适配指导**

异步接口以getImage为例，示例代码如下：

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

同步接口以getFileSync为例，示例代码如下：

```ts
import pointer from '@ohos.wallpaper';
try {
    let file = wallpaper.getFileSync(wallpaper.WallpaperType.WALLPAPER_SYSTEM);
} catch (err) {
    console.error(`failed to getFileSync because: ${err.message}`);
}
```

**锁屏管理服务适配指导**

异步接口以lock为例，示例代码如下：

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

同步接口以onSystemEvent为例，示例代码如下：

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
