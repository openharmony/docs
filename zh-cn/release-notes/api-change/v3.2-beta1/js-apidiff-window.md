# 窗口管理子系统JS API变更

OpenHarmony 3.2 Beta1版本相较于OpenHarmony 3.1 Release版本，窗口管理子系统的API变更如下:

## 接口变更



| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.screen | ScreenModeInfo | refreshRate: number; | 新增 |
| ohos.screen | ScreenModeInfo | height: number; | 新增 |
| ohos.screen | ScreenModeInfo | width: number; | 新增 |
| ohos.screen | ScreenModeInfo | id: number; | 新增 |
| ohos.screen | Orientation | SENSOR_HORIZONTAL = 7 | 新增 |
| ohos.screen | Orientation | SENSOR_VERTICAL = 6 | 新增 |
| ohos.screen | Orientation | SENSOR = 5 | 新增 |
| ohos.screen | Orientation | REVERSE_HORIZONTAL = 4 | 新增 |
| ohos.screen | Orientation | REVERSE_VERTICAL = 3 | 新增 |
| ohos.screen | Orientation | HORIZONTAL = 2 | 新增 |
| ohos.screen | Orientation | VERTICAL = 1 | 新增 |
| ohos.screen | Orientation | UNSPECIFIED = 0 | 新增 |
| ohos.screen | Screen | setScreenActiveMode(modeIndex: number, callback: AsyncCallback\<void>): void;<br>setScreenActiveMode(modeIndex: number): Promise\<void>; | 新增 |
| ohos.screen | Screen | setOrientation(orientation: Orientation, callback: AsyncCallback\<void>): void;<br>setOrientation(orientation: Orientation): Promise\<void>; | 新增 |
| ohos.screen | Screen | on(eventType: 'connect' \| 'disconnect' \| 'change', callback: Callback<number>): void; | 新增 |
| ohos.screen | Screen | off(eventType: 'connect' \| 'disconnect' \| 'change', callback?: Callback<number>): void; | 新增 |
| ohos.screen | Screen | readonly orientation: Orientation; | 新增 |
| ohos.screen | Screen | readonly activeModeIndex: number; | 新增 |
| ohos.screen | Screen | readonly supportedModeInfo: Array\<ScreenModeInfo>; | 新增 |
| ohos.screen | Screen | readonly parent: number; | 新增 |
| ohos.screen | Screen | readonly id: number; | 新增 |
| ohos.screen | ExpandOption | startY: number; | 新增 |
| ohos.screen | ExpandOption | startX: number; | 新增 |
| ohos.screen | ExpandOption | screenId: number; | 新增 |
| ohos.screen | screen | function makeMirror(mainScreen:number, mirrorScreen:Array\<number>, callback: AsyncCallback\<number>): void;<br>function makeMirror(mainScreen:number, mirrorScreen:Array\<number>): Promise\<number>; | 新增 |
| ohos.screen | screen | function makeExpand(options:Array\<ExpandOption>, callback: AsyncCallback\<number>): void;<br>function makeExpand(options:Array\<ExpandOption>): Promise\<number>; | 新增 |
| ohos.screen | screen | function off(eventType: 'connect' \| 'disconnect' \| 'change', callback?: Callback\<number>): void; | 新增 |
| ohos.screen | screen | function getAllScreens(callback: AsyncCallback\<Array\<Screen>>): void;<br>function getAllScreens(): Promise\<Array\<Screen>>; | 新增 |
| ohos.window | WindowStage | loadContent(path: string, storage: LocalStorage, callback: AsyncCallback\<void>): void;<br>loadContent(path: string, storage?: LocalStorage): Promise\<void>;<br>loadContent(path: string, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.window | WindowStage | getSubWindow(): Promise\<Array\<Window>>;<br>getSubWindow(callback: AsyncCallback\<Array\<Window>>): void; | 新增 |
| ohos.window | WindowStage | createSubWindow(name: string): Promise\<Window>;<br>createSubWindow(name: string, callback: AsyncCallback\<Window>): void; | 新增 |
| ohos.window | WindowStage | getMainWindow(): Promise\<Window>;<br>getMainWindow(callback: AsyncCallback\<Window>): void; | 新增 |
| ohos.window | WindowStage | on(eventType: 'windowStageEvent', callback: Callback<WindowStageEventType>): void; | 新增 |
| ohos.window | WindowStage | off(eventType: 'windowStageEvent', callback?: Callback<WindowStageEventType>): void; | 新增 |
| ohos.window | WindowStageEventType | BACKGROUND | 新增 |
| ohos.window | WindowStageEventType | INACTIVE | 新增 |
| ohos.window | WindowStageEventType | ACTIVE | 新增 |
| ohos.window | WindowStageEventType | FOREGROUND = 1 | 新增 |
| ohos.window | window | function setWindowLayoutMode(mode: WindowLayoutMode, callback: AsyncCallback\<void>): void;<br>function setWindowLayoutMode(mode: WindowLayoutMode): Promise\<void>; | 新增 |
| ohos.window | window | function toggleShownStateForAllAppWindows(callback: AsyncCallback\<void>): void;<br>function toggleShownStateForAllAppWindows(): Promise\<void>; | 新增 |
| ohos.window | window | function minimizeAll(id: number, callback: AsyncCallback\<void>): void;<br>function minimizeAll(id: number): Promise\<void>; | 新增 |
| ohos.window | WindowLayoutMode | WINDOW_LAYOUT_MODE_TILE | 新增 |
| ohos.window | WindowLayoutMode | WINDOW_LAYOUT_MODE_CASCADE | 新增 |
| ohos.window | Window | setOutsideTouchable(touchable: boolean): Promise\<void>;<br>setOutsideTouchable(touchable: boolean, callback: AsyncCallback\<void>): void; | 废弃 |
| ohos.window | Window | setDimBehind(dimBehindValue: number, callback: AsyncCallback\<void>): void;<br>setDimBehind(dimBehindValue: number): Promise\<void>; | 废弃 |
| ohos.window | WindowProperties | dimBehindValue: number | 废弃 |

