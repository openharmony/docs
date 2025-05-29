# OpenHarmony 4.0.4 Release


## 版本概述

当前版本在OpenHarmony 4.0.3 Release的基础上，主要修复了linux kernel等开源组件的安全漏洞，增强了系统安全性。修复了部分功能和系统稳定性的issue，增强了系统稳定性。


## 配套关系

**表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 |
| -------- | -------- | -------- |
| OpenHarmony | 4.0.4 Release | NA |
| Public SDK | Ohos_sdk_public 4.0.13.5 (API Version 10 Release) | 面向应用开发者提供，不包含需要使用系统权限的系统接口。通过DevEco Studio默认获取的SDK为Public SDK。 |
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
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-4.0.4-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v4.0.4-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**方式二**

通过repo + https 下载。

- 从版本分支获取源码。可获取该版本分支的最新源码，包括版本发布后在该分支的合入。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-4.0.4-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v4.0.4-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```


### 从镜像站点获取

**表2** 获取源码路径

| 版本源码                                | **版本信息** | **下载站点**                                                 | **SHA256校验码**                                             | **软件包容量** |
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| 全量代码（标准、轻量和小型系统）        | 4.0.4Release  | [站点](https://repo.huaweicloud.com/openharmony/os/4.0.4-Release/code-v4.0.4-Release.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0.4-Release/code-v4.0.4-Release.tar.gz.sha256) | 32.7 GB |
| Hi3861解决方案（二进制）        | 4.0.4Release  | [站点](https://repo.huaweicloud.com/openharmony/os/4.0.4-Release/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0.4-Release/hispark_pegasus.tar.gz.sha256) | 25.2 MB |
| Hi3516解决方案-LiteOS（二进制） | 4.0.4Release  | [站点](https://repo.huaweicloud.com/openharmony/os/4.0.4-Release/hispark_taurus_LiteOS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0.4-Release/hispark_taurus_LiteOS.tar.gz.sha256) | 304.1 MB |
| Hi3516解决方案-Linux（二进制）  | 4.0.4Release  | [站点](https://repo.huaweicloud.com/openharmony/os/4.0.4-Release/hispark_taurus_Linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0.4-Release/hispark_taurus_Linux.tar.gz.sha256) | 195.9 MB |
| RK3568标准系统解决方案（二进制）        | 4.0.4Release  | [站点](https://repo.huaweicloud.com/openharmony/os/4.0.4-Release/dayu200_standard_arm32.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0.4-Release/dayu200_standard_arm32.tar.gz.sha256) | 5.2 GB |
| 标准系统Public SDK包（Mac）             | 4.0.13.5 | [站点](https://repo.huaweicloud.com/openharmony/os/4.0.4-Release/ohos-sdk-mac-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0.4-Release/ohos-sdk-mac-public.tar.gz.sha256) | 844.9 MB |
| 标准系统Public SDK包（Mac-M1）             | 4.0.13.5 | [站点](https://repo.huaweicloud.com/openharmony/os/4.0.4-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0.4-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) | 797.3 MB |
| 标准系统Public SDK包（Windows/Linux）   | 4.0.13.5 | [站点](https://repo.huaweicloud.com/openharmony/os/4.0.4-Release/ohos-sdk-windows_linux-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0.4-Release/ohos-sdk-windows_linux-public.tar.gz.sha256) | 2.0 GB |

## 更新说明

本版本在OpenHarmony 4.0.3 Release的基础上有如下变更：


### API变更

- API接口无变更。


### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。


## 修复缺陷列表

**表3** 修复缺陷ISSUE列表

| ISSUE单 | 问题描述 |
| -------- | -------- |
| [IATPGT](https://e.gitee.com/open_harmony/issues/list?issue=IATPGT) | acts执行ActsRequestAuthorityTest套件有6个用例fail            |
| [IAWMVO](https://e.gitee.com/open_harmony/issues/list?issue=IAWMVO) | 压力测试出现2次  进程com.ohos.note出现jscrash,栈名：isFolderMoveIn |
| [IAHYHO](https://e.gitee.com/open_harmony/issues/list?issue=IAHYHO) | 照片页手动选中不同日期分类的图片后删除，只能删除已选中图片中日期分类靠前的图片 |
| [IA4OYK](https://e.gitee.com/open_harmony/issues/list?issue=IA4OYK) | 【reboot】压力测试出现1次  进程/system/bin/render_service下的render_service线程出现cppcrash，崩溃栈：librender_service.z.so |
| [I9AS1J](https://e.gitee.com/open_harmony/issues/list?issue=I9AS1J) | swiper组件，修改箭头大小为“100abcd”，箭头大小显示为100vp |
| [IAYMZ8](https://gitee.com/openharmony/applications_hap/issues/IAYMZ8?from=project-issue) | 修复备忘录jscrash |
| [IARU3T](https://gitee.com/openharmony/kernel_linux_5.10/issues/IARU3T?from=project-issue) | 修复hmdfs跨端访问command参数传递错误问题 |
| [IATWYZ](https://gitee.com/openharmony/startup_init/issues/IATWYZ?from=project-issue) | init安全问题修复 4.0-release |
| [IATKYS](https://gitee.com/openharmony/developtools_profiler/issues/IATKYS?from=project-issue) | OpenHarmony-4.0-Release分支host目录告警清理 |
| [I9BPOQ](https://gitee.com/openharmony/third_party_musl/issues/I9BPOQ?from=project-issue) | dlopen_impl函数处理依赖缺失情况时，卸载so处理异常，存在uaf合入4.0 |
| [IAREWW](https://gitee.com/openharmony/kernel_linux_5.10/issues/IAREWW?from=project-issue) | CVE-2024-26686补丁合入引发top命令失败 |
| [IAQYHH](https://gitee.com/openharmony/communication_ipc/issues/IAQYHH?from=project-issue) | 挑单4.0-deviceId匿名化处理 |
| [IAPABG](https://gitee.com/openharmony/filemanagement_dfs_service/issues/IAPABG?from=project-issue) | 代码中有包含用户信息的日志 |
| [IAMISK](https://gitee.com/openharmony/napi_generator/issues/IAMISK?from=project-issue) | napi_generator代码仓的OpenHarmony-4.0-Release分支的静态告警清零 |
| [IAP63C](https://gitee.com/openharmony/arkui_ace_engine/issues/IAP63C?from=project-issue) | 修复plugin加载绝对路径文件错误 |
| [IANK71](https://gitee.com/openharmony/applications_hap/issues/IANK71?from=project-issue) | 图库hap归档，解决按日删除异常问题 |
| [IALIBN](https://gitee.com/openharmony/xts_hats/issues/IALIBN?from=project-issue) | xts_hats/hdf/INPUT模块用例逻辑优化 |
| [IALKY4](https://gitee.com/openharmony/drivers_peripheral/issues/IALKY4?from=project-issue) | audio_manager_service_4.0新增安全编译选项SP-合入特殊分支 |

## 修复安全issue列表

**表4** 修复安全issue列表

| ISSUE                                                        | 问题描述                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [IAW2QM](https://e.gitee.com/open_harmony/issues/list?issue=IAW2QM) | 【漏洞】  【OpenHarmony-4.0-Release】openeuler:expat组件存在漏洞CVE-2024-45492 |
| [IAW2QF](https://e.gitee.com/open_harmony/issues/list?issue=IAW2QF) | 【漏洞】 【OpenHarmony-4.0-Release】openeuler:expat组件存在漏洞CVE-2024-45491 |
| [IAW2QE](https://e.gitee.com/open_harmony/issues/list?issue=IAW2QE) | 【漏洞】 【OpenHarmony-4.0-Release】openeuler:expat组件存在漏洞CVE-2024-45490 |
| [IAX807](https://e.gitee.com/open_harmony/issues/list?issue=IAX807) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-41049          |
| [IAVP6R](https://e.gitee.com/open_harmony/issues/list?issue=IAVP6R) | 【漏洞】 【OpenHarmony-4.0-Release】chromium组件存在漏洞CVE-2024-8636 |
| [IAVP6O](https://e.gitee.com/open_harmony/issues/list?issue=IAVP6O) | 【漏洞】 【OpenHarmony-4.0-Release】chromium组件存在漏洞CVE-2024-7971 |
| [IAVP6M](https://e.gitee.com/open_harmony/issues/list?issue=IAVP6M) | 【漏洞】 【OpenHarmony-4.0-Release】chromium组件存在漏洞CVE-2024-7535 |
| [IAVP6K](https://e.gitee.com/open_harmony/issues/list?issue=IAVP6K) | 【漏洞】 【OpenHarmony-4.0-Release】chromium组件存在漏洞CVE-2024-7255 |
| [IAVLNU](https://e.gitee.com/open_harmony/issues/list?issue=IAVLNU) | 【漏洞】 【OpenHarmony-4.0-Release】wpa supplicant组件存在漏洞CVE-2024-5290 |
| [IAQ16Z](https://e.gitee.com/open_harmony/issues/list?issue=IAQ16Z) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-44987          |
| [IAQ15F](https://e.gitee.com/open_harmony/issues/list?issue=IAQ15F) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-43882          |
| [IAO0XJ](https://e.gitee.com/open_harmony/issues/list?issue=IAO0XJ) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-42305          |
| [IAX89Y](https://e.gitee.com/open_harmony/issues/list?issue=IAX89Y) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-42131          |
| [IAX7YW](https://e.gitee.com/open_harmony/issues/list?issue=IAX7YW) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-26720          |
| [IAX7XZ](https://e.gitee.com/open_harmony/issues/list?issue=IAX7XZ) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-27043          |
| [IAX7X1](https://e.gitee.com/open_harmony/issues/list?issue=IAX7X1) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-26684          |
| [IAX7V8](https://e.gitee.com/open_harmony/issues/list?issue=IAX7V8) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-26627          |
| [IAX7QW](https://e.gitee.com/open_harmony/issues/list?issue=IAX7QW) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-46679          |
| [IAVP6Q](https://e.gitee.com/open_harmony/issues/list?issue=IAVP6Q) | 【漏洞】 【OpenHarmony-4.0-Release】chromium组件存在漏洞CVE-2024-8035 |
| [IAVN2E](https://e.gitee.com/open_harmony/issues/list?issue=IAVN2E) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-46713          |
| [IAUE85](https://e.gitee.com/open_harmony/issues/list?issue=IAUE85) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-45028          |
| [IASJLL](https://e.gitee.com/open_harmony/issues/list?issue=IASJLL) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-832718370087374848  |
| [IAQJNR](https://e.gitee.com/open_harmony/issues/list?issue=IAQJNR) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-45006          |
| [IAQJHL](https://e.gitee.com/open_harmony/issues/list?issue=IAQJHL) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-42276          |
| [IAQ18I](https://e.gitee.com/open_harmony/issues/list?issue=IAQ18I) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-43892          |
| [IAQ16G](https://e.gitee.com/open_harmony/issues/list?issue=IAQ16G) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2022-48877          |
| [IAQ158](https://e.gitee.com/open_harmony/issues/list?issue=IAQ158) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-43871          |
| [IAQ14R](https://e.gitee.com/open_harmony/issues/list?issue=IAQ14R) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-43884          |
| [IAQ12T](https://e.gitee.com/open_harmony/issues/list?issue=IAQ12T) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-43856          |
| [IAQ12G](https://e.gitee.com/open_harmony/issues/list?issue=IAQ12G) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-43828          |
| [IAO0YL](https://e.gitee.com/open_harmony/issues/list?issue=IAO0YL) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-43853          |
| [IAJW36](https://e.gitee.com/open_harmony/issues/list?issue=IAJW36) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-2024-41098          |
| [IAXDG6](https://e.gitee.com/open_harmony/issues/list?issue=IAXDG6) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-844296718181732352  |
| [IAWOD6](https://e.gitee.com/open_harmony/issues/list?issue=IAWOD6) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-844409455574519808  |
| [IAUKDD](https://e.gitee.com/open_harmony/issues/list?issue=IAUKDD) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-840681230440599552  |
| [IAUJWI](https://e.gitee.com/open_harmony/issues/list?issue=IAUJWI) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-840680534400045056  |
| [IAT99G](https://e.gitee.com/open_harmony/issues/list?issue=IAT99G) | 【漏洞】 【OpenHarmony-4.0-Release】 CVE-836801068271669248  |

## 遗留缺陷列表

**表5** 遗留缺陷列表

| ISSUE | 问题描述 | 影响 | 计划解决日期 |
| -------- | -------- | -------- | -------- |
| /     | /        | /    | /            |
