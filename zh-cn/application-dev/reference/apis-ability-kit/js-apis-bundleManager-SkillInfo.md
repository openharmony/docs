# SkillInfo
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @memghaiyang-->
<!--Adviser: @HelloCrease-->

技能（Skill）是系统为AI代理提供的能力封装单元。技能通过[module.json5配置文件](../../quick-start/module-configuration-file.md#skillprofiles标签)中的skillProfiles标签声明能力。应用可以通过[skillManager](js-apis-skillManager.md)中提供的接口查询已安装的技能信息，发现并调用设备上的AI代理能力。

**起始版本：** 26.0.0

## 导入模块

```ts
import { skillManager } from '@kit.AbilityKit';
```

## SkillInfo

技能配置信息，用于定义AI代理的技能能力。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

| 名称           | 类型   | 只读 | 可选 | 说明           |
| -------------- | ------ | ---- | ---- | -------------- |
| bundleName   | string | 是   | 否   | 技能所属应用的包名。   |
| moduleName   | string | 是   | 否   | 技能所属模块的名称。   |
| skillName   | string | 是   | 否   | 技能的名称。   |
| skillType   | [SkillType](#skilltype) | 是   | 否   | 技能的类型。   |
| skillPath   | string | 是   | 否   | 技能的安装路径。   |
| abilityName   | string | 是   | 否   | 技能关联的ability名称。   |
| versionCode   | number | 是   | 否   | 技能的版本号。   |
| description   | string | 是   | 是   | 技能的描述信息。当应用调用[skillManager](js-apis-skillManager.md)接口，传入的[SkillInfoFlag](js-apis-skillManager.md#skillinfoflag)不包含GET_SKILL_INFO_WITH_DESCRIPTION时，该字段将返回默认值为undefined，开发者使用时需要进行有效值判断以防代码异常。 |
| srcEntries   | Array\<string\> | 是   | 是   | 实现技能的代码文件路径列表。当应用调用[skillManager](js-apis-skillManager.md)接口，传入的[SkillInfoFlag](js-apis-skillManager.md#skillinfoflag)不包含GET_SKILL_INFO_WITH_SRC_ENTRIES时，该字段将返回默认值为undefined，开发者使用时需要进行有效值判断以防代码异常。  |
| permissions   | Array\<string\> | 是   | 是   | 调用该技能所需要的权限列表。当应用调用[skillManager](js-apis-skillManager.md)接口，传入的[SkillInfoFlag](js-apis-skillManager.md#skillinfoflag)不包含GET_SKILL_INFO_WITH_PERMISSIONS时，该字段将返回默认值为undefined，开发者使用时需要进行有效值判断以防代码异常。  |
| requestPermissions   | Array\<string\> | 是   | 是   | 技能所在的模块申请的权限列表。当应用调用[skillManager](js-apis-skillManager.md)接口，传入的[SkillInfoFlag](js-apis-skillManager.md#skillinfoflag)不包含GET_SKILL_INFO_WITH_REQUEST_PERMISSIONS时，该字段将返回默认值为undefined，开发者使用时需要进行有效值判断以防代码异常。|
| version   | string | 是   | 是   | 技能的版本号，格式为`主版本号.次版本号.补丁版本号`。   |
| visibility   | string | 是   | 是   | 技能的可见性，支持的取值如下：<br/>-&nbsp;"private"：私有，仅当前应用可见。<br/>-&nbsp;"system"：系统级，系统应用和当前应用可见。<br/>-&nbsp;"public"：公开，所有应用都可见。   |

## SkillType

技能类型的枚举。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

| 名称 | 值 | 说明 |
| --- | --- |------|
| APP_SKILL | 0 | 应用技能。 |
| INDEPENDENT_SKILL | 1 | 独立技能。 |
