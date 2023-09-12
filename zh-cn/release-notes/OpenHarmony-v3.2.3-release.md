# OpenHarmony 3.2.3 Release


## 版本概述

当前版本在OpenHarmony 3.2.2 Release的基础上，修复了内存泄漏及linux kernel等开源组件的安全漏洞，增强了系统安全性。修复了部分系统稳定性的issue，增强了系统稳定性。更新配套的SDK版本。


## 配套关系

  **表1** 版本软件和工具配套关系

| 软件                              | 版本                                             | 备注                                                         |
| --------------------------------- | ------------------------------------------------ | ------------------------------------------------------------ |
| OpenHarmony                       | 3.2.3 Release                                    | NA                                                           |
| Public SDK                        | Ohos_sdk_public 3.2.14.6 (API Version 9 Release) | 面向应用开发者提供，不包含需要使用系统权限的系统接口。通过DevEco Studio默认获取的SDK为Public SDK。 |
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
 repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.2.3-Release --no-repo-verify
 repo sync -c
 repo forall -c 'git lfs pull'
 ```

**方式二**

通过repo + https 下载。

从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
 ```
 repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v3.2.3-Release --no-repo-verify
 repo sync -c
 repo forall -c 'git lfs pull'
 ```

### 从镜像站点获取

  **表2** 获取源码路径

| 版本源码                              | **版本信息**  | **下载站点**                                                 | **SHA256校验码**                                             |
| ------------------------------------- | ------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 全量代码（标准、轻量和小型系统）      | 3.2.3 Release | [站点](https://repo.huaweicloud.com/openharmony/os/3.2.3/code-v3.2.3-Release_20230904.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2.3/code-v3.2.3-Release_20230904.tar.gz.sha256) |
| Hi3861解决方案（二进制）              | 3.2.3 Release | [站点](https://repo.huaweicloud.com/openharmony/os/3.2.3/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2.3/hispark_pegasus.tar.gz.sha256) |
| Hi3516解决方案-LiteOS（二进制）       | 3.2.3 Release | [站点](https://repo.huaweicloud.com/openharmony/os/3.2.3/hispark_taurus_LiteOS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2.3/hispark_taurus_LiteOS.tar.gz.sha256) |
| Hi3516解决方案-Linux（二进制）        | 3.2.3 Release | [站点](https://repo.huaweicloud.com/openharmony/os/3.2.3/hispark_taurus_Linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2.3/hispark_taurus_Linux.tar.gz.sha256) |
| RK3568标准系统解决方案（二进制）      | 3.2.3 Release | [站点](https://repo.huaweicloud.com/openharmony/os/3.2.3/dayu200_standard_arm32_20230904.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2.3/dayu200_standard_arm32_20230904.tar.gz.sha256) |
| 标准系统Public SDK包（Mac）           | 3.2.14.6      | [站点](https://repo.huaweicloud.com/openharmony/os/3.2.3/ohos-sdk-mac-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2.3/ohos-sdk-mac-public.tar.gz.sha256) |
| 标准系统Public SDK包（Mac-M1）        | 3.2.14.6      | [站点](https://repo.huaweicloud.com/openharmony/os/3.2.3/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2.3/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) |
| 标准系统Public SDK包（Windows/Linux） | 3.2.14.6      | [站点](https://repo.huaweicloud.com/openharmony/os/3.2.3/ohos-sdk-windows_linux-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/3.2.3/ohos-sdk-windows_linux-public.tar.gz.sha256) |

## 更新说明

### API 

3.2.3 Release对比3.2.2 Release API接口无变更。

### 芯片及开发板适配

芯片及开发板适配状态请参考[SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)信息。

## 修复缺陷issue列表

  **表3** 修复缺陷issue列表

| ISSUE                                                        | 问题描述                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [I76UCD](https://gitee.com/open_harmony/dashboard?issue_id=I76UCD) | 【OpenHarmony_3.2.12.5】【3.2Release】【多媒体子系统】【RK3568】【必现-10/10】录像文件在图库播放最后2秒画面卡住未播放 |
| [I7B07F](https://e.gitee.com/open_harmony/issues/table/?issue=I7B07F) | 【OpenHarmony_3.2.12.5】【软总线】【发现】【rk3568】【必现-3/3】蓝牙发现失败 |
| [I7BZ4F](https://e.gitee.com/open_harmony/issues/table/?issue=I7BZ4F) | 【OpenHarmony_3.2.13.1】【RK3568】【发现】【概率 3/42】coap发现概率失败 |
| [I7C98S](https://e.gitee.com/open_harmony/issues/table/?issue=I7C98S) | 【OpenHarmony 3.2.13.1】【RK3568】【压力测试】【低概率2/10】【wukong】出现2次，  com.ohos.photos下出现jscrash问题，栈名：initializeConsume |
| [I7FO8I](https://e.gitee.com/open_harmony/issues/table/?issue=I7FO8I) | 【OpenHarmony 3.2  0620daily】【RK3568】【压力测试】【低概率1/10】【wukong】出现1次  进com.ohos.adminprovisioning下的IPC_3_14056线程导致libabilitykit_native.z.so出现cppcrash |
| [I7FR03](https://e.gitee.com/open_harmony/issues/table/?issue=I7FR03) | 【OpenHarmony 3.2  0620daily】【RK3568】【压力测试】【低概率1/10】【wukong】出现1次  由进程com.ohos.note下的RSRenderThread线程出现Rosenweb on  consumer导致libmali-bifrost-g52-g2p0-ohos.so出现cppcrash |
| [I7WJ2I](https://gitee.com/open_harmony/dashboard?issue_id=I7WJ2I) | 【Openharmony-master】【驱动子系统】【rk3568】【必现-5/5】修复动态配流失败问题（cherry-pick 3.2release） |
| [I6UYP6](https://gitee.com/open_harmony/dashboard?issue_id=I6UYP6) | 【3.2 Release】调用put和putSync接口设置key值长度和value值长度超过最大字节数，接口响应未进异常 |
| [I72P5E](https://gitee.com/open_harmony/dashboard?issue_id=I72P5E) | 【OpenHarmony 3.2.12.2】【RK3568】【压力测试】【必现10/10】反复进入大图浏览界面后返回，导致libace.z.so出现内存泄露 |
| [I72P5I](https://gitee.com/open_harmony/dashboard?issue_id=I72P5I) | 【OpenHarmony 3.2.12.2】【RK3568】【压力测试】【必现10/10】反复进入某相册的图片宫格浏览界面，导致libace.z.so出现内存泄露 |
| [I76N0Y](https://gitee.com/open_harmony/dashboard?issue_id=I76N0Y) | 【OpenHarmony 3.2.12.2】【RK3568】【压力测试】【必现10/10】反复在dock栏添加/移除应用，导致libace.z.so出现内存泄露 |
| [I7FNXR](https://gitee.com/open_harmony/dashboard?issue_id=I7FNXR) | 【OpenHarmony 3.2.13.5】【RK3568】【压力测试】【低概率1/10】【wukong】出现1次 进camera_service下的IPC_7_15380线程导致libipc_core.z.so出现cppcrash |
| [I7GATH](https://gitee.com/open_harmony/dashboard?issue_id=I7GATH) | 【OpenHarmony 3.2.13.5】【输入法】【必现-5/5】执行DevecoTesting服务接口注入测试后输入法选择框有cppcrash |
| [I7HDQP](https://gitee.com/open_harmony/dashboard?issue_id=I7HDQP) | 【OpenHarmony 3.2.13.5】【应用子系统】【RK3568】【必现_5/5】切换英文后，桌面上应用名称仍中文显示，重启后才英文显示 |
| [I7HFEO](https://gitee.com/open_harmony/dashboard?issue_id=I7HFEO) | 【OpenHarmony 3.2.14.1】【测试子系统】【3861】【必现-5/5】ActsUiTest模块执行一条fail项 |
| [I7HX8E](https://gitee.com/open_harmony/dashboard?issue_id=I7HX8E) | 【OpenHarmony 3.2.14.1】【RK3568】【xts压力测试】【低概率】出现2次 由进程com.ohos.rpctest下的jsThread-1线程导致librpc.z.so出现cppcrash |
| [I7IV88](https://gitee.com/open_harmony/dashboard?issue_id=I7IV88) | 【OpenHarmony 3.2.14.1】【RK3568】【压力测试】【低概率】【wukong】出现4次 由关键进程com.ohos.mms下的clickToGroupDetail 出现jscrash |
| [I7KZKQ](https://gitee.com/open_harmony/dashboard?issue_id=I7KZKQ) | 【OpenHarmony 3.2.14.2】【RK3568】【压力测试】【低概率】【wukong】出现13次 由关键进程com.ohos.mms下的clickInfoToConversation 出现jscrash |
| [I7KZLX](https://gitee.com/open_harmony/dashboard?issue_id=I7KZLX) | 【OpenHarmony 3.2.14.2】【RK3568】【压力测试】【低概率】【wukong】出现1次 由应用com.ohos.mms下的dealSessionDraft出现jscrash |
| [I7KZN7](https://gitee.com/open_harmony/dashboard?issue_id=I7KZN7) | 【OpenHarmony 3.2.14.2】【RK3568】【压力测试】【低概率】【wukong】出现18次 由关键进程com.ohos.contact下的menuChange 出现jscrash |
| [I7PAL6](https://gitee.com/open_harmony/dashboard?issue_id=I7PAL6) | 【OpenHarmony 3.2.14.5】【RK3568】【压力测试】【低概率】【wukong】出现1次 进/system/bin/installs下的IPC_1_643线程导致libhap_restorecon.z.so出现cppcrash |
| [I7Q85E](https://gitee.com/open_harmony/dashboard?issue_id=I7Q85E) | 【OpenHarmony 3.2.14.5】【RK3568】【压力测试】【wukong】 wukong压力测试内存占用过高 |
| [I7VAB8](https://gitee.com/open_harmony/dashboard?issue_id=I7VAB8) | 【OpenHarmony 3.2.14.6】【RK3568】【压力测试】【低概率】【wukong】出现24次 进程com.ohos.camera下的com.ohos.camera线程导致libcamera_napi.z.so出现cppcrash |
| [I7VBCV](https://gitee.com/open_harmony/dashboard?issue_id=I7VBCV) | 【OpenHarmony 3.2.14.6】【RK3568】【压力测试】【低频率】出现3次，进程ohos.samples.distributedmusicplayer下出现jscrash，栈名：cancelTimer |
| [I7BL13](https://gitee.com/open_harmony/dashboard?issue_id=I7BL13) | 【OpenHarmony-release3.2】【电源子系统】【rk3568】【必现-5/5】使用局部变量创建了全局线程 |
| [I7BY2N](https://gitee.com/open_harmony/dashboard?issue_id=I7BY2N) | [3.2-release] 支持编译空文件 |
| [I7CREK](https://gitee.com/open_harmony/dashboard?issue_id=I7CREK) | [3.2release]json参数校验调整 | 

## 修复安全issue列表

  **表4** 修复安全issue列表

| ISSUE  | 问题描述                                            |
| ------ | --------------------------------------------------- |
| I71KHW | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-32233 |
| I6QYW7 | 【漏洞】【OpenHarmony-3.2-Release】CVE-2022-4095 |
| I6RZV9 | 【漏洞】【OpenHarmony-3.2-Release】CVE-2022-4744 |
| I6TCVF | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-1838 |
| I6TCVR | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-1855 |
| I6TCW0 | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-1582 |
| I6U82D | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-30456 |
| I6UW4X | 【漏洞】【OpenHarmony-3.2-Release】CVE-2022-29581 |
| I6UW4Y | 【漏洞】【OpenHarmony-3.2-Release】CVE-2022-1158 |
| I6VHE0 | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-1990 |
| I6VVQJ | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-1859 |
| I6W9EQ | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-30772 |
| I6YK8O | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-2008 |
| I6ZH6E | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-0458 |
| I6ZJDL | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-31436 |
| I6ZK8X | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-2177 |
| I6ZK92 | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-2194 |
| I6ZQRA | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-28328 |
| I6ZQRH | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-2166 |
| I6ZQRM | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-28327 |
| I6ZUT4 | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-2248 |
| I6ZZDJ | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-1998 |
| I70B1G | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-2483 |
| I72GRH | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-32269 |
| I73Z2O | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-2124 |
| I76VW0 | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-0459 |
| I78R44 | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-33203 |
| I79YE0 | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-34256 |
| I7HIGZ | 【漏洞】【OpenHarmony-3.2-Release】CVE-2022-41858 |
| I7HIH1 | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-3421 |
| I7HIH4 | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-3268 |
| I7HIHC | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-35788 |
| I7HIHE | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-3161 |
| I7HIHF | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-3220 |
| I7HIHG | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-3159 |
| I7HIHN | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-35823 |
| I7HIHP | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-35828 |
| I7HIHQ | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-35824 |
| I7HIHR | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-35829 |
| I7HIHT | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-3141 |
| I7HIHV | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-3216 |
| I7HIHW | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-3215 |
| I7HII0 | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-3212 |
| I7HII2 | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-2002 |
| I7HII3 | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-2970 |
| I7HII8 | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-3079 |
| I7I5J3 | 【漏洞】【OpenHarmony-3.2-Release】CVE-2020-22597 |
| I7JKP5 | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-37327 |
| I7MTCB | 【漏洞】【OpenHarmony-3.2-Release】CVE-2020-22039 |
| I7MTCL | 【漏洞】【OpenHarmony-3.2-Release】CVE-2020-12284 |
| I7MTCU | 【漏洞】【OpenHarmony-3.2-Release】CVE-2020-22044 |
| I7MTD1 | 【漏洞】【OpenHarmony-3.2-Release】CVE-2020-22021 |
| I7MTD8 | 【漏洞】【OpenHarmony-3.2-Release】CVE-2020-22040 |
| I7MTDG | 【漏洞】【OpenHarmony-3.2-Release】CVE-2020-22037 |
| I7MTDN | 【漏洞】【OpenHarmony-3.2-Release】CVE-2020-22041 |
| I7MTDX | 【漏洞】【OpenHarmony-3.2-Release】CVE-2020-22026 |
| I7MTE2 | 【漏洞】【OpenHarmony-3.2-Release】CVE-2020-22043 |
| I7MTE9 | 【漏洞】【OpenHarmony-3.2-Release】CVE-2020-22042 |
| I7MTEM | 【漏洞】【OpenHarmony-3.2-Release】CVE-2020-22035 |
| I7MTEX | 【漏洞】【OpenHarmony-3.2-Release】CVE-2020-22036 |
| I7MTFZ | 【漏洞】【OpenHarmony-3.2-Release】CVE-2020-22048 |
| I7MTGL | 【漏洞】【OpenHarmony-3.2-Release】lj-c-131450017-9125433 |
| I7MTML | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-3446 |
| I7N91T | 【漏洞】【OpenHarmony-3.2-Release】CVE-2022-25636 |
| I7NU2Z | 【漏洞】【OpenHarmony-3.2-Release】CVE-2020-22028 |
| I7NU35 | 【漏洞】【OpenHarmony-3.2-Release】CVE-2020-22019 |
| I7NU3C | 【漏洞】【OpenHarmony-3.2-Release】CVE-2020-22020 |
| I7NVP2 | 【漏洞】【OpenHarmony-3.2-Release】CVE-2022-41409 |
| I7OWF7 | 【漏洞】【OpenHarmony-3.2-Release】CVE-2020-27777 |
| I7OWFA | 【漏洞】【OpenHarmony-3.2-Release】CVE-2020-25668 |
| I7OY06 | 【漏洞】【OpenHarmony-3.2-Release】CVE-2022-4912 |
| I7OY0E | 【漏洞】【OpenHarmony-3.2-Release】CVE-2022-4909 |
| I7OZ6F | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-36191 |
| I7P791 | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-3598 |
| I7PTFP | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-3567 |
| I7Q3I0 | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-3812 |
| I7QFUC | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-3817 |
| I7QR0J | 【漏洞】【OpenHarmony-3.2-Release】CVE-2022-1729 |
| I7QR0S | 【漏洞】【OpenHarmony-3.2-Release】CVE-2022-3202 |
| I7QR0V | 【漏洞】【OpenHarmony-3.2-Release】CVE-2022-3564 |
| I7QR1U | 【漏洞】【OpenHarmony-3.2-Release】CVE-2021-4083 |
| I7QRFE | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-4072 |
| I7QRFQ | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-4071 |
| I7QRFT | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-4076 |
| I7S222 | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-4273 |
| I7T5YY | 【漏洞】【OpenHarmony-3.2-Release】CVE-2023-4194 |
| I7UE6S | 【漏洞】【OpenHarmony-3.2-Release】CVE-2022-3623 |
| I7UE6U | 【漏洞】【OpenHarmony-3.2-Release】CVE-2022-2196 

## 遗留缺陷列表

  **表5** 遗留缺陷列表

| ISSUE | 问题描述 | 影响 | 计划解决日期 |
| ----- | -------- | ---- | ------------ |
| [I7HW2C](https://e.gitee.com/open_harmony/dashboard?issue=I7E931) | 【OpenHarmony 3.2.14.1】【RK3568】【压力测试】【低概率】【wukong】出现20次 由关键进程com.ohos.note下的com.ohos.note线程导致libace.z.so出现cppcrash| 对北向应用开发（特别是API）和用户体验的影响评估社区note应用在部分场景可能会崩溃，发生概率多台设备压测10000小时出现15次；对hilog日志分析大概率为极端场景跑出的问题，正常使用影响不大；对南向芯片平台&子系统社区无影响 | 2023年10月31日 |
| [I7E931](https://e.gitee.com/open_harmony/dashboard?issue=I7E931) | 调试3.2内存泄漏问题 | JS应用需要IPC需要建立NAPIRemoteObject对象进程通信，创建一次可以循环使用，建立一次后泄露1.2kb，应用不需要反复创建新对象，泄露量可控，应用进程退出会释放掉 | 2023年10月31日 |
| [I7P9VS](https://e.gitee.com/open_harmony/issues/table/?issue=I7P9VS) |【OpenHarmony 3.2.14.5】【RK3568】【压力测试】【必现10/10】反复进入大图浏览界面后返回，ElementRegister::ClearRemovedItems处出现内存泄露 | 问题从KB修复到泄露72字节，对系统影响较小 | 2023年10月31日 |
| [I7P9T5](https://e.gitee.com/open_harmony/issues/table/?issue=I7P9T5) |【OpenHarmony 3.2.14.5】【RK3568】【压力测试】【必现10/10】反复进入某相册的图片宫格浏览界面，ElementRegister::RemoveItem 和ElementRegister::ClearRemovedItems出现内存泄露 | 问题从KB修复到泄露144字节，对系统影响较小 | 2023年10月31日 |
