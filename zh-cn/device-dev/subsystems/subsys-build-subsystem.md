# 子系统
### 子系统配置规则

通过build仓下的subsystem_config.json可以查看所有子系统的配置规则。

```json
{
  "arkui": {
    "path": "foundation/arkui",      # 路径
    "name": "arkui"                  # 子系统名
  },
  "ai": {
    "path": "foundation/ai",
    "name": "ai"
  },
  "account": {
    "path": "base/account",
    "name": "account"
  },
  "distributeddatamgr": {
    "path": "foundation/distributeddatamgr",
    "name": "distributeddatamgr"
  },
  "security": {
    "path": "base/security",
    "name": "security"
  },
  ...
}
```

子系统的配置规则主要是在build/subsystem_config.json中指定子系统的路径和子系统名称。
