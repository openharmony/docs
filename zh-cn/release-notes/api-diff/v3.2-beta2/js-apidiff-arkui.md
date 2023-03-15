# ArkUI子系统JS API变更

OpenHarmony 3.2 Beta2版本相较于OpenHarmony 3.2 Beta1版本，ArkUI子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ArkUI | AbilityComponentInterface | (want: Want): AbilityComponentAttribute; | 新增 |
| ArkUI | AbilityComponentAttribute | onConnect(callback: () => void): AbilityComponentAttribute; | 新增 |
| ArkUI | AbilityComponentAttribute | onDisconnect(callback: () => void): AbilityComponentAttribute; | 新增 |
| ArkUI | HttpAuthHandler | isHttpAuthInfoSaved(): boolean; | 新增 |
| ArkUI | HttpAuthHandler | cancel(): void; | 新增 |
| ArkUI | HttpAuthHandler | confirm(userName: string, password: string): boolean; | 新增 |
| ArkUI | HttpAuthHandler | constructor(); | 新增 |
| ArkUI | HitTestValue | getExtra(): string; | 新增 |
| ArkUI | HitTestValue | getType(): HitTestType; | 新增 |
| ArkUI | HitTestValue | constructor(); | 新增 |
| ArkUI | JsResult | handlePromptConfirm(result: string): void; | 新增 |
| ArkUI | Resource | readonly moduleName: string; | 新增 |
| ArkUI | Resource | readonly bundleName: string; | 新增 |
| ArkUI | TextInputAttribute | textAlign(value: TextAlign): TextInputAttribute; | 新增 |
| ArkUI | TextInputAttribute | showPasswordIcon(value: boolean): TextInputAttribute; | 新增 |
| ArkUI | TextInputAttribute | copyOption(value: boolean \| CopyOption): TextInputAttribute; | 新增 |
| ArkUI | InputType | PhoneNumber | 新增 |
| ArkUI | TextAreaAttribute | copyOption(value: boolean \| CopyOption): TextAreaAttribute; | 新增 |
| ArkUI | TextAttribute | copyOption(value: boolean \| CopyOption): TextAttribute; | 新增 |
| ArkUI | SearchAttribute | textAlign(value: TextAlign): SearchAttribute; | 新增 |
| ArkUI | SearchAttribute | copyOption(value: boolean \| CopyOption): SearchAttribute; | 新增 |
| ArkUI | ScrollAttribute | onScrollBegin(event: (dx: number, dy: number) => { dxRemain: number, dyRemain: number }): ScrollAttribute; | 新增 |
| ArkUI | Scroller | scrollBy(dx: Length, dy: Length); | 新增 |
| ArkUI | RemoteWindowInterface | (target: WindowAnimationTarget): RemoteWindowAttribute; | 新增 |
| ArkUI | WindowAnimationTarget | readonly windowBounds: RRect; | 新增 |
| ArkUI | WindowAnimationTarget | readonly abilityName: string; | 新增 |
| ArkUI | WindowAnimationTarget | readonly bundleName: string; | 新增 |
| ArkUI | RRect | radius: number; | 新增 |
| ArkUI | RRect | height: number; | 新增 |
| ArkUI | RRect | width: number; | 新增 |
| ArkUI | RRect | top: number; | 新增 |
| ArkUI | RRect | left: number; | 新增 |
| ArkUI | RelativeContainerInterface | (): RelativeContainerAttribute; | 新增 |
| ArkUI | PluginComponentAttribute | onError(callback: (info: { errcode: number; msg: string }) => void): PluginComponentAttribute; | 新增 |
| ArkUI | PluginComponentAttribute | onComplete(callback: () => void): PluginComponentAttribute; | 新增 |
| ArkUI | PluginComponentInterface | (value: { template: PluginComponentTemplate; data: any }): PluginComponentAttribute; | 新增 |
| ArkUI | PluginComponentTemplate | ability: string; | 新增 |
| ArkUI | PluginComponentTemplate | source: string; | 新增 |
| ArkUI | PatternLockAttribute | autoReset(value: boolean): PatternLockAttribute; | 新增 |
| ArkUI | PatternLockAttribute | onPatternComplete(callback: (input: Array\<number>) => void): PatternLockAttribute; | 新增 |
| ArkUI | PatternLockAttribute | pathStrokeWidth(value: number \| string): PatternLockAttribute; | 新增 |
| ArkUI | PatternLockAttribute | pathColor(value: ResourceColor): PatternLockAttribute; | 新增 |
| ArkUI | PatternLockAttribute | activeColor(value: ResourceColor): PatternLockAttribute; | 新增 |
| ArkUI | PatternLockAttribute | selectedColor(value: ResourceColor): PatternLockAttribute; | 新增 |
| ArkUI | PatternLockAttribute | regularColor(value: ResourceColor): PatternLockAttribute; | 新增 |
| ArkUI | PatternLockAttribute | backgroundColor(value: ResourceColor): PatternLockAttribute; | 新增 |
| ArkUI | PatternLockAttribute | circleRadius(value: Length): PatternLockAttribute; | 新增 |
| ArkUI | PatternLockAttribute | sideLength(value: Length): PatternLockAttribute; | 新增 |
| ArkUI | PatternLockInterface | (controller?: PatternLockController): PatternLockAttribute; | 新增 |
| ArkUI | PatternLockController | reset(); | 新增 |
| ArkUI | PatternLockController | constructor(); | 新增 |
| ArkUI | ListAttribute | onScrollBegin(event: (dx: number, dy: number) => { dxRemain: number, dyRemain: number }): ListAttribute; | 新增 |
| ArkUI | ListAttribute | alignListItem(value: ListItemAlign): ListAttribute; | 新增 |
| ArkUI | ListAttribute | lanes(value: number \| LengthConstrain): ListAttribute; | 新增 |
| ArkUI | ListItemAlign | End | 新增 |
| ArkUI | ListItemAlign | Center | 新增 |
| ArkUI | ListItemAlign | Start | 新增 |
| ArkUI | ImageFrameInfo | duration?: number; | 新增 |
| ArkUI | ImageFrameInfo | left?: number \| string; | 新增 |
| ArkUI | ImageFrameInfo | top?: number \| string; | 新增 |
| ArkUI | ImageFrameInfo | height?: number \| string; | 新增 |
| ArkUI | ImageFrameInfo | width?: number \| string; | 新增 |
| ArkUI | ImageFrameInfo | src: string \| Resource; | 新增 |
| ArkUI | GridRowAttribute | onBreakpointChange(callback: (breakpoints: string) => void): GridRowAttribute; | 新增 |
| ArkUI | GridRowInterface | (optiion?: GridRowOptions): GridRowAttribute; | 新增 |
| ArkUI | GridRowOptions | direction?: GridRowDirection; | 新增 |
| ArkUI | GridRowOptions | breakpoints?: BreakPoints; | 新增 |
| ArkUI | GridRowOptions | columns?: number \| GridRowColumnOption; | 新增 |
| ArkUI | GridRowOptions | gutter?: Length \| GetterOption; | 新增 |
| ArkUI | BreakPoints | reference?: BreakpointsReference, | 新增 |
| ArkUI | BreakPoints | value?: Array\<string>, | 新增 |
| ArkUI | GridRowDirection | RowReverse | 新增 |
| ArkUI | GridRowDirection | Row | 新增 |
| ArkUI | BreakpointsReference | ComponentSize | 新增 |
| ArkUI | BreakpointsReference | WindowSize | 新增 |
| ArkUI | GetterOption | y?: Length \| GridRowSizeOption | 新增 |
| ArkUI | GetterOption | x?: Length \| GridRowSizeOption, | 新增 |
| ArkUI | GridRowColumnOption | xxl?: number, | 新增 |
| ArkUI | GridRowColumnOption | xl?: number, | 新增 |
| ArkUI | GridRowColumnOption | lg?: number, | 新增 |
| ArkUI | GridRowColumnOption | md?: number, | 新增 |
| ArkUI | GridRowColumnOption | sm?: number, | 新增 |
| ArkUI | GridRowColumnOption | xs?: number, | 新增 |
| ArkUI | GridRowSizeOption | xxl?: Length, | 新增 |
| ArkUI | GridRowSizeOption | xl?: Length, | 新增 |
| ArkUI | GridRowSizeOption | lg?: Length, | 新增 |
| ArkUI | GridRowSizeOption | md?: Length, | 新增 |
| ArkUI | GridRowSizeOption | sm?: Length, | 新增 |
| ArkUI | GridRowSizeOption | xs?: Length, | 新增 |
| ArkUI | GridColAttribute | order(value: number \| GridColColumnOption): GridRowAttribute; | 新增 |
| ArkUI | GridColAttribute | offset(value: number \| GridColColumnOption): GridRowAttribute; | 新增 |
| ArkUI | GridColAttribute | span(value: number \| GridColColumnOption): GridRowAttribute; | 新增 |
| ArkUI | GridColInterface | (optiion?: GridColOptions): GridColAttribute; | 新增 |
| ArkUI | GridColOptions | order?: number \| GridColColumnOption; | 新增 |
| ArkUI | GridColOptions | offset?: number \| GridColColumnOption; | 新增 |
| ArkUI | GridColOptions | span?: number \| GridColColumnOption; | 新增 |
| ArkUI | GridColColumnOption | xxl?: number, | 新增 |
| ArkUI | GridColColumnOption | xl?: number, | 新增 |
| ArkUI | GridColColumnOption | lg?: number, | 新增 |
| ArkUI | GridColColumnOption | md?: number, | 新增 |
| ArkUI | GridColColumnOption | sm?: number, | 新增 |
| ArkUI | GridColColumnOption | xs?: number, | 新增 |
| ArkUI | CopyOption | CrossDevice = 2 | 新增 |
| ArkUI | CopyOption | LocalDevice = 1 | 新增 |
| ArkUI | CopyOption | InApp = 0 | 新增 |
| ArkUI | Placement | RightBottom | 新增 |
| ArkUI | Placement | RightTop | 新增 |
| ArkUI | Placement | LeftBottom | 新增 |
| ArkUI | Placement | LeftTop | 新增 |
| ArkUI | CommonMethod | onVisibleAreaChange(ratios: Array\<number>, event: (isVisible: boolean, currentRatio: number) => void): T; | 新增 |
| ArkUI | CommonMethod | alignRules(value: AlignRuleOption): T; | 新增 |
| ArkUI | CommonMethod | tabIndex(index: number): T; | 新增 |
| ArkUI | CommonMethod | borderImage(value: BorderImageOption): T; | 新增 |
| ArkUI | CommonMethod | backgroundBlurStyle(value: BlurStyle): T; | 新增 |
| ArkUI | BorderImageOption | fill?: boolean | 新增 |
| ArkUI | BorderImageOption | outset?: Length \| EdgeWidths, | 新增 |
| ArkUI | BorderImageOption | width?: Length \| EdgeWidths, | 新增 |
| ArkUI | BorderImageOption | source?: string \| Resource \| linearGradient, | 新增 |
| ArkUI | BorderImageOption | repeat?: RepeatMode, | 新增 |
| ArkUI | BorderImageOption | slice?: Length \| EdgeWidths, | 新增 |
| ArkUI | BlurStyle | Thick | 新增 |
| ArkUI | BlurStyle | Regular | 新增 |
| ArkUI | BlurStyle | Thin | 新增 |
| ArkUI | RepeatMode | Space | 新增 |
| ArkUI | RepeatMode | Round | 新增 |
| ArkUI | RepeatMode | Stretch | 新增 |
| ArkUI | RepeatMode | Repeat | 新增 |
| ArkUI | AlignRuleOption | center?: { anchor: string, align: VerticalAlign }; | 新增 |
| ArkUI | AlignRuleOption | bottom?: { anchor: string, align: VerticalAlign }; | 新增 |
| ArkUI | AlignRuleOption | top?: { anchor: string, align: VerticalAlign }; | 新增 |
| ArkUI | AlignRuleOption | middle?: { anchor: string, align: HorizontalAlign }; | 新增 |
| ArkUI | AlignRuleOption | right?: { anchor: string, align: HorizontalAlign }; | 新增 |
| ArkUI | AlignRuleOption | left?: { anchor: string, align: HorizontalAlign }; | 新增 |
| ArkUI | ICurve | interpolate(fraction : number) : number; | 新增 |
| elementName | ElementName | moduleName?: string; | 新增 |
| global |  |  function sendMouseEvent(event: MouseEvent): boolean; | 新增 |
| global |  |  function sendKeyEvent(event: KeyEvent): boolean; | 新增 |
| global |  |  function sendTouchEvent(event: TouchObject): boolean; | 新增 |
| global |  |  function sendEventByKey(id: string, action: number, params: string): boolean; | 新增 |
| global |  |  function getInspectorTree(): string; | 新增 |
| global |  |  function getInspectorByKey(id: string): string; | 新增 |
| ohos.curves | curves | function springCurve(velocity: number, mass: number, stiffness: number, damping: number): ICurve; | 新增 |
| ohos.curves | curves | function cubicBezierCurve(x1: number, y1: number, x2: number, y2: number): ICurve; | 新增 |
| ohos.curves | curves | function stepsCurve(count: number, end: boolean): ICurve; | 新增 |
| ohos.curves | curves | function initCurve(curve?: Curve): ICurve; | 新增 |
| ohos.curves | ICurve | interpolate(fraction : number) : number; | 新增 |
| ohos.router | RouterMode | Single | 新增 |
| ohos.router | RouterMode | Standard | 新增 |
| ohos.uiAppearance | uiAppearance | function getDarkMode(): DarkMode; | 新增 |
| ohos.uiAppearance | uiAppearance | function setDarkMode(mode: DarkMode, callback: AsyncCallback\<void>): void;<br>function setDarkMode(mode: DarkMode): Promise\<void>; | 新增 |
| ohos.uiAppearance | DarkMode | ALWAYS_LIGHT = 1 | 新增 |
| ohos.uiAppearance | DarkMode | ALWAYS_DARK = 0 | 新增 |
| viewmodel | CanvasRenderingContext2D | getPixelMap(sx: number, sy: number, sw: number, sh: number): PixelMap | 新增 |
| viewmodel | OffscreenCanvasRenderingContext2D | getPixelMap(sx: number, sy: number, sw: number, sh: number): PixelMap | 新增 |
| ohos.curves | curves | function spring(velocity: number, mass: number, stiffness: number, damping: number): string; | 废弃 |
| ohos.curves | curves | function cubicBezier(x1: number, y1: number, x2: number, y2: number): string; | 废弃 |
| ohos.curves | curves | function steps(count: number, end: boolean): string; | 废弃 |
| ohos.curves | curves | function init(curve?: Curve): string; | 废弃 |
| system.router | Router | static disableAlertBeforeBackPage(options?: DisableAlertBeforeBackPageOptions): void; | 废弃 |
| system.router | Router | static enableAlertBeforeBackPage(options: EnableAlertBeforeBackPageOptions): void; | 废弃 |
| system.router | Router | static getState(): RouterState; | 废弃 |
| system.router | Router | static getLength(): string; | 废弃 |
| system.router | Router | static clear(): void; | 废弃 |
| system.router | Router | static getParams(): ParamsInterface; | 废弃 |
| system.router | Router | static back(options?: BackRouterOptions): void; | 废弃 |
| system.router | Router | static replace(options: RouterOptions): void; | 废弃 |
| system.router | Router | static push(options: RouterOptions): void; | 废弃 |
| system.router | DisableAlertBeforeBackPageOptions | complete?: () => void; | 废弃 |
| system.router | DisableAlertBeforeBackPageOptions | cancel?: (errMsg: string) => void; | 废弃 |
| system.router | DisableAlertBeforeBackPageOptions | success?: (errMsg: string) => void; | 废弃 |
| system.router | EnableAlertBeforeBackPageOptions | complete?: () => void; | 废弃 |
| system.router | EnableAlertBeforeBackPageOptions | cancel?: (errMsg: string) => void; | 废弃 |
| system.router | EnableAlertBeforeBackPageOptions | success?: (errMsg: string) => void; | 废弃 |
| system.router | EnableAlertBeforeBackPageOptions | message: string; | 废弃 |
| system.router | RouterState | path: string; | 废弃 |
| system.router | RouterState | name: string; | 废弃 |
| system.router | RouterState | index: number; | 废弃 |
| system.router | BackRouterOptions | params?: Object; | 废弃 |
| system.router | BackRouterOptions | uri?: string; | 废弃 |
| system.router | RouterOptions | params?: Object; | 废弃 |
| system.router | RouterOptions | uri: string; | 废弃 |
| ohos.prompt | ActionMenuOptions |old : title?: string;<br>new : title?: string \| Resource;  | 变更 |
| ohos.prompt | ShowDialogOptions |old : message?: string;<br>new : message?: string \| Resource;  | 变更 |
| ohos.prompt | ShowDialogOptions |old : title?: string;<br>new : title?: string \| Resource;  | 变更 |
| ohos.prompt | Button |old : color: string;<br>new : color: string \| Resource;  | 变更 |
| ohos.prompt | Button |old : text: string;<br>new : text: string \| Resource;  | 变更 |
| ohos.prompt | ShowToastOptions |old : message: string;<br>new : message: string \| Resource;  | 变更 |
| ArkUI | BorderOptions |old : style?: BorderStyle;<br>new : style?: EdgeStyles \| BorderStyle; | 变更 |
| ArkUI | BorderOptions |old : radius?: Length;<br>new : radius?: BorderRadiuses \| Length;  | 变更 |
| ArkUI | BorderOptions |old : color?: ResourceColor;<br>new : color?: EdgeColors \| ResourceColor;  | 变更 |
| ArkUI | BorderOptions |old : width?: Length;<br>new : width?: EdgeWidths \| Length;  | 变更 |
| ArkUI | AnimateParam |old : curve?: Curve \| string;<br>new : curve?: Curve \| string \| ICurve;  | 变更 |