# HiCollie

## Overview

Provides the APIs for detecting service thread jank and stuck events. Note that these APIs must be called in non-main threads. The following capabilities are supported:<br>(1) Register a periodic detection task for application service thread stuck events.<br>(2) Register a callback for the detection of application service thread jank events.<br>(3) Report application service thread stuck events.

**Since**: 12
## Files

| Name| Description|
| -- | -- |
| [hicollie.h](capi-hicollie-h.md) | HiCollie provides APIs for detecting service thread stuck and jank events and reporting stuck events.|
