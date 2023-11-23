# @ohos.router    
本模块提供通过不同的url访问不同的页面，包括跳转到应用内的指定页面、同应用内的某个页面替换当前页面、返回上一页面或指定的页面等。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import router from '@ohos.router'    
```  
    
## RouterMode<sup>(9+)</sup>    
路由跳转模式。    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Standard | 0 | 多实例模式，也是默认情况下的跳转模式。 <br/>目标页面会被添加到页面栈顶，无论栈中是否存在相同url的页面。<br/>**说明：** 不使用路由跳转模式时，则按照默认的多实例模式进行跳转。 |  
| Single | 1 | 单实例模式。<br/>如果目标页面的url已经存在于页面栈中，则会将离栈顶最近的同url页面移动到栈顶，该页面成为新建页。<br />如果目标页面的url在页面栈中不存在同url页面，则按照默认的多实例模式进行跳转。 |  
    
## RouterOptions    
路由跳转选项。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Lite    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| url | string | false | true |  表示目标页面的url，可以用以下两种格式：<br/>-页面绝对路径，由配置文件中pages列表提供，例如：<br/>-pages/index/index<br/>-pages/detail/detail<br/>-特殊值，如果url的值是"/"，则跳转到首页。 |  
| params | Object | false | false | 表示路由跳转时要同时传递到目标页面的数据，切换到其他页面时，当前接收的数据失效。跳转到目标页面后，使用router.getParams()获取传递的参数，此外，在类web范式中，参数也可以在页面中直接使用，如this.keyValue(keyValue为跳转时params参数中的key值)，如果目标页面中已有该字段，则其值会被传入的字段值覆盖。<br/>**说明：** <br/>params参数不能传递方法和系统接口返回的对象（例如，媒体接口定义和返回的PixelMap对象）。建议开发者提取系统接口返回的对象中需要被传递的基础类型属性，自行构造object类型对象进行传递。 |  
    
## RouterState    
页面状态信息。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| index | number | false | true | 表示当前页面在页面栈中的索引。从栈底到栈顶，index从1开始递增。 |  
| name | string | false | true | 表示当前页面的名称，即对应文件名。 |  
| path | string | false | true | 表示当前页面的路径。   |  
    
## EnableAlertOptions    
页面返回询问对话框选项。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| message | string | false | true | 询问对话框内容。 |  
    
## push<sup>(deprecated)</sup>    
跳转到应用内的指定页面。  
 **调用形式：**     
- push(options: RouterOptions): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.router.router#pushUrl。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | RouterOptions | true | 跳转页面描述信息。  |  
    
 **示例代码：**   
```ts    
class innerParams {  
  data3:number[]  
  
  constructor(tuple:number[]) {  
    this.data3 = tuple  
  }  
}  
  
class routerParams {  
  data1:string  
  data2:innerParams  
  
  constructor(str:string, tuple:number[]) {  
    this.data1 = str  
    this.data2 = new innerParams(tuple)  
  }  
}  
  
router.push({  
  url: 'pages/routerpage2',  
  params: new routerParams('message' ,[123,456,789])  
});  
    
```    
  
    
## pushUrl<sup>(9+)</sup>    
跳转到应用内的指定页面。  
 **调用形式：**     
    
- pushUrl(options: RouterOptions, callback: AsyncCallback\<void>): void    
起始版本： 9    
- pushUrl(options: RouterOptions): Promise\<void>    
起始版本： 9    
- pushUrl(options: RouterOptions, mode: RouterMode, callback: AsyncCallback\<void>): void    
起始版本： 9    
- pushUrl(options: RouterOptions, mode: RouterMode): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | RouterOptions | true | 跳转页面描述信息。 |  
| mode | RouterMode | true | 跳转页面使用的模式。 |  
    
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
参数：option 示例promise  
```ts    
import { BusinessError } from '@ohos.base';  
  
class innerParams {  
  data3:number[]  
  
  constructor(tuple:number[]) {  
    this.data3 = tuple  
  }  
}  
  
class routerParams {  
  data1:string  
  data2:innerParams  
  
  constructor(str:string, tuple:number[]) {  
    this.data1 = str  
    this.data2 = new innerParams(tuple)  
  }  
}  
  
try {  
  router.pushUrl({  
    url: 'pages/routerpage2',  
    params: new routerParams('message' ,[123,456,789])  
  })  
} catch (err) {  
  console.error(`pushUrl failed, code is ${(err as BusinessError).code}, message is ${(err as BusinessError).message}`);  
}  
    
```    
  
    
 **示例代码2：**   
参数：option 示例（callback）  
  
```ts    
class innerParams {  
  data3:number[]  
  
  constructor(tuple:number[]) {  
    this.data3 = tuple  
  }  
}  
  
class routerParams {  
  data1:string  
  data2:innerParams  
  
  constructor(str:string, tuple:number[]) {  
    this.data1 = str  
    this.data2 = new innerParams(tuple)  
  }  
}  
  
router.pushUrl({  
  url: 'pages/routerpage2',  
  params: new routerParams('message' ,[123,456,789])  
}, (err) => {  
  if (err) {  
    console.error(`pushUrl failed, code is ${err.code}, message is ${err.message}`);  
    return;  
  }  
  console.info('pushUrl success');  
})  
    
```    
  
    
 **示例代码3：**   
参数（option mode） 示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
class innerParams {  
  data3:number[]  
  
  constructor(tuple:number[]) {  
    this.data3 = tuple  
  }  
}  
  
class routerParams {  
  data1:string  
  data2:innerParams  
  
  constructor(str:string, tuple:number[]) {  
    this.data1 = str  
    this.data2 = new innerParams(tuple)  
  }  
}  
  
try {  
  router.pushUrl({  
    url: 'pages/routerpage2',  
    params: new routerParams('message' ,[123,456,789])  
  }, router.RouterMode.Standard)  
} catch (err) {  
  console.error(`pushUrl failed, code is ${(err as BusinessError).code}, message is ${(err as BusinessError).message}`);  
}  
    
```    
  
    
 **示例代码4：**   
参数（option mode） 示例（callback）  
  
```ts    
class innerParams {  
  data3:number[]  
  
  constructor(tuple:number[]) {  
    this.data3 = tuple  
  }  
}  
  
class routerParams {  
  data1:string  
  data2:innerParams  
  
  constructor(str:string, tuple:number[]) {  
    this.data1 = str  
    this.data2 = new innerParams(tuple)  
  }  
}  
  
router.pushUrl({  
  url: 'pages/routerpage2',  
  params: new routerParams('message' ,[123,456,789])  
}, router.RouterMode.Standard, (err) => {  
  if (err) {  
    console.error(`pushUrl failed, code is ${err.code}, message is ${err.message}`);  
    return;  
  }  
  console.info('pushUrl success');  
})  
    
```    
  
    
## replace<sup>(deprecated)</sup>    
用应用内的某个页面替换当前页面，并销毁被替换的页面。  
 **调用形式：**     
- replace(options: RouterOptions): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.router.router#replaceUrl。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Lite    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | RouterOptions | true | 替换页面描述信息。 |  
    
 **示例代码：**   
```ts    
class routerParams {  
  data1:string  
  
  constructor(str:string) {  
    this.data1 = str  
  }  
}  
  
router.replace({  
  url: 'pages/detail',  
  params: new routerParams('message')  
});  
    
```    
  
    
## replaceUrl<sup>(9+)</sup>    
用应用内的某个页面替换当前页面，并销毁被替换的页面。不支持设置页面转场动效，如需设置，推荐使用[Navigation组件](../../ui/arkts-navigation-navigation.md)。  
 **调用形式：**     
    
- replaceUrl(options: RouterOptions, callback: AsyncCallback\<void>): void    
起始版本： 9    
- replaceUrl(options: RouterOptions): Promise\<void>    
起始版本： 9    
- replaceUrl(options: RouterOptions, mode: RouterMode, callback: AsyncCallback\<void>): void    
起始版本： 9    
- replaceUrl(options: RouterOptions, mode: RouterMode): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Lite    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | RouterOptions | true | 替换页面描述信息。 |  
| mode | RouterMode | true | 跳转页面使用的模式。 |  
    
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
参数（option） 示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
class routerParams {  
  data1:string  
  
  constructor(str:string) {  
    this.data1 = str  
  }  
}  
  
try {  
  router.replaceUrl({  
    url: 'pages/detail',  
    params: new routerParams('message')  
  })  
} catch (err) {  
  console.error(`replaceUrl failed, code is ${(err as BusinessError).code}, message is ${(err as BusinessError).message}`);  
}  
    
```    
  
    
 **示例代码2：**   
参数（options） 示例(callback)  
```ts    
class routerParams {  
  data1:string  
  
  constructor(str:string) {  
    this.data1 = str  
  }  
}  
  
router.replaceUrl({  
  url: 'pages/detail',  
  params: new routerParams('message')  
}, (err) => {  
  if (err) {  
    console.error(`replaceUrl failed, code is ${err.code}, message is ${err.message}`);  
    return;  
  }  
  console.info('replaceUrl success');  
})  
    
```    
  
    
 **示例代码3：**   
参数（options mode） 示例(promise)  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
class routerParams {  
  data1:string  
  
  constructor(str:string) {  
    this.data1 = str  
  }  
}  
  
try {  
  router.replaceUrl({  
    url: 'pages/detail',  
    params: new routerParams('message')  
  }, router.RouterMode.Standard)  
} catch (err) {  
  console.error(`replaceUrl failed, code is ${(err as BusinessError).code}, message is ${(err as BusinessError).message}`);  
}  
    
```    
  
    
 **示例代码4：**   
参数（options mode） 示例(callback)  
  
```ts    
class routerParams {  
  data1:string  
  
  constructor(str:string) {  
    this.data1 = str  
  }  
}  
  
router.replaceUrl({  
  url: 'pages/detail',  
  params: new routerParams('message')  
}, router.RouterMode.Standard, (err) => {  
  if (err) {  
    console.error(`replaceUrl failed, code is ${err.code}, message is ${err.message}`);  
    return;  
  }  
  console.info('replaceUrl success');  
});  
    
```    
  
    
## back    
返回上一页面或指定的页面。  
。router.back({url:'pages/detail'});    。  
 **调用形式：**     
- back(options?: RouterOptions): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | RouterOptions | false | 返回页面描述信息，其中参数url指路由跳转时会返回到指定url的界面，如果页面栈上没有url页面，则不响应该情况。如果url未设置，则返回上一页，页面不会重新构建，页面栈里面的page不会回收，出栈后会被回收。 |  
    
 **示例代码：**   
```ts    
router.back({url:'pages/detail'});        
```    
  
    
## clear    
清空页面栈中的所有历史页面，仅保留当前页面作为栈顶页面。  
 **调用形式：**     
- clear(): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **示例代码：**   
```ts    
router.clear();        
```    
  
    
## getLength    
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
let size = router.getLength();          
console.log('pages stack size = ' + size);        
```    
  
    
## getState    
获取当前页面的状态信息。  
 **调用形式：**     
- getState(): RouterState  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RouterState | 页面状态信息。 |  
    
 **示例代码：**   
```ts    
let page = router.getState();  
console.log('current index = ' + page.index);  
console.log('current name = ' + page.name);  
console.log('current path = ' + page.path);    
```    
  
    
## enableAlertBeforeBackPage<sup>(deprecated)</sup>    
开启页面返回询问对话框。  
  
从API version9开始不再维护，建议使用[showAlertBeforeBackPage<sup>9+</sup>](#routershowalertbeforebackpage9)。  
 **调用形式：**     
- enableAlertBeforeBackPage(options: EnableAlertOptions): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.router.router#showAlertBeforeBackPage。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | EnableAlertOptions | true | 文本弹窗信息描述。 |  
    
 **示例代码：**   
```ts    
router.enableAlertBeforeBackPage({  
  message: 'Message Info'  
});    
```    
  
    
## showAlertBeforeBackPage<sup>(9+)</sup>    
开启页面返回询问对话框。  
 **调用形式：**     
- showAlertBeforeBackPage(options: EnableAlertOptions): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | EnableAlertOptions | true | 文本弹窗信息描述。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 100001 | if UI execution context not found. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  router.showAlertBeforeBackPage({  
    message: 'Message Info'  
  });  
} catch(err) {  
  console.error(`showAlertBeforeBackPage failed, code is ${(err as BusinessError).code}, message is ${(err as BusinessError).message}`);  
}  
    
```    
  
    
## disableAlertBeforeBackPage<sup>(deprecated)</sup>    
禁用页面返回询问对话框。  
 **调用形式：**     
- disableAlertBeforeBackPage(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.router.router#hideAlertBeforeBackPage。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **示例代码：**   
```ts    
router.disableAlertBeforeBackPage();    
```    
  
    
## hideAlertBeforeBackPage<sup>(9+)</sup>    
禁用页面返回询问对话框。  
 **调用形式：**     
- hideAlertBeforeBackPage(): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **示例代码：**   
```ts    
router.hideAlertBeforeBackPage();        
```    
  
    
## getParams    
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
router.getParams();    
```    
  
    
## NamedRouterOptions<sup>(10+)</sup>    
命名路由跳转选项。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| name<sup>(10+)</sup> | string | false | true | 表示目标命名路由页面的name。 |  
| params<sup>(10+)</sup> | Object | false | false |  表示路由跳转时要同时传递到目标页面的数据。跳转到目标页面后，使用router.getParams()获取传递的参数，此外，在类web范式中，参数也可以在页面中直接使用，如this.keyValue(keyValue为跳转时params参数中的key值)，如果目标页面中已有该字段，则其值会被传入的字段值覆盖。 |  
    
## pushNamedRoute<sup>(10+)</sup>    
跳转到指定的命名路由页面。  
 **调用形式：**     
    
- pushNamedRoute(options: NamedRouterOptions, callback: AsyncCallback\<void>): void    
起始版本： 10    
- pushNamedRoute(options: NamedRouterOptions): Promise\<void>    
起始版本： 10    
- pushNamedRoute(options: NamedRouterOptions, mode: RouterMode, callback: AsyncCallback\<void>): void    
起始版本： 10    
- pushNamedRoute(options: NamedRouterOptions, mode: RouterMode): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | NamedRouterOptions | true | 跳转页面描述信息。 |  
| mode | RouterMode | true | 跳转页面使用的模式。 |  
    
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
| 100003 | if the pages are pushed too much. |  
| 100004 | if the named route is not exist. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
class innerParams {  
  data3:number[]  
  
  constructor(tuple:number[]) {  
    this.data3 = tuple  
  }  
}  
  
class routerParams {  
  data1:string  
  data2:innerParams  
  
  constructor(str:string, tuple:number[]) {  
    this.data1 = str  
    this.data2 = new innerParams(tuple)  
  }  
}  
  
try {  
  router.pushNamedRoute({  
    name: 'myPage',  
    params: new routerParams('message' ,[123,456,789])  
  })  
} catch (err) {  
  console.error(`pushNamedRoute failed, code is ${(err as BusinessError).code}, message is ${(err as BusinessError).message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
class innerParams {  
  data3:number[]  
  
  constructor(tuple:number[]) {  
    this.data3 = tuple  
  }  
}  
  
class routerParams {  
  data1:string  
  data2:innerParams  
  
  constructor(str:string, tuple:number[]) {  
    this.data1 = str  
    this.data2 = new innerParams(tuple)  
  }  
}  
  
try {  
  router.pushNamedRoute({  
    name: 'myPage',  
    params: new routerParams('message' ,[123,456,789])  
  }, router.RouterMode.Standard)  
} catch (err) {  
  console.error(`pushNamedRoute failed, code is ${(err as BusinessError).code}, message is ${(err as BusinessError).message}`);  
}  
    
```    
  
    
 **示例代码3：**   
参数（options mode）示例（callback）  
```ts    
class innerParams {  
  data3:number[]  
  
  constructor(tuple:number[]) {  
    this.data3 = tuple  
  }  
}  
  
class routerParams {  
  data1:string  
  data2:innerParams  
  
  constructor(str:string, tuple:number[]) {  
    this.data1 = str  
    this.data2 = new innerParams(tuple)  
  }  
}  
  
router.pushNamedRoute({  
  name: 'myPage',  
  params: new routerParams('message' ,[123,456,789])  
}, router.RouterMode.Standard, (err) => {  
  if (err) {  
    console.error(`pushNamedRoute failed, code is ${err.code}, message is ${err.message}`);  
    return;  
  }  
  console.info('pushNamedRoute success');  
})  
    
```    
  
    
 **示例代码4：**   
参数（options mode）示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
class innerParams {  
  data3:number[]  
  
  constructor(tuple:number[]) {  
    this.data3 = tuple  
  }  
}  
  
class routerParams {  
  data1:string  
  data2:innerParams  
  
  constructor(str:string, tuple:number[]) {  
    this.data1 = str  
    this.data2 = new innerParams(tuple)  
  }  
}  
  
try {  
  router.pushNamedRoute({  
    name: 'myPage',  
    params: new routerParams('message' ,[123,456,789])  
  }, router.RouterMode.Standard)  
} catch (err) {  
  console.error(`pushNamedRoute failed, code is ${(err as BusinessError).code}, message is ${(err as BusinessError).message}`);  
}  
    
```    
  
    
## replaceNamedRoute<sup>(10+)</sup>    
用指定的命名路由页面替换当前页面，并销毁被替换的页面。  
 **调用形式：**     
    
- replaceNamedRoute(options: NamedRouterOptions, callback: AsyncCallback\<void>): void    
起始版本： 10    
- replaceNamedRoute(options: NamedRouterOptions): Promise\<void>    
起始版本： 10    
- replaceNamedRoute(options: NamedRouterOptions, mode: RouterMode, callback: AsyncCallback\<void>): void    
起始版本： 10    
- replaceNamedRoute(options: NamedRouterOptions, mode: RouterMode): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | NamedRouterOptions | true |  替换页面描述信息。 |  
| mode | RouterMode | true | 跳转页面使用的模式。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异常响应回调。 |  
| Promise<void> | 异常返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 100001 | if UI execution context not found, only throw in standard system. |  
| 100004 | if the named route is not exist. |  
    
 **示例代码1：**   
参数（options）示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
class routerParams {  
  data1:string  
  
  constructor(str:string) {  
    this.data1 = str  
  }  
}  
  
try {  
  router.replaceNamedRoute({  
    name: 'myPage',  
    params: new routerParams('message')  
  })  
} catch (err) {  
  console.error(`replaceNamedRoute failed, code is ${(err as BusinessError).code}, message is ${(err as BusinessError).message}`);  
}  
    
```    
  
    
 **示例代码2：**   
参数（options）示例（callback）  
  
```ts    
class routerParams {  
  data1:string  
  
  constructor(str:string) {  
    this.data1 = str  
  }  
}  
  
router.replaceNamedRoute({  
  name: 'myPage',  
  params: new routerParams('message')  
}, (err) => {  
  if (err) {  
    console.error(`replaceNamedRoute failed, code is ${err.code}, message is ${err.message}`);  
    return;  
  }  
  console.info('replaceNamedRoute success');  
})  
    
```    
  
    
 **示例代码3：**   
参数（options mode）示例（promise）  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
class routerParams {  
  data1:string  
  
  constructor(str:string) {  
    this.data1 = str  
  }  
}  
  
try {  
  router.replaceNamedRoute({  
    name: 'myPage',  
    params: new routerParams('message')  
  }, router.RouterMode.Standard)  
} catch (err) {  
  console.error(`replaceNamedRoute failed, code is ${(err as BusinessError).code}, message is ${(err as BusinessError).message}`);  
}  
    
```    
  
    
 **示例代码4：**   
参数（options mode）示例（callback）  
  
```ts    
class routerParams {  
  data1:string  
  
  constructor(str:string) {  
    this.data1 = str  
  }  
}  
  
router.replaceNamedRoute({  
  name: 'myPage',  
  params: new routerParams('message')  
}, router.RouterMode.Standard, (err) => {  
  if (err) {  
    console.error(`replaceNamedRoute failed, code is ${err.code}, message is ${err.message}`);  
    return;  
  }  
  console.info('replaceNamedRoute success');  
});  
    
```    
  
