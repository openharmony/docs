# @ohos.userIAM.userAuth    
提供用户认证能力，可应用于设备解锁、支付、应用登录等身份认证场景。  
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import userAuth from '@ohos.userIAM.userAuth'    
```  
    
## WindowModeType<sup>(10+)</sup>    
用户认证界面的显示类型。    
    
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DIALOG_BOX | 1 | 弹框类型。 |  
| FULLSCREEN | 2 | 全屏类型。 |  
    
## WidgetParam<sup>(10+)</sup>    
用户认证界面配置相关参数。  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
### 属性    
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| windowMode<sup>(10+)</sup> | WindowModeType | false | false | 代表用户认证界面的显示类型，默认值为WindowModeType.DIALOG_BOX。 |  
    
## NoticeType<sup>(10+)</sup>    
用户身份认证的通知类型。    
    
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| WIDGET_NOTICE | 1 | 表示来自组件的通知。 |  
    
## sendNotice<sup>(10+)</sup>    
在使用统一身份认证组件进行用户身份认证时，用于接收来自统一身份认证组件的通知。  
 **调用形式：**     
- sendNotice(noticeType: NoticeType, eventData: string): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core  
 **需要权限：** ohos.permission.SUPPORT_USER_AUTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| noticeType | NoticeType | true | 通知类型。 |  
| eventData | string | true | 事件数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission verification failed. |  
| 202 | The caller is not a system application. |  
| 401 | Incorrect parameters. |  
| 12500002 | General operation error. |  
    
 **示例代码：**   
```ts    
import userAuth from '@ohos.userIAM.userAuth';  
  
interface  EventData {  
  widgetContextId: number;  
  event: string;  
  version: string;  
  payload: PayLoad;  
}  
interface PayLoad {  
  type: Object[];  
}  
try {  
  const eventData : EventData = {  
    widgetContextId: 123456,  
    event: 'EVENT_AUTH_TYPE_READY',  
    version: '1',  
    payload: {  
      type: ['pin']  
    } as PayLoad,  
  };  
  const jsonEventData = JSON.stringify(eventData);  
  let noticeType = userAuth.NoticeType.WIDGET_NOTICE;  
  userAuth.sendNotice(noticeType, jsonEventData);  
  console.log('sendNotice success');  
} catch (error) {  
  console.log('sendNotice catch error: ' + JSON.stringify(error));  
}  
    
```    
  
    
## UserAuthWidgetMgr<sup>(10+)</sup>    
组件管理接口，可将用身份认证组件注册到UserAuthWidgetMgr中，由UserAuthWidgetMgr进行管理、调度。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
### on('command')<sup>(10+)</sup>    
身份认证组件订阅来自用户认证框架的命令。  
 **调用形式：**     
    
- on(type: 'command', callback: IAuthWidgetCallback): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 订阅事件类型，表明该事件用于用户认证框架向身份认证组件发送命令。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 组件管理接口的回调函数，用于用户认证框架向身份认证组件发送命令。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Incorrect parameters. |  
| 12500002 | General operation error. |  
    
 **示例代码：**   
```ts    
import userAuth from '@ohos.userIAM.userAuth';  
  
const userAuthWidgetMgrVersion = 1;  
try {  
  let userAuthWidgetMgr = userAuth.getUserAuthWidgetMgr(userAuthWidgetMgrVersion);  
  console.log('get userAuthWidgetMgr instance success');  
  userAuthWidgetMgr.on('command', {  
    sendCommand(cmdData) {  
      console.log('The cmdData is ' + cmdData);  
    }  
  })  
  console.log('subscribe authentication event success');  
} catch (error) {  
  console.log('userAuth widgetMgr catch error: ' + JSON.stringify(error));  
}  
    
```    
  
    
### off('command')<sup>(10+)</sup>    
身份认证组件取消订阅来自用户认证框架的命令。  
 **调用形式：**     
    
- off(type: 'command', callback?: IAuthWidgetCallback): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 订阅事件类型，表明该事件用于用户认证框架向身份认证组件发送命令。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 组件管理接口的回调函数，用于用户认证框架向身份认证组件发送命令。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Incorrect parameters. |  
| 12500002 | General operation error. |  
    
 **示例代码：**   
```ts    
import userAuth from '@ohos.userIAM.userAuth';  
  
const userAuthWidgetMgrVersion = 1;  
try {  
  let userAuthWidgetMgr = userAuth.getUserAuthWidgetMgr(userAuthWidgetMgrVersion);  
  console.log('get userAuthWidgetMgr instance success');  
  userAuthWidgetMgr.off('command', {  
    sendCommand(cmdData) {  
      console.log('The cmdData is ' + cmdData);  
    }  
  })  
  console.log('cancel subscribe authentication event success');  
} catch (error) {  
  console.log('userAuth widgetMgr catch error: ' + JSON.stringify(error));  
}  
    
```    
  
    
## getUserAuthWidgetMgr<sup>(10+)</sup>    
获取UserAuthWidgetMgr对象，用于执行用户身份认证。  
 **调用形式：**     
- getUserAuthWidgetMgr(version: number): UserAuthWidgetMgr  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core  
 **需要权限：** ohos.permission.SUPPORT_USER_AUTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| version | number | true | 表示认证组件的版本。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| UserAuthWidgetMgr | 认证器对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission verification failed. |  
| 202 | The caller is not a system application. |  
| 401 | Incorrect parameters. |  
| 12500002 | General operation error. |  
    
 **示例代码：**   
```ts    
import userAuth from '@ohos.userIAM.userAuth';  
  
let userAuthWidgetMgrVersion = 1;  
try {  
  let userAuthWidgetMgr = userAuth.getUserAuthWidgetMgr(userAuthWidgetMgrVersion);  
  console.log('get userAuthWidgetMgr instance success');  
} catch (error) {  
  console.log('userAuth widgetMgr catch error: ' + JSON.stringify(error));  
}  
    
```    
  
    
## IAuthWidgetCallback<sup>(10+)</sup>    
认证组件通过该回调获取用户认证框架发送的命令。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
### sendCommand<sup>(10+)</sup>    
回调函数，用于用户认证框架向组件发送命令。  
 **调用形式：**     
- sendCommand(cmdData: string): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.UserIAM.UserAuth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| cmdData | string | true | 用户身份认证框架向组件发送的命令。 |  
    
 **示例代码：**   
```ts    
import userAuth from '@ohos.userIAM.userAuth';  
  
const userAuthWidgetMgrVersion = 1;  
try {  
  let userAuthWidgetMgr = userAuth.getUserAuthWidgetMgr(userAuthWidgetMgrVersion);  
  console.log('get userAuthWidgetMgr instance success');  
  userAuthWidgetMgr.on('command', {  
    sendCommand(cmdData) {  
      console.log('The cmdData is ' + cmdData);  
    }  
  })  
  console.log('subscribe authentication event success');  
} catch (error) {  
  console.log('userAuth widgetMgr catch error: ' + JSON.stringify(error));  
}  
    
```    
  
