# @ohos.commonEvent    
本模块提供了公共事件的能力，包括公共事件的权限列表，发布公共事件，订阅或取消订阅公共事件，获取或修改公共事件结果代码、结果数据等。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import commonEvent from '@ohos.commonEvent'    
```  
    
## publishAsUser<sup>(deprecated)</sup>    
以回调的形式向指定用户发布公共事件。  
 **调用形式：**     
- publishAsUser(event: string, userId: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.commonEventManager/commonEventManager#publishAsUser。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.CommonEvent    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(deprecated)</sup> | string | true | 表示要发送的公共事件。 |  
| userId<sup>(deprecated)</sup> | number | true | 表示指定向该用户ID发送此公共事件。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 表示被指定的回调方法。 |  
    
 **示例代码：**   
```ts    
import Base from '@ohos.base';  
  
// 发布公共事件回调  
function publishCB(err:Base.BusinessError) {  
	if (err.code) {  
        console.error(`publishAsUser failed, code is ${err.code}`);  
    } else {  
        console.info("publishAsUser");  
    }  
}  
  
// 指定发送的用户  
let userId = 100;  
  
// 发布公共事件  
CommonEvent.publishAsUser("event", userId, publishCB);  
    
```    
  
    
## publishAsUser<sup>(deprecated)</sup>  
 **调用形式：**     
- publishAsUser(     event: string,     userId: number,     options: CommonEventPublishData,     callback: AsyncCallback\<void>   ): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.commonEventManager/commonEventManager#publishAsUser。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.CommonEvent    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(deprecated)</sup> | string | true |  |  
| userId<sup>(deprecated)</sup> | number | true |  |  
| options<sup>(deprecated)</sup> | CommonEventPublishData | true |  |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true |  |  
