# Bundle Manager Subsystem Changelog

## cl.bundlemanager.1 Forbidding bm Commands for Cross-User Operations

**Access Level**

Public API

**Reason for Change**

The bm tool does not authenticate the identity of users invoking **sh**. Consequently, user A can run bm commands to install and uninstall applications in other user spaces, and discover applications installed there. This violates security standards.

**Change Impact**

This change is a non-compatible change.

Before change:

A user can use the **-u** parameter to specify other users in the following bm commands: **install**, **uninstall**, **dump**, **clean**, **disable** (for root users only), and **enable** (for root users only).

After change:

A user can no longer use the **-u** parameter to specify other users in the bm commands **install**, **uninstall**, **dump**, **clean**, **disable**, and **enable**. They are restricted to managing their own applications.

**Start API Level**

13

**Change Since**

OpenHarmony 5.0.0.52

**Key API/Component Changes**

bm tool

**Adaptation Guide**

To manipulate another user's application, it is necessary to log in as that user before proceeding with the bm commands.
