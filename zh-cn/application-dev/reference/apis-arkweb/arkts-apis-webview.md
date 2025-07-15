# 模块描述

@ohos.web.webview提供web控制能力，[Web](arkts-basic-components-web.md)组件提供网页显示的能力。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 示例效果请以真机运行为准，当前DevEco Studio预览器不支持。
>
> - 静态方法必须在用户界面（UI）线程上使用。

## 需要权限

访问在线网页时需添加网络权限：ohos.permission.INTERNET，具体申请方式请参考[声明权限](../../security/AccessToken/declare-permissions.md)。

## 导入模块

```ts
import { webview } from '@kit.ArkWeb';
```

**系统能力：** SystemCapability.Web.Webview.Core