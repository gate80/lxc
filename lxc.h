#pragma once
#include <sstream>	// sstream
#include <string>   // string
#include <fstream>	// fille >> <<
#include <list>		// list
using namespace std;
class lxc
{
public:
	lxc();
	~lxc();
	void readFile(string fileName, string &str);
	void split(string str, list<string> &list);
	void run(string command, int i);
	void run(string command);
	void installPackage();
	void create_container(string container, string dist, string relese, string arch);
	void start_container(string container);
	void ls_container();
	void ls_container_list(list <string> &ls);
	void info_container(string container);
	void stop_container(string container);
	void copy_container(string container, string copy_name);
	void del_container(string container);
	void freeze_container(string container);
	void unfreeze_container(string container);
	void memory_limit(string container, int M);
};