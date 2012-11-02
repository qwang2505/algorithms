
#include "transcoder.h"

Transcoder::Transcoder(const string config, IDomNodeVisitor* visitor)
{
    m_visitor = visitor;
    // init config
    m_cfg.Init(config.c_str());
    // init features, load feature extractors, etc.
    m_feature_repository = FeatureRepository::get_instance();

    // init classifiers, pass expression and feature names.
}

Transcoder::~Transcoder()
{
    // delete classifiers.
}

bool Transcoder::transcode(DomNodeKey node)
{
    // transocde
}
