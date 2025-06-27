# 元能力子系统错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 16000001 指定的Ability名称不存在

**错误信息**

The specified ability does not exist.

**错误描述**

当指定的Ability名称不存在时，方法将返回该错误码。

**可能原因**

所查询的Ability不存在。

**处理步骤**

1. 检查want中的bundleName、moduleName和abilityName是否正确。
2. 检查传入want中bundleName对应的应用是否安装。可使用如下命令查询已安装的应用列表，若bundleName不在查询结果中，说明应用未安装成功。
    ```
    hdc shell bm dump -a
    ```
3. 多hap应用需确认ability所属的hap是否已被安装。可使用如下命令查询应用的包信息，若安装的应用中没有对应的hap和ability，说明ability所属的hap未被安装。
    ```
    hdc shell bm dump -n 包名
    ```

## 16000002 接口调用Ability类型错误

**错误信息**

Incorrect ability type.

**错误描述**

当接口调用Ability类型错误时，方法将返回该错误码。

**可能原因**

接口调用所在的Ability类型不支持该接口调用。

**处理步骤**

1. 检查want中的bundleName、moduleName和abilityName是否正确。
2. 根据Ability类型调用不同接口，如ServiceExtensionAbility应使用<!--Del-->[startServiceExtensionAbility](js-apis-inner-application-uiAbilityContext-sys.md#startserviceextensionability)方法启动或<!--DelEnd-->[connectServiceExtensionAbility()](js-apis-inner-application-uiAbilityContext.md#connectserviceextensionability)方法连接。

## 16000003 指定的ID不存在

**错误信息**

The specified ID does not exist.

**错误描述**

当指定的ID不存在时，方法将返回该错误码。

**可能原因**

操作的目标ID不存在。

**处理步骤**

确认操作的ID是否存在。

## 16000004 可见性校验失败

**错误信息**

Cannot start an invisible component.

**错误描述**

当可见性校验失败时，方法将返回该错误码。

**可能原因**

应用可见性校验失败。

**处理步骤**

1. Stage模型下，拉起应用时抛出16000004异常，表示被拉应用调用失败，需要检查被拉应用module.json5的Ability字段的[exported](../../quick-start/module-configuration-file.md#abilities标签)配置是否为true。该配置字段为true，表示可以被其他应用调用；该配置字段为false，表示不可以被其他应用调用。
2. 若应用需要拉起exported为false的ability，请申请ohos.permission.START_INVISIBLE_ABILITY权限（该权限仅系统应用可申请）。

## 16000005 指定的进程权限校验失败

**错误信息**

The specified process does not have the permission.

**错误描述**

当指定的进程权限校验失败时，方法将返回该错误码。

**可能原因**

指定的进程权限校验失败。

**处理步骤**

确认指定进程的权限是否正确。

## 16000006 不允许跨用户操作

**错误信息**

Cross-user operations are not allowed.

**错误描述**

当应用跨用户操作时，方法将返回该错误码。

**可能原因**

应用进行了跨用户操作。

**处理步骤**

确认是否进行了跨用户操作。

## 16000007 服务繁忙

**错误信息**

Service busy. There are concurrent tasks. Try again later.

**错误描述**

当服务繁忙时，方法将返回该错误码。

**可能原因**

服务繁忙。

**处理步骤**

服务繁忙，请稍后重试。

## 16000008 众测应用到期

**错误信息**

The crowdtesting application expires.

**错误描述**

当众测应用到期时，方法将返回该错误码。

**可能原因**

众测应用到期，无法打开。

**处理步骤**

请检查应用是否众测到期，已过有效期的众测应用无法启动。

## 16000009 wukong模式，不允许启动/停止ability

**错误信息**

An ability cannot be started or stopped in Wukong mode.

**错误描述**

当wukong模式下，启动/停止ability时，方法将返回该错误码。

**可能原因**

wukong模式，不允许启动/停止ability。

**处理步骤**

退出wukong模式后，再尝试启动/停止ability。请勿在wukong模式下启动/停止Ability。

## 16000010 不允许带迁移flag

**错误信息**

The call with the continuation and prepare continuation flag is forbidden.

**错误描述**

当调用携带迁移flag时，方法将返回该错误码。

**可能原因**

当前调用不允许携带迁移flag。

**处理步骤**

请检查是否携带迁移flag。

## 16000011 上下文对象不存在

**错误信息**

The context does not exist.

**错误描述**

当上下文对象不存在时，方法将返回该错误码。

**可能原因**

当前上下文对象不存在。

**处理步骤**

请检查上下文对象是否可用。

## 16000012 应用被管控

**错误信息**

The application is controlled.

**错误描述**

当应用受到管控时，将返回该错误码。

**可能原因**

应用被系统管控模块管控，不允许启动。

**处理步骤**

建议卸载该应用。

## 16000013 应用被EDM管控

**错误信息**

The application is controlled by EDM.

**错误描述**

当应用受到企业设备管理[Enterprise Device Manager](../../mdm/mdm-kit-admin.md)管控时，方法将返回该错误码。

**可能原因**

应用受企业设备管理管控。

**处理步骤**

请联系企业设备管理相关人员。

## 16000015 服务超时

**错误信息**

Service timeout.

**错误描述**

当服务超时时，方法将返回该错误码。

**可能原因**

服务超时。

**处理步骤**

服务超时，请稍后重试。

## 16000018 限制API 11以上版本三方应用跳转

**错误信息**

Redirection to a third-party application is not allowed in API version greater than 11.

**错误描述**

当应用API版本大于11的时候，不允许显式跳转到其他三方应用。

**可能原因**

应用使用的API版本大于11并且显式跳转到其他三方应用。

**处理步骤**

使用隐式启动方式或通过[openLink](js-apis-inner-application-uiAbilityContext.md#openlink12)跳转其他应用。

## 16000019 隐式启动未查找到匹配应用

**错误信息**

No matching ability is found.

**错误描述**

隐式启动无法查找到匹配的Ability。

**可能原因**

1. 隐式启动的参数配置有误。
2. 指定的HAP包未安装。

**处理步骤**

1. 确保隐式启动的参数配置正确。
2. 确保对应的HAP包已安装。

<!--Del-->
## 16000020 传入的Context对象不是Ability级别Context

**错误信息**

The context is not ability context.

**错误描述**

传入的Context对象不是Ability级别Context。

**可能原因**

传入的Context对象既不是UIAbilityContext或ExtensionContext，也没有继承自UIAbilityContext或ExtensionContext。

**处理步骤**

使用UIAbilityContext或ExtensionContext对象作为入参，或者使用继承了UIAbilityContext或ExtensionContext类的对象作为入参。
<!--DelEnd-->

## 16000050 内部错误

**错误信息**

Internal error.

**错误描述**

当内存申请、多线程处理异常等内部处理错误时，方法将返回该错误码。

**可能原因**

内存申请、多线程处理等内核通用错误。具体原因可能包括：内部对象为空、处理超时、包管理获取应用信息失败、系统服务获取失败、启动的ability实例已达到上限等等。

**处理步骤**

1. 确认系统内存是否足够，设备使用的系统版本是否存在异常。
2. 检查是否启动了过多的ability。
3. 尝试重启设备。

## 16000053 非顶层应用

**错误信息**

The ability is not on the top of the UI.

**错误描述**

当前应用未显示在界面顶层时，方法将返回该错误码。

**可能原因**

用户执行免安装启动时需要确保应用在前台，但应用未显示在界面顶层。

**处理步骤**

请检查当前应用是否显示在界面顶层。

## 16000055 免安装超时

**错误信息**

Installation-free timed out.

**错误描述**

当免安装超时时，方法将返回该错误码。

**可能原因**

免安装超时。

**处理步骤**

免安装超时，请稍后重试。

<!--Del-->
## 16000058 指定的URI flag无效

**错误信息**

Invalid URI flag.

**错误描述**

指定的URI flag无效。

**可能原因**

传入的参数有误。

**处理步骤**

确认传入的参数属于Uri flag。

## 16000059 指定的URI类型无效

**错误信息**

Invalid URI type.

**错误描述**

指定的URI类型无效。

**可能原因**

传入的参数有误，目前URI授权管理仅支持file类型URI。

**处理步骤**

确认传入的参数属于支持的URI类型。

## 16000060 不支持沙箱应用授权URI

**错误信息**

A sandbox application cannot grant URI permission.

**错误描述**

当沙箱应用授权URI时，方法将返回该错误码。

**可能原因**

不支持沙箱应用授权URI。

**处理步骤**

确认为非沙箱应用。
<!--DelEnd-->

## 16000061 不支持的操作

**错误信息**

Operation not supported.

**错误描述**

当操作在当前系统上不支持时，返回该错误码。

**可能原因**

操作在当前系统上不支持。

**处理步骤**

确认操作在当前系统上是否支持。

## 16000062 子进程数量超出上限

**错误信息**

The number of child processes exceeds the upper limit.

**错误描述**

当申请创建子进程时，创建的子进程数量已经达到上限，返回该错误码。

**可能原因**

创建的子进程数量已经达到上限。

**处理步骤**

确认创建的子进程数量是否已经达到上限。子进程数量上限为512个。

## 16000063 重启应用指定组件无效

**错误信息**

The target to restart does not belong to the current application or is not a UIAbility.

**错误描述**

当重启应用拉起指定组件时，指定组件名称或类型无效，返回该错误码。

**可能原因**

指定组件名称或类型无效。

**处理步骤**

确认指定组件名称为当前应用组件，且类型为UIAbility。

## 16000064 重启应用频繁

**错误信息**

Restart too frequently. Try again at least 3s later.

**错误描述**

当重启应用拉起指定组件时，3s内再次调用，返回该错误码。

**可能原因**

调用接口频繁。

**处理步骤**

间隔3s后再次调用。

## 16000065 接口只支持Ability在前台时调用

**错误信息**

The API can be called only when the ability is running in the foreground.

**错误描述**

当Ability不在前台时，方法将返回该错误码。

**可能原因**

调用接口时，Ability不在前台。

**处理步骤**

将Ability切换到前台后，再调用接口。

## 16000066  wukong模式，不允许移动Ability到前台/后台

**错误信息**

An ability cannot switch to the foreground or background in Wukong mode.

**错误描述**

当wukong模式下，移动Ability到前台/后台时，方法将返回该错误码。

**可能原因**

wukong模式，不允许移动Ability到前台/后台。

**处理步骤**

退出wukong模式后，再尝试移动Ability到前台/后台。请勿在wukong模式下移动Ability到前台/后台。

## 16000067 Ability启动参数校验失败

**错误信息**

The StartOptions check failed.

**错误描述**

当StartOptions相关的参数校验失败时，返回该错误码。

**可能原因**

1. 调用startAbility时，processMode设置为NEW_PROCESS_ATTACH_TO_STATUS_BAR_ITEM或者ATTACH_TO_STATUS_BAR_ITEM，但是应用在状态栏没有图标，则返回该错误码。
2. 调用showAbility/hideAbility时，如果调用方不是以NEW_PROCESS_ATTACH_TO_STATUS_BAR_ITEM或者ATTACH_TO_STATUS_BAR_ITEM模式启动，则返回该错误码。

**处理步骤**

确认StartOptions参数配置，以及相应的约束条件是否满足。

## 16000068 Ability已经在运行中

**错误信息**

The ability is already running.

**错误描述**

当目标Ability已经在运行中时，返回该错误码。

**可能原因**

调用startAbility时，指定了processMode和startupVisibility，目标Ability的launchType是singleton或者specified，并且目标Ability正在运行中，则返回该错误码。

**处理步骤**

当目标Ability的launchType是singleton或者specified时，避免通过指定processMode和startupVisibility的方式重复startAbility。

## 16000069 严格模式下不允许该类型Extension启动三方应用

**错误信息**

The extension cannot start the third party application.

**错误描述**

严格模式下，不允许该类型Extension启动三方应用。

**可能原因**

当前Extension处于严格模式，且对应的Extension类型不允许严格模式下启动其他三方应用。

**处理步骤**

1. 查看[对应Extension类型](../../application-models/extensionability-overview.md)严格模式开启条件。
2. 以非严格模式启动当前Extension。

## 16000070 严格模式下不允许该类型Extension启动指定ServiceExtensionAbility

**错误信息**

The extension cannot start the service.

**错误描述**

严格模式下，不允许该类型Extension启动指定ServiceExtensionAbility。

**可能原因**

当前Extension处于严格模式，且对应的Extension类型不允许严格模式下启动指定ServiceExtensionAbility。

**处理步骤**

1. 查看[对应Extension类型](../../application-models/extensionability-overview.md)严格模式开启条件。
2. 以非严格模式启动当前Extension。

## 16000071 不支持应用分身模式

**错误信息**

App clone is not supported.

**错误描述**

当应用不支持分身模式时，返回该错误码。

**可能原因**

该应用没有在app.json5配置文件[multiAppMode](../../quick-start/app-configuration-file.md#multiappmode标签)标签中配置应用分身字段，导致该应用不支持分身模式，调用[getCurrentAppCloneIndex](./js-apis-inner-application-applicationContext.md#applicationcontextgetcurrentappcloneindex12)接口时返回该错误码。

**处理步骤**

参考[应用多实例的配置方法](../../quick-start/multiInstance.md)，在app.json5配置文件中配置multiAppMode标签，开启应用分身功能后，再调用[getCurrentAppCloneIndex](./js-apis-inner-application-applicationContext.md#applicationcontextgetcurrentappcloneindex12)接口。

<!--Del-->
## 16000072 不支持应用多开

**错误信息**

App clone or multi-instance is not supported.

**错误描述**

当应用不支持多开时，返回该错误码。

**可能原因**

调用getRunningMultiAppInfo查询不支持应用多开的应用多开信息，则返回该错误码。

**处理步骤**

调用getCurrentAppCloneIndex时确保查询的应用支持应用多开。
<!--DelEnd-->

## 16000073 传入的appCloneIndex是一个无效值

**错误信息**

The app clone index is invalid.

**错误描述**

传入一个无效的appCloneIndex，返回该错误码。

**可能原因**

1.调用startAbility时，使用ohos.extra.param.key.appCloneIndex携带的appCloneIndex是一个无效值，则返回该错误码。
2.调用isAppRunning时，入参appCloneIndex是一个无效值，则返回该错误码。

**处理步骤**

确认appCloneIndex的约束条件是否满足。

## 16000074 返回结果时requestCode对应的调用方不存在

**错误信息**

The caller does not exist.

**错误描述**

通过backTocallerAbilityResult接口向调用方返回结果时，如果根据传入的requestCode无法找到调用方，返回该错误码。

**可能原因**

1. requestCode不是通过want中的CALLER_REQUEST_CODE字段获取的。

2. requestCode对应的调用方已经被销毁或结果已经返回。

**处理步骤**

1. 确认requestCode是否是通过want中的CALLER_REQUEST_CODE获取的。

2. 确认调用方是否被销毁或结果已经返回。

## 16000075 不支持返回结果时拉起调用方

**错误信息**

BackToCaller is not supported.

**错误描述**

不支持通过backToCallerAbilityWithResult接口返回到调用方时，返回该错误码。

**可能原因**

当前应用未进行linkFeature配置或未通过系统审核。

**处理步骤**

1. 确认当前应用已在module.json5文件中配置linkFeature字段。
2. 确认当前应用声明的linkFeature取值正确，linkFeature描述的功能与应用链接对应的实际功能一致，且应用通过系统审核。

## 16000076 指定的APP_INSTANCE_KEY不存在

**错误信息**

The app instance key is invalid.

**错误描述**

指定的[APP_INSTANCE_KEY](js-apis-app-ability-wantConstant.md#params)不存在时，返回该错误码。

**可能原因**

应用的实例中不存在该[APP_INSTANCE_KEY](js-apis-app-ability-wantConstant.md#params)指定的实例。

**处理步骤**

确保传入的[APP_INSTANCE_KEY](js-apis-app-ability-wantConstant.md#params)是一个有效值。

## 16000077 应用的实例数量已达到上限

**错误信息**

The number of app instances reaches the limit.

**错误描述**

当应用的实例数量达到上限后，继续创建应用实例，返回该错误码。

**可能原因**

创建应用实例前未判断应用实例数量是否已达到应用自己设置的上限值。

**处理步骤**

调整设置的应用实例上限，或者删除已有应用实例后，才能继续创建新的应用实例。

## 16000078 不支持应用多实例

**错误信息**

The multi-instance is not supported.

**错误描述**

应用不支持多实例。

**可能原因**

1. 目标应用未配置多实例。
2. 当前设备类型不支持多实例。

**处理步骤**

1. 对目标应用配置多实例。
2. 在2in1设备上调用该方法。

## 16000079 不支持指定APP_INSTANCE_KEY

**错误信息**

The APP_INSTANCE_KEY cannot be specified.

**错误描述**

[APP_INSTANCE_KEY](js-apis-app-ability-wantConstant.md#params)和[CREATE_APP_INSTANCE_KEY](js-apis-app-ability-wantConstant.md#params)不支持同时指定。当指定[CREATE_APP_INSTANCE_KEY](js-apis-app-ability-wantConstant.md#params)的同时指定[APP_INSTANCE_KEY](js-apis-app-ability-wantConstant.md#params)，返回该错误码。

**可能原因**

参数传入过多。

**处理步骤**

参数[APP_INSTANCE_KEY](js-apis-app-ability-wantConstant.md#params)和[CREATE_APP_INSTANCE_KEY](js-apis-app-ability-wantConstant.md#params)只支持二选一。

## 16000080 不支持创建新实例

**错误信息**

Creating a new instance is not supported.

**错误描述**

只允许应用使用[CREATE_APP_INSTANCE_KEY](js-apis-app-ability-wantConstant.md#params)创建自己的实例，不允许应用间启动时为其他应用创建实例。否则，返回该错误码。

**可能原因**

参数使用场景有误。

**处理步骤**

删除参数[CREATE_APP_INSTANCE_KEY](js-apis-app-ability-wantConstant.md#params)。

<!--Del-->
## 16000081 获取目标应用信息失败

**错误信息**

Failed to obtain the target application information.

**错误描述**

调用[URI授权相关接口](js-apis-uripermissionmanager-sys.md)时，无法根据应用包名和分身索引获取到目标应用的相关信息。

**可能原因**

1. 没有安装目标应用。
2. 分身索引超出允许的范围。
3. 目标应用没有该索引的分身。

**处理步骤**

1. 检查目标应用是否已经安装。
2. 检查分身应用索引是否在允许范围内。
3. 检查目标应用是否创建了该索引对应的分身应用。
<!--DelEnd-->

## 16000084 只允许DelegatorAbility单次调用

**错误信息**

Only DelegatorAbility is allowed to call this API, and only once.

**错误描述**

系统只允许DelegatorAbility调用该接口一次。

**可能原因**

1. 调用方不是DelegatorAbility。
2. 调用方是DelegatorAbility，但是重复调用接口。

**处理步骤**

1. 检查调用方是否DelegatorAbility。
2. 检查是否重复调用。

## 16000085 元能力与窗口的交互流程发生错误

**错误信息**

An error occurred during the interaction between the ability and window.

**错误描述**

元能力与窗口的交互流程发生错误。

**可能原因**

窗口业务流程出现异常。

**处理步骤**

系统错误，尝试重新调用。

## 16000086 传入的context不是UIAbilityContext

**错误信息**

The context is not UIAbilityContext.

**错误描述**

传入的context不是UIAbilityContext。

**可能原因**

传入的Context对象既不是UIAbilityContext、也没有继承自UIAbilityContext。

**处理步骤**

使用UIAbilityContext对象或者继承了UIAbilityContext类的对象作为入参。

## 16000090 调用方不是原子化服务

**错误信息**

The caller is not an atomic service.

**错误描述**

调用方不是原子化服务。

**可能原因**

接口调用方不是原子化服务。

**处理步骤**

当前应用不支持调用该接口。

<!--Del-->
## 16000091 根据key获取文件URI数据失败

**错误信息**

Failed to get the file URI from the key.

**错误描述**

根据key获取文件URI失败。

**可能原因**

1. key为空。
2. key不属于当前调用方。
3. key不属于特定业务的数据通路。
4. key对应UDMF中写入的数据不全为文件URI。

**处理步骤**

1. 确保key是由调用方创建的。
2. 确保key属于特定业务的数据通路。参考[UDMF数据通路](../apis-arkdata/js-apis-data-unifiedDataChannel.md#intention)。
3. 确保创建key时在UDMF中写入的数据都为文件URI。

## 16000092 无权限授权URI

**错误信息**

No permission to authorize the URI.

**错误描述**

无权限授权URI。

**可能原因**

创建key时写入的URI存在无权限授权的URI。

**处理步骤**

确保创建key时写入的URI均为有权限授权的URI。

## 16000093 调用方的token ID无效

**错误信息**

The caller token ID is invalid.

**错误描述**

调用方的token ID无效。

**可能原因**

系统未找到callerTokenId对应的应用。

**处理步骤**

检查callerTokenId对应的应用是否安装。

## 16000094 目标应用的token ID无效

**错误信息**

The target token ID is invalid.

**错误描述**

目标应用的token ID无效。

**可能原因**

1. 系统未找到targetTokenId对应的应用。
2. targetTokenId与callerTokenId是同一应用。

**处理步骤**

1. 确保传入的targetTokenId对应的应用已安装。
2. 确保callerTokenId与targetTokenId不是同一应用。
<!--DelEnd-->

## 16000100 监听Ability生命周期变化的AbilityMonitor方法执行失败

**错误信息**

 - Calling AddAbilityMonitor failed.

 - Calling AddAbilityMonitorSync failed.

 - Calling RemoveAbilityMonitor failed.

 - Calling RemoveAbilityMonitorSync failed.

 - Calling WaitAbilityMonitor failed.

 - Calling GetCurrentTopAbility failed.

 - Calling DoAbilityForeground failed.

 - Calling DoAbilityBackground failed.

 - Calling FinishTest failed.

 - Calling AddAbilityStageMonitor failed.

 - Calling AddAbilityStageMonitorSync failed.

 - Calling RemoveAbilityStageMonitor failed.

 - Calling RemoveAbilityStageMonitorSync failed.

 - Calling WaitAbilityStageMonitor failed.

**错误描述**

当监听指定Ability的生命周期变化的AbilityMonitor方法执行失败时，返回该错误码。

**可能原因**

创建AbilityDelegatorRegistry实例执行失败。

**处理步骤**

检查是否成功创建了AbilityDelegatorRegistry实例。

## 16000110 当前应用不在Kiosk模式的列表内

**错误信息**

Current application is not in kiosk app list, can not exit kiosk mode.

**错误描述**

当前应用不在EDM配置的支持Kiosk模式的应用列表内，尝试进入或退出Kiosk模式时，将返回错误码。

**可能原因**

应用不在EDM配置的支持Kiosk模式的应用列表内。

**处理步骤**

检查应用是否在EDM配置的支持Kiosk模式的应用列表内。

## 16000111 已经有应用进入了Kiosk模式

**错误信息**

System is already in kiosk mode, can not enter again.

**错误描述**

当前系统已有应用进入Kiosk模式，调用方尝试进入时将返回错误码。

**可能原因**

已经有应用进入Kiosk模式。

**处理步骤**

检查系统内是否存在应用已经进入Kiosk模式。

## 16000112 当前系统没有应用进入Kiosk模式

**错误信息**

Current application is not in kiosk mode, can not exit.

**错误描述**

如果系统中没有应用进入Kiosk模式，尝试退出Kiosk模式时将返回错误码。

**可能原因**

当前系统没有应用进入Kiosk模式。

**处理步骤**

检查当前系统是否有应用进入Kiosk模式。

## 16000113 当前Ability不在前台

**错误信息**

Current ability is not in foreground.

**错误描述**

当Ability未处于前台状态时，尝试执行需在前台进行的操作将返回错误码。

**可能原因**

当前Ability没有处于前台。

**处理步骤**

检查当前Ability是否处于前台状态。

## 16000151 无效wantAgent对象

**错误信息**

Invalid wantAgent object.

**错误描述**

当传入接口的wantAgent对象无效时，方法将返回该错误码。

**可能原因**

1. 传入接口的wantAgent对象无效。
2. 三方应用设置其他应用的Ability。
3. 其它内部通信错误。

**处理步骤**

1. 检查传入接口的wantAgent对象是否存在。
2. 检查调用方是否为三方应用。不支持三方应用设置其他应用的Ability。

<!--Del-->
## 16000153 wantAgent对象已被取消

**错误信息**

The WantAgent has been canceled.

**错误描述**

当传入接口的wantAgent对象已被取消时，方法将返回该错误码。

**可能原因**

传入接口的wantAgent对象已被取消。

**处理步骤**

使用未被取消的wantAgent对象。
<!--DelEnd-->

## 16000200 不允许该调用方启动应用后台服务

**错误信息**

The caller is not in the appIdentifierAllowList of the target application.

**错误描述**

调用方不在目标应用的[appIdentifierAllowList](../../quick-start/module-configuration-file.md#extensionabilities标签)中时，返回该错误码。

**可能原因**

[startAppServiceExtensionAbility](js-apis-inner-application-uiAbilityContext.md#startappserviceextensionability20)、[stopAppServiceExtensionAbility](js-apis-inner-application-uiAbilityContext.md#stopappserviceextensionability20)接口调用方的app-identifier不在目标[AppServiceExtensionAbility](js-apis-app-ability-appServiceExtensionAbility.md)的[appIdentifierAllowList](../../quick-start/module-configuration-file.md#extensionabilities标签)中。

**处理步骤**

将接口调用方的app-identifier配置在目标[AppServiceExtensionAbility](js-apis-app-ability-appServiceExtensionAbility.md)的[appIdentifierAllowList](../../quick-start/module-configuration-file.md#extensionabilities标签)中。

## 16000201 目标服务还未启动

**错误信息**

The target service has not been started yet.

**错误描述**

目标服务还未启动时，返回该错误码。

**可能原因**

使用[connectAppServiceExtensionAbility](js-apis-inner-application-uiAbilityContext.md#connectappserviceextensionability20)接口时服务端还未启动且当前应用无权限拉起目标服务。

**处理步骤**

1. 等待服务端启动后重新连接。
2. 由当前应用拉起目标服务时，需要将接口调用方的app-identifier配置在目标[AppServiceExtensionAbility](js-apis-app-ability-appServiceExtensionAbility.md)的[appIdentifierAllowList](../../quick-start/module-configuration-file.md#extensionabilities标签)中。

## 16200001 通用组件客户端(Caller)已回收

**错误信息**

The caller has been released.

**错误描述**

当通用组件客户端(Caller)已回收时，方法将返回该错误码。

**可能原因**

通用组件客户端(Caller)已回收。

**处理步骤**

1. 请重新注册有效通用组件客户端调用接口。
2. 检查调用context.startAbility时，context对应的ability是否还在运行。若该ability已被析构，会抛出该错误码。
3. 若存在连续调用startAbility和terminateSelf的情况，请确认收到startAbility成功或失败的回调后，再调用terminateSelf。

## 16200002 通用组件服务端(Callee)无效

**错误信息**

The callee does not exist.

**错误描述**

当通用组件服务端(Callee)无效时，方法将返回该错误码。

**可能原因**

通用组件服务端(Callee)不存在。

**处理步骤**

请检查通用组件服务端是否存在。

## 16200004 方法已注册

**错误信息**

The method has been registered.

**错误描述**

当方法已注册时，方法将返回该错误码。

**可能原因**

方法已在通用组件服务端注册过。

**处理步骤**

请检查是否已注册该方法。

## 16200005 方法未注册

**错误信息**

The method has not been registered.

**错误描述**

当方法未注册时，方法将返回该错误码。

**可能原因**

方法未在通用组件服务端注册。

**处理步骤**

请检查是否未注册该方法。

<!--Del-->
## 16200006 没有权限设置常驻进程使能状态

**错误信息**

The caller application can only set the resident status of the configured process.

**错误描述**

当调用者没有权限设置常驻进程使能状态时返回。

**可能原因**

调用者没有常驻进程使能配置权限。

**处理步骤**

接口调用时从数据库查询调用者的常驻进程使能配置权限。

## 16300001 指定的任务不存在

**错误信息**

Mission not found.

**错误描述**

当指定的任务不存在时，方法将返回该错误码。

**可能原因**

操作的目标任务不存在。

**处理步骤**

确认操作的任务是否存在。

## 16300002 指定的任务监听器不存在

**错误信息**

The specified mission listener does not exist.

**错误描述**

当指定的任务监听器不存在时，方法将返回该错误码。

**可能原因**

操作的目标任务监听器不存在。

**处理步骤**

确认操作的任务监听器是否存在。
<!--DelEnd-->

## 16300003 目标应用程序不是自身应用程序

**错误信息**

The target application is not the current application.

**错误描述**

当被拉起的应用程序不是自身应用程序时，方法将返回该错误码。

**可能原因**

被拉起的应用和发起调用的应用不是同一个应用程序。

**处理步骤**

确认被拉起的应用程序是否为自身应用程序。

<!--Del-->
## 18500001 指定的包名无效

**错误信息**

The bundle does not exist or no patch has been applied.

**错误描述**

当指定的包名无效时，方法将返回该错误码。

**可能原因**

待查询的bundle不存在或未安装。

**处理步骤**

确认查询的应用是否已安装。

## 18500002 指定的补丁包无效

**错误信息**

Invalid patch package.

**错误描述**

当指定的补丁包无效，补丁包不存在或不可访问时，方法将返回该错误码。

**可能原因**

待安装的补丁包文件不存在或不可以访问。

**处理步骤**

1. 请检查传递的补丁包文件路径是否有效。
2. 请检查是否有权限访问此补丁包文件。

## 18500008 快速修复内部错误

**错误信息**

Internal error.

**错误描述**

当内存申请、多线程处理异常等内部处理错误时，方法将返回该错误码。

**可能原因**

内存申请、多线程处理等内核通用错误。

**处理步骤**

确认系统内存是否足够。

## 18500009 该应用当前有正在处理的快速修复任务

**错误信息**

The application has an ongoing quick fix task.

**错误描述**

该应用当前有正在处理的快速修复任务时，方法将返回该错误码。

**可能原因**

指定要撤销快速修复的应用，有正在处理的快速修复任务。

**处理步骤**

等待快速修复任务处理完成。
<!--DelEnd-->

## 16300004 指定的observer不存在

**错误信息**

The observer does not exist.

**错误描述**

当监听器不存在时，方法将返回该错误码。

**可能原因**

当前监听器不存在或者已注销。

**处理步骤**

请检查是否有重复注销监听器。

<!--Del-->
## 16300005 指定的包信息不存在

**错误信息**

The target bundle does not exist.

**错误描述**

预加载应用的包信息不存在时，方法将返回该错误码。

**可能原因**

预加载的bundleName、userId或appIndex错误，导致查询不到相关包信息。

**处理步骤**

检查传入的bundleName、userId和appIndex参数是否正确。

## 16300008 指定的包不存在主UIAbility

**错误信息**

The target bundle has no MainAbility.

**错误描述**

应用不存在主UIAbility。

**可能原因**

应用的mainElement不是UIAbility。

**处理步骤**

检查应用module.json中的mainElement对应的ability是否是UIAbility。

## 16300009 指定的包不存在状态栏

**错误信息**

The target bundle has no status-bar ability.

**错误描述**

应用不存在状态栏。

**可能原因**

应用不存在状态栏。

**处理步骤**

检查应用是否有状态栏。

## 16300010 指定的应用在运行中但没有绑定状态栏

**错误信息**

The target application is not attached to the status bar.

**错误描述**

应用运行后没有绑定状态栏。

**可能原因**

应用有状态栏，但在运行过程中没有绑定状态栏。

**处理步骤**

检查应用是否绑定状态栏。
<!--DelEnd-->

## 29600001 图片编辑内部错误

**错误信息**

Internal error.

**错误描述**

当图片保存时发生内存申请、多线程处理异常等内部错误时，方法将返回该错误码。

**可能原因**

内存申请、多线程处理等内核通用错误。具体原因可能包括：内部对象为空、处理超时等等。

**处理步骤**

1. 确认系统内存是否足够，设备使用的系统版本是否存在异常。
2. 尝试重启设备。

## 29600002 图片编辑内部错误

**错误信息**

Image input error.

**错误描述**

当图片uri不存在或无法解析图片时，方法将返回该错误码。

**可能原因**

uri不存在或uri非图片类型文件。

**处理步骤**

检查文件是否存在以及文件类型是否为图片。

## 29600003 图片大小过大

**错误信息**

Image too big.

**错误描述**

入参所传入的图片大小过大。

**可能原因**

当入参图片大小超过50M时，方法将返回该错误码。

**处理步骤**

1. 尝试将图片编辑后大小控制在50M以内。
2. 对图片大小进行校验。

<!--Del-->
## 16300007 指定的原子化服务的下载安装任务信息不存在

**错误信息**

The target free-installation task does not exist.

**错误描述**

为原子化服务窗口打开窗口时，指定的原子化服务的下载安装任务不存在时，方法将返回该错误码。

**可能原因**

传入的bundleName、moduleName、abilityName或startTime错误，导致查询不到相关原子化服务的下载安装任务信息。

**处理步骤**

检查传入的bundleName、moduleName、abilityName或startTime参数是否正确。
<!--DelEnd-->

## 28800001 启动任务或其依赖项不存在

**错误信息**

Startup task or its dependency not found.

**错误描述**

执行启动任务时，如果找不到该启动任务或其依赖的任务，方法将返回该错误码。

**可能原因**

未正确配置启动任务或其依赖的任务。

**处理步骤**

检查启动框架配置文件是否正确编写，并确保所有配置的启动任务均已实现。

## 28800002 启动任务之间存在循环依赖关系

**错误信息**

The startup tasks have circular dependencies.

**错误描述**

在加载启动任务时，如果检测到启动任务之间存在循环依赖，方法将返回该错误码。

**可能原因**

配置的启动任务之间存在循环依赖关系。

**处理步骤**

检查启动框架配置文件，确保所有启动任务之间没有循环依赖。

## 28800003 运行启动任务时发生错误

**错误信息**

An error occurred while running the startup tasks.

**错误描述**

运行启动任务时发生错误，方法将返回该错误码。

**可能原因**

启动任务的代码逻辑存在错误，或者缺少异常处理。

**处理步骤**

检查实现的启动任务是否存在逻辑错误，并确保每个启动任务中包含异常处理逻辑。

## 28800004 执行启动任务超时

**错误信息**

Running startup tasks timeout.

**错误描述**

如果启动任务的执行时间超过设置的超时时间（默认为10000毫秒），方法将返回该错误码。

**可能原因**

启动任务中包含大量耗时操作，或者设置的超时时间过短。

**处理步骤**

根据需要调整超时时间。超时时间的设置可参见[设置启动参数](../../application-models/app-startup.md#设置启动参数)。

<!--Del-->
## 16400001 目标应用类型不是系统级HSP

**错误信息**

The input bundleName is not a system HSP.

**错误描述**

通过[createSystemHspModuleResourceManager](js-apis-inner-application-context-sys.md#contextcreatesystemhspmoduleresourcemanager12)接口创建[ResourceManager](../apis-localization-kit/js-apis-resource-manager.md#resourcemanager)时，如果传入的bundleName不属于[系统级HSP](../../quick-start/application-package-glossary.md#系统级hsp)的模块，将返回该错误码。

**可能原因**

调用createSystemHspModuleResourceManager传入的bundleName，不是OEM预置到系统中的HSP的bundleName。

**处理步骤**

检查bundleName是否正确。

## 16000202 仅支持为appService类型的ExtensionAbility设置保活

**错误信息**

Invalid main element type.

**错误描述**

如果设置保活的对象不是appService类型的ExtensionAbility，方法将返回该错误码。

**可能原因**

应用中entry类型的HAP的module.json5配置文件中的mainElement字段不是appService类型的ExtensionAbility。

**处理步骤**

修改应用中entry类型的HAP的module.json5配置文件的mainElement字段为appService类型的ExtensionAbility。

## 16000203 无法更改AppServiceExtensionAbility保活状态

**错误信息**

Cannot change the keep-alive status.

**错误描述**

无法更改AppServiceExtensionAbility保活状态时，方法返回该错误码。

**可能原因**

AppServiceExtensionAbility的保活策略由MDM设置为用户不可取消，或者由其他用户设置为保活。

**处理步骤**

MDM取消设置保活，或设置保活策略为用户可取消；在设置保活的用户下取消AppServiceExtensionAbility的保活。

## 16000204 指定的应用未安装在userId为1的用户下

**错误信息**

The target bundle is not in u1.

**错误描述**

当指定的应用未安装在userId为1的用户下时，方法返回该错误码。

**可能原因**

指定的应用未安装在userId为1的用户下。

**处理步骤**

将指定的应用安装在userId为1的用户下。
<!--DelEnd-->

## 16000115 当前进程未运行isolationProcess字段设为true的组件

**错误信息**

The current process is not running a component configured with "isolationProcess" and cannot be set as a candidate master process.

**错误描述**

当前进程未运行配置了"isolationProcess"的组件，不支持设置为备选主控进程。

**可能原因**

当前进程没有运行配置了isolationProcess字段的组件，不支持声明为主控进程。

**处理步骤**

不支持处理，当前进程未运行isolationProcess字段设为true的组件，无法将其设置为备选主控进程。

## 16000116 当前进程已经是主控进程

**错误信息**

The current process is already a master process and does not support cancellation.

**错误描述**

当前进程已经是主控进程，不支持取消备选主控进程。

**可能原因**

当前进程已经是主控进程，不支持取消备选主控进程。

**处理步骤**

不支持处理，当前进程已经是主控进程的情况下，不支持取消。

## 16000117 当前进程非备选主控进程

**错误信息**

The current process is not a candidate master process and does not support cancellation.

**错误描述**

当前进程不是备选主控进程，不支持取消。

**可能原因**

当前进程不是备选主控进程，不支持取消。

**处理步骤**

不支持处理，当前进程不是备选主控进程，不支持取消。
