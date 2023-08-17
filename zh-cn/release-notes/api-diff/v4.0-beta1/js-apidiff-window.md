| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|模块名: ohos.display<br>类名: display<br>方法 or 属性：function on(type: 'privateModeChange', callback: Callback\<boolean>): void;|@ohos.display.d.ts|
|新增|NA|类名：display<br>方法or属性：function on(type: 'privateModeChange', callback: Callback\<boolean>): void;|@ohos.display.d.ts|
|新增|NA|模块名: ohos.display<br>类名: display<br>方法 or 属性：function off(type: 'privateModeChange', callback?: Callback\<boolean>): void;|@ohos.display.d.ts|
|新增|NA|模块名: ohos.display<br>类名: Orientation|@ohos.display.d.ts|
|新增|NA|模块名: ohos.display<br>类名: Orientation<br>方法 or 属性：PORTRAIT = 0|@ohos.display.d.ts|
|新增|NA|模块名: ohos.display<br>类名: Orientation<br>方法 or 属性：LANDSCAPE = 1|@ohos.display.d.ts|
|新增|NA|模块名: ohos.display<br>类名: Orientation<br>方法 or 属性：PORTRAIT_INVERTED = 2|@ohos.display.d.ts|
|新增|NA|模块名: ohos.display<br>类名: Orientation<br>方法 or 属性：LANDSCAPE_INVERTED = 3|@ohos.display.d.ts|
|新增|NA|类名：Display<br>方法or属性：orientation: Orientation;|@ohos.display.d.ts|
|新增|NA|类名：screen<br>方法or属性：function stopExpand(expandScreen: Array\<number>, callback: AsyncCallback\<void>): void;|@ohos.screen.d.ts|
|新增|NA|类名：screen<br>方法or属性：function stopExpand(expandScreen: Array\<number>): Promise\<void>;|@ohos.screen.d.ts|
|新增|NA|类名：screen<br>方法or属性：function stopMirror(mirrorScreen: Array\<number>, callback: AsyncCallback\<void>): void;|@ohos.screen.d.ts|
|新增|NA|类名：screen<br>方法or属性：function stopMirror(mirrorScreen: Array\<number>): Promise\<void>;|@ohos.screen.d.ts|
|新增|NA|模块名: ohos.screen<br>类名: ScreenSourceMode|@ohos.screen.d.ts|
|新增|NA|类名：ScreenSourceMode<br>方法or属性：|@ohos.screen.d.ts|
|新增|NA|模块名: ohos.screen<br>类名: ScreenSourceMode<br>方法 or 属性：SCREEN_MAIN = 0|@ohos.screen.d.ts|
|新增|NA|模块名: ohos.screen<br>类名: ScreenSourceMode<br>方法 or 属性：SCREEN_MIRROR = 1|@ohos.screen.d.ts|
|新增|NA|模块名: ohos.screen<br>类名: ScreenSourceMode<br>方法 or 属性：SCREEN_EXTEND = 2|@ohos.screen.d.ts|
|新增|NA|模块名: ohos.screen<br>类名: ScreenSourceMode<br>方法 or 属性：SCREEN_ALONE = 3|@ohos.screen.d.ts|
|新增|NA|模块名: ohos.screen<br>类名: Screen<br>方法 or 属性：readonly sourceMode: ScreenSourceMode;|@ohos.screen.d.ts|
|新增|NA|类名：window<br>方法or属性：function setGestureNavigationEnabled(enable: boolean, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：window<br>方法or属性：function setGestureNavigationEnabled(enable: boolean): Promise\<void>;|@ohos.window.d.ts|
|新增|NA|类名：window<br>方法or属性：function on(type: 'gestureNavigationEnabledChange', callback: Callback\<boolean>): void;|@ohos.window.d.ts|
|新增|NA|类名：window<br>方法or属性：function off(type: 'gestureNavigationEnabledChange', callback?: Callback\<boolean>): void;|@ohos.window.d.ts|
|新增|NA|模块名: ohos.window<br>类名: WindowEventType|@ohos.window.d.ts|
|新增|NA|类名：WindowEventType<br>方法or属性：|@ohos.window.d.ts|
|新增|NA|模块名: ohos.window<br>类名: WindowEventType<br>方法 or 属性：WINDOW_SHOWN = 1|@ohos.window.d.ts|
|新增|NA|模块名: ohos.window<br>类名: WindowEventType<br>方法 or 属性：WINDOW_ACTIVE = 2|@ohos.window.d.ts|
|新增|NA|模块名: ohos.window<br>类名: WindowEventType<br>方法 or 属性：WINDOW_INACTIVE = 3|@ohos.window.d.ts|
|新增|NA|模块名: ohos.window<br>类名: WindowEventType<br>方法 or 属性：WINDOW_HIDDEN = 4|@ohos.window.d.ts|
|新增|NA|类名：Window<br>方法or属性：on(type: 'dialogTargetTouch', callback: Callback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window<br>方法or属性：off(type: 'dialogTargetTouch', callback?: Callback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window<br>方法or属性：on(type: 'windowEvent', callback: Callback\<WindowEventType>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window<br>方法or属性：off(type: 'windowEvent', callback: Callback\<WindowEventType>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window<br>方法or属性：raiseToAppTop(callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window<br>方法or属性：raiseToAppTop(): Promise\<void>;|@ohos.window.d.ts|
|新增|NA|类名：Window<br>方法or属性：setAspectRatio(ratio: number, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window<br>方法or属性：setAspectRatio(ratio: number): Promise\<void>;|@ohos.window.d.ts|
|新增|NA|类名：Window<br>方法or属性：resetAspectRatio(callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window<br>方法or属性：resetAspectRatio(): Promise\<void>;|@ohos.window.d.ts|
|新增|NA|类名：Window<br>方法or属性：setWaterMarkFlag(enable: boolean, callback: AsyncCallback\<void>): void;|@ohos.window.d.ts|
|新增|NA|类名：Window<br>方法or属性：setWaterMarkFlag(enable: boolean): Promise\<void>;|@ohos.window.d.ts|
