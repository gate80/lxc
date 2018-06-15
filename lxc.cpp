#include "lxc.h"
#include <sstream>	// sstream
#include <string>   // string
#include <fstream>	// fille >> <<
#include <list>		// list
using namespace std;
lxc::lxc()
{
}
lxc::~lxc()
{
}

void lxc::readFile(string fileName, string &str)
{
	ifstream in(fileName.c_str(), ios::binary);
	ostringstream out;
	str.clear();
	out << in.rdbuf();
	out.str().swap(str);
}
void lxc::split(string str, list<string> &list)
{
	istringstream ss(str);
	string String;
	while (ss >> String)
		list.push_back(String);
}
void lxc::run(string command, int i) // to file
{
	command += " > console.linux.txt";
	system(command.c_str());
}
void lxc::run(string command)
{
	system(command.c_str());
}
void lxc::installPackage()
{
	run("sudo apt-get install lxc");
}
void lxc::create_container(string container, string dist, string relese, string arch)
{
	run("sudo lxc-create -t download -n " + container + " -- --dist " + dist + " --release " + relese + " --arch " + arch);
}
void lxc::start_container(string container)
{
	run("sudo lxc-start " + container);
}
void lxc::ls_container()
{
	run("sudo lxc-ls", 1);
}
void lxc::ls_container_list(list <string> &ls)
{
	run("sudo lxc-ls", 1);
	string s;
	readFile("t.txt", s);
	split(s, ls);
}
void lxc::info_container(string container)
{
	run("sudo lxc-info " + container, 1);
}
void lxc::stop_container(string container)
{
	run("sudo lxc-stop " + container);
}
void lxc::copy_container(string container, string copy_name)
{
	run("sudo lxc-copy " + container + " -N" + copy_name);
}
void lxc::del_container(string container)
{
	run("sudo lxc-destroy " + container);
}
void lxc::freeze_container(string container)
{
	run("sudo lxc-freeze " + container);
}
void lxc::unfreeze_container(string container)
{
	run("sudo lxc-unfreeze " + container);
}
void lxc::memory_limit(string container, int M)
{
	run("sudo lxc-cgroup -n " + container + " memory.limit_in_bytes " + to_string(M) + "M");
}