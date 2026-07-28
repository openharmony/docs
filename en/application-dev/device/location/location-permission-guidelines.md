# Applying for Location Permissions

<!--Kit: Location Kit-->
<!--Subsystem: Location-->
<!--Owner: @xxthadsl-->
<!--Designer: @liu-binjun-->
<!--Tester: @gcw_MslijYkf-->
<!--Adviser: @RayShih-->
<!-- md-trans-meta sourceCommit=4f1f82da82ec1da992bee864d1f41f66de3c9d98 translatedAt=2026-07-28T02:35:50.307Z pushedAt=2026-07-28T03:22:12.833Z -->

## Scenario

Before using the system capabilities of Location Kit, check whether your application has been granted the permission to access the device location information. If not, your application needs to obtain the permission from the user.

The system provides the following location permissions:

- **ohos.permission.LOCATION**: used to obtain location accurate to meters.

- **ohos.permission.APPROXIMATELY\_LOCATION**: used to obtain location accurate to 5 kilometers.

- **ohos.permission.LOCATION_IN_BACKGROUND**: used to obtain location while the application is running in the background.

For the permission requirements of Location Kit APIs, see [@ohos.geoLocationManager (Geolocation Manager)](../../reference/apis-location-kit/js-apis-geoLocationManager.md).

## How to Develop

1. Declare the required permission in your application's configuration file. For details, see [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).

2. If your application needs to access the device location when running in the foreground, declare the location permission as described in the following table.

| Permission| Declarable or Not| Location Accuracy|
| -------- | -------- | -------- |
| ohos.permission.APPROXIMATELY_LOCATION| Yes| Location accurate to 5 kilometers.|
| ohos.permission.APPROXIMATELY_LOCATION and ohos.permission.LOCATION| Yes| Location accurate to meters.|

3. If your application needs to access the device location when running in the background, declare the location permission as follows:

If your application needs to access the device location when running in the background, also request for a continuous task of the LOCATION type in addition to the permission declared in step 2.

For details about how to request for a continuous task, see [Continuous Task](../../task-management/continuous-task.md)<!--Del--> and [Continuous Task Development Example](../../performance/reasonable-running-backgroundTask.md#continuous-task)<!--DelEnd-->.

<!--RP1--><!--RP1End-->