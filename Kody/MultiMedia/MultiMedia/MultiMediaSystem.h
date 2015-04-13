#pragma once

#include "DataProducer.h"
#include "DataProcessor.h"
#include "DataConsumer.h"
#include "FeatureExtractor.h"
#include "Classifier.h"
#include "Effector.h"

class MultiMediaSystem
{
public:
	MultiMediaSystem(DataProducer* dataProducer, DataProcessor* dataProcessor,
		DataConsumer* dataConsumer, FeatureExtractor* featureExtractor, 
		Classifier* classifier, Effector* effector);
	~MultiMediaSystem();
	void init();
	void run();
	void done();
private:
	DataProducer* dataProducer;
	DataProcessor* dataProcessor;
	DataConsumer* dataConsumer;
	FeatureExtractor* featureExtractor;
	Classifier* classifier;
	Effector* effector;
};

