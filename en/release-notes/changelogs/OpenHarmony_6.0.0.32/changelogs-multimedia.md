# Multimedia Subsystem Changelog

## cl.multimedia.1 	Change in Memory Ownership for Player Usage

**Access Level**

Other

**Reason for Change**

Currently, the memory used by AVPlayer instances created by applications is uniformly attributed to the operating system. This makes it impossible to manage memory finely based on applications and can easily lead to misuse of AVPlayer instances by applications. This change will associate the memory cache used by the AVPlayer with the application that created the AVPlayer, facilitating the statistical use of resources by applications.

**Impact of the Change**

This change requires application adaptation.

Before the change, when an application uses AVPlayer, the memory used by the AVPlayer is attributed to the operating system's memory usage during memory management.
After the change, when an application uses AVPlayer, the memory used by the AVPlayer is attributed to the application's memory usage during memory management.

**Start API Level**

9

**Change Since**

OpenHarmony SDK 6.0.0.32

**Key API/Component Changes**

AVPlayer

**Adaptation Guide**

If the number of instances used by an application exceeds the recommended number (16), adjust the number of instances based on its actual memory usage to prevent the application from being terminated by RSS when it transitions to the background.
