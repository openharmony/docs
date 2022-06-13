# JS API Changes of the Testing Framework Subsystem

The table below lists the APIs changes of the testing framework subsystem in OpenHarmony 3.1 Release over OpenHarmony 3.0 LTS.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.uitest | UiDriver | screenCap(savePath:string):Promise\<bool>; | Added|
| ohos.uitest | UiDriver | swipe(startx:number,starty:number,endx:number,endy:number):Promise\<void>; | Added|
| ohos.uitest | UiDriver | longClick(x:number,y:number):Promise\<void>; | Added|
| ohos.uitest | UiDriver | doubleClick(x:number,y:number):Promise\<void>; | Added|
| ohos.uitest | UiDriver | click(x:number,y:number):Promise\<void>; | Added|
| ohos.uitest | UiDriver | triggerKey(keyCode:number):Promise\<void>; | Added|
| ohos.uitest | UiDriver | pressBack():Promise\<void>; | Added|
| ohos.uitest | UiDriver | assertComponentExist(by:By):Promise\<void>; | Added|
| ohos.uitest | UiDriver | findComponents(by:By):Promise\<Array\<UiComponent>>; | Added|
| ohos.uitest | UiDriver | findComponent(by:By):Promise\<UiComponent>; | Added|
| ohos.uitest | UiDriver | delayMs(duration:number):Promise\<void>; | Added|
| ohos.uitest | UiDriver | static create():UiDriver; | Added|
| ohos.uitest | UiComponent | scrollSearch(by:By):Promise\<UiComponent>; | Added|
| ohos.uitest | UiComponent | inputText(text: string):Promise\<void>; | Added|
| ohos.uitest | UiComponent | isSelected():Promise\<bool>; | Added|
| ohos.uitest | UiComponent | isFocused():Promise\<bool>; | Added|
| ohos.uitest | UiComponent | isEnabled():Promise\<bool>; | Added|
| ohos.uitest | UiComponent | isScrollable():Promise\<bool>; | Added|
| ohos.uitest | UiComponent | isClickable():Promise\<bool>; | Added|
| ohos.uitest | UiComponent | getType():Promise\<string>; | Added|
| ohos.uitest | UiComponent | getText():Promise\<string>; | Added|
| ohos.uitest | UiComponent | getKey():Promise\<string>; | Added|
| ohos.uitest | UiComponent | getId():Promise\<number>; | Added|
| ohos.uitest | UiComponent | longClick():Promise\<void>; | Added|
| ohos.uitest | UiComponent | doubleClick():Promise\<void>; | Added|
| ohos.uitest | UiComponent | click():Promise\<void>; | Added|
| ohos.uitest | By | isAfter(by:By):By; | Added|
| ohos.uitest | By | isBefore(by:By):By; | Added|
| ohos.uitest | By | selected(b?:bool):By; | Added|
| ohos.uitest | By | focused(b?:bool):By; | Added|
| ohos.uitest | By | enabled(b?:bool):By; | Added|
| ohos.uitest | By | scrollable(b?:bool):By; | Added|
| ohos.uitest | By | clickable(b?:bool):By; | Added|
| ohos.uitest | By | type(tp:string):By; | Added|
| ohos.uitest | By | id(id:number):By; | Added|
| ohos.uitest | By | key(key:string):By; | Added|
| ohos.uitest | By | text(txt:string,pattern?:MatchPattern):By; | Added|
| ohos.uitest | MatchPattern | ENDS_WITH = 3 | Added|
| ohos.uitest | MatchPattern | STARTS_WITH = 2 | Added|
| ohos.uitest | MatchPattern | CONTAINS = 1 | Added|
| ohos.uitest | MatchPattern | EQUALS = 0 | Added|
