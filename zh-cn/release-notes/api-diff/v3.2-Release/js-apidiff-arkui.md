| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：CanvasPattern;<br>方法or属性：setTransform(transform?: Matrix2D): void;|canvaspattern.d.ts|
|新增|NA|类名：Matrix2D;<br>方法or属性：scaleX?: number;|canvaspattern.d.ts|
|新增|NA|类名：Matrix2D;<br>方法or属性：rotateY?: number;|canvaspattern.d.ts|
|新增|NA|类名：Matrix2D;<br>方法or属性：rotateX?: number;|canvaspattern.d.ts|
|新增|NA|类名：Matrix2D;<br>方法or属性：scaleY?: number;|canvaspattern.d.ts|
|新增|NA|类名：Matrix2D;<br>方法or属性：translateX?: number;|canvaspattern.d.ts|
|新增|NA|类名：Matrix2D;<br>方法or属性：translateY?: number;|canvaspattern.d.ts|
|新增|NA|类名：Matrix2D;<br>方法or属性：identity(): Matrix2D;|canvaspattern.d.ts|
|新增|NA|类名：Matrix2D;<br>方法or属性：invert(): Matrix2D;|canvaspattern.d.ts|
|新增|NA|类名：Matrix2D;<br>方法or属性：multiply(other?: Matrix2D): Matrix2D;|canvaspattern.d.ts|
|新增|NA|类名：Matrix2D;<br>方法or属性：rotate(rx?: number, ry?: number): Matrix2D;|canvaspattern.d.ts|
|新增|NA|类名：Matrix2D;<br>方法or属性：translate(tx?: number, ty?: number): Matrix2D;|canvaspattern.d.ts|
|新增|NA|类名：Matrix2D;<br>方法or属性：scale(sx?: number, sy?: number): Matrix2D;|canvaspattern.d.ts|
|新增|NA|类名：Matrix2D;<br>方法or属性：constructor();|canvaspattern.d.ts|
|新增|NA|类名：AnimatorResult;<br>方法or属性：reset(options: AnimatorOptions): void;|@ohos.animator.d.ts|
|新增|NA|类名：Animator;<br>方法or属性：static create(options: AnimatorOptions): AnimatorResult;|@ohos.animator.d.ts|
|新增|NA|类名：curves;<br>方法or属性：function initCurve(curve?: Curve): ICurve;|@ohos.curves.d.ts|
|新增|NA|类名：curves;<br>方法or属性：function stepsCurve(count: number, end: boolean): ICurve;|@ohos.curves.d.ts|
|新增|NA|类名：curves;<br>方法or属性：function cubicBezierCurve(x1: number, y1: number, x2: number, y2: number): ICurve;|@ohos.curves.d.ts|
|新增|NA|类名：curves;<br>方法or属性：function springCurve(velocity: number, mass: number, stiffness: number, damping: number): ICurve;|@ohos.curves.d.ts|
|新增|NA|类名：curves;<br>方法or属性：function springMotion(response?: number, dampingFraction?: number, overlapDuration?: number): ICurve;|@ohos.curves.d.ts|
|新增|NA|类名：curves;<br>方法or属性：function responsiveSpringMotion(response?: number, dampingFraction?: number, overlapDuration?: number): ICurve;|@ohos.curves.d.ts|
|新增|NA|类名：ICurve;<br>方法or属性：interpolate(fraction : number) : number;|@ohos.curves.d.ts|
|新增|NA|类名：font;<br>方法or属性：function registerFont(options: FontOptions):void;|@ohos.font.d.ts|
|新增|NA|类名：FontOptions;<br>方法or属性：familyName: string;|@ohos.font.d.ts|
|新增|NA|类名：FontOptions;<br>方法or属性：familySrc: string;|@ohos.font.d.ts|
|新增|NA|类名：MeasureOptions;<br>方法or属性：textContent: string;|@ohos.measure.d.ts|
|新增|NA|类名：MeasureOptions;<br>方法or属性：fontSize?: number \| string \| Resource;|@ohos.measure.d.ts|
|新增|NA|类名：MeasureOptions;<br>方法or属性：fontStyle?: number \| FontStyle;|@ohos.measure.d.ts|
|新增|NA|类名：MeasureOptions;<br>方法or属性：fontWeight?: number \| string \| FontWeight;|@ohos.measure.d.ts|
|新增|NA|类名：MeasureOptions;<br>方法or属性：fontFamily?: string \| Resource;|@ohos.measure.d.ts|
|新增|NA|类名：MeasureOptions;<br>方法or属性：letterSpacing?: number \| string;|@ohos.measure.d.ts|
|新增|NA|类名：MeasureText;<br>方法or属性：static measureText(options: MeasureOptions): number;|@ohos.measure.d.ts|
|新增|NA|类名：pluginComponentManager;<br>方法or属性：function push(param: PushParameterForStage, callback: AsyncCallback\<void>): void;|@ohos.pluginComponent.d.ts|
|新增|NA|类名：pluginComponentManager;<br>方法or属性：function request(param: RequestParameterForStage, callback: AsyncCallback\<RequestCallbackParameters>): void;|@ohos.pluginComponent.d.ts|
|新增|NA|类名：PushParameterForStage;<br>方法or属性：owner: Want;|@ohos.pluginComponent.d.ts|
|新增|NA|类名：RequestParameterForStage;<br>方法or属性：owner: Want;|@ohos.pluginComponent.d.ts|
|新增|NA|类名：PushParameterForStage;<br>方法or属性：target: Want;|@ohos.pluginComponent.d.ts|
|新增|NA|类名：RequestParameterForStage;<br>方法or属性：target: Want;|@ohos.pluginComponent.d.ts|
|新增|NA|类名：PushParameterForStage;<br>方法or属性：name: string;|@ohos.pluginComponent.d.ts|
|新增|NA|类名：RequestParameterForStage;<br>方法or属性：name: string;|@ohos.pluginComponent.d.ts|
|新增|NA|类名：PushParameterForStage;<br>方法or属性：data: KVObject;|@ohos.pluginComponent.d.ts|
|新增|NA|类名：RequestParameterForStage;<br>方法or属性：data: KVObject;|@ohos.pluginComponent.d.ts|
|新增|NA|类名：PushParameterForStage;<br>方法or属性：extraData: KVObject;|@ohos.pluginComponent.d.ts|
|新增|NA|类名：PushParameterForStage;<br>方法or属性：jsonPath?: string;|@ohos.pluginComponent.d.ts|
|新增|NA|类名：RequestParameterForStage;<br>方法or属性：jsonPath?: string;|@ohos.pluginComponent.d.ts|
|新增|NA|类名：promptAction;<br>方法or属性：function showToast(options: ShowToastOptions):void;|@ohos.promptAction.d.ts|
|新增|NA|类名：promptAction;<br>方法or属性：function showDialog(options: ShowDialogOptions, callback: AsyncCallback\<ShowDialogSuccessResponse>):void;|@ohos.promptAction.d.ts|
|新增|NA|类名：promptAction;<br>方法or属性：function showDialog(options: ShowDialogOptions): Promise\<ShowDialogSuccessResponse>;|@ohos.promptAction.d.ts|
|新增|NA|类名：promptAction;<br>方法or属性：function showActionMenu(options: ActionMenuOptions, callback: AsyncCallback\<ActionMenuSuccessResponse>):void;|@ohos.promptAction.d.ts|
|新增|NA|类名：promptAction;<br>方法or属性：function showActionMenu(options: ActionMenuOptions): Promise\<ActionMenuSuccessResponse>;|@ohos.promptAction.d.ts|
|新增|NA|类名：ShowToastOptions;<br>方法or属性：message: string \| Resource;|@ohos.promptAction.d.ts|
|新增|NA|类名：ShowToastOptions;<br>方法or属性：duration?: number;|@ohos.promptAction.d.ts|
|新增|NA|类名：ShowToastOptions;<br>方法or属性：bottom?: string \| number;|@ohos.promptAction.d.ts|
|新增|NA|类名：Button;<br>方法or属性：text: string \| Resource;|@ohos.promptAction.d.ts|
|新增|NA|类名：Button;<br>方法or属性：color: string \| Resource;|@ohos.promptAction.d.ts|
|新增|NA|类名：ShowDialogSuccessResponse;<br>方法or属性：index: number;|@ohos.promptAction.d.ts|
|新增|NA|类名：ActionMenuSuccessResponse;<br>方法or属性：index: number;|@ohos.promptAction.d.ts|
|新增|NA|类名：ShowDialogOptions;<br>方法or属性：title?: string \| Resource;|@ohos.promptAction.d.ts|
|新增|NA|类名：ActionMenuOptions;<br>方法or属性：title?: string \| Resource;|@ohos.promptAction.d.ts|
|新增|NA|类名：ShowDialogOptions;<br>方法or属性：message?: string \| Resource;|@ohos.promptAction.d.ts|
|新增|NA|类名：ShowDialogOptions;<br>方法or属性：buttons?: [Button, Button?, Button?];|@ohos.promptAction.d.ts|
|新增|NA|类名：ActionMenuOptions;<br>方法or属性：buttons: [Button, Button?, Button?, Button?, Button?, Button?];|@ohos.promptAction.d.ts|
|新增|NA|类名：router;<br>方法or属性：function pushUrl(options: RouterOptions, callback: AsyncCallback\<void>):void;|@ohos.router.d.ts|
|新增|NA|类名：router;<br>方法or属性：function pushUrl(options: RouterOptions): Promise\<void>;|@ohos.router.d.ts|
|新增|NA|类名：router;<br>方法or属性：function pushUrl(options: RouterOptions, mode: RouterMode, callback: AsyncCallback\<void>):void;|@ohos.router.d.ts|
|新增|NA|类名：router;<br>方法or属性：function pushUrl(options: RouterOptions, mode: RouterMode): Promise\<void>;|@ohos.router.d.ts|
|新增|NA|类名：router;<br>方法or属性：function replaceUrl(options: RouterOptions, callback: AsyncCallback\<void>):void;|@ohos.router.d.ts|
|新增|NA|类名：router;<br>方法or属性：function replaceUrl(options: RouterOptions): Promise\<void>;|@ohos.router.d.ts|
|新增|NA|类名：router;<br>方法or属性：function replaceUrl(options: RouterOptions, mode: RouterMode, callback: AsyncCallback\<void>):void;|@ohos.router.d.ts|
|新增|NA|类名：router;<br>方法or属性：function replaceUrl(options: RouterOptions, mode: RouterMode): Promise\<void>;|@ohos.router.d.ts|
|新增|NA|类名：router;<br>方法or属性：function showAlertBeforeBackPage(options: EnableAlertOptions):void;|@ohos.router.d.ts|
|新增|NA|类名：router;<br>方法or属性：function hideAlertBeforeBackPage():void;|@ohos.router.d.ts|
|新增|NA|类名：RouterMode;<br>方法or属性：Standard|@ohos.router.d.ts|
|新增|NA|类名：RouterMode;<br>方法or属性：Single|@ohos.router.d.ts|
|废弃版本有变化|类名：AnimatorResult;<br>方法or属性：update(options: AnimatorOptions): void;<br>旧版本信息：|类名：AnimatorResult;<br>方法or属性：update(options: AnimatorOptions): void;<br>新版本信息：9<br>代替接口： ohos.animator.reset|@ohos.animator.d.ts|
|废弃版本有变化|类名：Animator;<br>方法or属性：static createAnimator(options: AnimatorOptions): AnimatorResult;<br>旧版本信息：|类名：Animator;<br>方法or属性：static createAnimator(options: AnimatorOptions): AnimatorResult;<br>新版本信息：9<br>代替接口： ohos.animator.create|@ohos.animator.d.ts|
|废弃版本有变化|类名：curves;<br>方法or属性：function init(curve?: Curve): string;<br>旧版本信息：|类名：curves;<br>方法or属性：function init(curve?: Curve): string;<br>新版本信息：9<br>代替接口： initCurve|@ohos.curves.d.ts|
|废弃版本有变化|类名：curves;<br>方法or属性：function steps(count: number, end: boolean): string;<br>旧版本信息：|类名：curves;<br>方法or属性：function steps(count: number, end: boolean): string;<br>新版本信息：9<br>代替接口： stepsCurve|@ohos.curves.d.ts|
|废弃版本有变化|类名：curves;<br>方法or属性：function cubicBezier(x1: number, y1: number, x2: number, y2: number): string;<br>旧版本信息：|类名：curves;<br>方法or属性：function cubicBezier(x1: number, y1: number, x2: number, y2: number): string;<br>新版本信息：9<br>代替接口： cubicBezierCurve|@ohos.curves.d.ts|
|废弃版本有变化|类名：curves;<br>方法or属性：function spring(velocity: number, mass: number, stiffness: number, damping: number): string;<br>旧版本信息：|类名：curves;<br>方法or属性：function spring(velocity: number, mass: number, stiffness: number, damping: number): string;<br>新版本信息：9<br>代替接口： springCurve|@ohos.curves.d.ts|
|废弃版本有变化|类名：prompt;<br>方法or属性：declare prompt<br>旧版本信息：|类名：prompt;<br>方法or属性：declare prompt<br>新版本信息：9<br>代替接口： ohos.promptAction|@ohos.prompt.d.ts|
|废弃版本有变化|类名：prompt;<br>方法or属性：function showToast(options: ShowToastOptions):void;<br>旧版本信息：|类名：prompt;<br>方法or属性：function showToast(options: ShowToastOptions):void;<br>新版本信息：9<br>代替接口： ohos.promptAction|@ohos.prompt.d.ts|
|废弃版本有变化|类名：prompt;<br>方法or属性：function showDialog(options: ShowDialogOptions, callback: AsyncCallback\<ShowDialogSuccessResponse>):void;<br>旧版本信息：|类名：prompt;<br>方法or属性：function showDialog(options: ShowDialogOptions, callback: AsyncCallback\<ShowDialogSuccessResponse>):void;<br>新版本信息：9<br>代替接口： ohos.promptAction|@ohos.prompt.d.ts|
|废弃版本有变化|类名：prompt;<br>方法or属性：function showDialog(options: ShowDialogOptions): Promise\<ShowDialogSuccessResponse>;<br>旧版本信息：|类名：prompt;<br>方法or属性：function showDialog(options: ShowDialogOptions): Promise\<ShowDialogSuccessResponse>;<br>新版本信息：9<br>代替接口： ohos.promptAction|@ohos.prompt.d.ts|
|废弃版本有变化|类名：prompt;<br>方法or属性：function showActionMenu(options: ActionMenuOptions, callback: AsyncCallback\<ActionMenuSuccessResponse>):void;<br>旧版本信息：|类名：prompt;<br>方法or属性：function showActionMenu(options: ActionMenuOptions, callback: AsyncCallback\<ActionMenuSuccessResponse>):void;<br>新版本信息：9<br>代替接口： ohos.promptAction|@ohos.prompt.d.ts|
|废弃版本有变化|类名：prompt;<br>方法or属性：function showActionMenu(options: ActionMenuOptions): Promise\<ActionMenuSuccessResponse>;<br>旧版本信息：|类名：prompt;<br>方法or属性：function showActionMenu(options: ActionMenuOptions): Promise\<ActionMenuSuccessResponse>;<br>新版本信息：9<br>代替接口： ohos.promptAction|@ohos.prompt.d.ts|
|废弃版本有变化|类名：ShowToastOptions;<br>方法or属性：interface ShowToastOptions<br>旧版本信息：|类名：ShowToastOptions;<br>方法or属性：interface ShowToastOptions<br>新版本信息：9<br>代替接口： ohos.promptAction|@ohos.prompt.d.ts|
|废弃版本有变化|类名：ShowToastOptions;<br>方法or属性：message: string;<br>旧版本信息：|类名：ShowToastOptions;<br>方法or属性：message: string;<br>新版本信息：9<br>代替接口： ohos.promptAction|@ohos.prompt.d.ts|
|废弃版本有变化|类名：ShowToastOptions;<br>方法or属性：duration?: number;<br>旧版本信息：|类名：ShowToastOptions;<br>方法or属性：duration?: number;<br>新版本信息：9<br>代替接口： ohos.promptAction|@ohos.prompt.d.ts|
|废弃版本有变化|类名：ShowToastOptions;<br>方法or属性：bottom?: string \| number;<br>旧版本信息：|类名：ShowToastOptions;<br>方法or属性：bottom?: string \| number;<br>新版本信息：9<br>代替接口： ohos.promptAction|@ohos.prompt.d.ts|
|废弃版本有变化|类名：Button;<br>方法or属性：interface Button<br>旧版本信息：|类名：Button;<br>方法or属性：interface Button<br>新版本信息：9<br>代替接口： ohos.promptAction|@ohos.prompt.d.ts|
|废弃版本有变化|类名：Button;<br>方法or属性：text: string;<br>旧版本信息：|类名：Button;<br>方法or属性：text: string;<br>新版本信息：9<br>代替接口： ohos.promptAction|@ohos.prompt.d.ts|
|废弃版本有变化|类名：Button;<br>方法or属性：color: string;<br>旧版本信息：|类名：Button;<br>方法or属性：color: string;<br>新版本信息：9<br>代替接口： ohos.promptAction|@ohos.prompt.d.ts|
|废弃版本有变化|类名：ShowDialogSuccessResponse;<br>方法or属性：interface ShowDialogSuccessResponse<br>旧版本信息：|类名：ShowDialogSuccessResponse;<br>方法or属性：interface ShowDialogSuccessResponse<br>新版本信息：9<br>代替接口： ohos.promptAction|@ohos.prompt.d.ts|
|废弃版本有变化|类名：ShowDialogSuccessResponse;<br>方法or属性：index: number;<br>旧版本信息：|类名：ShowDialogSuccessResponse;<br>方法or属性：index: number;<br>新版本信息：9<br>代替接口： ohos.promptAction|@ohos.prompt.d.ts|
|废弃版本有变化|类名：ActionMenuSuccessResponse;<br>方法or属性：index: number;<br>旧版本信息：|类名：ActionMenuSuccessResponse;<br>方法or属性：index: number;<br>新版本信息：9<br>代替接口： ohos.promptAction|@ohos.prompt.d.ts|
|废弃版本有变化|类名：ShowDialogOptions;<br>方法or属性：interface ShowDialogOptions<br>旧版本信息：|类名：ShowDialogOptions;<br>方法or属性：interface ShowDialogOptions<br>新版本信息：9<br>代替接口： ohos.promptAction|@ohos.prompt.d.ts|
|废弃版本有变化|类名：ShowDialogOptions;<br>方法or属性：title?: string;<br>旧版本信息：|类名：ShowDialogOptions;<br>方法or属性：title?: string;<br>新版本信息：9<br>代替接口： ohos.promptAction|@ohos.prompt.d.ts|
|废弃版本有变化|类名：ActionMenuOptions;<br>方法or属性：title?: string;<br>旧版本信息：|类名：ActionMenuOptions;<br>方法or属性：title?: string;<br>新版本信息：9<br>代替接口： ohos.promptAction|@ohos.prompt.d.ts|
|废弃版本有变化|类名：ShowDialogOptions;<br>方法or属性：message?: string;<br>旧版本信息：|类名：ShowDialogOptions;<br>方法or属性：message?: string;<br>新版本信息：9<br>代替接口： ohos.promptAction|@ohos.prompt.d.ts|
|废弃版本有变化|类名：ShowDialogOptions;<br>方法or属性：buttons?: [Button, Button?, Button?];<br>旧版本信息：|类名：ShowDialogOptions;<br>方法or属性：buttons?: [Button, Button?, Button?];<br>新版本信息：9<br>代替接口： ohos.promptAction|@ohos.prompt.d.ts|
|废弃版本有变化|类名：ActionMenuSuccessResponse;<br>方法or属性：interface ActionMenuSuccessResponse<br>旧版本信息：|类名：ActionMenuSuccessResponse;<br>方法or属性：interface ActionMenuSuccessResponse<br>新版本信息：9<br>代替接口： ohos.promptAction|@ohos.prompt.d.ts|
|废弃版本有变化|类名：ActionMenuOptions;<br>方法or属性：interface ActionMenuOptions<br>旧版本信息：|类名：ActionMenuOptions;<br>方法or属性：interface ActionMenuOptions<br>新版本信息：9<br>代替接口： ohos.promptAction|@ohos.prompt.d.ts|
|废弃版本有变化|类名：ActionMenuOptions;<br>方法or属性：buttons: [Button, Button?, Button?, Button?, Button?, Button?];<br>旧版本信息：|类名：ActionMenuOptions;<br>方法or属性：buttons: [Button, Button?, Button?, Button?, Button?, Button?];<br>新版本信息：9<br>代替接口： ohos.promptAction|@ohos.prompt.d.ts|
|废弃版本有变化|类名：router;<br>方法or属性：function push(options: RouterOptions):void;<br>旧版本信息：|类名：router;<br>方法or属性：function push(options: RouterOptions):void;<br>新版本信息：9<br>代替接口： ohos.router.router#pushUrl|@ohos.router.d.ts|
|废弃版本有变化|类名：router;<br>方法or属性：function replace(options: RouterOptions):void;<br>旧版本信息：|类名：router;<br>方法or属性：function replace(options: RouterOptions):void;<br>新版本信息：9<br>代替接口： ohos.router.router#replaceUrl|@ohos.router.d.ts|
|废弃版本有变化|类名：router;<br>方法or属性：function enableAlertBeforeBackPage(options: EnableAlertOptions):void;<br>旧版本信息：|类名：router;<br>方法or属性：function enableAlertBeforeBackPage(options: EnableAlertOptions):void;<br>新版本信息：9<br>代替接口： ohos.router.router#showAlertBeforeBackPage|@ohos.router.d.ts|
|废弃版本有变化|类名：router;<br>方法or属性：function disableAlertBeforeBackPage():void;<br>旧版本信息：|类名：router;<br>方法or属性：function disableAlertBeforeBackPage():void;<br>新版本信息：9<br>代替接口： ohos.router.router#hideAlertBeforeBackPage|@ohos.router.d.ts|
|废弃版本有变化|类名：RouterOptions;<br>方法or属性：export interface RouterOptions<br>旧版本信息：8, please use @ohos.router instead.|类名：RouterOptions;<br>方法or属性：export interface RouterOptions<br>新版本信息：8<br>代替接口： @ohos.router|@system.router.d.ts|
|废弃版本有变化|类名：RouterOptions;<br>方法or属性：uri: string;<br>旧版本信息：8, please use @ohos.router instead.|类名：RouterOptions;<br>方法or属性：uri: string;<br>新版本信息：8<br>代替接口： @ohos.router|@system.router.d.ts|
|废弃版本有变化|类名：RouterOptions;<br>方法or属性：params?: Object;<br>旧版本信息：8, please use @ohos.router instead.|类名：RouterOptions;<br>方法or属性：params?: Object;<br>新版本信息：8<br>代替接口： @ohos.router|@system.router.d.ts|
|废弃版本有变化|类名：BackRouterOptions;<br>方法or属性：params?: Object;<br>旧版本信息：8, please use @ohos.router instead.|类名：BackRouterOptions;<br>方法or属性：params?: Object;<br>新版本信息：8<br>代替接口： @ohos.router|@system.router.d.ts|
|废弃版本有变化|类名：BackRouterOptions;<br>方法or属性：export interface BackRouterOptions<br>旧版本信息：8, please use @ohos.router instead.|类名：BackRouterOptions;<br>方法or属性：export interface BackRouterOptions<br>新版本信息：8<br>代替接口： @ohos.router|@system.router.d.ts|
|废弃版本有变化|类名：BackRouterOptions;<br>方法or属性：uri?: string;<br>旧版本信息：8, please use @ohos.router instead.|类名：BackRouterOptions;<br>方法or属性：uri?: string;<br>新版本信息：8<br>代替接口： @ohos.router|@system.router.d.ts|
|废弃版本有变化|类名：RouterState;<br>方法or属性：export interface RouterState<br>旧版本信息：8, please use @ohos.router instead.|类名：RouterState;<br>方法or属性：export interface RouterState<br>新版本信息：8<br>代替接口： @ohos.router|@system.router.d.ts|
|废弃版本有变化|类名：RouterState;<br>方法or属性：index: number;<br>旧版本信息：8, please use @ohos.router instead.|类名：RouterState;<br>方法or属性：index: number;<br>新版本信息：8<br>代替接口： @ohos.router|@system.router.d.ts|
|废弃版本有变化|类名：RouterState;<br>方法or属性：name: string;<br>旧版本信息：8, please use @ohos.router instead.|类名：RouterState;<br>方法or属性：name: string;<br>新版本信息：8<br>代替接口： @ohos.router|@system.router.d.ts|
|废弃版本有变化|类名：RouterState;<br>方法or属性：path: string;<br>旧版本信息：8, please use @ohos.router instead.|类名：RouterState;<br>方法or属性：path: string;<br>新版本信息：8<br>代替接口： @ohos.router|@system.router.d.ts|
|废弃版本有变化|类名：EnableAlertBeforeBackPageOptions;<br>方法or属性：export interface EnableAlertBeforeBackPageOptions<br>旧版本信息：8, please use @ohos.router instead.|类名：EnableAlertBeforeBackPageOptions;<br>方法or属性：export interface EnableAlertBeforeBackPageOptions<br>新版本信息：8<br>代替接口： @ohos.router|@system.router.d.ts|
|废弃版本有变化|类名：EnableAlertBeforeBackPageOptions;<br>方法or属性：message: string;<br>旧版本信息：8, please use @ohos.router instead.|类名：EnableAlertBeforeBackPageOptions;<br>方法or属性：message: string;<br>新版本信息：8<br>代替接口： @ohos.router|@system.router.d.ts|
|废弃版本有变化|类名：EnableAlertBeforeBackPageOptions;<br>方法or属性：success?: (errMsg: string) => void;<br>旧版本信息：8, please use @ohos.router instead.|类名：EnableAlertBeforeBackPageOptions;<br>方法or属性：success?: (errMsg: string) => void;<br>新版本信息：8<br>代替接口： @ohos.router|@system.router.d.ts|
|废弃版本有变化|类名：DisableAlertBeforeBackPageOptions;<br>方法or属性：success?: (errMsg: string) => void;<br>旧版本信息：8, please use @ohos.router instead.|类名：DisableAlertBeforeBackPageOptions;<br>方法or属性：success?: (errMsg: string) => void;<br>新版本信息：8<br>代替接口： @ohos.router|@system.router.d.ts|
|废弃版本有变化|类名：EnableAlertBeforeBackPageOptions;<br>方法or属性：cancel?: (errMsg: string) => void;<br>旧版本信息：8, please use @ohos.router instead.|类名：EnableAlertBeforeBackPageOptions;<br>方法or属性：cancel?: (errMsg: string) => void;<br>新版本信息：8<br>代替接口： @ohos.router|@system.router.d.ts|
|废弃版本有变化|类名：DisableAlertBeforeBackPageOptions;<br>方法or属性：cancel?: (errMsg: string) => void;<br>旧版本信息：8, please use @ohos.router instead.|类名：DisableAlertBeforeBackPageOptions;<br>方法or属性：cancel?: (errMsg: string) => void;<br>新版本信息：8<br>代替接口： @ohos.router|@system.router.d.ts|
|废弃版本有变化|类名：EnableAlertBeforeBackPageOptions;<br>方法or属性：complete?: () => void;<br>旧版本信息：8, please use @ohos.router instead.|类名：EnableAlertBeforeBackPageOptions;<br>方法or属性：complete?: () => void;<br>新版本信息：8<br>代替接口： @ohos.router|@system.router.d.ts|
|废弃版本有变化|类名：DisableAlertBeforeBackPageOptions;<br>方法or属性：complete?: () => void;<br>旧版本信息：8, please use @ohos.router instead.|类名：DisableAlertBeforeBackPageOptions;<br>方法or属性：complete?: () => void;<br>新版本信息：8<br>代替接口： @ohos.router|@system.router.d.ts|
|废弃版本有变化|类名：DisableAlertBeforeBackPageOptions;<br>方法or属性：export interface DisableAlertBeforeBackPageOptions<br>旧版本信息：8, please use @ohos.router instead.|类名：DisableAlertBeforeBackPageOptions;<br>方法or属性：export interface DisableAlertBeforeBackPageOptions<br>新版本信息：8<br>代替接口： @ohos.router|@system.router.d.ts|
|废弃版本有变化|类名：Router;<br>方法or属性：export default class Router<br>旧版本信息：8, please use @ohos.router instead.|类名：Router;<br>方法or属性：export default class Router<br>新版本信息：8<br>代替接口： @ohos.router|@system.router.d.ts|
|废弃版本有变化|类名：Router;<br>方法or属性：static push(options: RouterOptions): void;<br>旧版本信息：8, please use @ohos.router instead.|类名：Router;<br>方法or属性：static push(options: RouterOptions): void;<br>新版本信息：8<br>代替接口： @ohos.router|@system.router.d.ts|
|废弃版本有变化|类名：Router;<br>方法or属性：static replace(options: RouterOptions): void;<br>旧版本信息：8, please use @ohos.router instead.|类名：Router;<br>方法or属性：static replace(options: RouterOptions): void;<br>新版本信息：8<br>代替接口： @ohos.router|@system.router.d.ts|
|废弃版本有变化|类名：Router;<br>方法or属性：static back(options?: BackRouterOptions): void;<br>旧版本信息：8, please use @ohos.router instead.|类名：Router;<br>方法or属性：static back(options?: BackRouterOptions): void;<br>新版本信息：8<br>代替接口： @ohos.router|@system.router.d.ts|
|废弃版本有变化|类名：Router;<br>方法or属性：static getParams(): ParamsInterface;<br>旧版本信息：8, please use @ohos.router instead.|类名：Router;<br>方法or属性：static getParams(): ParamsInterface;<br>新版本信息：8<br>代替接口： @ohos.router|@system.router.d.ts|
|废弃版本有变化|类名：Router;<br>方法or属性：static clear(): void;<br>旧版本信息：8, please use @ohos.router instead.|类名：Router;<br>方法or属性：static clear(): void;<br>新版本信息：8<br>代替接口： @ohos.router|@system.router.d.ts|
|废弃版本有变化|类名：Router;<br>方法or属性：static getLength(): string;<br>旧版本信息：8, please use @ohos.router instead.|类名：Router;<br>方法or属性：static getLength(): string;<br>新版本信息：8<br>代替接口： @ohos.router|@system.router.d.ts|
|废弃版本有变化|类名：Router;<br>方法or属性：static getState(): RouterState;<br>旧版本信息：8, please use @ohos.router instead.|类名：Router;<br>方法or属性：static getState(): RouterState;<br>新版本信息：8<br>代替接口： @ohos.router|@system.router.d.ts|
|废弃版本有变化|类名：Router;<br>方法or属性：static enableAlertBeforeBackPage(options: EnableAlertBeforeBackPageOptions): void;<br>旧版本信息：8, please use @ohos.router instead.|类名：Router;<br>方法or属性：static enableAlertBeforeBackPage(options: EnableAlertBeforeBackPageOptions): void;<br>新版本信息：8<br>代替接口： @ohos.router|@system.router.d.ts|
|废弃版本有变化|类名：Router;<br>方法or属性：static disableAlertBeforeBackPage(options?: DisableAlertBeforeBackPageOptions): void;<br>旧版本信息：8, please use @ohos.router instead.|类名：Router;<br>方法or属性：static disableAlertBeforeBackPage(options?: DisableAlertBeforeBackPageOptions): void;<br>新版本信息：8<br>代替接口： @ohos.router|@system.router.d.ts|
|废弃版本有变化|类名：CommonMethod;<br>方法or属性：touchable(value: boolean): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：touchable(value: boolean): T;<br>新版本信息：9<br>代替接口： hitTestBehavior|common.d.ts|
|访问级别有变化|类名：sourcefile;<br>方法or属性：export declare function getInspectorByKey(id: string): string;<br>旧版本信息：systemapi|类名：sourcefile;<br>方法or属性：export declare function getInspectorByKey(id: string): string;<br>新版本信息：|global.d.ts|
|访问级别有变化|类名：sourcefile;<br>方法or属性：export declare function getInspectorTree(): Object;<br>旧版本信息：systemapi|类名：sourcefile;<br>方法or属性：export declare function getInspectorTree(): Object;<br>新版本信息：|global.d.ts|
|访问级别有变化|类名：sourcefile;<br>方法or属性：export declare function sendEventByKey(id: string, action: number, params: string): boolean;<br>旧版本信息：systemapi|类名：sourcefile;<br>方法or属性：export declare function sendEventByKey(id: string, action: number, params: string): boolean;<br>新版本信息：|global.d.ts|
|访问级别有变化|类名：sourcefile;<br>方法or属性：export declare function sendTouchEvent(event: TouchObject): boolean;<br>旧版本信息：systemapi|类名：sourcefile;<br>方法or属性：export declare function sendTouchEvent(event: TouchObject): boolean;<br>新版本信息：|global.d.ts|
|访问级别有变化|类名：sourcefile;<br>方法or属性：export declare function sendKeyEvent(event: KeyEvent): boolean;<br>旧版本信息：systemapi|类名：sourcefile;<br>方法or属性：export declare function sendKeyEvent(event: KeyEvent): boolean;<br>新版本信息：|global.d.ts|
|访问级别有变化|类名：sourcefile;<br>方法or属性：export declare function sendMouseEvent(event: MouseEvent): boolean;<br>旧版本信息：systemapi|类名：sourcefile;<br>方法or属性：export declare function sendMouseEvent(event: MouseEvent): boolean;<br>新版本信息：|global.d.ts|
|访问级别有变化|类名：PreviewParams;<br>方法or属性：interface PreviewParams<br>旧版本信息：systemapi|类名：PreviewParams;<br>方法or属性：interface PreviewParams<br>新版本信息：|common.d.ts|
|访问级别有变化|类名：PreviewParams;<br>方法or属性：title?: string;<br>旧版本信息：systemapi|类名：PreviewParams;<br>方法or属性：title?: string;<br>新版本信息：|common.d.ts|
|访问级别有变化|类名：PreviewParams;<br>方法or属性：width?: number;<br>旧版本信息：systemapi|类名：PreviewParams;<br>方法or属性：width?: number;<br>新版本信息：|common.d.ts|
|访问级别有变化|类名：PreviewParams;<br>方法or属性：height?: number;<br>旧版本信息：systemapi|类名：PreviewParams;<br>方法or属性：height?: number;<br>新版本信息：|common.d.ts|
|访问级别有变化|类名：PreviewParams;<br>方法or属性：locale?: string;<br>旧版本信息：systemapi|类名：PreviewParams;<br>方法or属性：locale?: string;<br>新版本信息：|common.d.ts|
|访问级别有变化|类名：PreviewParams;<br>方法or属性：colorMode?: string;<br>旧版本信息：systemapi|类名：PreviewParams;<br>方法or属性：colorMode?: string;<br>新版本信息：|common.d.ts|
|访问级别有变化|类名：PreviewParams;<br>方法or属性：deviceType?: string;<br>旧版本信息：systemapi|类名：PreviewParams;<br>方法or属性：deviceType?: string;<br>新版本信息：|common.d.ts|
|访问级别有变化|类名：PreviewParams;<br>方法or属性：dpi?: number;<br>旧版本信息：systemapi|类名：PreviewParams;<br>方法or属性：dpi?: number;<br>新版本信息：|common.d.ts|
|访问级别有变化|类名：PreviewParams;<br>方法or属性：orientation?: string;<br>旧版本信息：systemapi|类名：PreviewParams;<br>方法or属性：orientation?: string;<br>新版本信息：|common.d.ts|
|访问级别有变化|类名：PreviewParams;<br>方法or属性：roundScreen?: boolean;<br>旧版本信息：systemapi|类名：PreviewParams;<br>方法or属性：roundScreen?: boolean;<br>新版本信息：|common.d.ts|
|访问级别有变化|类名：CommonShapeMethod;<br>方法or属性：constructor();<br>旧版本信息：|类名：CommonShapeMethod;<br>方法or属性：constructor();<br>新版本信息：systemapi|common.d.ts|
|type有变化|类名：AnimatorOptions;<br>方法or属性：duration: number;<br>旧版本信息：|类名：AnimatorOptions;<br>方法or属性：duration: number;<br>新版本信息：number|@ohos.animator.d.ts|
|type有变化|类名：AnimatorOptions;<br>方法or属性：easing: string;<br>旧版本信息：|类名：AnimatorOptions;<br>方法or属性：easing: string;<br>新版本信息：string|@ohos.animator.d.ts|
|type有变化|类名：AnimatorOptions;<br>方法or属性：delay: number;<br>旧版本信息：|类名：AnimatorOptions;<br>方法or属性：delay: number;<br>新版本信息：number|@ohos.animator.d.ts|
|type有变化|类名：AnimatorOptions;<br>方法or属性：fill: "none" \| "forwards" \| "backwards" \| "both";<br>旧版本信息：|类名：AnimatorOptions;<br>方法or属性：fill: "none" \| "forwards" \| "backwards" \| "both";<br>新版本信息：string|@ohos.animator.d.ts|
|type有变化|类名：AnimatorOptions;<br>方法or属性：direction: "normal" \| "reverse" \| "alternate" \| "alternate-reverse";<br>旧版本信息：|类名：AnimatorOptions;<br>方法or属性：direction: "normal" \| "reverse" \| "alternate" \| "alternate-reverse";<br>新版本信息：string|@ohos.animator.d.ts|
|type有变化|类名：AnimatorOptions;<br>方法or属性：iterations: number;<br>旧版本信息：|类名：AnimatorOptions;<br>方法or属性：iterations: number;<br>新版本信息：number|@ohos.animator.d.ts|
|type有变化|类名：AnimatorOptions;<br>方法or属性：begin: number;<br>旧版本信息：|类名：AnimatorOptions;<br>方法or属性：begin: number;<br>新版本信息：number|@ohos.animator.d.ts|
|type有变化|类名：AnimatorOptions;<br>方法or属性：end: number;<br>旧版本信息：|类名：AnimatorOptions;<br>方法or属性：end: number;<br>新版本信息：number|@ohos.animator.d.ts|
|type有变化|类名：ShowToastOptions;<br>方法or属性：message: string;<br>旧版本信息：|类名：ShowToastOptions;<br>方法or属性：message: string;<br>新版本信息：string|@ohos.prompt.d.ts|
|type有变化|类名：Button;<br>方法or属性：text: string;<br>旧版本信息：|类名：Button;<br>方法or属性：text: string;<br>新版本信息：string|@ohos.prompt.d.ts|
|type有变化|类名：Button;<br>方法or属性：color: string;<br>旧版本信息：|类名：Button;<br>方法or属性：color: string;<br>新版本信息：string|@ohos.prompt.d.ts|
|type有变化|类名：ShowDialogOptions;<br>方法or属性：title?: string;<br>旧版本信息：|类名：ShowDialogOptions;<br>方法or属性：title?: string;<br>新版本信息：string|@ohos.prompt.d.ts|
|type有变化|类名：ActionMenuOptions;<br>方法or属性：title?: string;<br>旧版本信息：|类名：ActionMenuOptions;<br>方法or属性：title?: string;<br>新版本信息：string|@ohos.prompt.d.ts|
|type有变化|类名：ShowDialogOptions;<br>方法or属性：message?: string;<br>旧版本信息：|类名：ShowDialogOptions;<br>方法or属性：message?: string;<br>新版本信息：string|@ohos.prompt.d.ts|
|type有变化|类名：RouterOptions;<br>方法or属性：url: string;<br>旧版本信息：|类名：RouterOptions;<br>方法or属性：url: string;<br>新版本信息：string|@ohos.router.d.ts|
|type有变化|类名：RouterOptions;<br>方法or属性：params?: Object;<br>旧版本信息：|类名：RouterOptions;<br>方法or属性：params?: Object;<br>新版本信息：Object|@ohos.router.d.ts|
|type有变化|类名：RouterState;<br>方法or属性：index: number;<br>旧版本信息：|类名：RouterState;<br>方法or属性：index: number;<br>新版本信息：number|@ohos.router.d.ts|
|type有变化|类名：RouterState;<br>方法or属性：name: string;<br>旧版本信息：|类名：RouterState;<br>方法or属性：name: string;<br>新版本信息：string|@ohos.router.d.ts|
|type有变化|类名：RouterState;<br>方法or属性：path: string;<br>旧版本信息：|类名：RouterState;<br>方法or属性：path: string;<br>新版本信息：string|@ohos.router.d.ts|
|type有变化|类名：EnableAlertOptions;<br>方法or属性：message: string;<br>旧版本信息：|类名：EnableAlertOptions;<br>方法or属性：message: string;<br>新版本信息：string|@ohos.router.d.ts|
|type有变化|类名：AnimateParam;<br>方法or属性：curve?: Curve \| string \| ICurve;<br>旧版本信息：|类名：AnimateParam;<br>方法or属性：curve?: Curve \| string \| ICurve;<br>新版本信息：string \| Curve \| ICurve|common.d.ts|
|函数有变化|类名：sourcefile;<br>方法or属性：export declare function getInspectorTree(): string;|类名：sourcefile;<br>方法or属性：export declare function getInspectorTree(): Object;|global.d.ts|
|卡片应用支持性有变化|类名：console;<br>方法or属性：export declare class console<br>旧版本信息：|类名：console;<br>方法or属性：export declare class console<br>新版本信息：form|global.d.ts|
|卡片应用支持性有变化|类名：console;<br>方法or属性：static debug(message: string, ...arguments: any[]): void;<br>旧版本信息：|类名：console;<br>方法or属性：static debug(message: string, ...arguments: any[]): void;<br>新版本信息：form|global.d.ts|
|卡片应用支持性有变化|类名：console;<br>方法or属性：static log(message: string, ...arguments: any[]): void;<br>旧版本信息：|类名：console;<br>方法or属性：static log(message: string, ...arguments: any[]): void;<br>新版本信息：form|global.d.ts|
|卡片应用支持性有变化|类名：console;<br>方法or属性：static info(message: string, ...arguments: any[]): void;<br>旧版本信息：|类名：console;<br>方法or属性：static info(message: string, ...arguments: any[]): void;<br>新版本信息：form|global.d.ts|
|卡片应用支持性有变化|类名：console;<br>方法or属性：static warn(message: string, ...arguments: any[]): void;<br>旧版本信息：|类名：console;<br>方法or属性：static warn(message: string, ...arguments: any[]): void;<br>新版本信息：form|global.d.ts|
|卡片应用支持性有变化|类名：console;<br>方法or属性：static error(message: string, ...arguments: any[]): void;<br>旧版本信息：|类名：console;<br>方法or属性：static error(message: string, ...arguments: any[]): void;<br>新版本信息：form|global.d.ts|
|卡片应用支持性有变化|类名：sourcefile;<br>方法or属性：declare function $r(value: string, ...params: any[]): Resource;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function $r(value: string, ...params: any[]): Resource;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：sourcefile;<br>方法or属性：declare function $rawfile(value: string): Resource;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function $rawfile(value: string): Resource;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：sourcefile;<br>方法or属性：declare function animateTo(value: AnimateParam, event: () => void): void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function animateTo(value: AnimateParam, event: () => void): void;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：sourcefile;<br>方法or属性：declare function vp2px(value: number): number;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function vp2px(value: number): number;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：sourcefile;<br>方法or属性：declare function px2vp(value: number): number;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function px2vp(value: number): number;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：sourcefile;<br>方法or属性：declare function fp2px(value: number): number;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function fp2px(value: number): number;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：sourcefile;<br>方法or属性：declare function px2fp(value: number): number;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function px2fp(value: number): number;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：sourcefile;<br>方法or属性：declare function lpx2px(value: number): number;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function lpx2px(value: number): number;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：sourcefile;<br>方法or属性：declare function px2lpx(value: number): number;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare function px2lpx(value: number): number;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：sourcefile;<br>方法or属性：declare type CustomBuilder = (() => any) \| void;<br>旧版本信息：|类名：sourcefile;<br>方法or属性：declare type CustomBuilder = (() => any) \| void;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：Configuration;<br>方法or属性：declare interface Configuration<br>旧版本信息：|类名：Configuration;<br>方法or属性：declare interface Configuration<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：Configuration;<br>方法or属性：readonly colorMode: string;<br>旧版本信息：|类名：Configuration;<br>方法or属性：readonly colorMode: string;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：Configuration;<br>方法or属性：readonly fontScale: number;<br>旧版本信息：|类名：Configuration;<br>方法or属性：readonly fontScale: number;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：Rectangle;<br>方法or属性：declare interface Rectangle<br>旧版本信息：|类名：Rectangle;<br>方法or属性：declare interface Rectangle<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：Rectangle;<br>方法or属性：x?: Length;<br>旧版本信息：|类名：Rectangle;<br>方法or属性：x?: Length;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：Rectangle;<br>方法or属性：y?: Length;<br>旧版本信息：|类名：Rectangle;<br>方法or属性：y?: Length;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：Rectangle;<br>方法or属性：width?: Length;<br>旧版本信息：|类名：Rectangle;<br>方法or属性：width?: Length;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：Rectangle;<br>方法or属性：height?: Length;<br>旧版本信息：|类名：Rectangle;<br>方法or属性：height?: Length;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：AnimateParam;<br>方法or属性：declare interface AnimateParam<br>旧版本信息：|类名：AnimateParam;<br>方法or属性：declare interface AnimateParam<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：AnimateParam;<br>方法or属性：duration?: number;<br>旧版本信息：|类名：AnimateParam;<br>方法or属性：duration?: number;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：AnimateParam;<br>方法or属性：curve?: Curve \| string \| ICurve;<br>旧版本信息：|类名：AnimateParam;<br>方法or属性：curve?: Curve \| string \| ICurve;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：AnimateParam;<br>方法or属性：playMode?: PlayMode;<br>旧版本信息：|类名：AnimateParam;<br>方法or属性：playMode?: PlayMode;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：AnimateParam;<br>方法or属性：onFinish?: () => void;<br>旧版本信息：|类名：AnimateParam;<br>方法or属性：onFinish?: () => void;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：TranslateOptions;<br>方法or属性：declare interface TranslateOptions<br>旧版本信息：|类名：TranslateOptions;<br>方法or属性：declare interface TranslateOptions<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：TranslateOptions;<br>方法or属性：x?: number \| string;<br>旧版本信息：|类名：TranslateOptions;<br>方法or属性：x?: number \| string;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：TranslateOptions;<br>方法or属性：y?: number \| string;<br>旧版本信息：|类名：TranslateOptions;<br>方法or属性：y?: number \| string;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：TranslateOptions;<br>方法or属性：z?: number \| string;<br>旧版本信息：|类名：TranslateOptions;<br>方法or属性：z?: number \| string;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：ScaleOptions;<br>方法or属性：declare interface ScaleOptions<br>旧版本信息：|类名：ScaleOptions;<br>方法or属性：declare interface ScaleOptions<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：ScaleOptions;<br>方法or属性：x?: number;<br>旧版本信息：|类名：ScaleOptions;<br>方法or属性：x?: number;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：RotateOptions;<br>方法or属性：x?: number;<br>旧版本信息：|类名：RotateOptions;<br>方法or属性：x?: number;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：ScaleOptions;<br>方法or属性：y?: number;<br>旧版本信息：|类名：ScaleOptions;<br>方法or属性：y?: number;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：RotateOptions;<br>方法or属性：y?: number;<br>旧版本信息：|类名：RotateOptions;<br>方法or属性：y?: number;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：ScaleOptions;<br>方法or属性：z?: number;<br>旧版本信息：|类名：ScaleOptions;<br>方法or属性：z?: number;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：RotateOptions;<br>方法or属性：z?: number;<br>旧版本信息：|类名：RotateOptions;<br>方法or属性：z?: number;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：ScaleOptions;<br>方法or属性：centerX?: number \| string;<br>旧版本信息：|类名：ScaleOptions;<br>方法or属性：centerX?: number \| string;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：RotateOptions;<br>方法or属性：centerX?: number \| string;<br>旧版本信息：|类名：RotateOptions;<br>方法or属性：centerX?: number \| string;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：ScaleOptions;<br>方法or属性：centerY?: number \| string;<br>旧版本信息：|类名：ScaleOptions;<br>方法or属性：centerY?: number \| string;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：RotateOptions;<br>方法or属性：centerY?: number \| string;<br>旧版本信息：|类名：RotateOptions;<br>方法or属性：centerY?: number \| string;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：RotateOptions;<br>方法or属性：declare interface RotateOptions<br>旧版本信息：|类名：RotateOptions;<br>方法or属性：declare interface RotateOptions<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：RotateOptions;<br>方法or属性：angle: number \| string;<br>旧版本信息：|类名：RotateOptions;<br>方法or属性：angle: number \| string;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：TransitionOptions;<br>方法or属性：declare interface TransitionOptions<br>旧版本信息：|类名：TransitionOptions;<br>方法or属性：declare interface TransitionOptions<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：TransitionOptions;<br>方法or属性：type?: TransitionType;<br>旧版本信息：|类名：TransitionOptions;<br>方法or属性：type?: TransitionType;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：TransitionOptions;<br>方法or属性：opacity?: number;<br>旧版本信息：|类名：TransitionOptions;<br>方法or属性：opacity?: number;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：TransitionOptions;<br>方法or属性：translate?: TranslateOptions;<br>旧版本信息：|类名：TransitionOptions;<br>方法or属性：translate?: TranslateOptions;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：TransitionOptions;<br>方法or属性：scale?: ScaleOptions;<br>旧版本信息：|类名：TransitionOptions;<br>方法or属性：scale?: ScaleOptions;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：TransitionOptions;<br>方法or属性：rotate?: RotateOptions;<br>旧版本信息：|类名：TransitionOptions;<br>方法or属性：rotate?: RotateOptions;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：PreviewParams;<br>方法or属性：interface PreviewParams<br>旧版本信息：|类名：PreviewParams;<br>方法or属性：interface PreviewParams<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：PreviewParams;<br>方法or属性：title?: string;<br>旧版本信息：|类名：PreviewParams;<br>方法or属性：title?: string;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：PreviewParams;<br>方法or属性：width?: number;<br>旧版本信息：|类名：PreviewParams;<br>方法or属性：width?: number;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：PreviewParams;<br>方法or属性：height?: number;<br>旧版本信息：|类名：PreviewParams;<br>方法or属性：height?: number;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：PreviewParams;<br>方法or属性：locale?: string;<br>旧版本信息：|类名：PreviewParams;<br>方法or属性：locale?: string;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：PreviewParams;<br>方法or属性：colorMode?: string;<br>旧版本信息：|类名：PreviewParams;<br>方法or属性：colorMode?: string;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：PreviewParams;<br>方法or属性：deviceType?: string;<br>旧版本信息：|类名：PreviewParams;<br>方法or属性：deviceType?: string;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：PreviewParams;<br>方法or属性：dpi?: number;<br>旧版本信息：|类名：PreviewParams;<br>方法or属性：dpi?: number;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：PreviewParams;<br>方法or属性：orientation?: string;<br>旧版本信息：|类名：PreviewParams;<br>方法or属性：orientation?: string;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：PreviewParams;<br>方法or属性：roundScreen?: boolean;<br>旧版本信息：|类名：PreviewParams;<br>方法or属性：roundScreen?: boolean;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：EventTarget;<br>方法or属性：declare interface EventTarget<br>旧版本信息：|类名：EventTarget;<br>方法or属性：declare interface EventTarget<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：EventTarget;<br>方法or属性：area: Area;<br>旧版本信息：|类名：EventTarget;<br>方法or属性：area: Area;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：BaseEvent;<br>方法or属性：declare interface BaseEvent<br>旧版本信息：|类名：BaseEvent;<br>方法or属性：declare interface BaseEvent<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：BaseEvent;<br>方法or属性：target: EventTarget;<br>旧版本信息：|类名：BaseEvent;<br>方法or属性：target: EventTarget;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：BaseEvent;<br>方法or属性：timestamp: number;<br>旧版本信息：|类名：BaseEvent;<br>方法or属性：timestamp: number;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：BaseEvent;<br>方法or属性：source: SourceType;<br>旧版本信息：|类名：BaseEvent;<br>方法or属性：source: SourceType;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：ClickEvent;<br>方法or属性：declare interface ClickEvent<br>旧版本信息：|类名：ClickEvent;<br>方法or属性：declare interface ClickEvent<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：ClickEvent;<br>方法or属性：screenX: number;<br>旧版本信息：|类名：ClickEvent;<br>方法or属性：screenX: number;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：ClickEvent;<br>方法or属性：screenY: number;<br>旧版本信息：|类名：ClickEvent;<br>方法or属性：screenY: number;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：ClickEvent;<br>方法or属性：x: number;<br>旧版本信息：|类名：ClickEvent;<br>方法or属性：x: number;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：ClickEvent;<br>方法or属性：y: number;<br>旧版本信息：|类名：ClickEvent;<br>方法or属性：y: number;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：StateStyles;<br>方法or属性：declare interface StateStyles<br>旧版本信息：|类名：StateStyles;<br>方法or属性：declare interface StateStyles<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：StateStyles;<br>方法or属性：normal?: any;<br>旧版本信息：|类名：StateStyles;<br>方法or属性：normal?: any;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：StateStyles;<br>方法or属性：pressed?: any;<br>旧版本信息：|类名：StateStyles;<br>方法or属性：pressed?: any;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：StateStyles;<br>方法or属性：disabled?: any;<br>旧版本信息：|类名：StateStyles;<br>方法or属性：disabled?: any;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：StateStyles;<br>方法or属性：focused?: any;<br>旧版本信息：|类名：StateStyles;<br>方法or属性：focused?: any;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：StateStyles;<br>方法or属性：clicked?: any;<br>旧版本信息：|类名：StateStyles;<br>方法or属性：clicked?: any;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：declare class CommonMethod<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：declare class CommonMethod<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：constructor();<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：constructor();<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonShapeMethod;<br>方法or属性：constructor();<br>旧版本信息：|类名：CommonShapeMethod;<br>方法or属性：constructor();<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：width(value: Length): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：width(value: Length): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：height(value: Length): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：height(value: Length): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：responseRegion(value: Array\<Rectangle> \| Rectangle): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：responseRegion(value: Array\<Rectangle> \| Rectangle): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：size(value: SizeOptions): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：size(value: SizeOptions): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：constraintSize(value: ConstraintSizeOptions): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：constraintSize(value: ConstraintSizeOptions): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：layoutWeight(value: number \| string): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：layoutWeight(value: number \| string): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：padding(value: Padding \| Length): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：padding(value: Padding \| Length): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：margin(value: Margin \| Length): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：margin(value: Margin \| Length): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：backgroundColor(value: ResourceColor): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：backgroundColor(value: ResourceColor): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：backgroundImage(src: ResourceStr, repeat?: ImageRepeat): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：backgroundImage(src: ResourceStr, repeat?: ImageRepeat): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：backgroundImageSize(value: SizeOptions \| ImageSize): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：backgroundImageSize(value: SizeOptions \| ImageSize): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：backgroundImagePosition(value: Position \| Alignment): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：backgroundImagePosition(value: Position \| Alignment): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：opacity(value: number \| Resource): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：opacity(value: number \| Resource): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：border(value: BorderOptions): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：border(value: BorderOptions): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：borderStyle(value: BorderStyle): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：borderStyle(value: BorderStyle): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：borderWidth(value: Length): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：borderWidth(value: Length): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：borderColor(value: ResourceColor): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：borderColor(value: ResourceColor): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：borderRadius(value: Length): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：borderRadius(value: Length): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：onClick(event: (event?: ClickEvent) => void): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：onClick(event: (event?: ClickEvent) => void): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：animation(value: AnimateParam): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：animation(value: AnimateParam): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：transition(value: TransitionOptions): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：transition(value: TransitionOptions): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：blur(value: number): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：blur(value: number): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：brightness(value: number): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：brightness(value: number): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：contrast(value: number): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：contrast(value: number): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：grayscale(value: number): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：grayscale(value: number): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：colorBlend(value: Color \| string \| Resource): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：colorBlend(value: Color \| string \| Resource): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：saturate(value: number): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：saturate(value: number): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：sepia(value: number): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：sepia(value: number): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：invert(value: number): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：invert(value: number): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：hueRotate(value: number \| string): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：hueRotate(value: number \| string): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：backdropBlur(value: number): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：backdropBlur(value: number): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：translate(value: TranslateOptions): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：translate(value: TranslateOptions): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：scale(value: ScaleOptions): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：scale(value: ScaleOptions): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：rotate(value: RotateOptions): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：rotate(value: RotateOptions): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：onAppear(event: () => void): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：onAppear(event: () => void): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：onDisAppear(event: () => void): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：onDisAppear(event: () => void): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：visibility(value: Visibility): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：visibility(value: Visibility): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：flexGrow(value: number): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：flexGrow(value: number): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：flexShrink(value: number): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：flexShrink(value: number): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：flexBasis(value: number \| string): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：flexBasis(value: number \| string): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：alignSelf(value: ItemAlign): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：alignSelf(value: ItemAlign): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：displayPriority(value: number): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：displayPriority(value: number): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：zIndex(value: number): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：zIndex(value: number): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：direction(value: Direction): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：direction(value: Direction): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：align(value: Alignment): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：align(value: Alignment): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：position(value: Position): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：position(value: Position): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：markAnchor(value: Position): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：markAnchor(value: Position): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：offset(value: Position): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：offset(value: Position): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：enabled(value: boolean): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：enabled(value: boolean): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：aspectRatio(value: number): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：aspectRatio(value: number): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：overlay(value: string, options?: { align?: Alignment; offset?: { x?: number; y?: number } }): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：overlay(value: string, options?: { align?: Alignment; offset?: { x?: number; y?: number } }): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：linearGradient(value: {<br>    angle?: number \| string;<br>    direction?: GradientDirection;<br>    colors: Array\<any>;<br>    repeating?: boolean;<br>  }): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：linearGradient(value: {<br>    angle?: number \| string;<br>    direction?: GradientDirection;<br>    colors: Array\<any>;<br>    repeating?: boolean;<br>  }): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：sweepGradient(value: {<br>    center: Array\<any>;<br>    start?: number \| string;<br>    end?: number \| string;<br>    rotation?: number \| string;<br>    colors: Array\<any>;<br>    repeating?: boolean;<br>  }): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：sweepGradient(value: {<br>    center: Array\<any>;<br>    start?: number \| string;<br>    end?: number \| string;<br>    rotation?: number \| string;<br>    colors: Array\<any>;<br>    repeating?: boolean;<br>  }): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：radialGradient(value: { center: Array\<any>; radius: number \| string; colors: Array\<any>; repeating?: boolean }): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：radialGradient(value: { center: Array\<any>; radius: number \| string; colors: Array\<any>; repeating?: boolean }): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：shadow(value: {<br>    radius: number \| Resource;<br>    color?: Color \| string \| Resource;<br>    offsetX?: number \| Resource;<br>    offsetY?: number \| Resource;<br>  }): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：shadow(value: {<br>    radius: number \| Resource;<br>    color?: Color \| string \| Resource;<br>    offsetX?: number \| Resource;<br>    offsetY?: number \| Resource;<br>  }): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：clip(value: boolean \| CircleAttribute \| EllipseAttribute \| PathAttribute \| RectAttribute): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：clip(value: boolean \| CircleAttribute \| EllipseAttribute \| PathAttribute \| RectAttribute): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：mask(value: CircleAttribute \| EllipseAttribute \| PathAttribute \| RectAttribute): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：mask(value: CircleAttribute \| EllipseAttribute \| PathAttribute \| RectAttribute): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：id(value: string): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：id(value: string): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonMethod;<br>方法or属性：stateStyles(value: StateStyles): T;<br>旧版本信息：|类名：CommonMethod;<br>方法or属性：stateStyles(value: StateStyles): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonAttribute;<br>方法or属性：declare class CommonAttribute<br>旧版本信息：|类名：CommonAttribute;<br>方法or属性：declare class CommonAttribute<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonInterface;<br>方法or属性：interface CommonInterface<br>旧版本信息：|类名：CommonInterface;<br>方法or属性：interface CommonInterface<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonShapeMethod;<br>方法or属性：declare class CommonShapeMethod<br>旧版本信息：|类名：CommonShapeMethod;<br>方法or属性：declare class CommonShapeMethod<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonShapeMethod;<br>方法or属性：stroke(value: ResourceColor): T;<br>旧版本信息：|类名：CommonShapeMethod;<br>方法or属性：stroke(value: ResourceColor): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonShapeMethod;<br>方法or属性：fill(value: ResourceColor): T;<br>旧版本信息：|类名：CommonShapeMethod;<br>方法or属性：fill(value: ResourceColor): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonShapeMethod;<br>方法or属性：strokeDashOffset(value: number \| string): T;<br>旧版本信息：|类名：CommonShapeMethod;<br>方法or属性：strokeDashOffset(value: number \| string): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonShapeMethod;<br>方法or属性：strokeLineCap(value: LineCapStyle): T;<br>旧版本信息：|类名：CommonShapeMethod;<br>方法or属性：strokeLineCap(value: LineCapStyle): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonShapeMethod;<br>方法or属性：strokeLineJoin(value: LineJoinStyle): T;<br>旧版本信息：|类名：CommonShapeMethod;<br>方法or属性：strokeLineJoin(value: LineJoinStyle): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonShapeMethod;<br>方法or属性：strokeMiterLimit(value: number \| string): T;<br>旧版本信息：|类名：CommonShapeMethod;<br>方法or属性：strokeMiterLimit(value: number \| string): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonShapeMethod;<br>方法or属性：strokeOpacity(value: number \| string \| Resource): T;<br>旧版本信息：|类名：CommonShapeMethod;<br>方法or属性：strokeOpacity(value: number \| string \| Resource): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonShapeMethod;<br>方法or属性：fillOpacity(value: number \| string \| Resource): T;<br>旧版本信息：|类名：CommonShapeMethod;<br>方法or属性：fillOpacity(value: number \| string \| Resource): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonShapeMethod;<br>方法or属性：strokeWidth(value: Length): T;<br>旧版本信息：|类名：CommonShapeMethod;<br>方法or属性：strokeWidth(value: Length): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonShapeMethod;<br>方法or属性：antiAlias(value: boolean): T;<br>旧版本信息：|类名：CommonShapeMethod;<br>方法or属性：antiAlias(value: boolean): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CommonShapeMethod;<br>方法or属性：strokeDashArray(value: Array\<any>): T;<br>旧版本信息：|类名：CommonShapeMethod;<br>方法or属性：strokeDashArray(value: Array\<any>): T;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CustomComponent;<br>方法or属性：declare class CustomComponent<br>旧版本信息：|类名：CustomComponent;<br>方法or属性：declare class CustomComponent<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CustomComponent;<br>方法or属性：build(): void;<br>旧版本信息：|类名：CustomComponent;<br>方法or属性：build(): void;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CustomComponent;<br>方法or属性：aboutToAppear?(): void;<br>旧版本信息：|类名：CustomComponent;<br>方法or属性：aboutToAppear?(): void;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：CustomComponent;<br>方法or属性：aboutToDisappear?(): void;<br>旧版本信息：|类名：CustomComponent;<br>方法or属性：aboutToDisappear?(): void;<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：View;<br>方法or属性：declare class View<br>旧版本信息：|类名：View;<br>方法or属性：declare class View<br>新版本信息：form|common.d.ts|
|卡片应用支持性有变化|类名：View;<br>方法or属性：create(value: any): any;<br>旧版本信息：|类名：View;<br>方法or属性：create(value: any): any;<br>新版本信息：form|common.d.ts|
