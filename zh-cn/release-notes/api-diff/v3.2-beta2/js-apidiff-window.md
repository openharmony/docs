# 窗口管理子系统JS API变更

OpenHarmony 3.2 Beta2版本相较于OpenHarmony 3.2 Beta1版本，窗口管理子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.animation.windowAnimationManager | WindowAnimationController | onScreenUnlock(finishCallback: WindowAnimationFinishedCallback): void; | 新增 |
| ohos.animation.windowAnimationManager | WindowAnimationController | onCloseWindow(closingWindowTarget: WindowAnimationTarget, finishCallback: WindowAnimationFinishedCallback): void; | 新增 |
| ohos.animation.windowAnimationManager | WindowAnimationController | onMinimizeWindow(minimizingWindowTarget: WindowAnimationTarget, finishCallback: WindowAnimationFinishedCallback): void; | 新增 |
| ohos.animation.windowAnimationManager | WindowAnimationController | onAppTransition(fromWindowTarget: WindowAnimationTarget, toWindowTarget: WindowAnimationTarget, finishCallback: WindowAnimationFinishedCallback): void; | 新增 |
| ohos.animation.windowAnimationManager | WindowAnimationController | onStartAppFromOther(startingWindowTarget: WindowAnimationTarget, finishCallback: WindowAnimationFinishedCallback): void; | 新增 |
| ohos.animation.windowAnimationManager | WindowAnimationController | onStartAppFromRecent(startingWindowTarget: WindowAnimationTarget, finishCallback: WindowAnimationFinishedCallback): void; | 新增 |
| ohos.animation.windowAnimationManager | WindowAnimationController | onStartAppFromLauncher(startingWindowTarget: WindowAnimationTarget, finishCallback: WindowAnimationFinishedCallback): void; | 新增 |
| ohos.animation.windowAnimationManager | WindowAnimationFinishedCallback | onAnimationFinish(): void; | 新增 |
| ohos.animation.windowAnimationManager | WindowAnimationTarget | readonly windowBounds: RRect; | 新增 |
| ohos.animation.windowAnimationManager | WindowAnimationTarget | readonly abilityName: string; | 新增 |
| ohos.animation.windowAnimationManager | WindowAnimationTarget | readonly bundleName: string; | 新增 |
| ohos.animation.windowAnimationManager | RRect | radius: number; | 新增 |
| ohos.animation.windowAnimationManager | RRect | height: number; | 新增 |
| ohos.animation.windowAnimationManager | RRect | width: number; | 新增 |
| ohos.animation.windowAnimationManager | RRect | top: number; | 新增 |
| ohos.animation.windowAnimationManager | RRect | left: number; | 新增 |
| ohos.animation.windowAnimationManager | windowAnimationManager | setController(controller: WindowAnimationController): void; | 新增 |
| ohos.display | display | getDefaultDisplaySync(): Display; | 新增 |
| ohos.screen | Screen | setDensityDpi(densityDpi: number, callback: AsyncCallback\<void>): void;<br>setDensityDpi(densityDpi: number): Promise\<void>; | 新增 |
| ohos.screen | VirtualScreenOption | surfaceId: string | 新增 |
| ohos.screen | VirtualScreenOption | density: number | 新增 |
| ohos.screen | VirtualScreenOption | height: number | 新增 |
| ohos.screen | VirtualScreenOption | width: number | 新增 |
| ohos.screen | VirtualScreenOption | name: string | 新增 |
| ohos.screen | screen | setScreenRotationLocked(isLocked:boolean, callback: AsyncCallback\<void>): void;<br>setScreenRotationLocked(isLocked:boolean): Promise\<void>; | 新增 |
| ohos.screen | screen | isScreenRotationLocked(callback: AsyncCallback\<boolean>): void;<br>isScreenRotationLocked(): Promise\<boolean>; | 新增 |
| ohos.screen | screen | setVirtualScreenSurface(screenId:number, surfaceId: string, callback: AsyncCallback\<void>): void;<br>setVirtualScreenSurface(screenId:number, surfaceId: string): Promise\<void>; | 新增 |
| ohos.screen | screen | destroyVirtualScreen(screenId:number, callback: AsyncCallback\<void>): void;<br>destroyVirtualScreen(screenId:number): Promise\<void>; | 新增 |
| ohos.screen | screen | createVirtualScreen(options:VirtualScreenOption, callback: AsyncCallback\<Screen>): void;<br>createVirtualScreen(options:VirtualScreenOption): Promise\<Screen>; | 新增 |
| ohos.window | WindowStage | setShowOnLockScreen(showOnLockScreen: boolean): void; | 新增 |
| ohos.window | WindowStage | disableWindowDecor(): void; | 新增 |
| ohos.window | Window | setForbidSplitMove(isForbidSplitMove: boolean, callback: AsyncCallback\<void>): void;<br>setForbidSplitMove(isForbidSplitMove: boolean): Promise\<void>; | 新增 |
| ohos.window | Window | off(type: 'touchOutside', callback?: Callback\<void>): void; | 新增 |
| ohos.window | Window | on(type: 'touchOutside', callback: Callback\<void>): void; | 新增 |
| ohos.window | Window | off(type: 'avoidAreaChange', callback?: Callback\<{ type: AvoidAreaType, area: AvoidArea }>): void; | 新增 |
| ohos.window | Window | on(type: 'avoidAreaChange', callback: Callback\<{ type: AvoidAreaType, area: AvoidArea }>): void; | 新增 |
| ohos.window | Window | setPreferredOrientation(orientation: Orientation): Promise\<void>;<br>setPreferredOrientation(orientation: Orientation, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.window | Orientation | LOCKED = 11 | 新增 |
| ohos.window | Orientation | AUTO_ROTATION_LANDSCAPE_RESTRICTED = 10 | 新增 |
| ohos.window | Orientation | AUTO_ROTATION_PORTRAIT_RESTRICTED = 9 | 新增 |
| ohos.window | Orientation | AUTO_ROTATION_RESTRICTED = 8 | 新增 |
| ohos.window | Orientation | AUTO_ROTATION_LANDSCAPE = 7 | 新增 |
| ohos.window | Orientation | AUTO_ROTATION_PORTRAIT = 6 | 新增 |
| ohos.window | Orientation | AUTO_ROTATION = 5 | 新增 |
| ohos.window | Orientation | LANDSCAPE_INVERTED = 4 | 新增 |
| ohos.window | Orientation | PORTRAIT_INVERTED = 3 | 新增 |
| ohos.window | Orientation | LANDSCAPE = 2 | 新增 |
| ohos.window | Orientation | PORTRAIT = 1 | 新增 |
| ohos.window | Orientation | UNSPECIFIED = 0 | 新增 |
| ohos.window | AvoidArea | visible: boolean; | 新增 |
| ohos.window | AvoidAreaType | TYPE_KEYBOARD | 新增 |
| ohos.window | AvoidAreaType | TYPE_SYSTEM_GESTURE | 新增 |
| ohos.window | WindowType | TYPE_POINTER | 新增 |
| ohos.window | WindowType | TYPE_VOICE_INTERACTION | 新增 |
| ohos.window | WindowType | TYPE_LAUNCHER_DOCK | 新增 |
| ohos.window | WindowType | TYPE_LAUNCHER_RECENT | 新增 |
| ohos.window | WindowType | TYPE_DESKTOP | 新增 |
| ohos.window | WindowType | TYPE_WALLPAPER | 新增 |
| ohos.window | WindowType | TYPE_FLOAT | 新增 |
| ohos.window | WindowType | TYPE_NAVIGATION_BAR | 新增 |
| ohos.window | WindowType | TYPE_VOLUME_OVERLAY | 新增 |
| ohos.window | WindowType | TYPE_KEYGUARD | 新增 |
| ohos.window | WindowType | TYPE_PANEL | 新增 |
| ohos.window | WindowType | TYPE_STATUS_BAR | 新增 |
| ohos.window | WindowType | TYPE_INPUT_METHOD | 新增 |
| ohos.window | Window | dump(params: Array\<string>): Array\<string>; | 删除 |
| ohos.window | Window | off(type: 'systemAvoidAreaChange', callback?: Callback\<AvoidArea>): void; | 废弃 |
| ohos.window | Window | on(type: 'systemAvoidAreaChange', callback: Callback\<AvoidArea>): void; | 废弃 |

