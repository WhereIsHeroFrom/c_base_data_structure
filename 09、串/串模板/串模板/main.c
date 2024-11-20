#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main() {
    // 一、串的定义和初始化
    char str1[50] = "Hello, ";
    char str2[50] = "World!";
    char str3[50];

    // 二、获取串的长度
    int str1len = strlen(str1);
    int str2len = strlen(str2);
    printf("str1 的长度为：%d\n", str1len);
    printf("str2 的长度为：%d\n", str2len);

    // 三、串的索引
    for (int i = 0; i < str1len; ++i) {
        printf("第 %d 个字符是 %c\n", i, str1[i]);
    }

    // 四、串的赋值
    strcpy(str3, str1);
    printf("str3 赋值后的字符串: %s\n", str3);

    // 五、串的比较
    if (strcmp(str1, "Hello, ") == 0) {
        printf("字符串相等\n");
    }
    else {
        printf("字符串不相等\n");
    }

    // 六、串的拼接
    strcat(str3, str2);
    printf("拼接后的字符串：%s", str3);

    return 0;
}
