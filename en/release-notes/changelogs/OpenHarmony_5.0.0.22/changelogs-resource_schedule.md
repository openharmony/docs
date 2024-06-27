# Resource Scheduler Subsystem Changelog

## c1.resource schedule.1 Background Application Control Changed

**Access Level**

Other

**Change Reason**

After the continuous task of an audio playback application is stopped, the application still plays audio streams, affecting system running.

**Change Impact**

Applications that use audio resources improperly in the background will be forcibly terminated by the system.

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.0.22

**Key API/Component Changes**

Before the change: If the audio stream type is **STREAM_USAGE_MEDIA** or **SREAM_USAGE_UNKNOWN**, the application will be forcibly terminated by the system.

After the change: The system forcibly terminates the application regardless of the audio stream type used by the application.

Change plan: In this version, the log "Audio cannot be used after being frozen. The system will kill the UID" will be recorded. From the next version, the application will be forcibly terminated.

**Adaptation Guide**

To use audio resources in the background, an application must request a continuous task. When it no longer requires the audio resources, it should release the continuous task and audio resources in a timely manner.

For details about how to request a continuous task, refer to the following guide:
https://gitee.com/openharmony/docs/blob/master/en/application-dev/task-management/continuous-task.md