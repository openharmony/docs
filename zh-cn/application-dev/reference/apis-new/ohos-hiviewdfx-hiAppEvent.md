# @ohos.hiviewdfx.hiAppEvent    
本模块提供了应用事件打点能力，包括应用事件落盘、应用事件订阅、应用事件清理、打点功能配置等功能。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import hiAppEvent from '@ohos.hiviewdfx.hiAppEvent'    
```  
    
## EventType    
事件类型枚举。  
    
    
 **系统能力:**  SystemCapability.HiviewDFX.HiAppEvent    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| FAULT | 1 | 故障类型事件。<br/> |  
| STATISTIC | 2 | 统计类型事件。<br/> |  
| SECURITY | 3 | 安全类型事件。<br/> |  
| BEHAVIOR | 4 | 行为类型事件。<br/> |  
    
 **常量：**     
 **系统能力:**  SystemCapability.HiviewDFX.HiAppEvent    
| 名称 | 类型 | 值 | 说明 |  
| --------| --------| --------| --------|  
| USER_LOGIN | string |  | 用户登录事件 |  
| USER_LOGOUT | string |  | 用户登出事件。<br/> |  
| DISTRIBUTED_SERVICE_START | string |  | 分布式服务启动事件。 |  
    
 **常量：**     
 **系统能力:**  SystemCapability.HiviewDFX.HiAppEvent    
| 名称 | 类型 | 值 | 说明 |  
| --------| --------| --------| --------|  
| USER_ID | string |  | 用户自定义ID。 |  
| DISTRIBUTED_SERVICE_NAME | string |  | 分布式服务名称。<br/> |  
| DISTRIBUTED_SERVICE_INSTANCE_ID | string |  | 分布式服务实例ID。<br/> |  
    
## configure    
应用事件打点配置方法，可用于配置打点开关、目录存储配额大小等功能。  
  
 **调用形式：**     
- configure(config: ConfigOption): void  
  
 **系统能力:**  SystemCapability.HiviewDFX.HiAppEvent    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config | ConfigOption | true | 应用事件打点配置项对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 11103001 | Invalid max storage quota value |  
    
## ConfigOption    
应用事件打点配置方法，可用于配置打点开关、目录存储配额大小等功能。  
  
 **系统能力:**  SystemCapability.HiviewDFX.HiAppEvent    
### 属性    
 **系统能力:**  SystemCapability.HiviewDFX.HiAppEvent    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| disable | boolean | false | false | 打点功能开关，默认值为false。true：关闭打点功能，false：不关闭打点功能 |  
| maxStorage | string | false | false | 打点数据存放目录的配额大小，默认值为“10M”。<br>在目录大小超出配额后，下次打点会触发对目录的清理操作：按从旧到新的顺序逐个删除打点数据文件，直到目录大小不超出配额时结束 |  
    
## AppEventInfo    
此接口提供了应用事件信息的参数选项。  
  
 **系统能力:**  SystemCapability.HiviewDFX.HiAppEvent    
### 属性    
 **系统能力:**  SystemCapability.HiviewDFX.HiAppEvent    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| domain | string | false | true | 事件领域。事件领域名称支持数字、小写字母、下划线字符，需要以小写字母开头且不能以下划线结尾，长度非空且不超过16个字符。<br/> |  
| name | string | false | true | 事件名称。事件名称支持数字字符、字母字符、下划线字符，需要以字母字符或$字符开头且不能以下划线字符结尾，长度非空且不超过48个字符。<br/> |  
| eventType | EventType | false | true | 事件类型。<br/> |  
| params | object | false | true | 事件参数对象，每个事件参数包括参数名和参数值，其规格定义如下：<br/>- 参数名为string类型，只支持数字字符、字母字符、下划线字符，需要以字母字符或$字符开头且不能以下划线字符结尾，长度非空且不超过16个字符。<br/>- 参数值支持string、number、boolean、数组类型，string类型参数长度需在8*1024个字符以内，超出会做丢弃处理；number类型参数取值需在Number.MIN_SAFE_INTEGER~Number.MAX_SAFE_INTEGER范围内，超出可能会产生不确定值；数组类型参数中的元素类型只能全为string、number、boolean中的一种，且元素个数需在100以内，超出会做丢弃处理。<br/>- 参数个数需在32个以内，超出的参数会做丢弃处理。<br/> |  
    
## write  
 **调用形式：**     
    
- write(info: AppEventInfo): Promise\<void>    
起始版本： 9    
- write(info: AppEventInfo, callback: AsyncCallback\<void>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.HiviewDFX.HiAppEvent    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| info | AppEventInfo | true | 应用事件对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 打点回调函数。 |  
| Promise<void> | Promise对象 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 11100001 | Function is disabled |  
| 11101001 | Invalid event domain |  
| 11101002 | Invalid event name |  
| 11101003 | Invalid number of event parameters |  
| 11101004 | Invalid string length of the event parameter |  
| 11101005 | Invalid event parameter name |  
| 11101006 | Invalid array length of the event parameter |  
    
## AppEventPackage    
此接口提供了订阅返回的应用事件包的参数定义。  
  
 **系统能力:**  SystemCapability.HiviewDFX.HiAppEvent    
### 属性    
 **系统能力:**  SystemCapability.HiviewDFX.HiAppEvent    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| packageId | number | false | true | 事件包ID，从0开始自动递增。<br/> |  
| row | number | false | true | 事件包的事件数量。<br/> |  
| size | number | false | true | 事件包的事件大小，单位为byte。<br/> |  
| data | string[] | false | true | 事件包的事件信息。<br/> |  
    
## AppEventPackageHolder    
订阅数据持有者类，用于对订阅事件进行处理。  
  
 **系统能力:**  SystemCapability.HiviewDFX.HiAppEvent    
### setSize    
设置每次取出的应用事件包的数据大小阈值。  
  
 **调用形式：**     
- setSize(size: number): void  
  
 **系统能力:**  SystemCapability.HiviewDFX.HiAppEvent    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| size | number | true | 数据大小阈值，单位为byte，默认值为512*1024。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | 数据大小阈值，单位为byte，默认值为512*1024 |  
| 11104001 | Invalid size value. |  
    
### takeNext  
 **调用形式：**     
- takeNext(): AppEventPackage  
  
 **系统能力:**  SystemCapability.HiviewDFX.HiAppEvent    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| AppEventPackage | 取出的事件包对象，订阅事件数据被全部取出后会返回null |  
    
## TriggerCondition    
此接口提供了回调触发条件的参数选项，只要满足任一条件就会触发订阅回调。  
  
 **系统能力:**  SystemCapability.HiviewDFX.HiAppEvent    
### 属性    
 **系统能力:**  SystemCapability.HiviewDFX.HiAppEvent    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| row | number | false | false | 满足触发回调的事件总数量。<br/> |  
| size | number | false | false | 满足触发回调的事件总大小，单位为byte。<br/> |  
| timeOut | number | false | false | 满足触发回调的超时时长，单位为30s。<br/> |  
    
## AppEventFilter    
此接口提供了过滤应用事件的参数选项。  
  
 **系统能力:**  SystemCapability.HiviewDFX.HiAppEvent    
### 属性    
 **系统能力:**  SystemCapability.HiviewDFX.HiAppEvent    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| domain | string | false | true | 需要订阅的事件领域。<br/> |  
| eventTypes | EventType[] | false | false | 需要订阅的事件类型集合。<br/> |  
    
## Watcher    
此接口提供了应用事件观察者的参数选项。  
  
 **系统能力:**  SystemCapability.HiviewDFX.HiAppEvent    
### 属性    
 **系统能力:**  SystemCapability.HiviewDFX.HiAppEvent    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| name | string | false | true | 观察者名称，用于唯一标识观察者。<br/> |  
| triggerCondition | TriggerCondition | false | false | 订阅回调触发条件，需要与回调函数一同传入才会生效。<br/> |  
| appEventFilters | AppEventFilter[] | false | false | 订阅过滤条件，在需要对订阅事件进行过滤时传入。<br/> |  
| onTrigger | (curRow: number, curSize: number, holder: AppEventPackageHolder) => void | false | false | 订阅回调函数，需要与回调触发条件一同传入才会生效，函数入参说明如下：<br/>curRow：在本次回调触发时的订阅事件总数量；<br/>curSize：在本次回调触发时的订阅事件总大小，单位为byte；<br/>holder：订阅数据持有者对象，可以通过其对订阅事件进行处理。<br/> |  
    
## addWatcher    
添加应用事件观察者方法，可用于订阅应用事件。  
  
 **调用形式：**     
- addWatcher(watcher: Watcher): AppEventPackageHolder  
  
 **系统能力:**  SystemCapability.HiviewDFX.HiAppEvent    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| watcher | Watcher | true | 应用事件观察者。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| AppEventPackageHolder |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 11102001 | Invalid watcher name. |  
| 11102002 | Invalid filtering event domain. |  
| 11102003 | Invalid row value. |  
| 11102004 | Invalid size value. |  
| 11102005 | Invalid timeout value. |  
    
## removeWatcher    
移除应用事件观察者方法，可用于取消订阅应用事件。  
  
 **调用形式：**     
- removeWatcher(watcher: Watcher): void  
  
 **系统能力:**  SystemCapability.HiviewDFX.HiAppEvent    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| watcher | Watcher | true | 应用事件观察者。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 11102001 | Invalid watcher name. |  
    
## clearData    
应用事件打点数据清理方法，将应用存储在本地的打点数据进行清除。  
 **调用形式：**     
- clearData(): void  
  
 **系统能力:**  SystemCapability.HiviewDFX.HiAppEvent  
