| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|删除|类名：MatchPattern;<br>方法or属性：EQUALS = 0|NA|@ohos.uitest.d.ts|
|删除|类名：MatchPattern;<br>方法or属性：CONTAINS = 1|NA|@ohos.uitest.d.ts|
|删除|类名：MatchPattern;<br>方法or属性：STARTS_WITH = 2|NA|@ohos.uitest.d.ts|
|删除|类名：MatchPattern;<br>方法or属性：ENDS_WITH = 3|NA|@ohos.uitest.d.ts|
|删除|类名：By;<br>方法or属性：text(txt:string,pattern?:MatchPattern):By;|NA|@ohos.uitest.d.ts|
|删除|类名：By;<br>方法or属性：key(key:string):By;|NA|@ohos.uitest.d.ts|
|删除|类名：By;<br>方法or属性：id(id:number):By;|NA|@ohos.uitest.d.ts|
|删除|类名：By;<br>方法or属性：type(tp:string):By;|NA|@ohos.uitest.d.ts|
|删除|类名：By;<br>方法or属性：clickable(b?:bool):By;|NA|@ohos.uitest.d.ts|
|删除|类名：By;<br>方法or属性：scrollable(b?:bool):By;|NA|@ohos.uitest.d.ts|
|删除|类名：By;<br>方法or属性：enabled(b?:bool):By;|NA|@ohos.uitest.d.ts|
|删除|类名：By;<br>方法or属性：focused(b?:bool):By;|NA|@ohos.uitest.d.ts|
|删除|类名：By;<br>方法or属性：selected(b?:bool):By;|NA|@ohos.uitest.d.ts|
|删除|类名：By;<br>方法or属性：isBefore(by:By):By;|NA|@ohos.uitest.d.ts|
|删除|类名：By;<br>方法or属性：isAfter(by:By):By;|NA|@ohos.uitest.d.ts|
|删除|类名：UiComponent;<br>方法or属性：click():Promise\<void>;|NA|@ohos.uitest.d.ts|
|删除|类名：UiComponent;<br>方法or属性：doubleClick():Promise\<void>;|NA|@ohos.uitest.d.ts|
|删除|类名：UiComponent;<br>方法or属性：longClick():Promise\<void>;|NA|@ohos.uitest.d.ts|
|删除|类名：UiComponent;<br>方法or属性：getId():Promise\<number>;|NA|@ohos.uitest.d.ts|
|删除|类名：UiComponent;<br>方法or属性：getKey():Promise\<string>;|NA|@ohos.uitest.d.ts|
|删除|类名：UiComponent;<br>方法or属性：getText():Promise\<string>;|NA|@ohos.uitest.d.ts|
|删除|类名：UiComponent;<br>方法or属性：getType():Promise\<string>;|NA|@ohos.uitest.d.ts|
|删除|类名：UiComponent;<br>方法or属性：isClickable():Promise\<bool>;|NA|@ohos.uitest.d.ts|
|删除|类名：UiComponent;<br>方法or属性：isScrollable():Promise\<bool>;|NA|@ohos.uitest.d.ts|
|删除|类名：UiComponent;<br>方法or属性：isEnabled():Promise\<bool>;|NA|@ohos.uitest.d.ts|
|删除|类名：UiComponent;<br>方法or属性：isFocused():Promise\<bool>;|NA|@ohos.uitest.d.ts|
|删除|类名：UiComponent;<br>方法or属性：isSelected():Promise\<bool>;|NA|@ohos.uitest.d.ts|
|删除|类名：UiComponent;<br>方法or属性：inputText(text: string):Promise\<void>;|NA|@ohos.uitest.d.ts|
|删除|类名：UiComponent;<br>方法or属性：scrollSearch(by:By):Promise\<UiComponent>;|NA|@ohos.uitest.d.ts|
|删除|类名：UiDriver;<br>方法or属性：static create():UiDriver;|NA|@ohos.uitest.d.ts|
|删除|类名：UiDriver;<br>方法or属性：delayMs(duration:number):Promise\<void>;|NA|@ohos.uitest.d.ts|
|删除|类名：UiDriver;<br>方法or属性：findComponent(by:By):Promise\<UiComponent>;|NA|@ohos.uitest.d.ts|
|删除|类名：UiDriver;<br>方法or属性：findComponents(by:By):Promise\<Array\<UiComponent>>;|NA|@ohos.uitest.d.ts|
|删除|类名：UiDriver;<br>方法or属性：assertComponentExist(by:By):Promise\<void>;|NA|@ohos.uitest.d.ts|
|删除|类名：UiDriver;<br>方法or属性：pressBack():Promise\<void>;|NA|@ohos.uitest.d.ts|
|删除|类名：UiDriver;<br>方法or属性：triggerKey(keyCode:number):Promise\<void>;|NA|@ohos.uitest.d.ts|
|删除|类名：UiDriver;<br>方法or属性：click(x:number,y:number):Promise\<void>;|NA|@ohos.uitest.d.ts|
|删除|类名：UiDriver;<br>方法or属性：doubleClick(x:number,y:number):Promise\<void>;|NA|@ohos.uitest.d.ts|
|删除|类名：UiDriver;<br>方法or属性：longClick(x:number,y:number):Promise\<void>;|NA|@ohos.uitest.d.ts|
|删除|类名：UiDriver;<br>方法or属性：swipe(startx:number,starty:number,endx:number,endy:number):Promise\<void>;|NA|@ohos.uitest.d.ts|
|删除|类名：UiDriver;<br>方法or属性：screenCap(savePath:string):Promise\<bool>;|NA|@ohos.uitest.d.ts|
|新增|NA|类名：MatchPattern;<br>方法or属性：EQUALS = 0|@ohos.UiTest.d.ts|
|新增|NA|类名：MatchPattern;<br>方法or属性：CONTAINS = 1|@ohos.UiTest.d.ts|
|新增|NA|类名：MatchPattern;<br>方法or属性：STARTS_WITH = 2|@ohos.UiTest.d.ts|
|新增|NA|类名：MatchPattern;<br>方法or属性：ENDS_WITH = 3|@ohos.UiTest.d.ts|
|新增|NA|类名：By;<br>方法or属性：text(txt: string, pattern?: MatchPattern): By;|@ohos.UiTest.d.ts|
|新增|NA|类名：By;<br>方法or属性：key(key: string): By;|@ohos.UiTest.d.ts|
|新增|NA|类名：By;<br>方法or属性：id(id: number): By;|@ohos.UiTest.d.ts|
|新增|NA|类名：By;<br>方法or属性：type(tp: string): By;|@ohos.UiTest.d.ts|
|新增|NA|类名：By;<br>方法or属性：clickable(b?: boolean): By;|@ohos.UiTest.d.ts|
|新增|NA|类名：By;<br>方法or属性：scrollable(b?: boolean): By;|@ohos.UiTest.d.ts|
|新增|NA|类名：By;<br>方法or属性：enabled(b?: boolean): By;|@ohos.UiTest.d.ts|
|新增|NA|类名：By;<br>方法or属性：focused(b?: boolean): By;|@ohos.UiTest.d.ts|
|新增|NA|类名：By;<br>方法or属性：selected(b?: boolean): By;|@ohos.UiTest.d.ts|
|新增|NA|类名：By;<br>方法or属性：isBefore(by: By): By;|@ohos.UiTest.d.ts|
|新增|NA|类名：By;<br>方法or属性：isAfter(by: By): By;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiComponent;<br>方法or属性：click(): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Component;<br>方法or属性：click(): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiComponent;<br>方法or属性：doubleClick(): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Component;<br>方法or属性：doubleClick(): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiComponent;<br>方法or属性：longClick(): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Component;<br>方法or属性：longClick(): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiComponent;<br>方法or属性：getId(): Promise\<number>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiComponent;<br>方法or属性：getKey(): Promise\<string>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiComponent;<br>方法or属性：getText(): Promise\<string>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Component;<br>方法or属性：getText(): Promise\<string>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiComponent;<br>方法or属性：getType(): Promise\<string>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Component;<br>方法or属性：getType(): Promise\<string>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiComponent;<br>方法or属性：isClickable(): Promise\<boolean>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Component;<br>方法or属性：isClickable(): Promise\<boolean>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiComponent;<br>方法or属性：isScrollable(): Promise\<boolean>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Component;<br>方法or属性：isScrollable(): Promise\<boolean>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiComponent;<br>方法or属性：isEnabled(): Promise\<boolean>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Component;<br>方法or属性：isEnabled(): Promise\<boolean>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiComponent;<br>方法or属性：isFocused(): Promise\<boolean>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Component;<br>方法or属性：isFocused(): Promise\<boolean>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiWindow;<br>方法or属性：isFocused(): Promise\<boolean>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiComponent;<br>方法or属性：isSelected(): Promise\<boolean>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Component;<br>方法or属性：isSelected(): Promise\<boolean>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiComponent;<br>方法or属性：inputText(text: string): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Component;<br>方法or属性：inputText(text: string): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiComponent;<br>方法or属性：scrollSearch(by: By): Promise\<UiComponent>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiDriver;<br>方法or属性：static create(): UiDriver;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiDriver;<br>方法or属性：delayMs(duration: number): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Driver;<br>方法or属性：delayMs(duration: number): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiDriver;<br>方法or属性：findComponent(by: By): Promise\<UiComponent>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiDriver;<br>方法or属性：findComponents(by: By): Promise\<Array\<UiComponent>>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiDriver;<br>方法or属性：assertComponentExist(by: By): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiDriver;<br>方法or属性：pressBack(): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Driver;<br>方法or属性：pressBack(): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiDriver;<br>方法or属性：triggerKey(keyCode: number): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Driver;<br>方法or属性：triggerKey(keyCode: number): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiDriver;<br>方法or属性：click(x: number, y: number): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Driver;<br>方法or属性：click(x: number, y: number): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiDriver;<br>方法or属性：doubleClick(x: number, y: number): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Driver;<br>方法or属性：doubleClick(x: number, y: number): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiDriver;<br>方法or属性：longClick(x: number, y: number): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Driver;<br>方法or属性：longClick(x: number, y: number): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiDriver;<br>方法or属性：swipe(startx: number, starty: number, endx: number, endy: number): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiDriver;<br>方法or属性：screenCap(savePath: string): Promise\<boolean>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Driver;<br>方法or属性：screenCap(savePath: string): Promise\<boolean>;|@ohos.UiTest.d.ts|
|新增|NA|类名：WindowMode;<br>方法or属性：FULLSCREEN = 0|@ohos.UiTest.d.ts|
|新增|NA|类名：WindowMode;<br>方法or属性：PRIMARY = 1|@ohos.UiTest.d.ts|
|新增|NA|类名：WindowMode;<br>方法or属性：SECONDARY = 2|@ohos.UiTest.d.ts|
|新增|NA|类名：WindowMode;<br>方法or属性：FLOATING = 3|@ohos.UiTest.d.ts|
|新增|NA|类名：ResizeDirection;<br>方法or属性：LEFT = 0|@ohos.UiTest.d.ts|
|新增|NA|类名：ResizeDirection;<br>方法or属性：RIGHT = 1|@ohos.UiTest.d.ts|
|新增|NA|类名：ResizeDirection;<br>方法or属性：UP = 2|@ohos.UiTest.d.ts|
|新增|NA|类名：ResizeDirection;<br>方法or属性：DOWN = 3|@ohos.UiTest.d.ts|
|新增|NA|类名：ResizeDirection;<br>方法or属性：LEFT_UP = 4|@ohos.UiTest.d.ts|
|新增|NA|类名：ResizeDirection;<br>方法or属性：LEFT_DOWN = 5|@ohos.UiTest.d.ts|
|新增|NA|类名：ResizeDirection;<br>方法or属性：RIGHT_UP = 6|@ohos.UiTest.d.ts|
|新增|NA|类名：ResizeDirection;<br>方法or属性：RIGHT_DOWN = 7|@ohos.UiTest.d.ts|
|新增|NA|类名：DisplayRotation;<br>方法or属性：ROTATION_0 = 0|@ohos.UiTest.d.ts|
|新增|NA|类名：DisplayRotation;<br>方法or属性：ROTATION_90 = 1|@ohos.UiTest.d.ts|
|新增|NA|类名：DisplayRotation;<br>方法or属性：ROTATION_180 = 2|@ohos.UiTest.d.ts|
|新增|NA|类名：DisplayRotation;<br>方法or属性：ROTATION_270 = 3|@ohos.UiTest.d.ts|
|新增|NA|类名：Point;<br>方法or属性：readonly x: number;|@ohos.UiTest.d.ts|
|新增|NA|类名：Point;<br>方法or属性：readonly y: number;|@ohos.UiTest.d.ts|
|新增|NA|类名：Rect;<br>方法or属性：readonly left: number;|@ohos.UiTest.d.ts|
|新增|NA|类名：Rect;<br>方法or属性：readonly top: number;|@ohos.UiTest.d.ts|
|新增|NA|类名：Rect;<br>方法or属性：readonly right: number;|@ohos.UiTest.d.ts|
|新增|NA|类名：Rect;<br>方法or属性：readonly bottom: number;|@ohos.UiTest.d.ts|
|新增|NA|类名：WindowFilter;<br>方法or属性：bundleName?: string;|@ohos.UiTest.d.ts|
|新增|NA|类名：WindowFilter;<br>方法or属性：title?: string;|@ohos.UiTest.d.ts|
|新增|NA|类名：WindowFilter;<br>方法or属性：focused?: boolean;|@ohos.UiTest.d.ts|
|新增|NA|类名：WindowFilter;<br>方法or属性：actived?: boolean;|@ohos.UiTest.d.ts|
|新增|NA|类名：On;<br>方法or属性：text(txt: string, pattern?: MatchPattern): On;|@ohos.UiTest.d.ts|
|新增|NA|类名：On;<br>方法or属性：id(id: string): On;|@ohos.UiTest.d.ts|
|新增|NA|类名：On;<br>方法or属性：type(tp: string): On;|@ohos.UiTest.d.ts|
|新增|NA|类名：On;<br>方法or属性：clickable(b?: boolean): On;|@ohos.UiTest.d.ts|
|新增|NA|类名：On;<br>方法or属性：longClickable(b?: boolean): On;|@ohos.UiTest.d.ts|
|新增|NA|类名：On;<br>方法or属性：scrollable(b?: boolean): On;|@ohos.UiTest.d.ts|
|新增|NA|类名：On;<br>方法or属性：enabled(b?: boolean): On;|@ohos.UiTest.d.ts|
|新增|NA|类名：On;<br>方法or属性：focused(b?: boolean): On;|@ohos.UiTest.d.ts|
|新增|NA|类名：On;<br>方法or属性：selected(b?: boolean): On;|@ohos.UiTest.d.ts|
|新增|NA|类名：On;<br>方法or属性：checked(b?: boolean): On;|@ohos.UiTest.d.ts|
|新增|NA|类名：On;<br>方法or属性：checkable(b?: boolean): On;|@ohos.UiTest.d.ts|
|新增|NA|类名：On;<br>方法or属性：isBefore(on: On): On;|@ohos.UiTest.d.ts|
|新增|NA|类名：On;<br>方法or属性：isAfter(on: On): On;|@ohos.UiTest.d.ts|
|新增|NA|类名：Component;<br>方法or属性：getId(): Promise\<string>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Component;<br>方法or属性：isLongClickable(): Promise\<boolean>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Component;<br>方法or属性：isChecked(): Promise\<boolean>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Component;<br>方法or属性：isCheckable(): Promise\<boolean>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Component;<br>方法or属性：clearText(): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Component;<br>方法or属性：scrollToTop(speed?: number): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Component;<br>方法or属性：scrollToBottom(speed?: number): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Component;<br>方法or属性：scrollSearch(on: On): Promise\<Component>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Component;<br>方法or属性：getBounds(): Promise\<Rect>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiWindow;<br>方法or属性：getBounds(): Promise\<Rect>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Component;<br>方法or属性：getBoundsCenter(): Promise\<Point>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Component;<br>方法or属性：dragTo(target: Component): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Component;<br>方法or属性：pinchOut(scale: number): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Component;<br>方法or属性：pinchIn(scale: number): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Driver;<br>方法or属性：static create(): Driver;|@ohos.UiTest.d.ts|
|新增|NA|类名：Driver;<br>方法or属性：findComponent(on: On): Promise\<Component>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Driver;<br>方法or属性：findWindow(filter: WindowFilter): Promise\<UiWindow>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Driver;<br>方法or属性：waitForComponent(on: On, time: number): Promise\<Component>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Driver;<br>方法or属性：findComponents(on: On): Promise\<Array\<Component>>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Driver;<br>方法or属性：assertComponentExist(on: On): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Driver;<br>方法or属性：triggerCombineKeys(key0: number, key1: number, key2?: number): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Driver;<br>方法or属性：swipe(startx: number, starty: number, endx: number, endy: number, speed?: number): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Driver;<br>方法or属性：drag(startx: number, starty: number, endx: number, endy: number, speed?: number): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Driver;<br>方法or属性：setDisplayRotation(rotation: DisplayRotation): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Driver;<br>方法or属性：getDisplayRotation(): Promise\<DisplayRotation>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Driver;<br>方法or属性：setDisplayRotationEnabled(enabled: boolean): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Driver;<br>方法or属性：getDisplaySize(): Promise\<Point>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Driver;<br>方法or属性：getDisplayDensity(): Promise\<Point>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Driver;<br>方法or属性：wakeUpDisplay(): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Driver;<br>方法or属性：pressHome(): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Driver;<br>方法or属性：waitForIdle(idleTime: number, timeout: number): Promise\<boolean>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Driver;<br>方法or属性：fling(from: Point, to: Point, stepLen: number, speed: number): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：Driver;<br>方法or属性：injectMultiPointerAction(pointers: PointerMatrix, speed?: number): Promise\<boolean>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiWindow;<br>方法or属性：getBundleName(): Promise\<string>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiWindow;<br>方法or属性：getTitle(): Promise\<string>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiWindow;<br>方法or属性：getWindowMode(): Promise\<WindowMode>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiWindow;<br>方法or属性：isActived(): Promise\<boolean>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiWindow;<br>方法or属性：focus(): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiWindow;<br>方法or属性：moveTo(x: number, y: number): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiWindow;<br>方法or属性：resize(wide: number, height: number, direction: ResizeDirection): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiWindow;<br>方法or属性：split(): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiWindow;<br>方法or属性：maximize(): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiWindow;<br>方法or属性：minimize(): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiWindow;<br>方法or属性：resume(): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：UiWindow;<br>方法or属性：close(): Promise\<void>;|@ohos.UiTest.d.ts|
|新增|NA|类名：PointerMatrix;<br>方法or属性：static create(fingers: number, steps: number): PointerMatrix;|@ohos.UiTest.d.ts|
|新增|NA|类名：PointerMatrix;<br>方法or属性：setPoint(finger: number, step: number, point: Point): void;|@ohos.UiTest.d.ts|
