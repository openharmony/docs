# 版本变更说明

- [V3.0 Beta2（2021-12-31）](#V30-Beta22021-12-31)
 - [版本兼容性](#版本兼容性)
 - [版本变更说明](#版本变更说明)
- [V3.0 Beta1（2021-09-29）](#V30-Beta12021-09-29)

## V3.0 Beta2（2021-12-31）


### 版本兼容性

DevEco Studio 3.0 Beta2版本兼容性配套关系如下表所示。

| 组件 | 版本要求 | 说明 | 
| -------- | -------- | -------- |
| Gradle | 7.3（最低版本要求7.2） | DevEco&nbsp;Studio已自带了Gradle7.3版本，开发者无需单独安装。 | 
| JDK | 11.0.x | DevEco&nbsp;Studio已自带了JDK&nbsp;11版本，开发者无需单独安装。 | 
| OpenHarmony&nbsp;SDK | 3.1.0.0（API&nbsp;Version&nbsp;8&nbsp;Beta） | 兼容历史版本SDK。 | 
| Toolchinas | 3.1.0.0 | 建议更新至最新版本。 | 
| hap插件 | 3.0.5.2 | 建议更新至最新版本。 |
| decctest插件 | 1.2.7.2 | 建议更新至最新版本。 |


### 版本变更说明

| |
| -------- |
| **新增特性：**<br/>-&nbsp;新增DevEco&nbsp;Studio支持界面功能菜单的汉化版本，默认显示为英文，如需开启汉化版本，请打开DevEco&nbsp;Studio的**Settings**界面，在**Plugins&nbsp;&gt;&nbsp;installed**中手动勾选“Chinese（Simplified）”插件，然后重新启动DevEco&nbsp;Studio即可生效。<br/>-&nbsp;新增支持OpenHarmony应用或服务的调试和运行，支持断点管理、变量查看、Step&nbsp;Into\Step&nbsp;Over\Step&nbsp;Out等单步调试功能。<br/>**增强特性：**<br/>-&nbsp;OpenHarmony&nbsp;SDK更新至3.1.0.0版本（API&nbsp;Version&nbsp;8&nbsp;Beta），配套的hap编译构建插件版本更新至3.0.5.2。<br/>-&nbsp;工程模板新增支持低代码开发的[Standard]Empty&nbsp;Ability模板。<br/>-&nbsp;支持eTS组件预览，要求compileSdkVersion为8或以上。<br/>-&nbsp;eTS实时预览支持边修改属性边展示预览效果，无需保存修改才生效，要求compileSdkVersion为8或以上。 | 


## V3.0 Beta1（2021-09-29）

| |
| -------- |
| **新增特性：**<br/>-&nbsp;新增支持OpenHarmony&nbsp;SDK的管理，开发者可通过DevEco&nbsp;Studio的SDK&nbsp;Manager功能来下载和管理OpenHarmony&nbsp;SDK。<br/>-&nbsp;在编译构建HAP包时，新增支持对单个Module进行编译，对于多Module工程中只需要编译其中一个Module的场景，可以提升编译构建速度；同时还新增支持一键重构建HAP包，即在编译构建HAP前，会自动执行Clean&nbsp;Project操作。<br/>**增强特性：**<br/>-&nbsp;编译构建插件更新至3.0.3.2版本。<br/>-&nbsp;Json编辑器增强，资源索引错误支持快速修复，并支持快速查看资源的取值。<br/>-&nbsp;工程视图支持Ohos视图，默认视图为Project视图，开发者可手动切换。<br/>-&nbsp;OpenHarmony工程支持ark方舟编译。<br/>-&nbsp;OpenHarmony工程类型标识字段supportSystem&nbsp;"standard"，由模块级build.gradle调整至工程级build.gradle。 | 
