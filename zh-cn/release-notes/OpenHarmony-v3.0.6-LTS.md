# OpenHarmony 3.0.6 LTS


## 版本概述

此版本为OpenHarmony-3.0-LTS分支上的维护版本，基于OpenHarmony-v3.0.5-LTS版本修复一些安全问题。


## 配套关系

  **表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 | 
| -------- | -------- | -------- |
| OpenHarmony | 3.0.6&nbsp;LTS | NA | 
| HUAWEI&nbsp;DevEco&nbsp;Studio（可选） | 3.0&nbsp;Beta1 | OpenHarmony应用开发推荐使用。 | 
| HUAWEI&nbsp;DevEco&nbsp;Device&nbsp;Tool（可选） | 2.2&nbsp;Beta2 | OpenHarmony智能设备集成开发环境推荐使用。 | 


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
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.0.6-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**方式二**：通过repo + https 下载。

  
```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v3.0.6-LTS --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### 从镜像站点获取

  **表2** 获取源码路径

| **LTS版本源码** | **版本信息** | **下载站点** | **SHA256校验码** | 
| -------- | -------- | -------- | -------- |
| 全量代码（标准、轻量和小型系统） | 3.0.6 | [站点](https://repo.huaweicloud.com/openharmony/os/3.0.6/code-v3.0.6-LTS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.0.6/code-v3.0.6-LTS.tar.gz.sha256) | 
| 标准系统Hi3516解决方案（二进制） | 3.0.6 | [站点](https://repo.huaweicloud.com/openharmony/os/3.0.6/standard.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.0.6/standard.tar.gz.sha256) | 
| 轻量系统Hi3861解决方案（二进制） | 3.0.6 | [站点](https://repo.huaweicloud.com/openharmony/os/3.0.6/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.0.6/hispark_pegasus.tar.gz.sha256) | 
| 小型系统Hi3516解决方案-LiteOS（二进制） | 3.0.6 | [站点](https://repo.huaweicloud.com/openharmony/os/3.0.6/hispark_taurus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.0.6/hispark_taurus.tar.gz.sha256) | 
| 小型系统Hi3516解决方案-Linux（二进制） | 3.0.6 | [站点](https://repo.huaweicloud.com/openharmony/os/3.0.6/hispark_taurus_linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.0.6/hispark_taurus_linux.tar.gz.sha256) | 


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
| I5MTWL | 修复kernel_linux_5.10组件的CVE-2022-36123、CVE-2022-20369、CVE-2022-2588、CVE-2022-2586、CVE-2022-2585、CVE-2022-20368安全漏洞 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/402) | 
| 5FYFI | 修复kernel_linux_5.10组件的CVE-2022-34918、CVE-2022-2318、CVE-2022-2380安全漏洞 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/331) | 
| 5FYFI | 修复kernel_linux_5.10组件的CVE-2022-26365、CVE-2022-33742、CVE-2022-33743、CVE-2022-33740、CVE-2022-33741安全漏洞 | [PR](https://gitee.com/openharmony/kernel_linux_5.10/pulls/352) | 
| I5LUE0 | 修复third_party_zlib组件的CVE-2022-37434安全漏洞 | [PR](https://gitee.com/openharmony/third_party_zlib/pulls/44) | 
| I5NCH4 | 小型系统Hi3516串口运行/bin/wms_server时会打印内存地址和布局信息 | [PR](https://gitee.com/openharmony/distributedschedule_samgr_lite/pulls/1) | 


