# Updating Widget Content

The ArkTS widget framework provides the [updateForm](../reference/apis-form-kit/js-apis-app-form-formProvider.md#updateform) API for widget providers and the **requestForm** API for widget hosts to proactively trigger widget page refreshes. It also alerts providers to update widgets based on the scheduled information.

In widget UI code, you can use [LocalStorageProp](../quick-start/arkts-localstorage.md#localstorageprop) to obtain the widget data that requires updating, sent by the provider

| API| System Capability| Constraints|
| -------- | -------- | -------- |
| updateForm | No| 1. Invoked by the widget provider.<br>2. Allows only the widget provider to update its own widgets.|
| requestForm | Yes| 1. Invoked by the widget host.<br>2. Allows only the widget host to update the widgets added to it.|

**Widget provider proactively updating a widget**

![updateForm](figures/updateForm.PNG)

If there is a need to update widget data, the widget provider, as long as it is running, can proactively update the widget using the **updateForm** API provided by formProvider.

**Widget host proactively requesting a widget update**

![requestForm](figures/requestForm.PNG)

If changes in system language or color scheme are detected, the widget host, as long as it is running, can proactively request to update the widget using the **requestForm** API provided by formHost. The widget manager then instructs the widget provider to complete the update.

**Widget manager instructing the widget provider to periodically update a widget**

![timer_updateForm](figures/timer_updateForm.PNG)

Based on the scheduled update information configured by the widget provider, the widget manager determines whether to instruct the provider to update the widget, considering factors such as timing information, widget visibility status, and the number of updates.

The following are the typical use cases of widget updates:

- [Interval-based Widget Updates](arkts-ui-widget-update-by-time.md)
- [Time-specific Widget Updates](arkts-ui-widget-update-by-time-point.md)
- [Updating Local and Online Images in the Widget](arkts-ui-widget-image-update.md)
- [Updating Widget Content by State](arkts-ui-widget-update-by-status.md)
