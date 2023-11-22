# @ohos.process    
获取进程相关的信息，提供进程管理的相关功能。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import process from '@ohos.process'    
```  
    
 **常量：**     
 **系统能力:**  SystemCapability.Utils.Lang    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 值 | 说明 |  
| --------| --------| --------| --------|  
| egid | number |  |  |  
| euid | number |  |  |  
| gid | number |  |  |  
| groups | number[] |  |  |  
| ppid | number |  |  |  
    
## ChildProcess  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| pid | number | true | true |  |  
| ppid | number | true | true |  |  
| exitCode | number | true | true |  |  
| killed | boolean | true | true |  |  
    
### wait  
 **调用形式：**     
    
- wait(): Promise\<number>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<number> |  |  
    
### getOutput  
 **调用形式：**     
    
- getOutput(): Promise\<Uint8Array>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<Uint8Array> |  |  
    
### getErrorOutput  
 **调用形式：**     
    
- getErrorOutput(): Promise\<Uint8Array>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<Uint8Array> |  |  
    
### close  
 **调用形式：**     
- close(): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Utils.Lang    
### kill  
 **调用形式：**     
- kill(signal: number | string): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| signal | string | true |  |  
    
## ConditionType<sup>(10+)</sup>  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| timeout<sup>(10+)</sup> | number | false | false |  |  
| killSignal<sup>(10+)</sup> | number \| string | false | false |  |  
| maxBuffer<sup>(10+)</sup> | number | false | false |  |  
    
## runCmd  
 **调用形式：**     
- runCmd(    command: string,    options?: ConditionType  ): ChildProcess  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| command | string | true |  |  
| options | ConditionType | false |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ChildProcess |  |  
    
## on  
 **调用形式：**     
- on(type: string, listener: EventListener): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
| listener | EventListener | true |  |  
    
## off  
 **调用形式：**     
- off(type: string): boolean  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean |  |  
    
## cwd  
 **调用形式：**     
- cwd(): string  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string |  |  
    
## chdir  
 **调用形式：**     
- chdir(dir: string): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| dir | string | true |  |  
