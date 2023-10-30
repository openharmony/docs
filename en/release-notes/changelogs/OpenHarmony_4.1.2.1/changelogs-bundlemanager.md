# Bundle Manager Subsystem Changelog
## cl.bundlemanager.1 Maximum Length Allowed for bundleName in the Application Installation Package Changed to 128 Characters

During application installation, the bundle manager subsystem verifies the length of **bundleName** in the installation package. The maximum length allowed is changed from 127 characters to 128 characters.

**Change Impact**

Before the change, the maximum length allowed for **bundleName** in the installation package is 127 characters. If the length of **bundleName** is greater than or equal to 128 characters, the system reports an error and the application cannot be installed.

After the change, the maximum length allowed for **bundleName** in the installation package is 128 characters. If the length of **bundleName** is 128 characters, the application can be installed. If the length is greater than 128 characters, the system reports an error and the application cannot be installed.

**Key API/Component Changes**

N/A

**Adaptation Guide**

No adaptation is required.