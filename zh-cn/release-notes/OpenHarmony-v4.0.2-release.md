# OpenHarmony 4.0.2 Release


## 版本概述

当前版本在OpenHarmony 4.0.1 Release的基础上，修复了内存泄漏及linux kernel等开源组件的安全漏洞，增强了系统安全性。修复了部分功能和系统稳定性的issue，增强了系统稳定性。


## 配套关系

**表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 |
| -------- | -------- | -------- |
| OpenHarmony | 4.0.2 Release | NA |
| Public SDK | Ohos_sdk_public 4.0.11.4 (API Version 10 Release) | 面向应用开发者提供，不包含需要使用系统权限的系统接口。通过DevEco Studio默认获取的SDK为Public SDK。 |
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
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-4.0.2-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v4.0.2-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**方式二**

通过repo + https 下载。

- 从版本分支获取源码。可获取该版本分支的最新源码，包括版本发布后在该分支的合入。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-4.0.2-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v4.0.2-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```


### 从镜像站点获取


**表2** 获取源码路径

| 版本源码                                | **版本信息** | **下载站点**                                                 | **SHA256校验码**                                             | **软件包容量** |
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| 全量代码（标准、轻量和小型系统）        | 4.0.2Release  | [站点](https://repo.huaweicloud.com/openharmony/os/4.0.2-Release/code-v4.0.2-Release.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0.2-Release/code-v4.0.2-Release.tar.gz.sha256) | 30.5 GB |
| Hi3861解决方案（二进制）        | 4.0.2Release  | [站点](https://repo.huaweicloud.com/openharmony/os/4.0.2-Release/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0.2-Release/hispark_pegasus.tar.gz.sha256) | 27.3 MB |
| Hi3516解决方案-LiteOS（二进制） | 4.0.2Release  | [站点](https://repo.huaweicloud.com/openharmony/os/4.0.2-Release/hispark_taurus_LiteOS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0.2-Release/hispark_taurus_LiteOS.tar.gz.sha256) | 302.5 MB |
| Hi3516解决方案-Linux（二进制）  | 4.0.2Release  | [站点](https://repo.huaweicloud.com/openharmony/os/4.0.2-Release/hispark_taurus_Linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0.2-Release/hispark_taurus_Linux.tar.gz.sha256) | 193.2 MB |
| RK3568标准系统解决方案（二进制）        | 4.0.2Release  | [站点](https://repo.huaweicloud.com/openharmony/os/4.0.2-Release/dayu200_standard_arm32.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0.2-Release/dayu200_standard_arm32.tar.gz.sha256) | 5.2 GB |
| 标准系统Public SDK包（Mac）             | 4.0.11.4  | [站点](https://repo.huaweicloud.com/openharmony/os/4.0.2-Release/ohos-sdk-mac-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0.2-Release/ohos-sdk-mac-public.tar.gz.sha256) | 2.0 GB |
| 标准系统Public SDK包（Mac-M1）             | 4.0.11.4 | [站点](https://repo.huaweicloud.com/openharmony/os/4.0.2-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0.2-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) | 800.7 MB |
| 标准系统Public SDK包（Windows/Linux）   | 4.0.11.4  | [站点](https://repo.huaweicloud.com/openharmony/os/4.0.2-Release/ohos-sdk-windows_linux-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0.2-Release/ohos-sdk-windows_linux-public.tar.gz.sha256) | 1.1 GB |

## 更新说明

本版本在OpenHarmony 4.0.1 Release的基础上有如下变更：


### API变更

- API接口无变更。


### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。


## 修复缺陷列表

**表4** 修复缺陷ISSUE列表

| ISSUE单 | 问题描述 |
| -------- | -------- |
| [IA7RFU](https://e.gitee.com/open_harmony/issues/table?issue=IA7RFU) | 【OpenHarmony 4.0.11.3】出现263次  进程composer_host下的IPC_0_583线程出现cppcrash，崩溃栈：libhdf_host.z.so |
| [IA50TF](https://e.gitee.com/open_harmony/issues/table?issue=IA50TF) | 【OpenHarmony 4.0.11.2】出现98次  进程composer_host下的IPC_0_600线程出现cppcrash，崩溃栈：libdisplay_composer_vdi_impl.z.so |
| [IA4VWD](https://e.gitee.com/open_harmony/issues/table?issue=IA4VWD) | 【OpenHarmony  4.0.11.2】出现99次，进程composer_host下的IPC_0_651线程出现cppcrash，崩溃栈：libdisplay_composer_service_1.0.z.so |
| [IA4VOG](https://e.gitee.com/open_harmony/issues/table?issue=IA4VOG) | 【OpenHarmony  4.0.11.2】出现1207次，进程composer_host下的IPC_0_611线程出现cppcrash，崩溃栈：libdisplay_composer_service_1.0.z.so |
| [I9UD63](https://e.gitee.com/open_harmony/issues/table?issue=I9UD63) | 【OpenHarmony 4.0.11.1】出现11次  进程com.ohos.contacts下出现appfreeze，栈名：getTimeDetailByCallTime |
| [I9D96I](https://e.gitee.com/open_harmony/issues/table?issue=I9D96I) | 【OpenHarmony 4.0.10.18】联系人点击搜索框不会自动弹出输入法  |
| [I9BN09](https://e.gitee.com/open_harmony/issues/table?issue=I9BN09) | 【OpenHarmony 4.0.10.18】出现10次 进程com.ohos.photos出现THREAD_BLOCK_6S的appfreeze |
| [I97K8F](https://e.gitee.com/open_harmony/issues/table?issue=I97K8F) | 【OpenHarmony 4.0.10.16】小型系统liteos软总线进程无法启动    |
| [IA8XY1](https://e.gitee.com/open_harmony/issues/table?issue=IA8XY1) | 【OpenHarmony 4.0.11.4】出现1次 进程com.ohos.note下出现jscrash，栈名：isFolderMoveIn |
| [IA8ORN](https://e.gitee.com/open_harmony/issues/table?issue=IA8ORN) | 【OpenHarmony 4.0.11.4】出现17次  由进程softbus_server下的IPC_0_625线程导致libipc_core.z.so出现cppcrash |
| [IA8HPZ](https://e.gitee.com/open_harmony/issues/table?issue=IA8HPZ) | 【OpenHarmony 4.0.11.3】打开设置-WLAN界面后，开关WLAN，设置主界面无法同步WLAN状态 |
| [IA56NT](https://e.gitee.com/open_harmony/issues/table?issue=IA56NT) | 【OpenHarmony 4.0.11.2】出现1次  进程com.ohos.settings下出现jscrash，栈名：unregisterObserver |
| [IA52Z3](https://e.gitee.com/open_harmony/issues/table?issue=IA52Z3) | 【OpenHarmony 4.0.11.2】出现5次  进程composer_host下线程IPC_0_623出现cppcrash，崩溃栈：libclang_rt.ubsan_minimal.so |
| [IA52VP](https://e.gitee.com/open_harmony/issues/table?issue=IA52VP) | 【OpenHarmony 4.0.11.2】出现22次  进程composer_host下的IPC_0_610线程出现cppcrash，崩溃栈：libdisplay_composer_stub_1.0.z.so |
| [IA52OZ](https://e.gitee.com/open_harmony/issues/table?issue=IA52OZ) | 【OpenHarmony 4.0.11.2】出现2次  进程composer_host下的OS_IPC_1_635线程出现cppcrash，崩溃栈：libdisplay_composer_vdi_impl.z.so |
| [IA52FF](https://e.gitee.com/open_harmony/issues/table?issue=IA52FF) | 【OpenHarmony 4.0.11.2】出现1次  进程composer_host下的IPC_1_613线程导致libdisplay_composer_vendor.z.so出现cppcrash |
| [IA5292](https://e.gitee.com/open_harmony/issues/table?issue=IA5292) | 【OpenHarmony 4.0.11.2】出现45次  进程composer_host下的IPC_0_628线程出现cppcrash，崩溃栈：libhdf_ipc_adapter.z.so |
| [IA521D](https://e.gitee.com/open_harmony/issues/table?issue=IA521D) | 【OpenHarmony 4.0.11.2】出现13次  进程composer_host下线程IPC_1_588出现cppcrash，崩溃栈：libhilog.so |
| [IA51QG](https://e.gitee.com/open_harmony/issues/table?issue=IA51QG) | 【OpenHarmony 4.0.11.2】出现3次  进程composer_host下的IPC_1_592线程导致libipc_single.z.so出现cppcrash |
| [IA51KP](https://e.gitee.com/open_harmony/issues/table?issue=IA51KP) | 【OpenHarmony  4.0.11.2】进程com.ohos.settingsdata下的os.settingsdata线程出现cppcrash，崩溃栈：libnative_rdb.z.so |
| [IA51AZ](https://e.gitee.com/open_harmony/issues/table?issue=IA51AZ) | 【OpenHarmony 4.0.11.2】出现11次  进程composer_host下的OS_IPC_1_626线程出现cppcrash，崩溃栈：libdisplay_composer_vdi_impl.z.so |
| [IA513N](https://e.gitee.com/open_harmony/issues/table?issue=IA513N) | 【OpenHarmony 4.0.11.2】出现18次  进程com.ohos.settingsdata下的os.settingsdata线程出现cppcrash，崩溃栈：libnative_appdatafwk.z.so |
| [I9UF1I](https://e.gitee.com/open_harmony/issues/table?issue=I9UF1I) | 【OpenHarmony  4.0.11.1】进程composer_host下线程IPC_1_625出现cppcrash，崩溃栈：libhdifd_parcelable.z.so |
| [I9UESA](https://e.gitee.com/open_harmony/issues/table?issue=I9UESA) | 【OpenHarmony 4.0.11.1】出现1次  进程foundation下线程ffrtwk/CPU-2-0出现cppcrash，崩溃栈：libdlp_permission_sdk.z.so |
| [I9TPH7](https://e.gitee.com/open_harmony/issues/table?issue=I9TPH7) | 【OpenHarmony 4.0.11.1】出现1次 进程com.ohos.photos下出现jscrash，栈名：updateActionBar |
| [I9TNOU](https://e.gitee.com/open_harmony/issues/table?issue=I9TNOU) | 【OpenHarmony 4.0.11.1】hap-sign-tool.jar工具inForm参数不兼容大小写 |
| [I9PITC](https://e.gitee.com/open_harmony/issues/table?issue=I9PITC) | 【OpenHarmony 4.0.10.18】备忘录更改文本缩进后保存退出，再次打开文本无缩进 |
| [I9K8ZD](https://e.gitee.com/open_harmony/issues/table?issue=I9K8ZD) | 【OpenHarmony 4.0.10.18】出现1次  进程device_manager下的TimerRunning线程出现cppcrash，崩溃栈：libdevicemanagerserviceimpl.z.so |
| [I96SJG](https://e.gitee.com/open_harmony/issues/table?issue=I96SJG) | 【OpenHarmony 4.0.10.17】出现1次  进程com.ohos.settings下出现jscrash，栈名：unregisterObserver |
| [I920DA](https://e.gitee.com/open_harmony/issues/table?issue=I920DA) | 【OpenHarmony 4.0.10.16】出现1次 进程com.ohos.systemui下出现jscrash，栈名：AirplaneVM |

## 修复安全issue列表

**表4** 修复安全issue列表

| ISSUE                                                        | 问题描述                                           |
| ------------------------------------------------------------ | -------------------------------------------------- |
| [IA9LC2](https://e.gitee.com/open_harmony/issues/table?issue=IA9LC2) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-36939 |
| [I9PJJN](https://e.gitee.com/open_harmony/issues/table?issue=I9PJJN) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-26733 |
| [I9QZR5](https://e.gitee.com/open_harmony/issues/table?issue=I9QZR5) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-27004 |
| [I9QZC7](https://e.gitee.com/open_harmony/issues/table?issue=I9QZC7) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2023-52467 |
| [I9QZB8](https://e.gitee.com/open_harmony/issues/table?issue=I9QZB8) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-26903 |
| [I9QZ9J](https://e.gitee.com/open_harmony/issues/table?issue=I9QZ9J) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-27399 |
| [I9QW5Y](https://e.gitee.com/open_harmony/issues/table?issue=I9QW5Y) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2023-51794 |
| [I9QW30](https://e.gitee.com/open_harmony/issues/table?issue=I9QW30) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2017-14058 |
| [I9Q65G](https://e.gitee.com/open_harmony/issues/table?issue=I9Q65G) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2023-51793 |
| [I9Q1NE](https://e.gitee.com/open_harmony/issues/table?issue=I9Q1NE) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-26862 |
| [I9Q1MT](https://e.gitee.com/open_harmony/issues/table?issue=I9Q1MT) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2023-52462 |
| [I9OGPC](https://e.gitee.com/open_harmony/issues/table?issue=I9OGPC) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-24863 |
| [I9OEZF](https://e.gitee.com/open_harmony/issues/table?issue=I9OEZF) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-46887 |
| [I9NQVB](https://e.gitee.com/open_harmony/issues/table?issue=I9NQVB) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-26601 |
| [I9JE1E](https://e.gitee.com/open_harmony/issues/table?issue=I9JE1E) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2022-2078  |
| [I9JDLS](https://e.gitee.com/open_harmony/issues/table?issue=I9JDLS) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2021-4001  |
| [I9H4QZ](https://e.gitee.com/open_harmony/issues/table?issue=I9H4QZ) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-0450  |
| [I9FXHF](https://e.gitee.com/open_harmony/issues/table?issue=I9FXHF) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2023-52160 |
| [I9COE3](https://e.gitee.com/open_harmony/issues/table?issue=I9COE3) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2023-52498 |
| [I9BU69](https://e.gitee.com/open_harmony/issues/table?issue=I9BU69) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-25739 |
| [I952TO](https://e.gitee.com/open_harmony/issues/table?issue=I952TO) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-24858 |
| [I950WP](https://e.gitee.com/open_harmony/issues/table?issue=I950WP) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-24857 |
| [IA7RSP](https://e.gitee.com/open_harmony/issues/table?issue=IA7RSP) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2021-47469 |
| [IA7RR1](https://e.gitee.com/open_harmony/issues/table?issue=IA7RR1) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2023-52835 |
| [IA7RQS](https://e.gitee.com/open_harmony/issues/table?issue=IA7RQS) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2023-52879 |
| [IA7RQM](https://e.gitee.com/open_harmony/issues/table?issue=IA7RQM) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2023-52868 |
| [IA7RQC](https://e.gitee.com/open_harmony/issues/table?issue=IA7RQC) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2023-52739 |
| [IA7ROX](https://e.gitee.com/open_harmony/issues/table?issue=IA7ROX) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2023-52869 |
| [IA7AZ7](https://e.gitee.com/open_harmony/issues/table?issue=IA7AZ7) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-35896 |
| [IA7AVQ](https://e.gitee.com/open_harmony/issues/table?issue=IA7AVQ) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2023-52781 |
| [IA7AUA](https://e.gitee.com/open_harmony/issues/table?issue=IA7AUA) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2023-52832 |
| [IA7A6Q](https://e.gitee.com/open_harmony/issues/table?issue=IA7A6Q) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-36017 |
| [IA7A60](https://e.gitee.com/open_harmony/issues/table?issue=IA7A60) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-35822 |
| [IA74VS](https://e.gitee.com/open_harmony/issues/table?issue=IA74VS) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2023-52881 |
| [IA74RP](https://e.gitee.com/open_harmony/issues/table?issue=IA74RP) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-36883 |
| [IA49BH](https://e.gitee.com/open_harmony/issues/table?issue=IA49BH) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-39375 |
| [I9UNOT](https://e.gitee.com/open_harmony/issues/table?issue=I9UNOT) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-4906  |
| [I9QZQO](https://e.gitee.com/open_harmony/issues/table?issue=I9QZQO) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-27038 |
| [I9QZQB](https://e.gitee.com/open_harmony/issues/table?issue=I9QZQB) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-26801 |
| [I9QZCJ](https://e.gitee.com/open_harmony/issues/table?issue=I9QZCJ) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-26923 |
| [I9PJK7](https://e.gitee.com/open_harmony/issues/table?issue=I9PJK7) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-26735 |
| [I9PJJT](https://e.gitee.com/open_harmony/issues/table?issue=I9PJJT) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-26805 |
| [IA4BSA](https://e.gitee.com/open_harmony/issues/table?issue=IA4BSA) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-36899 |
| [IA47RY](https://e.gitee.com/open_harmony/issues/table?issue=IA47RY) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-36904 |
| [I9TCEQ](https://e.gitee.com/open_harmony/issues/table?issue=I9TCEQ) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-26934 |
| [I9TCE6](https://e.gitee.com/open_harmony/issues/table?issue=I9TCE6) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2021-47479 |
| [I9TCBI](https://e.gitee.com/open_harmony/issues/table?issue=I9TCBI) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2021-47506 |
| [I9TCAM](https://e.gitee.com/open_harmony/issues/table?issue=I9TCAM) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2021-47485 |
| [I9TC9P](https://e.gitee.com/open_harmony/issues/table?issue=I9TC9P) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2021-47483 |
| [I9TC7F](https://e.gitee.com/open_harmony/issues/table?issue=I9TC7F) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2021-47474 |
| [I9OU4P](https://e.gitee.com/open_harmony/issues/table?issue=I9OU4P) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-26885 |
| [I9OU4C](https://e.gitee.com/open_harmony/issues/table?issue=I9OU4C) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-26883 |
| [I9OU42](https://e.gitee.com/open_harmony/issues/table?issue=I9OU42) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-26884 |
| [I9OU3J](https://e.gitee.com/open_harmony/issues/table?issue=I9OU3J) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2022-48655 |
| [I9O3RW](https://e.gitee.com/open_harmony/issues/table?issue=I9O3RW) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-31578 |
| [I9JNCO](https://e.gitee.com/open_harmony/issues/table?issue=I9JNCO) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2023-52436 |
| [I9H4LS](https://e.gitee.com/open_harmony/issues/table?issue=I9H4LS) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2023-6597  |
| [IA7RS0](https://e.gitee.com/open_harmony/issues/table?issue=IA7RS0) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-36929 |
| [IA7RRT](https://e.gitee.com/open_harmony/issues/table?issue=IA7RRT) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-36941 |
| [IA7RPQ](https://e.gitee.com/open_harmony/issues/table?issue=IA7RPQ) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-35984 |
| [IA7RPD](https://e.gitee.com/open_harmony/issues/table?issue=IA7RPD) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2023-52730 |
| [IA7ROQ](https://e.gitee.com/open_harmony/issues/table?issue=IA7ROQ) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-36008 |
| [IA7RO9](https://e.gitee.com/open_harmony/issues/table?issue=IA7RO9) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-35997 |
| [IA7BIZ](https://e.gitee.com/open_harmony/issues/table?issue=IA7BIZ) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-36901 |
| [IA7B91](https://e.gitee.com/open_harmony/issues/table?issue=IA7B91) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-36903 |
| [IA7B81](https://e.gitee.com/open_harmony/issues/table?issue=IA7B81) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-35904 |
| [IA7B1I](https://e.gitee.com/open_harmony/issues/table?issue=IA7B1I) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-27414 |
| [IA7B0N](https://e.gitee.com/open_harmony/issues/table?issue=IA7B0N) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-35955 |
| [IA7AY5](https://e.gitee.com/open_harmony/issues/table?issue=IA7AY5) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-35969 |
| [IA7AXC](https://e.gitee.com/open_harmony/issues/table?issue=IA7AXC) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-35962 |
| [IA7AV3](https://e.gitee.com/open_harmony/issues/table?issue=IA7AV3) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-35789 |
| [IA7AT2](https://e.gitee.com/open_harmony/issues/table?issue=IA7AT2) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-36940 |
| [IA7A45](https://e.gitee.com/open_harmony/issues/table?issue=IA7A45) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2023-52803 |
| [IA7A3F](https://e.gitee.com/open_harmony/issues/table?issue=IA7A3F) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2023-52791 |
| [IA74SA](https://e.gitee.com/open_harmony/issues/table?issue=IA74SA) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-36938 |
| [IA74RC](https://e.gitee.com/open_harmony/issues/table?issue=IA74RC) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-36905 |
| [IA74QZ](https://e.gitee.com/open_harmony/issues/table?issue=IA74QZ) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-36902 |
| [IA6W5Z](https://e.gitee.com/open_harmony/issues/table?issue=IA6W5Z) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-48514 |
| [I9RKKZ](https://e.gitee.com/open_harmony/issues/table?issue=I9RKKZ) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-31755 |
| [I9QZSH](https://e.gitee.com/open_harmony/issues/table?issue=I9QZSH) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-26852 |
| [I9QZS8](https://e.gitee.com/open_harmony/issues/table?issue=I9QZS8) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-26901 |

## 遗留缺陷列表

**表5** 遗留缺陷列表

| ISSUE | 问题描述 | 影响 | 计划解决日期 |
| -------- | -------- | -------- | -------- |
| /     | /        | /    | /            |
