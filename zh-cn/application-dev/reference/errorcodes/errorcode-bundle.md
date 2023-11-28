# 包管理子系统通用错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](errorcode-universal.md)。

## 17700001 指定的bundleName不存在

**错误信息**<br/>
The specified bundle name is not found.

**错误描述**<br/>
调用查询等接口时，传入的bundleName不存在。

**可能原因**<br/>

1. 输入的bundleName有误。
2. 系统中对应的应用没有安装。

**处理步骤**<br/>
1. 检查bundleName拼写是否正确。
2. 确认对应的应用是否安装。

## 17700002 指定的moduleName不存在

**错误信息**<br/>
The specified module name is not found.

**错误描述**<br/>
调用查询或者免安装相关接口时，传入的moduleName不存在。

**可能原因**<br/>
1. 输入的moduleName有误。
2. 系统中对应的应用没有安装该模块。

**处理步骤**<br/>
1. 检查moduleName拼写是否正确。
2. 确认对应的应用是否安装该模块。

## 17700003 指定的abilityName不存在

**错误信息**<br/>
The specified ability name is not found.

**错误描述**<br/>
调用查询等接口时，传入的abilityName不存在。

**可能原因**<br/>
1. 输入的abilityName有误。
2. 系统中对应的应用不存在该abilityName对应的ability。

**处理步骤**<br/>
1. 检查abilityName拼写是否正确。
2. 确认对应的应用是否存在该abilityName对应的ability。

## 17700004 指定的用户不存在

**错误信息**<br/>
The specified user ID is not found.

**错误描述**<br/>
调用与用户相关接口时，传入的用户不存在。

**可能原因**<br/>
1. 输入的用户名有误。
2. 系统中没有该用户。

**处理步骤**<br/>
1. 检查用户名拼写是否正确。
2. 确认系统中存在该用户。

## 17700005 指定的appId为空字符串

**错误信息**<br/>
The specified app ID is empty string.

**错误描述**<br/>
调用appControl模块中的相关接口时，传入的appId为空字符串。

**可能原因**<br/>
传入的appId为空字符串。

**处理步骤**<br/>
检查appId是否为空字符串。

## 17700006 查询的权限不存在

**错误信息**<br/>
The specified permission is not found.

**错误描述**<br/>
调用bundleManager模块中的getPermissionDef接口时，传入的权限不存在。

**可能原因**<br/>
1. 传入的permission名称拼写有误。
2. 系统中不存在对应的权限。

**处理步骤**<br/>
1. 检查permission拼写是否正确。
2. 确认系统中是否有该权限。

## 17700007 输入的设备Id有误

**错误信息**<br/>
The specified device ID is not found.

**错误描述**<br/>
调用distributedBundle模块相关接口时，传入的设备id有误。

**可能原因**<br/>
1. 传入的deviceId拼写有误。
2. deviceId不存在。

**处理步骤**<br/>
1. 检查deviceId拼写是否正确。
2. 确认deviceId是否存在。

## 17700010 文件解析失败导致应用安装失败

**错误信息**<br/>
Failed to install the HAP because the HAP fails to be parsed.

**错误描述**<br/>
调用installer模块中的install接口时，传入的HAP解析失败。

**可能原因**<br/>
1. HAP的格式不是zip格式。
2. HAP的配置文件不满足json格式。
3. HAP的配置文件缺少必要的字段。

**处理步骤**<br/>
1. 确认hap的格式是zip。
2. 确认hap的配置文件满足[配置文件json格式](../../quick-start/application-configuration-file-overview-stage.md)。
3. 检查DevEco Studio编译hap时是否有错误提示，缺省字段时会有相应的报错。

## 17700011 签名校验失败导致应用安装失败

**错误信息**<br/>
Failed to install the HAP because the HAP signature fails to be verified.

**错误描述**<br/>
调用installer模块中的install接口时，签名校验失败导致应用安装失败。

**可能原因**<br/>

1. HAP没有签名。
2. hap签名信息来源不可靠。
3. 升级的HAP与已安装的HAP签名信息不一致。
4. 多个hap的签名信息不一致。

**处理步骤**<br/>
1. 确认hap包是否签名成功。
2. 确认hap包的签名证书是从应用市场申请。
3. 确认多个hap包签名时使用的证书相同。
4. 确认升级的ha包p签名证书与已安装的hap包相同。

## 17700012 安装包路径无效或者文件过大导致应用安装失败

**错误信息**<br/>
Failed to install the HAP because the HAP path is invalid or the HAP is too large.

**错误描述**<br/>
调用installer模块中的install接口时，安装包路径无效或者文件过大导致应用安装失败。

**可能原因**<br/>
1. 输入错误，HAP的文件路径不存在。
2. HAP的路径无法访问。
3. HAP的大小超过最大限制4G。

**处理步骤**<br/>
1. 确认hap是否存在。
2. 查看hap的可执行权限，是否可读。
3. 查看HAP的大小是否超过4G。

## 17700015 多个HAP配置信息不同导致应用安装失败

**错误信息**<br/>
Failed to install the HAPs because they have different configuration information.

**错误描述**<br/>
调用installer模块中的install接口时，多个HAP配置信息不同导致应用安装失败。

**可能原因**<br/>
多个hap包中配置文件中app标签下面的字段信息不一致。

**处理步骤**<br/>
确认多个HAP中配置文件app下面的字段是否一致。

## 17700016 系统磁盘空间不足导致应用安装失败

**错误信息**<br/>
Failed to install the HAP because of insufficient system disk space.

**错误描述**<br/>
调用installer模块中的install接口时，系统磁盘空间不足导致应用安装失败。

**可能原因**<br/>
系统空间不足。

**处理步骤**<br/>
确认系统是否有足够的空间。

## 17700017 新安装的应用版本号低于已安装的版本号导致应用安装失败

**错误信息**<br/>
Failed to install the HAP since the version of the HAP to install is too early.

**错误描述**<br/>
调用installer模块中的install接口时，新安装的应用版本号低于已安装的版本号导致应用安装失败。

**可能原因**<br/>
新安装的应用版本号低于已安装的版本号。

**处理步骤**<br/>
确认新安装的应用版本号是否不低于已安装的同应用版本号。

## 17700018 安装失败，依赖的模块不存在

**错误信息**<br/>
Failed to install because the dependent module does not exist.

**错误描述**<br/>
安装hap或者hsp时，依赖的模块不存在。

**可能原因**<br/>
依赖的模块没有安装。

**处理步骤**<br/>
先安装依赖的模块。

## 17700020 预置应用无法卸载

**错误信息**<br/>
The preinstalled app cannot be uninstalled.

**错误描述**<br/>
调用installer模块中的uninstall接口卸载预置应用时，无法卸载。

**可能原因**<br/>
1. 传入的bundleName拼写有误。
2. 对应的预置应用无法卸载。

**处理步骤**<br/>
1. 确认bundleName是否拼写正确。
2. 确认对应的预置应用是否可卸载。

## 17700021 指定的uid无效

**错误信息**<br/>
The specified uid is invalid.

**错误描述**<br/>
调用bundleManager模块中的getBundleNameByUid接口时，指定的uid无效。

**可能原因**<br/>
1. 传入的uid拼写有误。
2. 传入的uid在系统中不存在。

**处理步骤**<br/>
1. 检查uid的拼写。
2. 检查系统中是否存在该uid。

## 17700022 输入的待解析源文件无效

**错误信息**<br/>
The input source file is invalid.

**错误描述**<br/>
调用bundleManager模块中的getBundleArchiveInfo接口时，传入的HAP路径无效。

**可能原因**<br/>
1. 待解析的源文件不存在。
2. 待解析的源文件不符合zip格式。

**处理步骤**<br/>
1. 确认待解析的源文件是否存在。
2. 确认待解析的源文件符合zip格式。

## 17700023 指定的默认应用不存在

**错误信息**<br/>
The specified default app does not exist.

**错误描述**<br/>
调用defaultAppManager模块中的getDefaultApplication接口时，指定的默认应用不存在。

**可能原因**<br/>
设备没有设置对应的默认应用。

**处理步骤**<br/>
确认设备是否设置了对应的默认应用。

## 17700024 没有相应的配置文件

**错误信息**<br/>
Failed to get the profile because the specified profile is not found in the HAP.

**错误描述**<br/>
调用查询profile文件的相关接口时，没有相应的配置文件。

**可能原因**<br/>
1. 输入的metadata name在配置文件中不存在。
2. 配置文件的内容不是json格式。
3. 查询的配置文件类型不存在。

**处理步骤**<br/>
1. 确认要查询的ability或者extensionAbility中的metadata name是否存在。
2. 确认指定查询的profile文件的内容是否为json格式。
3. 确认应用中是否存在与查询的profileType类型相符的配置文件。

## 17700025 输入的type无效

**错误信息**<br/>
The specified type is invalid.

**错误描述**<br/>
调用defaultAppManager模块的相关接口时，输入的type无效。

**可能原因**<br/>
1. 输入的type拼写有误。
2. 输入的type不存在。

**处理步骤**<br/>
1. 确认输入的type是否拼写正确。
2. 确认输入的type是否存在。

## 17700026 指定应用被禁用

**错误信息**<br/>
The specified bundle is disabled.

**错误描述**<br/>
当调用查询应用的相关信息接口时，指定应用被禁用。

**可能原因**<br/>
设备上对应的应用已经被禁用，无法查询。

**处理步骤**<br/>
确认设备上对应的应用是否被禁用。

## 17700027 分布式服务未启动

**错误信息**<br/>
The distributed service is not running.

**错误描述**<br/>
当调用distributedBundle模块的相关接口时，分布式服务未启动。

**可能原因**<br/>
设备未组网。

**处理步骤**<br/>
确认设备是否组网成功。
## 17700028 输入的ability与type不匹配

**错误信息**<br/>
The ability does not match the type.

**错误描述**<br/>
当调用defaultAppManager模块中的setDefaultApplication接口时，输入的ability与type不匹配。

**可能原因**<br/>
输入的ability和type拼写有误。

**处理步骤**<br/>
确认输入的ability和type拼写是否正确。

## 17700029 指定的ability被禁用

**错误信息**<br/>
The specified ability is disabled.

**错误描述**<br/>
当调用查询ability相关信息的接口时，指定的ability被禁用。

**可能原因**<br/>
指定的ability被禁用。

**处理步骤**<br/>
确认指定的ability是否被禁用，可以使用[bm工具命令](../../../readme/包管理子系统.md#bm工具命令)查询对应的应用信息。

## 17700030 指定的应用不支持清除缓存文件

**错误信息**<br/>
The specified bundle does not support clearing of cache files.

**错误描述**<br/>
当调用bundleManager模块中的cleanBundleCacheFiles接口时，指定的应用不支持清除缓存文件。

**可能原因**<br/>
指定的应用为系统应用且在签名证书中配置了不能清除数据(AllowAppDataNotCleared)的字段。

**处理步骤**<br/>
1. 确认指定的应用是否为系统应用，可以使用[bm工具命令](../../../readme/包管理子系统.md#bm工具命令)查询对应的应用信息，查看isSystemApp是否为true。
2. 确认指定的应用是否配置了能清除缓存(AllowAppDataNotCleared)的字段，可以使用[bm工具命令](../../../readme/包管理子系统.md#bm工具命令)查询对应的应用信息，查看userDataClearable是否为true。

## 17700031 Overlay特性校验失败导致HAP安装失败

**错误信息**<br/>
Failed to install the HAP because the overlay check of the HAP is failed.

**错误描述**<br/>
当安装overlay特征的应用时，指定的应用和待安装的overlay特征应用不为预置应用，或者目标应用/目标module是overlay特征的应用/module。

**可能原因**<br/>
1. 使用应用间的overlay特性时，overlay特征应用必须为预置应用。
2. 使用应用间的overlay特性时，目标应用必须为预置应用。
3. 使用应用间的overlay特性时，目标应用不能是具有overlay特征的应用
4. 目标module不能是具有overlay特征的module。

**处理步骤**<br/>
1. 检查overlay特征应用是否为预置应用。
2. 检查目标应用是否为预置应用。
3. 检查目标应用是否不为overlay特征的应用
4. 检查目标module是否不为overlay特征的module。

## 17700032 指定的应用不包含overlay特征的module

**错误信息**<br/>
The specified bundle does not contain any overlay module.

**错误描述**<br/>
查询指定应用中overlay特征module的overlayModuleInfo时, 指定的应用不包含overlay特征module。

**可能原因**<br/>
指定的应用不包含overlay特征module。

**处理步骤**<br/>
检查指定的应用是否不包含overlay特征module。

## 17700033 指定的module不是overlay特征的module

**错误信息**<br/>
The specified module is not an overlay module.

**错误描述**<br/>
查询指定的overlay特征module的overlayModuleInfo时, 指定的module不是overlay特征module。

**可能原因**<br/>
指定的module不是overlay特征的module。

**处理步骤**<br/>
检查指定的module是否不为overlay特征的module。

## 17700034 指定的module是overlay特征的module

**错误信息**<br/>
The specified module is an overlay module.

**错误描述**<br/>
查询指定的目标module所关联的overlayModuleInfo时, 指定的module是overlay特征module。

**可能原因**<br/>
指定的module是overlay特征的module。

**处理步骤**<br/>
检查指定的module是否为overlay特征的module。

## 17700035 指定的应用只包含overlay特征的module

**错误信息**<br/>
The specified bundle is an overlay bundle.

**错误描述**<br/>
查询指定应用的目标module所关联的overlayModuleInfo时, 指定的应用只包含overlay特征的module。

**可能原因**<br/>
指定的应用只包含overlay特征的module。

**处理步骤**<br/>
检查指定的应用是否只包含overlay特征的module。

## 17700036 共享库缺少AllowAppShareLibrary特权导致安装失败

**错误信息**<br/>
Failed to install the HSP because lacks appropriate permissions.

**错误描述**<br/>
共享库未申请配置AllowAppShareLibrary特权，可能存在安全隐私风险，不允许安装。

**可能原因**<br/>
发布共享库前，未申请配置AllowAppShareLibrary特权。

**处理步骤**<br/>
为共享库申请配置AllowAppShareLibrary特权，重新签名并发布。

## 17700037 被卸载的shared library版本被其他应用依赖

**错误信息**<br/>
The version of shared bundle is dependent on other applications.

**错误描述**<br/>
当卸载shared library某一版本时，指定的shared library的版本被其他应用依赖，卸载失败。

**可能原因**<br/>
1. 当前卸载的版本是shared library的最高版本，且该shared library被其他应用依赖。
2. 当前卸载时未指定shared library的版本，会卸载shared library的所有版本，该shared library被其他应用依赖。

**处理步骤**<br/>
1. 检查被卸载的shared library是否被其他应用依赖。
2. 检查被卸载的版本是否为shared library的最高版本。

## 17700038 被卸载的shared library不存在

**错误信息**<br/>
The specified shared bundle does not exist.

**错误描述**<br/>
当卸载shared library时，卸载的shared library不存在。

**可能原因**<br/>
1. 当前指定卸载的版本不存在与被卸载的shared library中。
2. 当前指定卸载的shared library不存在与设备中。

**处理步骤**<br/>
1. 检查被卸载的shared library是否存在于当前设备中。
2. 检查被卸载的版本是否存在于被卸载的shared library中。

## 17700039 不允许安装应用间共享库
**错误信息**<br/>
Failed to install because disallow install a shared bundle by hapFilePaths.

**错误描述**<br/>
安装应用时，传入的安装包为应用间共享库类型。

**可能原因**<br/>
1. 通过bm工具安装应用时，-p参数传入了应用间共享库的安装包路径。
2. 通过install接口安装应用时，hapFilePaths参数传入了应用间共享库的安装包路径。

**处理步骤**<br/>
1. 通过-s参数指定应用间共享库的安装包路径。
2. 通过installParam参数的sharedBundleDirPaths字段指定应用间共享库的安装包路径。

## 17700040 不允许卸载应用间共享库
**错误信息**<br/>
The specified bundle is a shared bundle which cannot be uninstalled.

**错误描述**<br/>
卸载应用时，传入的是应用间共享库的包名。

**可能原因**<br/>
1. 通过bm工具卸载应用时，-n参数传入了应用间共享库的包名。
2. 通过uninstall接口卸载应用时，bundleName传入的是应用间共享库的包名。

**处理步骤**<br/>
1. 通过-s参数指定卸载的应用为共享库应用。
2. 通过UninstallParam参数的bundleName及versionCode指定卸载的共享库的包名及版本。

## 17700041 企业设备管理不允许安装该应用
**错误信息**<br/>
Failed to install because enterprise device management disallow install.

**错误描述**<br/>
安装应用时，企业设备管理不允许安装。

**可能原因**<br/>
企业设备管理不允许安装该应用。

**处理步骤**<br/>
请在设备中检查应用是否被企业设备管理禁止安装。

## 17700042 数据代理中的uri配置错误
**错误信息**<br/>
Failed to install the HAP because of incorrect URI in the data proxy.

**错误描述**<br/>
安装应用时，数据代理的uri配置错误。

**可能原因**<br/>
1. uri中的包名与当前应用的包名不一致。
2. uri重复。

**处理步骤**<br/>
1. 修改uri中的包名为当前应用的包名。
2. 修改重复的uri，每一个数据代理的uri都是唯一的。

## 17700043 数据代理中的权限配置错误
**错误信息**<br/>
Failed to install the HAP because of low APL in the non-system data proxy (required APL: system_basic or system_core).

**错误描述**<br/>
安装应用时，非系统应用的数据代理的权限等级过低，应为system_basic或system_core。

**可能原因**<br/>
1. 非系统应用的数据代理未配置权限。
2. 非系统应用的数据代理的权限等级过低。

**处理步骤**<br/>
1. 在数据代理中配置读权限和写权限。
2. 修改读权限和写权限，并确认其权限等级为system_basic或system_core。

## 17700044 安装包设置的多进程配置项与系统配置项设置矛盾
**错误信息**<br/>
Failed to install the HAP because the isolationMode configured is not supported.

**错误描述**<br/>
安装应用时，设置的isolationMode与系统配置项所允许的系统配置项矛盾。

**可能原因**<br/>
1. 设备支持隔离模式，即persist.bms.supportIsolationMode为true时，HAP配置的isolationMode为nonisolationOnly。
2. 设备不支持隔离模式，即persist.bms.supportIsolationMode为false时，HAP配置的isolationMode为isolationOnly。

**处理步骤**<br/>
按照设备的隔离模式正确配置HAP字段isolationMode。

## 17700045 企业设备管理不允许卸载该应用
**错误信息**<br/>
Failed to uninstall because enterprise device management disallow uninstall.

**错误描述**<br/>
卸载应用时，企业设备管理不允许卸载。

**可能原因**<br/>
企业设备管理不允许安装该应用。

**处理步骤**<br/>
请在设备中检查应用是否被企业设备管理禁止卸载安装。

## 17700047 要更新的应用版本没有大于当前版本
**错误信息**<br/>
Failed to install the HAP because the VersionCode to be updated is not greater than the current VersionCode.

**错误描述**<br/>
安装应用时，要更新的应用版本没有大于当前版本。

**可能原因**<br/>
1. 安装应用的版本号小于等于已安装应用的版本号。
2. installFlag被设置为NORMAL，此时待更新的应用的版本号必须大于当前已安装的版本。

**处理步骤**<br/>
1. 设置应用的版本号大于当前版本。
2. 如果希望应用更新但版本号不升级，需要设置installFlag为REPLACE_EXISTING。

## 17700048 代码签名校验失败
**错误信息**<br/>
Failed to install the HAP because the code signature verification is failed.

**错误描述**<br/>
安装应用时，安装包的代码签名文件校验失败。

**可能原因**<br/>
1. 代码签名文件对应的module在安装包中不存在。
2. 代码签名文件路径无效。
3. 代码签名文件和对应的安装包不匹配。

**处理步骤**<br/>
1. 检查代码签名文件对应的module是否包含在安装包路径之中。
2. 检查提供的代码签名文件的路径是否合法。
3. 使用和安装包匹配的代码签名文件。

## 17700049 应用自升级时安装的应用与调用方包名不同
**错误信息**<br/>
Failed to install the HAP because the bundleName is different from the bundleName of the caller application.

**错误描述**<br/>
企业mdm应用自升级时，安装的应用与调用方包名不同。

**可能原因**<br/>
要安装的hap或hsp不属于当前应用。

**处理步骤**<br/>
检查要安装的hap或hsp是否属于当前应用。

## 17700050 企业设备校验失败
**错误信息**<br/>
Failed to install the HAP because enterprise normal/MDM bundle cannot be installed on non-enterprise device.

**错误描述**<br/>
安装应用时，企业normal应用或企业mdm应用无法在非企业设备上安装。

**可能原因**<br/>
安装设备不是企业设备。

**处理步骤**<br/>
1. 检查安装设备是否为企业设备。
2. 检查设备参数const.bms.allowenterprisebundle是否为true

## 17700051 应用自升级时安装的应用与调用方包名不同
**错误信息**<br/>
Failed to install the HAP because the distribution type of caller application is not enterprise_mdm.

**错误描述**<br/>
企业mdm应用自升级时，调用方的分发类型不是企业mdm。

**可能原因**<br/>
调用方的分发类型不是企业mdm。

**处理步骤**<br/>
检查应用的签名文件是否正确配置。

## 17700052 非开发者模式下不允许安装调试应用
**错误信息**<br/>
Failed to install the HAP because debug bundle cannot be installed under non-developer mode.

**错误描述**<br/>
安装调试应用时，设备处于非开发者模式，不允许安装。

**可能原因**<br/>
应用为调试应用，而设备处于非开发者模式。

**处理步骤**<br/>
执行hdc shell param get const.security.developermode.state，若返回结果为false，说明该设备无法安装调试应用。

## 17700053 非应用市场调用
**错误信息**<br/>
Not app gallery call.

**错误描述**<br/>
非应用市场的应用调用，仅供应用市场调用的接口。

**可能原因**<br/>
调用者不是应用市场。

**处理步骤**<br/>
请检查调用者是否是应用市场。