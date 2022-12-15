# 测试框架子系统JS API变更

OpenHarmony 3.2 Beta1版本相较于OpenHarmony 3.1 Release版本，测试框架子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.uitest | UiDriver | drag(startx: number, starty: number, endx: number, endy: number): Promise\<void>; | 新增 |
| ohos.uitest | UiDriver | waitForComponent(by: By, time: number): Promise\<UiComponent>; | 新增 |
| ohos.uitest | UiComponent | dragTo(target: UiComponent): Promise\<void>; | 新增 |
| ohos.uitest | UiComponent | getBounds(): Promise\<Rect>; | 新增 |
| ohos.uitest | UiComponent | scrollToBottom(): Promise\<void>; | 新增 |
| ohos.uitest | UiComponent | scrollToTop(): Promise\<void>; | 新增 |
| ohos.uitest | UiComponent | clearText(): Promise\<void>; | 新增 |
| ohos.uitest | UiComponent | isCheckable(): Promise\<bool>; | 新增 |
| ohos.uitest | UiComponent | isChecked(): Promise\<bool>; | 新增 |
| ohos.uitest | UiComponent | isLongClickable(): Promise\<bool>; | 新增 |
| ohos.uitest | By | checkable(b?: bool): By; | 新增 |
| ohos.uitest | By | checked(b?: bool): By; | 新增 |
| ohos.uitest | By | longClickable(b?: bool): By; | 新增 |
| ohos.uitest | Rect | readonly  bottomY: number; | 新增 |
| ohos.uitest | Rect | readonly  rightX: number; | 新增 |
| ohos.uitest | Rect | readonly  topY: number; | 新增 |
| ohos.uitest | Rect | readonly  leftX: number; | 新增 |

