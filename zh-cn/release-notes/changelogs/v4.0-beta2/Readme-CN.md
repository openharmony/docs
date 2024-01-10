# 总览


| 子系统 | 变更类型 | 变更描述 | 
| -------- | -------- | -------- |
| ArkUI | 状态变量变更 | [状态变量数据类型声明使用限制，所有的状态装饰器变量需要显式声明变量类型，不允许声明any。](changelogs-arkui.md#clarkui1-状态变量数据类型声明使用限制) | 
| ArkUI | 规则变更 | [自定义组件成员变量初始化的规则与约束，不允许从父组件初始化@LocalStorageLink，@LocalStorageProp修饰的变量。](changelogs-arkui.md#clarkui2-自定义组件成员变量初始化的规则与约束) | 
| ArkUI | 参数变更 | [通用事件参数支持undefined。](changelogs-arkui.md#clarkui3-通用事件参数支持undefined) | 
| ArkUI | 状态变量变更 | [1.Prop/BuilderParam状态变量需要初始化或从父组件传值。](changelogs-arkui.md#clarkui4-propbuilderparam-状态变量需要初始化或从父组件传值)<br/>[2.BuilderParam状态变量初始化赋值必须为@Builder函数/方法。](changelogs-arkui.md#clarkui5-builderparam-状态变量初始化赋值必须为builder函数方法) | 
| ArkUI | 接口/组件变更 | [Search组件的searchButton属性中SearchButtonOption修改为SearchButtonOptions。](changelogs-arkui.md#clarkui6-search组件的searchbutton属性中searchbuttonoption修改为searchbuttonoptions) | 
| ArkUI | 枚举值变更 | [滚动事件ScrollState上报滚动状态枚举值规则变更。](changelogs-arkui.md#clarkui7-滚动事件上报滚动状态枚举值规则变更) | 
| ArkUI | 组件变更 | [对ArkUI系统组件的使用场景进行限制，仅允许在struct的build方法内、pageTransition方法内或@Builder修饰的函数内使用。](changelogs-arkui.md#clarkui8-arkui系统组件使用限制) | 
| ArkUI | 行为变更 | [ArkUI子系统@Prop装饰器支持Object行为变化，Prop支持Object&nbsp;api9浅拷贝，api10变更为深拷贝。](changelogs-arkui.md#clarkui9-prop在api-9支持object浅拷贝api-10变更为深拷贝) | 
| ArkUI | 参数变更 | [1.编译拦截@Extend/@AnimatableExtend参数个数不符合预期。](changelogs-arkui.md#clarkui10-编译拦截extendanimatableextend参数个数不符合预期)<br/>[2.编译拦截@Link/@ObjectLink成员变量未从父组件传值。](changelogs-arkui.md#clarkui11-编译拦截linkobjectlink成员变量未从父组件传值) | 
| ArkUI | 行为变更 | [canvas组件onReady事件行为变更，onReady事件在组件创建完成后或组件大小发生变化时触发，并清空画布。](changelogs-arkui.md#clarkui12-canvas组件onready事件行为变更) | 
| ArkUI | 属性变更 | [Navigation menus属性显示变更。](changelogs-arkui.md#clarkui13-navigation-menus属性显示变更) |
| ArkUI | 属性变更 | [Navigation的titleMode属性Free模式默认显示位置变更。](changelogs-arkui.md#clarkui14-navigation的titlemode属性free模式默认显示位置变更) |
| 包管理 | 接口底层实现变更 | [1.ohos.bundle.d.ts中getAllBundleInfo接口底层实现变更。](changelogs-bundlemanager.md#clbundlemanager1-包管理ohosbundledts中getallbundleinfo接口底层实现变更)<br/>[2.ohos.bundle.d.ts中getAllApplicationInfo接口底层实现变更。](changelogs-bundlemanager.md#clbundlemanager2-包管理ohosbundledts中getallapplicationinfo接口底层实现变更) | 
| 包管理 | 接口权限变更 | [1.ohos.bundle.bundleManager.d.ts中getAllBundleInfo接口权限变更。](changelogs-bundlemanager.md#clbundlemanager3-包管理ohosbundlebundlemanagerdts中getallbundleinfo接口权限变更)<br/>[2.ohos.bundle.bundleManager.d.ts中getAllApplicationInfo接口权限变更。](changelogs-bundlemanager.md#clbundlemanager4-包管理ohosbundlebundlemanagerdts中getallapplicationinfo接口权限变更) | 
| 包管理 | 接口/组件变更 | [1.ohos.bundle.installer.d.ts中getSpecifiedDistributionType接口移动到@ohos.bundle.bundleManager.d.ts中。](changelogs-bundlemanager.md#clbundlemanager5-包管理ohosbundleinstallerdts中getspecifieddistributiontype接口移动到ohosbundlebundlemanagerdts中)<br/>[2.ohos.bundle.installer.d.ts中getAdditionalInfo接口移动到@ohos.bundle.bundleManager.d.ts中。](changelogs-bundlemanager.md#clbundlemanager6-包管理ohosbundleinstallerdts中getadditionalinfo接口移动到ohosbundlebundlemanagerdts中) | 
| 包管理 | 接口/组件变更 | [包管理Schema中proxyDatas更名为proxyData。](changelogs-bundlemanager.md#clbundlemanager7-应用配置文件modulejson5中proxydatas更名为proxydata) | 
| 包管理 | 配置文件变更 | [module.json配置文件schema变更。](https://gitee.com/openharmony/docs/blob/master/zh-cn/release-notes/changelogs/OpenHarmony_4.0.9.3/changelogs-bundlemanager.md) | 
| OS媒体 | 枚举声明变更 | [音频输出流类型由AUDIOSTREAM_TYPE_RERNDERER更名为AUDIOSTREAM_TYPE_RENDERER](changelogs-multimedia.md#clmultimedia1-音频c接口流类型枚举声明变更) | 
| OS媒体 | 枚举值变更 | [1.&nbsp;OH_AudioStream_Usage变更，删除了AUDIOSTREAM_USAGE_MEDIA枚举值，将AUDIOSTREAM_USAGE_COMMUNICATION枚举值变更为AUDIOSTREAM_USAGE_VOICE_COMMUNICATION和AUDIOSTREAM_USAGE_VOICE_ASSISTANT。](changelogs-multimedia.md#clmultimedia2-oh_audiostream_usage变更)<br/>[2.&nbsp;OH_AudioStream_SampleFormat变更，OH_AudioStream_SampleFormat枚举中删除了AUDIOSTREAM_SAMPLE_F32LE枚举值。](changelogs-multimedia.md#clmultimedia3-oh_audiostream_sampleformat变更删除audiostream_sample_f32le) | 
| OS媒体 | 接口入参变更 | [getAudioEffectInfoArray接口入参变更，删除Content&nbsp;type入参。](changelogs-multimedia.md#clmultimedia4-getaudioeffectinfoarray接口入参变更删除content-type入参) | 
| 程序访问控制 | 权限调整 | [“电话”、“信息”、“通话记录”权限组的权限仅对系统应用开放。](changelogs-accessToken.md#claccesstoken2-电话信息通话记录权限组的权限申请方式调整) | 
| 程序访问控制 | 权限组拆分 | [原“媒体和文件”权限组内权限组进行调整，MEDIA_LOCATION&nbsp;划分为图片和视频权限组，READ_MEDIA&nbsp;和WRITE_MEDIA&nbsp;划分为文件权限组。](changelogs-accessToken.md#claccesstoken1-媒体和文件权限组拆分) | 
| 输入法框架 | 返回错误码变更 | [1.ohos.InputMethod中on('imeShow')系统接口权限校验失败返回错误码变更。](changelogs-imf.md#climf1-ohosinputmethod中onimeshow系统接口权限校验失败返回错误码变更)<br/>[2.ohos.InputMethod中on('imeHide')系统接口权限校验失败返回错误码变更。](changelogs-imf.md#climf2-ohosinputmethod中onimehide系统接口权限校验失败返回错误码变更) | 
| 主题框架 | 接口实例名称变更 | [锁屏管理的包名为'@ohos.screenLock'，在导入时，使用的代码实例由screenlock变更为screenLock。](changelogs-screenlock.md#clscreenlock1-代码实例名称变更) | 
| 分布式数据管理 | 接口/组件变更 | [ValuesBucket由系统接口变更为公共接口。](changelogs-distributeddatamgr.md#cldistributeddatamgr1-valuesbucket由系统接口变更为公共接口) | 
| 分布式数据管理 | 接口/组件变更 | [dataSharePredicates部分谓词由系统接口变更为公共接口。](changelogs-distributeddatamgr.md#cldistributeddatamgr2-datasharepredicates部分谓词由系统接口变更为公共接口) | 
| 分布式数据管理 | 接口/组件变更 | [@ohos.application.DataShareExtensionAbility的context属性取消可选标识，同时起始版本从API&nbsp;version&nbsp;9变更为API&nbsp;version&nbsp;10。](changelogs-distributeddatamgr.md#cldistributeddatamgr3-datashareextensionability的context属性取消可选标识符) | 
| 分布式数据管理 | 接口/组件变更 | [OH_Predicates结构体的函数指针成员变量返回值类型由OH_Predicates&nbsp;变更为OH_Predicates。](changelogs-distributeddatamgr.md#cldistributeddatamgr4-oh_predicates结构体的函数指针成员变量返回值类型由oh_predicates变更为oh_predicates-) | 
| 分布式数据管理 | 接口/组件变更 | [OH_Rdb_ErrCode结构体的错误码信息变更。](changelogs-distributeddatamgr.md#cldistributeddatamgr5-oh_rdb_errcode结构体的错误码信息变更) | 
| 分布式数据管理 | 变量变更（Native） | [1.OH_Cursor结构体的函数指针成员变量int&nbsp;(*close)(OH_Cursor&nbsp;*cursor)变更为int&nbsp;(*destroy)(OH_Cursor&nbsp;*cursor)。](changelogs-distributeddatamgr.md#cldistributeddatamgr6-oh_cursor结构体的函数指针成员变量int-closeoh_cursor-cursor变更为int-destroyoh_cursor-cursor)<br/>[2.OH_Predicates结构体的函数指针成员变量int&nbsp;(*destroyPredicates)(OH_Predicates&nbsp;*predicates)变更为&nbsp;int&nbsp;(*destroy)(OH_Predicates&nbsp;*predicates)。](changelogs-distributeddatamgr.md#cldistributeddatamgr7-oh_predicates结构体的函数指针成员变量int-destroypredicatesoh_predicates-predicates变更为-int-destroyoh_predicates-predicates)<br/>[3.OH_VObject结构体的函数指针成员变量int&nbsp;(*destroyValueObject)(OH_VObject&nbsp;*valueObject)变更为&nbsp;int&nbsp;(*destroy)(OH_VObject&nbsp;*valueObject)。](changelogs-distributeddatamgr.md#cldistributeddatamgr8-oh_vobject结构体的函数指针成员变量int-destroyvalueobjectoh_vobject-valueobject变更为-int-destroyoh_vobject-valueobject)<br/>[4.OH_VBucket结构体的函数指针成员变量int&nbsp;(*destroyValuesBucket)(OH_VBucket&nbsp;*bucket)变更为&nbsp;int&nbsp;(*destroy)(OH_VBucket&nbsp;*bucket)](changelogs-distributeddatamgr.md#cldistributeddatamgr9-oh_vbucket结构体的函数指针成员变量int-destroyvaluesbucketoh_vbucket-bucket变更为-int-destroyoh_vbucket-bucket) | 
| 分布式数据管理 | 变量变更（Native） | [OH_Rdb_Config结构体成员变量变更，将成员变量securityLevel的类型由enum&nbsp;OH_Rdb_SecurityLevel改为in；删除成员变量path；并新增成员变量selfSize、dataBaseDir、storeName、bundleName、moduleName。](changelogs-distributeddatamgr.md#cldistributeddatamgr10-oh_rdb_config结构体成员变量变更) | 
| 分布式数据管理 | 接口入参变更（Native） | [OH_Rdb_DeleteStore接口入参const&nbsp;char&nbsp;*pat变更为const&nbsp;OH_Rdb_Config&nbsp;*config](changelogs-distributeddatamgr.md#cldistributeddatamgr11-oh_rdb_deletestore接口入参constchar-pat变更为const-oh_rdb_config-config) | 
| 分布式硬件 | 接口权限变更 | [接口权限变更，在Opeharmonny&nbsp;4.0.8.2之后版本开发的应用，需要持有相应权限，否则无法正常调用接口。](changelogs-device_manager.md) | 
| 媒体 | 接口入参变更 | [getAudioEffectInfoArray接口入参变更，删除Content&nbsp;type入参。](changelogs-multimedia.md#clmultimedia4-getaudioeffectinfoarray接口入参变更删除content-type入参) | 
| 媒体 | 接口变更 | [删除音轨切换相关接口。](changelogs-multimedia.md#clmultimedia5-播放功能接口变更) | 
| 元能力-卡片框架 | 接口权限变更 | [ohos.app.form.formHost.d.ts部分接口移出，接口权限变动。](changelogs-formfwk.md#clformfwk1-ohosappformformhostdts部分接口移出接口权限变动) | 
| 元能力-卡片框架 | 接口参数变更 | [事件订阅，取消订阅相关接口（on/off）中的callback调整为接口最后一个参数。](changelogs-formfwk.md#clformfwk2-事件订阅取消订阅相关接口onoff参数顺序调整) | 
| 泛Sensor | 接口/组件变更 | [新增自定义振动效果属性VibrateFromFile，自定义振动配置文件描述符属性HapticFileDescriptor；振动下发接口startVibration支持的振动效果由VibrateEffect&nbsp;=&nbsp;VibrateTime。](changelogs-miscdevice.md) | 
| 文件管理（媒体库） | 接口/组件变更 | [mediaLibrary部分接口兼容性发生变更。](changelogs-medialibrary.md#clfile1-medialibrary部分接口兼容性变更) | 
| 基础通信 | 接口/组件变更 | [wifiManager部分接口名称发生变更。](changelogs-wifiManager.md#clfile1-wifiManager部分接口名称发生变更) | 


> **说明：**
> 以上变更如未明确说明变更类型为Native接口，则均为ArkTS接口的变更。
<!--no_check-->