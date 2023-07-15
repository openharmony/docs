# OpenHarmony 3.2.1 Release


## 版本概述

当前版本在OpenHarmony 3.2 release的基础上，更新支持或优化增强的能力如下：
分布式数据管理：依照安全合规的要求uuid仅支持系统应用和SA，不再支持普通用应用，数据管理切换UUID，整改为普通应用可使用的新uuid(sha256(appId_uuid))。


## 配套关系

  **表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 |
| -------- | -------- | -------- |
| OpenHarmony | 3.2.1 Release | NA |
| Public SDK | Ohos_sdk_public 3.2.12.5 (API Version 9 Release) | 面向应用开发者提供，不包含需要使用系统权限的系统接口。通过DevEco Studio默认获取的SDK为Public SDK。 |
| HUAWEI DevEco Studio（可选） | 3.1 Release | OpenHarmony应用开发推荐使用。<br />[点击此处获取](https://developer.harmonyos.com/cn/develop/deveco-studio#download) |
| HUAWEI DevEco Device Tool（可选） | 3.1 Release | OpenHarmony智能设备集成开发环境推荐使用。<br />[点击此处获取](https://device.harmonyos.com/cn/develop/ide/) |

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

| 版本源码                                | **版本信息** | **下载站点**                                                 | **SHA256校验码**                                             | **软件包容量** |
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| 全量代码（标准、轻量和小型系统）        | 3.2.1 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/3.2.1/code-v3.2.1-Release.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2.1/code-v3.2.1-Release.tar.gz.sha256) | 21.8 GB |
| Hi3861解决方案（二进制）        | 3.2.1 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/3.2.1/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2.1/hispark_pegasus.tar.gz.sha256) | 22.9 MB |
| Hi3516解决方案-LiteOS（二进制） | 3.2.1 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/3.2.1/hispark_taurus_LiteOS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2.1/hispark_taurus_LiteOS.tar.gz.sha256) | 293.3 MB |
| Hi3516解决方案-Linux（二进制）  | 3.2.1 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/3.2.1/hispark_taurus_Linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2.1/hispark_taurus_Linux.tar.gz.sha256) | 174.6 MB |
| RK3568标准系统解决方案（二进制）        | 3.2.1 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/3.2.1/dayu200_standard_arm32.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2.1/dayu200_standard_arm32.tar.gz.sha256) | 3.9 GB |
| 标准系统Public SDK包（Mac）             | 3.2.12.5      | [站点](https://repo.huaweicloud.com/openharmony/os/3.2.1/ohos-sdk-mac-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2.1/ohos-sdk-mac-public.tar.gz.sha256) | 664.5 MB |
| 标准系统Public SDK包（Mac-M1）             | 3.2.12.5      | [站点](https://repo.huaweicloud.com/openharmony/os/3.2.1/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2.1/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) | 623.3 MB |
| 标准系统Public SDK包（Windows/Linux）   | 3.2.12.5      | [站点](https://repo.huaweicloud.com/openharmony/os/3.2.1/ohos-sdk-windows_linux-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2.1/ohos-sdk-windows_linux-public.tar.gz.sha256) | 1.6 GB |

## 更新说明

### API 

3.2.1 Release对比3.2 Release API接口无变更。

### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。

## 修复缺陷列表

  **表3** 修复缺陷ISSUE列表

| ISSUE单 | 问题描述 |
| -------- | -------- |
| I6U1H9 | GridCol的属性gridColOffset在IDE预览器中不支持预览。 |
| I6TMP3 | 长按应用进入图片预览，向后滑动150张卡片左右，点击添加卡片，桌面不显示卡片。 |
| I6RJTP | 设备蓝牙界面，点击对应的蓝牙耳机进行连接，当设备蓝牙耳机显示栏显示的状态为正在连接时，设备无法关闭蓝牙功能。在蓝牙设置页面点击开关按钮，页面无响应，有时还会出现页面闪退。 |
| I6TFXF | 【压力测试】【低概率】出现1次 由进程/system/bin/hiview下的sysevent_servic线程导致libjsoncpp.z.so出现crash。 |
| I6TS20 | 【压力测试】【低概率】出现2次，com.ohos.note进程下Chrome_IOThread发生cppcrash，信息为libweb_engine.so。 |
| I6TS25 | 【压力测试】【低概率】出现1次，com.ohos.note进程下com.ohos.note发生cppcrash，信息为libweb_engine.so。 |
| I6A80S | Web组件加载微博出现漏屏现象。 |
| I6VRJ8 | 【高概率】【wukong】出现8次，由进程com.ohos.note下的Chrome_IOThread线程导致libweb_engine.so出现cppcrash。 |
| I6YJHC | 【高概率】【wukong】出现9次由进程com.ohos.note下的com.ohos.note线程导致ld-musl-arm.so.1出现cppcrash。 |
| I6YT0V | 【高概率】【wukong】出现6次由进程com.ohos.note下的RSRenderThread线程导致libeventhandler.z.so出现crash。 |
| I6YSP4 | 【低概率1/10】【wukong】出现1次 由进程com.ohos.note下的com.ohos.note线程导致librender_service_base.z.so出现crash。 |
| I6Z5XW | 【高概率8/10】新建十几条条草稿，再逐一删除草稿，com.ohos.mms出现内存泄漏。 |
| I6YZGA | 【低概率1/10】【wukong】出现4次 由进程com.ohos.note下的RSRenderThread线程导致libskia_ohos.z.so 出现cppcrash。 |
| I64726<br/>I641A2 | 蓝牙功能接口bluetooth.pairDevice在与其他设备配对时无配对提示，与其他设备静默配对后通过蓝牙键盘、鼠标完全可控制设备。 |
| I6TRY1 | 【低概率】【wukong】出现1次 ，由进程com.ohos.note下的com.ohos.note线程导致libace.z.so出现cppcrash。 |
| I6TS3O | 【低概率】【wukong】出现3次 由进程 com.ohos.contacts下出现栈为libace.z.so出现appfreeze问题。 |
| I6TFT1 | 【低概率】出现2次，由进程com.example.actsgetcurrenttopabilitystageatest下的出现jscrash，栈名：anonymous/AssertException。 |
| I6TFUX | 【低概率】出现1次，由进程com.open.harmony.acetestfour下的events_emitter线程导致libemitter.z.so出现crash。 |
| I6TFXY | 【低概率】出现3次，由进程com.example.abilitymultiinstance下的出现jscrash，栈名：AssertException；由进程com.example.startabilityforresult下的出现jscrash，栈名：AssertException。 |
| I6TGJ2 | 【低概率】出现2次，由进程/system/bin/hiview下的usage_event_rep线程导致libhiviewbase.z.so出现crash。 |
| I6TR29 | 【低概率】出现1次，由进程com.ohos.smartperf下的com.ohos.smartp线程导致libace.z.so出现crash。 |
| I6TS0D | 【低概率】出现1次，由进程com.ohos.note下的Chrome_IOThread线程导致libace.z.so出现cppcrash。 |
| I6TS20 | 【低概率】出现2次，com.ohos.note进程下Chrome_IOThread发生cppcrash，信息为libweb_engine.so。 |
| I6TS25 | 【低概率】出现1次，com.ohos.note进程下com.ohos.note发生cppcrash，信息为libweb_engine.so。 |
| I6TUR9 | 【压力测试】【高概率】出现10次，com.ohos.mms应用出现appfreeze。 |
| I6TVCX | 【压力测试】【高概率】systemui出现内存泄漏，呈上升趋势。 |
| I6T09Y | 【压力测试】【低概率】出现1次由进程com.ohos.camera下的com.ohos.camera线程导致libpluginmanager.z.so出现crash。 |
| I6T0EO | 【压力测试】【低概率】出现2次由进程com.ohos.mms下的出现jscrash。 |
| I6TKQP | 【压力测试】【低概率】【wukong】出现1次，由进程com.ohos.note下的com.ohos.note线程导致libace.z.so出现crash。 |
| I6TNY9 | 通话记录处充满记录时，向上滑动时拨号键盘无法隐藏。 |
| I6TRW7<br/>I6TRRX<br/>I6TRHA<br/>I6TRH3<br/>I6TRGZ<br/>I6TRGO<br/>I6TRGJ<br/>I6TRGG<br/>I6TRGD<br/>I6TRG9<br/>I6TRG6<br/>I6TIFP<br/>I6TBIR<br/>I6RQLV<br/>I6RQLT<br/>I6QYZS<br/>I6QYZR<br/>I6QYZI<br/>I6QYZG<br/>I6QYZF<br/>I6QYZ9<br/>I6QYZ7<br/>I6TRHE<br/>I6TRH7<br/>I6TRGV<br/>I6TRGS<br/>I6TRG2 | 【漏洞】 【OpenHarmony-3.2-Release】 lj-oss-fuzz-132<br/>【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-1652<br/>【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-1815<br/>【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-1823<br/>【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-1817<br/>【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-1819<br/>【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-1822<br/>【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-1816<br/>【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-1821<br/>【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-1813<br/>【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-1814<br/>【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-28464<br/>【漏洞】 【OpenHarmony-3.2-Release】 CVE-2022-48434<br/>【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-0466<br/>【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-0465<br/>【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-27535<br/>【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-27533<br/>【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-27536<br/>【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-27538<br/>【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-27537<br/>【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-27534<br/>【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-0464<br/>【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-1812<br/>【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-1818<br/>【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-1811<br/>【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-1820<br/>【漏洞】 【OpenHarmony-3.2-Release】 CVE-2023-1810 |


## 遗留缺陷列表

  **表4** 遗留缺陷列表

| ISSUE | 问题描述 | 影响 | 计划解决日期 |
| -------- | -------- | -------- | -------- |
| I6B4U3 | 进程com.ohos.launcher低概率（3/10）引发appfreeze | 安装应用加多，安装超过40个应用，且内存较小的设备场景下，低概率出现appfreeze，但桌面功能正常，不影响整体功能和使用 | 2023年6月15日 |
| I6SXBI | 进程ohos.samples.distributedcalc下的libdistributeddata.z.so低概率导致cppcrash | 计算器应用快速启动和退出场景，启动后1秒内退出，导致JS对象读取数据库成功前JS对象被析构，只有LOG报错但用户无感知，影响可控 | 2023年7月15日 |
| I6TRE6 | 进程com.ohos.contacts下的com.ohos.contacts线程导致libdatashare_consumer.z.so低概率出现crash。 | 联系人应用快速启动和退出场景，发现在启动后600ms内退出，联系人进程低概率出现crash，出现crash后联系人进程会被重新拉起，影响可控。 | 2023年7月15日 |
| I6SMQA | 浏览器加载微博，滑动过程中出现抖动。 | 通过浏览器加载微博web网页后，快速滑动时，内容会闪现未加载，然后很快能加载出来，影响滑动体验。 | 2023年6月15日 |
| I72P5E | 反复进入大图浏览界面后返回，导致libace.z.so出现内存泄露 | 从图库进入大图浏览界面后返回，ArkUI模块每次泄露10kb，在应用上点击返回后，泄露问题消失。影响可控。 | 2023年7月15日 |
| I72P5I | 反复进入某相册的图片宫格浏览界面，导致libace.z.so出现内存泄露 | 进入某相册的图片宫格浏览界面后返回，ArkUI每次泄露19kb，在应用上点击返回后，泄露问题消失。影响可控。 | 2023年7月15日 |
| I76N0Y | 反复在dock栏添加/移除应用，导致libace.z.so出现内存泄露 | 移动卡片到合法区域，ArkUI每次泄露99kb，非常用场景，应用重启可泄露问题消失。影响可控。 | 2023年7月15日 |
| I6XHE7 | NAPIRemoteObject模块内存泄露 | JS应用调用IPC需要建立NAPIRemoteObject对象进程通信，创建一次可以循环使用，建立一次后泄露1.2kb，应用不需要反复创建新对象，泄露量可控，应用进程退出会释放掉内存。 | 2023年7月15日 |
