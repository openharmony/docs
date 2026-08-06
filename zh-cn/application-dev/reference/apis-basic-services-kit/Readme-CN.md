# Basic Services Kit（基础服务）
<!--Kit: Common-->
<!--Subsystem: Common-->
<!--Owner: @fang-jinxu-->
<!--Designer: @lingminghw-->
<!--Tester: @RayShih-->
<!--Adviser: @fang-jinxu-->

- ArkTS API<!--basic-services-arkts-->
  - 账号管理<!--account-management-arkts-->
    - [@ohos.account.appAccount (应用账号管理)](js-apis-appAccount.md)
    - [@ohos.account.distributedAccount (分布式账号管理)](js-apis-distributed-account.md)
    - [@ohos.account.osAccount (系统账号管理)](js-apis-osAccount.md)
    <!--Del-->
    - [@ohos.account.distributedAccount (分布式账号管理)(系统接口)](js-apis-distributed-account-sys.md)
    - [@ohos.account.osAccount (系统账号管理)(系统接口)](js-apis-osAccount-sys.md)
    <!--DelEnd-->
  - 设备管理<!--device-management-arkts-->
    - [@ohos.batteryInfo (电量信息)](js-apis-battery-info.md)
    - [@ohos.busManager.serial (串口通信管理)](js-apis-busmanager-serial.md)
    - [@ohos.deviceInfo (设备信息)](js-apis-device-info.md)
    - [@ohos.power (系统电源管理)](js-apis-power.md)
    - [@ohos.runningLock (Runninglock锁)](js-apis-runninglock.md)
    - [@ohos.thermal (热管理)](js-apis-thermal.md)
    - [@ohos.usbManager (USB管理)](js-apis-usbManager.md)
    - [@ohos.usbManager.serial (串口管理)](js-apis-serialManager.md)
    <!--Del-->
    - [@ohos.batteryInfo (电量信息)(系统接口)](js-apis-battery-info-sys.md)
    - [@ohos.batteryStatistics (耗电统计)(系统接口)](js-apis-batteryStatistics-sys.md)
    - [@ohos.brightness (屏幕亮度)(系统接口)](js-apis-brightness-sys.md)
    - [@ohos.busManager.serial (串口通信管理)(系统接口)](js-apis-busmanager-serial-sys.md)
    - [@ohos.charger (充电类型)(系统接口)](js-apis-charger-sys.md)
    - [@ohos.deviceAttest (设备证明)(系统接口)](js-apis-deviceAttest-sys.md)
    - [@ohos.power (系统电源管理)(系统接口)](js-apis-power-sys.md)
    - [@ohos.systemCapability (系统能力)(系统接口)](js-apis-system-capability-sys.md)
    - [@ohos.systemParameterEnhance (系统参数)(系统接口)](js-apis-system-parameterEnhance-sys.md)
    - [@ohos.screenLock (锁屏管理)(系统接口)](js-apis-screen-lock-sys.md)
    - [@ohos.usbManager (USB管理)(系统接口)](js-apis-usbManager-sys.md)
    - [@ohos.usbManager.serial (串口管理)(系统接口)](js-apis-serialManager-sys.md)
    - [@ohos.update (升级)(系统接口)](js-apis-update-sys.md)
    <!--DelEnd-->
  - 数据文件处理<!--data-file-processing-arkts-->
    - [@ohos.app.ability.PrintExtensionAbility (打印扩展能力)](js-apis-app-ability-PrintExtensionAbility.md)
    - [PrintExtensionContext](js-apis-PrintExtensionContext.md)
    - [@ohos.pasteboard (剪贴板)](js-apis-pasteboard.md)
    - [@ohos.print (打印)](js-apis-print.md)
    - [@ohos.scan (扫描)](js-apis-scan.md)
    - [@ohos.request (上传下载)](js-apis-request.md)
    - [@ohos.request.cacheDownload (缓存下载)](js-apis-request-cacheDownload.md)
    - [@ohos.zlib (Zip模块)](js-apis-zlib.md)
    - [@ohos.selectionInput.SelectionExtensionAbility (划词扩展能力)](js-apis-selectionInput-selectionExtensionAbility.md)
    - [@ohos.selectionInput.SelectionExtensionContext (划词扩展上下文)](js-apis-selectionInput-selectionExtensionContext.md)
    - [@ohos.selectionInput.selectionManager (划词管理)](js-apis-selectionInput-selectionManager.md)
    - [@ohos.selectionInput.SelectionPanel (划词面板)](js-apis-selectionInput-selectionPanel.md)
    <!--Del-->
    - [@ohos.app.ability.PrintExtensionAbility (打印扩展能力)(系统接口)](js-apis-app-ability-PrintExtensionAbility-sys.md)
    - [@ohos.print (打印)(系统接口)](js-apis-print-sys.md)
    - [@ohos.scan (扫描)(系统接口)](js-apis-scan-sys.md)
    - [@ohos.request (上传下载)(系统接口)](js-apis-request-sys.md)
    <!--DelEnd-->
  - 进程线程通信<!--process-thread-communi-arkts-->
    - [系统定义的公共事件](common_event/commonEventManager-definitions.md)
    <!--Del-->
    - [系统定义的公共事件（系统接口）](common_event/commonEventManager-definitions-sys.md)
    <!--DelEnd-->
    - [@ohos.commonEventManager (公共事件模块)](js-apis-commonEventManager.md)
    - [@ohos.events.emitter (Emitter)](js-apis-emitter.md)
    <!--Del-->
    - [@ohos.commonEventManager (公共事件模块)(系统应用)](js-apis-commonEventManager-sys.md)
    - [@ohos.application.StaticSubscriberExtensionAbility (StaticSubscriberExtensionAbility)(系统接口)](js-apis-application-staticSubscriberExtensionAbility-sys.md)
    - [@ohos.application.StaticSubscriberExtensionContext (StaticSubscriberExtensionContext)(系统接口)](js-apis-application-StaticSubscriberExtensionContext-sys.md)
    <!--DelEnd-->
    - commonEvent<!--commonevent-->
      - [CommonEventData](js-apis-inner-commonEvent-commonEventData.md)
      - [CommonEventPublishData](js-apis-inner-commonEvent-commonEventPublishData.md)
      - [CommonEventSubscriber](js-apis-inner-commonEvent-commonEventSubscriber.md)
      - [CommonEventSubscribeInfo](js-apis-inner-commonEvent-commonEventSubscribeInfo.md)
  - 其他<!--basic-services-others-->
    <!--Del-->
    - [@ohos.ai.intelligentVoice (智能语音)(系统接口)](js-apis-intelligentVoice-sys.md)
    <!--DelEnd-->
    - [@ohos.base (公共回调信息)](js-apis-base.md)
    - [@ohos.annotation (注解)](js-apis-annotation.md)
    - [@ohos.customization.customConfig (定制配置)](js-apis-customization-customConfig.md)
    - [@ohos.settings (设置数据项名称)](js-apis-settings.md)
    - [@ohos.settingsLite (设置信息)](js-apis-settings-lite.md)
    - [@ohos.wallpaper (壁纸)](js-apis-wallpaper.md)
    - [@ohos.resourceschedule.systemload (性能功耗热融合档位)](js-apis-resourceschedule-systemload.md)
    - [@ohos.systemDateTime (系统时间、时区)](js-apis-date-time.md)
    - [@ohos.intelligentScene (情景模式)](js-apis-intelligentScene.md)
    <!--Del-->
    - [@ohos.configPolicy (配置策略)(系统接口)](js-apis-configPolicy-sys.md)
    - [@ohos.settings (设置数据项名称)(系统接口)](js-apis-settings-sys.md)
    - [@ohos.systemDateTime (系统时间、时区)(系统接口)](js-apis-system-date-time-sys.md)<!--DelEnd-->
     <!--Del-->
    - [@ohos.wallpaper (壁纸)(系统接口)](js-apis-wallpaper-sys.md)
    - [@ohos.WallpaperExtensionAbility (WallpaperExtensionAbility)(系统接口)](js-apis-WallpaperExtensionAbility-sys.md)
    - [@ohos.systemTimer (系统定时器)(系统接口)](js-apis-system-timer-sys.md)
    <!--DelEnd-->
  - 已停止维护的接口<!--basic-services-arkts-dep-->
    - [系统公共事件定义](common_event/commonEvent-definitions.md)
    - [@ohos.commonEvent (公共事件模块)](js-apis-commonEvent.md)
    - [@ohos.usb (USB管理)](js-apis-usb-deprecated.md)
    - [@system.brightness (屏幕亮度)](js-apis-system-brightness.md)
    - [@system.battery (电量信息)](js-apis-system-battery.md)
    - [@system.device (设备信息)](js-apis-system-device.md)
    - [@system.request (上传下载)](js-apis-system-request.md)
    - [@ohos.screenLock (锁屏管理)](js-apis-screen-lock.md)
    <!--Del-->
    - [@ohos.commonEvent (公共事件模块)(系统应用)(已废弃)](js-apis-commonEvent-sys.md)
    - [@ohos.usb (USB管理)(系统接口)](js-apis-usb-deprecated-sys.md)
    - [@ohos.systemParameter (系统属性)(系统接口)](js-apis-system-parameter-sys.md)
    <!--DelEnd-->
    - [@ohos.systemTime (系统时间、时区)](js-apis-system-time.md)
- C API<!--basic-services-c-->
  - 模块<!--basic-services-module-->
    - [OH_CommonEvent](capi-oh-commonevent.md)
    - [DeviceInfo](capi-deviceinfo.md)
    - [OsAccount](capi-osaccount.md)
    - [OH_BatteryInfo](capi-oh-batteryinfo.md)
    - [OH_Scan](capi-oh-scan.md)
    - [OH_Print](capi-oh-print.md)
    - [Pasteboard](capi-pasteboard.md)
    - [TimeService](capi-timeservice.md)
  - 头文件<!--basic-services-headerfile-->
    - [deviceinfo.h](capi-deviceinfo-h.md)
    - [ohbattery_info.h](capi-ohbattery-info-h.md)
    - [oh_commonevent.h](capi-oh-commonevent-h.md)
    - [oh_commonevent_support.h](capi-oh-commonevent-support-h.md)
    - [oh_pasteboard.h](capi-oh-pasteboard-h.md)
    - [oh_pasteboard_err_code.h](capi-oh-pasteboard-err-code-h.md)
    - [os_account.h](capi-os-account-h.md)
    - [os_account_common.h](capi-os-account-common-h.md)
    - [ohprint.h](capi-ohprint-h.md)
    - [ohscan.h](capi-ohscan-h.md)
    - [time_service.h](capi-time-service-h.md)
  - 结构体<!--basic-services-struct-->
    - [CommonEvent_SubscribeInfo](capi-oh-commonevent-commonevent-subscribeinfo.md)
    - [CommonEvent_PublishInfo](capi-oh-commonevent-commonevent-publishinfo.md)
    - [CommonEvent_RcvData](capi-oh-commonevent-commonevent-rcvdata.md)
    - [Pasteboard_ProgressInfo](capi-pasteboard-progressinfo.md)
    - [Pasteboard_GetDataParams](capi-pasteboard-getdataparams.md)
    - [OH_PasteboardObserver](capi-pasteboard-oh-pasteboardobserver.md)
    - [OH_Pasteboard](capi-pasteboard-oh-pasteboard.md)
    - [Print_Margin](capi-oh-print-print-margin.md)
    - [Print_PageSize](capi-oh-print-print-pagesize.md)
    - [Print_Range](capi-oh-print-print-range.md)
    - [Print_DefaultValue](capi-oh-print-print-defaultvalue.md)
    - [Print_PrinterCapability](capi-oh-print-print-printercapability.md)
    - [Print_PrinterInfo](capi-oh-print-print-printerinfo.md)
    - [Print_PrintJob](capi-oh-print-print-printjob.md)
    - [Print_Property](capi-oh-print-print-property.md)
    - [Print_PropertyList](capi-oh-print-print-propertylist.md)
    - [Print_Resolution](capi-oh-print-print-resolution.md)
    - [Print_StringList](capi-oh-print-print-stringlist.md)
    - [Print_PrintAttributes](capi-oh-print-print-printattributes.md)
    - [Print_PrintDocCallback](capi-oh-print-print-printdoccallback.md)
    - [Scan_ScannerDevice](capi-oh-scan-scan-scannerdevice.md)
    - [Scan_PictureScanProgress](capi-oh-scan-scan-picturescanprogress.md)
    - [Scan_ScannerOptions](capi-oh-scan-scan-scanneroptions.md)
- 错误码<!--basic-services-arkts-errcode-->
  - [USB服务错误码](errorcode-usb.md)
  - [串口管理错误码](errorcode-busmanager-serial.md)
  - [RunningLock锁错误码](errorcode-runninglock.md)
  - [zlib子系统错误码](errorcode-zlib.md)
  <!--Del-->
  - [电量信息错误码](errorcode-battery-info.md)
  - [耗电统计错误码](errorcode-batteryStatistics.md)
  <!--DelEnd-->
  - [剪贴板错误码](errorcode-pasteboard.md)
  <!--Del-->
  - [屏幕亮度错误码](errorcode-brightness.md)
  <!--DelEnd-->
  - [热管理错误码](errorcode-thermal.md)
  - [上传下载错误码](errorcode-request.md)
  - [时间时区服务错误码](errorcode-time.md)
  - [公共事件错误码](errorcode-CommonEventService.md)
  <!--Del-->
  - [系统参数错误码](errorcode-system-parameterV9.md)
  <!--DelEnd-->
  - [系统电源管理错误码](errorcode-power.md)
  - [账号管理错误码](errorcode-account.md)
  <!--Del-->
  - [升级错误码](errorcode-update.md)
  <!--DelEnd-->
  - [打印服务错误码](errorcode-print.md)
  - [设置数据项错误码](errorcode-settings.md)
  - [划词服务错误码](errorcode-selection.md)
  - [情景模式错误码](errorcode-intelligentScene.md)
  <!--Del-->
  - [锁屏服务错误码](errorcode-screenlock.md)
  - [设备证明错误码](errorcode-deviceAttest.md)
  - [智能语音错误码](errorcode-intelligentVoice.md)
  <!--DelEnd-->
  - [deviceInfo错误码](errorcode-device-info.md)