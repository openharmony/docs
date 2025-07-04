# CustomData (系统接口)

拉起模态页面时，开发者可通过[reloadInModal](js-apis-inner-application-autoFillExtensionContext-sys.md)接口将自定义数据传递给自动填充服务，并可通过自动填充服务的[onFillRequest](js-apis-app-ability-autoFillExtensionAbility-sys.md)获取到该数据。

> **说明：**
> 
> 本模块首批接口从API version 13开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。  
> 本模块接口为系统接口。

##  属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

| 名称 | 类型                   | 只读 | 可选 | 说明                                                 |
| ---- | ---------------------- | ---- | ---- | ---------------------------------------------------- |
| data | Record<string, Object> | 否   | 否   | 拉起模态页面时传递的自定义数据，该数据为Record类型。 |
