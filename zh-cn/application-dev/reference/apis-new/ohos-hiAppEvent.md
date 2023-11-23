# @ohos.hiAppEvent    
本模块提供了应用事件打点能力，包括对打点数据的落盘，以及对打点功能的管理配置。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import hiAppEvent from '@ohos.hiAppEvent'    
```  
    
## EventType<sup>(deprecated)</sup>    
事件类型枚举。    
从API version 7 开始支持，从API version 9 开始废弃。    
    
 **系统能力:**  SystemCapability.HiviewDFX.HiAppEvent    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| FAULT<sup>(deprecated)</sup> | 1 | 从API version 7 开始支持，从API version 9 开始废弃。<br>故障类型事件。 |  
| STATISTIC<sup>(deprecated)</sup> | 2 | 从API version 7 开始支持，从API version 9 开始废弃。<br>统计类型事件。 |  
| SECURITY<sup>(deprecated)</sup> | 3 | 从API version 7 开始支持，从API version 9 开始废弃。<br>安全类型事件。 |  
| BEHAVIOR<sup>(deprecated)</sup> | 4 | 从API version 7 开始支持，从API version 9 开始废弃。<br>行为类型事件。 |  
    
 **常量：**     
 **系统能力:**  SystemCapability.HiviewDFX.HiAppEvent    
| 名称 | 类型 | 值 | 说明 |  
| --------| --------| --------| --------|  
| USER_LOGIN<sup>(deprecated)</sup> | string |  | 从API version 7 开始支持，从API version 9 开始废弃。<br>用户登录事件。 |  
| USER_LOGOUT<sup>(deprecated)</sup> | string |  | 从API version 7 开始支持，从API version 9 开始废弃。<br>用户登出事件。 |  
| DISTRIBUTED_SERVICE_START<sup>(deprecated)</sup> | string |  | 从API version 7 开始支持，从API version 9 开始废弃。<br>分布式服务启动事件。 |  
    
 **常量：**     
 **系统能力:**  SystemCapability.HiviewDFX.HiAppEvent    
| 名称 | 类型 | 值 | 说明 |  
| --------| --------| --------| --------|  
| USER_ID<sup>(deprecated)</sup> | string |  | 从API version 7 开始支持，从API version 9 开始废弃。<br>用户自定义ID。 |  
| DISTRIBUTED_SERVICE_NAME<sup>(deprecated)</sup> | string |  | 从API version 7 开始支持，从API version 9 开始废弃。<br>分布式服务名称。 |  
| DISTRIBUTED_SERVICE_INSTANCE_ID<sup>(deprecated)</sup> | string |  | 从API version 7 开始支持，从API version 9 开始废弃。<br>分布式服务实例ID。 |  
    
## write<sup>(deprecated)</sup>    
应用事件打点方法，将事件写入到当天的事件文件中，使用Promise方式作为异步回调。  
 **调用形式：**     
- write(eventName: string, eventType: EventType, keyValues: object): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.HiviewDFX.HiAppEvent    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| eventName<sup>(deprecated)</sup> | string | true | 事件名称。 |  
| eventType<sup>(deprecated)</sup> | EventType | true | 事件类型。 |  
| keyValues<sup>(deprecated)</sup> | object | true | 事件参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象，可以在其then()、catch()方法中分别对事件写入成功、写入异常的情况进行异步处理。 |  
    
 **示例代码：**   
示例（Promise）：  
```js    
import { BusinessError } from '@ohos.base'  
  
let eventParams: Record<string, number | string> = {  
  "int_data": 100,  
  "str_data": "strValue",  
};  
hiAppEvent.write("test_event", hiAppEvent.EventType.FAULT, eventParams).then(() => {  
  // 事件写入正常  
  console.log(`success to write event`);  
}).catch((err: BusinessError) => {  
  // 事件写入异常：事件存在异常参数时忽略异常参数后继续写入，或者事件校验失败时不执行写入  
  console.error(`failed to write event, code=${err.code}`);  
});  
    
```    
  
    
## write<sup>(deprecated)</sup>    
应用事件打点方法，将事件写入到当天的事件文件中，使用callback方式作为异步回调。  
 **调用形式：**     
- write(eventName: string, eventType: EventType, keyValues: object, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.HiviewDFX.HiAppEvent    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| eventName<sup>(deprecated)</sup> | string | true | 事件名称。 |  
| eventType<sup>(deprecated)</sup> | EventType | true | 事件类型。 |  
| keyValues<sup>(deprecated)</sup> | object | true | 事件参数。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 事件回调函数。 |  
    
 **示例代码：**   
示例（callback）：  
```js    
import { BusinessError } from '@ohos.base'  
  
let eventParams: Record<string, number | string> = {  
  "int_data": 100,  
  "str_data": "strValue",  
};  
hiAppEvent.write("test_event", hiAppEvent.EventType.FAULT, eventParams, (err: BusinessError) => {  
  if (err) {  
    // 事件写入异常：事件存在异常参数时忽略异常参数后继续写入，或者事件校验失败时不执行写入  
    console.error(`failed to write event, code=${err.code}`);  
    return;  
  }  
  // 事件写入正常  
  console.log(`success to write event`);  
});  
    
```    
  
    
## configure<sup>(deprecated)</sup>    
应用事件打点配置方法，可用于配置打点开关、文件目录存储限额大小等功能。  
 **调用形式：**     
- configure(config: ConfigOption): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.HiviewDFX.HiAppEvent    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config<sup>(deprecated)</sup> | ConfigOption | true | 应用事件打点配置项对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 配置结果，true表示配置成功，false表示配置失败。 |  
    
 **示例代码：**   
```js    
// 配置应用事件打点功能开关  
let config1: hiAppEvent.ConfigOption = {  
  disable: true,  
};  
hiAppEvent.configure(config1);  
  
// 配置事件文件目录存储限额大小  
let config2: hiAppEvent.ConfigOption = {  
  maxStorage: '100M',  
};  
hiAppEvent.configure(config2);<i></i>    
```    
  
    
## ConfigOption<sup>(deprecated)</sup>    
此接口提供了应用打点的配置选项。    
从API version 7 开始支持，从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.HiviewDFX.HiAppEvent    
### 属性    
 **系统能力:**  SystemCapability.HiviewDFX.HiAppEvent    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| disable<sup>(deprecated)</sup> | boolean | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>应用打点功能开关。配置值为true表示关闭打点功能，false表示不关闭打点功能。 |  
| maxStorage<sup>(deprecated)</sup> | string | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>打点数据本地存储文件所在目录的配额大小，默认限额为“10M”。所在目录大小超出限额后会对目录进行清理操作，会按从旧到新的顺序逐个删除打点数据文件，直到目录大小不超出限额时停止。 |  
    
 **示例代码：**   
应用事件打点方法，将事件写入到当天的事件文件中  
  
```js    
import { BusinessError } from '@ohos.base'  
  
let eventParams: Record<string, number | string> = {  
  "int_data": 100,  
  "str_data": "strValue",  
};  
hiAppEvent.write("test_event", hiAppEvent.EventType.FAULT, eventParams, (err: BusinessError) => {  
  if (err) {  
    // 事件写入异常：事件存在异常参数时忽略异常参数后继续写入，或者事件校验失败时不执行写入  
    console.error(`failed to write event, code=${err.code}`);  
    return;  
  }  
  // 事件写入正常  
  console.log(`success to write event`);  
});  
    
```    
  
