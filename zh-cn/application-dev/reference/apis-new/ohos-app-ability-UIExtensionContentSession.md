# @ohos.app.ability.UIExtensionContentSession    
UIExtensionContentSession是[UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md)加载界面内容时创建的实例对象，当UIExtensionComponent控件拉起指定的UIExtensionAbility时，UIExtensionAbility会创建UIExtensionContentSession对象，并通过[onSessionCreate](js-apis-app-ability-uiExtensionAbility.md#uiextensionabilityonsessioncreate)回调传递给开发者。一个UIExtensionComponent控件对应一个UIExtensionContentSession对象，提供界面加载，结果通知等方法。每个UIExtensionAbility的UIExtensionContentSession之间互不影响，可以各自进行操作。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## UIExtensionContentSession  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### loadContent    
为当前UIExtensionComponent控件对应的窗口加载与LocalStorage相关联的具体页面内容。  
 **调用形式：**     
- loadContent(path: string, storage?: LocalStorage): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | 设置加载页面的路径。 |  
| storage | LocalStorage | false | 存储单元，为应用程序范围内的可变状态属性和非可变状态属性提供存储。默认为空。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 16000050 | Internal error. |  
    
### terminateSelf  
 **调用形式：**     
    
- terminateSelf(callback: AsyncCallback\<void>): void    
起始版本： 10    
- terminateSelf(): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
### terminateSelfWithResult    
停止UIExtensionContentSession对应的窗口界面对象（promise形式）。  
 **调用形式：**     
    
- terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback\<void>): void    
起始版本： 10    
- terminateSelfWithResult(parameter: AbilityResult): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| parameter | AbilityResult | true | 返回给UIExtensionComponent控件的信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback形式返回停止结果。 |  
| Promise<void> | 停止UIExtensionContentSession对应的窗口界面对象的回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
### setWindowPrivacyMode    
设置窗口是否为隐私模式，使用Promise异步回调。设置为隐私模式的窗口，窗口内容将无法被截屏或录屏。  
 **调用形式：**     
    
- setWindowPrivacyMode(isPrivacyMode: boolean): Promise\<void>    
起始版本： 10    
- setWindowPrivacyMode(isPrivacyMode: boolean, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.PRIVACY_WINDOW    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isPrivacyMode | boolean | true | 窗口是否为隐私模式。true表示模式开启；false表示模式关闭。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
