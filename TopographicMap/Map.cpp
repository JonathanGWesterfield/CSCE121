#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

// reads the input file for the map data
vector<int> GetMapData(const string& filename)
{
	int elevation;
	vector<int> mapData;

	//string filename;
	//cout << "Input the name of the file: ";
	//cin >> filename;
	ifstream Data; // Input filestream object

	Data.open(filename);
	if (!Data.is_open())
	{
		// If file could not be found or opened then the 
		// program shuts down 
		cout << "ERROR: FILE COUD NOT BE OPENED" << endl;
		cout << "EXITING PROGRAM" << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		cout << "File found and good" << endl;
		while (!Data.eof())
		{
			Data >> elevation;
			mapData.push_back(elevation);
		}

		Data.close();
	}

	return mapData;
}

/* puts the vector of elevation into a 2d vector with demensions matching the image
 * width and the image height
 * */
vector<vector<int> > insertDataToVector(const vector<int>& elevation, int imageHeight, int imageWidth)
{
	vector<vector<int> > mapData;
	
	int count = 0;
	for (int i = 0; i < imageHeight; i++)
	{
		vector<int> row;
		for (int j = 0; j < imageWidth; j++)
		{
			row.push_back(elevation.at(count));
			count++;
		}
		mapData.push_back(row);
	}

	return mapData;
}

//Gets the minimum and maximum values for the 2d vector
void MinMax(int& maxVal, int& minVal, const vector<vector< int> > &mapData, int imageHeight, int imageWidth)
{
	maxVal = mapData.at(0).at(0);
	minVal = mapData.at(0).at(0);

	for (unsigned int i = 0; i < imageHeight; i++)
	{
		for(int j = 0; j < imageWidth; j++)
		{
			if (mapData.at(i).at(j) > maxVal)
				maxVal = mapData.at(i).at(j);
			else if (mapData.at(i).at(j) < minVal)
				minVal = mapData.at(i).at(j);
		}
	}
}

//scales down the elevation to rgb values between 0 and 255
vector<vector<int> > convertToColor(const vector<vector<int> > &mapData, double maxVal, double minVal)
{
	vector<vector<int> >colorVec;

	for(int i = 0; i < mapData.size(); i++)
	{	
		vector<int> row;
		
		for(int j = 0; j < mapData[i].size(); j++)
		{
			int ColorVal = 255 * ((mapData.at(i).at(j) - minVal) / (maxVal - minVal));
			row.push_back(ColorVal);
		}
		colorVec.push_back(row);
	}
	
	for(int i = 0; i < colorVec.size(); i++)
	{
		for(int j = 0; j < colorVec[i].size(); j++)
		{
			cout << colorVec.at(i).at(j) << " ";
		}
		cout << endl;
	}
	
	 return colorVec;
}

// puts the color values into a 2d vector
//actually unnecessary and redundant
vector<vector<int> > ColorVecPopulation(const vector<vector<int> > &ColorVal)
{
	vector<vector<int> > RGBVal;
	for(int i = 0; i < ColorVal.size(); i++)
	{	
		vector<int> row;
		
		for(int j = 0; j < ColorVal[i].size(); j++)
		{
			row.push_back(ColorVal.at(i).at(j));
		}
		RGBVal.push_back(row);
	}
	
	return RGBVal;
}

//prints the 2d vector into a ppm file 
void PrintVal(vector<vector<int> > &ColorVec, int imageHeight, int imageWidth, string filename,
const vector<vector<int> > &RedVal, const vector<vector<int> > &GreenVal, const vector<vector<int> > &BlueVal)
{
	ofstream outfile;
	string newFilename = filename + ".ppm";
	outfile.open(newFilename);
	
	if (!outfile.is_open())
	{
		// If file could not be found or opened then the 
		// program shuts down 
		cout << "ERROR: OUTPUT FILE COUD NOT BE OPENED" << endl;
		cout << "EXITING PROGRAM" << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		cout << "File OPENED" << endl;
		cout << "Your .ppm file has been created." << endl;
		cout << "Filename: " << newFilename << endl;
		outfile << "P3" << endl;
		outfile << imageWidth << " " << imageHeight << endl;
		outfile << 255 << endl;
		
		for(int i = 0; i < ColorVec.size(); i++)
		{
			for(int j = 0; j < ColorVec[i].size(); j++)
			{
				outfile << RedVal.at(i).at(j) << " ";
				outfile << GreenVal.at(i).at(j) << " ";
				outfile << BlueVal.at(i).at(j) << " ";
			}
			outfile << endl;
		}
		/*
		for(int i = 0; i < ColorVec.size(); i++)
		{
			for(int j = 0; j < ColorVec[i].size(); j++)
			{
				cout << RedVal.at(i).at(j) << " ";
				cout << GreenVal.at(i).at(j) << " ";
				cout << BlueVal.at(i).at(j) << " ";
			}
			outfile << endl;
		}
		 * */
	}
	outfile.close();
}

void redline(vector<vector<int> >& r, vector<vector<int> >& g, vector<vector<int> >& b, int color_r, int color_g, int color_b, int posr, int posc) {
	r[posr][posc] = color_r;
	g[posr][posc] = color_g;
	b[posr][posc] = color_b;
}
int colorPath(const vector<vector<int> >& v2d, vector<vector<int> >& r, vector<vector<int> >& g, vector<vector<int> >& b, int color_r, int color_g, int color_b, int start_row) {
	int changes = 0;//height
	int i = start_row; // easier for i,j inputs
	redline(r, g, b, color_r, color_g, color_b, i, 0);
	for (int j = 0; j < v2d[0].size() - 1; ++j) {
		if (i == 0) {//first row 
			//going straight
			if (abs(v2d[i][j] - v2d[i+1][j + 1]) >= abs(v2d[i][j] - v2d[i][j + 1])) {
				redline(r, g, b, color_r, color_g, color_b, i, j + 1);
				changes = abs(v2d[i][j] - v2d[i][j + 1]) + changes;

			}
			else {// going down right, south east
				redline(r, g, b, color_r, color_g, color_b, i + 1, j + 1);
				changes = abs(v2d[i][j] - v2d[i + 1][j + 1]) + changes ;

				i += 1;
			}

		}
		else if (i == v2d.size() - 1) {//bottom row
			if (abs(v2d[i][j] - v2d[i-1][j + 1]) >= abs(v2d[i][j] - v2d[i ][j + 1])) {
				redline(r, g, b, color_r, color_g, color_b, i, j + 1);
				changes =  abs(v2d[i][j] - v2d[i][j + 1])+changes ;
			}
			else {// going down right, south east
				redline(r, g, b, color_r, color_g, color_b, i - 1, j + 1);
				changes = abs(v2d[i][j] - v2d[i-1][j + 1]) + changes;

				i -= 1;
			}
		}
		else { //everything else
			if (abs(v2d[i][j] - v2d[i - 1][j + 1]) >= abs(v2d[i][j] - v2d[i + 1][j + 1])) { //north east equal sourth east
				if (abs(v2d[i][j] - v2d[i + 1][j + 1]) >= abs(v2d[i][j] - v2d[i][j + 1])) { //south east is equal to straight
					redline(r, g, b, color_r, color_g, color_b, i, j + 1);
					changes = abs(v2d[i][j] - v2d[i][j + 1]) + changes;
				}
				else if (abs(v2d[i][j] - v2d[i + 1][j + 1]) < abs(v2d[i][j] - v2d[i][j + 1])) { //seast = straight
					redline(r, g, b, color_r, color_g, color_b, i + 1, j + 1); //south east
					changes = abs(v2d[i][j] - v2d[i + 1][j + 1]) + changes;
					i += 1;
				}
			}
			else if (abs(v2d[i][j] - v2d[i - 1][j + 1]) < abs(v2d[i][j] - v2d[i + 1][j + 1])) { //south east greater north east
				if (abs(v2d[i][j] - v2d[i - 1][j + 1]) >= abs(v2d[i][j] - v2d[i][j + 1])) {//north east greater or = straight
					redline(r, g, b, color_r, color_g, color_b, i, j + 1); //straight
					changes = abs(v2d[i][j] - v2d[i][j + 1]) + changes;
				}
				else if (abs(v2d[i][j] - v2d[i - 1][j + 1]) < abs(v2d[i][j] - v2d[i][j + 1])) { //	straight greater than north east
					redline(r, g, b, color_r, color_g, color_b, i - 1, j + 1); //north east
					changes = abs(v2d[i][j] - v2d[i - 1][j + 1]) + changes;
					i -= 1;
				}
			}
		}
	}
	return changes;
}

int main()
{
	vector<vector<int> > mapData;
	vector<vector<int> > RedVal;
	vector<vector<int> > GreenVal;
	vector<vector<int> > BlueVal;
	int imageHeight;
	int imageWidth;
	int maxVal;
	int minVal;
	string filename; // = "map-input-480-480.dat";
	int altitudeChange;
	int altitudeChangeMin;
	int minimumRow = 0;
	int red = 252;
	int green = 25;
	int blue = 63;

	cout << "What is the height of the picture? ";
	cin >> imageHeight;

	cout << "What is the width of the picture? ";
	cin >> imageWidth;
	
	cout << "What is the file name?";
	cin >> filename;


	vector<int> elevation = GetMapData(filename); // gets the file information
	
	int sizeCheck = imageHeight * imageWidth;
	while(sizeCheck > elevation.size())
	{
		int sizeCheck = imageHeight * imageWidth;
		if(sizeCheck > elevation.size())
		{
			cout << "The image that you want is larger than original picture" << endl;
			
			cout << "What is the height of the picture? ";
			cin >> imageHeight;

			cout << "What is the width of the picture? ";
			cin >> imageWidth;
	
			continue;
		}
		else
			break;
	}
	mapData = insertDataToVector(elevation, imageHeight, imageWidth); // turns into a 2d vector

	MinMax(maxVal, minVal, mapData, imageHeight, imageWidth);// finds min and max value in 2d vector
	cout << "Max value: " << maxVal << endl;
	cout << "Min value: " << minVal << endl;
	
	vector<vector<int> > ColorRep = convertToColor(mapData, maxVal, minVal);// scales down the elevation values to rgb values
	RedVal = ColorRep;
	GreenVal = ColorRep;
	BlueVal = ColorRep;
	

	//altitudeChange = colorPath(mapData, RedVal, GreenVal, BlueVal, red, green, blue, mapData.size() / 2);
	//altitudeChange = colorPath(mapData, RedVal, GreenVal, BlueVal, red, green, blue, mapData.size() - 1);
	
	altitudeChangeMin = colorPath(mapData, RedVal, GreenVal, BlueVal, red, green, blue, 0);
	for(int i = 0; i < mapData.size(); i++)
	{
		altitudeChange = colorPath(mapData, RedVal, GreenVal, BlueVal, red, green, blue, i);
		if(altitudeChange < altitudeChangeMin)
		{
			altitudeChangeMin = altitudeChange;
			minimumRow = i;
		}
	}
	
	cout << "Minimum Row: " << minimumRow << endl;
	
	int altmin = colorPath(mapData, RedVal, GreenVal, BlueVal, 31, 253, 13, minimumRow);

	
	/*
	vector<int> altChangeVec;
	for(int i = 0; i < mapData.size(); i++)
	{
		altChangeVec.push_back(altitudeChange = colorPath(mapData, RedVal, GreenVal, BlueVal, red, green, blue, i));
	}
	int shortestpath = altChangeVec.at(0);
	int shortestRow = 0;
	for(int i = 0; i < altChangeVec.size(); i++)
	{
		if(altChangeVec.at(i) < shortestpath)
		{
			shortestRow = i;
			shortestpath = altChangeVec.at(i);
		}
	}
	colorPath(mapData, RedVal, GreenVal, BlueVal, 31, 253, 13, shortestRow);
	 * */
	cout << "Altitude Change Minimum: " <<  altitudeChangeMin << endl;
	cout << "Min Altitude Change on Row: " << minimumRow << endl;
	
	
	PrintVal(ColorRep, imageHeight, imageWidth,filename, RedVal, GreenVal, BlueVal);
	
	//system("pause");
}


