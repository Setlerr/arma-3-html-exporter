#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string str,id;
	string odp;
	fstream html_file;
	fstream txt_file;
	html_file.open("preset.html", ios::in);
	txt_file.open("server.txt", ios::out);
	if (html_file.good() == false)
	{
		cout << "No preset.html in Exporter.exe folder";
	}
	do
	{
		getline(html_file, str);
		if (str.find("id=") != string::npos)
		{
			id = str.substr(str.find("id=") + 3);
			id = id.substr(0,id.find("data-type")-2);
			odp = "@" + id + ":" + id+"\n";
			cout << odp<<endl;
			txt_file<<odp;
		}
		

	} while (html_file.eof() != true);
	html_file.close();
	txt_file.close();
	
	



	return 0;
}
