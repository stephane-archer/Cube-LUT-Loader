#include "TaskDispatcher/InputParams.h"
#include <string>

InputParams::InputParams(ProcessingMode processMode, unsigned int threadsNum, InterpolationMethod interpolation,
						 const std::string& inputPath, const std::string& outputPath, bool force,
						 const std::string& lut, float strength, int width, int height)
	: processingMode(processMode), threads(threadsNum), interpolationMethod(interpolation), inputImgPath(inputPath),
	  outputImgPath(outputPath), forceOverwrite(force), inputLutPath(lut), outputImageWidth(width),
	  outputImageHeight(height) {
	effectStrength = strength / 100.0f;
}

ProcessingMode InputParams::getProcessingMode() const {
	return processingMode;
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

void InputParams::setOutputImageWidth(int width) {
	outputImageWidth = width;
}

int InputParams::getOutputImageHeight() const {
	return outputImageHeight;
}

void InputParams::setOutputImageHeight(int height) {
	outputImageHeight = height;
}

ProcessingMode flagsToProcessingMode(bool gpu) {
	return gpu ? ProcessingMode::GPU : ProcessingMode::CPU;
}

InterpolationMethod flagsToInterpolationMethod(bool trilinear, bool nearestValue) {
	if (!trilinear && nearestValue) {
		return InterpolationMethod::NearestValue;
	}
	return InterpolationMethod::Trilinear;
}
