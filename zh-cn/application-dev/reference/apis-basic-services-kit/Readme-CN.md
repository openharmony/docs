# Basic Services Kit API参考

- ArkTS API
  - 帐号管理
    - [@ohos.account.appAccount (应用帐号管理)](js-apis-appAccount.md)
    - [@ohos.account.distributedAccount (分布式帐号管理)](js-apis-distributed-account.md)
    - [@ohos.account.osAccount (系统帐号管理)](js-apis-osAccount.md)
    <!--Del-->
    - [@ohos.account.distributedAccount (分布式帐号管理)(系统接口)](js-apis-distributed-account-sys.md)
    - [@ohos.account.osAccount (系统帐号管理)(系统接口)](js-apis-osAccount-sys.md)
    <!--DelEnd-->
  - 设备管理
    - [@ohos.batteryInfo (电量信息)](js-apis-battery-info.md)
    - [@ohos.deviceInfo (设备信息)](js-apis-device-info.md)
    - [@ohos.power (系统电源管理)](js-apis-power.md)
    - [@ohos.runningLock (Runninglock锁)](js-apis-runninglock.md)
    - [@ohos.thermal (热管理)](js-apis-thermal.md)
    - [@ohos.screenLock (锁屏管理)](js-apis-screen-lock.md)       
    - [@ohos.usbManager (USB管理)](js-apis-usbManager.md)
    <!--Del-->
    - [@ohos.batteryInfo (电量信息)(系统接口)](js-apis-battery-info-sys.md)
    - [@ohos.batteryStatistics (耗电统计)(系统接口)](js-apis-batteryStatistics-sys.md)
    - [@ohos.brightness (屏幕亮度)(系统接口)](js-apis-brightness-sys.md)
    - [@ohos.charger (充电类型)(系统接口)](js-apis-charger-sys.md)
    - [@ohos.deviceAttest (设备证明)(系统接口)](js-apis-deviceAttest-sys.md)
    - [@ohos.power (系统电源管理)(系统接口)](js-apis-power-sys.md)
    - [@ohos.systemCapability (系统能力)(系统接口)](js-apis-system-capability-sys.md)
    - [@ohos.systemParameterEnhance (系统参数)(系统接口)](js-apis-system-parameterEnhance-sys.md)
    - [@ohos.screenLock (锁屏管理)(系统接口)](js-apis-screen-lock-sys.md)
    - [@ohos.usbManager (USB管理)(系统接口)](js-apis-usbManager-sys.md)
    - [@ohos.update (升级)(系统接口)](js-apis-update-sys.md)
    <!--DelEnd-->
  - 数据文件处理
    - [@ohos.pasteboard (剪贴板)](js-apis-pasteboard.md)
    - [@ohos.print (打印)](js-apis-print.md)
    - [@ohos.request (上传下载)](js-apis-request.md)
    - [@ohos.zlib (Zip模块)](js-apis-zlib.md)
    <!--Del-->
    - [@ohos.app.ability.PrintExtensionAbility (打印扩展能力)(系统接口)](js-apis-app-ability-PrintExtensionAbility-sys.md)
    - [@ohos.print (打印)(系统接口)](js-apis-print-sys.md)
    - [@ohos.request (上传下载)(系统接口)](js-apis-request-sys.md)
    <!--DelEnd-->
  - 进程线程通信
    - [@ohos.commonEventManager (公共事件模块)](js-apis-commonEventManager.md)
    - [@ohos.events.emitter (Emitter)](js-apis-emitter.md)
    <!--Del-->
    - [@ohos.commonEventManager (公共事件模块)(系统接口)](js-apis-commonEventManager-sys.md)
    - [@ohos.application.StaticSubscriberExtensionAbility (StaticSubscriberExtensionAbility)(系统接口)](js-apis-application-staticSubscriberExtensionAbility-sys.md)
    - [@ohos.application.StaticSubscriberExtensionContext (StaticSubscriberExtensionContext)(系统接口)](js-apis-application-StaticSubscriberExtensionContext-sys.md)
    <!--DelEnd-->
    - commonEvent
      - [CommonEventData](js-apis-inner-commonEvent-commonEventData.md)
      - [CommonEventPublishData](js-apis-inner-commonEvent-commonEventPublishData.md)
      - [CommonEventSubscriber](js-apis-inner-commonEvent-commonEventSubscriber.md)
      - [CommonEventSubscribeInfo](js-apis-inner-commonEvent-commonEventSubscribeInfo.md)
    - 公共事件定义
      - [系统公共事件定义](common_event/commonEventManager-definitions.md)
      - [元能力子系统公共事件定义](common_event/commonEvent-ability.md)
      - [包管理子系统公共事件定义](common_event/commonEvent-bundleManager.md)
      - [通知服务公共事件定义](common_event/commonEvent-ans.md)
      - [资源调度子系统公共事件定义](common_event/commonEvent-resourceschedule.md)
      - [窗口管理子系统公共事件定义](common_event/commonEvent-window.md)
      - [网络管理子系统公共事件定义](common_event/commonEvent-netmanager.md)
      - [短信应用公共事件定义](common_event/commonEvent-mms.md)
      - [电话服务子系统公共事件定义](common_event/commonEvent-telephony.md)
      - [电源管理子系统公共事件定义](common_event/commonEvent-powermgr.md)
      - [NFC子系统公共事件定义](common_event/commonEvent-nfc.md)
      - [Wifi子系统公共事件定义](common_event/commonEvent-wifi.md)
      - [USB子系统公共事件定义](common_event/commonEvent-usb.md)
      - [文件管理子系统公共事件定义](common_event/commonEvent-filemanagement.md)
      - [主题框架子系统-锁屏管理公共事件定义](common_event/commonEvent-screenlock.md)
      - [时间时区子系统公共事件定义](common_event/commonEvent-time.md)
      - [帐号子系统公共事件定义](common_event/commonEvent-account.md)
      - [语言子系统公共事件定义](common_event/commonEvent-locale.md)
      - [Account Kit公共事件定义](common_event/commonEvent-accountkit.md)
      <!--Del-->
      - [系统公共事件定义 (系统接口)](common_event/commonEventManager-definitions-sys.md)
      <!--DelEnd-->
  - 其他
    - [@ohos.base (公共回调信息)](js-apis-base.md)
    - [@ohos.settings (设置数据项名称)](js-apis-settings.md)
    - [@ohos.wallpaper (壁纸)](js-apis-wallpaper.md)
    - [@ohos.resourceschedule.systemload (性能功耗热融合档位)](js-apis-resourceschedule-systemload.md)
    <!--Del-->
    - [@ohos.configPolicy (配置策略)(系统接口)](js-apis-configPolicy-sys.md)
    - [@ohos.settings (设置数据项名称)(系统接口)](js-apis-settings-sys.md)
    - [@ohos.systemDateTime (系统时间、时区)(系统接口)](js-apis-system-date-time-sys.md)
    <!--DelEnd-->
    - [@ohos.systemDateTime (系统时间、时区)](js-apis-date-time.md)
    <!--Del-->
    - [@ohos.wallpaper (壁纸)(系统接口)](js-apis-wallpaper-sys.md)
    - [@ohos.WallpaperExtensionAbility (WallpaperExtensionAbility)(系统接口)](js-apis-WallpaperExtensionAbility-sys.md)
    - [@ohos.systemTimer (系统定时器)(系统接口)](js-apis-system-timer-sys.md)
    <!--DelEnd-->
  - 已停止维护的接口
    - [系统公共事件定义](common_event/commonEvent-definitions.md)
    - [@ohos.commonEvent (公共事件模块)](js-apis-commonEvent.md)
    - [@ohos.usb (USB管理)](js-apis-usb-deprecated.md)
    - [@system.brightness (屏幕亮度)](js-apis-system-brightness.md)
    - [@system.battery (电量信息)](js-apis-system-battery.md)
    - [@system.device (设备信息)](js-apis-system-device.md)
    - [@system.request (上传下载)](js-apis-system-request.md)
    <!--Del-->
    - [@ohos.commonEvent (公共事件模块)(系统接口)](js-apis-commonEvent-sys.md)
    - [@ohos.usb (USB管理)(系统接口)](js-apis-usb-deprecated-sys.md)
    - [@ohos.systemParameter (系统属性)(系统接口)](js-apis-system-parameter-sys.md)
    - [@ohos.systemTime (系统时间、时区)(系统接口)](js-apis-system-time-sys.md)
    <!--DelEnd-->
    - [@ohos.systemTime(系统时间、时区)](js-apis-time.md)
- C API
  - 模块
    - [OsAccount](_os_account.md)
  - 头文件
    - [os_account.h](os__account_8h.md)
    - [os_account_common.h](os__account__common_8h.md)
- 错误码
  - [USB服务错误码](errorcode-usb.md)
  - [RunningLock锁错误码](errorcode-runninglock.md)
  - [zlib子系统错误码](errorcode-zlib.md)  
  - [电量信息错误码](errorcode-battery-info.md)
  - [耗电统计错误码](errorcode-batteryStatistics.md)
  - [剪贴板错误码](errorcode-pasteboard.md)
  - [屏幕亮度错误码](errorcode-brightness.md)
  - [热管理错误码](errorcode-thermal.md)
  - [上传下载错误码](errorcode-request.md)
  - [时间时区错误码](errorcode-time.md)
  - [事件错误码](errorcode-CommonEventService.md)
  - [系统参数错误码](errorcode-system-parameterV9.md)
  - [系统电源管理错误码](errorcode-power.md)
  - [帐号管理错误码](errorcode-account.md)
  - [升级错误码](errorcode-update.md)
  - [锁屏服务错误码](errorcode-screenlock.md)
  - [打印服务错误码](errorcode-print.md)
  - [设备证明错误码](errorcode-deviceAttest.md)
