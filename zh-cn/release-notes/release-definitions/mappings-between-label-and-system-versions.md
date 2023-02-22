# 标签版本与系统版本对应对应关系说明

系统版本号指的是操作系统及其版本号，系统名与版本号之间以英文字符“-”连接，不能包含空格，最多64字符，随软件版本变更。其API接口名为GetOsFullName()。

OpenHarmony历史发布的1.1.x/3.0.x/3.1.x标签版本采用3位版本号命名，系统版本号采用4位命名，导致历史发布的版本所显示的系统版本号与标签版本号规则不统一。为避免造成困扰，我们对社区已发布的版本及其标签的对应关系整理成下表。

## 标签版本号与系统版本号对应关系

| 标签                       | 小型/轻量系统版本号  | 标准系统版本号       | 备注                       |
| -------------------------- | -------------------- | -------------------- | -------------------------- |
| OpenHarmony_release_v1.1.0 | NA                   | NA                   | 未定义系统版本号           |
| OpenHarmony-v1.1.1-LTS     | NA                   | NA                   | 未定义系统版本号           |
| OpenHarmony-v1.1.2-LTS     | NA                   | NA                   | 未定义系统版本号           |
| OpenHarmony-v1.1.3-LTS     | NA                   | NA                   | 未定义系统版本号           |
| OpenHarmony-v1.1.4-LTS     | NA                   | NA                   | 未定义系统版本号           |
| OpenHarmony-v1.1.5-LTS     | NA                   | NA                   | 未定义系统版本号           |
| OpenHarmony-v3.0-LTS       | OpenHarmony-3.0.0.0  | OpenHarmony-3.0.0.0  | 历史OSFullName字段未做修改 |
| OpenHarmony-v3.0.1-LTS     | OpenHarmony-3.0.0.0  | OpenHarmony-3.0.0.0  | 历史OSFullName字段未做修改 |
| OpenHarmony-v3.0.2-LTS     | OpenHarmony-3.0.0.0  | OpenHarmony-3.0.0.0  | 历史OSFullName字段未做修改 |
| OpenHarmony-v3.0.3-LTS     | OpenHarmony-3.0.0.0  | OpenHarmony-3.0.0.0  | 历史OSFullName字段未做修改 |
| OpenHarmony-v3.0.5-LTS     | OpenHarmony-3.0.0.0  | OpenHarmony-3.0.0.0  | 历史OSFullName字段未做修改 |
| OpenHarmony-v3.0.6-LTS     | OpenHarmony-3.0.0.0  | OpenHarmony-3.0.0.0  | 历史OSFullName字段未做修改 |
| OpenHarmony-v3.0.7-LTS     | OpenHarmony-3.0.7.2  | OpenHarmony-3.0.7.2  | NA                         |
| OpenHarmony-v3.1-Release   | OpenHarmony-1.0.1.0  | OpenHarmony-2.2.0.0  | 历史OSFullName字段未做修改 |
| OpenHarmony-v3.1.1-Release | OpenHarmony-1.0.1.0  | OpenHarmony-2.2.0.0  | 历史OSFullName字段未做修改 |
| OpenHarmony-v3.1.2-Release | OpenHarmony-1.0.1.0  | OpenHarmony-2.2.0.0  | 历史OSFullName字段未做修改 |
| OpenHarmony-v3.1.3-Release | OpenHarmony-3.1.8.5  | OpenHarmony-2.2.0.0  | 历史OSFullName字段未做修改 |
| OpenHarmony-v3.1.4-Release | OpenHarmony-3.1.9.6  | OpenHarmony-3.1.9.6  | NA                         |
| OpenHarmony-v3.1.5-Release | OpenHarmony-3.1.11.5 | OpenHarmony-3.1.11.5 | NA                         |

## 系统版本号修改方法

### 1.0.x/3.0.x/3.1.x版本修改方法

1.0.x/3.0.x/3.1.x版本上社区未做集成配置，小型/轻量系统和标准系统需要在不同文件上修改配置。

小型/轻量系统OsFullName修改文件路径：startup_syspara_lite/ frameworks / parameter / src / parameter_common.c

标准系统OsFullName修改文件路径：startup_syspara_lite/ interfaces / innerkits / native / syspara / src / sysversion.c

修改static const int MAJOR_VERSION、static const int SENIOR_VERSION、static const int FEATURE_VERSION、static const int BUILD_VERSION字段为对应系统版本号即可。

### 3.2.x及之后版本修改方法

3.2.x及之后版本修改文件路径： startup_init_lite/ services / etc_lite / param / ohos_const / ohos.para

修改const.ohos.fullname字段为对应系统版本号即可。