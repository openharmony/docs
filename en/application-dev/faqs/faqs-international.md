# Intl Development

## How resources in AppScope, such as images and text, are referenced?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

Resources are referenced in the **$r('app.type.name')** format. Where, **type** indicates the resource type, such as color, string, and media, and **name** indicates the resource name.

## How do I convert the resource type to string?

Applicable to: OpenHarmony SDK3.0, stage model of API version 9

If the resource type is set to **string**, the qualifier directory can be set as **this.context.resourceManager.getStringSync(\\$r('app.string.test').id)** and can be converted synchronously. The **\$r('app.string.test', 2)** mode is not supported. For more usage methods, see [Resource Manager](../reference/apis/js-apis-resource-manager.md#getstringsync9).

## Why should I do if the constants referenced by $ in the form_config.json file does not take effect?

Applicable to: OpenHarmony SDK 3.2.6.5, API9 Stage model

In the **form\_config.json** file, **$** cannot be used to reference constants.
