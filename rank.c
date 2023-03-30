#include <stdio.h>

int main(void) {
	char name[4][10];
	double mark[8], score[4], sum, avg, max, min;
	int i, ch, name_strlen, j, max_sub, min_sub, one, two, three, A, B, C;

	for (i = 1; i <= 3; i++) {
		name_strlen = sum = avg = max = 0;
		min = 100;

		printf("请输入第%d位参赛选手的姓名：", i);
		while ((ch = getchar()) != EOF) {
			if (ch == '\n')
				break;
			name[i][name_strlen] = ch;
			name_strlen++;
		}
		name[i][name_strlen] = '\0';	//如果没有加上这个标志，输出字符串时就会继续向后读取，直到遇到'\0'为止

		printf("请输入7个评委对%s的评分<No.%d>\n", name[i], i);
		for (j = 1; j <= 7; j++)
			scanf_s("%lf", &mark[j]);
		for (j = 1; j <= 7; j++) {
			if (mark[j] > max) {
				max = mark[j];
				max_sub = j;		//改变最大最小值，储存下标
			}

			if (mark[j] < min) {
				min = mark[j];
				min_sub = j;
			}
		}
		printf("第%d位的最高分：%0.2lf\n", i, mark[max_sub]);
		printf("第%d位的最低分：%0.2lf\n", i, mark[min_sub]);
		mark[max_sub] = 0;	//去掉最高最低分
		mark[min_sub] = 0;
		for (j = 1; j <= 7; j++)
			sum += mark[j];
		avg = sum / 5;
		score[i] = avg;
		printf("第%d位参赛选手的最后得分：%0.2lf\n\n", i, score[i]);

		while ((ch = getchar()) != '\n' && ch != EOF);		//清空回车和其它字符，让下次循环的getchar正常获取字符
	}

	A = (score[1] > score[2]) + (score[1] > score[3]);
	if (A == 2)
		one = 1;
	else if (A == 1)
		two = 1;
	else if (A == 0)
		three = 1;

	B = (score[2] > score[1]) + (score[2] > score[3]);
	if (B == 2)
		one = 2;
	else if (B== 1)
		two = 2;
	else if (B == 0)
		three = 2;

	C = (score[3] > score[1]) + (score[3] > score[2]);
	if (C == 2)
		one = 3;
	else if (C == 1)
		two = 3;
	else if (C == 0)
		three = 3;

	printf("参赛选手的排名：\n");
	printf("第一名：%s %0.2lf\n", name[one], score[one]);
	printf("第二名：%s %0.2lf\n", name[two], score[two]);
	printf("第三名：%s %0.2lf", name[three], score[three]);

	return 0;
}