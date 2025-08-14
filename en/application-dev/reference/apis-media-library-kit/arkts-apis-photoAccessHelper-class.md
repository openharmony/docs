# Classes (Others)

<!--Kit: Media Library Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @xuchangda;@yixiaoff-->
<!--SE: @guxinggang;@liweilu1-->
<!--TSE: @wangbeibei;@xchaosioda-->

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## RecommendationOptions<sup>11+</sup>

Defines the image recommendation options. The image recommendation feature depends on the image data analysis capability, which varies with devices.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                   | Type               | Mandatory| Description                         |
| ----------------------- | ------------------- | ---- | -------------------------------- |
| recommendationType | [RecommendationType](arkts-apis-photoAccessHelper-e.md#recommendationtype11)   | No  | Type of the recommended image.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| textContextInfo<sup>12+</sup> | [TextContextInfo](arkts-apis-photoAccessHelper-i.md#textcontextinfo12)   | No  | Text based on which images are recommended. If both **recommendationType** and **textContextInfo** are set, **textContextInfo** takes precedence over **recommendationType**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

## BaseSelectOptions<sup>12+</sup>

Defines the basic options for selecting media assets from Gallery.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                   | Type               | Mandatory| Description                         |
| ----------------------- | ------------------- | ---- | -------------------------------- |
| MIMEType<sup>10+</sup>    | [PhotoViewMIMETypes](arkts-apis-photoAccessHelper-e.md#photoviewmimetypes)   | No  | Available media file types. **IMAGE_VIDEO_TYPE** is used by default.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| maxSelectNumber<sup>10+</sup>      | number | No  | Maximum number of media files that can be selected. The maximum value is **500**, and the default value is **50**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.  |
| isPhotoTakingSupported<sup>11+</sup> | boolean  | No  | Whether photo taking is supported. **true** if supported, **false** otherwise.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| isSearchSupported<sup>11+</sup> | boolean  | No  | Whether the image is searchable. **true** if searchable, **false** otherwise.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| recommendationOptions<sup>11+</sup>       | [RecommendationOptions](#recommendationoptions11)   | No  | Image recommendation parameters.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| preselectedUris<sup>11+</sup> | Array&lt;string&gt;  | No  | URI of the preselected image.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| isPreviewForSingleSelectionSupported<sup>(deprecated)</sup> | boolean  | No  | Whether to enable full image preview if a single image is selected. **true** to enable, **false** otherwise. The default value is **true**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>This API is supported since API version 12 and deprecated since API version 18.|
| singleSelectionMode<sup>18+</sup> | [SingleSelectionMode](arkts-apis-photoAccessHelper-e.md#singleselectionmode18) | No  | Single selection mode. The default value is **SingleSelectionMode.BROWSER_MODE**.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|
| mimeTypeFilter<sup>19+</sup> | [MimeTypeFilter](#mimetypefilter19)  | No  | Configuration for file type filtering. Multiple types can be specified.<br>When this parameter is set, the **MIMEType** configuration automatically becomes invalid.<br>When this parameter is set, only media files of the configured filter type are displayed. You are advised to notify users that only images or videos of the specified type can be selected.<br>**Atomic service API**: This API can be used in atomic services since API version 19.|
| fileSizeFilter<sup>19+</sup> | [FileSizeFilter](#filesizefilter19)  | No  | Configuration for file size filtering.<br>When this parameter is set, only media files within the specified size range are displayed. You are advised to notify users that only images or videos of the specified size can be selected.<br>**Atomic service API**: This API can be used in atomic services since API version 19.|
| videoDurationFilter<sup>19+</sup> | [VideoDurationFilter](#videodurationfilter19)  | No  | Configuration for video duration filtering.<br>When this parameter is set, only media files within the specified duration range are displayed. You are advised to notify users that only videos of the specified length can be selected.<br>**Atomic service API**: This API can be used in atomic services since API version 19.|

## PhotoSelectOptions

PhotoSelectOptions extends BaseSelectOptions

Defines additional options for selecting media assets from Gallery. It inherits from [BaseSelectOptions](#baseselectoptions12).

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                   | Type               | Mandatory| Description                         |
| ----------------------- | ------------------- | ---- | -------------------------------- |
| isEditSupported<sup>11+</sup>       | boolean | No  | Whether the image can be edited. **true** if editable, **false** otherwise.<br>**Atomic service API**: This API can be used in atomic services since API version 11.    |
| isOriginalSupported<sup>12+</sup>       | boolean | No  | Whether to display the button for selecting the original image. **true** to display, **false** otherwise. The default value is **true**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.    |
| subWindowName<sup>12+</sup>       | string | No  | Name of the child window.<br>**Atomic service API**: This API can be used in atomic services since API version 12.    |
| completeButtonText<sup>14+</sup>       | [CompleteButtonText](arkts-apis-photoAccessHelper-e.md#completebuttontext14) | No  | Text displayed on the complete button.<br>The complete button is located in the lower right corner of the page. It is used by users to signify that they have finished selecting images.<br>**Atomic service API**: This API can be used in atomic services since API version 14.    |

## PhotoSelectResult

Defines information about the images or videos selected.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                   | Type               | Readable| Writable| Description                          |
| ----------------------- | ------------------- | ---- | ---- | ------------------------------ |
| photoUris        | Array&lt;string&gt;    | Yes  | Yes  | URIs of the images or videos selected. The URI array can be used only by calling [photoAccessHelper.getAssets](arkts-apis-photoAccessHelper-PhotoAccessHelper.md#getassets) with temporary authorization. For details about how to use the media file URI, see [Using a Media File URI] (../../file-management/user-file-uri-intro.md#using-a-media-file-uri).|
| isOriginalPhoto        | boolean    | Yes  | Yes  | Whether the selected media asset is the original image. **true** if yes, **false** otherwise. The default value is **false**.|

## MimeTypeFilter<sup>19+</sup>

Describes the configuration for file type filtering.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                   | Type               | Mandatory| Description                          |
| ----------------------- | ------------------- | ---- | ------------------------------ |
| mimeTypeArray        | Array&lt;string&gt;    | Yes  | Types of media files that PhotoPicker allows users to filter by. Up to ten media file types can be specified for filtering.<br>The filter type is defined by the MIME type, for example, image/jpeg and video/mp4.|

## FileSizeFilter<sup>19+</sup>

Describes the configuration for file size filtering.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                   | Type               | Mandatory| Description                          |
| ----------------------- | ------------------- | ---- |------------------------------ |
| filterOperator        | [FilterOperator](arkts-apis-photoAccessHelper-e.md#filteroperator19)    | Yes | Filter operator.<br>For example, files can be filtered based on being greater than or less than a certain file size.|
| fileSize        | number    | Yes| File size used for filtering.<br>The unit is bytes.|
| extraFileSize   | number    | No| Maximum file size in **FilterOperator.BETWEEN** mode. The default value is **-1**.<br>The unit is bytes.|

## VideoDurationFilter<sup>19+</sup>

Describes the configuration for video duration filtering.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                   | Type               | Mandatory| Description                          |
| ----------------------- | ------------------- | ---- |------------------------------ |
| filterOperator        | [FilterOperator](arkts-apis-photoAccessHelper-e.md#filteroperator19)    | Yes |Filter operator.<br>For example, videos can be filtered based on being greater than or less than a certain duration.|
| videoDuration        | number    | Yes| Video duration used for filtering.<br>The unit is milliseconds (ms).|
| extraVideoDuration   | number    | No| Maximum video duration in **FilterOperator.BETWEEN** mode. The default value is **-1**.<br>The unit is milliseconds (ms).|

## RecentPhotoOptions<sup>20+</sup>

Represents the configuration options of the recent images or videos.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                   | Type                                                                                     | Mandatory | Description  |
|-------------------------|-----------------------------------------------------------------------------------------|-------|--------|
| period                  | number                                                                                  | No   | Time range for displaying the recent images or videos, measured in seconds. After setting, the system shows images or videos taken within the specified time from the current moment. The longest duration you can set is 1 day (86400s).<br>If the value is less than or equal to 0, greater than 86400, or not set, the system uses the longest duration (1 day) by default. If there are no images or videos within the set time range, the component does not show anything.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|
| MIMEType                | [photoAccessHelper.PhotoViewMIMETypes](arkts-apis-photoAccessHelper-e.md#photoviewmimetypes) | No   | Types of the file displayed. The default value is **PhotoViewMIMETypes.IMAGE_VIDEO_TYPE**.<br>**Atomic service API**: This API can be used in atomic services since API version 20.                        |
| photoSource             | [PhotoSource](arkts-apis-photoAccessHelper-e.md#photosource20)                                                             | No   | Source of the recent image or video, for example, photo or video taken by the camera or screenshot. By default, the source is not restricted.<br>**Atomic service API**: This API can be used in atomic services since API version 20.                              |

## RecentPhotoInfo<sup>20+</sup>

Describes the information about the recent image or video.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name        | Type    | Mandatory | Description                                                       |
|------------|--------|-------|-----------------------------------------------------------|
| dateTaken  | number | No   | Time when the recent image or video was shot (in milliseconds since January 1, 1970). The unit is ms.<br>**Atomic service API**: This API can be used in atomic services since API version 20.                    |
| identifier | string | No   | Hash value of the name of the recent image or video, which is used to help the application determine whether the image or video to be displayed is the same as the one displayed before.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|
