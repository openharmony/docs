# DFX Subsystem Changelog

## cl.hiviewdfx.1 System Event Logging Frequency Limit Changed for the write API of the HiSysEvent Module

This allows the **write** API to adapt to service scenarios that require frequent system event logging.

  - Changed the maximum number of times the **write** API can be called for system event logging within 5 seconds from 10 to 100.

**Change Impact**

The **write** API is able to adapt to service scenarios that require frequent system event logging.

**Key API/Component Changes**

Involved APIs:
  - Rust: hisysevent::write;
  - JS: hiSysEvent.write;
  - C++: HiSysEventWrite;
  - C: HiSysEvent_Write;

**Adaptation Guide**

No additional adaptation is required.
