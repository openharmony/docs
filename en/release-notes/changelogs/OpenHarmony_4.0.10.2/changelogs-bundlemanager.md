# Bundle Management Subsystem Changelog

## cl.bundlemanager.1 Bottom-Layer Capability Changed

When the SDK of API version 9 or an earlier version is used to compile the HAP, the resource files of the HAP are decompressed after the HAP is installed.

When the SDK of API version 10 or a later version is used to compile the HAP, the resource files of the HAP are not decompressed after the HAP is installed.

**Change Impact**

If the SDK of API version 9 or earlier is used, no adaptation is required.

If the SDK of API version 10 or a later version is used and your application accesses resource files by combining paths, adaptation is required. If your application does not access resource files by combining paths, adaptation is not required.

**Key API/Component Changes**

No API or component change is involved.

**Adaptation Guide**

The resource manager subsystem provides JS APIs for accessing resource files. 

Reference: [Accessing Resource Files](../../../application-dev/reference/apis/js-apis-resource-manager.md#getrawfilecontent9)