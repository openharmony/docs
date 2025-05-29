# OpenHarmony 4.1.4 Release


## 版本概述

当前版本在OpenHarmony 4.1.3 Release的基础上，主要修复了linux kernel等开源组件的安全漏洞，增强了系统安全性。修复了部分功能和系统稳定性的issue，增强了系统稳定性。

## 配套关系

**表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 |
| -------- | -------- | -------- |
| OpenHarmony | 4.1.4 Release | NA |
| Public SDK | Ohos_sdk_public 4.1.10.5 (API Version 11 Release) | 面向应用开发者提供，不包含需要使用系统权限的系统接口。 |
| HUAWEI DevEco Studio（可选） | 4.1 Release | OpenHarmony应用开发推荐使用。获取方式：<br />[Windows(64-bit)](https://contentcenter-vali-drcn.dbankcdn.cn/pvt_2/DeveloperAlliance_package_901_9/ee/v3/HqJ-6O2FQny86xtk_dg9HQ/devecostudio-windows-4.1.0.400.zip?HW-CC-KV=V1&HW-CC-Date=20240409T033730Z&HW-CC-Expire=315360000&HW-CC-Sign=BFA444BC43A041331E695AE2CFA9035A957AF107E06C97E793FD3D31D7096A0D)  <br />SHA256校验码：c46be4f3cfde27af1806cfc9860d9c366e66a20e31e15180cf3a90ab05464650<br />[Mac(X86)](https://contentcenter-vali-drcn.dbankcdn.cn/pvt_2/DeveloperAlliance_package_901_9/3b/v3/JgGp8n0bShOkm1MpBFJ73w/devecostudio-mac-4.1.0.400.zip?HW-CC-KV=V1&HW-CC-Date=20240409T034037Z&HW-CC-Expire=315360000&HW-CC-Sign=35C1F8B3FC19325EBBC32D8E11106DDB074A8ECC6BB3A77FF2EADBA2A8A223DA)  <br />SHA256校验码：15d6136959b715e4bb2160c41d405b889820ea26ceadbb416509a43e59ed7f09<br />[Mac(ARM)](https://contentcenter-vali-drcn.dbankcdn.cn/pvt_2/DeveloperAlliance_package_901_9/21/v3/D7Jy1StbTwSLUXaA20VrAw/devecostudio-mac-arm-4.1.0.400.zip?HW-CC-KV=V1&HW-CC-Date=20240409T034235Z&HW-CC-Expire=315360000&HW-CC-Sign=19598AAC650D2AB24CAC6DFDF0DBD312188FB0438A8233B7687E6ACDC43A51F8)  <br />SHA256校验码：ac04ca7c2344ec8f27531d5a59261ff037deed2c5a3d42ef88e6f90f4ed45484 |
| HUAWEI DevEco Device Tool（可选） | 4.0 Release | OpenHarmony智能设备集成开发环境推荐使用。<br />[请点击这里获取](https://device.harmonyos.com/cn/develop/ide#download)。  |


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


从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
```
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v4.1.4-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**方式二**

通过repo + https 下载。

从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
```
repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v4.1.4-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### 从镜像站点获取


**表2** 获取源码路径

| 版本源码                                | **版本信息** | **下载站点**                                                 | **SHA256校验码**                                             | **软件包容量** |
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| 全量代码（标准、轻量和小型系统）        | 4.1.4 Release  | [站点](https://repo.huaweicloud.com/openharmony/os/4.1.4-Release/code-v4.1.4-Release.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1.4-Release/code-v4.1.4-Release.tar.gz.sha256) | 36.4 GB |
| Hi3861解决方案（二进制）        | 4.1.4 Release   | [站点](https://repo.huaweicloud.com/openharmony/os/4.1.4-Release/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1.4-Release/hispark_pegasus.tar.gz.sha256) | 27.1 MB |
| Hi3516解决方案-LiteOS（二进制） | 4.1.4 Release | [站点](https://repo.huaweicloud.com/openharmony/os/4.1.4-Release/hispark_taurus_LiteOS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1.4-Release/hispark_taurus_LiteOS.tar.gz.sha256) | 320.2 MB |
| Hi3516解决方案-Linux（二进制）  | 4.1.4 Release  | [站点](https://repo.huaweicloud.com/openharmony/os/4.1.4-Release/hispark_taurus_Linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1.4-Release/hispark_taurus_Linux.tar.gz.sha256) | 215.1 MB |
| RK3568标准系统解决方案（二进制）        | 4.1.4 Release   | [站点](https://repo.huaweicloud.com/openharmony/os/4.1.4-Release/dayu200_standard_arm32.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1.4-Release/dayu200_standard_arm32.tar.gz.sha256) | 8.4 GB |
| 标准系统Public SDK包（Mac）             | 4.1.10.5 | [站点](https://repo.huaweicloud.com/openharmony/os/4.1.4-Release/ohos-sdk-mac-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1.4-Release/ohos-sdk-mac-public.tar.gz.sha256) | 913.3 MB |
| 标准系统Public SDK包（Mac-M1）             | 4.1.10.5 | [站点](https://repo.huaweicloud.com/openharmony/os/4.1.4-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1.4-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) | 884.0 MB |
| 标准系统Public SDK包（Windows/Linux）   | 4.1.10.5 | [站点](https://repo.huaweicloud.com/openharmony/os/4.1.4-Release/ohos-sdk-windows_linux-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1.4-Release/ohos-sdk-windows_linux-public.tar.gz.sha256) | 2.2 GB |


## 更新说明

 API接口无变更。

## 修复缺陷和安全问题列表

**表3** 修复缺陷ISSUE列表

| ISSUE单 | 问题描述 |
| -------- | -------- |
| [IC3RPF](https://gitee.com/openharmony/communication_dsoftbus/issues/IC3RPF?from=project-issue) | fix:Add null detection and  deinit                           |
| [IC4D1Q](https://gitee.com/openharmony/communication_ipc/issues/IC4D1Q?from=project-issue) | IPC安全问题挑单                                              |
| [IC4FOW](https://gitee.com/openharmony/communication_dsoftbus/issues/IC4FOW?from=project-issue) | 【分布式软总线】传输代码安全漏洞需修复                       |
| [IBLSXD](https://gitee.com/openharmony-sig/security_security_component_manager/issues/IBLSXD?from=project-issue) | 安全控件scId重复使用漏洞                                     |
| [IC2SOO](https://gitee.com/openharmony/kernel_linux_5.10/issues/IC2SOO?from=project-issue) | 代码回合4.1                                                  |
| [IC2V5S](https://gitee.com/openharmony/communication_ipc/issues/IC2V5S?from=project-issue) | RemoteObjectTranslateWhenRcv问题同步回合4.1                  |
| [IC1FQC](https://gitee.com/openharmony/arkui_ace_engine/issues/IC1FQC?from=project-issue) | 安全编码问题_0415                                            |
| [IC179F](https://gitee.com/openharmony/arkui_ace_engine/issues/IC179F?from=project-issue) | scrollbar编译告警修改                                        |
| [IC14FS](https://gitee.com/openharmony/arkui_ace_engine/issues/IC14FS?from=project-issue) | Dialog数组越界                                               |
| [IBYLBN](https://gitee.com/openharmony/developtools_syscap_codec/issues/IBYLBN?from=project-issue) | 修复栈溢出问题4.1                                            |
| [IBTUSR](https://gitee.com/openharmony/arkcompiler_ets_runtime/issues/IBTUSR?from=project-issue) | 3个漏洞修复代码挑单合入4.1                                   |
| [IBGXUO](https://gitee.com/openharmony/filemanagement_dfs_service/issues/IBGXUO?from=project-issue) | 【RK3568】cloudfileservice进程被 相机录像事件拉起之后不会自动退出 |
| [IBT30S](https://gitee.com/openharmony/multimedia_av_codec/issues/IBT30S?from=project-issue) | fix nullptr bug in 4.1 branch                                |
| [IBQY5G](https://gitee.com/openharmony/arkui_ace_engine/issues/IBQY5G?from=project-issue) | fixFDLeak问题挑单                                            |
| [IBQTJP](https://gitee.com/openharmony/bundlemanager_bundle_framework/issues/IBQTJP?from=project-issue) | 元服务免安装多线程问题修复挑4.1                              |
| [IBR3V5](https://gitee.com/openharmony/communication_dsoftbus/issues/IBR3V5?from=project-issue) | 【分布式软总线】【传输】fd泄露优化                           |
| [IBP0R4](https://gitee.com/openharmony/startup_init/issues/IBP0R4?from=project-issue) | init_group_manager.c中数组越界问题整改 4.1-release           |

**表4** 修复安全问题列表

| ISSUE单                                                      | 问题描述                                                     |
| :----------------------------------------------------------- | ------------------------------------------------------------ |
| [IC50QY](https://gitee.com/openharmony/kernel_linux_5.10/issues/IC50QY?from=project-issue) | 【漏洞】  4.1-Release CVE补丁同步                            |
| [IBXXSV](https://gitee.com/openharmony/third_party_freetype/issues/IBXXSV?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】openeuler:freetype组件存在漏洞CVE-2025-27363 |
| [IC1YRZ](https://gitee.com/openharmony/kernel_linux_5.10/issues/IC1YRZ?from=project-issue) | 【漏洞】 4.1-Release CVE同步                                 |
| [IBXXSW](https://gitee.com/openharmony/third_party_skia/issues/IBXXSW?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】openeuler:expat组件存在漏洞CVE-2024-8176 |
| [IBXWML](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBXWML?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2024-57981 |
| [IBXWN5](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBXWN5?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2025-21764 |
| [IBXWNB](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBXWNB?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2025-21785 |
| [IBT0OJ](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBT0OJ?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2022-48657 |
| [IBT0UG](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBT0UG?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2024-57798 |
| [IBT0XE](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBT0XE?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2024-57884 |
| [IBT0Z1](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBT0Z1?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2024-57888 |
| [IBT0ZN](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBT0ZN?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2024-57913 |
| [IBT11B](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBT11B?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2024-58005 |
| [IBT12A](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBT12A?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2025-21648 |
| [IBT12Y](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBT12Y?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2025-21728 |
| [IBT13J](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBT13J?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2025-21814 |
| [IBXWM0](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBXWM0?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2022-49046 |
| [IBXWM2](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBXWM2?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2022-49135 |
| [IBXWM4](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBXWM4?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2022-49443 |
| [IBXWM6](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBXWM6?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2022-49630 |
| [IBXWM7](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBXWM7?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2022-49632 |
| [IBXWMB](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBXWMB?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2022-49651 |
| [IBXWMC](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBXWMC?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2024-57977 |
| [IBXWMJ](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBXWMJ?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2024-57980 |
| [IBXWMP](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBXWMP?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2024-58017 |
| [IBXWMQ](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBXWMQ?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2024-58020 |
| [IBXWMT](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBXWMT?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2024-58058 |
| [IBXWMY](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBXWMY?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2025-21760 |
| [IBXWN1](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBXWN1?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2025-21762 |
| [IBXWN7](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBXWN7?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2025-21776 |
| [IBW4JQ](https://gitee.com/openharmony/kernel_liteos_m/issues/IBW4JQ?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】 vul-901221769187168256  |
| [IBZWP0](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBZWP0?from=project-issue) | 【漏洞】 master CVE同步至4.1-Release                         |
| [IBZA9I](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBZA9I?from=project-issue) | 【漏洞】 master CVE同步至4.1-Release                         |
| [IBVOLV](https://gitee.com/openharmony/web_webview/issues/IBVOLV?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】 vul-901929006431997952  |
| [IBY0M9](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBY0M9?from=project-issue) | 【漏洞】 4.1-Release CVE同步                                 |
| [IBWHEH](https://gitee.com/openharmony/kernel_liteos_a/issues/IBWHEH?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】 vul-905293076359024640  |
| [IBWHG7](https://gitee.com/openharmony/kernel_liteos_a/issues/IBWHG7?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】 vul-905292975204995072  |
| [IBWHIW](https://gitee.com/openharmony/kernel_liteos_a/issues/IBWHIW?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】 vul-905292389982146560  |
| [IBT05Z](https://gitee.com/openharmony/third_party_cJSON/issues/IBT05Z?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】third_party_cJSONl组件存在漏洞CVE-2024-31755 |
| [IBRFCU](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBRFCU?from=project-issue) | 【漏洞】 4.1-release CVE同步                                 |
| [IBIH4L](https://gitee.com/openharmony/arkcompiler_ets_runtime/issues/IBIH4L?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】 CVE-864686037719322624  |
| [IBIH4V](https://gitee.com/openharmony/arkcompiler_ets_runtime/issues/IBIH4V?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】 CVE-864685912552902656  |

## 遗留缺陷列表

**表5** 遗留缺陷列表

| ISSUE | 问题描述 | 影响 | 计划解决日期 |
| :------- | :------- | :------- | :------- |
| / | /        | /    | /            |
