#include "stdafx.h"
#include "p3_2.h"
#include "pre_process.h"
#include <vector>
#include <string>
#include <iostream>  
#include <fstream> 

using namespace std;

void HW1_Problem_three_part_two(void) 
{
	string file_audio = "E:\\MY_LOG\\669\\hw1\\input\\EE669_Fall_2017_HW1_Data_Files\\audio.dat";
	string file_binary = "E:\\MY_LOG\\669\\hw1\\input\\EE669_Fall_2017_HW1_Data_Files\\binary.dat";
	string file_image = "E:\\MY_LOG\\669\\hw1\\input\\EE669_Fall_2017_HW1_Data_Files\\image.dat";
	string file_text = "E:\\MY_LOG\\669\\hw1\\input\\EE669_Fall_2017_HW1_Data_Files\\text.dat";
	vector<unsigned char> audio = ReadBinaryFile(file_audio);
	vector<unsigned char> binary = ReadBinaryFile(file_binary);
	vector<unsigned char> image = ReadBinaryFile(file_image);
	vector<unsigned char> text = ReadBinaryFile(file_text);
	vector<unsigned char> pre_processed_imaged = Pre_Process_Image_restrict(image);
	vector<unsigned char> compressed_data = Improved_Run_Length_Encode(pre_processed_imaged);
	cout << "size:" << compressed_data.size() << endl;
	vector<unsigned char> decoded_data = Improved_Run_Length_Decode(compressed_data);
	Check(pre_processed_imaged, decoded_data);

	//���
	unsigned char buffer[99999999];
	int index = 0;
	for (vector<unsigned char>::iterator it = compressed_data.begin(); it != compressed_data.end(); it++)
	{
		buffer[index] = *it;
		index++;
	}
	string path = "E:\\MY_LOG\\669\\hw1\\output\\new_image_improved_run_length_with_pre_process.dat";
	FILE *fp_write = fopen(path.c_str(), "wb");
	if (fp_write == NULL)
	{
		printf("\nFail to create the file.");
	}
	else
	{
		printf("\nScuess to create the file.");
	}
	fwrite(buffer, sizeof(unsigned char), compressed_data.size(), fp_write);
	fclose(fp_write);
	cout << "done: " << path << endl;
}
