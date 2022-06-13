# video

The **\<video>** component provides a video player.

> ![img](https://gitee.com/openharmony/docs/raw/OpenHarmony-3.1-Release/en/application-dev/public_sys-resources/icon-note.gif) **NOTE:**
>
> - Configure the following information in the **config.json** file:
>
> ```
> "configChanges": ["orientation"]
> ```

## Required Permissions

## Child Component

Not supported

## Attributes

In addition to the attributes in [Universal Attributes](js-components-common-attributes.md), the following attributes are supported.



| Name     | Type    | Default Value | Mandatory | Description                                                  |
| -------- | ------- | ------------- | --------- | ------------------------------------------------------------ |
| muted    | boolean | false         | No        | Whether a video is muted.                                    |
| src      | string  | -             | No        | Path of the video content to play.                           |
| autoplay | boolean | false         | No        | Whether a video is played automatically after being rendered. |
| controls | boolean | true          | No        | Whether the control bar is displayed during video playback. If the value is set to **false**, the control bar is not displayed. The default value is **true**, indicating that the platform can either show or hide the control bar. |

## Styles

In addition to the styles in [Universal Styles](js-components-common-styles.md), the following styles are supported.



| Name       | Type   | Default Value | Mandatory | Description                                                  |
| ---------- | ------ | ------------- | --------- | ------------------------------------------------------------ |
| object-fit | string | contain       | No        | Scaling type of the video source. If **poster** has been assigned a value, this configuration will affect the scaling type of the video poster. For details about available values, see [Table 1](js-components-media-video.md). |

**Table 1** object-fit description



| Type | Description                                                  |
| ---- | ------------------------------------------------------------ |
| fill | The video content is resized to fill the display area and its aspect ratio is not retained. |

## Events

In addition to the events in [Universal Events](js-components-common-events.md), the following events are supported.



| Name       | Parameter              | Description                                                  |
| ---------- | ---------------------- | ------------------------------------------------------------ |
| prepared   | { duration: value }5+  | Triggered when the video preparation is complete. The video duration (in seconds) is obtained from **duration**. |
| start      | -                      | Triggered when a video is played.                            |
| pause      | -                      | Triggered when a video is paused.                            |
| finish     | -                      | Triggered when the video playback is finished.               |
| error      | -                      | Triggered when the playback fails.                           |
| seeking    | { currenttime: value } | Triggered to report the time (in seconds) when the progress bar is being dragged. |
| seeked     | { currenttime: value } | Triggered to report the playback time (in seconds) when the user finishes dragging the progress bar. |
| timeupdate | { currenttime: value } | Triggered once per 250 ms when the playback progress changes. The unit of the current playback time is second. |

## Methods

In addition to the methods in [Universal Methods](js-components-common-methods.md), the following methods are supported.



| Name           | Type                   | Description                                   |
| -------------- | ---------------------- | --------------------------------------------- |
| start          | -                      | Starts playing a video.                       |
| pause          | -                      | Pauses a video.                               |
| setCurrentTime | { currenttime: value } | Sets the video playback position, in seconds. |

> ![img](https://gitee.com/openharmony/docs/raw/OpenHarmony-3.1-Release/en/application-dev/public_sys-resources/icon-note.gif) **NOTE:** The methods in the above table can be called after the **attached** callback is invoked.