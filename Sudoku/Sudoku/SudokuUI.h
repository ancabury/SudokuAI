#pragma once
#include "back.h"
#include "bestfs.h"
#include "gbfs.h"
#include "bfs.h"
#include <time.h>

namespace Sudoku {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace Back;
	using namespace BestFS;
	using namespace GBFS;
	using namespace BFS;

	public ref class SudokuUI: public System::Windows::Forms::Form {
	public:	SudokuUI() {
		InitializeComponent();
		InitializeCombo();
		this->table = gcnew DataTable();
		addColumnsRows();
		}

	protected:	~SudokuUI() {
		if(components) {
			delete components;
			}
		}

	public: System::Windows::Forms::DataGridView^  SudokuTable;
	private: System::Windows::Forms::Button^  buttonBestFS;
	public:

	public:	 DataTable ^table;
	private: bool click = false;
	private: System::Windows::Forms::Button^  buttonGBFS;
	private: System::Windows::Forms::ComboBox^  comboBoxPuzzles;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  buttonBack;
	private: System::Windows::Forms::Button^  buttonBFS;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  labelTime;
	private: System::Windows::Forms::Button^  buttonUserInp;

	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
			 /* <summary>
			  Required method for Designer support - do not modify
			  the contents of this method with the code editor.
			  </summary>*/
			 void InitializeComponent(void) {
				 System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
				 this->SudokuTable = (gcnew System::Windows::Forms::DataGridView());
				 this->buttonBestFS = (gcnew System::Windows::Forms::Button());
				 this->buttonGBFS = (gcnew System::Windows::Forms::Button());
				 this->comboBoxPuzzles = (gcnew System::Windows::Forms::ComboBox());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->buttonBack = (gcnew System::Windows::Forms::Button());
				 this->buttonBFS = (gcnew System::Windows::Forms::Button());
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->labelTime = (gcnew System::Windows::Forms::Label());
				 this->buttonUserInp = (gcnew System::Windows::Forms::Button());
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SudokuTable))->BeginInit();
				 this->SuspendLayout();
				 // 
				 // SudokuTable
				 // 
				 this->SudokuTable->AllowUserToAddRows = false;
				 this->SudokuTable->AllowUserToDeleteRows = false;
				 this->SudokuTable->AllowUserToResizeColumns = false;
				 this->SudokuTable->AllowUserToResizeRows = false;
				 this->SudokuTable->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
				 this->SudokuTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				 this->SudokuTable->ColumnHeadersVisible = false;
				 dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
				 dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
				 dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
				 dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
				 dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::ControlText;
				 dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
				 this->SudokuTable->DefaultCellStyle = dataGridViewCellStyle2;
				 this->SudokuTable->Location = System::Drawing::Point(12, 12);
				 this->SudokuTable->Name = L"SudokuTable";
				 this->SudokuTable->ReadOnly = true;
				 this->SudokuTable->RowHeadersVisible = false;
				 this->SudokuTable->RowTemplate->Height = 40;
				 this->SudokuTable->Size = System::Drawing::Size(400, 363);
				 this->SudokuTable->TabIndex = 0;
				 this->SudokuTable->CellPainting += gcnew System::Windows::Forms::DataGridViewCellPaintingEventHandler(this, &SudokuUI::SudokuTable_CellPainting);
				 // 
				 // buttonBestFS
				 // 
				 this->buttonBestFS->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->buttonBestFS->Location = System::Drawing::Point(472, 230);
				 this->buttonBestFS->Name = L"buttonBestFS";
				 this->buttonBestFS->Size = System::Drawing::Size(152, 46);
				 this->buttonBestFS->TabIndex = 1;
				 this->buttonBestFS->Text = L"BestFS Solve";
				 this->buttonBestFS->UseVisualStyleBackColor = true;
				 this->buttonBestFS->Click += gcnew System::EventHandler(this, &SudokuUI::buttonSolve_Click);
				 // 
				 // buttonGBFS
				 // 
				 this->buttonGBFS->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->buttonGBFS->Location = System::Drawing::Point(472, 334);
				 this->buttonGBFS->Name = L"buttonGBFS";
				 this->buttonGBFS->Size = System::Drawing::Size(152, 46);
				 this->buttonGBFS->TabIndex = 2;
				 this->buttonGBFS->Text = L"GBFS Solve";
				 this->buttonGBFS->UseVisualStyleBackColor = true;
				 this->buttonGBFS->Click += gcnew System::EventHandler(this, &SudokuUI::buttonGBFS_Click);
				 // 
				 // comboBoxPuzzles
				 // 
				 this->comboBoxPuzzles->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->comboBoxPuzzles->FormattingEnabled = true;
				 this->comboBoxPuzzles->Location = System::Drawing::Point(418, 40);
				 this->comboBoxPuzzles->Name = L"comboBoxPuzzles";
				 this->comboBoxPuzzles->Size = System::Drawing::Size(239, 33);
				 this->comboBoxPuzzles->TabIndex = 3;
				 this->comboBoxPuzzles->SelectedIndexChanged += gcnew System::EventHandler(this, &SudokuUI::comboBoxPuzzles_SelectedIndexChanged);
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label1->Location = System::Drawing::Point(418, 9);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(92, 25);
				 this->label1->TabIndex = 4;
				 this->label1->Text = L"Puzzles :";
				 // 
				 // buttonBack
				 // 
				 this->buttonBack->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->buttonBack->Location = System::Drawing::Point(472, 178);
				 this->buttonBack->Name = L"buttonBack";
				 this->buttonBack->Size = System::Drawing::Size(152, 46);
				 this->buttonBack->TabIndex = 5;
				 this->buttonBack->Text = L"Back Solve";
				 this->buttonBack->UseVisualStyleBackColor = true;
				 this->buttonBack->Click += gcnew System::EventHandler(this, &SudokuUI::buttonBack_Click);
				 // 
				 // buttonBFS
				 // 
				 this->buttonBFS->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->buttonBFS->Location = System::Drawing::Point(472, 282);
				 this->buttonBFS->Name = L"buttonBFS";
				 this->buttonBFS->Size = System::Drawing::Size(152, 46);
				 this->buttonBFS->TabIndex = 6;
				 this->buttonBFS->Text = L"BFS Solve";
				 this->buttonBFS->UseVisualStyleBackColor = true;
				 this->buttonBFS->Click += gcnew System::EventHandler(this, &SudokuUI::buttonBFS_Click);
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label2->Location = System::Drawing::Point(418, 89);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(131, 25);
				 this->label2->TabIndex = 7;
				 this->label2->Text = L"Running time:";
				 // 
				 // labelTime
				 // 
				 this->labelTime->AutoSize = true;
				 this->labelTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->labelTime->Location = System::Drawing::Point(555, 89);
				 this->labelTime->Name = L"labelTime";
				 this->labelTime->Size = System::Drawing::Size(48, 25);
				 this->labelTime->TabIndex = 8;
				 this->labelTime->Text = L"time";
				 this->labelTime->Visible = false;
				 // 
				 // buttonUserInp
				 // 
				 this->buttonUserInp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->buttonUserInp->Location = System::Drawing::Point(438, 126);
				 this->buttonUserInp->Name = L"buttonUserInp";
				 this->buttonUserInp->Size = System::Drawing::Size(219, 46);
				 this->buttonUserInp->TabIndex = 9;
				 this->buttonUserInp->Text = L"Modify board";
				 this->buttonUserInp->UseVisualStyleBackColor = true;
				 this->buttonUserInp->Click += gcnew System::EventHandler(this, &SudokuUI::buttonUserInp_Click);
				 // 
				 // SudokuUI
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(669, 392);
				 this->Controls->Add(this->buttonUserInp);
				 this->Controls->Add(this->labelTime);
				 this->Controls->Add(this->label2);
				 this->Controls->Add(this->buttonBFS);
				 this->Controls->Add(this->buttonBack);
				 this->Controls->Add(this->label1);
				 this->Controls->Add(this->comboBoxPuzzles);
				 this->Controls->Add(this->buttonGBFS);
				 this->Controls->Add(this->buttonBestFS);
				 this->Controls->Add(this->SudokuTable);
				 this->Name = L"SudokuUI";
				 this->Text = L"SudokuUI";
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SudokuTable))->EndInit();
				 this->ResumeLayout(false);
				 this->PerformLayout();

				 }

			 void InitializeCombo() {
				 comboBoxPuzzles->Items->Add("input.txt");
				 comboBoxPuzzles->Items->Add("hard_input.txt");
				 comboBoxPuzzles->Items->Add("valid_sudoku.txt");
				 comboBoxPuzzles->Items->Add("easy_sudoku.txt");
				 comboBoxPuzzles->Items->Add("hardest_sudoku.txt");
				 comboBoxPuzzles->Items->Add("input1.txt");
				 }

			 void addColumnsRows() {
				 for(int i = 0;i < n;i++) {
					 this->table->Columns->Add("");
					 this->table->Rows->Add("");
					 }
				 }
#pragma endregion
	private: string getFileName() {
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*) (Marshal::StringToHGlobalAnsi(comboBoxPuzzles->SelectedItem->ToString())).ToPointer();
		string file = chars;
		Marshal::FreeHGlobal(IntPtr((void*) chars));
		return file;
		}

	private: System::Void SudokuTable_CellPainting(System::Object^  sender, System::Windows::Forms::DataGridViewCellPaintingEventArgs^  e) {
		Pen ^p = gcnew Pen(Brushes::Black);
		Brush ^b = gcnew SolidBrush(SudokuTable->DefaultCellStyle->BackColor);
		Point p1, p2;

		e->Handled = true;
		e->Graphics->FillRectangle(b, e->CellBounds);

		p1 = Point(0, e->CellBounds.Bottom - 1);
		p2 = Point(e->CellBounds.Right, e->CellBounds.Bottom - 1);
		e->Graphics->DrawLine(p, p1, p2);

		p1 = Point(e->CellBounds.Left, e->CellBounds.Top - 1);
		p2 = Point(e->CellBounds.Left, e->CellBounds.Bottom - 1);
		e->Graphics->DrawLine(p, p1, p2);

		if(e->RowIndex == 2 || e->RowIndex == 5) {
			p->Width = 5;
			p1 = Point(e->CellBounds.Right, e->CellBounds.Bottom - 1);
			p2 = Point(0, e->CellBounds.Bottom - 1);
			e->Graphics->DrawLine(p, p1, p2);
			}
		if(e->ColumnIndex == 2 || e->ColumnIndex == 5) {
			p->Width = 7;
			p1 = Point(e->CellBounds.Right, e->CellBounds.Top - 1);
			p2 = Point(e->CellBounds.Right, e->CellBounds.Bottom - 1);
			e->Graphics->DrawLine(p, p1, p2);
			}

		e->PaintContent(e->ClipBounds);
		}

	private: System::Void comboBoxPuzzles_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		string file = getFileName();
		int mat[9][9];
		readFile(mat, file);

		for(int i = 0;i < 9;i++)
			for(int j = 0;j < 9;j++)
				if(mat[i][j] == 0)
					this->table->Rows[i][j] = "";
				else
					this->table->Rows[i][j] = mat[i][j];

		this->SudokuTable->DataSource = table;
		this->labelTime->Visible = false;
		}

	private: void readFromBoard(int mat[9][9]) {
		for(int i = 0;i < 9;i++){
			for(int j = 0;j < 9; j++) {
				int rez = 0;
				Int32::TryParse(this->SudokuTable->Rows[i]->Cells[j]->Value->ToString(), rez);
				mat[i][j] = rez;
				}
			}
		}

	private: System::Void buttonBack_Click(System::Object^  sender, System::EventArgs^  e) {
		if(comboBoxPuzzles->SelectedIndex < 0)
			MessageBox::Show("Select a puzzle", "Information");
		else {
			using namespace Runtime::InteropServices;
			int mat[9][9];
			string file = getFileName();
			if(!click)
				readFile(mat, file);
			else
				readFromBoard(mat);

			clock_t t;
			t = clock();
			back(0, 0, mat);
			t = clock() - t;

			labelTime->Text = ((float) (t / CLOCKS_PER_SEC)).ToString() + "s";
			labelTime->Visible = true;

			for(int i = 0;i < 9;i++)
				for(int j = 0;j < 9;j++)
					this->table->Rows[i][j] = Back::sol[i][j];

			this->SudokuTable->DataSource = table;
			click = false;
			}
		}

	private: System::Void buttonSolve_Click(System::Object^  sender, System::EventArgs^  e) {
		if(comboBoxPuzzles->SelectedIndex < 0)
			MessageBox::Show("Select a puzzle", "Information");
		else {
			using namespace Runtime::InteropServices;
			int mat[9][9];
			string file = getFileName();
			if(!click)
				readFile(mat, file);
			else
				readFromBoard(mat);

			clock_t t;
			t = clock();
			bestfs(mat);
			t = clock() - t;

			labelTime->Text = (t / CLOCKS_PER_SEC).ToString() + "s";
			labelTime->Visible = true;

			for(int i = 0;i < 9;i++)
				for(int j = 0;j < 9;j++)
					this->table->Rows[i][j] = BestFS::sol[i][j];

			this->SudokuTable->DataSource = table;
			click = false;
			}
		}


	private: System::Void buttonGBFS_Click(System::Object^  sender, System::EventArgs^  e) {
		if(comboBoxPuzzles->SelectedIndex < 0)
			MessageBox::Show("Select a puzzle", "Information");
		else {
			using namespace Runtime::InteropServices;
			int mat[9][9];
			string file = getFileName();
			if(!click)
				readFile(mat, file);
			else
				readFromBoard(mat);

			clock_t t;
			t = clock();
			gbfs(mat);
			t = clock() - t;

			labelTime->Text = ((float) (t / CLOCKS_PER_SEC)).ToString() + "s";
			labelTime->Visible = true;

			if(GBFS::sol[0][0] == 0) {
				MessageBox::Show("The program did not find a valid board.", "Information");
				comboBoxPuzzles_SelectedIndexChanged(sender, e);
				return;
				}
			for(int i = 0;i < 9;i++)
				for(int j = 0;j < 9;j++)
					this->table->Rows[i][j] = GBFS::sol[i][j];

			this->SudokuTable->DataSource = table;
			click = false;
			}
		}
	private: System::Void buttonBFS_Click(System::Object^  sender, System::EventArgs^  e) {
		if(comboBoxPuzzles->SelectedIndex < 0)
			MessageBox::Show("Select a puzzle", "Information");
		else {
			using namespace Runtime::InteropServices;
			int mat[9][9];
			string file = getFileName();
			if(!click)
				readFile(mat, file);
			else
				readFromBoard(mat);

			clock_t t;
			t = clock();
			bfs(mat);
			t = clock() - t;

			labelTime->Text = (t / CLOCKS_PER_SEC).ToString() + "s";
			labelTime->Visible = true;

			for(int i = 0;i < 9;i++)
				for(int j = 0;j < 9;j++)
					this->table->Rows[i][j] = BFS::sol[i][j];

			this->SudokuTable->DataSource = table;
			click = false;
			}
		}
	private: System::Void buttonUserInp_Click(System::Object^  sender, System::EventArgs^  e) {
		click = true;
		this->SudokuTable->ReadOnly = false;
		}
		};
	}
