# 配置数据和事件


卡片使用json文件配置卡片使用的变量和事件，变量的声明在data字段下，事件的声明在actions字段下。


示例：



```json
{
    "data": {
        "temperature": "35°C",
        "city": "hangzhou"
    },
    "actions": {
        "routerEventName": {
            "action": "router",
            "abilityName": "com.example.myapplication.FormAbility",
            "params": {
                "message": "weather",
                "temperature": "{{temperature}}"
            }
        },
        "messageEventName": {
            "action": "message",
            "params": {
                "message": "weather update"
            }
        }
    }
}
```
