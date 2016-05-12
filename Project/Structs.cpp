#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Demand //представлять требование в виде дерева
{
	int id_dem;
	string type_dem;
	string num_dem;
	string text_dem;
	string name_dem;
	string code_dem;
	int id_par;
	string num_par;
	vector<Demand*> childs;
};

struct Change
{
	int project_id;
	int demand_id;
	int user_id;
	int date_change;
	string text_dem;
	string num_dem;
	string type_dem;
	string name_dem;
	string code_dem;
};

struct AllDem
{
	string proj_name; //название проекта
	string path; //путь до папки с файлами
	string name_dem; //путь до требования: список требований
};

struct doc_srtuct
{
	int project_id;
	int section_id;
	int num_in_doc;
	string section_name;
	int parent_id;
};

struct project
{
	int project_id;
	string project_name;
};

struct source
{
	int source_id;
	string text_source;
};

struct structt
{
	int project_id;
	int section_id;
	string num_in_doc;
	string section_name;
	int parent_id;
};

struct users
{
	int user_id;
	string user_name;
};

struct templatee
{
	int template_id;
	string name_temp;
};
