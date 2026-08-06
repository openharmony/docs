# Function Flow Runtime Job Partner (C++)

<!--Kit: Function Flow Runtime Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @chuchihtung-->
<!--Designer: @zhanglu161-->
<!--Tester: @lotsof-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=246cbb87769d7ba2d4f71c6a8b417a57ec2cbfa6 translatedAt=2026-08-03T08:16:39.810Z pushedAt=2026-08-03T09:24:11.743Z -->

## Overview

Function flow runtime (FFRT) supports the Job Partner function starting from API version 20. In some services, a thread (for example, the UI rendering thread) may take a long time, and the multi-core capability of the CPU cannot be fully utilized. In this case, you can split the large task of the original thread into multiple small tasks and assign them to other threads for execution. However, two problems may occur in practice:

- Problem 1: Some segments of small tasks must be executed on a specified thread due to certain reasons (for example, accessing variables in the JS virtual machine).

- Problem 2: Small tasks may be split into multiple smaller segments (possibly due to problem 1 or other reasons). The execution time of each segment may only be at the microsecond level, while the overhead of waking up a single thread is several tens of microseconds, making it difficult to obtain concurrency benefits.

To solve the preceding problems, the job partner concurrency paradigm is introduced.

![image](figures/ffrt_figure8.png)

In the job partner concurrency paradigm, the original thread is defined as the master thread, and partner threads can be dynamically managed. This paradigm addresses the aforementioned problems through the following two features:

- Feature 1 (for problem 1): The partner thread can suspend the execution of the current task, send the task to the master thread for execution, and continue the execution of the original task on the partner thread after the master thread completes the task.

- Feature 2 (for problem 2): Multiple small tasks can be dynamically combined into a larger FFRT task to average the scheduling overhead of a single small task.

## Example: A Mall System

Nodes of a mall system can be created in parallel. Some code snippets created by a node must run in the JS thread, and other code snippets can run in any thread.

The original pseudocode is as follows:

```cpp
namespace market_system {
    // Create nodes in batches. The API is called on the JS thread.
    void create_nodes(std::array<Node>& nodes)
    {
        for (int i = 0; i < nodes.size(); i++) {
            code1(); // Code snippet that can be executed on any thread.
            code2(); // Code snippet that must be executed on the JS thread.
            code3(); // Code snippet that can be executed on any thread.
        }
    }
};
```

The pseudocode after job partner parallelization is as follows:

```cpp
#include <array>
#include <memory>
#include "ffrt/ffrt.h" // From the OpenHarmony third-party library "@ppd/ffrt"

namespace market_system {
    // Create nodes in batches. The API is called on the JS thread.
    void create_nodes(std::array<Node>& nodes)
    {
        constexpr uint64_t stack_size = 16 * 1024;
        auto stack = std::make_unique<std::array<char, stack_size>[]>(nodes.size()); // Create a specified number (defined by job_num) of execution stacks.
        auto partner = ffrt::job_partner<>::get_partner_of_this_thread(); // Obtain the partner of the current JS thread.
        for (int i = 0; i < nodes.size(); i++) {
            partner->submit([&] { // Submit the creation of each node to the partner.
                code1(); // Code snippet that can be executed on any thread.
                ffrt::job_partner<>::submit_to_master([&] { // Send the task that must be executed on the master thread to the main thread and wait synchronously.
                    code2(); // Code snippet that must be executed on the JS thread.
                });
                code3(); // Code snippet that can be executed on any thread.
            }, &stack[i], stack_size);
        }
        partner->wait(); // Wait until all nodes are created.
    }
};
```

## Available APIs

The key FFRT APIs involved in the preceding example are as follows:

| API                                                                                                                     | Description                |
| ------------------------------------------------------------------------------------------------------------------------- | -------------------- |
| [job_partner](https://gitcode.com/openharmony/resourceschedule_ffrt/blob/master/docs/ffrt-api-guideline-cpp.md#job_partner) | Fine-grained job partner API.|

> **NOTE**
>
> - For details about how to use FFRT C++ APIs, see [Using FFRT C++ APIs](ffrt-development-guideline.md#using-ffrt-c-api-1).
> - When using FFRT C or C++ APIs, you can use the FFRT C++ API third-party library to simplify header file inclusion, that is, use the `#include "ffrt/ffrt.h"` statement.

## Constraints

- The job partner concurrency paradigm applies to a large number of tasks that are fine-grained and do not block threads for an extended period.

- If tasks are coarse-grained (for example, taking more than hundreds of microseconds), you are advised to use the more general task submission API of FFRT.

- If tasks are not in large batches, using the job partner concurrency paradigm will not significantly reduce scheduling overhead.