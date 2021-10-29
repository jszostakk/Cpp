using namespace std;

int **createMatrixInt(int wiersze, int kolumny);

double **createMatrixDouble(int wiersze, int kolumny);

bool insertValues(int **matrix, int wiersze, int kolumny);

bool insertValues(double **matrix, int wiersze, int kolumny);

void show(int **matrix, int wiersze, int kolumny);

void show(double **matrix, int wiersze, int kolumny);

int **addMatrix(int **martixA, int **matrixB, int wiersze, int kolumny);

double **addMatrix(double **martixA, double **matrixB, int wiersze, int kolumny);

int **subtractMatrix(int **martixA, int **matrixB, int wiersze, int kolumny);

double **subtractMatrix(double **martixA, double **matrixB, int wiersze, int kolumny);

int **multiplyMatrix(int **martixA, int **matrixB, int wierszeA, int kolumnyA, int kolumnyB);

double **multiplyMatrix(double **martixA, double **matrixB, int wierszeA, int kolumnyA, int kolumnyB);

int **multiplyByScalar(int **martix, int wiersze, int kolumny, int scalar);

double **multiplyByScalar(double **martix, int wiersze, int kolumny, double scalar);

int **transposeMatrix(int **matrix, int wiersze, int kolumny);

double **transposeMatrix(double **matrix, int wiersze, int kolumny);

int **powerMatrix(int **martix, int wiersze, int kolumny, int power);

double **powerMatrix(double **martix, int wiersze, int kolumny, int power);

int determinantMatrix(int **matrix, int wiersze);

int **submatrix(int **matrix, int wiersze, int kolumny, int size);

double determinantMatrix(double **matrix, int wiersze);

double **submatrix(double **matrix, int wiersze, int kolumny, int size);

bool matrixIsDiagonal(int **matrix, int wiersze, int kolumny);

bool matrixIsDiagonal(double **matrix, int wiersze, int kolumny);

void swap(int *x, int *y);

void swap(double *x, double *y);

void sortRow(int *tab, int kolumny);

void sortRow(double *tab, int kolumny);

void sortRowsInMatrix(int **matrix, int wiersze, int kolumny);

void sortRowsInMatrix(double **matrix, int wiersze, int kolumny);

bool command(string c);

int checkInt();

double checkDouble();

string checkString();

void help();