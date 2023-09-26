# OpenHarmony 3.2.2 Release


## 版本概述

当前版本在OpenHarmony 3.2.1 Release的基础上，修复了内存泄漏及linux kernel等开源组件的安全漏洞，增强了系统安全性。修复了部分系统稳定性的issue，增强了系统稳定性。更新配套的SDK版本。


## 配套关系

  **表1** 版本软件和工具配套关系

| 软件                              | 版本                                             | 备注                                                         |
| --------------------------------- | ------------------------------------------------ | ------------------------------------------------------------ |
| OpenHarmony                       | 3.2.2 Release                                    | NA                                                           |
| Public SDK                        | Ohos_sdk_public 3.2.13.5 (API Version 9 Release) | 面向应用开发者提供，不包含需要使用系统权限的系统接口。通过DevEco Studio默认获取的SDK为Public SDK。 |
| HUAWEI DevEco Studio（可选）      | 3.1 Release                                      | OpenHarmony应用开发推荐使用。<br />[点击此处获取](https://developer.harmonyos.com/cn/develop/deveco-studio#download) |
| HUAWEI DevEco Device Tool（可选） | 3.1 Release                                      | OpenHarmony智能设备集成开发环境推荐使用。<br />[点击此处获取](https://device.harmonyos.com/cn/develop/ide/) |

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

 ```
 repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.2.2-Release --no-repo-verify
 repo sync -c
 repo forall -c 'git lfs pull'
 ```

**方式二**

通过repo + https 下载。

从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
 ```
 repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v3.2.2-Release --no-repo-verify
 repo sync -c
 repo forall -c 'git lfs pull'
 ```

### 从镜像站点获取

  **表2** 获取源码路径

| 版本源码                              | **版本信息**  | **下载站点**                                                 | **SHA256校验码**                                             |
| ------------------------------------- | ------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 全量代码（标准、轻量和小型系统）      | 3.2.2 Release | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.2.2/code-v3.2.2-Release_20230628.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.2.2/code-v3.2.2-Release.tar.gz_20230628.sha256) |
| Hi3861解决方案（二进制）              | 3.2.2 Release | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.2.2/hispark_pegasus.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.2.2/hispark_pegasus.tar.gz.sha256) |
| Hi3516解决方案-LiteOS（二进制）       | 3.2.2 Release | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.2.2/hispark_taurus_LiteOS.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.2.2/hispark_taurus_LiteOS.tar.gz.sha256) |
| Hi3516解决方案-Linux（二进制）        | 3.2.2 Release | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.2.2/hispark_taurus_Linux.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.2.2/hispark_taurus_Linux.tar.gz.sha256) |
| RK3568标准系统解决方案（二进制）      | 3.2.2 Release | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.2.2/dayu200_standard_arm32.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.2.2/dayu200_standard_arm32.tar.gz.sha256) |
| 标准系统Public SDK包（Mac）           | 3.2.13.5      | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.2.2/ohos-sdk-mac-public.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.2.2/ohos-sdk-mac-public.tar.gz.sha256) |
| 标准系统Public SDK包（Mac-M1）        | 3.2.13.5      | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.2.2/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.2.2/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) |
| 标准系统Public SDK包（Windows/Linux） | 3.2.13.5      | [站点](https://mirrors.huaweicloud.com/openharmony/os/3.2.2/ohos-sdk-windows_linux-public.tar.gz) | [SHA256校验码](https://mirrors.huaweicloud.com/openharmony/os/3.2.2/ohos-sdk-windows_linux-public.tar.gz.sha256) |

## 更新说明

### API 

3.2.2 Release对比3.2.1 Release API接口无变更。

### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。

## 修复缺陷issue列表

  **表3** 修复缺陷issue列表

| ISSUE                                                        | 问题描述                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [I70T6E](https://gitee.com/openharmony/web_webview/issues/I70T6E) | 【OpenHarmony 3.2.12.2】【RK3568】【压力测试】【ToC】【低概率1/10】【wukong】出现1次 由进程com.ohos.note下的Chrome_IOThread线程导致libweb_engine.so出现cppcrash |
| [I76JRL](https://gitee.com/openharmony/drivers_peripheral/issues/I76JRL) | 【OpenHarmony 3.2.11.9】【RK3568】【压力测试】【ToC】【低概率1/10】【wukong】出现1次，camera_host进程下offlinepipeline发生cppcrash，信息为libcamera_pipeline_core.z.so。 |
| [I7C0LX](https://gitee.com/openharmony/developtools_profiler/issues/I7C0LX) | 【OpenHarmony 3.2.13.1】【RK3568】【压力测试】【ToC】【高概率6/10】【wukong】出现650次，com.ohos.smartperf应用出现jscrash，内容信息为initDb。 |
| [I7C0SA](https://gitee.com/openharmony/vendor_hihope/issues/I7C0SA) | 【OpenHarmony 3.2.13.1】【RK3568】【压力测试】【ToC】【高概率】【wukong】出现27次 由进程com.ohos.systemui下的RSRenderThread线程导致libmali-bifrost-g52-g2p0-ohos.so出现cppcrash |
| [I7C10M](https://gitee.com/openharmony/security_privacy_center/issues/I7C10M) | 【OpenHarmony 3.2.13.1】【RK3568】【压力测试】【ToC】【高概率6/10】【wukong】出现39次，com.ohos.certmanager出现jscrash，内容信息为saveAllMaps。 |
| [I7CA2W](https://gitee.com/openharmony/multimedia_medialibrary_standard/issues/I7CA2W) | 【OpenHarmony 3.2.13.1】【RK3568】【压力测试】【ToC】【高概率】【wukong】出现358次， 由进程com.ohos.medialibrary.medialibrarydata下com.ohos.medial线程出现cppcrash，崩溃栈显示为libmedialibrary_data_extension.z.so |
| [I7CA7A](https://gitee.com/openharmony/distributeddatamgr_relational_store/issues/I7CA7A) | 【OpenHarmony 3.2.13.1】【RK3568】【压力测试】【ToC】【高概率 8/10】【wukong】出现1131次，由进程com.ohos.contactsdataability下的IPC_2_4692线程导致librdb_data_share_adapter.z.so出现cppcrash |
| [I7CBLV](https://gitee.com/openharmony/bundlemanager_bundle_framework/issues/I7CBLV) | 【OpenHarmony 3.2.13.1】【RK3568】【压力测试】【ToC】【高概率】【wukong】出现1249次，com.ohos.note下出现jscrash问题，栈名：getFolderText与createRdbStore |
| [I7CBWQ](https://gitee.com/openharmony/applications_mms/issues/I7CBWQ) | 【OpenHarmony 3.2.13.1】【RK3568】【压力测试】【ToC】【低概率】【wukong】出现6次关键应用: com.ohos.mms由于STRINGID:APPLICATION_BLOCK_INPUT卡在libeventhandler.z.so |
| [I7CWA0](https://gitee.com/openharmony/communication_ipc/issues/I7CWA0) | 【OpenHarmony 3.2.13.1】【RK3568】【压力测试】【ToC】【低概率】【wukong】出现1次 由关键进程com.ohos.contacts下的IPC_3_17363线程导致libipc_core.z.so出现cppcrash |
| [I7CYM3](https://gitee.com/openharmony/applications_camera/issues/I7CYM3) | 【OpenHarmony 3.2.13.1】【RK3568】【压力测试】【ToC】【高概率8/10】【wukong】出现1800次，com.ohos.camer出现jscrash问题，栈名：getInstance |


## 修复安全issue列表

  **表4** 修复安全issue列表

| ISSUE                                                        | 问题描述                                            |
| ------------------------------------------------------------ | --------------------------------------------------- |
| I6QYVO | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2021-3923 |
| I6QYVZ | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-28772 |
| I6QYWE | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-1281 |
| I6RAW6 | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-0590 |
| I6UW4T | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-29156 |
| I6UW51 | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-2978 |
| I6UW52 | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-3176 |
| I6UW55 | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-45934 |
| I6UW56 | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-47521 |
| I6VUAY | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-2004 |
| I6XC4Y | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-2162 |
| I6ZM02 | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-0179 |
| I70CNH | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-2459 |
| I70SLA | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-1078 |
| I722JK | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-0326 |
| I722JP | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-0240 |
| I722K2 | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-42915 |
| I722K4 | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-42916 |
| I722K6 | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-32207 |
| I722K8 | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-32221 |
| I722UD | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-32206 |
| I722UL | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-25313 |
| I722UN | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-25314 |
| I722UP | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-25315 |
| I722UV | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-25235 |
| I722V1 | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-25236 |
| I722V6 | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-23990 |
| I722VB | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-23852 |
| I722VJ | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2021-45960 |
| I722VL | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2021-46143 |
| I722VN | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-22822 |
| I722VP | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-22824 |
| I722VR | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-22823 |
| I722VU | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-22827 |
| I722WC | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-22825 |
| I722WM | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-22826 |
| I722WV | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2021-39275 |
| I722X0 | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2021-36160 |
| I722X4 | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2021-33193 |
| I722XQ | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-21538 |
| I72RUE | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-47518 |
| I72SDD | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-3545 |
| I72SDF | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-4696 |
| I72SKQ | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-47519 |
| I73C2J | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-2513 |
| I73C2O | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-28893 |
| I73MW6 | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-23222 |
| I73MWI | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-32250 |
| I73MWQ | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-34918 |
| I73MX2 | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-36946 |
| I73PF6 | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-2726 |
| I749IX | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-2721 |
| I74HC1 | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-28320 |
| I74HCG | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-28322 |
| I74HD3 | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-28321 |
| I76NLQ | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-2724 |
| I76NLT | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-2722 |
| I77U26 | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2021-43389 |
| I77XID | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-25375 |
| I78I9U | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-2588 |
| I78R59 | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-3635 |
| I78R5B | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-3649 |
| I79CK8 | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2021-3600 |
| I79LH8 | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-2650 |
| I79NDI | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-2936 |
| I79NEF | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-2937 |
| I7A1M8 | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-3006 |
| I7AJ6J | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-2935 |
| I7AJ6M | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-2933 |
| I7AJ6P | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-2931 |
| I7AJ6S | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-2932 |
| I7AJ6W | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-2929 |
| I7AJHL | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-2940 |
| I7AJHO | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-2941 |
| I7AJHR | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-2938 |
| I7AJHU | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-2939 |
| I7AJHX | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-2930 |
| I7AJI0 | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-2934 |
| I7B049 | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-32643 |
| I7B04Z | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-32636 |
| I7B05A | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-32611 |
| I7B05I | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-32665 |


## 遗留缺陷列表

  **表5** 遗留缺陷列表

| ISSUE | 问题描述 | 影响 | 计划解决日期 |
| ----- | -------- | ---- | ------------ |
| I6SXBI | 【OpenHarmony 3.2.11.6】【RK3568】【压力测试】【ToC】【低概率】【wukong】出现由进程ohos.samples.distributedcalc下的libdistributeddata.z.so cppcrash | 计算器应用快速启动和退出场景，启动后1秒内退出，导致JS对象读取数据库成功前JS对象被析构，只有LOG报错但用户无感知，对2C无影响 | 2023年7月15日 |
| I6TRE6 | 进程com.ohos.contacts下的com.ohos.contacts线程导致libdatashare_consumer.z.so低概率出现crash。 | 联系人应用快速启动和退出场景，发现在启动后600ms内退出，联系人进程低概率出现crash，出现crash后联系人进程会被重新拉起，影响可控。 | 2023年7月15日 |
| I72P5E | 反复进入大图浏览界面后返回，导致libace.z.so出现内存泄露 | 从图库进入大图浏览界面后返回，ArkUI模块每次泄露10kb，应用点返回后，内存回收 | 2023年7月15日 |
| I72P5I | 反复进入某相册的图片宫格浏览界面，导致libace.z.so出现内存泄露 | 进入某相册的图片宫格浏览界面后返回，ArkUI每次泄露19kb，应用点返回后，内存回收 | 2023年7月15日 |
| I76N0Y | 反复在dock栏添加/移除应用，导致libace.z.so出现内存泄露 | 移动卡片到合法区域，ArkUI每次泄露99kb，非常用场景，应用重启内存回收。 | 2023年7月15日 |
| I6XHE7 | NAPIRemoteObject模块内存泄露 | JS应用需要IPC需要建立NAPIRemoteObject对象进程通信，创建一次可以循环使用，建立一次后泄露1.2kb，应用不需要反复创建新对象，泄露量可控，应用进程退出会释放掉 | 2023年7月15日 |
| I7D4CH | 【OpenHarmony】【体验测试】【版本号：3.2.13.1】【rk3568】【ToC】【概率：必现】首次启动短信息完成时延2300ms，实际值2537ms，超基线237ms | 版本为了合入I7CBSM稳定性问题，修改rdb数据锁保护范围，导致联系人加载耗时增加，平均劣化约9%，影响可控，跟踪在后续版本优化。 | 2023年7月15日 |

