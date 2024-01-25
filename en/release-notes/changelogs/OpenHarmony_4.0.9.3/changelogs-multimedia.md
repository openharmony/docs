# Multimedia Subsystem Changelog

## cl.multimedia.1 Deleted content from getAudioEffectInfoArray

The input parameter **content** is deleted from **getAudioEffectInfoArray**.

**Change Impact**

Third-party applications that use the involved JavaScript APIs may have compatibility issues.

**Key API/Component Changes**

Before change:

 ```js
getAudioEffectInfoArray(content: ContentType, usage: StreamUsage, callback: AsyncCallback<AudioEffectInfoArray>): void;
getAudioEffectInfoArray(content: ContentType, usage: StreamUsage): Promise<AudioEffectInfoArray>;
 ```

After change:

 ```js
getAudioEffectInfoArray(usage: StreamUsage, callback: AsyncCallback<AudioEffectInfoArray>): void;
getAudioEffectInfoArray(usage: StreamUsage): Promise<AudioEffectInfoArray>;
 ```

**Adaptation Guide**

When calling this API, pass in only the input parameter **usage**. If **getAudioEffectInfoArray** is used in your application code, delete the **content** parameter.
