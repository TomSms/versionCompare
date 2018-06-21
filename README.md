# versionCompare
版本比较

两个版本进行比较时需要考虑较多的因素

下面是我们程序的运行结果

```
version:1.2.3	 version 1.2.3  	compare result:0
version:1.2.3	 version 1.2.3a 	compare result:-1
version:1.2.3b	 version 1.2.3a 	compare result:1
version:1.2.a	 version: 1.2.3 	compare result:-3
version:1.2.3	 version: 1.2.3a	compare result:-1
version:[d]	 version: 1.2.3  	compare result:-2
version:1.2.3	 version: 1.12.3  	compare result:-1
version:1.a12b.3	 version: 1.a123b.3  	compare result:-1
version:1.ab1b.3	 version: 1.a123b.3  	compare result:1
```

/*比较版本大小的思路*/
1. split 
将对应的字符串风分割开，相同类型的字符作为同一个字符串
如 1.1.1 分割为 1 . 1 . 1 
如 1.11.1 分割为 1 . 11 . 1
如 1.a11ab.1 分割为 1 . a 11 ab . 1
2. 将分割开的字符串进行比较
比较分为字符串的比较和数字的比较
1 11 比较
a ab 比较
3. 根据比较的结果返回对应的比较结果

考虑上方的异常情况

