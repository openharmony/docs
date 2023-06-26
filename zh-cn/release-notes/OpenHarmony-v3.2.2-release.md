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
 repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.2.1-Release --no-repo-verify
 repo sync -c
 repo forall -c 'git lfs pull'
 ```

**方式二**

通过repo + https 下载。

从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
 ```
 repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v3.2.1-Release --no-repo-verify
 repo sync -c
 repo forall -c 'git lfs pull'
 ```

### 从镜像站点获取

  **表2** 获取源码路径

| 版本源码                              | **版本信息**  | **下载站点**                                                 | **SHA256校验码**                                             |
| ------------------------------------- | ------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 全量代码（标准、轻量和小型系统）      | 3.2.2 Release | [站点](https://repo.huaweicloud.com/openharmony/os/3.2.2/code-v3.2.2-Release.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2.2/code-v3.2.2-Release.tar.gz.sha256) |
| Hi3861解决方案（二进制）              | 3.2.2 Release | [站点](https://repo.huaweicloud.com/openharmony/os/3.2.2/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2.2/hispark_pegasus.tar.gz.sha256) |
| Hi3516解决方案-LiteOS（二进制）       | 3.2.2 Release | [站点](https://repo.huaweicloud.com/openharmony/os/3.2.2/hispark_taurus_LiteOS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2.2/hispark_taurus_LiteOS.tar.gz.sha256) |
| Hi3516解决方案-Linux（二进制）        | 3.2.2 Release | [站点](https://repo.huaweicloud.com/openharmony/os/3.2.2/hispark_taurus_Linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2.2/hispark_taurus_Linux.tar.gz.sha256) |
| RK3568标准系统解决方案（二进制）      | 3.2.2 Release | [站点](https://repo.huaweicloud.com/openharmony/os/3.2.2/dayu200_standard_arm32.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2.2/dayu200_standard_arm32.tar.gz.sha256) |
| 标准系统Public SDK包（Mac）           | 3.2.13.5      | [站点](https://repo.huaweicloud.com/openharmony/os/3.2.2/ohos-sdk-mac-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2.2/ohos-sdk-mac-public.tar.gz.sha256) |
| 标准系统Public SDK包（Mac-M1）        | 3.2.13.5      | [站点](https://repo.huaweicloud.com/openharmony/os/3.2.2/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2.2/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) |
| 标准系统Public SDK包（Windows/Linux） | 3.2.13.5      | [站点](https://repo.huaweicloud.com/openharmony/os/3.2.2/ohos-sdk-windows_linux-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2.2/ohos-sdk-windows_linux-public.tar.gz.sha256) |

## 更新说明

### API 

3.2.2 Release对比3.2.1 Release API接口无变更。

### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。

## 修复缺陷issue列表

  **表3** 修复缺陷issue列表

| ISSUE                                                        | 问题描述                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [I6Q0BP](https://gitee.com/openharmony/ability_form_fwk/issues/I6Q0BP) | 【OpenHarmony  3.2.11.1】【ability】【TOD】【rk3568】【必现-5/5】masterXTS执行测试，元能力测试套执行结果存在fail |
| [I70G1T](https://gitee.com/openharmony/applications_camera/issues/I70G1T) | 【OpenHarmony 3.2.12.2sp1】【应用子系统】【ToC】【RK3568】【必现】在RK3568设备上对Openharmony  进行动态内存测试，com.ohos.camera 进程 基线值 0 KB，实测值 42550KB，超基线41.55M |
| [I70VQX](https://gitee.com/openharmony/xts_acts/issues/I70VQX) | 【OpenHarmony  3.2.12.5】【xts_acts】【Misc软件服务子系统】【ToD】【RK3568】【必现】inputEngine属性接口覆盖 |
| [I72AD8](https://gitee.com/openharmony/drivers_peripheral/issues/I72AD8) | 【OpenHarmony 3.2.12.2 sp2】【驱动子系统】【ToC】【RK3568】【必现】相机黑屏，测试用例执行失败 |
| [I73A19](https://gitee.com/openharmony/multimedia_audio_framework/issues/I73A19) | 【OpenHarmony 3.2.12.3】【RK3568】【压力测试】【ToC】【高概率】【wukong】出现16次  ，进程com.ohos.setting下出现appfreeze问题，栈名：libaudio_policy_service.z.so |
| [I77YI6](https://gitee.com/openharmony/xts_acts/issues/I77YI6) | 【OpenHarmony4.0.7.2】【RK3568】【多模子系统3.2Release】【ToD】【必现】 多模子系统用例修改调整 |
| [I790E9](https://gitee.com/openharmony/xts_hats/issues/I790E9) | 【OpenHarmony  3.2Release】【驱动子系统】【ToC】【RK3568】【必现】HatsHdfAudioCaptureAttrTest和HatsHdfAudioCaptureVolumeTest  测试套用例失败 |
| [I79Z81](https://gitee.com/openharmony/xts_acts/issues/I79Z81) | 【OpenHarmony 3.2.12.2】【xts_acts】【Misc软件服务子系统】【ToD】【RK3568】【必现】优化input用例时延 |
| [I774YK](https://gitee.com/openharmony/window_window_manager/issues/I774YK) | 【OpenHarmony 4.0.7.2】【资料】【ToD】【必现】【WMS】ohos.display.d.ts文件中，跨平台接口的参数未添加 |
| [I6QTIN](https://gitee.com/openharmony/release-management/issues/I6QTIN) | 【OpenHarmony】【体验测试】【版本号：3.2.10.11】【rk3568】【ToC】【概率：必现】新建联系人场景---应用业务逻辑问题：应用不应该使用系统默认的转场动效(默认300ms)，需要应用实现窗口动效,Android的窗口动效80ms。 |
| [I6QTLI](https://gitee.com/openharmony/release-management/issues/I6QTLI) | 【OpenHarmony】【体验测试】【版本号：3.2.10.11】【rk3568】【ToC】【概率：必现】删除联系人场景---应用业务逻辑问题：已拆解出主线程同步等待子线程成146ms做数据库查询动作 |
| [I6R1F4](https://gitee.com/openharmony/release-management/issues/I6R1F4) | 【OpenHarmony】【体验测试】【版本号：3.2.10.11】【rk3568】【ToC】【概率：必现】输入法弹出标准值279ms，实际值740.3ms |
| [I6R21B](https://gitee.com/openharmony/release-management/issues/I6R21B) | 【OpenHarmony】【体验测试】【版本号：3.2.10.11】【rk3568】【ToC】【概率：必现】状态栏下拉标准值68ms，实际值177.7ms |
| [I55ZAC](https://gitee.com/openharmony/applications_contacts/issues/I55ZAC) | 【OpenHarmony】【applications_contacts】【版本号：3.2.3.2】【rk3568】【概率：必现】联系人-拨号子Tab切换完成时延标准值：250ms，实际值：325ms，超基线75ms |
| [I5G02U](https://gitee.com/openharmony/applications_contacts/issues/I5G02U) | 【OpenHarmony】【applications_contacts】【版本号：3.2.5.1】【rk3568】【概率：必现】联系人-拨号子Tab切换完成时延标准值：250ms，实际值：490.3ms，超基线240.3ms |
| [I6B4U3](https://gitee.com/openharmony/applications_launcher/issues/I6B4U3) | 【OpenHarmony 3.2.10.5(Mr)】【RK3568】【压力测试】【ToC】【低概率1/10】【xts】出现3次  由进程com.ohos.launcher出现appfreeze |
| [I6KYOV](https://gitee.com/openharmony/applications_launcher/issues/I6KYOV) | 【3.2 monthly】Launcher 反复同时点击桌面文件夹和home键 会出现状态栏、导航栏闪黑现象 |
| [I6OUPH](https://gitee.com/openharmony/xts_acts/issues/I6OUPH) | 【OpenHarmony  3.2release】【distributed_schedule_lite】IUnknownTestSuite模块执行一条failed项 |
| [I6T84B](https://gitee.com/openharmony/applications_launcher/issues/I6T84B) | 【OpenHarmony  3.2.10.11】【稳定性】【TOC】【rk3568】【必现-5/5】应用遍历测试：com.ohos.launcher出现错误 “APP_FREEZE” |
| [I6U00Q](https://gitee.com/openharmony/device_board_hihope/issues/I6U00Q) | 【3.2Release】Rk3568使用3.5mm耳机播放音频文件，存在pop音     |
| [I6V2F6](https://gitee.com/openharmony/drivers_peripheral/issues/I6V2F6) | 【OpenHarmony 3.2.11.9】【驱动子系统】【ToC】【RK3568】【必现】在RK3568设备上对Openharmony  进行动态内存测试，codec_host 进程 基线值 2367.6KB，实测值 17585KB，超基线14.86M |
| [I6WBVF](https://gitee.com/openharmony/arkui_ace_engine/issues/I6WBVF) | [OH-3.2Release]界面置灰，且实际上不可点击的控件信息中enabled属性仍为true，与规格不符，影响自动化测试功能 |
| [I70T6E](https://gitee.com/openharmony/web_webview/issues/I70T6E) | 【OpenHarmony 3.2.12.2】【RK3568】【压力测试】【ToC】【低概率1/10】【wukong】出现1次  由进程com.ohos.note下的Chrome_IOThread线程导致libweb_engine.so出现cppcrash |
| [I72P6D](https://gitee.com/openharmony/graphic_graphic_2d/issues/I72P6D) | 【OpenHarmony  3.2.12.2】【RK3568】【压力测试】【ToC】【必现10/10】反复移动卡片到合法区域挤位，导致libskia_ohos.z.so出现内存泄露 |
| [I72P6H](https://gitee.com/openharmony/graphic_graphic_2d/issues/I72P6H) | 【OpenHarmony  3.2.12.2】【RK3568】【压力测试】【ToC】【必现10/10】反复移动文件夹到合法区域挤位，导致libskia_ohos.z.so出现内存泄露 |
| [I76JRL](https://gitee.com/openharmony/drivers_peripheral/issues/I76JRL) | 【OpenHarmony  3.2.11.9】【RK3568】【压力测试】【ToC】【低概率1/10】【wukong】出现1次，camera_host进程下offlinepipeline发生cppcrash，信息为libcamera_pipeline_core.z.so。 |
| [I76N61](https://gitee.com/openharmony/graphic_graphic_2d/issues/I76N61) | 【OpenHarmony  3.2.12.2】【RK3568】【压力测试】【ToC】【必现10/10】反复进入某相册的图片宫格浏览界面，导致libmali-bifrost-g52-g2p0-ohos.so出现内存泄露 |
| [I76N63](https://gitee.com/openharmony/graphic_graphic_2d/issues/I76N63) | 【OpenHarmony  3.2.12.2】【RK3568】【压力测试】【ToC】【必现10/10】反复在dock栏添加/移除应用，导致libmali-bifrost-g52-g2p0-ohos.so出现内存泄露 |
| [I77HM5](https://gitee.com/openharmony/powermgr_battery_statistics/issues/I77HM5) | 【OpenHarmany-3.2release】battery_stattistic部件API文档描述与代码实现不一致 |
| [I77UBT](https://gitee.com/openharmony/third_party_chromium/issues/I77UBT) | 鸿蒙系统OpenHarmony-3.2-Release分支的源码与其给浏览内核提供的patch代码不一致，导致2个编译报错 |
| [I79SUV](https://gitee.com/openharmony/xts_acts/issues/I79SUV) | 【OpenHarmony-3.2-Release】【通知子系统】【XTS】3.2Release  acts缺少ActsNotificationRequestTest源码 |

## 修复安全issue列表

  **表4** 修复安全issue列表

| ISSUE                                                        | 问题描述                                            |
| ------------------------------------------------------------ | --------------------------------------------------- |
| [I6QYWE](https://gitee.com/openharmony/kernel_linux_5.10/issues/I6QYWE) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-1281  |
| [I6VUAY](https://gitee.com/openharmony/third_party_freetype/issues/I6VUAY) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-2004  |
| [I6YQP4](https://gitee.com/openharmony/third_party_jerryscript/issues/I6YQP4) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-30408 |
| [I70CNH](https://gitee.com/openharmony/third_party_chromium/issues/I70CNH) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-2459  |
| [I72RUE](https://gitee.com/openharmony/kernel_linux_5.10/issues/I72RUE) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-47518 |
| [I72SDD](https://gitee.com/openharmony/kernel_linux_5.10/issues/I72SDD) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-3545  |
| [I72SDF](https://gitee.com/openharmony/kernel_linux_5.10/issues/I72SDF) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-4696  |
| [I72SKQ](https://gitee.com/openharmony/kernel_linux_5.10/issues/I72SKQ) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-47519 |
| [I73C2J](https://gitee.com/openharmony/kernel_linux_5.10/issues/I73C2J) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-2513  |
| [I73C2O](https://gitee.com/openharmony/kernel_linux_5.10/issues/I73C2O) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-28893 |
| [I73MW6](https://gitee.com/openharmony/kernel_linux_5.10/issues/I73MW6) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-23222 |
| [I73MWI](https://gitee.com/openharmony/kernel_linux_5.10/issues/I73MWI) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-32250 |
| [I73MWQ](https://gitee.com/openharmony/kernel_linux_5.10/issues/I73MWQ) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-34918 |
| [I73MX2](https://gitee.com/openharmony/kernel_linux_5.10/issues/I73MX2) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-36946 |
| [I73PF6](https://gitee.com/openharmony/third_party_chromium/issues/I73PF6) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-2726  |
| [I749IX](https://gitee.com/openharmony/third_party_chromium/issues/I749IX) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-2721  |
| [I74HC1](https://gitee.com/openharmony/third_party_curl/issues/I74HC1) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-28320 |
| [I74HCG](https://gitee.com/openharmony/third_party_curl/issues/I74HCG) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-28322 |
| [I74HD3](https://gitee.com/openharmony/third_party_curl/issues/I74HD3) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-28321 |
| [I76NLQ](https://gitee.com/openharmony/third_party_chromium/issues/I76NLQ) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-2724  |
| [I76NLT](https://gitee.com/openharmony/third_party_chromium/issues/I76NLT) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-2722  |
| [I77U26](https://gitee.com/openharmony/kernel_linux_5.10/issues/I77U26) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2021-43389 |
| [I77XID](https://gitee.com/openharmony/kernel_linux_5.10/issues/I77XID) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-25375 |
| [I78I9U](https://gitee.com/openharmony/kernel_linux_5.10/issues/I78I9U) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-2588  |
| [I78R59](https://gitee.com/openharmony/kernel_linux_5.10/issues/I78R59) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-3635  |
| [I78R5B](https://gitee.com/openharmony/kernel_linux_5.10/issues/I78R5B) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-3649  |
| [I79CK8](https://gitee.com/openharmony/kernel_linux_5.10/issues/I79CK8) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2021-3600  |
| [I79LH8](https://gitee.com/openharmony/third_party_openssl/issues/I79LH8) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-2650  |
| [I7A1M8](https://gitee.com/openharmony/kernel_linux_5.10/issues/I7A1M8) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-3006  |

## 遗留缺陷列表

  **表5** 遗留缺陷列表

| ISSUE | 问题描述 | 影响 | 计划解决日期 |
| ----- | -------- | ---- | ------------ |
|       |          |      |              |
|       |          |      |              |
