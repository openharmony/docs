# 资源管理开发常见问题

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @liule_123-->
<!--Designer: @buda_wy-->
<!--Tester: @lpw_work-->
<!--Adviser: @Brilliantry_Rui-->

## 如何读取rawfile中的xml文件并转化为String类型(API 9)

**解决措施**

通过resourceManager的getRawFileContent接口获取xml数据，再通过String.fromCharCode将获取的数据转化为String类型。

**代码示例**

```
resourceManager.getRawFileContent('test.xml', (error, value) => {
  if (error != null) {
    console.log("error is " + error);
  } else {
    let rawFile = value;
    let xml = String.fromCharCode.apply(null, rawFile)
  }
});
```

**参考链接**

[资源管理](../reference/apis-localization-kit/js-apis-resource-manager.md)


## Stage模型下如何获取资源(API 9)

**解决措施**

Stage模型支持了通过context获取resourceManager对象的方式，再调用其内部获取资源的接口，无需再导入包。此方式不适用于FA模型。

**代码示例**

```
const context = getContext(this) as any
context 
  .resourceManager
  .getString($r('app.string.entry_desc').id)
  .then(value => {
    this.message = value.toString()
})
```


## 如何通过接口获取resource目录的路径(API 9)

**问题现象**

希望获取resource目录的路径，从而使用文件管理接口操作文件。

**解决措施**

由于应用以hap形式进行安装，安装完成后不会解压hap包，所以在程序运行时无法获取resource路径。

可以考虑如下两种方式获取资源文件：

1. 使用$r或者$rawfile访问。适合静态访问，程序运行时不改变资源路径。

2. 使用ResourceManage访问。适合动态访问，程序运行时可动态改变资源路径。

**参考链接**

[资源分类与访问](../quick-start/resource-categories-and-access.md)、[资源管理](../reference/apis-localization-kit/js-apis-resource-manager.md)


## 资源管理内的getPluralString方法获取value值有误(API 9)

**问题现象**

getPluralString接口获取value值有误，显示复数值（other）。

**解决措施**

getPluralString接口只支持英文系统，不支持中文。


## 如何获取resources目录中自定义的string字段(API 9)

**解决措施**

使用ResourceManager模块的getStringValue方法获取。

**参考链接**

[资源管理](../reference/apis-localization-kit/js-apis-resource-manager.md#getstringvalue9)


## AppScope中的资源如图片，文字等如何引用(API 9)

**解决措施**

通过$r('app.type.name')的形式来引用，type代表资源类型，如color，string，media等，name代表资源命名。


## Resource类型如何转为String(API 9)

**解决措施**

Resource为string支持限定词目录使用this.context.resourceManager.getStringSync($r('app.string.test').id)，可以同步转换，不支持$r('app.string.test', 2)方式。

**参考链接**

[ResourceManager\(资源管理\)](../reference/apis-localization-kit/js-apis-resource-manager.md#getstringsync9)


## form_config.json文件中是否可以使用$引用常量(API 9)

form_config.json文件中不支持使用$引用常量。


## ArkTS如何解析xml文件(API 9)

**解决措施**

1. 在rawfile目录下创建如下xml文件**。**

   ```
   <?xml version="1.0" encoding="utf-8"?>
   <user>
       <name>Jacky</name>
       <age>18</age>
   </user>
   ```

2. 使用resourceManager.getRawFileContent获取xml文件字节数组。

```
import resourceManager from '@ohos.resourceManager';
import xml from '@ohos.xml';
export default {
    onCreate() {
        resourceManager.getResourceManager((error, res) => {
            if (error != null) {
                console.log("error is " + error);
                return
            }
            res.getRawFileContent("test.xml", (error, value) => {
                if (error != null) {
                    console.log("error is " + error);
                    return
                }
                let arrayBuffer = value.buffer; // unit8Array
                var xmpParser = new xml.XmlPullParser(arrayBuffer);
                var tagName = ""
                //do something
                console.log("parse xml finished");
            })
        })
    }
};
```
