| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|syscap变更|类名：PiPWindow；<br>API声明：type PiPVideoActionEvent = 'playbackStateChanged' \| 'nextVideo' \| 'previousVideo';<br>差异内容：NA|类名：PiPWindow；<br>API声明：type PiPVideoActionEvent = 'playbackStateChanged' \| 'nextVideo' \| 'previousVideo';<br>差异内容：SystemCapability.Window.SessionManager|api/@ohos.PiPWindow.d.ts|
|syscap变更|类名：PiPWindow；<br>API声明：type PiPCallActionEvent = 'hangUp';<br>差异内容：NA|类名：PiPWindow；<br>API声明：type PiPCallActionEvent = 'hangUp' \| 'micStateChanged' \| 'videoStateChanged';<br>差异内容：SystemCapability.Window.SessionManager|api/@ohos.PiPWindow.d.ts|
|syscap变更|类名：PiPWindow；<br>API声明：type PiPMeetingActionEvent = 'hangUp';<br>差异内容：NA|类名：PiPWindow；<br>API声明：type PiPMeetingActionEvent = 'hangUp' \| 'voiceStateChanged' \| 'videoStateChanged';<br>差异内容：SystemCapability.Window.SessionManager|api/@ohos.PiPWindow.d.ts|
|syscap变更|类名：Window；<br>API声明：keepKeyboardOnFocus(keepKeyboardFlag: boolean): void;<br>差异内容：NA|类名：Window；<br>API声明：keepKeyboardOnFocus(keepKeyboardFlag: boolean): void;<br>差异内容：SystemCapability.Window.SessionManager|api/@ohos.window.d.ts|
|错误码变更|类名：Window；<br>API声明：keepKeyboardOnFocus(keepKeyboardFlag: boolean): void;<br>差异内容：NA|类名：Window；<br>API声明：keepKeyboardOnFocus(keepKeyboardFlag: boolean): void;<br>差异内容：1300002,1300004,401,801|api/@ohos.window.d.ts|
|自定义类型变更|类名：PiPWindow；<br>API声明：type PiPActionEventType = PiPVideoActionEvent \| PiPCallActionEvent \| PiPMeetingActionEvent;<br>差异内容：PiPVideoActionEvent,PiPCallActionEvent,PiPMeetingActionEvent|类名：PiPWindow；<br>API声明：type PiPActionEventType = PiPVideoActionEvent \| PiPCallActionEvent \| PiPMeetingActionEvent \| PiPLiveActionEvent;<br>差异内容：PiPVideoActionEvent,PiPCallActionEvent,PiPMeetingActionEvent,PiPLiveActionEvent|api/@ohos.PiPWindow.d.ts|
|自定义类型变更|类名：PiPWindow；<br>API声明：type PiPCallActionEvent = 'hangUp';<br>差异内容：'hangUp'|类名：PiPWindow；<br>API声明：type PiPCallActionEvent = 'hangUp' \| 'micStateChanged' \| 'videoStateChanged';<br>差异内容：'hangUp','micStateChanged','videoStateChanged'|api/@ohos.PiPWindow.d.ts|
|自定义类型变更|类名：PiPWindow；<br>API声明：type PiPMeetingActionEvent = 'hangUp';<br>差异内容：'hangUp'|类名：PiPWindow；<br>API声明：type PiPMeetingActionEvent = 'hangUp' \| 'voiceStateChanged' \| 'videoStateChanged';<br>差异内容：'hangUp','voiceStateChanged','videoStateChanged'|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPTemplateType；<br>API声明：VIDEO_LIVE<br>差异内容：VIDEO_LIVE|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：PiPWindow；<br>API声明：type PiPLiveActionEvent = 'playbackStateChanged';<br>差异内容：type PiPLiveActionEvent = 'playbackStateChanged';|api/@ohos.PiPWindow.d.ts|
|新增API|NA|类名：window；<br>API声明： interface TitleButtonRect<br>差异内容： interface TitleButtonRect|api/@ohos.window.d.ts|
|新增API|NA|类名：TitleButtonRect；<br>API声明：right: number;<br>差异内容：right: number;|api/@ohos.window.d.ts|
|新增API|NA|类名：TitleButtonRect；<br>API声明：top: number;<br>差异内容：top: number;|api/@ohos.window.d.ts|
|新增API|NA|类名：TitleButtonRect；<br>API声明：width: number;<br>差异内容：width: number;|api/@ohos.window.d.ts|
|新增API|NA|类名：TitleButtonRect；<br>API声明：height: number;<br>差异内容：height: number;|api/@ohos.window.d.ts|
|新增API|NA|类名：window；<br>API声明：function shiftAppWindowFocus(sourceWindowId: number, targetWindowId: number): Promise\<void>;<br>差异内容：function shiftAppWindowFocus(sourceWindowId: number, targetWindowId: number): Promise\<void>;|api/@ohos.window.d.ts|
|新增API|NA|类名：Window；<br>API声明：recover(): Promise\<void>;<br>差异内容：recover(): Promise\<void>;|api/@ohos.window.d.ts|
|新增API|NA|类名：Window；<br>API声明：setWindowDecorVisible(isVisible: boolean): void;<br>差异内容：setWindowDecorVisible(isVisible: boolean): void;|api/@ohos.window.d.ts|
|新增API|NA|类名：Window；<br>API声明：setWindowDecorHeight(height: number): void;<br>差异内容：setWindowDecorHeight(height: number): void;|api/@ohos.window.d.ts|
|新增API|NA|类名：Window；<br>API声明：getWindowDecorHeight(): number;<br>差异内容：getWindowDecorHeight(): number;|api/@ohos.window.d.ts|
|新增API|NA|类名：Window；<br>API声明：getTitleButtonRect(): TitleButtonRect;<br>差异内容：getTitleButtonRect(): TitleButtonRect;|api/@ohos.window.d.ts|
|新增API|NA|类名：Window；<br>API声明：on(type: 'windowTitleButtonRectChange', callback: Callback\<TitleButtonRect>): void;<br>差异内容：on(type: 'windowTitleButtonRectChange', callback: Callback\<TitleButtonRect>): void;|api/@ohos.window.d.ts|
|新增API|NA|类名：Window；<br>API声明：off(type: 'windowTitleButtonRectChange', callback?: Callback\<TitleButtonRect>): void;<br>差异内容：off(type: 'windowTitleButtonRectChange', callback?: Callback\<TitleButtonRect>): void;|api/@ohos.window.d.ts|
|删除API|类名：PiPWindow；<br>API声明：function create(config: PiPConfiguration, callback: AsyncCallback\<PiPController>): void;<br>差异内容：function create(config: PiPConfiguration, callback: AsyncCallback\<PiPController>): void;|NA|api/@ohos.PiPWindow.d.ts|
|删除API|类名：PiPController；<br>API声明：startPiP(callback: AsyncCallback\<void>): void;<br>差异内容：startPiP(callback: AsyncCallback\<void>): void;|NA|api/@ohos.PiPWindow.d.ts|
|删除API|类名：PiPController；<br>API声明：stopPiP(callback: AsyncCallback\<void>): void;<br>差异内容：stopPiP(callback: AsyncCallback\<void>): void;|NA|api/@ohos.PiPWindow.d.ts|
|起始版本有变化|类名：PiPWindow；<br>API声明：type PiPVideoActionEvent = 'playbackStateChanged' \| 'nextVideo' \| 'previousVideo';<br>差异内容：NA|类名：PiPWindow；<br>API声明：type PiPVideoActionEvent = 'playbackStateChanged' \| 'nextVideo' \| 'previousVideo';<br>差异内容：11|api/@ohos.PiPWindow.d.ts|
|起始版本有变化|类名：PiPWindow；<br>API声明：type PiPCallActionEvent = 'hangUp';<br>差异内容：NA|类名：PiPWindow；<br>API声明：type PiPCallActionEvent = 'hangUp' \| 'micStateChanged' \| 'videoStateChanged';<br>差异内容：11|api/@ohos.PiPWindow.d.ts|
|起始版本有变化|类名：PiPWindow；<br>API声明：type PiPMeetingActionEvent = 'hangUp';<br>差异内容：NA|类名：PiPWindow；<br>API声明：type PiPMeetingActionEvent = 'hangUp' \| 'voiceStateChanged' \| 'videoStateChanged';<br>差异内容：11|api/@ohos.PiPWindow.d.ts|
|起始版本有变化|类名：Window；<br>API声明：keepKeyboardOnFocus(keepKeyboardFlag: boolean): void;<br>差异内容：NA|类名：Window；<br>API声明：keepKeyboardOnFocus(keepKeyboardFlag: boolean): void;<br>差异内容：11|api/@ohos.window.d.ts|
