# Globalization Subsystem Changelog

## cl.global.1 Change in Display Names of Myanmar in Malay and Thai

**Access Level**

Public API

**Reason for Change**

The display names for Burmese, Malay, and Thai languages are incorrect.

**Change Impact**

This change requires application adaptation.

Before change: In the settings and startup wizard, the display name is မြန်မာ for Myanmar, Melayu for Malay, and ไทย for Thai.

After change: In the settings and startup wizard, the display name is မြန်မာစာ for Myanmar, Bahasa Melayu for Malay, and ภาษาไทย for Thai.

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.1.0.49

**Key API/Component Changes**

i18n.system.getDisplayLanguage

**Adaptation Guide**

No special checks are needed for the return values. They are only used for display purposes.
