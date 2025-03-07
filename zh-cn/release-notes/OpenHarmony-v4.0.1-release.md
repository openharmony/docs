# OpenHarmony 4.0.1 Release


## 版本概述

当前版本在OpenHarmony 4.0 Release的基础上，修复了部分功能问题、内存泄漏问题及开源组件的安全漏洞，增强了系统安全性。修复了部分系统稳定性的issue，增强了系统稳定性。更新配套的SDK版本。


## 配套关系

**表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 |
| -------- | -------- | -------- |
| OpenHarmony | 4.0.1 Release | NA |
| Public SDK | Ohos_sdk_public 4.0.10.19 (API Version 10 Release) | 面向应用开发者提供，不包含需要使用系统权限的系统接口。通过DevEco Studio默认获取的SDK为Public SDK。 |
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
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-4.0.1-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v4.0.1-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**方式二**

通过repo + https 下载。

- 从版本分支获取源码。可获取该版本分支的最新源码，包括版本发布后在该分支的合入。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-4.0.1-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v4.0.1-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```


### 从镜像站点获取


**表2** 获取源码路径

| 版本源码                                | **版本信息** | **下载站点**                                                 | **SHA256校验码**                                             | **软件包容量** |
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| 全量代码（标准、轻量和小型系统）        | 4.0.1 Release  | [站点](https://repo.huaweicloud.com/openharmony/os/4.0.1-Release/code-v4.0.1-Release.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0.1-Release/code-v4.0.1-Release.tar.gz.sha256) | 30.5 GB |
| Hi3861解决方案（二进制）        | 4.0.1 Release  | [站点](https://repo.huaweicloud.com/openharmony/os/4.0.1-Release/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0.1-Release/hispark_pegasus.tar.gz.sha256) | 27.3 MB |
| Hi3516解决方案-LiteOS（二进制） | 4.0.1 Release  | [站点](https://repo.huaweicloud.com/openharmony/os/4.0.1-Release/hispark_taurus_LiteOS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0.1-Release/hispark_taurus_LiteOS.tar.gz.sha256) | 302.5 MB |
| Hi3516解决方案-Linux（二进制）  | 4.0.1 Release  | [站点](https://repo.huaweicloud.com/openharmony/os/4.0.1-Release/hispark_taurus_Linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0.1-Release/hispark_taurus_Linux.tar.gz.sha256) | 193.2 MB |
| RK3568标准系统解决方案（二进制）        | 4.0.1 Release  | [站点](https://repo.huaweicloud.com/openharmony/os/4.0.1-Release/dayu200_standard_arm32.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0.1-Release/dayu200_standard_arm32.tar.gz.sha256) | 5.2 GB |
| 标准系统Public SDK包（Mac）             | 4.0.10.19     | [站点](https://repo.huaweicloud.com/openharmony/os/4.0.1-Release/ohos-sdk-mac-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0.1-Release/ohos-sdk-mac-public.tar.gz.sha256) | 2.0 GB |
| 标准系统Public SDK包（Mac-M1）             | 4.0.10.19    | [站点](https://repo.huaweicloud.com/openharmony/os/4.0.1-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0.1-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) | 800.7 MB |
| 标准系统Public SDK包（Windows/Linux）   | 4.0.10.19     | [站点](https://repo.huaweicloud.com/openharmony/os/4.0.1-Release/ohos-sdk-windows_linux-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.0.1-Release/ohos-sdk-windows_linux-public.tar.gz.sha256) | 1.1 GB |

## 更新说明

本版本在OpenHarmony 4.0 Release的基础上有如下变更：

### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。


## 修复缺陷列表

**表3** 修复缺陷ISSUE列表

| ISSUE单 | 问题描述 |
| -------- | -------- |
| [I7BF3M](https://gitee.com/open_harmony/dashboard?issue_id=I7BF3M) | 【OpenHarmony  4.0.7.5】出现194次，launcher由于STRINGID:APPLICATION_BLOCK_INPUT卡在libeventhandler.z.so出现Appfreeze |
| [I7BFAQ](https://gitee.com/open_harmony/dashboard?issue_id=I7BFAQ) | 【OpenHarmony 4.0.9.5】出现8次  由进程com.ohos.photos下的RSRenderThread线程导致librender_service_base.z.so出现cppcrash |
| [I7BFCE](https://gitee.com/open_harmony/dashboard?issue_id=I7BFCE) | 【OpenHarmony 4.0.9.5】出现8次  由进程com.ohos.mms下的com.ohos.mms线程导致librender_service_base.z.so出现cppcrash |
| [I7HZKG](https://gitee.com/open_harmony/dashboard?issue_id=I7HZKG) | 【OpenHarmony 4.0.8.3】出现10次  进进msdp下的RSRenderThread线程导致libskia_canvaskit.z.so出现cppcrash |
| [I7QP4W](https://gitee.com/open_harmony/dashboard?issue_id=I7QP4W) | 【OpenHarmony 4.0.9.6】出现10次 进程com.ohos.mms下出现jscrash，栈名：setShowContactName |
| [I7QPBJ](https://gitee.com/open_harmony/dashboard?issue_id=I7QPBJ) | 【OpenHarmony 4.0.9.6】出现24次  进程com.ohos.mms下出现jscrash，栈名：setReceiveContactValue |
| [I7RBGF](https://gitee.com/open_harmony/dashboard?issue_id=I7RBGF) | 【OpenHarmony 4.0.9.6】出现202次  进程com.ohos.camera由于THREAD_BLOCK_6S卡在libsamgr_proxy.z.so出现appfreeze |
| [I7RSJJ](https://gitee.com/open_harmony/dashboard?issue_id=I7RSJJ) | 【OpenHarmony 4.0.10.1】出现12次  进程media_service下的PlayerEngine线程导致libgstreamer.z.so出现cppcrash |
| [I7S75S](https://gitee.com/open_harmony/dashboard?issue_id=I7S75S) | 【OpenHarmony 4.0.10.1】出现8次  进程wifi_manager_se下的IPC_1_28750线程导致libipc_core.z.so出现cppcrash |
| [I7SAIU](https://gitee.com/open_harmony/dashboard?issue_id=I7SAIU) | 【OpenHarmony 4.0.10.1】出现12次  进程com.ohos.photos下的com.ohos.photos线程出现cppcrash，崩溃栈：librender_service_base.z.so |
| [I7SCU4](https://gitee.com/open_harmony/dashboard?issue_id=I7SCU4) | 【OpenHarmony 4.0.10.1】出现20次  进程com.ohos.photos由于THREAD_BLOCK_6S卡在libark_jsruntime.so出现appfreeze |
| [I7TGTW](https://gitee.com/open_harmony/dashboard?issue_id=I7TGTW) | 【OpenHarmony 4.0.10.2】出现443次  进程com.ohos.photos下的com.ohos.photos线程出现cppcrash，崩溃栈：libace.z.so |
| [I7UUBH](https://gitee.com/open_harmony/dashboard?issue_id=I7UUBH) | 【OpenHarmony  4.0.10.3】【应用子系统】【ToC】【RK3568】【高概率-5/10】在设置应用里快速多次打开关闭飞行模式，设置里的WLAN是关闭的，但是控制中心WLAN图标依然是点亮状态 |
| [I7VBL8](https://gitee.com/open_harmony/dashboard?issue_id=I7VBL8) | 【OpenHarmony 4.0.10.3】出现8次  进程com.ohos.contactsdataability下的IPC_0_20828线程导致libcontactsdataability.z.so出现cppcrash |
| [I7X7N7](https://gitee.com/open_harmony/dashboard?issue_id=I7X7N7) | 【OpenHarmony 4.0.10.3】出现11次  进程render_service下IPC_0_645线程的libsurface.z.so出现cppcrash |
| [I7XKYN](https://gitee.com/open_harmony/dashboard?issue_id=I7XKYN) | 【OpenHarmony 4.0.10.5】出现6次  进程com.ohos.note下的com.ohos.note线程出现cppcrash，崩溃栈：libweb_engine.so |
| [I7YRQG](https://gitee.com/open_harmony/dashboard?issue_id=I7YRQG) | 【OpenHarmony_4.0.10.6】【USB服务子系统】【ToC】【RK3568】【必现】hdi接口的test_request测试套执行8条后中断 |
| [I814ML](https://gitee.com/open_harmony/dashboard?issue_id=I814ML) | 【OpenHarmony 4.0.10.6】出现22次  进程media_service下的IPC_0_648线程导致libmedia_service.z.so出现cppcrash |
| [I815FD](https://gitee.com/open_harmony/dashboard?issue_id=I815FD) | 【OpenHarmony 4.0.10.6】出现14次  进程/system/bin/hdcd下的ffrtwk/CPU-2-0线程出现cppcrash |
| [I82CA5](https://gitee.com/open_harmony/dashboard?issue_id=I82CA5) | 【OpenHarmony 4.0.10.7】出现15次  进程wifi_manager_se下的IPC_4_12571线程导致libipc_core.z.so出现cppcrash |
| [I82Q8W](https://gitee.com/open_harmony/dashboard?issue_id=I82Q8W) | 【OpenHarmony 4.0.10.7】出现8次  进程com.ohos.smartperf下的WorkerThread线程导致libsocket.z.so出现cppcrash |
| [I81MUU](https://gitee.com/open_harmony/dashboard?issue_id=I81MUU) | 【OpenHarmony  4.0.10.7】【RK3568】【压力测试】【ToC】【必现10/10】反复进入某相册的图片宫格浏览界面出现泄漏，8小时涨到200M |
| [I82DBO](https://gitee.com/open_harmony/dashboard?issue_id=I82DBO) | 【OpenHarmony  4.0.10.7】【RK3568】【压力测试】【ToC】【必现10/10】进入设置反复打开关闭wifi开关出现泄漏,2小时泄露50 |
| [I82HFQ](https://gitee.com/open_harmony/dashboard?issue_id=I82HFQ) | 【OpenHarmony 4.0.10.7sp5】出现50次  进程ohos.samples.distributedmusicplayer由于UI_BLOCK_6S卡在libmedia_client.z.so发生appfreeze |
| [I82J4V](https://gitee.com/open_harmony/dashboard?issue_id=I82J4V) | 【OpenHarmony 4.0.10.7】【RK3568】【压力测试】【ToC】【高概率】【手工】来回拖动图标几乎必现  进程msdp下的RSRenderThread线程出现cppcrash，崩溃栈：libskia_canvaskit.z.so |
| [I84866](https://gitee.com/open_harmony/dashboard?issue_id=I84866) | 【OpenHarmony 4.0.10.9sp1】出现61次  com.ohos.smartperf由于APP_INPUT_BLOCK卡在libace.z.so |
| [I84QZZ](https://gitee.com/open_harmony/dashboard?issue_id=I84QZZ) | 【OpenHarmony 4.0.10.9sp1】出现9次  进程camera_host下的collect#2线程导致libcamera_pipeline_core.z.so出现cppcrash |
| [I84R11](https://gitee.com/open_harmony/dashboard?issue_id=I84R11) | 【OpenHarmony 4.0.10.9sp1】出现16次  进程camera_host下的IPC_5_24615线程导致libcamera_host_vdi_impl_1.0.z.so出现cppcrash |
| [I8661O](https://gitee.com/open_harmony/dashboard?issue_id=I8661O) | 【OpenHarmony 4.0.10.10】出现335次  进程com.ohos.camera由于THREAD_BLOCK_6S卡在libsamgr_proxy.z.so出现appfreeze |
| [I869MO](https://gitee.com/open_harmony/dashboard?issue_id=I869MO) | 【OpenHarmony  4.0.10.10】【RK3568】【压力测试】【ToC】【必现10/10】反复进入图库的大图浏览界面出现泄漏，12小时涨到180M，泄露点libmediaquery |
| [I869WH](https://gitee.com/open_harmony/dashboard?issue_id=I869WH) | 【OpenHarmony 4.0.10.10】出现17次  进程com.ohos.smartperf下出现jscrash，栈名：drawHighlighted |
| [I86M99](https://gitee.com/open_harmony/dashboard?issue_id=I86M99) | 【OpenHarmony  4.0.10.10】【RK3568】【压力测试】【ToC】【必现10/10】进行wukong测试foundation出现泄漏， |
| [I87XCI](https://gitee.com/open_harmony/dashboard?issue_id=I87XCI) | 【OpenHarmony 4.1.2.1】出现16次 时钟应用出现APPfreeze        |
| [I88UHY](https://gitee.com/open_harmony/dashboard?issue_id=I88UHY) | 【OpenHarmony 4.0.10.11sp1】出现8次  com.ohos.photos由于THREAD_BLOCK_6S卡在libmediaquery.z.so |
| [I88UVQ](https://gitee.com/open_harmony/dashboard?issue_id=I88UVQ) | 【OpenHarmony  4.0.10.10】【RK3568】【压力测试】【ToC】【必现10/10】进行wukong测试foundation拆分下wms出现泄漏， |
| [I890O6](https://gitee.com/open_harmony/dashboard?issue_id=I890O6) | 【OpenHarmony_4.0.10.11】【内核子系统】【ToC】【RK3568】【必现-3/3】应用内滑动场景抓取trace，trace中桩点（H：HandleEndScene）丢失 |
| [I89EUH](https://gitee.com/open_harmony/dashboard?issue_id=I89EUH) | 【OpenHarmony 4.0.10.11sp2】出现732次  进程com.ohos.camera由于THREAD_BLOCK_6S卡在libsamgr_proxy.z.so出现appfreeze |
| [I89FA5](https://gitee.com/open_harmony/dashboard?issue_id=I89FA5) | 【weekly分支】【RK3568】【分布式数据】【ToC】【必现3/3】DctsDistributedObjectDisJsTest测试套用例失败 |
| [I89JHP](https://gitee.com/open_harmony/dashboard?issue_id=I89JHP) | 【OpenHarmony  4.0release】【RK3568】【分布式软总线】【ToC】【必现3/3】SUB_Softbus_Trans_Comp_SendBytes_Fun_0800用例的相同功能但不具备和之前版本兼容 |
| [I8A7Y4](https://gitee.com/open_harmony/dashboard?issue_id=I8A7Y4) | 【OpenHarmony_4.1.2.2】【USB服务子系统】【ToC】【RK3568】【必现】test_usbevent用的关于port功能切换的广播监听用例无法执行，服务UT测试套执行报错 |
| [I8AR1A](https://gitee.com/open_harmony/dashboard?issue_id=I8AR1A) | 【 OpenHarmony 4.0.10.11 sp2】【4.0 Release】【应用子系统】【RK3568】【必现】图库应用功能异常 |
| [I8DD5M](https://gitee.com/open_harmony/dashboard?issue_id=I8DD5M) | 【OpenHarmony 4.0.10.15】【应用子系统】【RK3568】【必现_5/5】图库卡片封面不能自动刷新 |
| [I8DM2R](https://gitee.com/open_harmony/dashboard?issue_id=I8DM2R) | 【OpenHarmony 4.0.10.13】出现924次  进程com.ohos.camera由于THREAD_BLOCK_6S卡在libcamera_framework.z.so出现appfreeze |
| [I92HFJ](https://gitee.com/open_harmony/dashboard?issue_id=I92HFJ) | 【OpenHarmony 4.0.10.16sp2】出现77次  进程wifi_manager_se导致libipc_core.z.so出现cppcrash |
| [I957IR](https://gitee.com/open_harmony/dashboard?issue_id=I957IR) | 【OpenHarmony 4.0.10.16sp2】出现43次  进程ohos.samples.etsclock出现THREAD_BLOCK_6S的appfreeze |
| [I9H8J6](https://gitee.com/open_harmony/dashboard?issue_id=I9H8J6) | 相对于4.0.10.11版本开机阶段文件管理调用openssl接口导致偶现长耗时 |
| [I90FM1](https://gitee.com/open_harmony/dashboard?issue_id=I90FM1) | 【压力测试】出现42次 由进程wifi_manager_se下的IPC_2_2577线程导致libipc_core.z.so出现cppcrash |

## 修复安全issue列表

**表4** 修复安全issue列表

| ISSUE                                                        | 问题描述                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [I6U81V](https://gitee.com/open_harmony/dashboard?issue_id=I6U81V) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2023-30456           |
| [I6V7QA](https://gitee.com/open_harmony/dashboard?issue_id=I6V7QA) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2023-1829            |
| [I6V7V2](https://gitee.com/open_harmony/dashboard?issue_id=I6V7V2) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2023-1872            |
| [I6X3GE](https://gitee.com/open_harmony/dashboard?issue_id=I6X3GE) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2023-2002            |
| [I6Y8IE](https://gitee.com/open_harmony/dashboard?issue_id=I6Y8IE) | 【漏洞】【OpenHarmony-4.0-Release】CVE-2023-2194             |
| [I6ZJDC](https://gitee.com/open_harmony/dashboard?issue_id=I6ZJDC) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2023-31436           |
| [I6ZUSY](https://gitee.com/open_harmony/dashboard?issue_id=I6ZUSY) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2023-2248            |
| [I708T3](https://gitee.com/open_harmony/dashboard?issue_id=I708T3) | 【漏洞】【OpenHarmony-4.0-Release】CVE-2023-2124             |
| [I70B17](https://gitee.com/open_harmony/dashboard?issue_id=I70B17) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2023-2483            |
| [I71KHX](https://gitee.com/open_harmony/dashboard?issue_id=I71KHX) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2023-32233           |
| [I7FM6A](https://gitee.com/open_harmony/dashboard?issue_id=I7FM6A) | 【漏洞】【OpenHarmony-4.0-Release】CVE-2023-35788            |
| [I7SZTB](https://gitee.com/open_harmony/dashboard?issue_id=I7SZTB) | 【漏洞】【OpenHarmony_4.0.10.2】CVE-2015-8955                |
| [I7SZWH](https://gitee.com/open_harmony/dashboard?issue_id=I7SZWH) | 【漏洞】【OpenHarmony_4.0.10.2】CVE-2023-4128                |
| [I7XCCQ](https://gitee.com/open_harmony/dashboard?issue_id=I7XCCQ) | 【漏洞】【OpenHarmony_4.0.10.5】CVE-2022-40982               |
| [I934PZ](https://gitee.com/open_harmony/dashboard?issue_id=I934PZ) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-23775           |
| [I93ART](https://gitee.com/open_harmony/dashboard?issue_id=I93ART) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2023-43615           |
| [I944MQ](https://gitee.com/open_harmony/dashboard?issue_id=I944MQ) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-25062           |
| [I94IJY](https://gitee.com/open_harmony/dashboard?issue_id=I94IJY) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-24806           |
| [I952U8](https://gitee.com/open_harmony/dashboard?issue_id=I952U8) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-762126596168486912 |
| [I966TM](https://gitee.com/open_harmony/dashboard?issue_id=I966TM) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-762126168387227648 |
| [I966UT](https://gitee.com/open_harmony/dashboard?issue_id=I966UT) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2024-762133623825502208 |
| [I9BS9L](https://gitee.com/open_harmony/dashboard?issue_id=I9BS9L) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2023-52444           |
| [I9BUAF](https://gitee.com/open_harmony/dashboard?issue_id=I9BUAF) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2019-19768           |
| [I9C46A](https://gitee.com/open_harmony/dashboard?issue_id=I9C46A) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2023-52438           |
| [I9F1XE](https://gitee.com/open_harmony/dashboard?issue_id=I9F1XE) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2021-45485           |
| [I9FE7O](https://gitee.com/open_harmony/dashboard?issue_id=I9FE7O) | 【漏洞】【OpenHarmony-4.0-Release】 CVE-2022-3566            |
| [I818FO](https://gitee.com/open_harmony/dashboard?issue_id=I818FO) | 【漏洞】【OpenHarmony_4.0.10.7】CVE-2023-21636               |
| [I818G7](https://gitee.com/open_harmony/dashboard?issue_id=I818G7) | 【漏洞】【OpenHarmony_4.0.10.7】CVE-2023-4881                |

## 遗留缺陷列表

**表5** 遗留缺陷列表

| ISSUE | 问题描述 | 影响 | 计划解决日期 |
| -------- | -------- | -------- | -------- |
| I827LU | 进入设置反复打开关闭蓝牙开关会出现内存泄漏，经测试一个小时泄露15MB。 | 开关一次蓝牙系统内存泄露8.3KB，重启设备后可恢复，影响可控。<br />对于需要使用OpenHarmony进行商业开发的伙伴，建议使用芯片或硬件自带蓝牙模块的协议栈以规避此问题。 | 5月30日 |
