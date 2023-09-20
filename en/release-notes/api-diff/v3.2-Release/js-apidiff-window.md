| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Deleted|Class name: screenshot;<br>Method or attribute name: function save(options?: ScreenshotOptions, callback: AsyncCallback\<image.PixelMap>): void;|NA|@ohos.screenshot.d.ts|
|Added|NA|Class name: WindowStage;<br>Method or attribute name: loadContent(path: string, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|Added|NA|Class name: windowAnimationManager;<br>Method or attribute name: function setController(controller: WindowAnimationController): void;|@ohos.animation.windowAnimationManager.d.ts|
|Added|NA|Class name: windowAnimationManager;<br>Method or attribute name: function minimizeWindowWithAnimation(windowTarget: WindowAnimationTarget,<br>    callback: AsyncCallback\<WindowAnimationFinishedCallback>): void;|@ohos.animation.windowAnimationManager.d.ts|
|Added|NA|Class name: windowAnimationManager;<br>Method or attribute name: function minimizeWindowWithAnimation(windowTarget: WindowAnimationTarget): Promise\<WindowAnimationFinishedCallback>;|@ohos.animation.windowAnimationManager.d.ts|
|Added|NA|Class name: RRect;<br>Method or attribute name: left: number;|@ohos.animation.windowAnimationManager.d.ts|
|Added|NA|Class name: RRect;<br>Method or attribute name: top: number;|@ohos.animation.windowAnimationManager.d.ts|
|Added|NA|Class name: RRect;<br>Method or attribute name: width: number;|@ohos.animation.windowAnimationManager.d.ts|
|Added|NA|Class name: RRect;<br>Method or attribute name: height: number;|@ohos.animation.windowAnimationManager.d.ts|
|Added|NA|Class name: RRect;<br>Method or attribute name: radius: number;|@ohos.animation.windowAnimationManager.d.ts|
|Added|NA|Class name: WindowAnimationTarget;<br>Method or attribute name: readonly bundleName: string;|@ohos.animation.windowAnimationManager.d.ts|
|Added|NA|Class name: WindowAnimationTarget;<br>Method or attribute name: readonly abilityName: string;|@ohos.animation.windowAnimationManager.d.ts|
|Added|NA|Class name: WindowAnimationTarget;<br>Method or attribute name: readonly windowBounds: RRect;|@ohos.animation.windowAnimationManager.d.ts|
|Added|NA|Class name: WindowAnimationTarget;<br>Method or attribute name: readonly missionId: number;|@ohos.animation.windowAnimationManager.d.ts|
|Added|NA|Class name: WindowAnimationFinishedCallback;<br>Method or attribute name: onAnimationFinish(): void;|@ohos.animation.windowAnimationManager.d.ts|
|Added|NA|Class name: WindowAnimationController;<br>Method or attribute name: onStartAppFromLauncher(startingWindowTarget: WindowAnimationTarget,<br>      finishCallback: WindowAnimationFinishedCallback): void;|@ohos.animation.windowAnimationManager.d.ts|
|Added|NA|Class name: WindowAnimationController;<br>Method or attribute name: onStartAppFromRecent(startingWindowTarget: WindowAnimationTarget,<br>      finishCallback: WindowAnimationFinishedCallback): void;|@ohos.animation.windowAnimationManager.d.ts|
|Added|NA|Class name: WindowAnimationController;<br>Method or attribute name: onStartAppFromOther(startingWindowTarget: WindowAnimationTarget,<br>      finishCallback: WindowAnimationFinishedCallback): void;|@ohos.animation.windowAnimationManager.d.ts|
|Added|NA|Class name: WindowAnimationController;<br>Method or attribute name: onAppTransition(fromWindowTarget: WindowAnimationTarget, toWindowTarget: WindowAnimationTarget,<br>      finishCallback: WindowAnimationFinishedCallback): void;|@ohos.animation.windowAnimationManager.d.ts|
|Added|NA|Class name: WindowAnimationController;<br>Method or attribute name: onMinimizeWindow(minimizingWindowTarget: WindowAnimationTarget,<br>      finishCallback: WindowAnimationFinishedCallback): void;|@ohos.animation.windowAnimationManager.d.ts|
|Added|NA|Class name: WindowAnimationController;<br>Method or attribute name: onCloseWindow(closingWindowTarget: WindowAnimationTarget, finishCallback: WindowAnimationFinishedCallback): void;|@ohos.animation.windowAnimationManager.d.ts|
|Added|NA|Class name: WindowAnimationController;<br>Method or attribute name: onScreenUnlock(finishCallback: WindowAnimationFinishedCallback): void;|@ohos.animation.windowAnimationManager.d.ts|
|Added|NA|Class name: WindowAnimationController;<br>Method or attribute name: onWindowAnimationTargetsUpdate(fullScreenWindowTarget: WindowAnimationTarget,<br>      floatingWindowTargets: Array\<WindowAnimationTarget>): void;|@ohos.animation.windowAnimationManager.d.ts|
|Added|NA|Class name: WindowExtensionAbility;<br>Method or attribute name: context: WindowExtensionContext;|@ohos.application.WindowExtensionAbility.d.ts|
|Added|NA|Class name: WindowExtensionAbility;<br>Method or attribute name: onConnect(want: Want): void;|@ohos.application.WindowExtensionAbility.d.ts|
|Added|NA|Class name: WindowExtensionAbility;<br>Method or attribute name: onDisconnect(want: Want): void;|@ohos.application.WindowExtensionAbility.d.ts|
|Added|NA|Class name: WindowExtensionAbility;<br>Method or attribute name: onWindowReady(window: window.Window): void;|@ohos.application.WindowExtensionAbility.d.ts|
|Added|NA|Class name: display;<br>Method or attribute name: function getDefaultDisplaySync(): Display;|@ohos.display.d.ts|
|Added|NA|Class name: display;<br>Method or attribute name: function getAllDisplays(callback: AsyncCallback\<Array\<Display>>): void;|@ohos.display.d.ts|
|Added|NA|Class name: display;<br>Method or attribute name: function getAllDisplays(): Promise\<Array\<Display>>;|@ohos.display.d.ts|
|Added|NA|Class name: display;<br>Method or attribute name: function hasPrivateWindow(displayId: number): boolean;|@ohos.display.d.ts|
|Added|NA|Class name: Rect;<br>Method or attribute name: left: number;|@ohos.display.d.ts|
|Added|NA|Class name: Rect;<br>Method or attribute name: top: number;|@ohos.display.d.ts|
|Added|NA|Class name: Rect;<br>Method or attribute name: width: number;|@ohos.display.d.ts|
|Added|NA|Class name: Rect;<br>Method or attribute name: height: number;|@ohos.display.d.ts|
|Added|NA|Class name: WaterfallDisplayAreaRects;<br>Method or attribute name: readonly left: Rect;|@ohos.display.d.ts|
|Added|NA|Class name: WaterfallDisplayAreaRects;<br>Method or attribute name: readonly right: Rect;|@ohos.display.d.ts|
|Added|NA|Class name: WaterfallDisplayAreaRects;<br>Method or attribute name: readonly top: Rect;|@ohos.display.d.ts|
|Added|NA|Class name: WaterfallDisplayAreaRects;<br>Method or attribute name: readonly bottom: Rect;|@ohos.display.d.ts|
|Added|NA|Class name: CutoutInfo;<br>Method or attribute name: readonly boundingRects: Array\<Rect>;|@ohos.display.d.ts|
|Added|NA|Class name: CutoutInfo;<br>Method or attribute name: readonly waterfallDisplayAreaRects: WaterfallDisplayAreaRects;|@ohos.display.d.ts|
|Added|NA|Class name: Display;<br>Method or attribute name: getCutoutInfo(callback: AsyncCallback\<CutoutInfo>): void;|@ohos.display.d.ts|
|Added|NA|Class name: Display;<br>Method or attribute name: getCutoutInfo(): Promise\<CutoutInfo>;|@ohos.display.d.ts|
|Added|NA|Class name: screen;<br>Method or attribute name: function getAllScreens(callback: AsyncCallback\<Array\<Screen>>): void;|@ohos.screen.d.ts|
|Added|NA|Class name: screen;<br>Method or attribute name: function getAllScreens(): Promise\<Array\<Screen>>;|@ohos.screen.d.ts|
|Added|NA|Class name: screen;<br>Method or attribute name: function on(eventType: 'connect' \| 'disconnect' \| 'change', callback: Callback\<number>): void;|@ohos.screen.d.ts|
|Added|NA|Class name: screen;<br>Method or attribute name: function off(eventType: 'connect' \| 'disconnect' \| 'change', callback?: Callback\<number>): void;|@ohos.screen.d.ts|
|Added|NA|Class name: screen;<br>Method or attribute name: function makeExpand(options:Array\<ExpandOption>, callback: AsyncCallback\<number>): void;|@ohos.screen.d.ts|
|Added|NA|Class name: screen;<br>Method or attribute name: function makeExpand(options:Array\<ExpandOption>): Promise\<number>;|@ohos.screen.d.ts|
|Added|NA|Class name: screen;<br>Method or attribute name: function makeMirror(mainScreen:number, mirrorScreen:Array\<number>, callback: AsyncCallback\<number>): void;|@ohos.screen.d.ts|
|Added|NA|Class name: screen;<br>Method or attribute name: function makeMirror(mainScreen:number, mirrorScreen:Array\<number>): Promise\<number>;|@ohos.screen.d.ts|
|Added|NA|Class name: screen;<br>Method or attribute name: function createVirtualScreen(options:VirtualScreenOption, callback: AsyncCallback\<Screen>): void;|@ohos.screen.d.ts|
|Added|NA|Class name: screen;<br>Method or attribute name: function createVirtualScreen(options:VirtualScreenOption): Promise\<Screen>;|@ohos.screen.d.ts|
|Added|NA|Class name: screen;<br>Method or attribute name: function destroyVirtualScreen(screenId:number, callback: AsyncCallback\<void>): void;|@ohos.screen.d.ts|
|Added|NA|Class name: screen;<br>Method or attribute name: function destroyVirtualScreen(screenId:number): Promise\<void>;|@ohos.screen.d.ts|
|Added|NA|Class name: screen;<br>Method or attribute name: function setVirtualScreenSurface(screenId:number, surfaceId: string, callback: AsyncCallback\<void>): void;|@ohos.screen.d.ts|
|Added|NA|Class name: screen;<br>Method or attribute name: function setVirtualScreenSurface(screenId:number, surfaceId: string): Promise\<void>;|@ohos.screen.d.ts|
|Added|NA|Class name: screen;<br>Method or attribute name: function isScreenRotationLocked(callback: AsyncCallback\<boolean>): void;|@ohos.screen.d.ts|
|Added|NA|Class name: screen;<br>Method or attribute name: function isScreenRotationLocked(): Promise\<boolean>;|@ohos.screen.d.ts|
|Added|NA|Class name: screen;<br>Method or attribute name: function setScreenRotationLocked(isLocked:boolean, callback: AsyncCallback\<void>): void;|@ohos.screen.d.ts|
|Added|NA|Class name: screen;<br>Method or attribute name: function setScreenRotationLocked(isLocked:boolean): Promise\<void>;|@ohos.screen.d.ts|
|Added|NA|Class name: ExpandOption;<br>Method or attribute name: screenId: number;|@ohos.screen.d.ts|
|Added|NA|Class name: ExpandOption;<br>Method or attribute name: startX: number;|@ohos.screen.d.ts|
|Added|NA|Class name: ExpandOption;<br>Method or attribute name: startY: number;|@ohos.screen.d.ts|
|Added|NA|Class name: VirtualScreenOption;<br>Method or attribute name: name: string|@ohos.screen.d.ts|
|Added|NA|Class name: VirtualScreenOption;<br>Method or attribute name: width: number|@ohos.screen.d.ts|
|Added|NA|Class name: ScreenModeInfo;<br>Method or attribute name: width: number;|@ohos.screen.d.ts|
|Added|NA|Class name: VirtualScreenOption;<br>Method or attribute name: height: number|@ohos.screen.d.ts|
|Added|NA|Class name: ScreenModeInfo;<br>Method or attribute name: height: number;|@ohos.screen.d.ts|
|Added|NA|Class name: VirtualScreenOption;<br>Method or attribute name: density: number|@ohos.screen.d.ts|
|Added|NA|Class name: VirtualScreenOption;<br>Method or attribute name: surfaceId: string|@ohos.screen.d.ts|
|Added|NA|Class name: Screen;<br>Method or attribute name: readonly id: number;|@ohos.screen.d.ts|
|Added|NA|Class name: Screen;<br>Method or attribute name: readonly parent: number;|@ohos.screen.d.ts|
|Added|NA|Class name: Screen;<br>Method or attribute name: readonly supportedModeInfo: Array\<ScreenModeInfo>;|@ohos.screen.d.ts|
|Added|NA|Class name: Screen;<br>Method or attribute name: readonly activeModeIndex: number;|@ohos.screen.d.ts|
|Added|NA|Class name: Screen;<br>Method or attribute name: readonly orientation: Orientation;|@ohos.screen.d.ts|
|Added|NA|Class name: Screen;<br>Method or attribute name: setOrientation(orientation: Orientation, callback: AsyncCallback\<void>): void;|@ohos.screen.d.ts|
|Added|NA|Class name: Screen;<br>Method or attribute name: setOrientation(orientation: Orientation): Promise\<void>;|@ohos.screen.d.ts|
|Added|NA|Class name: Screen;<br>Method or attribute name: setScreenActiveMode(modeIndex: number, callback: AsyncCallback\<void>): void;|@ohos.screen.d.ts|
|Added|NA|Class name: Screen;<br>Method or attribute name: setScreenActiveMode(modeIndex: number): Promise\<void>;|@ohos.screen.d.ts|
|Added|NA|Class name: Screen;<br>Method or attribute name: setDensityDpi(densityDpi: number, callback: AsyncCallback\<void>): void;|@ohos.screen.d.ts|
|Added|NA|Class name: Screen;<br>Method or attribute name: setDensityDpi(densityDpi: number): Promise\<void>;|@ohos.screen.d.ts|
|Added|NA|Class name: Orientation;<br>Method or attribute name: UNSPECIFIED = 0|@ohos.screen.d.ts|
|Added|NA|Class name: Orientation;<br>Method or attribute name: VERTICAL = 1|@ohos.screen.d.ts|
|Added|NA|Class name: Orientation;<br>Method or attribute name: HORIZONTAL = 2|@ohos.screen.d.ts|
|Added|NA|Class name: Orientation;<br>Method or attribute name: REVERSE_VERTICAL = 3|@ohos.screen.d.ts|
|Added|NA|Class name: Orientation;<br>Method or attribute name: REVERSE_HORIZONTAL = 4|@ohos.screen.d.ts|
|Added|NA|Class name: ScreenModeInfo;<br>Method or attribute name: id: number;|@ohos.screen.d.ts|
|Added|NA|Class name: ScreenModeInfo;<br>Method or attribute name: refreshRate: number;|@ohos.screen.d.ts|
|Added|NA|Class name: screenshot;<br>Method or attribute name: function save(options: ScreenshotOptions, callback: AsyncCallback\<image.PixelMap>): void;|@ohos.screenshot.d.ts|
|Added|NA|Class name: screenshot;<br>Method or attribute name: function save(callback: AsyncCallback\<image.PixelMap>): void;|@ohos.screenshot.d.ts|
|Added|NA|Class name: window;<br>Method or attribute name: function createWindow(config: Configuration, callback: AsyncCallback\<Window>): void;|@ohos.window.d.ts|
|Added|NA|Class name: window;<br>Method or attribute name: function createWindow(config: Configuration): Promise\<Window>;|@ohos.window.d.ts|
|Added|NA|Class name: window;<br>Method or attribute name: function findWindow(name: string): Window;|@ohos.window.d.ts|
|Added|NA|Class name: window;<br>Method or attribute name: function getLastWindow(ctx: BaseContext, callback: AsyncCallback\<Window>): void;|@ohos.window.d.ts|
|Added|NA|Class name: window;<br>Method or attribute name: function getLastWindow(ctx: BaseContext): Promise\<Window>;|@ohos.window.d.ts|
|Added|NA|Class name: window;<br>Method or attribute name: function minimizeAll(id: number, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|Added|NA|Class name: window;<br>Method or attribute name: function minimizeAll(id: number): Promise\<void>;|@ohos.window.d.ts|
|Added|NA|Class name: window;<br>Method or attribute name: function toggleShownStateForAllAppWindows(callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|Added|NA|Class name: window;<br>Method or attribute name: function toggleShownStateForAllAppWindows(): Promise\<void>;|@ohos.window.d.ts|
|Added|NA|Class name: window;<br>Method or attribute name: function setWindowLayoutMode(mode: WindowLayoutMode, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|Added|NA|Class name: window;<br>Method or attribute name: function setWindowLayoutMode(mode: WindowLayoutMode): Promise\<void>;|@ohos.window.d.ts|
|Added|NA|Class name: WindowType;<br>Method or attribute name: TYPE_INPUT_METHOD|@ohos.window.d.ts|
|Added|NA|Class name: WindowType;<br>Method or attribute name: TYPE_STATUS_BAR|@ohos.window.d.ts|
|Added|NA|Class name: WindowType;<br>Method or attribute name: TYPE_PANEL|@ohos.window.d.ts|
|Added|NA|Class name: WindowType;<br>Method or attribute name: TYPE_KEYGUARD|@ohos.window.d.ts|
|Added|NA|Class name: WindowType;<br>Method or attribute name: TYPE_VOLUME_OVERLAY|@ohos.window.d.ts|
|Added|NA|Class name: WindowType;<br>Method or attribute name: TYPE_NAVIGATION_BAR|@ohos.window.d.ts|
|Added|NA|Class name: WindowType;<br>Method or attribute name: TYPE_FLOAT|@ohos.window.d.ts|
|Added|NA|Class name: WindowType;<br>Method or attribute name: TYPE_WALLPAPER|@ohos.window.d.ts|
|Added|NA|Class name: WindowType;<br>Method or attribute name: TYPE_DESKTOP|@ohos.window.d.ts|
|Added|NA|Class name: WindowType;<br>Method or attribute name: TYPE_LAUNCHER_RECENT|@ohos.window.d.ts|
|Added|NA|Class name: WindowType;<br>Method or attribute name: TYPE_LAUNCHER_DOCK|@ohos.window.d.ts|
|Added|NA|Class name: WindowType;<br>Method or attribute name: TYPE_VOICE_INTERACTION|@ohos.window.d.ts|
|Added|NA|Class name: WindowType;<br>Method or attribute name: TYPE_POINTER|@ohos.window.d.ts|
|Added|NA|Class name: WindowType;<br>Method or attribute name: TYPE_FLOAT_CAMERA|@ohos.window.d.ts|
|Added|NA|Class name: WindowType;<br>Method or attribute name: TYPE_DIALOG|@ohos.window.d.ts|
|Added|NA|Class name: WindowType;<br>Method or attribute name: TYPE_SCREENSHOT|@ohos.window.d.ts|
|Added|NA|Class name: AvoidAreaType;<br>Method or attribute name: TYPE_SYSTEM_GESTURE|@ohos.window.d.ts|
|Added|NA|Class name: AvoidAreaType;<br>Method or attribute name: TYPE_KEYBOARD|@ohos.window.d.ts|
|Added|NA|Class name: WindowLayoutMode;<br>Method or attribute name: WINDOW_LAYOUT_MODE_CASCADE|@ohos.window.d.ts|
|Added|NA|Class name: WindowLayoutMode;<br>Method or attribute name: WINDOW_LAYOUT_MODE_TILE|@ohos.window.d.ts|
|Added|NA|Class name: AvoidArea;<br>Method or attribute name: visible: boolean;|@ohos.window.d.ts|
|Added|NA|Class name: WindowProperties;<br>Method or attribute name: id: number|@ohos.window.d.ts|
|Added|NA|Class name: ScaleOptions;<br>Method or attribute name: x?: number;|@ohos.window.d.ts|
|Added|NA|Class name: RotateOptions;<br>Method or attribute name: x?: number;|@ohos.window.d.ts|
|Added|NA|Class name: TranslateOptions;<br>Method or attribute name: x?: number;|@ohos.window.d.ts|
|Added|NA|Class name: ScaleOptions;<br>Method or attribute name: y?: number;|@ohos.window.d.ts|
|Added|NA|Class name: RotateOptions;<br>Method or attribute name: y?: number;|@ohos.window.d.ts|
|Added|NA|Class name: TranslateOptions;<br>Method or attribute name: y?: number;|@ohos.window.d.ts|
|Added|NA|Class name: ScaleOptions;<br>Method or attribute name: pivotX?: number;|@ohos.window.d.ts|
|Added|NA|Class name: RotateOptions;<br>Method or attribute name: pivotX?: number;|@ohos.window.d.ts|
|Added|NA|Class name: ScaleOptions;<br>Method or attribute name: pivotY?: number;|@ohos.window.d.ts|
|Added|NA|Class name: RotateOptions;<br>Method or attribute name: pivotY?: number;|@ohos.window.d.ts|
|Added|NA|Class name: RotateOptions;<br>Method or attribute name: z?: number;|@ohos.window.d.ts|
|Added|NA|Class name: TranslateOptions;<br>Method or attribute name: z?: number;|@ohos.window.d.ts|
|Added|NA|Class name: TransitionContext;<br>Method or attribute name: toWindow: Window|@ohos.window.d.ts|
|Added|NA|Class name: TransitionContext;<br>Method or attribute name: completeTransition(isCompleted: boolean): void;|@ohos.window.d.ts|
|Added|NA|Class name: TransitionController;<br>Method or attribute name: animationForShown(context: TransitionContext): void;|@ohos.window.d.ts|
|Added|NA|Class name: TransitionController;<br>Method or attribute name: animationForHidden(context: TransitionContext): void;|@ohos.window.d.ts|
|Added|NA|Class name: Configuration;<br>Method or attribute name: name: string|@ohos.window.d.ts|
|Added|NA|Class name: Configuration;<br>Method or attribute name: windowType: WindowType|@ohos.window.d.ts|
|Added|NA|Class name: Configuration;<br>Method or attribute name: ctx?: BaseContext|@ohos.window.d.ts|
|Added|NA|Class name: Configuration;<br>Method or attribute name: displayId?: number|@ohos.window.d.ts|
|Added|NA|Class name: Configuration;<br>Method or attribute name: parentId?: number|@ohos.window.d.ts|
|Added|NA|Class name: Orientation;<br>Method or attribute name: UNSPECIFIED = 0|@ohos.window.d.ts|
|Added|NA|Class name: Orientation;<br>Method or attribute name: PORTRAIT = 1|@ohos.window.d.ts|
|Added|NA|Class name: Orientation;<br>Method or attribute name: LANDSCAPE = 2|@ohos.window.d.ts|
|Added|NA|Class name: Orientation;<br>Method or attribute name: PORTRAIT_INVERTED = 3|@ohos.window.d.ts|
|Added|NA|Class name: Orientation;<br>Method or attribute name: LANDSCAPE_INVERTED = 4|@ohos.window.d.ts|
|Added|NA|Class name: Orientation;<br>Method or attribute name: AUTO_ROTATION = 5|@ohos.window.d.ts|
|Added|NA|Class name: Orientation;<br>Method or attribute name: AUTO_ROTATION_PORTRAIT = 6|@ohos.window.d.ts|
|Added|NA|Class name: Orientation;<br>Method or attribute name: AUTO_ROTATION_LANDSCAPE = 7|@ohos.window.d.ts|
|Added|NA|Class name: Orientation;<br>Method or attribute name: AUTO_ROTATION_RESTRICTED = 8|@ohos.window.d.ts|
|Added|NA|Class name: Orientation;<br>Method or attribute name: AUTO_ROTATION_PORTRAIT_RESTRICTED = 9|@ohos.window.d.ts|
|Added|NA|Class name: Orientation;<br>Method or attribute name: AUTO_ROTATION_LANDSCAPE_RESTRICTED = 10|@ohos.window.d.ts|
|Added|NA|Class name: Orientation;<br>Method or attribute name: LOCKED = 11|@ohos.window.d.ts|
|Added|NA|Class name: BlurStyle;<br>Method or attribute name: OFF|@ohos.window.d.ts|
|Added|NA|Class name: BlurStyle;<br>Method or attribute name: THIN|@ohos.window.d.ts|
|Added|NA|Class name: BlurStyle;<br>Method or attribute name: REGULAR|@ohos.window.d.ts|
|Added|NA|Class name: BlurStyle;<br>Method or attribute name: THICK|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: hideWithAnimation(callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: hideWithAnimation(): Promise\<void>;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: showWindow(callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: showWindow(): Promise\<void>;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: showWithAnimation(callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: showWithAnimation(): Promise\<void>;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: destroyWindow(callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: destroyWindow(): Promise\<void>;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: moveWindowTo(x: number, y: number): Promise\<void>;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: moveWindowTo(x: number, y: number, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: resize(width: number, height: number): Promise\<void>;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: resize(width: number, height: number, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: setWindowMode(mode: WindowMode): Promise\<void>;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: setWindowMode(mode: WindowMode, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: getWindowProperties(): WindowProperties;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: getWindowAvoidArea(type: AvoidAreaType): AvoidArea;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: setWindowLayoutFullScreen(isLayoutFullScreen: boolean, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: setWindowLayoutFullScreen(isLayoutFullScreen: boolean): Promise\<void>;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: setWindowSystemBarEnable(names: Array\<'status'\|'navigation'>, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: setWindowSystemBarEnable(names: Array\<'status'\|'navigation'>): Promise\<void>;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: setWindowSystemBarProperties(systemBarProperties: SystemBarProperties, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: setWindowSystemBarProperties(systemBarProperties: SystemBarProperties): Promise\<void>;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: setPreferredOrientation(orientation: Orientation): Promise\<void>;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: setPreferredOrientation(orientation: Orientation, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: loadContent(path: string, storage: LocalStorage, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|Added|NA|Class name: WindowStage;<br>Method or attribute name: loadContent(path: string, storage: LocalStorage, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: loadContent(path: string, storage: LocalStorage): Promise\<void>;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: setUIContent(path: string, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: setUIContent(path: string): Promise\<void>;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: isWindowShowing(): boolean;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: on(type: 'avoidAreaChange', callback: Callback\<{ type: AvoidAreaType, area: AvoidArea }>): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: on(type: 'touchOutside', callback: Callback\<void>): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: on(type: 'screenshot', callback: Callback\<void>): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: off(type: 'avoidAreaChange', callback?: Callback\<{ type: AvoidAreaType, area: AvoidArea }>): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: off(type: 'touchOutside', callback?: Callback\<void>): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: off(type: 'screenshot', callback?: Callback\<void>): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: bindDialogTarget(token: rpc.RemoteObject, deathCallback: Callback\<void>): Promise\<void>;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: bindDialogTarget(token: rpc.RemoteObject, deathCallback: Callback\<void>, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: bindDialogTarget(requestInfo: dialogRequest.RequestInfo, deathCallback: Callback\<void>): Promise\<void>;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: bindDialogTarget(requestInfo: dialogRequest.RequestInfo, deathCallback: Callback\<void>, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: isWindowSupportWideGamut(): Promise\<boolean>;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: isWindowSupportWideGamut(callback: AsyncCallback\<boolean>): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: setWindowColorSpace(colorSpace:ColorSpace): Promise\<void>;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: setWindowColorSpace(colorSpace:ColorSpace, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: getWindowColorSpace(): ColorSpace;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: setWindowBackgroundColor(color: string): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: setWindowBrightness(brightness: number): Promise\<void>;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: setWindowBrightness(brightness: number, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: setWindowFocusable(isFocusable: boolean): Promise\<void>;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: setWindowFocusable(isFocusable: boolean, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: setWindowKeepScreenOn(isKeepScreenOn: boolean): Promise\<void>;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: setWindowKeepScreenOn(isKeepScreenOn: boolean, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: setWakeUpScreen(wakeUp: boolean): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: setWindowPrivacyMode(isPrivacyMode: boolean): Promise\<void>;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: setWindowPrivacyMode(isPrivacyMode: boolean, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: setSnapshotSkip(isSkip: boolean): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: setWindowTouchable(isTouchable: boolean): Promise\<void>;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: setWindowTouchable(isTouchable: boolean, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: setForbidSplitMove(isForbidSplitMove: boolean, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: setForbidSplitMove(isForbidSplitMove: boolean): Promise\<void>;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: snapshot(callback: AsyncCallback\<image.PixelMap>): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: snapshot(): Promise\<image.PixelMap>;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: opacity(opacity: number): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: scale(scaleOptions: ScaleOptions): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: rotate(rotateOptions: RotateOptions): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: translate(translateOptions: TranslateOptions): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: getTransitionController(): TransitionController;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: setBlur(radius: number): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: setBackdropBlur(radius: number): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: setBackdropBlurStyle(blurStyle: BlurStyle): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: setShadow(radius: number, color?: string, offsetX?: number, offsetY?: number): void;|@ohos.window.d.ts|
|Added|NA|Class name: Window;<br>Method or attribute name: setCornerRadius(cornerRadius: number): void;|@ohos.window.d.ts|
|Added|NA|Class name: WindowStageEventType;<br>Method or attribute name: SHOWN = 1|@ohos.window.d.ts|
|Added|NA|Class name: WindowStageEventType;<br>Method or attribute name: ACTIVE|@ohos.window.d.ts|
|Added|NA|Class name: WindowStageEventType;<br>Method or attribute name: INACTIVE|@ohos.window.d.ts|
|Added|NA|Class name: WindowStageEventType;<br>Method or attribute name: HIDDEN|@ohos.window.d.ts|
|Added|NA|Class name: WindowStage;<br>Method or attribute name: getMainWindow(): Promise\<Window>;|@ohos.window.d.ts|
|Added|NA|Class name: WindowStage;<br>Method or attribute name: getMainWindow(callback: AsyncCallback\<Window>): void;|@ohos.window.d.ts|
|Added|NA|Class name: WindowStage;<br>Method or attribute name: getMainWindowSync(): Window;|@ohos.window.d.ts|
|Added|NA|Class name: WindowStage;<br>Method or attribute name: createSubWindow(name: string): Promise\<Window>;|@ohos.window.d.ts|
|Added|NA|Class name: WindowStage;<br>Method or attribute name: createSubWindow(name: string, callback: AsyncCallback\<Window>): void;|@ohos.window.d.ts|
|Added|NA|Class name: WindowStage;<br>Method or attribute name: getSubWindow(): Promise\<Array\<Window>>;|@ohos.window.d.ts|
|Added|NA|Class name: WindowStage;<br>Method or attribute name: getSubWindow(callback: AsyncCallback\<Array\<Window>>): void;|@ohos.window.d.ts|
|Added|NA|Class name: WindowStage;<br>Method or attribute name: loadContent(path: string, storage?: LocalStorage): Promise\<void>;|@ohos.window.d.ts|
|Added|NA|Class name: WindowStage;<br>Method or attribute name: on(eventType: 'windowStageEvent', callback: Callback\<WindowStageEventType>): void;|@ohos.window.d.ts|
|Added|NA|Class name: WindowStage;<br>Method or attribute name: off(eventType: 'windowStageEvent', callback?: Callback\<WindowStageEventType>): void;|@ohos.window.d.ts|
|Added|NA|Class name: WindowStage;<br>Method or attribute name: disableWindowDecor(): void;|@ohos.window.d.ts|
|Added|NA|Class name: WindowStage;<br>Method or attribute name: setShowOnLockScreen(showOnLockScreen: boolean): void;|@ohos.window.d.ts|
|Added|NA|Class name: WindowExtensionContext;<br>Method or attribute name: startAbility(want: Want, options: StartOptions, callback: AsyncCallback\<void>): void;|WindowExtensionContext.d.ts|
|Added|NA|Class name: WindowExtensionContext;<br>Method or attribute name: startAbility(want: Want, options?: StartOptions): Promise\<void>;|WindowExtensionContext.d.ts|
|Deprecated version changed|Class name: display;<br>Method or attribute name: function getDefaultDisplay(callback: AsyncCallback\<Display>): void;<br>Old version: |Class name: display;<br>Method or attribute name: function getDefaultDisplay(callback: AsyncCallback\<Display>): void;<br>New version: 9<br>Substitute API: ohos.display#getDefaultDisplaySync|@ohos.display.d.ts|
|Deprecated version changed|Class name: display;<br>Method or attribute name: function getDefaultDisplay(): Promise\<Display>;<br>Old version: |Class name: display;<br>Method or attribute name: function getDefaultDisplay(): Promise\<Display>;<br>New version: 9<br>Substitute API: ohos.display#getDefaultDisplaySync|@ohos.display.d.ts|
|Deprecated version changed|Class name: display;<br>Method or attribute name: function getAllDisplay(callback: AsyncCallback\<Array\<Display>>): void;<br>Old version: |Class name: display;<br>Method or attribute name: function getAllDisplay(callback: AsyncCallback\<Array\<Display>>): void;<br>New version: 9<br>Substitute API: ohos.display#getAllDisplays|@ohos.display.d.ts|
|Deprecated version changed|Class name: display;<br>Method or attribute name: function getAllDisplay(): Promise\<Array\<Display>>;<br>Old version: |Class name: display;<br>Method or attribute name: function getAllDisplay(): Promise\<Array\<Display>>;<br>New version: 9<br>Substitute API: ohos.display#getAllDisplays|@ohos.display.d.ts|
|Deprecated version changed|Class name: window;<br>Method or attribute name: function create(id: string, type: WindowType, callback: AsyncCallback\<Window>): void;<br>Old version: |Class name: window;<br>Method or attribute name: function create(id: string, type: WindowType, callback: AsyncCallback\<Window>): void;<br>New version: 9<br>Substitute API: ohos.window#createWindow|@ohos.window.d.ts|
|Deprecated version changed|Class name: window;<br>Method or attribute name: function create(id: string, type: WindowType): Promise\<Window>;<br>Old version: |Class name: window;<br>Method or attribute name: function create(id: string, type: WindowType): Promise\<Window>;<br>New version: 9<br>Substitute API: ohos.window#createWindow|@ohos.window.d.ts|
|Deprecated version changed|Class name: window;<br>Method or attribute name: function create(ctx: BaseContext, id: string, type: WindowType): Promise\<Window>;<br>Old version: |Class name: window;<br>Method or attribute name: function create(ctx: BaseContext, id: string, type: WindowType): Promise\<Window>;<br>New version: 9<br>Substitute API: ohos.window#createWindow|@ohos.window.d.ts|
|Deprecated version changed|Class name: window;<br>Method or attribute name: function create(ctx: BaseContext, id: string, type: WindowType, callback: AsyncCallback\<Window>): void;<br>Old version: |Class name: window;<br>Method or attribute name: function create(ctx: BaseContext, id: string, type: WindowType, callback: AsyncCallback\<Window>): void;<br>New version: 9<br>Substitute API: ohos.window#createWindow|@ohos.window.d.ts|
|Deprecated version changed|Class name: window;<br>Method or attribute name: function find(id: string, callback: AsyncCallback\<Window>): void;<br>Old version: |Class name: window;<br>Method or attribute name: function find(id: string, callback: AsyncCallback\<Window>): void;<br>New version: 9<br>Substitute API: ohos.window#findWindow|@ohos.window.d.ts|
|Deprecated version changed|Class name: window;<br>Method or attribute name: function find(id: string): Promise\<Window>;<br>Old version: |Class name: window;<br>Method or attribute name: function find(id: string): Promise\<Window>;<br>New version: 9<br>Substitute API: ohos.window#findWindow|@ohos.window.d.ts|
|Deprecated version changed|Class name: window;<br>Method or attribute name: function getTopWindow(callback: AsyncCallback\<Window>): void;<br>Old version: |Class name: window;<br>Method or attribute name: function getTopWindow(callback: AsyncCallback\<Window>): void;<br>New version: 9<br>Substitute API: ohos.window#getLastWindow|@ohos.window.d.ts|
|Deprecated version changed|Class name: window;<br>Method or attribute name: function getTopWindow(): Promise\<Window>;<br>Old version: |Class name: window;<br>Method or attribute name: function getTopWindow(): Promise\<Window>;<br>New version: 9<br>Substitute API: ohos.window#getLastWindow|@ohos.window.d.ts|
|Deprecated version changed|Class name: window;<br>Method or attribute name: function getTopWindow(ctx: BaseContext): Promise\<Window>;<br>Old version: |Class name: window;<br>Method or attribute name: function getTopWindow(ctx: BaseContext): Promise\<Window>;<br>New version: 9<br>Substitute API: ohos.window#getLastWindow|@ohos.window.d.ts|
|Deprecated version changed|Class name: window;<br>Method or attribute name: function getTopWindow(ctx: BaseContext, callback: AsyncCallback\<Window>): void;<br>Old version: |Class name: window;<br>Method or attribute name: function getTopWindow(ctx: BaseContext, callback: AsyncCallback\<Window>): void;<br>New version: 9<br>Substitute API: ohos.window#getLastWindow|@ohos.window.d.ts|
|Deprecated version changed|Class name: WindowProperties;<br>Method or attribute name: dimBehindValue: number<br>Old version: |Class name: WindowProperties;<br>Method or attribute name: dimBehindValue: number<br>New version: 9<br>Substitute API: |@ohos.window.d.ts|
|Deprecated version changed|Class name: WindowProperties;<br>Method or attribute name: isRoundCorner: boolean<br>Old version: |Class name: WindowProperties;<br>Method or attribute name: isRoundCorner: boolean<br>New version: 9<br>Substitute API: |@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: show(callback: AsyncCallback\<void>): void;<br>Old version: |Class name: Window;<br>Method or attribute name: show(callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.window.Window#showWindow|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: show(): Promise\<void>;<br>Old version: |Class name: Window;<br>Method or attribute name: show(): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.window.Window#showWindow|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: destroy(callback: AsyncCallback\<void>): void;<br>Old version: |Class name: Window;<br>Method or attribute name: destroy(callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.window.Window#destroyWindow|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: destroy(): Promise\<void>;<br>Old version: |Class name: Window;<br>Method or attribute name: destroy(): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.window.Window#destroyWindow|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: moveTo(x: number, y: number): Promise\<void>;<br>Old version: |Class name: Window;<br>Method or attribute name: moveTo(x: number, y: number): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.window.Window#moveWindowTo|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: moveTo(x: number, y: number, callback: AsyncCallback\<void>): void;<br>Old version: |Class name: Window;<br>Method or attribute name: moveTo(x: number, y: number, callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.window.Window#moveWindowTo|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: resetSize(width: number, height: number): Promise\<void>;<br>Old version: |Class name: Window;<br>Method or attribute name: resetSize(width: number, height: number): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.window.Window#resize|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: resetSize(width: number, height: number, callback: AsyncCallback\<void>): void;<br>Old version: |Class name: Window;<br>Method or attribute name: resetSize(width: number, height: number, callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.window.Window#resize|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: setWindowType(type: WindowType): Promise\<void>;<br>Old version: |Class name: Window;<br>Method or attribute name: setWindowType(type: WindowType): Promise\<void>;<br>New version: 9<br>Substitute API: |@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: setWindowType(type: WindowType, callback: AsyncCallback\<void>): void;<br>Old version: |Class name: Window;<br>Method or attribute name: setWindowType(type: WindowType, callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: |@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: getProperties(callback: AsyncCallback\<WindowProperties>): void;<br>Old version: |Class name: Window;<br>Method or attribute name: getProperties(callback: AsyncCallback\<WindowProperties>): void;<br>New version: 9<br>Substitute API: ohos.window.Window#getWindowProperties|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: getProperties(): Promise\<WindowProperties>;<br>Old version: |Class name: Window;<br>Method or attribute name: getProperties(): Promise\<WindowProperties>;<br>New version: 9<br>Substitute API: ohos.window.Window#getWindowProperties|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: getAvoidArea(type: AvoidAreaType, callback: AsyncCallback\<AvoidArea>): void;<br>Old version: |Class name: Window;<br>Method or attribute name: getAvoidArea(type: AvoidAreaType, callback: AsyncCallback\<AvoidArea>): void;<br>New version: 9<br>Substitute API: ohos.window.Window#getWindowAvoidArea|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: getAvoidArea(type: AvoidAreaType): Promise\<AvoidArea>;<br>Old version: |Class name: Window;<br>Method or attribute name: getAvoidArea(type: AvoidAreaType): Promise\<AvoidArea>;<br>New version: 9<br>Substitute API: ohos.window.Window#getWindowAvoidArea|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: setFullScreen(isFullScreen: boolean, callback: AsyncCallback\<void>): void;<br>Old version: |Class name: Window;<br>Method or attribute name: setFullScreen(isFullScreen: boolean, callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.window.Window#setWindowSystemBarEnable|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: setFullScreen(isFullScreen: boolean): Promise\<void>;<br>Old version: |Class name: Window;<br>Method or attribute name: setFullScreen(isFullScreen: boolean): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.window.Window#setWindowSystemBarEnable|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: setLayoutFullScreen(isLayoutFullScreen: boolean, callback: AsyncCallback\<void>): void;<br>Old version: |Class name: Window;<br>Method or attribute name: setLayoutFullScreen(isLayoutFullScreen: boolean, callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.window.Window#setWindowLayoutFullScreen|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: setLayoutFullScreen(isLayoutFullScreen: boolean): Promise\<void>;<br>Old version: |Class name: Window;<br>Method or attribute name: setLayoutFullScreen(isLayoutFullScreen: boolean): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.window.Window#setWindowLayoutFullScreen|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: setSystemBarEnable(names: Array\<'status'\|'navigation'>, callback: AsyncCallback\<void>): void;<br>Old version: |Class name: Window;<br>Method or attribute name: setSystemBarEnable(names: Array\<'status'\|'navigation'>, callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.window.Window#setWindowSystemBarEnable|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: setSystemBarEnable(names: Array\<'status'\|'navigation'>): Promise\<void>;<br>Old version: |Class name: Window;<br>Method or attribute name: setSystemBarEnable(names: Array\<'status'\|'navigation'>): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.window.Window#setWindowSystemBarEnable|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: setSystemBarProperties(systemBarProperties: SystemBarProperties, callback: AsyncCallback\<void>): void;<br>Old version: |Class name: Window;<br>Method or attribute name: setSystemBarProperties(systemBarProperties: SystemBarProperties, callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.window.Window#setWindowSystemBarProperties|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: setSystemBarProperties(systemBarProperties: SystemBarProperties): Promise\<void>;<br>Old version: |Class name: Window;<br>Method or attribute name: setSystemBarProperties(systemBarProperties: SystemBarProperties): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.window.Window#setWindowSystemBarProperties|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: loadContent(path: string, callback: AsyncCallback\<void>): void;<br>Old version: |Class name: Window;<br>Method or attribute name: loadContent(path: string, callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.window.Window#setUIContent|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: loadContent(path: string): Promise\<void>;<br>Old version: |Class name: Window;<br>Method or attribute name: loadContent(path: string): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.window.Window#setUIContent|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: isShowing(callback: AsyncCallback\<boolean>): void;<br>Old version: |Class name: Window;<br>Method or attribute name: isShowing(callback: AsyncCallback\<boolean>): void;<br>New version: 9<br>Substitute API: ohos.window.Window#isWindowShowing|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: isShowing(): Promise\<boolean>;<br>Old version: |Class name: Window;<br>Method or attribute name: isShowing(): Promise\<boolean>;<br>New version: 9<br>Substitute API: ohos.window.Window#isWindowShowing|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: on(type: 'systemAvoidAreaChange', callback: Callback\<AvoidArea>): void;<br>Old version: |Class name: Window;<br>Method or attribute name: on(type: 'systemAvoidAreaChange', callback: Callback\<AvoidArea>): void;<br>New version: 9<br>Substitute API: ohos.window.Window#on_avoidAreaChange|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: off(type: 'systemAvoidAreaChange', callback?: Callback\<AvoidArea>): void;<br>Old version: |Class name: Window;<br>Method or attribute name: off(type: 'systemAvoidAreaChange', callback?: Callback\<AvoidArea>): void;<br>New version: 9<br>Substitute API: ohos.window.Window#off_avoidAreaChange|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: isSupportWideGamut(): Promise\<boolean>;<br>Old version: |Class name: Window;<br>Method or attribute name: isSupportWideGamut(): Promise\<boolean>;<br>New version: 9<br>Substitute API: ohos.window.Window#isWindowSupportWideGamut|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: isSupportWideGamut(callback: AsyncCallback\<boolean>): void;<br>Old version: |Class name: Window;<br>Method or attribute name: isSupportWideGamut(callback: AsyncCallback\<boolean>): void;<br>New version: 9<br>Substitute API: ohos.window.Window#isWindowSupportWideGamut|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: setColorSpace(colorSpace:ColorSpace): Promise\<void>;<br>Old version: |Class name: Window;<br>Method or attribute name: setColorSpace(colorSpace:ColorSpace): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.window.Window#setWindowColorSpace|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: setColorSpace(colorSpace:ColorSpace, callback: AsyncCallback\<void>): void;<br>Old version: |Class name: Window;<br>Method or attribute name: setColorSpace(colorSpace:ColorSpace, callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.window.Window#setWindowColorSpace|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: getColorSpace(): Promise\<ColorSpace>;<br>Old version: |Class name: Window;<br>Method or attribute name: getColorSpace(): Promise\<ColorSpace>;<br>New version: 9<br>Substitute API: ohos.window.Window#getWindowColorSpace|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: getColorSpace(callback: AsyncCallback\<ColorSpace>): void;<br>Old version: |Class name: Window;<br>Method or attribute name: getColorSpace(callback: AsyncCallback\<ColorSpace>): void;<br>New version: 9<br>Substitute API: ohos.window.Window#getWindowColorSpace|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: setBackgroundColor(color: string): Promise\<void>;<br>Old version: |Class name: Window;<br>Method or attribute name: setBackgroundColor(color: string): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.window.Window#setWindowBackgroundColor|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: setBackgroundColor(color: string, callback: AsyncCallback\<void>): void;<br>Old version: |Class name: Window;<br>Method or attribute name: setBackgroundColor(color: string, callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.window.Window#setWindowBackgroundColor|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: setBrightness(brightness: number): Promise\<void>;<br>Old version: |Class name: Window;<br>Method or attribute name: setBrightness(brightness: number): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.window.Window#setWindowBrightness|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: setBrightness(brightness: number, callback: AsyncCallback\<void>): void;<br>Old version: |Class name: Window;<br>Method or attribute name: setBrightness(brightness: number, callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.window.Window#setWindowBrightness|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: setDimBehind(dimBehindValue: number, callback: AsyncCallback\<void>): void;<br>Old version: |Class name: Window;<br>Method or attribute name: setDimBehind(dimBehindValue: number, callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: |@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: setDimBehind(dimBehindValue: number): Promise\<void>;<br>Old version: |Class name: Window;<br>Method or attribute name: setDimBehind(dimBehindValue: number): Promise\<void>;<br>New version: 9<br>Substitute API: |@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: setFocusable(isFocusable: boolean): Promise\<void>;<br>Old version: |Class name: Window;<br>Method or attribute name: setFocusable(isFocusable: boolean): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.window.Window#setWindowFocusable|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: setFocusable(isFocusable: boolean, callback: AsyncCallback\<void>): void;<br>Old version: |Class name: Window;<br>Method or attribute name: setFocusable(isFocusable: boolean, callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.window.Window#setWindowFocusable|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: setKeepScreenOn(isKeepScreenOn: boolean): Promise\<void>;<br>Old version: |Class name: Window;<br>Method or attribute name: setKeepScreenOn(isKeepScreenOn: boolean): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.window.Window#setWindowKeepScreenOn|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: setKeepScreenOn(isKeepScreenOn: boolean, callback: AsyncCallback\<void>): void;<br>Old version: |Class name: Window;<br>Method or attribute name: setKeepScreenOn(isKeepScreenOn: boolean, callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.window.Window#setWindowKeepScreenOn|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: setOutsideTouchable(touchable: boolean): Promise\<void>;<br>Old version: |Class name: Window;<br>Method or attribute name: setOutsideTouchable(touchable: boolean): Promise\<void>;<br>New version: 9<br>Substitute API: |@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: setOutsideTouchable(touchable: boolean, callback: AsyncCallback\<void>): void;<br>Old version: |Class name: Window;<br>Method or attribute name: setOutsideTouchable(touchable: boolean, callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: |@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: setPrivacyMode(isPrivacyMode: boolean): Promise\<void>;<br>Old version: |Class name: Window;<br>Method or attribute name: setPrivacyMode(isPrivacyMode: boolean): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.window.Window#setWindowPrivacyMode|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: setPrivacyMode(isPrivacyMode: boolean, callback: AsyncCallback\<void>): void;<br>Old version: |Class name: Window;<br>Method or attribute name: setPrivacyMode(isPrivacyMode: boolean, callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.window.Window#setWindowPrivacyMode|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: setTouchable(isTouchable: boolean): Promise\<void>;<br>Old version: |Class name: Window;<br>Method or attribute name: setTouchable(isTouchable: boolean): Promise\<void>;<br>New version: 9<br>Substitute API: ohos.window.Window#setWindowTouchable|@ohos.window.d.ts|
|Deprecated version changed|Class name: Window;<br>Method or attribute name: setTouchable(isTouchable: boolean, callback: AsyncCallback\<void>): void;<br>Old version: |Class name: Window;<br>Method or attribute name: setTouchable(isTouchable: boolean, callback: AsyncCallback\<void>): void;<br>New version: 9<br>Substitute API: ohos.window.Window#setWindowTouchable|@ohos.window.d.ts|
|Error code added|Class name: display;<br>Method or attribute name: function on(type: 'add' \| 'remove' \| 'change', callback: Callback\<number>): void;<br>Old version: |Class name: display;<br>Method or attribute name: function on(type: 'add' \| 'remove' \| 'change', callback: Callback\<number>): void;<br>New version: 401|@ohos.display.d.ts|
|Error code added|Class name: display;<br>Method or attribute name: function off(type: 'add' \| 'remove' \| 'change', callback?: Callback\<number>): void;<br>Old version: |Class name: display;<br>Method or attribute name: function off(type: 'add' \| 'remove' \| 'change', callback?: Callback\<number>): void;<br>New version: 401|@ohos.display.d.ts|
|Error code added|Class name: screenshot;<br>Method or attribute name: function save(options?: ScreenshotOptions): Promise\<image.PixelMap>;<br>Old version: |Class name: screenshot;<br>Method or attribute name: function save(options?: ScreenshotOptions): Promise\<image.PixelMap>;<br>New version: 201,401|@ohos.screenshot.d.ts|
|Error code added|Class name: window;<br>Method or attribute name: function on(type: 'systemBarTintChange', callback: Callback\<SystemBarTintState>): void;<br>Old version: |Class name: window;<br>Method or attribute name: function on(type: 'systemBarTintChange', callback: Callback\<SystemBarTintState>): void;<br>New version: 401|@ohos.window.d.ts|
|Error code added|Class name: window;<br>Method or attribute name: function off(type: 'systemBarTintChange', callback?: Callback\<SystemBarTintState>): void;<br>Old version: |Class name: window;<br>Method or attribute name: function off(type: 'systemBarTintChange', callback?: Callback\<SystemBarTintState>): void;<br>New version: 401|@ohos.window.d.ts|
|Error code added|Class name: Window;<br>Method or attribute name: hide (callback: AsyncCallback\<void>): void;<br>Old version: |Class name: Window;<br>Method or attribute name: hide (callback: AsyncCallback\<void>): void;<br>New version: 1300002|@ohos.window.d.ts|
|Error code added|Class name: Window;<br>Method or attribute name: hide(): Promise\<void>;<br>Old version: |Class name: Window;<br>Method or attribute name: hide(): Promise\<void>;<br>New version: 1300002|@ohos.window.d.ts|
|Error code added|Class name: Window;<br>Method or attribute name: on(type: 'windowSizeChange', callback: Callback\<Size>): void;<br>Old version: |Class name: Window;<br>Method or attribute name: on(type: 'windowSizeChange', callback: Callback\<Size>): void;<br>New version: 401|@ohos.window.d.ts|
|Error code added|Class name: Window;<br>Method or attribute name: on(type: 'keyboardHeightChange', callback: Callback\<number>): void;<br>Old version: |Class name: Window;<br>Method or attribute name: on(type: 'keyboardHeightChange', callback: Callback\<number>): void;<br>New version: 401|@ohos.window.d.ts|
|Error code added|Class name: Window;<br>Method or attribute name: off(type: 'windowSizeChange', callback?: Callback\<Size>): void;<br>Old version: |Class name: Window;<br>Method or attribute name: off(type: 'windowSizeChange', callback?: Callback\<Size>): void;<br>New version: 401|@ohos.window.d.ts|
|Error code added|Class name: Window;<br>Method or attribute name: off(type: 'keyboardHeightChange', callback?: Callback\<number>): void;<br>Old version: |Class name: Window;<br>Method or attribute name: off(type: 'keyboardHeightChange', callback?: Callback\<number>): void;<br>New version: 401|@ohos.window.d.ts|
|Model changed|Class name: window;<br>Method or attribute name: function create(id: string, type: WindowType, callback: AsyncCallback\<Window>): void;<br>Old version: |Class name: window;<br>Method or attribute name: function create(id: string, type: WindowType, callback: AsyncCallback\<Window>): void;<br>New version: FAModelOnly|@ohos.window.d.ts|
|Model changed|Class name: window;<br>Method or attribute name: function create(id: string, type: WindowType): Promise\<Window>;<br>Old version: |Class name: window;<br>Method or attribute name: function create(id: string, type: WindowType): Promise\<Window>;<br>New version: FAModelOnly|@ohos.window.d.ts|
|Model changed|Class name: window;<br>Method or attribute name: function getTopWindow(callback: AsyncCallback\<Window>): void;<br>Old version: |Class name: window;<br>Method or attribute name: function getTopWindow(callback: AsyncCallback\<Window>): void;<br>New version: FAModelOnly|@ohos.window.d.ts|
|Model changed|Class name: window;<br>Method or attribute name: function getTopWindow(): Promise\<Window>;<br>Old version: |Class name: window;<br>Method or attribute name: function getTopWindow(): Promise\<Window>;<br>New version: FAModelOnly|@ohos.window.d.ts|
|Model changed|Class name: WindowType;<br>Method or attribute name: TYPE_APP<br>Old version: |Class name: WindowType;<br>Method or attribute name: TYPE_APP<br>New version: FAModelOnly|@ohos.window.d.ts|
|Function changed|Class name: window;<br>Method or attribute name: function create(ctx: Context, id: string, type: WindowType): Promise\<Window>;|Class name: window;<br>Method or attribute name: function create(ctx: BaseContext, id: string, type: WindowType): Promise\<Window>;|@ohos.window.d.ts|
|Function changed|Class name: window;<br>Method or attribute name: function create(ctx: Context, id: string, type: WindowType, callback: AsyncCallback\<Window>): void;|Class name: window;<br>Method or attribute name: function create(ctx: BaseContext, id: string, type: WindowType, callback: AsyncCallback\<Window>): void;|@ohos.window.d.ts|
|Function changed|Class name: window;<br>Method or attribute name: function getTopWindow(ctx: Context): Promise\<Window>;|Class name: window;<br>Method or attribute name: function getTopWindow(ctx: BaseContext): Promise\<Window>;|@ohos.window.d.ts|
|Function changed|Class name: window;<br>Method or attribute name: function getTopWindow(ctx: Context, callback: AsyncCallback\<Window>): void;|Class name: window;<br>Method or attribute name: function getTopWindow(ctx: BaseContext, callback: AsyncCallback\<Window>): void;|@ohos.window.d.ts|
