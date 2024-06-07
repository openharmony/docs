# OpenHarmony 4.1.1 Release


## 版本概述

当前版本在OpenHarmony 4.1 Release的基础上，修复了修复了部分系统稳定性的issue，增强了系统稳定性。更新配套的SDK版本。

## 配套关系

**表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 | 
| -------- | -------- | -------- |
| OpenHarmony | 4.1.1 Release | NA | 
| Public SDK | Ohos_sdk_public 4.1.7.8 (API Version 11 Release) | 面向应用开发者提供，不包含需要使用系统权限的系统接口。 | 
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
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v4.1.1-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**方式二**

通过repo + https 下载。

从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
```
repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v4.1.1-Release --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### 从镜像站点获取


**表2** 获取源码路径

| 版本源码                                | **版本信息** | **下载站点**                                                 | **SHA256校验码**                                             | **软件包容量** |
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| 全量代码（标准、轻量和小型系统）        | 4.1.1 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/4.1.1-Release/code-v4.1.1-Release.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1.1-Release/code-v4.1.1-Release.tar.gz.sha256) | 31.9 GB |
| Hi3861解决方案（二进制）        | 4.1.1 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/4.1.1-Release/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1.1-Release/hispark_pegasus.tar.gz.sha256) | 29.2 MB |
| Hi3516解决方案-LiteOS（二进制） | 4.1.1 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/4.1.1-Release/hispark_taurus_LiteOS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1.1-Release/hispark_taurus_LiteOS.tar.gz.sha256) | 318.7 MB |
| Hi3516解决方案-Linux（二进制）  | 4.1.1 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/4.1.1-Release/hispark_taurus_Linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1.1-Release/hispark_taurus_Linux.tar.gz.sha256) | 215.7 MB |
| RK3568标准系统解决方案（二进制）        | 4.1.1 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/4.1.1-Release/dayu200_standard_arm32.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1.1-Release/dayu200_standard_arm32.tar.gz.sha256) | 8.4 GB |
| 标准系统Public SDK包（Mac）             | 4.1.7.8 | [站点](https://repo.huaweicloud.com/openharmony/os/4.1.1-Release/ohos-sdk-mac-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1.1-Release/ohos-sdk-mac-public.tar.gz.sha256) | 841 MB |
| 标准系统Public SDK包（Mac-M1）             | 4.1.7.8  | [站点](https://repo.huaweicloud.com/openharmony/os/4.1.1-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1.1-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) | 897.8 MB |
| 标准系统Public SDK包（Windows/Linux）   | 4.1.7.8   | [站点](https://repo.huaweicloud.com/openharmony/os/4.1.1-Release/ohos-sdk-windows_linux-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/4.1.1-Release/ohos-sdk-windows_linux-public.tar.gz.sha256) | 2.2 GB |


## 更新说明

3.2.4 Release对比3.2.3 Release API接口无变更。

## 修复缺陷列表

**表3** 修复缺陷ISSUE列表

| ISSUE单 | 问题描述 | 
| -------- | -------- |
| I8WP8M | 移动桌面一个图标使之与另一图标重叠创建大文件夹，之后选中文件夹内的一个应用移出文件夹，重复此操作，launcher出现内存泄露，操作五分钟，内存泄漏约25M，操作一次泄露约673.68KB。 |
| I9A089 | 中等概率下进程foundation由于SERVICE_BLOCK出现sysfreeze。 |
| I90A2N | 一定概率下，进程com.ohos.systemui由于THREAD_BLOCK_6S卡在libeventhandler.z.so出现appfreeze。 |
| I9CGOZ | 有较高概率，进程com.ohos.camera由于THREAD_BLOCK_6S卡在libcamera_framework.z.so出现appfreeze。 |
| I8QH9S | 小概率在进程com.ohos.settingsdata下的os.settingsdata线程出现cppcrash，崩溃栈：libnative_appdatafwk.z.so。 |
| I963TL | 小概率因进程com.ohos.mms下的com.ohos.mms线程导致libark_jsruntime.so出现cppcrash。 |
| I98KIG | 小概率下进程com.ohos.camera由于THREAD_BLOCK_6S卡在libcamera_framework.z.so出现appfreeze。 |

## 遗留缺陷列表

**表4** 遗留缺陷列表

| ISSUE | 问题描述 | 影响 | 计划解决日期 | 
| -------- | -------- | -------- | -------- |
| I98AV0 | 点击设置里的位置信息开关，重复此操作，distributeddata进程出现内存泄露，操作五分钟，泄露约14M，操作一次泄露约95.57KB。 | 泄漏达到一定程度后造成系统卡顿。<br/>规避措施：退出当前界面内存可释放。 | 6月30日 |
| I9A9NO | 不停执行点击短信界面右上角新建短信和返回操作，5分钟短信应用内存上涨约50M，操作一次泄露约341.33KB。 | 泄漏达到一定程度后造成系统卡顿。<br/>规避措施：退出应用内存可释放。 | 6月30日 |
| I8QLRO | 小概率在进程bluetooth_servi下的Stack线程出现cppcrash，崩溃栈：libbtstack.z.so。 | 蓝牙服务出现异常后服务自动恢复，用户无异常感知。 | 6月30日 |
| I8TLYJ | 小概率在进程bluetooth_servi下的SaInit1线程出现cppcrash，崩溃栈：libbtstack.z.so。 | 蓝牙服务出现异常后服务自动恢复，用户无异常感知。 | 6月30日 |
| I8TM99 | 小概率在进程softbus_server下的softbus_server线程出现cppcrash，崩溃栈：libbtframework.z.so。 | 软总线服务出现异常后服务自动恢复，用户无异常感知。 | 6月30日 |
| I8VFJS | 小概率在进程com.ohos.settings下出现jscrash，栈名：ObservedPropertyAbstractPU。 | settings应用小概率出现闪退，退出应用内存可释放。 | 6月30日 |
| I98NGO | 小概率下进程com.ohos.settings由于THREAD_BLOCK_6S卡在libbtframework.z.so发生appfreeze。 | settings应用小概率出现闪退，退出应用内存可释放。 | 6月30日 |
| I963UO | 一定概率下，进程com.ohos.systemui下的RSRenderThread线程导致libEGL.so出现cppcrash。 | 系统会自动进入锁屏界面，重新解锁可恢复。 | 6月30日 |
| I9AYM2 | 小概率下进程com.ohos.note由于THREAD_BLOCK_6S卡在libweb_engine.so出现appfreeze。 | 备忘录应用界面卡顿。重启备忘录应用可恢复。 | 6月30日 |
| I9AEO0 | 小概率在进程com.ohos.settings出现APP_INPUT_BLOCK的appfreeze。 | settings应用无响应，重启应用可恢复。 | 6月30日 |
| I9635I | 设备极小概率自动重启。 | 影响可控，无需规避。 | 6月30日 |
| I96JJ7 | 小概率在进程com.ohos.note下的com.ohos.note线程出现cppcrash，崩溃栈：libace_compatible.z.so。 | 使用备忘录应用时可能出现闪退，重启应用可恢复。 | 6月30日 |
| I993H9 | 一定概率下进程com.ohos.smartperf由于THREAD_BLOCK_6S卡在libglobal_resmgr.z.so出现appfreeze。 | 用户在使用smartperf应用测试其他应用性能数据时，触发查看实时性能数据功能时，应用有卡顿。<br/>规避措施：系统会自动清理掉应用进程，重启smartperf可恢复。 | 6月30日 |
| I97U6G | 小概率下进程com.ohos.certmanager由于THREAD_BLOCK_6S卡在librender_service_client.z.so出现appfreeze。 | 证书管理应用Freeze后系统自动退出该应用。影响可控。 | 6月30日 |
| I98NFR | 小概率在进程com.ohos.smartperf下的ohos.smartperf线程出现cppcrash，崩溃栈：libwm.z.so。 | 会有很低概率导致应用退出，退出后重启应用可恢复。 | 6月30日 |
| I98AWP | 小概率在进程com.ohos.note下的com.ohos.note线程出现cppcrash，崩溃栈：libweb_engine.so。 | 备忘录可能出现闪退。重启应用可恢复。 | 6月30日 |
| I96ZWB | 设备组网后查不到对端设备。 | OpenHarmony 4.0设备和4.1设备使用分布式音频无法兼容和互通。影响可控。 | 6月30日 |
| I96CJL | 轻量级设备之间组网失败。 | 影响可控，暂无规避措施。 | 6月30日 |
