| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：UIElementInfo;<br>方法or属性：readonly bundleName: string;|@ohos.UiTest.d.ts|
|新增|NA|类名：UIElementInfo;<br>方法or属性：readonly type: string;|@ohos.UiTest.d.ts|
|新增|NA|类名：UIElementInfo;<br>方法or属性：readonly text: string;|@ohos.UiTest.d.ts|
|新增|NA|类名：UIEventObserver;<br>方法or属性：once(type: 'toastShow', callback: Callback\<UIElementInfo>): void;|@ohos.UiTest.d.ts|
|新增|NA|类名：UIEventObserver;<br>方法or属性：once(type: 'dialogShow', callback: Callback\<UIElementInfo>): void;|@ohos.UiTest.d.ts|
|新增|NA|类名：Driver;<br>方法or属性：createUIEventObserver(): UIEventObserver;|@ohos.UiTest.d.ts|
|type有变化|类名：WindowFilter;<br>方法or属性：bundleName?: string;<br>旧版本信息：string?|类名：WindowFilter;<br>方法or属性：bundleName?: string;<br>新版本信息：?string|@ohos.UiTest.d.ts|
|type有变化|类名：WindowFilter;<br>方法or属性：title?: string;<br>旧版本信息：string?|类名：WindowFilter;<br>方法or属性：title?: string;<br>新版本信息：?string|@ohos.UiTest.d.ts|
|type有变化|类名：WindowFilter;<br>方法or属性：focused?: boolean;<br>旧版本信息：boolean?|类名：WindowFilter;<br>方法or属性：focused?: boolean;<br>新版本信息：?boolean|@ohos.UiTest.d.ts|
|type有变化|类名：WindowFilter;<br>方法or属性：actived?: boolean;<br>旧版本信息：boolean?|类名：WindowFilter;<br>方法or属性：actived?: boolean;<br>新版本信息：?boolean|@ohos.UiTest.d.ts|
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
