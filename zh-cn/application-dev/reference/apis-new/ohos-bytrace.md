# @ohos.bytrace    
数值变量的值。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import bytrace from '@ohos.bytrace'    
```  
    
## startTrace<sup>(deprecated)</sup>    
标记一个时间片跟踪任务的开始。  
 **调用形式：**     
- startTrace(name: string, taskId: number, expectedTime?: number): void  
  
 **废弃说明：** 从API version 8 开始废弃。替代接口: ohos.hiTraceMeter.startTrace。  
 **系统能力:**  SystemCapability.HiviewDFX.HiTrace    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 时间片跟踪任务名称<br/> |  
| taskId<sup>(deprecated)</sup> | number | true | 时间片跟踪任务id<br/> |  
| expectedTime<sup>(deprecated)</sup> | number | false | 期望的耗时时间（单位：ms）。可选，默认为空。 |  
    
 **示例代码：**   
```ts    
bytrace.startTrace("myTestFunc", 1);bytrace.startTrace("myTestFunc", 1, 5); // 从startTrace到finishTrace流程的期望耗时为5ms    
```    
  
    
## finishTrace<sup>(deprecated)</sup>    
标记一个时间片跟踪事件的结束。  
 **调用形式：**     
- finishTrace(name: string, taskId: number): void  
  
 **废弃说明：** 从API version 8 开始废弃。替代接口: ohos.hiTraceMeter.finishTrace。  
 **系统能力:**  SystemCapability.HiviewDFX.HiTrace    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 时间片跟踪任务名称<br/> |  
| taskId<sup>(deprecated)</sup> | number | true | 时间片跟踪任务id<br/> |  
    
 **示例代码：**   
```js    
```jsbytrace.finishTrace("myTestFunc", 1);```  
```// 跟踪并行执行的同名任务bytrace.startTrace("myTestFunc", 1);// 业务流程...... bytrace.startTrace("myTestFunc", 2);  // 第二个跟踪任务开始，同时第一个同名跟踪任务还没结束，出现了并行执行，对应接口的taskId需要不同// 业务流程...... bytrace.finishTrace("myTestFunc", 1);// 业务流程...... bytrace.finishTrace("myTestFunc", 2);```  
```// 跟踪串行执行的同名任务bytrace.startTrace("myTestFunc", 1);// 业务流程...... bytrace.finishTrace("myTestFunc", 1);  // 第一个跟踪任务结束// 业务流程...... bytrace.startTrace("myTestFunc", 1);   // 第二个跟踪任务开始，同名跟踪任务串行执行// 业务流程...... bytrace.finishTrace("myTestFunc", 1);```    
```    
  
    
## traceByValue<sup>(deprecated)</sup>    
标记预追踪耗时任务的数值变量，该变量的数值会不断变化。  
 **调用形式：**     
- traceByValue(name: string, count: number): void  
  
 **废弃说明：** 从API version 8 开始废弃。替代接口: ohos.hiTraceMeter.traceByValue。  
 **系统能力:**  SystemCapability.HiviewDFX.HiTrace    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 数值变量的名称<br/> |  
| count<sup>(deprecated)</sup> | number | true | 数值变量的值。 |  
    
 **示例代码：**   
```js    
let traceCount = 3;bytrace.traceByValue("myTestCount", traceCount);traceCount = 4;bytrace.traceByValue("myTestCount", traceCount);// 业务流程......    
```    
  
