# 创建ServiceAbility
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @xialiangwei-->
<!--SE: @jsjzju-->
<!--TSE: @lixueqing513-->


1. 创建ServiceAbility。

    通过DevEco Studio开发平台创建ServiceAbility时，DevEco Studio会默认生成onStart、onStop、onCommand方法，其他方法需要开发者自行实现，接口说明参见前述章节。开发者也可以添加其他Ability请求与ServiceAbility交互时的处理方法，示例如下：

    ```ts
    import { Want } from '@kit.AbilityKit';
    import { rpc } from '@kit.IPCKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    const TAG: string = '[Sample_FAModelAbilityDevelop]';
    const domain: number = 0xFF00;

    class FirstServiceAbilityStub extends rpc.RemoteObject {
      constructor(des: Object) {
        if (typeof des === 'string') {
          super(des);
        } else {
          return;
        }
      }

      onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean {
        hilog.info(domain, TAG, 'ServiceAbility onRemoteRequest called');
        if (code === 1) {
          let string = data.readString();
          hilog.info(domain, TAG, `ServiceAbility string=${string}`);
          let result = Array.from(string).sort().join('');
          hilog.info(domain, TAG, `ServiceAbility result=${result}`);
          reply.writeString(result);
        } else {
          hilog.info(domain, TAG, 'ServiceAbility unknown request code');
        }
        return true;
      }
    }

    class ServiceAbility {
      onStart(): void {
        hilog.info(domain, TAG, 'ServiceAbility onStart');
      }

      onStop(): void {
        hilog.info(domain, TAG, 'ServiceAbility onStop');
      }

      onCommand(want: Want, startId: number): void {
        hilog.info(domain, TAG, 'ServiceAbility onCommand');
      }

      onConnect(want: Want): rpc.RemoteObject {
        hilog.info(domain, TAG, 'ServiceAbility onDisconnect' + want);
        return new FirstServiceAbilityStub('test');
      }

      onDisconnect(want: Want): void {
        hilog.info(domain, TAG, 'ServiceAbility onDisconnect' + want);
      }
    }

    export default new ServiceAbility();
    ```

2. 注册ServiceAbility。
   
    ServiceAbility需要在应用配置文件config.json中进行注册，注册类型type需要设置为service。"visible"属性表示ServiceAbility是否可以被其他应用调用，true表示可以被其他应用调用，false表示不能被其他应用调用（仅应用内可以调用）。若ServiceAbility需要被其他应用调用，注册ServiceAbility时需要设置"visible"为true，同时需要设置支持关联启动。ServiceAbility的启动规则详见[组件启动规则](component-startup-rules.md)章节。
    
    ```json
    {
      ...
      "module": {
        ...
        "abilities": [
          ...
          {
            "name": ".ServiceAbility",
            "srcLanguage": "ets",
            "srcPath": "ServiceAbility",
            "icon": "$media:icon",
            "description": "$string:ServiceAbility_desc",
            "type": "service",
            "visible": true
          },
          ...
        ]
        ...
      }
    }
    ```

