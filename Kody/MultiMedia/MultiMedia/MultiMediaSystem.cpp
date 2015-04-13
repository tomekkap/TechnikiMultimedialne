#include "MultiMediaSystem.h"

MultiMediaSystem::MultiMediaSystem(DataProducer* dataProducer, DataProcessor* dataProcessor,
		DataConsumer* dataConsumer, FeatureExtractor* featureExtractor, 
		Classifier* classifier, Effector* effector)
{
	this->dataProducer = dataProducer;
	this->dataProcessor = dataProcessor;
	this->dataConsumer = dataConsumer;
	this->featureExtractor = featureExtractor;
	this->classifier = classifier;
	this->effector = effector;
}

MultiMediaSystem::~MultiMediaSystem()
{
	if(dataProducer)
		delete dataProducer;
	if(dataProcessor)
		delete dataProcessor;
	if(dataConsumer)
		delete dataConsumer;
	if(featureExtractor)
		delete featureExtractor;
	if(classifier)
		delete classifier;
	if(effector)
		delete effector;
}

void MultiMediaSystem::init()
{
	dataProducer->init();
	dataProcessor->init();
	dataConsumer->init();
	featureExtractor->init();
	classifier->init();
	effector->init();
}

void MultiMediaSystem::run()
{
	while(dataProducer->dataAvailable())
	{
		RawData* rawData = dataProducer->getData();
		ProcessedData* processedData = dataProcessor->processData(rawData);
		dataConsumer->setData(processedData);
		FeatureVector* featureVector = featureExtractor->extractFeature(processedData);
		Result* result = classifier->classify(featureVector);
		effector->apply(result);
	}
}

void MultiMediaSystem::done()
{
	dataProducer->done();
	dataProcessor->done();
	dataConsumer->done();
	featureExtractor->done();
	classifier->done();
	effector->done();
}