# 路由和导航类接口

以下接口在ArkTS1.1中已标记为废弃，并在ArkTS1.2中不再支持。

## @ohos.router

### push
ArkTS1.1接口声明：[function push(options: RouterOptions): void](../reference/apis-arkui/js-apis-router.md#routerpushdeprecated)

替代的ArkTS1.2接口声明：[pushUrl(options: router.RouterOptions): Promise<void>](../reference/apis-arkui/js-apis-arkui-UIContext.md#pushurl)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.push({url: "url"})
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().pushUrl({url: "url"})
```


### pushUrl
ArkTS1.1接口声明：[function pushUrl(options: RouterOptions): Promise<void>](../reference/apis-arkui/js-apis-router.md#routerpushurldeprecated)

替代的ArkTS1.2接口声明：[pushUrl(options: router.RouterOptions): Promise<void>](../reference/apis-arkui/js-apis-arkui-UIContext.md#pushurl)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.pushUrl({url: "url"})
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().pushUrl({url: "url"})
```


### pushUrl
ArkTS1.1接口声明：[function pushUrl(options: RouterOptions, callback: AsyncCallback<void>):void](../reference/apis-arkui/js-apis-router.md#routerpushurldeprecated-1)

替代的ArkTS1.2接口声明：[pushUrl(options: router.RouterOptions, callback: AsyncCallback<void>): void](../reference/apis-arkui/js-apis-arkui-UIContext.md#pushurl-1)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.pushUrl({url: "url"}, ()=>{})
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().pushUrl({url: "url"}, ()=>{})
```


### pushUrl
ArkTS1.1接口声明：[function pushUrl(options: RouterOptions, mode: RouterMode): Promise<void>](../reference/apis-arkui/js-apis-router.md#routerpushurldeprecated-2)

替代的ArkTS1.2接口声明：[pushUrl(options: router.RouterOptions, mode: router.RouterMode): Promise<void>](../reference/apis-arkui/js-apis-arkui-UIContext.md#pushurl-2)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.pushUrl({url: "url"}, router.RouterMode.Standard)
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().pushUrl({url: "url"}, router.RouterMode.Standard)
```


### pushUrl
ArkTS1.1接口声明：[function pushUrl(options: RouterOptions, mode: RouterMode, callback: AsyncCallback<void>):void](../reference/apis-arkui/js-apis-router.md#routerpushurldeprecated-3)

替代的ArkTS1.2接口声明：[pushUrl(options: router.RouterOptions, mode: router.RouterMode, callback: AsyncCallback<void>): void](../reference/apis-arkui/js-apis-arkui-UIContext.md#pushurl-3)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.pushUrl({url: "url"}, router.RouterMode.Standard, ()=>{})
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().pushUrl({url: "url"}, router.RouterMode.Standard, ()=>{})
```


### back
ArkTS1.1接口声明：[function back(options?: RouterOptions):void](../reference/apis-arkui/js-apis-router.md#routerbackdeprecated)

替代的ArkTS1.2接口声明：[back(options?: router.RouterOptions): void](../reference/apis-arkui/js-apis-arkui-UIContext.md#back)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.back({url: "url"})
```
ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().back({url: "url"})
```


### back
ArkTS1.1接口声明：[function back(index: number, params?: Object): void](../reference/apis-arkui/js-apis-router.md#routerbackdeprecated-1)

替代的ArkTS1.2接口声明：[back(index: number, params?: Object): void](../reference/apis-arkui/js-apis-arkui-UIContext.md#back12)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.back(1)
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().back(1)
```


### replace
ArkTS1.1接口声明：[function replace(options: RouterOptions): void](../reference/apis-arkui/js-apis-router.md#routerreplacedeprecated)

替代的ArkTS1.2接口声明：[replaceUrl(options: router.RouterOptions): Promise<void>](../reference/apis-arkui/js-apis-arkui-UIContext.md#replaceurl)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.replaceUrl({url: "url"})
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().replaceUrl({url: "url"})
```


### replaceUrl
ArkTS1.1接口声明：[function replaceUrl(options: RouterOptions): Promise<void>](../reference/apis-arkui/js-apis-router.md#routerreplaceurldeprecated)

替代的ArkTS1.2接口声明：[replaceUrl(options: router.RouterOptions): Promise<void>](../reference/apis-arkui/js-apis-arkui-UIContext.md#replaceurl)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.replaceUrl({url: "url"})
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().replaceUrl({url: "url"})
```


### replaceUrl
ArkTS1.1接口声明：[function replaceUrl(options: RouterOptions, callback: AsyncCallback<void>):void](../reference/apis-arkui/js-apis-router.md#routerreplaceurldeprecated-1)

替代的ArkTS1.2接口声明：[replaceUrl(options: router.RouterOptions, callback: AsyncCallback<void>): void](../reference/apis-arkui/js-apis-arkui-UIContext.md#replaceurl-1)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.replaceUrl({url: "url"}, ()=>{})
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().replaceUrl({url: "url"}, ()=>{})
```


### replaceUrl
ArkTS1.1接口声明：[function replaceUrl(options: RouterOptions, mode: RouterMode): Promise<void>](../reference/apis-arkui/js-apis-router.md#routerreplaceurldeprecated-2)

替代的ArkTS1.2接口声明：[replaceUrl(options: router.RouterOptions, mode: router.RouterMode): Promise<void>](../reference/apis-arkui/js-apis-arkui-UIContext.md#replaceurl-2)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.replaceUrl({url: "url"}, router.RouterMode.Standard)
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().replaceUrl({url: "url"}, router.RouterMode.Standard)
```


### replaceUrl
ArkTS1.1接口声明：[function replaceUrl(options: RouterOptions, mode: RouterMode, callback: AsyncCallback<void>):void](../reference/apis-arkui/js-apis-router.md#routerreplaceurldeprecated-3)

替代的ArkTS1.2接口声明：[replaceUrl(options: router.RouterOptions, mode: router.RouterMode, callback: AsyncCallback<void>): void](../reference/apis-arkui/js-apis-arkui-UIContext.md#replaceurl-3)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.replaceUrl({url: "url"}, router.RouterMode.Standard, ()=>{})
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().replaceUrl({url: "url"}, router.RouterMode.Standard, ()=>{})
```


### pushNamedRoute
ArkTS1.1接口声明：[function pushNamedRoute(options: NamedRouterOptions): Promise<void>](../reference/apis-arkui/js-apis-router.md#routerpushnamedroutedeprecated)

替代的ArkTS1.2接口声明：[pushNamedRoute(options: router.NamedRouterOptions): Promise<void>](../reference/apis-arkui/js-apis-arkui-UIContext.md#pushnamedroute)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.pushNamedRoute({name: "路由名"})
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().pushNamedRoute({name: "路由名"})
```


### pushNamedRoute
ArkTS1.1接口声明：[function pushNamedRoute(options: NamedRouterOptions, callback: AsyncCallback<void>): void](../reference/apis-arkui/js-apis-router.md#routerpushnamedroutedeprecated-1)

替代的ArkTS1.2接口声明：[pushNamedRoute(options: router.NamedRouterOptions, callback: AsyncCallback<void>): void](../reference/apis-arkui/js-apis-arkui-UIContext.md#pushnamedroute-1)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.pushNamedRoute({name: "路由名"}, ()=>{})
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().pushNamedRoute({name: "路由名"}, ()=>{})
```


### pushNamedRoute
ArkTS1.1接口声明：[function pushNamedRoute(options: NamedRouterOptions, mode: RouterMode): Promise<void>](../reference/apis-arkui/js-apis-router.md#routerpushnamedroutedeprecated-2)

替代的ArkTS1.2接口声明：[pushNamedRoute(options: router.NamedRouterOptions, mode: router.RouterMode): Promise<void>](../reference/apis-arkui/js-apis-arkui-UIContext.md#pushnamedroute-2)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.pushNamedRoute({name: "路由名"}, router.RouterMode.Standard)
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().pushNamedRoute({name: "路由名"}, router.RouterMode.Standard)
```


### pushNamedRoute
ArkTS1.1接口声明：[function pushNamedRoute(options: NamedRouterOptions, mode: RouterMode, callback: AsyncCallback<void>): void](../reference/apis-arkui/js-apis-router.md#routerpushnamedroutedeprecated-3)

替代的ArkTS1.2接口声明：[pushNamedRoute(options: router.NamedRouterOptions, mode: router.RouterMode, callback: AsyncCallback<void>): void](../reference/apis-arkui/js-apis-arkui-UIContext.md#pushnamedroute-3)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.pushNamedRoute({name: "路由名"}, router.RouterMode.Standard, ()=>{})
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().pushNamedRoute({name: "路由名"}, router.RouterMode.Standard, ()=>{})
```


### replaceNamedRoute
ArkTS1.1接口声明：[function replaceNamedRoute(options: NamedRouterOptions): Promise<void>](../reference/apis-arkui/js-apis-router.md#routerreplacenamedroutedeprecated)

替代的ArkTS1.2接口声明：[replaceNamedRoute(options: router.NamedRouterOptions): Promise<void>](../reference/apis-arkui/js-apis-arkui-UIContext.md#replacenamedroute)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.replaceNamedRoute({name: "路由名"})
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().replaceNamedRoute({name: "路由名"})
```


### replaceNamedRoute
ArkTS1.1接口声明：[function replaceNamedRoute(options: NamedRouterOptions, callback: AsyncCallback<void>): void](../reference/apis-arkui/js-apis-router.md#routerreplacenamedroutedeprecated-1)

替代的ArkTS1.2接口声明：[replaceNamedRoute(options: router.NamedRouterOptions, callback: AsyncCallback<void>): void](../reference/apis-arkui/js-apis-arkui-UIContext.md#replacenamedroute-1)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.replaceNamedRoute({name: "路由名"}, ()=>{})
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().replaceNamedRoute({name: "路由名"}, ()=>{})
```


### replaceNamedRoute
ArkTS1.1接口声明：[function replaceNamedRoute(options: NamedRouterOptions, mode: RouterMode): Promise<void>](../reference/apis-arkui/js-apis-router.md#routerreplacenamedroutedeprecated-2)

替代的ArkTS1.2接口声明：[replaceNamedRoute(options: router.NamedRouterOptions, mode: router.RouterMode): Promise<void>](../reference/apis-arkui/js-apis-arkui-UIContext.md#replacenamedroute-2)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.replaceNamedRoute({name: "路由名"}, router.RouterMode.Standard)
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().replaceNamedRoute({name: "路由名"}, router.RouterMode.Standard)
```


### replaceNamedRoute
ArkTS1.1接口声明：[function replaceNamedRoute(options: NamedRouterOptions, mode: RouterMode, callback: AsyncCallback<void>): void](../reference/apis-arkui/js-apis-router.md#routerreplacenamedroutedeprecated-3)

替代的ArkTS1.2接口声明：[pushNamedRoute(options: router.NamedRouterOptions, mode: router.RouterMode, callback: AsyncCallback<void>): void](../reference/apis-arkui/js-apis-arkui-UIContext.md#replacenamedroute-3)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.replaceNamedRoute({name: "路由名"}, router.RouterMode.Standard, ()=>{})
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().replaceNamedRoute({name: "路由名"}, router.RouterMode.Standard, ()=>{})
```


### getParams
ArkTS1.1接口声明：[function getParams(): Object](../reference/apis-arkui/js-apis-router.md#routergetparamsdeprecated)

替代的ArkTS1.2接口声明：[getParams(): Object](../reference/apis-arkui/js-apis-arkui-UIContext.md#getparams)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.getParams()
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().getParams()
```


### getStateByUrl
ArkTS1.1接口声明：[function getStateByUrl(url: string): Array<RouterState>](../reference/apis-arkui/js-apis-router.md#routergetstatebyurldeprecated)

替代的ArkTS1.2接口声明：[getStateByUrl(url: string): Array<router.RouterState>](../reference/apis-arkui/js-apis-arkui-UIContext.md#getstatebyurl12)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.getStateByUrl("url")
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().getStateByUrl("url")
```


### getStateByIndex
ArkTS1.1接口声明：[function getStateByIndex(index: number): RouterState | undefined](../reference/apis-arkui/js-apis-router.md#routergetstatebyindexdeprecated)

替代的ArkTS1.2接口声明：[getStateByIndex(index: number): router.RouterState | undefined](../reference/apis-arkui/js-apis-arkui-UIContext.md#getstatebyindex12)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.getStateByIndex(1)
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().getStateByIndex(1)
```


### getState
ArkTS1.1接口声明：[function getState():RouterState](../reference/apis-arkui/js-apis-router.md#routergetstatedeprecated)

替代的ArkTS1.2接口声明：[getState(): router.RouterState](../reference/apis-arkui/js-apis-arkui-UIContext.md#getstate)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.getState()
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().getState()
```


### getLength
ArkTS1.1接口声明：[function getLength():string](../reference/apis-arkui/js-apis-router.md#routergetlengthdeprecated)

替代的ArkTS1.2接口声明：[getLength(): string](../reference/apis-arkui/js-apis-arkui-UIContext.md#getlength)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.getLength()
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().getLength()
```


### clear
ArkTS1.1接口声明：[function clear():void](../reference/apis-arkui/js-apis-router.md#routercleardeprecated)

替代的ArkTS1.2接口声明：[clear(): void](../reference/apis-arkui/js-apis-arkui-UIContext.md#clear)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.clear()
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().clear()
```


### enableAlertBeforeBackPage
ArkTS1.1接口声明：[function enableAlertBeforeBackPage(options: EnableAlertOptions): void](../reference/apis-arkui/js-apis-router.md#routerenablealertbeforebackpagedeprecated)

替代的ArkTS1.2接口声明：[showAlertBeforeBackPage(options: router.EnableAlertOptions): void](../reference/apis-arkui/js-apis-arkui-UIContext.md#showalertbeforebackpage)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.enableAlertBeforeBackPage({ message: "1111" })
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().showAlertBeforeBackPage({message: "1111"})
```


### showAlertBeforeBackPage
ArkTS1.1接口声明：[function showAlertBeforeBackPage(options: EnableAlertOptions):void](../reference/apis-arkui/js-apis-router.md#routershowalertbeforebackpagedeprecated)

替代的ArkTS1.2接口声明：[showAlertBeforeBackPage(options: router.EnableAlertOptions): void](../reference/apis-arkui/js-apis-arkui-UIContext.md#showalertbeforebackpage)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.showAlertBeforeBackPage({message: "1111"})
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().showAlertBeforeBackPage({message: "1111"})
```


### disableAlertBeforeBackPage
ArkTS1.1接口声明：[function disableAlertBeforeBackPage(): void](../reference/apis-arkui/js-apis-router.md#routerdisablealertbeforebackpagedeprecated)
替代的ArkTS1.2接口声明：[hideAlertBeforeBackPage(): void](../reference/apis-arkui/js-apis-arkui-UIContext.md#hidealertbeforebackpage)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.disableAlertBeforeBackPage()
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().hideAlertBeforeBackPage()
```


### hideAlertBeforeBackPage
ArkTS1.1接口声明：[function hideAlertBeforeBackPage():void](../reference/apis-arkui/js-apis-router.md#routerhidealertbeforebackpagedeprecated)

替代的ArkTS1.2接口声明：[hideAlertBeforeBackPage(): void](../reference/apis-arkui/js-apis-arkui-UIContext.md#hidealertbeforebackpage)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.hideAlertBeforeBackPage()
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().hideAlertBeforeBackPage()
```


## @system.router

### Router
ArkTS1.1接口声明：[export default class Router](../reference/apis-arkui/js-apis-system-router.md#导入模块)

替代的ArkTS1.2接口声明：[export class Router](../reference/apis-arkui/js-apis-arkui-UIContext.md#router)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
import router from '@system.router'
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter()
```


### push
ArkTS1.1接口声明：[static push(options: RouterOptions): void](../reference/apis-arkui/js-apis-system-router.md#routerpush)

替代的ArkTS1.2接口声明：[pushUrl(options: router.RouterOptions, callback: AsyncCallback<void>): void](../reference/apis-arkui/js-apis-arkui-UIContext.md#pushurl-1)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.push({ uri: "url" })
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().pushUrl({url: "url"}, ()=>{})
```


### back
ArkTS1.1接口声明：[static back(options?: BackRouterOptions): void](../reference/apis-arkui/js-apis-system-router.md#routerback)

替代的ArkTS1.2接口声明：[back(options?: router.RouterOptions): void](../reference/apis-arkui/js-apis-arkui-UIContext.md#back)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.back() 
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().back()
```


### replace
ArkTS1.1接口声明：[static replace(options: RouterOptions): void](../reference/apis-arkui/js-apis-system-router.md#routerreplace)

替代的ArkTS1.2接口声明：[replaceUrl(options: router.RouterOptions, callback: AsyncCallback<void>): void](../reference/apis-arkui/js-apis-arkui-UIContext.md#replaceUrl-1)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.replace({ uri: "url" })
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().replaceUrl({ url: "url" }, ()=>{})
```


### clear
ArkTS1.1接口声明：[static clear(): void](../reference/apis-arkui/js-apis-system-router.md#routerclear)

替代的ArkTS1.2接口声明：[clear(): void](../reference/apis-arkui/js-apis-arkui-UIContext.md#clear)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.clear()
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().clear()
```


### enableAlertBeforeBackPage
ArkTS1.1接口声明：[static enableAlertBeforeBackPage(options: EnableAlertBeforeBackPageOptions): void](../reference/apis-arkui/js-apis-system-router.md#routerenablealertbeforebackpage6)

替代的ArkTS1.2接口声明：[showAlertBeforeBackPage(options: router.EnableAlertOptions): void](../reference/apis-arkui/js-apis-arkui-UIContext.md#showalertbeforebackpage)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.enableAlertBeforeBackPage({ message: "" })
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().showAlertBeforeBackPage({ message: "" })
```


### disableAlertBeforeBackPage
ArkTS1.1接口声明：[static disableAlertBeforeBackPage(options?: DisableAlertBeforeBackPageOptions): void](../reference/apis-arkui/js-apis-system-router.md#routerdisablealertbeforebackpage6)

替代的ArkTS1.2接口声明：[hideAlertBeforeBackPage(): void](../reference/apis-arkui/js-apis-arkui-UIContext.md#hidealertbeforebackpage)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.disableAlertBeforeBackPage()
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().hideAlertBeforeBackPage()
```


### getLength
ArkTS1.1接口声明：[static getLength(): string](../reference/apis-arkui/js-apis-system-router.md#routergetlength)

替代的ArkTS1.2接口声明：[getLength(): string](../reference/apis-arkui/js-apis-arkui-UIContext.md#getlength)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
let length: string = router.getLength()
```

ArkTS1.2

<!--code_no_check-->
```ts
let length: string = this.getUIContext().getRouter().getLength()
```


### getParams
ArkTS1.1接口声明：[static getParams(): ParamsInterface](../reference/apis-arkui/js-apis-system-router.md#routergetparams7)

替代的ArkTS1.2接口声明：[getParams(): Object](../reference/apis-arkui/js-apis-arkui-UIContext.md#getparams)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.getParams()
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().getParams()
```


### getState
ArkTS1.1接口声明：[static getState(): RouterState](../reference/apis-arkui/js-apis-system-router.md#routergetstate)

替代的ArkTS1.2接口声明：[getState(): router.RouterState](../reference/apis-arkui/js-apis-arkui-UIContext.md#getstate)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.getState()
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().getState()
```


## BackRouterOptions

### BackRouterOptions
ArkTS1.1接口声明：[export interface BackRouterOptions](../reference/apis-arkui/js-apis-system-router.md#backrouteroptions)

替代的ArkTS1.2接口声明：[interface RouterOptions](../reference/apis-arkui/js-apis-router.md#routeroptions)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
let options: BackRouterOptions = { uri: "url" }
```

ArkTS1.2

<!--code_no_check-->
```ts
let options: router.RouterOptions = { url: "url" }
```


### uri
ArkTS1.1接口声明：[uri: string ](../reference/apis-arkui/js-apis-system-router.md#backrouteroptions)

替代的ArkTS1.2接口声明：[url: string ](../reference/apis-arkui/js-apis-router.md#routeroptions)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
let options: BackRouterOptions = { uri: "url" }
```

ArkTS1.2

<!--code_no_check-->
```ts
let options: router.RouterOptions = { url: "url" }
```


### params
ArkTS1.1接口声明：[params?: Object](../reference/apis-arkui/js-apis-system-router.md#backrouteroptions)

替代的ArkTS1.2接口声明：[params?: Object](../reference/apis-arkui/js-apis-router.md#routeroptions)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
let options: BackRouterOptions = {uri: "url", params: ""}
```

ArkTS1.2

<!--code_no_check-->
```ts
let options: router.RouterOptions = {uri: "url", params: ""}
```


## RouterOptions

### RouterOptions
ArkTS1.1接口声明：[export interface RouterOptions](../reference/apis-arkui/js-apis-system-router.md#routeroptions)

替代的ArkTS1.2接口声明：[interface RouterOptions](../reference/apis-arkui/js-apis-router.md#routeroptions)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
let options: RouterOptions = { uri: "url" }
```

ArkTS1.2

<!--code_no_check-->
```ts
let options: router.RouterOptions = { url: "url" }
```


### uri
ArkTS1.1接口声明：[uri: string](/reference/apis-arkui/js-apis-system-router.md#routeroptions)

替代的ArkTS1.2接口声明：[ url: string](../reference/apis-arkui/js-apis-router.md#routeroptions)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
let options: RouterOptions = { uri: "url" }
```

ArkTS1.2

<!--code_no_check-->
```ts
let options: router.RouterOptions = { url: "url" }
```


### params
ArkTS1.1接口声明：[params?: Object](/reference/apis-arkui/js-apis-system-router.md#routeroptions)

替代的ArkTS1.2接口声明：[params?: Object](../reference/apis-arkui/js-apis-router.md#routeroptions)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
let options: RouterOptions = {url: "url", params: ""}
```

ArkTS1.2

<!--code_no_check-->
```ts
let options: router.RouterOptions = {url: "url", params: ""}
```


## RouterState

### RouterState
ArkTS1.1接口声明：[export interface RouterState](../reference/apis-arkui/js-apis-system-router.md#routerstate)

替代的ArkTS1.2接口声明：[interface RouterState](../reference/apis-arkui/js-apis-router.md#routerstate)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
let state: RouterState = { uri: "url" }
```

ArkTS1.2

<!--code_no_check-->
```ts
let state: router.RouterState = { url: "url" }
```


### index
ArkTS1.1接口声明：[index: number](../reference/apis-arkui/js-apis-system-router.md#routerstate)

替代的ArkTS1.2接口声明：[index: number](../reference/apis-arkui/js-apis-router.md#routerstate)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
let state: RouterState = router.getState()
let index: number = state.index
```

ArkTS1.2

<!--code_no_check-->
```ts
let state: router.RouterState = this.getUIContext().getRouter().getState()
let index: number = state.index
```


### name
ArkTS1.1接口声明：[name: string](../reference/apis-arkui/js-apis-system-router.md#routerstate)

替代的ArkTS1.2接口声明：[name: string](../reference/apis-arkui/js-apis-router.md#routerstate)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
let state: RouterState = router.getState()
let name: string = state.name
```

ArkTS1.2

<!--code_no_check-->
```ts
let state: router.RouterState = this.getUIContext().getRouter().getState()
let name: string = state.name
```


### path
ArkTS1.1接口声明：[path: string](../reference/apis-arkui/js-apis-system-router.md#routerstate)

替代的ArkTS1.2接口声明：[path: string](../reference/apis-arkui/js-apis-router.md#routerstate)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
let state: RouterState = router.getState()
let path: string = state.path
```

ArkTS1.2

<!--code_no_check-->
```ts
let state: router.RouterState = this.getUIContext().getRouter().getState()
let path: string = state.path
```


## EnableAlertBeforeBackPageOptions

### EnableAlertBeforeBackPageOptions
ArkTS1.1接口声明：[export interface EnableAlertBeforeBackPageOptions](../reference/apis-arkui/js-apis-system-router.md#enablealertbeforebackpageoptions6)

替代的ArkTS1.2接口声明：[interface EnableAlertOptions](../reference/apis-arkui/js-apis-router.md#enablealertoptions)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
let options: EnableAlertBeforeBackPageOptions = { message: "" }
```

ArkTS1.2

<!--code_no_check-->
```ts
let options: EnableAlertOptions = { message: "" }
```


### message
ArkTS1.1接口声明：[message: string ](../reference/apis-arkui/js-apis-system-router.md#enablealertbeforebackpageoptions6)

替代的ArkTS1.2接口声明：[message: string ](../reference/apis-arkui/js-apis-router.md#enablealertoptions)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.enableAlertBeforeBackPage({ message: "" })
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().showAlertBeforeBackPage({ message: "" })
```


### success
ArkTS1.1接口声明：[success?: (errMsg: string) => void](../reference/apis-arkui/js-apis-system-router.md#enablealertbeforebackpageoptions6)

替代的ArkTS1.2接口声明：[showAlertBeforeBackPage(options: router.EnableAlertOptions): void](../reference/apis-arkui/js-apis-arkui-UIContext.md#showalertbeforebackpage)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.enableAlertBeforeBackPage({ message: "", success: (err: string)=>{} })
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().showAlertBeforeBackPage({ message: "" })
```


### cancel
ArkTS1.1接口声明：[cancel?: (errMsg: string) => void](../reference/apis-arkui/js-apis-system-router.md#enablealertbeforebackpageoptions6)

替代的ArkTS1.2接口声明：[showAlertBeforeBackPage(options: router.EnableAlertOptions): void](../reference/apis-arkui/js-apis-arkui-UIContext.md#showalertbeforebackpage)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.enableAlertBeforeBackPage({ message: "", cancel: (err: string)=>{} })
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().showAlertBeforeBackPage({ message: "" })
```


### complete
ArkTS1.1接口声明：[complete?: () => void](../reference/apis-arkui/js-apis-system-router.md#enablealertbeforebackpageoptions6)

替代的ArkTS1.2接口声明：[showAlertBeforeBackPage(options: router.EnableAlertOptions): void](../reference/apis-arkui/js-apis-arkui-UIContext.md#showalertbeforebackpage)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.enableAlertBeforeBackPage({ message: "", complete: ()=>{} })
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().showAlertBeforeBackPage({ message: "" })
```


## DisableAlertBeforeBackPageOptions

### DisableAlertBeforeBackPageOptions
ArkTS1.1接口声明：[export interface DisableAlertBeforeBackPageOptions](../reference/apis-arkui/js-apis-system-router.md#disablealertbeforebackpageoptions6)

替代的ArkTS1.2接口声明：[interface RouterOptions](../reference/apis-arkui/js-apis-arkui-UIContext.md#showalertbeforebackpage)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
let options: DisableAlertBeforeBackPageOptions = { complete: ()=>{} }
```

ArkTS1.2

<!--code_no_check-->
```ts
let options: router.RouterOptions = { url: "url" }
```


### success
ArkTS1.1接口声明：[success?: (errMsg: string) => void](../reference/apis-arkui/js-apis-system-router.md#disablealertbeforebackpageoptions6)

替代的ArkTS1.2接口声明：[hideAlertBeforeBackPage(): void](../reference/apis-arkui/js-apis-arkui-UIContext.md#hidealertbeforebackpage)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.disableAlertBeforeBackPage({ success: (err: string)=>{} })
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().hideAlertBeforeBackPage()
```


### cancel
ArkTS1.1接口声明：[cancel?: (errMsg: string) => void](../reference/apis-arkui/js-apis-system-router.md#disablealertbeforebackpageoptions6)

替代的ArkTS1.2接口声明：[hideAlertBeforeBackPage(): void](../reference/apis-arkui/js-apis-arkui-UIContext.md#hidealertbeforebackpage)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.disableAlertBeforeBackPage({ cancel: (err: string)=>{} })
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().hideAlertBeforeBackPage()
```


### complete
ArkTS1.1接口声明：[complete?: () => void](../reference/apis-arkui/js-apis-system-router.md#disablealertbeforebackpageoptions6)

替代的ArkTS1.2接口声明：[hideAlertBeforeBackPage(): void](../reference/apis-arkui/js-apis-arkui-UIContext.md#hidealertbeforebackpage)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
router.disableAlertBeforeBackPage({ complete: ()=>{} })
```

ArkTS1.2

<!--code_no_check-->
```ts
this.getUIContext().getRouter().hideAlertBeforeBackPage()
```


## ParamsInterface

### ParamsInterface
ArkTS1.1接口声明：type ParamsInterface = {[key: string]: Object}

替代的ArkTS1.2接口声明：interface Object

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
let params: ParamsInterface = router.getParams()
```

ArkTS1.2

<!--code_no_check-->
```ts
let params: Object = this.getUIContext().getRouter().getParams()
```


## Navigation

### toolBar

ArkTS1.1接口声明：[toolBar(value: object | CustomBuilder): NavigationAttribute](../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md#toolbardeprecated)

替代的ArkTS1.2接口声明：[toolbarConfiguration(value: Array<ToolbarItem> | CustomBuilder, options?: NavigationToolbarOptions): NavigationAttribute](../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md#toolbarconfiguration10)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
@Builder
MyToolBar(name: string) {
    //...
}
build(){
    Navigation().toolBar(this.MyToolBar)
}
```

ArkTS1.2
<!--code_no_check-->
```ts
@Builder
MyToolBar(name: string) {
    //...
}
build(){
    Navigation().toolbarConfiguration(this.MyToolBar)
}
```


### subTitle

ArkTS1.1接口声明：[subTitle(value: string): NavigationAttribute](../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md#subtitledeprecated)

替代的ArkTS1.2接口声明：[title(value: ResourceStr | CustomBuilder | NavigationCommonTitle | NavigationCustomTitle, options?: NavigationTitleOptions): NavigationAttribute](../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md#title)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
Navigation().subTitle("子标题")
```

ArkTS1.2
<!--code_no_check-->
```ts
Navigation().title({main: "标题", sub: "子标题"})
```


## Navigator

ArkTS1.1接口声明：[Navigator(value?: {target: string, type?: NavigationType})](../reference/apis-arkui/arkui-ts/ts-container-navigator.md#navigator)

替代的ArkTS1.2接口声明：[export class Router](../reference/apis-arkui/js-apis-arkui-UIContext.md#router)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
Navigator({ target: "url", type: NavigationType.Push}){
    Text("Push")
}
Navigator({ target: "url", type: NavigationType.Back}){
    Text("Back")
}
Navigator({ target: "url", type: NavigationType.Replace}){
    Text("Replace")
}
```

ArkTS1.2
<!--code_no_check-->
```ts
Text("Push").onClick(()=>{
    this.getUIContext().getRouter().pushUrl({ url: "url"});
})
Text("Back").onClick(()=> {
    this.getUIContext().getRouter().back({ url: "url"});
})
Text("Replace").onClick(()=>{
    this.getUIContext().getRouter().replaceUrl({ url: "url"});
})
```


## NavRouter

ArkTS1.1接口声明：[NavRouter()](../reference/apis-arkui/arkui-ts/ts-basic-components-navrouter.md#navrouter-1)

替代的ArkTS1.2接口声明：[Navigation(pathInfos: NavPathStack)](../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md#navigation10)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
@Entry
@Component
struct Index {
  build(){
    Column(){
      Navigation(){
        NavRouter(){
          Row(){
            Row()
            Text("pageOne")
          }
          NavDestination(){
            Text("当前页面为pageOne")
          }.title("pageOne")
        }
        NavRouter(){
          Row(){
            Row()
            Text("pageTwo")
          }
          NavDestination(){
            Text("当前页面为pageTwo")
          }.title("pageTwo")
        }
      }
    }
  }
}
```

ArkTS1.2
<!--code_no_check-->
```ts
@Entry
@Component
struct Index {
  private pageInfos: NavPathStack = new NavPathStack();

  @Builder
  MyPageMap(name: string) {
    if (name === 'pageOne') {
      PageOne()
    } else if (name === 'pageTwo') {
      PageTwo()
    }
  }

  build(){
    Navigation(this.pageInfos){
      Text("pageOne").onClick(()=>{
        this.pageInfos.pushPath({name : "pageOne"});
      })
      Text("pageTwo").onClick(()=>{
        this.pageInfos.pushPath({name : "pageTwo"});
      })
    }.navDestination(this.MyPageMap)
  }
}

@Component
export struct PageOne {
  build() {
    NavDestination() {
      Text("当前页面为pageOne")
    }.title("PageOne")
  }
}

@Component
export struct PageTwo {
  build() {
    NavDestination() {
      Text("当前页面为pageTwo")
    }.title("PageTwo")
  }
}
```