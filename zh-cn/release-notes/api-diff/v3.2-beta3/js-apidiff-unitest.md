# 测试框架子系统JS API变更

OpenHarmony 3.2 Beta3版本相较于OpenHarmony 3.2 Beta2版本，测试框架子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.uitest | PointerMatrix   | setPoint(finger: number, step: number, point: Point):void;                          | 新增 |
| ohos.uitest | PointerMatrix   | static create(fingers: number, steps: number):PointerMatrix;                        | 新增 |
| ohos.uitest | UiDriver        | injectMultiPointerAction(pointers: PointerMatrix, speed?: number):Promise\<boolean>; | 新增 |
| ohos.uitest | UiDriver        | fling(from: Point, to: Point, stepLen: number, speed: number):Promise\<void>;       | 新增 |
| ohos.uitest | UiDriver        | waitForIdle(idleTime: number, timeout: number):Promise\<boolean>;                   | 新增 |
| ohos.uitest | UiDriver        | pressHome():Promise\<void>;                                                         | 新增 |
| ohos.uitest | UiDriver        | wakeUpDisplay():Promise\<void>;                                                     | 新增 |
| ohos.uitest | UiDriver        | getDisplayDensity():Promise\<Point>;                                                | 新增 |
| ohos.uitest | UiDriver        | getDisplaySize():Promise\<Point>;                                                   | 新增 |
| ohos.uitest | UiDriver        | setDisplayRotationEnabled(enabled:boolean):Promise\<void>;                          | 新增 |
| ohos.uitest | UiDriver        | getDisplayRotation():Promise\<DisplayRotation>;                                     | 新增 |
| ohos.uitest | UiDriver        | setDisplayRotation(rotation: DisplayRotation):Promise\<void>;                       | 新增 |
| ohos.uitest | DisplayRotation | ROTATION_270                                                                        | 新增 |
| ohos.uitest | DisplayRotation | ROTATION_180                                                                        | 新增 |
| ohos.uitest | DisplayRotation | ROTATION_90                                                                         | 新增 |
| ohos.uitest | DisplayRotation | ROTATION_0                                                                          | 新增 |
