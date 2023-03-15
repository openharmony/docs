| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|方法名 or 属性名：onConnect<br>函数：onConnect(want: Want): void;|@ohos.application.WindowExtensionAbility.d.ts|
|新增|NA|方法名 or 属性名：onWindowReady<br>函数：onWindowReady(window: window.Window): void;|@ohos.application.WindowExtensionAbility.d.ts|
|新增|NA|方法名 or 属性名：save<br>函数：function save(options: ScreenshotOptions, callback: AsyncCallback<image.PixelMap>): void;|@ohos.screenshot.d.ts|
|新增|NA|方法名 or 属性名：save<br>函数：function save(callback: AsyncCallback<image.PixelMap>): void;|@ohos.screenshot.d.ts|
|新增|NA|模块名: ohos.window<br>类名: WindowProperties<br>方法名 or 属性名：id|@ohos.window.d.ts|
|新增|NA|模块名: ohos.window<br>类名: Configuration|@ohos.window.d.ts|
|新增|NA|模块名: ohos.window<br>类名: Configuration<br>方法名 or 属性名：name|@ohos.window.d.ts|
|新增|NA|模块名: ohos.window<br>类名: Configuration<br>方法名 or 属性名：windowType|@ohos.window.d.ts|
|新增|NA|模块名: ohos.window<br>类名: Configuration<br>方法名 or 属性名：ctx|@ohos.window.d.ts|
|新增|NA|模块名: ohos.window<br>类名: Configuration<br>方法名 or 属性名：displayId|@ohos.window.d.ts|
|新增|NA|模块名: ohos.window<br>类名: Configuration<br>方法名 or 属性名：parentId|@ohos.window.d.ts|
|新增|NA|方法名 or 属性名：create<br>函数：function create(ctx: BaseContext, id: string, type: WindowType): Promise<Window>;|@ohos.window.d.ts|
|新增|NA|方法名 or 属性名：create<br>函数：function create(ctx: BaseContext, id: string, type: WindowType, callback: AsyncCallback<Window>): void;|@ohos.window.d.ts|
|新增|NA|方法名 or 属性名：getTopWindow<br>函数：function getTopWindow(ctx: BaseContext): Promise<Window>;|@ohos.window.d.ts|
|新增|NA|方法名 or 属性名：getTopWindow<br>函数：function getTopWindow(ctx: BaseContext, callback: AsyncCallback<Window>): void;|@ohos.window.d.ts|
|新增|NA|方法名 or 属性名：bindDialogTarget<br>函数：bindDialogTarget(token: rpc.RemoteObject, deathCallback: Callback<void>, callback: AsyncCallback<void>): void;|@ohos.window.d.ts|
|新增|NA|模块名: ohos.window<br>类名: WindowStage<br>方法名 or 属性名：getMainWindowSync|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：getDefaultDisplay<br>废弃版本：N/A|方法名 or 属性名：getDefaultDisplay<br>废弃版本：9<br>代替接口：ohos.display|@ohos.display.d.ts|
|废弃版本有变化|方法名 or 属性名：getDefaultDisplay<br>废弃版本：N/A|方法名 or 属性名：getDefaultDisplay<br>废弃版本：9<br>代替接口：ohos.display|@ohos.display.d.ts|
|废弃版本有变化|方法名 or 属性名：getAllDisplay<br>废弃版本：N/A|方法名 or 属性名：getAllDisplay<br>废弃版本：9<br>代替接口：ohos.display|@ohos.display.d.ts|
|废弃版本有变化|方法名 or 属性名：getAllDisplay<br>废弃版本：N/A|方法名 or 属性名：getAllDisplay<br>废弃版本：9<br>代替接口：ohos.display|@ohos.display.d.ts|
|废弃版本有变化|方法名 or 属性名：create<br>废弃版本：N/A|方法名 or 属性名：create<br>废弃版本：9<br>代替接口：ohos.window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：create<br>废弃版本：N/A|方法名 or 属性名：create<br>废弃版本：9<br>代替接口：ohos.window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：find<br>废弃版本：N/A|方法名 or 属性名：find<br>废弃版本：9<br>代替接口：ohos.window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：find<br>废弃版本：N/A|方法名 or 属性名：find<br>废弃版本：9<br>代替接口：ohos.window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：getTopWindow<br>废弃版本：N/A|方法名 or 属性名：getTopWindow<br>废弃版本：9<br>代替接口：ohos.window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：getTopWindow<br>废弃版本：N/A|方法名 or 属性名：getTopWindow<br>废弃版本：9<br>代替接口：ohos.window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：show<br>废弃版本：N/A|方法名 or 属性名：show<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：show<br>废弃版本：N/A|方法名 or 属性名：show<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：destroy<br>废弃版本：N/A|方法名 or 属性名：destroy<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：destroy<br>废弃版本：N/A|方法名 or 属性名：destroy<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：moveTo<br>废弃版本：N/A|方法名 or 属性名：moveTo<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：moveTo<br>废弃版本：N/A|方法名 or 属性名：moveTo<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：resetSize<br>废弃版本：N/A|方法名 or 属性名：resetSize<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：resetSize<br>废弃版本：N/A|方法名 or 属性名：resetSize<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：getProperties<br>废弃版本：N/A|方法名 or 属性名：getProperties<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：getProperties<br>废弃版本：N/A|方法名 or 属性名：getProperties<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：getAvoidArea<br>废弃版本：N/A|方法名 or 属性名：getAvoidArea<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：getAvoidArea<br>废弃版本：N/A|方法名 or 属性名：getAvoidArea<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：setFullScreen<br>废弃版本：N/A|方法名 or 属性名：setFullScreen<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：setFullScreen<br>废弃版本：N/A|方法名 or 属性名：setFullScreen<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：setLayoutFullScreen<br>废弃版本：N/A|方法名 or 属性名：setLayoutFullScreen<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：setLayoutFullScreen<br>废弃版本：N/A|方法名 or 属性名：setLayoutFullScreen<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：setSystemBarEnable<br>废弃版本：N/A|方法名 or 属性名：setSystemBarEnable<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：setSystemBarEnable<br>废弃版本：N/A|方法名 or 属性名：setSystemBarEnable<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：setSystemBarProperties<br>废弃版本：N/A|方法名 or 属性名：setSystemBarProperties<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：setSystemBarProperties<br>废弃版本：N/A|方法名 or 属性名：setSystemBarProperties<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：loadContent<br>废弃版本：N/A|方法名 or 属性名：loadContent<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：loadContent<br>废弃版本：N/A|方法名 or 属性名：loadContent<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：isShowing<br>废弃版本：N/A|方法名 or 属性名：isShowing<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：isShowing<br>废弃版本：N/A|方法名 or 属性名：isShowing<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：isSupportWideGamut<br>废弃版本：N/A|方法名 or 属性名：isSupportWideGamut<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：isSupportWideGamut<br>废弃版本：N/A|方法名 or 属性名：isSupportWideGamut<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：setColorSpace<br>废弃版本：N/A|方法名 or 属性名：setColorSpace<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：setColorSpace<br>废弃版本：N/A|方法名 or 属性名：setColorSpace<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：getColorSpace<br>废弃版本：N/A|方法名 or 属性名：getColorSpace<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：getColorSpace<br>废弃版本：N/A|方法名 or 属性名：getColorSpace<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：setBackgroundColor<br>废弃版本：N/A|方法名 or 属性名：setBackgroundColor<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：setBackgroundColor<br>废弃版本：N/A|方法名 or 属性名：setBackgroundColor<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：setBrightness<br>废弃版本：N/A|方法名 or 属性名：setBrightness<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：setBrightness<br>废弃版本：N/A|方法名 or 属性名：setBrightness<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：setFocusable<br>废弃版本：N/A|方法名 or 属性名：setFocusable<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：setFocusable<br>废弃版本：N/A|方法名 or 属性名：setFocusable<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：setKeepScreenOn<br>废弃版本：N/A|方法名 or 属性名：setKeepScreenOn<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：setKeepScreenOn<br>废弃版本：N/A|方法名 or 属性名：setKeepScreenOn<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：setPrivacyMode<br>废弃版本：N/A|方法名 or 属性名：setPrivacyMode<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：setPrivacyMode<br>废弃版本：N/A|方法名 or 属性名：setPrivacyMode<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：setTouchable<br>废弃版本：N/A|方法名 or 属性名：setTouchable<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|废弃版本有变化|方法名 or 属性名：setTouchable<br>废弃版本：N/A|方法名 or 属性名：setTouchable<br>废弃版本：9<br>代替接口：ohos.window.Window|@ohos.window.d.ts|
|权限有变化|方法名 or 属性名：createVirtualScreen<br>权限:ohos.permission.CAPTURE_SCREEN. if VirtualScreenOption.surfaceId is valid|方法名 or 属性名：createVirtualScreen<br>权限:ohos.permission.CAPTURE_SCREEN|@ohos.screen.d.ts|
|权限有变化|方法名 or 属性名：createVirtualScreen<br>权限:ohos.permission.CAPTURE_SCREEN. if VirtualScreenOption.surfaceId is valid|方法名 or 属性名：createVirtualScreen<br>权限:ohos.permission.CAPTURE_SCREEN|@ohos.screen.d.ts|
