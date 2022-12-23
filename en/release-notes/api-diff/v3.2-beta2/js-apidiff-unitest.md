# JS API Changes of the Test Subsystem

The table below lists the APIs changes of the test subsystem in OpenHarmony 3.2 Beta2 over OpenHarmony 3.2 Beta1.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.uitest | UiWindow | close():Promise\<bool>; | Added|
| ohos.uitest | UiWindow | resume():Promise\<bool>; | Added|
| ohos.uitest | UiWindow | minimize():Promise\<bool>; | Added|
| ohos.uitest | UiWindow | maximize():Promise\<bool>; | Added|
| ohos.uitest | UiWindow | split():Promise\<bool>; | Added|
| ohos.uitest | UiWindow | resize(wide: number, height: number, direction: ResizeDirection):Promise\<bool>; | Added|
| ohos.uitest | UiWindow | moveTo(x: number, y: number):Promise\<bool>; | Added|
| ohos.uitest | UiWindow | focus():Promise\<bool>; | Added|
| ohos.uitest | UiWindow | isActived():Promise\<bool>; | Added|
| ohos.uitest | UiWindow | isFocused():Promise\<bool>; | Added|
| ohos.uitest | UiWindow | getWindowMode():Promise\<WindowMode>; | Added|
| ohos.uitest | UiWindow | getTitle():Promise\<string>; | Added|
| ohos.uitest | UiWindow | getBounds():Promise\<Rect>; | Added|
| ohos.uitest | UiWindow | getBundleName():Promise\<string>; | Added|
| ohos.uitest | UiDriver | triggerCombineKeys(key0: number, key1: number, key2?: number): Promise\<void>; | Added|
| ohos.uitest | UiDriver | findWindow(filter:WindowFilter):Promise\<UiWindow>; | Added|
| ohos.uitest | UiComponent | pinchIn(scale: number): Promise\<void>; | Added|
| ohos.uitest | UiComponent | pinchOut(scale: number): Promise\<void>; | Added|
| ohos.uitest | UiComponent | getBoundsCenter(): Promise\<Point>; | Added|
| ohos.uitest | WindowFilter | readonly  actived?: bool; | Added|
| ohos.uitest | WindowFilter | readonly  focused?: bool; | Added|
| ohos.uitest | WindowFilter | readonly  title?: string; | Added|
| ohos.uitest | WindowFilter | readonly  bundleName?: string; | Added|
| ohos.uitest | Point | readonly  Y: number; | Added|
| ohos.uitest | Point | readonly  X: number; | Added|
| ohos.uitest | WindowMode | FLOATING | Added|
| ohos.uitest | WindowMode | SECONDARY | Added|
| ohos.uitest | WindowMode | PRIMARY | Added|
| ohos.uitest | WindowMode | FULLSCREEN | Added|
| ohos.uitest | ResizeDirection | RIGHT_DOWN | Added|
| ohos.uitest | ResizeDirection | RIGHT_UP | Added|
| ohos.uitest | ResizeDirection | LEFT_DOWN | Added|
| ohos.uitest | ResizeDirection | LEFT_UP | Added|
| ohos.uitest | ResizeDirection | DOWN | Added|
| ohos.uitest | ResizeDirection | UP | Added|
| ohos.uitest | ResizeDirection | RIGHT | Added|
| ohos.uitest | ResizeDirection | LEFT | Added|
| ohos.uitest | UiDriver | swipe(startx:number,starty:number,endx:number,endy:number):Promise\<void>; | Deprecated|
| ohos.uitest | UiDriver |old : drag(startx: number, starty: number, endx: number, endy: number): Promise\<void>;<br>new :  drag(startx: number, starty: number, endx: number, endy: number, speed?: number): Promise\<void>;| Updated|
| ohos.uitest | UiComponent |old : scrollToBottom(): Promise\<void>;<br>new : scrollToTop(speed?: number): Promise\<void>;| Updated|
| ohos.uitest | UiComponent |old : scrollToTop(): Promise\<void>;<br>new : scrollToTop(speed?: number): Promise\<void>; | Updated|
