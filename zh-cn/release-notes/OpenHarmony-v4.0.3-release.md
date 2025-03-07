# OpenHarmony 4.0.3 Release


## 版本概述

当前版本在OpenHarmony 4.0.2 Release的基础上，主要修复了linux kernel等开源组件的安全漏洞，增强了系统安全性。修复了部分功能和系统稳定性的issue，增强了系统稳定性。


## 配套关系

**表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 |
| -------- | -------- | -------- |
| OpenHarmony | 4.0.3 Release | NA |
| Public SDK | Ohos_sdk_public 4.0.12.4 (API Version 10 Release) | 面向应用开发者提供，不包含需要使用系统权限的系统接口。通过DevEco Studio默认获取的SDK为Public SDK。 |
| HUAWEI DevEco Studio（可选） | 4.0 Release | OpenHarmony应用开发推荐使用。获取方式：<br />[Windows(64-bit)](https://contentcenter-vali-drcn.dbankcdn.cn/pvt_2/DeveloperAlliance_package_901_9/9a/v3/HBD3TfhiT_GFqeX44Qcwtg/devecostudio-windows-4.0.0.600.zip?HW-CC-KV=V1&HW-CC-Date=20231027T004333Z&HW-CC-Expire=315360000&HW-CC-Sign=279824A013505EFC063997614DC1B6AB1C3A2EE5AC48CEF15DDB3E1F79DA435A)  <br />SHA256校验码：2c88cf43e1ef6ba722aac31eccc8ef92f07a9b72e43a9c1df127017828a22137<br />[Mac(X86)](https://contentcenter-vali-drcn.dbankcdn.cn/pvt_2/DeveloperAlliance_package_901_9/e0/v3/y3Qc4UHsTn6i1M7yr3hVYg/devecostudio-mac-4.0.0.600.zip?HW-CC-KV=V1&HW-CC-Date=20231027T004531Z&HW-CC-Expire=315360000&HW-CC-Sign=07F14E7173D87ABF73777BA0CF7ADF1C1264A7D94909976471AC420C1932E8A6)  <br />SHA256校验码：25e491458eec50b4abddf5bed6aa85893801d70afbce02958f17bd904619405a<br />[Mac(ARM)](https://contentcenter-vali-drcn.dbankcdn.cn/pvt_2/DeveloperAlliance_package_901_9/94/v3/b0yynFMFSGGvbe--AQQR9w/devecostudio-mac-arm-4.0.0.600.zip?HW-CC-KV=V1&HW-CC-Date=20231027T004429Z&HW-CC-Expire=315360000&HW-CC-Sign=451E5B5C6B6E721A6C35E96FD67791D50ADEC56E987D87CD61E9E5152F8D6626)  <br />SHA256校验码：284cb01f7b819e0da1d4fcacbbbbe8017ba220b5e3b9b1d5e4cc59ea30456acc |
| HUAWEI DevEco Device Tool（可选） | 4.0 Release | OpenHarmony智能设备集成开发环境推荐使用。<br />[请点击这里获取](https://device.harmonyos.com/cn/develop/ide#download)。 |


## 源码获取


### 前提条件

1. 注册码云gitee帐号。

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

- 从版本分支获取源码。可获取该版本分支的最新源码，包括版本发布后在该分支的合入。
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-4.0.3-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v4.0.3-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**方式二**

通过repo + https 下载。

- 从版本分支获取源码。可获取该版本分支的最新源码，包括版本发布后在该分支的合入。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-4.0.3-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v4.0.3-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```


### 从镜像站点获取


**表2** 获取源码路径

| 版本源码                                | **版本信息** | **下载站点**                                                 | **SHA256校验码**                                             | **软件包容量** |
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| 全量代码（标准、轻量和小型系统）        | 4.0.3Release  | [站点](https://repo.huaweicloud.com/openharmony/os/4.0.3-Release/code-v4.0.3-Release.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0.3-Release/code-v4.0.3-Release.tar.gz.sha256) | 31.5 GB |
| Hi3861解决方案（二进制）        | 4.0.3Release  | [站点](https://repo.huaweicloud.com/openharmony/os/4.0.3-Release/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0.3-Release/hispark_pegasus.tar.gz.sha256) | 25.2 MB |
| Hi3516解决方案-LiteOS（二进制） | 4.0.3Release  | [站点](https://repo.huaweicloud.com/openharmony/os/4.0.3-Release/hispark_taurus_LiteOS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0.3-Release/hispark_taurus_LiteOS.tar.gz.sha256) | 304.1 MB |
| Hi3516解决方案-Linux（二进制）  | 4.0.3Release  | [站点](https://repo.huaweicloud.com/openharmony/os/4.0.3-Release/hispark_taurus_Linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0.3-Release/hispark_taurus_Linux.tar.gz.sha256) | 195.4 MB |
| RK3568标准系统解决方案（二进制）        | 4.0.3Release  | [站点](https://repo.huaweicloud.com/openharmony/os/4.0.3-Release/dayu200_standard_arm32.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0.3-Release/dayu200_standard_arm32.tar.gz.sha256) | 5.2 GB |
| 标准系统Public SDK包（Mac）             | 4.0.12.4 | [站点](https://repo.huaweicloud.com/openharmony/os/4.0.3-Release/ohos-sdk-mac-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0.3-Release/ohos-sdk-mac-public.tar.gz.sha256) | 1.1 GB |
| 标准系统Public SDK包（Mac-M1）             | 4.0.12.4 | [站点](https://repo.huaweicloud.com/openharmony/os/4.0.3-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0.3-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) | 800.7 MB |
| 标准系统Public SDK包（Windows/Linux）   | 4.0.12.4 | [站点](https://repo.huaweicloud.com/openharmony/os/4.0.3-Release/ohos-sdk-windows_linux-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0.3-Release/ohos-sdk-windows_linux-public.tar.gz.sha256) | 2.0 GB |

## 更新说明

本版本在OpenHarmony 4.0.2 Release的基础上有如下变更：


### API变更

- API接口无变更。


### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。


## 修复缺陷列表

**表4** 修复缺陷ISSUE列表

| ISSUE单 | 问题描述 |
| -------- | -------- |
| [I9TEYD](https://e.gitee.com/open_harmony/issues/list?issue=I9TEYD) | 编译轻内核容器测试版本失败           |
| [IAJDXD](https://e.gitee.com/open_harmony/issues/list?issue=IAJDXD) | 出现2次  进程composer_host下的IPC_3_1346线程出现cppcrash，崩溃栈：libdisplay_composer_vdi_impl.z.so |
| [IA7R8Z](https://e.gitee.com/open_harmony/issues/list?issue=IA7R8Z) | 出现1次  进程sensor_host下的sensor_host线程导致libhdf_utils.z.so出现cppcrash |
| [I9UEWK](https://e.gitee.com/open_harmony/issues/list?issue=I9UEWK) | 出现5次  进程audio_host下线程audio_host出现cppcrash，崩溃栈：libhdi_audio_pnp_server.z.so |
| [I97YSN](https://e.gitee.com/open_harmony/issues/list?issue=I97YSN) | NavRouter跳转和退出页面，onStateChange回调不生效 |
| [I93ZB9](https://e.gitee.com/open_harmony/issues/list?issue=I93ZB9) | 安装中sys_installer崩溃,无法返回安装超时，页面卡死 |
| [I9EWLM](https://e.gitee.com/open_harmony/issues/list?issue=I9EWLM) | 设置搜索输入框输入内容过长时会遮挡最右侧叉号                 |
| [I9F3MR](https://e.gitee.com/open_harmony/issues/list?issue=I9F3MR) | 新建信息，删除信息联系人会同步删除下方编辑栏中的短信详情     |
| [I9FQD5](https://e.gitee.com/open_harmony/issues/list?issue=I9FQD5) | 全局动画切换至5X或10X，下载状态栏，状态栏会自动退出          |
| [I9GRCL](https://e.gitee.com/open_harmony/issues/list?issue=I9GRCL) | 当短信对话界面划动到最上面一条，接收到对端发送消息后，短信对话界面不会自动划动回到最新消息的位置 |
| [IAIKP6](https://e.gitee.com/open_harmony/issues/list?issue=IAIKP6) | FileShare中Picker应用、fileFs.ts、show.ets链接失效           |
| [IAFCN5](https://e.gitee.com/open_harmony/issues/list?issue=IAFCN5) | 修复4.0Release UT失败                                        |
| [IAF9R7](https://e.gitee.com/open_harmony/issues/list?issue=IAF9R7) | 4.0release TDD问题挑单                                       |
| [IADVF8](https://e.gitee.com/open_harmony/issues/list?issue=IADVF8) | 使用控制中心打开wifi开关后，设置页显示已成功连接wifi，但控制中心出现短暂未同步显示连接对应wifi |
| [IACY4V](https://e.gitee.com/open_harmony/issues/list?issue=IACY4V) | hmdfs fix skip tls init                                      |

## 修复安全issue列表

**表4** 修复安全issue列表

| ISSUE                                                        | 问题描述                                                    |
| ------------------------------------------------------------ | ----------------------------------------------------------- |
| [IAI3SL](https://e.gitee.com/open_harmony/issues/list?issue=IAI3SL) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-36031         |
| [IAI3YH](https://e.gitee.com/open_harmony/issues/list?issue=IAI3YH) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-42161         |
| [IAI3XW](https://e.gitee.com/open_harmony/issues/list?issue=IAI3XW) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-42154         |
| [IAI3VQ](https://e.gitee.com/open_harmony/issues/list?issue=IAI3VQ) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-41012         |
| [IAI3VA](https://e.gitee.com/open_harmony/issues/list?issue=IAI3VA) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-41087         |
| [IAI3TH](https://e.gitee.com/open_harmony/issues/list?issue=IAI3TH) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-42160         |
| [IAI3SZ](https://e.gitee.com/open_harmony/issues/list?issue=IAI3SZ) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2023-52672         |
| [IAEK1H](https://e.gitee.com/open_harmony/issues/list?issue=IAEK1H) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-39495         |
| [IAI3SZ](https://e.gitee.com/open_harmony/issues/list?issue=IAI3SZ) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2023-52672         |
| [IAEK1H](https://e.gitee.com/open_harmony/issues/list?issue=IAEK1H) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-39495         |
| [IABPBB](https://e.gitee.com/open_harmony/issues/list?issue=IABPBB) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-36971         |
| [IAAC06](https://e.gitee.com/open_harmony/issues/list?issue=IAAC06) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-38577         |
| [IAABZS](https://e.gitee.com/open_harmony/issues/list?issue=IAABZS) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-38588         |
| [IALLOV](https://e.gitee.com/open_harmony/issues/list?issue=IALLOV) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-825178265344806912 |
| [IALD0O](https://e.gitee.com/open_harmony/issues/list?issue=IALD0O) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-826547532216668160 |
| [IAKL82](https://e.gitee.com/open_harmony/issues/list?issue=IAKL82) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-26984         |
| [IAJW6P](https://e.gitee.com/open_harmony/issues/list?issue=IAJW6P) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-41035         |
| [IAJW65](https://e.gitee.com/open_harmony/issues/list?issue=IAJW65) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-41072         |
| [IAJW5Y](https://e.gitee.com/open_harmony/issues/list?issue=IAJW5Y) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-41063         |
| [IAJW5T](https://e.gitee.com/open_harmony/issues/list?issue=IAJW5T) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-35947         |
| [IAJW5L](https://e.gitee.com/open_harmony/issues/list?issue=IAJW5L) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-42115         |
| [IAJW4P](https://e.gitee.com/open_harmony/issues/list?issue=IAJW4P) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-42084         |
| [IAJW4H](https://e.gitee.com/open_harmony/issues/list?issue=IAJW4H) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-42082         |
| [IAJW3M](https://e.gitee.com/open_harmony/issues/list?issue=IAJW3M) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-35884         |
| [IAJW2W](https://e.gitee.com/open_harmony/issues/list?issue=IAJW2W) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-41020         |
| [IAIRKT](https://e.gitee.com/open_harmony/issues/list?issue=IAIRKT) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-26966         |
| [IAIKJM](https://e.gitee.com/open_harmony/issues/list?issue=IAIKJM) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-42084         |
| [IAI79Y](https://e.gitee.com/open_harmony/issues/list?issue=IAI79Y) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-42068         |
| [IAI79K](https://e.gitee.com/open_harmony/issues/list?issue=IAI79K) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-42229         |
| [IAI795](https://e.gitee.com/open_harmony/issues/list?issue=IAI795) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-42226         |
| [IAI3WS](https://e.gitee.com/open_harmony/issues/list?issue=IAI3WS) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-39501         |
| [IAI3W8](https://e.gitee.com/open_harmony/issues/list?issue=IAI3W8) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-40959         |
| [IAI3VH](https://e.gitee.com/open_harmony/issues/list?issue=IAI3VH) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-40960         |
| [IAI3UT](https://e.gitee.com/open_harmony/issues/list?issue=IAI3UT) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2022-48797         |
| [IAI3UM](https://e.gitee.com/open_harmony/issues/list?issue=IAI3UM) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-40961         |
| [IAI3TM](https://e.gitee.com/open_harmony/issues/list?issue=IAI3TM) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-40905         |
| [IAHRT0](https://e.gitee.com/open_harmony/issues/list?issue=IAHRT0) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-40912         |
| [IAFG57](https://e.gitee.com/open_harmony/issues/list?issue=IAFG57) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-36286         |
| [IAFG4Y](https://e.gitee.com/open_harmony/issues/list?issue=IAFG4Y) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-38780         |
| [IAFG4I](https://e.gitee.com/open_harmony/issues/list?issue=IAFG4I) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-36270         |
| [IAE0GE](https://e.gitee.com/open_harmony/issues/list?issue=IAE0GE) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-39475         |
| [IAE0G7](https://e.gitee.com/open_harmony/issues/list?issue=IAE0G7) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2021-47582         |
| [IAE0G0](https://e.gitee.com/open_harmony/issues/list?issue=IAE0G0) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-39472         |
| [IAE0FT](https://e.gitee.com/open_harmony/issues/list?issue=IAE0FT) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-34027         |
| [IAE0FI](https://e.gitee.com/open_harmony/issues/list?issue=IAE0FI) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-36489         |
| [IABPAU](https://e.gitee.com/open_harmony/issues/list?issue=IABPAU) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-38596         |
| [IABPAG](https://e.gitee.com/open_harmony/issues/list?issue=IABPAG) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-38601         |
| [IAAC00](https://e.gitee.com/open_harmony/issues/list?issue=IAAC00) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-38564         |
| [IAA6AF](https://e.gitee.com/open_harmony/issues/list?issue=IAA6AF) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-39276         |
| [IA7RS0](https://e.gitee.com/open_harmony/issues/list?issue=IA7RS0) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-36929         |
| [IA7RRT](https://e.gitee.com/open_harmony/issues/list?issue=IA7RRT) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-36941         |
| [IA7RPQ](https://e.gitee.com/open_harmony/issues/list?issue=IA7RPQ) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-35984         |
| [IA7RPD](https://e.gitee.com/open_harmony/issues/list?issue=IA7RPD) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2023-52730         |
| [IA7A3F](https://e.gitee.com/open_harmony/issues/list?issue=IA7A3F) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2023-52791         |
| [IA74SA](https://e.gitee.com/open_harmony/issues/list?issue=IA74SA) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-36938         |
| [IA74RC](https://e.gitee.com/open_harmony/issues/list?issue=IA74RC) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-36905         |
| [IA74QZ](https://e.gitee.com/open_harmony/issues/list?issue=IA74QZ) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-36902         |
| [IAJW57](https://e.gitee.com/open_harmony/issues/list?issue=IAJW57) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-42236         |
| [IAJW4Y](https://e.gitee.com/open_harmony/issues/list?issue=IAJW4Y) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-41041         |
| [IAI3X0](https://e.gitee.com/open_harmony/issues/list?issue=IAI3X0) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-40942         |
| [IAI3WV](https://e.gitee.com/open_harmony/issues/list?issue=IAI3WV) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-40971         |
| [IAI3WK](https://e.gitee.com/open_harmony/issues/list?issue=IAI3WK) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-39509         |
| [IAHRH2](https://e.gitee.com/open_harmony/issues/list?issue=IAHRH2) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-38615         |
| [IA7RR1](https://e.gitee.com/open_harmony/issues/list?issue=IA7RR1) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2023-52835         |
| [IA7RQC](https://e.gitee.com/open_harmony/issues/list?issue=IA7RQC) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2023-52739         |
| [IA74VS](https://e.gitee.com/open_harmony/issues/list?issue=IA74VS) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2023-52881         |
| [IA74RP](https://e.gitee.com/open_harmony/issues/list?issue=IA74RP) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-36883         |
| [IAHB13](https://e.gitee.com/open_harmony/issues/list?issue=IAHB13) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2022-48805         |

## 遗留缺陷列表

**表5** 遗留缺陷列表

| ISSUE | 问题描述 | 影响 | 计划解决日期 |
| -------- | -------- | -------- | -------- |
| /     | /        | /    | /            |
