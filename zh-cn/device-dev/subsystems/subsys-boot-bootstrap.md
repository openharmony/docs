# bootstrap服务启动组件


bootstrap服务启动组件实现了服务的自动初始化，即服务的初始化函数无需显式调用，而是将其使用宏定义的方式申明，就会在系统启动时自动被执行。实现原理是将服务启动的函数通过宏定义的方式申明之后，放在预定义好的zInit代码段中，系统启动的时候调用OHOS_SystemInit接口遍历该代码段并调用其中的函数。因此，需要在链接脚本中添加zInit段，并且在main函数里调用OHOS_SystemInit接口。


zInit段的添加可参考已有的Hi3861平台的链接脚本，文件路径为vendor/hisi/hi3861/hi3861/build/link/link.ld.S。


用于实现服务的自动初始化的宏定义接口请参见启动恢复子系统的[API接口文档](https://device.harmonyos.com/cn/docs/develop/apiref/init-0000001054598113)。


## 接口说明

bootstrap服务自动初始化宏如表1所述。

  **表1** 主要的服务自动初始化宏

| 接口名 | 描述 | 
| -------- | -------- |
| SYS_SERVICE_INIT(func) | 标识核心系统服务的初始化启动入口。 | 
| SYS_FEATURE_INIT(func) | 标识核心系统功能的初始化启动入口。 | 
| APP_SERVICE_INIT(func) | 标识应用层服务的初始化启动入口。 | 
| APP_FEATURE_INIT(func) | 标识应用层功能的初始化启动入口。 | 


## 开发实例

  服务自动初始化宏使用实例：
  
```
void SystemServiceInit(void) {
    printf("Init System Service\n");
}
SYS_SERVICE_INIT(SystemServiceInit);

void SystemFeatureInit(void) {
    printf("Init System Feature\n");
}
SYS_FEATURE_INIT(SystemFeatureInit);

void AppServiceInit(void) {
    printf("Init App Service\n");
}
APP_SERVICE_INIT(AppServiceInit);

void AppFeatureInit(void) {
    printf("Init App Feature\n");
}
APP_FEATURE_INIT(AppFeatureInit);

// 日志打印顺序为：
// Init System Service
// Init System Feature
// Init App Service
// Init App Feature
```
