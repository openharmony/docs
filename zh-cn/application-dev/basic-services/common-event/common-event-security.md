# 公共事件安全注意事项

- **公共事件发布方**：如果不加限制，任何应用都可以订阅公共事件并读取相关信息，应避免在公共事件中携带敏感信息。采用以下方式，可以限制公共事件接收方的范围。
  - 通过[CommonEventPublishData](../../reference/apis-basic-services-kit/js-apis-inner-commonEvent-commonEventPublishData.md)中的subscriberPermissions参数指定订阅者所需权限。
  - 通过[CommonEventPublishData](../../reference/apis-basic-services-kit/js-apis-inner-commonEvent-commonEventPublishData.md)中的bundleName参数指定订阅者的包名。
- **公共事件订阅方**：订阅自定义公共事件后，任意应用都可以向订阅者发送潜在的恶意公共事件。采用以下方式，可以限制公共事件发布方的范围。
  - 通过[CommonEventSubscribeInfo](../../reference/apis-basic-services-kit/js-apis-inner-commonEvent-commonEventSubscribeInfo.md)中的publisherPermission参数指定发布者所需权限。
  - 通过[CommonEventSubscribeInfo](../../reference/apis-basic-services-kit/js-apis-inner-commonEvent-commonEventSubscribeInfo.md)中的publisherBundleName参数参数指定发布者的包名。
- 自定义公共事件名称应确保全局唯一，否则可能与其他公共事件冲突。