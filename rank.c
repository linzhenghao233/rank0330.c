#include <stdio.h>

int main(void) {
	char name[4][10];
	double mark[8], score[4], sum, avg, max, min;
	int i, ch, name_strlen, j, max_sub, min_sub, one, two, three, A, B, C;

	for (i = 1; i <= 3; i++) {
		name_strlen = sum = avg = max = 0;
		min = 100;

		printf("�������%dλ����ѡ�ֵ�������", i);
		while ((ch = getchar()) != EOF) {
			if (ch == '\n')
				break;
			name[i][name_strlen] = ch;
			name_strlen++;
		}
		name[i][name_strlen] = '\0';	//���û�м��������־������ַ���ʱ�ͻ��������ȡ��ֱ������'\0'Ϊֹ

		printf("������7����ί��%s������<No.%d>\n", name[i], i);
		for (j = 1; j <= 7; j++)
			scanf_s("%lf", &mark[j]);
		for (j = 1; j <= 7; j++) {
			if (mark[j] > max) {
				max = mark[j];
				max_sub = j;		//�ı������Сֵ�������±�
			}

			if (mark[j] < min) {
				min = mark[j];
				min_sub = j;
			}
		}
		printf("��%dλ����߷֣�%0.2lf\n", i, mark[max_sub]);
		printf("��%dλ����ͷ֣�%0.2lf\n", i, mark[min_sub]);
		mark[max_sub] = 0;	//ȥ�������ͷ�
		mark[min_sub] = 0;
		for (j = 1; j <= 7; j++)
			sum += mark[j];
		avg = sum / 5;
		score[i] = avg;
		printf("��%dλ����ѡ�ֵ����÷֣�%0.2lf\n\n", i, score[i]);

		while ((ch = getchar()) != '\n' && ch != EOF);		//��ջس��������ַ������´�ѭ����getchar������ȡ�ַ�
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

	printf("����ѡ�ֵ�������\n");
	printf("��һ����%s %0.2lf\n", name[one], score[one]);
	printf("�ڶ�����%s %0.2lf\n", name[two], score[two]);
	printf("��������%s %0.2lf", name[three], score[three]);

	return 0;
}