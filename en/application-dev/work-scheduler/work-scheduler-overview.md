# Work Scheduler Overview

The Work Scheduler provides a mechanism for applications to execute non-real-time tasks when the system is idle. If the preset conditions are met, the tasks will be placed in the execution queue and scheduled when the system is idle.

## Usage

If your application needs to execute a non-real-time task, for example, data learning, you can harness the Work Scheduler mechanism, which will schedule the task based on the storage space, power consumption, temperature, and more when the preset conditions are met.

## Constraints

The use of the Work Scheduler must comply with the following restrictions and rules:

- **Timeout**: The Work Scheduler callback can run only within the specified period of time. After the timeout, the callback automatically stops.
- **WorkInfo setting**

(1) **workId**, **bundleName**, and **abilityName** are mandatory. **bundleName** must be set to the name of the current application. Otherwise, the verification will fail.

(2) At least one condition must be set.

(3) The repeat interval must be at least 20 minutes and must work with the Always repeat pattern or repeat times.
