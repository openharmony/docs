# UIExtensionContext    
UIExtensionContext是[UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md)的上下文环境，继承自[ExtensionContext](js-apis-inner-application-extensionContext.md)，提供UIExtensionAbility的相关配置信息以及操作UIAbility的方法，如启动UIAbility等。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## UIExtensionContext  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### startAbility    
启动Ability。  使用规则：  调用方应用位于后台时，使用该接口启动Ability需申请ohos.permission.START_ABILITIES_FROM_BACKGROUND权限 跨应用场景下，目标Ability的exported属性若配置为false，调用方应用需申请ohos.permission.START_INVISIBLE_ABILITY权限 组件启动规则详见：组件启动规则（Stage模型）  
 **调用形式：**     
    
- startAbility(want: Want, callback: AsyncCallback\<void>): void    
起始版本： 10    
- startAbility(want: Want, options: StartOptions, callback: AsyncCallback\<void>): void    
起始版本： 10    
- startAbility(want: Want, options?: StartOptions): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 启动Ability的want信息。 |  
| options | StartOptions | true | 启动Ability所携带的参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback形式返回启动结果。 |  
| Promise<void> | Promise形式返回启动结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 16000001 | The specified ability does not exist. |  
| 16000002 | The specified ability does not exist. |  
| 16000004 | Can not start invisible component. |  
| 16000005 | The specified process does not have the permission. |  
| 16000006 | Cross-user operations are not allowed. |  
| 16000008 | The crowdtesting application expires. |  
| 16000009 | An ability cannot be started or stopped in Wukong mode. |  
| 16000010 | The call with the continuation flag is forbidden. |  
| 16000011 | The context does not exist. |  
| 16000012 | The application is controlled. |  
| 16000013 | The application is controlled by EDM. |  
| 16000050 | Internal error. |  
| 16000053 | The ability is not on the top of the UI. |  
| 16000055 | Installation-free timed out. |  
| 16200001 | The caller has been released. |  
    
### startAbilityForResult    
启动一个Ability。Ability被启动后，有如下情况(callback形式):  - 正常情况下可通过调用[terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult)接口使之终止并且返回结果给调用方。  - 异常情况下比如杀死Ability会返回异常信息给调用方, 异常信息中resultCode为-1。  - 如果被启动的Ability模式是单实例模式, 不同应用多次调用该接口启动这个Ability，当这个Ability调用[terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult)接口使之终止时，只将正常结果返回给最后一个调用方, 其它调用方返回异常信息, 异常信息中resultCode为-1。  使用规则：  - 调用方应用位于后台时，使用该接口启动Ability需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限  - 跨应用场景下，目标Ability的exported属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限  - 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)  
 **调用形式：**     
    
- startAbilityForResult(want: Want, callback: AsyncCallback\<AbilityResult>): void    
起始版本： 10    
- startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback\<AbilityResult>): void    
起始版本： 10    
- startAbilityForResult(want: Want, options?: StartOptions): Promise\<AbilityResult>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 启动Ability的want信息。 |  
| options | StartOptions | true | 启动Ability所携带的参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 执行结果回调函数。 |  
| Promise<AbilityResult> | Promise形式返回执行结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 16000001 | The specified ability does not exist. |  
| 16000002 | The specified ability does not exist. |  
| 16000004 | Can not start invisible component. |  
| 16000005 | The specified process does not have the permission. |  
| 16000006 | Cross-user operations are not allowed. |  
| 16000008 | The crowdtesting application expires. |  
| 16000009 | An ability cannot be started or stopped in Wukong mode. |  
| 16000010 | The call with the continuation flag is forbidden. |  
| 16000011 | The context does not exist. |  
| 16000012 | The application is controlled. |  
| 16000013 | The application is controlled by EDM. |  
| 16000050 | Internal error. |  
| 16000053 | The ability is not on the top of the UI. |  
| 16000055 | Installation-free timed out. |  
| 16200001 | The caller has been released. |  
    
### connectServiceExtensionAbility    
将当前Ability连接到一个使用AbilityInfo.AbilityType.SERVICE模板的Ability。  
 **调用形式：**     
- connectServiceExtensionAbility(want: Want, options: ConnectOptions): number  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 连接ServiceExtensionAbility的want信息。 |  
| options | ConnectOptions | true | 与ServiceExtensionAbility建立连接后回调函数的实例。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回Ability连接的结果code。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 16000001 | The specified ability does not exist. |  
| 16000002 | The specified ability does not exist. |  
| 16000004 | Can not start invisible component. |  
| 16000005 | The specified process does not have the permission. |  
| 16000006 | Cross-user operations are not allowed. |  
| 16000008 | The crowdtesting application expires. |  
| 16000011 | The context does not exist. |  
| 16000050 | Internal error. |  
| 16000053 | The ability is not on the top of the UI. |  
| 16000055 | Installation-free timed out. |  
    
### disconnectServiceExtensionAbility    
断开与ServiceExtensionAbility的连接，断开连接之后需要将连接成功时返回的remote对象置空。  
 **调用形式：**     
    
- disconnectServiceExtensionAbility(connection: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- disconnectServiceExtensionAbility(connection: number): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| connection | number | true | 连接的ServiceExtensionAbility的数字代码，即connectServiceExtensionAbility返回的connectionId。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback形式返回断开连接的结果。 |  
| Promise<void> | 返回执行结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 16000011 | The context does not exist. |  
| 16000050 | Internal error. |  
