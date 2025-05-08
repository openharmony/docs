# PageNodeInfo (系统接口)

用于自动填充的页面节点信息。

> **说明：**
> 
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口均为系统接口。
> 本模块接口仅可在Stage模型下使用。

## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

| 名称        | 类型                 | 只读 | 可选 | 说明                                                         |
| ----------- | -------------------- | ----| ---- | ------------------------------------------------------------ |
| id    | number               | 否   | 否   | 页面节点的ID。                               |
| depth    | number              | 否   | 否   | 页面节点的深度（单位：px）。                               |
| autoFillType    | [AutoFillType](js-apis-inner-application-autoFillType-sys.md)        | 否   | 否   | 页面节点的自动填充类型。    |
| tag    | string              | 否   | 否   | 页面节点的标签。                               |
| value    | string              | 否   | 否   | 页面节点的值。                               |
| placeholder    | string              | 否   | 是   | 页面节点的占位符。                               |
| passwordRules    | string              | 否   | 是   | 生成密码的规则。                               |
| enableAutoFill    | boolean              | 否   | 否   | 自动填充标志。true表示已开启自动填充，false表示未开启自动填充。            |
| rect<sup>12+</sup>    | [AutoFillRect](js-apis-inner-application-autoFillRect-sys.md) | 否   | 否   | 当前节点的坐标和宽高信息。  |
| isFocus<sup>12+</sup>    | boolean              | 否   | 否   | 当前节点是否获焦。true表示当前节点获焦，false表示当前节点未获焦。   |
| metadata<sup>12+</sup>    | string              | 否   | 是   | 页面节点的元数据。                               |
