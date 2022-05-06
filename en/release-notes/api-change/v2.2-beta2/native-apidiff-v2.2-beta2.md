# Native API Differences
This document describes the changes of APIs in OpenHarmony 2.2 Beta2 over OpenHarmony 2.0 Canary.
## Mini System API Changes

| Module | API | Change Type | Change Type |
|  --------  |  --------  |  --------  |  --------  |
| global_i18n_lite                                   | static LocaleInfo LocaleInfo ::ForLanguageTag(const char *languageTag, I18nStatus &status); | Added                                      | API added.                                                    |
| global_i18n_lite                                   | const char LocaleInfo ::*GetExtension(const char *key);      | Added                                      | API added.                                                    |
| global_i18n_lite                                   | WeekInfo::WeekInfo(const LocaleInfo &localeInfo, I18nStatus &status); | Added                                      | API added.                                                    |
| global_i18n_lite                                   | uint8_t WeekInfo::GetFirstDayOfWeek();                       | Added                                      | API added.                                                    |
| global_i18n_lite                                   | uint8_t WeekInfo::GetMinimalDaysInFirstWeek();               | Added                                      | API added.                                                    |
| global_i18n_lite                                   | uint8_t WeekInfo::GetFirstDayOfWeekend();                    | Added                                      | API added.                                                    |
| global_i18n_lite                                   | uint8_t WeekInfo::GetLastDayOfWeekend();                     | Added                                      | API added.                                                    |
| global_i18n_lite                                   | int PluralFormat::GetPluralRuleIndex(double number, I18nStatus status); | Added                                      | API added.                                                    |
| powermgr_powermgr_lite                                   | const RunningLock *CreateRunningLock(const char *name, RunningLockType type, RunningLockFlag flag); | Added                                      | API added.                                                    |
| powermgr_powermgr_lite                                   | void DestroyRunningLock(const RunningLock *lock); | Added                                      | API added.                                                    |
| powermgr_powermgr_lite                                   | BOOL AcquireRunningLock(const RunningLock *lock); | Added                                      | API added.                                                    |
| powermgr_powermgr_lite                                   | BOOL ReleaseRunningLock(const RunningLock *lock); | Added                                      | API added.                                                    |
| powermgr_powermgr_lite                                   | BOOL IsRunningLockHolding(const RunningLock *lock); | Added                                      | API added.                                                    |
