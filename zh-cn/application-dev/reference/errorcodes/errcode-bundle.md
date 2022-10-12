#  包管理子系统通用错误码

## 201 权限校验失败

### 错误信息
Permission denied.

### 可能原因
1. 调用目标接口时，未申请权限。
2. 非会话请求方和响应方查询会话信息。

### 处理步骤
1. 请申请相应接口要求的权限。
2. 请取消非法查询，使用会话请求方和响应方查询会话信息。

## 401 参数检查失败

### 错误信息
Parameter check failed.

### 可能原因
1. 必选参数没有传入，参数类型错误。

### 处理步骤
1. 请按照参数类型、位置，传入合法的参数。

## 801 API不支持

### 错误信息
Capability not supported.

### 可能原因
暂无

### 处理步骤
1. 取消调用和调用替代接口。

## 17700001 指定的bundleName不存在

### 错误信息
The specified bundle name is not found.

### 错误描述
调用接口时，传入的bundleName不存在。

### 可能原因
1. 输入的bundleName有误
2. 系统中对应的应用没有安装

### 处理步骤
1. 检查bundleName拼写是否有误
2. 确认对应的应用是否安装

## 17700002 指定的moduleName不存在

### 错误信息
The specified module name is not found.

### 错误描述
调用接口时，传入的moduleName不存在。

### 可能原因
1. 输入的moduleName有误
2. 系统中对应的应用没有安装该模块

### 处理步骤
1. 检查bundleName拼写是否有误
2. 确认对应的应用是否安装该模块

## 17700003 指定的abilityName不存在

### 错误信息
The specified ability name is not found.

### 错误描述
调用接口时，传入的abilityName不存在。

### 可能原因
1. 输入的abilityName有误
2. 系统中对应的应用没有安装

### 处理步骤
1. 检查abilityName拼写是否有误
2. 确认对应的应用是否安装该模块

## 17700004 指定的用户不存在

### 错误信息
The specified user id is not found.

### 错误描述
调用接口时，传入的用户不存在。

### 可能原因
1. 输入的用户有误，系统中没有该用户

### 处理步骤
1. 检查用户拼写是否有误
2. 确认系统中存在该用户

## 17700005 指定的appId不存在

### 错误信息
The specified appId is not found.

### 错误描述
调用接口时，传入的appId为空字符串。

### 可能原因
1. 传入的appId为空字符串

### 处理步骤
1. 检查appId拼写是否有误

## 17700006 查询的权限不存在

### 错误信息
The specified permission is not found.

### 错误描述
调用接口时，传入的权限不存在。

### 可能原因
1. 传入的permission名称拼写有误
2. 系统中不存在对应的权限

### 处理步骤
1. 检查permission拼写是否有误
2. 确认系统中是否有该权限

## 17700007 输入的设备Id有误

### 错误信息
The specified deviceId is not found.

### 错误描述
调用接口时，传入的设备id有误。

### 可能原因
1. 传入的deviceId拼写有误
2. deviceId不存在

### 处理步骤
1. 检查deviceId拼写是否有误
2. 确认deviceId是否存在

## 17700010 文件解析失败导致应用安装失败

### 错误信息
Failed to install the hap since the hap fails to be parsed.

### 错误描述
文件解析失败导致应用安装失败

### 可能原因
1. hap包的格式不是zip格式
2. hap包的配置文件不满足json格式
3. hap包的配置文件缺少必要的字段

### 处理步骤
1. 确认hap的格式是zip
2. 确认hap的配置文件满足json格式
3. 检查IDE编译hap时是否有错误提示，缺省字段时会有相应的报错。

## 17700011 签名校验失败失败导致应用安装失败

### 错误信息
Failed to install the hap since the hap signature fails to be verified.

### 错误描述
签名校验失败失败导致应用安装失败

### 可能原因
1. hap包没有签名
2. hap签名信息来源不可靠
3. 升级的hap包与已安装的hap包签名信息不一致
4. 多个hap的签名信息不一致

### 处理步骤
1. 确认hap是否签名成功
2. 确认多个hap签名时使用的证书相同
3. 确认升级的hap签名证书与已安装的hap相同

## 17700012 安装包路径无效导致应用安装失败

### 错误信息
Failed to install the hap since the path of the hap is invalid.

### 错误描述
安装包路径无效导致应用安装失败

### 可能原因
1. 输入错误，hap包的文件路径不存在
2. hap包的路径无法访问

### 处理步骤
1. 确认hap是否存在
2. 查看hap的可执行权限，是否可读

## 17700013 应用包过大导致应用安装失败

### 错误信息
Failed to install the hap since the hap is too large.

### 错误描述
应用包过大导致应用安装失败

### 可能原因
1. hap包过大，一个hap不能超过4GB。

### 处理步骤
1. 确认hap包的大小

## 17700014 应用包后缀有误导致应用安装失败

### 错误信息
Failed to install the hap since the extension name of the hap is not .hap.

### 错误描述
应用包后缀有误导致应用安装失败

### 可能原因
1. hap包的文件后缀名不为.hap

### 处理步骤
1. 确认hap包的后缀是否为.hap

## 17700015 多个hap包配置信息不同导致应用安装失败

### 错误信息
Failed to install haps since the configuration information of multi haps is inconsistent.

### 错误描述
多个hap包配置信息不同导致应用安装失败。

### 可能原因
1. 多个hap包中配置文件app下面的字段不一致

### 处理步骤
1. 确认多个hap包中配置文件app下面的字段是否一致

## 17700016 系统磁盘空间不足导致应用安装失败

### 错误信息
Failed to install the hap since the system disk space is insufficient.

### 错误描述
系统磁盘空间不足导致应用安装失败

### 可能原因
1. 系统空间不足

### 处理步骤
1. 确认系统是否有多余的空间

## 17700017 新安装的应用版本号过低导致应用安装失败

### 错误信息
Failed to install the hap since the version of the newly installed hap is too early.

### 错误描述
新安装的应用版本号过低导致应用安装失败。

### 可能原因
1. 新安装的应用版本号过低

### 处理步骤
1. 确认新安装的应用版本号是否比已安装的同应用版本号高

## 17700020 预置应用无法卸载

### 错误信息
The preinstalled app cannot be uninstalled.

### 错误描述
预置应用无法卸载。

### 可能原因
1. 传入的bundleName是否拼写有误
2. 对应的预置应用无法卸载

### 处理步骤
1. 确认对应的预置应用是否可卸载

## 17700021 指定的uid无效

### 错误信息
The specified uid is invalid.

### 错误描述
指定的uid无效

### 可能原因
1. 传入的uid拼写有误
2. 传入的uid在系统中不存在

### 处理步骤
1. 检查uid的拼写
2. 检查系统中是否存在该uid

## 17700022 输入的待解析源文件无效

### 错误信息
The input source file is invalid.

### 错误描述
输入的待解析源文件无效

### 可能原因
1. 待解析的源文件不存在
2. 待解析的源文件不符合zip格式

### 处理步骤
1. 确认待解析的源文件是否存在
2. 确认待解析的源文件符合zip格式

## 17700023 指定的默认应用不存在

### 错误信息
The specified default app does not exist.

### 错误描述
指定的默认应用不存在

### 可能原因
1. 设备没有设置对应的默认应用

### 处理步骤
1. 确认设备是否设置了对应的默认应用

## 17700024 没有相应的配置文件

### 错误信息
Failed to get profile since no profile in the hap.

### 错误描述
没有相应的配置文件

### 可能原因
1. 输入的metadata name在配置文件中不存在
2. 配置文件的内容不是json格式

### 处理步骤
1. 确认要查询的ability或者extensionAbility中的metadata name是否存在
2. 确认指定查询的profile文件的内容是否为json格式

## 17700025 输入的type无效

### 错误信息
The specified type is invalid.

### 错误描述
输入的type无效

### 可能原因
1. 输入的type拼写有误
2. 输入的type不存在

### 处理步骤
1. 确认输入的type是否拼写正确

## 17700026 指定应用被禁用

### 错误信息
The specified bundle is disabled.

### 错误描述
指定应用被禁用

### 可能原因
1. 设备上对应的应用已经被禁用，无法查询

### 处理步骤
1. 确认设备上对应的应用是否被禁用

## 17700027 分布式服务未启动

### 错误信息
The distributed service is not running.

### 错误描述
分布式服务未启动

### 可能原因
1. 设备未组网

### 处理步骤
1. 确认设备是否组网成功

## 17700027 分布式服务未启动

### 错误信息
The distributed service is not running.

### 错误描述
分布式服务未启动

### 可能原因
1. 设备未组网

### 处理步骤
1. 确认设备是否组网成功

## 17700028 输入的ability与type不匹配

### 错误信息
The distributed service is not running.

### 错误描述
输入的ability与type不匹配

### 可能原因
1. 输入的ability和type拼写有误

### 处理步骤
1. 确认输入的ability和type拼写是否有误

## 900001 输入待压缩的源文件或目录无效

### 错误信息
The input source file is invalid.

### 错误描述
输入待压缩的源文件或目录无效

### 可能原因
1. 输入的路径不存在

### 处理步骤
1. 确认输入的路径是否存在

## 900002 输入压缩的目的文件无效

### 错误信息
The input source file is invalid.

### 错误描述
输入压缩的目的文件无效

### 可能原因
1. 输入压缩的目的文件无效
2. 输入压缩的目的文件已存在

### 处理步骤
1. 确认输入压缩的目的文件无效
2. 确认输入压缩的目的文件是否已存在
