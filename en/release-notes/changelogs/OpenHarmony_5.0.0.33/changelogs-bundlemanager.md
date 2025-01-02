# Bundle Manager Subsystem Changelog

## cl.bundlemanager.1 Default Compression Behavior Changed for APP File Packaging with the Packing Tool

**Access Level**

Other

**Reason for Change**

The packaging specifications are changed. APP files are packaged in compression mode to reduce the size of applications to be released. The size of a single package of an atomic service cannot exceed 2 MB.

**Change Impact**

This change is a non-compatible change. In release mode, compression is enabled by default during APP file packaging, which slows down the packaging speed. This change is not introduced in debug mode. The size of a single atomic service package cannot exceed 2 MB.

**Start API Level**

N/A

**Change Since**

OpenHarmony SDK 5.0.0.33

**Key API/Component Changes**

Packing tool

**Adaptation Guide**

No adaptation is required.

## cl.bundlemanager.2 Verification Rules of the Packing Tool Changed for Atomic Service Widgets and Snapshots

**Access Level**

Other

**Reason for Change**

Removed the restriction that an atomic service must contain at least one 2 x 2 widget. An atomic service can provide no widget. However, if a widget is provided, snapshots of all sizes configured for the widget must be available.

**Change Impact**

This change is a non-compatible change. After the change, if there is a widget, snapshots of all sizes configured for the widget must be provided. Otherwise, the packaging fails.

**Start API Level**

N/A

**Change Since**

OpenHarmony SDK 5.0.0.33

**Key API/Component Changes**

Packing tool

**Adaptation Guide**

Provide snapshots of all sizes configured for the widget.
