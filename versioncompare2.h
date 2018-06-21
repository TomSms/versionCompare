#ifndef VERSIONCOMPARE2_H
#define VERSIONCOMPARE2_H

#include<string>
#include<vector>

class VersionCompare2
{
public:
    VersionCompare2();

    static int compare(const std::string &v1,const std::string &v2);

    static int getType(char c);

    static bool isValidVersion(const std::string &v);

    static void splitVersionInVector(const std::string &v,std::vector<std::string> &vv);

};

#endif // VERSIONCOMPARE2_H
