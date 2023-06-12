# Bundle Management Subsystem Changelog

## cl.bundlemanager.1 Changed Underlying Capability by Not Decompressing the HAP During HAP Installation

The HAP will no longer be decompressed during installation. After the installation is complete, only the HAP file exists in the installation directory. As a result, the application must use the standard resource management interface, rather than a combined path, to access a resource file.

**Change Impact**

If the application uses a combined path to access a resource file, the access fails. It must use the resource management interface.

**Key API/Component Changes**

No API or component change is involved.

**Adaptation Guide**

The resource management subsystem provides the JS interface for accessing resource files. Reference: [Accessing Resource Files](../../../application-dev/reference/apis/js-apis-resource-manager.md#getrawfilecontent9)