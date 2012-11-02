#ifndef _TRANSCODER_H
#define _TRANSCODER_H

#include "feature_repository.h"
#include "config.h"
#include "boolean_classifier.h"
#include "linear_classifier.h"

class Transcoder
{
public:
    Transcoder(const string config, IDomNodeVisitor* visitor);

    ~Transcoder();

    // just return boolean value.
    // transcode result will be apply on node.
    bool transcode(DomNodeKey node);

private:
    // visitor to visit dom node.
    IDomNodeVisitor* m_visitor;
    Config m_cfg;

    // classifiers
    BooleanClassifier m_valid_node_classifier;
    // TODO add list classifier
    BooleanClassifier m_reorder_parent_classifier;
    BooleanClassifier m_reorder_child_classifier;
    LinearClassifier m_reorder_rating_classifier;
    BooleanClassifier m_link_node_classifier;
    BooleanClassifier m_valid_link_classifier;

    // features
    map<int, double> m_features;
    // feature repository
    FeatureRepository* m_feature_repository;
};

#endif
