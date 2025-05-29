# FA模型应用程序包结构


基于[FA模型](application-configuration-file-overview-fa.md)开发的应用，其应用程序包结构如下图应用程序包结构（FA模型）所示。开发者需要熟悉应用程序包结构相关的基本概念。

>
> **说明：** API version 8及更早的版本支持的应用模型，FA模型已经不再主推。建议使用新的Stage模型进行开发。
>


FA模型与Stage模型的主要区别在于HAP内部文件的存放位置不同。FA模型中，所有资源文件、库文件和代码文件都存放在assets文件夹中，并在文件夹内部进一步区分。


- config.json是应用配置文件，DevEco Studio会自动生成部分模块代码，开发者按需修改其中的配置。详细字段请参见[应用配置文件](application-configuration-file-overview-fa.md#配置文件的内部结构)。

- assets是HAP所有的资源文件、库文件和代码文件的集合，内部可以分为entry和js文件夹。entry文件夹中存放的是resources目录和resources.index文件。

- resources目录用于存放应用的资源文件（字符串、图片等），便于开发者使用和维护，详见[资源文件的使用](resource-categories-and-access.md)。

- resources.index是资源索引表，由DevEco Studio调用SDK工具生成。

- js文件夹中存放的是编译后的代码文件。

- `pack.info` 是 Bundle 中用于描述每个 HAP 属性的文件，包含应用的 `bundleName` 和 `versionCode` 信息、模块的 `name`、`type` 和 `abilities` 等信息。该文件由 DevEco Studio 工具在构建 Bundle 包时自动生成。

**图1** 应用程序包结构（FA模型）  
![app-pack-fa](figures/app-pack-fa.png)