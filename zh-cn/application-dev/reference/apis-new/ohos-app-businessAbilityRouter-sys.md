# @ohos.app.businessAbilityRouter    
本模块用于查询当前设备上安装的各种应用程序的路由ability信息。通过业务路由提供标准的业务模板和业务管理能力，开发者可以按照指定的业务类别注册标准业务，丰富的业务形成一个庞大的超市。系统应用或者三方应用可以从业务路由中获取所需业务，并选择合适的业务使用。同时业务路由提供统一的跳转管控规则，控制应用与业务之间的合理跳转，杜绝前后台任意的跳转行为，避免三方应用通过跳转变相分发，解决安全弱、体验差的问题。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import businessAbilityRouter from '@ohos.app.businessAbilityRouter'    
```  
    
## BusinessType    
此枚举值用于标识过滤条件类型。    
    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SHARE | 0 | 标识具有共享类型的ability信息。 |  
| UNSPECIFIED | 255 | 标识未指定类型的ability信息。 |  
    
## BusinessAbilityFilter    
此过滤值用于过滤查询的ability类型。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### 属性    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| businessType | BusinessType | false | true | 标识ability信息的类型。 |  
| mimeType | string | false | false | 标识支持mime类型的ability信息。 |  
| uri | string | false | false | 标识ability信息支持的uri。 |  
    
## queryBusinessAbilityInfo    
以异步方法通过给定的过滤条件查询ability信息。使用callback异步回调。成功返回查询到的路由ability信息，失败返回对应错误信息。  
 **调用形式：**     
    
- queryBusinessAbilityInfo(     filter: BusinessAbilityFilter,     callback: AsyncCallback\<Array\<BusinessAbilityInfo>>   ): void    
起始版本： 10    
- queryBusinessAbilityInfo(filter: BusinessAbilityFilter): Promise\<Array\<BusinessAbilityInfo>>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| filter | BusinessAbilityFilter | true | 支持按业务类型过滤的对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回查询到的ability信息，否则为错误对象。 |  
| Promise<Array<BusinessAbilityInfo>> | Promise对象，返回符合过滤条件的ability信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import businessAbilityRouter from '@ohos.app.businessAbilityRouter';  
import { BusinessError } from '@ohos.base';  
  
let filter: businessAbilityRouter.BusinessAbilityFilter = {businessType: businessAbilityRouter.BusinessType.SHARE};  
  
try {  
    businessAbilityRouter.queryBusinessAbilityInfo(filter, (error, data) => {  
        if (error) {  
            console.error('queryBusinessAbilityInfo failed ' + error.message);  
            return;  
        }  
        console.info('queryBusinessAbilityInfo success');  
    });  
} catch (error) {  
    let message = (error as BusinessError).message;  
    console.error('queryBusinessAbilityInfo failed ' + message);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import businessAbilityRouter from '@ohos.app.businessAbilityRouter';  
import { BusinessError } from '@ohos.base';  
  
let filter: businessAbilityRouter.BusinessAbilityFilter = {businessType: businessAbilityRouter.BusinessType.SHARE};  
  
try {  
    businessAbilityRouter.queryBusinessAbilityInfo(filter)  
        .then(() => {  
            console.info('queryBusinessAbilityInfo success');  
        }).catch((error: BusinessError) => {  
            console.error('queryBusinessAbilityInfo failed ' + error.message);  
        });  
} catch (error) {  
    let message = (error as BusinessError).message;  
    console.error('queryBusinessAbilityInfo failed ' + message);  
}  
    
```    
  
