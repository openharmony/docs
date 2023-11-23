# @system.notification    
> **说明**   
>本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import notification from '@system.notification';  
    
```  
    
## ActionResult  
 **系统能力:**  SystemCapability.Notification.Notification    
### 属性    
 **系统能力:**  SystemCapability.Notification.Notification    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| bundleName | string | false | true | 单击通知后要重定向到的应用程序的Bundle名。 |  
| abilityName | string | false | true | 单击通知后要重定向到的应用程序的Ability名称。 |  
| uri | string | false | true | 要重定向到的页面的uri。 |  
    
## ShowNotificationOptions  
 **系统能力:**  SystemCapability.Notification.Notification    
### 属性    
 **系统能力:**  SystemCapability.Notification.Notification    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| contentTitle | string | false | false | 通知标题。 |  
| contentText | string | false | false | 通知内容。 |  
| clickAction | ActionResult | false | false | 通知被点击后触发的行为。 |  
    
## Notification    
  
  
 **系统能力:**  SystemCapability.Notification.Notification    
### show    
显示通知。  
 **调用形式：**     
- static show(options?: ShowNotificationOptions): void  
  
 **系统能力:**  SystemCapability.Notification.Notification    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | ShowNotificationOptions | false | 通知标题。 |  
    
 **示例代码：**   
```js    
let notificationObj: notification = { show() {  notification.show({   contentTitle: 'title info',   contentText: 'text',   clickAction: {    bundleName: 'com.example.testapp',    abilityName: 'notificationDemo',    uri: '/path/to/notification'   }  }); }}export default notificationObj    
```    
  
