# IPC通信鉴权开发指导<a name="ZH-CN_TOPIC_0000001058671861"></a>


## 场景介绍<a name="section18502174174019"></a>

系统服务通过IPC跨进程方式开放的接口，需要对接口调用者进行鉴权操作。在Samgr中注册的系统服务，可以通过进程间通信的方式暴露接口给其他进程访问，同时需要配置相应的访问策略，当其他进程访问这些接口时，将会触发IPC通信鉴权机制校验访问进程是否拥有权限访问该接口，若无权限，则访问会被拒绝。

当开发一个系统服务时，如果需要对外开放某些接口，开发者可以通过IPC通信鉴权组件配置这些接口的访问策略。当其他服务通过IPC方式访问这些接口时，会触发Samgr服务调用IPC通信鉴权组件的接口检查调用者服务是否有权限调用该接口。

## 接口说明<a name="section1633115419401"></a>

IPC通信鉴权提供的API，仅供Samgr调用，开发者在开发服务时需要配置对应的访问策略，Samgr会调用如下接口获取和检查调用者是否具有正确的访问权限，提供的API列表如下。

**表 1**  IPC通信鉴权API接口功能介绍

<a name="table10494122145517"></a>
<table><thead align="left"><tr id="row1494152195511"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p14941221135515"><a name="p14941221135515"></a><a name="p14941221135515"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p8494172116555"><a name="p8494172116555"></a><a name="p8494172116555"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1849482118555"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1414381815720"><a name="p1414381815720"></a><a name="p1414381815720"></a>int GetCommunicationStrategy(RegParams params, PolicyTrans **policies, unsigned int *policyNum)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p749582195510"><a name="p749582195510"></a><a name="p749582195510"></a>服务注册过程中查询调用接口对应的访问策略，仅供Samgr调用</p>
</td>
</tr>
<tr id="row8495521115517"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p966319247576"><a name="p966319247576"></a><a name="p966319247576"></a>int IsCommunicationAllowed(AuthParams params)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p134951921115511"><a name="p134951921115511"></a><a name="p134951921115511"></a>检查访问主体进程是否有权限调用受访客体进程的接口，仅供Samgr调用</p>
</td>
</tr>
</tbody>
</table>

## 开发步骤<a name="section022611498210"></a>

本部分以BMS服务通过IPC通信方式对外开放接口为例，讲解如何通过IPC通信鉴权组件配置对应接口的访问策略。这里BMS在Samgr中注册的service为bundlems，为开放的接口注册的Feature为BmsFeature。

1.  OpenHarmony侧在源码路径下的头文件base/security/permission/services/permission\_lite/ipc\_auth/include/policy\_preset.h中配置相应的访问策略，产品侧独有的在vendor/hisilicon/产品名称/hals/security/permission\_lite/ipc\_auth/include/policy\_preset\_product.h中配置相应的访问策略，配置策略后将头文件中的宏POLICY\_PRODUCT 配置为1；访问策略主要有三种类型：

    （1）type为RANGE类型：允许某个特定范围UID的进程访问，需要指定uidMin和uidMax；

    （2）type为FIXED类型：允许指定的几个UID的进程访问，需要指定fixedUid，最多配置8个；

    （3）type为BUNDLENAME类型：只允许特定的应用访问，需要指定bundleName（包名）；

    ```
    FeaturePolicy bmsFeature[] = {
        {
            "BmsFeature",
            {
                {
                    .type=FIXED,    // 允许指定UID的进程访问的方式 
                    .fixedUid={2, 3, 8}
                },
                {
                    .type=RANGE,    // 允许特定范围内的UID的进程访问的方式 
                    .uidMin=100,
                    .uidMax=__INT_MAX__,
                },
            }
        },
        {
            "BmsInnerFeature",
            {
                {
                    .type=FIXED,     // 允许指定UID的进程访问的方式 
                    .fixedUid={2, 3, 8}
                },
                {
                    .type=RANGE,
                    .uidMin=100,
                    .uidMax=999,
                },
            }
        },
    };
    ```

2.  将步骤1中定义的Feature的策略加配到全局策略中，需要配置feature数量；

    ```
    static PolicySetting g_presetPolicies[] = {
        {"permissionms", pmsFeature, 1},
        {"abilityms", amsFeature, 2},
        {"bundlems", bmsFeature, 2},  // 步骤1定义的BMS的feature，数量为2 
        {"dtbschedsrv", dmsFeature, 1},
        {"samgr", samgrFeature, 1},
        {"appspawn", appspawnFeature, 1},
        {"WMS", wmsFeature, 1},
        {"bundle_daemon", bdsFeature, 1},
    };
    ```

3.  将步骤1中定义的BmsFeature注册到Samgr；

    ```
    const char BMS_SERVICE[] = "bundlems";
    const char BMS_FEATURE[] = "BmsFeature";
    static void Init()
    {
        SamgrLite *sm = SAMGR_GetInstance();
        if (sm == nullptr) {
            return;
        }
        // 注册服务到Samgr
        sm->RegisterFeature(BMS_SERVICE, reinterpret_cast<Feature *>(BundleMsFeature::GetInstance()));
        sm->RegisterFeatureApi(BMS_SERVICE, BMS_FEATURE,
            GetBmsFeatureApi(reinterpret_cast<Feature *>(BundleMsFeature::GetInstance())));
        HILOG_DEBUG(HILOG_MODULE_APP, "BundleMS feature start success");
    }
    APP_FEATURE_INIT(Init);
    ```


完成以上开发步骤后，开发者在Samgr注册服务时，Samgr会调用IPC通信鉴权组件的GetCommunicationStrategy接口获取服务的访问策略；当其他服务或应用通过IPC方式访问这些服务时，Samgr会调用IPC通信鉴权组件的IsCommunicationAllowed接口检查调用者服务的权限，如果满足访问策略，则可以访问开发者接口，否则拒绝访问。

## 常见问题<a name="section15729104510271"></a>

-   开发新服务后，在Samgr注册失败问题

    **现象描述**

    开发完新服务后，在启动时出现服务在Samgr注册失败问题。

    **可能原因**

    服务注册过程中，Samgr需要从IPC通信鉴权模块获取该服务的访问策略，但是未在该模块配置该服务的UID。

    **解决办法**

    在base/security/permission/services/permission\_lite/ipc\_auth/src/ipc\_auth\_impl.c中配置有效的服务的UID。


