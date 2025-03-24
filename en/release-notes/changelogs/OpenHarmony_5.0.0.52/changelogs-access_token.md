# Access Token Changelog

## cl.access_token.1 Change of the Default Behavior of Security Components upon UX Display Exceptions

**Access Level**

Public API

**Reason for Change**

When a security component integrated into an application encounters a UX display exception, it still responds to user taps.

**Change Impact**

This change is a non-compatible change.

Before the change:

The security components integrated into application still respond to user taps when encountering a UX display exception.

After the change:

The security components integrated into applications do not respond to user taps when encountering a UX display exception.

**Start API Level**

10

**Change Since**

OpenHarmony SDK 5.0.0.52

**Key API/Component Changes**

**LocationButton** in @internal/component/ets/location_button.d.ts.

**SaveButton** in @internal/component/ets/save_button.d.ts.

**PasteButton** in @internal/component/ets/paste_button.d.ts.

**Adaptation Guide**

If a security component encounters a UX display exception, check the [image effect settings](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-image-effect.md) of its parent component. Change image effect properties to no effect.
