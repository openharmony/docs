## 开发指导
1. 获取流管理器。

    const audioStreamManager = audio.getStreamManager();
    
2. 获取当前音频渲染器流信息。

```
audioStreamManager.getCurrentAudioRendererInfoArray(async (err, AudioRendererChangeInfoArray) => {
    console.info('[GET_RENDERER_STATE_1_CALLBACK] **** Get Callback Called ****');
    if (err) {
        console.log('getCurrentAudioRendererInfoArray :ERROR: '+err.message);
        resultFlag = false;
    }
    else {
        if (AudioRendererChangeInfoArray !=null) {
            for (let i=0;i<AudioRendererChangeInfoArray.length;i++) {
                AudioRendererChangeInfo = AudioRendererChangeInfoArray[i];
                console.info('StreamId for '+i+' is:'+AudioRendererChangeInfo.streamId);
                console.info('ClientUid for '+i+' is:'+AudioRendererChangeInfo.clientUid);
                console.info('Content '+i+' is:'+AudioRendererChangeInfo.rendererInfo.content);
                console.info('Stream'+i+' is:'+AudioRendererChangeInfo.rendererInfo.usage);
                console.info('Flag'+i+' is:'+AudioRendererChangeInfo.rendererInfo.rendererFlags); 
                console.info('State for '+i+' is:'+AudioRendererChangeInfo.rendererState);

                var devDescriptor = AudioRendererChangeInfo.deviceDescriptors;
                for (let j=0;j<AudioRendererChangeInfo.deviceDescriptors.length; j++) {
                    console.info('Id:'+i+':'+AudioRendererChangeInfo.deviceDescriptors[j].id);
                    console.info('Type:'+i+':'+AudioRendererChangeInfo.deviceDescriptors[j].deviceType);
                    console.info('Role:'+i+':'+AudioRendererChangeInfo.deviceDescriptors[j].deviceRole);
                    console.info('Name:'+i+':'+AudioRendererChangeInfo.deviceDescriptors[j].name);
                    console.info('Address:'+i+':'+AudioRendererChangeInfo.deviceDescriptors[j].address);
                    console.info('SampleRates:'+i+':'+AudioRendererChangeInfo.deviceDescriptors[j].sampleRates[0]);
                    console.info('ChannelCount'+i+':'+AudioRendererChangeInfo.deviceDescriptors[j].channelCounts[0]);
                    console.info('ChannelMask:'+i+':'+AudioRendererChangeInfo.deviceDescriptors[j].channelMasks);
                }
            }
        }
    }
});
```