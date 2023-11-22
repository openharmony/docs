# @system.prompt    
创建并显示文本提示框、对话框和操作菜单。  
> **说明**   
>本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import prompt from '@system.prompt';  
    
```  
    
## ShowToastOptions<sup>(deprecated)</sup>    
定义ShowToast的选项。    
从API version 3 开始支持，从API version 8 开始废弃。建议使用ohos.prompt替代。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| message<sup>(deprecated)</sup> | string | false | true | 从API version 3 开始支持，从API version 8 开始废弃。<br>显示的文本信息。 |  
| duration<sup>(deprecated)</sup> | number | false | false | 从API version 3 开始支持，从API version 8 开始废弃。<br>默认值1500ms，建议区间：1500ms-10000ms。若小于1500ms则取默认值，最大取值为10000ms |  
| bottom<sup>(deprecated)</sup> | string \| number | false | false | 从API version 5 开始支持，从API version 8 开始废弃。<br>设置弹窗边框距离屏幕底部的位置。 |  
    
## Button    
定义按钮的提示信息。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| text | string | false | true | 定义按钮信息。 |  
| color | string | false | true | 定义按钮颜色。 |  
    
## ShowDialogSuccessResponse    
定义ShowDialog的响应。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| index | number | false | true | 定义数据的索引信息。 |  
    
## ShowDialogOptions    
定义显示对话框的选项。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| title | string | false | false | 标题文本。 |  
| message | string | false | false | 文本内容。 |  
| buttons | [Button, Button?, Button?] | false | false | 对话框中按钮的数组，结构为：{text:'button', color: '\#666666'}，支持1-6个按钮。大于6个按钮时弹窗不显示。 |  
| success | function | false | false | 接口调用成功的回调函数。 |  
| cancel | function | false | false | 接口调用失败的回调函数。 |  
| complete | function | false | false | 接口调用结束的回调函数。 |  
    
## ShowActionMenuOptions<sup>(6+)</sup>    
定义ShowActionMenu的选项。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| title<sup>(6+)</sup> | string | false | false | 标题文本。 |  
| buttons<sup>(6+)</sup> | [Button, Button, Button?, Button?, Button?, Button?] | false | false | 对话框中按钮的数组，结构为：{text:'button', color: '\#666666'}，支持1-6个按钮。 |  
| success<sup>(6+)</sup> | function | false | false | 弹出对话框时调用。 |  
| fail<sup>(6+)</sup> | function | false | false | 接口调用失败的回调函数。 |  
| complete<sup>(6+)</sup> | function | false | false | 关闭对话框时调用。 |  
    
## Prompt    
创建并显示文本提示框、对话框和操作菜单。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### showToast    
显示文本弹窗。  
 **调用形式：**     
- static showToast(options: ShowToastOptions): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | ShowToastOptions | true | 定义ShowToast的选项。 |  
    
 **示例代码：**   
```js    
import prompt from '@system.prompt';class A{ showToast() {  prompt.showToast({   message: 'Message Info',   duration: 2000  }); }}export default new A()    
```    
  
    
### showDialog    
显示对话框。  
 **调用形式：**     
- static showDialog(options: ShowDialogOptions): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | ShowDialogOptions | true | 定义显示对话框的选项。 |  
    
 **示例代码：**   
```js    
import prompt from '@system.prompt';class B{ showDialog() {  prompt.showDialog({   title: 'Title Info',   message: 'Message Info',   buttons: [    {     text: 'button',     color: '#666666'    },   ],   success: (data)=> {    console.log('dialog success callback，click button : ' + data.index);   },   cancel: ()=> {    console.log('dialog cancel callback');   },  }); }}export default new B()    
```    
  
    
### showActionMenu<sup>(6+)</sup>    
显示操作菜单。  
 **调用形式：**     
- static showActionMenu(options: ShowActionMenuOptions): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | ShowActionMenuOptions | true | 定义ShowActionMenu的选项。 |  
    
 **示例代码：**   
```js    
import prompt from '@system.prompt';class C{ showActionMenu() {  prompt.showActionMenu({   title: 'Title Info',   buttons: [    {     text: 'item1',     color: '#666666'    },    {     text: 'item2',     color: '#000000'    },   ],   success: (tapIndex)=> {    console.log('dialog success callback，click button : ' + tapIndex);   },   fail: (errMsg)=> {    console.log('dialog fail callback' + errMsg);   },  }); }}export default new C()    
```    
  
