# JS API Changes of the ArkUI Development Framework

The table below lists the APIs changes of the ArkUI development framework in OpenHarmony 3.2 Beta2 over OpenHarmony 3.2 Beta1.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ArkUI | AbilityComponentInterface | (want: Want): AbilityComponentAttribute; | Added|
| ArkUI | AbilityComponentAttribute | onConnect(callback: () => void): AbilityComponentAttribute; | Added|
| ArkUI | AbilityComponentAttribute | onDisconnect(callback: () => void): AbilityComponentAttribute; | Added|
| ArkUI | HttpAuthHandler | isHttpAuthInfoSaved(): boolean; | Added|
| ArkUI | HttpAuthHandler | cancel(): void; | Added|
| ArkUI | HttpAuthHandler | confirm(userName: string, password: string): boolean; | Added|
| ArkUI | HttpAuthHandler | constructor(); | Added|
| ArkUI | HitTestValue | getExtra(): string; | Added|
| ArkUI | HitTestValue | getType(): HitTestType; | Added|
| ArkUI | HitTestValue | constructor(); | Added|
| ArkUI | JsResult | handlePromptConfirm(result: string): void; | Added|
| ArkUI | Resource | readonly moduleName: string; | Added|
| ArkUI | Resource | readonly bundleName: string; | Added|
| ArkUI | TextInputAttribute | textAlign(value: TextAlign): TextInputAttribute; | Added|
| ArkUI | TextInputAttribute | showPasswordIcon(value: boolean): TextInputAttribute; | Added|
| ArkUI | TextInputAttribute | copyOption(value: boolean \| CopyOption): TextInputAttribute; | Added|
| ArkUI | InputType | PhoneNumber | Added|
| ArkUI | TextAreaAttribute | copyOption(value: boolean \| CopyOption): TextAreaAttribute; | Added|
| ArkUI | TextAttribute | copyOption(value: boolean \| CopyOption): TextAttribute; | Added|
| ArkUI | SearchAttribute | textAlign(value: TextAlign): SearchAttribute; | Added|
| ArkUI | SearchAttribute | copyOption(value: boolean \| CopyOption): SearchAttribute; | Added|
| ArkUI | ScrollAttribute | onScrollBegin(event: (dx: number, dy: number) => { dxRemain: number, dyRemain: number }): ScrollAttribute; | Added|
| ArkUI | Scroller | scrollBy(dx: Length, dy: Length); | Added|
| ArkUI | RemoteWindowInterface | (target: WindowAnimationTarget): RemoteWindowAttribute; | Added|
| ArkUI | WindowAnimationTarget | readonly windowBounds: RRect; | Added|
| ArkUI | WindowAnimationTarget | readonly abilityName: string; | Added|
| ArkUI | WindowAnimationTarget | readonly bundleName: string; | Added|
| ArkUI | RRect | radius: number; | Added|
| ArkUI | RRect | height: number; | Added|
| ArkUI | RRect | width: number; | Added|
| ArkUI | RRect | top: number; | Added|
| ArkUI | RRect | left: number; | Added|
| ArkUI | RelativeContainerInterface | (): RelativeContainerAttribute; | Added|
| ArkUI | PluginComponentAttribute | onError(callback: (info: { errcode: number; msg: string }) => void): PluginComponentAttribute; | Added|
| ArkUI | PluginComponentAttribute | onComplete(callback: () => void): PluginComponentAttribute; | Added|
| ArkUI | PluginComponentInterface | (value: { template: PluginComponentTemplate; data: any }): PluginComponentAttribute; | Added|
| ArkUI | PluginComponentTemplate | ability: string; | Added|
| ArkUI | PluginComponentTemplate | source: string; | Added|
| ArkUI | PatternLockAttribute | autoReset(value: boolean): PatternLockAttribute; | Added|
| ArkUI | PatternLockAttribute | onPatternComplete(callback: (input: Array\<number>) => void): PatternLockAttribute; | Added|
| ArkUI | PatternLockAttribute | pathStrokeWidth(value: number \| string): PatternLockAttribute; | Added|
| ArkUI | PatternLockAttribute | pathColor(value: ResourceColor): PatternLockAttribute; | Added|
| ArkUI | PatternLockAttribute | activeColor(value: ResourceColor): PatternLockAttribute; | Added|
| ArkUI | PatternLockAttribute | selectedColor(value: ResourceColor): PatternLockAttribute; | Added|
| ArkUI | PatternLockAttribute | regularColor(value: ResourceColor): PatternLockAttribute; | Added|
| ArkUI | PatternLockAttribute | backgroundColor(value: ResourceColor): PatternLockAttribute; | Added|
| ArkUI | PatternLockAttribute | circleRadius(value: Length): PatternLockAttribute; | Added|
| ArkUI | PatternLockAttribute | sideLength(value: Length): PatternLockAttribute; | Added|
| ArkUI | PatternLockInterface | (controller?: PatternLockController): PatternLockAttribute; | Added|
| ArkUI | PatternLockController | reset(); | Added|
| ArkUI | PatternLockController | constructor(); | Added|
| ArkUI | ListAttribute | onScrollBegin(event: (dx: number, dy: number) => { dxRemain: number, dyRemain: number }): ListAttribute; | Added|
| ArkUI | ListAttribute | alignListItem(value: ListItemAlign): ListAttribute; | Added|
| ArkUI | ListAttribute | lanes(value: number \| LengthConstrain): ListAttribute; | Added|
| ArkUI | ListItemAlign | End | Added|
| ArkUI | ListItemAlign | Center | Added|
| ArkUI | ListItemAlign | Start | Added|
| ArkUI | ImageFrameInfo | duration?: number; | Added|
| ArkUI | ImageFrameInfo | left?: number \| string; | Added|
| ArkUI | ImageFrameInfo | top?: number \| string; | Added|
| ArkUI | ImageFrameInfo | height?: number \| string; | Added|
| ArkUI | ImageFrameInfo | width?: number \| string; | Added|
| ArkUI | ImageFrameInfo | src: string \| Resource; | Added|
| ArkUI | GridRowAttribute | onBreakpointChange(callback: (breakpoints: string) => void): GridRowAttribute; | Added|
| ArkUI | GridRowInterface | (optiion?: GridRowOptions): GridRowAttribute; | Added|
| ArkUI | GridRowOptions | direction?: GridRowDirection; | Added|
| ArkUI | GridRowOptions | breakpoints?: BreakPoints; | Added|
| ArkUI | GridRowOptions | columns?: number \| GridRowColumnOption; | Added|
| ArkUI | GridRowOptions | gutter?: Length \| GetterOption; | Added|
| ArkUI | BreakPoints | reference?: BreakpointsReference, | Added|
| ArkUI | BreakPoints | value?: Array\<string>, | Added|
| ArkUI | GridRowDirection | RowReverse | Added|
| ArkUI | GridRowDirection | Row | Added|
| ArkUI | BreakpointsReference | ComponentSize | Added|
| ArkUI | BreakpointsReference | WindowSize | Added|
| ArkUI | GetterOption | y?: Length \| GridRowSizeOption | Added|
| ArkUI | GetterOption | x?: Length \| GridRowSizeOption, | Added|
| ArkUI | GridRowColumnOption | xxl?: number, | Added|
| ArkUI | GridRowColumnOption | xl?: number, | Added|
| ArkUI | GridRowColumnOption | lg?: number, | Added|
| ArkUI | GridRowColumnOption | md?: number, | Added|
| ArkUI | GridRowColumnOption | sm?: number, | Added|
| ArkUI | GridRowColumnOption | xs?: number, | Added|
| ArkUI | GridRowSizeOption | xxl?: Length, | Added|
| ArkUI | GridRowSizeOption | xl?: Length, | Added|
| ArkUI | GridRowSizeOption | lg?: Length, | Added|
| ArkUI | GridRowSizeOption | md?: Length, | Added|
| ArkUI | GridRowSizeOption | sm?: Length, | Added|
| ArkUI | GridRowSizeOption | xs?: Length, | Added|
| ArkUI | GridColAttribute | order(value: number \| GridColColumnOption): GridRowAttribute; | Added|
| ArkUI | GridColAttribute | offset(value: number \| GridColColumnOption): GridRowAttribute; | Added|
| ArkUI | GridColAttribute | span(value: number \| GridColColumnOption): GridRowAttribute; | Added|
| ArkUI | GridColInterface | (optiion?: GridColOptions): GridColAttribute; | Added|
| ArkUI | GridColOptions | order?: number \| GridColColumnOption; | Added|
| ArkUI | GridColOptions | offset?: number \| GridColColumnOption; | Added|
| ArkUI | GridColOptions | span?: number \| GridColColumnOption; | Added|
| ArkUI | GridColColumnOption | xxl?: number, | Added|
| ArkUI | GridColColumnOption | xl?: number, | Added|
| ArkUI | GridColColumnOption | lg?: number, | Added|
| ArkUI | GridColColumnOption | md?: number, | Added|
| ArkUI | GridColColumnOption | sm?: number, | Added|
| ArkUI | GridColColumnOption | xs?: number, | Added|
| ArkUI | CopyOption | CrossDevice = 2 | Added|
| ArkUI | CopyOption | LocalDevice = 1 | Added|
| ArkUI | CopyOption | InApp = 0 | Added|
| ArkUI | Placement | RightBottom | Added|
| ArkUI | Placement | RightTop | Added|
| ArkUI | Placement | LeftBottom | Added|
| ArkUI | Placement | LeftTop | Added|
| ArkUI | CommonMethod | onVisibleAreaChange(ratios: Array\<number>, event: (isVisible: boolean, currentRatio: number) => void): T; | Added|
| ArkUI | CommonMethod | alignRules(value: AlignRuleOption): T; | Added|
| ArkUI | CommonMethod | tabIndex(index: number): T; | Added|
| ArkUI | CommonMethod | borderImage(value: BorderImageOption): T; | Added|
| ArkUI | CommonMethod | backgroundBlurStyle(value: BlurStyle): T; | Added|
| ArkUI | BorderImageOption | fill?: boolean | Added|
| ArkUI | BorderImageOption | outset?: Length \| EdgeWidths, | Added|
| ArkUI | BorderImageOption | width?: Length \| EdgeWidths, | Added|
| ArkUI | BorderImageOption | source?: string \| Resource \| linearGradient, | Added|
| ArkUI | BorderImageOption | repeat?: RepeatMode, | Added|
| ArkUI | BorderImageOption | slice?: Length \| EdgeWidths, | Added|
| ArkUI | BlurStyle | Thick | Added|
| ArkUI | BlurStyle | Regular | Added|
| ArkUI | BlurStyle | Thin | Added|
| ArkUI | RepeatMode | Space | Added|
| ArkUI | RepeatMode | Round | Added|
| ArkUI | RepeatMode | Stretch | Added|
| ArkUI | RepeatMode | Repeat | Added|
| ArkUI | AlignRuleOption | center?: { anchor: string, align: VerticalAlign }; | Added|
| ArkUI | AlignRuleOption | bottom?: { anchor: string, align: VerticalAlign }; | Added|
| ArkUI | AlignRuleOption | top?: { anchor: string, align: VerticalAlign }; | Added|
| ArkUI | AlignRuleOption | middle?: { anchor: string, align: HorizontalAlign }; | Added|
| ArkUI | AlignRuleOption | right?: { anchor: string, align: HorizontalAlign }; | Added|
| ArkUI | AlignRuleOption | left?: { anchor: string, align: HorizontalAlign }; | Added|
| ArkUI | ICurve | interpolate(fraction : number) : number; | Added|
| elementName | ElementName | moduleName?: string; | Added|
| global |  |  function sendMouseEvent(event: MouseEvent): boolean; | Added|
| global |  |  function sendKeyEvent(event: KeyEvent): boolean; | Added|
| global |  |  function sendTouchEvent(event: TouchObject): boolean; | Added|
| global |  |  function sendEventByKey(id: string, action: number, params: string): boolean; | Added|
| global |  |  function getInspectorTree(): string; | Added|
| global |  |  function getInspectorByKey(id: string): string; | Added|
| ohos.curves | curves | function springCurve(velocity: number, mass: number, stiffness: number, damping: number): ICurve; | Added|
| ohos.curves | curves | function cubicBezierCurve(x1: number, y1: number, x2: number, y2: number): ICurve; | Added|
| ohos.curves | curves | function stepsCurve(count: number, end: boolean): ICurve; | Added|
| ohos.curves | curves | function initCurve(curve?: Curve): ICurve; | Added|
| ohos.curves | ICurve | interpolate(fraction : number) : number; | Added|
| ohos.router | RouterMode | Single | Added|
| ohos.router | RouterMode | Standard | Added|
| ohos.uiAppearance | uiAppearance | function getDarkMode(): DarkMode; | Added|
| ohos.uiAppearance | uiAppearance | function setDarkMode(mode: DarkMode, callback: AsyncCallback\<void>): void;<br>function setDarkMode(mode: DarkMode): Promise\<void>; | Added|
| ohos.uiAppearance | DarkMode | ALWAYS_LIGHT = 1 | Added|
| ohos.uiAppearance | DarkMode | ALWAYS_DARK = 0 | Added|
| viewmodel | CanvasRenderingContext2D | getPixelMap(sx: number, sy: number, sw: number, sh: number): PixelMap | Added|
| viewmodel | OffscreenCanvasRenderingContext2D | getPixelMap(sx: number, sy: number, sw: number, sh: number): PixelMap | Added|
| ohos.curves | curves | function spring(velocity: number, mass: number, stiffness: number, damping: number): string; | Deprecated|
| ohos.curves | curves | function cubicBezier(x1: number, y1: number, x2: number, y2: number): string; | Deprecated|
| ohos.curves | curves | function steps(count: number, end: boolean): string; | Deprecated|
| ohos.curves | curves | function init(curve?: Curve): string; | Deprecated|
| system.router | Router | static disableAlertBeforeBackPage(options?: DisableAlertBeforeBackPageOptions): void; | Deprecated|
| system.router | Router | static enableAlertBeforeBackPage(options: EnableAlertBeforeBackPageOptions): void; | Deprecated|
| system.router | Router | static getState(): RouterState; | Deprecated|
| system.router | Router | static getLength(): string; | Deprecated|
| system.router | Router | static clear(): void; | Deprecated|
| system.router | Router | static getParams(): ParamsInterface; | Deprecated|
| system.router | Router | static back(options?: BackRouterOptions): void; | Deprecated|
| system.router | Router | static replace(options: RouterOptions): void; | Deprecated|
| system.router | Router | static push(options: RouterOptions): void; | Deprecated|
| system.router | DisableAlertBeforeBackPageOptions | complete?: () => void; | Deprecated|
| system.router | DisableAlertBeforeBackPageOptions | cancel?: (errMsg: string) => void; | Deprecated|
| system.router | DisableAlertBeforeBackPageOptions | success?: (errMsg: string) => void; | Deprecated|
| system.router | EnableAlertBeforeBackPageOptions | complete?: () => void; | Deprecated|
| system.router | EnableAlertBeforeBackPageOptions | cancel?: (errMsg: string) => void; | Deprecated|
| system.router | EnableAlertBeforeBackPageOptions | success?: (errMsg: string) => void; | Deprecated|
| system.router | EnableAlertBeforeBackPageOptions | message: string; | Deprecated|
| system.router | RouterState | path: string; | Deprecated|
| system.router | RouterState | name: string; | Deprecated|
| system.router | RouterState | index: number; | Deprecated|
| system.router | BackRouterOptions | params?: Object; | Deprecated|
| system.router | BackRouterOptions | uri?: string; | Deprecated|
| system.router | RouterOptions | params?: Object; | Deprecated|
| system.router | RouterOptions | uri: string; | Deprecated|
| ohos.prompt | ActionMenuOptions |old : title?: string;<br>new : title?: string \| Resource;  | Updated|
| ohos.prompt | ShowDialogOptions |old : message?: string;<br>new : message?: string \| Resource;  | Updated|
| ohos.prompt | ShowDialogOptions |old : title?: string;<br>new : title?: string \| Resource;  | Updated|
| ohos.prompt | Button |old : color: string;<br>new : color: string \| Resource;  | Updated|
| ohos.prompt | Button |old : text: string;<br>new : text: string \| Resource;  | Updated|
| ohos.prompt | ShowToastOptions |old : message: string;<br>new : message: string \| Resource;  | Updated|
| ArkUI | BorderOptions |old : style?: BorderStyle;<br>new : style?: EdgeStyles \| BorderStyle; | Updated|
| ArkUI | BorderOptions |old : radius?: Length;<br>new : radius?: BorderRadiuses \| Length;  | Updated|
| ArkUI | BorderOptions |old : color?: ResourceColor;<br>new : color?: EdgeColors \| ResourceColor;  | Updated|
| ArkUI | BorderOptions |old : width?: Length;<br>new : width?: EdgeWidths \| Length;  | Updated|
| ArkUI | AnimateParam |old : curve?: Curve \| string;<br>new : curve?: Curve \| string \| ICurve;  | Updated|
