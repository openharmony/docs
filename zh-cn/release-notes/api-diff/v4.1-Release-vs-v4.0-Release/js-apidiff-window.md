| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增API|NA|类名：global；<br>API声明： declare namespace PiPWindow<br>差异内容： declare namespace PiPWindow|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPWindow；<br>API声明：function isPiPEnabled(): boolean;<br>差异内容：function isPiPEnabled(): boolean;|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPWindow；<br>API声明：function create(config: PiPConfiguration): Promise\<PiPController>;<br>差异内容：function create(config: PiPConfiguration): Promise\<PiPController>;|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPWindow；<br>API声明： interface PiPConfiguration<br>差异内容： interface PiPConfiguration|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPConfiguration；<br>API声明：context: BaseContext;<br>差异内容：context: BaseContext;|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPConfiguration；<br>API声明：componentController: XComponentController;<br>差异内容：componentController: XComponentController;|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPConfiguration；<br>API声明：navigationId?: string;<br>差异内容：navigationId?: string;|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPConfiguration；<br>API声明：templateType?: PiPTemplateType;<br>差异内容：templateType?: PiPTemplateType;|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPConfiguration；<br>API声明：contentWidth?: number;<br>差异内容：contentWidth?: number;|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPConfiguration；<br>API声明：contentHeight?: number;<br>差异内容：contentHeight?: number;|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPWindow；<br>API声明： enum PiPTemplateType<br>差异内容： enum PiPTemplateType|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPTemplateType；<br>API声明：VIDEO_PLAY<br>差异内容：VIDEO_PLAY|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPTemplateType；<br>API声明：VIDEO_CALL<br>差异内容：VIDEO_CALL|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPTemplateType；<br>API声明：VIDEO_MEETING<br>差异内容：VIDEO_MEETING|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPTemplateType；<br>API声明：VIDEO_LIVE<br>差异内容：VIDEO_LIVE|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPWindow；<br>API声明： enum PiPState<br>差异内容： enum PiPState|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPState；<br>API声明：ABOUT_TO_START = 1<br>差异内容：ABOUT_TO_START = 1|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPState；<br>API声明：STARTED = 2<br>差异内容：STARTED = 2|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPState；<br>API声明：ABOUT_TO_STOP = 3<br>差异内容：ABOUT_TO_STOP = 3|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPState；<br>API声明：STOPPED = 4<br>差异内容：STOPPED = 4|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPState；<br>API声明：ABOUT_TO_RESTORE = 5<br>差异内容：ABOUT_TO_RESTORE = 5|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPState；<br>API声明：ERROR = 6<br>差异内容：ERROR = 6|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPWindow；<br>API声明：type PiPActionEventType = PiPVideoActionEvent \| PiPCallActionEvent \| PiPMeetingActionEvent \| PiPLiveActionEvent;<br>差异内容：type PiPActionEventType = PiPVideoActionEvent \| PiPCallActionEvent \| PiPMeetingActionEvent \| PiPLiveActionEvent;|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPWindow；<br>API声明：type PiPVideoActionEvent = 'playbackStateChanged' \| 'nextVideo' \| 'previousVideo';<br>差异内容：type PiPVideoActionEvent = 'playbackStateChanged' \| 'nextVideo' \| 'previousVideo';|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPWindow；<br>API声明：type PiPCallActionEvent = 'hangUp' \| 'micStateChanged' \| 'videoStateChanged';<br>差异内容：type PiPCallActionEvent = 'hangUp' \| 'micStateChanged' \| 'videoStateChanged';|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPWindow；<br>API声明：type PiPMeetingActionEvent = 'hangUp' \| 'voiceStateChanged' \| 'videoStateChanged';<br>差异内容：type PiPMeetingActionEvent = 'hangUp' \| 'voiceStateChanged' \| 'videoStateChanged';|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPWindow；<br>API声明：type PiPLiveActionEvent = 'playbackStateChanged';<br>差异内容：type PiPLiveActionEvent = 'playbackStateChanged';|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPWindow；<br>API声明： interface PiPController<br>差异内容： interface PiPController|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPController；<br>API声明：startPiP(): Promise\<void>;<br>差异内容：startPiP(): Promise\<void>;|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPController；<br>API声明：stopPiP(): Promise\<void>;<br>差异内容：stopPiP(): Promise\<void>;|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPController；<br>API声明：setAutoStartEnabled(enable: boolean): void;<br>差异内容：setAutoStartEnabled(enable: boolean): void;|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPController；<br>API声明：updateContentSize(width: number, height: number): void;<br>差异内容：updateContentSize(width: number, height: number): void;|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPController；<br>API声明：on(type: 'stateChange', callback: (state: PiPState, reason: string) => void): void;<br>差异内容：on(type: 'stateChange', callback: (state: PiPState, reason: string) => void): void;|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPController；<br>API声明：off(type: 'stateChange'): void;<br>差异内容：off(type: 'stateChange'): void;|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPController；<br>API声明：on(type: 'controlPanelActionEvent', callback: (event: PiPActionEventType) => void): void;<br>差异内容：on(type: 'controlPanelActionEvent', callback: (event: PiPActionEventType) => void): void;|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPController；<br>API声明：off(type: 'controlPanelActionEvent'): void;<br>差异内容：off(type: 'controlPanelActionEvent'): void;|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：window；<br>API声明： enum WindowStatusType<br>差异内容： enum WindowStatusType|api/@ohos.window.d.ts|
|新增API|NA|类名：WindowStatusType；<br>API声明：UNDEFINED = 0<br>差异内容：UNDEFINED = 0|api/@ohos.window.d.ts|
|新增API|NA|类名：WindowStatusType；<br>API声明：FULL_SCREEN<br>差异内容：FULL_SCREEN|api/@ohos.window.d.ts|
|新增API|NA|类名：WindowStatusType；<br>API声明：MAXIMIZE<br>差异内容：MAXIMIZE|api/@ohos.window.d.ts|
|新增API|NA|类名：WindowStatusType；<br>API声明：MINIMIZE<br>差异内容：MINIMIZE|api/@ohos.window.d.ts|
|新增API|NA|类名：WindowStatusType；<br>API声明：FLOATING<br>差异内容：FLOATING|api/@ohos.window.d.ts|
|新增API|NA|类名：WindowStatusType；<br>API声明：SPLIT_SCREEN<br>差异内容：SPLIT_SCREEN|api/@ohos.window.d.ts|
|新增API|NA|类名：window；<br>API声明： interface WindowLimits<br>差异内容： interface WindowLimits|api/@ohos.window.d.ts|
|新增API|NA|类名：WindowLimits；<br>API声明：maxWidth?: number;<br>差异内容：maxWidth?: number;|api/@ohos.window.d.ts|
|新增API|NA|类名：WindowLimits；<br>API声明：maxHeight?: number;<br>差异内容：maxHeight?: number;|api/@ohos.window.d.ts|
|新增API|NA|类名：WindowLimits；<br>API声明：minWidth?: number;<br>差异内容：minWidth?: number;|api/@ohos.window.d.ts|
|新增API|NA|类名：WindowLimits；<br>API声明：minHeight?: number;<br>差异内容：minHeight?: number;|api/@ohos.window.d.ts|
|新增API|NA|类名：window；<br>API声明： interface TitleButtonRect<br>差异内容： interface TitleButtonRect|api/@ohos.window.d.ts|
|新增API|NA|类名：TitleButtonRect；<br>API声明：right: number;<br>差异内容：right: number;|api/@ohos.window.d.ts|
|新增API|NA|类名：TitleButtonRect；<br>API声明：top: number;<br>差异内容：top: number;|api/@ohos.window.d.ts|
|新增API|NA|类名：TitleButtonRect；<br>API声明：width: number;<br>差异内容：width: number;|api/@ohos.window.d.ts|
|新增API|NA|类名：TitleButtonRect；<br>API声明：height: number;<br>差异内容：height: number;|api/@ohos.window.d.ts|
|新增API|NA|类名：window；<br>API声明：function shiftAppWindowFocus(sourceWindowId: number, targetWindowId: number): Promise\<void>;<br>差异内容：function shiftAppWindowFocus(sourceWindowId: number, targetWindowId: number): Promise\<void>;|api/@ohos.window.d.ts|
|新增API|NA|类名：WindowEventType；<br>API声明：WINDOW_DESTROYED = 7<br>差异内容：WINDOW_DESTROYED = 7|api/@ohos.window.d.ts|
|新增API|NA|类名：window；<br>API声明：type SpecificSystemBar = 'status' \| 'navigation' \| 'navigationIndicator';<br>差异内容：type SpecificSystemBar = 'status' \| 'navigation' \| 'navigationIndicator';|api/@ohos.window.d.ts|
|新增API|NA|类名：Window；<br>API声明：setSpecificSystemBarEnabled(name: SpecificSystemBar, enable: boolean): Promise\<void>;<br>差异内容：setSpecificSystemBarEnabled(name: SpecificSystemBar, enable: boolean): Promise\<void>;|api/@ohos.window.d.ts|
|新增API|NA|类名：Window；<br>API声明：on(type: 'windowVisibilityChange', callback: Callback\<boolean>): void;<br>差异内容：on(type: 'windowVisibilityChange', callback: Callback\<boolean>): void;|api/@ohos.window.d.ts|
|新增API|NA|类名：Window；<br>API声明：off(type: 'windowVisibilityChange', callback?: Callback\<boolean>): void;<br>差异内容：off(type: 'windowVisibilityChange', callback?: Callback\<boolean>): void;|api/@ohos.window.d.ts|
|新增API|NA|类名：Window；<br>API声明：on(type: 'windowStatusChange', callback: Callback\<WindowStatusType>): void;<br>差异内容：on(type: 'windowStatusChange', callback: Callback\<WindowStatusType>): void;|api/@ohos.window.d.ts|
|新增API|NA|类名：Window；<br>API声明：off(type: 'windowStatusChange', callback?: Callback\<WindowStatusType>): void;<br>差异内容：off(type: 'windowStatusChange', callback?: Callback\<WindowStatusType>): void;|api/@ohos.window.d.ts|
|新增API|NA|类名：Window；<br>API声明：minimize(callback: AsyncCallback\<void>): void;<br>差异内容：minimize(callback: AsyncCallback\<void>): void;|api/@ohos.window.d.ts|
|新增API|NA|类名：Window；<br>API声明：minimize(): Promise\<void>;<br>差异内容：minimize(): Promise\<void>;|api/@ohos.window.d.ts|
|新增API|NA|类名：Window；<br>API声明：getWindowLimits(): WindowLimits;<br>差异内容：getWindowLimits(): WindowLimits;|api/@ohos.window.d.ts|
|新增API|NA|类名：Window；<br>API声明：setWindowLimits(windowLimits: WindowLimits): Promise\<WindowLimits>;<br>差异内容：setWindowLimits(windowLimits: WindowLimits): Promise\<WindowLimits>;|api/@ohos.window.d.ts|
|新增API|NA|类名：Window；<br>API声明：keepKeyboardOnFocus(keepKeyboardFlag: boolean): void;<br>差异内容：keepKeyboardOnFocus(keepKeyboardFlag: boolean): void;|api/@ohos.window.d.ts|
|新增API|NA|类名：Window；<br>API声明：recover(): Promise\<void>;<br>差异内容：recover(): Promise\<void>;|api/@ohos.window.d.ts|
|新增API|NA|类名：Window；<br>API声明：setWindowDecorVisible(isVisible: boolean): void;<br>差异内容：setWindowDecorVisible(isVisible: boolean): void;|api/@ohos.window.d.ts|
|新增API|NA|类名：Window；<br>API声明：setWindowDecorHeight(height: number): void;<br>差异内容：setWindowDecorHeight(height: number): void;|api/@ohos.window.d.ts|
|新增API|NA|类名：Window；<br>API声明：getWindowDecorHeight(): number;<br>差异内容：getWindowDecorHeight(): number;|api/@ohos.window.d.ts|
|新增API|NA|类名：Window；<br>API声明：getTitleButtonRect(): TitleButtonRect;<br>差异内容：getTitleButtonRect(): TitleButtonRect;|api/@ohos.window.d.ts|
|新增API|NA|类名：Window；<br>API声明：on(type: 'windowTitleButtonRectChange', callback: Callback\<TitleButtonRect>): void;<br>差异内容：on(type: 'windowTitleButtonRectChange', callback: Callback\<TitleButtonRect>): void;|api/@ohos.window.d.ts|
|新增API|NA|类名：Window；<br>API声明：off(type: 'windowTitleButtonRectChange', callback?: Callback\<TitleButtonRect>): void;<br>差异内容：off(type: 'windowTitleButtonRectChange', callback?: Callback\<TitleButtonRect>): void;|api/@ohos.window.d.ts|
|新增API|NA|类名：window；<br>API声明： interface SubWindowOptions<br>差异内容： interface SubWindowOptions|api/@ohos.window.d.ts|
|新增API|NA|类名：SubWindowOptions；<br>API声明：title: string;<br>差异内容：title: string;|api/@ohos.window.d.ts|
|新增API|NA|类名：SubWindowOptions；<br>API声明：decorEnabled: boolean;<br>差异内容：decorEnabled: boolean;|api/@ohos.window.d.ts|
|新增API|NA|类名：WindowStage；<br>API声明：createSubWindowWithOptions(name: string, options: SubWindowOptions): Promise\<Window>;<br>差异内容：createSubWindowWithOptions(name: string, options: SubWindowOptions): Promise\<Window>;|api/@ohos.window.d.ts|
