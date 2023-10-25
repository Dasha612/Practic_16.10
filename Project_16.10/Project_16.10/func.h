#pragma once
#include <stdio.h>

#include <stdlib.h>


void z1() {
	int arr[14];
	int count = 0, sum = 0;
	for (int i = 0; i < 14; i++) {
		scanf_s("%d", &arr[i]);
	}

	for (int j = 0; j < 14; j++) {
		if (arr[j] > 0 && arr[j] % 2 == 0) {
			count++;
			sum += arr[j];
		}
	}
	printf("Всего %d эл-ов. Их сумма равна %d\n", count, sum);
}

void z2() {
	int arr[17];
	int count = 0, sum = 0;
	for (int i = 0; i < 17; i++) {
		scanf_s("%d", &arr[i]);
	}
	for (int i = 0; i < 17; i++)
		if (arr[i] % 2 != 0)
			sum += arr[i];

	for (int i = 0; i < 17; i++) {
		if (arr[i] % 3 == 0) {
			arr[i] = sum;
		}
	}
	for (int i = 0; i < 17; i++)
		printf("%d \n", arr[i]);
}
int comp(const void* i, const void* j) {
	if (*(float*)i < *(float*)j) return -1;
	if (*(float*)i > *(float*)j) return 1;
	return 0;
}

int comp_n(const void* i, const void* j) {
	if (*(float*)i > *(float*)j) return -1;
	if (*(float*)i < *(float*)j) return 1;
	return 0;
}
void z3() {
	float arr[14];
	int count = 0, sum = 0;
	for (int i = 0; i < 14; i++) {
		scanf_s("%f", &arr[i]);
	}
	qsort(&arr[0], 7, sizeof(float), comp);
	qsort(&arr[7], 7, sizeof(float), comp_n);
	printf("z3:\n");
	for (int i = 0; i < 14; i++) {
		printf("%f \n", arr[i]);
	}
}


void z4() {
	double array[12];
	int max_index = 0;
	int min_index = 0;
	int start, end;
	for (int i = 0; i < 12; i++) {
		scanf_s("%lf", &array[i]);
		if (array[i] > array[max_index]) {
			max_index = i; 
		}
		if (array[i] < array[min_index]) {
			min_index = i; 
		}
	}
	if (max_index < min_index) {
		start = max_index + 1;
		end = min_index - 1;
	}
	else {
		start = min_index + 1;
		end = max_index - 1;
	}
	int count = end - start + 1;

	printf("z4: %d \n", count);

}
void z5() {
	int arr[15];
	for (int i = 0; i < 15; i++)
		scanf_s("%d", &arr[i]);
	int count = 0, mult = 1, count_zero = 0;
	for (int i = 0; i < 15; i++) {
		if (arr[i] < 0)
			count++;
		if (arr[i] > 0)
			mult *= arr[i];
		if (arr[i] == 0)
			count_zero++;
	}
	printf("%d %d %d \n", count, mult, count_zero);
}

void z6() {
	float arr[12];
	for (int i = 0; i < 12; i++) {
		scanf_s("%f", &arr[i]);
	}
	float min = arr[0];
	float max = arr[0];
	for (int i = 1; i < 12; i++) {
		if (arr[i] < min) 
			min = arr[i];
		if (arr[i] > max) 
			max = arr[i];
	}
	printf("z6: %f %f \n", min, max);

}

void z7() {
	int arr[19];
	int sum = 0;
	int flag = 0;  
	for (int i = 0; i < 19; i++) {
		scanf_s("%d", &arr[i]);
	}
	for (int i = 0; i < 19; i++) {
		if (arr[i] < 0) {
			flag= 1;
			break;
		}
		sum += arr[i];
	}

	if (flag) {
		printf("z7: %d\n", sum);
	}
	else {
		printf("z7: -1\n");
	}

}

void z8() {
	int matrix[4][4];
	int trans_mat[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			scanf_s("%d", &matrix[i][j]);
		}
	}
	printf("z8\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			trans_mat[j][i] = matrix[i][j];
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d ", trans_mat[i][j]);
		}
		printf("\n");
	}

}

void z9() {
	int matrix[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			scanf_s("%d", &matrix[i][j]);
		}
	}
	for (int i = 0; i < 4; i++) {
		int n = matrix[i][i];
		matrix[i][i] = matrix[i][3 - i];
		matrix[i][3 - i] = n;
	}
	printf("z9:\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}

}

void z10() {
	int matrix[5][5];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf_s("%d", &matrix[i][j]);
		}
	}

	int min = matrix[0][0];
	int max = matrix[4][4];
	int minr = 0, minc = 0;
	int maxr = 4, maxc = 4;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (matrix[i][j] < min) {
				min = matrix[i][j];
				minr = i;
				minc = j;
			}
			if (matrix[i][j] > max) {
				max = matrix[i][j];
				maxr = i;
				maxc = j;
			}
		}
	}

	int left_r_top = minr < maxr ? minr : maxr;
	int left_r_c = minc < maxc ? minc : maxc;
	int right_r_b = minr > maxr ? minr : maxr;
	int right_c_b = minc > maxc ? minc : maxc;

	int sum = 0;
	for (int i = left_r_top; i <= right_r_b; i++) {
		for (int j = left_r_c; j <= right_c_b; j++) {
			sum += matrix[i][j];
		}
	}
	printf("z10: %d", sum);
}