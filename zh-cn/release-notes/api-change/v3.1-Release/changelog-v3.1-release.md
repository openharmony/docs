# 3.1 release相对于3.1 beta变更详细说明

### 针对color.json中颜色值，增加合法性校验

针对color.json中颜色值，增加合法性校验，其校验规则如下：

- 使用十六进制颜色码，格式如下：
    - #rgb：red(0-f) green(0-f) blue(0-f)
    - #argb：transparency(0-f) red(0-f) green(0-f) blue(0-f)
    - #rrggbb： red(00-ff) green(00-ff) blue(00-ff)
    - #aarrggbb： transparency(00-ff) red(00-ff) green(00-ff) blue(00-ff)
- 使用$引用应用中已定义的资源，格式如下：
    - $color:xxx

**变更影响**

不符合上述校验规则，将在编译时报错。

**关键的接口/组件变更**

无