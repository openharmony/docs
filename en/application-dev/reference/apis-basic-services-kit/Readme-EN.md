# Basic Services Kit

- ArkTS APIs
  - Account Management
    - [@ohos.account.appAccount (App Account Management)](js-apis-appAccount.md)
    - [@ohos.account.distributedAccount (Distributed Account Management)](js-apis-distributed-account.md)
    - [@ohos.account.osAccount (OS Account Management)](js-apis-osAccount.md)
    <!--Del-->
    - [@ohos.account.distributedAccount (Distributed Account Management) (System API)](js-apis-distributed-account-sys.md)
    - [@ohos.account.osAccount (OS Account Management) (System API)](js-apis-osAccount-sys.md)
    <!--DelEnd-->
  - Device Management
    - [@ohos.batteryInfo (Battery Information)](js-apis-battery-info.md)
    - [@ohos.deviceInfo (Device Information)](js-apis-device-info.md)
    - [@ohos.power (System Power Management)](js-apis-power.md)
    - [@ohos.runningLock (Running Lock)](js-apis-runninglock.md)
    - [@ohos.thermal (Thermal Management)](js-apis-thermal.md)
    - [@ohos.usbManager (USB Manager)](js-apis-usbManager.md)
    <!--Del-->
    - [@ohos.batteryInfo (Battery Information) (System API)](js-apis-battery-info-sys.md)
    - [@ohos.batteryStatistics (Battery Statistics) (System API)](js-apis-batteryStatistics-sys.md)
    - [@ohos.brightness (Screen Brightness) (System API)](js-apis-brightness-sys.md)
    - [@ohos.charger (Charging Type) (System API)](js-apis-charger-sys.md)
    - [@ohos.deviceAttest (Device Attestation) (System API)](js-apis-deviceAttest-sys.md)
    - [@ohos.power (Power Management) (System API)](js-apis-power-sys.md)
    - [@ohos.systemCapability (SystemCapability) (System API)](js-apis-system-capability-sys.md)
    - [@ohos.systemParameterEnhance (System Parameter) (System API)](js-apis-system-parameterEnhance-sys.md)
    - [@ohos.screenLock (Screen Lock) (System API)](js-apis-screen-lock-sys.md)
    - [@ohos.usbManager (USB Management) (System API)](js-apis-usbManager-sys.md)
    - [@ohos.update (Update) (System API)](js-apis-update-sys.md)
    <!--DelEnd-->
  - Data File Processing
    - [@ohos.pasteboard (Pasteboard)](js-apis-pasteboard.md)
    - [@ohos.print (Print)](js-apis-print.md)
    - [@ohos.request (Upload and Download)](js-apis-request.md)
    - [@ohos.zlib (Zip)](js-apis-zlib.md)
    <!--Del-->
    - [@ohos.app.ability.PrintExtensionAbility (Print Extension Ability) (System API)](js-apis-app-ability-PrintExtensionAbility-sys.md)
    - [@ohos.pasetboard (Pasteboard) (System API)](js-apis-pasteboard-sys.md)
    - [@ohos.print (Print) (System API)](js-apis-print-sys.md)
    - [@ohos.request (Upload and Download) (System API)](js-apis-request-sys.md)
    <!--DelEnd-->
  - Process and Thread Communication
    - [System Common Events](common_event/commonEventManager-definitions.md)
    <!--Del-->
    - [System Common Events (System API)](common_event/commonEventManager-definitions-sys.md)
    <!--DelEnd-->
    - [@ohos.commonEventManager (Common Event)](js-apis-commonEventManager.md)
    - [@ohos.events.emitter (Emitter)](js-apis-emitter.md)
    <!--Del-->
    - [@ohos.commonEventManager (Common Event) (System API)](js-apis-commonEventManager-sys.md)
    - [@ohos.application.StaticSubscriberExtensionAbility (StaticSubscriberExtensionAbility) (System API)](js-apis-application-staticSubscriberExtensionAbility-sys.md)
    - [@ohos.application.StaticSubscriberExtensionContext (StaticSubscriberExtensionContext) (System API)](js-apis-application-StaticSubscriberExtensionContext-sys.md)
    <!--DelEnd-->
    - commonEvent
      - [CommonEventData](js-apis-inner-commonEvent-commonEventData.md)
      - [CommonEventPublishData](js-apis-inner-commonEvent-commonEventPublishData.md)
      - [CommonEventSubscriber](js-apis-inner-commonEvent-commonEventSubscriber.md)
      - [CommonEventSubscribeInfo](js-apis-inner-commonEvent-commonEventSubscribeInfo.md)
  - Others
    <!--Del-->
    - [@ohos.ai.intelligentVoice (Intelligent Voice) (System API)](js-apis-intelligentVoice-sys.md)
    <!--DelEnd-->
    - [@ohos.base (Public Callback Information)](js-apis-base.md)
    - [@ohos.customization.customConfig (Custom Configurations)](js-apis-customization-customConfig.md)
    - [@ohos.settings (Data Item Settings)](js-apis-settings.md)
    - [@ohos.wallpaper (Wallpaper)](js-apis-wallpaper.md)
    - [@ohos.resourceschedule.systemload (System Load Level Management)](js-apis-resourceschedule-systemload.md)
    <!--Del-->
    - [@ohos.configPolicy (Configuration Policy) (System API)](js-apis-configPolicy-sys.md)
    - [@ohos.settings (Data Item Settings) (System API)](js-apis-settings-sys.md)
    - [@ohos.systemDateTime (System Time and Time Zone) (System API)](js-apis-system-date-time-sys.md)
    - [@ohos.systemDateTime (System Time and Time Zone)](js-apis-date-time.md)
    - [@ohos.wallpaper (Wallpaper) (System API)](js-apis-wallpaper-sys.md)
    - [@ohos.WallpaperExtensionAbility (WallpaperExtensionAbility) (System API)](js-apis-WallpaperExtensionAbility-sys.md)
    - [@ohos.systemTimer (System Timer) (System API)](js-apis-system-timer-sys.md)
    <!--DelEnd-->
  - APIs No Longer Maintained
    - [System Common Events](common_event/commonEvent-definitions.md)
    - [@ohos.commonEvent (Common Event)](js-apis-commonEvent.md)
    - [@ohos.usb (USB)](js-apis-usb-deprecated.md)
    - [@system.brightness (Screen Brightness)](js-apis-system-brightness.md)
    - [@system.battery (Battery Information)](js-apis-system-battery.md)
    - [@system.device (Device Information)](js-apis-system-device.md)
    - [@system.request (Upload and Download)](js-apis-system-request.md)
    - [@ohos.screenLock (Screen Lock)](js-apis-screen-lock.md)
    <!--Del-->
    - [@ohos.commonEvent (Common Event) (System API)](js-apis-commonEvent-sys.md)
    - [@ohos.usb (USB) (System API)](js-apis-usb-deprecated-sys.md)
    - [@ohos.systemParameter (System Parameter) (System API)](js-apis-system-parameter-sys.md)
    <!--DelEnd-->
    - [@ohos.systemTime (System Time and Time Zone)](js-apis-system-time.md)
- C API
  - Modules
    - [OsAccount](_os_account.md)
    - [OH_Scan](c-apis-scan.md)
    - [TimeService](_time_service.md)
    - [CommonEvent](capi-common-event.md)
  - Header Files
    - [os_account.h](os__account_8h.md)
    - [os_account_common.h](os__account__common_8h.md)
    - [time_service.h](time__service_8h.md)
    - [oh_commonevent.h](oh_commonevent_8h.md)
    - [oh_commonevnt_support.h](oh_commonevent_support_8h.md)
- Error Codes
  - [USB Error Codes](errorcode-usb.md)
  - [Running Lock Error Codes](errorcode-runninglock.md)
  - [zlib Error Codes](errorcode-zlib.md)
  <!--Del-->
  - [Battery Info Error Codes](errorcode-battery-info.md)
  - [Power Consumption Statistics Error Codes](errorcode-batteryStatistics.md)
  <!--DelEnd-->
  - [Pasteboard Error Codes](errorcode-pasteboard.md)
  <!--Del-->
  - [Brightness Error Codes](errorcode-brightness.md)
  <!--DelEnd-->
  - [Thermal Manager Error Codes](errorcode-thermal.md)
  - [Upload and Download Error Codes](errorcode-request.md)
  - [Time and Time Zone Service Error Codes](errorcode-time.md)
  - [Event Error Codes](errorcode-CommonEventService.md)
  - [System Parameter Error Codes](errorcode-system-parameterV9.md)
  - [Power Manager Error Codes](errorcode-power.md)
  - [Account Management Error Codes](errorcode-account.md)
  - [Update Error Codes](errorcode-update.md)
  <!--Del-->
  - [Screen Lock Management Error Codes](errorcode-screenlock.md)
  - [Intelligent Voice Error Codes](errorcode-intelligentVoice.md)
  <!--DelEnd-->
