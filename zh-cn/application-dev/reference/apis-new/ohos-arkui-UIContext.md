# @ohos.arkui.UIContext    
在Stage模型中，WindowStage/Window可以通过loadContent接口加载页面并创建UI的实例，并将页面内容渲染到关联的窗口中，所以UI实例和窗口是一一关联的。一些全局的UI接口是和具体UI实例的执行上下文相关的，在当前接口调用时，通过追溯调用链跟踪到UI的上下文，来确定具体的UI实例。若在非UI页面中或者一些异步回调中调用这类接口，可能无法跟踪到当前UI的上下文，导致接口执行失败。  
  
sion 10 新增[getUIContext](./js-apis-window.md#getuicontext10)接口，获取UI上下文实例UIContext对象，使用UIContext对象提供的替代方法，可以直接作用在对应的UI实例上。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## Font    
获取Font对象。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### registerFont    
在字体管理中注册自定义字体。  
 **调用形式：**     
- registerFont(options: font.FontOptions): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | font.FontOptions | true | 注册的自定义字体信息。 |  
    
 **示例代码：**   
```ts    
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';  
let font:Font = uiContext.getFont();  
font.registerFont({  
  familyName: 'medium',  
  familySrc: '/font/medium.ttf'  
});  
    
```    
  
    
### getSystemFontList    
获取系统支持的字体名称列表。  
 **调用形式：**     
- getSystemFontList(): Array\<string>  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<string> | 系统的字体名列表。 |  
    
 **示例代码：**   
```ts    
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';  
let font:Font|undefined = uiContext.getFont();  
if(font){  
  font.getSystemFontList()  
}  
    
```    
  
    
### getFontByName    
根据传入的系统字体名称获取系统字体的相关信息。  
 **调用形式：**     
- getFontByName(fontName: string): font.FontInfo  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fontName | string | true | 系统的字体名。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| font.FontInfo | 字体的详细信息 |  
    
 **示例代码：**   
```ts    
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';  
let font:Font|undefined = uiContext.getFont();  
if(font){  
  font.getFontByName('Sans Italic')  
}  
    
```    
  
    
## MediaQuery    
以下API需先使用UIContext中的[getMediaQuery()](#getmediaquery)方法获取到MediaQuery对象，再通过该对象调用对应方法。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### matchMediaSync    
设置媒体查询的查询条件，并返回对应的监听句柄。  
 **调用形式：**     
- matchMediaSync(condition: string): mediaQuery.MediaQueryListener  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| condition | string | true | 媒体事件的匹配条件，具体可参考[媒体查询语法规则](../../ui/arkts-layout-development-media-query.md#语法规则)。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| mediaQuery.MediaQueryListener | 媒体事件监听句柄，用于注册和去注册监听回调。 |  
    
 **示例代码：**   
```ts    
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';  
let mediaquery: MediaQuery = uiContext.getMediaQuery();  
let listener = mediaquery.matchMediaSync('(orientation: landscape)'); //监听横屏事件  
    
```    
  
    
## UIInspector    
获取UIInspector对象。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### createComponentObserver    
createComponentObserver(id: string): inspector.ComponentObserver。  
 **调用形式：**     
- createComponentObserver(id: string): inspector.ComponentObserver  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| id | string | true | 指定组件id。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| inspector.ComponentObserver | 组件回调事件监听句柄，用于注册和取消注册监听回调。 |  
    
 **示例代码：**   
```ts    
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';  
let inspector:UIInspector = uiContext.getUIInspector();  
let listener = inspector.createComponentObserver('COMPONENT_ID');  
    
```    
  
    
## Router    
以下API需先使用UIContext中的[getRouter()](#getrouter)方法获取到Router对象，再通过该对象调用对应方法。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### pushUrl    
跳转到应用内的指定页面。  
 **调用形式：**     
    
- pushUrl(options: router.RouterOptions, callback: AsyncCallback\<void>): void    
起始版本： 10    
- pushUrl(options: router.RouterOptions): Promise\<void>    
起始版本： 10    
- pushUrl(options: router.RouterOptions, mode: router.RouterMode, callback: AsyncCallback\<void>): void    
起始版本： 10    
- pushUrl(options: router.RouterOptions, mode: router.RouterMode): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | router.RouterOptions | true | 跳转页面描述信息 |  
| mode | router.RouterMode | true | 跳转页面使用的模式。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异常响应回调。 |  
| Promise<void> | 异常返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 100001 | if UI execution context not found. |  
| 100002 | if the uri is not exist. |  
| 100003 | if the pages are pushed too much. |  
    
 **示例代码1：**   
示例(Promise):  
```ts    
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';  
import { BusinessError } from '@ohos.base';  
let router:Router = uiContext.getRouter();  
try {  
  router.pushUrl({  
    url: 'pages/routerpage2',  
    params: {  
      data1: 'message',  
      data2: {  
        data3: [123, 456, 789]  
      }  
    }  
  })  
} catch (err) {  
  let message = (err as BusinessError).message;  
  let code = (err as BusinessError).code;  
  console.error(`pushUrl failed, code is ${code}, message is ${message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(callback):  
```ts    
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';  
import { BusinessError } from '@ohos.base';  
let router:Router = uiContext.getRouter();  
router.pushUrl({  
  url: 'pages/routerpage2',  
  params: {  
    data1: 'message',  
    data2: {  
      data3: [123, 456, 789]  
    }  
  }  
}, (err: Error) => {  
  if (err) {  
    let message = (err as BusinessError).message;  
    let code = (err as BusinessError).code;  
    console.error(`pushUrl failed, code is ${code}, message is ${message}`);  
    return;  
  }  
  console.info('pushUrl success');  
})  
    
```    
  
    
### replaceUrl    
用应用内的某个页面替换当前页面，并销毁被替换的页面。  
 **调用形式：**     
    
- replaceUrl(options: router.RouterOptions, callback: AsyncCallback\<void>): void    
起始版本： 10    
- replaceUrl(options: router.RouterOptions): Promise\<void>    
起始版本： 10    
- replaceUrl(options: router.RouterOptions, mode: router.RouterMode, callback: AsyncCallback\<void>): void    
起始版本： 10    
- replaceUrl(options: router.RouterOptions, mode: router.RouterMode): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | router.RouterOptions | true | 异常响应回调。 |  
| mode | router.RouterMode | true | 跳转页面使用的模式。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异常响应回调。 |  
| Promise<void> | 异常返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 100001 | if can not get the delegate, only throw in standard system. |  
| 200002 | if the uri is not exist. |  
    
 **示例代码1：**   
示例(Promise):  
```ts    
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';  
import { BusinessError } from '@ohos.base';  
let router:Router = uiContext.getRouter();  
try {  
  router.replaceUrl({  
    url: 'pages/detail',  
    params: {  
      data1: 'message'  
    }  
  })  
} catch (err) {  
  let message = (err as BusinessError).message;  
  let code = (err as BusinessError).code;  
  console.error(`replaceUrl failed, code is ${code}, message is ${message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(callback):  
```ts    
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';  
import { BusinessError } from '@ohos.base';  
let router:Router = uiContext.getRouter();  
router.replaceUrl({  
  url: 'pages/detail',  
  params: {  
    data1: 'message'  
  }  
}, (err: Error) => {  
  if (err) {  
    let message = (err as BusinessError).message;  
    let code = (err as BusinessError).code;  
    console.error(`replaceUrl failed, code is ${code}, message is ${message}`);  
    return;  
  }  
  console.info('replaceUrl success');  
})  
    
```    
  
    
### back    
返回上一页面或指定的页面。  
 **调用形式：**     
- back(options?: router.RouterOptions): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | router.RouterOptions | false | 返回页面描述信息，其中参数url指路由跳转时会返回到指定url的界面，如果页面栈上没有url页面，则不响应该情况。如果url未设置，则返回上一页，页面不会重新构建，页面栈里面的page不会回收，出栈后会被回收。 |  
    
 **示例代码：**   
```ts    
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';  
import { BusinessError } from '@ohos.base';  
let router: Router = uiContext.getRouter();  
router.back({url:'pages/detail'});  
    
```    
  
    
### clear    
清空页面栈中的所有历史页面，仅保留当前页面作为栈顶页面。  
 **调用形式：**     
- clear(): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **示例代码：**   
```ts    
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';  
import { BusinessError } from '@ohos.base';  
let router: Router = uiContext.getRouter();  
router.clear();  
    
```    
  
    
### getLength    
获取当前在页面栈内的页面数量。  
 **调用形式：**     
- getLength(): string  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 页面数量，页面栈支持最大数值是32。 |  
    
 **示例代码：**   
```ts    
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';  
import { BusinessError } from '@ohos.base';  
let router: Router = uiContext.getRouter();  
let size = router.getLength();          
console.log('pages stack size = ' + size);  
    
```    
  
    
### getState    
获取当前页面的状态信息。  
 **调用形式：**     
- getState(): router.RouterState  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| router.RouterState | 页面状态信息。 |  
    
 **示例代码：**   
```ts    
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';  
import { BusinessError } from '@ohos.base';  
let router: Router = uiContext.getRouter();  
let page = router.getState();  
console.log('current index = ' + page.index);  
console.log('current name = ' + page.name);  
console.log('current path = ' + page.path);  
    
```    
  
    
### showAlertBeforeBackPage    
开启页面返回询问对话框。  
 **调用形式：**     
- showAlertBeforeBackPage(options: router.EnableAlertOptions): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | router.EnableAlertOptions | true | 文本弹窗信息描述。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 100001 | if UI execution context not found. |  
    
 **示例代码：**   
```ts    
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';  
import { BusinessError } from '@ohos.base';  
let router: Router = uiContext.getRouter();  
try {  
  router.showAlertBeforeBackPage({              
    message: 'Message Info'          
  });  
} catch(error) {  
  let message = (error as BusinessError).message;  
  let code = (error as BusinessError).code;  
  console.error(`showAlertBeforeBackPage failed, code is ${code}, message is ${message}`);  
}  
    
```    
  
    
### hideAlertBeforeBackPage    
禁用页面返回询问对话框。  
 **调用形式：**     
- hideAlertBeforeBackPage(): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **示例代码：**   
```ts    
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';  
import { BusinessError } from '@ohos.base';  
let router: Router = uiContext.getRouter();  
router.hideAlertBeforeBackPage();  
    
```    
  
    
### getParams    
获取发起跳转的页面往当前页传入的参数。  
 **调用形式：**     
- getParams(): Object  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Object | 发起跳转的页面往当前页传入的参数。 |  
    
 **示例代码：**   
```ts    
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';  
import { BusinessError } from '@ohos.base';  
let router: Router = uiContext.getRouter();  
router.getParams();  
    
```    
  
    
### pushNamedRoute    
跳转到指定的命名路由页面。  
 **调用形式：**     
    
- pushNamedRoute(options: router.NamedRouterOptions, callback: AsyncCallback\<void>): void    
起始版本： 10    
- pushNamedRoute(options: router.NamedRouterOptions): Promise\<void>    
起始版本： 10    
- pushNamedRoute(options: router.NamedRouterOptions, mode: router.RouterMode, callback: AsyncCallback\<void>): void    
起始版本： 10    
- pushNamedRoute(options: router.NamedRouterOptions, mode: router.RouterMode): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | router.NamedRouterOptions | true | 跳转页面描述信息。 |  
| mode | router.RouterMode | true | 跳转页面使用的模式。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异常响应回调。 |  
| Promise<void> | 异常返回结果 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 100001 | if UI execution context not found. |  
| 100003 | if the pages are pushed too much. |  
| 100004 | if the named route is not exist. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';  
import { BusinessError } from '@ohos.base';  
let router:Router = uiContext.getRouter();  
router.pushNamedRoute({  
  name: 'myPage',  
  params: {  
    data1: 'message',  
    data2: {  
      data3: [123, 456, 789]  
    }  
  }  
}, (err: Error) => {  
  if (err) {  
    let message = (err as BusinessError).message;  
    let code = (err as BusinessError).code;  
    console.error(`pushNamedRoute failed, code is ${code}, message is ${message}`);  
    return;  
  }  
  console.info('pushNamedRoute success');  
})  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';  
import { BusinessError } from '@ohos.base';  
import router from '@ohos.router';  
let routerF:Router = uiContext.getRouter();  
class routerTmp{  
  Standard:router.RouterMode = router.RouterMode.Standard  
}  
let rtm:routerTmp = new routerTmp()  
try {  
  routerF.pushNamedRoute({  
    name: 'myPage',  
    params: {  
      data1: 'message',  
      data2: {  
        data3: [123, 456, 789]  
      }  
    }  
  }, rtm.Standard)  
} catch (err) {  
  let message = (err as BusinessError).message;  
  let code = (err as BusinessError).code;  
  console.error(`pushNamedRoute failed, code is ${code}, message is ${message}`);  
}  
    
```    
  
    
### replaceNamedRoute    
用指定的命名路由页面替换当前页面，并销毁被替换的页面。  
 **调用形式：**     
    
- replaceNamedRoute(options: router.NamedRouterOptions, callback: AsyncCallback\<void>): void    
起始版本： 10    
- replaceNamedRoute(options: router.NamedRouterOptions): Promise\<void>    
起始版本： 10    
- replaceNamedRoute(options: router.NamedRouterOptions, mode: router.RouterMode, callback: AsyncCallback\<void>): void    
起始版本： 10    
- replaceNamedRoute(options: router.NamedRouterOptions, mode: router.RouterMode): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | router.NamedRouterOptions | true | 替换页面描述信息。 |  
| mode | router.RouterMode | true | 跳转页面使用的模式。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异常响应回调。 |  
| Promise<void> | 异常返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 100001 | if can not get the delegate, only throw in standard system. |  
| 100004 | if the named route is not exist. |  
    
 **示例代码1：**   
示例(Promise):  
```ts    
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';  
import { BusinessError } from '@ohos.base';  
let router:Router = uiContext.getRouter();  
try {  
  router.replaceNamedRoute({  
    name: 'myPage',  
    params: {  
      data1: 'message'  
    }  
  })  
} catch (err) {  
  let message = (err as BusinessError).message;  
  let code = (err as BusinessError).code;  
  console.error(`replaceNamedRoute failed, code is ${code}, message is ${message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(callback):  
```ts    
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';  
import { BusinessError } from '@ohos.base';  
let router:Router = uiContext.getRouter();  
router.replaceNamedRoute({  
  name: 'myPage',  
  params: {  
    data1: 'message'  
  }  
}, (err: Error) => {  
  if (err) {  
    let message = (err as BusinessError).message;  
    let code = (err as BusinessError).code;  
    console.error(`replaceNamedRoute failed, code is ${code}, message is ${message}`);  
    return;  
  }  
  console.info('replaceNamedRoute success');  
})  
    
```    
  
    
## PromptAction    
以下API需先使用UIContext中的[getPromptAction()](#getpromptaction)方法获取到PromptAction对象，再通过该对象调用对应方法。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### showToast    
创建并显示文本提示框。  
 **调用形式：**     
- showToast(options: promptAction.ShowToastOptions): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | promptAction.ShowToastOptions | true | 文本弹窗选项。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 100001 | if UI execution context not found. |  
    
 **示例代码：**   
```ts    
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';  
import { BusinessError } from '@ohos.base';  
let promptAction: PromptAction = uiContext.getPromptAction();  
try {  
  promptAction.showToast({              
    message: 'Message Info',  
    duration: 2000   
  });  
} catch (error) {  
  let message = (error as BusinessError).message;  
  let code = (error as BusinessError).code;  
  console.error(`showToast args error code is ${code}, message is ${message}`);  
};  
    
```    
  
    
### showDialog  
 **调用形式：**     
    
- showDialog(options: promptAction.ShowDialogOptions, callback: AsyncCallback\<promptAction.ShowDialogSuccessResponse>): void    
起始版本： 10    
- showDialog(options: promptAction.ShowDialogOptions): Promise\<promptAction.ShowDialogSuccessResponse>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | promptAction.ShowDialogOptions | true | 页面显示对话框信息描述。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 对话框选项。 |  
| Promise<promptAction.ShowDialogSuccessResponse> | 对话框响应结果 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 100001 | if UI execution context not found. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';  
import { BusinessError } from '@ohos.base';  
class buttonsMoabl {  
  text: string = ""  
  color: string = ""  
}  
let promptAction: PromptAction = uiContext.getPromptAction();  
try {  
  promptAction.showDialog({  
    title: 'showDialog Title Info',  
    message: 'Message Info',  
    buttons: [  
      {  
        text: 'button1',  
        color: '#000000'  
      } as buttonsMoabl,  
      {  
        text: 'button2',  
        color: '#000000'  
      } as buttonsMoabl  
    ]  
  }, (err, data) => {  
    if (err) {  
      console.info('showDialog err: ' + err);  
      return;  
    }  
    console.info('showDialog success callback, click button: ' + data.index);  
  });  
} catch (error) {  
  let message = (error as BusinessError).message;  
  let code = (error as BusinessError).code;  
  console.error(`showDialog args error code is ${code}, message is ${message}`);  
};  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';  
import { BusinessError } from '@ohos.base';  
let promptAction: PromptAction = uiContext.getPromptAction();  
try {  
  promptAction.showDialog({  
    title: 'Title Info',  
    message: 'Message Info',  
    buttons: [  
      {  
        text: 'button1',  
        color: '#000000'  
      },  
      {  
        text: 'button2',  
        color: '#000000'  
      }  
    ],  
  })  
    .then(data => {  
      console.info('showDialog success, click button: ' + data.index);  
    })  
    .catch((err:Error) => {  
      console.info('showDialog error: ' + err);  
    })  
} catch (error) {  
  let message = (error as BusinessError).message;  
  let code = (error as BusinessError).code;  
  console.error(`showDialog args error code is ${code}, message is ${message}`);  
};  
    
```    
  
    
### showActionMenu    
创建并显示操作菜单，菜单响应结果异步返回。  
 **调用形式：**     
    
- showActionMenu(options: promptAction.ActionMenuOptions, callback: promptAction.ActionMenuSuccessResponse): void    
起始版本： 10    
- showActionMenu(options: promptAction.ActionMenuOptions): Promise\<promptAction.ActionMenuSuccessResponse>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | promptAction.ActionMenuOptions | true | 操作菜单选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 操作菜单选项。 |  
| Promise<promptAction.ActionMenuSuccessResponse> | 菜单响应结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 100001 | if UI execution context not found. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';  
import promptAction from '@ohos.promptAction';  
import { BusinessError } from '@ohos.base';  
class buttonsMoabl {  
  text: string = ""  
  color: string = ""  
}  
class dataR{  
  err:Error = new Error;  
  data:promptAction.ActionMenuSuccessResponse | undefined = undefined;  
}  
let dataAMSR:dataR = new dataR()  
let promptActionF: PromptAction = uiContext.getPromptAction();  
try {  
  if(dataAMSR.data){  
    promptActionF.showActionMenu({  
      title: 'Title Info',  
      buttons: [  
        {  
          text: 'item1',  
          color: '#666666'  
        } as buttonsMoabl,  
        {  
          text: 'item2',  
          color: '#000000'  
        } as buttonsMoabl  
      ]  
    }, (dataAMSR.data))  
    if (dataAMSR.err) {  
      console.info('showActionMenu err: ' + dataAMSR.err);  
    }else{  
      console.info('showActionMenu success callback, click button: ' + dataAMSR.data.index);  
    }  
  }  
} catch (error) {  
  let message = (error as BusinessError).message;  
  let code = (error as BusinessError).code;  
  console.error(`showActionMenu args error code is ${code}, message is ${message}`);  
};  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';  
import { BusinessError } from '@ohos.base';  
let promptAction: PromptAction = uiContext.getPromptAction();  
try {  
  promptAction.showActionMenu({  
    title: 'showActionMenu Title Info',  
    buttons: [  
      {  
        text: 'item1',  
        color: '#666666'  
      },  
      {  
        text: 'item2',  
        color: '#000000'  
      },  
    ]  
  })  
    .then(data => {  
      console.info('showActionMenu success, click button: ' + data.index);  
    })  
    .catch((err:Error) => {  
      console.info('showActionMenu error: ' + err);  
    })  
} catch (error) {  
  let message = (error as BusinessError).message;  
  let code = (error as BusinessError).code;  
  console.error(`showActionMenu args error code is ${code}, message is ${message}`);  
};  
    
```    
  
    
## ComponentUtils    
以下API需先使用UIContext中的[getComponentUtils()](#getcomponentutils)方法获取到ComponentUtils对象，再通过该对象调用对应方法。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### getRectangleById    
获取组件大小、位置、平移缩放旋转及仿射矩阵属性信息。  
 **调用形式：**     
- getRectangleById(id: string): componentUtils.ComponentInfo  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| id | string | true | 组件唯一标识id。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| componentUtils.ComponentInfo | 组件大小、位置、平移缩放旋转及仿射矩阵属性信息。 |  
    
 **示例代码：**   
```ts    
import { ComponentUtils, Font, PromptAction, Router, UIInspector, MediaQuery } from '@ohos.arkui.UIContext';  
let componentUtils:ComponentUtils = uiContext.getComponentUtils();  
let modePosition = componentUtils.getRectangleById("onClick");  
let localOffsetWidth = modePosition.size.width;  
let localOffsetHeight = modePosition.size.height;  
    
```    
  
    
## UIContext    
以下API需先使用ohos.window中的[getUIContext()](./js-apis-window.md#getuicontext10)方法获取UIContext实例，再通过此实例调用对应方法。本文中UIContext对象以uiContext表示。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### getFont    
获取Font对象。  
 **调用形式：**     
- getFont(): Font  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Font | 返回Font实例对象。 |  
    
 **示例代码：**   
```ts    
uiContext.getFont();    
```    
  
    
### getMediaQuery    
获取MediaQuery对象。  
 **调用形式：**     
- getMediaQuery(): MediaQuery  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| MediaQuery | 返回MediaQuery实例对象。 |  
    
 **示例代码：**   
```ts    
uiContext.getMediaQuery();    
```    
  
    
### getUIInspector    
获取UIInspector对象。  
 **调用形式：**     
- getUIInspector(): UIInspector  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| UIInspector | 返回UIInspector实例对象。 |  
    
 **示例代码：**   
```ts    
uiContext.getUIInspector();    
```    
  
    
### getRouter    
获取Router对象。  
 **调用形式：**     
- getRouter(): Router  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Router | 返回Router实例对象。 |  
    
 **示例代码：**   
```ts    
uiContext.getRouter();    
```    
  
    
### getPromptAction    
获取PromptAction对象。  
 **调用形式：**     
- getPromptAction(): PromptAction  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| PromptAction | 返回PromptAction实例对象。 |  
    
 **示例代码：**   
```ts    
uiContext.getRouter();    
```    
  
    
### getComponentUtils    
获取ComponentUtils对象。  
 **调用形式：**     
- getComponentUtils(): ComponentUtils  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ComponentUtils | 返回ComponentUtils实例对象。 |  
    
 **示例代码：**   
```ts    
uiContext.getComponentUtils();    
```    
  
    
### createAnimator    
定义Animator类。  
 **调用形式：**     
- createAnimator(options: AnimatorOptions): AnimatorResult  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | AnimatorOptions | true | 定义动画选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| AnimatorResult | Animator结果接口。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { AnimatorOptions } from '@ohos.animator';  
let options:AnimatorOptions = {  
  duration: 1500,  
  easing: "friction",  
  delay: 0,  
  fill: "forwards",  
  direction: "normal",  
  iterations: 3,  
  begin: 200.0,  
  end: 400.0  
};  
    
```    
  
    
### animateTo    
提供animateTo接口来指定由于闭包代码导致的状态变化插入过渡动效。  
 **调用形式：**     
- animateTo(value: AnimateParam, event: () => void): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | AnimateParam | true | 设置动画效果相关参数。  |  
| event | () => void | true | 指定显示动效的闭包函数，在闭包函数中导致的状态变化系统会自动插入过渡动画。 |  
    
 **示例代码：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct AnimateToExample {  
  @State widthSize: number = 250  
  @State heightSize: number = 100  
  @State rotateAngle: number = 0  
  private flag: boolean = true  
  
  build() {  
    Column() {  
      Button('change size')  
        .width(this.widthSize)  
        .height(this.heightSize)  
        .margin(30)  
        .onClick(() => {  
          if (this.flag) {  
            uiContext.animateTo({  
              duration: 2000,  
              curve: Curve.EaseOut,  
              iterations: 3,  
              playMode: PlayMode.Normal,  
              onFinish: () => {  
                console.info('play end')  
              }  
            }, () => {  
              this.widthSize = 150  
              this.heightSize = 60  
            })  
          } else {  
            uiContext.animateTo({}, () => {  
              this.widthSize = 250  
              this.heightSize = 100  
            })  
          }  
          this.flag = !this.flag  
        })  
      Button('change rotate angle')  
        .margin(50)  
        .rotate({ x: 0, y: 0, z: 1, angle: this.rotateAngle })  
        .onClick(() => {  
          uiContext.animateTo({  
            duration: 1200,  
            curve: Curve.Friction,  
            delay: 500,  
            iterations: -1, // 设置-1表示动画无限循环  
            playMode: PlayMode.Alternate,  
            onFinish: () => {  
              console.info('play end')  
            }  
          }, () => {  
            this.rotateAngle = 90  
          })  
        })  
    }.width('100%').margin({ top: 5 })  
  }  
}  
    
```    
  
    
### showAlertDialog    
显示警告弹窗组件，可设置文本内容与响应回调。  
 **调用形式：**     
- showAlertDialog(options: AlertDialogParamWithConfirm | AlertDialogParamWithButtons | AlertDialogParamWithOptions): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | string | true | 定义并显示AlertDialog组件。 |  
    
 **示例代码：**   
```ts    
uiContext.showAlertDialog(  {    title: 'title',    message: 'text',    autoCancel: true,    alignment: DialogAlignment.Bottom,    offset: { dx: 0, dy: -20 },    gridCount: 3,    confirm: {      value: 'button',      action: () => {        console.info('Button-clicking callback')      }    },    cancel: () => {      console.info('Closed callbacks')    }  })    
```    
  
    
### showActionSheet    
定义列表弹窗并弹出。  
 **调用形式：**     
- showActionSheet(value: ActionSheetOptions): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | ActionSheetOptions | true |  |  
    
 **示例代码：**   
```ts    
uiContext.showActionSheet({  title: 'ActionSheet title',  message: 'message',  autoCancel: true,  confirm: {    value: 'Confirm button',    action: () => {      console.log('Get Alert Dialog handled')    }  },  cancel: () => {    console.log('actionSheet canceled')  },  alignment: DialogAlignment.Bottom,  offset: { dx: 0, dy: -10 },  sheets: [    {      title: 'apples',      action: () => {        console.log('apples')      }    },    {      title: 'bananas',      action: () => {        console.log('bananas')      }    },    {      title: 'pears',      action: () => {        console.log('pears')      }    }  ]})    
```    
  
    
### showDatePickerDialog    
定义日期滑动选择器弹窗并弹出。  
 **调用形式：**     
- showDatePickerDialog(options: DatePickerDialogOptions): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | DatePickerDialogOptions | true |  |  
    
 **示例代码：**   
```ts    
let selectedDate: Date = new Date("2010-1-1")uiContext.showDatePickerDialog({  start: new Date("2000-1-1"),  end: new Date("2100-12-31"),  selected: selectedDate,  onAccept: (value: DatePickerResult) => {    // 通过Date的setFullYear方法设置按下确定按钮时的日期，这样当弹窗再次弹出时显示选中的是上一次确定的日期    selectedDate.setFullYear(Number(value.year), Number(value.month), Number(value.day))    console.info("DatePickerDialog:onAccept()" + JSON.stringify(value))  },  onCancel: () => {    console.info("DatePickerDialog:onCancel()")  },  onChange: (value: DatePickerResult) => {    console.info("DatePickerDialog:onChange()" + JSON.stringify(value))  }})    
```    
  
    
### showTimePickerDialog    
定义时间滑动选择器弹窗并弹出。  
 **调用形式：**     
- showTimePickerDialog(options: TimePickerDialogOptions): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | TimePickerDialogOptions | true |  |  
    
 **示例代码：**   
```ts    
class sethours{  selectTime: Date = new Date('2020-12-25T08:30:00')  hours(h:number,m:number){    this.selectTime.setHours(h,m)  }}uiContext.showTimePickerDialog({  selected: this.selectTime,  onAccept: (value: TimePickerResult) => {    // 设置selectTime为按下确定按钮时的时间，这样当弹窗再次弹出时显示选中的为上一次确定的时间    let time = new sethours()    if(value.hourvalue.minute){      time.hours(value.hour, value.minute)    }    console.info("TimePickerDialog:onAccept()" + JSON.stringify(value))  },  onCancel: () => {    console.info("TimePickerDialog:onCancel()")  },  onChange: (value: TimePickerResult) => {    console.info("TimePickerDialog:onChange()" + JSON.stringify(value))  }})    
```    
  
    
### showTextPickerDialog    
定义文本滑动选择器弹窗并弹出。  
 **调用形式：**     
- showTextPickerDialog(options: TextPickerDialogOptions): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | TextPickerDialogOptions | true |  |  
    
 **示例代码：**   
```ts    
{ class setvalue{  select: number = 2  set(val:number){    this.select = val  }}class setvaluearr{  select: number[] = []  set(val:number[]){    this.select = val  }}let fruits: string[] = ['apple1', 'orange2', 'peach3', 'grape4', 'banana5']uiContext.showTextPickerDialog({  range: this.fruits,  selected: this.select,  onAccept: (value: TextPickerResult) => {    // 设置select为按下确定按钮时候的选中项index，这样当弹窗再次弹出时显示选中的是上一次确定的选项    let setv = new setvalue()    let setvarr = new setvaluearr()    if(value.index){      value.index instanceof Array?setvarr.set(value.index) : setv.set(value.index)    }    console.info("TextPickerDialog:onAccept()" + JSON.stringify(value))  },  onCancel: () => {    console.info("TextPickerDialog:onCancel()")  },  onChange: (value: TextPickerResult) => {    console.info("TextPickerDialog:onChange()" + JSON.stringify(value))  }})    
```    
  
    
### runScopedTask    
在当前UI上下文执行传入的回调函数。  
 **调用形式：**     
    
- runScopedTask(callback: () => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数 |  
    
 **示例代码：**   
```ts    
uiContext.runScopedTask(  () => {    console.log('Succeeded in runScopedTask');  });    
```    
  
