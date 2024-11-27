# Bundle Manager Subsystem Changelog

## cl.bundlemanager.1 bm Commands Changed

**Access Level**

Other

**Reason for Change**

Previously, if the **-u** parameter is not specified, the **bm install** and **bm uninstall** commands are executed for all users. For security purposes, now they are executed for the current active user.

**Change Impact**

This change is a non-compatible change.

Before change:
If **-u** is not specified in the **bm install** and **bm uninstall** commands, the commands apply to all users.

After change:
If **-u** is not specified in the **bm install** and **bm uninstall** commands, the commands apply to the current active user. If you want to install or uninstall applications for all users, use **-u** to specify user IDs one by one.

**API Level**

N/A

**Change Since**

OpenHarmony 5.0.0.36

**Adaptation Guide**

N/A
