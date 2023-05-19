#include "DataFile.h"
#include <fstream>
using namespace std;

//  Constructor
DataFile::DataFile()
{
	recordCount = 0;
}

//  Deconstructor
DataFile::~DataFile()
{
	Clear();
}

//  Loading from the data file
void DataFile::Load(string filename, int index)		
{
	Clear();

	ifstream infile(filename, ios::binary);
	recordCount = 0;
	infile.read((char*)&recordCount, sizeof(int));	// read the record count from the data file

	for (int i = 0; i < recordCount; i++)
	{
		//  initializing variables to zero
		int nameSize = 0;
		int ageSize = 0;
		int width = 0, height = 0, format = 0, imageSize = 0;

		infile.read((char*)&width, sizeof(int));
		infile.read((char*)&height, sizeof(int));

		imageSize = sizeof(Color) * width * height;

		infile.read((char*)&nameSize, sizeof(int));
		infile.read((char*)&ageSize, sizeof(int));

		if (i == index) // if i is equal to the index load the required data
		{
			char* imgdata = new char[imageSize];
			infile.read(imgdata, imageSize);

			Image img = LoadImageEx((Color*)imgdata, width, height);
			char* name = new char[nameSize];
			int age = 0;

			infile.read((char*)name, nameSize);
			infile.read((char*)&age, ageSize);

			Record* r = new Record();
			r->image = img;
			r->name = string(name, nameSize);	// ensuring that the name length does not exceed nameSize
			r->age = age;

			records = r;

			// deleting the variables

			delete[] imgdata;
			delete[] name;
		}
		else		// moves to the next file using the offset of the sizes of the name age and img variables
		{
			infile.seekg(nameSize + ageSize + imageSize, std::ios::cur); 
		}

	}

	infile.close();
}


void DataFile::Clear()
{
}