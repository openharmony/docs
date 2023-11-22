# @ohos.commonEventManager    
本模块提供了公共事件相关的能力，包括发布公共事件、订阅公共事件、以及退订公共事件。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import commonEventManager from '@ohos.commonEventManager'    
```  
    
## publishAsUser    
以回调的形式向指定用户发布公共事件。  
 **调用形式：**     
    
- publishAsUser(event: string, userId: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- publishAsUser(     event: string,     userId: number,     options: CommonEventPublishData,     callback: AsyncCallback\<void>   ): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.CommonEvent    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | string | true | 表示要发送的公共事件。 |  
| userId | number | true | 表示指定向该用户ID发送此公共事件。 |  
| options | CommonEventPublishData | true | 表示发布公共事件的属性。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示被指定的回调方法。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
| 1500004 | not System services or System app. |  
| 1500007 | error sending message to Common Event Service. |  
| 1500008 | Common Event Service does not complete initialization. |  
| 1500009 | error obtaining system parameters. |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import Base from '@ohos.base';  
  
//发布公共事件回调  
function publishCB(err:Base.BusinessError) {  
	if (err) {  
        console.error(`publishAsUser failed, code is ${err.code}, message is ${err.message}`);  
    } else {  
        console.info("publishAsUser");  
    }  
}  
  
//指定发送的用户  
let userId = 100;  
  
//发布公共事件  
try {  
    CommonEventManager.publishAsUser("event", userId, publishCB);  
} catch (error) {  
    let err:Base.BusinessError = error as Base.BusinessError;  
    console.error(`publishAsUser failed, code is ${err.code}, message is ${err.message}`);  
}  
    
```    
  
    
## removeStickyCommonEvent<sup>(10+)</sup>    
以回调形式移除粘性公共事件。  
 **调用形式：**     
    
- removeStickyCommonEvent(event: string, callback: AsyncCallback\<void>): void    
起始版本： 10    
- removeStickyCommonEvent(event: string): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.CommonEvent  
 **需要权限：** ohos.permission.COMMONEVENT_STICKY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | string | true | 表示被移除的粘性公共事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示移除粘性公共事件的回调方法。 |  
| Promise<void> | 表示移除粘性公共事件的对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 1500004 | not system service. |  
| 1500007 | error sending message to Common Event Service. |  
| 1500008 | Common Event Service does not complete initialization. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import Base from '@ohos.base';  
CommonEventManager.removeStickyCommonEvent("sticky_event", (err:Base.BusinessError) => {    if (err) {        console.info(`Remove sticky event AsyncCallback failed, errCode: ${err.code}, errMes: ${err.message}`);        return;    }    console.info(`Remove sticky event AsyncCallback success`);});    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import Base from '@ohos.base';  
CommonEventManager.removeStickyCommonEvent("sticky_event").then(() => {    console.info(`Remove sticky event AsyncCallback success`);}).catch ((err:Base.BusinessError) => {    console.info(`Remove sticky event AsyncCallback failed, errCode: ${err.code}, errMes: ${err.message}`);});    
```    
  
    
## setStaticSubscriberState<sup>(10+)</sup>    
方法介绍：为当前应用设置静态订阅事件使能或去使能状态。使用callback异步回调。  
 **调用形式：**     
    
- setStaticSubscriberState(enable: boolean, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setStaticSubscriberState(enable: boolean): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.CommonEvent    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| enable | boolean | true | 表示静态订阅事件使能状态。 true:使能 false：去使能。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示设置静态订阅事件使能状态的回调方法。 |  
| Promise<void> | 表示设置静态订阅事件使能状态的对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
| 1500007 | error sending message to Common Event Service. |  
| 1500008 | Common Event Service does not complete initialization. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import Base from '@ohos.base';  
CommonEventManager.setStaticSubscriberState(true, (err:Base.BusinessError) => {    if (!err) {        console.info(`Set static subscriber state callback failed, err is null.`);        return;    }    if (err.code !== undefined  err.code != null) {        console.info(`Set static subscriber state callback failed, errCode: ${err.code}, errMes: ${err.message}`);        return;    }    console.info(`Set static subscriber state callback success`);});    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import Base from '@ohos.base';  
CommonEventManager.setStaticSubscriberState(false).then(() => {    console.info(`Set static subscriber state promise success`);}).catch ((err:Base.BusinessError) => {    console.info(`Set static subscriber state promise failed, errCode: ${err.code}, errMes: ${err.message}`);});    
```    
  
    
## Support    
    
 **系统能力:**  SystemCapability.Notification.CommonEvent    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| COMMON_EVENT_CHARGE_TYPE_CHANGED<sup>(10+)</sup> | usual.event.CHARGE_TYPE_CHANGED | 表示系统充电类型改变的公共事件的动作。仅限系统应用使用。 |  
| COMMON_EVENT_DEVICE_IDLE_EXEMPTION_LIST_UPDATED<sup>(10+)</sup> | usual.event.DEVICE_IDLE_EXEMPTION_LIST_UPDATED | 表示系统待机空闲模式下豁免应用程序列表已更新的公共事件的动作。仅限系统应用使用。 |  
| COMMON_EVENT_SMS_RECEIVE_COMPLETED<sup>(10+)</sup> | usual.event.SMS_RECEIVE_COMPLETED |  |  
| COMMON_EVENT_SMS_EMERGENCY_CB_RECEIVE_COMPLETED<sup>(10+)</sup> | usual.event.SMS_EMERGENCY_CB_RECEIVE_COMPLETED | 提示紧急小区广播短信接收完成。 |  
| COMMON_EVENT_SMS_CB_RECEIVE_COMPLETED<sup>(10+)</sup> | usual.event.SMS_CB_RECEIVE_COMPLETED | 提示小区广播短信接收完成。 |  
| COMMON_EVENT_STK_COMMAND<sup>(10+)</sup> | usual.event.STK_COMMAND | （预留事件，暂未支持）提示STK命令。 |  
| COMMON_EVENT_STK_SESSION_END<sup>(10+)</sup> | usual.event.STK_SESSION_END | （预留事件，暂未支持）提示STK会话结束。 |  
| COMMON_EVENT_STK_CARD_STATE_CHANGED<sup>(10+)</sup> | usual.event.STK_CARD_STATE_CHANGED | （预留事件，暂未支持）提示STK卡状态已更新。 |  
| COMMON_EVENT_STK_ALPHA_IDENTIFIER<sup>(10+)</sup> | usual.event.STK_ALPHA_IDENTIFIER | （预留事件，暂未支持）提示STK ALPHA标识符。 |  
| COMMON_EVENT_SMS_WAPPUSH_RECEIVE_COMPLETED<sup>(10+)</sup> | usual.event.SMS_WAPPUSH_RECEIVE_COMPLETED | 提示服务信息短信接收完成。 |  
| COMMON_EVENT_OPERATOR_CONFIG_CHANGED<sup>(10+)</sup> | usual.event.OPERATOR_CONFIG_CHANGED | 提示运营商配置已更新。 |  
| COMMON_EVENT_SIM_CARD_DEFAULT_SMS_SUBSCRIPTION_CHANGED<sup>(10+)</sup> | usual.event.SIM.DEFAULT_SMS_SUBSCRIPTION_CHANGED | 提示SIM卡默认短信主卡已更新。 |  
| COMMON_EVENT_SIM_CARD_DEFAULT_DATA_SUBSCRIPTION_CHANGED<sup>(10+)</sup> | usual.event.SIM.DEFAULT_DATA_SUBSCRIPTION_CHANGED | 提示SIM卡默认数据主卡已更新。 |  
| COMMON_EVENT_SIM_CARD_DEFAULT_MAIN_SUBSCRIPTION_CHANGED<sup>(10+)</sup> | usual.event.SIM.DEFAULT_MAIN_SUBSCRIPTION_CHANGED | 提示SIM卡默认主卡已更新。 |  
| COMMON_EVENT_SIM_CARD_DEFAULT_VOICE_SUBSCRIPTION_CHANGED<sup>(10+)</sup> | usual.event.SIM.DEFAULT_VOICE_SUBSCRIPTION_CHANGED | 提示SIM卡默认语音主卡已更新。 |  
| COMMON_EVENT_CELLULAR_DATA_STATE_CHANGED<sup>(10+)</sup> | usual.event.CELLULAR_DATA_STATE_CHANGED | 提示蜂窝数据状态更新。 |  
| COMMON_EVENT_INCOMING_CALL_MISSED<sup>(10+)</sup> | usual.event.INCOMING_CALL_MISSED | 提示未接来电。 |  
| COMMON_EVENT_RADIO_STATE_CHANGE<sup>(10+)</sup> | usual.event.RADIO_STATE_CHANGE | 提示设备modem上下电状态变化。 |  
| COMMON_EVENT_DOMAIN_ACCOUNT_STATUS_CHANGED<sup>(10+)</sup> | usual.event.DOMAIN_ACCOUNT_STATUS_CHANGED | 表示域账号状态发生变化。 |  
| COMMON_EVENT_SPECIAL_CODE<sup>(10+)</sup> | common.event.SPECIAL_CODE |  |  
| COMMON_EVENT_AUDIO_QUALITY_CHANGE<sup>(10+)</sup> | usual.event.AUDIO_QUALITY_CHANGE | 提示音频质量发生变化。 |  
