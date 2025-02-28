# OpenHarmony 4.1.3 Release


## 版本概述

当前版本在OpenHarmony 4.1.2 Release的基础上，主要修复了linux kernel等开源组件的安全漏洞，增强了系统安全性。修复了部分功能和系统稳定性的issue，增强了系统稳定性。

## 配套关系

**表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 |
| -------- | -------- | -------- |
| OpenHarmony | 4.1.3 Release | NA |
| Public SDK | Ohos_sdk_public 4.1.9.4 (API Version 11 Release) | 面向应用开发者提供，不包含需要使用系统权限的系统接口。 |
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
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v4.1.3-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**方式二**

通过repo + https 下载。

从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
```
repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v4.1.3-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### 从镜像站点获取


**表2** 获取源码路径

| 版本源码                                | **版本信息** | **下载站点**                                                 | **SHA256校验码**                                             | **软件包容量** |
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| 全量代码（标准、轻量和小型系统）        | 4.1.3 Release   | [站点](https://repo.huaweicloud.com/openharmony/os/4.1.3-Release/code-v4.1.3-Release.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1.3-Release/code-v4.1.3-Release.tar.gz.sha256) | 34.8 GB |
| Hi3861解决方案（二进制）        | 4.1.3 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/4.1.3-Release/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1.3-Release/hispark_pegasus.tar.gz.sha256) | 27.1 MB |
| Hi3516解决方案-LiteOS（二进制） | 4.1.3Release   | [站点](https://repo.huaweicloud.com/openharmony/os/4.1.3-Release/hispark_taurus_LiteOS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1.3-Release/hispark_taurus_LiteOS.tar.gz.sha256) | 320.1 MB |
| Hi3516解决方案-Linux（二进制）  | 4.1.3 Release   | [站点](https://repo.huaweicloud.com/openharmony/os/4.1.3-Release/hispark_taurus_Linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1.3-Release/hispark_taurus_Linux.tar.gz.sha256) | 215.1 MB |
| RK3568标准系统解决方案（二进制）        | 4.1.3 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/4.1.3-Release/dayu200_standard_arm32.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1.3-Release/dayu200_standard_arm32.tar.gz.sha256) | 8.4 GB |
| 标准系统Public SDK包（Mac）             | 4.1.9.4 | [站点](https://repo.huaweicloud.com/openharmony/os/4.1.3-Release/ohos-sdk-mac-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1.3-Release/ohos-sdk-mac-public.tar.gz.sha256) | 913.3 MB |
| 标准系统Public SDK包（Mac-M1）             | 4.1.9.4 | [站点](https://repo.huaweicloud.com/openharmony/os/4.1.3-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1.3-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) | 884.0 MB |
| 标准系统Public SDK包（Windows/Linux）   | 4.1.9.4 | [站点](https://repo.huaweicloud.com/openharmony/os/4.1.3-Release/ohos-sdk-windows_linux-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1.3-Release/ohos-sdk-windows_linux-public.tar.gz.sha256) | 2.2 GB |


## 更新说明

 API接口无变更。

## 修复缺陷和安全问题列表

**表3** 修复缺陷ISSUE列表

| ISSUE单 | 问题描述 |
| -------- | -------- |
| [IAOH0J](https://gitee.com/openharmony/useriam_user_auth_framework/issues/IAOH0J?from=project-issue) | 【RK3568】出现1次进程foundation下的OS_IPC_2_834线程导致libuserauth_client.z.so出现cppcrash |
| [IBE7FX](https://gitee.com/openharmony/third_party_musl/issues/IBE7FX?from=project-issue) | 【RK3568】出现1次 进程foundation下线程OS_IPC_6_936出现cppcrash，崩溃栈：  libdistributed_ability_manager_svr.z.so |
| [IB7TVH](https://gitee.com/openharmony/communication_netmanager_base/issues/IB7TVH?from=project-issue) | 【RK3568】出现2次 进程Process  name:foundation下的OS_IPC_2_784线程出现cppcrash，崩溃栈：libnet_manager_common.z.so |
| [IBBNLR](https://gitee.com/openharmony/commonlibrary_ets_utils/issues/IBBNLR?from=project-issue) | 【RK3568】修复worker内存泄漏                                 |
| [IAPG6G](https://gitee.com/openharmony/filemanagement_dfs_service/issues/IAPG6G?from=project-issue) | 【RK3568】cloudfileservice非常驻进程，被wifi扫描事件循环拉起 |
| [IAAB5R](https://gitee.com/openharmony/arkui_ace_engine/issues/IAAB5R?from=project-issue) | 【RK3568】【必现10/10】设置.enabled(false)的可编辑组件，拖拽到文本类组件区域，组件跟手位置顶部居中8vp |
| [I9BKLO](https://gitee.com/openharmony/applications_mms/issues/I9BKLO?from=project-issue) | 【RK3568】出现2次 进程com.ohos.mms下出现jscrash，栈名：nameClick |
| [IAVSNL](https://gitee.com/openharmony/web_webview/issues/IAVSNL?from=project-issue) | 【RK3568】处理edm事件时对uid进行校验                         |
| [IBH4N7](https://gitee.com/openharmony/distributedhardware_device_manager/issues/IBH4N7?from=project-issue) | 【RK3568】4.1release分支UX修改                               |
| [IBJL5T](https://gitee.com/openharmony/web_webview/issues/IBJL5T?from=project-issue) | 【RK3568】安装nodelesses.hap进行同层渲染测试，渲染功能完全不可用 |
| [IBJ6EC](https://gitee.com/openharmony/arkcompiler_ets_runtime/issues/IBJ6EC?from=project-issue) | 【RK3568】Cherry-Pick 10577 to 4.1 Release                   |
| [IBJ7R4](https://gitee.com/openharmony/arkcompiler_ets_runtime/issues/IBJ7R4?from=project-issue) | 【RK3568】Cherry-Pick 10642 to 4.1 Release                   |
| [IBKK6D](https://gitee.com/openharmony/arkcompiler_ets_runtime/issues/IBKK6D?from=project-issue) | 【RK3568】Cherry-Pick PR 10501 to 4.1 Release Join 问题      |
| [IBJ90O](https://gitee.com/openharmony/arkcompiler_ets_runtime/issues/IBJ90O?from=project-issue) | 【RK3568】Cherry-pick 10670 to 4.1Release                    |
| [IBH1E9](https://gitee.com/openharmony/window_window_manager/issues/IBH1E9?from=project-issue) | 【RK3568】出现2次  进程foundation下的OS_FFRT_2_0线程出现cppcrash，崩溃栈：libmodal_system_ui_extension_client.z.so |
| [IBIZ14](https://gitee.com/openharmony/arkcompiler_ets_runtime/issues/IBIZ14?from=project-issue) | 【RK3568】漏洞合入OpenHarmony-4.1-Release分支                |
| [IBIWKU](https://gitee.com/openharmony/arkcompiler_ets_runtime/issues/IBIWKU?from=project-issue) | 【RK3568】Cherry-Pick bug fix to 4.1                         |
| [IBI74E](https://gitee.com/openharmony/communication_dsoftbus/issues/IBI74E?from=project-issue) | 【RK3568】修复风险漏洞                                       |
| [IBGUBD](https://gitee.com/openharmony/applications_app_samples/issues/IBGUBD?from=project-issue) | 【RK3568】WorkScheduler 去除冗余二进制文件                   |
| [IBGHNE](https://gitee.com/openharmony/applications_app_samples/issues/IBGHNE?from=project-issue) | 【RK3568】HapBuild 升级项目依赖版本&删除冗余文件&替换签名工具 |
| [IBGJHO](https://gitee.com/openharmony/arkui_ace_engine/issues/IBGJHO?from=project-issue) | 【RK3568】设置.enabled(false)的可编辑组件，拖拽到文本类组件区域，组件跟手位置顶部居中8vp |

**表4** 修复安全问题列表

| ISSUE单                                                      | 问题描述                                                     |
| :----------------------------------------------------------- | ------------------------------------------------------------ |
| [IBHYAM](https://gitee.com/openharmony/arkcompiler_ets_runtime/issues/IBHYAM?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】  CVE-871978016102682624 |
| [IBISRC](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBISRC?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2024-56605 |
| [IBLGDX](https://gitee.com/openharmony/third_party_NuttX/issues/IBLGDX?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】 CVE-884973832148881408  |
| [IBISTN](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBISTN?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2024-56647 |
| [IBISOU](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBISOU?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2024-56583 |
| [IBISPT](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBISPT?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2024-53171 |
| [IBISSV](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBISSV?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2024-56606 |
| [IBISUH](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBISUH?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2024-56658 |
| [IBISV2](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBISV2?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2024-56688 |
| [IBISWH](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBISWH?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2024-56692 |
| [IBISXD](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBISXD?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2024-56720 |
| [IBISYG](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBISYG?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2024-56739 |
| [IBISZC](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBISZC?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2024-56756 |
| [IBIT1N](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBIT1N?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2024-56763 |
| [IBIT2H](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBIT2H?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2024-56769 |
| [IBIT3K](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBIT3K?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2024-56770 |
| [IBK84G](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBK84G?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】4.1-Release回合cve补丁   |
| [IBJSHR](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBJSHR?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2024-53173 |
| [IBJSIV](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBJSIV?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2024-56369 |
| [IBKPCV](https://gitee.com/openharmony/kernel_liteos_a/issues/IBKPCV?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】 CVE-887050703653048320  |
| [IBINMH](https://gitee.com/openharmony/communication_dsoftbus/issues/IBINMH?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】 CVE-871975948294033408  |
| [IBINMC](https://gitee.com/openharmony/communication_dsoftbus/issues/IBINMC?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】 CVE-871976081169584128  |
| [IBG37W](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBG37W?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】回合cve补丁              |
| [IBIKDC](https://gitee.com/openharmony/kernel_liteos_a/issues/IBIKDC?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】CVE-879923376297086976   |
| [IBI1JO](https://gitee.com/openharmony/communication_dsoftbus/issues/IBI1JO?from=project-issue) | 【漏洞】  【OpenHarmony-4.1-Release】Disc_ble.c中RecvMessageDeinit未加锁处理，disc_manager.c中未做上限处理，存在安全风险 |
| [IBHTM4](https://gitee.com/openharmony/kernel_liteos_a/issues/IBHTM4?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】CVE-879883602844717056   |
| [IBFEJ7](https://gitee.com/openharmony/applications_app_samples/issues/IBFEJ7?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】发现引用了有问题的axios 1.6.2版本 |
| [IBFEWO](https://gitee.com/openharmony/applications_app_samples/issues/IBFEWO?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】发现引用了有问题的body-parser版本1.20.1、1.20.2 |
| [IBFF0F](https://gitee.com/openharmony/applications_app_samples/issues/IBFF0F?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】4.1 release 分支发现引用了有问题的braces(dev) 3.0.2版本 |
| [IBGB67](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBGB67?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】CVE 同步                 |
| [IB8M92](https://gitee.com/openharmony/kernel_linux_5.10/issues/IB8M92?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2024-50256 |
| [IB8L2B](https://gitee.com/openharmony/kernel_linux_5.10/issues/IB8L2B?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2024-38594 |
| [IBE44O](https://gitee.com/openharmony/kernel_linux_5.10/issues/IBE44O?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】回合cve补丁              |
| [IBERYF](https://gitee.com/openharmony/kernel_liteos_a/issues/IBERYF?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】 CVE-873354661225041920  |
| [IBEB48](https://gitee.com/openharmony/kernel_liteos_a/issues/IBEB48?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】 CVE-872272903297568768  |
| [IBDWNM](https://gitee.com/openharmony/kernel_liteos_a/issues/IBDWNM?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】 CVE-871586908591886336  |
| [IBJESO](https://gitee.com/openharmony/third_party_openssl/issues/IBJESO?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】CVE-2024-13176           |
| [IBFN54](https://gitee.com/openharmony-sig/chromium_src/issues/IBFN54?from=project-issue) | 【漏洞】 【OpenHarmony-4.1-Release】CVE-2023-6112            |

## 遗留缺陷列表

**表5** 遗留缺陷列表

| ISSUE | 问题描述 | 影响 | 计划解决日期 |
| :------- | :------- | :------- | :------- |
| / | /        | /    | /            |
