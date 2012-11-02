
#include <iostream>
#include "config.h"

using namespace std;

int main(int argc, char** argv)
{
    Config cfg;
    cfg.Init("../transcode/transcoder.ini");
    vector<string> list;
    cout << cfg.GetStringList("feature_extractor_parameters", "removed_words", list) << endl;
    cout << list.size() << endl;
}
