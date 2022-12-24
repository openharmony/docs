# JS API Changes of the Test Subsystem

The table below lists the APIs changes of the test subsystem in OpenHarmony 3.2 Beta3 over OpenHarmony 3.2 Beta2.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.uitest | PointerMatrix   | setPoint(finger: number, step: number, point: Point):void;                          | Added|
| ohos.uitest | PointerMatrix   | static create(fingers: number, steps: number):PointerMatrix;                        | Added|
| ohos.uitest | UiDriver        | injectMultiPointerAction(pointers: PointerMatrix, speed?: number):Promise\<boolean>; | Added|
| ohos.uitest | UiDriver        | fling(from: Point, to: Point, stepLen: number, speed: number):Promise\<void>;       | Added|
| ohos.uitest | UiDriver        | waitForIdle(idleTime: number, timeout: number):Promise\<boolean>;                   | Added|
| ohos.uitest | UiDriver        | pressHome():Promise\<void>;                                                         | Added|
| ohos.uitest | UiDriver        | wakeUpDisplay():Promise\<void>;                                                     | Added|
| ohos.uitest | UiDriver        | getDisplayDensity():Promise\<Point>;                                                | Added|
| ohos.uitest | UiDriver        | getDisplaySize():Promise\<Point>;                                                   | Added|
| ohos.uitest | UiDriver        | setDisplayRotationEnabled(enabled:boolean):Promise\<void>;                          | Added|
| ohos.uitest | UiDriver        | getDisplayRotation():Promise\<DisplayRotation>;                                     | Added|
| ohos.uitest | UiDriver        | setDisplayRotation(rotation: DisplayRotation):Promise\<void>;                       | Added|
| ohos.uitest | DisplayRotation | ROTATION_270                                                                        | Added|
| ohos.uitest | DisplayRotation | ROTATION_180                                                                        | Added|
| ohos.uitest | DisplayRotation | ROTATION_90                                                                         | Added|
| ohos.uitest | DisplayRotation | ROTATION_0                                                                          | Added|
