# Event Subscription Overview

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @liujiaxing2024-->
<!--Designer: @jiangwenhao-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=83e3a48dffb345a35ffd2cec54f9c4fffdcf8535 translatedAt=2026-07-29T10:46:45.902Z pushedAt=2026-07-29T11:06:16.723Z -->

## Event Description

The HiAppEvent module can be used to subscribe to application events and system events.

### Application Events

Application events are defined by developers. For example, a button click event. The fields contained in the **params** object of an application event come from the application. You can customize the fields through the [write](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#hiappeventwrite-1) API. You can determine the field meanings as required.

### System Events

System events occur during application running, such as performance, power consumption, and stability issues. The fields contained in the **params** object of system events are defined by the system services. In addition, you can add custom parameters to the **params** object for crash events and application freeze events through the [setEventParam](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#hiappeventseteventparam12) API.

For details about the supported system events, detection principles, and fields in **params**, see the related topics.

[Crash Event Overview](hiappevent-watcher-crash-events.md)

[Application Freeze Event Overview](hiappevent-watcher-freeze-events.md)

[App Freeze Warning Event Overview](hiappevent-watcher-appfreezewarning-events.md)

[Resource Leak Event Overview](hiappevent-watcher-resourceleak-events.md)

[Address Sanitizer Event Overview](hiappevent-watcher-address-sanitizer-events.md)

[Main Thread Jank Event Overview](hiappevent-watcher-mainthreadjank-events.md)

[Task Execution Timeout Event Overview](hiappevent-watcher-apphicollie-events.md)

[Application Killed Event Overview](hiappevent-watcher-app-killed-events.md)

[ArkWeb Fling Jank Event Overview](hiappevent-watcher-web-fling-jank-events.md)

<!--RP1-->
<!--RP1End-->

## Event Subscription Methods

HiAppEvent provides the [addWatcher](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#hiappeventaddwatcher) API for subscribing to system events. The following subscription methods are supported:

Method 1: Set **triggerCondition** to implement the **onTrigger()** callback. When the callback conditions are met, the system automatically triggers the callback.

Method 2: If the **triggerCondition** parameter is not set, use the **holder** object returned by the event subscription to obtain the subscribed event.

> **NOTE**
>
> If the event is not generated or the log information is not captured, the query result may be empty. In this case, you are advised to call the query interface for multiple times.

Method 3: Implement the **onReceive()** callback, which is triggered in real time when the subscribed event occurs.

For details about event subscription using ArkTS APIs, see [hiAppEvent.addWatcher](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#hiappeventaddwatcher). The C/C++ event subscription APIs support only method 1 and method 3. For details, see [Subscribing to an Event](hiappevent-watcher-app-events-ndk.md#step-2-subscribing-to-an-event).