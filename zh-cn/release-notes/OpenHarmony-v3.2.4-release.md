# OpenHarmony 3.2.4 Release


## 版本概述

当前版本在OpenHarmony 3.2.3 Release的基础上，修复了内存泄漏及linux kernel等开源组件的安全漏洞，增强了系统安全性。修复了部分系统稳定性的issue，增强了系统稳定性。更新配套的SDK版本。


## 配套关系

  **表1** 版本软件和工具配套关系

| 软件                              | 版本                                             | 备注                                                         |
| --------------------------------- | ------------------------------------------------ | ------------------------------------------------------------ |
| OpenHarmony                       | 3.2.4 Release                                    | NA                                                           |
| Public SDK                        | Ohos_sdk_public 3.2.15.4 (API Version 9 Release) | 面向应用开发者提供，不包含需要使用系统权限的系统接口。通过DevEco Studio默认获取的SDK为Public SDK。 |
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
 repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.2.4-Release --no-repo-verify
 repo sync -c
 repo forall -c 'git lfs pull'
 ```

**方式二**

通过repo + https 下载。

从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
 ```
 repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v3.2.4-Release --no-repo-verify
 repo sync -c
 repo forall -c 'git lfs pull'
 ```

### 从镜像站点获取

  **表2** 获取源码路径

| 版本源码                              | **版本信息**  | **下载站点**                                                 | **SHA256校验码**                                             |
| ------------------------------------- | ------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 全量代码（标准、轻量和小型系统）      | 3.2.4 Release | [站点](https://repo.huaweicloud.com/openharmony/os/3.2.4/code-v3.2.4-Release_20231113.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2.4/code-v3.2.4-Release_20231113.tar.gz.sha256) |
| Hi3861解决方案（二进制）              | 3.2.4 Release | [站点](https://repo.huaweicloud.com/openharmony/os/3.2.4/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2.4/hispark_pegasus.tar.gz.sha256) |
| Hi3516解决方案-LiteOS（二进制）       | 3.2.4 Release | [站点](https://repo.huaweicloud.com/openharmony/os/3.2.4/hispark_taurus_LiteOS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2.4/hispark_taurus_LiteOS.tar.gz.sha256) |
| Hi3516解决方案-Linux（二进制）        | 3.2.4 Release | [站点](https://repo.huaweicloud.com/openharmony/os/3.2.4/hispark_taurus_Linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2.4/hispark_taurus_Linux.tar.gz.sha256) |
| RK3568标准系统解决方案（二进制）      | 3.2.4 Release | [站点](https://repo.huaweicloud.com/openharmony/os/3.2.4/dayu200_standard_arm32_20231129.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2.4/dayu200_standard_arm32_20231129.tar.gz.sha256) |
| 标准系统Public SDK包（Mac）           | 3.2.15.4      | [站点](https://repo.huaweicloud.com/openharmony/os/3.2.4/ohos-sdk-mac-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2.4/ohos-sdk-mac-public.tar.gz.sha256) |
| 标准系统Public SDK包（Mac-M1）        | 3.2.15.4      | [站点](https://repo.huaweicloud.com/openharmony/os/3.2.4/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2.4/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) |
| 标准系统Public SDK包（Windows/Linux） | 3.2.15.4      | [站点](https://repo.huaweicloud.com/openharmony/os/3.2.4/ohos-sdk-windows_linux-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2.4/ohos-sdk-windows_linux-public.tar.gz.sha256) |

## 更新说明

### API 

3.2.4 Release对比3.2.3 Release API接口无变更。

### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。

## 修复缺陷issue列表

  **表3** 修复缺陷issue列表

| ISSUE                                                        | 问题描述                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [I7C8QM](https://gitee.com/open_harmony/dashboard?issue_id=I7C8QM) | 【OpenHarmony  3.2.13.1】【RK3568】【压力测试】【ToC】【低概率2/10】【wukong】出现2次，由进程com.ohos.contacts的:com.ohos.contac线程导致libability_manager.z.so出现cppcrash |
| [I7GFN1](https://gitee.com/open_harmony/dashboard?issue_id=I7GFN1) | 【OpenHarmony  3.2.13.5】【应用子系统】【RK3568】【必现_5/5】联系人应用英文下电话TAB"Telephone"单词换行显示 |
| [I7GFWZ](https://gitee.com/open_harmony/dashboard?issue_id=I7GFWZ) | 【OpenHarmony  3.2.13.5】【应用子系统】【RK3568】【必现_5/5】联系人生日字段日期弹窗默认日期显示为2000年1月31日 |
| [I7GG5K](https://gitee.com/open_harmony/dashboard?issue_id=I7GG5K) | 【OpenHarmony  3.2.13.5】【应用子系统】【RK3568】【必现_5/5】新建联系人页面，生日栏选择任意日期，再次进入选择日期时，还是默认日期 |
| [I7GGCV](https://gitee.com/open_harmony/dashboard?issue_id=I7GGCV) | 【OpenHarmony  3.2.13.5】【应用子系统】【RK3568】【必现_5/5】联系人编辑界面，电子邮件字段新增一行输入框，新增行后面的×点击无反应 |
| [I7IJNI](https://gitee.com/open_harmony/dashboard?issue_id=I7IJNI) | 【OpenHarmony  3.2.14.1】【web子系统】【RK3568】【必现_5/5】点击“Web组件基本功能&回调”，输入hilog \| grep  WebRedo查看无预期日志“The request header key is : xxx -- value is : xxx” |
| [I7OODS](https://gitee.com/open_harmony/dashboard?issue_id=I7OODS) | 【OpenHarmony 3.2.14.5】【RK3568】【压力测试】【ToC】【低概率1/10】【wukong】出现2次  进程com.ohos.callui 下出现jscrash问题，栈名：aboutToDisappear |
| [I7P9T5](https://gitee.com/open_harmony/dashboard?issue_id=I7P9T5) | 【OpenHarmony  3.2.14.5】【RK3568】【压力测试】【必现10/10】反复进入某相册的图片宫格浏览界面，ElementRegister::RemoveItem  和ElementRegister::ClearRemovedItems出现内存泄露 |
| [I7P9VS](https://gitee.com/open_harmony/dashboard?issue_id=I7P9VS) | 【OpenHarmony  3.2.14.5】【RK3568】【压力测试】【必现10/10】反复进入大图浏览界面后返回，ElementRegister::ClearRemovedItems处出现内存泄露 |
| [I7PASS](https://gitee.com/open_harmony/dashboard?issue_id=I7PASS) | 【OpenHarmony  3.2.14.5】【RK3568】【压力测试】【ToC】【低概率】【wukong】出现2次，由进程camera_host的offlinepipeline线程导致libcamera_pipeline_core.z.so出现cppcrash |
| [I7WQX1](https://gitee.com/open_harmony/dashboard?issue_id=I7WQX1) | 【OpenHarmony  3.2.14.6】【图形子系统】【标准系统】【高概率_8/20】相机录像模式下HOME键返回桌面，从FA卡片拍照按钮进入相机拍照模式时预览区域下方有蓝条显示 |
| [I80MCW](https://gitee.com/open_harmony/dashboard?issue_id=I80MCW) | 【OpenHarmony 3.2.14.6】【应用子系统】【RK3568】【必现_5/5】‘最近任务‘界面打开时闪烁 |
| [I822E8](https://gitee.com/open_harmony/dashboard?issue_id=I822E8) | 【OpenHarmony  3.2.15.1】【媒体子系统】【标准系统】【必现_5/5】相机开始录制kill掉media_service,退回后台再进入相机会出现显示错误 |
| [I82H3V](https://gitee.com/open_harmony/dashboard?issue_id=I82H3V) | 【OpenHarmony 3.2.15.1】【媒体子系统】【RK3568】【必现】  图库中进入图片编辑再返回，滑动图片后，图片详情异常，重启后无法清除已删除图片 |
| [I82LYJ](https://gitee.com/open_harmony/dashboard?issue_id=I82LYJ) | 【OpenHarmony 3.2.15.1】【全球化子系统】【RK3568】【必现】 进入管控应用，设置企业信息重启后再查看，恢复为设置之前的信息 |
| [I836GY](https://gitee.com/open_harmony/dashboard?issue_id=I836GY) | 【OpenHarmony  3.2.15.1】【应用子系统】【RK3568】【必现_5/5】图库中视频大图沉浸状态进入播放界面，底部显示导航栏，挡住进度条 |
| [I8407H](https://gitee.com/open_harmony/dashboard?issue_id=I8407H) | 【OpenHarmony  3.2.15.1】【RK3568】【压力测试】【ToC】【低概率】【wukong】出现1次，com.ohos.smartperf应用出现jscrash，内容信息为initDb。 |
| [I844Q9](https://gitee.com/open_harmony/dashboard?issue_id=I844Q9) | 【OpenHarmony 3.2.15.2】【应用子系统】【RK3568】【必现_5/5】图库卡片封面不能自动刷新 |
| [I84F9F](https://gitee.com/open_harmony/dashboard?issue_id=I84F9F) | 【OpenHarmony 3.2.15.2】【应用子系统】【标准系统】【必现_5/5】大图浏览和宫格界面选择状态不一致 |
| [I84FAO](https://gitee.com/open_harmony/dashboard?issue_id=I84FAO) | 【OpenHarmony 3.2.15.2】【应用子系统】【RK3568】【必现_5/5】RK锁屏状态下，给RK发短信，锁屏界面无短信通知 |
| [I84IB2](https://gitee.com/open_harmony/dashboard?issue_id=I84IB2) | 【OpenHarmony  3.2.15.2】【应用子系统】【RK3568】【必现_5/5】相机录像时打开最近任务，最近任务列表中相机未显示运行界面截图 |
| [I86PMC](https://gitee.com/open_harmony/dashboard?issue_id=I86PMC) | 【OpenHarmony 3.2.15.3】【应用子系统】【标准系统】【必现_5/5】图库照片镜像后大小和分辨率不一致 |
| [I86Y2L](https://gitee.com/open_harmony/dashboard?issue_id=I86Y2L) | 【OpenHarmony3.2】【acts】【3568】【必现-5/5】ActsDeqpgles2TestSuite套件执行失败 |
| [I88A1G](https://gitee.com/open_harmony/dashboard?issue_id=I88A1G) | 【OpenHarmony 3.2.15.3】【RK3568】【压力测试】【ToC】【低概率】【wukong】出现1次  由进程media_service下的IPC_3_10819线程导致libaudio_client.z.so 出现cppcrash |
| [I89423](https://gitee.com/open_harmony/dashboard?issue_id=I89423) | 【OpenHarmony  3.2.15.3】【应用子系统】【RK3568】【必现_5/5】通话中back键返回桌面，再点击状态栏绿条返回通话界面，挂断电话后通话界面不消失 |
| [I8952L](https://gitee.com/open_harmony/dashboard?issue_id=I8952L) | 【OpenHarmony  3.2.15.3】【应用子系统】【RK3568】【必现_5/5】图库日视图中，第二天00:00~07:59的照片和第一天08:00~23:59的照片会放在同一个日期下显示 |
| [I89FCI](https://gitee.com/open_harmony/dashboard?issue_id=I89FCI) | 【OpenHarmony  3.2.15.3】【RK3568】【压力测试】【ToC】【低概率】【wukong】出现1次  由进程ohos.samples.distributedmusicplayer下的jsThread-1线程导致libfeatureability.z.so  出现cppcrash |
| [I8EJ62](https://gitee.com/open_harmony/dashboard?issue_id=I8EJ62) | 【OpenHarmony 3.2.15.3】【netmanager_base】【RK3568】【必现】出现netmanager的avc告警日志 |
| [I8EQPY](https://gitee.com/open_harmony/dashboard?issue_id=I8EQPY) | 【OpenHarmony 3.2.15.4】【应用子系统】【RK3568】【必现_5/5】图库中新建相册不显示 |

## 修复安全issue列表

  **表4** 修复安全issue列表

| ISSUE                                                        | 问题描述                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [I73C2J](https://gitee.com/open_harmony/dashboard?issue_id=I73C2J) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-2513           |
| [I7HIH8](https://gitee.com/open_harmony/dashboard?issue_id=I7HIH8) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-1206           |
| [I7JBBQ](https://gitee.com/open_harmony/dashboard?issue_id=I7JBBQ) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-37453          |
| [I7QH9Y](https://gitee.com/open_harmony/dashboard?issue_id=I7QH9Y) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-4911           |
| [I7QHAP](https://gitee.com/open_harmony/dashboard?issue_id=I7QHAP) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-4908           |
| [I7QR3I](https://gitee.com/open_harmony/dashboard?issue_id=I7QR3I) | 【漏洞】 【OpenHarmony-3.2-Release】 lj-linux-131204684-0541812 |
| [I7U56X](https://gitee.com/open_harmony/dashboard?issue_id=I7U56X) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-4357           |
| [I7U57G](https://gitee.com/open_harmony/dashboard?issue_id=I7U57G) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-4351           |
| [I7U57L](https://gitee.com/open_harmony/dashboard?issue_id=I7U57L) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-4354           |
| [I7U583](https://gitee.com/open_harmony/dashboard?issue_id=I7U583) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-4353           |
| [I7U59K](https://gitee.com/open_harmony/dashboard?issue_id=I7U59K) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-4362           |
| [I7U5A4](https://gitee.com/open_harmony/dashboard?issue_id=I7U5A4) | 【漏洞】 【OpenHarmony-3.2-Release】 lj-linux-131204684-0547797 |
| [I7U5A9](https://gitee.com/open_harmony/dashboard?issue_id=I7U5A9) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-4352           |
| [I7U7HY](https://gitee.com/open_harmony/dashboard?issue_id=I7U7HY) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-4355           |
| [I7UZ5X](https://gitee.com/open_harmony/dashboard?issue_id=I7UZ5X) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-40283          |
| [I7V73B](https://gitee.com/open_harmony/dashboard?issue_id=I7V73B) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-4385           |
| [I7V74X](https://gitee.com/open_harmony/dashboard?issue_id=I7V74X) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-4387           |
| [I7V8FJ](https://gitee.com/open_harmony/dashboard?issue_id=I7V8FJ) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-4427           |
| [I7VS48](https://gitee.com/open_harmony/dashboard?issue_id=I7VS48) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-4459           |
| [I7W2OE](https://gitee.com/open_harmony/dashboard?issue_id=I7W2OE) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-0850           |
| [I7W6NH](https://gitee.com/open_harmony/dashboard?issue_id=I7W6NH) | 【漏洞】 【OpenHarmony-3.2-Release】 lj-linux-131204684-0557737 |
| [I7XPVH](https://gitee.com/open_harmony/dashboard?issue_id=I7XPVH) | 【漏洞】 【OpenHarmony-3.2-Release】 lj-linux-131204684-0566914 |
| [I7XT56](https://gitee.com/open_harmony/dashboard?issue_id=I7XT56) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-3777           |
| [I7XXDW](https://gitee.com/open_harmony/dashboard?issue_id=I7XXDW) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-4572           |
| [I7ZATO](https://gitee.com/open_harmony/dashboard?issue_id=I7ZATO) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-4208           |
| [I7ZATV](https://gitee.com/open_harmony/dashboard?issue_id=I7ZATV) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-4207           |
| [I7ZATY](https://gitee.com/open_harmony/dashboard?issue_id=I7ZATY) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-4206           |
| [I7ZBXP](https://gitee.com/open_harmony/dashboard?issue_id=I7ZBXP) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-4623           |
| [I7ZBXS](https://gitee.com/open_harmony/dashboard?issue_id=I7ZBXS) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-4622           |
| [I7ZLCB](https://gitee.com/open_harmony/dashboard?issue_id=I7ZLCB) | 【漏洞】 【OpenHarmony-3.2-Release】 lj-linux-131204684-0568539 |
| [I7ZV0X](https://gitee.com/open_harmony/dashboard?issue_id=I7ZV0X) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-4762           |
| [I7ZV0Z](https://gitee.com/open_harmony/dashboard?issue_id=I7ZV0Z) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-4763           |
| [I7ZVJW](https://gitee.com/open_harmony/dashboard?issue_id=I7ZVJW) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-4807           |
| [I819HJ](https://gitee.com/open_harmony/dashboard?issue_id=I819HJ) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-4921           |
| [I81J37](https://gitee.com/open_harmony/dashboard?issue_id=I81J37) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-4863           |
| [I81T8G](https://gitee.com/open_harmony/dashboard?issue_id=I81T8G) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-4904           |
| [I82FGR](https://gitee.com/open_harmony/dashboard?issue_id=I82FGR) | 【漏洞】 【OpenHarmony-3.2-Release】 lj-linux-131204684-0572429 |
| [I83HEM](https://gitee.com/open_harmony/dashboard?issue_id=I83HEM) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-2163           |
| [I83SS5](https://gitee.com/open_harmony/dashboard?issue_id=I83SS5) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-39615          |
| [I84KG1](https://gitee.com/open_harmony/dashboard?issue_id=I84KG1) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2020-24187          |
| [I84N7U](https://gitee.com/open_harmony/dashboard?issue_id=I84N7U) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-42753          |
| [I84PVS](https://gitee.com/open_harmony/dashboard?issue_id=I84PVS) | 【漏洞】 【OpenHarmony-3.2-Release】 LJ-2023-0102259         |
| [I86CNK](https://gitee.com/open_harmony/dashboard?issue_id=I86CNK) | 【漏洞】 【OpenHarmony-3.2-Release】 lj-linux-131204684-0577967 |
| [I86KSB](https://gitee.com/open_harmony/dashboard?issue_id=I86KSB) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-38545          |
| [I86P29](https://gitee.com/open_harmony/dashboard?issue_id=I86P29) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-39194          |
| [I86WMZ](https://gitee.com/open_harmony/dashboard?issue_id=I86WMZ) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-4128           |
| [I86WNG](https://gitee.com/open_harmony/dashboard?issue_id=I86WNG) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-3420           |
| [I86WNW](https://gitee.com/open_harmony/dashboard?issue_id=I86WNW) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-5217           |
| [I86WOQ](https://gitee.com/open_harmony/dashboard?issue_id=I86WOQ) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-45322          |
| [I870HM](https://gitee.com/open_harmony/dashboard?issue_id=I870HM) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-44487          |
| [I873CB](https://gitee.com/open_harmony/dashboard?issue_id=I873CB) | 【漏洞】 【OpenHarmony-3.2-Release】 LJ-2023-0105149         |
| [I877V3](https://gitee.com/open_harmony/dashboard?issue_id=I877V3) | 【漏洞】 【OpenHarmony-3.2-Release】 lj-linux-131204699-0582367 |
| [I877V6](https://gitee.com/open_harmony/dashboard?issue_id=I877V6) | 【漏洞】 【OpenHarmony-3.2-Release】 LJ-2023-0105164         |
| [I87AR1](https://gitee.com/open_harmony/dashboard?issue_id=I87AR1) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-38545          |
| [I87BZG](https://gitee.com/open_harmony/dashboard?issue_id=I87BZG) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-38546          |
| [I87CVV](https://gitee.com/open_harmony/dashboard?issue_id=I87CVV) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-42754          |
| [I87CWV](https://gitee.com/open_harmony/dashboard?issue_id=I87CWV) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-39189          |
| [I87CX1](https://gitee.com/open_harmony/dashboard?issue_id=I87CX1) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-39193          |
| [I87CX3](https://gitee.com/open_harmony/dashboard?issue_id=I87CX3) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-39192          |
| [I87QBZ](https://gitee.com/open_harmony/dashboard?issue_id=I87QBZ) | 【漏洞】 【OpenHarmony-3.2-Release】 lj-linux-131204684-0583126 |
| [I87ZQ2](https://gitee.com/open_harmony/dashboard?issue_id=I87ZQ2) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-5218           |
| [I87ZQT](https://gitee.com/open_harmony/dashboard?issue_id=I87ZQT) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-5484           |
| [I8846X](https://gitee.com/open_harmony/dashboard?issue_id=I8846X) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-45853          |
| [I88GIQ](https://gitee.com/open_harmony/dashboard?issue_id=I88GIQ) | 【漏洞】 【OpenHarmony-3.2-Release】 lj-linux-131204684-0611977 |
| [I88GIS](https://gitee.com/open_harmony/dashboard?issue_id=I88GIS) | 【漏洞】 【OpenHarmony-3.2-Release】 lj-linux-131204684-0611988 |
| [I894HL](https://gitee.com/open_harmony/dashboard?issue_id=I894HL) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-40474          |
| [I894IR](https://gitee.com/open_harmony/dashboard?issue_id=I894IR) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-40475          |
| [I894JL](https://gitee.com/open_harmony/dashboard?issue_id=I894JL) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-40476          |
| [I8B1VW](https://gitee.com/open_harmony/dashboard?issue_id=I8B1VW) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-5717           |
| [I8BB0I](https://gitee.com/open_harmony/dashboard?issue_id=I8BB0I) | 【漏洞】 【OpenHarmony-3.2-Release】 lj-linux-131204684-0620866 |
| [I8BKEB](https://gitee.com/open_harmony/dashboard?issue_id=I8BKEB) | 【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-5472           |

## 遗留缺陷列表

  **表5** 遗留缺陷列表

| ISSUE | 问题描述 | 影响 | 计划解决日期 |
| ----- | -------- | ---- | ------------ |
| /     | /        | /    | /            |

