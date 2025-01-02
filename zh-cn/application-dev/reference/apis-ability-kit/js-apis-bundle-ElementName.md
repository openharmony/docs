# ElementName

ElementName信息，通过接口[Context.getElementName](js-apis-inner-app-context.md)获取。

> **说明：**
> 本模块首批接口从API version 7 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## ElementName<sup>(deprecated)</sup>

> 从API version 9开始不再维护，建议使用[bundleManager-ElementName](js-apis-bundleManager-elementName.md)替代。

ElementName信息，标识Ability的基本信息，通过接口[Context.getElementName](js-apis-inner-app-context.md)获取。

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework。



| 名称                     | 类型     | 只读 | 可选 | 说明                       |
| ----------------------- | ---------| ---- | ---- | ------------------------- |
| deviceId                | string   | 否   | 是   | 设备id值。                   |
| bundleName              | string   | 否   | 否  | 应用Bundle的名称。          |
| abilityName             | string   | 否   | 否  | Ability的名称。               |
| uri                     | string   | 否   | 是  | 资源标识符。                 |
| shortName               | string   | 否   | 是  | Ability的短名称。               |