# @ohos.app.ability.UIExtensionContentSession    
UIExtensionContentSession是[UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md)加载界面内容时创建的实例对象，当UIExtensionComponent控件拉起指定的UIExtensionAbility时，UIExtensionAbility会创建UIExtensionContentSession对象，并通过[onSessionCreate](js-apis-app-ability-uiExtensionAbility.md#uiextensionabilityonsessioncreate)回调传递给开发者。一个UIExtensionComponent控件对应一个UIExtensionContentSession对象，提供界面加载，结果通知等方法。每个UIExtensionAbility的UIExtensionContentSession之间互不影响，可以各自进行操作。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## UIExtensionContentSession  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### sendData    
发送数据给UIExtensionComponent控件。  
 **调用形式：**     
- sendData(data: { [key: string]: Object }): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| data | { [key: string]: Object } | true | 发送给UIExtensionComponent控件的数据参数 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
| 16000050 | Internal error. |  
    
### setReceiveDataCallback    
设置从UIExtensionComponent控件接收数据的回调方法。  
 **调用形式：**     
    
- setReceiveDataCallback(callback: (data: { [key: string]: Object }) => void): void    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 接收数据的回调方法。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
| 16000050 | Internal error. |  
    
### startAbility    
启动Ability（callback形式）。  
 **调用形式：**     
    
- startAbility(want: Want, callback: AsyncCallback\<void>): void    
起始版本： 10    
- startAbility(want: Want, options: StartOptions, callback: AsyncCallback\<void>): void    
起始版本： 10    
- startAbility(want: Want, options?: StartOptions): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
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
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 16000001 | The specified ability does not exist. |  
| 16000002 | Incorrect ability type. |  
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
启动一个Ability，在Ability终止后返回结果给调用方(callback形式)。Ability的终止方式包括以下几种情况:  - 正常情况下可通过调用[terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult)接口使之终止并且返回结果给调用方。  - 异常情况下比如杀死Ability会返回异常信息给调用方, 异常信息中resultCode为-1。  - 如果被启动的Ability模式是单实例模式, 不同应用多次调用该接口启动这个Ability，当这个Ability调用[terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult)接口使之终止时，只将正常结果返回给最后一个调用方, 其它调用方返回异常信息, 异常信息中resultCode为-1。  
 **调用形式：**     
    
- startAbilityForResult(want: Want, callback: AsyncCallback\<AbilityResult>): void    
起始版本： 10    
- startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback\<AbilityResult>): void    
起始版本： 10    
- startAbilityForResult(want: Want, options?: StartOptions): Promise\<AbilityResult>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 启动Ability的want信息。 |  
| options | StartOptions | true | 启动Ability所携带的参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<AbilityResult> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 16000001 | The specified ability does not exist. |  
| 16000002 | Incorrect ability type. |  
| 16000004 | Can not start invisible component. |  
| 16000005 | The specified process does not have the permission. |  
| 16000006 | Cross-user operations are not allowed. |  
| 16000008 | The crowdtesting application expires. |  
| 16000009 | An ability cannot be started or stopped in Wukong mode. |  
| 16000010 | The call with the continuation flag is forbidden |  
| 16000011 | The context does not exist. |  
| 16000012 | The application is controlled. |  
| 16000013 | The application is controlled by EDM. |  
| 16000050 | Internal error. |  
| 16000053 | The ability is not on the top of the UI. |  
| 16000055 | Installation-free timed out. |  
| 16200001 | The caller has been released. |  
    
### setWindowBackgroundColor    
设置UIExtensionAbility加载界面的背景色。该接口需要在[loadContent()](#uiextensioncontentsessionloadcontent)调用生效后使用。  
 **调用形式：**     
- setWindowBackgroundColor(color: string): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| color | string | true | 需要设置的背景色，为十六进制RGB或ARGB颜色，不区分大小写，例如`#00FF00`或`#FF00FF00`。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
| 16000050 | Internal error. |  
