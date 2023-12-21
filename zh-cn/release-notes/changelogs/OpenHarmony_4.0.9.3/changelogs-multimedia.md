# multimedia子系统ChangeLog

## cl.multimedia.1 getAudioEffectInfoArray接口入参变更，删除Content type入参

对于getAudioEffectInfoArray，适配4.0.9.2修改，删除Content type入参。

**变更影响**

对于已发布的js接口，可能影响三方应用的兼容性。

**关键的接口/组件变更**

修改前的接口原型：

 ```js
getAudioEffectInfoArray(content: ContentType, usage: StreamUsage, callback: AsyncCallback<AudioEffectInfoArray>): void;
getAudioEffectInfoArray(content: ContentType, usage: StreamUsage): Promise<AudioEffectInfoArray>;
 ```

修改后的接口原型：

 ```js
getAudioEffectInfoArray(usage: StreamUsage, callback: AsyncCallback<AudioEffectInfoArray>): void;
getAudioEffectInfoArray(usage: StreamUsage): Promise<AudioEffectInfoArray>;
 ```

**适配指导**

修改后用户调用该接口时，只需要传入StreamUsage入参，对于已经适配的用户，直接删去ContentType type入参即可。