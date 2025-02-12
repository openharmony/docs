# 基础类型定义

## 概述

>**说明：**
>
>本模块首批接口从API version 7开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。

**起始版本：** 7

## Resource

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

资源引用类型，用于设置组件属性的值。

可以通过`$r`或者`$rawfile`创建Resource类型对象，不可以修改Resource中的各属性的值。

- `$r('belonging.type.name')`

  belonging：系统资源或者应用资源，相应的取值为'sys'和'app'；

  type：资源类型，支持'boolean'、'color'、'float'、'intarray'、'integer'、'pattern'、'plural'、'strarray'、'string'、'media'；

  name：资源名称，在资源定义时确定。

- `$rawfile('filename')`

  filename：工程中resources/rawfile目录下的文件名称。

  **说明：** 在引用资源类型时，注意其数据类型要与属性方法本身的类型一致，例如某个属性方法支持设置string | Resource，那么在使用Resource引用类型时，其数据类型也应当为string。

## Length

长度类型，用于描述尺寸单位。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

| 类型                    | 说明                                     |
| --------------------- | -------------------------------------- |
| string                | 需要显式指定，如'10px'，也可设置百分比字符串，如'100%'。<br/>**说明：** <br/>不指定像素单位时，默认单位vp，如'10'，等同于10。 |
| number                | 默认单位vp。                                |
| [Resource空格替换#resource) | 资源引用类型，引入系统资源或者应用资源中的尺寸。