| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：Window;<br>方法or属性：getUIContext() : UIContext;|@ohos.window.d.ts|
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
|访问级别有变化|类名：ScreenSourceMode;<br>方法or属性：enum ScreenSourceMode<br>旧版本信息：|类名：ScreenSourceMode;<br>方法or属性：enum ScreenSourceMode<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：ScreenSourceMode;<br>方法or属性：SCREEN_MAIN = 0<br>旧版本信息：|类名：ScreenSourceMode;<br>方法or属性：SCREEN_MAIN = 0<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：ScreenSourceMode;<br>方法or属性：SCREEN_MIRROR = 1<br>旧版本信息：|类名：ScreenSourceMode;<br>方法or属性：SCREEN_MIRROR = 1<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：ScreenSourceMode;<br>方法or属性：SCREEN_EXTEND = 2<br>旧版本信息：|类名：ScreenSourceMode;<br>方法or属性：SCREEN_EXTEND = 2<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：ScreenSourceMode;<br>方法or属性：SCREEN_ALONE = 3<br>旧版本信息：|类名：ScreenSourceMode;<br>方法or属性：SCREEN_ALONE = 3<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：Screen;<br>方法or属性：interface Screen<br>旧版本信息：|类名：Screen;<br>方法or属性：interface Screen<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：Screen;<br>方法or属性：readonly id: number;<br>旧版本信息：|类名：Screen;<br>方法or属性：readonly id: number;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：Screen;<br>方法or属性：readonly parent: number;<br>旧版本信息：|类名：Screen;<br>方法or属性：readonly parent: number;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：Screen;<br>方法or属性：readonly supportedModeInfo: Array\<ScreenModeInfo>;<br>旧版本信息：|类名：Screen;<br>方法or属性：readonly supportedModeInfo: Array\<ScreenModeInfo>;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：Screen;<br>方法or属性：readonly activeModeIndex: number;<br>旧版本信息：|类名：Screen;<br>方法or属性：readonly activeModeIndex: number;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：Screen;<br>方法or属性：readonly orientation: Orientation;<br>旧版本信息：|类名：Screen;<br>方法or属性：readonly orientation: Orientation;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：Screen;<br>方法or属性：readonly sourceMode: ScreenSourceMode;<br>旧版本信息：|类名：Screen;<br>方法or属性：readonly sourceMode: ScreenSourceMode;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：Screen;<br>方法or属性：setOrientation(orientation: Orientation, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Screen;<br>方法or属性：setOrientation(orientation: Orientation, callback: AsyncCallback\<void>): void;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：Screen;<br>方法or属性：setOrientation(orientation: Orientation): Promise\<void>;<br>旧版本信息：|类名：Screen;<br>方法or属性：setOrientation(orientation: Orientation): Promise\<void>;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：Screen;<br>方法or属性：setScreenActiveMode(modeIndex: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Screen;<br>方法or属性：setScreenActiveMode(modeIndex: number, callback: AsyncCallback\<void>): void;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：Screen;<br>方法or属性：setScreenActiveMode(modeIndex: number): Promise\<void>;<br>旧版本信息：|类名：Screen;<br>方法or属性：setScreenActiveMode(modeIndex: number): Promise\<void>;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：Screen;<br>方法or属性：setDensityDpi(densityDpi: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：Screen;<br>方法or属性：setDensityDpi(densityDpi: number, callback: AsyncCallback\<void>): void;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：Screen;<br>方法or属性：setDensityDpi(densityDpi: number): Promise\<void>;<br>旧版本信息：|类名：Screen;<br>方法or属性：setDensityDpi(densityDpi: number): Promise\<void>;<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：Orientation;<br>方法or属性：enum Orientation<br>旧版本信息：|类名：Orientation;<br>方法or属性：enum Orientation<br>新版本信息：systemapi|@ohos.screen.d.ts|
|访问级别有变化|类名：ScreenModeInfo;<br>方法or属性：interface ScreenModeInfo<br>旧版本信息：|类名：ScreenModeInfo;<br>方法or属性：interface ScreenModeInfo<br>新版本信息：systemapi|@ohos.screen.d.ts|
|权限有变化|类名：screen;<br>方法or属性：function createVirtualScreen(options: VirtualScreenOption): Promise\<Screen>;<br>旧版本信息：|类名：screen;<br>方法or属性：function createVirtualScreen(options: VirtualScreenOption): Promise\<Screen>;<br>新版本信息：ohos.permission.CAPTURE_SCREEN|@ohos.screen.d.ts|
|权限有变化|类名：screen;<br>方法or属性：function setVirtualScreenSurface(screenId: number, surfaceId: string): Promise\<void>;<br>旧版本信息：|类名：screen;<br>方法or属性：function setVirtualScreenSurface(screenId: number, surfaceId: string): Promise\<void>;<br>新版本信息：ohos.permission.CAPTURE_SCREEN|@ohos.screen.d.ts|
|跨平台能力有变化|类名：display;<br>方法or属性：declare display<br>旧版本信息：|类名：display;<br>方法or属性：declare display<br>新版本信息：crossplatform|@ohos.display.d.ts|
|跨平台能力有变化|类名：display;<br>方法or属性：function getDefaultDisplaySync(): Display;<br>旧版本信息：|类名：display;<br>方法or属性：function getDefaultDisplaySync(): Display;<br>新版本信息：crossplatform|@ohos.display.d.ts|
|跨平台能力有变化|类名：Orientation;<br>方法or属性：enum Orientation<br>旧版本信息：|类名：Orientation;<br>方法or属性：enum Orientation<br>新版本信息：crossplatform|@ohos.display.d.ts|
|跨平台能力有变化|类名：Orientation;<br>方法or属性：PORTRAIT = 0<br>旧版本信息：|类名：Orientation;<br>方法or属性：PORTRAIT = 0<br>新版本信息：crossplatform|@ohos.display.d.ts|
|跨平台能力有变化|类名：Orientation;<br>方法or属性：LANDSCAPE = 1<br>旧版本信息：|类名：Orientation;<br>方法or属性：LANDSCAPE = 1<br>新版本信息：crossplatform|@ohos.display.d.ts|
|跨平台能力有变化|类名：Orientation;<br>方法or属性：PORTRAIT_INVERTED = 2<br>旧版本信息：|类名：Orientation;<br>方法or属性：PORTRAIT_INVERTED = 2<br>新版本信息：crossplatform|@ohos.display.d.ts|
|跨平台能力有变化|类名：Orientation;<br>方法or属性：LANDSCAPE_INVERTED = 3<br>旧版本信息：|类名：Orientation;<br>方法or属性：LANDSCAPE_INVERTED = 3<br>新版本信息：crossplatform|@ohos.display.d.ts|
|跨平台能力有变化|类名：Rect;<br>方法or属性：interface Rect<br>旧版本信息：|类名：Rect;<br>方法or属性：interface Rect<br>新版本信息：crossplatform|@ohos.display.d.ts|
|跨平台能力有变化|类名：Rect;<br>方法or属性：left: number;<br>旧版本信息：|类名：Rect;<br>方法or属性：left: number;<br>新版本信息：crossplatform|@ohos.display.d.ts|
|跨平台能力有变化|类名：Rect;<br>方法or属性：top: number;<br>旧版本信息：|类名：Rect;<br>方法or属性：top: number;<br>新版本信息：crossplatform|@ohos.display.d.ts|
|跨平台能力有变化|类名：Rect;<br>方法or属性：width: number;<br>旧版本信息：|类名：Rect;<br>方法or属性：width: number;<br>新版本信息：crossplatform|@ohos.display.d.ts|
|跨平台能力有变化|类名：Display;<br>方法or属性：width: number;<br>旧版本信息：|类名：Display;<br>方法or属性：width: number;<br>新版本信息：crossplatform|@ohos.display.d.ts|
|跨平台能力有变化|类名：Rect;<br>方法or属性：height: number;<br>旧版本信息：|类名：Rect;<br>方法or属性：height: number;<br>新版本信息：crossplatform|@ohos.display.d.ts|
|跨平台能力有变化|类名：Display;<br>方法or属性：height: number;<br>旧版本信息：|类名：Display;<br>方法or属性：height: number;<br>新版本信息：crossplatform|@ohos.display.d.ts|
|跨平台能力有变化|类名：Display;<br>方法or属性：interface Display<br>旧版本信息：|类名：Display;<br>方法or属性：interface Display<br>新版本信息：crossplatform|@ohos.display.d.ts|
|跨平台能力有变化|类名：Display;<br>方法or属性：id: number;<br>旧版本信息：|类名：Display;<br>方法or属性：id: number;<br>新版本信息：crossplatform|@ohos.display.d.ts|
|跨平台能力有变化|类名：Display;<br>方法or属性：orientation: Orientation;<br>旧版本信息：|类名：Display;<br>方法or属性：orientation: Orientation;<br>新版本信息：crossplatform|@ohos.display.d.ts|
|跨平台能力有变化|类名：window;<br>方法or属性：declare window<br>旧版本信息：|类名：window;<br>方法or属性：declare window<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：window;<br>方法or属性：function createWindow(config: Configuration, callback: AsyncCallback\<Window>): void;<br>旧版本信息：|类名：window;<br>方法or属性：function createWindow(config: Configuration, callback: AsyncCallback\<Window>): void;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：window;<br>方法or属性：function createWindow(config: Configuration): Promise\<Window>;<br>旧版本信息：|类名：window;<br>方法or属性：function createWindow(config: Configuration): Promise\<Window>;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：window;<br>方法or属性：function findWindow(name: string): Window;<br>旧版本信息：|类名：window;<br>方法or属性：function findWindow(name: string): Window;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：window;<br>方法or属性：function getLastWindow(ctx: BaseContext, callback: AsyncCallback\<Window>): void;<br>旧版本信息：|类名：window;<br>方法or属性：function getLastWindow(ctx: BaseContext, callback: AsyncCallback\<Window>): void;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：window;<br>方法or属性：function getLastWindow(ctx: BaseContext): Promise\<Window>;<br>旧版本信息：|类名：window;<br>方法or属性：function getLastWindow(ctx: BaseContext): Promise\<Window>;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：WindowType;<br>方法or属性：enum WindowType<br>旧版本信息：|类名：WindowType;<br>方法or属性：enum WindowType<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：WindowType;<br>方法or属性：TYPE_APP<br>旧版本信息：|类名：WindowType;<br>方法or属性：TYPE_APP<br>新版本信息：crossplatform|@ohos.window.d.ts|
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
|跨平台能力有变化|类名：WindowProperties;<br>方法or属性：type: WindowType;<br>旧版本信息：|类名：WindowProperties;<br>方法or属性：type: WindowType;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：WindowProperties;<br>方法or属性：brightness: number;<br>旧版本信息：|类名：WindowProperties;<br>方法or属性：brightness: number;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：WindowProperties;<br>方法or属性：isKeepScreenOn: boolean;<br>旧版本信息：|类名：WindowProperties;<br>方法or属性：isKeepScreenOn: boolean;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Configuration;<br>方法or属性：interface Configuration<br>旧版本信息：|类名：Configuration;<br>方法or属性：interface Configuration<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Configuration;<br>方法or属性：name: string;<br>旧版本信息：|类名：Configuration;<br>方法or属性：name: string;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Configuration;<br>方法or属性：windowType: WindowType;<br>旧版本信息：|类名：Configuration;<br>方法or属性：windowType: WindowType;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Configuration;<br>方法or属性：ctx?: BaseContext;<br>旧版本信息：|类名：Configuration;<br>方法or属性：ctx?: BaseContext;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Configuration;<br>方法or属性：displayId?: number;<br>旧版本信息：|类名：Configuration;<br>方法or属性：displayId?: number;<br>新版本信息：crossplatform|@ohos.window.d.ts|
|跨平台能力有变化|类名：Configuration;<br>方法or属性：parentId?: number;<br>旧版本信息：|类名：Configuration;<br>方法or属性：parentId?: number;<br>新版本信息：crossplatform|@ohos.window.d.ts|
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
|函数有变化|类名：Window;<br>方法or属性：off(type: 'windowEvent',callback:Callback\<WindowEventType>):void;|类名：Window;<br>方法or属性：off(type:'windowEvent',callback?: Callback\<WindowEventType):void;|@ohos.window.d.ts|
