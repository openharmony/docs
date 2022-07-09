# 远端状态订阅开发实例

IPC/RPC提供对远端Stub对象状态的订阅机制， 在远端Stub对象死亡时，可触发死亡通知告诉本地Proxy对象。这种状态通知订阅需要调用特定接口完成，当不再需要订阅时也需要调用特定接口取消。使用这种订阅机制的用户，需要实现死亡通知接口DeathRecipient并实现onRemoteDied方法清理资源。该方法会在远端Stub对象所在进程死亡或所在设备离开组网时被回调。值得注意的是，调用这些接口有一定的顺序。首先，需要Proxy订阅Stub死亡通知，若在订阅期间Stub状态正常，则在不再需要时取消订阅；若在订阅期间Stub所在进程退出或者所在设备退出组网，则会自动触发Proxy自定义的后续操作。




## Native侧接口

| 接口名 | 功能描述 |
| -------- | -------- |
| AddDeathRecipient(const sptr\<DeathRecipient> &recipient); | 订阅远端Stub对象状态。 |
| RemoveDeathRecipient(const sptr\<DeathRecipient> &recipient); | 取消订阅远端Stub对象状态。 |
| OnRemoteDied(const wptr\<IRemoteObject> &object); | 当远端Stub对象死亡时回调。 |


## 参考代码


```
class TestDeathRecipient : public IRemoteObject::DeathRecipient {
public:
    virtual void OnRemoteDied(const wptr<IRemoteObject>& remoteObject);
}
sptr<IRemoteObject::DeathRecipient> deathRecipient (new TestDeathRecipient());// 构造一个死亡通知对象
bool result = proxy->AddDeathRecipient(deathRecipient); // 注册死亡通知
result = proxy->RemoveDeathRecipient(deathRecipient); // 移除死亡通知
```
