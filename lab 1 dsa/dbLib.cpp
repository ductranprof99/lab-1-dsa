/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : dbLib.cpp
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : The data structure library for Assignment 1
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#include "dbLib.h"

 /* TODO: You can implement methods, functions that support your data structures here.
  * */

void LoadData(void*& pData)
{
	TDataset* GoiDanhSach = new TDataset();
	pData = GoiDanhSach;
	GoiDanhSach->LoadLines();
	GoiDanhSach->LoadCity();
	GoiDanhSach->LoadStation();
	GoiDanhSach->StationLineLoad();
	GoiDanhSach->LoadTrack();
	GoiDanhSach->LoadTrackline();
}

void ReleaseData(void*& pOutput)
{

}

void TDataset::LoadLines()
{
	fstream ip1("lines.csv");
	if (ip1.good())
	{
		string str;
		getline(ip1, str);
	}
	int a = 0;
	string line;
	TLine LineNhoTam;
	while (ip1.good()) {
		getline(ip1, line);
		stringstream ss(line);
		if (line != "")
		{
			while (ss >> ws) {
				string csvElement;

				if (ss.peek() == '"') {
					ss >> quoted(csvElement);
					string discard;
					getline(ss, discard, ',');
				}
				else {
					getline(ss, csvElement, ',');
				}
				switch (a)
				{
				case 0: { if (csvElement != "")LineNhoTam.id = stoi(csvElement); a++; break; }
				case 1: { if (csvElement != "")LineNhoTam.city_id = stoi(csvElement); a++; break; }
				case 2: { LineNhoTam.name = csvElement; a++; break; }
				case 3: { LineNhoTam.name_url = csvElement; a++; break; }
				case 4: { LineNhoTam.colors = csvElement; a++; break; }
				case 5: { LineNhoTam.system_id = stoi(csvElement); a++; break; }
				case 6: { if (csvElement != "") LineNhoTam.transport_mode_id = stoi(csvElement); a = 0; break; }
				}
			}
			DLine->push_back(LineNhoTam);
		}
	}
}

void TDataset::LoadCity()
{
	fstream ip1("cities.csv");
	if (ip1.good())
	{
		string str;
		getline(ip1, str);
	}
	int a = 0;
	string line;
	TCity Citynhotam;
	while (ip1.good())
	{
		getline(ip1, line);
		stringstream ss(line);
		if (line != "") {
			while (ss >> ws) {
				string csvElement;

				if (ss.peek() == '"') {
					ss >> quoted(csvElement);
					string discard;
					getline(ss, discard, ',');
				}
				else {
					getline(ss, csvElement, ',');
				}
				switch (a)
				{
				case 0: { if (csvElement != "") Citynhotam.id = stoi(csvElement); a++; break; };
				case 1: { Citynhotam.name = csvElement; a++; break; }
				case 2: { Citynhotam.coords = csvElement; a++; break; }
				case 3: { if (csvElement != "") Citynhotam.start_year = stoi(csvElement); a++; break; }
				case 4: { Citynhotam.url_name = csvElement; a++; break; }
				case 5: { Citynhotam.country = csvElement; a++; break; }
				case 6: { if (csvElement != "") Citynhotam.country_state = csvElement; a = 0; break; }
				}
			}
		}
		DCity->push_back(Citynhotam);
	}
}

void TDataset::LoadStation()
{
	fstream ip1("stations.csv");
	if (ip1.good())
	{
		string str;
		getline(ip1, str);
	}
	int a = 0;
	string line;
	TStation tempStation;
	while (ip1.good())
	{
		getline(ip1, line);
		stringstream ss(line);
		if (line != "") {
			while (ss >> ws) {
				string csvElement;

				if (ss.peek() == '"') {
					ss >> quoted(csvElement);
					string discard;
					getline(ss, discard, ',');
				}
				else {
					getline(ss, csvElement, ',');
				}
				switch (a)
				{
				case 0: { if (csvElement != "") tempStation.id = stoi(csvElement); a++; break;	};
				case 1: { tempStation.name = csvElement; a++; break; }
				case 2: { tempStation.geometry = csvElement; a++; break; }
				case 3: { if (csvElement != "") tempStation.buildstart = stoi(csvElement); a++; break; }
				case 4: { if (csvElement != "") tempStation.openning = stoi(csvElement); a++; break; }
				case 5: { if (csvElement != "") tempStation.closure = stoi(csvElement);	a++; break; }
				case 6: { if (csvElement != "") tempStation.city_id = stoi(csvElement);	a = 0; break; }
				}
			}
		}
		DStation->push_back(tempStation);
	}
}

void TDataset::StationLineLoad()
{
	fstream ip1("station_lines.csv");
	if (ip1.good())
	{
		string str;
		getline(ip1, str);
	}
	string line;
	TStationLine tempStationLine;
	while (ip1.good())
	{
		getline(ip1, line,',');
		if (line == "") break;
		tempStationLine.id = stoi(line);
		getline(ip1, line, ',');
		tempStationLine.station_id = stoi(line);
		getline(ip1, line, ',');
		tempStationLine.line_id = stoi(line);
		getline(ip1, line, ',');
		tempStationLine.city_id = stoi(line);
		getline(ip1, line, ',');
		tempStationLine.create_up = line;
		getline(ip1, line, '\n');
		tempStationLine.update_up = line;
		DStationLine->push_back(tempStationLine);
	}
}

void TDataset::LoadTrack()
{
	fstream ip1("tracks.csv");
	if (ip1.good())
	{
		string str;
		getline(ip1, str);
	}
	int a = 0;
	string line;
	TTrack tempTrack;
	while (ip1.good())
	{
		getline(ip1, line);
		stringstream ss(line);
		if (line != "") {
			while (ss >> ws) {
				string csvElement;

				if (ss.peek() == '"') {
					ss >> quoted(csvElement);
					string discard;
					getline(ss, discard, ',');
				}
				else {
					getline(ss, csvElement, ',');
				}
				switch (a)
				{
				case 0: { if (csvElement != "") tempTrack.id = stoi(csvElement); a++; break; }
				case 1: { tempTrack.geometry = csvElement; a++; break; }
				case 2: { if (csvElement != "") tempTrack.buildstart = stoi(csvElement); a++; break; }
				case 3: { if (csvElement != "") tempTrack.openning = stoi(csvElement); a++; break; }
				case 4: { if (csvElement != "") tempTrack.closure = stoi(csvElement); a++; break; }
				case 5: { if (csvElement != "") tempTrack.length = stoi(csvElement); a++; break; }
				case 6: { if (csvElement != "") tempTrack.city_id = stoi(csvElement); a = 0; break; }
				}
			}
		}
		DTrack->push_back(tempTrack);
	}
}

void TDataset::LoadTrackline()
{
	fstream ip1("track_lines.csv");
	if (ip1.good())
	{
		string str;
		getline(ip1, str);
	}
	string line;
	TTrackLine tempTrackLine;
	while (ip1.good())
	{
		getline(ip1, line, ',');
		tempTrackLine.id = stoi(line);
		getline(ip1, line, ',');
		tempTrackLine.section_id = stoi(line);
		getline(ip1, line, ',');
		tempTrackLine.line_id = stoi(line);
		getline(ip1, line, ',');
		tempTrackLine.create_up = line;
		getline(ip1, line, ',');
		tempTrackLine.update_up = line;
		getline(ip1, line, ',');
		tempTrackLine.City_id = stoi(line);
		DTrackLine->push_back(tempTrackLine);
	}
}

int TDataset::countcity(string a)
{
	L1Item<TCity>* tCyti = new L1Item<TCity>;
	L1Item<TLine>* guess = new L1Item<TLine>;
	int sothanhpho = DCity->getSize();
	int soduong = DLine->getSize();
	int i(1),dem(0);
	bool find(0);
	while (i <= sothanhpho)
	{
		tCyti->data = DCity->at(i);
		if (a.compare(tCyti->data.name) == 0)
		{
			find = 1;
			break;
		}
		i++;
	}
	if(!find) return -1;
	i = 1;
	while (i <= soduong)
	{
		guess->data = DLine->at(i);
		if (tCyti->data.id == guess->data.city_id)
		{
			dem++;
		}
		i++;
	}
	delete tCyti;
	delete guess;
	return dem;
}

void TDataset::listLsc(string a, int*& output,int& N)
{
	L1Item<TCity>* tCyti = new L1Item<TCity>;
	L1Item<TStation>* tNhaGa = new L1Item<TStation>;
	int sothanhpho = DCity->getSize();
	int soNhaga = DStation->getSize();
	int i(1);
	bool find = 0;
	int* dayidStation = new int[soNhaga];
	output = dayidStation;
	while (i <= sothanhpho)
	{
		tCyti->data = DCity->at(i);
		if (a.compare(tCyti->data.name) == 0)
		{
			find = 1;
			break;
		}
		i++;
	}
	i = 1;
	if (!find) { 
		N = 1;
		dayidStation[0] = -1;
	}
	while (i <= soNhaga)
	{
		tNhaGa->data = DStation->at(i);
		if (tCyti->data.id == tNhaGa->data.city_id)
		{
			dayidStation[N] = tNhaGa->data.id;
			N++;
		}
		i++;
	}
	delete tCyti;
	delete tNhaGa;
}

void TDataset::listLlc(string a, int*& output, int& N)
{
	L1Item<TCity>* tCyti = new L1Item<TCity>;
	L1Item<TLine>* guess = new L1Item<TLine>;
	int sothanhpho = DCity->getSize();
	int soduong = DLine->getSize();
	int i(1), dem(0);
	bool find(0);
	int* numberofLine = new int[soduong];
	output = numberofLine;
	while (i <= sothanhpho)
	{
		tCyti->data = DCity->at(i);
		if (a.compare(tCyti->data.name) == 0)
		{
			find = 1;
			break;
		}
		i++;
	}
	if (!find) {
		N = 1;
		numberofLine[0] = -1;
	}
	i = 1;
	while (i <= soduong)
	{
		guess->data = DLine->at(i);
		if (tCyti->data.id == guess->data.city_id)
		{
			numberofLine[N] = guess->data.id;
			N++;
		}
		i++;
	}
	delete tCyti;
	delete guess;
}

void TDataset::listLsl(int index, int*& pOuput, int& N)
{
	L1Item<TStationLine>* temporary = new L1Item<TStationLine>;
	int i = 1;
	int* vorpox = new int[DStationLine->getSize()];
	while (i <= DStationLine->getSize())
	{
		temporary->data = DStationLine->at(i);
		if (index == temporary->data.line_id)
		{
			vorpox[N] = temporary->data.station_id;
			N++;
		}
		i++;
	}
	pOuput = vorpox;
	delete temporary;
}

int TDataset::findCity(string a)
{
	L1Item<TCity>* tempCity = new L1Item<TCity>;
	unsigned int i = 1;
	while (i < DCity->getSize() + 1)
	{
		tempCity->data = DCity->at(i);
		if (a.compare(tempCity->data.name) == 0)
		{
			return tempCity->data.id;
		}
		i++;
	}
	return -1;
}

int TDataset::findStation(string a)
{
	L1Item<TStation>* tempStation = new L1Item<TStation>;
	unsigned int i = 1;
	while (i < DStation->getSize() + 1)
	{
		tempStation->data = DStation->at(i);
		if (a.compare(tempStation->data.name) == 0)
		{
			return tempStation->data.id;
		}
		i++;
	}
	return -1;
}

int TDataset::findSLP(int a, int b)
{
	bool found = 0;
	unsigned int i = 1,dem = 0;
	string Location, LocationTracking;
	L1Item<TStation>* tempStation = new L1Item<TStation>;
	while (i < DStation->getSize() + 1)
	{
		tempStation->data = DStation->at(i);
		if (tempStation->data.id == a) 
		{
			i = 1; 
			Location = tempStation->data.geometry; 
			found = 1; 
			break; 
		}
		i++;
	}
	delete tempStation;
	if (found)
	{
		L1Item<TTrack>* tempTrack = new L1Item<TTrack>;
		while (i < DTrack->getSize() + 1)
		{
			tempTrack->data = DTrack->at(i);
			if (tempTrack->data.id == b)
			{
				i = 0;
				LocationTracking = tempTrack->data.geometry;
				break;
			}
			i++;
		}
		delete tempTrack;
		if (i == 0)
		{
			Location = Location.substr(Location.find('(') + 1, Location.find(')')-1 - Location.find('('));
			LocationTracking = LocationTracking.substr(LocationTracking.find('(') + 1, LocationTracking.find(')') - 1 - LocationTracking.find('('));
			stringstream ss(LocationTracking);
			string token;
			while (getline(ss, token, ','))
			{
				if (Location.compare(token) == 0)
				{
					return i;
				}
				i++;
			}
		}
	}
	return -1;
}

int TDataset::insertStation(string abe)
{
	TStation tempStation;
	L1Item<TStation>* tempStation1 = new L1Item<TStation>;
	int a = 0, maxID(0);
	for (int i = 1; i < DStation->getSize() + 1; i++)
	{
		tempStation1->data = DStation->at(i);
		if (tempStation1->data.id > maxID) maxID = tempStation1->data.id;
	}
	stringstream ss(abe);
	while (ss >> ws) {
		string csvElement;

		if (ss.peek() == '"') {
			ss >> quoted(csvElement);
			string discard;
			getline(ss, discard, ',');
		}
		else {
			getline(ss, csvElement, ',');
		}
		switch (a)
		{
		case 0: { tempStation.name = csvElement; a++; break; }
		case 1: { tempStation.geometry = csvElement; a++; break; }
		case 2: { if (csvElement != "") tempStation.buildstart = stoi(csvElement); a++; break; }
		case 3: { if (csvElement != "") tempStation.openning = stoi(csvElement); a++; break; }
		case 4: { if (csvElement != "") tempStation.closure = stoi(csvElement); a++; break; }
		}
	}
	maxID++;
	tempStation.id = maxID;
	DStation->push_back(tempStation);
	delete tempStation1;
	return maxID;
}





