# @ohos.hichecker    
HiChecker可以作为应用开发阶段使用的检测工具，用于检测代码运行过程中部分易忽略的问题，如应用线程出现耗时调用、应用进程中Ability资源泄露等问题。开发者可以通过日志记录或进程crash等形式查看具体问题并进行修改，提升应用的使用体验。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import hichecker from '@ohos.hichecker'    
```  
    
 **常量：**     
 **系统能力:**  SystemCapability.HiviewDFX.HiChecker    
| 名称 | 类型 | 值 | 说明 |  
| --------| --------| --------| --------|  
| RULE_CAUTION_PRINT_LOG |  | 9223372036854775808n | 告警规则，当有告警时记录日志。 |  
| RULE_CAUTION_TRIGGER_CRASH |  | 4611686018427387904n | 告警规则，当有告警时让应用推出。 |  
| RULE_THREAD_CHECK_SLOW_PROCESS |  | 1n | 检测规则，检测是否有耗时函数被调用。 |  
| RULE_CHECK_ABILITY_CONNECTION_LEAK |  | 8589934592n | 检测规则，检测是否发生ability泄露。 |  
| RULE_CHECK_ARKUI_PERFORMANCE<sup>(11+)</sup> |  | 17179869184n |  |  
    
## addRule<sup>(deprecated)</sup>    
添加一条或多条规则到系统，系统根据添加的规则进行检测或反馈。  
 **调用形式：**     
- addRule(rule: bigint): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.hichecker/hichecker#addCheckRule。  
 **系统能力:**  SystemCapability.HiviewDFX.HiChecker    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| rule<sup>(deprecated)</sup> | bigint | true | 需要添加的规则。 |  
    
 **示例代码：**   
```ts    
// 添加一条规则hichecker.addRule(hichecker.RULE_CAUTION_PRINT_LOG);  
// 添加多条规则hichecker.addRule(          hichecker.RULE_CAUTION_PRINT_LOG | hichecker.RULE_CAUTION_TRIGGER_CRASH);    
```    
  
    
## removeRule<sup>(deprecated)</sup>    
删除一条或多条规则，删除的规则后续将不再生效。  
 **调用形式：**     
- removeRule(rule: bigint): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.hichecker/hichecker#removeCheckRule。  
 **系统能力:**  SystemCapability.HiviewDFX.HiChecker    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| rule<sup>(deprecated)</sup> | bigint | true | 需要删除的规则。 |  
    
 **示例代码：**   
```ts    
// 删除一条规则hichecker.removeRule(hichecker.RULE_CAUTION_PRINT_LOG);  
// 删除多条规则hichecker.removeRule(          hichecker.RULE_CAUTION_PRINT_LOG | hichecker.RULE_CAUTION_TRIGGER_CRASH);    
```    
  
    
## getRule    
获取当前线程规则、进程规则、告警规则的合集。  
 **调用形式：**     
- getRule(): bigint  
  
 **系统能力:**  SystemCapability.HiviewDFX.HiChecker    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| bigint | 当前系统中添加的规则。 |  
    
 **示例代码：**   
```ts    
// 添加一条规则hichecker.addRule(hichecker.RULE_THREAD_CHECK_SLOW_PROCESS);  
// 获取已添加的规则hichecker.getRule();   // return 1n;    
```    
  
    
## contains<sup>(deprecated)</sup>    
当前已添加的规则集中是否包含了某一个特定的规则，如果传入的规则级别为线程级别，则仅在当前线程中进行查询。  
 **调用形式：**     
- contains(rule: bigint): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.hichecker/hichecker#containsCheckRule。  
 **系统能力:**  SystemCapability.HiviewDFX.HiChecker    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| rule<sup>(deprecated)</sup> | bigint | true | 需要查询的规则。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 查询结果，true表示规则已添加，false 表示规则未添加。 |  
    
 **示例代码：**   
```ts    
// 添加一条规则hichecker.addRule(hichecker.RULE_THREAD_CHECK_SLOW_PROCESS);  
// 查询是否包含hichecker.contains(hichecker.RULE_THREAD_CHECK_SLOW_PROCESS); // return true;hichecker.contains(hichecker.RULE_CAUTION_PRINT_LOG); // return false;    
```    
  
    
## addCheckRule<sup>(9+)</sup>    
添加一条或多条规则到系统，系统根据添加的规则进行检测或反馈。  
 **调用形式：**     
- addCheckRule(rule: bigint): void  
  
 **系统能力:**  SystemCapability.HiviewDFX.HiChecker    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| rule | bigint | true | 需要添加的规则。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
    // 添加一条规则  
    hichecker.addCheckRule(hichecker.RULE_CAUTION_PRINT_LOG);  
    // 添加多条规则  
    // hichecker.addCheckRule(  
    //     hichecker.RULE_CAUTION_PRINT_LOG | hichecker.RULE_CAUTION_TRIGGER_CRASH);  
} catch (err) {  
    console.error(`code: ${(err as BusinessError).code}, message: ${(err as BusinessError).message}`);  
}  
    
```    
  
    
## removeCheckRule<sup>(9+)</sup>    
删除一条或多条规则，删除的规则后续将不再生效。  
 **调用形式：**     
- removeCheckRule(rule: bigint): void  
  
 **系统能力:**  SystemCapability.HiviewDFX.HiChecker    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| rule | bigint | true | 需要删除的规则。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base'  
  
try {  
    // 删除一条规则  
    hichecker.removeCheckRule(hichecker.RULE_CAUTION_PRINT_LOG);  
    // 删除多条规则  
    // hichecker.removeCheckRule(  
    //     hichecker.RULE_CAUTION_PRINT_LOG | hichecker.RULE_CAUTION_TRIGGER_CRASH);  
} catch (err) {  
    console.error(`code: ${(err as BusinessError).code}, message: ${(err as BusinessError).message}`);  
}  
    
```    
  
    
## containsCheckRule<sup>(9+)</sup>    
当前已添加的规则集中是否包含了某一个特定的规则，如果传入的规则级别为线程级别，则仅在当前线程中进行查询。  
 **调用形式：**     
- containsCheckRule(rule: bigint): boolean  
  
 **系统能力:**  SystemCapability.HiviewDFX.HiChecker    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| rule | bigint | true | 需要查询的规则。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 查询结果，true表示规则已添加，false 表示规则未添加。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base'  
  
try {  
    // 添加一条规则  
    hichecker.addCheckRule(hichecker.RULE_THREAD_CHECK_SLOW_PROCESS);  
  
    // 查询是否包含  
    hichecker.containsCheckRule(hichecker.RULE_THREAD_CHECK_SLOW_PROCESS); // return true;  
    hichecker.containsCheckRule(hichecker.RULE_CAUTION_PRINT_LOG); // return false;  
} catch (err) {  
    console.error(`code: ${(err as BusinessError).code}, message: ${(err as BusinessError).message}`);  
}  
    
```    
  
