# 弹窗

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```
import prompt from '@ohos.prompt'
```
## 权限列表

无

## prompt.showToast

showToast(options: ShowToastOptions): void

创建并显示文本提示框。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | options | [ShowToastOptions](#ShowToastOptions) | 是 | 文本弹窗选项。 |

**示例：**
  ```
  export default {    
    showToast() {        
      prompt.showToast({            
        message: 'Message Info',
        duration: 2000,      
      });
    }
  }
  ```
## ShowToastOptions

文本提示框的选项。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.ArkUI.ArkUI.Full。

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| message | string | 是 | 显示的文本信息。 |
| duration | number | 否 | 默认值1500ms，建议区间：1500ms-10000ms。<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**说明：**<br/>>&nbsp;若小于1500ms则取默认值，最大取值为10000ms。 |
| bottom  | &lt;length&gt; | 否 | 设置弹窗边框距离屏幕底部的位置。<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**说明：**<br/>>&nbsp;仅手机和平板设备支持。 |

## prompt.showDialog

showDialog(options: ShowDialogOptions): Promise<ShowDialogSuccessResponse>

创建并显示对话框，对话框响应后同步返回结果。
**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | options | [ShowDialogOptions](#ShowDialogOptions) | 是 | 对话框选项。|

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[ShowDialogSuccessResponse](#ShowDialogSuccessResponse)&gt; |  对话框响应结果。|
  
**示例：**
  
  ```
  export default {    
    showDialog() {       
      prompt.showDialog({           
        title: 'Title Info',            
        message: 'Message Info',           
        buttons: [                
          {                    
             text: 'button',                   
             color: '#666666',                
           },            
         ],            
         success: function(data) {                
           console.log('dialog success callback，click button : ' + data.index);            
         },            
         cancel: function() {                
           console.log('dialog cancel callback');            
         },
       });    
    }
  }
  ```

showDialog(options: ShowDialogOptions, callback: AsyncCallback<ShowDialogSuccessResponse>):void 

创建并显示对话框，对话框响应结果异步返回。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full


**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | options | [ShowDialogOptions](#ShowDialogOptions) | 是 | 页面显示对话框信息描述。|
  | callback | AsyncCallback&lt;[ShowDialogSuccessResponse](#ShowDialogSuccessResponse)&gt; | 是 | 对话框响应结果回调。 |

**示例：**
  ```
  export default {    
    showDialog() {       
      prompt.showDialog({           
        title: 'Title Info',            
        message: 'Message Info',           
        buttons: [                
          {                    
             text: 'button',                   
             color: '#666666',                
           },            
         ],            
         success: function(data) {                
           console.log('dialog success callback，click button : ' + data.index);            
         },            
         cancel: function() {                
           console.log('dialog cancel callback');            
         },
       });    
    }
  }
  ```

## ShowDialogOptions

对话框的选项。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.ArkUI.ArkUI.Full。

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| title | string | 否 | 标题文本。 |
| message | string | 否 | 内容文本。 |
| buttons | Array | 否 | 对话框中按钮的数组，结构为：{text:'button',&nbsp;color:&nbsp;'\#666666'}，支持1-3个按钮。其中第一个为positiveButton；第二个为negativeButton；第三个为neutralButton。 |

## ShowDialogSuccessResponse 

对话框的响应结果。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.ArkUI.ArkUI.Full。

| 名称 | 类型 | 说明 |
| -------- | -------- | -------- |
| index | number | 选中按钮在buttons数组中的索引。 |


## prompt.showActionMenu

 showActionMenu(options: ActionMenuOptions, callback: AsyncCallback&lt;ActionMenuSuccessResponse&gt;):void

创建并显示操作菜单，菜单响应结果异步返回。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.ArkUI.ArkUI.Full。

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | options  | [ActionMenuOptions](#ActionMenuOptions) | 是 | 操作菜单选项。 |
  | callback |  AsyncCallback&lt;[ActionMenuSuccessResponse](#ActionMenuSuccessResponse)>  | 是 | 菜单响应结果回调。 |


**示例：**
  ```
  export default {    
    showActionMenu() {        
      prompt.showActionMenu({            
        title: 'Title Info',            
        buttons: [                
          {                    
            text: 'item1',                    
            color: '#666666',                
          },                
          {                    
             text: 'item2',                    
             color: '#000000',                
          },            
        ],            
        success: function(data) {                
          console.log('dialog success callback，click button : ' + data.tapIndex);            
        },            
        fail: function(data) {                
          console.log('dialog fail callback' + data.errMsg);            
        },       
      });    
    }
  }
  ```
  

showActionMenu(options: ActionMenuOptions): Promise<ActionMenuSuccessResponse>

创建并显示操作菜单，菜单响应后同步返回结果。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | options  | [ActionMenuOptions](#ActionMenuOptions) | 是 | 操作菜单选项。 |
**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[ActionMenuSuccessResponse](#ActionMenuSuccessResponse)&gt; |  菜单响应结果。|

**示例：**
  ```
  export default {    
    showActionMenu() {        
      prompt.showActionMenu({            
        title: 'Title Info',            
        buttons: [                
          {                    
            text: 'item1',                    
            color: '#666666',                
          },                
          {                    
             text: 'item2',                    
             color: '#000000',                
          },            
        ],            
        success: function(data) {                
          console.log('dialog success callback，click button : ' + data.tapIndex);            
        },            
        fail: function(data) {                
          console.log('dialog fail callback' + data.errMsg);            
        },       
      });    
    }
  }
  ```
## ActionMenuOptions

操作菜单的选项。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.ArkUI.ArkUI.Full。

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| title | string | 否 | 标题文本。 |
| buttons | Array | 是 | 对话框中按钮的数组，结构为：{text:'button',&nbsp;color:&nbsp;'\#666666'}，支持1-6个按钮。大于6个按钮时弹窗不显示。 |

  **表1** TapIndex

| 参数名 | 类型 | 说明 |
| -------- | -------- | -------- |
| tapIndex | number | 选中按钮在buttons数组中的索引，从0开始。 |

## ActionMenuSuccessResponse

操作菜单的响应结果。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.ArkUI.ArkUI.Full。

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| index | number | 否 | 菜单成功的响应值 |

