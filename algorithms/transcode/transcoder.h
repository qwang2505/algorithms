#ifndef _TRANSCODER_H
#define _TRANSCODER_H

#include "feature_repository.h"
#include "config.h"

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
};

#endif
