#include <stdio.h>
#include <math.h>

// 函数声明（可选）
double calculateSeries(double x, double threshold, int* termCount);

int main() {
	double x;
	double sum;
	int termCount = 0;
	double threshold = 0.00001;

	// 输入部分
	while (1) {
		printf("请输入一个正实数x: ");
		if (scanf_s("%lf", &x) != 1) {
			printf("输入无效，请输入一个数字。\n");
			while (getchar() != '\n'); // 清除输入缓冲区
			continue;
		}
		if (x <= 0) {
			printf("x必须是一个正实数，请重新输入。\n");
			continue;
		}
		break;
	}

	// 级数求和
	sum = calculateSeries(x, threshold, &termCount);

	// 输出结果
	printf("\n级数的和为: %.10f\n", sum);
	printf("共计算了 %d 项。\n", termCount);

	return 0;
}

// 计算级数的函数
double calculateSeries(double x, double threshold, int* termCount) {
	double sum = 1.0;       // 累加和，初始为1（对应x^0 / 0!）
	double term = 1.0;      // 当前项的值，初始为1（对应x^0 / 0!）
	int n = 1;              // 当前项的指数

	while (1) {
		term *= x / n;      // 计算下一项：term = term * x / n
		if (fabs(term) < threshold) {
			break;
		}
		sum += term;
		printf("第 %d 项: %.10f，当前和: %.10f\n", n, term, sum);
		n++;
	}

	*termCount = n - 1; // 已添加的项数
	return sum;
}