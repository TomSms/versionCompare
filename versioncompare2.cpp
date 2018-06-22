#include "versioncompare2.h"
#include<iostream>
VersionCompare2::VersionCompare2()
{

}

int  isSameType(const std::string &v1,const std::string &v2){
    int type1 = VersionCompare2::getType(v1[0]);
    int type2 = VersionCompare2::getType(v2[0]);

    if( type1 == type2 ) return 1;
    if(type1 == 4 ) return -1;
    if(type2 == 4) return 1;
    return -3;
}

int compareString(const std::string &v1,const std::string &v2){
    int len1 = v1.size();
    int len2 = v2.size();
    int len = len1 > len2 ? len2 : len1;
    if(len1 == len2){
        for(int i = 0;i< len;i++){
            if(v1[i] > v2[i]){
                return 1;
            }
            if(v1[i] < v2[i]){
                return -1;
            }
            continue;
        }
    }
    if(len1 > len2) return 1;
    if(len1 < len2) return -1;
    return 0;
}
int VersionCompare2::compare(const std::string &v1,const std::string &v2){
    if(!isValidVersion(v1) || !isValidVersion(v2)){
        return -2;
    }
    std::vector<std::string> vv1,vv2;
    splitVersionInVector(v1,vv1);
    splitVersionInVector(v2,vv2);




    int len1 = vv1.size();
    int len2 = vv2.size();
    int ret = 0;
    int len = len1 > len2 ? len2 : len1;
    int n1,n2;

    for(int i = 0;i< len;i++){
        ret = isSameType(vv1[i],vv2[i]);
        if(ret != 1) return ret;
        if(getType(vv1[i][0]) == 3) {
            n1 = atoi(vv1[i].c_str());
            n2 = atoi(vv2[i].c_str());
            if(n1 > n2){
                return 1;
            }
            if(n2 > n1){
                return -1;
            }
            continue;
        }
        ret = compareString(vv1[i],vv2[i]);
        if(ret != 0){
            return ret;
        }
    }
    if(len1 > len2) return 1;
    if(len1 < len2) return -1;
    return 0;
}

int VersionCompare2::getType(char c){
    if(isupper(c)){
        return 1;
    }
    if(islower(c)){
        return 2;
    }
    if(isdigit(c)){
        return 3;
    }
    if(c == '.')
        return 4;
    return 5;
}

bool VersionCompare2::isValidVersion(const std::string &v){
    const char* p = v.c_str();
    if(*p =='.') return false;
    /* valid version only . 0~9 a~z A~Z */
    while(*p!='\0'){
        if((*p)=='.'){
            p++;
            continue;
        }
        if(isdigit(*p)){/*0~9*/
            p++;
            continue;
        }
        if(isupper(*p)){ /*A~Z*/
            p++;
            continue;
        }
        if(islower(*p)){/**/
            p++;
            continue;
        }
        return false;
    }
    return true;
}

void VersionCompare2::splitVersionInVector(const std::string &v,std::vector<std::string> &vv){
    int len = v.size();
    int otype = 0,ntype = 0;
    ntype = otype = getType(v[0]);
    int start = 0;
    int end = 0;
    for(int i =0;i<len;i++){
        ntype = getType(v[i]);
        if(otype != ntype){
            end = i;
            otype = ntype;

            vv.push_back(v.substr(start,end-start));
            start = i;
            end = 0;
        }
    }
    vv.push_back(v.substr(start,len));
}

char* getRestult(int i){
    if(i  == 1) return ">";
    if(i == 0) return "=";
    if(i == -1) return "<";
    if(i == -2) return "invalid version compare";
    if(i == -3) return "two format version compare";
}
