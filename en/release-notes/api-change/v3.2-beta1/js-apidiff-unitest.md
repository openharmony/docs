# JS API Changes of the Test Subsystem

The table below lists the APIs changes of the test subsystem in OpenHarmony 3.2 Beta1 over OpenHarmony 3.1 Release.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.uitest | UiDriver | drag(startx: number, starty: number, endx: number, endy: number): Promise\<void>; | Added|
| ohos.uitest | UiDriver | waitForComponent(by: By, time: number): Promise\<UiComponent>; | Added|
| ohos.uitest | UiComponent | dragTo(target: UiComponent): Promise\<void>; | Added|
| ohos.uitest | UiComponent | getBounds(): Promise\<Rect>; | Added|
| ohos.uitest | UiComponent | scrollToBottom(): Promise\<void>; | Added|
| ohos.uitest | UiComponent | scrollToTop(): Promise\<void>; | Added|
| ohos.uitest | UiComponent | clearText(): Promise\<void>; | Added|
| ohos.uitest | UiComponent | isCheckable(): Promise\<bool>; | Added|
| ohos.uitest | UiComponent | isChecked(): Promise\<bool>; | Added|
| ohos.uitest | UiComponent | isLongClickable(): Promise\<bool>; | Added|
| ohos.uitest | By | checkable(b?: bool): By; | Added|
| ohos.uitest | By | checked(b?: bool): By; | Added|
| ohos.uitest | By | longClickable(b?: bool): By; | Added|
| ohos.uitest | Rect | readonly  bottomY: number; | Added|
| ohos.uitest | Rect | readonly  rightX: number; | Added|
| ohos.uitest | Rect | readonly  topY: number; | Added|
| ohos.uitest | Rect | readonly  leftX: number; | Added|
