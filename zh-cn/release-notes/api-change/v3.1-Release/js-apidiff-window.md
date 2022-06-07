# 窗口管理子系统JS API变更

OpenHarmony 3.1 Release版本相较于OpenHarmony 3.0 LTS版本，窗口管理子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.window | Window | setTouchable(isTouchable: boolean): Promise\<void>;<br>setTouchable(isTouchable: boolean, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.window | Window | setPrivacyMode(isPrivacyMode: boolean): Promise\<void>;<br>setPrivacyMode(isPrivacyMode: boolean, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.window | Window | setOutsideTouchable(touchable: boolean): Promise\<void>;<br>setOutsideTouchable(touchable: boolean, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.window | Window | setKeepScreenOn(isKeepScreenOn: boolean): Promise\<void>;<br>setKeepScreenOn(isKeepScreenOn: boolean, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.window | Window | setFocusable(isFocusable: boolean): Promise\<void>;<br>setFocusable(isFocusable: boolean, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.window | Window | setDimBehind(dimBehindValue: number, callback: AsyncCallback\<void>): void;<br>setDimBehind(dimBehindValue: number): Promise\<void>; | 新增 |
| ohos.window | Window | setBrightness(brightness: number): Promise\<void>;<br>setBrightness(brightness: number, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.window | Window | setBackgroundColor(color: string): Promise\<void>;<br>setBackgroundColor(color: string, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.window | Window | getColorSpace(): Promise\<ColorSpace>;<br>getColorSpace(callback: AsyncCallback\<ColorSpace>): void; | 新增 |
| ohos.window | Window | setColorSpace(colorSpace:ColorSpace): Promise\<void>;<br>setColorSpace(colorSpace:ColorSpace, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.window | Window | isSupportWideGamut(): Promise\<boolean>;<br>isSupportWideGamut(callback: AsyncCallback\<boolean>): void; | 新增 |
| ohos.window | Window | off(type: 'keyboardHeightChange', callback?: Callback\<number>): void; | 新增 |
| ohos.window | Window | on(type: 'keyboardHeightChange', callback: Callback\<number>): void; | 新增 |
| ohos.window | Window | off(type: 'systemAvoidAreaChange', callback?: Callback\<AvoidArea>): void; | 新增 |
| ohos.window | Window | on(type: 'systemAvoidAreaChange', callback: Callback\<AvoidArea>): void; | 新增 |
| ohos.window | Window | off(type: 'windowSizeChange', callback?: Callback\<Size>): void; | 新增 |
| ohos.window | Window | on(type: 'windowSizeChange', callback: Callback\<Size>): void; | 新增 |
| ohos.window | Window | isShowing(callback: AsyncCallback\<boolean>): void;<br>isShowing(): Promise\<boolean>; | 新增 |
| ohos.window | Window | loadContent(path: string, callback: AsyncCallback\<void>): void;<br>loadContent(path: string): Promise\<void>; | 新增 |
| ohos.window | Window | setSystemBarProperties(systemBarProperties: SystemBarProperties, callback: AsyncCallback\<void>): void;<br>setSystemBarProperties(systemBarProperties: SystemBarProperties): Promise\<void>; | 新增 |
| ohos.window | Window | setSystemBarEnable(names: Array\<'status'\|'navigation'>, callback: AsyncCallback\<void>): void;<br>setSystemBarEnable(names: Array\<'status'\|'navigation'>): Promise\<void>; | 新增 |
| ohos.window | Window | setLayoutFullScreen(isLayoutFullScreen: boolean, callback: AsyncCallback\<void>): void;<br>setLayoutFullScreen(isLayoutFullScreen: boolean): Promise\<void>; | 新增 |
| ohos.window | Window | setFullScreen(isFullScreen: boolean, callback: AsyncCallback\<void>): void;<br>setFullScreen(isFullScreen: boolean): Promise\<void>; | 新增 |
| ohos.window | Window | getAvoidArea(type: AvoidAreaType, callback: AsyncCallback\<AvoidArea>): void;<br>getAvoidArea(type: AvoidAreaType): Promise\<AvoidArea>; | 新增 |
| ohos.window | Window | getProperties(callback: AsyncCallback\<WindowProperties>): void;<br>getProperties(): Promise\<WindowProperties>; | 新增 |
| ohos.window | Window | destroy(callback: AsyncCallback\<void>): void;<br>destroy(): Promise\<void>; | 新增 |
| ohos.window | Window | show(callback: AsyncCallback\<void>): void;<br>show(): Promise\<void>; | 新增 |
| ohos.window | window | find(id: string, callback: AsyncCallback\<Window>): void;<br>find(id: string): Promise\<Window>; | 新增 |
| ohos.window | window | create(id: string, type: WindowType, callback: AsyncCallback\<Window>): void;<br>create(id: string, type: WindowType): Promise\<Window>;<br>create(ctx: Context, id: string, type: WindowType): Promise\<Window>;<br>create(ctx: Context, id: string, type: WindowType, callback: AsyncCallback\<Window>): void; | 新增 |
| ohos.window | ColorSpace | WIDE_GAMUT | 新增 |
| ohos.window | ColorSpace | DEFAULT | 新增 |
| ohos.window | WindowProperties | isTransparent: boolean | 新增 |
| ohos.window | WindowProperties | isRoundCorner: boolean | 新增 |
| ohos.window | WindowProperties | isPrivacyMode: boolean | 新增 |
| ohos.window | WindowProperties | isKeepScreenOn: boolean | 新增 |
| ohos.window | WindowProperties | dimBehindValue: number | 新增 |
| ohos.window | WindowProperties | brightness: number | 新增 |
| ohos.window | WindowProperties | touchable: boolean | 新增 |
| ohos.window | WindowProperties | focusable: boolean | 新增 |
| ohos.window | WindowProperties | isLayoutFullScreen: boolean | 新增 |
| ohos.window | WindowProperties | isFullScreen: boolean | 新增 |
| ohos.window | WindowProperties | type: WindowType; | 新增 |
| ohos.window | WindowProperties | windowRect: Rect; | 新增 |
| ohos.window | Size | height: number; | 新增 |
| ohos.window | Size | width: number; | 新增 |
| ohos.window | AvoidArea | bottomRect: Rect; | 新增 |
| ohos.window | AvoidArea | rightRect: Rect; | 新增 |
| ohos.window | AvoidArea | topRect: Rect; | 新增 |
| ohos.window | AvoidArea | leftRect: Rect; | 新增 |
| ohos.window | Rect | height: number; | 新增 |
| ohos.window | Rect | width: number; | 新增 |
| ohos.window | Rect | top: number; | 新增 |
| ohos.window | Rect | left: number; | 新增 |
| ohos.window | SystemBarProperties | navigationBarContentColor?: string; | 新增 |
| ohos.window | SystemBarProperties | isNavigationBarLightIcon?: boolean; | 新增 |
| ohos.window | SystemBarProperties | navigationBarColor?: string; | 新增 |
| ohos.window | SystemBarProperties | statusBarContentColor?: string; | 新增 |
| ohos.window | SystemBarProperties | isStatusBarLightIcon?: boolean; | 新增 |
| ohos.window | SystemBarProperties | statusBarColor?: string; | 新增 |
| ohos.window | AvoidAreaType | TYPE_CUTOUT | 新增 |
| ohos.window | AvoidAreaType | TYPE_SYSTEM | 新增 |
| ohos.display | Display | yDPI: number; | 新增 |
| ohos.display | Display | xDPI: number; | 新增 |
| ohos.display | Display | scaledDensity: number; | 新增 |
| ohos.display | Display | densityPixels: number; | 新增 |
| ohos.display | Display | densityDPI: number; | 新增 |
| ohos.display | Display | height: number; | 新增 |
| ohos.display | Display | width: number; | 新增 |
| ohos.display | Display | rotation: number; | 新增 |
| ohos.display | Display | refreshRate: number; | 新增 |
| ohos.display | Display | state: DisplayState; | 新增 |
| ohos.display | Display | alive: boolean; | 新增 |
| ohos.display | Display | name: string; | 新增 |
| ohos.display | Display | id: number; | 新增 |
| ohos.display | DisplayState | STATE_ON_SUSPEND | 新增 |
| ohos.display | DisplayState | STATE_VR | 新增 |
| ohos.display | DisplayState | STATE_DOZE_SUSPEND | 新增 |
| ohos.display | DisplayState | STATE_DOZE | 新增 |
| ohos.display | DisplayState | STATE_ON | 新增 |
| ohos.display | DisplayState | STATE_OFF | 新增 |
| ohos.display | DisplayState | STATE_UNKNOWN = 0 | 新增 |
| ohos.display | display | off(type: 'add' \| 'remove' \| 'change', callback?: Callback\<number>): void; | 新增 |
| ohos.display | display | off(type: 'add' \| 'remove' \| 'change', callback?: Callback\<number>): void; | 新增 |
| ohos.display | display | off(type: 'add' \| 'remove' \| 'change', callback?: Callback\<number>): void; | 新增 |
| ohos.display | display | on(type: 'add' \| 'remove' \| 'change', callback: Callback\<number>): void; | 新增 |
| ohos.display | display | on(type: 'add' \| 'remove' \| 'change', callback: Callback\<number>): void; | 新增 |
| ohos.display | display | on(type: 'add' \| 'remove' \| 'change', callback: Callback\<number>): void; | 新增 |
| ohos.display | display | getAllDisplay(callback: AsyncCallback\<Array\<Display>>): void;<br>getAllDisplay(): Promise\<Array\<Display>>; | 新增 |
| ohos.display | display | getDefaultDisplay(callback: AsyncCallback\<Display>): void;<br>getDefaultDisplay(): Promise\<Display>; | 新增 |
