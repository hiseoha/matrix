#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 100

typedef struct {
	int row;
	int col;
	int value;
} element;

typedef struct SparseMatrix {
	element data[MAX_TERMS];
	int rows;
	int cols;
	int terms;
} SparseMatrix;

SparseMatrix matrix_transpose2(SparseMatrix a)
{
	SparseMatrix* b = (SparseMatrix*)malloc(sizeof(SparseMatrix));
	int bindex;

	b->rows = a.rows;
	b->cols = a.cols;
	b->terms = a.terms;

	if (a.terms > 0) {

		bindex = 0;

		for (int c = 0; c < a.cols; c++) {
			for (int i = 0; i < a.terms; i++) {
				if (a.data[i].col == c) {
					b->data[bindex].row = a.data[i].col;
					b->data[bindex].col = a.data[i].row;
					b->data[bindex].value = a.data[i].value;

					bindex++;
				}
			}
		}
		for (int i = 0; i < b->terms; i++) {
			printf("%d %d %d \n", b->data[i].row, b->data[i].col, b->data[i].value);
		}
	}
	return *b;
	free(b);
}
int main(void)
{
	int cols, rows, terms;

	SparseMatrix* m = (SparseMatrix*)malloc(sizeof(SparseMatrix));

	printf("Enter the size of rows and columns, the number of non-zero terms: ");
	scanf_s("%d %d %d", &rows, &cols, &terms);

	m->terms = terms;
	m->cols = cols;
	m->rows = rows;

	printf("Enter row, column, and value pairs in order:\n");

	for (int i = 0; i < terms; i++) {
		scanf_s("%d %d %d", &m->data[i].row, &m->data[i].col, &m->data[i].value);
	}

	printf("The transposed matrix is:\n");
	matrix_transpose2(*m);
	free(m);

	return 0;
}