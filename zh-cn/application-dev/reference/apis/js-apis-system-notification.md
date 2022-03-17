# 通知消息

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - 从API Version 7 开始，该接口不再维护，推荐使用新接口['@ohos.notification'](js-apis-notification.md)。
> 
> - 本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块


```
import notification from '@system.notification';
```


## notification.show

show(contentTitle: string, contentText: string, clickAction: ActionInfo): void

显示通知。

**系统能力：** SystemCapability.Notification.Notification

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| contentTitle | string | 否 | 通知标题。 |
| contentText | string | 否 | 通知内容。 |
| clickAction | ActionInfo | 否 | 通知点击后触发的动作。 |

  **表1** ActionInfo

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 点击通知后要跳转到的应用的bundleName |
| abilityName | string | 是 | 点击通知后要跳转到的应用的abilityName |
| uri | string | 是 | 要跳转到的uri，可以是下面的两种格式：<br/>-&nbsp;页面绝对路径，由配置文件中pages列表提供，例如：<br/>&nbsp;&nbsp;-&nbsp;pages/index/index<br/>&nbsp;&nbsp;-&nbsp;pages/detail/detail<br/>-&nbsp;特殊的，如果uri的值是"/"，则跳转到首页。 |

**示例：**

```
export default {    
  show() {        
    notification.show({            
      contentTitle: 'title info',            
        contentText: 'text',            
        clickAction: {                
          bundleName: 'com.example.testapp',                
          abilityName: 'notificationDemo',                
          uri: '/path/to/notification',            
         },
     });    
  },
}
;
```