# 源码混淆错误码
<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

从API version 18开始，提供源码混淆错误码。开发者在编译遇到此类错误时，可通过本文档查询错误码的含义、可能原因及建议的处理步骤。

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。有关源码混淆工具的说明，请参考[ArkGuard源码混淆工具概述](../../arkts-utils/source-obfuscation-overview.md)。

## 10804001 混淆规则配置文件缺失

**错误信息**

Failed to open obfuscation config file from {path}.

**错误描述**

{path}路径下混淆规则配置文件缺失或路径有误，无法读取。

**可能原因**

本模块`build-profile.json5`文件中的`arkOptions.obfuscation.ruleOptions`字段所指定的混淆规则配置文件不存在或者路径有误。

**处理步骤**

检查{path}是否存在，路径是否有误。具体可以参考[混淆规则配置文件示例](../../arkts-utils/source-obfuscation-guide.md#混淆配置文件)。

## 10804002 nameCache.json文件内容格式错误

**错误信息**

Failed to open namecache file from {nameCachePath}, Error message: SyntaxError: Unexpected string in JSON at position 733 At {nameCachePath}.

**错误描述**

指定的名称缓存文件路径{nameCachePath}下的JSON文件内容格式错误，不符合JSON文件格式要求。

**可能原因**

在混淆规则配置文件中通过-apply-namecache配置引用的nameCache.json文件内容格式错误，不符合JSON文件格式要求。

**处理步骤**

找到该{nameCachePath}文件，按照报错信息中提示的行号定位问题所在，对照JSON格式规范修正语法错误（如缺少逗号、括号不匹配等），确保文件内容符合标准JSON格式。

## 10804003 keptNames.json文件生成失败

**错误信息**

Failed to open keptNames.json from {defaultUnobfuscationPath}.

**错误描述**

{defaultUnobfuscationPath}路径下未生成keptNames.json文件。

**可能原因**

混淆规则配置中指定的{defaultUnobfuscationPath}路径中没有生成keptNames.json文件。

**处理步骤**

检查混淆规则配置中{defaultUnobfuscationPath}路径是否正确，确认该路径是否生成keptNames.json文件，若没有，清理缓存后重新编译。

## 10804004 nameCache.json文件不存在

**错误信息**

The applied namecache file {nameCachePath} configured by {configPath} does not exist.

**错误描述**

-apply-namecache规则配置的JSON文件{nameCachePath}不存在。

**可能原因**

在混淆规则配置文件obfuscation-rules.txt中，-apply-namecache配置的JSON文件不存在。-apply-namecache用于应用已有的名称缓存文件，以保持多次编译间混淆结果一致性。

**处理步骤**

在混淆规则配置文件obfuscation-rules.txt中，检查-apply-namecache配置的JSON文件路径是否正确。若路径有误，修正为正确的JSON文件路径。

## 10810001 混淆工具内部错误

**错误信息**

ArkTS:INTERNAL ERROR: Failed to obfuscate file 'entry/src/main/ets/entryability/EntryAbility.ets' with arkguard. Error: Obfuscation failed At entry/src/main/ets/entryability/EntryAbility.ets.

**错误描述**

ArkGuard混淆工具发生内部错误，导致文件混淆流程执行失败。

**可能原因**

ArkGuard源码混淆工具的核心文件被非官方途径修改或损坏。

**处理步骤**

在DevEco Studio中定位路径`\DevEco-Studio\sdk\default\openharmony\ets\build-tools\ets-loader\node_modules\arkguard`，对比arkguard目录与其同级文件的最后修改日期。如存在差异，重新下载安装该版本的DevEco Studio。
