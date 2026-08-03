# 企业设备管理错误码
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 9200001 应用没有激活成设备管理器

**错误信息**

The application is not an administrator application of the device.

**错误描述**

当应用没有激活成设备管理器时，会产生此错误码。

**可能原因**

应用没有激活设备管理器。

**处理步骤**

请检查调用者是否成功激活过设备管理应用，没有激活过的设备管理应用无法调用设备管理接口。

## 9200002 设备管理器权限不够

**错误信息**

The administrator application does not have permission to manage the device.

**错误描述**

当设备管理器调用高权限接口时，则会产生此错误码。

**可能原因**

已激活为DA管理器，但调用了SDA管理器接口。

**处理步骤**

请检查调用者是否存在越权调用，即激活的设备管理器类型和调用的API要求的管理器类型是否一致。

## 9200003 指定的设备管理器元能力组件无效

**错误信息**

The administrator ability component is invalid.

**错误描述**

当应用传入参数中指定的设备管理器元能力组件无效时，会产生此错误码。

**可能原因**

该错误码表示指定的设备管理器元能力组件无效，可能原因如下。
1. 应用激活设备管理器时指定的设备管理器元能力组件不存在。
2. 设备管理器元能力组件不是合法的企业设备管理元能力组件。

**处理步骤**

1. 请检查激活时输入的设备管理器元能力组件name是否存在应用包中。
2. 请检查企业设备管理组件是否继承企业设备管理框架定义的EnterpriseAdminExtensionAbility组件。

## 9200004 激活设备管理器失败

**错误信息**

Failed to activate the administrator application of the device.

**错误描述**

当应用重复激活不同类型的设备管理器或激活多个管理器时，会产生此错误码。

**可能原因**

该错误码表示激活设备管理器失败，可能原因如下：
1. 同时激活多个SDA设备管理器。
2. 重复激活设备管理器，且管理器类型发生变化。
3. 同一个应用多个设备管理器元能力组件激活。

**处理步骤**

1. 检查是否激活多个SDA设备管理器，SDA设备管理器只允许激活一个。
2. 检查指定的设备管理器是否已激活了，且重复激活时管理器类型发生变化，此时需要先解除激活，再重新激活。
3. 检查待激活的设备管理器应用中是否已有设备管理元能力组件激活过，同一个应用只允许激活一个设备管理器元能力组件。

## 9200005 解除激活设备管理器失败

**错误信息**

Failed to deactivate the administrator application of the device.

**错误描述**

当应用没有激活过或者解除激活的是其他设备管理器时，会产生此错误码。

**可能原因**

该错误码表示解除激活设备管理器失败，可能原因如下。
1. 解除激活的设备管理器应用没有激活过。
2. 不能解除激活其他设备管理器。

**处理步骤**

1. 检查解除激活时设备管理应用是否激活过。
2. 检查解除激活时设备管理应用中指定设备管理元能力组件是否激活过。
3. 检查调用者是否解除激活自身，设备管理器应用不能解除激活其他设备管理器应用。

<!--Del-->
## 9200006 指定的用户ID非法

**错误信息**

The specified user ID is invalid.

**错误描述**

当应用调用接口设置用户策略，指定的user ID不存在、或DA管理器跨用户设置，则会产生此错误码。

**可能原因**

该错误码表示指定的用户ID非法，可能原因如下。
1. 调用接口设置用户策略，指定的user ID不存在。
2. DA管理器不允许跨用户设置，指定的user ID和调用者user ID不同。

**处理步骤**

1. 检查调用接口中指定的user ID是否是有效的user ID。
2. 检查调用者user ID和指定设置的user ID是否是同一user ID，DA模式下不允许跨用户设置策略。
<!--DelEnd-->

## 9200007 系统服务工作异常

**错误信息**

The system ability works abnormally.

**错误描述**

当企业设备管理服务异常时，则会产生此错误码。

**可能原因**

该错误码表示系统服务工作异常，可能原因如下。
1. 企业设备管理服务没有正常启动。
2. 企业设备管理的RPC对象无法获取。
3. 企业设备管理依赖的其他服务没有正常启动或者RPC对象无法获取。
4. 企业设备管理运行过程中系统异常。

**处理步骤**

系统服务内部工作异常，请稍后重试，或者重启设备尝试。

## 9200008 系统订阅事件无效

**错误信息**

The specified system event is invalid.

**错误描述**

当企业设备管理暂不支持订阅此事件或系统订阅的事件无效时，则会产生此错误码。

**可能原因**

企业设备管理暂不支持订阅此事件或系统订阅的事件无效。

**处理步骤**

检查所订阅事件是企业设备管理所支持的有效管理事件。

## 9200009 授予应用权限失败

**错误信息**

Failed to grant the permission to the application.

**错误描述**

当超级设备管理应用授予其他应用管理员权限失败时，则会产生此错误码。

**可能原因**

被授予权限的应用未在管理员用户下安装。

**处理步骤**

检查需要被授予权限的应用是否在管理员用户下安装。

## 9200010 策略冲突

**错误信息**

A conflict policy has been configured.

**错误描述**

当企业设备管理在存在互斥策略的情况下下发策略，则会产生此错误码。

**可能原因**

企业设备管理在存在互斥策略的情况下下发策略。

**处理步骤**

先取消与当前策略互斥的策略，然后再下发策略。

<!--Del-->
## 9200011 设备管理应用替换失败

**错误信息**

Failed to replace the administrator application of the device.

**错误描述**

设备管理应用替换失败。

**可能原因**

指定应用为被委托、被授权的设备管理应用或普通设备管理应用，无法成为超级设备管理应用。

**处理步骤**

1. 采用[disableSuperAdmin](js-apis-enterprise-adminManager-sys.md#adminmanagerdisablesuperadmin)接口取消超级设备管理权限，即可取消指定应用的被委托、被授权的设备管理权限。
2. 采用[disableAdmin](js-apis-enterprise-adminManager.md#adminmanagerdisableadmin)接口取消指定应用的普通设备管理权限。
<!--DelEnd-->

## 9200012 参数校验失败

**错误信息**

Parameter verification failed.

**错误描述**

参数校验失败时，会产生此错误码。

**可能原因**

参数校验失败时，可能的原因如下。
1. 传入的企业设备管理扩展组件不属于当前应用。
2. 传入的参数长度超长。
3. 传入的数组长度超出限制。
4. 参数值不在取值范围内。
5. 对尚未设置的禁用或允许名单进行了移除操作。

**处理步骤**

1. 检查传入的企业设备管理扩展组件是否属于当前应用。
2. 检查传入的参数长度是否超过接口限制。
3. 检测传入的数组长度是否超过接口限制。
4. 检查传入参数值是否在接口支持取值范围内。
5. 移除前先查询是否有设置相应的名单。

## 9200013 管控未实时生效

**错误信息**

The enterprise management policy has been successfully set, but the function has not taken effect in real time.

**错误描述**

企业管控策略设置成功，但是管控未实时生效。

**可能原因**

在外置存储管控场景，禁用外置存储时，由于外置存储有文件正在被使用，导致禁用未实时生效，此时无法立即卸载外置存储。

**处理步骤**

重启设备，重启后管控生效。在外置存储管控场景下，重启后禁用外置存储生效，不会主动加载外置存储。

## 9200014 启动组件失败

**错误信息**

Failed to start the ability.

**错误描述**

启动组件失败时，会产生此错误码。

**可能原因**

1. 当设置了禁止运行应用名单（例如调用[addDisallowedRunningBundlesSync](js-apis-enterprise-applicationManager.md#applicationmanageradddisallowedrunningbundlessync)接口），且应用在禁止运行应用名单中时，启动组件会失败。
2. 当设置了允许运行应用名单（例如调用[addAllowedRunningBundles](js-apis-enterprise-applicationManager.md#applicationmanageraddallowedrunningbundles21)接口），且应用不在允许运行应用名单中时，启动组件会失败。

**处理步骤**

1. 将应用从禁止运行名单中移除，例如调用[removeDisallowedRunningBundlesSync](js-apis-enterprise-applicationManager.md#applicationmanagerremovedisallowedrunningbundlessync)接口。
2. 将应用添加到允许运行名单，例如调用[addAllowedRunningBundles](js-apis-enterprise-applicationManager.md#applicationmanageraddallowedrunningbundles21)接口。

## 9200015 组件不存在

**错误信息**

The ability does not exist.

**错误描述**

当组件不存在，启动该组件时，会产生此错误码。

**可能原因**

1. 传入了不存在bundleName和abilityName。
2. 传入的Ability对外不可见。

**处理步骤**

1. 检查want中的bundleName和abilityName是否正确。
2. 检查传入的Ability对外是否可见。

## 9200016 服务超时

**错误信息**

Service timeout.

**错误描述**

当服务超时时，方法将返回该错误码。

**可能原因**

服务超时。

**处理步骤**

服务超时，请稍后重试。

## 9200017 企业设备管理员自激活凭证无效

**错误信息**

The self-activation credential of the enterprise device administrator is invalid.

**错误描述**

当企业设备管理员自激活凭证无效时，方法将返回该错误码。

**可能原因**

1. 企业ID不匹配。

2. 应用appIdentifier配置失败。

3. 激活凭证缺少必需字段或者证书链校验失败。

**处理步骤**

检查企业设备管理员自激活凭证是否正确。

## 9200018 该设备非企业设备

**错误信息**

This device is not an enterprise device.

**错误描述**

该设备非企业设备。

**可能原因**

该设备非企业设备。

**处理步骤**

检查该设备是否设置为企业设备。

## 9201001 管理证书失败

**错误信息**

Failed to manage the certificate.

**错误描述**

当超级设备管理应用安装或卸载用户证书失败时，会产生此错误码。

**可能原因**

用户证书信息错误。

**处理步骤**

检查用户证书是否正确。

## 9201002 企业应用安装失败

**错误信息**

Failed to install the application.

**错误描述**

当企业设备管理安装企业应用失败时，则会产生此错误码。

**可能原因**

该错误码表示安装企业应用失败。

如果调用接口为[bundleManager.install](./js-apis-enterprise-bundleManager.md#bundlemanagerinstall)，可能原因如下。
1. 应用安装路径为空、不存在、无效路径。
2. 安装多个不同包名的应用。
3. 当安装参数flag为0时再次安装已存在的应用。
4. 传入无效用户id。

<!--RP3--><!--RP3End-->

**处理步骤**

如果调用接口为[bundleManager.install](./js-apis-enterprise-bundleManager.md#bundlemanagerinstall)，处理步骤如下。

1. 检查应用安装路径是有效的安装路径。
2. 检查安装参数是有效的安装参数。
3. 检查安装的是同一应用。

<!--RP4--><!--RP4End-->

## 9201003 创建账号失败

**错误信息**

Failed to add an OS account.

**错误描述**

当企业设备管理创建账号失败时，会产生此错误码。

**可能原因**

该错误码表示创建账号失败，可能原因如下。

1. 账号已存在。
2. 账号名非法。
3. 创建账号时未连接网络。
4. 系统不支持多账号。

**处理步骤**

1. 检查账号名是否已存在，如果已存在则需更换。
2. 检查账号名长度和内容，确保正确性。
3. 确保创建账号时网络畅通。

## 9201004 系统更新包不存在或解析失败

**错误信息**

The update packages do not exist or analyzing failed.

**错误描述**

当企业设备管理通知系统更新包失败时，会产生此错误码。

**可能原因**

该错误码表示通知系统更新包失败，可能原因如下。

1. 系统更新包不存在。
2. 系统更新包文件名校验失败。
3. 系统更新包打开失败。
4. 系统更新包解析失败。

**处理步骤**

1. 检查系统更新包是否存在。
2. 检查系统更新包文件名是否有效。
3. 检查系统更新包是否具有可读权限。
4. 检查系统更新包是否完整。

## 9201005 添加保活应用失败

**错误信息**

Add keep alive applications failed.

**错误描述**

当企业设备管理添加保活应用失败时，则会产生此错误码。

**可能原因**

该错误码表示添加保活应用失败，可能原因如下。

1. 应用未安装。
2. 应用没有MainAbility。
3. 应用没有托盘服务。
4. 应用未添加到托盘。
5. 当前设备不支持添加保活应用。

**处理步骤**

1. 检查应用是否安装。
2. 检查应用是否有MainAbility。
3. 检查应用是否实现托盘服务。
4. 检查应用是否已添加到托盘。

## 9201006 安装企业重签名证书超过数量上限

**错误信息**

The number of certificates has reached the limit.

**错误描述**

当企业设备管理已安装的企业重签名证书数量达到10个时，会产生此错误码。

**可能原因**

已安装的企业重签名证书数量达到上限。

**处理步骤**

检查已安装的企业重签名证书数量是否达到10个，卸载多余证书。

## 9201007 企业重签名证书无效

**错误信息**

The certificate is invalid.

**错误描述**

当企业设备管理安装企业重签名证书失败时，会产生此错误码。

**可能原因**

该错误码表示企业设备管理安装企业重签名证书失败，可能原因如下。

1. 证书无效。
2. 已安装过同名证书。

**处理步骤**

1. 检查证书是否为有效的企业重签名证书。
2. 检查是否已安装过同名证书。

## 9201008 企业重签名证书不存在

**错误信息**

The certificate does not exist.

**错误描述**

当企业设备管理卸载企业重签名证书失败时，会产生此错误码。

**可能原因**

卸载的证书不存在。

**处理步骤**

检查卸载的证书是否存在。

## 9201009 日志收集任务创建失败

**错误信息**

Collecting logs, please try again later.

**错误描述**

当企业设备管理创建日志收集任务失败时，会产生此错误码。

**可能原因**

当已有一个日志收集任务正在执行时，调用了[systemManager.startCollectLog](./js-apis-enterprise-systemManager.md#systemmanagerstartcollectlog23)接口创建日志收集任务。

**处理步骤**

等前一个日志收集任务完成（即收到[EnterpriseAdminExtensionAbility.onLogCollected](js-apis-EnterpriseAdminExtensionAbility.md#onlogcollected23)回调）后，再调用[systemManager.startCollectLog](./js-apis-enterprise-systemManager.md#systemmanagerstartcollectlog23)接口创建日志收集任务。

## 9201010 以太网网络接口配置失败

**错误信息**

Ethernet configuration failed. Ethernet device not connected.

**错误描述**

以太网配置失败，或以太网设备未连接。

**可能原因**

该错误码表示以太网配置失败，可能原因如下。

1. 网卡未启用。
2. 网卡名输入错误。
3. 配置参数错误。

**处理步骤**

1. 检查网卡是否启用。
2. 检查输入的网卡名是否正确。
3. 检查配置的参数是否正确。

## 9201011 禁用凭据无效

**错误信息**

The credential of the activation lock is invalid.

**错误描述**

禁用凭据无效。

**可能原因**

1. 传入的禁用凭据格式不正确。
2. 传入的禁用凭据字段值不正确。
3. 传入的禁用凭据非当前设备对应的凭据。

**处理步骤**

1. 检查禁用凭据格式是否正确。
2. 检查禁用凭据各字段值是否正确。
3. 检查禁用凭据是否是当前设备对应的禁用凭据。

## 9201012 禁用或启用激活锁失败

**错误信息**

Failed to enable or disable the activation lock.

**错误描述**

禁用或启用激活锁失败。

**可能原因**

<!--RP1-->设备不支持激活锁服务。
<!--RP1End-->

**处理步骤**

<!--RP2-->设备不支持激活锁服务。
<!--RP2End-->

## 9201013 快捷栏中的应用数量已到最大值

**错误信息**

The number of applications in the Dock has reached the maximum.

**错误描述**

当企业设备管理员添加应用到快捷栏失败时，会产生此错误码。

**可能原因**

快捷栏中的应用数量已经达到最大值。

**处理步骤**

删除快捷栏中多余的应用。

## 9201014 指定应用已经在快捷栏中

**错误信息**

The application is already in the Dock.

**错误描述**

当企业设备管理员添加应用到快捷栏失败时，会产生此错误码。

**可能原因**

指定应用已经在快捷栏中，重复添加时会报此错误码。

**处理步骤**

从快捷栏中移除指定应用后，再次添加该应用到快捷栏的指定位置。

## 9201015 指定应用未安装

**错误信息**

The application is not installed.

**错误描述**

当指定应用未安装时，需要下发此应用的策略时，会产生此错误码。

**可能原因**

指定应用未安装。

**处理步骤**

安装指定应用后重试。

## 9201016 指定应用不在快捷栏

**错误信息**

The application has not been added to the Dock.

**错误描述**

当企业设备管理员从快捷栏中移除应用时，会产生此错误码。

**可能原因**

需要移除的应用不在快捷栏。

**处理步骤**

请检查需要从快捷栏中移除的应用包名是否填写正确。

## 9201017 启用SIM或停用SIM卡失败

**错误信息**

SIM card activation or deactivation failed.

**错误描述**

启用SIM或停用SIM卡失败。

**可能原因**

该错误码表示启用SIM或停用SIM卡失败，可能原因如下。

1. 未关闭飞行模式。
2. 未插入SIM卡。

**处理步骤**

1. 检查飞行模式是否关闭。
2. 检查是否插入SIM卡。

## 9201018 指定应用不支持操作

**错误信息**

The application is inoperable.

**错误描述**

当企业设备管理员添加应用到快捷栏失败时，会产生此错误码。

**可能原因**

指定应用如应用中心、任务中心、文件管理、回收站和无图标的应用不支持操作。

**处理步骤**

指定应用不支持添加，请添加其他应用到栏。

## 9201019 指定位置不支持操作

**错误信息**

The location is inoperable.

**错误描述**

当企业设备管理员添加应用到快捷栏失败时，会产生此错误码。

**可能原因**

快捷栏中0或1位置的应用是应用中心或任务中心时，0或1位置的应用不可改变。

**处理步骤**

该位置不可添加应用，请将应用添加到其他位置。

## 9201020 设置默认数据流量卡失败

**错误信息**

set default data sim failed.

**错误描述**

设置默认数据流量卡失败。

**可能原因**

该错误码表示设置默认数据流量卡失败，可能原因如下。

1. 未关闭飞行模式。
2. 未插入SIM卡。

**处理步骤**

1. 检查飞行模式是否关闭。
2. 检查是否插入SIM卡。

## 9201021 设备存在锁屏密码

**错误信息**

A lock screen password has been set for the device.

**错误描述**

当企业设备管理员添加禁用滑动解锁能力的策略时，会产生此错误码。

**可能原因**

设备已经存在锁屏密码，存在锁屏密码时，设备需要校验密码才能进入桌面。

**处理步骤**

删除锁屏密码。

## 9201022 系统磁盘空间不足导致应用安装失败

**错误信息**

Failed to install the HAP because of insufficient system disk space.

**错误描述**

当系统磁盘空间不足导致应用安装失败时，会产生此错误码。

**可能原因**

系统磁盘空间不足。

**处理步骤**

清理系统磁盘空间后重试。

## 9201023 企业设备管理禁止安装导致应用安装失败

**错误信息**

Failed to install the HAP because enterprise device management disallows the installation.

**错误描述**

当企业设备管理禁止安装应用导致安装失败时，会产生此错误码。

**可能原因**

1. 应用不在允许安装名单中。
2. 应用在禁止安装名单中。

**处理步骤**

1. 检查应用是否在允许安装名单中，不在名单中的应用不允许安装。
2. 检查应用是否在禁止安装名单中，在名单中的应用不允许安装。

## 9201024 HAP解析失败导致应用安装失败

**错误信息**

Failed to install the HAP because the HAP fails to be parsed.

**错误描述**

当HAP包解析失败导致应用安装失败时，会产生此错误码。

**可能原因**

该错误码表示HAP包解析失败，可能原因如下。
1. HAP包文件损坏或不完整。
2. HAP包格式不正确。
3. HAP包配置文件错误。

**处理步骤**

1. 检查HAP包文件是否完整无损。
2. 检查HAP包格式是否正确。
3. 检查HAP包配置文件是否符合规范。

## 9201025 HAP签名验证失败导致应用安装失败

**错误信息**

Failed to install the HAP because the HAP signature fails to be verified.

**错误描述**

当HAP包签名验证失败导致应用安装失败时，会产生此错误码。

**可能原因**

该错误码表示HAP签名验证失败，可能原因如下。
1. HAP包签名无效。
2. HAP包签名证书过期。
3. HAP包签名证书不被信任。

**处理步骤**

1. 检查HAP包签名是否有效。
2. 检查HAP包签名证书是否过期。
3. 检查HAP包签名证书是否为可信证书。

## 9201026 HAP路径无效或文件过大导致应用安装失败

**错误信息**

Failed to install the HAP because the HAP path is invalid or the HAP is too large.

**错误描述**

当HAP包路径无效或文件过大导致应用安装失败时，会产生此错误码。

**可能原因**

该错误码表示HAP路径无效或文件过大，可能原因如下。
1. HAP包路径不存在或无效。
2. HAP包文件超过系统限制大小。

**处理步骤**

1. 检查HAP包路径是否存在且有效。
2. 检查HAP包文件大小是否在系统允许范围内。

## 9201027 HAP配置信息不一致导致安装失败

**错误信息**

Failed to install the HAPs because they have different configuration information.

**错误描述**

当多个HAP包配置信息不一致导致安装失败时，会产生此错误码。

**可能原因**

同时安装多个HAP包时，HAP包的配置信息不一致。

**处理步骤**

检查待安装的多个HAP包配置信息是否一致。

## 9201028 isolationMode配置不支持导致应用安装失败

**错误信息**

Failed to install the HAP because the isolationMode configured is not supported.

**错误描述**

当HAP包配置的isolationMode不被支持导致应用安装失败时，会产生此错误码。

**可能原因**

HAP包配置的isolationMode不被当前系统支持。

**处理步骤**

检查HAP包配置的isolationMode是否为系统支持的值。

## 9201029 HAP版本过低导致应用安装失败

**错误信息**

Failed to install the HAP since the version of the HAP to install is too early.

**错误描述**

当HAP包版本过低导致应用安装失败时，会产生此错误码。

**可能原因**

待安装的HAP包版本低于已安装的应用版本。

**处理步骤**

使用更高版本的HAP包进行安装。

## 9201030 VersionCode不大于当前版本导致应用安装失败

**错误信息**

Failed to install the HAP because the VersionCode to be updated is not greater than the current VersionCode.

**错误描述**

当更新安装的HAP包VersionCode不大于当前已安装版本导致安装失败时，会产生此错误码。

**可能原因**

待更新安装的HAP包VersionCode不大于当前已安装应用的VersionCode。

**处理步骤**

确保待安装的HAP包VersionCode大于当前已安装应用的VersionCode。

## 9201031 依赖模块不存在导致应用安装失败

**错误信息**

Installation failed because the dependent module does not exist.

**错误描述**

当应用依赖的模块不存在导致安装失败时，会产生此错误码。

**可能原因**

应用依赖的模块未安装或不存在。

**处理步骤**

先安装应用依赖的模块，然后再安装该应用。

## 9201032 指定用户ID不存在

**错误信息**

The specified user ID is not found.

**错误描述**

当指定的用户ID不存在时，会产生此错误码。

**可能原因**

指定的用户ID在系统中不存在。

**处理步骤**

检查指定的用户ID是否为有效的用户ID。

可参考[包管理子系统通用错误码](../apis-ability-kit/errorcode-bundle.md)中的错误码17700004。

## 9201033 overlay检查失败导致应用安装失败

**错误信息**

Failed to install the HAP because the overlay check failed.

**错误描述**

当安装overlay特征的应用时，指定的应用和待安装的overlay特征应用不为预置应用，或者目标应用/目标module是overlay特征的应用/module。

**可能原因**

1. 使用应用间的overlay特性时，overlay特征应用必须为预置应用。
2. 使用应用间的overlay特性时，目标应用必须为预置应用。
3. 使用应用间的overlay特性时，目标应用不能是具有overlay特征的应用。
4. 目标module不能是具有overlay特征的module。

**处理步骤**

1. 检查overlay特征应用是否为预置应用。
2. 检查目标应用是否为预置应用。
3. 检查目标应用是否不为overlay特征的应用。
4. 检查目标module是否不为overlay特征的module。

## 9201034 HSP缺少必需权限导致应用安装失败

**错误信息**

Failed to install the HSP due to missing required permissions.

**错误描述**

当HSP包缺少必需权限导致安装失败时，会产生此错误码。

**可能原因**

HSP包缺少必需的权限配置。

**处理步骤**

检查HSP包是否包含所有必需的权限配置。

## 9201035 跨应用共享库安装不被允许导致应用安装失败

**错误信息**

Installation failed because the installation of cross-app shared libraries is not allowed.

**错误描述**

当跨应用共享库安装不被允许导致应用安装失败时，会产生此错误码。

**可能原因**

系统不允许安装跨应用共享库。

**处理步骤**

确认当前场景是否允许安装跨应用共享库。

## 9201036 数据代理URI错误导致应用安装失败

**错误信息**

Failed to install the HAP due to incorrect URI in the data proxy.

**错误描述**

当数据代理URI配置错误导致应用安装失败时，会产生此错误码。

**可能原因**

HAP包中数据代理的URI配置不正确。

**处理步骤**

检查HAP包中数据代理的URI配置是否正确。

## 9201037 数据代理权限配置错误导致应用安装失败

**错误信息**

Failed to install the HAP due to incorrect permission configuration in the data proxy.

**错误描述**

当数据代理权限配置错误导致应用安装失败时，会产生此错误码。

**可能原因**

HAP包中数据代理的权限配置不正确。

**处理步骤**

检查HAP包中数据代理的权限配置是否正确。

## 9201038 代码签名验证失败导致应用安装失败

**错误信息**

Failed to install the HAP due to code signature verification failure.

**错误描述**

当代码签名验证失败导致应用安装失败时，会产生此错误码。

**可能原因**

该错误码表示代码签名验证失败，可能原因如下。
1. HAP包代码签名无效。
2. HAP包代码签名证书不被信任。

**处理步骤**

1. 检查HAP包代码签名是否有效。
2. 检查HAP包代码签名证书是否为可信证书。

## 9201039 企业设备验证失败导致应用安装失败

**错误信息**

Failed to install the HAP due to enterprise device verification failure.

**错误描述**

当企业设备验证失败导致应用安装失败时，会产生此错误码。

**可能原因**

该错误码表示企业设备验证失败，可能原因如下。
1. 设备不在企业设备管理范围内。
2. 设备未通过企业设备管理验证。

**处理步骤**

确认设备是否在企业设备管理范围内，并通过企业设备管理验证。

## 9201040 系统账号数量已达到最大限制

**错误信息**

The number of accounts reaches the upper limit.

**错误描述**

已创建的系统账号数量达到最大限制。

**可能原因**

当已创建系统账号的数量达到最大值，再创建新系统账号时，会产生此错误码。

**处理步骤**

确认已创建系统账号数量是否达到上限，及时移除不需要保留的系统账号。

## 9201041 系统账号类型受限

**错误信息**

Restricted account.

**错误描述**

当前类型的系统账号不支持此类操作。

**可能原因**

1. 移除系统账号时，移除的是默认系统账号。
2. 切换系统账号时，不支持切换为此类型系统账号。

**处理步骤**

确认系统账号的类型是否支持此类操作。

## 9201043 API调用的前置条件未满足

**错误信息**

Prerequisites for the API call have not been satisfied. For example, distributed outgoing transmission is not disallowed before adding the distributed bidirectional collaboration trustlist.

**错误描述**

当API调用的前置条件未满足时，会产生此错误码。

**可能原因**

在添加允许分布式双向协同应用名单之前，设备间单向传输能力未被禁止。

**处理步骤**

先通过[setDisallowedPolicyForAccount](./js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicyforaccountdeprecated)接口禁用设备间单向传输数据的能力，再添加允许分布式双向协同应用名单。

## 9201044 指定权限未被禁用

**错误信息**

This permission is not disallowed. Applications cannot be added to or removed from the trustlist.

**错误描述**

指定权限未被禁用时，给该权限添加权限使用例外名单，会产生此错误码。

**可能原因**

在添加允许使用已禁用指定权限的应用到权限使用例外名单之前，指定权限未被禁止。

**处理步骤**

先通过[setDisallowedPermission](./js-apis-enterprise-securityManager.md#securitymanagersetdisallowedpermission)接口禁用指定权限，再给指定权限添加权限使用例外名单。

## 9201045 指定权限不可被禁用

**错误信息**

This permission cannot be disallowed.

**错误描述**

需要禁用指定权限时，会产生此错误码。

**可能原因**

需要禁用的权限的APL等级不是normal或system_basic。

**处理步骤**

检查需要禁用的权限的APL等级是否为normal或system_basic。

## 9201046 已登录系统账号数量达到上限

**错误信息**

The number of signed-in accounts reaches the upper limit.

**错误描述**

当前设备上已登录的系统账号数量达到最大上限。

**可能原因**

当前创建并登录的系统账号已达到最大限制。

**处理步骤**

尝试注销多余的系统账号，并及时移除不再需要保留的系统账号。
