# UI Stability Issue Analysis Overview

This topic explains the concepts and classification of stability issues, and provides guidance for locating stability issues using system debugging capabilities and tools.

Application stability issues include application crashes, application freezes, and application resource leaks. Performance issues are not classified as stability issues. For details about performance issues, see [High-Performance UI Development](ui-performance-overview.md).

<!--RP1-->
<!--RP1End-->

## Application Crash

Application crashes, also referred to as unexpected application exits, occur when an application terminates unexpectedly during runtime. They are typically caused by the following factors:

- Unhandled JavaScript exceptions, such as **TypeError** and **ReferenceError**.
- Unhandled native exceptions, such as **SIGSEGV** and **SIGABRT**.
- System resource limitations, such as insufficient memory and exhausted file handles or thread handles.
- Application UI freezes.

This document focuses on the first two categories: JavaScript crashes and C++ crashes. Other types are covered under application resource leaks and freezes.

### JavaScript Crash (jscrash)

When a JavaScript crash occurs, the FaultLogger module collects fault information. For details about how to obtain logs, see [Obtaining Logs](../dfx/jscrash-guidelines.md#obtaining-logs).

Reference materials:

- [JS Crash (Process Crash) Detection](../dfx/jscrash-guidelines.md)

### C++ Crashes (cppcrash)

When a C++ crash occurs, the FaultLogger module collects fault information. For details about how to obtain logs, see [Obtaining Logs](../dfx/cppcrash-guidelines.md#obtaining-logs).

Reference materials:

- [C++ Crash (Process Crash) Detection](../dfx/cppcrash-guidelines.md)
- [Address Sanitizer Detection](../dfx/address-sanitizer-guidelines.md)
<!--RP1-->
<!--RP1End-->

## Application Freeze

Application freezes, also known as application unresponsiveness , occur when an application becomes unresponsive to user interactions. The following materials provide guidance for analyzing application freeze issues:

- [Application Freeze Detection](../dfx/appfreeze-guidelines.md)
- [Task Timeout Detection](../dfx/apptask-timeout-guidelines.md)
<!--RP1-->
<!--RP1End-->

## Application Resource Leak

The following materials provide guidance for analyzing application resource leak issues:

- [Resource Leak Event Overview](../dfx/hiappevent-watcher-resourceleak-events.md)
- [Subscribing to Resource Leak Events (ArkTS)](../dfx/hiappevent-watcher-resourceleak-events-arkts.md)
- [Subscribing to Resource Leak Events (C/C++)](../dfx/hiappevent-watcher-resourceleak-events-ndk.md)
<!--RP1-->
<!--RP1End-->
