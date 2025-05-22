# 应用文件分享

应用文件分享是应用之间通过分享URI（Uniform Resource Identifier）进行文件共享的过程。

## 通过拉起文件处理类应用进行文件分享(startAbility)

基于[文件选择器(startAbility)](../application-models/file-processing-apps-startup.md)的分享方式，应用可分享单个文件，通过[ohos.app.ability.wantConstant的wantConstant.Flags接口](../reference/apis-ability-kit/js-apis-app-ability-wantConstant.md#flags)以只读或读写权限授权给其他应用。被分享应用可通过[ohos.file.fs的fs.open](../reference/apis-core-file-kit/js-apis-file-fs.md#fsopen)打开URI，并进行读写操作。

## 应用可分享目录

| 沙箱路径                             | 说明 &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp; |
| -------                              |  ---- |
| /data/storage/el1/base               |  应用el1级别加密数据目录 |
| /data/storage/el2/base               |  应用el2级别加密数据目录 |
| /data/storage/el2/distributedfiles   |  应用el2加密级别有账号分布式数据融合目录 |

## 文件URI规范

文件URI的格式：

  格式为：file://&lt;bundleName&gt;/&lt;path&gt;

- file：文件URI的标志。

- bundleName：该文件资源的属主。

- path：文件资源在应用沙箱中的路径。

## 相关实例

针对应用文件分享，有以下相关实例可供参考：

- [文件分享与访问（ArkTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/FileManagement/FileShare/SandboxShare)