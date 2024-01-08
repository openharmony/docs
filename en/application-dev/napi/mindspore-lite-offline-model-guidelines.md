# Using MindSpore Lite for Offline Model Conversion and Inference

## Basic Concepts

- MindSpore Lite: a built-in AI inference engine of OpenHarmony that provides inference deployment for deep learning models.

- Neural Network Runtime (NNRt): a bridge that connects the upper-layer AI inference framework to the bottom-layer acceleration chip to implement cross-chip inference and computing of AI models.

- Offline model: a model obtained using the offline model conversion tool of the AI hardware vendor. The hardware vendor is responsible for parsing and inference of offline models.

## When to Use

The common process for MindSpore Lite AI model deployment is as follows:
- Use the MindSpore Lite model conversion tool to convert third-party models (such as ONNX and CAFFE) to `.ms` models.
- Call APIs of the MindSpore Lite inference engine to perform model inference. By specifying NNRt as the inference device, you can then use the AI hardware in the system to accelerate inference.

When MindSpore Lite + NNRt inference is used, dynamic image composition in the initial phase will introduce a certain model loading delay.

If you want to reduce the loading delay to meet the requirements of the deployment scenario, you can use offline model-based inference as an alternative. The operation procedure is as follows:
- Use the offline model conversion tool provided by the AI hardware vendor to compile an offline model in advance.
- Use the MindSpore Lite conversion tool to encapsulate the offline model as a black box into the `.ms` model.
- Pass the `.ms` model to MindSpore Lite for inference.

During inference, MindSpore Lite directly sends the offline model to the AI hardware connected to NNRt. This way, the model can be loaded without the need for online image composition, greatly reducing the model loading delay. In addition, MindSpore Lite can provide additional hardware-specific information to assist the AI hardware in model inference.

The following sections describe the offline model inference and conversion process in detail.

## Constraints

- Offline model inference can only be implemented at the NNRt backend. The AI hardware needs to connect to NNRt and support offline model inference.

## Offline Model Conversion


### 1. Building the MindSpore Lite Release Package

Obtain the [MindSpore Lite source code](https://gitee.com/openharmony/third_party_mindspore). The source code is managed in "compressed package + patch" mode. Run the following commands to decompress the source code package and install the patch:
```bash
cd mindspore
python3 build_helper.py --in_zip_path=./mindspore-v1.8.1.zip --patch_dir=./patches/ --out_src_path=./mindspore-src
```
If the command execution is successful, the complete MindSpore Lite source code is generated in `mindspore-src/source/`.

Run the following commands to start building:
```bash
cd mindspore-src/source/
bash build.sh -I x86_64 -j 8
```

After the building is complete, you can obtain the MindSpore Lite release package from the `output/` directory in the root directory of the source code.


### 2. Writing Extended Configuration File of the Conversion Tool

The offline model comes as a black box and cannot be parsed by the conversion tool to obtain its input and output tensor information. Therefore, you need to manually configure the tensor information in the extended configuration file of the conversion tool. Based on the extended configuration, the conversion tool can then generate the `.ms` model file for encapsulating the offline model.

An example of the extended configuration is as follows:
- `[third_party_model]` in the first line is a fixed keyword that indicates the section of offline model configuration.
- The following lines exhibit the name, data type, shape, and memory format of the input and output tensors of the model respectively. Each field occupies a line and is expressed in the key-value pair format. The sequence of fields is not limited.
- Among the fields, data type and shape are mandatory, and other parameters are optional.
- Extended parameters are also provided. They are used to encapsulate custom configuration of the offline model into an `.ms` file in the the key-value pair format. The `.ms` file is passed to the AI hardware by NNRt during inference.

```text
[third_party_model]
input_names=in_0;in_1
input_dtypes=float32;float32
input_shapes=8,256,256;8,256,256,3
input_formats=NCHW;NCHW
output_names=out_0
output_dtypes=float32
output_shapes=8,64
output_formats=NCHW
extended_parameters=key_foo:value_foo;key_bar:value_bar
```

The related fields are described as follows:

- `input_names` (optional): model input name, which is in the string format. If multiple names are specified, use a semicolon (`;`) to separate them.
- `input_dtypes` (mandatory): model input data type, which is in the type format. If multiple data types are specified, use a semicolon (`;`) to separate them.
- `input_shapes` (mandatory): model input shape, which is in the integer array format. If multiple input shapes are specified, use a semicolon (`;`) to separate them.
- `input_formats` (optional): model input memory format, which is in the string format. If multiple formats are specified, use a semicolon (`;`) to separate them. The default value is `NHWC`.
- `output_names` (optional): model output name, which is in the string format. If multiple names are specified, use a semicolon (`;`) to separate them.
- `output_dtypes` (mandatory): model output data type, which is in the type format. If multiple data types are specified, use a semicolon (`;`) to separate them.
- `output_shapes` (mandatory): model output shape, which is in the integer array format. If multiple output shapes are specified, use a semicolon (`;`) to separate them.
- `output_formats` (optional): model output memory format, which is in the string format. If multiple formats are specified, use a semicolon (`;`) to separate them. The default value is `NHWC`.
- `extended_parameters` (optional): custom configuration of the inference hardware, which is in the key-value pair format. It is passed to the AI hardware through the NNRt backend during inference.

### 3. Converting an Offline Model

Decompress the MindSpore Lite release package obtained in step 1. Go to the directory where the conversion tool is located (that is, `tools/converter/converter/`), and run the following commands:

```bash
export LD_LIBRARY_PATH=${PWD}/../lib
./converter_lite --fmk=THIRDPARTY --modelFile=/path/to/your_model --configFile=/path/to/your_config --outputFile=/path/to/output_model
```
The offline model conversion is complete.

The related parameters are described as follows:
- `--fmk`: original format of the input model. `THIRDPARTY` indicates an offline model.
- `--modelFile`: path of the input model.
- `--configFile`: path of the extended configuration file. The file is used to configure offline model information.
- `--outputFile`: path of the output model. You do not need to add the file name extension. The `.ms` suffix is generated automatically.

> **NOTE**
> 
> If `fmk` is set to `THIRDPARTY`, offline model conversion is performed. In this case, only the preceding four parameters and the extended configuration file take effect.

## Offline Model Inference

Offline model inference is the same as common MindSpore Lite model inference except that only NNRt devices can be added to the inference context.

For details about the MindSpore Lite model inference process, see [Using MindSpore Lite for Model Inference](./mindspore-lite-guidelines.md).
