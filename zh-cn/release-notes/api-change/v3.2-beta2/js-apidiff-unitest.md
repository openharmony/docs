# 测试框架子系统JS API变更

OpenHarmony 3.2 Beta2版本相较于OpenHarmony 3.2 Beta1版本，测试框架子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.uitest | UiWindow | close():Promise\<bool>; | 新增 |
| ohos.uitest | UiWindow | resume():Promise\<bool>; | 新增 |
| ohos.uitest | UiWindow | minimize():Promise\<bool>; | 新增 |
| ohos.uitest | UiWindow | maximize():Promise\<bool>; | 新增 |
| ohos.uitest | UiWindow | split():Promise\<bool>; | 新增 |
| ohos.uitest | UiWindow | resize(wide: number, height: number, direction: ResizeDirection):Promise\<bool>; | 新增 |
| ohos.uitest | UiWindow | moveTo(x: number, y: number):Promise\<bool>; | 新增 |
| ohos.uitest | UiWindow | focus():Promise\<bool>; | 新增 |
| ohos.uitest | UiWindow | isActived():Promise\<bool>; | 新增 |
| ohos.uitest | UiWindow | isFocused():Promise\<bool>; | 新增 |
| ohos.uitest | UiWindow | getWindowMode():Promise\<WindowMode>; | 新增 |
| ohos.uitest | UiWindow | getTitle():Promise\<string>; | 新增 |
| ohos.uitest | UiWindow | getBounds():Promise\<Rect>; | 新增 |
| ohos.uitest | UiWindow | getBundleName():Promise\<string>; | 新增 |
| ohos.uitest | UiDriver | triggerCombineKeys(key0: number, key1: number, key2?: number): Promise\<void>; | 新增 |
| ohos.uitest | UiDriver | findWindow(filter:WindowFilter):Promise\<UiWindow>; | 新增 |
| ohos.uitest | UiComponent | pinchIn(scale: number): Promise\<void>; | 新增 |
| ohos.uitest | UiComponent | pinchOut(scale: number): Promise\<void>; | 新增 |
| ohos.uitest | UiComponent | getBoundsCenter(): Promise\<Point>; | 新增 |
| ohos.uitest | WindowFilter | readonly  actived?: bool; | 新增 |
| ohos.uitest | WindowFilter | readonly  focused?: bool; | 新增 |
| ohos.uitest | WindowFilter | readonly  title?: string; | 新增 |
| ohos.uitest | WindowFilter | readonly  bundleName?: string; | 新增 |
| ohos.uitest | Point | readonly  Y: number; | 新增 |
| ohos.uitest | Point | readonly  X: number; | 新增 |
| ohos.uitest | WindowMode | FLOATING | 新增 |
| ohos.uitest | WindowMode | SECONDARY | 新增 |
| ohos.uitest | WindowMode | PRIMARY | 新增 |
| ohos.uitest | WindowMode | FULLSCREEN | 新增 |
| ohos.uitest | ResizeDirection | RIGHT_DOWN | 新增 |
| ohos.uitest | ResizeDirection | RIGHT_UP | 新增 |
| ohos.uitest | ResizeDirection | LEFT_DOWN | 新增 |
| ohos.uitest | ResizeDirection | LEFT_UP | 新增 |
| ohos.uitest | ResizeDirection | DOWN | 新增 |
| ohos.uitest | ResizeDirection | UP | 新增 |
| ohos.uitest | ResizeDirection | RIGHT | 新增 |
| ohos.uitest | ResizeDirection | LEFT | 新增 |
| ohos.uitest | UiDriver | swipe(startx:number,starty:number,endx:number,endy:number):Promise\<void>; | 废弃 |
| ohos.uitest | UiDriver |old : drag(startx: number, starty: number, endx: number, endy: number): Promise\<void>;<br>new :  drag(startx: number, starty: number, endx: number, endy: number, speed?: number): Promise\<void>;| 变更 |
| ohos.uitest | UiComponent |old : scrollToBottom(): Promise\<void>;<br>new : scrollToTop(speed?: number): Promise\<void>;| 变更 |
| ohos.uitest | UiComponent |old : scrollToTop(): Promise\<void>;<br>new : scrollToTop(speed?: number): Promise\<void>; | 变更 |

