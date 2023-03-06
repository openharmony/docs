# 资源调度子系统ChangeLog

## cl.resourceschedule.workScheduler 
修改parameters属性值的数据类型，不允许使用any类型，支持number、string、boolean三种类型。

**变更影响**

基于OpenHarmony3.2.10.7及之后的SDK版本开发的应用，parameters属性值的数据类型不允许使用any类型，仅支持number、string、boolean三种类型，否则将编译报错。

**关键接口/组件变更**

@ohos.resourceschedule.workScheduler.d.ts中的parameters属性变更。

| 类名 | 接口类型 | 变更前声明 | 变更后声明 | 
|  -- | -- | -- | -- |
| workScheduler.WorkInfo | field | parameters?: {[key: string]: any} | parameters?: {[key: string]: number | string | boolean} | 


**适配指导**<br>

parameters属性使用{[key: string]: number | string | boolean}数据类型。