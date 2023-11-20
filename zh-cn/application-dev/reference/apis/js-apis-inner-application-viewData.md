# ViewData

自动填充的视图数据信息。

> **说明：**
> 
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。

## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

| 名称        | 类型                 | 必填 | 说明                                                         |
| ----------- | -------------------- | ---- | ------------------------------------------------------------ |
| bundleName    | string               | 是   | 应用名称。                               |
| moduleName    | string              | 是   | 模块名称。                               |
| abilityName    | string        | 是   | Ability名称。    |
| pageUrl    | string              | 是   | 页面的url。                               |
| pageNodeInfos    | Array&lt;[PageNodeInfo](js-apis-inner-application-pageNodeInfo.md)&gt;     | 是   | 页面节点的信息。                |