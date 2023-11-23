# @ohos.systemparameter    
系统参数（SystemParameter）是为各系统服务提供的简单易用的键值对访问接口，各个系统服务可以定义系统参数来描述该服务的状态信息，或者通过系统参数来改变系统服务的行为。其基本操作原语为get和set，通过get可以查询系统参数的值，通过set可以修改系统参数的值。  
详细的系统参数设计原理及定义可参考[系统参数](../../../device-dev/subsystems/subsys-boot-init-sysparam.md)。  
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import systemParameter from '@ohos.systemparameter'    
```  
    
## getSync<sup>(deprecated)</sup>    
获取系统参数Key对应的值。  
 **调用形式：**     
- getSync(key: string, def?: string): string  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Startup.SystemInfo    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key<sup>(deprecated)</sup> | string | true | 待查询的系统参数Key。 |  
| def<sup>(deprecated)</sup> | string | false | def为所要获取的系统参数的默认值 <br> def为可选参数，仅当系统参数不存在时生效 <br>def可以传undefined或自定义的任意值 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 系统参数值。<br> 若key存在,返回设定的值。<br> 若key不存在且def有效，返回def；若未指定def或def无效(如undefined)，返回空字符串。 |  
    
 **示例代码：**   
```ts    
try {  
    let info: string = systemparameter.getSync("const.ohos.apiversion");  
    console.log(JSON.stringify(info));  
} catch(e) {  
    console.log("getSync unexpected error: " + e);  
}  
    
```    
  
    
## get<sup>(deprecated)</sup>    
获取系统参数Key对应的值。  
 **调用形式：**     
- get(key: string, callback: AsyncCallback\<string>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Startup.SystemInfo    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key<sup>(deprecated)</sup> | string | true | 待查询的系统参数Key。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<string> | true | 回调函数。 |  
    
 **示例代码：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
    systemparameter.get("const.ohos.apiversion", (err: BusinessError, data: string) => {  
    if (err == undefined) {  
        console.log("get test.parameter.key value success:" + data)  
    } else {  
        console.log(" get test.parameter.key value err:" + err.code)  
    }});  
} catch(e) {  
    console.log("get unexpected error: " + e);  
}  
    
```    
  
    
## get<sup>(deprecated)</sup>    
获取系统参数Key对应的值。  
 **调用形式：**     
- get(key: string, def: string, callback: AsyncCallback\<string>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Startup.SystemInfo    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key<sup>(deprecated)</sup> | string | true | 待查询的系统参数Key。 |  
| def<sup>(deprecated)</sup> | string | true |  默认值。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<string> | true | 回调函数。 |  
    
 **示例代码：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
    systemparameter.get("const.ohos.apiversion", "default", (err: BusinessError, data: string) => {  
        if (err == undefined) {  
            console.log("get test.parameter.key value success:" + data)  
        } else {  
            console.log(" get test.parameter.key value err:" + err.code)  
        }  
    });  
} catch(e) {  
    console.log("get unexpected error:" + e)  
}  
    
```    
  
    
## get<sup>(deprecated)</sup>    
获取系统参数Key对应的值。  
 **调用形式：**     
- get(key: string, def?: string): Promise\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Startup.SystemInfo    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key<sup>(deprecated)</sup> | string | true | 待查询的系统参数Key。 |  
| def<sup>(deprecated)</sup> | string | false |  def为所要获取的系统参数的默认值 <br> def为可选参数，仅当系统参数不存在时生效 <br> def可以传undefined或自定义的任意值 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<string> | Promise示例，用于异步获取结果。 |  
    
 **示例代码：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
    let p: Promise<string> = systemparameter.get("const.ohos.apiversion");  
    p.then((value: string) => {  
        console.log("get test.parameter.key success: " + value);  
    }).catch((err: BusinessError) => {  
        console.log("get test.parameter.key error: " + err.code);  
    });  
} catch(e) {  
    console.log("get unexpected error: " + e);  
}  
    
```    
  
    
## setSync    
设置系统参数Key对应的值。  
 **调用形式：**     
- setSync(key: string, value: string): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Startup.SystemInfo    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | string | true | 待设置的系统参数Key。 |  
| value | string | true | 待设置的系统参数值。 |  
    
 **示例代码：**   
```ts    
try {  
    systemparameter.setSync("test.parameter.key", "default");  
} catch(e) {  
    console.log("set unexpected error: " + e);  
}  
    
```    
  
    
## set<sup>(deprecated)</sup>    
设置系统参数Key对应的值。  
 **调用形式：**     
- set(key: string, value: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Startup.SystemInfo    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key<sup>(deprecated)</sup> | string | true | 待设置的系统参数Key。 |  
| value<sup>(deprecated)</sup> | string | true | 待设置的系统参数值。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。 |  
    
 **示例代码：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
    systemparameter.set("test.parameter.key", "testValue",  (err: BusinessError, data: void) =>{  
    if (err == undefined) {  
        console.log("set test.parameter.key value success :" + data)  
    } else {  
        console.log("set test.parameter.key value err:" + err.code)  
    }});  
} catch(e) {  
    console.log("set unexpected error: " + e);  
}  
    
```    
  
    
## set<sup>(deprecated)</sup>    
设置系统参数Key对应的值。  
 **调用形式：**     
- set(key: string, value: string): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Startup.SystemInfo    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key<sup>(deprecated)</sup> | string | true | 待设置的系统参数Key。 |  
| value<sup>(deprecated)</sup> | string | true | 待设置的系统参数值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise示例，用于异步获取结果。 |  
    
 **示例代码：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
    let p: Promise<void> = systemparameter.set("test.parameter.key", "testValue");  
    p.then((value: void) => {  
        console.log("set test.parameter.key success: " + value);  
    }).catch((err: BusinessError) => {  
        console.log(" set test.parameter.key error: " + err.code);  
    });  
} catch(e) {  
    console.log("set unexpected error: " + e);  
}    
```    
  
