scanf 使用 %s 读取字符串时，会在遇到空白字符（如空格、换行符）时停止，因此无法读取包含空格的字符串。
不需要对数组名使用 & 运算符，因为数组名本身就是指针。
优缺点
优点：

简单、方便，适合读取格式化的数据。
支持多种数据类型和复杂的格式。
缺点：

容易导致缓冲区溢出，特别是读取字符串时未限制输入长度。
当输入格式不匹配时，可能导致意想不到的行为，如残留字符留在输入缓冲区。
不适合读取包含空格的字符串。
2. fgets
功能与用法
fgets 用于从指定的输入流中读取一行字符串，包括空格和其他空白字符，直到遇到换行符、文件结束符或达到指定的字符数限制。

#include <stdio.h>
#include <string.h>

int main() {
    char buffer[100];

    printf("请输入一行文本：");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        // 去除换行符
        buffer[strcspn(buffer, "\n")] = '\0';
        printf("您输入的是：%s\n", buffer);
    } else {
        printf("读取输入时发生错误。\n");
    }

    return 0;
}

fgets 会读取包括换行符在内的所有字符，直到达到 n-1 个字符或遇到换行符。
使用 strcspn 去除末尾的换行符，避免影响后续处理。
  优点：

可以读取包含空格的字符串。
允许指定最大读取长度，防止缓冲区溢出。
适合读取整行输入，便于后续处理。
缺点：

会保留换行符，需要手动去除。
相对于 scanf，读取格式化数据稍显繁琐，需要结合 sscanf 等函数处理。

getchar 是一个简单的函数，用于从标准输入（通常是键盘）读取下一个可用字符。每次调用 getchar 会返回输入流中的一个字符。
#include <stdio.h>

int main() {
    int c;

    printf("请输入文本（按 Ctrl+D 结束）：\n");
    while ((c = getchar()) != EOF) {
        putchar(c); // 将读取的字符输出
    }

    printf("\n输入结束。\n");
    return 0;
}

#include <stdio.h>

int main() {
    int c;

    printf("请输入一个字符：");
    c = getchar();

    printf("您输入的字符是：%c\n", c);
    return 0;
}

适合读取单个字符输入。
注意，输入缓冲区中的换行符 \n 也会被读取，可能需要额外处理。

使用 scanf：

当需要读取格式化的数据，如多个整数、浮点数等。
确保使用适当的格式说明符和缓冲区大小，避免缓冲区溢出。
注意 scanf 可能留下换行符或其他字符在输入缓冲区中，影响后续输入。
使用 fgets：

当需要读取包含空格的整行输入时。
需要限制输入长度，防止缓冲区溢出。
适合读取文件中的行数据。
使用 getchar：

当需要逐个字符处理输入时，如实现字符计数、密码输入隐藏等功能。
简单的字符读取，不适合复杂输入处理。



