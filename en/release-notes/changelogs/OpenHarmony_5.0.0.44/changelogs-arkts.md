# ArkTS Subsystem Changelog

## cl.arkts.1 Access Level of APIs of RestrictedWorker in the worker Module Changed

**Access Level**

Public API

**Reason for Change**

Due to security compliance requirements, the APIs of the **RestrictedWorker** class are changed from public APIs to system APIs.

**Change Impact**

This change is a non-compatible change.

Before change:

APIs of the **RestrictedWorker** class in the worker module are public APIs and can be called by third-party applications.

After change:

APIs of the **RestrictedWorker** class in the worker module are changed to system APIs and can be called only by system applications. When a non-system application uses these APIs, the compilation may fail.

**Start API Level**

11

**Change Since**

OpenHarmony SDK 5.0.0.44

**Key API/Component Changes**

Two APIs in the worker module:

1. class RestrictedWorker extends ThreadWorker;

2. constructor(scriptURL: string, options?: WorkerOptions);

**Adaptation Guide**

If only inter-thread communication is involved, you can use the **worker.ThreadWorker** class to create Worker threads.
