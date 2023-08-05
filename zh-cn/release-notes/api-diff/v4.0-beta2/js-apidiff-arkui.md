| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：NamedRouterOptions;<br>方法or属性：params?: Object;|@ohos.router.d.ts|
|新增|NA|类名：dragController;<br>方法or属性：function executeDrag(custom: CustomBuilder \| DragItemInfo, dragInfo: DragInfo, callback: AsyncCallback\<{<br>    event: DragEvent, extraParams: string<br>  }>): void;|@ohos.arkui.dragController.d.ts|
|新增|NA|类名：dragController;<br>方法or属性：function executeDrag(custom: CustomBuilder \| DragItemInfo, dragInfo: DragInfo): Promise\<{<br>    event: DragEvent, extraParams: string<br>  }>;|@ohos.arkui.dragController.d.ts|
|新增|NA|类名：DragInfo;<br>方法or属性：pointerId: number;|@ohos.arkui.dragController.d.ts|
|新增|NA|类名：DragInfo;<br>方法or属性：data?: UDMF.UnifiedData;|@ohos.arkui.dragController.d.ts|
|新增|NA|类名：DragInfo;<br>方法or属性：extraParams?: string;|@ohos.arkui.dragController.d.ts|
|新增|NA|类名：LayeredDrawableDescriptor;<br>方法or属性：static getMaskClipPath(): string;|@ohos.arkui.drawableDescriptor.d.ts|
|新增|NA|类名：inspector;<br>方法or属性：function createComponentObserver(id: string): ComponentObserver;|@ohos.arkui.inspector.d.ts|
|新增|NA|类名：ComponentObserver;<br>方法or属性：on(type: 'layout', callback: () => void): void;|@ohos.arkui.inspector.d.ts|
|新增|NA|类名：ComponentObserver;<br>方法or属性：on(type: 'draw', callback: () => void): void;|@ohos.arkui.inspector.d.ts|
|新增|NA|类名：ComponentObserver;<br>方法or属性：off(type: 'layout', callback?: () => void): void;|@ohos.arkui.inspector.d.ts|
|新增|NA|类名：ComponentObserver;<br>方法or属性：off(type: 'draw', callback?: () => void): void;|@ohos.arkui.inspector.d.ts|
|新增|NA|类名：performanceMonitor;<br>方法or属性：function begin(scene: string, startInputType: ActionType, note?: string): void;|@ohos.arkui.performanceMonitor.d.ts|
|新增|NA|类名：performanceMonitor;<br>方法or属性：function end(scene: string): void;|@ohos.arkui.performanceMonitor.d.ts|
|新增|NA|类名：ActionType;<br>方法or属性：LAST_DOWN = 0|@ohos.arkui.performanceMonitor.d.ts|
|新增|NA|类名：ActionType;<br>方法or属性：LAST_UP = 1|@ohos.arkui.performanceMonitor.d.ts|
|新增|NA|类名：ActionType;<br>方法or属性：FIRST_MOVE = 2|@ohos.arkui.performanceMonitor.d.ts|
|新增|NA|类名：Font;<br>方法or属性：registerFont(options: font.FontOptions): void;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：Font;<br>方法or属性：getSystemFontList(): Array\<string>;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：Font;<br>方法or属性：getFontByName(fontName: string): font.FontInfo;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：MediaQuery;<br>方法or属性：matchMediaSync(condition: string): mediaQuery.MediaQueryListener;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：UIInspector;<br>方法or属性：createComponentObserver(id: string): inspector.ComponentObserver;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：Router;<br>方法or属性：pushUrl(options: router.RouterOptions, callback: AsyncCallback\<void>): void;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：Router;<br>方法or属性：pushUrl(options: router.RouterOptions): Promise\<void>;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：Router;<br>方法or属性：pushUrl(options: router.RouterOptions, mode: router.RouterMode, callback: AsyncCallback\<void>): void;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：Router;<br>方法or属性：pushUrl(options: router.RouterOptions, mode: router.RouterMode): Promise\<void>;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：Router;<br>方法or属性：replaceUrl(options: router.RouterOptions, callback: AsyncCallback\<void>): void;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：Router;<br>方法or属性：replaceUrl(options: router.RouterOptions): Promise\<void>;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：Router;<br>方法or属性：replaceUrl(options: router.RouterOptions, mode: router.RouterMode, callback: AsyncCallback\<void>): void;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：Router;<br>方法or属性：replaceUrl(options: router.RouterOptions, mode: router.RouterMode): Promise\<void>;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：Router;<br>方法or属性：back(options: router.RouterOptions): void;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：Router;<br>方法or属性：clear(): void;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：Router;<br>方法or属性：getLength(): string;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：Router;<br>方法or属性：getState(): router.RouterState;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：Router;<br>方法or属性：showAlertBeforeBackPage(options: router.EnableAlertOptions): void;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：Router;<br>方法or属性：hideAlertBeforeBackPage(): void;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：Router;<br>方法or属性：getParams(): Object;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：Router;<br>方法or属性：pushNamedRoute(options: router.NamedRouterOptions, callback: AsyncCallback\<void>): void;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：Router;<br>方法or属性：pushNamedRoute(options: router.NamedRouterOptions): Promise\<void>;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：Router;<br>方法or属性：pushNamedRoute(options: router.NamedRouterOptions, mode: router.RouterMode, callback: AsyncCallback\<void>): void;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：Router;<br>方法or属性：pushNamedRoute(options: router.NamedRouterOptions, mode: router.RouterMode): Promise\<void>;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：Router;<br>方法or属性：replaceNamedRoute(options: router.NamedRouterOptions, callback: AsyncCallback\<void>): void;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：Router;<br>方法or属性：replaceNamedRoute(options: router.NamedRouterOptions): Promise\<void>;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：Router;<br>方法or属性：replaceNamedRoute(options: router.NamedRouterOptions, mode: router.RouterMode, callback: AsyncCallback\<void>): void;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：Router;<br>方法or属性：replaceNamedRoute(options: router.NamedRouterOptions, mode: router.RouterMode): Promise\<void>;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：PromptAction;<br>方法or属性：showToast(options: promptAction.ShowToastOptions): void;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：PromptAction;<br>方法or属性：showDialog(options: promptAction.ShowDialogOptions, callback: AsyncCallback\<promptAction.ShowDialogSuccessResponse>): void;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：PromptAction;<br>方法or属性：showDialog(options: promptAction.ShowDialogOptions): Promise\<promptAction.ShowDialogSuccessResponse>;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：PromptAction;<br>方法or属性：showActionMenu(options: promptAction.ActionMenuOptions, callback: promptAction.ActionMenuSuccessResponse): void;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：PromptAction;<br>方法or属性：showActionMenu(options: promptAction.ActionMenuOptions): Promise\<promptAction.ActionMenuSuccessResponse>;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：ComponentUtils;<br>方法or属性：getRectangleById(id: string): componentUtils.ComponentInfo;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：UIContext;<br>方法or属性：getFont(): Font;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：UIContext;<br>方法or属性：getMediaQuery(): MediaQuery;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：UIContext;<br>方法or属性：getUIInspector(): UIInspector;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：UIContext;<br>方法or属性：getRouter(): Router;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：UIContext;<br>方法or属性：getPromptAction(): PromptAction;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：UIContext;<br>方法or属性：getComponentUtils(): ComponentUtils;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：UIContext;<br>方法or属性：createAnimator(options: AnimatorOptions): AnimatorResult;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：UIContext;<br>方法or属性：animateTo(value: AnimateParam, event: () => void): void;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：UIContext;<br>方法or属性：showAlertDialog(options: AlertDialogParamWithConfirm \| AlertDialogParamWithButtons): void;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：UIContext;<br>方法or属性：showActionSheet(value: ActionSheetOptions): void;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：UIContext;<br>方法or属性：showDatePickerDialog(options: DatePickerDialogOptions): void;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：UIContext;<br>方法or属性：showTimePickerDialog(options: TimePickerDialogOptions): void;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：UIContext;<br>方法or属性：showTextPickerDialog(options: TextPickerDialogOptions): void;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：UIContext;<br>方法or属性：runScopedTask(callback: () => void): void;|@ohos.arkui.UIContext.d.ts|
|新增|NA|类名：componentUtils;<br>方法or属性：type Matrix4Result = [<br>    number,<br>    number,<br>    number,<br>    number,<br>    number,<br>    number,<br>    number,<br>    number,<br>    number,<br>    number,<br>    number,<br>    number,<br>    number,<br>    number,<br>    number,<br>    number,<br>  ];|@ohos.componentUtils.d.ts|
|新增|NA|类名：componentUtils;<br>方法or属性：function getRectangleById(id: string): ComponentInfo;|@ohos.componentUtils.d.ts|
|新增|NA|类名：ComponentInfo;<br>方法or属性：size: Size|@ohos.componentUtils.d.ts|
|新增|NA|类名：ComponentInfo;<br>方法or属性：localOffset: Offset|@ohos.componentUtils.d.ts|
|新增|NA|类名：ComponentInfo;<br>方法or属性：windowOffset: Offset|@ohos.componentUtils.d.ts|
|新增|NA|类名：ComponentInfo;<br>方法or属性：screenOffset: Offset|@ohos.componentUtils.d.ts|
|新增|NA|类名：ComponentInfo;<br>方法or属性：translate: TranslateResult|@ohos.componentUtils.d.ts|
|新增|NA|类名：ComponentInfo;<br>方法or属性：scale: ScaleResult|@ohos.componentUtils.d.ts|
|新增|NA|类名：ComponentInfo;<br>方法or属性：rotate: RotateResult|@ohos.componentUtils.d.ts|
|新增|NA|类名：ComponentInfo;<br>方法or属性：transform: Matrix4Result|@ohos.componentUtils.d.ts|
|新增|NA|类名：Size;<br>方法or属性：width: number|@ohos.componentUtils.d.ts|
|新增|NA|类名：Size;<br>方法or属性：height: number|@ohos.componentUtils.d.ts|
|新增|NA|类名：Offset;<br>方法or属性：x: number|@ohos.componentUtils.d.ts|
|新增|NA|类名：TranslateResult;<br>方法or属性：x: number|@ohos.componentUtils.d.ts|
|新增|NA|类名：ScaleResult;<br>方法or属性：x: number|@ohos.componentUtils.d.ts|
|新增|NA|类名：RotateResult;<br>方法or属性：x: number|@ohos.componentUtils.d.ts|
|新增|NA|类名：Offset;<br>方法or属性：y: number|@ohos.componentUtils.d.ts|
|新增|NA|类名：TranslateResult;<br>方法or属性：y: number|@ohos.componentUtils.d.ts|
|新增|NA|类名：ScaleResult;<br>方法or属性：y: number|@ohos.componentUtils.d.ts|
|新增|NA|类名：RotateResult;<br>方法or属性：y: number|@ohos.componentUtils.d.ts|
|新增|NA|类名：TranslateResult;<br>方法or属性：z: number|@ohos.componentUtils.d.ts|
|新增|NA|类名：ScaleResult;<br>方法or属性：z: number|@ohos.componentUtils.d.ts|
|新增|NA|类名：RotateResult;<br>方法or属性：z: number|@ohos.componentUtils.d.ts|
|新增|NA|类名：ScaleResult;<br>方法or属性：centerX: number|@ohos.componentUtils.d.ts|
|新增|NA|类名：RotateResult;<br>方法or属性：centerX: number|@ohos.componentUtils.d.ts|
|新增|NA|类名：ScaleResult;<br>方法or属性：centerY: number|@ohos.componentUtils.d.ts|
|新增|NA|类名：RotateResult;<br>方法or属性：centerY: number|@ohos.componentUtils.d.ts|
|新增|NA|类名：RotateResult;<br>方法or属性：angle: number|@ohos.componentUtils.d.ts|
|新增|NA|类名：curves;<br>方法or属性：function customCurve(interpolate: (fraction: number) => number): ICurve;|@ohos.curves.d.ts|
|新增|NA|类名：font;<br>方法or属性：function getSystemFontList(): Array\<string>;|@ohos.font.d.ts|
|新增|NA|类名：font;<br>方法or属性：function getFontByName(fontName: string): FontInfo;|@ohos.font.d.ts|
|新增|NA|类名：FontInfo;<br>方法or属性：path: string;|@ohos.font.d.ts|
|新增|NA|类名：FontInfo;<br>方法or属性：postScriptName: string;|@ohos.font.d.ts|
|新增|NA|类名：FontInfo;<br>方法or属性：fullName: string;|@ohos.font.d.ts|
|新增|NA|类名：FontInfo;<br>方法or属性：family: string;|@ohos.font.d.ts|
|新增|NA|类名：FontInfo;<br>方法or属性：subfamily: string;|@ohos.font.d.ts|
|新增|NA|类名：FontInfo;<br>方法or属性：weight: number;|@ohos.font.d.ts|
|新增|NA|类名：FontInfo;<br>方法or属性：width: number;|@ohos.font.d.ts|
|新增|NA|类名：FontInfo;<br>方法or属性：italic: boolean;|@ohos.font.d.ts|
|新增|NA|类名：FontInfo;<br>方法or属性：monoSpace: boolean;|@ohos.font.d.ts|
|新增|NA|类名：FontInfo;<br>方法or属性：symbolic: boolean;|@ohos.font.d.ts|
|新增|NA|类名：router;<br>方法or属性：function pushNamedRoute(options: NamedRouterOptions, callback: AsyncCallback\<void>): void;|@ohos.router.d.ts|
|新增|NA|类名：router;<br>方法or属性：function pushNamedRoute(options: NamedRouterOptions): Promise\<void>;|@ohos.router.d.ts|
|新增|NA|类名：router;<br>方法or属性：function pushNamedRoute(options: NamedRouterOptions, mode: RouterMode, callback: AsyncCallback\<void>): void;|@ohos.router.d.ts|
|新增|NA|类名：router;<br>方法or属性：function pushNamedRoute(options: NamedRouterOptions, mode: RouterMode): Promise\<void>;|@ohos.router.d.ts|
|新增|NA|类名：router;<br>方法or属性：function replaceNamedRoute(options: NamedRouterOptions, callback: AsyncCallback\<void>): void;|@ohos.router.d.ts|
|新增|NA|类名：router;<br>方法or属性：function replaceNamedRoute(options: NamedRouterOptions): Promise\<void>;|@ohos.router.d.ts|
|新增|NA|类名：router;<br>方法or属性：function replaceNamedRoute(options: NamedRouterOptions, mode: RouterMode, callback: AsyncCallback\<void>): void;|@ohos.router.d.ts|
|新增|NA|类名：router;<br>方法or属性：function replaceNamedRoute(options: NamedRouterOptions, mode: RouterMode): Promise\<void>;|@ohos.router.d.ts|
|新增|NA|类名：NamedRouterOptions;<br>方法or属性：name: string;|@ohos.router.d.ts|
|废弃版本有变化|类名：matrix4;<br>方法or属性：function copy(): Matrix4Transit;<br>旧版本信息：|类名：matrix4;<br>方法or属性：function copy(): Matrix4Transit;<br>新版本信息：10<br>代替接口：|@ohos.matrix4.d.ts|
|废弃版本有变化|类名：matrix4;<br>方法or属性：function invert(): Matrix4Transit;<br>旧版本信息：|类名：matrix4;<br>方法or属性：function invert(): Matrix4Transit;<br>新版本信息：10<br>代替接口：|@ohos.matrix4.d.ts|
|废弃版本有变化|类名：matrix4;<br>方法or属性：function combine(options: Matrix4Transit): Matrix4Transit;<br>旧版本信息：|类名：matrix4;<br>方法or属性：function combine(options: Matrix4Transit): Matrix4Transit;<br>新版本信息：10<br>代替接口：|@ohos.matrix4.d.ts|
|废弃版本有变化|类名：matrix4;<br>方法or属性：function translate(options: TranslateOption): Matrix4Transit;<br>旧版本信息：|类名：matrix4;<br>方法or属性：function translate(options: TranslateOption): Matrix4Transit;<br>新版本信息：10<br>代替接口：|@ohos.matrix4.d.ts|
|废弃版本有变化|类名：matrix4;<br>方法or属性：function scale(options: ScaleOption): Matrix4Transit;<br>旧版本信息：|类名：matrix4;<br>方法or属性：function scale(options: ScaleOption): Matrix4Transit;<br>新版本信息：10<br>代替接口：|@ohos.matrix4.d.ts|
|废弃版本有变化|类名：matrix4;<br>方法or属性：function rotate(options: RotateOption): Matrix4Transit;<br>旧版本信息：|类名：matrix4;<br>方法or属性：function rotate(options: RotateOption): Matrix4Transit;<br>新版本信息：10<br>代替接口：|@ohos.matrix4.d.ts|
|废弃版本有变化|类名：matrix4;<br>方法or属性：function transformPoint(options: [number, number]): [number, number];<br>旧版本信息：|类名：matrix4;<br>方法or属性：function transformPoint(options: [number, number]): [number, number];<br>新版本信息：10<br>代替接口：|@ohos.matrix4.d.ts|
|废弃版本有变化|类名：ClickEvent;<br>方法or属性：screenX: number;<br>旧版本信息：|类名：ClickEvent;<br>方法or属性：screenX: number;<br>新版本信息：10<br>代替接口： ClickEvent#windowX|common.d.ts|
|废弃版本有变化|类名：MouseEvent;<br>方法or属性：screenX: number;<br>旧版本信息：|类名：MouseEvent;<br>方法or属性：screenX: number;<br>新版本信息：10<br>代替接口： MouseEvent#windowX|common.d.ts|
|废弃版本有变化|类名：TouchObject;<br>方法or属性：screenX: number;<br>旧版本信息：|类名：TouchObject;<br>方法or属性：screenX: number;<br>新版本信息：10<br>代替接口： TouchObject#windowX|common.d.ts|
|废弃版本有变化|类名：ClickEvent;<br>方法or属性：screenY: number;<br>旧版本信息：|类名：ClickEvent;<br>方法or属性：screenY: number;<br>新版本信息：10<br>代替接口： ClickEvent#windowY|common.d.ts|
|废弃版本有变化|类名：MouseEvent;<br>方法or属性：screenY: number;<br>旧版本信息：|类名：MouseEvent;<br>方法or属性：screenY: number;<br>新版本信息：10<br>代替接口： MouseEvent#windowY|common.d.ts|
|废弃版本有变化|类名：TouchObject;<br>方法or属性：screenY: number;<br>旧版本信息：|类名：TouchObject;<br>方法or属性：screenY: number;<br>新版本信息：10<br>代替接口： TouchObject#windowY|common.d.ts|
|废弃版本有变化|类名：DragEvent;<br>方法or属性：getX(): number;<br>旧版本信息：|类名：DragEvent;<br>方法or属性：getX(): number;<br>新版本信息：10<br>代替接口： DragEvent#getWindowX()|common.d.ts|
|废弃版本有变化|类名：DragEvent;<br>方法or属性：getY(): number;<br>旧版本信息：|类名：DragEvent;<br>方法or属性：getY(): number;<br>新版本信息：10<br>代替接口： DragEvent#getWindowY()|common.d.ts|
|废弃版本有变化|类名：AppStorage;<br>方法or属性：static Link(propName: string): any;<br>旧版本信息：|类名：AppStorage;<br>方法or属性：static Link(propName: string): any;<br>新版本信息：10<br>代替接口： AppStorage#link|common_ts_ets_api.d.ts|
|废弃版本有变化|类名：AppStorage;<br>方法or属性：static SetAndLink\<T>(propName: string, defaultValue: T): SubscribedAbstractProperty\<T>;<br>旧版本信息：|类名：AppStorage;<br>方法or属性：static SetAndLink\<T>(propName: string, defaultValue: T): SubscribedAbstractProperty\<T>;<br>新版本信息：10<br>代替接口： AppStorage#setAndLink|common_ts_ets_api.d.ts|
|废弃版本有变化|类名：AppStorage;<br>方法or属性：static Prop(propName: string): any;<br>旧版本信息：|类名：AppStorage;<br>方法or属性：static Prop(propName: string): any;<br>新版本信息：10<br>代替接口： AppStorage#prop|common_ts_ets_api.d.ts|
|废弃版本有变化|类名：AppStorage;<br>方法or属性：static SetAndProp\<S>(propName: string, defaultValue: S): SubscribedAbstractProperty\<S>;<br>旧版本信息：|类名：AppStorage;<br>方法or属性：static SetAndProp\<S>(propName: string, defaultValue: S): SubscribedAbstractProperty\<S>;<br>新版本信息：10<br>代替接口： AppStorage#setAndProp|common_ts_ets_api.d.ts|
|废弃版本有变化|类名：AppStorage;<br>方法or属性：static Has(propName: string): boolean;<br>旧版本信息：|类名：AppStorage;<br>方法or属性：static Has(propName: string): boolean;<br>新版本信息：10<br>代替接口： AppStorage#has|common_ts_ets_api.d.ts|
|废弃版本有变化|类名：AppStorage;<br>方法or属性：static Get\<T>(propName: string): T \| undefined;<br>旧版本信息：|类名：AppStorage;<br>方法or属性：static Get\<T>(propName: string): T \| undefined;<br>新版本信息：10<br>代替接口： AppStorage#get|common_ts_ets_api.d.ts|
|废弃版本有变化|类名：AppStorage;<br>方法or属性：static Set\<T>(propName: string, newValue: T): boolean;<br>旧版本信息：|类名：AppStorage;<br>方法or属性：static Set\<T>(propName: string, newValue: T): boolean;<br>新版本信息：10<br>代替接口： AppStorage#set|common_ts_ets_api.d.ts|
|废弃版本有变化|类名：AppStorage;<br>方法or属性：static SetOrCreate\<T>(propName: string, newValue: T): void;<br>旧版本信息：|类名：AppStorage;<br>方法or属性：static SetOrCreate\<T>(propName: string, newValue: T): void;<br>新版本信息：10<br>代替接口： AppStorage#setOrCreate|common_ts_ets_api.d.ts|
|废弃版本有变化|类名：AppStorage;<br>方法or属性：static Delete(propName: string): boolean;<br>旧版本信息：|类名：AppStorage;<br>方法or属性：static Delete(propName: string): boolean;<br>新版本信息：10<br>代替接口： AppStorage#delete|common_ts_ets_api.d.ts|
|废弃版本有变化|类名：AppStorage;<br>方法or属性：static Keys(): IterableIterator\<string>;<br>旧版本信息：|类名：AppStorage;<br>方法or属性：static Keys(): IterableIterator\<string>;<br>新版本信息：10<br>代替接口： AppStorage#keys|common_ts_ets_api.d.ts|
|废弃版本有变化|类名：AppStorage;<br>方法or属性：static Clear(): boolean;<br>旧版本信息：|类名：AppStorage;<br>方法or属性：static Clear(): boolean;<br>新版本信息：10<br>代替接口： AppStorage#clear|common_ts_ets_api.d.ts|
|废弃版本有变化|类名：AppStorage;<br>方法or属性：static IsMutable(propName: string): boolean;<br>旧版本信息：|类名：AppStorage;<br>方法or属性：static IsMutable(propName: string): boolean;<br>新版本信息：10<br>代替接口：|common_ts_ets_api.d.ts|
|废弃版本有变化|类名：AppStorage;<br>方法or属性：static Size(): number;<br>旧版本信息：|类名：AppStorage;<br>方法or属性：static Size(): number;<br>新版本信息：10<br>代替接口： AppStorage#size|common_ts_ets_api.d.ts|
|废弃版本有变化|类名：Environment;<br>方法or属性：static EnvProp\<S>(key: string, value: S): boolean;<br>旧版本信息：|类名：Environment;<br>方法or属性：static EnvProp\<S>(key: string, value: S): boolean;<br>新版本信息：10<br>代替接口： Environment#envProp|common_ts_ets_api.d.ts|
|废弃版本有变化|类名：Environment;<br>方法or属性：static EnvProps(<br>    props: {<br>      key: string;<br>      defaultValue: any;<br>    }[],<br>  ): void;<br>旧版本信息：|类名：Environment;<br>方法or属性：static EnvProps(<br>    props: {<br>      key: string;<br>      defaultValue: any;<br>    }[],<br>  ): void;<br>新版本信息：10<br>代替接口： Environment#envProps|common_ts_ets_api.d.ts|
|废弃版本有变化|类名：Environment;<br>方法or属性：static Keys(): Array\<string>;<br>旧版本信息：|类名：Environment;<br>方法or属性：static Keys(): Array\<string>;<br>新版本信息：10<br>代替接口： Environment#keys|common_ts_ets_api.d.ts|
|废弃版本有变化|类名：PersistentStorage;<br>方法or属性：static Keys(): Array\<string>;<br>旧版本信息：|类名：PersistentStorage;<br>方法or属性：static Keys(): Array\<string>;<br>新版本信息：10<br>代替接口： PersistentStorage#keys|common_ts_ets_api.d.ts|
|废弃版本有变化|类名：PersistentStorage;<br>方法or属性：static PersistProp\<T>(key: string, defaultValue: T): void;<br>旧版本信息：|类名：PersistentStorage;<br>方法or属性：static PersistProp\<T>(key: string, defaultValue: T): void;<br>新版本信息：10<br>代替接口： PersistentStorage#persistProp|common_ts_ets_api.d.ts|
|废弃版本有变化|类名：PersistentStorage;<br>方法or属性：static DeleteProp(key: string): void;<br>旧版本信息：|类名：PersistentStorage;<br>方法or属性：static DeleteProp(key: string): void;<br>新版本信息：10<br>代替接口： PersistentStorage#deleteProp|common_ts_ets_api.d.ts|
|废弃版本有变化|类名：PersistentStorage;<br>方法or属性：static PersistProps(<br>    properties: {<br>      key: string;<br>      defaultValue: any;<br>    }[],<br>  ): void;<br>旧版本信息：|类名：PersistentStorage;<br>方法or属性：static PersistProps(<br>    properties: {<br>      key: string;<br>      defaultValue: any;<br>    }[],<br>  ): void;<br>新版本信息：10<br>代替接口： PersistentStorage#PersistProps|common_ts_ets_api.d.ts|
|废弃版本有变化|类名：LocalStorage;<br>方法or属性：static GetShared(): LocalStorage;<br>旧版本信息：|类名：LocalStorage;<br>方法or属性：static GetShared(): LocalStorage;<br>新版本信息：10<br>代替接口： LocalStorage#getShared|common_ts_ets_api.d.ts|
|废弃版本有变化|类名：ListItemInterface;<br>方法or属性：(value?: string): ListItemAttribute;<br>旧版本信息：|类名：ListItemInterface;<br>方法or属性：(value?: string): ListItemAttribute;<br>新版本信息：10<br>代替接口： listItem/ListItemInterface|list_item.d.ts|
|废弃版本有变化|类名：NavigationAttribute;<br>方法or属性：toolBar(value: object \| CustomBuilder): NavigationAttribute;<br>旧版本信息：|类名：NavigationAttribute;<br>方法or属性：toolBar(value: object \| CustomBuilder): NavigationAttribute;<br>新版本信息：10<br>代替接口： navigation/NavigationAttribute#toolbarConfiguration|navigation.d.ts|
|废弃版本有变化|类名：WebAttribute;<br>方法or属性：password(password: boolean): WebAttribute;<br>旧版本信息：|类名：WebAttribute;<br>方法or属性：password(password: boolean): WebAttribute;<br>新版本信息：10<br>代替接口：|web.d.ts|
|废弃版本有变化|类名：WebAttribute;<br>方法or属性：tableData(tableData: boolean): WebAttribute;<br>旧版本信息：|类名：WebAttribute;<br>方法or属性：tableData(tableData: boolean): WebAttribute;<br>新版本信息：10<br>代替接口：|web.d.ts|
|废弃版本有变化|类名：WebAttribute;<br>方法or属性：wideViewModeAccess(wideViewModeAccess: boolean): WebAttribute;<br>旧版本信息：|类名：WebAttribute;<br>方法or属性：wideViewModeAccess(wideViewModeAccess: boolean): WebAttribute;<br>新版本信息：10<br>代替接口：|web.d.ts|
|访问级别有变化|类名：uiAppearance;<br>方法or属性：declare uiAppearance<br>旧版本信息：|类名：uiAppearance;<br>方法or属性：declare uiAppearance<br>新版本信息：systemapi|@ohos.uiAppearance.d.ts|
|访问级别有变化|类名：DarkMode;<br>方法or属性：enum DarkMode<br>旧版本信息：|类名：DarkMode;<br>方法or属性：enum DarkMode<br>新版本信息：systemapi|@ohos.uiAppearance.d.ts|
|访问级别有变化|类名：DarkMode;<br>方法or属性：ALWAYS_DARK = 0<br>旧版本信息：|类名：DarkMode;<br>方法or属性：ALWAYS_DARK = 0<br>新版本信息：systemapi|@ohos.uiAppearance.d.ts|
|访问级别有变化|类名：DarkMode;<br>方法or属性：ALWAYS_LIGHT = 1<br>旧版本信息：|类名：DarkMode;<br>方法or属性：ALWAYS_LIGHT = 1<br>新版本信息：systemapi|@ohos.uiAppearance.d.ts|
|访问级别有变化|类名：CommonMethod;<br>方法or属性：sphericalEffect(value: number): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：sphericalEffect(value: number): T;<br>新版本信息：systemapi|common.d.ts|
|访问级别有变化|类名：CommonMethod;<br>方法or属性：lightUpEffect(value: number): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：lightUpEffect(value: number): T;<br>新版本信息：systemapi|common.d.ts|
|访问级别有变化|类名：CommonMethod;<br>方法or属性：pixelStretchEffect(options: PixelStretchEffectOptions): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：pixelStretchEffect(options: PixelStretchEffectOptions): T;<br>新版本信息：systemapi|common.d.ts|
|访问级别有变化|类名：ChainEdgeEffect;<br>方法or属性：DEFAULT<br>旧版本信息：|类名：ChainEdgeEffect;<br>方法or属性：DEFAULT<br>新版本信息：systemapi|list.d.ts|
|访问级别有变化|类名：ChainEdgeEffect;<br>方法or属性：STRETCH<br>旧版本信息：|类名：ChainEdgeEffect;<br>方法or属性：STRETCH<br>新版本信息：systemapi|list.d.ts|
|访问级别有变化|类名：ChainAnimationOptions;<br>方法or属性：minSpace: Length;<br>旧版本信息：|类名：ChainAnimationOptions;<br>方法or属性：minSpace: Length;<br>新版本信息：systemapi|list.d.ts|
|访问级别有变化|类名：ChainAnimationOptions;<br>方法or属性：maxSpace: Length;<br>旧版本信息：|类名：ChainAnimationOptions;<br>方法or属性：maxSpace: Length;<br>新版本信息：systemapi|list.d.ts|
|访问级别有变化|类名：ChainAnimationOptions;<br>方法or属性：conductivity?: number;<br>旧版本信息：|类名：ChainAnimationOptions;<br>方法or属性：conductivity?: number;<br>新版本信息：systemapi|list.d.ts|
|访问级别有变化|类名：ChainAnimationOptions;<br>方法or属性：intensity?: number;<br>旧版本信息：|类名：ChainAnimationOptions;<br>方法or属性：intensity?: number;<br>新版本信息：systemapi|list.d.ts|
|访问级别有变化|类名：ChainAnimationOptions;<br>方法or属性：edgeEffect?: ChainEdgeEffect;<br>旧版本信息：|类名：ChainAnimationOptions;<br>方法or属性：edgeEffect?: ChainEdgeEffect;<br>新版本信息：systemapi|list.d.ts|
|访问级别有变化|类名：RRect;<br>方法or属性：left: number;<br>旧版本信息：|类名：RRect;<br>方法or属性：left: number;<br>新版本信息：systemapi|remote_window.d.ts|
|访问级别有变化|类名：RRect;<br>方法or属性：top: number;<br>旧版本信息：|类名：RRect;<br>方法or属性：top: number;<br>新版本信息：systemapi|remote_window.d.ts|
|访问级别有变化|类名：RRect;<br>方法or属性：width: number;<br>旧版本信息：|类名：RRect;<br>方法or属性：width: number;<br>新版本信息：systemapi|remote_window.d.ts|
|访问级别有变化|类名：RRect;<br>方法or属性：height: number;<br>旧版本信息：|类名：RRect;<br>方法or属性：height: number;<br>新版本信息：systemapi|remote_window.d.ts|
|访问级别有变化|类名：RRect;<br>方法or属性：radius: number;<br>旧版本信息：|类名：RRect;<br>方法or属性：radius: number;<br>新版本信息：systemapi|remote_window.d.ts|
|访问级别有变化|类名：WindowAnimationTarget;<br>方法or属性：readonly bundleName: string;<br>旧版本信息：|类名：WindowAnimationTarget;<br>方法or属性：readonly bundleName: string;<br>新版本信息：systemapi|remote_window.d.ts|
|访问级别有变化|类名：WindowAnimationTarget;<br>方法or属性：readonly abilityName: string;<br>旧版本信息：|类名：WindowAnimationTarget;<br>方法or属性：readonly abilityName: string;<br>新版本信息：systemapi|remote_window.d.ts|
|访问级别有变化|类名：WindowAnimationTarget;<br>方法or属性：readonly windowBounds: RRect;<br>旧版本信息：|类名：WindowAnimationTarget;<br>方法or属性：readonly windowBounds: RRect;<br>新版本信息：systemapi|remote_window.d.ts|
|访问级别有变化|类名：WindowAnimationTarget;<br>方法or属性：readonly missionId: number;<br>旧版本信息：|类名：WindowAnimationTarget;<br>方法or属性：readonly missionId: number;<br>新版本信息：systemapi|remote_window.d.ts|
|type有变化|类名：Matrix2D;<br>方法or属性：scaleX?: number;<br>旧版本信息：|类名：Matrix2D;<br>方法or属性：scaleX?: number;<br>新版本信息：number|canvaspattern.d.ts|
|type有变化|类名：Matrix2D;<br>方法or属性：rotateY?: number;<br>旧版本信息：|类名：Matrix2D;<br>方法or属性：rotateY?: number;<br>新版本信息：number|canvaspattern.d.ts|
|type有变化|类名：Matrix2D;<br>方法or属性：rotateX?: number;<br>旧版本信息：|类名：Matrix2D;<br>方法or属性：rotateX?: number;<br>新版本信息：number|canvaspattern.d.ts|
|type有变化|类名：Matrix2D;<br>方法or属性：scaleY?: number;<br>旧版本信息：|类名：Matrix2D;<br>方法or属性：scaleY?: number;<br>新版本信息：number|canvaspattern.d.ts|
|type有变化|类名：Matrix2D;<br>方法or属性：translateX?: number;<br>旧版本信息：|类名：Matrix2D;<br>方法or属性：translateX?: number;<br>新版本信息：number|canvaspattern.d.ts|
|type有变化|类名：Matrix2D;<br>方法or属性：translateY?: number;<br>旧版本信息：|类名：Matrix2D;<br>方法or属性：translateY?: number;<br>新版本信息：number|canvaspattern.d.ts|
|type有变化|类名：FontOptions;<br>方法or属性：familyName: string \| Resource;<br>旧版本信息：|类名：FontOptions;<br>方法or属性：familyName: string \| Resource;<br>新版本信息：string \| Resource|@ohos.font.d.ts|
|type有变化|类名：FontOptions;<br>方法or属性：familySrc: string \| Resource;<br>旧版本信息：|类名：FontOptions;<br>方法or属性：familySrc: string \| Resource;<br>新版本信息：string \| Resource|@ohos.font.d.ts|
|type有变化|类名：TranslateOption;<br>方法or属性：x?: number;<br>旧版本信息：|类名：TranslateOption;<br>方法or属性：x?: number;<br>新版本信息：?number|@ohos.matrix4.d.ts|
|type有变化|类名：ScaleOption;<br>方法or属性：x?: number;<br>旧版本信息：|类名：ScaleOption;<br>方法or属性：x?: number;<br>新版本信息：?number|@ohos.matrix4.d.ts|
|type有变化|类名：RotateOption;<br>方法or属性：x?: number;<br>旧版本信息：|类名：RotateOption;<br>方法or属性：x?: number;<br>新版本信息：?number|@ohos.matrix4.d.ts|
|type有变化|类名：TranslateOption;<br>方法or属性：y?: number;<br>旧版本信息：|类名：TranslateOption;<br>方法or属性：y?: number;<br>新版本信息：?number|@ohos.matrix4.d.ts|
|type有变化|类名：ScaleOption;<br>方法or属性：y?: number;<br>旧版本信息：|类名：ScaleOption;<br>方法or属性：y?: number;<br>新版本信息：?number|@ohos.matrix4.d.ts|
|type有变化|类名：RotateOption;<br>方法or属性：y?: number;<br>旧版本信息：|类名：RotateOption;<br>方法or属性：y?: number;<br>新版本信息：?number|@ohos.matrix4.d.ts|
|type有变化|类名：TranslateOption;<br>方法or属性：z?: number;<br>旧版本信息：|类名：TranslateOption;<br>方法or属性：z?: number;<br>新版本信息：?number|@ohos.matrix4.d.ts|
|type有变化|类名：ScaleOption;<br>方法or属性：z?: number;<br>旧版本信息：|类名：ScaleOption;<br>方法or属性：z?: number;<br>新版本信息：?number|@ohos.matrix4.d.ts|
|type有变化|类名：RotateOption;<br>方法or属性：z?: number;<br>旧版本信息：|类名：RotateOption;<br>方法or属性：z?: number;<br>新版本信息：?number|@ohos.matrix4.d.ts|
|type有变化|类名：ScaleOption;<br>方法or属性：centerX?: number;<br>旧版本信息：|类名：ScaleOption;<br>方法or属性：centerX?: number;<br>新版本信息：?number|@ohos.matrix4.d.ts|
|type有变化|类名：RotateOption;<br>方法or属性：centerX?: number;<br>旧版本信息：|类名：RotateOption;<br>方法or属性：centerX?: number;<br>新版本信息：?number|@ohos.matrix4.d.ts|
|type有变化|类名：ScaleOption;<br>方法or属性：centerY?: number;<br>旧版本信息：|类名：ScaleOption;<br>方法or属性：centerY?: number;<br>新版本信息：?number|@ohos.matrix4.d.ts|
|type有变化|类名：RotateOption;<br>方法or属性：centerY?: number;<br>旧版本信息：|类名：RotateOption;<br>方法or属性：centerY?: number;<br>新版本信息：?number|@ohos.matrix4.d.ts|
|type有变化|类名：RotateOption;<br>方法or属性：angle?: number;<br>旧版本信息：|类名：RotateOption;<br>方法or属性：angle?: number;<br>新版本信息：?number|@ohos.matrix4.d.ts|
|type有变化|类名：MeasureOptions;<br>方法or属性：textContent: string \| Resource;<br>旧版本信息：( string \| Resource )|类名：MeasureOptions;<br>方法or属性：textContent: string \| Resource;<br>新版本信息：string \| Resource|@ohos.measure.d.ts|
|type有变化|类名：MeasureOptions;<br>方法or属性：constraintWidth?: number \| string \| Resource;<br>旧版本信息：|类名：MeasureOptions;<br>方法or属性：constraintWidth?: number \| string \| Resource;<br>新版本信息：?(number \| string \| Resource)|@ohos.measure.d.ts|
|type有变化|类名：MeasureOptions;<br>方法or属性：fontSize?: number \| string \| Resource;<br>旧版本信息：|类名：MeasureOptions;<br>方法or属性：fontSize?: number \| string \| Resource;<br>新版本信息：?(number \| string \| Resource)|@ohos.measure.d.ts|
|type有变化|类名：MeasureOptions;<br>方法or属性：fontStyle?: number \| FontStyle;<br>旧版本信息：|类名：MeasureOptions;<br>方法or属性：fontStyle?: number \| FontStyle;<br>新版本信息：?(number \| FontStyle)|@ohos.measure.d.ts|
|type有变化|类名：MeasureOptions;<br>方法or属性：fontWeight?: number \| string \| FontWeight;<br>旧版本信息：|类名：MeasureOptions;<br>方法or属性：fontWeight?: number \| string \| FontWeight;<br>新版本信息：?(number \| string \| FontWeight)|@ohos.measure.d.ts|
|type有变化|类名：MeasureOptions;<br>方法or属性：fontFamily?: string \| Resource;<br>旧版本信息：|类名：MeasureOptions;<br>方法or属性：fontFamily?: string \| Resource;<br>新版本信息：?(number \| Resource)|@ohos.measure.d.ts|
|type有变化|类名：MeasureOptions;<br>方法or属性：letterSpacing?: number \| string;<br>旧版本信息：|类名：MeasureOptions;<br>方法or属性：letterSpacing?: number \| string;<br>新版本信息：?(number \| string)|@ohos.measure.d.ts|
|type有变化|类名：MeasureOptions;<br>方法or属性：textAlign?: number \| TextAlign;<br>旧版本信息：|类名：MeasureOptions;<br>方法or属性：textAlign?: number \| TextAlign;<br>新版本信息：?(number \| TextAlign)|@ohos.measure.d.ts|
|type有变化|类名：MeasureOptions;<br>方法or属性：overflow?: number \| TextOverflow;<br>旧版本信息：|类名：MeasureOptions;<br>方法or属性：overflow?: number \| TextOverflow;<br>新版本信息：?(number \| TextOverflow)|@ohos.measure.d.ts|
|type有变化|类名：MeasureOptions;<br>方法or属性：maxLines?: number;<br>旧版本信息：|类名：MeasureOptions;<br>方法or属性：maxLines?: number;<br>新版本信息：?number|@ohos.measure.d.ts|
|type有变化|类名：MeasureOptions;<br>方法or属性：lineHeight?: number \| string \| Resource;<br>旧版本信息：|类名：MeasureOptions;<br>方法or属性：lineHeight?: number \| string \| Resource;<br>新版本信息：?(number \| string \| Resource)|@ohos.measure.d.ts|
|type有变化|类名：MeasureOptions;<br>方法or属性：baselineOffset?: number \| string;<br>旧版本信息：|类名：MeasureOptions;<br>方法or属性：baselineOffset?: number \| string;<br>新版本信息：?(number \| string)|@ohos.measure.d.ts|
|type有变化|类名：MeasureOptions;<br>方法or属性：textCase?: number \| TextCase;<br>旧版本信息：|类名：MeasureOptions;<br>方法or属性：textCase?: number \| TextCase;<br>新版本信息：?(number \| TextCase)|@ohos.measure.d.ts|
|type有变化|类名：MediaQueryResult;<br>方法or属性：readonly matches: boolean;<br>旧版本信息：|类名：MediaQueryResult;<br>方法or属性：readonly matches: boolean;<br>新版本信息：boolean|@ohos.mediaquery.d.ts|
|type有变化|类名：MediaQueryResult;<br>方法or属性：readonly media: string;<br>旧版本信息：|类名：MediaQueryResult;<br>方法or属性：readonly media: string;<br>新版本信息：string|@ohos.mediaquery.d.ts|
|type有变化|类名：ShowToastOptions;<br>方法or属性：duration?: number;<br>旧版本信息：|类名：ShowToastOptions;<br>方法or属性：duration?: number;<br>新版本信息：?number|@ohos.prompt.d.ts|
|type有变化|类名：ShowToastOptions;<br>方法or属性：bottom?: string \| number;<br>旧版本信息：|类名：ShowToastOptions;<br>方法or属性：bottom?: string \| number;<br>新版本信息：?(string \| number)|@ohos.prompt.d.ts|
|type有变化|类名：ShowDialogOptions;<br>方法or属性：title?: string;<br>旧版本信息：string|类名：ShowDialogOptions;<br>方法or属性：title?: string;<br>新版本信息：?string|@ohos.prompt.d.ts|
|type有变化|类名：ActionMenuOptions;<br>方法or属性：title?: string;<br>旧版本信息：string|类名：ActionMenuOptions;<br>方法or属性：title?: string;<br>新版本信息：?string|@ohos.prompt.d.ts|
|type有变化|类名：ShowDialogOptions;<br>方法or属性：message?: string;<br>旧版本信息：string|类名：ShowDialogOptions;<br>方法or属性：message?: string;<br>新版本信息：?string|@ohos.prompt.d.ts|
|type有变化|类名：ShowDialogOptions;<br>方法or属性：buttons?: [Button, Button?, Button?];<br>旧版本信息：|类名：ShowDialogOptions;<br>方法or属性：buttons?: [Button, Button?, Button?];<br>新版本信息：?([Button, Button?, Button?])|@ohos.prompt.d.ts|
|type有变化|类名：ActionMenuSuccessResponse;<br>方法or属性：index: number;<br>旧版本信息：|类名：ActionMenuSuccessResponse;<br>方法or属性：index: number;<br>新版本信息：number|@ohos.prompt.d.ts|
|type有变化|类名：ActionMenuOptions;<br>方法or属性：buttons: [Button, Button?, Button?, Button?, Button?, Button?];<br>旧版本信息：|类名：ActionMenuOptions;<br>方法or属性：buttons: [Button, Button?, Button?, Button?, Button?, Button?];<br>新版本信息：[Button, Button?, Button?, Button?, Button?, Button?]|@ohos.prompt.d.ts|
|type有变化|类名：ShowToastOptions;<br>方法or属性：duration?: number;<br>旧版本信息：number|类名：ShowToastOptions;<br>方法or属性：duration?: number;<br>新版本信息：?number|@ohos.promptAction.d.ts|
|type有变化|类名：ShowToastOptions;<br>方法or属性：bottom?: string \| number;<br>旧版本信息：string \| number|类名：ShowToastOptions;<br>方法or属性：bottom?: string \| number;<br>新版本信息：?string \| number|@ohos.promptAction.d.ts|
|type有变化|类名：ShowDialogOptions;<br>方法or属性：title?: string \| Resource;<br>旧版本信息：string \| Resource|类名：ShowDialogOptions;<br>方法or属性：title?: string \| Resource;<br>新版本信息：?string \| Resource|@ohos.promptAction.d.ts|
|type有变化|类名：ActionMenuOptions;<br>方法or属性：title?: string \| Resource;<br>旧版本信息：string \| Resource|类名：ActionMenuOptions;<br>方法or属性：title?: string \| Resource;<br>新版本信息：?string \| Resource|@ohos.promptAction.d.ts|
|type有变化|类名：ShowDialogOptions;<br>方法or属性：message?: string \| Resource;<br>旧版本信息：string \| Resource|类名：ShowDialogOptions;<br>方法or属性：message?: string \| Resource;<br>新版本信息：?string \| Resource|@ohos.promptAction.d.ts|
|type有变化|类名：RouterOptions;<br>方法or属性：params?: Object;<br>旧版本信息：Object|类名：RouterOptions;<br>方法or属性：params?: Object;<br>新版本信息：?Object|@ohos.router.d.ts|
|type有变化|类名：AppResponse;<br>方法or属性：appID: string;<br>旧版本信息：|类名：AppResponse;<br>方法or属性：appID: string;<br>新版本信息：string|@system.app.d.ts|
|type有变化|类名：AppResponse;<br>方法or属性：appName: string;<br>旧版本信息：|类名：AppResponse;<br>方法or属性：appName: string;<br>新版本信息：string|@system.app.d.ts|
|type有变化|类名：AppResponse;<br>方法or属性：versionName: string;<br>旧版本信息：|类名：AppResponse;<br>方法or属性：versionName: string;<br>新版本信息：string|@system.app.d.ts|
|type有变化|类名：AppResponse;<br>方法or属性：versionCode: number;<br>旧版本信息：|类名：AppResponse;<br>方法or属性：versionCode: number;<br>新版本信息：string|@system.app.d.ts|
|type有变化|类名：ScreenOnVisibleOptions;<br>方法or属性：visible?: boolean;<br>旧版本信息：|类名：ScreenOnVisibleOptions;<br>方法or属性：visible?: boolean;<br>新版本信息：?string|@system.app.d.ts|
|type有变化|类名：ScreenOnVisibleOptions;<br>方法or属性：success?: () => void;<br>旧版本信息：|类名：ScreenOnVisibleOptions;<br>方法or属性：success?: () => void;<br>新版本信息：?(() => void)|@system.app.d.ts|
|type有变化|类名：ScreenOnVisibleOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>旧版本信息：|类名：ScreenOnVisibleOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>新版本信息：?((data: string, code: number) => void)|@system.app.d.ts|
|type有变化|类名：ScreenOnVisibleOptions;<br>方法or属性：complete?: () => void;<br>旧版本信息：|类名：ScreenOnVisibleOptions;<br>方法or属性：complete?: () => void;<br>新版本信息：?(() => void)|@system.app.d.ts|
|type有变化|类名：RequestFullWindowOptions;<br>方法or属性：duration: number;<br>旧版本信息：|类名：RequestFullWindowOptions;<br>方法or属性：duration: number;<br>新版本信息：number|@system.app.d.ts|
|type有变化|类名：LocaleResponse;<br>方法or属性：language: string;<br>旧版本信息：|类名：LocaleResponse;<br>方法or属性：language: string;<br>新版本信息：string|@system.configuration.d.ts|
|type有变化|类名：LocaleResponse;<br>方法or属性：countryOrRegion: string;<br>旧版本信息：|类名：LocaleResponse;<br>方法or属性：countryOrRegion: string;<br>新版本信息：string|@system.configuration.d.ts|
|type有变化|类名：LocaleResponse;<br>方法or属性：dir: "ltr" \| "rtl";<br>旧版本信息：|类名：LocaleResponse;<br>方法or属性：dir: "ltr" \| "rtl";<br>新版本信息：'ltr' \| 'rtl'|@system.configuration.d.ts|
|type有变化|类名：MediaQueryEvent;<br>方法or属性：matches: boolean;<br>旧版本信息：|类名：MediaQueryEvent;<br>方法or属性：matches: boolean;<br>新版本信息：boolean|@system.mediaquery.d.ts|
|type有变化|类名：MediaQueryList;<br>方法or属性：media?: string;<br>旧版本信息：|类名：MediaQueryList;<br>方法or属性：media?: string;<br>新版本信息：?string|@system.mediaquery.d.ts|
|type有变化|类名：MediaQueryList;<br>方法or属性：matches?: boolean;<br>旧版本信息：|类名：MediaQueryList;<br>方法or属性：matches?: boolean;<br>新版本信息：?boolean|@system.mediaquery.d.ts|
|type有变化|类名：MediaQueryList;<br>方法or属性：onchange?: (matches: boolean) => void;<br>旧版本信息：|类名：MediaQueryList;<br>方法or属性：onchange?: (matches: boolean) => void;<br>新版本信息：?((matches: boolean) => void)|@system.mediaquery.d.ts|
|type有变化|类名：ShowToastOptions;<br>方法or属性：message: string;<br>旧版本信息：|类名：ShowToastOptions;<br>方法or属性：message: string;<br>新版本信息：string|@system.prompt.d.ts|
|type有变化|类名：ShowToastOptions;<br>方法or属性：duration?: number;<br>旧版本信息：|类名：ShowToastOptions;<br>方法or属性：duration?: number;<br>新版本信息：number|@system.prompt.d.ts|
|type有变化|类名：ShowToastOptions;<br>方法or属性：bottom?: string \| number;<br>旧版本信息：|类名：ShowToastOptions;<br>方法or属性：bottom?: string \| number;<br>新版本信息：string \| number|@system.prompt.d.ts|
|type有变化|类名：Button;<br>方法or属性：text: string;<br>旧版本信息：|类名：Button;<br>方法or属性：text: string;<br>新版本信息：string|@system.prompt.d.ts|
|type有变化|类名：Button;<br>方法or属性：color: string;<br>旧版本信息：|类名：Button;<br>方法or属性：color: string;<br>新版本信息：string|@system.prompt.d.ts|
|type有变化|类名：ShowDialogSuccessResponse;<br>方法or属性：index: number;<br>旧版本信息：|类名：ShowDialogSuccessResponse;<br>方法or属性：index: number;<br>新版本信息：number|@system.prompt.d.ts|
|type有变化|类名：ShowDialogOptions;<br>方法or属性：title?: string;<br>旧版本信息：|类名：ShowDialogOptions;<br>方法or属性：title?: string;<br>新版本信息：?string|@system.prompt.d.ts|
|type有变化|类名：ShowActionMenuOptions;<br>方法or属性：title?: string;<br>旧版本信息：|类名：ShowActionMenuOptions;<br>方法or属性：title?: string;<br>新版本信息：?string|@system.prompt.d.ts|
|type有变化|类名：ShowDialogOptions;<br>方法or属性：message?: string;<br>旧版本信息：|类名：ShowDialogOptions;<br>方法or属性：message?: string;<br>新版本信息：?string|@system.prompt.d.ts|
|type有变化|类名：ShowDialogOptions;<br>方法or属性：buttons?: [Button, Button?, Button?];<br>旧版本信息：|类名：ShowDialogOptions;<br>方法or属性：buttons?: [Button, Button?, Button?];<br>新版本信息：[Button, Button?, Button?]|@system.prompt.d.ts|
|type有变化|类名：ShowActionMenuOptions;<br>方法or属性：buttons: [Button, Button?, Button?, Button?, Button?, Button?];<br>旧版本信息：|类名：ShowActionMenuOptions;<br>方法or属性：buttons: [Button, Button?, Button?, Button?, Button?, Button?];<br>新版本信息：[Button, Button?, Button?, Button?, Button?, Button?]|@system.prompt.d.ts|
|type有变化|类名：ShowActionMenuOptions;<br>方法or属性：success?: (tapIndex: number, errMsg: string) => void;<br>旧版本信息：|类名：ShowActionMenuOptions;<br>方法or属性：success?: (tapIndex: number, errMsg: string) => void;<br>新版本信息：?((tapIndex: number, errMsg: string) => void)|@system.prompt.d.ts|
|type有变化|类名：ShowActionMenuOptions;<br>方法or属性：fail?: (errMsg: string) => void;<br>旧版本信息：|类名：ShowActionMenuOptions;<br>方法or属性：fail?: (errMsg: string) => void;<br>新版本信息：?((errMsg: string) => void)|@system.prompt.d.ts|
|type有变化|类名：ShowActionMenuOptions;<br>方法or属性：complete?: () => void;<br>旧版本信息：|类名：ShowActionMenuOptions;<br>方法or属性：complete?: () => void;<br>新版本信息：?(() => void)|@system.prompt.d.ts|
|type有变化|类名：RouterOptions;<br>方法or属性：uri: string;<br>旧版本信息：|类名：RouterOptions;<br>方法or属性：uri: string;<br>新版本信息：string|@system.router.d.ts|
|type有变化|类名：RouterOptions;<br>方法or属性：params?: Object;<br>旧版本信息：|类名：RouterOptions;<br>方法or属性：params?: Object;<br>新版本信息：?Object|@system.router.d.ts|
|type有变化|类名：BackRouterOptions;<br>方法or属性：params?: Object;<br>旧版本信息：|类名：BackRouterOptions;<br>方法or属性：params?: Object;<br>新版本信息：?Object|@system.router.d.ts|
|type有变化|类名：BackRouterOptions;<br>方法or属性：uri?: string;<br>旧版本信息：|类名：BackRouterOptions;<br>方法or属性：uri?: string;<br>新版本信息：?string|@system.router.d.ts|
|type有变化|类名：RouterState;<br>方法or属性：index: number;<br>旧版本信息：|类名：RouterState;<br>方法or属性：index: number;<br>新版本信息：number|@system.router.d.ts|
|type有变化|类名：RouterState;<br>方法or属性：name: string;<br>旧版本信息：|类名：RouterState;<br>方法or属性：name: string;<br>新版本信息：string|@system.router.d.ts|
|type有变化|类名：RouterState;<br>方法or属性：path: string;<br>旧版本信息：|类名：RouterState;<br>方法or属性：path: string;<br>新版本信息：string|@system.router.d.ts|
|type有变化|类名：EnableAlertBeforeBackPageOptions;<br>方法or属性：message: string;<br>旧版本信息：|类名：EnableAlertBeforeBackPageOptions;<br>方法or属性：message: string;<br>新版本信息：string|@system.router.d.ts|
|type有变化|类名：EnableAlertBeforeBackPageOptions;<br>方法or属性：success?: (errMsg: string) => void;<br>旧版本信息：|类名：EnableAlertBeforeBackPageOptions;<br>方法or属性：success?: (errMsg: string) => void;<br>新版本信息：(errMsg: string) => void|@system.router.d.ts|
|type有变化|类名：DisableAlertBeforeBackPageOptions;<br>方法or属性：success?: (errMsg: string) => void;<br>旧版本信息：|类名：DisableAlertBeforeBackPageOptions;<br>方法or属性：success?: (errMsg: string) => void;<br>新版本信息：(errMsg: string) => void|@system.router.d.ts|
|type有变化|类名：EnableAlertBeforeBackPageOptions;<br>方法or属性：cancel?: (errMsg: string) => void;<br>旧版本信息：|类名：EnableAlertBeforeBackPageOptions;<br>方法or属性：cancel?: (errMsg: string) => void;<br>新版本信息：(errMsg: string) => void|@system.router.d.ts|
|type有变化|类名：DisableAlertBeforeBackPageOptions;<br>方法or属性：cancel?: (errMsg: string) => void;<br>旧版本信息：|类名：DisableAlertBeforeBackPageOptions;<br>方法or属性：cancel?: (errMsg: string) => void;<br>新版本信息：(errMsg: string) => void|@system.router.d.ts|
|type有变化|类名：EnableAlertBeforeBackPageOptions;<br>方法or属性：complete?: () => void;<br>旧版本信息：|类名：EnableAlertBeforeBackPageOptions;<br>方法or属性：complete?: () => void;<br>新版本信息：() => void|@system.router.d.ts|
|type有变化|类名：DisableAlertBeforeBackPageOptions;<br>方法or属性：complete?: () => void;<br>旧版本信息：|类名：DisableAlertBeforeBackPageOptions;<br>方法or属性：complete?: () => void;<br>新版本信息：() => void|@system.router.d.ts|
|type有变化|类名：sourcefile;<br>方法or属性：declare type CustomBuilder = (() => any) \| void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare type CustomBuilder = (() => any) \| void;<br>新版本信息：(() => any) \| void|common.d.ts|
|type有变化|类名：SheetInfo;<br>方法or属性：title: string \| Resource;<br>旧版本信息：|类名：SheetInfo;<br>方法or属性：title: string \| Resource;<br>新版本信息：string \| Resource|action_sheet.d.ts|
|type有变化|类名：SheetInfo;<br>方法or属性：icon?: string \| Resource;<br>旧版本信息：|类名：SheetInfo;<br>方法or属性：icon?: string \| Resource;<br>新版本信息：?(string \| Resource)|action_sheet.d.ts|
|type有变化|类名：SheetInfo;<br>方法or属性：action: () => void;<br>旧版本信息：|类名：SheetInfo;<br>方法or属性：action: () => void;<br>新版本信息：() => void|action_sheet.d.ts|
|type有变化|类名：AlertDialogParam;<br>方法or属性：title?: ResourceStr;<br>旧版本信息：|类名：AlertDialogParam;<br>方法or属性：title?: ResourceStr;<br>新版本信息：?ResourceStr|alert_dialog.d.ts|
|type有变化|类名：AlertDialogParam;<br>方法or属性：message: ResourceStr;<br>旧版本信息：|类名：AlertDialogParam;<br>方法or属性：message: ResourceStr;<br>新版本信息：ResourceStr|alert_dialog.d.ts|
|type有变化|类名：AlertDialogParam;<br>方法or属性：autoCancel?: boolean;<br>旧版本信息：|类名：AlertDialogParam;<br>方法or属性：autoCancel?: boolean;<br>新版本信息：?boolean|alert_dialog.d.ts|
|type有变化|类名：AlertDialogParam;<br>方法or属性：cancel?: () => void;<br>旧版本信息：|类名：AlertDialogParam;<br>方法or属性：cancel?: () => void;<br>新版本信息：?(() => void)|alert_dialog.d.ts|
|type有变化|类名：AlertDialogParam;<br>方法or属性：alignment?: DialogAlignment;<br>旧版本信息：|类名：AlertDialogParam;<br>方法or属性：alignment?: DialogAlignment;<br>新版本信息：?DialogAlignment|alert_dialog.d.ts|
|type有变化|类名：AlertDialogParam;<br>方法or属性：offset?: Offset;<br>旧版本信息：|类名：AlertDialogParam;<br>方法or属性：offset?: Offset;<br>新版本信息：?Offset|alert_dialog.d.ts|
|type有变化|类名：AlertDialogParam;<br>方法or属性：gridCount?: number;<br>旧版本信息：|类名：AlertDialogParam;<br>方法or属性：gridCount?: number;<br>新版本信息：?number|alert_dialog.d.ts|
|type有变化|类名：AlertDialogParamWithConfirm;<br>方法or属性：confirm?: {<br>    /**<br>     * Text content of the confirmation button.<br>     *<br>     * @type { ResourceStr }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @since 7<br>     */<br>    /**<br>     * Text content of the confirmation button.<br>     *<br>     * @type { ResourceStr }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @crossplatform<br>     * @since 10<br>     */<br>    value: ResourceStr;<br><br>    /**<br>     * Text color of the confirmation button.<br>     *<br>     * @type { ?ResourceColor }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @since 7<br>     */<br>    /**<br>     * Text color of the confirmation button.<br>     *<br>     * @type { ?ResourceColor }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @crossplatform<br>     * @since 10<br>     */<br>    fontColor?: ResourceColor;<br><br>    /**<br>     * Background color of the confirmation button.<br>     *<br>     * @type { ?ResourceColor }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @since 7<br>     */<br>    /**<br>     * Background color of the confirmation button.<br>     *<br>     * @type { ?ResourceColor }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @crossplatform<br>     * @since 10<br>     */<br>    backgroundColor?: ResourceColor;<br><br>    /**<br>     * Method executed by the callback.<br>     *<br>     * @type { () => void }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @since 7<br>     */<br>    /**<br>     * Method executed by the callback.<br>     *<br>     * @type { () => void }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @crossplatform<br>     * @since 10<br>     */<br>    action: () => void;<br>  };<br>旧版本信息：|类名：AlertDialogParamWithConfirm;<br>方法or属性：confirm?: {<br>    /**<br>     * Text content of the confirmation button.<br>     *<br>     * @type { ResourceStr }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @since 7<br>     */<br>    /**<br>     * Text content of the confirmation button.<br>     *<br>     * @type { ResourceStr }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @crossplatform<br>     * @since 10<br>     */<br>    value: ResourceStr;<br><br>    /**<br>     * Text color of the confirmation button.<br>     *<br>     * @type { ?ResourceColor }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @since 7<br>     */<br>    /**<br>     * Text color of the confirmation button.<br>     *<br>     * @type { ?ResourceColor }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @crossplatform<br>     * @since 10<br>     */<br>    fontColor?: ResourceColor;<br><br>    /**<br>     * Background color of the confirmation button.<br>     *<br>     * @type { ?ResourceColor }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @since 7<br>     */<br>    /**<br>     * Background color of the confirmation button.<br>     *<br>     * @type { ?ResourceColor }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @crossplatform<br>     * @since 10<br>     */<br>    backgroundColor?: ResourceColor;<br><br>    /**<br>     * Method executed by the callback.<br>     *<br>     * @type { () => void }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @since 7<br>     */<br>    /**<br>     * Method executed by the callback.<br>     *<br>     * @type { () => void }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @crossplatform<br>     * @since 10<br>     */<br>    action: () => void;<br>  };<br>新版本信息：?{value: ResourceStr; fontColor?: ResourceColor; backgroundColor?: ResourceColor;action: () => void;}|alert_dialog.d.ts|
|type有变化|类名：AlertDialogParamWithButtons;<br>方法or属性：primaryButton: {<br>    /**<br>     * Text content of the confirmation button.<br>     *<br>     * @type { ResourceStr }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @since 7<br>     */<br>    /**<br>     * Text content of the confirmation button.<br>     *<br>     * @type { ResourceStr }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @crossplatform<br>     * @since 10<br>     */<br>    value: ResourceStr;<br><br>    /**<br>     * Text color of the confirmation button.<br>     *<br>     * @type { ?ResourceColor }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @since 7<br>     */<br>    /**<br>     * Text color of the confirmation button.<br>     *<br>     * @type { ?ResourceColor }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @crossplatform<br>     * @since 10<br>     */<br>    fontColor?: ResourceColor;<br><br>    /**<br>     * Background color of the confirmation button.<br>     *<br>     * @type { ?ResourceColor }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @since 7<br>     */<br>    /**<br>     * Background color of the confirmation button.<br>     *<br>     * @type { ?ResourceColor }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @crossplatform<br>     * @since 10<br>     */<br>    backgroundColor?: ResourceColor;<br><br>    /**<br>     * Method executed by the callback.<br>     *<br>     * @type { () => void }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @since 7<br>     */<br>    /**<br>     * Method executed by the callback.<br>     *<br>     * @type { () => void }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @crossplatform<br>     * @since 10<br>     */<br>    action: () => void;<br>  };<br>旧版本信息：|类名：AlertDialogParamWithButtons;<br>方法or属性：primaryButton: {<br>    /**<br>     * Text content of the confirmation button.<br>     *<br>     * @type { ResourceStr }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @since 7<br>     */<br>    /**<br>     * Text content of the confirmation button.<br>     *<br>     * @type { ResourceStr }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @crossplatform<br>     * @since 10<br>     */<br>    value: ResourceStr;<br><br>    /**<br>     * Text color of the confirmation button.<br>     *<br>     * @type { ?ResourceColor }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @since 7<br>     */<br>    /**<br>     * Text color of the confirmation button.<br>     *<br>     * @type { ?ResourceColor }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @crossplatform<br>     * @since 10<br>     */<br>    fontColor?: ResourceColor;<br><br>    /**<br>     * Background color of the confirmation button.<br>     *<br>     * @type { ?ResourceColor }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @since 7<br>     */<br>    /**<br>     * Background color of the confirmation button.<br>     *<br>     * @type { ?ResourceColor }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @crossplatform<br>     * @since 10<br>     */<br>    backgroundColor?: ResourceColor;<br><br>    /**<br>     * Method executed by the callback.<br>     *<br>     * @type { () => void }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @since 7<br>     */<br>    /**<br>     * Method executed by the callback.<br>     *<br>     * @type { () => void }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @crossplatform<br>     * @since 10<br>     */<br>    action: () => void;<br>  };<br>新版本信息：{value: ResourceStr; fontColor?: ResourceColor; backgroundColor?: ResourceColor;action: () => void;}|alert_dialog.d.ts|
|type有变化|类名：AlertDialogParamWithButtons;<br>方法or属性：secondaryButton: {<br>    /**<br>     * Text content of the confirmation button.<br>     *<br>     * @type { ResourceStr }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @since 7<br>     */<br>    /**<br>     * Text content of the confirmation button.<br>     *<br>     * @type { ResourceStr }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @crossplatform<br>     * @since 10<br>     */<br>    value: ResourceStr;<br><br>    /**<br>     * Text color of the confirmation button.<br>     *<br>     * @type { ?ResourceColor }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @since 7<br>     */<br>    /**<br>     * Text color of the confirmation button.<br>     *<br>     * @type { ?ResourceColor }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @crossplatform<br>     * @since 10<br>     */<br>    fontColor?: ResourceColor;<br><br>    /**<br>     * Background color of the confirmation button.<br>     *<br>     * @type { ?ResourceColor }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @since 7<br>     */<br>    /**<br>     * Background color of the confirmation button.<br>     *<br>     * @type { ?ResourceColor }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @crossplatform<br>     * @since 10<br>     */<br>    backgroundColor?: ResourceColor;<br><br>    /**<br>     * Method executed by the callback.<br>     *<br>     * @type { () => void }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @since 7<br>     */<br>    /**<br>     * Method executed by the callback.<br>     *<br>     * @type { () => void }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @crossplatform<br>     * @since 10<br>     */<br>    action: () => void;<br>  };<br>旧版本信息：|类名：AlertDialogParamWithButtons;<br>方法or属性：secondaryButton: {<br>    /**<br>     * Text content of the confirmation button.<br>     *<br>     * @type { ResourceStr }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @since 7<br>     */<br>    /**<br>     * Text content of the confirmation button.<br>     *<br>     * @type { ResourceStr }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @crossplatform<br>     * @since 10<br>     */<br>    value: ResourceStr;<br><br>    /**<br>     * Text color of the confirmation button.<br>     *<br>     * @type { ?ResourceColor }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @since 7<br>     */<br>    /**<br>     * Text color of the confirmation button.<br>     *<br>     * @type { ?ResourceColor }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @crossplatform<br>     * @since 10<br>     */<br>    fontColor?: ResourceColor;<br><br>    /**<br>     * Background color of the confirmation button.<br>     *<br>     * @type { ?ResourceColor }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @since 7<br>     */<br>    /**<br>     * Background color of the confirmation button.<br>     *<br>     * @type { ?ResourceColor }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @crossplatform<br>     * @since 10<br>     */<br>    backgroundColor?: ResourceColor;<br><br>    /**<br>     * Method executed by the callback.<br>     *<br>     * @type { () => void }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @since 7<br>     */<br>    /**<br>     * Method executed by the callback.<br>     *<br>     * @type { () => void }<br>     * @syscap SystemCapability.ArkUI.ArkUI.Full<br>     * @crossplatform<br>     * @since 10<br>     */<br>    action: () => void;<br>  };<br>新版本信息：{value: ResourceStr; fontColor?: ResourceColor; backgroundColor?: ResourceColor;action: () => void;}|alert_dialog.d.ts|
|type有变化|类名：BadgeStyle;<br>方法or属性：color?: ResourceColor;<br>旧版本信息：|类名：BadgeStyle;<br>方法or属性：color?: ResourceColor;<br>新版本信息：?ResourceColor|badge.d.ts|
|type有变化|类名：BadgeStyle;<br>方法or属性：fontSize?: number \| string;<br>旧版本信息：|类名：BadgeStyle;<br>方法or属性：fontSize?: number \| string;<br>新版本信息：?(number \| string)|badge.d.ts|
|type有变化|类名：BadgeStyle;<br>方法or属性：badgeSize?: number \| string;<br>旧版本信息：|类名：BadgeStyle;<br>方法or属性：badgeSize?: number \| string;<br>新版本信息：?(number \| string)|badge.d.ts|
|type有变化|类名：BadgeStyle;<br>方法or属性：badgeColor?: ResourceColor;<br>旧版本信息：|类名：BadgeStyle;<br>方法or属性：badgeColor?: ResourceColor;<br>新版本信息：?ResourceColor|badge.d.ts|
|type有变化|类名：BadgeStyle;<br>方法or属性：borderColor?: ResourceColor;<br>旧版本信息：ResourceColor|类名：BadgeStyle;<br>方法or属性：borderColor?: ResourceColor;<br>新版本信息：?ResourceColor|badge.d.ts|
|type有变化|类名：BadgeStyle;<br>方法or属性：borderWidth?: Length;<br>旧版本信息：Length|类名：BadgeStyle;<br>方法or属性：borderWidth?: Length;<br>新版本信息：?Length|badge.d.ts|
|type有变化|类名：BadgeStyle;<br>方法or属性：fontWeight?: number \| FontWeight \| string;<br>旧版本信息：number \| FontWeight \| string|类名：BadgeStyle;<br>方法or属性：fontWeight?: number \| FontWeight \| string;<br>新版本信息：?(number \| FontWeight \| string)|badge.d.ts|
|type有变化|类名：BadgeParam;<br>方法or属性：position?: BadgePosition \| Position;<br>旧版本信息：|类名：BadgeParam;<br>方法or属性：position?: BadgePosition \| Position;<br>新版本信息：BadgePosition \| Position|badge.d.ts|
|type有变化|类名：BadgeParam;<br>方法or属性：style: BadgeStyle;<br>旧版本信息：|类名：BadgeParam;<br>方法or属性：style: BadgeStyle;<br>新版本信息：BadgeStyle|badge.d.ts|
|type有变化|类名：BadgeParamWithNumber;<br>方法or属性：count: number;<br>旧版本信息：|类名：BadgeParamWithNumber;<br>方法or属性：count: number;<br>新版本信息：number|badge.d.ts|
|type有变化|类名：BadgeParamWithNumber;<br>方法or属性：maxCount?: number;<br>旧版本信息：|类名：BadgeParamWithNumber;<br>方法or属性：maxCount?: number;<br>新版本信息：?number|badge.d.ts|
|type有变化|类名：BadgeParamWithString;<br>方法or属性：value: string;<br>旧版本信息：|类名：BadgeParamWithString;<br>方法or属性：value: string;<br>新版本信息：string|badge.d.ts|
|type有变化|类名：ButtonOptions;<br>方法or属性：type?: ButtonType;<br>旧版本信息：|类名：ButtonOptions;<br>方法or属性：type?: ButtonType;<br>新版本信息：?ButtonType|button.d.ts|
|type有变化|类名：ButtonOptions;<br>方法or属性：stateEffect?: boolean;<br>旧版本信息：|类名：ButtonOptions;<br>方法or属性：stateEffect?: boolean;<br>新版本信息：?boolean|button.d.ts|
|type有变化|类名：LabelStyle;<br>方法or属性：overflow?: TextOverflow;<br>旧版本信息：TextOverflow|类名：LabelStyle;<br>方法or属性：overflow?: TextOverflow;<br>新版本信息：?TextOverflow|button.d.ts|
|type有变化|类名：LabelStyle;<br>方法or属性：maxLines?: number;<br>旧版本信息：number|类名：LabelStyle;<br>方法or属性：maxLines?: number;<br>新版本信息：?number|button.d.ts|
|type有变化|类名：LabelStyle;<br>方法or属性：minFontSize?: number \| ResourceStr;<br>旧版本信息：number \| ResourceStr|类名：LabelStyle;<br>方法or属性：minFontSize?: number \| ResourceStr;<br>新版本信息：?(number \| ResourceStr)|button.d.ts|
|type有变化|类名：LabelStyle;<br>方法or属性：maxFontSize?: number \| ResourceStr;<br>旧版本信息：number \| ResourceStr|类名：LabelStyle;<br>方法or属性：maxFontSize?: number \| ResourceStr;<br>新版本信息：?(number \| ResourceStr)|button.d.ts|
|type有变化|类名：LabelStyle;<br>方法or属性：heightAdaptivePolicy?: TextHeightAdaptivePolicy;<br>旧版本信息：TextHeightAdaptivePolicy|类名：LabelStyle;<br>方法or属性：heightAdaptivePolicy?: TextHeightAdaptivePolicy;<br>新版本信息：?TextHeightAdaptivePolicy|button.d.ts|
|type有变化|类名：LabelStyle;<br>方法or属性：font?: Font;<br>旧版本信息：Font|类名：LabelStyle;<br>方法or属性：font?: Font;<br>新版本信息：?Font|button.d.ts|
|type有变化|类名：CalendarDay;<br>方法or属性：index: number;<br>旧版本信息：|类名：CalendarDay;<br>方法or属性：index: number;<br>新版本信息：number|calendar.d.ts|
|type有变化|类名：CalendarDay;<br>方法or属性：lunarMonth: string;<br>旧版本信息：|类名：CalendarDay;<br>方法or属性：lunarMonth: string;<br>新版本信息：string|calendar.d.ts|
|type有变化|类名：CalendarDay;<br>方法or属性：lunarDay: string;<br>旧版本信息：|类名：CalendarDay;<br>方法or属性：lunarDay: string;<br>新版本信息：string|calendar.d.ts|
|type有变化|类名：CalendarDay;<br>方法or属性：dayMark: string;<br>旧版本信息：|类名：CalendarDay;<br>方法or属性：dayMark: string;<br>新版本信息：string|calendar.d.ts|
|type有变化|类名：CalendarDay;<br>方法or属性：dayMarkValue: string;<br>旧版本信息：|类名：CalendarDay;<br>方法or属性：dayMarkValue: string;<br>新版本信息：string|calendar.d.ts|
|type有变化|类名：CalendarDay;<br>方法or属性：year: number;<br>旧版本信息：|类名：CalendarDay;<br>方法or属性：year: number;<br>新版本信息：number|calendar.d.ts|
|type有变化|类名：MonthData;<br>方法or属性：year: number;<br>旧版本信息：|类名：MonthData;<br>方法or属性：year: number;<br>新版本信息：number|calendar.d.ts|
|type有变化|类名：CalendarDay;<br>方法or属性：month: number;<br>旧版本信息：|类名：CalendarDay;<br>方法or属性：month: number;<br>新版本信息：number|calendar.d.ts|
|type有变化|类名：MonthData;<br>方法or属性：month: number;<br>旧版本信息：|类名：MonthData;<br>方法or属性：month: number;<br>新版本信息：number|calendar.d.ts|
|type有变化|类名：CalendarDay;<br>方法or属性：day: number;<br>旧版本信息：|类名：CalendarDay;<br>方法or属性：day: number;<br>新版本信息：number|calendar.d.ts|
|type有变化|类名：CalendarDay;<br>方法or属性：isFirstOfLunar: boolean;<br>旧版本信息：|类名：CalendarDay;<br>方法or属性：isFirstOfLunar: boolean;<br>新版本信息：boolean|calendar.d.ts|
|type有变化|类名：CalendarDay;<br>方法or属性：hasSchedule: boolean;<br>旧版本信息：|类名：CalendarDay;<br>方法or属性：hasSchedule: boolean;<br>新版本信息：boolean|calendar.d.ts|
|type有变化|类名：CalendarDay;<br>方法or属性：markLunarDay: boolean;<br>旧版本信息：|类名：CalendarDay;<br>方法or属性：markLunarDay: boolean;<br>新版本信息：boolean|calendar.d.ts|
|type有变化|类名：MonthData;<br>方法or属性：data: CalendarDay[];<br>旧版本信息：|类名：MonthData;<br>方法or属性：data: CalendarDay[];<br>新版本信息：CalendarDay[]|calendar.d.ts|
|type有变化|类名：CurrentDayStyle;<br>方法or属性：dayColor?: ResourceColor;<br>旧版本信息：|类名：CurrentDayStyle;<br>方法or属性：dayColor?: ResourceColor;<br>新版本信息：?ResourceColor|calendar.d.ts|
|type有变化|类名：CurrentDayStyle;<br>方法or属性：lunarColor?: ResourceColor;<br>旧版本信息：|类名：CurrentDayStyle;<br>方法or属性：lunarColor?: ResourceColor;<br>新版本信息：?ResourceColor|calendar.d.ts|
|type有变化|类名：CurrentDayStyle;<br>方法or属性：markLunarColor?: ResourceColor;<br>旧版本信息：|类名：CurrentDayStyle;<br>方法or属性：markLunarColor?: ResourceColor;<br>新版本信息：?ResourceColor|calendar.d.ts|
|type有变化|类名：CurrentDayStyle;<br>方法or属性：dayFontSize?: number;<br>旧版本信息：|类名：CurrentDayStyle;<br>方法or属性：dayFontSize?: number;<br>新版本信息：?number|calendar.d.ts|
|type有变化|类名：CurrentDayStyle;<br>方法or属性：lunarDayFontSize?: number;<br>旧版本信息：|类名：CurrentDayStyle;<br>方法or属性：lunarDayFontSize?: number;<br>新版本信息：?number|calendar.d.ts|
|type有变化|类名：CurrentDayStyle;<br>方法or属性：dayHeight?: number;<br>旧版本信息：|类名：CurrentDayStyle;<br>方法or属性：dayHeight?: number;<br>新版本信息：?number|calendar.d.ts|
|type有变化|类名：CurrentDayStyle;<br>方法or属性：dayWidth?: number;<br>旧版本信息：|类名：CurrentDayStyle;<br>方法or属性：dayWidth?: number;<br>新版本信息：?number|calendar.d.ts|
|type有变化|类名：CurrentDayStyle;<br>方法or属性：gregorianCalendarHeight?: number;<br>旧版本信息：|类名：CurrentDayStyle;<br>方法or属性：gregorianCalendarHeight?: number;<br>新版本信息：?number|calendar.d.ts|
|type有变化|类名：CurrentDayStyle;<br>方法or属性：dayYAxisOffset?: number;<br>旧版本信息：|类名：CurrentDayStyle;<br>方法or属性：dayYAxisOffset?: number;<br>新版本信息：?number|calendar.d.ts|
|type有变化|类名：CurrentDayStyle;<br>方法or属性：lunarDayYAxisOffset?: number;<br>旧版本信息：|类名：CurrentDayStyle;<br>方法or属性：lunarDayYAxisOffset?: number;<br>新版本信息：?number|calendar.d.ts|
|type有变化|类名：CurrentDayStyle;<br>方法or属性：underscoreXAxisOffset?: number;<br>旧版本信息：|类名：CurrentDayStyle;<br>方法or属性：underscoreXAxisOffset?: number;<br>新版本信息：?number|calendar.d.ts|
|type有变化|类名：CurrentDayStyle;<br>方法or属性：underscoreYAxisOffset?: number;<br>旧版本信息：|类名：CurrentDayStyle;<br>方法or属性：underscoreYAxisOffset?: number;<br>新版本信息：?number|calendar.d.ts|
|type有变化|类名：CurrentDayStyle;<br>方法or属性：scheduleMarkerXAxisOffset?: number;<br>旧版本信息：|类名：CurrentDayStyle;<br>方法or属性：scheduleMarkerXAxisOffset?: number;<br>新版本信息：?number|calendar.d.ts|
|type有变化|类名：CurrentDayStyle;<br>方法or属性：scheduleMarkerYAxisOffset?: number;<br>旧版本信息：|类名：CurrentDayStyle;<br>方法or属性：scheduleMarkerYAxisOffset?: number;<br>新版本信息：?number|calendar.d.ts|
|type有变化|类名：CurrentDayStyle;<br>方法or属性：colSpace?: number;<br>旧版本信息：|类名：CurrentDayStyle;<br>方法or属性：colSpace?: number;<br>新版本信息：?number|calendar.d.ts|
|type有变化|类名：CurrentDayStyle;<br>方法or属性：dailyFiveRowSpace?: number;<br>旧版本信息：|类名：CurrentDayStyle;<br>方法or属性：dailyFiveRowSpace?: number;<br>新版本信息：?number|calendar.d.ts|
|type有变化|类名：CurrentDayStyle;<br>方法or属性：dailySixRowSpace?: number;<br>旧版本信息：|类名：CurrentDayStyle;<br>方法or属性：dailySixRowSpace?: number;<br>新版本信息：?number|calendar.d.ts|
|type有变化|类名：CurrentDayStyle;<br>方法or属性：lunarHeight?: number;<br>旧版本信息：|类名：CurrentDayStyle;<br>方法or属性：lunarHeight?: number;<br>新版本信息：?number|calendar.d.ts|
|type有变化|类名：CurrentDayStyle;<br>方法or属性：underscoreWidth?: number;<br>旧版本信息：|类名：CurrentDayStyle;<br>方法or属性：underscoreWidth?: number;<br>新版本信息：?number|calendar.d.ts|
|type有变化|类名：CurrentDayStyle;<br>方法or属性：underscoreLength?: number;<br>旧版本信息：|类名：CurrentDayStyle;<br>方法or属性：underscoreLength?: number;<br>新版本信息：?number|calendar.d.ts|
|type有变化|类名：CurrentDayStyle;<br>方法or属性：scheduleMarkerRadius?: number;<br>旧版本信息：|类名：CurrentDayStyle;<br>方法or属性：scheduleMarkerRadius?: number;<br>新版本信息：?number|calendar.d.ts|
|type有变化|类名：CurrentDayStyle;<br>方法or属性：boundaryRowOffset?: number;<br>旧版本信息：|类名：CurrentDayStyle;<br>方法or属性：boundaryRowOffset?: number;<br>新版本信息：?number|calendar.d.ts|
|type有变化|类名：CurrentDayStyle;<br>方法or属性：boundaryColOffset?: number;<br>旧版本信息：|类名：CurrentDayStyle;<br>方法or属性：boundaryColOffset?: number;<br>新版本信息：?number|calendar.d.ts|
|type有变化|类名：NonCurrentDayStyle;<br>方法or属性：nonCurrentMonthDayColor?: ResourceColor;<br>旧版本信息：|类名：NonCurrentDayStyle;<br>方法or属性：nonCurrentMonthDayColor?: ResourceColor;<br>新版本信息：?ResourceColor|calendar.d.ts|
|type有变化|类名：NonCurrentDayStyle;<br>方法or属性：nonCurrentMonthLunarColor?: ResourceColor;<br>旧版本信息：|类名：NonCurrentDayStyle;<br>方法or属性：nonCurrentMonthLunarColor?: ResourceColor;<br>新版本信息：?ResourceColor|calendar.d.ts|
|type有变化|类名：NonCurrentDayStyle;<br>方法or属性：nonCurrentMonthWorkDayMarkColor?: ResourceColor;<br>旧版本信息：|类名：NonCurrentDayStyle;<br>方法or属性：nonCurrentMonthWorkDayMarkColor?: ResourceColor;<br>新版本信息：?ResourceColor|calendar.d.ts|
|type有变化|类名：NonCurrentDayStyle;<br>方法or属性：nonCurrentMonthOffDayMarkColor?: ResourceColor;<br>旧版本信息：|类名：NonCurrentDayStyle;<br>方法or属性：nonCurrentMonthOffDayMarkColor?: ResourceColor;<br>新版本信息：?ResourceColor|calendar.d.ts|
|type有变化|类名：TodayStyle;<br>方法or属性：focusedDayColor?: ResourceColor;<br>旧版本信息：|类名：TodayStyle;<br>方法or属性：focusedDayColor?: ResourceColor;<br>新版本信息：?ResourceColor|calendar.d.ts|
|type有变化|类名：TodayStyle;<br>方法or属性：focusedLunarColor?: ResourceColor;<br>旧版本信息：|类名：TodayStyle;<br>方法or属性：focusedLunarColor?: ResourceColor;<br>新版本信息：?ResourceColor|calendar.d.ts|
|type有变化|类名：TodayStyle;<br>方法or属性：focusedAreaBackgroundColor?: ResourceColor;<br>旧版本信息：|类名：TodayStyle;<br>方法or属性：focusedAreaBackgroundColor?: ResourceColor;<br>新版本信息：?ResourceColor|calendar.d.ts|
|type有变化|类名：TodayStyle;<br>方法or属性：focusedAreaRadius?: number;<br>旧版本信息：|类名：TodayStyle;<br>方法or属性：focusedAreaRadius?: number;<br>新版本信息：?number|calendar.d.ts|
|type有变化|类名：WeekStyle;<br>方法or属性：weekColor?: ResourceColor;<br>旧版本信息：|类名：WeekStyle;<br>方法or属性：weekColor?: ResourceColor;<br>新版本信息：?ResourceColor|calendar.d.ts|
|type有变化|类名：WeekStyle;<br>方法or属性：weekendDayColor?: ResourceColor;<br>旧版本信息：|类名：WeekStyle;<br>方法or属性：weekendDayColor?: ResourceColor;<br>新版本信息：?ResourceColor|calendar.d.ts|
|type有变化|类名：WeekStyle;<br>方法or属性：weekendLunarColor?: ResourceColor;<br>旧版本信息：|类名：WeekStyle;<br>方法or属性：weekendLunarColor?: ResourceColor;<br>新版本信息：?ResourceColor|calendar.d.ts|
|type有变化|类名：WeekStyle;<br>方法or属性：weekFontSize?: number;<br>旧版本信息：|类名：WeekStyle;<br>方法or属性：weekFontSize?: number;<br>新版本信息：?number|calendar.d.ts|
|type有变化|类名：WeekStyle;<br>方法or属性：weekHeight?: number;<br>旧版本信息：|类名：WeekStyle;<br>方法or属性：weekHeight?: number;<br>新版本信息：?number|calendar.d.ts|
|type有变化|类名：WeekStyle;<br>方法or属性：weekWidth?: number;<br>旧版本信息：|类名：WeekStyle;<br>方法or属性：weekWidth?: number;<br>新版本信息：?number|calendar.d.ts|
|type有变化|类名：WeekStyle;<br>方法or属性：weekAndDayRowSpace?: number;<br>旧版本信息：|类名：WeekStyle;<br>方法or属性：weekAndDayRowSpace?: number;<br>新版本信息：?number|calendar.d.ts|
|type有变化|类名：WorkStateStyle;<br>方法or属性：workDayMarkColor?: ResourceColor;<br>旧版本信息：|类名：WorkStateStyle;<br>方法or属性：workDayMarkColor?: ResourceColor;<br>新版本信息：?ResourceColor|calendar.d.ts|
|type有变化|类名：WorkStateStyle;<br>方法or属性：offDayMarkColor?: ResourceColor;<br>旧版本信息：|类名：WorkStateStyle;<br>方法or属性：offDayMarkColor?: ResourceColor;<br>新版本信息：?ResourceColor|calendar.d.ts|
|type有变化|类名：WorkStateStyle;<br>方法or属性：workDayMarkSize?: number;<br>旧版本信息：|类名：WorkStateStyle;<br>方法or属性：workDayMarkSize?: number;<br>新版本信息：?number|calendar.d.ts|
|type有变化|类名：WorkStateStyle;<br>方法or属性：offDayMarkSize?: number;<br>旧版本信息：|类名：WorkStateStyle;<br>方法or属性：offDayMarkSize?: number;<br>新版本信息：?number|calendar.d.ts|
|type有变化|类名：WorkStateStyle;<br>方法or属性：workStateWidth?: number;<br>旧版本信息：|类名：WorkStateStyle;<br>方法or属性：workStateWidth?: number;<br>新版本信息：?number|calendar.d.ts|
|type有变化|类名：WorkStateStyle;<br>方法or属性：workStateHorizontalMovingDistance?: number;<br>旧版本信息：|类名：WorkStateStyle;<br>方法or属性：workStateHorizontalMovingDistance?: number;<br>新版本信息：?number|calendar.d.ts|
|type有变化|类名：WorkStateStyle;<br>方法or属性：workStateVerticalMovingDistance?: number;<br>旧版本信息：|类名：WorkStateStyle;<br>方法or属性：workStateVerticalMovingDistance?: number;<br>新版本信息：?number|calendar.d.ts|
|type有变化|类名：TextMetrics;<br>方法or属性：readonly actualBoundingBoxAscent: number;<br>旧版本信息：|类名：TextMetrics;<br>方法or属性：readonly actualBoundingBoxAscent: number;<br>新版本信息：number|canvas.d.ts|
|type有变化|类名：TextMetrics;<br>方法or属性：readonly actualBoundingBoxDescent: number;<br>旧版本信息：|类名：TextMetrics;<br>方法or属性：readonly actualBoundingBoxDescent: number;<br>新版本信息：number|canvas.d.ts|
|type有变化|类名：TextMetrics;<br>方法or属性：readonly actualBoundingBoxLeft: number;<br>旧版本信息：|类名：TextMetrics;<br>方法or属性：readonly actualBoundingBoxLeft: number;<br>新版本信息：number|canvas.d.ts|
|type有变化|类名：TextMetrics;<br>方法or属性：readonly actualBoundingBoxRight: number;<br>旧版本信息：|类名：TextMetrics;<br>方法or属性：readonly actualBoundingBoxRight: number;<br>新版本信息：number|canvas.d.ts|
|type有变化|类名：TextMetrics;<br>方法or属性：readonly alphabeticBaseline: number;<br>旧版本信息：|类名：TextMetrics;<br>方法or属性：readonly alphabeticBaseline: number;<br>新版本信息：number|canvas.d.ts|
|type有变化|类名：TextMetrics;<br>方法or属性：readonly emHeightAscent: number;<br>旧版本信息：|类名：TextMetrics;<br>方法or属性：readonly emHeightAscent: number;<br>新版本信息：number|canvas.d.ts|
|type有变化|类名：TextMetrics;<br>方法or属性：readonly emHeightDescent: number;<br>旧版本信息：|类名：TextMetrics;<br>方法or属性：readonly emHeightDescent: number;<br>新版本信息：number|canvas.d.ts|
|type有变化|类名：TextMetrics;<br>方法or属性：readonly fontBoundingBoxAscent: number;<br>旧版本信息：|类名：TextMetrics;<br>方法or属性：readonly fontBoundingBoxAscent: number;<br>新版本信息：number|canvas.d.ts|
|type有变化|类名：TextMetrics;<br>方法or属性：readonly fontBoundingBoxDescent: number;<br>旧版本信息：|类名：TextMetrics;<br>方法or属性：readonly fontBoundingBoxDescent: number;<br>新版本信息：number|canvas.d.ts|
|type有变化|类名：TextMetrics;<br>方法or属性：readonly hangingBaseline: number;<br>旧版本信息：|类名：TextMetrics;<br>方法or属性：readonly hangingBaseline: number;<br>新版本信息：number|canvas.d.ts|
|type有变化|类名：TextMetrics;<br>方法or属性：readonly ideographicBaseline: number;<br>旧版本信息：|类名：TextMetrics;<br>方法or属性：readonly ideographicBaseline: number;<br>新版本信息：number|canvas.d.ts|
|type有变化|类名：TextMetrics;<br>方法or属性：readonly width: number;<br>旧版本信息：|类名：TextMetrics;<br>方法or属性：readonly width: number;<br>新版本信息：number|canvas.d.ts|
|type有变化|类名：ImageBitmap;<br>方法or属性：readonly width: number;<br>旧版本信息：|类名：ImageBitmap;<br>方法or属性：readonly width: number;<br>新版本信息：number|canvas.d.ts|
|type有变化|类名：ImageData;<br>方法or属性：readonly width: number;<br>旧版本信息：|类名：ImageData;<br>方法or属性：readonly width: number;<br>新版本信息：number|canvas.d.ts|
|type有变化|类名：CanvasRenderingContext2D;<br>方法or属性：readonly width: number;<br>旧版本信息：|类名：CanvasRenderingContext2D;<br>方法or属性：readonly width: number;<br>新版本信息：number|canvas.d.ts|
|type有变化|类名：TextMetrics;<br>方法or属性：readonly height: number;<br>旧版本信息：|类名：TextMetrics;<br>方法or属性：readonly height: number;<br>新版本信息：number|canvas.d.ts|
|type有变化|类名：ImageBitmap;<br>方法or属性：readonly height: number;<br>旧版本信息：|类名：ImageBitmap;<br>方法or属性：readonly height: number;<br>新版本信息：number|canvas.d.ts|
|type有变化|类名：ImageData;<br>方法or属性：readonly height: number;<br>旧版本信息：|类名：ImageData;<br>方法or属性：readonly height: number;<br>新版本信息：number|canvas.d.ts|
|type有变化|类名：CanvasRenderingContext2D;<br>方法or属性：readonly height: number;<br>旧版本信息：|类名：CanvasRenderingContext2D;<br>方法or属性：readonly height: number;<br>新版本信息：number|canvas.d.ts|
|type有变化|类名：ImageData;<br>方法or属性：readonly data: Uint8ClampedArray;<br>旧版本信息：|类名：ImageData;<br>方法or属性：readonly data: Uint8ClampedArray;<br>新版本信息：Uint8ClampedArray|canvas.d.ts|
|type有变化|类名：RenderingContextSettings;<br>方法or属性：antialias?: boolean;<br>旧版本信息：|类名：RenderingContextSettings;<br>方法or属性：antialias?: boolean;<br>新版本信息：?boolean|canvas.d.ts|
|type有变化|类名：CanvasRenderer;<br>方法or属性：globalAlpha: number;<br>旧版本信息：|类名：CanvasRenderer;<br>方法or属性：globalAlpha: number;<br>新版本信息：number|canvas.d.ts|
|type有变化|类名：CanvasRenderer;<br>方法or属性：globalCompositeOperation: string;<br>旧版本信息：|类名：CanvasRenderer;<br>方法or属性：globalCompositeOperation: string;<br>新版本信息：string|canvas.d.ts|
|type有变化|类名：CanvasRenderer;<br>方法or属性：filter: string;<br>旧版本信息：|类名：CanvasRenderer;<br>方法or属性：filter: string;<br>新版本信息：string|canvas.d.ts|
|type有变化|类名：CanvasRenderer;<br>方法or属性：imageSmoothingEnabled: boolean;<br>旧版本信息：|类名：CanvasRenderer;<br>方法or属性：imageSmoothingEnabled: boolean;<br>新版本信息：boolean|canvas.d.ts|
|type有变化|类名：CanvasRenderer;<br>方法or属性：imageSmoothingQuality: ImageSmoothingQuality;<br>旧版本信息：|类名：CanvasRenderer;<br>方法or属性：imageSmoothingQuality: ImageSmoothingQuality;<br>新版本信息：ImageSmoothingQuality|canvas.d.ts|
|type有变化|类名：CanvasRenderer;<br>方法or属性：lineCap: CanvasLineCap;<br>旧版本信息：|类名：CanvasRenderer;<br>方法or属性：lineCap: CanvasLineCap;<br>新版本信息：CanvasLineCap|canvas.d.ts|
|type有变化|类名：CanvasRenderer;<br>方法or属性：lineDashOffset: number;<br>旧版本信息：|类名：CanvasRenderer;<br>方法or属性：lineDashOffset: number;<br>新版本信息：number|canvas.d.ts|
|type有变化|类名：CanvasRenderer;<br>方法or属性：lineJoin: CanvasLineJoin;<br>旧版本信息：|类名：CanvasRenderer;<br>方法or属性：lineJoin: CanvasLineJoin;<br>新版本信息：CanvasLineJoin|canvas.d.ts|
|type有变化|类名：CanvasRenderer;<br>方法or属性：lineWidth: number;<br>旧版本信息：|类名：CanvasRenderer;<br>方法or属性：lineWidth: number;<br>新版本信息：number|canvas.d.ts|
|type有变化|类名：CanvasRenderer;<br>方法or属性：miterLimit: number;<br>旧版本信息：|类名：CanvasRenderer;<br>方法or属性：miterLimit: number;<br>新版本信息：number|canvas.d.ts|
|type有变化|类名：CanvasRenderer;<br>方法or属性：shadowBlur: number;<br>旧版本信息：|类名：CanvasRenderer;<br>方法or属性：shadowBlur: number;<br>新版本信息：number|canvas.d.ts|
|type有变化|类名：CanvasRenderer;<br>方法or属性：shadowColor: string;<br>旧版本信息：|类名：CanvasRenderer;<br>方法or属性：shadowColor: string;<br>新版本信息：string|canvas.d.ts|
|type有变化|类名：CanvasRenderer;<br>方法or属性：shadowOffsetX: number;<br>旧版本信息：|类名：CanvasRenderer;<br>方法or属性：shadowOffsetX: number;<br>新版本信息：number|canvas.d.ts|
|type有变化|类名：CanvasRenderer;<br>方法or属性：shadowOffsetY: number;<br>旧版本信息：|类名：CanvasRenderer;<br>方法or属性：shadowOffsetY: number;<br>新版本信息：number|canvas.d.ts|
|type有变化|类名：CanvasRenderer;<br>方法or属性：font: string;<br>旧版本信息：|类名：CanvasRenderer;<br>方法or属性：font: string;<br>新版本信息：string|canvas.d.ts|
|type有变化|类名：CanvasRenderer;<br>方法or属性：textAlign: CanvasTextAlign;<br>旧版本信息：|类名：CanvasRenderer;<br>方法or属性：textAlign: CanvasTextAlign;<br>新版本信息：CanvasTextAlign|canvas.d.ts|
|type有变化|类名：CanvasRenderer;<br>方法or属性：textBaseline: CanvasTextBaseline;<br>旧版本信息：|类名：CanvasRenderer;<br>方法or属性：textBaseline: CanvasTextBaseline;<br>新版本信息：CanvasTextBaseline|canvas.d.ts|
|type有变化|类名：OffscreenCanvas;<br>方法or属性：height: number;<br>旧版本信息：|类名：OffscreenCanvas;<br>方法or属性：height: number;<br>新版本信息：number|canvas.d.ts|
|type有变化|类名：OffscreenCanvas;<br>方法or属性：width: number;<br>旧版本信息：|类名：OffscreenCanvas;<br>方法or属性：width: number;<br>新版本信息：number|canvas.d.ts|
|type有变化|类名：CheckboxOptions;<br>方法or属性：name?: string;<br>旧版本信息：|类名：CheckboxOptions;<br>方法or属性：name?: string;<br>新版本信息：?string|checkbox.d.ts|
|type有变化|类名：CheckboxOptions;<br>方法or属性：group?: string;<br>旧版本信息：|类名：CheckboxOptions;<br>方法or属性：group?: string;<br>新版本信息：?string|checkbox.d.ts|
|type有变化|类名：CheckboxGroupOptions;<br>方法or属性：group?: string;<br>旧版本信息：|类名：CheckboxGroupOptions;<br>方法or属性：group?: string;<br>新版本信息：?string|checkboxgroup.d.ts|
|type有变化|类名：CheckboxGroupResult;<br>方法or属性：name: Array\<string>;<br>旧版本信息：|类名：CheckboxGroupResult;<br>方法or属性：name: Array\<string>;<br>新版本信息：Array\<string>|checkboxgroup.d.ts|
|type有变化|类名：CheckboxGroupResult;<br>方法or属性：status: SelectStatus;<br>旧版本信息：|类名：CheckboxGroupResult;<br>方法or属性：status: SelectStatus;<br>新版本信息：SelectStatus|checkboxgroup.d.ts|
|type有变化|类名：CircleOptions;<br>方法or属性：width?: string \| number;<br>旧版本信息：|类名：CircleOptions;<br>方法or属性：width?: string \| number;<br>新版本信息：?(string \| number)|circle.d.ts|
|type有变化|类名：CircleOptions;<br>方法or属性：height?: string \| number;<br>旧版本信息：|类名：CircleOptions;<br>方法or属性：height?: string \| number;<br>新版本信息：?(string \| number)|circle.d.ts|
|type有变化|类名：Configuration;<br>方法or属性：readonly colorMode: string;<br>旧版本信息：|类名：Configuration;<br>方法or属性：readonly colorMode: string;<br>新版本信息：string|common.d.ts|
|type有变化|类名：Configuration;<br>方法or属性：readonly fontScale: number;<br>旧版本信息：|类名：Configuration;<br>方法or属性：readonly fontScale: number;<br>新版本信息：number|common.d.ts|
|type有变化|类名：Rectangle;<br>方法or属性：x?: Length;<br>旧版本信息：|类名：Rectangle;<br>方法or属性：x?: Length;<br>新版本信息：?Length|common.d.ts|
|type有变化|类名：Rectangle;<br>方法or属性：y?: Length;<br>旧版本信息：|类名：Rectangle;<br>方法or属性：y?: Length;<br>新版本信息：?Length|common.d.ts|
|type有变化|类名：Rectangle;<br>方法or属性：width?: Length;<br>旧版本信息：|类名：Rectangle;<br>方法or属性：width?: Length;<br>新版本信息：?Length|common.d.ts|
|type有变化|类名：Rectangle;<br>方法or属性：height?: Length;<br>旧版本信息：|类名：Rectangle;<br>方法or属性：height?: Length;<br>新版本信息：?Length|common.d.ts|
|type有变化|类名：AnimateParam;<br>方法or属性：duration?: number;<br>旧版本信息：|类名：AnimateParam;<br>方法or属性：duration?: number;<br>新版本信息：?number|common.d.ts|
|type有变化|类名：sharedTransitionOptions;<br>方法or属性：duration?: number;<br>旧版本信息：|类名：sharedTransitionOptions;<br>方法or属性：duration?: number;<br>新版本信息：?number|common.d.ts|
|type有变化|类名：AnimateParam;<br>方法or属性：tempo?: number;<br>旧版本信息：|类名：AnimateParam;<br>方法or属性：tempo?: number;<br>新版本信息：?number|common.d.ts|
|type有变化|类名：AnimateParam;<br>方法or属性：curve?: Curve \| string \| ICurve;<br>旧版本信息：string \| Curve \| ICurve|类名：AnimateParam;<br>方法or属性：curve?: Curve \| string \| ICurve;<br>新版本信息：?(Curve \| string \| ICurve)|common.d.ts|
|type有变化|类名：sharedTransitionOptions;<br>方法or属性：curve?: Curve \| string \| ICurve;<br>旧版本信息：|类名：sharedTransitionOptions;<br>方法or属性：curve?: Curve \| string \| ICurve;<br>新版本信息：?(Curve \| string \| ICurve)|common.d.ts|
|type有变化|类名：AnimateParam;<br>方法or属性：delay?: number;<br>旧版本信息：|类名：AnimateParam;<br>方法or属性：delay?: number;<br>新版本信息：?number|common.d.ts|
|type有变化|类名：sharedTransitionOptions;<br>方法or属性：delay?: number;<br>旧版本信息：|类名：sharedTransitionOptions;<br>方法or属性：delay?: number;<br>新版本信息：?number|common.d.ts|
|type有变化|类名：AnimateParam;<br>方法or属性：iterations?: number;<br>旧版本信息：|类名：AnimateParam;<br>方法or属性：iterations?: number;<br>新版本信息：?number|common.d.ts|
|type有变化|类名：AnimateParam;<br>方法or属性：playMode?: PlayMode;<br>旧版本信息：|类名：AnimateParam;<br>方法or属性：playMode?: PlayMode;<br>新版本信息：?PlayMode|common.d.ts|
|type有变化|类名：AnimateParam;<br>方法or属性：onFinish?: () => void;<br>旧版本信息：|类名：AnimateParam;<br>方法or属性：onFinish?: () => void;<br>新版本信息：?(() => void)|common.d.ts|
|type有变化|类名：MotionPathOptions;<br>方法or属性：path: string;<br>旧版本信息：|类名：MotionPathOptions;<br>方法or属性：path: string;<br>新版本信息：string|common.d.ts|
|type有变化|类名：MotionPathOptions;<br>方法or属性：from?: number;<br>旧版本信息：|类名：MotionPathOptions;<br>方法or属性：from?: number;<br>新版本信息：?number|common.d.ts|
|type有变化|类名：MotionPathOptions;<br>方法or属性：to?: number;<br>旧版本信息：|类名：MotionPathOptions;<br>方法or属性：to?: number;<br>新版本信息：?number|common.d.ts|
|type有变化|类名：MotionPathOptions;<br>方法or属性：rotatable?: boolean;<br>旧版本信息：|类名：MotionPathOptions;<br>方法or属性：rotatable?: boolean;<br>新版本信息：?boolean|common.d.ts|
|type有变化|类名：sharedTransitionOptions;<br>方法or属性：motionPath?: MotionPathOptions;<br>旧版本信息：|类名：sharedTransitionOptions;<br>方法or属性：motionPath?: MotionPathOptions;<br>新版本信息：?MotionPathOptions|common.d.ts|
|type有变化|类名：sharedTransitionOptions;<br>方法or属性：zIndex?: number;<br>旧版本信息：|类名：sharedTransitionOptions;<br>方法or属性：zIndex?: number;<br>新版本信息：?number|common.d.ts|
|type有变化|类名：sharedTransitionOptions;<br>方法or属性：type?: SharedTransitionEffectType;<br>旧版本信息：|类名：sharedTransitionOptions;<br>方法or属性：type?: SharedTransitionEffectType;<br>新版本信息：?SharedTransitionEffectType|common.d.ts|
|type有变化|类名：TranslateOptions;<br>方法or属性：y?: number \| string;<br>旧版本信息：|类名：TranslateOptions;<br>方法or属性：y?: number \| string;<br>新版本信息：?(number \| string)|common.d.ts|
|type有变化|类名：TranslateOptions;<br>方法or属性：z?: number \| string;<br>旧版本信息：|类名：TranslateOptions;<br>方法or属性：z?: number \| string;<br>新版本信息：?(number \| string)|common.d.ts|
|type有变化|类名：ScaleOptions;<br>方法or属性：x?: number;<br>旧版本信息：|类名：ScaleOptions;<br>方法or属性：x?: number;<br>新版本信息：?number|common.d.ts|
|type有变化|类名：RotateOptions;<br>方法or属性：x?: number;<br>旧版本信息：|类名：RotateOptions;<br>方法or属性：x?: number;<br>新版本信息：?number|common.d.ts|
|type有变化|类名：ScaleOptions;<br>方法or属性：y?: number;<br>旧版本信息：|类名：ScaleOptions;<br>方法or属性：y?: number;<br>新版本信息：?number|common.d.ts|
|type有变化|类名：RotateOptions;<br>方法or属性：y?: number;<br>旧版本信息：|类名：RotateOptions;<br>方法or属性：y?: number;<br>新版本信息：?number|common.d.ts|
|type有变化|类名：ScaleOptions;<br>方法or属性：z?: number;<br>旧版本信息：|类名：ScaleOptions;<br>方法or属性：z?: number;<br>新版本信息：?number|common.d.ts|
|type有变化|类名：RotateOptions;<br>方法or属性：z?: number;<br>旧版本信息：|类名：RotateOptions;<br>方法or属性：z?: number;<br>新版本信息：?number|common.d.ts|
|type有变化|类名：ScaleOptions;<br>方法or属性：centerX?: number \| string;<br>旧版本信息：|类名：ScaleOptions;<br>方法or属性：centerX?: number \| string;<br>新版本信息：?(number \| string)|common.d.ts|
|type有变化|类名：RotateOptions;<br>方法or属性：centerX?: number \| string;<br>旧版本信息：|类名：RotateOptions;<br>方法or属性：centerX?: number \| string;<br>新版本信息：?(number \| string)|common.d.ts|
|type有变化|类名：ScaleOptions;<br>方法or属性：centerY?: number \| string;<br>旧版本信息：|类名：ScaleOptions;<br>方法or属性：centerY?: number \| string;<br>新版本信息：?(number \| string)|common.d.ts|
|type有变化|类名：AlignRuleOption;<br>方法or属性：left?: { anchor: string, align: HorizontalAlign };<br>旧版本信息：|类名：AlignRuleOption;<br>方法or属性：left?: { anchor: string, align: HorizontalAlign };<br>新版本信息：?{ anchor: string, align: HorizontalAlign }|common.d.ts|
|type有变化|类名：AlignRuleOption;<br>方法or属性：right?: { anchor: string, align: HorizontalAlign };<br>旧版本信息：|类名：AlignRuleOption;<br>方法or属性：right?: { anchor: string, align: HorizontalAlign };<br>新版本信息：?{ anchor: string, align: HorizontalAlign }|common.d.ts|
|type有变化|类名：AlignRuleOption;<br>方法or属性：middle?: { anchor: string, align: HorizontalAlign };<br>旧版本信息：|类名：AlignRuleOption;<br>方法or属性：middle?: { anchor: string, align: HorizontalAlign };<br>新版本信息：?{ anchor: string, align: HorizontalAlign }|common.d.ts|
|type有变化|类名：AlignRuleOption;<br>方法or属性：top?: { anchor: string, align: VerticalAlign };<br>旧版本信息：|类名：AlignRuleOption;<br>方法or属性：top?: { anchor: string, align: VerticalAlign };<br>新版本信息：?{ anchor: string, align: VerticalAlign }|common.d.ts|
|type有变化|类名：AlignRuleOption;<br>方法or属性：bottom?: { anchor: string, align: VerticalAlign };<br>旧版本信息：|类名：AlignRuleOption;<br>方法or属性：bottom?: { anchor: string, align: VerticalAlign };<br>新版本信息：?{ anchor: string, align: VerticalAlign }|common.d.ts|
|type有变化|类名：AlignRuleOption;<br>方法or属性：center?: { anchor: string, align: VerticalAlign };<br>旧版本信息：|类名：AlignRuleOption;<br>方法or属性：center?: { anchor: string, align: VerticalAlign };<br>新版本信息：?{ anchor: string, align: VerticalAlign }|common.d.ts|
|type有变化|类名：RotateOptions;<br>方法or属性：angle: number \| string;<br>旧版本信息：|类名：RotateOptions;<br>方法or属性：angle: number \| string;<br>新版本信息：number \| string|common.d.ts|
|type有变化|类名：TransitionOptions;<br>方法or属性：type?: TransitionType;<br>旧版本信息：|类名：TransitionOptions;<br>方法or属性：type?: TransitionType;<br>新版本信息：?TransitionType|common.d.ts|
|type有变化|类名：TransitionOptions;<br>方法or属性：opacity?: number;<br>旧版本信息：|类名：TransitionOptions;<br>方法or属性：opacity?: number;<br>新版本信息：?number|common.d.ts|
|type有变化|类名：TransitionOptions;<br>方法or属性：translate?: TranslateOptions;<br>旧版本信息：|类名：TransitionOptions;<br>方法or属性：translate?: TranslateOptions;<br>新版本信息：?TranslateOptions|common.d.ts|
|type有变化|类名：TransitionOptions;<br>方法or属性：scale?: ScaleOptions;<br>旧版本信息：|类名：TransitionOptions;<br>方法or属性：scale?: ScaleOptions;<br>新版本信息：?ScaleOptions|common.d.ts|
|type有变化|类名：TransitionOptions;<br>方法or属性：rotate?: RotateOptions;<br>旧版本信息：|类名：TransitionOptions;<br>方法or属性：rotate?: RotateOptions;<br>新版本信息：?RotateOptions|common.d.ts|
|type有变化|类名：PreviewParams;<br>方法or属性：title?: string;<br>旧版本信息：|类名：PreviewParams;<br>方法or属性：title?: string;<br>新版本信息：?string|common.d.ts|
|type有变化|类名：PreviewParams;<br>方法or属性：width?: number;<br>旧版本信息：|类名：PreviewParams;<br>方法or属性：width?: number;<br>新版本信息：?number|common.d.ts|
|type有变化|类名：PreviewParams;<br>方法or属性：height?: number;<br>旧版本信息：|类名：PreviewParams;<br>方法or属性：height?: number;<br>新版本信息：?number|common.d.ts|
|type有变化|类名：PreviewParams;<br>方法or属性：locale?: string;<br>旧版本信息：|类名：PreviewParams;<br>方法or属性：locale?: string;<br>新版本信息：?string|common.d.ts|
|type有变化|类名：PreviewParams;<br>方法or属性：colorMode?: string;<br>旧版本信息：|类名：PreviewParams;<br>方法or属性：colorMode?: string;<br>新版本信息：?string|common.d.ts|
|type有变化|类名：PreviewParams;<br>方法or属性：deviceType?: string;<br>旧版本信息：|类名：PreviewParams;<br>方法or属性：deviceType?: string;<br>新版本信息：?string|common.d.ts|
|type有变化|类名：PreviewParams;<br>方法or属性：dpi?: number;<br>旧版本信息：|类名：PreviewParams;<br>方法or属性：dpi?: number;<br>新版本信息：?number|common.d.ts|
|type有变化|类名：PreviewParams;<br>方法or属性：orientation?: string;<br>旧版本信息：|类名：PreviewParams;<br>方法or属性：orientation?: string;<br>新版本信息：?string|common.d.ts|
|type有变化|类名：PreviewParams;<br>方法or属性：roundScreen?: boolean;<br>旧版本信息：|类名：PreviewParams;<br>方法or属性：roundScreen?: boolean;<br>新版本信息：?boolean|common.d.ts|
|type有变化|类名：ItemDragInfo;<br>方法or属性：x: number;<br>旧版本信息：|类名：ItemDragInfo;<br>方法or属性：x: number;<br>新版本信息：number|common.d.ts|
|type有变化|类名：ClickEvent;<br>方法or属性：x: number;<br>旧版本信息：|类名：ClickEvent;<br>方法or属性：x: number;<br>新版本信息：number|common.d.ts|
|type有变化|类名：MouseEvent;<br>方法or属性：x: number;<br>旧版本信息：|类名：MouseEvent;<br>方法or属性：x: number;<br>新版本信息：number|common.d.ts|
|type有变化|类名：TouchObject;<br>方法or属性：x: number;<br>旧版本信息：|类名：TouchObject;<br>方法or属性：x: number;<br>新版本信息：number|common.d.ts|
|type有变化|类名：ItemDragInfo;<br>方法or属性：y: number;<br>旧版本信息：|类名：ItemDragInfo;<br>方法or属性：y: number;<br>新版本信息：number|common.d.ts|
|type有变化|类名：ClickEvent;<br>方法or属性：y: number;<br>旧版本信息：|类名：ClickEvent;<br>方法or属性：y: number;<br>新版本信息：number|common.d.ts|
|type有变化|类名：MouseEvent;<br>方法or属性：y: number;<br>旧版本信息：|类名：MouseEvent;<br>方法or属性：y: number;<br>新版本信息：number|common.d.ts|
|type有变化|类名：TouchObject;<br>方法or属性：y: number;<br>旧版本信息：|类名：TouchObject;<br>方法or属性：y: number;<br>新版本信息：number|common.d.ts|
|type有变化|类名：DragItemInfo;<br>方法or属性：pixelMap?: PixelMap;<br>旧版本信息：|类名：DragItemInfo;<br>方法or属性：pixelMap?: PixelMap;<br>新版本信息：?PixelMap|common.d.ts|
|type有变化|类名：DragItemInfo;<br>方法or属性：builder?: CustomBuilder;<br>旧版本信息：|类名：DragItemInfo;<br>方法or属性：builder?: CustomBuilder;<br>新版本信息：?CustomBuilder|common.d.ts|
|type有变化|类名：DragItemInfo;<br>方法or属性：extraInfo?: string;<br>旧版本信息：|类名：DragItemInfo;<br>方法or属性：extraInfo?: string;<br>新版本信息：?string|common.d.ts|
|type有变化|类名：EventTarget;<br>方法or属性：area: Area;<br>旧版本信息：|类名：EventTarget;<br>方法or属性：area: Area;<br>新版本信息：Area|common.d.ts|
|type有变化|类名：PickerTextStyle;<br>方法or属性：color?: ResourceColor;<br>旧版本信息：ResourceColor|类名：PickerTextStyle;<br>方法or属性：color?: ResourceColor;<br>新版本信息：?ResourceColor|common.d.ts|
|type有变化|类名：PickerTextStyle;<br>方法or属性：font?: Font;<br>旧版本信息：Font|类名：PickerTextStyle;<br>方法or属性：font?: Font;<br>新版本信息：?Font|common.d.ts|
|type有变化|类名：PopupMessageOptions;<br>方法or属性：font?: Font;<br>旧版本信息：Font|类名：PopupMessageOptions;<br>方法or属性：font?: Font;<br>新版本信息：?Font|common.d.ts|
|type有变化|类名：ShadowOptions;<br>方法or属性：radius: number \| Resource;<br>旧版本信息：|类名：ShadowOptions;<br>方法or属性：radius: number \| Resource;<br>新版本信息：number \| Resource|common.d.ts|
|type有变化|类名：ShadowOptions;<br>方法or属性：type?: ShadowType;<br>旧版本信息：ShadowType|类名：ShadowOptions;<br>方法or属性：type?: ShadowType;<br>新版本信息：?ShadowType|common.d.ts|
|type有变化|类名：ShadowOptions;<br>方法or属性：color?: Color \| string \| Resource;<br>旧版本信息：|类名：ShadowOptions;<br>方法or属性：color?: Color \| string \| Resource;<br>新版本信息：?(Color \| string \| Resource)|common.d.ts|
|type有变化|类名：ShadowOptions;<br>方法or属性：offsetX?: number \| Resource;<br>旧版本信息：|类名：ShadowOptions;<br>方法or属性：offsetX?: number \| Resource;<br>新版本信息：?(number \| Resource)|common.d.ts|
|type有变化|类名：ShadowOptions;<br>方法or属性：offsetY?: number \| Resource;<br>旧版本信息：|类名：ShadowOptions;<br>方法or属性：offsetY?: number \| Resource;<br>新版本信息：?(number \| Resource)|common.d.ts|
|type有变化|类名：BaseEvent;<br>方法or属性：target: EventTarget;<br>旧版本信息：|类名：BaseEvent;<br>方法or属性：target: EventTarget;<br>新版本信息：EventTarget|common.d.ts|
|type有变化|类名：BaseEvent;<br>方法or属性：timestamp: number;<br>旧版本信息：|类名：BaseEvent;<br>方法or属性：timestamp: number;<br>新版本信息：number|common.d.ts|
|type有变化|类名：KeyEvent;<br>方法or属性：timestamp: number;<br>旧版本信息：|类名：KeyEvent;<br>方法or属性：timestamp: number;<br>新版本信息：number|common.d.ts|
|type有变化|类名：BaseEvent;<br>方法or属性：source: SourceType;<br>旧版本信息：|类名：BaseEvent;<br>方法or属性：source: SourceType;<br>新版本信息：SourceType|common.d.ts|
|type有变化|类名：BaseEvent;<br>方法or属性：pressure: number;<br>旧版本信息：|类名：BaseEvent;<br>方法or属性：pressure: number;<br>新版本信息：number|common.d.ts|
|type有变化|类名：BaseEvent;<br>方法or属性：tiltX: number;<br>旧版本信息：|类名：BaseEvent;<br>方法or属性：tiltX: number;<br>新版本信息：number|common.d.ts|
|type有变化|类名：BaseEvent;<br>方法or属性：tiltY: number;<br>旧版本信息：|类名：BaseEvent;<br>方法or属性：tiltY: number;<br>新版本信息：number|common.d.ts|
|type有变化|类名：BaseEvent;<br>方法or属性：sourceTool: SourceTool;<br>旧版本信息：|类名：BaseEvent;<br>方法or属性：sourceTool: SourceTool;<br>新版本信息：SourceTool|common.d.ts|
|type有变化|类名：BorderImageOption;<br>方法or属性：slice?: Length \| EdgeWidths,<br>旧版本信息：|类名：BorderImageOption;<br>方法or属性：slice?: Length \| EdgeWidths,<br>新版本信息：?(Length \| EdgeWidths)|common.d.ts|
|type有变化|类名：BorderImageOption;<br>方法or属性：repeat?: RepeatMode,<br>旧版本信息：|类名：BorderImageOption;<br>方法or属性：repeat?: RepeatMode,<br>新版本信息：?RepeatMode|common.d.ts|
|type有变化|类名：BorderImageOption;<br>方法or属性：source?: string \| Resource \| LinearGradient,<br>旧版本信息：|类名：BorderImageOption;<br>方法or属性：source?: string \| Resource \| LinearGradient,<br>新版本信息：?(string \| Resource \| LinearGradient)|common.d.ts|
|type有变化|类名：BorderImageOption;<br>方法or属性：width?: Length \| EdgeWidths,<br>旧版本信息：|类名：BorderImageOption;<br>方法or属性：width?: Length \| EdgeWidths,<br>新版本信息：?(Length \| EdgeWidths)|common.d.ts|
|type有变化|类名：BorderImageOption;<br>方法or属性：outset?: Length \| EdgeWidths,<br>旧版本信息：|类名：BorderImageOption;<br>方法or属性：outset?: Length \| EdgeWidths,<br>新版本信息：?(Length \| EdgeWidths)|common.d.ts|
|type有变化|类名：BorderImageOption;<br>方法or属性：fill?: boolean<br>旧版本信息：|类名：BorderImageOption;<br>方法or属性：fill?: boolean<br>新版本信息：?boolean|common.d.ts|
|type有变化|类名：ClickEvent;<br>方法or属性：screenX: number;<br>旧版本信息：|类名：ClickEvent;<br>方法or属性：screenX: number;<br>新版本信息：number|common.d.ts|
|type有变化|类名：MouseEvent;<br>方法or属性：screenX: number;<br>旧版本信息：|类名：MouseEvent;<br>方法or属性：screenX: number;<br>新版本信息：number|common.d.ts|
|type有变化|类名：TouchObject;<br>方法or属性：screenX: number;<br>旧版本信息：|类名：TouchObject;<br>方法or属性：screenX: number;<br>新版本信息：number|common.d.ts|
|type有变化|类名：ClickEvent;<br>方法or属性：screenY: number;<br>旧版本信息：|类名：ClickEvent;<br>方法or属性：screenY: number;<br>新版本信息：number|common.d.ts|
|type有变化|类名：MouseEvent;<br>方法or属性：screenY: number;<br>旧版本信息：|类名：MouseEvent;<br>方法or属性：screenY: number;<br>新版本信息：number|common.d.ts|
|type有变化|类名：TouchObject;<br>方法or属性：screenY: number;<br>旧版本信息：|类名：TouchObject;<br>方法or属性：screenY: number;<br>新版本信息：number|common.d.ts|
|type有变化|类名：MouseEvent;<br>方法or属性：button: MouseButton;<br>旧版本信息：|类名：MouseEvent;<br>方法or属性：button: MouseButton;<br>新版本信息：MouseButton|common.d.ts|
|type有变化|类名：MouseEvent;<br>方法or属性：action: MouseAction;<br>旧版本信息：|类名：MouseEvent;<br>方法or属性：action: MouseAction;<br>新版本信息：MouseAction|common.d.ts|
|type有变化|类名：MouseEvent;<br>方法or属性：stopPropagation?: () => void;<br>旧版本信息：|类名：MouseEvent;<br>方法or属性：stopPropagation?: () => void;<br>新版本信息：?(() => void)|common.d.ts|
|type有变化|类名：KeyEvent;<br>方法or属性：stopPropagation?: () => void;<br>旧版本信息：|类名：KeyEvent;<br>方法or属性：stopPropagation?: () => void;<br>新版本信息：?(() => void)|common.d.ts|
|type有变化|类名：TouchObject;<br>方法or属性：type: TouchType;<br>旧版本信息：|类名：TouchObject;<br>方法or属性：type: TouchType;<br>新版本信息：TouchType|common.d.ts|
|type有变化|类名：TouchEvent;<br>方法or属性：type: TouchType;<br>旧版本信息：|类名：TouchEvent;<br>方法or属性：type: TouchType;<br>新版本信息：TouchType|common.d.ts|
|type有变化|类名：TouchObject;<br>方法or属性：id: number;<br>旧版本信息：|类名：TouchObject;<br>方法or属性：id: number;<br>新版本信息：number|common.d.ts|
|type有变化|类名：TouchEvent;<br>方法or属性：touches: TouchObject[];<br>旧版本信息：|类名：TouchEvent;<br>方法or属性：touches: TouchObject[];<br>新版本信息：TouchObject[]|common.d.ts|
|type有变化|类名：TouchEvent;<br>方法or属性：changedTouches: TouchObject[];<br>旧版本信息：|类名：TouchEvent;<br>方法or属性：changedTouches: TouchObject[];<br>新版本信息：TouchObject[]|common.d.ts|
|type有变化|类名：DragEvent;<br>方法or属性：getX(): number;<br>旧版本信息：|类名：DragEvent;<br>方法or属性：getX(): number;<br>新版本信息：number|common.d.ts|
|type有变化|类名：DragEvent;<br>方法or属性：getY(): number;<br>旧版本信息：|类名：DragEvent;<br>方法or属性：getY(): number;<br>新版本信息：number|common.d.ts|
|type有变化|类名：KeyEvent;<br>方法or属性：type: KeyType;<br>旧版本信息：|类名：KeyEvent;<br>方法or属性：type: KeyType;<br>新版本信息：KeyType|common.d.ts|
|type有变化|类名：KeyEvent;<br>方法or属性：keyCode: number;<br>旧版本信息：|类名：KeyEvent;<br>方法or属性：keyCode: number;<br>新版本信息：number|common.d.ts|
|type有变化|类名：KeyEvent;<br>方法or属性：keyText: string;<br>旧版本信息：|类名：KeyEvent;<br>方法or属性：keyText: string;<br>新版本信息：string|common.d.ts|
|type有变化|类名：KeyEvent;<br>方法or属性：keySource: KeySource;<br>旧版本信息：|类名：KeyEvent;<br>方法or属性：keySource: KeySource;<br>新版本信息：KeySource|common.d.ts|
|type有变化|类名：KeyEvent;<br>方法or属性：deviceId: number;<br>旧版本信息：|类名：KeyEvent;<br>方法or属性：deviceId: number;<br>新版本信息：number|common.d.ts|
|type有变化|类名：KeyEvent;<br>方法or属性：metaKey: number;<br>旧版本信息：|类名：KeyEvent;<br>方法or属性：metaKey: number;<br>新版本信息：number|common.d.ts|
|type有变化|类名：StateStyles;<br>方法or属性：normal?: any;<br>旧版本信息：|类名：StateStyles;<br>方法or属性：normal?: any;<br>新版本信息：?any|common.d.ts|
|type有变化|类名：StateStyles;<br>方法or属性：pressed?: any;<br>旧版本信息：|类名：StateStyles;<br>方法or属性：pressed?: any;<br>新版本信息：?any|common.d.ts|
|type有变化|类名：StateStyles;<br>方法or属性：disabled?: any;<br>旧版本信息：|类名：StateStyles;<br>方法or属性：disabled?: any;<br>新版本信息：?any|common.d.ts|
|type有变化|类名：StateStyles;<br>方法or属性：focused?: any;<br>旧版本信息：|类名：StateStyles;<br>方法or属性：focused?: any;<br>新版本信息：?any|common.d.ts|
|type有变化|类名：StateStyles;<br>方法or属性：clicked?: any;<br>旧版本信息：|类名：StateStyles;<br>方法or属性：clicked?: any;<br>新版本信息：?any|common.d.ts|
|type有变化|类名：PopupMessageOptions;<br>方法or属性：textColor?: ResourceColor;<br>旧版本信息：ResourceColor|类名：PopupMessageOptions;<br>方法or属性：textColor?: ResourceColor;<br>新版本信息：?ResourceColor|common.d.ts|
|type有变化|类名：PopupOptions;<br>方法or属性：message: string;<br>旧版本信息：|类名：PopupOptions;<br>方法or属性：message: string;<br>新版本信息：string|common.d.ts|
|type有变化|类名：PopupOptions;<br>方法or属性：placementOnTop?: boolean;<br>旧版本信息：|类名：PopupOptions;<br>方法or属性：placementOnTop?: boolean;<br>新版本信息：?boolean|common.d.ts|
|type有变化|类名：PopupOptions;<br>方法or属性：placement?: Placement;<br>旧版本信息：Placement|类名：PopupOptions;<br>方法or属性：placement?: Placement;<br>新版本信息：?Placement|common.d.ts|
|type有变化|类名：CustomPopupOptions;<br>方法or属性：placement?: Placement;<br>旧版本信息：|类名：CustomPopupOptions;<br>方法or属性：placement?: Placement;<br>新版本信息：?Placement|common.d.ts|
|type有变化|类名：PopupOptions;<br>方法or属性：arrowOffset?: Length;<br>旧版本信息：|类名：PopupOptions;<br>方法or属性：arrowOffset?: Length;<br>新版本信息：?Length|common.d.ts|
|type有变化|类名：CustomPopupOptions;<br>方法or属性：arrowOffset?: Length;<br>旧版本信息：|类名：CustomPopupOptions;<br>方法or属性：arrowOffset?: Length;<br>新版本信息：?Length|common.d.ts|
|type有变化|类名：PopupOptions;<br>方法or属性：showInSubWindow?: boolean;<br>旧版本信息：|类名：PopupOptions;<br>方法or属性：showInSubWindow?: boolean;<br>新版本信息：?boolean|common.d.ts|
|type有变化|类名：CustomPopupOptions;<br>方法or属性：showInSubWindow?: boolean;<br>旧版本信息：|类名：CustomPopupOptions;<br>方法or属性：showInSubWindow?: boolean;<br>新版本信息：?boolean|common.d.ts|
|type有变化|类名：PopupOptions;<br>方法or属性：mask?: boolean \| { color: ResourceColor };<br>旧版本信息：|类名：PopupOptions;<br>方法or属性：mask?: boolean \| { color: ResourceColor };<br>新版本信息：?(boolean \| { color: ResourceColor })|common.d.ts|
|type有变化|类名：CustomPopupOptions;<br>方法or属性：mask?: boolean \| { color: ResourceColor };<br>旧版本信息：|类名：CustomPopupOptions;<br>方法or属性：mask?: boolean \| { color: ResourceColor };<br>新版本信息：?(boolean \| { color: ResourceColor })|common.d.ts|
|type有变化|类名：PopupOptions;<br>方法or属性：messageOptions?: PopupMessageOptions<br>旧版本信息：PopupMessageOptions|类名：PopupOptions;<br>方法or属性：messageOptions?: PopupMessageOptions<br>新版本信息：?PopupMessageOptions|common.d.ts|
|type有变化|类名：PopupOptions;<br>方法or属性：targetSpace?: Length<br>旧版本信息：Length|类名：PopupOptions;<br>方法or属性：targetSpace?: Length<br>新版本信息：?Length|common.d.ts|
|type有变化|类名：CustomPopupOptions;<br>方法or属性：targetSpace?: Length<br>旧版本信息：Length|类名：CustomPopupOptions;<br>方法or属性：targetSpace?: Length<br>新版本信息：?Length|common.d.ts|
|type有变化|类名：CustomPopupOptions;<br>方法or属性：builder: CustomBuilder;<br>旧版本信息：|类名：CustomPopupOptions;<br>方法or属性：builder: CustomBuilder;<br>新版本信息：CustomBuilder|common.d.ts|
|type有变化|类名：CustomPopupOptions;<br>方法or属性：maskColor?: Color \| string \| Resource \| number;<br>旧版本信息：|类名：CustomPopupOptions;<br>方法or属性：maskColor?: Color \| string \| Resource \| number;<br>新版本信息：?(Color \| string \| Resource \| number)|common.d.ts|
|type有变化|类名：CustomPopupOptions;<br>方法or属性：popupColor?: Color \| string \| Resource \| number;<br>旧版本信息：|类名：CustomPopupOptions;<br>方法or属性：popupColor?: Color \| string \| Resource \| number;<br>新版本信息：?(Color \| string \| Resource \| number)|common.d.ts|
|type有变化|类名：CustomPopupOptions;<br>方法or属性：enableArrow?: boolean;<br>旧版本信息：|类名：CustomPopupOptions;<br>方法or属性：enableArrow?: boolean;<br>新版本信息：?boolean|common.d.ts|
|type有变化|类名：CustomPopupOptions;<br>方法or属性：autoCancel?: boolean;<br>旧版本信息：|类名：CustomPopupOptions;<br>方法or属性：autoCancel?: boolean;<br>新版本信息：?boolean|common.d.ts|
|type有变化|类名：ContextMenuOptions;<br>方法or属性：onAppear?: () => void;<br>旧版本信息：?() => void|类名：ContextMenuOptions;<br>方法or属性：onAppear?: () => void;<br>新版本信息：?(() => void)|common.d.ts|
|type有变化|类名：ContextMenuOptions;<br>方法or属性：onDisappear?: () => void;<br>旧版本信息：?() => void|类名：ContextMenuOptions;<br>方法or属性：onDisappear?: () => void;<br>新版本信息：?(() => void)|common.d.ts|
|type有变化|类名：PixelStretchEffectOptions;<br>方法or属性：top?: Length;<br>旧版本信息：Length|类名：PixelStretchEffectOptions;<br>方法or属性：top?: Length;<br>新版本信息：?Length|common.d.ts|
|type有变化|类名：PixelStretchEffectOptions;<br>方法or属性：bottom?: Length;<br>旧版本信息：Length|类名：PixelStretchEffectOptions;<br>方法or属性：bottom?: Length;<br>新版本信息：?Length|common.d.ts|
|type有变化|类名：PixelStretchEffectOptions;<br>方法or属性：left?: Length;<br>旧版本信息：Length|类名：PixelStretchEffectOptions;<br>方法or属性：left?: Length;<br>新版本信息：?Length|common.d.ts|
|type有变化|类名：LayoutBorderInfo;<br>方法or属性：borderWidth: EdgeWidths;<br>旧版本信息：|类名：LayoutBorderInfo;<br>方法or属性：borderWidth: EdgeWidths;<br>新版本信息：EdgeWidths|common.d.ts|
|type有变化|类名：LayoutBorderInfo;<br>方法or属性：margin: Margin,<br>旧版本信息：|类名：LayoutBorderInfo;<br>方法or属性：margin: Margin,<br>新版本信息：Margin|common.d.ts|
|type有变化|类名：LayoutBorderInfo;<br>方法or属性：padding: Padding,<br>旧版本信息：|类名：LayoutBorderInfo;<br>方法or属性：padding: Padding,<br>新版本信息：Padding|common.d.ts|
|type有变化|类名：LayoutInfo;<br>方法or属性：position: Position,<br>旧版本信息：|类名：LayoutInfo;<br>方法or属性：position: Position,<br>新版本信息：Position|common.d.ts|
|type有变化|类名：LayoutChild;<br>方法or属性：position: Position,<br>旧版本信息：|类名：LayoutChild;<br>方法or属性：position: Position,<br>新版本信息：Position|common.d.ts|
|type有变化|类名：LayoutInfo;<br>方法or属性：constraint: ConstraintSizeOptions,<br>旧版本信息：|类名：LayoutInfo;<br>方法or属性：constraint: ConstraintSizeOptions,<br>新版本信息：ConstraintSizeOptions|common.d.ts|
|type有变化|类名：LayoutChild;<br>方法or属性：constraint: ConstraintSizeOptions,<br>旧版本信息：|类名：LayoutChild;<br>方法or属性：constraint: ConstraintSizeOptions,<br>新版本信息：ConstraintSizeOptions|common.d.ts|
|type有变化|类名：LayoutChild;<br>方法or属性：name: string,<br>旧版本信息：|类名：LayoutChild;<br>方法or属性：name: string,<br>新版本信息：string|common.d.ts|
|type有变化|类名：LayoutChild;<br>方法or属性：id: string,<br>旧版本信息：|类名：LayoutChild;<br>方法or属性：id: string,<br>新版本信息：string|common.d.ts|
|type有变化|类名：LayoutChild;<br>方法or属性：borderInfo: LayoutBorderInfo,<br>旧版本信息：|类名：LayoutChild;<br>方法or属性：borderInfo: LayoutBorderInfo,<br>新版本信息：LayoutBorderInfo|common.d.ts|
|type有变化|类名：SubscribedAbstractProperty;<br>方法or属性：protected subscribers_: Set\<number>;<br>旧版本信息：|类名：SubscribedAbstractProperty;<br>方法or属性：protected subscribers_: Set\<number>;<br>新版本信息：Set\<number>|common_ts_ets_api.d.ts|
|type有变化|类名：CustomDialogControllerOptions;<br>方法or属性：builder: any;<br>旧版本信息：|类名：CustomDialogControllerOptions;<br>方法or属性：builder: any;<br>新版本信息：any|custom_dialog_controller.d.ts|
|type有变化|类名：CustomDialogControllerOptions;<br>方法or属性：cancel?: () => void;<br>旧版本信息：|类名：CustomDialogControllerOptions;<br>方法or属性：cancel?: () => void;<br>新版本信息：?(() => void)|custom_dialog_controller.d.ts|
|type有变化|类名：CustomDialogControllerOptions;<br>方法or属性：autoCancel?: boolean;<br>旧版本信息：|类名：CustomDialogControllerOptions;<br>方法or属性：autoCancel?: boolean;<br>新版本信息：?boolean|custom_dialog_controller.d.ts|
|type有变化|类名：CustomDialogControllerOptions;<br>方法or属性：alignment?: DialogAlignment;<br>旧版本信息：|类名：CustomDialogControllerOptions;<br>方法or属性：alignment?: DialogAlignment;<br>新版本信息：?DialogAlignment|custom_dialog_controller.d.ts|
|type有变化|类名：CustomDialogControllerOptions;<br>方法or属性：offset?: Offset;<br>旧版本信息：|类名：CustomDialogControllerOptions;<br>方法or属性：offset?: Offset;<br>新版本信息：?Offset|custom_dialog_controller.d.ts|
|type有变化|类名：CustomDialogControllerOptions;<br>方法or属性：customStyle?: boolean;<br>旧版本信息：|类名：CustomDialogControllerOptions;<br>方法or属性：customStyle?: boolean;<br>新版本信息：?boolean|custom_dialog_controller.d.ts|
|type有变化|类名：CustomDialogControllerOptions;<br>方法or属性：gridCount?: number;<br>旧版本信息：|类名：CustomDialogControllerOptions;<br>方法or属性：gridCount?: number;<br>新版本信息：?number|custom_dialog_controller.d.ts|
|type有变化|类名：CustomDialogControllerOptions;<br>方法or属性：maskColor?: ResourceColor;<br>旧版本信息：|类名：CustomDialogControllerOptions;<br>方法or属性：maskColor?: ResourceColor;<br>新版本信息：?ResourceColor|custom_dialog_controller.d.ts|
|type有变化|类名：CustomDialogControllerOptions;<br>方法or属性：openAnimation?: AnimateParam;<br>旧版本信息：|类名：CustomDialogControllerOptions;<br>方法or属性：openAnimation?: AnimateParam;<br>新版本信息：?AnimateParam|custom_dialog_controller.d.ts|
|type有变化|类名：CustomDialogControllerOptions;<br>方法or属性：closeAnimation?: AnimateParam;<br>旧版本信息：|类名：CustomDialogControllerOptions;<br>方法or属性：closeAnimation?: AnimateParam;<br>新版本信息：?AnimateParam|custom_dialog_controller.d.ts|
|type有变化|类名：CustomDialogControllerOptions;<br>方法or属性：showInSubWindow?: boolean;<br>旧版本信息：boolean|类名：CustomDialogControllerOptions;<br>方法or属性：showInSubWindow?: boolean;<br>新版本信息：?boolean|custom_dialog_controller.d.ts|
|type有变化|类名：DataPanelOptions;<br>方法or属性：values: number[];<br>旧版本信息：|类名：DataPanelOptions;<br>方法or属性：values: number[];<br>新版本信息：number[]|data_panel.d.ts|
|type有变化|类名：DataPanelOptions;<br>方法or属性：max?: number;<br>旧版本信息：|类名：DataPanelOptions;<br>方法or属性：max?: number;<br>新版本信息：?number|data_panel.d.ts|
|type有变化|类名：DataPanelOptions;<br>方法or属性：type?: DataPanelType;<br>旧版本信息：|类名：DataPanelOptions;<br>方法or属性：type?: DataPanelType;<br>新版本信息：?DataPanelType|data_panel.d.ts|
|type有变化|类名：DatePickerResult;<br>方法or属性：year?: number;<br>旧版本信息：|类名：DatePickerResult;<br>方法or属性：year?: number;<br>新版本信息：?number|date_picker.d.ts|
|type有变化|类名：DatePickerResult;<br>方法or属性：month?: number;<br>旧版本信息：|类名：DatePickerResult;<br>方法or属性：month?: number;<br>新版本信息：?number|date_picker.d.ts|
|type有变化|类名：DatePickerResult;<br>方法or属性：day?: number;<br>旧版本信息：|类名：DatePickerResult;<br>方法or属性：day?: number;<br>新版本信息：?number|date_picker.d.ts|
|type有变化|类名：DatePickerOptions;<br>方法or属性：start?: Date;<br>旧版本信息：|类名：DatePickerOptions;<br>方法or属性：start?: Date;<br>新版本信息：?Date|date_picker.d.ts|
|type有变化|类名：DatePickerOptions;<br>方法or属性：end?: Date;<br>旧版本信息：|类名：DatePickerOptions;<br>方法or属性：end?: Date;<br>新版本信息：?Date|date_picker.d.ts|
|type有变化|类名：DatePickerOptions;<br>方法or属性：selected?: Date;<br>旧版本信息：|类名：DatePickerOptions;<br>方法or属性：selected?: Date;<br>新版本信息：?Date|date_picker.d.ts|
|type有变化|类名：DatePickerDialogOptions;<br>方法or属性：lunar?: boolean;<br>旧版本信息：|类名：DatePickerDialogOptions;<br>方法or属性：lunar?: boolean;<br>新版本信息：?boolean|date_picker.d.ts|
|type有变化|类名：DatePickerDialogOptions;<br>方法or属性：showTime?: boolean;<br>旧版本信息：boolean|类名：DatePickerDialogOptions;<br>方法or属性：showTime?: boolean;<br>新版本信息：?boolean|date_picker.d.ts|
|type有变化|类名：DatePickerDialogOptions;<br>方法or属性：useMilitaryTime?: boolean;<br>旧版本信息：boolean|类名：DatePickerDialogOptions;<br>方法or属性：useMilitaryTime?: boolean;<br>新版本信息：?boolean|date_picker.d.ts|
|type有变化|类名：DatePickerDialogOptions;<br>方法or属性：disappearTextStyle?: PickerTextStyle;<br>旧版本信息：PickerTextStyle|类名：DatePickerDialogOptions;<br>方法or属性：disappearTextStyle?: PickerTextStyle;<br>新版本信息：?PickerTextStyle|date_picker.d.ts|
|type有变化|类名：DatePickerDialogOptions;<br>方法or属性：textStyle?: PickerTextStyle;<br>旧版本信息：PickerTextStyle|类名：DatePickerDialogOptions;<br>方法or属性：textStyle?: PickerTextStyle;<br>新版本信息：?PickerTextStyle|date_picker.d.ts|
|type有变化|类名：DatePickerDialogOptions;<br>方法or属性：selectedTextStyle?: PickerTextStyle;<br>旧版本信息：PickerTextStyle|类名：DatePickerDialogOptions;<br>方法or属性：selectedTextStyle?: PickerTextStyle;<br>新版本信息：?PickerTextStyle|date_picker.d.ts|
|type有变化|类名：DatePickerDialogOptions;<br>方法or属性：onAccept?: (value: DatePickerResult) => void;<br>旧版本信息：|类名：DatePickerDialogOptions;<br>方法or属性：onAccept?: (value: DatePickerResult) => void;<br>新版本信息：?((value: DatePickerResult) => void)|date_picker.d.ts|
|type有变化|类名：DatePickerDialogOptions;<br>方法or属性：onCancel?: () => void;<br>旧版本信息：|类名：DatePickerDialogOptions;<br>方法or属性：onCancel?: () => void;<br>新版本信息：?(() => void)|date_picker.d.ts|
|type有变化|类名：DatePickerDialogOptions;<br>方法or属性：onChange?: (value: DatePickerResult) => void;<br>旧版本信息：|类名：DatePickerDialogOptions;<br>方法or属性：onChange?: (value: DatePickerResult) => void;<br>新版本信息：?((value: DatePickerResult) => void)|date_picker.d.ts|
|type有变化|类名：FlexOptions;<br>方法or属性：direction?: FlexDirection;<br>旧版本信息：|类名：FlexOptions;<br>方法or属性：direction?: FlexDirection;<br>新版本信息：?FlexDirection|flex.d.ts|
|type有变化|类名：FlexOptions;<br>方法or属性：wrap?: FlexWrap;<br>旧版本信息：|类名：FlexOptions;<br>方法or属性：wrap?: FlexWrap;<br>新版本信息：?FlexWrap|flex.d.ts|
|type有变化|类名：FlexOptions;<br>方法or属性：justifyContent?: FlexAlign;<br>旧版本信息：|类名：FlexOptions;<br>方法or属性：justifyContent?: FlexAlign;<br>新版本信息：?FlexAlign|flex.d.ts|
|type有变化|类名：FlexOptions;<br>方法or属性：alignItems?: ItemAlign;<br>旧版本信息：|类名：FlexOptions;<br>方法or属性：alignItems?: ItemAlign;<br>新版本信息：?ItemAlign|flex.d.ts|
|type有变化|类名：FlexOptions;<br>方法or属性：alignContent?: FlexAlign;<br>旧版本信息：|类名：FlexOptions;<br>方法or属性：alignContent?: FlexAlign;<br>新版本信息：?FlexAlign|flex.d.ts|
|type有变化|类名：FingerInfo;<br>方法or属性：id: number;<br>旧版本信息：|类名：FingerInfo;<br>方法or属性：id: number;<br>新版本信息：number|gesture.d.ts|
|type有变化|类名：FingerInfo;<br>方法or属性：globalX: number;<br>旧版本信息：|类名：FingerInfo;<br>方法or属性：globalX: number;<br>新版本信息：number|gesture.d.ts|
|type有变化|类名：FingerInfo;<br>方法or属性：globalY: number;<br>旧版本信息：|类名：FingerInfo;<br>方法or属性：globalY: number;<br>新版本信息：number|gesture.d.ts|
|type有变化|类名：FingerInfo;<br>方法or属性：localX: number;<br>旧版本信息：|类名：FingerInfo;<br>方法or属性：localX: number;<br>新版本信息：number|gesture.d.ts|
|type有变化|类名：FingerInfo;<br>方法or属性：localY: number;<br>旧版本信息：|类名：FingerInfo;<br>方法or属性：localY: number;<br>新版本信息：number|gesture.d.ts|
|type有变化|类名：GestureEvent;<br>方法or属性：repeat: boolean;<br>旧版本信息：|类名：GestureEvent;<br>方法or属性：repeat: boolean;<br>新版本信息：boolean|gesture.d.ts|
|type有变化|类名：GestureEvent;<br>方法or属性：fingerList: FingerInfo[];<br>旧版本信息：|类名：GestureEvent;<br>方法or属性：fingerList: FingerInfo[];<br>新版本信息：FingerInfo[]|gesture.d.ts|
|type有变化|类名：GestureEvent;<br>方法or属性：offsetX: number;<br>旧版本信息：|类名：GestureEvent;<br>方法or属性：offsetX: number;<br>新版本信息：number|gesture.d.ts|
|type有变化|类名：GestureEvent;<br>方法or属性：offsetY: number;<br>旧版本信息：|类名：GestureEvent;<br>方法or属性：offsetY: number;<br>新版本信息：number|gesture.d.ts|
|type有变化|类名：GestureEvent;<br>方法or属性：angle: number;<br>旧版本信息：|类名：GestureEvent;<br>方法or属性：angle: number;<br>新版本信息：number|gesture.d.ts|
|type有变化|类名：GestureEvent;<br>方法or属性：speed: number;<br>旧版本信息：|类名：GestureEvent;<br>方法or属性：speed: number;<br>新版本信息：number|gesture.d.ts|
|type有变化|类名：GestureEvent;<br>方法or属性：scale: number;<br>旧版本信息：|类名：GestureEvent;<br>方法or属性：scale: number;<br>新版本信息：number|gesture.d.ts|
|type有变化|类名：GestureEvent;<br>方法or属性：pinchCenterX: number;<br>旧版本信息：|类名：GestureEvent;<br>方法or属性：pinchCenterX: number;<br>新版本信息：number|gesture.d.ts|
|type有变化|类名：GestureEvent;<br>方法or属性：pinchCenterY: number;<br>旧版本信息：|类名：GestureEvent;<br>方法or属性：pinchCenterY: number;<br>新版本信息：number|gesture.d.ts|
|type有变化|类名：GridColColumnOption;<br>方法or属性：xs?: number,<br>旧版本信息：|类名：GridColColumnOption;<br>方法or属性：xs?: number,<br>新版本信息：?number|grid_col.d.ts|
|type有变化|类名：GridColColumnOption;<br>方法or属性：sm?: number,<br>旧版本信息：|类名：GridColColumnOption;<br>方法or属性：sm?: number,<br>新版本信息：?number|grid_col.d.ts|
|type有变化|类名：GridColColumnOption;<br>方法or属性：md?: number,<br>旧版本信息：|类名：GridColColumnOption;<br>方法or属性：md?: number,<br>新版本信息：?number|grid_col.d.ts|
|type有变化|类名：GridColColumnOption;<br>方法or属性：lg?: number,<br>旧版本信息：|类名：GridColColumnOption;<br>方法or属性：lg?: number,<br>新版本信息：?number|grid_col.d.ts|
|type有变化|类名：GridColColumnOption;<br>方法or属性：xl?: number,<br>旧版本信息：|类名：GridColColumnOption;<br>方法or属性：xl?: number,<br>新版本信息：?number|grid_col.d.ts|
|type有变化|类名：GridColColumnOption;<br>方法or属性：xxl?: number,<br>旧版本信息：|类名：GridColColumnOption;<br>方法or属性：xxl?: number,<br>新版本信息：?number|grid_col.d.ts|
|type有变化|类名：GridColOptions;<br>方法or属性：span?: number \| GridColColumnOption;<br>旧版本信息：|类名：GridColOptions;<br>方法or属性：span?: number \| GridColColumnOption;<br>新版本信息：?(number \| GridColColumnOption)|grid_col.d.ts|
|type有变化|类名：GridColOptions;<br>方法or属性：offset?: number \| GridColColumnOption;<br>旧版本信息：|类名：GridColOptions;<br>方法or属性：offset?: number \| GridColColumnOption;<br>新版本信息：?(number \| GridColColumnOption)|grid_col.d.ts|
|type有变化|类名：GridColOptions;<br>方法or属性：order?: number \| GridColColumnOption;<br>旧版本信息：|类名：GridColOptions;<br>方法or属性：order?: number \| GridColColumnOption;<br>新版本信息：?(number \| GridColColumnOption)|grid_col.d.ts|
|type有变化|类名：GridContainerOptions;<br>方法or属性：columns?: number \| "auto";<br>旧版本信息：|类名：GridContainerOptions;<br>方法or属性：columns?: number \| "auto";<br>新版本信息：?(number \| "auto")|grid_container.d.ts|
|type有变化|类名：GridContainerOptions;<br>方法or属性：sizeType?: SizeType;<br>旧版本信息：|类名：GridContainerOptions;<br>方法or属性：sizeType?: SizeType;<br>新版本信息：?SizeType|grid_container.d.ts|
|type有变化|类名：GridContainerOptions;<br>方法or属性：gutter?: number \| string;<br>旧版本信息：|类名：GridContainerOptions;<br>方法or属性：gutter?: number \| string;<br>新版本信息：?(number \| string)|grid_container.d.ts|
|type有变化|类名：GridContainerOptions;<br>方法or属性：margin?: number \| string;<br>旧版本信息：|类名：GridContainerOptions;<br>方法or属性：margin?: number \| string;<br>新版本信息：?(number \| string)|grid_container.d.ts|
|type有变化|类名：GridRowSizeOption;<br>方法or属性：xs?: Length,<br>旧版本信息：|类名：GridRowSizeOption;<br>方法or属性：xs?: Length,<br>新版本信息：?Length|grid_row.d.ts|
|type有变化|类名：GridRowSizeOption;<br>方法or属性：sm?: Length,<br>旧版本信息：|类名：GridRowSizeOption;<br>方法or属性：sm?: Length,<br>新版本信息：?Length|grid_row.d.ts|
|type有变化|类名：GridRowSizeOption;<br>方法or属性：md?: Length,<br>旧版本信息：|类名：GridRowSizeOption;<br>方法or属性：md?: Length,<br>新版本信息：?Length|grid_row.d.ts|
|type有变化|类名：GridRowSizeOption;<br>方法or属性：lg?: Length,<br>旧版本信息：|类名：GridRowSizeOption;<br>方法or属性：lg?: Length,<br>新版本信息：?Length|grid_row.d.ts|
|type有变化|类名：GridRowSizeOption;<br>方法or属性：xl?: Length,<br>旧版本信息：|类名：GridRowSizeOption;<br>方法or属性：xl?: Length,<br>新版本信息：?Length|grid_row.d.ts|
|type有变化|类名：GridRowColumnOption;<br>方法or属性：xs?: number,<br>旧版本信息：|类名：GridRowColumnOption;<br>方法or属性：xs?: number,<br>新版本信息：?number|grid_row.d.ts|
|type有变化|类名：GridRowColumnOption;<br>方法or属性：sm?: number,<br>旧版本信息：|类名：GridRowColumnOption;<br>方法or属性：sm?: number,<br>新版本信息：?number|grid_row.d.ts|
|type有变化|类名：GridRowColumnOption;<br>方法or属性：md?: number,<br>旧版本信息：|类名：GridRowColumnOption;<br>方法or属性：md?: number,<br>新版本信息：?number|grid_row.d.ts|
|type有变化|类名：GridRowColumnOption;<br>方法or属性：lg?: number,<br>旧版本信息：|类名：GridRowColumnOption;<br>方法or属性：lg?: number,<br>新版本信息：?number|grid_row.d.ts|
|type有变化|类名：GridRowColumnOption;<br>方法or属性：xl?: number,<br>旧版本信息：|类名：GridRowColumnOption;<br>方法or属性：xl?: number,<br>新版本信息：?number|grid_row.d.ts|
|type有变化|类名：GutterOption;<br>方法or属性：x?: Length \| GridRowSizeOption,<br>旧版本信息：|类名：GutterOption;<br>方法or属性：x?: Length \| GridRowSizeOption,<br>新版本信息：?(Length \| GridRowSizeOption)|grid_row.d.ts|
|type有变化|类名：GutterOption;<br>方法or属性：y?: Length \| GridRowSizeOption<br>旧版本信息：|类名：GutterOption;<br>方法or属性：y?: Length \| GridRowSizeOption<br>新版本信息：?(Length \| GridRowSizeOption)|grid_row.d.ts|
|type有变化|类名：BreakPoints;<br>方法or属性：value?: Array\<string>,<br>旧版本信息：|类名：BreakPoints;<br>方法or属性：value?: Array\<string>,<br>新版本信息：?Array\<string>|grid_row.d.ts|
|type有变化|类名：BreakPoints;<br>方法or属性：reference?: BreakpointsReference,<br>旧版本信息：|类名：BreakPoints;<br>方法or属性：reference?: BreakpointsReference,<br>新版本信息：?BreakpointsReference|grid_row.d.ts|
|type有变化|类名：GridRowOptions;<br>方法or属性：gutter?: Length \| GutterOption;<br>旧版本信息：|类名：GridRowOptions;<br>方法or属性：gutter?: Length \| GutterOption;<br>新版本信息：?(Length \| GutterOption)|grid_row.d.ts|
|type有变化|类名：GridRowOptions;<br>方法or属性：columns?: number \| GridRowColumnOption;<br>旧版本信息：|类名：GridRowOptions;<br>方法or属性：columns?: number \| GridRowColumnOption;<br>新版本信息：?(number \| GridRowColumnOption)|grid_row.d.ts|
|type有变化|类名：GridRowOptions;<br>方法or属性：breakpoints?: BreakPoints;<br>旧版本信息：|类名：GridRowOptions;<br>方法or属性：breakpoints?: BreakPoints;<br>新版本信息：?BreakPoints|grid_row.d.ts|
|type有变化|类名：GridRowOptions;<br>方法or属性：direction?: GridRowDirection;<br>旧版本信息：|类名：GridRowOptions;<br>方法or属性：direction?: GridRowDirection;<br>新版本信息：?GridRowDirection|grid_row.d.ts|
|type有变化|类名：ImageFrameInfo;<br>方法or属性：width?: number \| string;<br>旧版本信息：|类名：ImageFrameInfo;<br>方法or属性：width?: number \| string;<br>新版本信息：?(number \| string)|image_animator.d.ts|
|type有变化|类名：ImageFrameInfo;<br>方法or属性：height?: number \| string;<br>旧版本信息：|类名：ImageFrameInfo;<br>方法or属性：height?: number \| string;<br>新版本信息：?(number \| string)|image_animator.d.ts|
|type有变化|类名：ImageFrameInfo;<br>方法or属性：top?: number \| string;<br>旧版本信息：|类名：ImageFrameInfo;<br>方法or属性：top?: number \| string;<br>新版本信息：?(number \| string)|image_animator.d.ts|
|type有变化|类名：ImageFrameInfo;<br>方法or属性：left?: number \| string;<br>旧版本信息：|类名：ImageFrameInfo;<br>方法or属性：left?: number \| string;<br>新版本信息：?(number \| string)|image_animator.d.ts|
|type有变化|类名：ImageFrameInfo;<br>方法or属性：duration?: number;<br>旧版本信息：|类名：ImageFrameInfo;<br>方法or属性：duration?: number;<br>新版本信息：?number|image_animator.d.ts|
|type有变化|类名：ChainAnimationOptions;<br>方法or属性：conductivity?: number;<br>旧版本信息：number|类名：ChainAnimationOptions;<br>方法or属性：conductivity?: number;<br>新版本信息：?number|list.d.ts|
|type有变化|类名：ChainAnimationOptions;<br>方法or属性：intensity?: number;<br>旧版本信息：number|类名：ChainAnimationOptions;<br>方法or属性：intensity?: number;<br>新版本信息：?number|list.d.ts|
|type有变化|类名：ChainAnimationOptions;<br>方法or属性：edgeEffect?: ChainEdgeEffect;<br>旧版本信息：ChainEdgeEffect|类名：ChainAnimationOptions;<br>方法or属性：edgeEffect?: ChainEdgeEffect;<br>新版本信息：?ChainEdgeEffect|list.d.ts|
|type有变化|类名：SwipeActionOptions;<br>方法or属性：start?: CustomBuilder \| SwipeActionItem;<br>旧版本信息：|类名：SwipeActionOptions;<br>方法or属性：start?: CustomBuilder \| SwipeActionItem;<br>新版本信息：?(CustomBuilder \| SwipeActionItem)|list_item.d.ts|
|type有变化|类名：SwipeActionOptions;<br>方法or属性：end?: CustomBuilder \| SwipeActionItem;<br>旧版本信息：|类名：SwipeActionOptions;<br>方法or属性：end?: CustomBuilder \| SwipeActionItem;<br>新版本信息：?(CustomBuilder \| SwipeActionItem)|list_item.d.ts|
|type有变化|类名：SwipeActionOptions;<br>方法or属性：edgeEffect?: SwipeEdgeEffect;<br>旧版本信息：|类名：SwipeActionOptions;<br>方法or属性：edgeEffect?: SwipeEdgeEffect;<br>新版本信息：?SwipeEdgeEffect|list_item.d.ts|
|type有变化|类名：ListItemGroupOptions;<br>方法or属性：header?: CustomBuilder;<br>旧版本信息：|类名：ListItemGroupOptions;<br>方法or属性：header?: CustomBuilder;<br>新版本信息：?CustomBuilder|list_item_group.d.ts|
|type有变化|类名：ListItemGroupOptions;<br>方法or属性：footer?: CustomBuilder;<br>旧版本信息：|类名：ListItemGroupOptions;<br>方法or属性：footer?: CustomBuilder;<br>新版本信息：?CustomBuilder|list_item_group.d.ts|
|type有变化|类名：ListItemGroupOptions;<br>方法or属性：space?: number \| string;<br>旧版本信息：|类名：ListItemGroupOptions;<br>方法or属性：space?: number \| string;<br>新版本信息：?(number \| string)|list_item_group.d.ts|
|type有变化|类名：Matrix2D;<br>方法or属性：scaleX?: number;<br>旧版本信息：|类名：Matrix2D;<br>方法or属性：scaleX?: number;<br>新版本信息：?number|matrix2d.d.ts|
|type有变化|类名：Matrix2D;<br>方法or属性：rotateY?: number;<br>旧版本信息：|类名：Matrix2D;<br>方法or属性：rotateY?: number;<br>新版本信息：?number|matrix2d.d.ts|
|type有变化|类名：Matrix2D;<br>方法or属性：rotateX?: number;<br>旧版本信息：|类名：Matrix2D;<br>方法or属性：rotateX?: number;<br>新版本信息：?number|matrix2d.d.ts|
|type有变化|类名：Matrix2D;<br>方法or属性：scaleY?: number;<br>旧版本信息：|类名：Matrix2D;<br>方法or属性：scaleY?: number;<br>新版本信息：?number|matrix2d.d.ts|
|type有变化|类名：Matrix2D;<br>方法or属性：translateX?: number;<br>旧版本信息：|类名：Matrix2D;<br>方法or属性：translateX?: number;<br>新版本信息：?number|matrix2d.d.ts|
|type有变化|类名：Matrix2D;<br>方法or属性：translateY?: number;<br>旧版本信息：|类名：Matrix2D;<br>方法or属性：translateY?: number;<br>新版本信息：?number|matrix2d.d.ts|
|type有变化|类名：MenuItemOptions;<br>方法or属性：startIcon?: ResourceStr;<br>旧版本信息：|类名：MenuItemOptions;<br>方法or属性：startIcon?: ResourceStr;<br>新版本信息：?ResourceStr|menu_item.d.ts|
|type有变化|类名：MenuItemOptions;<br>方法or属性：content?: ResourceStr;<br>旧版本信息：|类名：MenuItemOptions;<br>方法or属性：content?: ResourceStr;<br>新版本信息：?ResourceStr|menu_item.d.ts|
|type有变化|类名：MenuItemOptions;<br>方法or属性：endIcon?: ResourceStr;<br>旧版本信息：|类名：MenuItemOptions;<br>方法or属性：endIcon?: ResourceStr;<br>新版本信息：?ResourceStr|menu_item.d.ts|
|type有变化|类名：MenuItemOptions;<br>方法or属性：labelInfo?: ResourceStr;<br>旧版本信息：|类名：MenuItemOptions;<br>方法or属性：labelInfo?: ResourceStr;<br>新版本信息：?ResourceStr|menu_item.d.ts|
|type有变化|类名：MenuItemOptions;<br>方法or属性：builder?: CustomBuilder;<br>旧版本信息：|类名：MenuItemOptions;<br>方法or属性：builder?: CustomBuilder;<br>新版本信息：?CustomBuilder|menu_item.d.ts|
|type有变化|类名：MenuItemGroupOptions;<br>方法or属性：header?: ResourceStr \| CustomBuilder;<br>旧版本信息：|类名：MenuItemGroupOptions;<br>方法or属性：header?: ResourceStr \| CustomBuilder;<br>新版本信息：?(ResourceStr \| CustomBuilder)|menu_item_group.d.ts|
|type有变化|类名：MenuItemGroupOptions;<br>方法or属性：footer?: ResourceStr \| CustomBuilder;<br>旧版本信息：|类名：MenuItemGroupOptions;<br>方法or属性：footer?: ResourceStr \| CustomBuilder;<br>新版本信息：?(ResourceStr \| CustomBuilder)|menu_item_group.d.ts|
|type有变化|类名：NavigationCommonTitle;<br>方法or属性：main: string;<br>旧版本信息：|类名：NavigationCommonTitle;<br>方法or属性：main: string;<br>新版本信息：string|navigation.d.ts|
|type有变化|类名：NavigationCommonTitle;<br>方法or属性：sub: string;<br>旧版本信息：|类名：NavigationCommonTitle;<br>方法or属性：sub: string;<br>新版本信息：string|navigation.d.ts|
|type有变化|类名：NavigationCustomTitle;<br>方法or属性：builder: CustomBuilder;<br>旧版本信息：|类名：NavigationCustomTitle;<br>方法or属性：builder: CustomBuilder;<br>新版本信息：CustomBuilder|navigation.d.ts|
|type有变化|类名：NavigationCustomTitle;<br>方法or属性：height: TitleHeight \| Length;<br>旧版本信息：|类名：NavigationCustomTitle;<br>方法or属性：height: TitleHeight \| Length;<br>新版本信息：TitleHeight \| Length|navigation.d.ts|
|type有变化|类名：NavigationMenuItem;<br>方法or属性：value: string;<br>旧版本信息：|类名：NavigationMenuItem;<br>方法or属性：value: string;<br>新版本信息：string|navigation.d.ts|
|type有变化|类名：NavigationMenuItem;<br>方法or属性：icon?: string;<br>旧版本信息：|类名：NavigationMenuItem;<br>方法or属性：icon?: string;<br>新版本信息：?string|navigation.d.ts|
|type有变化|类名：NavigationMenuItem;<br>方法or属性：action?: () => void;<br>旧版本信息：|类名：NavigationMenuItem;<br>方法or属性：action?: () => void;<br>新版本信息：?(() => void)|navigation.d.ts|
|type有变化|类名：NavPathInfo;<br>方法or属性：param?: unknown;<br>旧版本信息：unknown|类名：NavPathInfo;<br>方法or属性：param?: unknown;<br>新版本信息：?unknown|navigation.d.ts|
|type有变化|类名：NavigationAttribute;<br>方法or属性：title(value: ResourceStr \| CustomBuilder \| NavigationCommonTitle \| NavigationCustomTitle): NavigationAttribute;<br>旧版本信息：(ResourceStr \| CustomBuilder \| NavigationCommonTitle \| NavigationCustomTitle)|类名：NavigationAttribute;<br>方法or属性：title(value: ResourceStr \| CustomBuilder \| NavigationCommonTitle \| NavigationCustomTitle): NavigationAttribute;<br>新版本信息：|navigation.d.ts|
|type有变化|类名：NavDestinationCommonTitle;<br>方法or属性：main: string;<br>旧版本信息：|类名：NavDestinationCommonTitle;<br>方法or属性：main: string;<br>新版本信息：string|nav_destination.d.ts|
|type有变化|类名：NavDestinationCommonTitle;<br>方法or属性：sub: string;<br>旧版本信息：|类名：NavDestinationCommonTitle;<br>方法or属性：sub: string;<br>新版本信息：string|nav_destination.d.ts|
|type有变化|类名：NavDestinationCustomTitle;<br>方法or属性：builder: CustomBuilder;<br>旧版本信息：|类名：NavDestinationCustomTitle;<br>方法or属性：builder: CustomBuilder;<br>新版本信息：CustomBuilder|nav_destination.d.ts|
|type有变化|类名：NavDestinationCustomTitle;<br>方法or属性：height: TitleHeight \| Length;<br>旧版本信息：|类名：NavDestinationCustomTitle;<br>方法or属性：height: TitleHeight \| Length;<br>新版本信息：TitleHeight \| Length|nav_destination.d.ts|
|type有变化|类名：RouteInfo;<br>方法or属性：param?: unknown;<br>旧版本信息：unknown|类名：RouteInfo;<br>方法or属性：param?: unknown;<br>新版本信息：?unknown|nav_router.d.ts|
|type有变化|类名：PluginComponentTemplate;<br>方法or属性：source: string;<br>旧版本信息：|类名：PluginComponentTemplate;<br>方法or属性：source: string;<br>新版本信息：string|plugin_component.d.ts|
|type有变化|类名：PluginComponentTemplate;<br>方法or属性：bundleName: string;<br>旧版本信息：|类名：PluginComponentTemplate;<br>方法or属性：bundleName: string;<br>新版本信息：string|plugin_component.d.ts|
|type有变化|类名：ProgressOptions;<br>方法or属性：value: number;<br>旧版本信息：|类名：ProgressOptions;<br>方法or属性：value: number;<br>新版本信息：number|progress.d.ts|
|type有变化|类名：ProgressOptions;<br>方法or属性：total?: number;<br>旧版本信息：|类名：ProgressOptions;<br>方法or属性：total?: number;<br>新版本信息：?number|progress.d.ts|
|type有变化|类名：ProgressOptions;<br>方法or属性：style?: ProgressStyle<br>旧版本信息：|类名：ProgressOptions;<br>方法or属性：style?: ProgressStyle<br>新版本信息：?ProgressStyle|progress.d.ts|
|type有变化|类名：ProgressOptions;<br>方法or属性：type?: Type<br>旧版本信息：|类名：ProgressOptions;<br>方法or属性：type?: Type<br>新版本信息：?Type|progress.d.ts|
|type有变化|类名：ProgressStyleOptions;<br>方法or属性：strokeWidth?: Length;<br>旧版本信息：|类名：ProgressStyleOptions;<br>方法or属性：strokeWidth?: Length;<br>新版本信息：?Length|progress.d.ts|
|type有变化|类名：ProgressStyleOptions;<br>方法or属性：scaleCount?: number;<br>旧版本信息：|类名：ProgressStyleOptions;<br>方法or属性：scaleCount?: number;<br>新版本信息：?number|progress.d.ts|
|type有变化|类名：ProgressStyleOptions;<br>方法or属性：scaleWidth?: Length;<br>旧版本信息：|类名：ProgressStyleOptions;<br>方法or属性：scaleWidth?: Length;<br>新版本信息：?Length|progress.d.ts|
|type有变化|类名：RadioOptions;<br>方法or属性：group: string;<br>旧版本信息：|类名：RadioOptions;<br>方法or属性：group: string;<br>新版本信息：string|radio.d.ts|
|type有变化|类名：RadioOptions;<br>方法or属性：value: string;<br>旧版本信息：|类名：RadioOptions;<br>方法or属性：value: string;<br>新版本信息：string|radio.d.ts|
|type有变化|类名：RadioStyle;<br>方法or属性：checkedBackgroundColor?: ResourceColor;<br>旧版本信息：ResourceColor|类名：RadioStyle;<br>方法or属性：checkedBackgroundColor?: ResourceColor;<br>新版本信息：?ResourceColor|radio.d.ts|
|type有变化|类名：RadioStyle;<br>方法or属性：uncheckedBorderColor?: ResourceColor;<br>旧版本信息：ResourceColor|类名：RadioStyle;<br>方法or属性：uncheckedBorderColor?: ResourceColor;<br>新版本信息：?ResourceColor|radio.d.ts|
|type有变化|类名：RadioStyle;<br>方法or属性：indicatorColor?: ResourceColor;<br>旧版本信息：ResourceColor|类名：RadioStyle;<br>方法or属性：indicatorColor?: ResourceColor;<br>新版本信息：?ResourceColor|radio.d.ts|
|type有变化|类名：RefreshOptions;<br>方法or属性：offset?: number \| string;<br>旧版本信息：number \| string|类名：RefreshOptions;<br>方法or属性：offset?: number \| string;<br>新版本信息：?(number \| string)|refresh.d.ts|
|type有变化|类名：RefreshOptions;<br>方法or属性：friction?: number \| string;<br>旧版本信息：number \| string|类名：RefreshOptions;<br>方法or属性：friction?: number \| string;<br>新版本信息：?(number \| string)|refresh.d.ts|
|type有变化|类名：RefreshOptions;<br>方法or属性：builder?: CustomBuilder;<br>旧版本信息：CustomBuilder|类名：RefreshOptions;<br>方法or属性：builder?: CustomBuilder;<br>新版本信息：?CustomBuilder|refresh.d.ts|
|type有变化|类名：RRect;<br>方法or属性：left: number;<br>旧版本信息：|类名：RRect;<br>方法or属性：left: number;<br>新版本信息：number|remote_window.d.ts|
|type有变化|类名：RRect;<br>方法or属性：top: number;<br>旧版本信息：|类名：RRect;<br>方法or属性：top: number;<br>新版本信息：number|remote_window.d.ts|
|type有变化|类名：RRect;<br>方法or属性：width: number;<br>旧版本信息：|类名：RRect;<br>方法or属性：width: number;<br>新版本信息：number|remote_window.d.ts|
|type有变化|类名：RRect;<br>方法or属性：height: number;<br>旧版本信息：|类名：RRect;<br>方法or属性：height: number;<br>新版本信息：number|remote_window.d.ts|
|type有变化|类名：RRect;<br>方法or属性：radius: number;<br>旧版本信息：|类名：RRect;<br>方法or属性：radius: number;<br>新版本信息：number|remote_window.d.ts|
|type有变化|类名：WindowAnimationTarget;<br>方法or属性：readonly bundleName: string;<br>旧版本信息：|类名：WindowAnimationTarget;<br>方法or属性：readonly bundleName: string;<br>新版本信息：string|remote_window.d.ts|
|type有变化|类名：WindowAnimationTarget;<br>方法or属性：readonly abilityName: string;<br>旧版本信息：|类名：WindowAnimationTarget;<br>方法or属性：readonly abilityName: string;<br>新版本信息：string|remote_window.d.ts|
|type有变化|类名：WindowAnimationTarget;<br>方法or属性：readonly windowBounds: RRect;<br>旧版本信息：|类名：WindowAnimationTarget;<br>方法or属性：readonly windowBounds: RRect;<br>新版本信息：RRect|remote_window.d.ts|
|type有变化|类名：WindowAnimationTarget;<br>方法or属性：readonly missionId: number;<br>旧版本信息：|类名：WindowAnimationTarget;<br>方法or属性：readonly missionId: number;<br>新版本信息：number|remote_window.d.ts|
|type有变化|类名：ScrollBarOptions;<br>方法or属性：scroller: Scroller;<br>旧版本信息：|类名：ScrollBarOptions;<br>方法or属性：scroller: Scroller;<br>新版本信息：Scroller|scroll_bar.d.ts|
|type有变化|类名：ScrollBarOptions;<br>方法or属性：direction?: ScrollBarDirection;<br>旧版本信息：|类名：ScrollBarOptions;<br>方法or属性：direction?: ScrollBarDirection;<br>新版本信息：?ScrollBarDirection|scroll_bar.d.ts|
|type有变化|类名：ScrollBarOptions;<br>方法or属性：state?: BarState;<br>旧版本信息：|类名：ScrollBarOptions;<br>方法or属性：state?: BarState;<br>新版本信息：?BarState|scroll_bar.d.ts|
|type有变化|类名：IconOptions;<br>方法or属性：size?: Length;<br>旧版本信息：Length|类名：IconOptions;<br>方法or属性：size?: Length;<br>新版本信息：?Length|search.d.ts|
|type有变化|类名：IconOptions;<br>方法or属性：color?: ResourceColor;<br>旧版本信息：ResourceColor|类名：IconOptions;<br>方法or属性：color?: ResourceColor;<br>新版本信息：?ResourceColor|search.d.ts|
|type有变化|类名：CaretStyle;<br>方法or属性：color?: ResourceColor,<br>旧版本信息：ResourceColor|类名：CaretStyle;<br>方法or属性：color?: ResourceColor,<br>新版本信息：?ResourceColor|search.d.ts|
|type有变化|类名：IconOptions;<br>方法or属性：src?: ResourceStr;<br>旧版本信息：ResourceStr|类名：IconOptions;<br>方法or属性：src?: ResourceStr;<br>新版本信息：?ResourceStr|search.d.ts|
|type有变化|类名：CaretStyle;<br>方法or属性：width?: Length,<br>旧版本信息：Length|类名：CaretStyle;<br>方法or属性：width?: Length,<br>新版本信息：?Length|search.d.ts|
|type有变化|类名：SelectOption;<br>方法or属性：value: ResourceStr;<br>旧版本信息：|类名：SelectOption;<br>方法or属性：value: ResourceStr;<br>新版本信息：ResourceStr|select.d.ts|
|type有变化|类名：SelectOption;<br>方法or属性：icon?: ResourceStr;<br>旧版本信息：|类名：SelectOption;<br>方法or属性：icon?: ResourceStr;<br>新版本信息：ResourceStr|select.d.ts|
|type有变化|类名：ButtonStyle;<br>方法or属性：left?: number;<br>旧版本信息：|类名：ButtonStyle;<br>方法or属性：left?: number;<br>新版本信息：?number|sidebar.d.ts|
|type有变化|类名：ButtonStyle;<br>方法or属性：top?: number;<br>旧版本信息：|类名：ButtonStyle;<br>方法or属性：top?: number;<br>新版本信息：?number|sidebar.d.ts|
|type有变化|类名：ButtonStyle;<br>方法or属性：width?: number;<br>旧版本信息：|类名：ButtonStyle;<br>方法or属性：width?: number;<br>新版本信息：?number|sidebar.d.ts|
|type有变化|类名：ButtonStyle;<br>方法or属性：height?: number;<br>旧版本信息：|类名：ButtonStyle;<br>方法or属性：height?: number;<br>新版本信息：?number|sidebar.d.ts|
|type有变化|类名：DividerStyle;<br>方法or属性：color?: ResourceColor;<br>旧版本信息：ResourceColor|类名：DividerStyle;<br>方法or属性：color?: ResourceColor;<br>新版本信息：?ResourceColor|sidebar.d.ts|
|type有变化|类名：DividerStyle;<br>方法or属性：startMargin?: Length;<br>旧版本信息：Length|类名：DividerStyle;<br>方法or属性：startMargin?: Length;<br>新版本信息：?Length|sidebar.d.ts|
|type有变化|类名：DividerStyle;<br>方法or属性：endMargin?: Length;<br>旧版本信息：Length|类名：DividerStyle;<br>方法or属性：endMargin?: Length;<br>新版本信息：?Length|sidebar.d.ts|
|type有变化|类名：SliderOptions;<br>方法or属性：value?: number;<br>旧版本信息：|类名：SliderOptions;<br>方法or属性：value?: number;<br>新版本信息：?number|slider.d.ts|
|type有变化|类名：SliderOptions;<br>方法or属性：min?: number;<br>旧版本信息：|类名：SliderOptions;<br>方法or属性：min?: number;<br>新版本信息：?number|slider.d.ts|
|type有变化|类名：SliderOptions;<br>方法or属性：max?: number;<br>旧版本信息：|类名：SliderOptions;<br>方法or属性：max?: number;<br>新版本信息：?number|slider.d.ts|
|type有变化|类名：SliderOptions;<br>方法or属性：step?: number;<br>旧版本信息：|类名：SliderOptions;<br>方法or属性：step?: number;<br>新版本信息：?number|slider.d.ts|
|type有变化|类名：SliderOptions;<br>方法or属性：style?: SliderStyle;<br>旧版本信息：|类名：SliderOptions;<br>方法or属性：style?: SliderStyle;<br>新版本信息：?SliderStyle|slider.d.ts|
|type有变化|类名：SliderOptions;<br>方法or属性：direction?: Axis;<br>旧版本信息：|类名：SliderOptions;<br>方法or属性：direction?: Axis;<br>新版本信息：?Axis|slider.d.ts|
|type有变化|类名：SliderOptions;<br>方法or属性：reverse?: boolean;<br>旧版本信息：|类名：SliderOptions;<br>方法or属性：reverse?: boolean;<br>新版本信息：?boolean|slider.d.ts|
|type有变化|类名：SliderBlockStyle;<br>方法or属性：image?: ResourceStr;<br>旧版本信息：ResourceStr|类名：SliderBlockStyle;<br>方法or属性：image?: ResourceStr;<br>新版本信息：?ResourceStr|slider.d.ts|
|type有变化|类名：SliderBlockStyle;<br>方法or属性：shape?: CircleAttribute \| EllipseAttribute \| PathAttribute \| RectAttribute;<br>旧版本信息：CircleAttribute \| EllipseAttribute \| PathAttribute \| RectAttribute|类名：SliderBlockStyle;<br>方法or属性：shape?: CircleAttribute \| EllipseAttribute \| PathAttribute \| RectAttribute;<br>新版本信息：?(CircleAttribute \| EllipseAttribute \| PathAttribute \| RectAttribute)|slider.d.ts|
|type有变化|类名：IndicatorStyle;<br>方法or属性：left?: Length;<br>旧版本信息：|类名：IndicatorStyle;<br>方法or属性：left?: Length;<br>新版本信息：?Length|swiper.d.ts|
|type有变化|类名：IndicatorStyle;<br>方法or属性：top?: Length;<br>旧版本信息：|类名：IndicatorStyle;<br>方法or属性：top?: Length;<br>新版本信息：?Length|swiper.d.ts|
|type有变化|类名：IndicatorStyle;<br>方法or属性：right?: Length;<br>旧版本信息：|类名：IndicatorStyle;<br>方法or属性：right?: Length;<br>新版本信息：?Length|swiper.d.ts|
|type有变化|类名：IndicatorStyle;<br>方法or属性：bottom?: Length;<br>旧版本信息：|类名：IndicatorStyle;<br>方法or属性：bottom?: Length;<br>新版本信息：?Length|swiper.d.ts|
|type有变化|类名：IndicatorStyle;<br>方法or属性：size?: Length;<br>旧版本信息：|类名：IndicatorStyle;<br>方法or属性：size?: Length;<br>新版本信息：?Length|swiper.d.ts|
|type有变化|类名：IndicatorStyle;<br>方法or属性：mask?: boolean;<br>旧版本信息：|类名：IndicatorStyle;<br>方法or属性：mask?: boolean;<br>新版本信息：?boolean|swiper.d.ts|
|type有变化|类名：IndicatorStyle;<br>方法or属性：color?: ResourceColor;<br>旧版本信息：|类名：IndicatorStyle;<br>方法or属性：color?: ResourceColor;<br>新版本信息：?ResourceColor|swiper.d.ts|
|type有变化|类名：IndicatorStyle;<br>方法or属性：selectedColor?: ResourceColor;<br>旧版本信息：|类名：IndicatorStyle;<br>方法or属性：selectedColor?: ResourceColor;<br>新版本信息：?ResourceColor|swiper.d.ts|
|type有变化|类名：IndicatorStyle;<br>方法or属性：height?: Length;<br>旧版本信息：Length|类名：IndicatorStyle;<br>方法or属性：height?: Length;<br>新版本信息：?Length|tab_content.d.ts|
|type有变化|类名：IndicatorStyle;<br>方法or属性：width?: Length;<br>旧版本信息：Length|类名：IndicatorStyle;<br>方法or属性：width?: Length;<br>新版本信息：?Length|tab_content.d.ts|
|type有变化|类名：IndicatorStyle;<br>方法or属性：borderRadius?: Length;<br>旧版本信息：Length|类名：IndicatorStyle;<br>方法or属性：borderRadius?: Length;<br>新版本信息：?Length|tab_content.d.ts|
|type有变化|类名：BoardStyle;<br>方法or属性：borderRadius?: Length;<br>旧版本信息：Length|类名：BoardStyle;<br>方法or属性：borderRadius?: Length;<br>新版本信息：?Length|tab_content.d.ts|
|type有变化|类名：IndicatorStyle;<br>方法or属性：marginTop?: Length;<br>旧版本信息：Length|类名：IndicatorStyle;<br>方法or属性：marginTop?: Length;<br>新版本信息：?Length|tab_content.d.ts|
|type有变化|类名：SwiperAttribute;<br>方法or属性：curve(value: Curve \| string \| ICurve): SwiperAttribute;<br>旧版本信息：?(Curve \| string \| ICurve)|类名：SwiperAttribute;<br>方法or属性：curve(value: Curve \| string \| ICurve): SwiperAttribute;<br>新版本信息：|swiper.d.ts|
|type有变化|类名：TextAttribute;<br>方法or属性：draggable(value: boolean): TextAttribute;<br>旧版本信息：|类名：TextAttribute;<br>方法or属性：draggable(value: boolean): TextAttribute;<br>新版本信息：|text.d.ts|
|type有变化|类名：TextAreaOptions;<br>方法or属性：placeholder?: ResourceStr;<br>旧版本信息：|类名：TextAreaOptions;<br>方法or属性：placeholder?: ResourceStr;<br>新版本信息：?ResourceStr|text_area.d.ts|
|type有变化|类名：TextAreaOptions;<br>方法or属性：text?: ResourceStr;<br>旧版本信息：|类名：TextAreaOptions;<br>方法or属性：text?: ResourceStr;<br>新版本信息：?ResourceStr|text_area.d.ts|
|type有变化|类名：TextAreaOptions;<br>方法or属性：controller?: TextAreaController;<br>旧版本信息：|类名：TextAreaOptions;<br>方法or属性：controller?: TextAreaController;<br>新版本信息：?TextAreaController|text_area.d.ts|
|type有变化|类名：TextInputOptions;<br>方法or属性：placeholder?: ResourceStr;<br>旧版本信息：|类名：TextInputOptions;<br>方法or属性：placeholder?: ResourceStr;<br>新版本信息：?ResourceStr|text_input.d.ts|
|type有变化|类名：TextInputOptions;<br>方法or属性：text?: ResourceStr;<br>旧版本信息：|类名：TextInputOptions;<br>方法or属性：text?: ResourceStr;<br>新版本信息：?ResourceStr|text_input.d.ts|
|type有变化|类名：TextInputOptions;<br>方法or属性：controller?: TextInputController;<br>旧版本信息：|类名：TextInputOptions;<br>方法or属性：controller?: TextInputController;<br>新版本信息：?TextInputController|text_input.d.ts|
|type有变化|类名：TextPickerRangeContent;<br>方法or属性：text?: string \| Resource;<br>旧版本信息：string \| Resource|类名：TextPickerRangeContent;<br>方法or属性：text?: string \| Resource;<br>新版本信息：?(string \| Resource)|text_picker.d.ts|
|type有变化|类名：TextPickerOptions;<br>方法or属性：range: string[] \| string[][] \| Resource \| TextPickerRangeContent[] \| TextCascadePickerRangeContent[];<br>旧版本信息：string[] \| Resource \| TextPickerRangeContent[]|类名：TextPickerOptions;<br>方法or属性：range: string[] \| string[][] \| Resource \| TextPickerRangeContent[] \| TextCascadePickerRangeContent[];<br>新版本信息：string[] \| string[][] \| Resource \| TextPickerRangeContent[] \| TextCascadePickerRangeContent[]|text_picker.d.ts|
|type有变化|类名：TextPickerOptions;<br>方法or属性：value?: string \| string[];<br>旧版本信息：string|类名：TextPickerOptions;<br>方法or属性：value?: string \| string[];<br>新版本信息：?(string \| string[])|text_picker.d.ts|
|type有变化|类名：TextPickerOptions;<br>方法or属性：selected?: number \| number[];<br>旧版本信息：|类名：TextPickerOptions;<br>方法or属性：selected?: number \| number[];<br>新版本信息：?(number \| number[])|text_picker.d.ts|
|type有变化|类名：TextPickerResult;<br>方法or属性：value: string \| string[];<br>旧版本信息：string|类名：TextPickerResult;<br>方法or属性：value: string \| string[];<br>新版本信息：string \| string[]|text_picker.d.ts|
|type有变化|类名：TextPickerResult;<br>方法or属性：index: number \| number[];<br>旧版本信息：|类名：TextPickerResult;<br>方法or属性：index: number \| number[];<br>新版本信息：number \| number[]|text_picker.d.ts|
|type有变化|类名：TextPickerDialogOptions;<br>方法or属性：defaultPickerItemHeight?: number \| string;<br>旧版本信息：|类名：TextPickerDialogOptions;<br>方法or属性：defaultPickerItemHeight?: number \| string;<br>新版本信息：number \| string|text_picker.d.ts|
|type有变化|类名：TextPickerDialogOptions;<br>方法or属性：disappearTextStyle?: PickerTextStyle;<br>旧版本信息：PickerTextStyle|类名：TextPickerDialogOptions;<br>方法or属性：disappearTextStyle?: PickerTextStyle;<br>新版本信息：?PickerTextStyle|text_picker.d.ts|
|type有变化|类名：TextPickerDialogOptions;<br>方法or属性：textStyle?: PickerTextStyle;<br>旧版本信息：PickerTextStyle|类名：TextPickerDialogOptions;<br>方法or属性：textStyle?: PickerTextStyle;<br>新版本信息：?PickerTextStyle|text_picker.d.ts|
|type有变化|类名：TextPickerDialogOptions;<br>方法or属性：selectedTextStyle?: PickerTextStyle;<br>旧版本信息：PickerTextStyle|类名：TextPickerDialogOptions;<br>方法or属性：selectedTextStyle?: PickerTextStyle;<br>新版本信息：?PickerTextStyle|text_picker.d.ts|
|type有变化|类名：TextPickerDialogOptions;<br>方法or属性：onAccept?: (value: TextPickerResult) => void;<br>旧版本信息：|类名：TextPickerDialogOptions;<br>方法or属性：onAccept?: (value: TextPickerResult) => void;<br>新版本信息：?((value: TextPickerResult) => void)|text_picker.d.ts|
|type有变化|类名：TextPickerDialogOptions;<br>方法or属性：onCancel?: () => void;<br>旧版本信息：|类名：TextPickerDialogOptions;<br>方法or属性：onCancel?: () => void;<br>新版本信息：?(() => void)|text_picker.d.ts|
|type有变化|类名：TextPickerDialogOptions;<br>方法or属性：onChange?: (value: TextPickerResult) => void;<br>旧版本信息：|类名：TextPickerDialogOptions;<br>方法or属性：onChange?: (value: TextPickerResult) => void;<br>新版本信息：?((value: TextPickerResult) => void)|text_picker.d.ts|
|type有变化|类名：TextTimerOptions;<br>方法or属性：isCountDown?: boolean;<br>旧版本信息：|类名：TextTimerOptions;<br>方法or属性：isCountDown?: boolean;<br>新版本信息：?boolean|text_timer.d.ts|
|type有变化|类名：TextTimerOptions;<br>方法or属性：count?: number;<br>旧版本信息：|类名：TextTimerOptions;<br>方法or属性：count?: number;<br>新版本信息：?number|text_timer.d.ts|
|type有变化|类名：TextTimerOptions;<br>方法or属性：controller?: TextTimerController;<br>旧版本信息：|类名：TextTimerOptions;<br>方法or属性：controller?: TextTimerController;<br>新版本信息：?TextTimerController|text_timer.d.ts|
|type有变化|类名：TimePickerResult;<br>方法or属性：hour?: number;<br>旧版本信息：|类名：TimePickerResult;<br>方法or属性：hour?: number;<br>新版本信息：?number|time_picker.d.ts|
|type有变化|类名：TimePickerResult;<br>方法or属性：minute?: number;<br>旧版本信息：|类名：TimePickerResult;<br>方法or属性：minute?: number;<br>新版本信息：?number|time_picker.d.ts|
|type有变化|类名：TimePickerOptions;<br>方法or属性：selected?: Date;<br>旧版本信息：|类名：TimePickerOptions;<br>方法or属性：selected?: Date;<br>新版本信息：?Date|time_picker.d.ts|
|type有变化|类名：TimePickerDialogOptions;<br>方法or属性：useMilitaryTime?: boolean;<br>旧版本信息：|类名：TimePickerDialogOptions;<br>方法or属性：useMilitaryTime?: boolean;<br>新版本信息：?boolean|time_picker.d.ts|
|type有变化|类名：TimePickerDialogOptions;<br>方法or属性：disappearTextStyle?: PickerTextStyle;<br>旧版本信息：PickerTextStyle|类名：TimePickerDialogOptions;<br>方法or属性：disappearTextStyle?: PickerTextStyle;<br>新版本信息：?PickerTextStyle|time_picker.d.ts|
|type有变化|类名：TimePickerDialogOptions;<br>方法or属性：textStyle?: PickerTextStyle;<br>旧版本信息：PickerTextStyle|类名：TimePickerDialogOptions;<br>方法or属性：textStyle?: PickerTextStyle;<br>新版本信息：?PickerTextStyle|time_picker.d.ts|
|type有变化|类名：TimePickerDialogOptions;<br>方法or属性：selectedTextStyle?: PickerTextStyle;<br>旧版本信息：PickerTextStyle|类名：TimePickerDialogOptions;<br>方法or属性：selectedTextStyle?: PickerTextStyle;<br>新版本信息：?PickerTextStyle|time_picker.d.ts|
|type有变化|类名：TimePickerDialogOptions;<br>方法or属性：onAccept?: (value: TimePickerResult) => void;<br>旧版本信息：|类名：TimePickerDialogOptions;<br>方法or属性：onAccept?: (value: TimePickerResult) => void;<br>新版本信息：?((value: TimePickerResult) => void)|time_picker.d.ts|
|type有变化|类名：TimePickerDialogOptions;<br>方法or属性：onCancel?: () => void;<br>旧版本信息：|类名：TimePickerDialogOptions;<br>方法or属性：onCancel?: () => void;<br>新版本信息：?(() => void)|time_picker.d.ts|
|type有变化|类名：TimePickerDialogOptions;<br>方法or属性：onChange?: (value: TimePickerResult) => void;<br>旧版本信息：|类名：TimePickerDialogOptions;<br>方法or属性：onChange?: (value: TimePickerResult) => void;<br>新版本信息：?((value: TimePickerResult) => void)|time_picker.d.ts|
|type有变化|类名：Resource;<br>方法or属性：readonly id: number;<br>旧版本信息：|类名：Resource;<br>方法or属性：readonly id: number;<br>新版本信息：number|units.d.ts|
|type有变化|类名：Resource;<br>方法or属性：readonly type: number;<br>旧版本信息：|类名：Resource;<br>方法or属性：readonly type: number;<br>新版本信息：number|units.d.ts|
|type有变化|类名：Resource;<br>方法or属性：readonly params?: any[];<br>旧版本信息：|类名：Resource;<br>方法or属性：readonly params?: any[];<br>新版本信息：?any[]|units.d.ts|
|type有变化|类名：Resource;<br>方法or属性：readonly bundleName: string;<br>旧版本信息：|类名：Resource;<br>方法or属性：readonly bundleName: string;<br>新版本信息：string|units.d.ts|
|type有变化|类名：Resource;<br>方法or属性：readonly moduleName: string;<br>旧版本信息：|类名：Resource;<br>方法or属性：readonly moduleName: string;<br>新版本信息：string|units.d.ts|
|type有变化|类名：Font;<br>方法or属性：size?: Length;<br>旧版本信息：|类名：Font;<br>方法or属性：size?: Length;<br>新版本信息：?Length|units.d.ts|
|type有变化|类名：MarkStyle;<br>方法or属性：size?: Length;<br>旧版本信息：Length|类名：MarkStyle;<br>方法or属性：size?: Length;<br>新版本信息：?Length|units.d.ts|
|type有变化|类名：Font;<br>方法or属性：weight?: FontWeight \| number \| string;<br>旧版本信息：|类名：Font;<br>方法or属性：weight?: FontWeight \| number \| string;<br>新版本信息：?(FontWeight \| number \| string)|units.d.ts|
|type有变化|类名：Font;<br>方法or属性：family?: string \| Resource;<br>旧版本信息：|类名：Font;<br>方法or属性：family?: string \| Resource;<br>新版本信息：?(string \| Resource)|units.d.ts|
|type有变化|类名：Font;<br>方法or属性：style?: FontStyle;<br>旧版本信息：|类名：Font;<br>方法or属性：style?: FontStyle;<br>新版本信息：?FontStyle|units.d.ts|
|type有变化|类名：Area;<br>方法or属性：width: Length;<br>旧版本信息：|类名：Area;<br>方法or属性：width: Length;<br>新版本信息：Length|units.d.ts|
|type有变化|类名：Area;<br>方法or属性：height: Length;<br>旧版本信息：|类名：Area;<br>方法or属性：height: Length;<br>新版本信息：Length|units.d.ts|
|type有变化|类名：Area;<br>方法or属性：position: Position;<br>旧版本信息：|类名：Area;<br>方法or属性：position: Position;<br>新版本信息：Position|units.d.ts|
|type有变化|类名：Area;<br>方法or属性：globalPosition: Position;<br>旧版本信息：|类名：Area;<br>方法or属性：globalPosition: Position;<br>新版本信息：Position|units.d.ts|
|type有变化|类名：Position;<br>方法or属性：x?: Length;<br>旧版本信息：|类名：Position;<br>方法or属性：x?: Length;<br>新版本信息：?Length|units.d.ts|
|type有变化|类名：Position;<br>方法or属性：y?: Length;<br>旧版本信息：|类名：Position;<br>方法or属性：y?: Length;<br>新版本信息：?Length|units.d.ts|
|type有变化|类名：ConstraintSizeOptions;<br>方法or属性：minWidth?: Length;<br>旧版本信息：|类名：ConstraintSizeOptions;<br>方法or属性：minWidth?: Length;<br>新版本信息：?Length|units.d.ts|
|type有变化|类名：ConstraintSizeOptions;<br>方法or属性：maxWidth?: Length;<br>旧版本信息：|类名：ConstraintSizeOptions;<br>方法or属性：maxWidth?: Length;<br>新版本信息：?Length|units.d.ts|
|type有变化|类名：ConstraintSizeOptions;<br>方法or属性：minHeight?: Length;<br>旧版本信息：|类名：ConstraintSizeOptions;<br>方法or属性：minHeight?: Length;<br>新版本信息：?Length|units.d.ts|
|type有变化|类名：ConstraintSizeOptions;<br>方法or属性：maxHeight?: Length;<br>旧版本信息：|类名：ConstraintSizeOptions;<br>方法or属性：maxHeight?: Length;<br>新版本信息：?Length|units.d.ts|
|type有变化|类名：SizeOptions;<br>方法or属性：width?: Length;<br>旧版本信息：|类名：SizeOptions;<br>方法or属性：width?: Length;<br>新版本信息：?Length|units.d.ts|
|type有变化|类名：SizeOptions;<br>方法or属性：height?: Length;<br>旧版本信息：|类名：SizeOptions;<br>方法or属性：height?: Length;<br>新版本信息：?Length|units.d.ts|
|type有变化|类名：BorderOptions;<br>方法or属性：width?: EdgeWidths \| Length;<br>旧版本信息：EdgeWidths \| Length|类名：BorderOptions;<br>方法or属性：width?: EdgeWidths \| Length;<br>新版本信息：?(EdgeWidths \| Length)|units.d.ts|
|type有变化|类名：BorderOptions;<br>方法or属性：color?: EdgeColors \| ResourceColor;<br>旧版本信息：EdgeColors \| ResourceColor|类名：BorderOptions;<br>方法or属性：color?: EdgeColors \| ResourceColor;<br>新版本信息：?(EdgeColors \| ResourceColor)|units.d.ts|
|type有变化|类名：BorderOptions;<br>方法or属性：radius?: BorderRadiuses \| Length;<br>旧版本信息：BorderRadiuses \| Length|类名：BorderOptions;<br>方法or属性：radius?: BorderRadiuses \| Length;<br>新版本信息：?(BorderRadiuses \| Length)|units.d.ts|
|type有变化|类名：BorderOptions;<br>方法or属性：style?: EdgeStyles \| BorderStyle;<br>旧版本信息：EdgeStyles \| BorderStyle|类名：BorderOptions;<br>方法or属性：style?: EdgeStyles \| BorderStyle;<br>新版本信息：?(EdgeStyles \| BorderStyle)|units.d.ts|
|type有变化|类名：MarkStyle;<br>方法or属性：strokeColor?: ResourceColor;<br>旧版本信息：ResourceColor|类名：MarkStyle;<br>方法or属性：strokeColor?: ResourceColor;<br>新版本信息：?ResourceColor|units.d.ts|
|type有变化|类名：MarkStyle;<br>方法or属性：strokeWidth?: Length;<br>旧版本信息：Length|类名：MarkStyle;<br>方法or属性：strokeWidth?: Length;<br>新版本信息：?Length|units.d.ts|
|type有变化|类名：VideoOptions;<br>方法or属性：src?: string \| Resource;<br>旧版本信息：|类名：VideoOptions;<br>方法or属性：src?: string \| Resource;<br>新版本信息：?(string \| Resource)|video.d.ts|
|type有变化|类名：VideoOptions;<br>方法or属性：currentProgressRate?: number \| string \| PlaybackSpeed;<br>旧版本信息：|类名：VideoOptions;<br>方法or属性：currentProgressRate?: number \| string \| PlaybackSpeed;<br>新版本信息：?(number \| string \| PlaybackSpeed)|video.d.ts|
|type有变化|类名：VideoOptions;<br>方法or属性：previewUri?: string \| PixelMap \| Resource;<br>旧版本信息：|类名：VideoOptions;<br>方法or属性：previewUri?: string \| PixelMap \| Resource;<br>新版本信息：?(string \| PixelMap \| Resource)|video.d.ts|
|type有变化|类名：VideoOptions;<br>方法or属性：controller?: VideoController;<br>旧版本信息：|类名：VideoOptions;<br>方法or属性：controller?: VideoController;<br>新版本信息：?VideoController|video.d.ts|
|type有变化|类名：WaterFlowOptions;<br>方法or属性：footer?: CustomBuilder;<br>旧版本信息：|类名：WaterFlowOptions;<br>方法or属性：footer?: CustomBuilder;<br>新版本信息：?CustomBuilder|water_flow.d.ts|
|type有变化|类名：WaterFlowOptions;<br>方法or属性：scroller?: Scroller;<br>旧版本信息：|类名：WaterFlowOptions;<br>方法or属性：scroller?: Scroller;<br>新版本信息：?Scroller|water_flow.d.ts|
|type有变化|类名：WebMediaOptions;<br>方法or属性：resumeInterval?: number;<br>旧版本信息：|类名：WebMediaOptions;<br>方法or属性：resumeInterval?: number;<br>新版本信息：?number|web.d.ts|
|type有变化|类名：WebMediaOptions;<br>方法or属性：audioExclusive?: boolean;<br>旧版本信息：|类名：WebMediaOptions;<br>方法or属性：audioExclusive?: boolean;<br>新版本信息：?boolean|web.d.ts|
|type有变化|类名：Header;<br>方法or属性：headerKey: string;<br>旧版本信息：|类名：Header;<br>方法or属性：headerKey: string;<br>新版本信息：string|web.d.ts|
|type有变化|类名：Header;<br>方法or属性：headerValue: string;<br>旧版本信息：|类名：Header;<br>方法or属性：headerValue: string;<br>新版本信息：string|web.d.ts|
|type有变化|类名：WebOptions;<br>方法or属性：src: string \| Resource;<br>旧版本信息：|类名：WebOptions;<br>方法or属性：src: string \| Resource;<br>新版本信息：string \| Resource|web.d.ts|
|type有变化|类名：WebOptions;<br>方法or属性：controller: WebController \| WebviewController;<br>旧版本信息：(WebController \| WebviewController)|类名：WebOptions;<br>方法or属性：controller: WebController \| WebviewController;<br>新版本信息：WebController \| WebviewController|web.d.ts|
|type有变化|类名：WebAttribute;<br>方法or属性：javaScriptProxy(javaScriptProxy: { object: object, name: string, methodList: Array\<string>,<br>    controller: WebController \| WebviewController }): WebAttribute;<br>旧版本信息：controller : WebController \| WebviewController|类名：WebAttribute;<br>方法or属性：javaScriptProxy(javaScriptProxy: { object: object, name: string, methodList: Array\<string>,<br>    controller: WebController \| WebviewController }): WebAttribute;<br>新版本信息：|web.d.ts|
|函数有变化|类名：FontOptions;<br>方法or属性：familyName: string;|类名：FontOptions;<br>方法or属性：familyName: string \| Resource;|@ohos.font.d.ts|
|函数有变化|类名：FontOptions;<br>方法or属性：familySrc: string;|类名：FontOptions;<br>方法or属性：familySrc: string \| Resource;|@ohos.font.d.ts|
|卡片应用支持性有变化|类名：ClickEvent;<br>方法or属性：screenX: number;<br>旧版本信息：form|类名：ClickEvent;<br>方法or属性：screenX: number;<br>新版本信息：|common.d.ts|
|卡片应用支持性有变化|类名：ClickEvent;<br>方法or属性：screenY: number;<br>旧版本信息：form|类名：ClickEvent;<br>方法or属性：screenY: number;<br>新版本信息：|common.d.ts|
|卡片应用支持性有变化|类名：TextAttribute;<br>方法or属性：textShadow(value: ShadowOptions): TextAttribute;<br>旧版本信息：|类名：TextAttribute;<br>方法or属性：textShadow(value: ShadowOptions): TextAttribute;<br>新版本信息：form|text.d.ts|
