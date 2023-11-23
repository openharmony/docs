# @system.router    
通过不同的uri访问不同的页面。  
> **说明**   
>本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import router from '@system.router';  
    
```  
    
## RouterOptions<sup>(deprecated)</sup>    
定义路由器的选项。    
从API version 3 开始支持，从API version 8 开始废弃。建议使用ohos.router#RouterOptions替代。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Lite    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| uri<sup>(deprecated)</sup> | string | false | true | 从API version 3 开始支持，从API version 8 开始废弃。<br>目标页面的uri，可以是以下的两种格式：<br/>1. 页面的绝对路径，由config.json文件中的页面列表提供。例如：<br/>- pages/index/index<br/> -pages/detail/detail<br/>2. 特定路径。如果URI为斜杠（/），则显示主页。 |  
| params<sup>(deprecated)</sup> | Object | false | false | 从API version 3 开始支持，从API version 8 开始废弃。<br>表示路由跳转时要同时传递到目标页面的数据。跳转到目标页面后，使用router.getParams()获取传递的参数，此外，在类web范式中，参数也可以在页面中直接使用，如this.keyValue(keyValue为跳转时params参数中的key值)，如果目标页面中已有该字段，则其值会被传入的字段值覆盖。 |  
    
## BackRouterOptions<sup>(deprecated)</sup>    
定义路由器返回的选项。    
从API version 7 开始支持，从API version 8 开始废弃。建议使用ohos.router#RouterOptions替代。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| uri<sup>(deprecated)</sup> | string | false | false | 从API version 7 开始支持，从API version 8 开始废弃。系统能力：SystemCapability.ArkUI.ArkUI.Full<br>返回到指定uri的界面，如果页面栈上没有uri页面，则不响应该情况。如果uri未设置，则返回上一页。 <br>**系统能力：** SystemCapability.ArkUI.ArkUI.Full。 |  
| params<sup>(deprecated)</sup> | Object | false | false | 从API version 7 开始支持，从API version 8 开始废弃。系统能力：SystemCapability.ArkUI.ArkUI.Lite<br>跳转时要同时传递到目标页面的数据。 <br>**系统能力：** SystemCapability.ArkUI.ArkUI.Lite |  
    
## RouterState<sup>(deprecated)</sup>    
定义路由器的状态。    
从API version 3 开始支持，从API version 8 开始废弃。建议使用ohos.router#RouterState替代。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| index<sup>(deprecated)</sup> | number | false | true | 从API version 3 开始支持，从API version 8 开始废弃。<br>表示当前页面在页面栈中的索引。从栈底到栈顶，index从1开始递增。 |  
| name<sup>(deprecated)</sup> | string | false | true | 从API version 3 开始支持，从API version 8 开始废弃。<br>表示当前页面的名称，即对应文件名。 |  
| path<sup>(deprecated)</sup> | string | false | true | 从API version 3 开始支持，从API version 8 开始废弃。<br>表示当前页面的路径。 |  
    
## EnableAlertBeforeBackPageOptions<sup>(deprecated)</sup>    
定义EnableAlertBeforeBackPage选项。    
从API version 6 开始支持，从API version 8 开始废弃。建议使用ohos.router#RouterState替代。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| message<sup>(deprecated)</sup> | string | false | true | 从API version 6 开始支持，从API version 8 开始废弃。<br>询问对话框内容。 |  
| success<sup>(deprecated)</sup> | function | false | false | 从API version 6 开始支持，从API version 8 开始废弃。<br>用户选择对话框确认按钮时触发，errMsg表示返回信息。 |  
| cancel<sup>(deprecated)</sup> | function | false | false | 从API version 6 开始支持，从API version 8 开始废弃。<br>用户选择对话框取消按钮时触发，errMsg表示返回信息。 |  
| complete<sup>(deprecated)</sup> | function | false | false | 从API version 6 开始支持，从API version 8 开始废弃。<br>当对话框关闭时触发该回调。 |  
    
## DisableAlertBeforeBackPageOptions<sup>(deprecated)</sup>    
定义DisableAlertBeforeBackPage参数选项。    
从API version 6 开始支持，从API version 8 开始废弃。建议使用ohos.router#RouterOptions替代。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| success<sup>(deprecated)</sup> | function | false | false | 从API version 6 开始支持，从API version 8 开始废弃。<br>关闭询问对话框能力成功时触发，errMsg表示返回信息。 |  
| cancel<sup>(deprecated)</sup> | function | false | false | 从API version 6 开始支持，从API version 8 开始废弃。<br>关闭询问对话框能力失败时触发，errMsg表示返回信息。 |  
| complete<sup>(deprecated)</sup> | function | false | false | 从API version 6 开始支持，从API version 8 开始废弃。<br>当对话框关闭时触发该回调。 |  
    
## ParamsInterface    
路由参数列表。    
## Router<sup>(deprecated)</sup>    
从API version 3 开始支持，从API version 8 开始废弃。建议使用ohos.router#router替代。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Lite    
### push<sup>(deprecated)</sup>    
跳转到应用内的指定页面。  
 **调用形式：**     
- static push(options: RouterOptions): void  
  
 **废弃说明：** 从API version 8 开始废弃。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | RouterOptions | true | 页面路由参数，详细请参考RouterOptions。 |  
    
 **示例代码：**   
```js    
import router from '@system.router';class A{ pushPage() {  router.push({   uri: 'pages/routerpage2/routerpage2',   params: {    data1: 'message',    data2: {     data3: [123, 456, 789]    }   }  }); }}export default new A()    
```    
  
    
### replace<sup>(deprecated)</sup>    
用应用内的某个页面替换当前页面，并销毁被替换的页面。  
 **调用形式：**     
- static replace(options: RouterOptions): void  
  
 **废弃说明：** 从API version 8 开始废弃。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Lite    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | RouterOptions | true | 页面路由参数，详细请参考RouterOptions。 |  
    
 **示例代码：**   
```js    
// 在当前页面中import router from '@system.router';class C{ replacePage() {  router.replace({   uri: 'pages/detail/detail',   params: {    data1: 'message'   }  }); }}export default new C()// 在detail页面中  
class Area {  
  data:Record<string,string> = {'data1': 'default'}  
  onInit() {  
    console.info('showData1:' + this.data)  
  }  
}  
export default new Area()  
    
```    
  
    
### back<sup>(deprecated)</sup>    
返回上一页面或指定的页面。  
 **调用形式：**     
- static back(options?: BackRouterOptions): void  
  
 **废弃说明：** 从API version 8 开始废弃。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | BackRouterOptions | false | 详细请参考BackRouterOptions。 |  
    
 **示例代码：**   
```js    
// index页面import router from '@system.router';class D{ indexPushPage() {  router.push({   uri: 'pages/detail/detail'  }); }}export default new D()    
```    
  
    
### getParams<sup>(deprecated)</sup>    
获取当前页面的参数信息。  
 **调用形式：**     
- static getParams(): ParamsInterface  
  
 **废弃说明：** 从API version 8 开始废弃。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ParamsInterface | 详细请参见ParamsInterface。 |  
    
### clear<sup>(deprecated)</sup>    
清空页面栈中的所有历史页面，仅保留当前页面作为栈顶页面。  
 **调用形式：**     
- static clear(): void  
  
 **废弃说明：** 从API version 8 开始废弃。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### getLength<sup>(deprecated)</sup>    
获取当前在页面栈内的页面数量。  
 **调用形式：**     
- static getLength(): string  
  
 **废弃说明：** 从API version 8 开始废弃。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 页面数量，页面栈支持最大数值是32。 |  
    
 **示例代码：**   
```js    
import router from '@system.router';class J{ getLength() {  let size = router.getLength();  console.log('pages stack size = ' + size); }}export default new J()    
```    
  
    
### getState<sup>(deprecated)</sup>    
获取当前页面的状态信息。  
 **调用形式：**     
- static getState(): RouterState  
  
 **废弃说明：** 从API version 8 开始废弃。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RouterState | 详细请参见RouterState。 |  
    
 **示例代码：**   
```js    
import router from '@system.router';class K{ getState() {  let page = router.getState();  console.log('current index = ' + page.index);  console.log('current name = ' + page.name);  console.log('current path = ' + page.path); }}export default new K()    
```    
  
    
### enableAlertBeforeBackPage<sup>(deprecated)</sup>    
开启页面返回询问对话框。  
 **调用形式：**     
- static enableAlertBeforeBackPage(options: EnableAlertBeforeBackPageOptions): void  
  
 **废弃说明：** 从API version 8 开始废弃。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | EnableAlertBeforeBackPageOptions | true | 详细请参见EnableAlertBeforeBackPageOptions。 |  
    
 **示例代码：**   
```js    
import router from '@system.router';class L{ enableAlertBeforeBackPage() {  router.enableAlertBeforeBackPage({   message: 'Message Info',   success: ()=> {    console.log('success');   },   cancel: ()=> {    console.log('cancel');   }  }); }}export default new L()    
```    
  
    
### disableAlertBeforeBackPage<sup>(deprecated)</sup>    
禁用页面返回询问对话框。  
 **调用形式：**     
- static disableAlertBeforeBackPage(options?: DisableAlertBeforeBackPageOptions): void  
  
 **废弃说明：** 从API version 8 开始废弃。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | DisableAlertBeforeBackPageOptions | false | 详细请参见DisableAlertBeforeBackPageOptions。 |  
    
 **示例代码：**   
```js    
import router from '@system.router';class Z{ disableAlertBeforeBackPage() {  router.disableAlertBeforeBackPage({   success: ()=> {    console.log('success');   },   cancel: ()=> {    console.log('cancel');   }  }); }}export default new Z()    
```    
  
