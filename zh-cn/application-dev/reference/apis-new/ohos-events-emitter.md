# @ohos.events.emitter    
本模块提供了在同一进程不同线程间，或同一进程同一线程内，发送和处理事件的能力，包括持续订阅事件、单次订阅事件、取消订阅事件，以及发送事件到事件队列的能力。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import emitter from '@ohos.events.emitter'    
```  
    
## on    
持续订阅指定的事件，并在接收到该事件时，执行对应的回调处理函数。  
 **调用形式：**     
    
- on(event: InnerEvent, callback: Callback\<EventData>): void    
起始版本： 7  
  
 **系统能力:**  SystemCapability.Notification.Emitter    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | InnerEvent | true | 持续订阅的事件，其中[EventPriority](#eventpriority)，在订阅事件时无需指定，也不生效 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 接收到该事件时需要执行的回调处理函数 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
let innerEvent: emitter.InnerEvent = {  eventId: 1};  
// 收到eventId为1的事件后执行回调函数emitter.on(innerEvent, () => {  console.info('callback');});    
```    
  
    
## once    
单次订阅指定的事件，并在接收到该事件并执行完相应的回调函数后，自动取消订阅。  
 **调用形式：**     
    
- once(event: InnerEvent, callback: Callback\<EventData>): void    
起始版本： 7  
  
 **系统能力:**  SystemCapability.Notification.Emitter    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | InnerEvent | true | 单次订阅的事件，其中[EventPriority](#eventpriority)，在订阅事件时无需指定，也不生效 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 接收到该事件时需要执行的回调处理函数 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
let innerEvent: emitter.InnerEvent = {    eventId: 1};  
// 收到eventId为1的事件后执行该回调函数emitter.once(innerEvent, () => {    console.info('once callback');});    
```    
  
    
## off    
取消针对该事件ID的订阅。  
 **调用形式：**     
- off(eventId: number): void  
  
 **系统能力:**  SystemCapability.Notification.Emitter    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| eventId | number | true | 事件ID。 |  
    
 **示例代码：**   
```ts    
// 取消eventID为1的所有事件回调处理函数emitter.off(1);    
```    
  
    
## off<sup>(10+)</sup>    
取消针对该事件ID的订阅，传入可选参数callback，并且该callback已经通过on或者once接口订阅，则取消该订阅；否则，不做任何处理。  
 **调用形式：**     
    
- off(eventId: number, callback: Callback\<EventData>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Notification.Emitter    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| eventId | number | true | 事件ID |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | API version 10 新增取消该事件的回调处理函数。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
// 取消eventID为1的事件回调处理函数 emitterCallback// 如果该回调处理函数没有被订阅，则不做任何处理emitter.off(1, () => {  console.info('callback');});    
```    
  
    
## emit    
发送指定的事件。  
 **调用形式：**     
- emit(event: InnerEvent, data?: EventData): void  
  
 **系统能力:**  SystemCapability.Notification.Emitter    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | InnerEvent | true | 发送的事件，其中[EventPriority](#eventpriority)用于指定事件被发送的优先级 |  
| data | EventData | false | 事件携带的数据 |  
    
 **示例代码：**   
```ts    
let eventData: emitter.EventData = {    data: {        "content": "c",        "id": 1,    }};  
let innerEvent: emitter.InnerEvent = {    eventId: 1,    priority: emitter.EventPriority.HIGH};emitter.emit(innerEvent, eventData);    
```    
  
    
## EventData    
发送事件时传递的数据。  
 **系统能力:**  SystemCapability.Notification.Emitter    
### 属性    
 **系统能力:**  SystemCapability.Notification.Emitter    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| data | object | false | false | 发送事件时传递的数据，数据类型支持字符串、整型和布尔型。<br> 其中字符串长度最大为10240字节。 |  
    
## InnerEvent    
订阅或发送的事件，订阅事件时`EventPriority`不生效。  
 **系统能力:**  SystemCapability.Notification.Emitter    
### 属性    
 **系统能力:**  SystemCapability.Notification.Emitter    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| eventId | number | false | true | 事件ID，由开发者定义用来辨别事件。 |  
| priority | EventPriority | false | false | 事件被投递的优先级。 |  
    
## EventPriority    
用于表示事件被发送的优先级。    
    
 **系统能力:**  SystemCapability.Notification.Emitter    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| IMMEDIATE | 0 | 表示事件被立即投递。 |  
| HIGH | 1 | 表示事件先于LOW优先级投递。 |  
| LOW | 2 | 表示事件优于IDLE优先级投递，事件的默认优先级是LOW。 |  
| IDLE | 3 | 表示在没有其他事件的情况下，才投递该事件。 |  
