# soundPool    
音频池加载播放实例，音频池提供了系统声音的加载、播放、音量设置、循环设置、停止播放、资源卸载等功能。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## PlayParameters    
表示音频池播放参数设置。通过设置播放相关参数，来控制播放的音量，循环次数，播放优先级等参数。  
 **系统能力:**  SystemCapability.Multimedia.Media.SoundPool    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.Media.SoundPool    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| parallelPlayFlag | boolean | false | false | 是否和其它正在播放的音频并行播放的标识，true:不抢占音频焦点和其它正在播放的音频并行播放，false:抢占焦点打断其它正在播放的音频。<br/>此接口为系统接口。 |  
