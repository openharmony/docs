| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Deleted|Class name: MatchPattern;<br>Method or attribute name: EQUALS = 0|NA|@ohos.uitest.d.ts|
|Deleted|Class name: MatchPattern;<br>Method or attribute name: CONTAINS = 1|NA|@ohos.uitest.d.ts|
|Deleted|Class name: MatchPattern;<br>Method or attribute name: STARTS_WITH = 2|NA|@ohos.uitest.d.ts|
|Deleted|Class name: MatchPattern;<br>Method or attribute name: ENDS_WITH = 3|NA|@ohos.uitest.d.ts|
|Deleted|Class name: By;<br>Method or attribute name: text(txt:string,pattern?:MatchPattern):By;|NA|@ohos.uitest.d.ts|
|Deleted|Class name: By;<br>Method or attribute name: key(key:string):By;|NA|@ohos.uitest.d.ts|
|Deleted|Class name: By;<br>Method or attribute name: id(id:number):By;|NA|@ohos.uitest.d.ts|
|Deleted|Class name: By;<br>Method or attribute name: type(tp:string):By;|NA|@ohos.uitest.d.ts|
|Deleted|Class name: By;<br>Method or attribute name: clickable(b?:bool):By;|NA|@ohos.uitest.d.ts|
|Deleted|Class name: By;<br>Method or attribute name: scrollable(b?:bool):By;|NA|@ohos.uitest.d.ts|
|Deleted|Class name: By;<br>Method or attribute name: enabled(b?:bool):By;|NA|@ohos.uitest.d.ts|
|Deleted|Class name: By;<br>Method or attribute name: focused(b?:bool):By;|NA|@ohos.uitest.d.ts|
|Deleted|Class name: By;<br>Method or attribute name: selected(b?:bool):By;|NA|@ohos.uitest.d.ts|
|Deleted|Class name: By;<br>Method or attribute name: isBefore(by:By):By;|NA|@ohos.uitest.d.ts|
|Deleted|Class name: By;<br>Method or attribute name: isAfter(by:By):By;|NA|@ohos.uitest.d.ts|
|Deleted|Class name: UiComponent;<br>Method or attribute name: click():Promise\<void>;|NA|@ohos.uitest.d.ts|
|Deleted|Class name: UiComponent;<br>Method or attribute name: doubleClick():Promise\<void>;|NA|@ohos.uitest.d.ts|
|Deleted|Class name: UiComponent;<br>Method or attribute name: longClick():Promise\<void>;|NA|@ohos.uitest.d.ts|
|Deleted|Class name: UiComponent;<br>Method or attribute name: getId():Promise\<number>;|NA|@ohos.uitest.d.ts|
|Deleted|Class name: UiComponent;<br>Method or attribute name: getKey():Promise\<string>;|NA|@ohos.uitest.d.ts|
|Deleted|Class name: UiComponent;<br>Method or attribute name: getText():Promise\<string>;|NA|@ohos.uitest.d.ts|
|Deleted|Class name: UiComponent;<br>Method or attribute name: getType():Promise\<string>;|NA|@ohos.uitest.d.ts|
|Deleted|Class name: UiComponent;<br>Method or attribute name: isClickable():Promise\<bool>;|NA|@ohos.uitest.d.ts|
|Deleted|Class name: UiComponent;<br>Method or attribute name: isScrollable():Promise\<bool>;|NA|@ohos.uitest.d.ts|
|Deleted|Class name: UiComponent;<br>Method or attribute name: isEnabled():Promise\<bool>;|NA|@ohos.uitest.d.ts|
|Deleted|Class name: UiComponent;<br>Method or attribute name: isFocused():Promise\<bool>;|NA|@ohos.uitest.d.ts|
|Deleted|Class name: UiComponent;<br>Method or attribute name: isSelected():Promise\<bool>;|NA|@ohos.uitest.d.ts|
|Deleted|Class name: UiComponent;<br>Method or attribute name: inputText(text: string):Promise\<void>;|NA|@ohos.uitest.d.ts|
|Deleted|Class name: UiComponent;<br>Method or attribute name: scrollSearch(by:By):Promise\<UiComponent>;|NA|@ohos.uitest.d.ts|
|Deleted|Class name: UiDriver;<br>Method or attribute name: static create():UiDriver;|NA|@ohos.uitest.d.ts|
|Deleted|Class name: UiDriver;<br>Method or attribute name: delayMs(duration:number):Promise\<void>;|NA|@ohos.uitest.d.ts|
|Deleted|Class name: UiDriver;<br>Method or attribute name: findComponent(by:By):Promise\<UiComponent>;|NA|@ohos.uitest.d.ts|
|Deleted|Class name: UiDriver;<br>Method or attribute name: findComponents(by:By):Promise\<Array\<UiComponent>>;|NA|@ohos.uitest.d.ts|
|Deleted|Class name: UiDriver;<br>Method or attribute name: assertComponentExist(by:By):Promise\<void>;|NA|@ohos.uitest.d.ts|
|Deleted|Class name: UiDriver;<br>Method or attribute name: pressBack():Promise\<void>;|NA|@ohos.uitest.d.ts|
|Deleted|Class name: UiDriver;<br>Method or attribute name: triggerKey(keyCode:number):Promise\<void>;|NA|@ohos.uitest.d.ts|
|Deleted|Class name: UiDriver;<br>Method or attribute name: click(x:number,y:number):Promise\<void>;|NA|@ohos.uitest.d.ts|
|Deleted|Class name: UiDriver;<br>Method or attribute name: doubleClick(x:number,y:number):Promise\<void>;|NA|@ohos.uitest.d.ts|
|Deleted|Class name: UiDriver;<br>Method or attribute name: longClick(x:number,y:number):Promise\<void>;|NA|@ohos.uitest.d.ts|
|Deleted|Class name: UiDriver;<br>Method or attribute name: swipe(startx:number,starty:number,endx:number,endy:number):Promise\<void>;|NA|@ohos.uitest.d.ts|
|Deleted|Class name: UiDriver;<br>Method or attribute name: screenCap(savePath:string):Promise\<bool>;|NA|@ohos.uitest.d.ts|
|Added|NA|Class name: MatchPattern;<br>Method or attribute name: EQUALS = 0|@ohos.UiTest.d.ts|
|Added|NA|Class name: MatchPattern;<br>Method or attribute name: CONTAINS = 1|@ohos.UiTest.d.ts|
|Added|NA|Class name: MatchPattern;<br>Method or attribute name: STARTS_WITH = 2|@ohos.UiTest.d.ts|
|Added|NA|Class name: MatchPattern;<br>Method or attribute name: ENDS_WITH = 3|@ohos.UiTest.d.ts|
|Added|NA|Class name: By;<br>Method or attribute name: text(txt: string, pattern?: MatchPattern): By;|@ohos.UiTest.d.ts|
|Added|NA|Class name: By;<br>Method or attribute name: key(key: string): By;|@ohos.UiTest.d.ts|
|Added|NA|Class name: By;<br>Method or attribute name: id(id: number): By;|@ohos.UiTest.d.ts|
|Added|NA|Class name: By;<br>Method or attribute name: type(tp: string): By;|@ohos.UiTest.d.ts|
|Added|NA|Class name: By;<br>Method or attribute name: clickable(b?: boolean): By;|@ohos.UiTest.d.ts|
|Added|NA|Class name: By;<br>Method or attribute name: scrollable(b?: boolean): By;|@ohos.UiTest.d.ts|
|Added|NA|Class name: By;<br>Method or attribute name: enabled(b?: boolean): By;|@ohos.UiTest.d.ts|
|Added|NA|Class name: By;<br>Method or attribute name: focused(b?: boolean): By;|@ohos.UiTest.d.ts|
|Added|NA|Class name: By;<br>Method or attribute name: selected(b?: boolean): By;|@ohos.UiTest.d.ts|
|Added|NA|Class name: By;<br>Method or attribute name: isBefore(by: By): By;|@ohos.UiTest.d.ts|
|Added|NA|Class name: By;<br>Method or attribute name: isAfter(by: By): By;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiComponent;<br>Method or attribute name: click(): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Component;<br>Method or attribute name: click(): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiComponent;<br>Method or attribute name: doubleClick(): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Component;<br>Method or attribute name: doubleClick(): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiComponent;<br>Method or attribute name: longClick(): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Component;<br>Method or attribute name: longClick(): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiComponent;<br>Method or attribute name: getId(): Promise\<number>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiComponent;<br>Method or attribute name: getKey(): Promise\<string>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiComponent;<br>Method or attribute name: getText(): Promise\<string>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Component;<br>Method or attribute name: getText(): Promise\<string>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiComponent;<br>Method or attribute name: getType(): Promise\<string>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Component;<br>Method or attribute name: getType(): Promise\<string>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiComponent;<br>Method or attribute name: isClickable(): Promise\<boolean>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Component;<br>Method or attribute name: isClickable(): Promise\<boolean>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiComponent;<br>Method or attribute name: isScrollable(): Promise\<boolean>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Component;<br>Method or attribute name: isScrollable(): Promise\<boolean>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiComponent;<br>Method or attribute name: isEnabled(): Promise\<boolean>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Component;<br>Method or attribute name: isEnabled(): Promise\<boolean>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiComponent;<br>Method or attribute name: isFocused(): Promise\<boolean>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Component;<br>Method or attribute name: isFocused(): Promise\<boolean>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiWindow;<br>Method or attribute name: isFocused(): Promise\<boolean>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiComponent;<br>Method or attribute name: isSelected(): Promise\<boolean>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Component;<br>Method or attribute name: isSelected(): Promise\<boolean>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiComponent;<br>Method or attribute name: inputText(text: string): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Component;<br>Method or attribute name: inputText(text: string): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiComponent;<br>Method or attribute name: scrollSearch(by: By): Promise\<UiComponent>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiDriver;<br>Method or attribute name: static create(): UiDriver;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiDriver;<br>Method or attribute name: delayMs(duration: number): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Driver;<br>Method or attribute name: delayMs(duration: number): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiDriver;<br>Method or attribute name: findComponent(by: By): Promise\<UiComponent>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiDriver;<br>Method or attribute name: findComponents(by: By): Promise\<Array\<UiComponent>>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiDriver;<br>Method or attribute name: assertComponentExist(by: By): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiDriver;<br>Method or attribute name: pressBack(): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Driver;<br>Method or attribute name: pressBack(): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiDriver;<br>Method or attribute name: triggerKey(keyCode: number): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Driver;<br>Method or attribute name: triggerKey(keyCode: number): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiDriver;<br>Method or attribute name: click(x: number, y: number): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Driver;<br>Method or attribute name: click(x: number, y: number): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiDriver;<br>Method or attribute name: doubleClick(x: number, y: number): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Driver;<br>Method or attribute name: doubleClick(x: number, y: number): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiDriver;<br>Method or attribute name: longClick(x: number, y: number): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Driver;<br>Method or attribute name: longClick(x: number, y: number): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiDriver;<br>Method or attribute name: swipe(startx: number, starty: number, endx: number, endy: number): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiDriver;<br>Method or attribute name: screenCap(savePath: string): Promise\<boolean>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Driver;<br>Method or attribute name: screenCap(savePath: string): Promise\<boolean>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: WindowMode;<br>Method or attribute name: FULLSCREEN = 0|@ohos.UiTest.d.ts|
|Added|NA|Class name: WindowMode;<br>Method or attribute name: PRIMARY = 1|@ohos.UiTest.d.ts|
|Added|NA|Class name: WindowMode;<br>Method or attribute name: SECONDARY = 2|@ohos.UiTest.d.ts|
|Added|NA|Class name: WindowMode;<br>Method or attribute name: FLOATING = 3|@ohos.UiTest.d.ts|
|Added|NA|Class name: ResizeDirection;<br>Method or attribute name: LEFT = 0|@ohos.UiTest.d.ts|
|Added|NA|Class name: ResizeDirection;<br>Method or attribute name: RIGHT = 1|@ohos.UiTest.d.ts|
|Added|NA|Class name: ResizeDirection;<br>Method or attribute name: UP = 2|@ohos.UiTest.d.ts|
|Added|NA|Class name: ResizeDirection;<br>Method or attribute name: DOWN = 3|@ohos.UiTest.d.ts|
|Added|NA|Class name: ResizeDirection;<br>Method or attribute name: LEFT_UP = 4|@ohos.UiTest.d.ts|
|Added|NA|Class name: ResizeDirection;<br>Method or attribute name: LEFT_DOWN = 5|@ohos.UiTest.d.ts|
|Added|NA|Class name: ResizeDirection;<br>Method or attribute name: RIGHT_UP = 6|@ohos.UiTest.d.ts|
|Added|NA|Class name: ResizeDirection;<br>Method or attribute name: RIGHT_DOWN = 7|@ohos.UiTest.d.ts|
|Added|NA|Class name: DisplayRotation;<br>Method or attribute name: ROTATION_0 = 0|@ohos.UiTest.d.ts|
|Added|NA|Class name: DisplayRotation;<br>Method or attribute name: ROTATION_90 = 1|@ohos.UiTest.d.ts|
|Added|NA|Class name: DisplayRotation;<br>Method or attribute name: ROTATION_180 = 2|@ohos.UiTest.d.ts|
|Added|NA|Class name: DisplayRotation;<br>Method or attribute name: ROTATION_270 = 3|@ohos.UiTest.d.ts|
|Added|NA|Class name: Point;<br>Method or attribute name: readonly x: number;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Point;<br>Method or attribute name: readonly y: number;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Rect;<br>Method or attribute name: readonly left: number;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Rect;<br>Method or attribute name: readonly top: number;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Rect;<br>Method or attribute name: readonly right: number;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Rect;<br>Method or attribute name: readonly bottom: number;|@ohos.UiTest.d.ts|
|Added|NA|Class name: WindowFilter;<br>Method or attribute name: bundleName?: string;|@ohos.UiTest.d.ts|
|Added|NA|Class name: WindowFilter;<br>Method or attribute name: title?: string;|@ohos.UiTest.d.ts|
|Added|NA|Class name: WindowFilter;<br>Method or attribute name: focused?: boolean;|@ohos.UiTest.d.ts|
|Added|NA|Class name: WindowFilter;<br>Method or attribute name: actived?: boolean;|@ohos.UiTest.d.ts|
|Added|NA|Class name: On;<br>Method or attribute name: text(txt: string, pattern?: MatchPattern): On;|@ohos.UiTest.d.ts|
|Added|NA|Class name: On;<br>Method or attribute name: id(id: string): On;|@ohos.UiTest.d.ts|
|Added|NA|Class name: On;<br>Method or attribute name: type(tp: string): On;|@ohos.UiTest.d.ts|
|Added|NA|Class name: On;<br>Method or attribute name: clickable(b?: boolean): On;|@ohos.UiTest.d.ts|
|Added|NA|Class name: On;<br>Method or attribute name: longClickable(b?: boolean): On;|@ohos.UiTest.d.ts|
|Added|NA|Class name: On;<br>Method or attribute name: scrollable(b?: boolean): On;|@ohos.UiTest.d.ts|
|Added|NA|Class name: On;<br>Method or attribute name: enabled(b?: boolean): On;|@ohos.UiTest.d.ts|
|Added|NA|Class name: On;<br>Method or attribute name: focused(b?: boolean): On;|@ohos.UiTest.d.ts|
|Added|NA|Class name: On;<br>Method or attribute name: selected(b?: boolean): On;|@ohos.UiTest.d.ts|
|Added|NA|Class name: On;<br>Method or attribute name: checked(b?: boolean): On;|@ohos.UiTest.d.ts|
|Added|NA|Class name: On;<br>Method or attribute name: checkable(b?: boolean): On;|@ohos.UiTest.d.ts|
|Added|NA|Class name: On;<br>Method or attribute name: isBefore(on: On): On;|@ohos.UiTest.d.ts|
|Added|NA|Class name: On;<br>Method or attribute name: isAfter(on: On): On;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Component;<br>Method or attribute name: getId(): Promise\<string>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Component;<br>Method or attribute name: isLongClickable(): Promise\<boolean>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Component;<br>Method or attribute name: isChecked(): Promise\<boolean>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Component;<br>Method or attribute name: isCheckable(): Promise\<boolean>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Component;<br>Method or attribute name: clearText(): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Component;<br>Method or attribute name: scrollToTop(speed?: number): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Component;<br>Method or attribute name: scrollToBottom(speed?: number): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Component;<br>Method or attribute name: scrollSearch(on: On): Promise\<Component>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Component;<br>Method or attribute name: getBounds(): Promise\<Rect>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiWindow;<br>Method or attribute name: getBounds(): Promise\<Rect>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Component;<br>Method or attribute name: getBoundsCenter(): Promise\<Point>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Component;<br>Method or attribute name: dragTo(target: Component): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Component;<br>Method or attribute name: pinchOut(scale: number): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Component;<br>Method or attribute name: pinchIn(scale: number): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Driver;<br>Method or attribute name: static create(): Driver;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Driver;<br>Method or attribute name: findComponent(on: On): Promise\<Component>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Driver;<br>Method or attribute name: findWindow(filter: WindowFilter): Promise\<UiWindow>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Driver;<br>Method or attribute name: waitForComponent(on: On, time: number): Promise\<Component>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Driver;<br>Method or attribute name: findComponents(on: On): Promise\<Array\<Component>>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Driver;<br>Method or attribute name: assertComponentExist(on: On): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Driver;<br>Method or attribute name: triggerCombineKeys(key0: number, key1: number, key2?: number): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Driver;<br>Method or attribute name: swipe(startx: number, starty: number, endx: number, endy: number, speed?: number): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Driver;<br>Method or attribute name: drag(startx: number, starty: number, endx: number, endy: number, speed?: number): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Driver;<br>Method or attribute name: setDisplayRotation(rotation: DisplayRotation): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Driver;<br>Method or attribute name: getDisplayRotation(): Promise\<DisplayRotation>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Driver;<br>Method or attribute name: setDisplayRotationEnabled(enabled: boolean): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Driver;<br>Method or attribute name: getDisplaySize(): Promise\<Point>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Driver;<br>Method or attribute name: getDisplayDensity(): Promise\<Point>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Driver;<br>Method or attribute name: wakeUpDisplay(): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Driver;<br>Method or attribute name: pressHome(): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Driver;<br>Method or attribute name: waitForIdle(idleTime: number, timeout: number): Promise\<boolean>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Driver;<br>Method or attribute name: fling(from: Point, to: Point, stepLen: number, speed: number): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: Driver;<br>Method or attribute name: injectMultiPointerAction(pointers: PointerMatrix, speed?: number): Promise\<boolean>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiWindow;<br>Method or attribute name: getBundleName(): Promise\<string>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiWindow;<br>Method or attribute name: getTitle(): Promise\<string>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiWindow;<br>Method or attribute name: getWindowMode(): Promise\<WindowMode>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiWindow;<br>Method or attribute name: isActived(): Promise\<boolean>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiWindow;<br>Method or attribute name: focus(): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiWindow;<br>Method or attribute name: moveTo(x: number, y: number): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiWindow;<br>Method or attribute name: resize(wide: number, height: number, direction: ResizeDirection): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiWindow;<br>Method or attribute name: split(): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiWindow;<br>Method or attribute name: maximize(): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiWindow;<br>Method or attribute name: minimize(): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiWindow;<br>Method or attribute name: resume(): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: UiWindow;<br>Method or attribute name: close(): Promise\<void>;|@ohos.UiTest.d.ts|
|Added|NA|Class name: PointerMatrix;<br>Method or attribute name: static create(fingers: number, steps: number): PointerMatrix;|@ohos.UiTest.d.ts|
|Added|NA|Class name: PointerMatrix;<br>Method or attribute name: setPoint(finger: number, step: number, point: Point): void;|@ohos.UiTest.d.ts|
