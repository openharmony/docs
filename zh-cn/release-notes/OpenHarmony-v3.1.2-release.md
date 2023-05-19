# OpenHarmony 3.1.2 Release


## 版本概述

当前版本在OpenHarmony 3.1.1 Release的基础上，做了如下更新：

修复部分子系统acts测试用例执行失败问题，同时补齐部分子系统的acts用例覆盖。

修复了linux kernel、OpenSSL、curl、node等三方组件的已知漏洞，增强了系统安全性。

修复了备忘录、设置、通知栏等系统应用的部分已知缺陷，提升了标准系统开发板的用户体验。

修复了SDK已知缺陷问题并配套发布最新的SDK版本。


## 配套关系

  **表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 |
| -------- | -------- | -------- |
| OpenHarmony | 3.1.2&nbsp;Release | NA |
| Full&nbsp;SDK | Ohos_sdk_full&nbsp;3.1.7.7&nbsp;(API&nbsp;Version&nbsp;8&nbsp;Relese)<br />Ohos_sdk_full&nbsp;3.1.7.5&nbsp;(API&nbsp;Version&nbsp;8&nbsp;Relese) | 面向OEM厂商提供，包含了需要使用系统权限的系统接口。<br/>使用Full&nbsp;SDK时需要手动从镜像站点获取，并在DevEco&nbsp;Studio中替换，具体操作可参考[替换指南](../application-dev/faqs/full-sdk-switch-guide.md)。 |
| Public&nbsp;SDK | Ohos_sdk_public&nbsp;3.1.7.7&nbsp;(API&nbsp;Version&nbsp;8&nbsp;Release)<br />Ohos_sdk_public&nbsp;3.1.7.5&nbsp;(API&nbsp;Version&nbsp;8&nbsp;Release) | 面向应用开发者提供，不包含需要使用系统权限的系统接口。<br/>DevEco&nbsp;Studio&nbsp;3.0&nbsp;Beta4版本起，通过DevEco&nbsp;Studio获取的SDK默认为Public&nbsp;SDK。 |
| HUAWEI&nbsp;DevEco&nbsp;Studio（可选） | 3.0&nbsp;Beta4&nbsp;for&nbsp;OpenHarmony | OpenHarmony应用开发推荐使用 |
| HUAWEI&nbsp;DevEco&nbsp;Device&nbsp;Tool（可选） | 3.0&nbsp;Release | OpenHarmony智能设备集成开发环境推荐使用 |


## 源码获取


### 前提条件

1. 注册码云gitee账号。

2. 注册码云SSH公钥，请参考[码云帮助中心](https://gitee.com/help/articles/4191)。

3. 安装[git客户端](https://git-scm.com/book/zh/v2/%E8%B5%B7%E6%AD%A5-%E5%AE%89%E8%A3%85-Git)和[git-lfs](https://gitee.com/vcs-all-in-one/git-lfs?_from=gitee_search#downloading)并配置用户信息。
   
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
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.1.2-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**方式二**

通过repo + https 下载。


```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v3.1.2-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### 从镜像站点获取

**表2** 获取源码路径

| 版本源码 | **版本信息** | **下载站点** | **SHA256校验码** |
| -------- | -------- | -------- | -------- |
| 全量代码（标准、轻量和小型系统） | 3.1.2&nbsp;Release | [站点](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/code-v3.1.2-Release.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/code-v3.1.2-Release.tar.gz.sha256) |
| Hi3516标准系统解决方案（二进制） | 3.1.2&nbsp;Release | [站点](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/standard_hi3516.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/standard_hi3516.tar.gz.sha256) |
| RK3568标准系统解决方案（二进制） | 3.1.2&nbsp;Release | [站点](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/standard_rk3568.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/standard_rk3568.tar.gz.sha256) |
| Hi3861轻量系统解决方案（二进制） | 3.1.2&nbsp;Release | [站点](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/hispark_pegasus.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/hispark_pegasus.tar.gz.sha256) |
| Hi3516小型系统解决方案-LiteOS（二进制） | 3.1.2&nbsp;Release | [站点](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/hispark_taurus.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/hispark_taurus.tar.gz.sha256) |
| Hi3516小型系统解决方案-Linux（二进制） | 3.1.2&nbsp;Release | [站点](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/hispark_taurus_linux.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/hispark_taurus_linux.tar.gz.sha256) |
| 标准系统Full&nbsp;SDK包（Mac） | 3.1.7.5 | [站点](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/ohos-sdk-mac-full.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/ohos-sdk-mac-full.tar.gz.sha256) |
| 标准系统Full&nbsp;SDK包（Windows\Linux） | 3.1.7.5 | [站点](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/ohos-sdk-full.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/ohos-sdk-full.tar.gz.sha256) |
| 标准系统Public&nbsp;SDK包（Mac） | 3.1.7.5 | [站点](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/ohos-sdk-mac-public.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/ohos-sdk-mac-public.tar.gz.sha256) |
| 标准系统Public&nbsp;SDK包（Windows\Linux） | 3.1.7.5 | [站点](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/ohos-sdk-public.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/harmonyos/os/3.1.2/ohos-sdk-public.tar.gz.sha256) |
| 标准系统Full&nbsp;SDK包（Mac） | 3.1.7.7 | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.2/sdk-patch/ohos-sdk-mac-full.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.2/sdk-patch/ohos-sdk-mac-full.tar.gz.sha256) |
| 标准系统Full&nbsp;SDK包（Windows\Linux） | 3.1.7.7 | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.2/sdk-patch/ohos-sdk-full.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.2/sdk-patch/ohos-sdk-full.tar.gz.sha256) |
| 标准系统Public&nbsp;SDK包（Mac） | 3.1.7.7 | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.2/sdk-patch/ohos-sdk-mac-public.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.2/sdk-patch/ohos-sdk-mac-public.tar.gz.sha256) |
| 标准系统Public&nbsp;SDK包（Windows\Linux） | 3.1.7.7 | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.2/sdk-patch/ohos-sdk-public.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.2/sdk-patch/ohos-sdk-public.tar.gz.sha256) |


## 更新说明

本版本在OpenHarmony 3.1.1 Release的基础上有如下变更。


### 特性变更

本次版本无新增特性及变更。

API变更


3.1.2 Release对比3.1.1 Release API接口无变更。



### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。


## 修复缺陷列表

**表3** 修复缺陷ISSUE列表

| 子系统 | 问题描述 |
| -------- | -------- |
| acts子系统 | -&nbsp;修复ActsFeatureAbilityTest模块1条用例执行失败的问题（[I5G8Q5](https://gitee.com/openharmony/xts_acts/issues/I5G8Q5)）<br/>-&nbsp;修复usb的sdk中的参数target未覆盖的问题（[I5FU0F](https://gitee.com/openharmony/xts_acts/issues/I5FU0F)）<br/>-&nbsp;修复graphic/webGL/src/main/js/default/test下用例未覆盖的问题（[I5FMJJ](https://gitee.com/openharmony/xts_acts/issues/I5FMJJ)）<br/>-&nbsp;修复ActsFeatureAbilityTest模块22条用例执行失败的问题（[I5FILR](https://gitee.com/openharmony/xts_acts/issues/I5FILR)）<br/>-&nbsp;删除Webgl下graphic/webGL/src/main/js/default/test测试套未使用的引用'\@ohos.napi_context'（[I5FAF7](https://gitee.com/openharmony/xts_acts/issues/I5FAF7)）<br/>-&nbsp;修复ActsAudioManagerJsTest的Test.json配置错误问题（[I5EJPP](https://gitee.com/openharmony/xts_acts/issues/I5EJPP)）<br/>-&nbsp;修复ohos.multimedia.mediaLibrary测试用例导包大小写错误问题（[I5EJ3W](https://gitee.com/openharmony/xts_acts/issues/I5EJ3W)）<br/>-&nbsp;修复通知子系统对应的4个测试套执行失败的问题（[I5EA00](https://gitee.com/openharmony/xts_acts/issues/I5EA00)）<br/>-&nbsp;修复ActsUpdateJsTest模块index.js源码引入测试套的api异常问题（[I5D5BV](https://gitee.com/openharmony/xts_acts/issues/I5D5BV)）<br/>-&nbsp;修复Test.json配置的命令无法创建push资源的目录问题（[I5D50G](https://gitee.com/openharmony/xts_acts/issues/I5D50G)）<br/>-&nbsp;修复ActsAnsActiveTest测试套用例兼容性问题（[I5BQB0](https://gitee.com/openharmony/xts_acts/issues/I5BQB0)）<br/>-&nbsp;修复ActsStServiceAbilityClientCaseTest模块五条用例执行失败问题（[I5GHRE](https://gitee.com/openharmony/xts_acts/issues/I5GHRE)）<br/>-&nbsp;修复ActsSubscriberTestUnorderSystemTest模块两条用例执行失败的问题（[I5GHP5](https://gitee.com/openharmony/xts_acts/issues/I5GHP5)）<br/>-&nbsp;修复ActsAudioRecorderJsTest、ActsMediaLibraryJsTest模块测试套无法执行问题（[I5H431](https://gitee.com/openharmony/xts_acts/issues/I5H431)） |
| SDK子系统 | -&nbsp;解决了预览器相关的一些问题。<br/>-&nbsp;解决了c++调试相关的一些问题。 |
| 应用子系统 | -&nbsp;修复通知管理界面相关的问题（[I5FLLB](https://gitee.com/openharmony/applications_systemui/issues/I5FLLB)）<br/>-&nbsp;修复备忘录的一些缺陷问题（[5FJGJ](https://gitee.com/openharmony/applications_notes/issues/I5FJGJ)）（[I5FJ9L](https://gitee.com/openharmony/applications_notes/issues/I5FJ9L)）（[I5FJCS](https://gitee.com/openharmony/applications_notes/issues/I5FJCS)） |


## 修复安全漏洞列表

**表4** 修复安全问题列表

| ISSUE | 问题描述 | 修复链接 |
| -------- | -------- | -------- |
| I5FZTU | 修复组件linux&nbsp;kernel&nbsp;5.10上的CVE-2022-21125、CVE-2022-2153、CVE-2022-32296安全漏洞。 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/307) |
| I5FZT0 | 修复组件linux&nbsp;kernel&nbsp;5.10上的CVE-2022-1508、CVE-2022-1972、CVE-2022-1998、CVE-2022-21499、CVE-2022-32981安全漏洞。 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/301) |
| I5FZSH | 修复组件linux&nbsp;kernel&nbsp;5.10上的CVE-2022-1974、CVE-2022-1975、CVE-2022-20153、CVE-2022-20154、CVE-2022-20132安全漏洞。 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/302) |
| I5FZQS | 修复组件linux&nbsp;kernel&nbsp;5.10上的CVE-2022-1729、CVE-2022-29581安全漏洞。 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/299) |
| I5CQMC | 修复组件third_party_chromium上的CVE-2022-2158、CVE-2022-2161、CVE-2022-2163、CVE-2022-2164、CVE-2022-2157、CVE-2022-2165、CVE-2022-2160、CVE-2022-2156、CVE-2022-1501、CVE-2022-2008、CVE-2022-2010、CVE-2022-2011、CVE-2022-1857、CVE-2022-1874、CVE-2022-0311、CVE-2022-1314安全漏洞。 | [PR](https://gitee.com/openharmony/third_party_chromium/pulls/29) |
| I5GG74 | 修复组件third_party_openssl上的CVE-2022-2097安全漏洞。 | [PR](https://gitee.com/openharmony/third_party_openssl/pulls/64) |
| I5GQI2 | 修复组件third_party_curl上的CVE-2022-22576、CVE-2022-27775、CVE-2022-27774、CVE-2022-27776安全漏洞。 | [PR](https://gitee.com/openharmony/third_party_curl/pulls/51) |
| I5H1HU | 修复组件third_party_flutter下libjpeg-turbo组件的CVE-2021-46822安全漏洞。 | [PR](https://gitee.com/openharmony/third_party_flutter/pulls/117) |
| I5KI54 | 修复组件third_party_freetype的CVE-2022-27405安全漏洞。 | [PR](https://gitee.com/openharmony/third_party_freetype/pulls/32) |
| I5J8V2 | 升级组件third_party_node到14.19.1版本，解决CVE-2022-32212、CVE-2022-32213、CVE-2022-2097、CVE-2022-32215安全漏洞。 | [PR](https://gitee.com/openharmony/third_party_node/pulls/29) |
| I59ZPI | 升级组件third_party_ntfs-3g到2022.5.17版本，修复2021.8.22版本上的已知安全漏洞。 | [PR](https://gitee.com/openharmony/third_party_ntfs-3g/pulls/18) |
| I5EEXE | 修复组件third_party_pcre2组件的CVE-2022-1586、CVE-2022-1587安全漏洞。 | [PR](https://gitee.com/openharmony/third_party_pcre2/pulls/24) |
| I5I9YX | 修复组件third_party_selinux上的CVE-2021-36085CVE-2021-36084CVE-2021-36087安全漏洞。 | [PR](https://gitee.com/openharmony/third_party_selinux/pulls/31) |


## 遗留缺陷列表

**表5** 遗留缺陷列表

| ISSUE | 问题描述 | 影响 | 计划解决日期 |
| -------- | -------- | -------- | -------- |
| [I5M0GH](https://gitee.com/openharmony/applications_notes/issues/I5M0GH) | 备忘录—最近删除界面选中笔记点击恢复按钮无反应。 | 备忘录demo应用，影响开发者体验。 | 2022/9/30 |
