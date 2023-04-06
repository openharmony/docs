# JS API Changes of the Window Manager Subsystem

The table below lists the APIs changes of the window manager subsystem in OpenHarmony 3.2 Beta2 over OpenHarmony 3.2 Beta1.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.animation.windowAnimationManager | WindowAnimationController | onScreenUnlock(finishCallback: WindowAnimationFinishedCallback): void; | Added|
| ohos.animation.windowAnimationManager | WindowAnimationController | onCloseWindow(closingWindowTarget: WindowAnimationTarget, finishCallback: WindowAnimationFinishedCallback): void; | Added|
| ohos.animation.windowAnimationManager | WindowAnimationController | onMinimizeWindow(minimizingWindowTarget: WindowAnimationTarget, finishCallback: WindowAnimationFinishedCallback): void; | Added|
| ohos.animation.windowAnimationManager | WindowAnimationController | onAppTransition(fromWindowTarget: WindowAnimationTarget, toWindowTarget: WindowAnimationTarget, finishCallback: WindowAnimationFinishedCallback): void; | Added|
| ohos.animation.windowAnimationManager | WindowAnimationController | onStartAppFromOther(startingWindowTarget: WindowAnimationTarget, finishCallback: WindowAnimationFinishedCallback): void; | Added|
| ohos.animation.windowAnimationManager | WindowAnimationController | onStartAppFromRecent(startingWindowTarget: WindowAnimationTarget, finishCallback: WindowAnimationFinishedCallback): void; | Added|
| ohos.animation.windowAnimationManager | WindowAnimationController | onStartAppFromLauncher(startingWindowTarget: WindowAnimationTarget, finishCallback: WindowAnimationFinishedCallback): void; | Added|
| ohos.animation.windowAnimationManager | WindowAnimationFinishedCallback | onAnimationFinish(): void; | Added|
| ohos.animation.windowAnimationManager | WindowAnimationTarget | readonly windowBounds: RRect; | Added|
| ohos.animation.windowAnimationManager | WindowAnimationTarget | readonly abilityName: string; | Added|
| ohos.animation.windowAnimationManager | WindowAnimationTarget | readonly bundleName: string; | Added|
| ohos.animation.windowAnimationManager | RRect | radius: number; | Added|
| ohos.animation.windowAnimationManager | RRect | height: number; | Added|
| ohos.animation.windowAnimationManager | RRect | width: number; | Added|
| ohos.animation.windowAnimationManager | RRect | top: number; | Added|
| ohos.animation.windowAnimationManager | RRect | left: number; | Added|
| ohos.animation.windowAnimationManager | windowAnimationManager | setController(controller: WindowAnimationController): void; | Added|
| ohos.display | display | getDefaultDisplaySync(): Display; | Added|
| ohos.screen | Screen | setDensityDpi(densityDpi: number, callback: AsyncCallback\<void>): void;<br>setDensityDpi(densityDpi: number): Promise\<void>; | Added|
| ohos.screen | VirtualScreenOption | surfaceId: string | Added|
| ohos.screen | VirtualScreenOption | density: number | Added|
| ohos.screen | VirtualScreenOption | height: number | Added|
| ohos.screen | VirtualScreenOption | width: number | Added|
| ohos.screen | VirtualScreenOption | name: string | Added|
| ohos.screen | screen | setScreenRotationLocked(isLocked:boolean, callback: AsyncCallback\<void>): void;<br>setScreenRotationLocked(isLocked:boolean): Promise\<void>; | Added|
| ohos.screen | screen | isScreenRotationLocked(callback: AsyncCallback\<boolean>): void;<br>isScreenRotationLocked(): Promise\<boolean>; | Added|
| ohos.screen | screen | setVirtualScreenSurface(screenId:number, surfaceId: string, callback: AsyncCallback\<void>): void;<br>setVirtualScreenSurface(screenId:number, surfaceId: string): Promise\<void>; | Added|
| ohos.screen | screen | destroyVirtualScreen(screenId:number, callback: AsyncCallback\<void>): void;<br>destroyVirtualScreen(screenId:number): Promise\<void>; | Added|
| ohos.screen | screen | createVirtualScreen(options:VirtualScreenOption, callback: AsyncCallback\<Screen>): void;<br>createVirtualScreen(options:VirtualScreenOption): Promise\<Screen>; | Added|
| ohos.window | WindowStage | setShowOnLockScreen(showOnLockScreen: boolean): void; | Added|
| ohos.window | WindowStage | disableWindowDecor(): void; | Added|
| ohos.window | Window | setForbidSplitMove(isForbidSplitMove: boolean, callback: AsyncCallback\<void>): void;<br>setForbidSplitMove(isForbidSplitMove: boolean): Promise\<void>; | Added|
| ohos.window | Window | off(type: 'touchOutside', callback?: Callback\<void>): void; | Added|
| ohos.window | Window | on(type: 'touchOutside', callback: Callback\<void>): void; | Added|
| ohos.window | Window | off(type: 'avoidAreaChange', callback?: Callback\<{ type: AvoidAreaType, area: AvoidArea }>): void; | Added|
| ohos.window | Window | on(type: 'avoidAreaChange', callback: Callback\<{ type: AvoidAreaType, area: AvoidArea }>): void; | Added|
| ohos.window | Window | setPreferredOrientation(orientation: Orientation): Promise\<void>;<br>setPreferredOrientation(orientation: Orientation, callback: AsyncCallback\<void>): void; | Added|
| ohos.window | Orientation | LOCKED = 11 | Added|
| ohos.window | Orientation | AUTO_ROTATION_LANDSCAPE_RESTRICTED = 10 | Added|
| ohos.window | Orientation | AUTO_ROTATION_PORTRAIT_RESTRICTED = 9 | Added|
| ohos.window | Orientation | AUTO_ROTATION_RESTRICTED = 8 | Added|
| ohos.window | Orientation | AUTO_ROTATION_LANDSCAPE = 7 | Added|
| ohos.window | Orientation | AUTO_ROTATION_PORTRAIT = 6 | Added|
| ohos.window | Orientation | AUTO_ROTATION = 5 | Added|
| ohos.window | Orientation | LANDSCAPE_INVERTED = 4 | Added|
| ohos.window | Orientation | PORTRAIT_INVERTED = 3 | Added|
| ohos.window | Orientation | LANDSCAPE = 2 | Added|
| ohos.window | Orientation | PORTRAIT = 1 | Added|
| ohos.window | Orientation | UNSPECIFIED = 0 | Added|
| ohos.window | AvoidArea | visible: boolean; | Added|
| ohos.window | AvoidAreaType | TYPE_KEYBOARD | Added|
| ohos.window | AvoidAreaType | TYPE_SYSTEM_GESTURE | Added|
| ohos.window | WindowType | TYPE_POINTER | Added|
| ohos.window | WindowType | TYPE_VOICE_INTERACTION | Added|
| ohos.window | WindowType | TYPE_LAUNCHER_DOCK | Added|
| ohos.window | WindowType | TYPE_LAUNCHER_RECENT | Added|
| ohos.window | WindowType | TYPE_DESKTOP | Added|
| ohos.window | WindowType | TYPE_WALLPAPER | Added|
| ohos.window | WindowType | TYPE_FLOAT | Added|
| ohos.window | WindowType | TYPE_NAVIGATION_BAR | Added|
| ohos.window | WindowType | TYPE_VOLUME_OVERLAY | Added|
| ohos.window | WindowType | TYPE_KEYGUARD | Added|
| ohos.window | WindowType | TYPE_PANEL | Added|
| ohos.window | WindowType | TYPE_STATUS_BAR | Added|
| ohos.window | WindowType | TYPE_INPUT_METHOD | Added|
| ohos.window | Window | dump(params: Array\<string>): Array\<string>; | Deleted|
| ohos.window | Window | off(type: 'systemAvoidAreaChange', callback?: Callback\<AvoidArea>): void; | Deprecated|
| ohos.window | Window | on(type: 'systemAvoidAreaChange', callback: Callback\<AvoidArea>): void; | Deprecated|
