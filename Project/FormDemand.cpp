//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormDemand.h"
#include "FormProject.h"
#include "FormCreateUser.h"
#include "FormSelectProject.h"
#include "FormLogin.h"
#include "Structs.cpp"
#include "String.h"
#include "Classes.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmDemand *FrmDemand;
//---------------------------------------------------------------------------
__fastcall TFrmDemand::TFrmDemand(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall TFrmDemand::Name1Click(TObject *Sender)//создание нового проекта, сразу создается в treeview
{
	  FrmCreateProj->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFrmDemand::button_add_InClick(TObject *Sender)
{
	if(TreeView_doc_Struct->Selected)
	{
	   //	TreeView_doc_Struct->Items->AddChild(TreeView_doc_Struct->Selected,this->node_Name->Text);
		Demand *reqinfo = new Demand;
		reqinfo->name_dem = string(AnsiString(this->node_Name->Text).c_str());
		reqinfo->num_par = string(AnsiString(this->Editnumber->Text).c_str());
		int cou = TreeView_doc_Struct->Selected->Count+1;
		String str = IntToStr(cou);

		Demand *e = (Demand *)TreeView_doc_Struct->Selected->Data;
		reqinfo->num_dem = e->num_dem+"."+string(AnsiString(str).c_str());

		//reqinfo->num_dem = e->num_dem.c_str();
		TTreeNode* node = TreeView_doc_Struct->Items->AddChildObject(TreeView_doc_Struct->Selected, this->node_Name->Text, (void*)reqinfo);
		node->Selected = true;
		this->Editnumber->Text = reqinfo->num_dem.c_str();
	}
	else ShowMessage("Please, select node");
}


//---------------------------------------------------------------------------

void __fastcall TFrmDemand::button_add_NewClick(TObject *Sender)
{
	Demand *reqinfo = new Demand;
	reqinfo->name_dem = string(AnsiString(this->node_Name->Text).c_str());
	reqinfo->num_par = string(AnsiString("0").c_str());
	TTreeNode* node = TreeView_doc_Struct->Items->AddObject(NULL, this->node_Name->Text, (void*)reqinfo);
	node->Selected = true;
	reqinfo->num_dem = string(AnsiString((UnicodeString)this->TreeView_doc_Struct->Items->Count).c_str());
	Editnumber->Text = ((UnicodeString)this->TreeView_doc_Struct->Items->Count).c_str();
}
//---------------------------------------------------------------------------

void __fastcall TFrmDemand::Button_add_textClick(TObject *Sender)
{
	Demand* text = new Demand;
	text->text_dem = string(AnsiString(Edit_textNode->Text).c_str());
	TreeView_doc_Struct->Items->AddObject(NULL, this->Edit_textNode->Text, (void*)text);
}
//---------------------------------------------------------------------------

void __fastcall TFrmDemand::TreeView_doc_StructClick(TObject *Sender)
{
	if(TreeView_doc_Struct->Selected)
	{
		Demand *reqinfo = (Demand *)TreeView_doc_Struct->Selected->Data;
		this->Edit_textNode->Text = reqinfo->text_dem.c_str();
		this->Editnamedem->Text = reqinfo->name_dem.c_str();
		this->Editcode->Text = reqinfo->code_dem.c_str();
		this->comboboxtypedem->Text = reqinfo->type_dem.c_str();
		this->Editnumber->Text = reqinfo->num_dem.c_str();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmDemand::Edit_textNodeChange(TObject *Sender)
{
	if(TreeView_doc_Struct->Selected)
	{
		//Demand *reqinfo = new Demand;
		//reqinfo->text_dem = string(AnsiString(Edit_textNode->Text).c_str());
		((Demand*)(TreeView_doc_Struct->Selected->Data))->text_dem = string(AnsiString(Edit_textNode->Text).c_str());

	}
		//TreeView_doc_Struct->Items->AddObject(NULL, this->node_Name->Text, (void*)reqinfo);

}
//---------------------------------------------------------------------------

void __fastcall TFrmDemand::Button_saveClick(TObject *Sender)
{
	for (int i = 0; i < this->TreeView_doc_Struct->Items->Count; i++) {
		 if(this->TreeView_doc_Struct->Items->Item[i]->Data)
		 {
			Demand *reqinfo = (Demand *)TreeView_doc_Struct->Items->Item[i]->Data;
			this->ADOQuery_insert->SQL->Text = (UnicodeString)"insert into demand (type_dem,text_dem,name_dem,code_dem,num_dem,num_par) values ('"+reqinfo->type_dem.c_str()+"','"+reqinfo->text_dem.c_str()+"','"+reqinfo->name_dem.c_str()+"','"+reqinfo->code_dem.c_str()+"','"+reqinfo->num_dem.c_str()+"','"+reqinfo->num_par.c_str()+"')";
			this->ADOQuery_insert->ExecSQL();
		 }
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmDemand::node_NameClick(TObject *Sender)
{
	this->node_Name->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TFrmDemand::Name2Click(TObject *Sender)
{
	FrmCreateUser->Show();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------


void __fastcall TFrmDemand::FormCreate(TObject *Sender)
{
	this->comboboxtypedem->Items->Add("Функциональное");
	this->comboboxtypedem->Items->Add("Нефункциональное");
}
//---------------------------------------------------------------------------

void __fastcall TFrmDemand::Select1Click(TObject *Sender)
{
	FrmSelectProject->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFrmDemand::ButtondelnodeClick(TObject *Sender)
{
	this->TreeView_doc_Struct->Selected->Delete();
}
//---------------------------------------------------------------------------

void __fastcall TFrmDemand::Login1Click(TObject *Sender)
{
	FrmLogin->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFrmDemand::EditnamedemChange(TObject *Sender)
{
	((Demand*)(TreeView_doc_Struct->Selected->Data))->name_dem = string(AnsiString(this->Editnamedem->Text).c_str());
	 TreeView_doc_Struct->Selected->Text = this->Editnamedem->Text;
}
//---------------------------------------------------------------------------

void __fastcall TFrmDemand::EditcodeChange(TObject *Sender)
{
	 ((Demand*)(TreeView_doc_Struct->Selected->Data))->code_dem = string(AnsiString(this->Editcode->Text).c_str());
	 TreeView_doc_Struct->Selected->Text = this->Editnamedem->Text;
}
//---------------------------------------------------------------------------

void __fastcall TFrmDemand::comboboxtypedemChange(TObject *Sender)
{
		 ((Demand*)(TreeView_doc_Struct->Selected->Data))->type_dem = string(AnsiString(this->comboboxtypedem->Text).c_str());
}
//---------------------------------------------------------------------------
void Recursive(Demand*, TADOQuery*);
void RecursiveFChilds(Demand*, TTreeNode*);
void __fastcall TFrmDemand::ButtonrefreshClick(TObject *Sender)
{
	ADOQuery_insert->SQL->Text = (AnsiString)"select * from Demand where project_id=1 order by id_dem";
	ADOQuery_insert->Open();

	 TADOQuery * ado = new TADOQuery(NULL);
	 ado->Connection = ADOConnection1;

		ado->SQL->Text = (AnsiString)"select * from Demand where project_id=1 order by id_dem";
		ado->Open();


	//TTreeNode* node = TreeView_doc_Struct->Items->AddObject(NULL, this->node_Name->Text, (void*)reqinfo);
	//node->Selected = true;

	for(ADOQuery_insert->First();!ADOQuery_insert->Eof;ADOQuery_insert->Next())
	{

		if(ADOQuery_insert->FieldByName("id_par")->Value.IsNull())//==0
		{
		Demand *reqinfo = new Demand;
		//записываем данные из бд в структуры
		reqinfo->name_dem = ADOQuery_insert->FieldByName("name_dem")->AsAnsiString.c_str();
		reqinfo->text_dem = ADOQuery_insert->FieldByName("text_dem")->AsAnsiString.c_str();
		reqinfo->type_dem = ADOQuery_insert->FieldByName("type_dem")->AsAnsiString.c_str();
		reqinfo->num_dem = ADOQuery_insert->FieldByName("num_dem")->AsAnsiString.c_str();
		reqinfo->code_dem = ADOQuery_insert->FieldByName("code_dem")->AsAnsiString.c_str();
		reqinfo->id_dem = ADOQuery_insert->FieldByName("id_dem")->Value;
		top_level.push_back(reqinfo);



		Recursive(reqinfo, ado);
		}
		/*reqinfo->name_dem = string(AnsiString(this->node_Name->Text).c_str());
		reqinfo->num_par = string(AnsiString("0").c_str());

		this->TreeView_doc_Struct->Items->Add(ADOQuery_insert->FieldValues["project_name"]);
		*/
	}
	for(int i = 0;i<top_level.size();i++)
	{
		TTreeNode* node = TreeView_doc_Struct->Items->AddObject(NULL, top_level[i]->name_dem.c_str(), (void*)(top_level[i]));
		RecursiveFChilds(top_level[i], node);
	}

}


void TFrmDemand::RecursiveFChilds(Demand* parent_level, TTreeNode* node)
{
	for(int i = 0;i<parent_level->childs.size();i++)
	{
	   TTreeNode *nod = TreeView_doc_Struct->Items->AddChildObject(node, parent_level->childs[i]->name_dem.c_str(), parent_level->childs[i]);
		RecursiveFChilds(parent_level->childs[i], nod);
	}
}

void Recursive(Demand* parent, TADOQuery* sql)
{
	sql->First();
	while(!sql->Eof) {
		if(parent->id_dem == sql->FieldByName("id_par")->Value)
		{
			Demand *reqinfo = new Demand;


			reqinfo->name_dem = sql->FieldByName("name_dem")->AsAnsiString.c_str();
			reqinfo->text_dem = sql->FieldByName("text_dem")->AsAnsiString.c_str();
			reqinfo->type_dem = sql->FieldByName("type_dem")->AsAnsiString.c_str();
			reqinfo->num_dem = sql->FieldByName("num_dem")->AsAnsiString.c_str();
			reqinfo->code_dem = sql->FieldByName("code_dem")->AsAnsiString.c_str();
			reqinfo->id_dem = sql->FieldByName("id_dem")->Value;

			parent->childs.push_back(reqinfo);
			Recursive(reqinfo,sql);

		}
		sql->Next();
	  }
}
//---------------------------------------------------------------------------

