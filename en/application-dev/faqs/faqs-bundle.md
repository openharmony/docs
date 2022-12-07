# Bundle Management Development

## How do I obtain the version code and version name of an application?

Applicable to: OpenHarmony SDK 3.2.3.5, stage model of API version 9

Use **bundle.getBundleInfo()** to obtain the bundle information, which contains the version code and version name.

Reference: [Bundle](../reference/apis/js-apis-Bundle.md#bundlegetbundleinfo)

## How do I obtain the bundle name of an application?

Applicable to: OpenHarmony SDK 3.2.3.5, stage model of API version 9

Obtain the bundle name through **context.abilityInfo.bundleName**.

Reference: [AbilityContext](../reference/apis/js-apis-ability-context.md) and [AbilityInfo](../reference/apis/js-apis-bundle-AbilityInfo.md)

## How do I obtain an application icon?

Applicable to: OpenHarmony SDK 3.2.3.5, stage model of API version 9

Use **bundle.getAbilityIcon** to obtain the application icon. To use this API, you must configure the permission **ohos.permission.GET_BUNDLE_INFO**.

Reference: [Bundle](../reference/apis/js-apis-Bundle.md#bundlegetbundleinfo)

## How do I determine whether an application is a system application?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

Use **bundle.getApplicationInfo** to obtain the application information, and then check the value of **systemApp** in the information. The application is a system application if the value is **true**.
