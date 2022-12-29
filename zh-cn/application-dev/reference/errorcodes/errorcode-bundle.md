#  包管理子系统通用错误码

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
1. 确认对应的预置应用是否可卸载。

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
Failed to get the profile because there is no profile in the HAP.

**错误描述**<br/>
调用查询profile文件的相关接口时，没有相应的配置文件。

**可能原因**<br/>
1. 输入的metadata name在配置文件中不存在。
2. 配置文件的内容不是json格式。

**处理步骤**<br/>
1. 确认要查询的ability或者extensionAbility中的metadata name是否存在。
2. 确认指定查询的profile文件的内容是否为json格式。

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
确认指定的ability是否被禁用，可以使用[bm工具命令](../../../readme/%E5%8C%85%E7%AE%A1%E7%90%86%E5%AD%90%E7%B3%BB%E7%BB%9F.md%23bm%E5%B7%A5%E5%85%B7%E5%91%BD%E4%BB%A4)查询对应的应用信息。

## 17700030 指定的应用不支持清除缓存文件

**错误信息**<br/>
The specified bundle does not support clearing of cache files.

**错误描述**<br/>
当调用bundleManager模块中的cleanBundleCacheFiles接口时，指定的应用不支持清除缓存文件。

**可能原因**<br/>
指定的应用为系统应用且在签名证书中配置了不能清除数据(AllowAppDataNotCleared)的字段。

**处理步骤**<br/>
1.确认指定的应用是否为系统应用，可以使用[bm工具命令](../../../readme/%E5%8C%85%E7%AE%A1%E7%90%86%E5%AD%90%E7%B3%BB%E7%BB%9F.md%23bm%E5%B7%A5%E5%85%B7%E5%91%BD%E4%BB%A4)查询对应的应用信息，查看isSystemApp是否为true。
2.确认指定的应用是否配置了能清除缓存(AllowAppDataNotCleared)的字段，可以使用[bm工具命令](../../../readme/%E5%8C%85%E7%AE%A1%E7%90%86%E5%AD%90%E7%B3%BB%E7%BB%9F.md%23bm%E5%B7%A5%E5%85%B7%E5%91%BD%E4%BB%A4)查询对应的应用信息，查看userDataClearable是否为true。

<!--no_check-->