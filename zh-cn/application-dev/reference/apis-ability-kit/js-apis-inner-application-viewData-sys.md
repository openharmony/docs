# ViewData (系统接口)

自动填充的视图数据信息。

> **说明：**
> 
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口均为系统接口。
> 本模块接口仅可在Stage模型下使用。

## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

| 名称        | 类型                 | 只读 | 可选 | 说明                                                         |
| ----------- | ------------------- | ---- | ---- | ------------------------------------------------------------ |
| bundleName    | string            | 否   | 否   | 应用名称。                               |
| moduleName    | string            | 否   | 否   | 模块名称。                               |
| abilityName   | string            | 否   | 否   | Ability名称。    |
| pageUrl       | string            | 否   | 否   | 页面的url。                               |
| pageNodeInfos | Array&lt;[PageNodeInfo](js-apis-inner-application-pageNodeInfo-sys.md)&gt;    | 否   | 否   | 页面节点的信息。                |
| pageRect<sup>12+</sup>    | [AutoFillRect](js-apis-inner-application-autoFillRect-sys.md)     | 否   | 否   | 页面的坐标和宽高信息。                |
| isUserSelected<sup>12+</sup> | boolean | 否   | 否   | 是否是用户选择的填充内容，true表示用户选择的填充内容，false表示非用户选择的填充内容。 |
| isOtherAccount<sup>12+</sup> | boolean | 否   | 否   | 是否拉起密码箱中其它账号信息供用户选择，true表示拉起密码箱中其他账号信息供用户选择，false表示不拉起密码箱中其他账号信息。 |
