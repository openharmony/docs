# 实现一个划词应用（仅对系统应用开放）

<!--Kit: Basic Services Kit-->
<!--Subsystem: SelectionInput-->
<!--Owner: @no86-->
<!--Designer: @mmwwbb-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @fang-jinxu-->

## 接口说明

请参考[selectionInput.SelectionManager](../../reference/apis-basic-services-kit/js-apis-selectionInput-selectionManager-sys.md)文档获取接口详情。

| 名称 | 描述 |
| ---- | ---- |
| on(type: 'selectionCompleted', callback: Callback\<SelectionInfo\>): void | 订阅划词完成事件，使用`callback`回调函数。 |
| createPanel(ctx: Context, info: PanelInfo): Promise\<Panel\> | 创建划词面板。 |
| show(): Promise\<void\> | 显示面板。 |

## 开发步骤

1. 创建划词应用工程。

    1. 在DevEco Studio工程Module对应的ets目录下，右键选择“New > Directory”，新建一个目录，并命名为ServiceExtAbility。

    2. 在目录pages下，从菜单栏创建两个page文件MainPanel.ets和MenuPanel.ets。在ServiceExtAbility目录下，右键选择“New > File”，新建SelectionExtensionAbility.ts。目录如下：

    ```
    /src/main/
    ├── ets/
    │   ├── pages
    │   |   ├── MainPanel.ets                    # 主面板
    │   |   └── MenuPanel.ets                    # 菜单面板
    |   └── ServiceExtAbility
    │       └── SelectionExtensionAbility.ts     # 划词扩展类
    ├── resources/base/profile/main_pages.json
    ├── module.json5                             # 配置文件
    ```

    ![划词应用工程](figures/selection-application-project.png)

2. 继承[SelectionExtensionAbility](../../reference/apis-basic-services-kit/js-apis-selectionInput-selectionExtensionAbility-sys.md)，实现扩展生命周期函数。
    ```ts
    import { selectionManager, PanelInfo, PanelType, SelectionExtensionAbility, BusinessError } from '@kit.BasicServicesKit';
    import { Want } from '@kit.AbilityKit';
    import { rpc } from '@kit.IPCKit';

    class SelectionAbilityStub extends rpc.RemoteObject {
      constructor(des) {
        if (typeof des === 'string') {
          super(des);
        } else {
          return null;
        }
      }

      onRemoteMessageRequest(
        code: number,
        data: rpc.MessageSequence,
        reply: rpc.MessageSequence,
        options: rpc.MessageOption
      ): boolean | Promise<boolean> {
        return true;
      }
    }

    class ServiceExtAbility extends SelectionExtensionAbility {
      panel_: selectionManager.Panel = undefined;

      onConnect(want: Want): rpc.RemoteObject {
        // 当SelectionExtensionAbility实例完成创建时，系统会触发该回调。开发者可在该回调中执行初始化逻辑（如定义变量、加载资源、监听划词事件等）。
        return new SelectionAbilityStub('remote');
      }

      onDisconnect(): void {
        // 当SelectionExtensionAbility实例被销毁（例如用户关闭划词开关或切换划词应用）时，系统触发该回调。开发者可以在该生命周期中执行资源清理、数据保存等相关操作。
      }
    }
    ```
    上述代码中，划词扩展被拉起时会触发[onConnect](../../reference/apis-basic-services-kit/js-apis-selectionInput-selectionExtensionAbility-sys.md#onconnect)回调，可以在该回调中监听划词事件，完成划词窗口的创建、窗口内容设定、窗口的移动、窗口的显示和隐藏等操作；当划词扩展退出时会触发[onDisconnect](../../reference/apis-basic-services-kit/js-apis-selectionInput-selectionExtensionAbility-sys.md#ondisconnect)回调，可以在该回调中完成窗口销毁的操作。部分操作可参见下面3、4、5步。

3. 在划词扩展被拉起时，使用划词Ability接口监听划词事件。
    ```ts
    selectionManager.on('selectionCompleted', (info: selectionManager.SelectionInfo) => {
    });
    ```

4. 在划词扩展被拉起时，使用划词Ability接口创建划词窗口。
    ```ts
    let panelInfo: PanelInfo = {
      panelType: PanelType.MENU_PANEL,
      x: 0,
      y: 0,
      width: 500,
      height: 200
    }
    selectionManager.createPanel(this.context, panelInfo)
      .then(async (panel: selectionManager.Panel) => {
        panel.setUiContent('pages/MenuPanel')
          .then(()=>{
          })
          .catch((error: BusinessError) => {
          });
        this.panel_ = panel;
      })
      .catch((error: BusinessError) => {
      });
    ```
5. 在划词任务结束时，使用划词Ability接口销毁划词窗口。
    ```ts
    selectionManager.destroyPanel(this.panel_);
    ```

6. 配置`module.json5`文件。

    在`extensionAbilities`字段中配置划词扩展类文件路径。

    ```json
    {
      "module": {
      // ...
        "extensionAbilities": [
          {
            "name": "SelectionExtensionAbility",
            "srcEntry": "./ets/ServiceExtAbility/SelectionExtensionAbility.ts",
            "type": "selection",
            "exported": false,
          }
        ]
      }
    }
    ```

## 调测验证

1. 设置系统参数以配置划词。

    1. 打开划词开关。
    2. 选择当前应用为划词应用。
    3. 设置划词触发方式。

2. 通过日志观察划词服务拉起SelectionExtensionAbility过程。

    使用DevEco Studio的Hilog窗口查看日志。

3. 使用鼠标左键单击选中文本，观察应用界面弹出划词窗口。
