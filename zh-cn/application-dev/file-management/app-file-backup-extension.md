# 应用接入数据备份恢复

应用接入数据备份恢复需要通过BackupExtensionAbility实现。

BackupExtensionAbility，是[Stage模型](../application-models/stage-model-development-overview.md)中扩展组件[ExtensionAbility](../application-models/extensionability-overview.md)的派生类。开发者可以通过修改配置文件定制备份恢复框架的行为，包括是否允许备份恢复，备份哪些文件等。

## 约束与限制

- 当备份恢复时，所有待备份文件及目录的路径不得超过4095字节，否则将导致未定义行为。
- 当备份目录时，应用进程必须拥有读取该目录及其所有子目录的权限（DAC中的`r`），否则将导致备份失败。
- 当备份文件时，应用进程必须拥有搜索该文件所有祖父级目录的权限（DAC中的`x`），否则将导致备份失败。

## 开发步骤

1. 在应用配置文件`module.json5`中注册`extensionAbilities`相关配置

   新增`"extensionAbilities"`字段，其中注册类型`"type"`设置为`"backup"`，元数据信息["metadata"](../reference/apis/js-apis-bundleManager-metadata.md)新增一个`"name"`为`"ohos.  extension. backup"`的条目。

   BackupExtensionAbility配置文件示例：

   ```json
   {
       "extensionAbilities": [
           {
               "description": "$string:ServiceExtAbility",
               "icon": "$media:icon",
               "name": "BackupExtensionAbility",
               "type": "backup",
               "visible": true,
               "metadata": [
                   {
                       "name": "ohos.extension.backup",
                       "resource": "$profile:backup_config"
                   }
               ],
               "srcEntrance": "",
           }      
       ]
   }
   ```

2. 新增元数据资源配置文件

   在元数据资源配置文件中，定义备份恢复时需要传输的文件。元数据资源配置文件名称需要与`module.json5`中`"metadata.resource"`名称保持一致，其保存位置在工程的`resources/profile`文件夹下。

   元数据资源配置文件示例：

   ```json
   {
       "allowToBackupRestore": true,
       "includes": [
           "/data/storage/el2/base/files/users/*/*.json"
       ],
       "excludes": [
           "/data/storage/el2/base/files/users/*/hidden.json"
       ],
   }
   ```

### 元数据资源配置文件说明

| 属性名称             | 数据类型   | 必填 | 含义     |
| -------------------- | ---------- | ---- | ----------------------- |
| allowToBackupRestore | 布尔值     | 是   | 是否允许备份恢复，默认为false  |
| includes             | 字符串数组 | 否   | 应用沙箱中需要备份的文件和目录。<br>数组中的每一项均为模式串，可包含SHELL风格通配符（`*`，`?`，`[`）。<br>当模式串以非/开始时，表示一个相对于根路径的相对路径。<br>当`includes`已配置时，备份恢复框架会采用开发者配置的模式串，否则将会采用下述代码段内容作为默认值。 |
| excludes             | 字符串数组 | 否   | `includes`中无需备份的例外项。格式同`includes`。<br>当`excludes`已配置时，备份恢复框架会采用开发者配置的模式串，否则将会采用**空数组**作为默认值。  |

**includes默认值：**

```json
{
    "includes": [
    "data/storage/el2/database/",
    "data/storage/el2/base/files/",
    "data/storage/el2/base/preferences/",
    "data/storage/el2/base/haps/*/database/",
    "data/storage/el2/base/haps/*/files/",
    "data/storage/el2/base/haps/*/preferences/",
    ]
}
```

## 相关实例

针对应用接入数据的备份与恢复，有以下相关实例可供参考：

- [应用接入数据备份恢复（ArkTS）（Full SDK）（API10）](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Release/code/BasicFeature/FileManagement/FileBackupExtension)