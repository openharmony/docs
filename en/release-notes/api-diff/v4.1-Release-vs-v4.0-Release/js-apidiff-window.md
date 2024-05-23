| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|API added|NA|Class name: global;<br>API declaration:  declare namespace PiPWindow<br>Differences:  declare namespace PiPWindow|api/@ohos.PiPWindow.d.ts|
|API added|NA|Class name: PiPWindow;<br>API declaration: function isPiPEnabled(): boolean;<br>Differences: function isPiPEnabled(): boolean;|api/@ohos.PiPWindow.d.ts|
|API added|NA|Class name: PiPWindow;<br>API declaration: function create(config: PiPConfiguration): Promise\<PiPController>;<br>Differences: function create(config: PiPConfiguration): Promise\<PiPController>;|api/@ohos.PiPWindow.d.ts|
|API added|NA|Class name: PiPWindow;<br>API declaration:  interface PiPConfiguration<br>Differences:  interface PiPConfiguration|api/@ohos.PiPWindow.d.ts|
|API added|NA|Class name: PiPConfiguration;<br>API declaration: context: BaseContext;<br>Differences: context: BaseContext;|api/@ohos.PiPWindow.d.ts|
|API added|NA|Class name: PiPConfiguration;<br>API declaration: componentController: XComponentController;<br>Differences: componentController: XComponentController;|api/@ohos.PiPWindow.d.ts|
|API added|NA|Class name: PiPConfiguration;<br>API declaration: navigationId?: string;<br>Differences: navigationId?: string;|api/@ohos.PiPWindow.d.ts|
|API added|NA|Class name: PiPConfiguration;<br>API declaration: templateType?: PiPTemplateType;<br>Differences: templateType?: PiPTemplateType;|api/@ohos.PiPWindow.d.ts|
|API added|NA|Class name: PiPConfiguration;<br>API declaration: contentWidth?: number;<br>Differences: contentWidth?: number;|api/@ohos.PiPWindow.d.ts|
|API added|NA|Class name: PiPConfiguration;<br>API declaration: contentHeight?: number;<br>Differences: contentHeight?: number;|api/@ohos.PiPWindow.d.ts|
|API added|NA|Class name: PiPWindow;<br>API declaration:  enum PiPTemplateType<br>Differences:  enum PiPTemplateType|api/@ohos.PiPWindow.d.ts|
|API added|NA|Class name: PiPTemplateType;<br>API declaration: VIDEO_PLAY<br>Differences: VIDEO_PLAY|api/@ohos.PiPWindow.d.ts|
|API added|NA|Class name: PiPTemplateType;<br>API declaration: VIDEO_CALL<br>Differences: VIDEO_CALL|api/@ohos.PiPWindow.d.ts|
|API added|NA|Class name: PiPTemplateType;<br>API declaration: VIDEO_MEETING<br>Differences: VIDEO_MEETING|api/@ohos.PiPWindow.d.ts|
|API added|NA|Class name: PiPTemplateType;<br>API declaration: VIDEO_LIVE<br>Differences: VIDEO_LIVE|api/@ohos.PiPWindow.d.ts|
|API added|NA|Class name: PiPWindow;<br>API declaration:  enum PiPState<br>Differences:  enum PiPState|api/@ohos.PiPWindow.d.ts|
|API added|NA|Class name: PiPState;<br>API declaration: ABOUT_TO_START = 1<br>Differences: ABOUT_TO_START = 1|api/@ohos.PiPWindow.d.ts|
|API added|NA|Class name: PiPState;<br>API declaration: STARTED = 2<br>Differences: STARTED = 2|api/@ohos.PiPWindow.d.ts|
|API added|NA|Class name: PiPState;<br>API declaration: ABOUT_TO_STOP = 3<br>Differences: ABOUT_TO_STOP = 3|api/@ohos.PiPWindow.d.ts|
|API added|NA|Class name: PiPState;<br>API declaration: STOPPED = 4<br>Differences: STOPPED = 4|api/@ohos.PiPWindow.d.ts|
|API added|NA|Class name: PiPState;<br>API declaration: ABOUT_TO_RESTORE = 5<br>Differences: ABOUT_TO_RESTORE = 5|api/@ohos.PiPWindow.d.ts|
|API added|NA|Class name: PiPState;<br>API declaration: ERROR = 6<br>Differences: ERROR = 6|api/@ohos.PiPWindow.d.ts|
|API added|NA|Class name: PiPWindow;<br>API declaration: type PiPActionEventType = PiPVideoActionEvent \| PiPCallActionEvent \| PiPMeetingActionEvent \| PiPLiveActionEvent;<br>Differences: type PiPActionEventType = PiPVideoActionEvent \| PiPCallActionEvent \| PiPMeetingActionEvent \| PiPLiveActionEvent;|api/@ohos.PiPWindow.d.ts|
|API added|NA|Class name: PiPWindow;<br>API declaration: type PiPVideoActionEvent = 'playbackStateChanged' \| 'nextVideo' \| 'previousVideo';<br>Differences: type PiPVideoActionEvent = 'playbackStateChanged' \| 'nextVideo' \| 'previousVideo';|api/@ohos.PiPWindow.d.ts|
|API added|NA|Class name: PiPWindow;<br>API declaration: type PiPCallActionEvent = 'hangUp' \| 'micStateChanged' \| 'videoStateChanged';<br>Differences: type PiPCallActionEvent = 'hangUp' \| 'micStateChanged' \| 'videoStateChanged';|api/@ohos.PiPWindow.d.ts|
|API added|NA|Class name: PiPWindow;<br>API declaration: type PiPMeetingActionEvent = 'hangUp' \| 'voiceStateChanged' \| 'videoStateChanged';<br>Differences: type PiPMeetingActionEvent = 'hangUp' \| 'voiceStateChanged' \| 'videoStateChanged';|api/@ohos.PiPWindow.d.ts|
|API added|NA|Class name: PiPWindow;<br>API declaration: type PiPLiveActionEvent = 'playbackStateChanged';<br>Differences: type PiPLiveActionEvent = 'playbackStateChanged';|api/@ohos.PiPWindow.d.ts|
|API added|NA|Class name: PiPWindow;<br>API declaration:  interface PiPController<br>Differences:  interface PiPController|api/@ohos.PiPWindow.d.ts|
|API added|NA|Class name: PiPController;<br>API declaration: startPiP(): Promise\<void>;<br>Differences: startPiP(): Promise\<void>;|api/@ohos.PiPWindow.d.ts|
|API added|NA|Class name: PiPController;<br>API declaration: stopPiP(): Promise\<void>;<br>Differences: stopPiP(): Promise\<void>;|api/@ohos.PiPWindow.d.ts|
|API added|NA|Class name: PiPController;<br>API declaration: setAutoStartEnabled(enable: boolean): void;<br>Differences: setAutoStartEnabled(enable: boolean): void;|api/@ohos.PiPWindow.d.ts|
|API added|NA|Class name: PiPController;<br>API declaration: updateContentSize(width: number, height: number): void;<br>Differences: updateContentSize(width: number, height: number): void;|api/@ohos.PiPWindow.d.ts|
|API added|NA|Class name: PiPController;<br>API declaration: on(type: 'stateChange', callback: (state: PiPState, reason: string) => void): void;<br>Differences: on(type: 'stateChange', callback: (state: PiPState, reason: string) => void): void;|api/@ohos.PiPWindow.d.ts|
|API added|NA|Class name: PiPController;<br>API declaration: off(type: 'stateChange'): void;<br>Differences: off(type: 'stateChange'): void;|api/@ohos.PiPWindow.d.ts|
|API added|NA|Class name: PiPController;<br>API declaration: on(type: 'controlPanelActionEvent', callback: (event: PiPActionEventType) => void): void;<br>Differences: on(type: 'controlPanelActionEvent', callback: (event: PiPActionEventType) => void): void;|api/@ohos.PiPWindow.d.ts|
|API added|NA|Class name: PiPController;<br>API declaration: off(type: 'controlPanelActionEvent'): void;<br>Differences: off(type: 'controlPanelActionEvent'): void;|api/@ohos.PiPWindow.d.ts|
|API added|NA|Class name: window;<br>API declaration:  enum WindowStatusType<br>Differences:  enum WindowStatusType|api/@ohos.window.d.ts|
|API added|NA|Class name: WindowStatusType;<br>API declaration: UNDEFINED = 0<br>Differences: UNDEFINED = 0|api/@ohos.window.d.ts|
|API added|NA|Class name: WindowStatusType;<br>API declaration: FULL_SCREEN<br>Differences: FULL_SCREEN|api/@ohos.window.d.ts|
|API added|NA|Class name: WindowStatusType;<br>API declaration: MAXIMIZE<br>Differences: MAXIMIZE|api/@ohos.window.d.ts|
|API added|NA|Class name: WindowStatusType;<br>API declaration: MINIMIZE<br>Differences: MINIMIZE|api/@ohos.window.d.ts|
|API added|NA|Class name: WindowStatusType;<br>API declaration: FLOATING<br>Differences: FLOATING|api/@ohos.window.d.ts|
|API added|NA|Class name: WindowStatusType;<br>API declaration: SPLIT_SCREEN<br>Differences: SPLIT_SCREEN|api/@ohos.window.d.ts|
|API added|NA|Class name: window;<br>API declaration:  interface WindowLimits<br>Differences:  interface WindowLimits|api/@ohos.window.d.ts|
|API added|NA|Class name: WindowLimits;<br>API declaration: maxWidth?: number;<br>Differences: maxWidth?: number;|api/@ohos.window.d.ts|
|API added|NA|Class name: WindowLimits;<br>API declaration: maxHeight?: number;<br>Differences: maxHeight?: number;|api/@ohos.window.d.ts|
|API added|NA|Class name: WindowLimits;<br>API declaration: minWidth?: number;<br>Differences: minWidth?: number;|api/@ohos.window.d.ts|
|API added|NA|Class name: WindowLimits;<br>API declaration: minHeight?: number;<br>Differences: minHeight?: number;|api/@ohos.window.d.ts|
|API added|NA|Class name: window;<br>API declaration:  interface TitleButtonRect<br>Differences:  interface TitleButtonRect|api/@ohos.window.d.ts|
|API added|NA|Class name: TitleButtonRect;<br>API declaration: right: number;<br>Differences: right: number;|api/@ohos.window.d.ts|
|API added|NA|Class name: TitleButtonRect;<br>API declaration: top: number;<br>Differences: top: number;|api/@ohos.window.d.ts|
|API added|NA|Class name: TitleButtonRect;<br>API declaration: width: number;<br>Differences: width: number;|api/@ohos.window.d.ts|
|API added|NA|Class name: TitleButtonRect;<br>API declaration: height: number;<br>Differences: height: number;|api/@ohos.window.d.ts|
|API added|NA|Class name: window;<br>API declaration: function shiftAppWindowFocus(sourceWindowId: number, targetWindowId: number): Promise\<void>;<br>Differences: function shiftAppWindowFocus(sourceWindowId: number, targetWindowId: number): Promise\<void>;|api/@ohos.window.d.ts|
|API added|NA|Class name: WindowEventType;<br>API declaration: WINDOW_DESTROYED = 7<br>Differences: WINDOW_DESTROYED = 7|api/@ohos.window.d.ts|
|API added|NA|Class name: window;<br>API declaration: type SpecificSystemBar = 'status' \| 'navigation' \| 'navigationIndicator';<br>Differences: type SpecificSystemBar = 'status' \| 'navigation' \| 'navigationIndicator';|api/@ohos.window.d.ts|
|API added|NA|Class name: Window;<br>API declaration: setSpecificSystemBarEnabled(name: SpecificSystemBar, enable: boolean): Promise\<void>;<br>Differences: setSpecificSystemBarEnabled(name: SpecificSystemBar, enable: boolean): Promise\<void>;|api/@ohos.window.d.ts|
|API added|NA|Class name: Window;<br>API declaration: on(type: 'windowVisibilityChange', callback: Callback\<boolean>): void;<br>Differences: on(type: 'windowVisibilityChange', callback: Callback\<boolean>): void;|api/@ohos.window.d.ts|
|API added|NA|Class name: Window;<br>API declaration: off(type: 'windowVisibilityChange', callback?: Callback\<boolean>): void;<br>Differences: off(type: 'windowVisibilityChange', callback?: Callback\<boolean>): void;|api/@ohos.window.d.ts|
|API added|NA|Class name: Window;<br>API declaration: on(type: 'windowStatusChange', callback: Callback\<WindowStatusType>): void;<br>Differences: on(type: 'windowStatusChange', callback: Callback\<WindowStatusType>): void;|api/@ohos.window.d.ts|
|API added|NA|Class name: Window;<br>API declaration: off(type: 'windowStatusChange', callback?: Callback\<WindowStatusType>): void;<br>Differences: off(type: 'windowStatusChange', callback?: Callback\<WindowStatusType>): void;|api/@ohos.window.d.ts|
|API added|NA|Class name: Window;<br>API declaration: minimize(callback: AsyncCallback\<void>): void;<br>Differences: minimize(callback: AsyncCallback\<void>): void;|api/@ohos.window.d.ts|
|API added|NA|Class name: Window;<br>API declaration: minimize(): Promise\<void>;<br>Differences: minimize(): Promise\<void>;|api/@ohos.window.d.ts|
|API added|NA|Class name: Window;<br>API declaration: getWindowLimits(): WindowLimits;<br>Differences: getWindowLimits(): WindowLimits;|api/@ohos.window.d.ts|
|API added|NA|Class name: Window;<br>API declaration: setWindowLimits(windowLimits: WindowLimits): Promise\<WindowLimits>;<br>Differences: setWindowLimits(windowLimits: WindowLimits): Promise\<WindowLimits>;|api/@ohos.window.d.ts|
|API added|NA|Class name: Window;<br>API declaration: keepKeyboardOnFocus(keepKeyboardFlag: boolean): void;<br>Differences: keepKeyboardOnFocus(keepKeyboardFlag: boolean): void;|api/@ohos.window.d.ts|
|API added|NA|Class name: Window;<br>API declaration: recover(): Promise\<void>;<br>Differences: recover(): Promise\<void>;|api/@ohos.window.d.ts|
|API added|NA|Class name: Window;<br>API declaration: setWindowDecorVisible(isVisible: boolean): void;<br>Differences: setWindowDecorVisible(isVisible: boolean): void;|api/@ohos.window.d.ts|
|API added|NA|Class name: Window;<br>API declaration: setWindowDecorHeight(height: number): void;<br>Differences: setWindowDecorHeight(height: number): void;|api/@ohos.window.d.ts|
|API added|NA|Class name: Window;<br>API declaration: getWindowDecorHeight(): number;<br>Differences: getWindowDecorHeight(): number;|api/@ohos.window.d.ts|
|API added|NA|Class name: Window;<br>API declaration: getTitleButtonRect(): TitleButtonRect;<br>Differences: getTitleButtonRect(): TitleButtonRect;|api/@ohos.window.d.ts|
|API added|NA|Class name: Window;<br>API declaration: on(type: 'windowTitleButtonRectChange', callback: Callback\<TitleButtonRect>): void;<br>Differences: on(type: 'windowTitleButtonRectChange', callback: Callback\<TitleButtonRect>): void;|api/@ohos.window.d.ts|
|API added|NA|Class name: Window;<br>API declaration: off(type: 'windowTitleButtonRectChange', callback?: Callback\<TitleButtonRect>): void;<br>Differences: off(type: 'windowTitleButtonRectChange', callback?: Callback\<TitleButtonRect>): void;|api/@ohos.window.d.ts|
|API added|NA|Class name: window;<br>API declaration:  interface SubWindowOptions<br>Differences:  interface SubWindowOptions|api/@ohos.window.d.ts|
|API added|NA|Class name: SubWindowOptions;<br>API declaration: title: string;<br>Differences: title: string;|api/@ohos.window.d.ts|
|API added|NA|Class name: SubWindowOptions;<br>API declaration: decorEnabled: boolean;<br>Differences: decorEnabled: boolean;|api/@ohos.window.d.ts|
|API added|NA|Class name: WindowStage;<br>API declaration: createSubWindowWithOptions(name: string, options: SubWindowOptions): Promise\<Window>;<br>Differences: createSubWindowWithOptions(name: string, options: SubWindowOptions): Promise\<Window>;|api/@ohos.window.d.ts|
