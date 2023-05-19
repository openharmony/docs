# OpenHarmony 3.1.3 Release


## 版本概述

当前版本在OpenHarmony 3.1.2 Release的基础上，修复了linux kernel、Python等开源组件的已知漏洞，增强了系统安全性。


## 配套关系

  **表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 | 
| -------- | -------- | -------- |
| OpenHarmony | 3.1.3&nbsp;Release | NA | 
| Full&nbsp;SDK | Ohos_sdk_full&nbsp;3.1.7.7&nbsp;(API&nbsp;Version&nbsp;8&nbsp;Release) | 面向OEM厂商提供，包含了需要使用系统权限的系统接口。<br/>使用Full&nbsp;SDK时需要手动从镜像站点获取，并在DevEco&nbsp;Studio中替换，具体操作可参考[替换指南](../application-dev/faqs/full-sdk-switch-guide.md)。 | 
| Public&nbsp;SDK | Ohos_sdk_public&nbsp;3.1.7.7&nbsp;(API&nbsp;Version&nbsp;8&nbsp;Release) | 面向应用开发者提供，不包含需要使用系统权限的系统接口。<br/>DevEco&nbsp;Studio&nbsp;3.0&nbsp;Beta4版本起，通过DevEco&nbsp;Studio获取的SDK默认为Public&nbsp;SDK。 | 
| HUAWEI&nbsp;DevEco&nbsp;Studio（可选） | 3.0&nbsp;Release&nbsp;for&nbsp;OpenHarmony | OpenHarmony应用开发推荐使用。 | 
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
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.1.3-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**方式二**

通过repo + https 下载。

  
```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v3.1.3-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### 从镜像站点获取

**表2** 获取源码路径

  | 版本源码 | **版本信息** | **下载站点** | **SHA256校验码** | 
| -------- | -------- | -------- | -------- |
| 全量代码（标准、轻量和小型系统） | 3.1.3&nbsp;Release | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.3/code-v3.1.3-Release.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.3/code-v3.1.3-Release.tar.gz.sha256) | 
| Hi3516标准系统解决方案（二进制） | 3.1.3&nbsp;Release | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.3/standard_hi3516.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.3/standard_hi3516.tar.gz.sha256) | 
| RK3568标准系统解决方案（二进制） | 3.1.3&nbsp;Release | [站点](https://mirrors.huaweicloud.com/harmonyos/os/3.1.3/standard_rk3568.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.3/standard_rk3568.tar.gz.sha256) | 
| Hi3861轻量系统解决方案（二进制） | 3.1.3&nbsp;Release | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.3/hispark_pegasus.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.3/hispark_pegasus.tar.gz.sha256) | 
| Hi3516小型系统解决方案-LiteOS（二进制） | 3.1.3&nbsp;Release | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.3/hispark_taurus.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.3/hispark_taurus.tar.gz.sha256) | 
| Hi3516小型系统解决方案-Linux（二进制） | 3.1.3&nbsp;Release | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.3/hispark_taurus_linux.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.3/hispark_taurus_linux.tar.gz.sha256) | 
| 标准系统Full&nbsp;SDK包（Mac） | 3.1.7.7 | [站点](https://gitee.com/link?target=https%3A%2F%2Fmirrors.huaweicloud.com%2Fopenharmony%2Fos%2F3.1.2%2Fsdk-patch%2Fohos-sdk-mac-full.tar.gz) | [SHA256校验码](https://gitee.com/link?target=https%3A%2F%2Fmirrors.huaweicloud.com%2Fopenharmony%2Fos%2F3.1.2%2Fsdk-patch%2Fohos-sdk-mac-full.tar.gz.sha256) | 
| 标准系统Full&nbsp;SDK包（Windows\Linux） | 3.1.7.7 | [站点](https://gitee.com/link?target=https%3A%2F%2Fmirrors.huaweicloud.com%2Fopenharmony%2Fos%2F3.1.2%2Fsdk-patch%2Fohos-sdk-full.tar.gz) | [SHA256校验码](https://gitee.com/link?target=https%3A%2F%2Fmirrors.huaweicloud.com%2Fopenharmony%2Fos%2F3.1.2%2Fsdk-patch%2Fohos-sdk-full.tar.gz.sha256) | 
| 标准系统Public&nbsp;SDK包（Mac） | 3.1.7.7 | [站点](https://gitee.com/link?target=https%3A%2F%2Fmirrors.huaweicloud.com%2Fopenharmony%2Fos%2F3.1.2%2Fsdk-patch%2Fohos-sdk-mac-public.tar.gz) | [SHA256校验码](https://gitee.com/link?target=https%3A%2F%2Fmirrors.huaweicloud.com%2Fopenharmony%2Fos%2F3.1.2%2Fsdk-patch%2Fohos-sdk-mac-public.tar.gz.sha256) | 
| 标准系统Public&nbsp;SDK包（Windows\Linux） | 3.1.7.7 | [站点](https://gitee.com/link?target=https%3A%2F%2Fmirrors.huaweicloud.com%2Fopenharmony%2Fos%2F3.1.2%2Fsdk-patch%2Fohos-sdk-public.tar.gz) | [SHA256校验码](https://gitee.com/link?target=https%3A%2F%2Fmirrors.huaweicloud.com%2Fopenharmony%2Fos%2F3.1.2%2Fsdk-patch%2Fohos-sdk-public.tar.gz.sha256) | 


## 更新说明

本版本在OpenHarmony 3.1.2 Release的基础上有如下变更。


### 特性变更

本次版本无新增特性及变更。

API变更


3.1.3 Release对比3.1.2 Release API接口无变更。



### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。


## 修复缺陷列表

**表3** 修复缺陷ISSUE列表

  | 子系统 | 问题描述 | 
| -------- | -------- |
| 媒体子系统 | 标准系统Hi3516在图库中播放视频，单板有概率异常重启（[I5N70Z](https://gitee.com/openharmony/kernel_linux_config/issues/I5N70Z)） | 


## 修复安全漏洞列表

**表4** 修复安全问题列表

  | ISSUE | 问题描述 | 修复链接 | 
| -------- | -------- | -------- |
| I5QAEX | 手机开启热点，测试机设置应用WLAN界面执行连接wifi操作，日志中打印ip地址。 | [PR](https://gitee.com/openharmony/communication_netmanager_base/pulls/527) | 
| I5QBQD | dsoftbus_standard:启动日志中存在明文mac地址打印。 | [PR](https://gitee.com/openharmony/communication_dsoftbus/pulls/2328) | 
| I5R13H | dhd启动日志中存在明文mac地址信息打印。 | [PR](https://gitee.com/openharmony/kernel_linux_patches/pulls/304) | 
| I5MVEM | 修复组件css-what&nbsp;上的CVE-2021-33587漏洞。 | [PR](https://gitee.com/openharmony/third_party_css-what/pulls/8) | 
| I5QBNS | 修复组件curl上的CVE-2022-35252漏洞。 | [PR](https://gitee.com/openharmony/third_party_curl/pulls/83) | 
| I5MR1V | 修复组件linux_kernel上的CVE-2022-2588、CVE-2022-2585、CVE-2022-20369、CVE-2022-20368安全漏洞。 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/426) | 
| I5MQS0 | 修复组件linux_kernel上的CVE-2022-2586安全漏洞。 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/427) | 
| I5P0W4 | 修复组件linux_kernel上的CVE-2022-2959、CVE-2022-2991安全漏洞。 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/428) | 
| I5P0TX | 修复组件linux_kernel上的CVE-2022-2938安全漏洞。 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/430) | 
| I5QBWI | 修复组件linux_kernel上的CVE-2022-3028、CVE-2022-2977、CVE-2022-2964安全漏洞。 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/440) | 
| I5QC1O | 修复组件linux_kernel上的CVE-2022-39188、CVE-2022-3078、CVE-2022-2905、CVE-2022-39842安全漏洞。 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/450) | 
| I5P0WN | 修复组件linux_kernel上的CVE-2022-26373安全漏洞。 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/461) | 
| I5NZKV | 修复组件linux_kernel上的CVE-2022-2503安全漏洞。 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/431) | 
| I5R2L0 | 修复组件linux_kernel上的CVE-2022-3061安全漏洞。 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/443) | 
| I5R2JQ | 修复组件linux_kernel上的CVE-2022-2663、CVE-2022-39190、CVE-2022-39189安全漏洞。 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/445) | 
| I5R8X1 | 修复组件Python上的CVE-2021-29921安全漏洞。 | [PR](https://gitee.com/openharmony/third_party_python/pulls/19) | 
| I5R8X1 | 修复组件Python上的CVE-2022-0391安全漏洞。 | [PR](https://gitee.com/openharmony/third_party_python/pulls/23) | 
| I5R8X1 | 修复组件Python上的CVE-2021-3737安全漏洞。 | [PR](https://gitee.com/openharmony/third_party_python/pulls/20) | 
| I5R8X1 | 修复组件Python上的CVE-2021-4189安全漏洞。 | [PR](https://gitee.com/openharmony/third_party_python/pulls/21) | 
| I5R8X1 | 修复组件Python上的CVE-2021-3733安全漏洞。 | [PR](https://gitee.com/openharmony/third_party_python/pulls/22) | 
| I5R8X1 | 修复组件Python上的CVE-2021-28861安全漏洞。 | [PR](https://gitee.com/openharmony/third_party_python/pulls/24) | 

