# OpenHarmony 3.1.6 Release


## 版本概述

当前版本在OpenHarmony 3.1.5 Release的基础上，修复了内存泄漏及linux kernel等开源组件的安全漏洞，增强了系统安全性。修复了部分系统稳定性的issue，增强了系统稳定性。更新配套的SDK版本。


## 配套关系

  **表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 |
| -------- | -------- | -------- |
| OpenHarmony | 3.1.6&nbsp;Release | NA |
| Full&nbsp;SDK | Ohos_sdk_full&nbsp;3.1.12.5&nbsp;(API&nbsp;Version&nbsp;8&nbsp;Relese) | 面向OEM厂商提供，包含了需要使用系统权限的系统接口。<br/>使用Full&nbsp;SDK时需要手动从镜像站点获取，并在DevEco&nbsp;Studio中替换，具体操作可参考[替换指南](../application-dev/faqs/full-sdk-switch-guide.md)。 |
| Public&nbsp;SDK | Ohos_sdk_public&nbsp;3.1.12.5&nbsp;(API&nbsp;Version&nbsp;8&nbsp;Release) | 面向应用开发者提供，不包含需要使用系统权限的系统接口。<br/>DevEco&nbsp;Studio&nbsp;3.0&nbsp;Beta4版本起，通过DevEco&nbsp;Studio获取的SDK默认为Public&nbsp;SDK。 |
| HUAWEI&nbsp;DevEco&nbsp;Studio（可选） | 3.1&nbsp;Preview&nbsp;for&nbsp;OpenHarmony | OpenHarmony应用开发推荐使用。 |
| HUAWEI&nbsp;DevEco&nbsp;Device&nbsp;Tool（可选） | 3.0&nbsp;Release | OpenHarmony智能设备集成开发环境推荐使用。 |


## 源码获取


### 前提条件

1. 注册码云gitee账号。

2. 注册码云SSH公钥，请参考[码云帮助中心](https://gitee.com/help/articles/4191)。

3. 安装[git客户端](https://gitee.com/link?target=https%3A%2F%2Fgit-scm.com%2Fbook%2Fzh%2Fv2%2F%25E8%25B5%25B7%25E6%25AD%25A5-%25E5%25AE%2589%25E8%25A3%2585-Git)和[git-lfs](https://gitee.com/vcs-all-in-one/git-lfs?_from=gitee_search#downloading)并配置用户信息。
   
   ```
   git config --global user.name "yourname"
   git config --global user.email "your-email-address"
   git config --global credential.helper store
   ```

4. 安装码云repo工具，可以执行如下命令。
   
   ```
   curl -s https://gitee.com/oschina/repo/raw/fork_flow/repo-py3 > /usr/local/bin/repo  #如果没有权限，可下载至其他目录，并将其配置到环境变量中chmod a+x /usr/local/bin/repo
   pip3 install -i https://repo.huaweicloud.com/repository/pypi/simple requests
   ```


### 通过repo获取

**方式一（推荐）**

通过repo + ssh 下载（需注册公钥，请参考[码云帮助中心](https://gitee.com/help/articles/4191)）。


```
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.1.6-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**方式二**

通过repo + https 下载。


```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v3.1.6-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### 从镜像站点获取

**表2** 获取源码路径

| 版本源码 | **版本信息** | **下载站点** | **SHA256校验码** |
| -------- | -------- | -------- | -------- |
| 全量代码（标准、轻量和小型系统） | 3.1.6&nbsp;Release | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/code-v3.1.6-Release.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/code-v3.1.6-Release.tar.gz.sha256) |
| Hi3516标准系统解决方案（二进制） | 3.1.6&nbsp;Release | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/standard_hi3516.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/standard_hi3516.tar.gz.sha256) |
| RK3568标准系统解决方案（二进制） | 3.1.6&nbsp;Release | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/standard_rk3568.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/standard_rk3568.tar.gz.sha256) |
| Hi3861轻量系统解决方案（二进制） | 3.1.6&nbsp;Release | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/hispark_pegasus.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/hispark_pegasus.tar.gz.sha256) |
| Hi3516小型系统解决方案-LiteOS（二进制） | 3.1.6&nbsp;Release | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/hispark_taurus.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/hispark_taurus.tar.gz.sha256) |
| Hi3516小型系统解决方案-Linux（二进制） | 3.1.6&nbsp;Release | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/hispark_taurus_linux.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/hispark_taurus_linux.tar.gz.sha256) |
| 标准系统Full&nbsp;SDK包（Mac） | 3.1.12.5 | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/ohos-sdk-mac-full.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/ohos-sdk-mac-full.tar.gz.sha256) |
| 标准系统Full&nbsp;SDK包（Windows\Linux） | 3.1.12.5 | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/ohos-sdk-full.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/ohos-sdk-full.tar.gz.sha256) |
| 标准系统Public&nbsp;SDK包（Mac） | 3.1.12.5 | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/ohos-sdk-mac-public.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/ohos-sdk-mac-public.tar.gz.sha256) |
| 标准系统Public&nbsp;SDK包（Windows\Linux） | 3.1.12.5 | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/ohos-sdk-public.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.6/ohos-sdk-public.tar.gz.sha256) |


## 更新说明

本版本在OpenHarmony 3.1.5 Release的基础上有如下变更。


### 特性变更

本次版本无新增特性及变更。

### API变更

3.1.6 Release对比3.1.5 Release API接口无变更。



### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。


### 修复缺陷列表

**表3** 修复缺陷issue列表

| 子系统             | 问题描述                                                     |
| ------------------ | ------------------------------------------------------------ |
| 应用子系统         | com.ohos.callui应用多次出现jscrash 栈名：updateCallTimeList([I5LWIW](https://gitee.com/openharmony/applications_call/issues/I5LWIW)) |
| 全球化子系统       | 关键进程com.ohos.launcher下的com.ohos.launch线程多次出现libglobal_resmgr.z.so异常栈([I5LT0M](https://gitee.com/openharmony/global_resource_management/issues/I5LT0M))<br/>进程com.ohos.permissionmanager下的2.ui线程多次出现libglobal_resmgr.z.so异常栈([I68J7P](https://gitee.com/openharmony/global_resource_management/issues/I68J7P)) |
| Misc软件服务子系统 | 进程com.example.kikakeyboard出现cppcrash, libinputmethod_client.z.so([I66W3B](https://gitee.com/openharmony/inputmethod_imf/issues/I66W3B))<br/>通过工具进行压测出现CPPCrash问题([I65K13](https://gitee.com/openharmony/inputmethod_imf/issues/I65K13)) |
| 分布式硬件         | com.ohos.devicemanagerui多次出现jscrash([I69LD9](https://gitee.com/openharmony/distributedhardware_device_manager/issues/I69LD9)) |
| 分布式软总线       | 分布式图库组网重启后对端设备媒体资源显示不出来([I674LD](https://gitee.com/openharmony/applications_photos/issues/I674LD)) |




### 修复安全漏洞列表

**表4** 修复安全问题列表

| ISSUE | 问题描述 | 修复链接 |
| -------- | -------- | -------- |
| I5UI5A | 修复组件kernel_linux_5.10上的CVE-2022-41218、CVE-2022-3424、CVE-2022-42328、CVE-2022-3643、CVE-2022-47946安全漏洞。 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/646) |
| I69WX6 | 修复组件ffmpeg上的CVE-2022-3341安全漏洞。                    | [PR](https://gitee.com/openharmony/third_party_ffmpeg/pulls/74) |
| I68JS0 | 修复组件ffmpeg上的CVE-2022-3109安全漏洞。                    | [PR](https://gitee.com/openharmony/third_party_ffmpeg/pulls/71) |
| I671DT | 修复组件curl上的CVE-2022-43551、CVE-2022-43552安全漏洞。     | [PR](https://gitee.com/openharmony/third_party_curl/pulls/99) |
| I6A4YJ | 修复组件kernel_linux_5.10上的CVE-2022-20568安全漏洞。        | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/629) |
| I6A55C | 修复组件kernel_linux_5.10上的CVE-2023-0047安全漏洞。         | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/631) |

##  遗留缺陷列表

**表5** 遗留缺陷列表

| issue                                                        | 问题描述                                                   | 影响             | 计划解决日期 |
| ------------------------------------------------------------ | ---------------------------------------------------------- | ---------------- | ------------ |
| [I6AF0Y](https://gitee.com/openharmony/ability_ability_runtime/issues/I6AF0Y) | 两个窗口分屏配对后，关闭其中一个窗口，另一个窗口也会关闭。 | 分屏功能退出失效 | 2/15         |

