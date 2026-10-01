#pragma once
#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
using cd = std::complex<double>;

class mrtx
{
  public:
	std::vector<std::vector<cd>> matrix;
	int rows()const { return matrix.size(); }
	int cols()const { return matrix[0].size(); }
	
	static mrtx zeros(int r, int c){
		 mrtx z;
		 z.matrix=std::vector<std::vector<cd>>(r, std::vector<cd>(c, 0.0));
		 return z;
		
		}

	//print matrix
	void show()const
	{
		for (auto &row : matrix)
		{
			for (auto &val : row)
			{
				if (val.imag() == 0)
				{
					std::cout << val.real() << " ";
				}
				else
				{
					std::cout << val << " ";
				}
			}
			std::cout << "\n";
		}
	}

	//matrix multiplication
	mrtx operator*(const mrtx &B)const
	{
		mrtx C=this->multiply(B);
		return C;
	}
	mrtx multiply(const mrtx &B)const
	{
		mrtx C;
		int r1 = this->rows(), c1 = this->cols();
		int r2 = B.rows(), c2 = B.cols();
		if (c1 != r2)
		{
			std::cout << "error:" << c1 << "!=" << r2 << "\n";
			return C;
		}

		C =zeros(r1,c2);
		// std::vector<std::vector<cd>>(r1, std::vector<cd>(c2, 0.0));

		for (int i = 0; i < r1; i++)
		{
			for (int j = 0; j < c2; j++)
			{
				for (int k = 0; k < c1; k++)
				{
					C.matrix[i][j] += this->matrix[i][k] * B.matrix[k][j];
				}
			}
		}
		return C;
	}

	//matrix addition
	mrtx operator+(const mrtx &B)const
	{
		mrtx C=this->add(B);
		return C;
	}
	mrtx operator-(const mrtx &B)const
	{
		mrtx C=this->add(B.scale(cd(-1)));
		return C;
	}
	mrtx add(const mrtx &B)const
	{
		mrtx C;
		int r1 = this->rows(), c1 = this->cols();
		int r2 = B.rows(), c2 = B.cols();
		if (r1 != r2 || c1 != c2)
		{
			std::cout << "error:" << r1 << "×"
					  << "c1"
					  << "!=" << r2 << "×" << c2 << "\n";
			return C;
		}

		C= zeros(r1,c2);
		//std::vector<std::vector<cd>>(r1, std::vector<cd>(c2, 0.0));

		for (int i = 0; i < r1; i++)
		{
			for (int j = 0; j < c2; j++)
			{
				C.matrix[i][j] = this->matrix[i][j] + B.matrix[i][j];
			}
		}
		return C;
	}

	mrtx tns(const mrtx &B)const
	{
		mrtx C;
		int r1 = this->rows(), c1 = this->cols();
		int r2 = B.rows(), c2 = B.cols();

		C= zeros(r1*r2,c1*c2);
		//vector<vector<cd>>(r1 * r2, vector<cd>(c1 * c2, 0.0));

		for (int i = 0; i < r1; i++)
		{
			for (int j = 0; j < c1; j++)
			{
				for (int k = 0; k < r2; k++)
				{
					for (int l = 0; l < c2; l++)
					{
						C.matrix[i * r2 + k][j * c2 + l] = this->matrix[i][j] * B.matrix[k][l];
					}
				}
			}
		}
		return C;
	}





	//scaler multiplication
	mrtx scale(const cd n)const
	{
		mrtx result;
		result=zeros(this->rows(),this->cols());
		for(int i=0;i<this->rows();i++)
		{
			for(int j=0;j<this->cols();j++)
			{
				result.matrix[i][j]=(this->matrix[i][j])*n;
			}
		}
		return result;
	}



	//identity matrix
	static mrtx I(int n)
	{
		mrtx result=zeros(n,n);
		for(int i=0;i<n;i++)
			result.matrix[i][i]=cd(1.0);
		return result;
	}
	//fetch data
	cd operator[](int a, int b)const
	{
		return this->matrix[a][b];
	}

	//conjugate
	mrtx Cj()const
	{
		mrtx res=zeros(rows(), cols());
		int R=this->rows();
         	int C=this->cols();
		for (int i=0; i<R; i++)
			for(int j=0; j<R; j++)
				res.matrix[i][j]=conj((*this)[i, j]);
		return res;
	}

	//transpose
        mrtx T()const
	{
		mrtx res;
		res=zeros(cols(),rows());
			for(int i = 0; i < rows(); i++)
			{
				for(int j = 0; j < cols(); j++)
				{
					res.matrix[j][i] = (*this)[i,j];
        			}
    			}
		return res;
	}

	//dagger
	mrtx dagger()const
	{
		return this->T().Cj();
	}
	//is unitary
	bool isUn()const
	{
		if(rows()!=cols())return false;

		mrtx U= this->dagger().multiply(*this);
		mrtx id= I(rows());
		for(int i = 0; i< rows(); i++)
		{
			for(int j = 0; j< cols(); j++)
			{
				if(abs(U.matrix[i][j]-id.matrix[i][j])>1e-9)
				{
					return false;
				}
			}
		}
		return true;
	}




};
