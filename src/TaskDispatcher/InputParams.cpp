#include "TaskDispatcher/InputParams.h"

InputParams::InputParams(boost::program_options::variables_map&& vm) {
	parseInputParams(std::move(vm));
}

namespace {
void setBoolParamIfAvailable(const std::string& key, bool& field, const boost::program_options::variables_map& vm) {
	if (vm.count(key)) {
		field = true;
	}
}
} // namespace

void InputParams::parseInputParams(boost::program_options::variables_map&& vm) {
	if (vm.count("gpu")) {
		processingMode = ProcessingMode::GPU;
	}

	if (vm.count("trilinear")) {
		interpolationMethod = InterpolationMethod::Trilinear;
	}
	else if (vm.count("nearest_value")) {
		interpolationMethod = InterpolationMethod::NearestValue;
	}

	setBoolParamIfAvailable("help", showHelp, vm);
	setBoolParamIfAvailable("force", forceOverwrite, vm);
	setParam("input", inputImgPath, vm);
	setParam("output", outputImgPath, vm);
	setParam("lut", inputLutPath, vm);
	setParam("strength", effectStrength, vm);
	setParam("threads", threads, vm);

	const auto verifyUnsignedInt = [](int value) {
		return value > 0;
	};

	setParam<int>("width", outputImageWidth, vm, verifyUnsignedInt);
	setParam<int>("height", outputImageHeight, vm, verifyUnsignedInt);
}

ProcessingMode InputParams::getProcessingMode() const {
	return processingMode;
}

bool InputParams::getShowHelp() const {
	return showHelp;
}

void InputParams::setShowHelp(bool value) {
	showHelp = value;
}

bool InputParams::getForceOverwrite() const {
	return forceOverwrite;
}

void InputParams::setForceOverwrite(bool value) {
	forceOverwrite = value;
}

std::string InputParams::getInputImgPath() const {
	return inputImgPath;
}

void InputParams::setInputImgPath(const std::string& inputPath) {
	inputImgPath = inputPath;
}

std::string InputParams::getOutputImgPath() const {
	return outputImgPath;
}

std::string InputParams::getInputLutPath() const {
	return inputLutPath;
}

void InputParams::setInputLutPath(const std::string& lutPath) {
	inputLutPath = lutPath;
}

float InputParams::getEffectStrength() const {
	return effectStrength;
}

unsigned int InputParams::getThreads() const {
	return threads;
}

InterpolationMethod InputParams::getInterpolationMethod() const {
	return interpolationMethod;
}

int InputParams::getOutputImageWidth() const {
	return outputImageWidth;
}

void InputParams::setOutputImageWidth(unsigned int width) {
	outputImageWidth = width;
}

int InputParams::getOutputImageHeight() const {
	return outputImageHeight;
}

void InputParams::setOutputImageHeight(unsigned int height) {
	outputImageHeight = height;
}
