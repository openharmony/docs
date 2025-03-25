# HdfUserAuth (V1_1)


## 概述

提供用户认证驱动的标准API接口。

用户认证驱动为用户认证服务提供统一的访问接口。获取用户认证驱动代理后，用户认证服务可以调用相关接口注册执行器，管理用户认证凭据，完成PIN码和生物特征认证。

**起始版本：** 4.0


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [IUserAuthInterface.idl](_i_user_auth_interface_8idl_v11.md) | 声明用户认证驱动的API接口。接口可用于注册执行器，管理用户认证凭据，完成PIN码和生物特征认证。 | 
| [UserAuthTypes.idl](_user_auth_types_8idl_v11.md) | 定义用户认证驱动的枚举类和数据结构。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[IUserAuthInterface](interface_i_user_auth_interface_v11.md) | 声明用户认证驱动的API接口。 | 
| struct&nbsp;&nbsp;[ScheduleInfoV1_1](_schedule_info_v1__1_v11.md) | 调度信息。 | 
| struct&nbsp;&nbsp;[UserInfo](_user_info_v11.md) | 用户信息。 | 
