# notificationContent    
描述通知类型。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## NotificationBasicContent    
描述普通文本通知。  
 **系统能力:**  SystemCapability.Notification.Notification    
### 属性    
 **系统能力:**  SystemCapability.Notification.Notification    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| title | string | false | true | 通知标题（不可为空字符串）。 |  
| text | string | false | true | 通知内容（不可为空字符串）。 |  
| additionalText | string | false | false | 通知附加内容，是对通知内容的补充。 |  
    
## NotificationLongTextContent    
描述长文本通知。  
 **系统能力:**  SystemCapability.Notification.Notification    
### 属性    
 **系统能力:**  SystemCapability.Notification.Notification    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| longText | string | false | true | 通知的长文本（不可为空字符串）。 |  
| briefText | string | false | true | 通知概要内容，是对通知内容的总结（不可为空字符串）。 |  
| expandedTitle | string | false | true | 通知展开时的标题（不可为空字符串）。 |  
    
## NotificationMultiLineContent    
描述多行文本通知。  
 **系统能力:**  SystemCapability.Notification.Notification    
### 属性    
 **系统能力:**  SystemCapability.Notification.Notification    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| briefText | string | false | true | 通知概要内容，是对通知内容的总结（不可为空字符串）。 |  
| longTitle | string | false | true | 通知展开时的标题（不可为空字符串）。 |  
| lines | Array<string> | false | true | 通知的多行文本。 |  
    
## NotificationPictureContent    
描述附有图片的通知。  
 **系统能力:**  SystemCapability.Notification.Notification    
### 属性    
 **系统能力:**  SystemCapability.Notification.Notification    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| briefText | string | false | true | 通知概要内容，是对通知内容的总结（不可为空字符串）。 |  
| expandedTitle | string | false | true | 通知展开时的标题（不可为空字符串）。 |  
| picture | image.PixelMap | false | true | 通知的图片内容(最大支持2MB的图片文件)。 |  
    
## NotificationContent    
描述通知类型。  
 **系统能力:**  SystemCapability.Notification.Notification    
### 属性    
 **系统能力:**  SystemCapability.Notification.Notification    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| contentType | notification.ContentType | false | true | 通知内容类型。<br>从API version 11开始不再维护，建议使用notificationContentType代替。 |  
| normal | NotificationBasicContent | false | false | 基本类型通知内容。 |  
| longText | NotificationLongTextContent | false | false | 长文本类型通知内容。 |  
| multiLine | NotificationMultiLineContent | false | false | 多行类型通知内容。 |  
| picture | NotificationPictureContent | false | false | 图片类型通知内容。 |  
