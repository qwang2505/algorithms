#include <iostream>
#include <vector>
#include <map>

using namespace std;

class BaseFeature
{
public:
    // all features' extract method must return int value.
    // for bool result, 0 as false, 1 as true.
    virtual double extract() = 0;
};

class IsValidFeature: public BaseFeature
{
public:
    virtual double extract(){ return 1; };
};

class LinkCountFeature: public BaseFeature
{
public:
    virtual double extract(){ return 9; };
};

typedef double (*feature_extractor)(int node);

void map_insert(map<int, feature_extractor>* features, int id, feature_extractor extractor)
{
    features->insert(map<int, feature_extractor>::value_type(id, extractor));
}

double is_valid(int node){
    return 0.0;
}

double link_count(int node){
    return 2.0;
}

int main(int argc, char** argv)
{
    // init features, register with name
    map<int, feature_extractor> features;
    map_insert(&features, 0, &is_valid);
    map_insert(&features, 1, &link_count);
    map<int, feature_extractor>::iterator iter = features.begin();
    cout << features.size() << endl;
    for (; iter != features.end(); iter++)
    {
        int feature_id = iter->first;
        cout << "id: " << feature_id << endl;
        double result = (iter->second)(1);
        cout << "result: " << result << endl;
    }
    // feature config, store in map
    // suppose we are in a classifier.
    // init features by name, well, some way.
    /*
    vector<BaseFeature*> features;
    features.push_back(new IsValidFeature());
    features.push_back(new LinkCountFeature());
    vector<BaseFeature*>::iterator iter = features.begin();
    // if classify while extract, we can do it.
    // extract features
    for (; iter != features.end(); iter++)
    {
        (*iter)->extract();
    }
    // classify
    // can't do it.
    cout << "test" << endl;
    */
}
