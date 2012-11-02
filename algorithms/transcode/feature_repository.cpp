

#include <iostream>
#include "feature_repository.h"
#include "features.h"

FeatureRepository* FeatureRepository::m_instance = NULL;

void feature_insert(map<int, FEATURE_EXTRACTOR_PTR>* features, int id, FEATURE_EXTRACTOR_PTR extractor)
{
    features->insert(map<int, FEATURE_EXTRACTOR_PTR>::value_type(id, extractor));
}

FeatureRepository::FeatureRepository()
{
}

void FeatureRepository::init()
{
    load_features();
}

FeatureRepository* FeatureRepository::get_instance()
{
    if (m_instance == NULL)
    {
        m_instance = new FeatureRepository();
    }
    return m_instance;
}

FeatureRepository::~FeatureRepository()
{
    m_features.clear();
    m_names.clear();
}

bool FeatureRepository::load(char* name, FEATURE_EXTRACTOR_PTR extractor)
{
    // get feature id, just use map size before insert.
    int feature_id = m_features.size();
    // insert <id, extractor> pair into map.
    feature_insert(&m_features, feature_id, extractor);
    // insert name
    m_names.push_back(name);
    return true;
}

map<int, FEATURE_EXTRACTOR_PTR> FeatureRepository::get_features()
{
    return m_features;
}

vector<char*> FeatureRepository::get_feature_names()
{
    return m_names;
}
