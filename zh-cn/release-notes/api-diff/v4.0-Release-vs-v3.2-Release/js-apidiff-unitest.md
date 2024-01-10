| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：UIElementInfo;<br>方法or属性：readonly bundleName: string;|@ohos.UiTest.d.ts|
|新增|NA|类名：UIElementInfo;<br>方法or属性：readonly type: string;|@ohos.UiTest.d.ts|
|新增|NA|类名：UIElementInfo;<br>方法or属性：readonly text: string;|@ohos.UiTest.d.ts|
|新增|NA|类名：UIEventObserver;<br>方法or属性：once(type: 'toastShow', callback: Callback\<UIElementInfo>): void;|@ohos.UiTest.d.ts|
|新增|NA|类名：UIEventObserver;<br>方法or属性：once(type: 'dialogShow', callback: Callback\<UIElementInfo>): void;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiDirection;<br>方法or属性：LEFT = 0|@ohos.UiTest.d.ts|
|新增|NA|类名：UiDirection;<br>方法or属性：RIGHT = 1|@ohos.UiTest.d.ts|
|新增|NA|类名：UiDirection;<br>方法or属性：UP = 2|@ohos.UiTest.d.ts|
|新增|NA|类名：UiDirection;<br>方法or属性：DOWN = 3|@ohos.UiTest.d.ts|
|新增|NA|类名：MouseButton;<br>方法or属性：MOUSE_BUTTON_LEFT = 0|@ohos.UiTest.d.ts|
|新增|NA|类名：MouseButton;<br>方法or属性：MOUSE_BUTTON_RIGHT = 1|@ohos.UiTest.d.ts|
|新增|NA|类名：MouseButton;<br>方法or属性：MOUSE_BUTTON_MIDDLE = 2|@ohos.UiTest.d.ts|
|新增|NA|类名：On;<br>方法or属性：within(on: On): On;|@ohos.UiTest.d.ts|
|新增|NA|类名：On;<br>方法or属性：inWindow(bundleName: string): On;|@ohos.UiTest.d.ts|
|新增|NA|类名：Driver;<br>方法or属性：fling(direction: UiDirection, speed: number): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Driver;<br>方法or属性：mouseClick(p: Point, btnId: MouseButton, key1?: number, key2?: number): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Driver;<br>方法or属性：mouseMoveTo(p: Point): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Driver;<br>方法or属性：mouseScroll(p: Point, down: boolean, d: number, key1?: number, key2?: number): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Driver;<br>方法or属性：screenCapture(savePath: string, rect?: Rect): Promise\<boolean>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Driver;<br>方法or属性：createUIEventObserver(): UIEventObserver;|@ohos.UiTest.d.ts|
|错误码有变化|类名：UiDriver;<br>方法or属性：assertComponentExist(by: By): Promise\<void>;<br>旧版本信息：Throws|类名：UiDriver;<br>方法or属性：assertComponentExist(by: By): Promise\<void>;<br>新版本信息：401,17000002,17000003|@ohos.UiTest.d.ts|
|type有变化|类名：Point;<br>方法or属性：readonly x: number;<br>旧版本信息：|类名：Point;<br>方法or属性：readonly x: number;<br>新版本信息：number|@ohos.UiTest.d.ts|
|type有变化|类名：Point;<br>方法or属性：readonly y: number;<br>旧版本信息：|类名：Point;<br>方法or属性：readonly y: number;<br>新版本信息：number|@ohos.UiTest.d.ts|
|type有变化|类名：Rect;<br>方法or属性：readonly left: number;<br>旧版本信息：|类名：Rect;<br>方法or属性：readonly left: number;<br>新版本信息：number|@ohos.UiTest.d.ts|
|type有变化|类名：Rect;<br>方法or属性：readonly top: number;<br>旧版本信息：|类名：Rect;<br>方法or属性：readonly top: number;<br>新版本信息：number|@ohos.UiTest.d.ts|
|type有变化|类名：Rect;<br>方法or属性：readonly right: number;<br>旧版本信息：|类名：Rect;<br>方法or属性：readonly right: number;<br>新版本信息：number|@ohos.UiTest.d.ts|
|type有变化|类名：Rect;<br>方法or属性：readonly bottom: number;<br>旧版本信息：|类名：Rect;<br>方法or属性：readonly bottom: number;<br>新版本信息：number|@ohos.UiTest.d.ts|
|type有变化|类名：WindowFilter;<br>方法or属性：bundleName?: string;<br>旧版本信息：|类名：WindowFilter;<br>方法or属性：bundleName?: string;<br>新版本信息：?string|@ohos.UiTest.d.ts|
|type有变化|类名：WindowFilter;<br>方法or属性：title?: string;<br>旧版本信息：|类名：WindowFilter;<br>方法or属性：title?: string;<br>新版本信息：?string|@ohos.UiTest.d.ts|
|type有变化|类名：WindowFilter;<br>方法or属性：focused?: boolean;<br>旧版本信息：|类名：WindowFilter;<br>方法or属性：focused?: boolean;<br>新版本信息：?boolean|@ohos.UiTest.d.ts|
|type有变化|类名：WindowFilter;<br>方法or属性：actived?: boolean;<br>旧版本信息：|类名：WindowFilter;<br>方法or属性：actived?: boolean;<br>新版本信息：?boolean|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：MatchPattern;<br>方法or属性：declare enum MatchPattern<br>旧版本信息：|类名：MatchPattern;<br>方法or属性：declare enum MatchPattern<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：MatchPattern;<br>方法or属性：EQUALS = 0<br>旧版本信息：|类名：MatchPattern;<br>方法or属性：EQUALS = 0<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：MatchPattern;<br>方法or属性：CONTAINS = 1<br>旧版本信息：|类名：MatchPattern;<br>方法or属性：CONTAINS = 1<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：MatchPattern;<br>方法or属性：STARTS_WITH = 2<br>旧版本信息：|类名：MatchPattern;<br>方法or属性：STARTS_WITH = 2<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：MatchPattern;<br>方法or属性：ENDS_WITH = 3<br>旧版本信息：|类名：MatchPattern;<br>方法or属性：ENDS_WITH = 3<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：Point;<br>方法or属性：declare interface Point<br>旧版本信息：|类名：Point;<br>方法or属性：declare interface Point<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：Point;<br>方法or属性：readonly x: number;<br>旧版本信息：|类名：Point;<br>方法or属性：readonly x: number;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：Point;<br>方法or属性：readonly y: number;<br>旧版本信息：|类名：Point;<br>方法or属性：readonly y: number;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：On;<br>方法or属性：text(txt: string, pattern?: MatchPattern): On;<br>旧版本信息：|类名：On;<br>方法or属性：text(txt: string, pattern?: MatchPattern): On;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：On;<br>方法or属性：id(id: string): On;<br>旧版本信息：|类名：On;<br>方法or属性：id(id: string): On;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：On;<br>方法or属性：type(tp: string): On;<br>旧版本信息：|类名：On;<br>方法or属性：type(tp: string): On;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：On;<br>方法or属性：clickable(b?: boolean): On;<br>旧版本信息：|类名：On;<br>方法or属性：clickable(b?: boolean): On;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：On;<br>方法or属性：longClickable(b?: boolean): On;<br>旧版本信息：|类名：On;<br>方法or属性：longClickable(b?: boolean): On;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：On;<br>方法or属性：scrollable(b?: boolean): On;<br>旧版本信息：|类名：On;<br>方法or属性：scrollable(b?: boolean): On;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：On;<br>方法or属性：enabled(b?: boolean): On;<br>旧版本信息：|类名：On;<br>方法or属性：enabled(b?: boolean): On;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：On;<br>方法or属性：focused(b?: boolean): On;<br>旧版本信息：|类名：On;<br>方法or属性：focused(b?: boolean): On;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：On;<br>方法or属性：selected(b?: boolean): On;<br>旧版本信息：|类名：On;<br>方法or属性：selected(b?: boolean): On;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：On;<br>方法or属性：checked(b?: boolean): On;<br>旧版本信息：|类名：On;<br>方法or属性：checked(b?: boolean): On;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：On;<br>方法or属性：checkable(b?: boolean): On;<br>旧版本信息：|类名：On;<br>方法or属性：checkable(b?: boolean): On;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：Component;<br>方法or属性：click(): Promise\<void>;<br>旧版本信息：|类名：Component;<br>方法or属性：click(): Promise\<void>;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：Component;<br>方法or属性：doubleClick(): Promise\<void>;<br>旧版本信息：|类名：Component;<br>方法or属性：doubleClick(): Promise\<void>;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：Component;<br>方法or属性：longClick(): Promise\<void>;<br>旧版本信息：|类名：Component;<br>方法or属性：longClick(): Promise\<void>;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：Component;<br>方法or属性：getId(): Promise\<string>;<br>旧版本信息：|类名：Component;<br>方法or属性：getId(): Promise\<string>;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：Component;<br>方法or属性：getText(): Promise\<string>;<br>旧版本信息：|类名：Component;<br>方法or属性：getText(): Promise\<string>;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：Component;<br>方法or属性：getType(): Promise\<string>;<br>旧版本信息：|类名：Component;<br>方法or属性：getType(): Promise\<string>;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：Component;<br>方法or属性：isClickable(): Promise\<boolean>;<br>旧版本信息：|类名：Component;<br>方法or属性：isClickable(): Promise\<boolean>;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：Component;<br>方法or属性：isLongClickable(): Promise\<boolean>;<br>旧版本信息：|类名：Component;<br>方法or属性：isLongClickable(): Promise\<boolean>;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：Component;<br>方法or属性：isScrollable(): Promise\<boolean>;<br>旧版本信息：|类名：Component;<br>方法or属性：isScrollable(): Promise\<boolean>;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：Component;<br>方法or属性：isEnabled(): Promise\<boolean>;<br>旧版本信息：|类名：Component;<br>方法or属性：isEnabled(): Promise\<boolean>;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：Component;<br>方法or属性：isFocused(): Promise\<boolean>;<br>旧版本信息：|类名：Component;<br>方法or属性：isFocused(): Promise\<boolean>;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：Component;<br>方法or属性：isSelected(): Promise\<boolean>;<br>旧版本信息：|类名：Component;<br>方法or属性：isSelected(): Promise\<boolean>;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：Component;<br>方法or属性：isChecked(): Promise\<boolean>;<br>旧版本信息：|类名：Component;<br>方法or属性：isChecked(): Promise\<boolean>;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：Component;<br>方法or属性：isCheckable(): Promise\<boolean>;<br>旧版本信息：|类名：Component;<br>方法or属性：isCheckable(): Promise\<boolean>;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：Component;<br>方法or属性：inputText(text: string): Promise\<void>;<br>旧版本信息：|类名：Component;<br>方法or属性：inputText(text: string): Promise\<void>;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：Component;<br>方法or属性：clearText(): Promise\<void>;<br>旧版本信息：|类名：Component;<br>方法or属性：clearText(): Promise\<void>;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：Component;<br>方法or属性：scrollToTop(speed?: number): Promise\<void>;<br>旧版本信息：|类名：Component;<br>方法or属性：scrollToTop(speed?: number): Promise\<void>;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：Component;<br>方法or属性：scrollToBottom(speed?: number): Promise\<void>;<br>旧版本信息：|类名：Component;<br>方法or属性：scrollToBottom(speed?: number): Promise\<void>;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：Component;<br>方法or属性：scrollSearch(on: On): Promise\<Component>;<br>旧版本信息：|类名：Component;<br>方法or属性：scrollSearch(on: On): Promise\<Component>;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：Component;<br>方法or属性：getBoundsCenter(): Promise\<Point>;<br>旧版本信息：|类名：Component;<br>方法or属性：getBoundsCenter(): Promise\<Point>;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：Driver;<br>方法or属性：static create(): Driver;<br>旧版本信息：|类名：Driver;<br>方法or属性：static create(): Driver;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：Driver;<br>方法or属性：delayMs(duration: number): Promise\<void>;<br>旧版本信息：|类名：Driver;<br>方法or属性：delayMs(duration: number): Promise\<void>;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：Driver;<br>方法or属性：findComponent(on: On): Promise\<Component>;<br>旧版本信息：|类名：Driver;<br>方法or属性：findComponent(on: On): Promise\<Component>;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：Driver;<br>方法or属性：findComponents(on: On): Promise\<Array\<Component>>;<br>旧版本信息：|类名：Driver;<br>方法or属性：findComponents(on: On): Promise\<Array\<Component>>;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：Driver;<br>方法or属性：assertComponentExist(on: On): Promise\<void>;<br>旧版本信息：|类名：Driver;<br>方法or属性：assertComponentExist(on: On): Promise\<void>;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：Driver;<br>方法or属性：pressBack(): Promise\<void>;<br>旧版本信息：|类名：Driver;<br>方法or属性：pressBack(): Promise\<void>;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：Driver;<br>方法or属性：click(x: number, y: number): Promise\<void>;<br>旧版本信息：|类名：Driver;<br>方法or属性：click(x: number, y: number): Promise\<void>;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：Driver;<br>方法or属性：doubleClick(x: number, y: number): Promise\<void>;<br>旧版本信息：|类名：Driver;<br>方法or属性：doubleClick(x: number, y: number): Promise\<void>;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：Driver;<br>方法or属性：longClick(x: number, y: number): Promise\<void>;<br>旧版本信息：|类名：Driver;<br>方法or属性：longClick(x: number, y: number): Promise\<void>;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：Driver;<br>方法or属性：swipe(startx: number, starty: number, endx: number, endy: number, speed?: number): Promise\<void>;<br>旧版本信息：|类名：Driver;<br>方法or属性：swipe(startx: number, starty: number, endx: number, endy: number, speed?: number): Promise\<void>;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
|跨平台能力有变化|类名：Driver;<br>方法or属性：fling(from: Point, to: Point, stepLen: number, speed: number): Promise\<void>;<br>旧版本信息：|类名：Driver;<br>方法or属性：fling(from: Point, to: Point, stepLen: number, speed: number): Promise\<void>;<br>新版本信息：crossplatform|@ohos.UiTest.d.ts|
