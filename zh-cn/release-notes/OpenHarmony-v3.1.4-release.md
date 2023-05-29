# OpenHarmony 3.1.4 Release


## 版本概述

当前版本在OpenHarmony 3.1.3 Release的基础上，修复了linux kernel等开源组件的已知漏洞，增强了系统安全性。更新配套的SDK版本，修复了预览器相关的问题。


## 配套关系

  **表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 |
| -------- | -------- | -------- |
| OpenHarmony | 3.1.4&nbsp;Release | NA |
| Full&nbsp;SDK | Ohos_sdk_full&nbsp;3.1.9.7&nbsp;(API&nbsp;Version&nbsp;8&nbsp;Relese) | 面向OEM厂商提供，包含了需要使用系统权限的系统接口。<br/>使用Full&nbsp;SDK时需要手动从镜像站点获取，并在DevEco&nbsp;Studio中替换，具体操作可参考[替换指南](../application-dev/faqs/full-sdk-switch-guide.md)。 |
| Public&nbsp;SDK | Ohos_sdk_public&nbsp;3.1.9.7&nbsp;(API&nbsp;Version&nbsp;8&nbsp;Release) | 面向应用开发者提供，不包含需要使用系统权限的系统接口。<br/>DevEco&nbsp;Studio&nbsp;3.0&nbsp;Beta4版本起，通过DevEco&nbsp;Studio获取的SDK默认为Public&nbsp;SDK。 |
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
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.1.4-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**方式二**

通过repo + https 下载。


```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v3.1.4-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### 从镜像站点获取

**表2** 获取源码路径

| 版本源码 | **版本信息** | **下载站点** | **SHA256校验码** |
| -------- | -------- | -------- | -------- |
| 全量代码（标准、轻量和小型系统） | 3.1.4&nbsp;Release | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/code-v3.1.4-Release-2022-12-12.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/code-v3.1.4-Release-2022-12-12.tar.gz.sha256) |
| Hi3516标准系统解决方案（二进制） | 3.1.4&nbsp;Release | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/standard_hi3516.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/standard_hi3516.tar.gz.sha256) |
| RK3568标准系统解决方案（二进制） | 3.1.4&nbsp;Release | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/standard_rk3568.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/standard_rk3568.tar.gz.sha256) |
| Hi3861轻量系统解决方案（二进制） | 3.1.4&nbsp;Release | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/hispark_pegasus.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/hispark_pegasus.tar.gz.sha256) |
| Hi3516小型系统解决方案-LiteOS（二进制） | 3.1.4&nbsp;Release | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/hispark_taurus.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/hispark_taurus.tar.gz.sha256) |
| Hi3516小型系统解决方案-Linux（二进制） | 3.1.4&nbsp;Release | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/hispark_taurus_linux.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/hispark_taurus_linux.tar.gz.sha256) |
| 标准系统Full&nbsp;SDK包（Mac） | 3.1.9.7 | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/ohos-sdk-mac-full.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/ohos-sdk-mac-full.tar.gz.sha256) |
| 标准系统Full&nbsp;SDK包（Windows\Linux） | 3.1.9.7 | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/ohos-sdk-full.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/ohos-sdk-full.tar.gz.sha256) |
| 标准系统Public&nbsp;SDK包（Mac） | 3.1.9.7 | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/ohos-sdk-mac-public.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/ohos-sdk-mac-public.tar.gz.sha256) |
| 标准系统Public&nbsp;SDK包（Windows\Linux） | 3.1.9.7 | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/ohos-sdk-public.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.4/ohos-sdk-public.tar.gz.sha256) |


## 更新说明

本版本在OpenHarmony 3.1.3 Release的基础上有如下变更。


### 特性变更

本次版本无新增特性及变更。

### API变更

3.1.4 Release对比3.1.3 Release API接口无变更。



### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。


### 修复缺陷列表

**表3** 修复缺陷issue列表

| 子系统    | 问题描述                                                     |
| --------- | ------------------------------------------------------------ |
| SDK子系统 | 解决了预览器相关的一些问题（[I59433](https://gitee.com/openharmony/arkui_ace_engine/issues/I59433)、[I5K6B1](https://gitee.com/openharmony/arkui_ace_engine/issues/I5K6B1)、[I5C9XJ](https://gitee.com/openharmony/arkui_ace_engine/issues/I5C9XJ)、[I5AVZT](https://gitee.com/openharmony/arkui_ace_engine/issues/I5AVZT)） |
| Demo应用  | 修复小型系统退出设置后应用无法再进入的问题（[I5KTI8](https://gitee.com/openharmony/applications_sample_camera/issues/I5KTI8)） |




### 修复安全漏洞列表

**表4** 修复安全问题列表

| ISSUE | 问题描述 | 修复链接 |
| -------- | -------- | -------- |
| I5SD5S | 修复组件expat上的CVE-2022-40674安全漏洞                      | [PR](https://gitee.com/openharmony/third_party_expat/pulls/20) |
| I5XTS9 | 修复组件expat上的CVE-2022-43680安全漏洞 | [PR](https://gitee.com/openharmony/third_party_expat/pulls/23) |
| I5VNM9 | 修复组件skia上的CVE-2022-27405安全漏洞                       | [PR](https://gitee.com/openharmony/third_party_skia/pulls/24) |
| I5VGM0 | 修复组件kernel_linux_5.10上的CVE-2022-20421、CVE-2022-42719、CVE-2022-42720、CVE-2022-42721、CVE-2022-42722、CVE-2022-41674、CVE-2022-3535、CVE-2022-3521、CVE-2022-3565、CVE-2022-3594、CVE-2022-3435、CVE-2022-41849、CVE-2022-3524、CVE-2022-3542、CVE-2022-3534安全漏洞 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/502) |
| I5SBWK | 修复组件kernel_linux_5.10上的CVE-2022-3202、CVE-2022-40307安全漏洞 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/463) |
| I5QBUR | 修复组件kernel_linux_5.10上的CVE-2022-1184安全漏洞           | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/474) |
| I5WSJ5 | 修复组件chromium上的CVE-2022-3199、CVE-2022-3046、CVE-2022-3041、CVE-2022-3040、CVE-2022-3039、CVE-2022-3038、CVE-2022-3057、CVE-2022-3195、CVE-2022-3054、CVE-2022-3075安全漏洞，并同步更新webview hap包 | [PR](https://gitee.com/openharmony/web_webview/pulls/349) |
| I5UF8Z | 修复标准系统上的dhd_linux.c中泄露MAC地址的安全问题 | [PR](https://gitee.com/openharmony/kernel_linux_patches/pulls/315) |
| I5VISW | 修复标准系统上的蓝牙日志中存在明文打印Mac地址的安全问题            | [PR](https://gitee.com/openharmony/communication_bluetooth/pulls/626) |
| I5WJU0 | 修复标准系统上的分布式组网日志中出现设备udid敏感信息的安全问题     | [PR](https://gitee.com/openharmony/security_access_token/pulls/761) |
