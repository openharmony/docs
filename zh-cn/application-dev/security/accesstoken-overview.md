# 访问控制开发指南

## 功能简介
ATM(AccessTokenManager)是OpenHarmony上基于AccessToken构建的统一的应用权限管理能力。

当前，ATM模块对三方应用提供了权限校验功能，三方应用可以检查当前访问者是否具有所需的权限。


## 基本概念

当前，ATM提供的应用权限校验功能是基于统一管理的TokenID(Token identity)。

- TokenID：32bits的设备内唯一标识符，用于标识每个应用的Accestoken信息。
- Accestoken信息：主要包括应用身份标识APPID、用户ID、应用分身索引、应用APL(Ability Privilege Level)、应用权限信息等。

## 约束与限制

 - 三方应用不允许自定义权限，系统权限定义信息详见[权限定义信息](https://gitee.com/openharmony/resources/blob/master/systemres/main/config.json)