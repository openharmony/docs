# 测试框架子系统JS API变更

OpenHarmony 3.1 Release版本相较于OpenHarmony 3.0 LTS版本，测试框架子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.uitest | UiDriver | screenCap(savePath:string):Promise\<bool>; | 新增 |
| ohos.uitest | UiDriver | swipe(startx:number,starty:number,endx:number,endy:number):Promise\<void>; | 新增 |
| ohos.uitest | UiDriver | longClick(x:number,y:number):Promise\<void>; | 新增 |
| ohos.uitest | UiDriver | doubleClick(x:number,y:number):Promise\<void>; | 新增 |
| ohos.uitest | UiDriver | click(x:number,y:number):Promise\<void>; | 新增 |
| ohos.uitest | UiDriver | triggerKey(keyCode:number):Promise\<void>; | 新增 |
| ohos.uitest | UiDriver | pressBack():Promise\<void>; | 新增 |
| ohos.uitest | UiDriver | assertComponentExist(by:By):Promise\<void>; | 新增 |
| ohos.uitest | UiDriver | findComponents(by:By):Promise\<Array\<UiComponent>>; | 新增 |
| ohos.uitest | UiDriver | findComponent(by:By):Promise\<UiComponent>; | 新增 |
| ohos.uitest | UiDriver | delayMs(duration:number):Promise\<void>; | 新增 |
| ohos.uitest | UiDriver | static create():UiDriver; | 新增 |
| ohos.uitest | UiComponent | scrollSearch(by:By):Promise\<UiComponent>; | 新增 |
| ohos.uitest | UiComponent | inputText(text: string):Promise\<void>; | 新增 |
| ohos.uitest | UiComponent | isSelected():Promise\<bool>; | 新增 |
| ohos.uitest | UiComponent | isFocused():Promise\<bool>; | 新增 |
| ohos.uitest | UiComponent | isEnabled():Promise\<bool>; | 新增 |
| ohos.uitest | UiComponent | isScrollable():Promise\<bool>; | 新增 |
| ohos.uitest | UiComponent | isClickable():Promise\<bool>; | 新增 |
| ohos.uitest | UiComponent | getType():Promise\<string>; | 新增 |
| ohos.uitest | UiComponent | getText():Promise\<string>; | 新增 |
| ohos.uitest | UiComponent | getKey():Promise\<string>; | 新增 |
| ohos.uitest | UiComponent | getId():Promise\<number>; | 新增 |
| ohos.uitest | UiComponent | longClick():Promise\<void>; | 新增 |
| ohos.uitest | UiComponent | doubleClick():Promise\<void>; | 新增 |
| ohos.uitest | UiComponent | click():Promise\<void>; | 新增 |
| ohos.uitest | By | isAfter(by:By):By; | 新增 |
| ohos.uitest | By | isBefore(by:By):By; | 新增 |
| ohos.uitest | By | selected(b?:bool):By; | 新增 |
| ohos.uitest | By | focused(b?:bool):By; | 新增 |
| ohos.uitest | By | enabled(b?:bool):By; | 新增 |
| ohos.uitest | By | scrollable(b?:bool):By; | 新增 |
| ohos.uitest | By | clickable(b?:bool):By; | 新增 |
| ohos.uitest | By | type(tp:string):By; | 新增 |
| ohos.uitest | By | id(id:number):By; | 新增 |
| ohos.uitest | By | key(key:string):By; | 新增 |
| ohos.uitest | By | text(txt:string,pattern?:MatchPattern):By; | 新增 |
| ohos.uitest | MatchPattern | ENDS_WITH = 3 | 新增 |
| ohos.uitest | MatchPattern | STARTS_WITH = 2 | 新增 |
| ohos.uitest | MatchPattern | CONTAINS = 1 | 新增 |
| ohos.uitest | MatchPattern | EQUALS = 0 | 新增 |
