# HiSysEvent Overview


## Introduction

HiSysEvent provides event logging APIs for OpenHarmony to record important information of key processes during system running, helping you locate faults. In addition, you can upload the log data to the cloud for big data analytics.

The key modules of HiSysEvent are described as follows:

- Event configuration: enables you to define HiSysEvent events in YAML files.

- Trace point configuration: provides trace point APIs and supports flushing of HiSysEvent events to disks.

- Event subscription: provides APIs for you to subscribe to HiSysEvent events by event domain and event name.

- Event query: provides APIs for you to query HiSysEvent events by event domain and event name.

- Event debugging tool: allows you to subscribe to real-time HiSysEvent events and query historical HiSysEvent events.

## Reference

For more information about the source code and usage of HiSysEvent, access the HiSysEvent code repository(https://gitee.com/openharmony/hiviewdfx_hisysevent).
