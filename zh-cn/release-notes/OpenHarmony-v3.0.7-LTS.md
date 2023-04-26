# OpenHarmony 3.0.7 LTS


## 版本概述

此版本为OpenHarmony-3.0-LTS分支上的维护版本，基于OpenHarmony-v3.0.6-LTS版本修复一些安全问题。


## 配套关系

  **表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 |
| -------- | -------- | -------- |
| OpenHarmony | 3.0.7&nbsp;LTS | NA |
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
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.0.7-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**方式二**：通过repo + https 下载。


```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v3.0.7-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### 从镜像站点获取

  **表2** 获取源码路径

| **LTS版本源码** | **版本信息** | **下载站点** | **SHA256校验码** |
| -------- | -------- | -------- | -------- |
| 全量代码（标准、轻量和小型系统） | 3.0.7 | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.0.7/code-v3.0.7-LTS.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.0.7/code-v3.0.7-LTS.tar.gz.sha256) |
| 标准系统Hi3516解决方案（二进制） | 3.0.7 | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.0.7/standard.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.0.7/standard.tar.gz.sha256) |
| 轻量系统Hi3861解决方案（二进制） | 3.0.7 | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.0.7/hispark_pegasus.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.0.7/hispark_pegasus.tar.gz.sha256) |
| 小型系统Hi3516解决方案-LiteOS（二进制） | 3.0.7 | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.0.7/hispark_taurus.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.0.7/hispark_taurus.tar.gz.sha256) |
| 小型系统Hi3516解决方案-Linux（二进制） | 3.0.7 | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.0.7/hispark_taurus_linux.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.0.7/hispark_taurus_linux.tar.gz.sha256) |


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
| I5VFI7    | 修复组件Kernel_linux_5.10上的CVE-2022-3303、CVE-2022-42703、CVE-2022-20422、CVE-2022-41222、CVE-2022-3239、CVE-2022-20423、CVE-2022-41850安全漏洞 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/508) |
| I5UHPU    | 修复组件Kernel_linux_5.10上的CVE-2022-40768、CVE-2022-3577、CVE-2022-20409、CVE-2022-3566、CVE-2022-3606、CVE-2022-3564、CVE-2022-3649安全漏洞 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/506) |
| I5QBIA    | 修复组件Kernel_linux_5.10上的CVE-2022-1184安全漏洞           | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/475) |
| I5VFK1    | 修复组件Kernel_linux_5.10上的CVE-2022-20421、CVE-2022-42719、CVE-2022-42720、CVE-2022-42721、CVE-2022-42722、CVE-2022-41674、CVE-2022-3535、CVE-2022-3521、CVE-2022-3565、CVE-2022-3594、CVE-2022-3435、CVE-2022-41849、CVE-2022-3524、CVE-2022-3542、CVE-2022-3534安全漏洞 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/503) |
| I5OJL9    | 修复组件Kernel_linux_5.10上的CVE-2022-26373安全漏洞          | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/495) |
| I5WC2X    | 修复组件Kernel_linux_5.10上的CVE-2022-23816、CVE-2022-29901、CVE-2022-29900安全漏洞 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/494) |
| I5VQVK    | 修复组件Kernel_linux_5.10上的CVE-2022-1462安全漏洞           | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/490) |
| I5VP0D    | 修复组件Kernel_linux_5.10上的CVE-2022-39189、CVE-2022-39190、CVE-2022-2663安全漏洞 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/489) |
| I5QBPW    | 修复组件Kernel_linux_5.10上的CVE-2022-39188、CVE-2022-3078、CVE-2022-2905、CVE-2022-39842安全漏洞 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/481) |
| I5SCE3    | 修复组件Kernel_linux_5.10上的CVE-2022-3202、CVE-2022-40307安全漏洞 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/464) |
| I5QBK8    | 修复组件Kernel_linux_5.10上的CVE-2022-3028，CVE-2022-2977，CVE-2022-2964安全漏洞 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/442) |
| I5RQTK    | 修复组件Kernel_linux_5.10上的CVE-2022-3061安全漏洞           | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/444) |
| I5R8CM    | 修复组件Kernel_linux_5.10上的CVE-2022-2959，CVE-2022-2991安全漏洞 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/436) |
| I5R8BB    | 修复组件Kernel_linux_5.10上的CVE-2022-2503安全漏洞           | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/435) |
| I5R6VI    | 修复组件Kernel_linux_5.10上的CVE-2022-2938安全漏洞           | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/434) |
| I5ZA11    | 修复组件curl上的CVE-2022-32221、CVE-2022-42915、CVE-2022-42916安全漏洞 | [PR](https://gitee.com/openharmony/third_party_curl/pulls/90) |
| I5QBFJ    | 修复组件curl上的CVE-2022-35252安全漏洞                       | [PR](https://gitee.com/openharmony/third_party_curl/pulls/85) |
| I5UHWM    | 修复组件wayland上的CVE-2021-3782安全漏洞                     | [PR](https://gitee.com/openharmony/third_party_wayland_standard/pulls/22) |
| I5MVPK    | 修复组件css-what上的CVE-2021-33587安全漏洞                   | [PR](https://gitee.com/openharmony/third_party_css-what/pulls/9) |
| I5YR0H    | 修复组件gstreamer上的CVE-2021-3185安全漏洞                   | [PR](https://gitee.com/openharmony/third_party_gstreamer/pulls/207) |
| I5XT87    | 修复组件expat上的CVE-2022-43680安全漏洞                      | [PR](https://gitee.com/openharmony/third_party_expat/pulls/22) |
| I5SD4W    | 修复组件expat上的CVE-2022-40674安全漏洞                      | [PR](https://gitee.com/openharmony/third_party_expat/pulls/19) |


