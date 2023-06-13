# Ability Framework Changelog


## cl.ability.1 RestartFlag Attribute Names Changed and Unsupported Attribute Deleted in appRecovery

In the **appRecovery** API, the enum names of **RestartFlag** are changed from **NO_RESTART** upon a specific fault to **RESTART** upon a specific fault. 
The **CPP_CRASH_NO_RESTART** enum is deleted.

**Change Impact**

If your application uses the **CPP_CRASH_NO_RESTART**, **JS_CRASH_NO_RESTART**, or **APP_FREEZE_NO_RESTART** attribute in versions earlier than 4.0.2.3, its behavior will change after an upgrade to 4.0.2.3.

**Key API/Component Changes**

**RestartFlag** <sup>9+</sup>

Before change
| Name                         | Value  | Description                                                        |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| ALWAYS_RESTART           | 0    | The application is restarted in all cases.|
| CPP_CRASH_NO_RESTART           | 0x0001    | The application is **not restarted** in the case of CPP_CRASH.|
| JS_CRASH_NO_RESTART           | 0x0002    | The application is **not restarted** in the case of JS_CRASH.|
| APP_FREEZE_NO_RESTART           | 0x0004    | The application is **not restarted** in the case of APP_FREEZE.|
| NO_RESTART           | 0xFFFF    | The application is not restarted in any case.|

After change
| Name      | Value  | Description      |
| ---------- | ---- | ---------- |
| ALWAYS_RESTART   | 0    | The application is restarted in all cases.|
| CPP_CRASH_NO_RESTART   | NA    | **Deleted.** The restart in this scenario is not supported.|
| RESTART_WHEN_JS_CRASH   | 0x0001    | The application is **restarted** in the case of JS_CRASH.|
| RESTART_WHEN_APP_FREEZE   | 0x0002    | The application is **restarted** in the case of APP_FREEZE.|
| NO_RESTART           | 0xFFFF    | The application is not restarted in any case.|

**Adaptation Guide**

Perform adaptation based on the new semantics.
