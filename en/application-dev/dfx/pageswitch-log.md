# Page Switch Logs

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @buzhenwang-->
<!--Designer: @shenchenkai-->
<!--Tester: @liyang2235-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=9d773833b117fc5ed73ff7de0ced9eed6cb96fec translatedAt=2026-07-31T01:35:15.645Z pushedAt=2026-07-31T08:30:52.573Z -->

## Overview

Page switch logs record the app's page switch history, including events such as window creation, window destruction, and page switches. These logs help developers analyze user actions leading up to a fault and improve troubleshooting efficiency.

## Obtaining Logs

If a process enables page switch logging in a fault event policy configured through the HiAppEvent API (for example, a [crash event configuration policy](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#appcrashpolicy24)), HiAppEvent returns a snapshot of the corresponding page switch log file when the fault occurs. Developers can use this snapshot for fault analysis. The log snapshot file format is as follows:

```text
page_switch-com.example.myapplication-1-1-20260509142812417.log
```

| Column 1 | Column 2 | Column 3 | Column 4 | Column 5 | Column 6 |
| :--------: | :--------: | :--------: | :--------: | :--------: | :--------: |
| Log prefix | Process name | Instance index | File index | Timestamp | Log suffix |
| page_switch | com.example.myapplication | 1 | 1 | 20260509142812417 | log |

> **NOTE**
>
> Process name: When the process name contains `:`, `/`, or `-`, these characters are replaced with `_`.
>
> Instance index: In scenarios where multiple processes share a sandbox (for example, [multi-instance](../quick-start/multiInstance.md) or [ExtensionAbility component](../application-models/extensionability-overview.md) scenarios), log write conflicts may occur. To avoid conflicts, page switch logs maintain a separate set of log files for each process, identified by an instance index. Value range: [1, 10].
>
> File index: A maximum of 2 files are retained under the same process name and instance index. Value range: [1, 2].
>
> Timestamp: The format is `YYYYMMDDhhmmssSSS`, where the year (`YYYY`) occupies 4 digits, the month (`MM`), day (`DD`), hour (`hh`), minute (`mm`), and second (`ss`) each occupy 2 digits, and the millisecond (`SSS`) occupies 3 digits.

## Log Format

The log format in the log snapshot file is as follows:

```text
2026-03-24 17:03:55.361   2569   2569 Hap onBackground
```

| Column 1 | Column 2 | Column 3 | Column 4 | Column 5 |
| :--------: | :--------: | :--------: | :--------: | :--------: |
| Date | Timestamp | Process ID | Thread ID | Log content |
| 2026-03-24 | 17:03:55.361 | 2569 | 2569 | Hap onBackground |

> **NOTE**
>
> Each log message supports a maximum length of 1024 bytes. Any excess content is truncated.