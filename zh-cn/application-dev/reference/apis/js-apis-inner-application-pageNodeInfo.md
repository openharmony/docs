# PageNodeInfo

用于自动填充的页面节点信息。

> **说明：**
> 
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。

## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

| 名称        | 类型                 | 必填 | 说明                                                         |
| ----------- | -------------------- | ---- | ------------------------------------------------------------ |
| id    | number               | 是   | 页面节点的ID。                               |
| depth    | number              | 是   | 页面节点的深度。                               |
| autoFillType    | [AutoFillType](js-apis-inner-application-autoFillType.md)        | 是   | 页面节点的自动填充类型。    |
| tag    | string              | 是   | 页面节点的标签。                               |
| value    | string              | 是   | 页面节点的值。                               |
| placeholder    | string              | 否   | 页面节点的占位符。                               |
| passwordRules    | string              | 否   | 生成密码的规则。                               |
| enableAutoFill    | boolean              | 是   | 自动填充标志。                               |
