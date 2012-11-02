#ifndef _FEATURE_REPOSITORY_H
#define _FEATURE_REPOSITORY_H

#include <map>
#include <vector>
#include "config.h"

using namespace std;

class DomNode;
typedef DomNode* DomNodeKey;

class IDomNodeVisitor;


// feature extractor function pointer
typedef double (*FEATURE_EXTRACTOR_PTR)(const Config cfg, IDomNodeVisitor* visitor, DomNodeKey node);

class FeatureRepository
{
public:

    static FeatureRepository* get_instance();

    ~FeatureRepository();

    void init();

    bool load(char* name, FEATURE_EXTRACTOR_PTR extractor);

    map<int, FEATURE_EXTRACTOR_PTR> get_features();

    vector<char*> get_feature_names();

private:
    FeatureRepository();

    static FeatureRepository* m_instance;

    map<int, FEATURE_EXTRACTOR_PTR> m_features;
    vector<char*> m_names;
};


#endif
