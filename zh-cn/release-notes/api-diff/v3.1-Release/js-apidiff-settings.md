# 应用子系统JS API变更

OpenHarmony 3.1 Release版本相较于OpenHarmony 3.0 LTS版本，应用子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.settings | settings | setValueSync(dataAbilityHelper: DataAbilityHelper, name: string, value: string): boolean; | 新增 |
| ohos.settings | settings | getValueSync(dataAbilityHelper: DataAbilityHelper, name: string, defValue: string): string; | 新增 |
| ohos.settings | settings | getUriSync(name: string): string; | 新增 |
| ohos.settings | settings | canShowFloating(callback: AsyncCallback\<boolean>): void;<br>canShowFloating(): Promise\<boolean>; | 新增 |
| ohos.settings | settings | enableAirplaneMode(enable: boolean, callback: AsyncCallback\<void>): void;<br>enableAirplaneMode(enable: boolean): Promise\<void>; | 新增 |
| ohos.settings | settings | getValue(dataAbilityHelper: DataAbilityHelper, name: string, callback: AsyncCallback\<object>): void;<br>getValue(dataAbilityHelper: DataAbilityHelper, name: string): Promise\<object>; | 新增 |
| ohos.settings | settings | getURI(name: string, callback: AsyncCallback\<object>): void;<br>getURI(name: string): Promise\<object>; | 新增 |
| ohos.settings | wireless | const WIFI_WATCHDOG_STATUS: string | 新增 |
| ohos.settings | wireless | const WIFI_STATUS: string | 新增 |
| ohos.settings | wireless | const WIFI_TO_MOBILE_DATA_AWAKE_TIMEOUT: string | 新增 |
| ohos.settings | wireless | const WIFI_DHCP_MAX_RETRY_COUNT: string | 新增 |
| ohos.settings | wireless | const OWNER_LOCKDOWN_WIFI_CFG: string | 新增 |
| ohos.settings | wireless | const WIFI_RADIO: string | 新增 |
| ohos.settings | wireless | const NFC_RADIO: string | 新增 |
| ohos.settings | wireless | const CELL_RADIO: string | 新增 |
| ohos.settings | wireless | const BLUETOOTH_RADIO: string | 新增 |
| ohos.settings | wireless | const BLUETOOTH_STATUS: string | 新增 |
| ohos.settings | wireless | const AIRPLANE_MODE_RADIOS: string | 新增 |
| ohos.settings | wireless | const BLUETOOTH_DISCOVER_TIMEOUT: string | 新增 |
| ohos.settings | wireless | const BLUETOOTH_DISCOVER_ABILITY_STATUS: string | 新增 |
| ohos.settings | TTS | const ENABLED_TTS_PLUGINS: string | 新增 |
| ohos.settings | TTS | const DEFAULT_TTS_SYNTH: string | 新增 |
| ohos.settings | TTS | const DEFAULT_TTS_RATE: string | 新增 |
| ohos.settings | TTS | const DEFAULT_TTS_PITCH: string | 新增 |
| ohos.settings | sound | const HAPTIC_FEEDBACK_STATUS: string | 新增 |
| ohos.settings | sound | const VIBRATE_STATUS: string | 新增 |
| ohos.settings | sound | const SOUND_EFFECTS_STATUS: string | 新增 |
| ohos.settings | sound | const DEFAULT_RINGTONE: string | 新增 |
| ohos.settings | sound | const DEFAULT_NOTIFICATION_SOUND: string | 新增 |
| ohos.settings | sound | const AFFECTED_MUTE_STREAMS: string | 新增 |
| ohos.settings | sound | const AFFECTED_MODE_RINGER_STREAMS: string | 新增 |
| ohos.settings | sound | const DTMF_TONE_WHILE_DIALING: string | 新增 |
| ohos.settings | sound | const DTMF_TONE_TYPE_WHILE_DIALING: string | 新增 |
| ohos.settings | sound | const DEFAULT_ALARM_ALERT: string | 新增 |
| ohos.settings | sound | const VIBRATE_WHILE_RINGING: string | 新增 |
| ohos.settings | phone | const RTT_CALLING_STATUS: string | 新增 |
| ohos.settings | network | const NETWORK_PREFERENCE_USAGE: string | 新增 |
| ohos.settings | network | const HTTP_PROXY_CFG: string | 新增 |
| ohos.settings | network | const DATA_ROAMING_STATUS: string | 新增 |
| ohos.settings | input | const SHOW_PASSWORD_TEXT_INPUT: string | 新增 |
| ohos.settings | input | const AUTO_REPLACE_TEXT_INPUT: string | 新增 |
| ohos.settings | input | const AUTO_PUNCTUATE_TEXT_INPUT: string | 新增 |
| ohos.settings | input | const AUTO_CAPS_TEXT_INPUT: string | 新增 |
| ohos.settings | input | const SELECTOR_VISIBILITY_FOR_INPUT_METHOD: string | 新增 |
| ohos.settings | input | const ACTIVATED_INPUT_METHODS: string | 新增 |
| ohos.settings | input | const ACTIVATED_INPUT_METHOD_SUB_MODE: string | 新增 |
| ohos.settings | input | const DEFAULT_INPUT_METHOD: string | 新增 |
| ohos.settings | general | const TOUCH_EXPLORATION_STATUS: string | 新增 |
| ohos.settings | general | const SKIP_USE_HINTS: string | 新增 |
| ohos.settings | general | const GEOLOCATION_ORIGINS_ALLOWED: string | 新增 |
| ohos.settings | general | const ACTIVATED_ACCESSIBILITY_SERVICES: string | 新增 |
| ohos.settings | general | const ACCESSIBILITY_STATUS: string | 新增 |
| ohos.settings | general | const DEBUG_APP_PACKAGE: string | 新增 |
| ohos.settings | general | const DEBUGGER_WAITING: string | 新增 |
| ohos.settings | general | const USB_STORAGE_STATUS: string | 新增 |
| ohos.settings | general | const DEVICE_NAME: string | 新增 |
| ohos.settings | general | const CONTACT_METADATA_SYNC_STATUS: string | 新增 |
| ohos.settings | general | const BOOT_COUNTING: string | 新增 |
| ohos.settings | general | const HDC_STATUS: string | 新增 |
| ohos.settings | general | const DEVICE_PROVISION_STATUS: string | 新增 |
| ohos.settings | general | const ACCELEROMETER_ROTATION_STATUS: string | 新增 |
| ohos.settings | general | const END_BUTTON_ACTION: string | 新增 |
| ohos.settings | general | const SETUP_WIZARD_FINISHED: string | 新增 |
| ohos.settings | display | const DISPLAY_INVERSION_STATUS: string | 新增 |
| ohos.settings | display | const WINDOW_ANIMATION_SCALE: string | 新增 |
| ohos.settings | display | const TRANSITION_ANIMATION_SCALE: string | 新增 |
| ohos.settings | display | const ANIMATOR_DURATION_SCALE: string | 新增 |
| ohos.settings | display | const DEFAULT_SCREEN_ROTATION: string | 新增 |
| ohos.settings | display | const SCREEN_OFF_TIMEOUT: string | 新增 |
| ohos.settings | display | const MANUAL_SCREEN_BRIGHTNESS_MODE: number | 新增 |
| ohos.settings | display | const AUTO_SCREEN_BRIGHTNESS_MODE: number | 新增 |
| ohos.settings | display | const AUTO_SCREEN_BRIGHTNESS: string | 新增 |
| ohos.settings | display | const SCREEN_BRIGHTNESS_STATUS: string | 新增 |
| ohos.settings | display | const FONT_SCALE: string | 新增 |
| ohos.settings | date | const AUTO_GAIN_TIME_ZONE: string | 新增 |
| ohos.settings | date | const AUTO_GAIN_TIME: string | 新增 |
| ohos.settings | date | const TIME_FORMAT: string | 新增 |
| ohos.settings | date | const DATE_FORMAT: string | 新增 |
