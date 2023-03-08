# Resource Scheduler Subsystem Changelog

## cl.resourceschedule.workScheduler 
The data type of the **parameters** attribute value is changed. Specifically, the number, string, and boolean types are supported, but the any type is not.

**Change Impact**

For applications developed based on OpenHarmony3.2.10.7 and later SDK versions, the **parameters** attribute value can use the number, string, and boolean types only. If it uses the any type, a compilation error is reported.

**Key API/Component Changes**

The **parameters** attribute in @ohos.resourceschedule.workScheduler.d.ts is changed.

| Class| API Type| Statement Before the Change| Statement After the Change| 
|  -- | -- | -- | -- |
| workScheduler.WorkInfo | field | parameters?: {[key: string]: any} | parameters?: {[key: string]: number | string | boolean} | 


**Adaptation Guide**

The **parameters** attribute uses the {[key: string]: number | string | boolean} data type.
