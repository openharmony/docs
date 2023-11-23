# @ohos.prompt    
创建并显示文本提示框、对话框和操作菜单。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import prompt from '@ohos.prompt'    
```  
    
## ShowToastOptions<sup>(deprecated)</sup>    
文本提示框的选项。    
从API version 8 开始支持，从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| message<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>显示的文本信息。 |  
| duration<sup>(deprecated)</sup> | number | false | false | 从API version 8 开始支持，从API version 9 开始废弃。<br>默认值1500ms，取值区间：1500ms-10000ms。若小于1500ms则取默认值，若大于10000ms则取上限值10000ms。 |  
| bottom<sup>(deprecated)</sup> | string \| number | false | false | 从API version 8 开始支持，从API version 9 开始废弃。<br> 设置弹窗边框距离屏幕底部的位置，无上限值，默认单位vp。       |  
    
## Button<sup>(deprecated)</sup>    
菜单中的菜单项按钮。    
从API version 8 开始支持，从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| text<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>按钮文本内容。 |  
| color<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>按钮文本颜色。 |  
    
## ShowDialogSuccessResponse<sup>(deprecated)</sup>    
对话框的响应结果。    
从API version 8 开始支持，从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| index<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>选中按钮在buttons数组中的索引。 |  
    
## ShowDialogOptions<sup>(deprecated)</sup>    
对话框的选项。    
从API version 8 开始支持，从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| title<sup>(deprecated)</sup> | string | false | false | 从API version 8 开始支持，从API version 9 开始废弃。<br>标题文本。  |  
| message<sup>(deprecated)</sup> | string | false | false | 从API version 8 开始支持，从API version 9 开始废弃。<br>内容文本。 |  
| buttons<sup>(deprecated)</sup> | [Button, Button?, Button?] | false | false | 从API version 8 开始支持，从API version 9 开始废弃。<br>对话框中按钮的数组，结构为：{text:'button',color:'\#666666'}，支持1-3个按钮。其中第一个为positiveButton；第二个为negativeButton；第三个为neutralButton。 |  
    
## ActionMenuSuccessResponse<sup>(deprecated)</sup>    
操作菜单的响应结果。    
从API version 8 开始支持，从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| index<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br> 选中按钮在buttons数组中的索引，从0开始。 |  
    
## ActionMenuOptions<sup>(deprecated)</sup>    
操作菜单的选项。    
从API version 8 开始支持，从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| title<sup>(deprecated)</sup> | string | false | false | 从API version 8 开始支持，从API version 9 开始废弃。<br> 标题文本。         |  
| buttons<sup>(deprecated)</sup> | [Button, Button, Button?, Button?, Button?, Button?] | false | false | 从API version 8 开始支持，从API version 9 开始废弃。<br>菜单中菜单项按钮的数组，结构为：{text:'button',color:'\#666666'}，支持1-6个按钮。大于6个按钮时弹窗不显示。 |  
    
## showToast<sup>(deprecated)</sup>    
创建并显示文本提示框。  
 **调用形式：**     
- showToast(options: ShowToastOptions): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | ShowToastOptions | true | 文本弹窗选项。 |  
    
 **示例代码：**   
```ts    
import prompt from '@ohos.prompt'prompt.showToast({  message: 'Message Info',    duration: 2000});    
```    
  
![zh-cn_image_0001](figures/zh-cn_image_0001.gif)  
    
## showDialog<sup>(deprecated)</sup>    
创建并显示对话框，对话框响应后同步返回结果。  
 **调用形式：**     
- showDialog(options: ShowDialogOptions, callback: AsyncCallback\<ShowDialogSuccessResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | ShowDialogOptions | true | 对话框选项。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<ShowDialogSuccessResponse> | true |  对话框响应结果。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import prompt from '@ohos.prompt'prompt.showDialog({  title: 'showDialog Title Info',  message: 'Message Info',  buttons: [    {      text: 'button1',      color: '#000000'    },    {      text: 'button2',      color: '#000000'    }  ]}, (err, data) => {  if (err) {    console.info('showDialog err: ' + err);    return;  }  console.info('showDialog success callback, click button: ' + data.index);});    
```    
  
![zh-cn_image_0002](figures/zh-cn_image_0002.gif)  
    
## showDialog<sup>(deprecated)</sup>    
创建并显示对话框，对话框响应结果异步返回。  
 **调用形式：**     
- showDialog(options: ShowDialogOptions): Promise\<ShowDialogSuccessResponse>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | ShowDialogOptions | true | 页面显示对话框信息描述。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<ShowDialogSuccessResponse> | 对话框响应结果回调。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import prompt from '@ohos.prompt'prompt.showDialog({  title: 'Title Info',  message: 'Message Info',  buttons: [    {      text: 'button1',      color: '#000000'    },    {      text: 'button2',      color: '#000000'    }  ],})  .then(data => {    console.info('showDialog success, click button: ' + data.index);  })  .catch((err:Error) => {    console.info('showDialog error: ' + err);  })    
```    
  
![zh-cn_image_0004](figures/zh-cn_image_0004.gif)  
    
## showActionMenu<sup>(deprecated)</sup>    
创建并显示操作菜单，菜单响应结果异步返回。  
 **调用形式：**     
- showActionMenu(options: ActionMenuOptions, callback: AsyncCallback\<ActionMenuSuccessResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | ActionMenuOptions | true | 操作菜单选项。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<ActionMenuSuccessResponse> | true | 菜单响应结果回调。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import prompt from '@ohos.prompt'prompt.showActionMenu({  title: 'Title Info',  buttons: [    {      text: 'item1',      color: '#666666'    },    {      text: 'item2',      color: '#000000'    },  ]}, (err, data) => {  if (err) {    console.info('showActionMenu err: ' + err);    return;  }  console.info('showActionMenu success callback, click button: ' + data.index);})    
```    
  
![zh-cn_image_0005](figures/zh-cn_image_0005.gif)  
    
## showActionMenu<sup>(deprecated)</sup>    
创建并显示操作菜单，菜单响应后同步返回结果。  
 **调用形式：**     
- showActionMenu(options: ActionMenuOptions): Promise\<ActionMenuSuccessResponse>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | ActionMenuOptions | true | 操作菜单选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<ActionMenuSuccessResponse> | 菜单响应结果。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import prompt from '@ohos.prompt'prompt.showActionMenu({  title: 'showActionMenu Title Info',  buttons: [    {      text: 'item1',      color: '#666666'    },    {      text: 'item2',      color: '#000000'    },  ]})  .then(data => {    console.info('showActionMenu success, click button: ' + data.index);  })  .catch((err:Error) => {    console.info('showActionMenu error: ' + err);  })    
```    
  
![zh-cn_image_0006](figures/zh-cn_image_0006.gif)  
