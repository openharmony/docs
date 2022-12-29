# JS API Changes of the Window Manager Subsystem

The table below lists the APIs changes of the Window Manager subsystem in OpenHarmony 3.1 Release over OpenHarmony 3.0 LTS.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.window | Window | setTouchable(isTouchable: boolean): Promise\<void>;<br>setTouchable(isTouchable: boolean, callback: AsyncCallback\<void>): void; | Added|
| ohos.window | Window | setPrivacyMode(isPrivacyMode: boolean): Promise\<void>;<br>setPrivacyMode(isPrivacyMode: boolean, callback: AsyncCallback\<void>): void; | Added|
| ohos.window | Window | setOutsideTouchable(touchable: boolean): Promise\<void>;<br>setOutsideTouchable(touchable: boolean, callback: AsyncCallback\<void>): void; | Added|
| ohos.window | Window | setKeepScreenOn(isKeepScreenOn: boolean): Promise\<void>;<br>setKeepScreenOn(isKeepScreenOn: boolean, callback: AsyncCallback\<void>): void; | Added|
| ohos.window | Window | setFocusable(isFocusable: boolean): Promise\<void>;<br>setFocusable(isFocusable: boolean, callback: AsyncCallback\<void>): void; | Added|
| ohos.window | Window | setDimBehind(dimBehindValue: number, callback: AsyncCallback\<void>): void;<br>setDimBehind(dimBehindValue: number): Promise\<void>; | Added|
| ohos.window | Window | setBrightness(brightness: number): Promise\<void>;<br>setBrightness(brightness: number, callback: AsyncCallback\<void>): void; | Added|
| ohos.window | Window | setBackgroundColor(color: string): Promise\<void>;<br>setBackgroundColor(color: string, callback: AsyncCallback\<void>): void; | Added|
| ohos.window | Window | getColorSpace(): Promise\<ColorSpace>;<br>getColorSpace(callback: AsyncCallback\<ColorSpace>): void; | Added|
| ohos.window | Window | setColorSpace(colorSpace:ColorSpace): Promise\<void>;<br>setColorSpace(colorSpace:ColorSpace, callback: AsyncCallback\<void>): void; | Added|
| ohos.window | Window | isSupportWideGamut(): Promise\<boolean>;<br>isSupportWideGamut(callback: AsyncCallback\<boolean>): void; | Added|
| ohos.window | Window | off(type: 'keyboardHeightChange', callback?: Callback\<number>): void; | Added|
| ohos.window | Window | on(type: 'keyboardHeightChange', callback: Callback\<number>): void; | Added|
| ohos.window | Window | off(type: 'systemAvoidAreaChange', callback?: Callback\<AvoidArea>): void; | Added|
| ohos.window | Window | on(type: 'systemAvoidAreaChange', callback: Callback\<AvoidArea>): void; | Added|
| ohos.window | Window | off(type: 'windowSizeChange', callback?: Callback\<Size>): void; | Added|
| ohos.window | Window | on(type: 'windowSizeChange', callback: Callback\<Size>): void; | Added|
| ohos.window | Window | isShowing(callback: AsyncCallback\<boolean>): void;<br>isShowing(): Promise\<boolean>; | Added|
| ohos.window | Window | loadContent(path: string, callback: AsyncCallback\<void>): void;<br>loadContent(path: string): Promise\<void>; | Added|
| ohos.window | Window | setSystemBarProperties(systemBarProperties: SystemBarProperties, callback: AsyncCallback\<void>): void;<br>setSystemBarProperties(systemBarProperties: SystemBarProperties): Promise\<void>; | Added|
| ohos.window | Window | setSystemBarEnable(names: Array\<'status'\|'navigation'>, callback: AsyncCallback\<void>): void;<br>setSystemBarEnable(names: Array\<'status'\|'navigation'>): Promise\<void>; | Added|
| ohos.window | Window | setLayoutFullScreen(isLayoutFullScreen: boolean, callback: AsyncCallback\<void>): void;<br>setLayoutFullScreen(isLayoutFullScreen: boolean): Promise\<void>; | Added|
| ohos.window | Window | setFullScreen(isFullScreen: boolean, callback: AsyncCallback\<void>): void;<br>setFullScreen(isFullScreen: boolean): Promise\<void>; | Added|
| ohos.window | Window | getAvoidArea(type: AvoidAreaType, callback: AsyncCallback\<AvoidArea>): void;<br>getAvoidArea(type: AvoidAreaType): Promise\<AvoidArea>; | Added|
| ohos.window | Window | getProperties(callback: AsyncCallback\<WindowProperties>): void;<br>getProperties(): Promise\<WindowProperties>; | Added|
| ohos.window | Window | destroy(callback: AsyncCallback\<void>): void;<br>destroy(): Promise\<void>; | Added|
| ohos.window | Window | show(callback: AsyncCallback\<void>): void;<br>show(): Promise\<void>; | Added|
| ohos.window | window | find(id: string, callback: AsyncCallback\<Window>): void;<br>find(id: string): Promise\<Window>; | Added|
| ohos.window | window | create(id: string, type: WindowType, callback: AsyncCallback\<Window>): void;<br>create(id: string, type: WindowType): Promise\<Window>;<br>create(ctx: Context, id: string, type: WindowType): Promise\<Window>;<br>create(ctx: Context, id: string, type: WindowType, callback: AsyncCallback\<Window>): void; | Added|
| ohos.window | ColorSpace | WIDE_GAMUT | Added|
| ohos.window | ColorSpace | DEFAULT | Added|
| ohos.window | WindowProperties | isTransparent: boolean | Added|
| ohos.window | WindowProperties | isRoundCorner: boolean | Added|
| ohos.window | WindowProperties | isPrivacyMode: boolean | Added|
| ohos.window | WindowProperties | isKeepScreenOn: boolean | Added|
| ohos.window | WindowProperties | dimBehindValue: number | Added|
| ohos.window | WindowProperties | brightness: number | Added|
| ohos.window | WindowProperties | touchable: boolean | Added|
| ohos.window | WindowProperties | focusable: boolean | Added|
| ohos.window | WindowProperties | isLayoutFullScreen: boolean | Added|
| ohos.window | WindowProperties | isFullScreen: boolean | Added|
| ohos.window | WindowProperties | type: WindowType; | Added|
| ohos.window | WindowProperties | windowRect: Rect; | Added|
| ohos.window | Size | height: number; | Added|
| ohos.window | Size | width: number; | Added|
| ohos.window | AvoidArea | bottomRect: Rect; | Added|
| ohos.window | AvoidArea | rightRect: Rect; | Added|
| ohos.window | AvoidArea | topRect: Rect; | Added|
| ohos.window | AvoidArea | leftRect: Rect; | Added|
| ohos.window | Rect | height: number; | Added|
| ohos.window | Rect | width: number; | Added|
| ohos.window | Rect | top: number; | Added|
| ohos.window | Rect | left: number; | Added|
| ohos.window | SystemBarProperties | navigationBarContentColor?: string; | Added|
| ohos.window | SystemBarProperties | isNavigationBarLightIcon?: boolean; | Added|
| ohos.window | SystemBarProperties | navigationBarColor?: string; | Added|
| ohos.window | SystemBarProperties | statusBarContentColor?: string; | Added|
| ohos.window | SystemBarProperties | isStatusBarLightIcon?: boolean; | Added|
| ohos.window | SystemBarProperties | statusBarColor?: string; | Added|
| ohos.window | AvoidAreaType | TYPE_CUTOUT | Added|
| ohos.window | AvoidAreaType | TYPE_SYSTEM | Added|
| ohos.display | Display | yDPI: number; | Added|
| ohos.display | Display | xDPI: number; | Added|
| ohos.display | Display | scaledDensity: number; | Added|
| ohos.display | Display | densityPixels: number; | Added|
| ohos.display | Display | densityDPI: number; | Added|
| ohos.display | Display | height: number; | Added|
| ohos.display | Display | width: number; | Added|
| ohos.display | Display | rotation: number; | Added|
| ohos.display | Display | refreshRate: number; | Added|
| ohos.display | Display | state: DisplayState; | Added|
| ohos.display | Display | alive: boolean; | Added|
| ohos.display | Display | name: string; | Added|
| ohos.display | Display | id: number; | Added|
| ohos.display | DisplayState | STATE_ON_SUSPEND | Added|
| ohos.display | DisplayState | STATE_VR | Added|
| ohos.display | DisplayState | STATE_DOZE_SUSPEND | Added|
| ohos.display | DisplayState | STATE_DOZE | Added|
| ohos.display | DisplayState | STATE_ON | Added|
| ohos.display | DisplayState | STATE_OFF | Added|
| ohos.display | DisplayState | STATE_UNKNOWN = 0 | Added|
| ohos.display | display | off(type: 'add' \| 'remove' \| 'change', callback?: Callback\<number>): void; | Added|
| ohos.display | display | off(type: 'add' \| 'remove' \| 'change', callback?: Callback\<number>): void; | Added|
| ohos.display | display | off(type: 'add' \| 'remove' \| 'change', callback?: Callback\<number>): void; | Added|
| ohos.display | display | on(type: 'add' \| 'remove' \| 'change', callback: Callback\<number>): void; | Added|
| ohos.display | display | on(type: 'add' \| 'remove' \| 'change', callback: Callback\<number>): void; | Added|
| ohos.display | display | on(type: 'add' \| 'remove' \| 'change', callback: Callback\<number>): void; | Added|
| ohos.display | display | getAllDisplay(callback: AsyncCallback\<Array\<Display>>): void;<br>getAllDisplay(): Promise\<Array\<Display>>; | Added|
| ohos.display | display | getDefaultDisplay(callback: AsyncCallback\<Display>): void;<br>getDefaultDisplay(): Promise\<Display>; | Added|
