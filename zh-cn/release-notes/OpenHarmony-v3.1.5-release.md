# OpenHarmony 3.1.5 Release


## 版本概述

当前版本在OpenHarmony 3.1.4 Release的基础上，修复了内存泄漏及linux kernel等开源组件的安全漏洞，增强了系统安全性。修复了部分系统稳定性的issue，增强了系统稳定性。更新配套的SDK版本，修复了预览器相关的问题。


## 配套关系

  **表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 |
| -------- | -------- | -------- |
| OpenHarmony | 3.1.5&nbsp;Release | NA |
| Full&nbsp;SDK | Ohos_sdk_full&nbsp;3.1.11.5&nbsp;(API&nbsp;Version&nbsp;8&nbsp;Relese) | 面向OEM厂商提供，包含了需要使用系统权限的系统接口。<br/>使用Full&nbsp;SDK时需要手动从镜像站点获取，并在DevEco&nbsp;Studio中替换，具体操作可参考[替换指南](../application-dev/faqs/full-sdk-switch-guide.md)。 |
| Public&nbsp;SDK | Ohos_sdk_public&nbsp;3.1.11.5&nbsp;(API&nbsp;Version&nbsp;8&nbsp;Release) | 面向应用开发者提供，不包含需要使用系统权限的系统接口。<br/>DevEco&nbsp;Studio&nbsp;3.0&nbsp;Beta4版本起，通过DevEco&nbsp;Studio获取的SDK默认为Public&nbsp;SDK。 |
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
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.1.5-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**方式二**

通过repo + https 下载。


```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v3.1.5-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### 从镜像站点获取

**表2** 获取源码路径

| 版本源码 | **版本信息** | **下载站点** | **SHA256校验码** |
| -------- | -------- | -------- | -------- |
| 全量代码（标准、轻量和小型系统） | 3.1.5&nbsp;Release | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/OpenHarmony-v3.1.5-Release.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/OpenHarmony-v3.1.5-Release.tar.gz.sha256) |
| Hi3516标准系统解决方案（二进制） | 3.1.5&nbsp;Release | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/standard_hi3516.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/standard_hi3516.tar.gz.sha256) |
| RK3568标准系统解决方案（二进制） | 3.1.5&nbsp;Release | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/standard_rk3568.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/standard_rk3568.tar.gz.sha256) |
| Hi3861轻量系统解决方案（二进制） | 3.1.5&nbsp;Release | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/hispark_pegasus.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/hispark_pegasus.tar.gz.sha256) |
| Hi3516小型系统解决方案-LiteOS（二进制） | 3.1.5&nbsp;Release | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/hispark_taurus.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/hispark_taurus.tar.gz.sha256) |
| Hi3516小型系统解决方案-Linux（二进制） | 3.1.5&nbsp;Release | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/hispark_taurus_linux.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/hispark_taurus_linux.tar.gz.sha256) |
| 标准系统Full&nbsp;SDK包（Mac） | 3.1.11.4 | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/ohos-sdk-mac-full.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/ohos-sdk-mac-full.tar.gz.sha256) |
| 标准系统Full&nbsp;SDK包（Windows\Linux） | 3.1.11.4 | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/ohos-sdk-full.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/ohos-sdk-full.tar.gz.sha256) |
| 标准系统Public&nbsp;SDK包（Mac） | 3.1.11.4 | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/ohos-sdk-mac-public.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/ohos-sdk-mac-public.tar.gz.sha256) |
| 标准系统Public&nbsp;SDK包（Windows\Linux） | 3.1.11.4 | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/ohos-sdk-public.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.1.5/ohos-sdk-public.tar.gz.sha256) |


## 更新说明

本版本在OpenHarmony 3.1.4 Release的基础上有如下变更。


### 特性变更

本次版本无新增特性及变更。

### API变更

3.1.5 Release对比3.1.4 Release API接口无变更。



### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。


### 修复缺陷列表

**表3** 修复缺陷issue列表

| 子系统         | 问题描述                                                     |
| -------------- | ------------------------------------------------------------ |
| SDK子系统      | 修复了预览器相关的一些问题。                                 |
| 网络管理子系统 | 进程com.ohos.netmanagersocket下线程1.ui出现了异常栈libconnection.z.so([I5IXWZ](https://gitee.com/openharmony/communication_netmanager_base/issues/I5IXWZ)) |
| Misc子系统     | request.download 下载时概率不上报complete事件([I5WZC6](https://gitee.com/openharmony/request_request/issues/I5WZC6)) |
| DFX子系统      | hdcd低概率出现cpp_crash([I65P94](https://gitee.com/openharmony/developtools_hdc/issues/I65P94)) |
| Arkui子系统    | 修复获焦组件通用属性异常的问题([I64YLA](https://gitee.com/openharmony/arkui_ace_engine/issues/I64YLA)) |




### 修复安全漏洞列表

**表4** 修复安全问题列表

| ISSUE | 问题描述 | 修复链接 |
| -------- | -------- | -------- |
| I5UHSG | 修复组件das u-boot上的CVE-2022-2347安全漏洞。 | [PR](https://gitee.com/openharmony/third_party_u-boot/pulls/62) |
| I5UI3F/I5VGDV | 修复组件kernel_linux_5.10上的CVE-2022-3303、CVE-2022-42703、CVE-2022-20422、CVE-2022-41222、CVE-2022-3239、CVE-2022-20423、CVE-2022-41850安全漏洞。 | [PR](https://gitee.com/openharmony/third_party_expat/pulls/23) |
| I5XU3W | 修复组件kernel_linux_5.10上的CVE-2022-3586、CVE-2022-3625、CVE-2022-42432、CVE-2022-3633、CVE-2022-3635、CVE-2022-3629、CVE-2022-3623、CVE-2022-3646、CVE-2022-3621、CVE-2022-3567、CVE-2022-43750、CVE-2022-3545、CVE-2022-2978、CVE-2022-3523、CVE-2022-2602、CVE-2022-3628安全漏洞。 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/541) |
| I5XUCJ | 修复组件kernel_linux_5.10上的CVE-2022-40768、CVE-2022-3577、CVE-2022-20409、CVE-2022-3566、CVE-2022-3606、CVE-2022-3564、CVE-2022-3649安全漏洞。 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/505) |
| I5VGIU | 修复组件kernel_linux_5.10上的CVE-2022-3169安全漏洞。 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/553) |
| I63VFW | 修复组件kernel_linux_5.10上的CVE-2022-41858安全漏洞。 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/569) |
| I63VG7 | 修复组件kernel_linux_5.10上的CVE-2022-45934、CVE-2022-4129、CVE-2022-4378、CVE-2022-3108、CVE-2022-47518、CVE-2022-47521、CVE-2022-47519、CVE-2022-47520安全漏洞。 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/586) |
| I66ZCI | 修复组件kernel_linux_5.10上的CVE-2022-3105、CVE-2022-3104、CVE-2022-3115、CVE-2022-3113、CVE-2022-3112安全漏洞。 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/579) |
| I66ZHX | 修复组件kernel_linux_5.10上的CVE-2022-3111安全漏洞。 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/584) |
| I66ZKM | 修复组件kernel_linux_5.10上的CVE-2022-3107安全漏洞。 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/590) |
| I65T2H | 修复组件kernel_linux_5.10上的CVE-2022-20566安全漏洞。 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/582) |
| I61HGX | 修复组件kernel_linux_5.10上的CVE-2022-42895、CVE-2022-42896安全漏洞。 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/545) |
| I652LY | 修复组件kernel_linux_5.10上的CVE-2022-4139安全漏洞。 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/567) |
| I65R2K | 修复组件python上的CVE-2022-42919安全漏洞。 | [PR](https://gitee.com/openharmony/third_party_python/pulls/36) |
| I65R59 | 修复组件python上的CVE-2022-45061安全漏洞。 | [PR](https://gitee.com/openharmony/third_party_python/pulls/37) |
| I65UJ8 | 修复组件python上的CVE-2022-45061安全漏洞。 | [PR](https://gitee.com/openharmony/third_party_python/pulls/35) |
| I60GOT | 修复组件pixman上的CVE-2022-37454安全漏洞。 | [PR](https://gitee.com/openharmony/third_party_pixman/pulls/11) |
| I5Z39U | 修复组件curl上的CVE-2022-32221、CVE-2022-42915、CVE-2022-42916安全漏洞。 | [PR](https://gitee.com/openharmony/third_party_curl/pulls/91) |
| I61I8F | 修复组件ntfs-3g上的CVE-2022-40284安全漏洞。 | [PR](https://gitee.com/openharmony/third_party_ntfs-3g/pulls/33) |
| I63V9Z | 修复组件libxml2上的CVE-2022-40303、CVE-2022-40304安全漏洞。 | [PR](https://gitee.com/openharmony/third_party_libxml2/pulls/31) |
