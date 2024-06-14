# Bundle Manager Subsystem Changelog

## cl.bundlemanager.1 bm Commands Changed

**Access Level**

Other

**Change Reason**

The **bm disable** and **bm enable** commands have excessive permissions. After **bm disable** is run, necessary processes may be skipped for some applications. For security purposes, the two commands are disabled in the user version.

The **bm clean** command clears application data. It is available in the user version only when the developer mode is enabled.

**Change Impact**

This change is a non-compatible change.

The **bm disable** and **bm enable** commands are unavailable in the user version.

The **bm clean** command is available in the user version only when the developer mode is enabled.

**API Level**

N/A

**Change Since**

OpenHarmony 5.0.0.17

**Adaptation Guide**

No adaptation is required.
