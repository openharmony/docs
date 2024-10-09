# Introduction to Basic Services Kit

Basic Services Kit provides basic capabilities for application developers, from pasteboard read/write, file upload/download, file compression, file printing, inter-process/inter-thread communication, to device and application account management.

## When to Use

Among the various use cases, Basic Services Kit is typically used in the following:

- Pasteboard read/write
  - Intra-device copy and paste: For example, copy a piece of text in application A and paste it to another application.
  - Cross-device copy and paste: For example, copy a piece of text in a browser on device A and paste it to a notes application on device B.

- File upload and download
  - Upload and download in the foreground: usually involves small data volume and real-time feedback. Examples: send social media posts (such as images and short videos), share files with friends, and save images to the local device.
  - Upload and download in the background: usually involves large data volume and resumable transfers. Examples: cloud-device data synchronization and movie download.

- Inter-process/Inter-thread communication
  - Inter-process communication: For example, an ExtensionAbility sends events to the main process.
  - Inter-thread communication: For example, after processing a network request, the worker thread transfers the event back to the UI main thread.

## Capability Scope

Depending on different use cases, this Kit provides the following capabilities:

- Data file processing
  - [Pasteboard](../reference/apis-basic-services-kit/js-apis-pasteboard.md): provides the copy and paste support. You can use the provided APIs to operate pasteboard content of the plain text, HTML, URI, pixel map, and other types.
  - [Compression](../reference/apis-basic-services-kit/js-apis-zlib.md): provides APIs for file compression and decompression.
  - [Print](../reference/apis-basic-services-kit/js-apis-print.md): provides APIs for basic print operations, for example, transferring files for printing and setting printing parameters.
  - [Upload and download](../reference/apis-basic-services-kit/js-apis-request.md): provides basic upload, download, and background transmission agent capabilities.

- Inter-process/Inter-thread communication
  - [Common event](../reference/apis-basic-services-kit/js-apis-commonEvent.md): provides inter-process communication capabilities, including the capabilities to publish, subscribe to, and unsubscribe from common events. For details about the development guide, see [Introduction to Common Events](common-event/common-event-overview.md).
  - [Emitter](../reference/apis-basic-services-kit/js-apis-emitter.md): provides intra-thread communication capabilities, including the capabilities to publish, subscribe to, and unsubscribe from custom events. For details about the development guide, see [Using Emitter for Inter-Thread Communication](common-event/itc-with-emitter.md).

- Device management
  - [Device information](../reference/apis-basic-services-kit/js-apis-device-info.md): provides APIs for querying product information, such as the device type, device brand, product series, and product version.
  - [Data item settings](../reference/apis-basic-services-kit/js-apis-settings.md): provides APIs for setting data items, such as airplane mode and explore by touch.
  - [Battery information](../reference/apis-basic-services-kit/js-apis-battery-info.md): provides APIs for querying the battery information.
  - [Power management](../reference/apis-basic-services-kit/js-apis-power.md): provides system power management capabilities, such as querying the screen status.
  - [Running lock](../reference/apis-basic-services-kit/js-apis-runninglock.md): provides APIs for creating, querying, holding, and releasing running locks.
  - [Thermal management](../reference/apis-basic-services-kit/js-apis-thermal.md): provides thermal management capabilities, such as thermal level query.
  - [USB management](../reference/apis-basic-services-kit/js-apis-usbManager.md): provides USB device management capabilities, including USB device list query, bulk data transfer, control transfer, and permission control. For details about the development guide, see [USB Service Development Overview](usb/usb-overview.md).

- Others:
  - [App account management](../reference/apis-basic-services-kit/js-apis-appAccount.md): provides application account management and data management capabilities. For details, see [Managing App Accounts](account/manage-application-account.md).
  - [Public callback information](../reference/apis-basic-services-kit/js-apis-base.md): defines the public callback types of ArkTS APIs, including the common and error callbacks.
  - [Time and time zone](../reference/apis-basic-services-kit/js-apis-date-time.md): provides APIs for obtaining the system time and time zone.

## Relationship with Other Kits

- [ArkTS Kit](../arkts-utils/arkts-commonlibrary-overview.md): [Multithreaded concurrency (TaskPool and Worker)](../arkts-utils/multi-thread-concurrency-overview.md) in ArkTS Kit needs to use Emitter in this Kit for inter-thread communication.

- [Ability Kit](../application-models/abilitykit-overview.md): Common events in this Kit are required for inter-process communication in Ability Kit.

- [Core File Kit](../file-management/core-file-kit-intro.md): Core File Kit provides file access and management capabilities. You can use Core File Kit for application file access, file sharing, and data backup and restore, and use this Kit to implement file compression, file upload and download, and file printing.
