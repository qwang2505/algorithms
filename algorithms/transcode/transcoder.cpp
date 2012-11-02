
#include "transcoder.h"

Transcoder::Transcoder(const string config, IDomNodeVisitor* visitor)
{
    m_visitor = visitor;
    // init config
    m_cfg.Init(config.c_str());
    // init classifier
    // init features
}

Transcoder::~Transcoder()
{
    // delete classifiers.
}

bool Transcoder::transcode(DomNodeKey node)
{
    // transocde
}
