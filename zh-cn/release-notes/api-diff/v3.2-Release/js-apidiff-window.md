| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|删除|类名：screenshot;<br>方法or属性：function save(options?: ScreenshotOptions, callback: AsyncCallback\<image.PixelMap>): void;|NA|@ohos.screenshot.d.ts|
|新增|NA|类名：WindowStage;<br>方法or属性：loadContent(path: string, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：windowAnimationManager;<br>方法or属性：function setController(controller: WindowAnimationController): void;|@ohos.animation.windowAnimationManager.d.ts|
|新增|NA|类名：windowAnimationManager;<br>方法or属性：function minimizeWindowWithAnimation(windowTarget: WindowAnimationTarget,<br>    callback: AsyncCallback\<WindowAnimationFinishedCallback>): void;|@ohos.animation.windowAnimationManager.d.ts|
|新增|NA|类名：windowAnimationManager;<br>方法or属性：function minimizeWindowWithAnimation(windowTarget: WindowAnimationTarget): Promise\<WindowAnimationFinishedCallback>;|@ohos.animation.windowAnimationManager.d.ts|
|新增|NA|类名：RRect;<br>方法or属性：left: number;|@ohos.animation.windowAnimationManager.d.ts|
|新增|NA|类名：RRect;<br>方法or属性：top: number;|@ohos.animation.windowAnimationManager.d.ts|
|新增|NA|类名：RRect;<br>方法or属性：width: number;|@ohos.animation.windowAnimationManager.d.ts|
|新增|NA|类名：RRect;<br>方法or属性：height: number;|@ohos.animation.windowAnimationManager.d.ts|
|新增|NA|类名：RRect;<br>方法or属性：radius: number;|@ohos.animation.windowAnimationManager.d.ts|
|新增|NA|类名：WindowAnimationTarget;<br>方法or属性：readonly bundleName: string;|@ohos.animation.windowAnimationManager.d.ts|
|新增|NA|类名：WindowAnimationTarget;<br>方法or属性：readonly abilityName: string;|@ohos.animation.windowAnimationManager.d.ts|
|新增|NA|类名：WindowAnimationTarget;<br>方法or属性：readonly windowBounds: RRect;|@ohos.animation.windowAnimationManager.d.ts|
|新增|NA|类名：WindowAnimationTarget;<br>方法or属性：readonly missionId: number;|@ohos.animation.windowAnimationManager.d.ts|
|新增|NA|类名：WindowAnimationFinishedCallback;<br>方法or属性：onAnimationFinish(): void;|@ohos.animation.windowAnimationManager.d.ts|
|新增|NA|类名：WindowAnimationController;<br>方法or属性：onStartAppFromLauncher(startingWindowTarget: WindowAnimationTarget,<br>      finishCallback: WindowAnimationFinishedCallback): void;|@ohos.animation.windowAnimationManager.d.ts|
|新增|NA|类名：WindowAnimationController;<br>方法or属性：onStartAppFromRecent(startingWindowTarget: WindowAnimationTarget,<br>      finishCallback: WindowAnimationFinishedCallback): void;|@ohos.animation.windowAnimationManager.d.ts|
|新增|NA|类名：WindowAnimationController;<br>方法or属性：onStartAppFromOther(startingWindowTarget: WindowAnimationTarget,<br>      finishCallback: WindowAnimationFinishedCallback): void;|@ohos.animation.windowAnimationManager.d.ts|
|新增|NA|类名：WindowAnimationController;<br>方法or属性：onAppTransition(fromWindowTarget: WindowAnimationTarget, toWindowTarget: WindowAnimationTarget,<br>      finishCallback: WindowAnimationFinishedCallback): void;|@ohos.animation.windowAnimationManager.d.ts|
|新增|NA|类名：WindowAnimationController;<br>方法or属性：onMinimizeWindow(minimizingWindowTarget: WindowAnimationTarget,<br>      finishCallback: WindowAnimationFinishedCallback): void;|@ohos.animation.windowAnimationManager.d.ts|
|新增|NA|类名：WindowAnimationController;<br>方法or属性：onCloseWindow(closingWindowTarget: WindowAnimationTarget, finishCallback: WindowAnimationFinishedCallback): void;|@ohos.animation.windowAnimationManager.d.ts|
|新增|NA|类名：WindowAnimationController;<br>方法or属性：onScreenUnlock(finishCallback: WindowAnimationFinishedCallback): void;|@ohos.animation.windowAnimationManager.d.ts|
|新增|NA|类名：WindowAnimationController;<br>方法or属性：onWindowAnimationTargetsUpdate(fullScreenWindowTarget: WindowAnimationTarget,<br>      floatingWindowTargets: Array\<WindowAnimationTarget>): void;|@ohos.animation.windowAnimationManager.d.ts|
|新增|NA|类名：WindowExtensionAbility;<br>方法or属性：context: WindowExtensionContext;|@ohos.application.WindowExtensionAbility.d.ts|
|新增|NA|类名：WindowExtensionAbility;<br>方法or属性：onConnect(want: Want): void;|@ohos.application.WindowExtensionAbility.d.ts|
|新增|NA|类名：WindowExtensionAbility;<br>方法or属性：onDisconnect(want: Want): void;|@ohos.application.WindowExtensionAbility.d.ts|
|新增|NA|类名：WindowExtensionAbility;<br>方法or属性：onWindowReady(window: window.Window): void;|@ohos.application.WindowExtensionAbility.d.ts|
|新增|NA|类名：display;<br>方法or属性：function getDefaultDisplaySync(): Display;|@ohos.display.d.ts|
|新增|NA|类名：display;<br>方法or属性：function getAllDisplays(callback: AsyncCallback\<Array\<Display>>): void;|@ohos.display.d.ts|
|新增|NA|类名：display;<br>方法or属性：function getAllDisplays(): Promise\<Array\<Display>>;|@ohos.display.d.ts|
|新增|NA|类名：display;<br>方法or属性：function hasPrivateWindow(displayId: number): boolean;|@ohos.display.d.ts|
|新增|NA|类名：Rect;<br>方法or属性：left: number;|@ohos.display.d.ts|
|新增|NA|类名：Rect;<br>方法or属性：top: number;|@ohos.display.d.ts|
|新增|NA|类名：Rect;<br>方法or属性：width: number;|@ohos.display.d.ts|
|新增|NA|类名：Rect;<br>方法or属性：height: number;|@ohos.display.d.ts|
|新增|NA|类名：WaterfallDisplayAreaRects;<br>方法or属性：readonly left: Rect;|@ohos.display.d.ts|
|新增|NA|类名：WaterfallDisplayAreaRects;<br>方法or属性：readonly right: Rect;|@ohos.display.d.ts|
|新增|NA|类名：WaterfallDisplayAreaRects;<br>方法or属性：readonly top: Rect;|@ohos.display.d.ts|
|新增|NA|类名：WaterfallDisplayAreaRects;<br>方法or属性：readonly bottom: Rect;|@ohos.display.d.ts|
|新增|NA|类名：CutoutInfo;<br>方法or属性：readonly boundingRects: Array\<Rect>;|@ohos.display.d.ts|
|新增|NA|类名：CutoutInfo;<br>方法or属性：readonly waterfallDisplayAreaRects: WaterfallDisplayAreaRects;|@ohos.display.d.ts|
|新增|NA|类名：Display;<br>方法or属性：getCutoutInfo(callback: AsyncCallback\<CutoutInfo>): void;|@ohos.display.d.ts|
|新增|NA|类名：Display;<br>方法or属性：getCutoutInfo(): Promise\<CutoutInfo>;|@ohos.display.d.ts|
|新增|NA|类名：screen;<br>方法or属性：function getAllScreens(callback: AsyncCallback\<Array\<Screen>>): void;|@ohos.screen.d.ts|
|新增|NA|类名：screen;<br>方法or属性：function getAllScreens(): Promise\<Array\<Screen>>;|@ohos.screen.d.ts|
|新增|NA|类名：screen;<br>方法or属性：function on(eventType: 'connect' \| 'disconnect' \| 'change', callback: Callback\<number>): void;|@ohos.screen.d.ts|
|新增|NA|类名：screen;<br>方法or属性：function off(eventType: 'connect' \| 'disconnect' \| 'change', callback?: Callback\<number>): void;|@ohos.screen.d.ts|
|新增|NA|类名：screen;<br>方法or属性：function makeExpand(options:Array\<ExpandOption>, callback: AsyncCallback\<number>): void;|@ohos.screen.d.ts|
|新增|NA|类名：screen;<br>方法or属性：function makeExpand(options:Array\<ExpandOption>): Promise\<number>;|@ohos.screen.d.ts|
|新增|NA|类名：screen;<br>方法or属性：function makeMirror(mainScreen:number, mirrorScreen:Array\<number>, callback: AsyncCallback\<number>): void;|@ohos.screen.d.ts|
|新增|NA|类名：screen;<br>方法or属性：function makeMirror(mainScreen:number, mirrorScreen:Array\<number>): Promise\<number>;|@ohos.screen.d.ts|
|新增|NA|类名：screen;<br>方法or属性：function createVirtualScreen(options:VirtualScreenOption, callback: AsyncCallback\<Screen>): void;|@ohos.screen.d.ts|
|新增|NA|类名：screen;<br>方法or属性：function createVirtualScreen(options:VirtualScreenOption): Promise\<Screen>;|@ohos.screen.d.ts|
|新增|NA|类名：screen;<br>方法or属性：function destroyVirtualScreen(screenId:number, callback: AsyncCallback\<void>): void;|@ohos.screen.d.ts|
|新增|NA|类名：screen;<br>方法or属性：function destroyVirtualScreen(screenId:number): Promise\<void>;|@ohos.screen.d.ts|
|新增|NA|类名：screen;<br>方法or属性：function setVirtualScreenSurface(screenId:number, surfaceId: string, callback: AsyncCallback\<void>): void;|@ohos.screen.d.ts|
|新增|NA|类名：screen;<br>方法or属性：function setVirtualScreenSurface(screenId:number, surfaceId: string): Promise\<void>;|@ohos.screen.d.ts|
|新增|NA|类名：screen;<br>方法or属性：function isScreenRotationLocked(callback: AsyncCallback\<boolean>): void;|@ohos.screen.d.ts|
|新增|NA|类名：screen;<br>方法or属性：function isScreenRotationLocked(): Promise\<boolean>;|@ohos.screen.d.ts|
|新增|NA|类名：screen;<br>方法or属性：function setScreenRotationLocked(isLocked:boolean, callback: AsyncCallback\<void>): void;|@ohos.screen.d.ts|
|新增|NA|类名：screen;<br>方法or属性：function setScreenRotationLocked(isLocked:boolean): Promise\<void>;|@ohos.screen.d.ts|
|新增|NA|类名：ExpandOption;<br>方法or属性：screenId: number;|@ohos.screen.d.ts|
|新增|NA|类名：ExpandOption;<br>方法or属性：startX: number;|@ohos.screen.d.ts|
|新增|NA|类名：ExpandOption;<br>方法or属性：startY: number;|@ohos.screen.d.ts|
|新增|NA|类名：VirtualScreenOption;<br>方法or属性：name: string|@ohos.screen.d.ts|
|新增|NA|类名：VirtualScreenOption;<br>方法or属性：width: number|@ohos.screen.d.ts|
|新增|NA|类名：ScreenModeInfo;<br>方法or属性：width: number;|@ohos.screen.d.ts|
|新增|NA|类名：VirtualScreenOption;<br>方法or属性：height: number|@ohos.screen.d.ts|
|新增|NA|类名：ScreenModeInfo;<br>方法or属性：height: number;|@ohos.screen.d.ts|
|新增|NA|类名：VirtualScreenOption;<br>方法or属性：density: number|@ohos.screen.d.ts|
|新增|NA|类名：VirtualScreenOption;<br>方法or属性：surfaceId: string|@ohos.screen.d.ts|
|新增|NA|类名：Screen;<br>方法or属性：readonly id: number;|@ohos.screen.d.ts|
|新增|NA|类名：Screen;<br>方法or属性：readonly parent: number;|@ohos.screen.d.ts|
|新增|NA|类名：Screen;<br>方法or属性：readonly supportedModeInfo: Array\<ScreenModeInfo>;|@ohos.screen.d.ts|
|新增|NA|类名：Screen;<br>方法or属性：readonly activeModeIndex: number;|@ohos.screen.d.ts|
|新增|NA|类名：Screen;<br>方法or属性：readonly orientation: Orientation;|@ohos.screen.d.ts|
|新增|NA|类名：Screen;<br>方法or属性：setOrientation(orientation: Orientation, callback: AsyncCallback\<void>): void;|@ohos.screen.d.ts|
|新增|NA|类名：Screen;<br>方法or属性：setOrientation(orientation: Orientation): Promise\<void>;|@ohos.screen.d.ts|
|新增|NA|类名：Screen;<br>方法or属性：setScreenActiveMode(modeIndex: number, callback: AsyncCallback\<void>): void;|@ohos.screen.d.ts|
|新增|NA|类名：Screen;<br>方法or属性：setScreenActiveMode(modeIndex: number): Promise\<void>;|@ohos.screen.d.ts|
|新增|NA|类名：Screen;<br>方法or属性：setDensityDpi(densityDpi: number, callback: AsyncCallback\<void>): void;|@ohos.screen.d.ts|
|新增|NA|类名：Screen;<br>方法or属性：setDensityDpi(densityDpi: number): Promise\<void>;|@ohos.screen.d.ts|
|新增|NA|类名：Orientation;<br>方法or属性：UNSPECIFIED = 0|@ohos.screen.d.ts|
|新增|NA|类名：Orientation;<br>方法or属性：VERTICAL = 1|@ohos.screen.d.ts|
|新增|NA|类名：Orientation;<br>方法or属性：HORIZONTAL = 2|@ohos.screen.d.ts|
|新增|NA|类名：Orientation;<br>方法or属性：REVERSE_VERTICAL = 3|@ohos.screen.d.ts|
|新增|NA|类名：Orientation;<br>方法or属性：REVERSE_HORIZONTAL = 4|@ohos.screen.d.ts|
|新增|NA|类名：ScreenModeInfo;<br>方法or属性：id: number;|@ohos.screen.d.ts|
|新增|NA|类名：ScreenModeInfo;<br>方法or属性：refreshRate: number;|@ohos.screen.d.ts|
|新增|NA|类名：screenshot;<br>方法or属性：function save(options: ScreenshotOptions, callback: AsyncCallback\<image.PixelMap>): void;|@ohos.screenshot.d.ts|
|新增|NA|类名：screenshot;<br>方法or属性：function save(callback: AsyncCallback\<image.PixelMap>): void;|@ohos.screenshot.d.ts|
|新增|NA|类名：window;<br>方法or属性：function createWindow(config: Configuration, callback: AsyncCallback\<Window>): void;|@ohos.window.d.ts|
|新增|NA|类名：window;<br>方法or属性：function createWindow(config: Configuration): Promise\<Window>;|@ohos.window.d.ts|
|新增|NA|类名：window;<br>方法or属性：function findWindow(name: string): Window;|@ohos.window.d.ts|
|新增|NA|类名：window;<br>方法or属性：function getLastWindow(ctx: BaseContext, callback: AsyncCallback\<Window>): void;|@ohos.window.d.ts|
|新增|NA|类名：window;<br>方法or属性：function getLastWindow(ctx: BaseContext): Promise\<Window>;|@ohos.window.d.ts|
|新增|NA|类名：window;<br>方法or属性：function minimizeAll(id: number, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：window;<br>方法or属性：function minimizeAll(id: number): Promise\<void>;|@ohos.window.d.ts|
|新增|NA|类名：window;<br>方法or属性：function toggleShownStateForAllAppWindows(callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：window;<br>方法or属性：function toggleShownStateForAllAppWindows(): Promise\<void>;|@ohos.window.d.ts|
|新增|NA|类名：window;<br>方法or属性：function setWindowLayoutMode(mode: WindowLayoutMode, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：window;<br>方法or属性：function setWindowLayoutMode(mode: WindowLayoutMode): Promise\<void>;|@ohos.window.d.ts|
|新增|NA|类名：WindowType;<br>方法or属性：TYPE_INPUT_METHOD|@ohos.window.d.ts|
|新增|NA|类名：WindowType;<br>方法or属性：TYPE_STATUS_BAR|@ohos.window.d.ts|
|新增|NA|类名：WindowType;<br>方法or属性：TYPE_PANEL|@ohos.window.d.ts|
|新增|NA|类名：WindowType;<br>方法or属性：TYPE_KEYGUARD|@ohos.window.d.ts|
|新增|NA|类名：WindowType;<br>方法or属性：TYPE_VOLUME_OVERLAY|@ohos.window.d.ts|
|新增|NA|类名：WindowType;<br>方法or属性：TYPE_NAVIGATION_BAR|@ohos.window.d.ts|
|新增|NA|类名：WindowType;<br>方法or属性：TYPE_FLOAT|@ohos.window.d.ts|
|新增|NA|类名：WindowType;<br>方法or属性：TYPE_WALLPAPER|@ohos.window.d.ts|
|新增|NA|类名：WindowType;<br>方法or属性：TYPE_DESKTOP|@ohos.window.d.ts|
|新增|NA|类名：WindowType;<br>方法or属性：TYPE_LAUNCHER_RECENT|@ohos.window.d.ts|
|新增|NA|类名：WindowType;<br>方法or属性：TYPE_LAUNCHER_DOCK|@ohos.window.d.ts|
|新增|NA|类名：WindowType;<br>方法or属性：TYPE_VOICE_INTERACTION|@ohos.window.d.ts|
|新增|NA|类名：WindowType;<br>方法or属性：TYPE_POINTER|@ohos.window.d.ts|
|新增|NA|类名：WindowType;<br>方法or属性：TYPE_FLOAT_CAMERA|@ohos.window.d.ts|
|新增|NA|类名：WindowType;<br>方法or属性：TYPE_DIALOG|@ohos.window.d.ts|
|新增|NA|类名：WindowType;<br>方法or属性：TYPE_SCREENSHOT|@ohos.window.d.ts|
|新增|NA|类名：AvoidAreaType;<br>方法or属性：TYPE_SYSTEM_GESTURE|@ohos.window.d.ts|
|新增|NA|类名：AvoidAreaType;<br>方法or属性：TYPE_KEYBOARD|@ohos.window.d.ts|
|新增|NA|类名：WindowLayoutMode;<br>方法or属性：WINDOW_LAYOUT_MODE_CASCADE|@ohos.window.d.ts|
|新增|NA|类名：WindowLayoutMode;<br>方法or属性：WINDOW_LAYOUT_MODE_TILE|@ohos.window.d.ts|
|新增|NA|类名：AvoidArea;<br>方法or属性：visible: boolean;|@ohos.window.d.ts|
|新增|NA|类名：WindowProperties;<br>方法or属性：id: number|@ohos.window.d.ts|
|新增|NA|类名：ScaleOptions;<br>方法or属性：x?: number;|@ohos.window.d.ts|
|新增|NA|类名：RotateOptions;<br>方法or属性：x?: number;|@ohos.window.d.ts|
|新增|NA|类名：TranslateOptions;<br>方法or属性：x?: number;|@ohos.window.d.ts|
|新增|NA|类名：ScaleOptions;<br>方法or属性：y?: number;|@ohos.window.d.ts|
|新增|NA|类名：RotateOptions;<br>方法or属性：y?: number;|@ohos.window.d.ts|
|新增|NA|类名：TranslateOptions;<br>方法or属性：y?: number;|@ohos.window.d.ts|
|新增|NA|类名：ScaleOptions;<br>方法or属性：pivotX?: number;|@ohos.window.d.ts|
|新增|NA|类名：RotateOptions;<br>方法or属性：pivotX?: number;|@ohos.window.d.ts|
|新增|NA|类名：ScaleOptions;<br>方法or属性：pivotY?: number;|@ohos.window.d.ts|
|新增|NA|类名：RotateOptions;<br>方法or属性：pivotY?: number;|@ohos.window.d.ts|
|新增|NA|类名：RotateOptions;<br>方法or属性：z?: number;|@ohos.window.d.ts|
|新增|NA|类名：TranslateOptions;<br>方法or属性：z?: number;|@ohos.window.d.ts|
|新增|NA|类名：TransitionContext;<br>方法or属性：toWindow: Window|@ohos.window.d.ts|
|新增|NA|类名：TransitionContext;<br>方法or属性：completeTransition(isCompleted: boolean): void;|@ohos.window.d.ts|
|新增|NA|类名：TransitionController;<br>方法or属性：animationForShown(context: TransitionContext): void;|@ohos.window.d.ts|
|新增|NA|类名：TransitionController;<br>方法or属性：animationForHidden(context: TransitionContext): void;|@ohos.window.d.ts|
|新增|NA|类名：Configuration;<br>方法or属性：name: string|@ohos.window.d.ts|
|新增|NA|类名：Configuration;<br>方法or属性：windowType: WindowType|@ohos.window.d.ts|
|新增|NA|类名：Configuration;<br>方法or属性：ctx?: BaseContext|@ohos.window.d.ts|
|新增|NA|类名：Configuration;<br>方法or属性：displayId?: number|@ohos.window.d.ts|
|新增|NA|类名：Configuration;<br>方法or属性：parentId?: number|@ohos.window.d.ts|
|新增|NA|类名：Orientation;<br>方法or属性：UNSPECIFIED = 0|@ohos.window.d.ts|
|新增|NA|类名：Orientation;<br>方法or属性：PORTRAIT = 1|@ohos.window.d.ts|
|新增|NA|类名：Orientation;<br>方法or属性：LANDSCAPE = 2|@ohos.window.d.ts|
|新增|NA|类名：Orientation;<br>方法or属性：PORTRAIT_INVERTED = 3|@ohos.window.d.ts|
|新增|NA|类名：Orientation;<br>方法or属性：LANDSCAPE_INVERTED = 4|@ohos.window.d.ts|
|新增|NA|类名：Orientation;<br>方法or属性：AUTO_ROTATION = 5|@ohos.window.d.ts|
|新增|NA|类名：Orientation;<br>方法or属性：AUTO_ROTATION_PORTRAIT = 6|@ohos.window.d.ts|
|新增|NA|类名：Orientation;<br>方法or属性：AUTO_ROTATION_LANDSCAPE = 7|@ohos.window.d.ts|
|新增|NA|类名：Orientation;<br>方法or属性：AUTO_ROTATION_RESTRICTED = 8|@ohos.window.d.ts|
|新增|NA|类名：Orientation;<br>方法or属性：AUTO_ROTATION_PORTRAIT_RESTRICTED = 9|@ohos.window.d.ts|
|新增|NA|类名：Orientation;<br>方法or属性：AUTO_ROTATION_LANDSCAPE_RESTRICTED = 10|@ohos.window.d.ts|
|新增|NA|类名：Orientation;<br>方法or属性：LOCKED = 11|@ohos.window.d.ts|
|新增|NA|类名：BlurStyle;<br>方法or属性：OFF|@ohos.window.d.ts|
|新增|NA|类名：BlurStyle;<br>方法or属性：THIN|@ohos.window.d.ts|
|新增|NA|类名：BlurStyle;<br>方法or属性：REGULAR|@ohos.window.d.ts|
|新增|NA|类名：BlurStyle;<br>方法or属性：THICK|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：hideWithAnimation(callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：hideWithAnimation(): Promise\<void>;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：showWindow(callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：showWindow(): Promise\<void>;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：showWithAnimation(callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：showWithAnimation(): Promise\<void>;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：destroyWindow(callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：destroyWindow(): Promise\<void>;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：moveWindowTo(x: number, y: number): Promise\<void>;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：moveWindowTo(x: number, y: number, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：resize(width: number, height: number): Promise\<void>;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：resize(width: number, height: number, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setWindowMode(mode: WindowMode): Promise\<void>;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setWindowMode(mode: WindowMode, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：getWindowProperties(): WindowProperties;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：getWindowAvoidArea(type: AvoidAreaType): AvoidArea;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setWindowLayoutFullScreen(isLayoutFullScreen: boolean, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setWindowLayoutFullScreen(isLayoutFullScreen: boolean): Promise\<void>;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setWindowSystemBarEnable(names: Array\<'status'\|'navigation'>, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setWindowSystemBarEnable(names: Array\<'status'\|'navigation'>): Promise\<void>;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setWindowSystemBarProperties(systemBarProperties: SystemBarProperties, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setWindowSystemBarProperties(systemBarProperties: SystemBarProperties): Promise\<void>;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setPreferredOrientation(orientation: Orientation): Promise\<void>;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setPreferredOrientation(orientation: Orientation, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：loadContent(path: string, storage: LocalStorage, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：WindowStage;<br>方法or属性：loadContent(path: string, storage: LocalStorage, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：loadContent(path: string, storage: LocalStorage): Promise\<void>;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setUIContent(path: string, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setUIContent(path: string): Promise\<void>;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：isWindowShowing(): boolean;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：on(type: 'avoidAreaChange', callback: Callback\<{ type: AvoidAreaType, area: AvoidArea }>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：on(type: 'touchOutside', callback: Callback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：on(type: 'screenshot', callback: Callback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：off(type: 'avoidAreaChange', callback?: Callback\<{ type: AvoidAreaType, area: AvoidArea }>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：off(type: 'touchOutside', callback?: Callback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：off(type: 'screenshot', callback?: Callback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：bindDialogTarget(token: rpc.RemoteObject, deathCallback: Callback\<void>): Promise\<void>;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：bindDialogTarget(token: rpc.RemoteObject, deathCallback: Callback\<void>, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：bindDialogTarget(requestInfo: dialogRequest.RequestInfo, deathCallback: Callback\<void>): Promise\<void>;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：bindDialogTarget(requestInfo: dialogRequest.RequestInfo, deathCallback: Callback\<void>, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：isWindowSupportWideGamut(): Promise\<boolean>;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：isWindowSupportWideGamut(callback: AsyncCallback\<boolean>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setWindowColorSpace(colorSpace:ColorSpace): Promise\<void>;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setWindowColorSpace(colorSpace:ColorSpace, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：getWindowColorSpace(): ColorSpace;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setWindowBackgroundColor(color: string): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setWindowBrightness(brightness: number): Promise\<void>;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setWindowBrightness(brightness: number, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setWindowFocusable(isFocusable: boolean): Promise\<void>;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setWindowFocusable(isFocusable: boolean, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setWindowKeepScreenOn(isKeepScreenOn: boolean): Promise\<void>;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setWindowKeepScreenOn(isKeepScreenOn: boolean, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setWakeUpScreen(wakeUp: boolean): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setWindowPrivacyMode(isPrivacyMode: boolean): Promise\<void>;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setWindowPrivacyMode(isPrivacyMode: boolean, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setSnapshotSkip(isSkip: boolean): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setWindowTouchable(isTouchable: boolean): Promise\<void>;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setWindowTouchable(isTouchable: boolean, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setForbidSplitMove(isForbidSplitMove: boolean, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setForbidSplitMove(isForbidSplitMove: boolean): Promise\<void>;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：snapshot(callback: AsyncCallback\<image.PixelMap>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：snapshot(): Promise\<image.PixelMap>;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：opacity(opacity: number): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：scale(scaleOptions: ScaleOptions): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：rotate(rotateOptions: RotateOptions): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：translate(translateOptions: TranslateOptions): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：getTransitionController(): TransitionController;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setBlur(radius: number): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setBackdropBlur(radius: number): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setBackdropBlurStyle(blurStyle: BlurStyle): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setShadow(radius: number, color?: string, offsetX?: number, offsetY?: number): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setCornerRadius(cornerRadius: number): void;|@ohos.window.d.ts|
|新增|NA|类名：WindowStageEventType;<br>方法or属性：SHOWN = 1|@ohos.window.d.ts|
|新增|NA|类名：WindowStageEventType;<br>方法or属性：ACTIVE|@ohos.window.d.ts|
|新增|NA|类名：WindowStageEventType;<br>方法or属性：INACTIVE|@ohos.window.d.ts|
|新增|NA|类名：WindowStageEventType;<br>方法or属性：HIDDEN|@ohos.window.d.ts|
|新增|NA|类名：WindowStage;<br>方法or属性：getMainWindow(): Promise\<Window>;|@ohos.window.d.ts|
|新增|NA|类名：WindowStage;<br>方法or属性：getMainWindow(callback: AsyncCallback\<Window>): void;|@ohos.window.d.ts|
|新增|NA|类名：WindowStage;<br>方法or属性：getMainWindowSync(): Window;|@ohos.window.d.ts|
|新增|NA|类名：WindowStage;<br>方法or属性：createSubWindow(name: string): Promise\<Window>;|@ohos.window.d.ts|
|新增|NA|类名：WindowStage;<br>方法or属性：createSubWindow(name: string, callback: AsyncCallback\<Window>): void;|@ohos.window.d.ts|
|新增|NA|类名：WindowStage;<br>方法or属性：getSubWindow(): Promise\<Array\<Window>>;|@ohos.window.d.ts|
|新增|NA|类名：WindowStage;<br>方法or属性：getSubWindow(callback: AsyncCallback\<Array\<Window>>): void;|@ohos.window.d.ts|
|新增|NA|类名：WindowStage;<br>方法or属性：loadContent(path: string, storage?: LocalStorage): Promise\<void>;|@ohos.window.d.ts|
|新增|NA|类名：WindowStage;<br>方法or属性：on(eventType: 'windowStageEvent', callback: Callback\<WindowStageEventType>): void;|@ohos.window.d.ts|
|新增|NA|类名：WindowStage;<br>方法or属性：off(eventType: 'windowStageEvent', callback?: Callback\<WindowStageEventType>): void;|@ohos.window.d.ts|
|新增|NA|类名：WindowStage;<br>方法or属性：disableWindowDecor(): void;|@ohos.window.d.ts|
|新增|NA|类名：WindowStage;<br>方法or属性：setShowOnLockScreen(showOnLockScreen: boolean): void;|@ohos.window.d.ts|
|新增|NA|类名：WindowExtensionContext;<br>方法or属性：startAbility(want: Want, options: StartOptions, callback: AsyncCallback\<void>): void;|WindowExtensionContext.d.ts|
|新增|NA|类名：WindowExtensionContext;<br>方法or属性：startAbility(want: Want, options?: StartOptions): Promise\<void>;|WindowExtensionContext.d.ts|
|废弃版本有变化|类名：display;<br>方法or属性：function getDefaultDisplay(callback: AsyncCallback\<Display>): void;<br>旧版本信息：|类名：display;<br>方法or属性：function getDefaultDisplay(callback: AsyncCallback\<Display>): void;<br>新版本信息：9<br>代替接口： ohos.display#getDefaultDisplaySync|@ohos.display.d.ts|
|废弃版本有变化|类名：display;<br>方法or属性：function getDefaultDisplay(): Promise\<Display>;<br>旧版本信息：|类名：display;<br>方法or属性：function getDefaultDisplay(): Promise\<Display>;<br>新版本信息：9<br>代替接口： ohos.display#getDefaultDisplaySync|@ohos.display.d.ts|
|废弃版本有变化|类名：display;<br>方法or属性：function getAllDisplay(callback: AsyncCallback\<Array\<Display>>): void;<br>旧版本信息：|类名：display;<br>方法or属性：function getAllDisplay(callback: AsyncCallback\<Array\<Display>>): void;<br>新版本信息：9<br>代替接口： ohos.display#getAllDisplays|@ohos.display.d.ts|
|废弃版本有变化|类名：display;<br>方法or属性：function getAllDisplay(): Promise\<Array\<Display>>;<br>旧版本信息：|类名：display;<br>方法or属性：function getAllDisplay(): Promise\<Array\<Display>>;<br>新版本信息：9<br>代替接口： ohos.display#getAllDisplays|@ohos.display.d.ts|
|废弃版本有变化|类名：window;<br>方法or属性：function create(id: string, type: WindowType, callback: AsyncCallback\<Window>): void;<br>旧版本信息：|类名：window;<br>方法or属性：function create(id: string, type: WindowType, callback: AsyncCallback\<Window>): void;<br>新版本信息：9<br>代替接口： ohos.window#createWindow|@ohos.window.d.ts|
|废弃版本有变化|类名：window;<br>方法or属性：function create(id: string, type: WindowType): Promise\<Window>;<br>旧版本信息：|类名：window;<br>方法or属性：function create(id: string, type: WindowType): Promise\<Window>;<br>新版本信息：9<br>代替接口： ohos.window#createWindow|@ohos.window.d.ts|
|废弃版本有变化|类名：window;<br>方法or属性：function create(ctx: BaseContext, id: string, type: WindowType): Promise\<Window>;<br>旧版本信息：|类名：window;<br>方法or属性：function create(ctx: BaseContext, id: string, type: WindowType): Promise\<Window>;<br>新版本信息：9<br>代替接口： ohos.window#createWindow|@ohos.window.d.ts|
|废弃版本有变化|类名：window;<br>方法or属性：function create(ctx: BaseContext, id: string, type: WindowType, callback: AsyncCallback\<Window>): void;<br>旧版本信息：|类名：window;<br>方法or属性：function create(ctx: BaseContext, id: string, type: WindowType, callback: AsyncCallback\<Window>): void;<br>新版本信息：9<br>代替接口： ohos.window#createWindow|@ohos.window.d.ts|
|废弃版本有变化|类名：window;<br>方法or属性：function find(id: string, callback: AsyncCallback\<Window>): void;<br>旧版本信息：|类名：window;<br>方法or属性：function find(id: string, callback: AsyncCallback\<Window>): void;<br>新版本信息：9<br>代替接口： ohos.window#findWindow|@ohos.window.d.ts|
|废弃版本有变化|类名：window;<br>方法or属性：function find(id: string): Promise\<Window>;<br>旧版本信息：|类名：window;<br>方法or属性：function find(id: string): Promise\<Window>;<br>新版本信息：9<br>代替接口： ohos.window#findWindow|@ohos.window.d.ts|
|废弃版本有变化|类名：window;<br>方法or属性：function getTopWindow(callback: AsyncCallback\<Window>): void;<br>旧版本信息：|类名：window;<br>方法or属性：function getTopWindow(callback: AsyncCallback\<Window>): void;<br>新版本信息：9<br>代替接口： ohos.window#getLastWindow|@ohos.window.d.ts|
|废弃版本有变化|类名：window;<br>方法or属性：function getTopWindow(): Promise\<Window>;<br>旧版本信息：|类名：window;<br>方法or属性：function getTopWindow(): Promise\<Window>;<br>新版本信息：9<br>代替接口： ohos.window#getLastWindow|@ohos.window.d.ts|
|废弃版本有变化|类名：window;<br>方法or属性：function getTopWindow(ctx: BaseContext): Promise\<Window>;<br>旧版本信息：|类名：window;<br>方法or属性：function getTopWindow(ctx: BaseContext): Promise\<Window>;<br>新版本信息：9<br>代替接口： ohos.window#getLastWindow|@ohos.window.d.ts|
|废弃版本有变化|类名：window;<br>方法or属性：function getTopWindow(ctx: BaseContext, callback: AsyncCallback\<Window>): void;<br>旧版本信息：|类名：window;<br>方法or属性：function getTopWindow(ctx: BaseContext, callback: AsyncCallback\<Window>): void;<br>新版本信息：9<br>代替接口： ohos.window#getLastWindow|@ohos.window.d.ts|
|废弃版本有变化|类名：WindowProperties;<br>方法or属性：dimBehindValue: number<br>旧版本信息：|类名：WindowProperties;<br>方法or属性：dimBehindValue: number<br>新版本信息：9<br>代替接口：|@ohos.window.d.ts|
|废弃版本有变化|类名：WindowProperties;<br>方法or属性：isRoundCorner: boolean<br>旧版本信息：|类名：WindowProperties;<br>方法or属性：isRoundCorner: boolean<br>新版本信息：9<br>代替接口：|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：show(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：show(callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.window.Window#showWindow|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：show(): Promise\<void>;<br>旧版本信息：|类名：Window;<br>方法or属性：show(): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.window.Window#showWindow|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：destroy(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：destroy(callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.window.Window#destroyWindow|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：destroy(): Promise\<void>;<br>旧版本信息：|类名：Window;<br>方法or属性：destroy(): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.window.Window#destroyWindow|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：moveTo(x: number, y: number): Promise\<void>;<br>旧版本信息：|类名：Window;<br>方法or属性：moveTo(x: number, y: number): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.window.Window#moveWindowTo|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：moveTo(x: number, y: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：moveTo(x: number, y: number, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.window.Window#moveWindowTo|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：resetSize(width: number, height: number): Promise\<void>;<br>旧版本信息：|类名：Window;<br>方法or属性：resetSize(width: number, height: number): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.window.Window#resize|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：resetSize(width: number, height: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：resetSize(width: number, height: number, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.window.Window#resize|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：setWindowType(type: WindowType): Promise\<void>;<br>旧版本信息：|类名：Window;<br>方法or属性：setWindowType(type: WindowType): Promise\<void>;<br>新版本信息：9<br>代替接口：|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：setWindowType(type: WindowType, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：setWindowType(type: WindowType, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口：|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：getProperties(callback: AsyncCallback\<WindowProperties>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：getProperties(callback: AsyncCallback\<WindowProperties>): void;<br>新版本信息：9<br>代替接口： ohos.window.Window#getWindowProperties|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：getProperties(): Promise\<WindowProperties>;<br>旧版本信息：|类名：Window;<br>方法or属性：getProperties(): Promise\<WindowProperties>;<br>新版本信息：9<br>代替接口： ohos.window.Window#getWindowProperties|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：getAvoidArea(type: AvoidAreaType, callback: AsyncCallback\<AvoidArea>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：getAvoidArea(type: AvoidAreaType, callback: AsyncCallback\<AvoidArea>): void;<br>新版本信息：9<br>代替接口： ohos.window.Window#getWindowAvoidArea|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：getAvoidArea(type: AvoidAreaType): Promise\<AvoidArea>;<br>旧版本信息：|类名：Window;<br>方法or属性：getAvoidArea(type: AvoidAreaType): Promise\<AvoidArea>;<br>新版本信息：9<br>代替接口： ohos.window.Window#getWindowAvoidArea|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：setFullScreen(isFullScreen: boolean, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：setFullScreen(isFullScreen: boolean, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.window.Window#setWindowSystemBarEnable|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：setFullScreen(isFullScreen: boolean): Promise\<void>;<br>旧版本信息：|类名：Window;<br>方法or属性：setFullScreen(isFullScreen: boolean): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.window.Window#setWindowSystemBarEnable|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：setLayoutFullScreen(isLayoutFullScreen: boolean, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：setLayoutFullScreen(isLayoutFullScreen: boolean, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.window.Window#setWindowLayoutFullScreen|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：setLayoutFullScreen(isLayoutFullScreen: boolean): Promise\<void>;<br>旧版本信息：|类名：Window;<br>方法or属性：setLayoutFullScreen(isLayoutFullScreen: boolean): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.window.Window#setWindowLayoutFullScreen|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：setSystemBarEnable(names: Array\<'status'\|'navigation'>, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：setSystemBarEnable(names: Array\<'status'\|'navigation'>, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.window.Window#setWindowSystemBarEnable|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：setSystemBarEnable(names: Array\<'status'\|'navigation'>): Promise\<void>;<br>旧版本信息：|类名：Window;<br>方法or属性：setSystemBarEnable(names: Array\<'status'\|'navigation'>): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.window.Window#setWindowSystemBarEnable|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：setSystemBarProperties(systemBarProperties: SystemBarProperties, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：setSystemBarProperties(systemBarProperties: SystemBarProperties, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.window.Window#setWindowSystemBarProperties|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：setSystemBarProperties(systemBarProperties: SystemBarProperties): Promise\<void>;<br>旧版本信息：|类名：Window;<br>方法or属性：setSystemBarProperties(systemBarProperties: SystemBarProperties): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.window.Window#setWindowSystemBarProperties|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：loadContent(path: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：loadContent(path: string, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.window.Window#setUIContent|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：loadContent(path: string): Promise\<void>;<br>旧版本信息：|类名：Window;<br>方法or属性：loadContent(path: string): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.window.Window#setUIContent|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：isShowing(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：isShowing(callback: AsyncCallback\<boolean>): void;<br>新版本信息：9<br>代替接口： ohos.window.Window#isWindowShowing|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：isShowing(): Promise\<boolean>;<br>旧版本信息：|类名：Window;<br>方法or属性：isShowing(): Promise\<boolean>;<br>新版本信息：9<br>代替接口： ohos.window.Window#isWindowShowing|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：on(type: 'systemAvoidAreaChange', callback: Callback\<AvoidArea>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：on(type: 'systemAvoidAreaChange', callback: Callback\<AvoidArea>): void;<br>新版本信息：9<br>代替接口： ohos.window.Window#on_avoidAreaChange|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：off(type: 'systemAvoidAreaChange', callback?: Callback\<AvoidArea>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：off(type: 'systemAvoidAreaChange', callback?: Callback\<AvoidArea>): void;<br>新版本信息：9<br>代替接口： ohos.window.Window#off_avoidAreaChange|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：isSupportWideGamut(): Promise\<boolean>;<br>旧版本信息：|类名：Window;<br>方法or属性：isSupportWideGamut(): Promise\<boolean>;<br>新版本信息：9<br>代替接口： ohos.window.Window#isWindowSupportWideGamut|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：isSupportWideGamut(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：isSupportWideGamut(callback: AsyncCallback\<boolean>): void;<br>新版本信息：9<br>代替接口： ohos.window.Window#isWindowSupportWideGamut|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：setColorSpace(colorSpace:ColorSpace): Promise\<void>;<br>旧版本信息：|类名：Window;<br>方法or属性：setColorSpace(colorSpace:ColorSpace): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.window.Window#setWindowColorSpace|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：setColorSpace(colorSpace:ColorSpace, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：setColorSpace(colorSpace:ColorSpace, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.window.Window#setWindowColorSpace|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：getColorSpace(): Promise\<ColorSpace>;<br>旧版本信息：|类名：Window;<br>方法or属性：getColorSpace(): Promise\<ColorSpace>;<br>新版本信息：9<br>代替接口： ohos.window.Window#getWindowColorSpace|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：getColorSpace(callback: AsyncCallback\<ColorSpace>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：getColorSpace(callback: AsyncCallback\<ColorSpace>): void;<br>新版本信息：9<br>代替接口： ohos.window.Window#getWindowColorSpace|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：setBackgroundColor(color: string): Promise\<void>;<br>旧版本信息：|类名：Window;<br>方法or属性：setBackgroundColor(color: string): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.window.Window#setWindowBackgroundColor|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：setBackgroundColor(color: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：setBackgroundColor(color: string, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.window.Window#setWindowBackgroundColor|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：setBrightness(brightness: number): Promise\<void>;<br>旧版本信息：|类名：Window;<br>方法or属性：setBrightness(brightness: number): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.window.Window#setWindowBrightness|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：setBrightness(brightness: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：setBrightness(brightness: number, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.window.Window#setWindowBrightness|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：setDimBehind(dimBehindValue: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：setDimBehind(dimBehindValue: number, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口：|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：setDimBehind(dimBehindValue: number): Promise\<void>;<br>旧版本信息：|类名：Window;<br>方法or属性：setDimBehind(dimBehindValue: number): Promise\<void>;<br>新版本信息：9<br>代替接口：|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：setFocusable(isFocusable: boolean): Promise\<void>;<br>旧版本信息：|类名：Window;<br>方法or属性：setFocusable(isFocusable: boolean): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.window.Window#setWindowFocusable|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：setFocusable(isFocusable: boolean, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：setFocusable(isFocusable: boolean, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.window.Window#setWindowFocusable|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：setKeepScreenOn(isKeepScreenOn: boolean): Promise\<void>;<br>旧版本信息：|类名：Window;<br>方法or属性：setKeepScreenOn(isKeepScreenOn: boolean): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.window.Window#setWindowKeepScreenOn|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：setKeepScreenOn(isKeepScreenOn: boolean, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：setKeepScreenOn(isKeepScreenOn: boolean, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.window.Window#setWindowKeepScreenOn|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：setOutsideTouchable(touchable: boolean): Promise\<void>;<br>旧版本信息：|类名：Window;<br>方法or属性：setOutsideTouchable(touchable: boolean): Promise\<void>;<br>新版本信息：9<br>代替接口：|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：setOutsideTouchable(touchable: boolean, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：setOutsideTouchable(touchable: boolean, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口：|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：setPrivacyMode(isPrivacyMode: boolean): Promise\<void>;<br>旧版本信息：|类名：Window;<br>方法or属性：setPrivacyMode(isPrivacyMode: boolean): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.window.Window#setWindowPrivacyMode|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：setPrivacyMode(isPrivacyMode: boolean, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：setPrivacyMode(isPrivacyMode: boolean, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.window.Window#setWindowPrivacyMode|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：setTouchable(isTouchable: boolean): Promise\<void>;<br>旧版本信息：|类名：Window;<br>方法or属性：setTouchable(isTouchable: boolean): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.window.Window#setWindowTouchable|@ohos.window.d.ts|
|废弃版本有变化|类名：Window;<br>方法or属性：setTouchable(isTouchable: boolean, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：setTouchable(isTouchable: boolean, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.window.Window#setWindowTouchable|@ohos.window.d.ts|
|新增(错误码)|类名：display;<br>方法or属性：function on(type: 'add' \| 'remove' \| 'change', callback: Callback\<number>): void;<br>旧版本信息：|类名：display;<br>方法or属性：function on(type: 'add' \| 'remove' \| 'change', callback: Callback\<number>): void;<br>新版本信息：401|@ohos.display.d.ts|
|新增(错误码)|类名：display;<br>方法or属性：function off(type: 'add' \| 'remove' \| 'change', callback?: Callback\<number>): void;<br>旧版本信息：|类名：display;<br>方法or属性：function off(type: 'add' \| 'remove' \| 'change', callback?: Callback\<number>): void;<br>新版本信息：401|@ohos.display.d.ts|
|新增(错误码)|类名：screenshot;<br>方法or属性：function save(options?: ScreenshotOptions): Promise\<image.PixelMap>;<br>旧版本信息：|类名：screenshot;<br>方法or属性：function save(options?: ScreenshotOptions): Promise\<image.PixelMap>;<br>新版本信息：201,401|@ohos.screenshot.d.ts|
|新增(错误码)|类名：window;<br>方法or属性：function on(type: 'systemBarTintChange', callback: Callback\<SystemBarTintState>): void;<br>旧版本信息：|类名：window;<br>方法or属性：function on(type: 'systemBarTintChange', callback: Callback\<SystemBarTintState>): void;<br>新版本信息：401|@ohos.window.d.ts|
|新增(错误码)|类名：window;<br>方法or属性：function off(type: 'systemBarTintChange', callback?: Callback\<SystemBarTintState>): void;<br>旧版本信息：|类名：window;<br>方法or属性：function off(type: 'systemBarTintChange', callback?: Callback\<SystemBarTintState>): void;<br>新版本信息：401|@ohos.window.d.ts|
|新增(错误码)|类名：Window;<br>方法or属性：hide (callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：hide (callback: AsyncCallback\<void>): void;<br>新版本信息：1300002|@ohos.window.d.ts|
|新增(错误码)|类名：Window;<br>方法or属性：hide(): Promise\<void>;<br>旧版本信息：|类名：Window;<br>方法or属性：hide(): Promise\<void>;<br>新版本信息：1300002|@ohos.window.d.ts|
|新增(错误码)|类名：Window;<br>方法or属性：on(type: 'windowSizeChange', callback: Callback\<Size>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：on(type: 'windowSizeChange', callback: Callback\<Size>): void;<br>新版本信息：401|@ohos.window.d.ts|
|新增(错误码)|类名：Window;<br>方法or属性：on(type: 'keyboardHeightChange', callback: Callback\<number>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：on(type: 'keyboardHeightChange', callback: Callback\<number>): void;<br>新版本信息：401|@ohos.window.d.ts|
|新增(错误码)|类名：Window;<br>方法or属性：off(type: 'windowSizeChange', callback?: Callback\<Size>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：off(type: 'windowSizeChange', callback?: Callback\<Size>): void;<br>新版本信息：401|@ohos.window.d.ts|
|新增(错误码)|类名：Window;<br>方法or属性：off(type: 'keyboardHeightChange', callback?: Callback\<number>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：off(type: 'keyboardHeightChange', callback?: Callback\<number>): void;<br>新版本信息：401|@ohos.window.d.ts|
|model有变化|类名：window;<br>方法or属性：function create(id: string, type: WindowType, callback: AsyncCallback\<Window>): void;<br>旧版本信息：|类名：window;<br>方法or属性：function create(id: string, type: WindowType, callback: AsyncCallback\<Window>): void;<br>新版本信息：FAModelOnly|@ohos.window.d.ts|
|model有变化|类名：window;<br>方法or属性：function create(id: string, type: WindowType): Promise\<Window>;<br>旧版本信息：|类名：window;<br>方法or属性：function create(id: string, type: WindowType): Promise\<Window>;<br>新版本信息：FAModelOnly|@ohos.window.d.ts|
|model有变化|类名：window;<br>方法or属性：function getTopWindow(callback: AsyncCallback\<Window>): void;<br>旧版本信息：|类名：window;<br>方法or属性：function getTopWindow(callback: AsyncCallback\<Window>): void;<br>新版本信息：FAModelOnly|@ohos.window.d.ts|
|model有变化|类名：window;<br>方法or属性：function getTopWindow(): Promise\<Window>;<br>旧版本信息：|类名：window;<br>方法or属性：function getTopWindow(): Promise\<Window>;<br>新版本信息：FAModelOnly|@ohos.window.d.ts|
|model有变化|类名：WindowType;<br>方法or属性：TYPE_APP<br>旧版本信息：|类名：WindowType;<br>方法or属性：TYPE_APP<br>新版本信息：FAModelOnly|@ohos.window.d.ts|
|函数有变化|类名：window;<br>方法or属性：function create(ctx: Context, id: string, type: WindowType): Promise\<Window>;|类名：window;<br>方法or属性：function create(ctx: BaseContext, id: string, type: WindowType): Promise\<Window>;|@ohos.window.d.ts|
|函数有变化|类名：window;<br>方法or属性：function create(ctx: Context, id: string, type: WindowType, callback: AsyncCallback\<Window>): void;|类名：window;<br>方法or属性：function create(ctx: BaseContext, id: string, type: WindowType, callback: AsyncCallback\<Window>): void;|@ohos.window.d.ts|
|函数有变化|类名：window;<br>方法or属性：function getTopWindow(ctx: Context): Promise\<Window>;|类名：window;<br>方法or属性：function getTopWindow(ctx: BaseContext): Promise\<Window>;|@ohos.window.d.ts|
|函数有变化|类名：window;<br>方法or属性：function getTopWindow(ctx: Context, callback: AsyncCallback\<Window>): void;|类名：window;<br>方法or属性：function getTopWindow(ctx: BaseContext, callback: AsyncCallback\<Window>): void;|@ohos.window.d.ts|
