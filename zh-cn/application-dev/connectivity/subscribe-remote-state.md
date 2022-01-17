# 远端状态订阅开发实例

IPC/RPC 提供对远端 Stub对象状态的订阅机制， 在远端 Stub对象死亡时，可触发死亡通知告诉本地 Proxy对象。这种状态通知订阅并不会自动附加在每个本地 Proxy对象上，需要调用特定接口完成，当不再需要订阅时也需要调用特定接口取消。使用这种订阅机制的用户，需要实现死亡通知接口DeathRecipient并实现onRemoteDied方法，清理资源，该方法会在 远端 Stub对象所在进程死亡，或所在设备离开组网时被回调。值得注意的是，调用这些接口有一定的顺序。首先，需要 Proxy订阅 Stub死亡通知，若在订阅期间Stub状态正常，则可在不再需要时取消订阅；若在订阅期间 Stub所在进程退出，或者所在设备退出组网，则会自动触发 Proxy自定义的后续操作。




**Native侧接口**


依次为添加对远端Stub对象状态订阅的接口，取消订阅的接口，及感知到远端Stub对象死亡而进行本地操作的接口：


```
bool AddDeathRecipient(const sptr<DeathRecipient> &recipient);
bool RemoveDeathRecipient(const sptr<DeathRecipient> &recipient);
void OnRemoteDied(const wptr<IRemoteObject> &object);
```


参考代码


```
class TestDeathRecipient : public IRemoteObject::DeathRecipient {
public:
    virtual void OnRemoteDied(const wptr<IRemoteObject>& remoteObject);
}
sptr<IRemoteObject::DeathRecipient> deathRecipient (new TestDeathRecipient());// 构造一个死亡通知对象
bool result = proxy->AddDeathRecipient(deathRecipient); // 注册死亡通知
result = proxy->RemoveDeathRecipient(deathRecipient); // 移除死亡通知
```
