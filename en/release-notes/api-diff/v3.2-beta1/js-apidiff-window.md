# JS API Changes of the Window Manager Subsystem

The table below lists the APIs changes of the window manager subsystem in OpenHarmony 3.2 Beta1 over OpenHarmony 3.1 Release.

## API Changes



| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.screen | ScreenModeInfo | refreshRate: number; | Added|
| ohos.screen | ScreenModeInfo | height: number; | Added|
| ohos.screen | ScreenModeInfo | width: number; | Added|
| ohos.screen | ScreenModeInfo | id: number; | Added|
| ohos.screen | Orientation | SENSOR_HORIZONTAL = 7 | Added|
| ohos.screen | Orientation | SENSOR_VERTICAL = 6 | Added|
| ohos.screen | Orientation | SENSOR = 5 | Added|
| ohos.screen | Orientation | REVERSE_HORIZONTAL = 4 | Added|
| ohos.screen | Orientation | REVERSE_VERTICAL = 3 | Added|
| ohos.screen | Orientation | HORIZONTAL = 2 | Added|
| ohos.screen | Orientation | VERTICAL = 1 | Added|
| ohos.screen | Orientation | UNSPECIFIED = 0 | Added|
| ohos.screen | Screen | setScreenActiveMode(modeIndex: number, callback: AsyncCallback\<void>): void;<br>setScreenActiveMode(modeIndex: number): Promise\<void>; | Added|
| ohos.screen | Screen | setOrientation(orientation: Orientation, callback: AsyncCallback\<void>): void;<br>setOrientation(orientation: Orientation): Promise\<void>; | Added|
| ohos.screen | Screen | on(eventType: 'connect' \| 'disconnect' \| 'change', callback: Callback<number>): void; | Added|
| ohos.screen | Screen | off(eventType: 'connect' \| 'disconnect' \| 'change', callback?: Callback<number>): void; | Added|
| ohos.screen | Screen | readonly orientation: Orientation; | Added|
| ohos.screen | Screen | readonly activeModeIndex: number; | Added|
| ohos.screen | Screen | readonly supportedModeInfo: Array\<ScreenModeInfo>; | Added|
| ohos.screen | Screen | readonly parent: number; | Added|
| ohos.screen | Screen | readonly id: number; | Added|
| ohos.screen | ExpandOption | startY: number; | Added|
| ohos.screen | ExpandOption | startX: number; | Added|
| ohos.screen | ExpandOption | screenId: number; | Added|
| ohos.screen | screen | function makeMirror(mainScreen:number, mirrorScreen:Array\<number>, callback: AsyncCallback\<number>): void;<br>function makeMirror(mainScreen:number, mirrorScreen:Array\<number>): Promise\<number>; | Added|
| ohos.screen | screen | function makeExpand(options:Array\<ExpandOption>, callback: AsyncCallback\<number>): void;<br>function makeExpand(options:Array\<ExpandOption>): Promise\<number>; | Added|
| ohos.screen | screen | function off(eventType: 'connect' \| 'disconnect' \| 'change', callback?: Callback\<number>): void; | Added|
| ohos.screen | screen | function getAllScreens(callback: AsyncCallback\<Array\<Screen>>): void;<br>function getAllScreens(): Promise\<Array\<Screen>>; | Added|
| ohos.window | WindowStage | loadContent(path: string, storage: LocalStorage, callback: AsyncCallback\<void>): void;<br>loadContent(path: string, storage?: LocalStorage): Promise\<void>;<br>loadContent(path: string, callback: AsyncCallback\<void>): void; | Added|
| ohos.window | WindowStage | getSubWindow(): Promise\<Array\<Window>>;<br>getSubWindow(callback: AsyncCallback\<Array\<Window>>): void; | Added|
| ohos.window | WindowStage | createSubWindow(name: string): Promise\<Window>;<br>createSubWindow(name: string, callback: AsyncCallback\<Window>): void; | Added|
| ohos.window | WindowStage | getMainWindow(): Promise\<Window>;<br>getMainWindow(callback: AsyncCallback\<Window>): void; | Added|
| ohos.window | WindowStage | on(eventType: 'windowStageEvent', callback: Callback<WindowStageEventType>): void; | Added|
| ohos.window | WindowStage | off(eventType: 'windowStageEvent', callback?: Callback<WindowStageEventType>): void; | Added|
| ohos.window | WindowStageEventType | BACKGROUND | Added|
| ohos.window | WindowStageEventType | INACTIVE | Added|
| ohos.window | WindowStageEventType | ACTIVE | Added|
| ohos.window | WindowStageEventType | FOREGROUND = 1 | Added|
| ohos.window | window | function setWindowLayoutMode(mode: WindowLayoutMode, callback: AsyncCallback\<void>): void;<br>function setWindowLayoutMode(mode: WindowLayoutMode): Promise\<void>; | Added|
| ohos.window | window | function toggleShownStateForAllAppWindows(callback: AsyncCallback\<void>): void;<br>function toggleShownStateForAllAppWindows(): Promise\<void>; | Added|
| ohos.window | window | function minimizeAll(id: number, callback: AsyncCallback\<void>): void;<br>function minimizeAll(id: number): Promise\<void>; | Added|
| ohos.window | WindowLayoutMode | WINDOW_LAYOUT_MODE_TILE | Added|
| ohos.window | WindowLayoutMode | WINDOW_LAYOUT_MODE_CASCADE | Added|
| ohos.window | Window | setOutsideTouchable(touchable: boolean): Promise\<void>;<br>setOutsideTouchable(touchable: boolean, callback: AsyncCallback\<void>): void; | Deprecated|
| ohos.window | Window | setDimBehind(dimBehindValue: number, callback: AsyncCallback\<void>): void;<br>setDimBehind(dimBehindValue: number): Promise\<void>; | Deprecated|
| ohos.window | WindowProperties | dimBehindValue: number | Deprecated|
