# 帐号子系统系统帐号模块ChangeLog

## cl.account_os_account.1.onAcquireInfo接口参数变更

**访问级别**

系统接口

**变更原因**

ArkTS语法不支持any类型，需将any类型变更为实际类型

**变更影响**

该变更为非兼容性变更。开发者未按变更后的原型定义接口时会存在编译问题。

**API Level**

8

**变更发生版本**

从Openharmony SDK OpenHarmony_4.1.6.2 开始

**变更的接口**

变更前：

```js
    interface IUserAuthCallback  {
        ...
        onAcquireInfo?: (module: number, acquire: number, extraInfo: any) => void;
        ...
    }

    interface IIdmCallback   {
        ...
        onAcquireInfo?: (module: number, acquire: number, extraInfo: any) => void;
        ...
    }
```

变更后：

```js
    interface IUserAuthCallback  {
        ...
        onAcquireInfo?: (module: number, acquire: number, extraInfo: Uint8Array) => void;
        ...
    }

    interface IIdmCallback   {
        ...
        onAcquireInfo?: (module: number, acquire: number, extraInfo: Uint8Array) => void;
        ...
    }
```

**适配指导**

应用按照变更后的接口原型定义onAcquireInfo回调