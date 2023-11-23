# @ohos.promptAction    
创建并显示文本提示框、对话框和操作菜单。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import promptAction from '@ohos.promptAction'    
```  
    
## ShowToastOptions    
文本提示框的选项。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| message | string \| Resource | false | true | 显示的文本信息。<br>**说明：** <br/>默认字体为'Harmony Sans'，不支持设置其他字体。 |  
| duration | number | false | false | 默认值1500ms，取值区间：1500ms-10000ms。若小于1500ms则取默认值，若大于10000ms则取上限值10000ms。 |  
| bottom | string \| number | false | false | 设置弹窗边框距离屏幕底部的位置。<br>默认值：80vp     |  
    
## Button    
菜单中的菜单项按钮。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| text | string \| Resource | false | true | 按钮文本内容。 |  
| color | string \| Resource | false | true | 按钮文本颜色。 |  
    
## ShowDialogSuccessResponse    
对话框的响应结果。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| index | number | false | true | 选中按钮在buttons数组中的索引。 |  
    
## ShowDialogOptions    
对话框的选项。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| title | string \| Resource | false | false | 标题文本。 |  
| message | string \| Resource | false | false | 内容文本。        |  
| buttons | Array<Button> | false | false | 对话框中按钮的数组，结构为：{text:'button',color:'\#666666'}，支持大于1个按钮。 |  
| maskRect<sup>(10+)</sup> | Rectangle | false | false | 弹窗遮蔽层区域，在遮蔽层区域内的事件不透传，在遮蔽层区域外的事件透传。<br/>默认值：{ x: 0, y: 0, width: '100%', height: '100%' } |  
| alignment<sup>(10+)</sup> | DialogAlignment | false | false | 弹窗在竖直方向上的对齐方式。<br>默认值：DialogAlignment.Default  |  
| offset<sup>(10+)</sup> | Offset | false | false |  弹窗相对alignment所在位置的偏移量。<br/>默认值：{dx:0,dy:0} |  
    
## ActionMenuSuccessResponse    
操作菜单的响应结果。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| index | number | false | true | 选中按钮在buttons数组中的索引，从0开始。 |  
    
## ActionMenuOptions    
操作菜单的选项。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| title | string \| Resource | false | false | string\| [Resource](../arkui-ts/ts-types.md#resource类型)<sup>9+</sup> | 否   | 标题文本。   |  
| buttons | [Button, Button?, Button?, Button?, Button?, Button?] | false | true | [[Button](#button),[Button](#button)?,[Button](#button)?,[Button](#button)?,[Button](#button)?,[Button](#button)?] | 是   | 菜单中菜单项按钮的数组，结构为：{text:'button',color:'\#666666'}，支持1-6个按钮。按钮数量大于6个时，仅显示前6个按钮，之后的按钮不显示。 |  
    
## showToast    
创建并显示文本提示框。  
 **调用形式：**     
- showToast(options: ShowToastOptions): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | ShowToastOptions | true | 文本弹窗选项。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 100001 | if UI execution context not found. | |  
    
 **示例代码：**   
```ts    
import promptAction from '@ohos.promptAction'  
import { BusinessError } from '@ohos.base';  
try {  
  promptAction.showToast({              
    message: 'Message Info',  
    duration: 2000   
  });  
} catch (error) {  
  let message = (error as BusinessError).message  
  let code = (error as BusinessError).code  
  console.error(`showToast args error code is ${code}, message is ${message}`);  
};  
    
```    
  
![zh-cn_image_0001](figures/zh-cn_image_0001.gif)  
    
## showDialog    
创建并显示对话框，对话框响应后异步返回结果。  
 **调用形式：**     
    
- showDialog(options: ShowDialogOptions, callback: AsyncCallback\<ShowDialogSuccessResponse>): void    
起始版本： 9    
- showDialog(options: ShowDialogOptions): Promise\<ShowDialogSuccessResponse>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | ShowDialogOptions | true |  对话框选项。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 对话框响应结果回调。 |  
| Promise<ShowDialogSuccessResponse> | 对话框响应结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 100001 | if UI execution context not found. |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import promptAction from '@ohos.promptAction';  
import { BusinessError } from '@ohos.base';  
try {  
  promptAction.showDialog({  
    title: 'showDialog Title Info',  
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
    ]  
  }, (err, data) => {  
    if (err) {  
      console.info('showDialog err: ' + err);  
      return;  
    }  
    console.info('showDialog success callback, click button: ' + data.index);  
  });  
} catch (error) {  
  let message = (error as BusinessError).message  
  let code = (error as BusinessError).code  
  console.error(`showDialog args error code is ${code}, message is ${message}`);  
};  
    
```    
  
![zh-cn_image_0002](figures/zh-cn_image_0002.gif)  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import promptAction from '@ohos.promptAction'  
import { BusinessError } from '@ohos.base';  
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
  let message = (error as BusinessError).message  
  let code = (error as BusinessError).code  
  console.error(`showDialog args error code is ${code}, message is ${message}`);  
};  
    
```    
  
![zh-cn_image_0002](figures/zh-cn_image_0002.gif)  
    
## showActionMenu    
创建并显示操作菜单，菜单响应结果异步返回。  
 **调用形式：**     
    
- showActionMenu(options: ActionMenuOptions, callback: AsyncCallback\<ActionMenuSuccessResponse>): void    
起始版本： 9    
- showActionMenu(options: ActionMenuOptions): Promise\<ActionMenuSuccessResponse>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | ActionMenuOptions | true | 操作菜单选项。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 菜单响应结果回调。 |  
| Promise<ActionMenuSuccessResponse> | 菜单响应结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 100001 | if UI execution context not found. |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import promptAction from '@ohos.promptAction';  
import { BusinessError } from '@ohos.base';  
try {  
  promptAction.showActionMenu({  
    title: 'Title Info',  
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
  }, (err, data) => {  
    if (err) {  
      console.info('showActionMenu err: ' + err);  
      return;  
    }  
    console.info('showActionMenu success callback, click button: ' + data.index);  
  })  
} catch (error) {  
  let message = (error as BusinessError).message  
  let code = (error as BusinessError).code  
  console.error(`showActionMenu args error code is ${code}, message is ${message}`);  
};  
    
```    
  
![zh-cn_image_0005](figures/zh-cn_image_0005.gif)  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import promptAction from '@ohos.promptAction';  
import { BusinessError } from '@ohos.base';  
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
  let message = (error as BusinessError).message  
  let code = (error as BusinessError).code  
  console.error(`showActionMenu args error code is ${code}, message is ${message}`);  
};  
    
```    
  
![zh-cn_image_0005](figures/zh-cn_image_0005.gif)  
