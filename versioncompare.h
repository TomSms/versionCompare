#ifndef VERSIONCOMPARE_H
#define VERSIONCOMPARE_H

#include<string.h>
#include<ctype.h>
#include<stdio.h>
class VersionCompare
{
public:
    VersionCompare();
public:
    /****
     * @params:
     * version1： 版本1
     * version2： 版本2
     * @return:
     * 0 version1 = version2
     * 1 version1 > version2
     * -1 version2 < version1
     * -2 two error version compare
     * -3 verion is invalid
     */
    static int versionCompare(const char *version1,const char * version2){
        // 1. 判断version 是否非法
        if(!isValidVersion(version1) || !isValidVersion(version2)){
            //error handle
            return -3;
        }
        //version compare
        int len1 = strlen(version1);
        int len2 = strlen(version2);
        int min = len1 > len2 ? len2: len1;
        int dis = 0;
        for(int i =0; i<min; i++){
            if(isSameV(version1[i],version2[i])){
                dis = version1[i]-version2[i];
                if(dis >0){
                    return 1;
                }
                if(dis < 0){
                    return -1;
                }
                if(dis == 0) continue;/*do nothings continue*/
            }else{
                /*error two verison compare*/
                return -2;
            }
        }
        if(len1 > len2) return 1;
        else if(len1 < len2) return -1;
        else return 0;
    }
    /*
     * @params:
     * version: 版本
     * @return
     * less than 0: invalid version
     * more than 0 or equal 0 : valid version
     * */
    static int isValidVersion(const char *version){
        char* p = const_cast<char*>(version);
        if(*p =='.') return -1;
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
            return 0;
        }
        return 1;
    }

    static int isSameV(char a,char b){
        if(isdigit(a)&&isdigit(b)){
            return 1;
        }
        if(islower(a)&&islower(b)){
            return 1;
        }
        if(isupper(a)&&isupper(b)){
            return 1;
        }
        if(a == b && a == '.'){
            return 1;
        }
        return 0;
    }
};

#endif // VERSIONCOMPARE_H
