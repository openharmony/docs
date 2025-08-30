# HiAppEvent

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @liujiaxing2024-->
<!--SE: @junjie_shi-->
<!--TSE: @gcw_KuLfPSbe-->

## Overview

Provides APIs for implementing the application event logging functionality. This functionality allows your application to record fault events, statistics events, security events, and user behavior events reported during system running. Based on the event information, you can analyze the operating status of your application.

**Since**: 8
## Files

| Name| Description|
| -- | -- |
| [hiappevent.h](capi-hiappevent-h.md) | Defines the application event logging functions of the HiAppEvent module. Before performing application event logging, you must construct a parameter list object to store the input event parameters and specify the event domain, event name, and event type. <p>Event domain: domain associated with the application event. <p>Event name: name of the application event. <p>Event type: fault, statistics, security, or behavior. <p>Parameter list: a linked list used to store event parameters. Each parameter consists of a parameter name and a parameter value.|
| [hiappevent_cfg.h](capi-hiappevent-cfg-h.md) | Defines the configuration items of the event logging configuration function. If you want to configure the application event logging function, you can directly use configuration item constants.|
| [hiappevent_event.h](capi-hiappevent-event-h.md) | Defines the names of all predefined events. In addition to custom events associated with specific applications, you can use predefined events for logging.|
| [hiappevent_param.h](capi-hiappevent-param-h.md) | Defines the names of all predefined event parameters. In addition to custom events associated with specific applications, you can use predefined events for logging.|
