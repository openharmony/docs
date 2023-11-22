# @ohos.reminderAgentManager    
本模块提供后台代理提醒的能力，即当应用被冻结或应用退出时，计时和提醒的功能将被系统服务代理。在开发过程中，开发者可以调用本模块接口创建定时提醒，提醒类型支持倒计时、日历、闹钟三种。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import reminderAgentManager from '@ohos.reminderAgentManager'    
```  
    
## ActionButtonType    
按钮的类型。    
    
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| ACTION_BUTTON_TYPE_CUSTOM<sup>(10+)</sup> | 2 | 表示自定义的按钮。<br>**系统接口**: 系统接口，三方应用不支持调用。 |  
    
## ActionButton    
弹出的提醒通知中按钮的类型和标题。  
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
### 属性    
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| wantAgent<sup>(10+)</sup> | WantAgent | false | false | 点击按钮跳转的ability信息。<br>**系统接口**: 系统接口，三方应用不支持调用。 |  
    
## WantAgent    
跳转目标的ability信息。  
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
### 属性    
 **系统能力:**  SystemCapability.Notification.ReminderAgent    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| uri<sup>(10+)</sup> | string | false | false | 指明跳转目标的uri信息。<br>**系统接口**: 系统接口，三方应用不支持调用。 |  
