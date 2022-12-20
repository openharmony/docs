# Native API 差异报告
OpenHarmony 2.2 Beta2相较于OpenHarmony 2.0 Canary版本的API变更如下:
## 轻量级系统接口变更

| 模块名称  | 接口名称  | 变更类型  | 变更类型  |
|  --------  |  --------  |  --------  |  --------  |
| global_i18n_lite                                   | static LocaleInfo LocaleInfo ::ForLanguageTag(const char *languageTag, I18nStatus &status); | 新增                                       | 新增接口                                                     |
| global_i18n_lite                                   | const char LocaleInfo ::*GetExtension(const char *key);      | 新增                                       | 新增接口                                                     |
| global_i18n_lite                                   | WeekInfo::WeekInfo(const LocaleInfo &localeInfo, I18nStatus &status); | 新增                                       | 新增接口                                                     |
| global_i18n_lite                                   | uint8_t WeekInfo::GetFirstDayOfWeek();                       | 新增                                       | 新增接口                                                     |
| global_i18n_lite                                   | uint8_t WeekInfo::GetMinimalDaysInFirstWeek();               | 新增                                       | 新增接口                                                     |
| global_i18n_lite                                   | uint8_t WeekInfo::GetFirstDayOfWeekend();                    | 新增                                       | 新增接口                                                     |
| global_i18n_lite                                   | uint8_t WeekInfo::GetLastDayOfWeekend();                     | 新增                                       | 新增接口                                                     |
| global_i18n_lite                                   | int PluralFormat::GetPluralRuleIndex(double number, I18nStatus status); | 新增                                       | 新增接口                                                     |
| powermgr_powermgr_lite                                   | const RunningLock *CreateRunningLock(const char *name, RunningLockType type, RunningLockFlag flag); | 新增                                       | 新增接口                                                     |
| powermgr_powermgr_lite                                   | void DestroyRunningLock(const RunningLock *lock); | 新增                                       | 新增接口                                                     |
| powermgr_powermgr_lite                                   | BOOL AcquireRunningLock(const RunningLock *lock); | 新增                                       | 新增接口                                                     |
| powermgr_powermgr_lite                                   | BOOL ReleaseRunningLock(const RunningLock *lock); | 新增                                       | 新增接口                                                     |
| powermgr_powermgr_lite                                   | BOOL IsRunningLockHolding(const RunningLock *lock); | 新增                                       | 新增接口                                                     |