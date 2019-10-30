#pragma once
/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : dbLib.h
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : The data structure library for Assignment 1
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#ifndef DSA191_A1_DBLIB_H
#define DSA191_A1_DBLIB_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
#include <math.h>

#include "dsaLib.h"

 /* TODO: Please design your data structure carefully so that you can work with the given dataset
  *       in this assignment. The below structures are just some suggestions.
  */
struct TCity {
	// The structure to store city information
	int id;
	string name;
	string coords;
	int start_year;
	string url_name;
	string country;
	string country_state;
	
};

struct TLine {
	// The structure to store line information
	int id;
	int city_id;
	string name;
	string name_url;
	string colors;
	int transport_mode_id;
	int system_id;
};

struct TTrack {
	// The structure to store track information
	int id;
	string geometry;
	int buildstart;
	int openning;
	int closure;
	int length;
	int city_id;
};
struct TStation
{
	int id;
	string name;
	string geometry;
	int buildstart;
	int openning;
	int closure;
	int city_id;
};
struct TTrackLine
{
	int id;
	int section_id;
	int line_id;
	int City_id;
	string create_up;
	string update_up;
};
struct TStationLine
{
	int id;
	int station_id;
	int line_id;
	int city_id;
	string create_up;
	string update_up;
};
class TDataset {
	// This class can be a container that help you manage your tables
public:
	L1List<TCity>* DCity;
	L1List<TLine>* DLine;
	L1List<TTrack>* DTrack;
	L1List<TStation>* DStation;
	L1List<TStationLine>* DStationLine;
	L1List<TTrackLine>* DTrackLine;
	TDataset()
	{
		DCity = new L1List<TCity>;
		DLine = new L1List<TLine>;
		DTrack = new L1List<TTrack>;
		DStation = new L1List<TStation>;
		DStationLine = new L1List<TStationLine>;
		DTrackLine = new L1List<TTrackLine>;
	}
	~TDataset()
	{
		delete DCity;
		delete DLine;
		delete DTrackLine;
		delete DTrack;
		delete DStation;
		delete DStationLine;
	}
	void LoadLines();
	void LoadCity();
	void LoadStation();
	void StationLineLoad();
	void LoadTrack();
	void LoadTrackline();
	int countcity(string);
	void listLsc(string, int*&,int&);
	void listLlc(string, int*&, int&);
	void listLsl(int, int*&, int&);
	int findCity(string);
	int findStation(string);
	int findSLP(int a, int b);
	int insertStation(string);
};

// Please add more or modify as needed

void LoadData(void*&);
void ReleaseData(void*&);
#endif //DSA191_A1_DBLIB_H
