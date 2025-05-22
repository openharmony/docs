# OpenHarmony 4.1.2 Release


## 版本概述

当前版本在OpenHarmony 4.1.1 Release的基础上，主要修复了linux kernel等开源组件的安全漏洞，增强了系统安全性。修复了部分功能和系统稳定性的issue，增强了系统稳定性。

## 配套关系

**表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 |
| -------- | -------- | -------- |
| OpenHarmony | 4.1.2 Release | NA |
| Public SDK | Ohos_sdk_public 4.1.8.5 (API Version 11 Release) | 面向应用开发者提供，不包含需要使用系统权限的系统接口。 |
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
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v4.1.2-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**方式二**

通过repo + https 下载。

从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
```
repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v4.1.2-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### 从镜像站点获取


**表2** 获取源码路径

| 版本源码                                | **版本信息** | **下载站点**                                                 | **SHA256校验码**                                             | **软件包容量** |
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| 全量代码（标准、轻量和小型系统）        | 4.1.2 Release   | [站点](https://repo.huaweicloud.com/openharmony/os/4.1.2-Release/code-v4.1.2-Release.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1.2-Release/code-v4.1.2-Release.tar.gz.sha256) | 34.5 GB |
| Hi3861解决方案（二进制）        | 4.1.2 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/4.1.2-Release/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1.2-Release/hispark_pegasus.tar.gz.sha256) | 27.0 MB |
| Hi3516解决方案-LiteOS（二进制） | 4.1.2Release   | [站点](https://repo.huaweicloud.com/openharmony/os/4.1.2-Release/hispark_taurus_LiteOS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1.2-Release/hispark_taurus_LiteOS.tar.gz.sha256) | 320.1 MB |
| Hi3516解决方案-Linux（二进制）  | 4.1.2 Release   | [站点](https://repo.huaweicloud.com/openharmony/os/4.1.2-Release/hispark_taurus_Linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1.2-Release/hispark_taurus_Linux.tar.gz.sha256) | 217.4 MB |
| RK3568标准系统解决方案（二进制）        | 4.1.2 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/4.1.2-Release/dayu200_standard_arm32.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1.2-Release/dayu200_standard_arm32.tar.gz.sha256) | 8.4 GB |
| 标准系统Public SDK包（Mac）             | 4.1.8.5 | [站点](https://repo.huaweicloud.com/openharmony/os/4.1.2-Release/ohos-sdk-mac-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1.2-Release/ohos-sdk-mac-public.tar.gz.sha256) | 913.3 MB |
| 标准系统Public SDK包（Mac-M1）             | 4.1.8.5 | [站点](https://repo.huaweicloud.com/openharmony/os/4.1.2-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1.2-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) | 884.0 MB |
| 标准系统Public SDK包（Windows/Linux）   | 4.1.8.5 | [站点](https://repo.huaweicloud.com/openharmony/os/4.1.2-Release/ohos-sdk-windows_linux-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1.2-Release/ohos-sdk-windows_linux-public.tar.gz.sha256) | 2.2 GB |


## 更新说明

 API接口无变更。

## 修复缺陷和安全问题列表

**表3** 修复缺陷ISSUE列表

| ISSUE单 | 问题描述 |
| -------- | -------- |
| [IB7R74](https://gitee.com/openharmony/applications_photos/issues/IB7R74?from=project-issue) | 【RK3568】备忘录中插入图库图片，选择第二张，实际插入第一张   |
| [IB7KDL](https://gitee.com/openharmony/applications_screenlock/issues/IB7KDL?from=project-issue) | 【RK3568】锁屏密码取消后再次锁屏解锁还是要输入密码，且输入上次密码失效 |
| [IB7KDI](https://gitee.com/openharmony/applications_screenlock/issues/IB7KDI?from=project-issue) | 【RK3568】混合密码解锁界面，输入的第一个字符显示不完整       |
| [IB7KGX](https://gitee.com/openharmony/applications_launcher/issues/IB7KGX?from=project-issue) | 【RK3568】正常刷机桌面图标布局混乱                           |
| [IB8YCY](https://gitee.com/openharmony/xts_acts/issues/IB8YCY?from=project-issue) | 【RK3568】ACTS套件ActsNetManagerHttpEtsTest套件执行失败      |
| [IAPYJN](https://gitee.com/openharmony/multimedia_media_lite/issues/IAPYJN?from=project-issue) | 【小型系统liteos】相册中视频播放完毕后重新点击播放会出现蓝屏 |
| [IB21XU](https://gitee.com/openharmony/xts_hats/issues/IB21XU?from=project-issue) | 【RK3568】HATS执行HatsHdfAudioIdlRenderAdditionalTest&HatsHdfAudioIdlCaptureAdditionalTest套件执行失败 |
| [IB68WS](https://gitee.com/openharmony/xts_acts/issues/IB68WS?from=project-issue) | 【RK3568】ACTS套件ActsAceWebEnhancedTestTwo执行有一个fail |
| [I90N04](https://gitee.com/openharmony/applications_settings/issues/I90N04?from=project-issue) | 【RK3568】设置-系统-恢复出厂设置，点击进入恢复出厂设置页面，页面文本错乱，无重置按钮 |
| [IAX7SV](https://gitee.com/openharmony/xts_acts/issues/IAX7SV?from=project-issue) | 【RK3568】acts执行ActsAceWebEnhancedTestTwo套件有一个用例fail |
| [I9PQ6I](https://gitee.com/openharmony-sig/ability_form_runtime/issues/I9PQ6I?from=project-issue) | 【RK3568】添加静态卡片，几秒后透明 |
| [IATPGW](https://gitee.com/openharmony/xts_acts/issues/IATPGW?from=project-issue) | 【RK3568】acts执行ActsRequestAuthorityTest套件有6个用例fail |
| [I9NDZE](https://gitee.com/openharmony/accessibility/issues/I9NDZE?from=project-issue) | 【RK3568】重启手机、升级应用 切换账号等操作,已开启的服务不能重新自动拉起 |
| [I9SI9E](https://gitee.com/openharmony/web_webview/issues/I9SI9E?from=project-issue) | 【RK3568】过滚动功能失效 |
| [I9PQFE](https://gitee.com/openharmony/window_window_manager/issues/I9PQFE?from=project-issue) | 【RK3568】配置装饰栏后，点击分屏按钮，点击待分屏的快照，不能组成分屏 |
| [IANK0I](https://gitee.com/openharmony/applications_launcher/issues/IANK0I?from=project-issue) | 【RK3568】添加服务卡片到桌面失败 |
| [I90GOK](https://gitee.com/openharmony/applications_launcher/issues/I90GOK?from=project-issue) | 【RK3568】桌面存在空白页，新建文件夹，点击+号将桌面应用加入文件夹后，空白页消失 |
| [I9SMPC](https://gitee.com/openharmony/graphic_graphic_2d/issues/I9SMPC?from=project-issue) | 【RK3568】无障碍中开启颜色反转后，桌面和设置界面不生效 |
| [I9RMYL](https://gitee.com/openharmony/notification_distributed_notification_service/issues/I9RMYL?from=project-issue) | 【RK3568】点击WantAgent通知无法拉起另一个应用 |
| [I9RZLH](https://gitee.com/openharmony/multimedia_media_lite/issues/I9RZLH?from=project-issue) | 【小型系统liteos】相册中视频播放完毕后重新点击播放会出现蓝屏 |
| [IAHYNM](https://gitee.com/openharmony/applications_photos/issues/IAHYNM?from=project-issue) | 【RK3568】照片页手动选中不同日期分类的图片后删除，只能删除已选中图片中日期分类靠前的图片 |
| [I97G7Y](https://gitee.com/openharmony/multimedia_av_session/issues/I97G7Y?from=project-issue) | 【RK3568】MediaProvider:上一首、下一首只切换歌曲图片，没有切换文本，文本信息一直是first  music。MediaController获取不到MediaProvider音乐信息 |
| [I9OF7E](https://gitee.com/openharmony/update_update_app/issues/I9OF7E?from=project-issue) | 【RK3568】升级安装成功或失败,重启设备后,通知中心没有消息提醒 |
| [I9CX99](https://gitee.com/openharmony/arkcompiler_ets_runtime/issues/I9CX99?from=project-issue) | 【RK3568】虚拟机部分接口对比4.0劣化，还需要进一步分析 |
| [I98KLY](https://gitee.com/openharmony/arkui_ace_engine/issues/I98KLY?from=project-issue) | 【RK3568】abilityComponent有问题，不应该走windowpattern的OnAttachToFrameNode |
| [I966DO](https://gitee.com/openharmony/multimedia_audio_framework/issues/I966DO?from=project-issue) | 【RK3568】系统服务未通过fuzz测试 |
| [I9JX99](https://gitee.com/openharmony/arkui_ace_engine/issues/I9JX99?from=project-issue) | 【RK3568】Tabs子页签和自定义页签混合使用场景，子页签第二个直接连页签文本也不显示选中态 |
| [IAEQQV](https://gitee.com/openharmony/applications_systemui/issues/IAEQQV?from=project-issue) | 【RK3568】连接wifi后出现“无法打开此文件”弹窗 |
| [I9TEVB](https://gitee.com/openharmony/window_window_manager/issues/I9TEVB?from=project-issue) | 【RK3568】验证支持通过窗口设置屏幕亮度恢复默认值的能力，点击“Default brightness”按钮，亮度无变化 |
| [I9R4Y1](https://gitee.com/openharmony/multimodalinput_input/issues/I9R4Y1?from=project-issue) | 【RK3568】连接鼠标，切换到横屏，鼠标移动方向、点击位置与光标位置不一致 |
| [IA9ONV](https://gitee.com/openharmony/window_window_manager/issues/IA9ONV?from=project-issue) | 【RK3568】back键退出应用后，多任务界面任务卡片无最后运行界面截图 |
| [I9UKQ3](https://gitee.com/openharmony/applications_app_samples/issues/I9UKQ3?from=project-issue) | 【RK3568】分布式关系型数据库DistributedRdb，点击连接设备，设备列表显示为空 |
| [I9UKNG](https://gitee.com/openharmony/applications_app_samples/issues/I9UKNG?from=project-issue) | 【RK3568】【sample】【Browser】Browser 主页没有新建按钮 |
| [I8TS8U](https://gitee.com/openharmony/kernel_liteos_a/issues/I8TS8U?from=project-issue) | 【RK3568】容器测试堵塞 |
| [I9TJ5N](https://gitee.com/openharmony/multimodalinput_input/issues/I9TJ5N?from=project-issue) | 【RK3568】音量条概率消失，物理按键失效 |
| [I90FTY](https://gitee.com/openharmony/applications_launcher/issues/I90FTY?from=project-issue) | 【RK3568】桌面存在文件夹，对文件夹重命名时输入名称显示不全（gjpqy等） |
| [I9OETO](https://gitee.com/openharmony/update_update_app/issues/I9OETO?from=project-issue) | 【RK3568】稍后安装和倒计时按钮显示白屏 没有文字 |
| [IAF5SS](https://gitee.com/openharmony/security_privacy_center/issues/IAF5SS?from=project-issue) | 【RK3568】用户证书弹窗，点击启用/禁用开关，弹窗会右移一部分，超出界面显示 |
| [I9GLKF](https://gitee.com/openharmony/applications_app_samples/issues/I9GLKF?from=project-issue) | 【RK3568】【Sample】手机拨打电话通话中，详细信息。通话状态，没有显示电话号码 |
| [I9OZC2](https://gitee.com/openharmony/multimodalinput_input/issues/I9OZC2?from=project-issue) | 【RK3568】设置鼠标光标样式值为41(对应pointer.PointerStyle.CURSOR_CIRCLE)时，鼠标光标不可见 |
| [IA5EDU](https://gitee.com/openharmony/xts_acts/issues/IA5EDU?from=project-issue) | 【RK3568】4.1执行XTS测试ActsNativeAVScreenCaptureTest套件执行失败 |
| [I9UKT8](https://gitee.com/openharmony/ability_dmsfwk/issues/I9UKT8?from=project-issue) | 【RK3568】版本兼容性DctsDmsHapTest测试套用例failed |
| [I9VJLA](https://gitee.com/openharmony/multimedia_audio_framework/issues/I9VJLA?from=project-issue) | 【RK3568】系统内录读取资源失败 |
| [I9F8M0](https://gitee.com/openharmony/applications_app_samples/issues/I9F8M0?from=project-issue) | 【RK3568】CertificateFramework,文本框最大输入字符限制为100，存在生成的数据长度大于100如592/100，显示不太友好 |
| [I9PK5K](https://gitee.com/openharmony/developtools_profiler/issues/I9PK5K?from=project-issue) | 【RK3568】双击测试报告内的曲线图，SP应用闪退。 |
| [I93ONW](https://gitee.com/openharmony/drivers_peripheral/issues/I93ONW?from=project-issue) | 【RK3568】rkusb相机dumper出来的图片命名的分辨率与实际不符 |
| [I9SSRV](https://gitee.com/openharmony/arkcompiler_runtime_core/issues/I9SSRV?from=project-issue) | 【RK3568】runtime_core_host_unittest UT测试存在失败项 |
| [I9PIQK](https://gitee.com/openharmony/applications_notes/issues/I9PIQK?from=project-issue) | 【RK3568】备忘录更改文本缩进后保存退出，再次打开文本无缩进 |
| [I9QC3M](https://gitee.com/openharmony/xts_acts/issues/I9QC3M?from=project-issue) | 【RK3568】acts测试套优化 |
| [I9R5MJ](https://gitee.com/openharmony/bundlemanager_bundle_framework/issues/I9R5MJ?from=project-issue) | 【RK3568】调用verifyAbc接口放置非法abc文件后，安装目录下存在abc文件 |
| [I934K9](https://gitee.com/openharmony/testfwk_arkxtest/issues/I934K9?from=project-issue) | 【RK3568】assertPromiseIs相关断言功能异常 |
| [I9PPPN](https://gitee.com/openharmony/systemabilitymgr_samgr/issues/I9PPPN?from=project-issue) | 【RK3568】打开日志落盘重启设备，重启后打印日志"SystemWaitParameter failed!" |
| [I9Q6OD](https://gitee.com/openharmony/xts_dcts/issues/I9Q6OD?from=project-issue) | 【RK3568】4.1release测试套概率性出现测试套失败问题 |
| [I9NCRP](https://gitee.com/openharmony/drivers_hdf_core/issues/I9NCRP?from=project-issue) | 【RK3568】执行命令 ./hdf_dbg -q -1 回显异常 |
| [I9OWYO](https://gitee.com/openharmony/xts_acts/issues/I9OWYO?from=project-issue) | 【RK3568】安全控件部分用例存在失败情况 |

**表4** 修复安全问题列表

| ISSUE单                                                      | 问题描述                                                     |
| :----------------------------------------------------------- | ------------------------------------------------------------ |
| [IB3TKK](https://gitee.com/openharmony/third_party_wpa_supplicant/issues/IB3TKK?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】wpa  supplicant组件存在漏洞CVE-2024-5290 |
| [IB8L9Y](https://gitee.com/openharmony/kernel_linux_5.10/issues/IB8L9Y?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】 CVE-2024-50150           |
| [IB8LVR](https://gitee.com/openharmony/kernel_linux_5.10/issues/IB8LVR?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2024-50228 |
| [IB8MCA](https://gitee.com/openharmony/kernel_linux_5.10/issues/IB8MCA?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2024-50262 |
| [IB8MEM](https://gitee.com/openharmony/kernel_linux_5.10/issues/IB8MEM?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2024-50301 |
| [IB8NDV](https://gitee.com/openharmony/third_party_skia/issues/IB8NDV?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】skia组件存在漏洞CVE-2024-8636 |
| [IB8ND4](https://gitee.com/openharmony/third_party_skia/issues/IB8ND4?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】skia组件存在漏洞CVE-2024-43091 |
| [IB5RJE](https://gitee.com/openharmony/kernel_linux_5.10/issues/IB5RJE?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2024-49883 |
| [IB3RXG](https://gitee.com/openharmony/third_party_grpc/issues/IB3RXG?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】 CVE-2023-33953           |
| [IB2ZTU](https://gitee.com/openharmony/kernel_linux_5.10/issues/IB2ZTU?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】 CVE-2024-50067           |
| [IAX809](https://gitee.com/openharmony/kernel_linux_5.10/issues/IAX809?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】 CVE-2024-41049           |
| [IAQ16Y](https://gitee.com/openharmony/kernel_linux_5.10/issues/IAQ16Y?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】 CVE-2024-44987           |
| [IAQ15E](https://gitee.com/openharmony/kernel_linux_5.10/issues/IAQ15E?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】 CVE-2024-43882           |
| [I9TCEB](https://gitee.com/openharmony/build/issues/I9TCEB?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】kosample.origin.ko 存在安全编译选项问题，请处理 |
| [I9UV4W](https://gitee.com/openharmony/third_party_openssl/issues/I9UV4W?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】CVE-2023-4807             |
| [I9UVFZ](https://gitee.com/openharmony/third_party_zlib/issues/I9UVFZ?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】CVE-2023-45853            |
| [I9UV9E](https://gitee.com/openharmony/third_party_openssl/issues/I9UV9E?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】CVE-2023-5363             |
| [I9UUVH](https://gitee.com/openharmony/third_party_mbedtls/issues/I9UUVH?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】CVE-2024-23775            |
| [IAI3T3](https://gitee.com/openharmony/kernel_linux_5.10/issues/IAI3T3?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】 CVE-2023-52672           |
| [IAI3TF](https://gitee.com/openharmony/kernel_linux_5.10/issues/IAI3TF?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】 CVE-2024-42160           |
| [IAI3VC](https://gitee.com/openharmony/kernel_linux_5.10/issues/IAI3VC?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】 CVE-2024-41087           |
| [IAI3VS](https://gitee.com/openharmony/kernel_linux_5.10/issues/IAI3VS?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】 CVE-2024-41012           |
| [IAI3XX](https://gitee.com/openharmony/kernel_linux_5.10/issues/IAI3XX?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】 CVE-2024-42154           |
| [IAI3YK](https://gitee.com/openharmony/kernel_linux_5.10/issues/IAI3YK?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】 CVE-2024-42161           |
| [IAI3SI](https://gitee.com/openharmony/kernel_linux_5.10/issues/IAI3SI?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】 CVE-2024-36031           |
| [IAEK1E](https://gitee.com/openharmony/kernel_linux_5.10/issues/IAEK1E?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】 CVE-2024-39495           |
| [IA4KT2](https://gitee.com/openharmony/kernel_linux_5.10/issues/IA4KT2?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】 CVE-2024-36894           |
| [IAAC05](https://gitee.com/openharmony/kernel_linux_5.10/issues/IAAC05?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】 CVE-2024-38577           |
| [IAABZK](https://gitee.com/openharmony/kernel_linux_5.10/issues/IAABZK?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】 CVE-2024-38588           |
| [IABPB5](https://gitee.com/openharmony/kernel_linux_5.10/issues/IABPB5?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】 CVE-2024-36971           |
| [I9TCOO](https://gitee.com/openharmony/kernel_linux_5.10/issues/I9TCOO?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2024-27043 |
| [I9TCEJ](https://gitee.com/openharmony/kernel_linux_5.10/issues/I9TCEJ?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】 CVE-2024-26934           |
| [I9TC6R](https://gitee.com/openharmony/kernel_linux_5.10/issues/I9TC6R?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】 CVE-2021-47474           |
| [IA47RU](https://gitee.com/openharmony/kernel_linux_5.10/issues/IA47RU?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】 CVE-2024-36904           |
| [IA4BS6](https://gitee.com/openharmony/kernel_linux_5.10/issues/IA4BS6?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】 CVE-2024-36899           |
| [I9UZ0X](https://gitee.com/openharmony/kernel_linux_5.10/issues/I9UZ0X?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2021-46996 |
| [I9UYU0](https://gitee.com/openharmony/kernel_linux_5.10/issues/I9UYU0?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】linux kernel组件存在漏洞CVE-2019-25162 |
| [I9TCDG](https://gitee.com/openharmony/kernel_linux_5.10/issues/I9TCDG?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】 CVE-2021-47479           |
| [I9TCCK](https://gitee.com/openharmony/kernel_linux_5.10/issues/I9TCCK?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】 CVE-2021-47521           |
| [I9TCBF](https://gitee.com/openharmony/kernel_linux_5.10/issues/I9TCBF?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】 CVE-2021-47506           |
| [I9TCAI](https://gitee.com/openharmony/kernel_linux_5.10/issues/I9TCAI?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】 CVE-2021-47485           |
| [I9TC9M](https://gitee.com/openharmony/kernel_linux_5.10/issues/I9TC9M?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】 CVE-2021-47483           |
| [I9O1FB](https://gitee.com/openharmony/third_party_ffmpeg/issues/I9O1FB?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】 CVE-2024-31578           |
| [I9OU4B](https://gitee.com/openharmony/kernel_linux_5.10/issues/I9OU4B?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】 CVE-2024-26883           |
| [I9OU4O](https://gitee.com/openharmony/kernel_linux_5.10/issues/I9OU4O?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】 CVE-2024-26885           |
| [I9OU3Z](https://gitee.com/openharmony/kernel_linux_5.10/issues/I9OU3Z?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】 CVE-2024-26884           |
| [I9OU3I](https://gitee.com/openharmony/kernel_linux_5.10/issues/I9OU3I?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】 CVE-2022-48655           |
| [I9IVLW](https://gitee.com/openharmony/third_party_curl/issues/I9IVLW?from=project-issue) | 【漏洞】【OpenHarmony-4.1-Release】 CVE-2024-2398            |

## 遗留缺陷列表

**表5** 遗留缺陷列表

| ISSUE | 问题描述 | 影响 | 计划解决日期 |
| :------- | :------- | :------- | :------- |
| / | /        | /    | /            |
