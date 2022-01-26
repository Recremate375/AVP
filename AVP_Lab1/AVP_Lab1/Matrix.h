#pragma once
#include<iostream>

template <typename T> class Matrix 
{
public:
	T**** matrix;

	const int basicHeight;
	const int basicWidth;
	const int includedHeight;
	const int includedWidth;

	Matrix(int basicHeight, int basicWidth, int includedHeight, int includedWidth) :
		basicWidth(basicWidth), basicHeight(basicHeight), includedHeight(includedHeight), includedWidth(includedWidth)
	{
		this->matrix = new T***[basicHeight];
		for (int i = 0; i < basicHeight; i++)
		{
			this->matrix[i] = new T**[basicWidth];
			for (int j = 0; j < basicWidth; j++)
			{
				this->matrix[i][j] = new T*[includedHeight];
				for (int k = 0; k < includedHeight; k++)
				{
					this->matrix[i][j][k] = new T[includedWidth];
					for (int m = 0; m < includedWidth; m++)
					{
						this->matrix[i][j][k][m] = 0;
					}
				}
			}
		}
	}
	~Matrix()
	{
		for (int i = 0; i < basicHeight; i++)
		{
			for (int j = 0; j < basicWidth; j++)
			{
				for (int k = 0; k < includedHeight; k++)
				{
					delete[] matrix[i][j][k];
				}
				delete[] matrix[i][j];
			}
			delete[] matrix[i];
		}
		delete[] matrix;
	}
};

