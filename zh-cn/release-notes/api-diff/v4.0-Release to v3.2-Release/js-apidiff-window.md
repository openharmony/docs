| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：sourcefile;<br>方法or属性：export type WindowExtensionContext = _WindowExtensionContext;|@ohos.application.WindowExtensionAbility.d.ts|
|新增|NA|类名：display;<br>方法or属性：function on(type: 'privateModeChange', callback: Callback\<boolean>): void;|@ohos.display.d.ts|
|新增|NA|类名：display;<br>方法or属性：function off(type: 'privateModeChange', callback?: Callback\<boolean>): void;|@ohos.display.d.ts|
|新增|NA|类名：Orientation;<br>方法or属性：PORTRAIT = 0|@ohos.display.d.ts|
|新增|NA|类名：Orientation;<br>方法or属性：LANDSCAPE = 1|@ohos.display.d.ts|
|新增|NA|类名：Orientation;<br>方法or属性：PORTRAIT_INVERTED = 2|@ohos.display.d.ts|
|新增|NA|类名：Orientation;<br>方法or属性：LANDSCAPE_INVERTED = 3|@ohos.display.d.ts|
|新增|NA|类名：Display;<br>方法or属性：orientation: Orientation;|@ohos.display.d.ts|
|新增|NA|类名：screen;<br>方法or属性：function stopExpand(expandScreen: Array\<number>, callback: AsyncCallback\<void>): void;|@ohos.screen.d.ts|
|新增|NA|类名：screen;<br>方法or属性：function stopExpand(expandScreen: Array\<number>): Promise\<void>;|@ohos.screen.d.ts|
|新增|NA|类名：screen;<br>方法or属性：function stopMirror(mirrorScreen: Array\<number>, callback: AsyncCallback\<void>): void;|@ohos.screen.d.ts|
|新增|NA|类名：screen;<br>方法or属性：function stopMirror(mirrorScreen: Array\<number>): Promise\<void>;|@ohos.screen.d.ts|
|新增|NA|类名：ScreenSourceMode;<br>方法or属性：SCREEN_MAIN = 0|@ohos.screen.d.ts|
|新增|NA|类名：ScreenSourceMode;<br>方法or属性：SCREEN_MIRROR = 1|@ohos.screen.d.ts|
|新增|NA|类名：ScreenSourceMode;<br>方法or属性：SCREEN_EXTEND = 2|@ohos.screen.d.ts|
|新增|NA|类名：ScreenSourceMode;<br>方法or属性：SCREEN_ALONE = 3|@ohos.screen.d.ts|
|新增|NA|类名：Screen;<br>方法or属性：readonly sourceMode: ScreenSourceMode;|@ohos.screen.d.ts|
|新增|NA|类名：window;<br>方法or属性：function setGestureNavigationEnabled(enable: boolean, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：window;<br>方法or属性：function setGestureNavigationEnabled(enable: boolean): Promise\<void>;|@ohos.window.d.ts|
|新增|NA|类名：window;<br>方法or属性：function setWaterMarkImage(pixelMap: image.PixelMap, enable: boolean): Promise\<void>;|@ohos.window.d.ts|
|新增|NA|类名：window;<br>方法or属性：function setWaterMarkImage(pixelMap: image.PixelMap, enable: boolean, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：window;<br>方法or属性：function on(type: 'gestureNavigationEnabledChange', callback: Callback\<boolean>): void;|@ohos.window.d.ts|
|新增|NA|类名：window;<br>方法or属性：function on(type: 'waterMarkFlagChange', callback: Callback\<boolean>): void;|@ohos.window.d.ts|
|新增|NA|类名：window;<br>方法or属性：function off(type: 'gestureNavigationEnabledChange', callback?: Callback\<boolean>): void;|@ohos.window.d.ts|
|新增|NA|类名：window;<br>方法or属性：function off(type: 'waterMarkFlagChange', callback?: Callback\<boolean>): void;|@ohos.window.d.ts|
|新增|NA|类名：WindowEventType;<br>方法or属性：WINDOW_SHOWN = 1|@ohos.window.d.ts|
|新增|NA|类名：WindowEventType;<br>方法or属性：WINDOW_ACTIVE = 2|@ohos.window.d.ts|
|新增|NA|类名：WindowEventType;<br>方法or属性：WINDOW_INACTIVE = 3|@ohos.window.d.ts|
|新增|NA|类名：WindowEventType;<br>方法or属性：WINDOW_HIDDEN = 4|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：getUIContext() : UIContext;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：on(type: 'dialogTargetTouch', callback: Callback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：on(type: 'windowEvent', callback: Callback\<WindowEventType>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：off(type: 'dialogTargetTouch', callback?: Callback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：off(type: 'windowEvent', callback?: Callback\<WindowEventType>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：raiseToAppTop(callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：raiseToAppTop(): Promise\<void>;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setAspectRatio(ratio: number, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setAspectRatio(ratio: number): Promise\<void>;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：resetAspectRatio(callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：resetAspectRatio(): Promise\<void>;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setWaterMarkFlag(enable: boolean, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window;<br>方法or属性：setWaterMarkFlag(enable: boolean): Promise\<void>;|@ohos.window.d.ts|
|新增(错误码)|类名：screen;<br>方法or属性：function getAllScreens(): Promise\<Array\<Screen>>;<br>旧版本信息：|类名：screen;<br>方法or属性：function getAllScreens(): Promise\<Array\<Screen>>;<br>新版本信息：1400001|@ohos.screen.d.ts|
|新增(错误码)|类名：screen;<br>方法or属性：function makeExpand(options: Array\<ExpandOption>): Promise\<number>;<br>旧版本信息：|类名：screen;<br>方法or属性：function makeExpand(options: Array\<ExpandOption>): Promise\<number>;<br>新版本信息：401,1400001|@ohos.screen.d.ts|
|新增(错误码)|类名：screen;<br>方法or属性：function makeMirror(mainScreen: number, mirrorScreen: Array\<number>): Promise\<number>;<br>旧版本信息：|类名：screen;<br>方法or属性：function makeMirror(mainScreen: number, mirrorScreen: Array\<number>): Promise\<number>;<br>新版本信息：401,1400001|@ohos.screen.d.ts|
|新增(错误码)|类名：screen;<br>方法or属性：function createVirtualScreen(options: VirtualScreenOption): Promise\<Screen>;<br>旧版本信息：|类名：screen;<br>方法or属性：function createVirtualScreen(options: VirtualScreenOption): Promise\<Screen>;<br>新版本信息：201,401,1400001|@ohos.screen.d.ts|
|新增(错误码)|类名：screen;<br>方法or属性：function destroyVirtualScreen(screenId: number): Promise\<void>;<br>旧版本信息：|类名：screen;<br>方法or属性：function destroyVirtualScreen(screenId: number): Promise\<void>;<br>新版本信息：401,1400002|@ohos.screen.d.ts|
|新增(错误码)|类名：screen;<br>方法or属性：function setVirtualScreenSurface(screenId: number, surfaceId: string): Promise\<void>;<br>旧版本信息：|类名：screen;<br>方法or属性：function setVirtualScreenSurface(screenId: number, surfaceId: string): Promise\<void>;<br>新版本信息：201,401,1400001|@ohos.screen.d.ts|
|新增(错误码)|类名：screen;<br>方法or属性：function setScreenRotationLocked(isLocked: boolean): Promise\<void>;<br>旧版本信息：|类名：screen;<br>方法or属性：function setScreenRotationLocked(isLocked: boolean): Promise\<void>;<br>新版本信息：401|@ohos.screen.d.ts|
|新增(错误码)|类名：Screen;<br>方法or属性：setOrientation(orientation: Orientation): Promise\<void>;<br>旧版本信息：|类名：Screen;<br>方法or属性：setOrientation(orientation: Orientation): Promise\<void>;<br>新版本信息：401,1400003|@ohos.screen.d.ts|
|新增(错误码)|类名：Screen;<br>方法or属性：setScreenActiveMode(modeIndex: number): Promise\<void>;<br>旧版本信息：|类名：Screen;<br>方法or属性：setScreenActiveMode(modeIndex: number): Promise\<void>;<br>新版本信息：401,1400003|@ohos.screen.d.ts|
|新增(错误码)|类名：Screen;<br>方法or属性：setDensityDpi(densityDpi: number): Promise\<void>;<br>旧版本信息：|类名：Screen;<br>方法or属性：setDensityDpi(densityDpi: number): Promise\<void>;<br>新版本信息：401,1400003|@ohos.screen.d.ts|
|错误码有变化|类名：window;<br>方法or属性：function createWindow(config: Configuration, callback: AsyncCallback\<Window>): void;<br>旧版本信息：201,401,1300001,1300006|类名：window;<br>方法or属性：function createWindow(config: Configuration, callback: AsyncCallback\<Window>): void;<br>新版本信息：201,401,1300001,1300006,1300008,1300009|@ohos.window.d.ts|
|错误码有变化|类名：window;<br>方法or属性：function createWindow(config: Configuration): Promise\<Window>;<br>旧版本信息：201,401,1300001,1300006|类名：window;<br>方法or属性：function createWindow(config: Configuration): Promise\<Window>;<br>新版本信息：201,401,1300001,1300006,1300008,1300009|@ohos.window.d.ts|
|错误码有变化|类名：window;<br>方法or属性：function findWindow(name: string): Window;<br>旧版本信息：401|类名：window;<br>方法or属性：function findWindow(name: string): Window;<br>新版本信息：401,1300002|@ohos.window.d.ts|
|错误码有变化|类名：Window;<br>方法or属性：setWindowSystemBarProperties(systemBarProperties: SystemBarProperties, callback: AsyncCallback\<void>): void;<br>旧版本信息：401,1300002,1300003|类名：Window;<br>方法or属性：setWindowSystemBarProperties(systemBarProperties: SystemBarProperties, callback: AsyncCallback\<void>): void;<br>新版本信息：401,801,1300002,1300003|@ohos.window.d.ts|
|错误码有变化|类名：Window;<br>方法or属性：setWindowSystemBarProperties(systemBarProperties: SystemBarProperties): Promise\<void>;<br>旧版本信息：401,1300002,1300003|类名：Window;<br>方法or属性：setWindowSystemBarProperties(systemBarProperties: SystemBarProperties): Promise\<void>;<br>新版本信息：401,801,1300002,1300003|@ohos.window.d.ts|
|访问级别有变化|类名：RRect;<br>方法or属性：left: number;<br>旧版本信息：|类名：RRect;<br>方法or属性：left: number;<br>新版本信息：systemapi|@ohos.animation.windowAnimationManager.d.ts|
|访问级别有变化|类名：RRect;<br>方法or属性：top: number;<br>旧版本信息：|类名：RRect;<br>方法or属性：top: number;<br>新版本信息：systemapi|@ohos.animation.windowAnimationManager.d.ts|
|访问级别有变化|类名：RRect;<br>方法or属性：width: number;<br>旧版本信息：|类名：RRect;<br>方法or属性：width: number;<br>新版本信息：systemapi|@ohos.animation.windowAnimationManager.d.ts|
|访问级别有变化|类名：RRect;<br>方法or属性：height: number;<br>旧版本信息：|类名：RRect;<br>方法or属性：height: number;<br>新版本信息：systemapi|@ohos.animation.windowAnimationManager.d.ts|
|访问级别有变化|类名：RRect;<br>方法or属性：radius: number;<br>旧版本信息：|类名：RRect;<br>方法or属性：radius: number;<br>新版本信息：systemapi|@ohos.animation.windowAnimationManager.d.ts|
|访问级别有变化|类名：WindowAnimationTarget;<br>方法or属性：readonly bundleName: string;<br>旧版本信息：|类名：WindowAnimationTarget;<br>方法or属性：readonly bundleName: string;<br>新版本信息：systemapi|@ohos.animation.windowAnimationManager.d.ts|
|访问级别有变化|类名：WindowAnimationTarget;<br>方法or属性：readonly abilityName: string;<br>旧版本信息：|类名：WindowAnimationTarget;<br>方法or属性：readonly abilityName: string;<br>新版本信息：systemapi|@ohos.animation.windowAnimationManager.d.ts|
|访问级别有变化|类名：WindowAnimationTarget;<br>方法or属性：readonly windowBounds: RRect;<br>旧版本信息：|类名：WindowAnimationTarget;<br>方法or属性：readonly windowBounds: RRect;<br>新版本信息：systemapi|@ohos.animation.windowAnimationManager.d.ts|
|访问级别有变化|类名：WindowAnimationTarget;<br>方法or属性：readonly missionId: number;<br>旧版本信息：|类名：WindowAnimationTarget;<br>方法or属性：readonly missionId: number;<br>新版本信息：systemapi|@ohos.animation.windowAnimationManager.d.ts|
|访问级别有变化|类名：screen;<br>方法or属性：function getAllScreens(callback: AsyncCallback\<Array\<Screen>>): void;<br>旧版本信息：|类名：screen;<br>方法or属性：function getAllScreens(callback: AsyncCallback\<Array\<Screen>>): void;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：screen;<br>方法or属性：function getAllScreens(): Promise\<Array\<Screen>>;<br>旧版本信息：|类名：screen;<br>方法or属性：function getAllScreens(): Promise\<Array\<Screen>>;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：screen;<br>方法or属性：function on(eventType: 'connect' \| 'disconnect' \| 'change', callback: Callback\<number>): void;<br>旧版本信息：|类名：screen;<br>方法or属性：function on(eventType: 'connect' \| 'disconnect' \| 'change', callback: Callback\<number>): void;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：screen;<br>方法or属性：function off(eventType: 'connect' \| 'disconnect' \| 'change', callback?: Callback\<number>): void;<br>旧版本信息：|类名：screen;<br>方法or属性：function off(eventType: 'connect' \| 'disconnect' \| 'change', callback?: Callback\<number>): void;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：screen;<br>方法or属性：function makeExpand(options: Array\<ExpandOption>, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：screen;<br>方法or属性：function makeExpand(options: Array\<ExpandOption>, callback: AsyncCallback\<number>): void;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：screen;<br>方法or属性：function makeExpand(options: Array\<ExpandOption>): Promise\<number>;<br>旧版本信息：|类名：screen;<br>方法or属性：function makeExpand(options: Array\<ExpandOption>): Promise\<number>;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：screen;<br>方法or属性：function makeMirror(mainScreen: number, mirrorScreen: Array\<number>, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：screen;<br>方法or属性：function makeMirror(mainScreen: number, mirrorScreen: Array\<number>, callback: AsyncCallback\<number>): void;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：screen;<br>方法or属性：function makeMirror(mainScreen: number, mirrorScreen: Array\<number>): Promise\<number>;<br>旧版本信息：|类名：screen;<br>方法or属性：function makeMirror(mainScreen: number, mirrorScreen: Array\<number>): Promise\<number>;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：screen;<br>方法or属性：function createVirtualScreen(options: VirtualScreenOption, callback: AsyncCallback\<Screen>): void;<br>旧版本信息：|类名：screen;<br>方法or属性：function createVirtualScreen(options: VirtualScreenOption, callback: AsyncCallback\<Screen>): void;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：screen;<br>方法or属性：function createVirtualScreen(options: VirtualScreenOption): Promise\<Screen>;<br>旧版本信息：|类名：screen;<br>方法or属性：function createVirtualScreen(options: VirtualScreenOption): Promise\<Screen>;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：screen;<br>方法or属性：function destroyVirtualScreen(screenId: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：screen;<br>方法or属性：function destroyVirtualScreen(screenId: number, callback: AsyncCallback\<void>): void;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：screen;<br>方法or属性：function destroyVirtualScreen(screenId: number): Promise\<void>;<br>旧版本信息：|类名：screen;<br>方法or属性：function destroyVirtualScreen(screenId: number): Promise\<void>;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：screen;<br>方法or属性：function setVirtualScreenSurface(screenId: number, surfaceId: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：screen;<br>方法or属性：function setVirtualScreenSurface(screenId: number, surfaceId: string, callback: AsyncCallback\<void>): void;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：screen;<br>方法or属性：function setVirtualScreenSurface(screenId: number, surfaceId: string): Promise\<void>;<br>旧版本信息：|类名：screen;<br>方法or属性：function setVirtualScreenSurface(screenId: number, surfaceId: string): Promise\<void>;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：screen;<br>方法or属性：function isScreenRotationLocked(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：screen;<br>方法or属性：function isScreenRotationLocked(callback: AsyncCallback\<boolean>): void;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：screen;<br>方法or属性：function isScreenRotationLocked(): Promise\<boolean>;<br>旧版本信息：|类名：screen;<br>方法or属性：function isScreenRotationLocked(): Promise\<boolean>;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：screen;<br>方法or属性：function setScreenRotationLocked(isLocked: boolean, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：screen;<br>方法or属性：function setScreenRotationLocked(isLocked: boolean, callback: AsyncCallback\<void>): void;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：screen;<br>方法or属性：function setScreenRotationLocked(isLocked: boolean): Promise\<void>;<br>旧版本信息：|类名：screen;<br>方法or属性：function setScreenRotationLocked(isLocked: boolean): Promise\<void>;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：ExpandOption;<br>方法or属性：interface ExpandOption<br>旧版本信息：|类名：ExpandOption;<br>方法or属性：interface ExpandOption<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：ExpandOption;<br>方法or属性：screenId: number;<br>旧版本信息：|类名：ExpandOption;<br>方法or属性：screenId: number;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：ExpandOption;<br>方法or属性：startX: number;<br>旧版本信息：|类名：ExpandOption;<br>方法or属性：startX: number;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：ExpandOption;<br>方法or属性：startY: number;<br>旧版本信息：|类名：ExpandOption;<br>方法or属性：startY: number;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：VirtualScreenOption;<br>方法or属性：interface VirtualScreenOption<br>旧版本信息：|类名：VirtualScreenOption;<br>方法or属性：interface VirtualScreenOption<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：VirtualScreenOption;<br>方法or属性：name: string;<br>旧版本信息：|类名：VirtualScreenOption;<br>方法or属性：name: string;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：VirtualScreenOption;<br>方法or属性：width: number;<br>旧版本信息：|类名：VirtualScreenOption;<br>方法or属性：width: number;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：VirtualScreenOption;<br>方法or属性：height: number;<br>旧版本信息：|类名：VirtualScreenOption;<br>方法or属性：height: number;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：VirtualScreenOption;<br>方法or属性：density: number;<br>旧版本信息：|类名：VirtualScreenOption;<br>方法or属性：density: number;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：VirtualScreenOption;<br>方法or属性：surfaceId: string;<br>旧版本信息：|类名：VirtualScreenOption;<br>方法or属性：surfaceId: string;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：Screen;<br>方法or属性：interface Screen<br>旧版本信息：|类名：Screen;<br>方法or属性：interface Screen<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：Screen;<br>方法or属性：readonly id: number;<br>旧版本信息：|类名：Screen;<br>方法or属性：readonly id: number;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：Screen;<br>方法or属性：readonly parent: number;<br>旧版本信息：|类名：Screen;<br>方法or属性：readonly parent: number;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：Screen;<br>方法or属性：readonly supportedModeInfo: Array\<ScreenModeInfo>;<br>旧版本信息：|类名：Screen;<br>方法or属性：readonly supportedModeInfo: Array\<ScreenModeInfo>;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：Screen;<br>方法or属性：readonly activeModeIndex: number;<br>旧版本信息：|类名：Screen;<br>方法or属性：readonly activeModeIndex: number;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：Screen;<br>方法or属性：readonly orientation: Orientation;<br>旧版本信息：|类名：Screen;<br>方法or属性：readonly orientation: Orientation;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：Screen;<br>方法or属性：setOrientation(orientation: Orientation, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Screen;<br>方法or属性：setOrientation(orientation: Orientation, callback: AsyncCallback\<void>): void;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：Screen;<br>方法or属性：setOrientation(orientation: Orientation): Promise\<void>;<br>旧版本信息：|类名：Screen;<br>方法or属性：setOrientation(orientation: Orientation): Promise\<void>;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：Screen;<br>方法or属性：setScreenActiveMode(modeIndex: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Screen;<br>方法or属性：setScreenActiveMode(modeIndex: number, callback: AsyncCallback\<void>): void;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：Screen;<br>方法or属性：setScreenActiveMode(modeIndex: number): Promise\<void>;<br>旧版本信息：|类名：Screen;<br>方法or属性：setScreenActiveMode(modeIndex: number): Promise\<void>;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：Screen;<br>方法or属性：setDensityDpi(densityDpi: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Screen;<br>方法or属性：setDensityDpi(densityDpi: number, callback: AsyncCallback\<void>): void;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：Screen;<br>方法or属性：setDensityDpi(densityDpi: number): Promise\<void>;<br>旧版本信息：|类名：Screen;<br>方法or属性：setDensityDpi(densityDpi: number): Promise\<void>;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：Orientation;<br>方法or属性：enum Orientation<br>旧版本信息：|类名：Orientation;<br>方法or属性：enum Orientation<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：ScreenModeInfo;<br>方法or属性：interface ScreenModeInfo<br>旧版本信息：|类名：ScreenModeInfo;<br>方法or属性：interface ScreenModeInfo<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：screenshot;<br>方法or属性：function save(options: ScreenshotOptions, callback: AsyncCallback\<image.PixelMap>): void;<br>旧版本信息：|类名：screenshot;<br>方法or属性：function save(options: ScreenshotOptions, callback: AsyncCallback\<image.PixelMap>): void;<br>新版本信息：systemapi|@ohos.screenshot.d.ts|
|访问级别有变化|类名：screenshot;<br>方法or属性：function save(callback: AsyncCallback\<image.PixelMap>): void;<br>旧版本信息：|类名：screenshot;<br>方法or属性：function save(callback: AsyncCallback\<image.PixelMap>): void;<br>新版本信息：systemapi|@ohos.screenshot.d.ts|
|访问级别有变化|类名：screenshot;<br>方法or属性：function save(options?: ScreenshotOptions): Promise\<image.PixelMap>;<br>旧版本信息：|类名：screenshot;<br>方法or属性：function save(options?: ScreenshotOptions): Promise\<image.PixelMap>;<br>新版本信息：systemapi|@ohos.screenshot.d.ts|
|访问级别有变化|类名：Rect;<br>方法or属性：interface Rect<br>旧版本信息：|类名：Rect;<br>方法or属性：interface Rect<br>新版本信息：systemapi|@ohos.screenshot.d.ts|
|访问级别有变化|类名：Size;<br>方法or属性：interface Size<br>旧版本信息：|类名：Size;<br>方法or属性：interface Size<br>新版本信息：systemapi|@ohos.screenshot.d.ts|
|访问级别有变化|类名：ScreenshotOptions;<br>方法or属性：interface ScreenshotOptions<br>旧版本信息：|类名：ScreenshotOptions;<br>方法or属性：interface ScreenshotOptions<br>新版本信息：systemapi|@ohos.screenshot.d.ts|
|访问级别有变化|类名：ScreenshotOptions;<br>方法or属性：screenRect?: Rect;<br>旧版本信息：|类名：ScreenshotOptions;<br>方法or属性：screenRect?: Rect;<br>新版本信息：systemapi|@ohos.screenshot.d.ts|
|访问级别有变化|类名：ScreenshotOptions;<br>方法or属性：imageSize?: Size;<br>旧版本信息：|类名：ScreenshotOptions;<br>方法or属性：imageSize?: Size;<br>新版本信息：systemapi|@ohos.screenshot.d.ts|
|访问级别有变化|类名：ScreenshotOptions;<br>方法or属性：rotation?: number;<br>旧版本信息：|类名：ScreenshotOptions;<br>方法or属性：rotation?: number;<br>新版本信息：systemapi|@ohos.screenshot.d.ts|
|访问级别有变化|类名：ScreenshotOptions;<br>方法or属性：displayId?: number;<br>旧版本信息：|类名：ScreenshotOptions;<br>方法or属性：displayId?: number;<br>新版本信息：systemapi|@ohos.screenshot.d.ts|
|访问级别有变化|类名：WindowType;<br>方法or属性：TYPE_DIALOG<br>旧版本信息：systemapi|类名：WindowType;<br>方法or属性：TYPE_DIALOG<br>新版本信息：|@ohos.window.d.ts|
|访问级别有变化|类名：SystemBarRegionTint;<br>方法or属性：type: WindowType;<br>旧版本信息：|类名：SystemBarRegionTint;<br>方法or属性：type: WindowType;<br>新版本信息：systemapi|@ohos.window.d.ts|
|访问级别有变化|类名：SystemBarRegionTint;<br>方法or属性：isEnable?: boolean;<br>旧版本信息：|类名：SystemBarRegionTint;<br>方法or属性：isEnable?: boolean;<br>新版本信息：systemapi|@ohos.window.d.ts|
|访问级别有变化|类名：SystemBarRegionTint;<br>方法or属性：region?: Rect;<br>旧版本信息：|类名：SystemBarRegionTint;<br>方法or属性：region?: Rect;<br>新版本信息：systemapi|@ohos.window.d.ts|
|访问级别有变化|类名：SystemBarRegionTint;<br>方法or属性：backgroundColor?: string;<br>旧版本信息：|类名：SystemBarRegionTint;<br>方法or属性：backgroundColor?: string;<br>新版本信息：systemapi|@ohos.window.d.ts|
|访问级别有变化|类名：SystemBarRegionTint;<br>方法or属性：contentColor?: string;<br>旧版本信息：|类名：SystemBarRegionTint;<br>方法or属性：contentColor?: string;<br>新版本信息：systemapi|@ohos.window.d.ts|
|访问级别有变化|类名：SystemBarTintState;<br>方法or属性：displayId: number;<br>旧版本信息：|类名：SystemBarTintState;<br>方法or属性：displayId: number;<br>新版本信息：systemapi|@ohos.window.d.ts|
|访问级别有变化|类名：SystemBarTintState;<br>方法or属性：regionTint: Array\<SystemBarRegionTint>;<br>旧版本信息：|类名：SystemBarTintState;<br>方法or属性：regionTint: Array\<SystemBarRegionTint>;<br>新版本信息：systemapi|@ohos.window.d.ts|
|访问级别有变化|类名：ScaleOptions;<br>方法or属性：x?: number;<br>旧版本信息：|类名：ScaleOptions;<br>方法or属性：x?: number;<br>新版本信息：systemapi|@ohos.window.d.ts|
|访问级别有变化|类名：RotateOptions;<br>方法or属性：x?: number;<br>旧版本信息：|类名：RotateOptions;<br>方法or属性：x?: number;<br>新版本信息：systemapi|@ohos.window.d.ts|
|访问级别有变化|类名：TranslateOptions;<br>方法or属性：x?: number;<br>旧版本信息：|类名：TranslateOptions;<br>方法or属性：x?: number;<br>新版本信息：systemapi|@ohos.window.d.ts|
|访问级别有变化|类名：ScaleOptions;<br>方法or属性：y?: number;<br>旧版本信息：|类名：ScaleOptions;<br>方法or属性：y?: number;<br>新版本信息：systemapi|@ohos.window.d.ts|
|访问级别有变化|类名：RotateOptions;<br>方法or属性：y?: number;<br>旧版本信息：|类名：RotateOptions;<br>方法or属性：y?: number;<br>新版本信息：systemapi|@ohos.window.d.ts|
|访问级别有变化|类名：TranslateOptions;<br>方法or属性：y?: number;<br>旧版本信息：|类名：TranslateOptions;<br>方法or属性：y?: number;<br>新版本信息：systemapi|@ohos.window.d.ts|
|访问级别有变化|类名：ScaleOptions;<br>方法or属性：pivotX?: number;<br>旧版本信息：|类名：ScaleOptions;<br>方法or属性：pivotX?: number;<br>新版本信息：systemapi|@ohos.window.d.ts|
|访问级别有变化|类名：RotateOptions;<br>方法or属性：pivotX?: number;<br>旧版本信息：|类名：RotateOptions;<br>方法or属性：pivotX?: number;<br>新版本信息：systemapi|@ohos.window.d.ts|
|访问级别有变化|类名：ScaleOptions;<br>方法or属性：pivotY?: number;<br>旧版本信息：|类名：ScaleOptions;<br>方法or属性：pivotY?: number;<br>新版本信息：systemapi|@ohos.window.d.ts|
|访问级别有变化|类名：RotateOptions;<br>方法or属性：pivotY?: number;<br>旧版本信息：|类名：RotateOptions;<br>方法or属性：pivotY?: number;<br>新版本信息：systemapi|@ohos.window.d.ts|
|访问级别有变化|类名：RotateOptions;<br>方法or属性：z?: number;<br>旧版本信息：|类名：RotateOptions;<br>方法or属性：z?: number;<br>新版本信息：systemapi|@ohos.window.d.ts|
|访问级别有变化|类名：TranslateOptions;<br>方法or属性：z?: number;<br>旧版本信息：|类名：TranslateOptions;<br>方法or属性：z?: number;<br>新版本信息：systemapi|@ohos.window.d.ts|
|访问级别有变化|类名：TransitionContext;<br>方法or属性：toWindow: Window;<br>旧版本信息：|类名：TransitionContext;<br>方法or属性：toWindow: Window;<br>新版本信息：systemapi|@ohos.window.d.ts|
|访问级别有变化|类名：TransitionContext;<br>方法or属性：completeTransition(isCompleted: boolean): void;<br>旧版本信息：|类名：TransitionContext;<br>方法or属性：completeTransition(isCompleted: boolean): void;<br>新版本信息：systemapi|@ohos.window.d.ts|
|访问级别有变化|类名：TransitionController;<br>方法or属性：animationForShown(context: TransitionContext): void;<br>旧版本信息：|类名：TransitionController;<br>方法or属性：animationForShown(context: TransitionContext): void;<br>新版本信息：systemapi|@ohos.window.d.ts|
|访问级别有变化|类名：TransitionController;<br>方法or属性：animationForHidden(context: TransitionContext): void;<br>旧版本信息：|类名：TransitionController;<br>方法or属性：animationForHidden(context: TransitionContext): void;<br>新版本信息：systemapi|@ohos.window.d.ts|
|访问级别有变化|类名：BlurStyle;<br>方法or属性：OFF<br>旧版本信息：|类名：BlurStyle;<br>方法or属性：OFF<br>新版本信息：systemapi|@ohos.window.d.ts|
|访问级别有变化|类名：BlurStyle;<br>方法or属性：THIN<br>旧版本信息：|类名：BlurStyle;<br>方法or属性：THIN<br>新版本信息：systemapi|@ohos.window.d.ts|
|访问级别有变化|类名：BlurStyle;<br>方法or属性：REGULAR<br>旧版本信息：|类名：BlurStyle;<br>方法or属性：REGULAR<br>新版本信息：systemapi|@ohos.window.d.ts|
|访问级别有变化|类名：BlurStyle;<br>方法or属性：THICK<br>旧版本信息：|类名：BlurStyle;<br>方法or属性：THICK<br>新版本信息：systemapi|@ohos.window.d.ts|
|权限有变化|类名：screen;<br>方法or属性：function createVirtualScreen(options: VirtualScreenOption): Promise\<Screen>;<br>旧版本信息：|类名：screen;<br>方法or属性：function createVirtualScreen(options: VirtualScreenOption): Promise\<Screen>;<br>新版本信息：ohos.permission.CAPTURE_SCREEN|@ohos.screen.d.ts|
|权限有变化|类名：screen;<br>方法or属性：function setVirtualScreenSurface(screenId: number, surfaceId: string): Promise\<void>;<br>旧版本信息：|类名：screen;<br>方法or属性：function setVirtualScreenSurface(screenId: number, surfaceId: string): Promise\<void>;<br>新版本信息：ohos.permission.CAPTURE_SCREEN|@ohos.screen.d.ts|
|model有变化|类名：WindowStageEventType;<br>方法or属性：SHOWN = 1<br>旧版本信息：|类名：WindowStageEventType;<br>方法or属性：SHOWN = 1<br>新版本信息：StageModelOnly|@ohos.window.d.ts|
|model有变化|类名：WindowStageEventType;<br>方法or属性：ACTIVE<br>旧版本信息：|类名：WindowStageEventType;<br>方法or属性：ACTIVE<br>新版本信息：StageModelOnly|@ohos.window.d.ts|
|model有变化|类名：WindowStageEventType;<br>方法or属性：INACTIVE<br>旧版本信息：|类名：WindowStageEventType;<br>方法or属性：INACTIVE<br>新版本信息：StageModelOnly|@ohos.window.d.ts|
|model有变化|类名：WindowStageEventType;<br>方法or属性：HIDDEN<br>旧版本信息：|类名：WindowStageEventType;<br>方法or属性：HIDDEN<br>新版本信息：StageModelOnly|@ohos.window.d.ts|
|type有变化|类名：RRect;<br>方法or属性：left: number;<br>旧版本信息：|类名：RRect;<br>方法or属性：left: number;<br>新版本信息：number|@ohos.animation.windowAnimationManager.d.ts|
|type有变化|类名：RRect;<br>方法or属性：top: number;<br>旧版本信息：|类名：RRect;<br>方法or属性：top: number;<br>新版本信息：number|@ohos.animation.windowAnimationManager.d.ts|
|type有变化|类名：RRect;<br>方法or属性：width: number;<br>旧版本信息：|类名：RRect;<br>方法or属性：width: number;<br>新版本信息：number|@ohos.animation.windowAnimationManager.d.ts|
|type有变化|类名：RRect;<br>方法or属性：height: number;<br>旧版本信息：|类名：RRect;<br>方法or属性：height: number;<br>新版本信息：number|@ohos.animation.windowAnimationManager.d.ts|
|type有变化|类名：RRect;<br>方法or属性：radius: number;<br>旧版本信息：|类名：RRect;<br>方法or属性：radius: number;<br>新版本信息：number|@ohos.animation.windowAnimationManager.d.ts|
|type有变化|类名：WindowAnimationTarget;<br>方法or属性：readonly bundleName: string;<br>旧版本信息：|类名：WindowAnimationTarget;<br>方法or属性：readonly bundleName: string;<br>新版本信息：string|@ohos.animation.windowAnimationManager.d.ts|
|type有变化|类名：WindowAnimationTarget;<br>方法or属性：readonly abilityName: string;<br>旧版本信息：|类名：WindowAnimationTarget;<br>方法or属性：readonly abilityName: string;<br>新版本信息：string|@ohos.animation.windowAnimationManager.d.ts|
|type有变化|类名：WindowAnimationTarget;<br>方法or属性：readonly windowBounds: RRect;<br>旧版本信息：|类名：WindowAnimationTarget;<br>方法or属性：readonly windowBounds: RRect;<br>新版本信息：RRect|@ohos.animation.windowAnimationManager.d.ts|
|type有变化|类名：WindowAnimationTarget;<br>方法or属性：readonly missionId: number;<br>旧版本信息：|类名：WindowAnimationTarget;<br>方法or属性：readonly missionId: number;<br>新版本信息：number|@ohos.animation.windowAnimationManager.d.ts|
|type有变化|类名：WindowProperties;<br>方法or属性：type: WindowType;<br>旧版本信息：|类名：WindowProperties;<br>方法or属性：type: WindowType;<br>新版本信息：WindowType|@ohos.window.d.ts|
|type有变化|类名：Size;<br>方法or属性：width: number;<br>旧版本信息：|类名：Size;<br>方法or属性：width: number;<br>新版本信息：number|@ohos.window.d.ts|
|type有变化|类名：Size;<br>方法or属性：height: number;<br>旧版本信息：|类名：Size;<br>方法or属性：height: number;<br>新版本信息：number|@ohos.window.d.ts|
|type有变化|类名：AvoidArea;<br>方法or属性：visible: boolean;<br>旧版本信息：|类名：AvoidArea;<br>方法or属性：visible: boolean;<br>新版本信息：boolean|@ohos.window.d.ts|
|type有变化|类名：AvoidArea;<br>方法or属性：leftRect: Rect;<br>旧版本信息：|类名：AvoidArea;<br>方法or属性：leftRect: Rect;<br>新版本信息：Rect|@ohos.window.d.ts|
|type有变化|类名：AvoidArea;<br>方法or属性：topRect: Rect;<br>旧版本信息：|类名：AvoidArea;<br>方法or属性：topRect: Rect;<br>新版本信息：Rect|@ohos.window.d.ts|
|type有变化|类名：AvoidArea;<br>方法or属性：rightRect: Rect;<br>旧版本信息：|类名：AvoidArea;<br>方法or属性：rightRect: Rect;<br>新版本信息：Rect|@ohos.window.d.ts|
|type有变化|类名：AvoidArea;<br>方法or属性：bottomRect: Rect;<br>旧版本信息：|类名：AvoidArea;<br>方法or属性：bottomRect: Rect;<br>新版本信息：Rect|@ohos.window.d.ts|
|type有变化|类名：WindowProperties;<br>方法or属性：windowRect: Rect;<br>旧版本信息：|类名：WindowProperties;<br>方法or属性：windowRect: Rect;<br>新版本信息：Rect|@ohos.window.d.ts|
|type有变化|类名：WindowProperties;<br>方法or属性：isFullScreen: boolean;<br>旧版本信息：|类名：WindowProperties;<br>方法or属性：isFullScreen: boolean;<br>新版本信息：boolean|@ohos.window.d.ts|
|type有变化|类名：WindowProperties;<br>方法or属性：isLayoutFullScreen: boolean;<br>旧版本信息：|类名：WindowProperties;<br>方法or属性：isLayoutFullScreen: boolean;<br>新版本信息：boolean|@ohos.window.d.ts|
|type有变化|类名：WindowProperties;<br>方法or属性：focusable: boolean;<br>旧版本信息：|类名：WindowProperties;<br>方法or属性：focusable: boolean;<br>新版本信息：boolean|@ohos.window.d.ts|
|type有变化|类名：WindowProperties;<br>方法or属性：touchable: boolean;<br>旧版本信息：|类名：WindowProperties;<br>方法or属性：touchable: boolean;<br>新版本信息：boolean|@ohos.window.d.ts|
|type有变化|类名：WindowProperties;<br>方法or属性：brightness: number;<br>旧版本信息：|类名：WindowProperties;<br>方法or属性：brightness: number;<br>新版本信息：number|@ohos.window.d.ts|
|type有变化|类名：WindowProperties;<br>方法or属性：dimBehindValue: number;<br>旧版本信息：|类名：WindowProperties;<br>方法or属性：dimBehindValue: number;<br>新版本信息：number|@ohos.window.d.ts|
|type有变化|类名：WindowProperties;<br>方法or属性：isKeepScreenOn: boolean;<br>旧版本信息：|类名：WindowProperties;<br>方法or属性：isKeepScreenOn: boolean;<br>新版本信息：boolean|@ohos.window.d.ts|
|type有变化|类名：WindowProperties;<br>方法or属性：isPrivacyMode: boolean;<br>旧版本信息：|类名：WindowProperties;<br>方法or属性：isPrivacyMode: boolean;<br>新版本信息：boolean|@ohos.window.d.ts|
|type有变化|类名：WindowProperties;<br>方法or属性：isRoundCorner: boolean;<br>旧版本信息：|类名：WindowProperties;<br>方法or属性：isRoundCorner: boolean;<br>新版本信息：boolean|@ohos.window.d.ts|
|type有变化|类名：WindowProperties;<br>方法or属性：isTransparent: boolean;<br>旧版本信息：|类名：WindowProperties;<br>方法or属性：isTransparent: boolean;<br>新版本信息：boolean|@ohos.window.d.ts|
|type有变化|类名：WindowProperties;<br>方法or属性：id: number;<br>旧版本信息：|类名：WindowProperties;<br>方法or属性：id: number;<br>新版本信息：number|@ohos.window.d.ts|
|type有变化|类名：RotateOptions;<br>方法or属性：x?: number;<br>旧版本信息：|类名：RotateOptions;<br>方法or属性：x?: number;<br>新版本信息：?number|@ohos.window.d.ts|
|type有变化|类名：TranslateOptions;<br>方法or属性：x?: number;<br>旧版本信息：|类名：TranslateOptions;<br>方法or属性：x?: number;<br>新版本信息：?number|@ohos.window.d.ts|
|type有变化|类名：RotateOptions;<br>方法or属性：y?: number;<br>旧版本信息：|类名：RotateOptions;<br>方法or属性：y?: number;<br>新版本信息：?number|@ohos.window.d.ts|
|type有变化|类名：TranslateOptions;<br>方法or属性：y?: number;<br>旧版本信息：|类名：TranslateOptions;<br>方法or属性：y?: number;<br>新版本信息：?number|@ohos.window.d.ts|
|type有变化|类名：RotateOptions;<br>方法or属性：pivotX?: number;<br>旧版本信息：|类名：RotateOptions;<br>方法or属性：pivotX?: number;<br>新版本信息：?number|@ohos.window.d.ts|
|type有变化|类名：RotateOptions;<br>方法or属性：pivotY?: number;<br>旧版本信息：|类名：RotateOptions;<br>方法or属性：pivotY?: number;<br>新版本信息：?number|@ohos.window.d.ts|
|type有变化|类名：RotateOptions;<br>方法or属性：z?: number;<br>旧版本信息：|类名：RotateOptions;<br>方法or属性：z?: number;<br>新版本信息：?number|@ohos.window.d.ts|
|type有变化|类名：TranslateOptions;<br>方法or属性：z?: number;<br>旧版本信息：|类名：TranslateOptions;<br>方法or属性：z?: number;<br>新版本信息：?number|@ohos.window.d.ts|
|type有变化|类名：TransitionContext;<br>方法or属性：toWindow: Window;<br>旧版本信息：|类名：TransitionContext;<br>方法or属性：toWindow: Window;<br>新版本信息：Window|@ohos.window.d.ts|
|type有变化|类名：Configuration;<br>方法or属性：windowType: WindowType;<br>旧版本信息：|类名：Configuration;<br>方法or属性：windowType: WindowType;<br>新版本信息：WindowType|@ohos.window.d.ts|
|type有变化|类名：Configuration;<br>方法or属性：ctx?: BaseContext;<br>旧版本信息：|类名：Configuration;<br>方法or属性：ctx?: BaseContext;<br>新版本信息：?BaseContext|@ohos.window.d.ts|
|type有变化|类名：Configuration;<br>方法or属性：displayId?: number;<br>旧版本信息：|类名：Configuration;<br>方法or属性：displayId?: number;<br>新版本信息：?number|@ohos.window.d.ts|
|type有变化|类名：Configuration;<br>方法or属性：parentId?: number;<br>旧版本信息：|类名：Configuration;<br>方法or属性：parentId?: number;<br>新版本信息：?number|@ohos.window.d.ts|
|跨平台能力有变化|类名：display;<br>方法or属性：declare display<br>旧版本信息：|类名：display;<br>方法or属性：declare display<br>新版本信息：crossplatform|@ohos.display.d.ts|
|跨平台能力有变化|类名：display;<br>方法or属性：function getDefaultDisplaySync(): Display;<br>旧版本信息：|类名：display;<br>方法or属性：function getDefaultDisplaySync(): Display;<br>新版本信息：crossplatform|@ohos.display.d.ts|
|跨平台能力有变化|类名：Display;<br>方法or属性：interface Display<br>旧版本信息：|类名：Display;<br>方法or属性：interface Display<br>新版本信息：crossplatform|@ohos.display.d.ts|
|跨平台能力有变化|类名：Display;<br>方法or属性：id: number;<br>旧版本信息：|类名：Display;<br>方法or属性：id: number;<br>新版本信息：crossplatform|@ohos.display.d.ts|
|跨平台能力有变化|类名：Display;<br>方法or属性：width: number;<br>旧版本信息：|类名：Display;<br>方法or属性：width: number;<br>新版本信息：crossplatform|@ohos.display.d.ts|
|跨平台能力有变化|类名：Display;<br>方法or属性：height: number;<br>旧版本信息：|类名：Display;<br>方法or属性：height: number;<br>新版本信息：crossplatform|@ohos.display.d.ts|
|跨平台能力有变化|类名：window;<br>方法or属性：declare window<br>旧版本信息：|类名：window;<br>方法or属性：declare window<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：window;<br>方法or属性：function findWindow(name: string): Window;<br>旧版本信息：|类名：window;<br>方法or属性：function findWindow(name: string): Window;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：window;<br>方法or属性：function getLastWindow(ctx: BaseContext, callback: AsyncCallback\<Window>): void;<br>旧版本信息：|类名：window;<br>方法or属性：function getLastWindow(ctx: BaseContext, callback: AsyncCallback\<Window>): void;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：window;<br>方法or属性：function getLastWindow(ctx: BaseContext): Promise\<Window>;<br>旧版本信息：|类名：window;<br>方法or属性：function getLastWindow(ctx: BaseContext): Promise\<Window>;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Rect;<br>方法or属性：interface Rect<br>旧版本信息：|类名：Rect;<br>方法or属性：interface Rect<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Rect;<br>方法or属性：left: number;<br>旧版本信息：|类名：Rect;<br>方法or属性：left: number;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Rect;<br>方法or属性：top: number;<br>旧版本信息：|类名：Rect;<br>方法or属性：top: number;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Rect;<br>方法or属性：width: number;<br>旧版本信息：|类名：Rect;<br>方法or属性：width: number;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Size;<br>方法or属性：width: number;<br>旧版本信息：|类名：Size;<br>方法or属性：width: number;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Rect;<br>方法or属性：height: number;<br>旧版本信息：|类名：Rect;<br>方法or属性：height: number;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Size;<br>方法or属性：height: number;<br>旧版本信息：|类名：Size;<br>方法or属性：height: number;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Size;<br>方法or属性：interface Size<br>旧版本信息：|类名：Size;<br>方法or属性：interface Size<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：WindowProperties;<br>方法or属性：interface WindowProperties<br>旧版本信息：|类名：WindowProperties;<br>方法or属性：interface WindowProperties<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：WindowProperties;<br>方法or属性：windowRect: Rect;<br>旧版本信息：|类名：WindowProperties;<br>方法or属性：windowRect: Rect;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：WindowProperties;<br>方法or属性：brightness: number;<br>旧版本信息：|类名：WindowProperties;<br>方法or属性：brightness: number;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：WindowProperties;<br>方法or属性：isKeepScreenOn: boolean;<br>旧版本信息：|类名：WindowProperties;<br>方法or属性：isKeepScreenOn: boolean;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Orientation;<br>方法or属性：enum Orientation<br>旧版本信息：|类名：Orientation;<br>方法or属性：enum Orientation<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Orientation;<br>方法or属性：UNSPECIFIED = 0<br>旧版本信息：|类名：Orientation;<br>方法or属性：UNSPECIFIED = 0<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Orientation;<br>方法or属性：PORTRAIT = 1<br>旧版本信息：|类名：Orientation;<br>方法or属性：PORTRAIT = 1<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Orientation;<br>方法or属性：LANDSCAPE = 2<br>旧版本信息：|类名：Orientation;<br>方法or属性：LANDSCAPE = 2<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Orientation;<br>方法or属性：PORTRAIT_INVERTED = 3<br>旧版本信息：|类名：Orientation;<br>方法or属性：PORTRAIT_INVERTED = 3<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Orientation;<br>方法or属性：LANDSCAPE_INVERTED = 4<br>旧版本信息：|类名：Orientation;<br>方法or属性：LANDSCAPE_INVERTED = 4<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Window;<br>方法or属性：showWindow(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：showWindow(callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Window;<br>方法or属性：showWindow(): Promise\<void>;<br>旧版本信息：|类名：Window;<br>方法or属性：showWindow(): Promise\<void>;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Window;<br>方法or属性：destroyWindow(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：destroyWindow(callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Window;<br>方法or属性：destroyWindow(): Promise\<void>;<br>旧版本信息：|类名：Window;<br>方法or属性：destroyWindow(): Promise\<void>;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Window;<br>方法or属性：moveWindowTo(x: number, y: number): Promise\<void>;<br>旧版本信息：|类名：Window;<br>方法or属性：moveWindowTo(x: number, y: number): Promise\<void>;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Window;<br>方法or属性：moveWindowTo(x: number, y: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：moveWindowTo(x: number, y: number, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Window;<br>方法or属性：resize(width: number, height: number): Promise\<void>;<br>旧版本信息：|类名：Window;<br>方法or属性：resize(width: number, height: number): Promise\<void>;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Window;<br>方法or属性：resize(width: number, height: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：resize(width: number, height: number, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Window;<br>方法or属性：getWindowProperties(): WindowProperties;<br>旧版本信息：|类名：Window;<br>方法or属性：getWindowProperties(): WindowProperties;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Window;<br>方法or属性：setWindowSystemBarEnable(names: Array\<'status' \| 'navigation'>, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：setWindowSystemBarEnable(names: Array\<'status' \| 'navigation'>, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Window;<br>方法or属性：setWindowSystemBarEnable(names: Array\<'status' \| 'navigation'>): Promise\<void>;<br>旧版本信息：|类名：Window;<br>方法or属性：setWindowSystemBarEnable(names: Array\<'status' \| 'navigation'>): Promise\<void>;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Window;<br>方法or属性：setPreferredOrientation(orientation: Orientation): Promise\<void>;<br>旧版本信息：|类名：Window;<br>方法or属性：setPreferredOrientation(orientation: Orientation): Promise\<void>;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Window;<br>方法or属性：setPreferredOrientation(orientation: Orientation, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：setPreferredOrientation(orientation: Orientation, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Window;<br>方法or属性：loadContent(path: string, storage: LocalStorage, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：loadContent(path: string, storage: LocalStorage, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：WindowStage;<br>方法or属性：loadContent(path: string, storage: LocalStorage, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：WindowStage;<br>方法or属性：loadContent(path: string, storage: LocalStorage, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Window;<br>方法or属性：loadContent(path: string, storage: LocalStorage): Promise\<void>;<br>旧版本信息：|类名：Window;<br>方法or属性：loadContent(path: string, storage: LocalStorage): Promise\<void>;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Window;<br>方法or属性：setUIContent(path: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：setUIContent(path: string, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Window;<br>方法or属性：setUIContent(path: string): Promise\<void>;<br>旧版本信息：|类名：Window;<br>方法or属性：setUIContent(path: string): Promise\<void>;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Window;<br>方法or属性：isWindowShowing(): boolean;<br>旧版本信息：|类名：Window;<br>方法or属性：isWindowShowing(): boolean;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Window;<br>方法or属性：setWindowBackgroundColor(color: string): void;<br>旧版本信息：|类名：Window;<br>方法or属性：setWindowBackgroundColor(color: string): void;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Window;<br>方法or属性：setWindowBrightness(brightness: number): Promise\<void>;<br>旧版本信息：|类名：Window;<br>方法or属性：setWindowBrightness(brightness: number): Promise\<void>;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Window;<br>方法or属性：setWindowBrightness(brightness: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：setWindowBrightness(brightness: number, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Window;<br>方法or属性：setWindowKeepScreenOn(isKeepScreenOn: boolean): Promise\<void>;<br>旧版本信息：|类名：Window;<br>方法or属性：setWindowKeepScreenOn(isKeepScreenOn: boolean): Promise\<void>;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Window;<br>方法or属性：setWindowKeepScreenOn(isKeepScreenOn: boolean, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Window;<br>方法or属性：setWindowKeepScreenOn(isKeepScreenOn: boolean, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：WindowStageEventType;<br>方法or属性：enum WindowStageEventType<br>旧版本信息：|类名：WindowStageEventType;<br>方法or属性：enum WindowStageEventType<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：WindowStageEventType;<br>方法or属性：SHOWN = 1<br>旧版本信息：|类名：WindowStageEventType;<br>方法or属性：SHOWN = 1<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：WindowStageEventType;<br>方法or属性：ACTIVE<br>旧版本信息：|类名：WindowStageEventType;<br>方法or属性：ACTIVE<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：WindowStageEventType;<br>方法or属性：INACTIVE<br>旧版本信息：|类名：WindowStageEventType;<br>方法or属性：INACTIVE<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：WindowStageEventType;<br>方法or属性：HIDDEN<br>旧版本信息：|类名：WindowStageEventType;<br>方法or属性：HIDDEN<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：WindowStage;<br>方法or属性：interface WindowStage<br>旧版本信息：|类名：WindowStage;<br>方法or属性：interface WindowStage<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：WindowStage;<br>方法or属性：getMainWindow(): Promise\<Window>;<br>旧版本信息：|类名：WindowStage;<br>方法or属性：getMainWindow(): Promise\<Window>;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：WindowStage;<br>方法or属性：getMainWindow(callback: AsyncCallback\<Window>): void;<br>旧版本信息：|类名：WindowStage;<br>方法or属性：getMainWindow(callback: AsyncCallback\<Window>): void;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：WindowStage;<br>方法or属性：getMainWindowSync(): Window;<br>旧版本信息：|类名：WindowStage;<br>方法or属性：getMainWindowSync(): Window;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：WindowStage;<br>方法or属性：createSubWindow(name: string): Promise\<Window>;<br>旧版本信息：|类名：WindowStage;<br>方法or属性：createSubWindow(name: string): Promise\<Window>;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：WindowStage;<br>方法or属性：createSubWindow(name: string, callback: AsyncCallback\<Window>): void;<br>旧版本信息：|类名：WindowStage;<br>方法or属性：createSubWindow(name: string, callback: AsyncCallback\<Window>): void;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：WindowStage;<br>方法or属性：getSubWindow(): Promise\<Array\<Window>>;<br>旧版本信息：|类名：WindowStage;<br>方法or属性：getSubWindow(): Promise\<Array\<Window>>;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：WindowStage;<br>方法or属性：getSubWindow(callback: AsyncCallback\<Array\<Window>>): void;<br>旧版本信息：|类名：WindowStage;<br>方法or属性：getSubWindow(callback: AsyncCallback\<Array\<Window>>): void;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：WindowStage;<br>方法or属性：loadContent(path: string, storage?: LocalStorage): Promise\<void>;<br>旧版本信息：|类名：WindowStage;<br>方法or属性：loadContent(path: string, storage?: LocalStorage): Promise\<void>;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：WindowStage;<br>方法or属性：loadContent(path: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：WindowStage;<br>方法or属性：loadContent(path: string, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：WindowStage;<br>方法or属性：on(eventType: 'windowStageEvent', callback: Callback\<WindowStageEventType>): void;<br>旧版本信息：|类名：WindowStage;<br>方法or属性：on(eventType: 'windowStageEvent', callback: Callback\<WindowStageEventType>): void;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：WindowStage;<br>方法or属性：off(eventType: 'windowStageEvent', callback?: Callback\<WindowStageEventType>): void;<br>旧版本信息：|类名：WindowStage;<br>方法or属性：off(eventType: 'windowStageEvent', callback?: Callback\<WindowStageEventType>): void;<br>新版本信息：crossplatform|@ohos.window.d.ts|
