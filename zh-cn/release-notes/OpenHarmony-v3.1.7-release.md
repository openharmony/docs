# OpenHarmony 3.1.7 Release


## 版本概述

当前版本在OpenHarmony 3.1.6 Release的基础上，修复了内存泄漏及linux kernel等开源组件的安全漏洞，增强了系统安全性。修复了部分系统稳定性的issue，增强了系统稳定性。更新配套的SDK版本。


## 配套关系

  **表1** 版本软件和工具配套关系

| 软件                                             | 版本                                                         | 备注                                                         |
| ------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| OpenHarmony                                      | 3.1.7&nbsp;Release                                           | NA                                                           |
| Full&nbsp;SDK                                    | Ohos_sdk_full&nbsp;3.1.13.6&nbsp;(API&nbsp;Version&nbsp;8&nbsp;Relese) | 面向OEM厂商提供，包含了需要使用系统权限的系统接口。<br/>使用Full&nbsp;SDK时需要手动从镜像站点获取，并在DevEco&nbsp;Studio中替换，具体操作可参考[替换指南](../application-dev/faqs/full-sdk-switch-guide.md)。 |
| Public&nbsp;SDK                                  | Ohos_sdk_public&nbsp;3.1.13.6&nbsp;(API&nbsp;Version&nbsp;8&nbsp;Release) | 面向应用开发者提供，不包含需要使用系统权限的系统接口。<br/>DevEco&nbsp;Studio&nbsp;3.0&nbsp;Beta4版本起，通过DevEco&nbsp;Studio获取的SDK默认为Public&nbsp;SDK。 |
| HUAWEI&nbsp;DevEco&nbsp;Studio（可选）           | 3.1&nbsp;Preview&nbsp;for&nbsp;OpenHarmony                   | OpenHarmony应用开发推荐使用。                                |
| HUAWEI&nbsp;DevEco&nbsp;Device&nbsp;Tool（可选） | 3.0&nbsp;Release                                             | OpenHarmony智能设备集成开发环境推荐使用。                    |


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
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.1.7-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**方式二**

通过repo + https 下载。


```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v3.1.7-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### 从镜像站点获取

**表2** 获取源码路径

| 版本源码                                   | **版本信息**       | **下载站点**                                                 | **SHA256校验码**                                             |
| ------------------------------------------ | ------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 全量代码（标准、轻量和小型系统）           | 3.1.7&nbsp;Release | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/code-v3.1.7-Release.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/code-v3.1.7-Release.tar.gz.sha256) |
| Hi3516标准系统解决方案（二进制）           | 3.1.7&nbsp;Release | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/standard_hi3516.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/standard_hi3516.tar.gz.sha256) |
| RK3568标准系统解决方案（二进制）           | 3.1.7&nbsp;Release | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/standard_rk3568.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/standard_rk3568.tar.gz.sha256) |
| Hi3861轻量系统解决方案（二进制）           | 3.1.7&nbsp;Release | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/hispark_pegasus.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/hispark_pegasus.tar.gz.sha256) |
| Hi3516小型系统解决方案-LiteOS（二进制）    | 3.1.7&nbsp;Release | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/hispark_taurus.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/hispark_taurus.tar.gz.sha256) |
| Hi3516小型系统解决方案-Linux（二进制）     | 3.1.7&nbsp;Release | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/hispark_taurus_linux.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/hispark_taurus_linux.tar.gz.sha256) |
| 标准系统Full&nbsp;SDK包（Mac）             | 3.1.13.6           | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/ohos-sdk-mac-full-3.1.13.6.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/ohos-sdk-mac-full-3.1.13.6.tar.gz.sha256) |
| 标准系统Full&nbsp;SDK包（Windows\Linux）   | 3.1.13.6           | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/ohos-sdk-full-3.1.13.6.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/ohos-sdk-full-3.1.13.6.tar.gz.sha256) |
| 标准系统Public&nbsp;SDK包（Mac）           | 3.1.13.6           | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/ohos-sdk-mac-public-3.1.13.6.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/ohos-sdk-mac-public-3.1.13.6.tar.gz.sha256) |
| 标准系统Public&nbsp;SDK包（Windows\Linux） | 3.1.13.6           | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/ohos-sdk-public-3.1.13.6.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.7/ohos-sdk-public-3.1.13.6.tar.gz.sha256) |


## 更新说明

本版本在OpenHarmony 3.1.7 Release的基础上有如下变更。


### 特性变更

本次版本无新增特性及变更。

### API变更

3.1.7 Release对比3.1.6 Release API接口无变更。



### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。


### 修复缺陷列表

**表3** 修复缺陷issue列表

| 子系统       | 问题描述                                                     |
| ------------ | ------------------------------------------------------------ |
| 应用子系统   | 进入联系人页面时“无联系人”默认页面一闪而过，进入联系人列表([I5ET9R](https://gitee.com/openharmony/applications_contacts/issues/I5ET9R))<br/>新建卡片推包到rk版，将卡片添加到桌面，长按桌面卡片，弹出服务卡片和移除按钮的同时也打开了应用([I5YB1O](https://gitee.com/openharmony/applications_hap/issues/I5YB1O))<br/>通过工具测出CPPCrash问题([I65H83](https://gitee.com/openharmony/applications_permission_manager/issues/I65H83))<br/>通过工具测出CPPCrash问题([I65TVW](https://gitee.com/openharmony/applications_permission_manager/issues/I65TVW))<br/>Launcher 反复点击recent 按钮会出现内存泄漏([I67SRG](https://gitee.com/openharmony/xts_acts/issues/I67SRG)) |
| 媒体子系统   | 打开图库应用，选择相册页签，点击相机，高概率闪退值桌面([I5QUSZ](https://gitee.com/openharmony/applications_hap/issues/I5QUSZ))<br/>通过工具测出CPPCrash问题([I65GZ1](https://gitee.com/openharmony/multimedia_medialibrary_standard/issues/I65GZ1)) |
| 全球化子系统 | 通过工具测出CPPCrash问题([I65GR8](https://gitee.com/openharmony/global_resmgr_standard/issues/I65GR8)) |
| 无障碍子系统 | 安全注入攻击测试，测试报告中存在服务接口ohos.accessibility.IAccessibleAbilityManagerServiceClient存在注入异常([I65PHE](https://gitee.com/openharmony/accessibility/issues/I65PHE)) |
| ArkUI子系统  | 图像效果功能失效([I65UID](https://gitee.com/openharmony/arkui_ace_engine/issues/I65UID))<br/>适配lite多资源打包([I78S6M](https://gitee.com/openharmony/developtools_ace_js2bundle/issues/I78S6M)) |
| 元能力子系统 | 两个窗口分屏配对后，关闭B窗口另一个窗口也会关闭([I6AF0Y](https://gitee.com/openharmony/ability_ability_runtime/issues/I6AF0Y)) |
| DFX子系统    | ohos.samples.distributedmusicplayer出现libhilog.z.so崩溃([I6DCSL](https://gitee.com/openharmony/hiviewdfx_hilog/issues/I6DCSL)) |




### 修复安全漏洞列表

**表4** 修复安全问题列表

| ISSUE  | 问题描述                                                     | 修复链接                                                     |
| ------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| I67XCL | 修复组件kernel_linux_5.10上的CVE-2022-3640安全漏洞           | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/659) |
| I6A56Q | 修复组件kernel_linux_5.10上的CVE-2023-20928安全漏洞          | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/653) |
| I6B0K7 | 修复组件kernel_linux_5.10上的CVE-2022-4696安全漏洞           | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/663) |
| I6BNVW | 修复组件mbedtls上的CVE-2021-44732、CVE-2021-45450安全漏洞    | [PR](https://gitee.com/openharmony/third_party_mbedtls/pulls/78) |
| I6BTZM | 修复组件flutter上的CVE-2022-37434安全漏洞                    | [PR](https://gitee.com/openharmony/third_party_flutter/pulls/247) |
| I6BXT0 | 修复组件kernel_linux_5.10上的CVE-2023-23559、CVE-2023-0179、CVE-2023-23454、CVE-2023-23455安全漏洞 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/661) |
| I6DQAH | 修复组件kernel_linux_5.10上的CVE-2023-0590、CVE-2022-3707安全漏洞 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/687) |
| I6DTV8 | 修复组件libexif上的CVE-2019-9278安全漏洞                     | [PR](https://github.com/libexif/libexif/commit/75aa73267fdb1e0ebfbc00369e7312bac43d0566) |
| I6E5KA | 修复组件openssl上的CVE-2023-0286安全漏洞                     | [PR](https://gitee.com/openharmony/third_party_openssl/pulls/83) |
| I6FFUV | 修复组件kernel_linux_5.10上的CVE-2023-20938、CVE-2023-0045、CVE-2023-0615安全漏洞 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/696) |
| I6FZ3A | 修复组件cares上的CVE-2022-4904安全漏洞                       | [PR](https://gitee.com/openharmony/third_party_cares/pulls/12) |
| I6HYRO | 修复组件kernel_linux_4.19上的CVE-2022-3028安全漏洞           | [PR](https://gitee.com/openharmony/kernel_linux_4.19/pulls/98) |
| I6JH1I | 修复组件kernel_linux_5.10上的CVE-2023-0461、CVE-2023-23004、CVE-2023-23000、CVE-2023-1078、CVE-2023-1076、CVE-2023-1118、CVE-2023-22995、CVE-2023-26545安全漏洞 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/725) |
| I6JH1L | 修复组件kernel_linux_4.19上的CVE-2023-0461、CVE-2023-26545、CVE-2022-0480、CVE-2023-1118、CVE-2022-1652、CVE-2021-3760安全漏洞 | [PR](https://gitee.com/openharmony/kernel_linux_4.19/pulls/107) |
| I6JH2L | 修复组件kernel_linux_4.19上的CVE-2023-23559、CVE-2022-47929、CVE-2022-2873、CVE-2023-23455安全漏洞 | [PR](https://gitee.com/openharmony/kernel_linux_4.19/pulls/103) |
| I6LCHO | 修复组件kernel_linux_4.19上的CVE-2023-0030安全漏洞           | [PR](https://gitee.com/openharmony/kernel_linux_4.19/pulls/111) |

##  

**表5** 遗留缺陷列表

| issue                                                        | 问题描述                               | 影响           | 计划解决日期 |
| ------------------------------------------------------------ | -------------------------------------- | -------------- | ------------ |
| [I6HAUC](https://gitee.com/openharmony/xts_acts/issues/I6HAUC) | 【3.1】调用Windows接口横竖屏鼠标会变形 | 影响开发者体验 | 2023-04-28   |
