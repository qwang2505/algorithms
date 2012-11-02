
#define REGISTER_FEATURE(name) \
    FeatureRepository::get_instance()->load((char*)#name, &name);

// add parameters?
double in_whitelist(const Config cfg, IDomNodeVisitor* visitor, DomNodeKey node)
{
    return 0;
}

double not_in_blacklist(const Config cfg, IDomNodeVisitor* visitor, DomNodeKey node)
{
    return 0;
}

// load features in feature repository
bool load_features()
{
    REGISTER_FEATURE(in_whitelist);
    REGISTER_FEATURE(not_in_blacklist);
}
