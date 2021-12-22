# 弹窗


## 导入模块

```
import prompt from '@system.prompt';
```


## 权限列表

无

## prompt.showToast

showToast(Object): void

显示文本弹窗。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | message | string | 是 | 显示的文本信息。 |
  | duration | number | 否 | 默认值1500ms，建议区间：1500ms-10000ms。<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**说明：**<br/>>&nbsp;若小于1500ms则取默认值，最大取值为10000ms。 |
  | $[bottom]^{5+}$ | &lt;length&gt; | 否 | 设置弹窗边框距离屏幕底部的位置。<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**说明：**<br/>>&nbsp;仅手机和平板设备支持。 |

- 示例
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


## prompt.showDialog

showDialog(): void

在页面内显示对话框。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | title | string | 否 | 标题文本。 |
  | message | string | 否 | 内容文本。 |
  | buttons | Array | 否 | 对话框中按钮的数组，结构为：{text:'button',&nbsp;color:&nbsp;'\#666666'}，支持1-3个按钮。其中第一个为positiveButton；第二个为negativeButton；第三个为neutralButton。 |
  | success | Function | 否 | 接口调用成功的回调函数，返回值如success返回值所示。 |
  | cancel | Function | 否 | 取消调用此接口的回调函数。 |
  | complete | Function | 否 | 弹框退出时的回调函数。 |

  success返回值：

  | 参数名 | 类型 | 说明 |
  | -------- | -------- | -------- |
  | index | number | 选中按钮在buttons数组中的索引。 |

- 示例
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

## prompt.showActionMenu<sup>6+</sup>

showActionMenu(Object): void

显示操作菜单。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | title | string | 否 | 标题文本。 |
  | buttons | Array | 是 | 对话框中按钮的数组，结构为：{text:'button',&nbsp;color:&nbsp;'\#666666'}，支持1-6个按钮。大于6个按钮时弹窗不显示。 |
  | success | (data:&nbsp;TapIndex)&nbsp;=&gt;&nbsp;void | 否 | 接口调用成功的回调函数。 |
  | cancel | ()&nbsp;=&gt;&nbsp;void | 否 | 接口调用失败的回调函数。 |
  | complete | ()&nbsp;=&gt;&nbsp;void | 否 | 接口调用结束的回调函数。 |

  **表1** TapIndex
  
  | 参数名 | 类型 | 说明 |
  | -------- | -------- | -------- |
  | tapIndex | number | 选中按钮在buttons数组中的索引，从0开始。 |

- 示例
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
