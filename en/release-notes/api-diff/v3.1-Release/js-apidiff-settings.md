# JS API Changes of the Application Framework Subsystem

The table below lists the APIs changes of the application framework subsystem in OpenHarmony 3.1 Release over OpenHarmony 3.0 LTS.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.settings | settings | setValueSync(dataAbilityHelper: DataAbilityHelper, name: string, value: string): boolean; | Added|
| ohos.settings | settings | getValueSync(dataAbilityHelper: DataAbilityHelper, name: string, defValue: string): string; | Added|
| ohos.settings | settings | getUriSync(name: string): string; | Added|
| ohos.settings | settings | canShowFloating(callback: AsyncCallback\<boolean>): void;<br>canShowFloating(): Promise\<boolean>; | Added|
| ohos.settings | settings | enableAirplaneMode(enable: boolean, callback: AsyncCallback\<void>): void;<br>enableAirplaneMode(enable: boolean): Promise\<void>; | Added|
| ohos.settings | settings | getValue(dataAbilityHelper: DataAbilityHelper, name: string, callback: AsyncCallback\<object>): void;<br>getValue(dataAbilityHelper: DataAbilityHelper, name: string): Promise\<object>; | Added|
| ohos.settings | settings | getURI(name: string, callback: AsyncCallback\<object>): void;<br>getURI(name: string): Promise\<object>; | Added|
| ohos.settings | wireless | const WIFI_WATCHDOG_STATUS: string | Added|
| ohos.settings | wireless | const WIFI_STATUS: string | Added|
| ohos.settings | wireless | const WIFI_TO_MOBILE_DATA_AWAKE_TIMEOUT: string | Added|
| ohos.settings | wireless | const WIFI_DHCP_MAX_RETRY_COUNT: string | Added|
| ohos.settings | wireless | const OWNER_LOCKDOWN_WIFI_CFG: string | Added|
| ohos.settings | wireless | const WIFI_RADIO: string | Added|
| ohos.settings | wireless | const NFC_RADIO: string | Added|
| ohos.settings | wireless | const CELL_RADIO: string | Added|
| ohos.settings | wireless | const BLUETOOTH_RADIO: string | Added|
| ohos.settings | wireless | const BLUETOOTH_STATUS: string | Added|
| ohos.settings | wireless | const AIRPLANE_MODE_RADIOS: string | Added|
| ohos.settings | wireless | const BLUETOOTH_DISCOVER_TIMEOUT: string | Added|
| ohos.settings | wireless | const BLUETOOTH_DISCOVER_ABILITY_STATUS: string | Added|
| ohos.settings | TTS | const ENABLED_TTS_PLUGINS: string | Added|
| ohos.settings | TTS | const DEFAULT_TTS_SYNTH: string | Added|
| ohos.settings | TTS | const DEFAULT_TTS_RATE: string | Added|
| ohos.settings | TTS | const DEFAULT_TTS_PITCH: string | Added|
| ohos.settings | sound | const HAPTIC_FEEDBACK_STATUS: string | Added|
| ohos.settings | sound | const VIBRATE_STATUS: string | Added|
| ohos.settings | sound | const SOUND_EFFECTS_STATUS: string | Added|
| ohos.settings | sound | const DEFAULT_RINGTONE: string | Added|
| ohos.settings | sound | const DEFAULT_NOTIFICATION_SOUND: string | Added|
| ohos.settings | sound | const AFFECTED_MUTE_STREAMS: string | Added|
| ohos.settings | sound | const AFFECTED_MODE_RINGER_STREAMS: string | Added|
| ohos.settings | sound | const DTMF_TONE_WHILE_DIALING: string | Added|
| ohos.settings | sound | const DTMF_TONE_TYPE_WHILE_DIALING: string | Added|
| ohos.settings | sound | const DEFAULT_ALARM_ALERT: string | Added|
| ohos.settings | sound | const VIBRATE_WHILE_RINGING: string | Added|
| ohos.settings | phone | const RTT_CALLING_STATUS: string | Added|
| ohos.settings | network | const NETWORK_PREFERENCE_USAGE: string | Added|
| ohos.settings | network | const HTTP_PROXY_CFG: string | Added|
| ohos.settings | network | const DATA_ROAMING_STATUS: string | Added|
| ohos.settings | input | const SHOW_PASSWORD_TEXT_INPUT: string | Added|
| ohos.settings | input | const AUTO_REPLACE_TEXT_INPUT: string | Added|
| ohos.settings | input | const AUTO_PUNCTUATE_TEXT_INPUT: string | Added|
| ohos.settings | input | const AUTO_CAPS_TEXT_INPUT: string | Added|
| ohos.settings | input | const SELECTOR_VISIBILITY_FOR_INPUT_METHOD: string | Added|
| ohos.settings | input | const ACTIVATED_INPUT_METHODS: string | Added|
| ohos.settings | input | const ACTIVATED_INPUT_METHOD_SUB_MODE: string | Added|
| ohos.settings | input | const DEFAULT_INPUT_METHOD: string | Added|
| ohos.settings | general | const TOUCH_EXPLORATION_STATUS: string | Added|
| ohos.settings | general | const SKIP_USE_HINTS: string | Added|
| ohos.settings | general | const GEOLOCATION_ORIGINS_ALLOWED: string | Added|
| ohos.settings | general | const ACTIVATED_ACCESSIBILITY_SERVICES: string | Added|
| ohos.settings | general | const ACCESSIBILITY_STATUS: string | Added|
| ohos.settings | general | const DEBUG_APP_PACKAGE: string | Added|
| ohos.settings | general | const DEBUGGER_WAITING: string | Added|
| ohos.settings | general | const USB_STORAGE_STATUS: string | Added|
| ohos.settings | general | const DEVICE_NAME: string | Added|
| ohos.settings | general | const CONTACT_METADATA_SYNC_STATUS: string | Added|
| ohos.settings | general | const BOOT_COUNTING: string | Added|
| ohos.settings | general | const HDC_STATUS: string | Added|
| ohos.settings | general | const DEVICE_PROVISION_STATUS: string | Added|
| ohos.settings | general | const ACCELEROMETER_ROTATION_STATUS: string | Added|
| ohos.settings | general | const END_BUTTON_ACTION: string | Added|
| ohos.settings | general | const SETUP_WIZARD_FINISHED: string | Added|
| ohos.settings | display | const DISPLAY_INVERSION_STATUS: string | Added|
| ohos.settings | display | const WINDOW_ANIMATION_SCALE: string | Added|
| ohos.settings | display | const TRANSITION_ANIMATION_SCALE: string | Added|
| ohos.settings | display | const ANIMATOR_DURATION_SCALE: string | Added|
| ohos.settings | display | const DEFAULT_SCREEN_ROTATION: string | Added|
| ohos.settings | display | const SCREEN_OFF_TIMEOUT: string | Added|
| ohos.settings | display | const MANUAL_SCREEN_BRIGHTNESS_MODE: number | Added|
| ohos.settings | display | const AUTO_SCREEN_BRIGHTNESS_MODE: number | Added|
| ohos.settings | display | const AUTO_SCREEN_BRIGHTNESS: string | Added|
| ohos.settings | display | const SCREEN_BRIGHTNESS_STATUS: string | Added|
| ohos.settings | display | const FONT_SCALE: string | Added|
| ohos.settings | date | const AUTO_GAIN_TIME_ZONE: string | Added|
| ohos.settings | date | const AUTO_GAIN_TIME: string | Added|
| ohos.settings | date | const TIME_FORMAT: string | Added|
| ohos.settings | date | const DATE_FORMAT: string | Added|
