# 包管理子系统ChangeLog

## cl.bundlemanager.1 API9的ApplicationInfo结构体字段变更，新增systemApp字段，删除entryDir字段。

API9的ApplicationInfo结构体[bundleManager/applicationInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/ApplicationInfo.d.ts)字段变更，新增systemApp字段，删除entryDir字段。

**变更影响**<br>
对原有使用API version 9之前的应用无影响，使用API version 9的应用需要适配新模块和新接口。

**关键的接口/组件变更**<br>
ApplicationInfo结构体发生变化的字段内容如下表所示。
| 删除 | API9新增或变更 | 类型 |
| --- | --- | --- |
| 无 | systemApp | boolean |
| entryDir | 无  | string |

**适配指导**<br>
导入包管理查询的模块，在API9 version的ApplicationInfo结构体时，可以使用systemApp字段。使用了entryDir需要进行修改，该字段在HAP不解压特性中属于多余字段。

## cl.bundlemanager.2 API9的HapModuleInfo结构体字段变更，删除moduleSourceDir字段。

API9的HapModuleInfo结构体[bundleManager/hapModuleInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/HapModuleInfo.d.ts)字段变更，删除moduleSourceDir字段。

**变更影响**<br>
对原有使用API version 9之前的应用无影响，使用API version 9的应用需要适配新模块和新接口。

**关键的接口/组件变更**<br>
HapModuleInfo结构体发生变化的字段内容如下表所示。
| 删除 | API9新增或变更 | 类型 |
| --- | --- | --- |
| moduleSourceDir | 无  | string |

**适配指导**<br>
导入包管理查询的模块，在API9 version的HapModuleInfo结构体时不能使用moduleSourceDir字段。使用了moduleSourceDir需要进行修改，该字段在HAP不解压特性中属于多余字段。
