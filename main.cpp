#include <iostream>
#include "versioncompare.h"
#include "versioncompare2.h"
using namespace std;


int main()
{
    cout << "Hello World!" << endl;
    /*
    std::cout << "version:1.2.3\t version 1.2.3  \t"   << "compare result:" << VersionCompare::versionCompare("1.2.3","1.2.3") << std::endl;
    std::cout << "version:1.2.3\t version 1.2.3a \t"  << "compare result:" << VersionCompare::versionCompare("1.2.3","1.2.3a")<< std::endl;
    std::cout << "version:1.2.3b\t version 1.2.3a \t" << "compare result:" << VersionCompare::versionCompare("1.2.3b","1.2.3a")<< std::endl;
    std::cout << "version:1.2.a\t version: 1.2.3 \t"  << "compare result:" << VersionCompare::versionCompare("1.2.a","1.2.3")<< std::endl;
    std::cout << "version:1.2.3\t version: 1.2.3a\t" << "compare result:" << VersionCompare::versionCompare("1.2.3","1.2.3a")<< std::endl;
    std::cout << "version:[d]\t version: 1.2.3  \t"    << "compare result:" << VersionCompare::versionCompare("[d]","1.2.3")<< std::endl;
    std::cout << "version:1.2.3\t version: 1.12.3  \t"    << "compare result:" << VersionCompare::versionCompare("1.2.3","1.12.3")<< std::endl;

    VersionCompare2::compare("1.2.3","1.12.3.4");
    VersionCompare2::compare("1.2.3","1.1a2.3.4");
    std::string v("hello world");
    std::cout << v.substr(0,1) <<endl;
    */

    std::cout << "version:1.2.3\t version 1.2.3  \t"   << "compare result:" << VersionCompare2::compare("1.2.3","1.2.3") << std::endl;
    std::cout << "version:1.2.3\t version 1.2.3a \t"  << "compare result:" << VersionCompare2::compare("1.2.3","1.2.3a")<< std::endl;
    std::cout << "version:1.2.3b\t version 1.2.3a \t" << "compare result:" << VersionCompare2::compare("1.2.3b","1.2.3a")<< std::endl;
    std::cout << "version:1.2.a\t version: 1.2.3 \t"  << "compare result:" << VersionCompare2::compare("1.2.a","1.2.3")<< std::endl;
    std::cout << "version:1.2.3\t version: 1.2.3a\t" << "compare result:" << VersionCompare2::compare("1.2.3","1.2.3a")<< std::endl;
    std::cout << "version:[d]\t version: 1.2.3  \t"    << "compare result:" << VersionCompare2::compare("[d]","1.2.3")<< std::endl;
    std::cout << "version:1.2.3\t version: 1.12.3  \t"    << "compare result:" << VersionCompare2::compare("1.2.3","1.12.3")<< std::endl;

    std::cout << "version:1.a12b.3\t version: 1.a123b.3  \t"    << "compare result:" << VersionCompare2::compare("1.a12b.3","1.a123b.3")<< std::endl;
    std::cout << "version:1.ab1b.3\t version: 1.a123b.3  \t"    << "compare result:" << VersionCompare2::compare("1.ab1b.3","1.a123b.3")<< std::endl;
    return 0;
}
