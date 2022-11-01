# 国际化开发常见问题

## AppScope中的资源如图片，文字等的引用方式是什么

适用于：OpenHarmony SDK 3.2.5.5版本，API9 Stage模型

通过$r('app.type.name')的形式来引用，type代表资源类型，如color，string，media等，name代表资源命名

## Resource类型转为string

适用于：OpenHarmony SDK3.0, API9 Stage模型

Resource为string支持限定词目录使用this.context.resourceManager.getStringSync(\\$r('app.string.test').id)，可以同步转换，不支持\$r('app.string.test', 2)方式。更多用法请参考[ResourceManager(资源管理)](../reference/apis/js-apis-resource-manager.md#getstringsync9)

## form_config.json文件中使用$引用常量为什么不生效 

适用于：OpenHarmony SDK 3.2.6.5, API9 Stage模型

form_config.json文件中不支持使用$引用常量。
