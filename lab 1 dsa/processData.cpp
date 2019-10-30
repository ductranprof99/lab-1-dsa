/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : processData.cpp
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : Implementation of main features in the assignment
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#include "processData.h"
#include "dbLib.h"

 /* TODO: You can implement methods, functions that support your data structures here.
  * */
using namespace std;

void Initialization() {
	// If you use global variables, please initialize them explicitly in this function.
}

void Finalization() {
	// Release your data before exiting
}

void ProcessRequest(const char* pRequest, void* pData, void*& pOutput, int& N) {
	// TODO: Implement this function for processing a request
	// NOTE: You can add other functions to support this main process.
	//       pData is a pointer to a data structure that manages the dataset
	//       pOutput is a pointer reference. It is set to nullptr and student must allocate data for it in order to save the required output
	//       N is the size of output, must be a non-negative number
	TDataset* temPAccess = static_cast<TDataset *>(pData);
	N = 0;
	if (strlen(pRequest) <= 3 && strlen(pRequest) > 0)
	{
		int A = temPAccess->DLine->getSize();
		pOutput = malloc(sizeof(int));
		*((int*)pOutput) = A;
		N = 1;
	}
	else
	{
		string a = pRequest;
		string b,c;
		stringstream ss(a);
		getline(ss, b, ' ');
		if (b == "CL")
		{
			getline(ss, c);
			int aba = temPAccess->countcity(c);
			pOutput = malloc(sizeof(int));
			*((int*)pOutput) = aba;
			N = 1;
		}
		if (b == "LSC")
		{
			getline(ss, c);
			pOutput = malloc(sizeof(int));
			int* Sg553 = NULL;
			temPAccess->listLsc(c, Sg553, N);
			pOutput = Sg553;
		}
		if (b == "LLC")
		{
			getline(ss, c);
			pOutput = malloc(sizeof(int));
			int* Sg553 = NULL;
			temPAccess->listLlc(c, Sg553, N);
			pOutput = Sg553;
		}
		if (b == "LSL")
		{
			getline(ss, c);
			int lineID = stoi(c);
			pOutput = malloc(sizeof(int));
			int* Sg553 = NULL;
			temPAccess->listLsl(lineID, Sg553, N);
			pOutput = Sg553;
		}
		if (b == "FC")
		{
			getline(ss, c);
			int vortex = temPAccess->findCity(c);
			pOutput = malloc(sizeof(int));
			*((int*)pOutput) = vortex;
			N = 1;
		}
		if (b == "FS")
		{
			getline(ss, c);
			int vortex = temPAccess->findStation(c);
			pOutput = malloc(sizeof(int));
			*((int*)pOutput) = vortex;
			N = 1;
		}
		if (b == "SLP")
		{
			getline(ss, c,' ');
			int station = stoi(c);
			getline(ss, c, ' ');
			int track = stoi(c);
			pOutput = malloc(sizeof(int));
			int vortex = temPAccess->findSLP(station, track);
			*((int*)pOutput) = vortex;
			N = 1;
		}
		if (b == "IS")
		{
			getline(ss, c);
			int vortex = temPAccess->insertStation(c);
			pOutput = malloc(sizeof(int));
			*((int*)pOutput) = vortex;
			N = 1;
		}
	}
}

