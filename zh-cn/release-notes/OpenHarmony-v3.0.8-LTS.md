# OpenHarmony 3.0.8 LTS


## 版本概述

此版本为OpenHarmony-3.0-LTS分支上的维护版本，基于OpenHarmony-v3.0.7-LTS版本修复一些安全问题。


## 配套关系

  **表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 |
| -------- | -------- | -------- |
| OpenHarmony | 3.0.8&nbsp;LTS | NA |
| HUAWEI&nbsp;DevEco&nbsp;Studio（可选） | 3.0 Beta3 for OpenHarmony | OpenHarmony应用开发推荐使用。 |
| HUAWEI&nbsp;DevEco&nbsp;Device&nbsp;Tool（可选） | 3.0 Release | OpenHarmony智能设备集成开发环境推荐使用。 |


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

**方式一（推荐）**：通过repo + ssh 下载（需注册公钥，请参考[码云帮助中心](https://gitee.com/help/articles/4191)）。


```
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.0.8-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**方式二**：通过repo + https 下载。


```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v3.0.8-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### 从镜像站点获取

  **表2** 获取源码路径

| **LTS版本源码** | **版本信息** | **下载站点** | **SHA256校验码** |
| -------- | -------- | -------- | -------- |
| 全量代码（标准、轻量和小型系统） | 3.0.8 | [站点](https://mirrors.huaweicloud.com/harmonyos/os/3.0.8/code-v3.0.8-LTS.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/harmonyos/os/3.0.8/code-v3.0.8-LTS.tar.gz.sha256) |
| 标准系统Hi3516解决方案（二进制） | 3.0.8 | [站点](https://mirrors.huaweicloud.com/harmonyos/os/3.0.8/standard.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/harmonyos/os/3.0.8/standard.tar.gz.sha256) |
| 轻量系统Hi3861解决方案（二进制） | 3.0.8 | [站点](https://mirrors.huaweicloud.com/harmonyos/os/3.0.8/hispark_pegasus.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/harmonyos/os/3.0.8/hispark_pegasus.tar.gz.sha256) |
| 小型系统Hi3516解决方案-LiteOS（二进制） | 3.0.8 | [站点](https://mirrors.huaweicloud.com/harmonyos/os/3.0.8/hispark_taurus.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/harmonyos/os/3.0.8/hispark_taurus.tar.gz.sha256) |
| 小型系统Hi3516解决方案-Linux（二进制） | 3.0.8 | [站点](https://mirrors.huaweicloud.com/harmonyos/os/3.0.8/hispark_taurus_linux.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/harmonyos/os/3.0.8/hispark_taurus_linux.tar.gz.sha256) |


## 更新说明


### 特性变更

此版本不涉及特性变更。


### API变更

此版本不涉及API变更。


### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。


## <sup>修复安全漏洞列表</sup>

  **表3** 修复的安全漏洞列表

| issue编号 | 描述 | 合入链接 |
| -------- | -------- | -------- |
| I5UHRW | 修复组件Kernel_linux_5.10上的CVE-2022-41218、CVE-2022-3424、CVE-2022-42328、CVE-2022-3643、CVE-2022-47946安全漏洞 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/647) |
| I648XK | 修复组件Kernel_linux_5.10上的CVE-2022-3169安全漏洞 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/561) |
| I5QBIA    | 修复组件Kernel_linux_5.10上的CVE-2022-1184安全漏洞           | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/475) |
| I62G8K | 修复组件Kernel_linux_5.10上的CVE-2022-42895、CVE-2022-42896安全漏洞 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/545) |
| I63VI6 | 修复组件Kernel_linux_5.10上的CVE-2022-41858安全漏洞 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/570) |
| I63VID    | 修复组件Kernel_linux_5.10上的CVE-2022-45934、CVE-2022-4129、CVE-2022-4378、CVE-2022-3108、CVE-2022-47518、CVE-2022-47521、CVE-2022-47519、CVE-2022-47520安全漏洞 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/587) |
| I65INV    | 修复组件Kernel_linux_5.10上的CVE-2022-4139安全漏洞           | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/568) |
| I66Y94    | 修复组件Kernel_linux_5.10上的CVE-2022-3105、CVE-2022-3104、CVE-2022-3115、CVE-2022-3113、CVE-2022-3112安全漏洞 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/580) |
| I66Y9Y    | 修复组件Kernel_linux_5.10上的CVE-2022-3106安全漏洞           | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/593) |
| I66YAD    | 修复组件Kernel_linux_5.10上的CVE-2022-3107安全漏洞           | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/591) |
| I6A4HN | 修复组件Kernel_linux_5.10上的CVE-2022-20568安全漏洞 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/630) |
| I6A4IZ | 修复组件Kernel_linux_5.10上的CVE-2023-20928安全漏洞 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/654) |
| I6B0AN | 修复组件Kernel_linux_5.10上的CVE-2022-4696安全漏洞 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/664) |
| I6B0B4 | 修复组件Kernel_linux_5.10上的CVE-2023-23559、CVE-2023-0179、CVE-2023-23454、CVE-2023-23455安全漏洞 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/662) |
| I65R5Q | 修复组件third_party_python上的CVE-2022-45061安全漏洞 | [PR](https://gitee.com/openharmony/third_party_python/pulls/40) |
| I6494T | 修复组件third_party_libxml2上的CVE-2022-40303、CVE-2022-40304安全漏洞 | [PR](https://gitee.com/openharmony/third_party_libxml2/pulls/32) |
| I5ZYY3 | 修复组件third_party_pixman上的CVE-2022-44638安全漏洞 | [PR](https://gitee.com/openharmony/third_party_pixman/pulls/12) |
| I5UHVA | 修复组件third_party_u-boot上的CVE-2022-2347安全漏洞 | [PR](https://gitee.com/openharmony/third_party_u-boot/pulls/63) |


